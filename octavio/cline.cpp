#include <bits/stdc++.h>
using namespace std;

mat line(mat (A)){
	mat B;
	vector <pi> E;
	for(int i=0;i<n;i<n;i++){
		for(int j=i+1;j<n;j++){
			edge+=A(i,j);
			P.push_(pi (i,j) );
		}
	}
	for(int i=0;i<E.size();i++){
		for(int j=i+1;j<E.size();j++){
			if(E[i].first== E[j].first || E[i].first == E[j].second || E[i].second == E[j].first || E[i].second == E[j].second){
				B(i,j)=B(j,i)=1;
			}
		}
	}
	return(B);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	}
}