//这个程序只进行了一次测试。
#include<stdio.h>
const int nlift=2;
const int nnfloor=10;//一共几层楼
const int nfloor=18;//一个电梯的gene
const int lengene=36;
int L1;//ground floor
int L2;//highest down call
int L3;//# of calls btw L1,L2
int L4;//highest up call
int L5;//# of calls btw L1,L4
int L6;//lowest down call
double t;//foor opening and closing time
double tp;//passenger transfer time
double hct,lct;//highest/lowest car trip time
double k1,k2;
double f;
bool c[lengene]={0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0};//1,2,3向上，2,3,4向下
//这个fitness函数还没有实现hct和lct的计算。
double fitness(){
	k1=1.5;
	k2=2;
	t=5.5;
	tp=3;
	hct=57;
	lct=54;
	L1=1;
	L2=L3=L4=L5=L6=0;
		int cnfloor=0;
		int cndirec=1;
		int lolo=999;
		int j=0;
		for(int i=0;i<lengene;i++){
			cnfloor++;
			if(c[i]==1){
				if(cndirec%2==1){//1的话向上
					L4=i+1-(j*nfloor);
					L5++;
				}
				else              {//0向下
					L2=i+2-(j*nfloor)-(nfloor/2);
					L3++;
					if(i<lolo)lolo=i;
					L6=lolo+2-(j*nfloor)-(nfloor/2);
				}
			}
			if(cnfloor==nfloor/2&&cndirec%2==1){cndirec++;cnfloor=1;}
			if(cnfloor==nnfloor&&cndirec%2==0){
				cndirec++;
				cnfloor=0;
				j++;
				if(L3&&L5)f+=t*(L4-L1)+t*(L2-L4)+t*(L2-L6)+tp*(L3 +L5 -L1);
				else if(L3)f+=t*(L2-L1)+tp*(L3-L1);
				else if(L5)f+=t*(L4-L1)+tp*(L5-L1);				
				L2=L3=L4=L5=L6=0;
			}
			printf("%d %d %d %d %d %d\n",L1,L2,L3,L4,L5,L6);
			printf("%lf\n",f);
			}
		f=k1*(f/nlift)+k2*(hct-lct);
	return(f);
}
int main(){
//	freopen("result.out","w",stdout);
	printf("%lf",fitness());
}
