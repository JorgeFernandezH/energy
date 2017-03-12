#include <iostream>
#include <armadillo>

using namespace arma;
using namespace std;

const int Ma=20;

mat raiz(mat A){
	int n=size(A)(0);
	vec D;
	mat B;
	mat G(n,n);
	G.zeros();
	eig_sym(D,B,A);
	for(int i=0;i<n;i++){
		if(D(i)<0 ) D(i)=0;
		G(i,i)=sqrt(D(i));
	}
	return(inv(trans(B))*G*(trans(B)));
}

int main(){
	for(int S=2;S<=Ma;S++){
		mat A(S,S);
		A.zeros();
		for(int i=0;i+1<S;i++){
			A(i,i+1)=1;
			A(i+1,i)=1;
		}
		mat B=raiz(A*A);
		printf("\\vbox{\n");
		double tot=0;
		for(int i=0;i<S;i++){
			tot+=B(i,i);
		}
		printf("\\noindent %d vertices \\\\",S);
		printf("\\noindent total energy $%.3f$ \\\\\\ \n",tot);
		printf("\\begin{tikzpicture}\n");
		for(int i=1;i<=S;i++){
			int r= min(100.0,(B(i-1,i-1)*100-50));
			printf("\\node[style={circle,fill=yellow!%d!red!%d,draw,minimum size=1em,inner sep=3pt]}] (%d) at (0,%.1f) {$\\scriptstyle %.3f$};\n",100-r,(int) (20+r*0.8),i,-1.2*i,B(i-1,i-1));
		}
		for(int i=0;i<S;i++){
			for(int j=i+1;j<S;j++){
				if(A(i,j)) printf("\\path[draw,thick](%d) edge node {} (%d);\n",i+1,j+1);
			}
		}
		printf("\\end{tikzpicture}\n");
		printf("\\\\");
		printf("}\n");
		printf("\n\n");
	}
}