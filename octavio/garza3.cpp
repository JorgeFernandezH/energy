#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

const int MAX=20;
lli St[MAX][MAX];
lli Bi[MAX][MAX];

lli f(int dk,int j){
	lli res=0;
	for(int r=2;r<=dk/2+1;r++){
		int s=1;
		if((dk/2-r+1)%2) s=-1;
		res+=s*St[r][j]*Bi[dk][r-2]*Bi[dk-r][dk/2-r+1];

	}
}

int main(){
	Bi[0][0]=1;
	St[0][0]=1;
	for(int i=1;i<MAX;i++){
		Bi[i][0]=1;
		for(int j=1;j<MAX;j++){
			Bi[i][j]=Bi[i-1][j-1]+Bi[i-1][j];
		}
		for(int j=1;j<MAX;j++){
			St[i][j]=St[i-1][j-1]+j*St[i-1][j];
		}
	}

}