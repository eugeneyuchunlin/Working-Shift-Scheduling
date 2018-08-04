#include<iostream>
using namespace std;
int main(){
    int date=0;
    char days[20];
    FILE *f=NULL;
    f=fopen("calendar.txt","r");
    if(f!=NULL){
        while(EOF!=fscanf(f,"%d %s",&date,days))
            printf("%d %s\n",date,days);
    }
}