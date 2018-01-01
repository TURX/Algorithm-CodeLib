#include <cstdio>
//#include <iostream>
#include <cstring>
#include <ctype.h>
using namespace std;
char target[100], article[1000005];
//string target,article;
bool flag=0;
char* getLower(char in[]) {
	for(int t=0;t<strlen(in);t++) {
		in[t]=tolower(in[t]);
	}
	return in;
}
bool check(int n) {
	if(n<0) return true;
	if(article[n]==' ') return true;
	return false;
}
int main() {
	int i,j,k,first,count=0;
	/*cin>>target;
	while(cin>>article) {
		if(getLower(article)==getLower(target)) {
			count++;
			if(flag==0) {
				first=i;
				flag=1;
			}
		}
	}*/
	gets(target);
	gets(article);
	//fgets(target, sizeof(target), stdin);
	//fgets(article, sizeof(article), stdin);
	//getLower(target);
	//getLower(article);
	for(i=0;i<=strlen(article);i++){ //-strlen(target)
		for(j=0,k=i;j<strlen(target)&&tolower(target[j])==tolower(article[k]);j++,k++);
		if(j==strlen(target)&&check(k-j-1)) {
			count++;
			if(flag==0) {
				first=i;
				flag=1;
			}
		}
	}
	if(count!=0) printf("%d %d\n",count,first); else printf("-1");
	return 0;
}
/*
int main(){
	int first,result=0;
	int flag=0;
	scanf("%s",target);
	gets(article);
	for(int t=0;t<strlen(target);t++) tolower(target[t]);
	for(int t=0;t<strlen(article);t++) tolower(article[t]);
	for(int t=0;t<strlen(article)-strlen(target);t++){
		char cmp[10];
		for(int t2=0;t2<strlen(target);t2++){
			cmp[t2]=article[t];
		}
		if(strcmp(cmp,target)==0){
			result++;
			if(flag==0){
				first=t;
				flag=1;
			}
		}
	}
	if(flag==0) printf("-1\n");
	if(flag==1) printf("%d %d\n",result,first);
}
*/

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j,k,TLen,PLen,count=0,first=-1;
    char T[50],P[10];
    printf("????????,?????,????,????:\n");
    gets(T);
    gets(P);
    TLen=strlen(T);
    PLen=strlen(P);
    
    for(i=0;i<=TLen-PLen;i++)
    {
        for(j=0,k=i;j<PLen&&tolower(P[j])==tolower(T[k]);j++,k++);
        if(j==PLen)count++;
        if(count==1) first=i;
    }
    if(count>0) printf("%d,%d\n",count,first);
    else printf("-1\n");
    //system("pause");
    return 0;
}
*/
