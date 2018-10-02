#include <stdio.h>

int main(){
	int c;
	int nc=0,nl=0;
	int na=0,ne=0,ni=0,no=0,nu=0;
	int nodd=0;
	int ndigit=0;
	
	while((c=getchar())!=EOF){
		nc++;
		if(c=='\n')nl++;
		if((c=='a')||(c=='A'))na++;
    if((c=='e')||(c=='E'))ne++;
    if((c=='i')||(c=='I'))ni++;
    if((c=='o')||(c=='O'))no++;
    if((c=='u')||(c=='U'))nu++;
		if((c=='1')||(c=='3')||(c=='5')||(c=='7')||(c=='9'))nodd++;
    if(c<='9'&&c>='0')ndigit++;
	}
	printf("number of lines: %d\n",nl);
	printf("number of vowels: %d\n",na+ne+ni+no+nu);
	printf("number of digits: %d\n",ndigit);
	printf("number of odds: %d\n",nodd);
	printf("number of characters: %d\n",nc); 
}