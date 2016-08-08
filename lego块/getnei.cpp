#include<iostream>
#include<stdlib.h>
#include<time.h>
//#include<vector>
using namespace std;
#define Random(x)(rand()%x+1)
const int Vc_size=5;
const int nlift=2;
const int nfloor=4;
//const bool c[8]={1,1,0,1,0,0,0,0};
const bool c[8]={1,0,0,0,0,1,0,0};

const int lengene=8;
//int Vc[lengene];
//vector<int> Vc[Vc_size];
bool Vc[Vc_size][lengene];
//邻域为只有一对01交换的
void Get_Neighbourhood(){
	int cn=1;
	int count[lengene];
 for(int i=0;i<lengene;i++){
         if(c[i]==0)continue;
         else{
                 count[cn]=i;
                 cn++;
         }
 }
 cn--;
 for(int j=0;j<Vc_size;j++)
 for (int i=0;i<lengene;i++){
	 Vc[j][i]=c[i];
 }
 srand(time(NULL));
 for(int i=0;i<Vc_size;i++){
	// srand(time(NULL));
 	int w=Random(cn);//减1因为上次循环最后多了1
	int n;
	do{ n=Random(nlift);}while(count[w]/nfloor+1==n);
	int du=(count[w]+1)%nfloor;
	if(du==0) du=4;
	int dudu=(n-1)*nfloor+du-1;
	Vc[i][count[w]]=0;
	Vc[i][dudu]=1;
 for(int ww =0;ww<lengene;ww++)printf("% d",Vc[i][ww]);
 printf("\n");
}
}
int main(){
Get_Neighbourhood();
return 0;
}
//setbit可以代替数组
