#include <bits/stdc++.h>

using namespace std;

int R[20][20];
int B[20][20];


int bit(int p,int s){
	int x=s;
	for(int i=0;i+1 < p;i++){
		x/=2;
	}
	return(x%2);
}

int cuenta(int N){
	int res=0;
	for(int i=1; i+1 < 1<< N ; i++){
		int c1=0,c2=0,sred=0,ered=0,sblue=0,eblue=0;
		for(int j=0;j<N;j++){
			if(bit(j,i)==0 && bit((j+1)%N,i)==1 ){
				if(j%2) sred++;
				else sblue++;
			}
			if(bit(j,i)==1 && bit((j+1)%N,i)==0 ){
				if(j%2) ered++;
				else eblue++;
			}
			if(bit(j,i)==1 && bit((j+1)%N,i)==1 ){
				if(j%2) c1++;
				else c1--;
			}
			if(bit(j,i)==0 && bit((j+1)%N,i)==0 ){
				if(j%2) c2++;
				else c2--;
			}
		}
		if (ered!= sblue ) continue;
		if (eblue != sred) continue;
		if(c1 != 0) continue;
		if(c2 != 0) continue;
		res++;
	}
	return(res/2);
}

int main(){
	for(int i=2;i<=20;i+=2){
		printf("%d\n",cuenta(i));
	}
}