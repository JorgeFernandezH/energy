#include <bits/stdc++.h>
using namespace std;
typedef long long lli;


const int MAX=20;
lli Em[MAX][MAX];

int bit(int x, int p){
	while(p--){
		x/=2;
	}
	return(x%2);
}

int main(){
	for(int i=1;i<MAX;i++){
		for(int j=1;j< 1<<n ;j++){
			lli sum=1,bits=0;
			for(int k=0;k<n;k++){
				if(bit(j,k)){
					sum*=k+1;
					bits++;
				}
				Em(i,j)+=sum;
			}
		}
	}
}