#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Random(x)(rand()%x+1)
int plt=60;
int lytic=0, lyso=0;
void Get_Rnd_Replication_Type(int plt){
	int w=Random(100);
	if(w<61)lytic++;
	else    lyso++;	
}

int main(){
	srand(time(NULL));
	for(int i=1;i<=1000;i++)
	Get_Rnd_Replication_Type(plt);
	printf("lytic:%d lyso:%d",lytic,lyso);
	return 0;
}
