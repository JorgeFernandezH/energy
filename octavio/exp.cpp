#include <iostream>
#include <armadillo>

using namespace arma;
using namespace std;

mat raiz(mat A){
	int n=size(A)(0);
	vec D;
	mat B;
	mat G(n,n);
	eig_sym(D,B,A);
	for(int i=0;i<n;i++){
		if(D(i)<0 ) D(i)=0;
		G(i,i)=sqrt(D(i));
	}
	return(inv(trans(B))*G*(trans(B)));
}

int main(){
	mat A(10,10);
	for(int i=0;i<10;i++){ // this part just reads the matrix,
		for(int j=0;j<10;j++){
			int x;
			scanf("%d",&x);
			A(i,j)=x;
		}
	}
	cout << A;
}