#include <stdio.h>

int adjustscore(int x)
{
    int b;
    float j;
    for(j=0.0;j*j<=x;j+=0.01);
    b=j*10;
    return b;
}

int main(){
	int MathScore[100],maxMathScore,minMathScore,sumMathScore=0;
	int EngScore[100],maxEngScore,minEngScore,sumEngScore=0;
	int ProgScore[100],maxProgScore,minProgScore,sumProgScore=0;
	int AveScore[100],maxAveScore,minAveScore,sumAveScore=0;
	int i = 0,j;
	int studentcnt;
	int aveMathScore,aveEngScore,aveProgScore,aveAveScore;
	
	// printf("the number of students:");
	// scanf("%d",&studentcnt);
	// printf("intput the scores:\n");

    
	// for(i=0;i<studentcnt;i++){
	// 	scanf("%d %d %d",);
	// }

	while(EOF!=scanf("%d %d %d %d",&j,&MathScore[i],&EngScore[i],&ProgScore[i]))
		i++;
	
	studentcnt = i;

	for(i=0;i<studentcnt;i++){
		MathScore[i]=adjustscore(MathScore[i]);
		EngScore[i]=adjustscore(EngScore[i]);
		ProgScore[i]=adjustscore(ProgScore[i]);
		AveScore[i]=(MathScore[i]+EngScore[i]+ ProgScore[i])/3;
		sumMathScore=sumMathScore+MathScore[i];
	    sumEngScore=sumEngScore+EngScore[i];
	    sumProgScore=sumProgScore+ProgScore[i];
	    sumAveScore=sumAveScore+AveScore[i];
	    aveMathScore=sumMathScore/studentcnt;
	    aveEngScore=sumEngScore/studentcnt;
	    aveProgScore=sumProgScore/studentcnt;
	    aveAveScore=sumAveScore/studentcnt;
	}
	
	minMathScore=MathScore[0];
	maxMathScore=MathScore[0];
	minEngScore=EngScore[0];
	maxEngScore=EngScore[0];
	minProgScore=ProgScore[0];
	maxProgScore=ProgScore[0];
	minAveScore=AveScore[0];
	maxAveScore=AveScore[0];
	
	for(i=0; i<studentcnt; i++){
		if(MathScore[i]<minMathScore) minMathScore=MathScore[i];
		if(EngScore[i]<minEngScore) minEngScore=EngScore[i];
		if(ProgScore[i]<minProgScore) minProgScore=ProgScore[i];
		if(AveScore[i]<minAveScore) minAveScore=AveScore[i];
		if(MathScore[i]>maxMathScore) maxMathScore=MathScore[i];
		if(EngScore[i]>maxEngScore) maxEngScore=EngScore[i];
		if(ProgScore[i]>maxProgScore) maxProgScore=ProgScore[i];
		if(AveScore[i]>maxAveScore) maxAveScore=AveScore[i];
	}
	// printf("After adjustment\n");
	printf("No\tMath\tEnglish\tProg\tAverage\n");
	printf("========================================\n");
	for(i=0;i<studentcnt;i++)
	printf("%d\t%d\t%d\t%d\t%d\n",i+1,MathScore[i],EngScore[i],ProgScore[i],AveScore[i]);
	printf("========================================\n");
	printf("AVG\t%d\t%d\t%d\t%d\n",aveMathScore,aveEngScore,aveProgScore,aveAveScore);
	printf("Max\t%d\t%d\t%d\t%d\n",maxMathScore,maxEngScore,maxProgScore,maxAveScore);
	printf("Min\t%d\t%d\t%d\t%d\n",minMathScore,minEngScore,minProgScore,minAveScore);
	
	return 0;
}