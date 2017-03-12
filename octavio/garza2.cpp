#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long lli;

const int MAX=20;
int P[MAX];
int F[MAX];
int R[MAX][MAX];
int B[MAX][MAX];
int Res[MAX];
int Spec[MAX];
int N;

lli St[MAX][MAX];
lli Bi[MAX][MAX];
lli Em[MAX][MAX];

int bit(int x, int p){
	while(p--){
		x/=2;
	}
	return(x%2);
}

lli f(lli dk,lli j){
	lli res=0;
	for(lli r=j;r<=dk/2+1;r++){
		lli s=1;
		if((dk/2-r+1)%2) s=-1;
		res+=s*St[r][j]*Bi[dk][r-2]*Bi[dk-r][dk/2-r+1];

	}
	return(res/(dk/2));
}

lli a(lli dk, lli j){
	lli res=0;
	for(lli r=j;r<=dk/2+1;r++){
		lli s=1;
		if((r-j)%2) s=-1;
		res+=s*Em[r-1][r-j]*Res[r];
	}
	return(res);
}

lli poten(lli b, lli e){
	lli res=1;
	while(e){
		if(e%2) res*=b;
		e/=2;
		b=b*b;
	}
	return(res);
}

int next(){
	for(int i=N-1;i>=0;i--){
		P[F[i]]=i;
	}
	for(int i=N-1;i>=0;i--){
		if(F[i]+1<N && P[F[i]]!=i){
			F[i]++;
			for(int j=i+1;j<N;j++){
				F[j]=0;
			}
			return(1);
		} 
	}
	return(0);
}

int test(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(R[i][j] != B[j][i]) return(0); 
		}
	}
	return(1);
}

int main(){
	Em[0][0]=1;
	for(int i=1;i<MAX;i++){ // calcula los Em
		Em[i][0]=1;
		for(int j=1;j< 1<<i ;j++){
			lli sum=1,bits=0;
			for(int k=0;k<i;k++){
				if(bit(j,k)){
					sum*=k+1;
					bits++;
				}
			}
			Em[i][bits]+=sum;
		}
	}
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
	scanf("%d",&N);
	int start=1;
	while(start || next()){
		start=0;
		int v=0;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				R[i][j]=0;
				B[i][j]=0;
			}
		}
		for(int i=0;i<N;i++){
			if(F[i]==F[(i+2)%N]) v=1;
		}
		int blocks=0;
		for(int i=0;i<N;i++){
			blocks=max(blocks,F[i]+1);
		}
		for(int i=0;i<N;i++){
			if(i%2) R[F[i]][F[(i+1)%N]]++;
			else B[F[i]][F[(i+1)%N]]++;
		}
		if ( test() ) Res[blocks]++;
		if( test() && v==0 && blocks == 3){
			/* for(int i=0;i<N;i++){
				printf("%d ",F[i]);
			}
			printf("\n"); */
			Spec[blocks]++;
		}
	}
	for(int i=1;i<=N/2+1;i++){
		printf("%d block(s): %d,%d, %lld\n",i,Res[i],Res[i]-Spec[i],f(N,i));
	}
	lli t=0;
	for(int i=1;i<=N/2+1;i++){
		printf("a_%d: %lld\n",i,a(N,i));
		printf("%lld\n",a(N,i));
		t+=a(N,i)*poten(3,i);
	}
	printf("%lld\n",t/9);
}