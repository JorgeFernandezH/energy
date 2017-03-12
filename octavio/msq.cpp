#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

mat raiz(mat A){
	int n=size(A)(0);
	vec D;
	mat B;
	mat G(n,n);
	eig_sym(D,B,A);
	for(int i=0;i<n;i++){
		G(i,i)=sqrt(D(i));
	}
	return(inv(trans(B))*G*(trans(B)));
}

int main(){
	mat A(3,3);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			int x;
			scanf("%d",&x);
			A(i,j)=x;
		}
	}
	mat B=raiz(A*A);
	mat C=sqrtmat_sympd(A*A);
	cout << (B-C);

}