#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef struct Book {
	char id_number[8];
	char title[81];
	char author[81];
	char key_words[81];
	char publisher[81];
	char published_year[5];
}Book;
Book books[10002];
int N,M;
bool cmp(Book a,Book b)
{
	return strcmp(a.id_number,b.id_number)<0;
}
bool find_key_words(char src[],char dst[])
{
	char *p=dst;
	char words[100];
	char *pos=p;
	while(*pos) {
		while((*pos)!=' '&&(*pos)) {
			pos++;
		}
		int i;
		for(i=0;p<=pos-1;i++) {
			words[i]=*p;
			p++;
		}
		words[i]='\0';
		if(strcmp(src,words)==0)
			return true;
		if(!(*pos))
			break;
		pos++;
		p=pos;
	}
	return false;
}
bool do_search(char search_rq[])
{
	char *p=search_rq;
	int i;
	bool flag=false;
	if(*p=='1') {
		for(i=0;i<N;i++)
			if(strcmp(p+3,books[i].title)==0) {
				puts(books[i].id_number);
				flag=true;
			}
	} else if(*p=='2') {
		for(i=0;i<N;i++)
			if(strcmp(p+3,books[i].author)==0) {
				puts(books[i].id_number);
				flag=true;
			}
	} else if(*p=='3') {
		for(i=0;i<N;i++) 
			if(find_key_words(p+3,books[i].key_words)) {
				puts(books[i].id_number);
				flag=true;
			}
	} else if(*p=='4') {
		for(i=0;i<N;i++) if(strcmp(p+3,books[i].publisher)==0){
		  	 	puts(books[i].id_number);
				flag=true;
		}
	} else if(*p=='5') {
		for(i=0;i<N;i++)
			if(strcmp(p+3,books[i].published_year)==0) {
				puts(books[i].id_number);
				flag=true;
			}
	}
	return flag;
}


int main()
{
	scanf("%d",&N);
	int i;
	for(i=0;i<N;i++) {
		scanf("%s",books[i].id_number);
		getchar();
		gets(books[i].title);
		gets(books[i].author);
		gets(books[i].key_words);
		gets(books[i].publisher);
		gets(books[i].published_year);
	}
	sort(books,books+N,cmp);
	scanf("%d",&M);
	char request[102];
	getchar();
	for(i=0;i<M;i++) {
		gets(request);
		puts(request);
		if(!do_search(request))
			printf("Not Found\n");
	}
	return 0;
}
