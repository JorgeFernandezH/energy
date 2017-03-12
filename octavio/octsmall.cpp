#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

string s;
const int S=9;

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
	while (getline(cin,s)){
		getline(cin,s);
		printf("\\vbox{\n");
		cout << s << "\\" << endl;
		mat A(S,S);
		for(int i=0;i<S;i++){
			for(int j=0;j<S;j++){
				int x;
				scanf("%d",&x);
				A(i,j)=x;
			}
		}
		mat B=raiz(A*A);
		double tot=0;
		for(int i=0;i<S;i++){
			tot+=B(i,i);
		}
		cout << endl;
		printf("Total energy: $%.3f$ \\\\\\ \n",tot);
		printf("\\begin{tikzpicture}\n");
		for(int i=1;i<=S;i++){
			int r= min(100.0,B(i-1,i-1)*100/pow(6,0.5));
			printf("\\node[style={circle,fill=blue!%d!red!%d,draw,minimum size=1em,inner sep=3pt]}] (%d) at (%d*360/%d:1.5) {$%.3f$};\n",100-r,r,i,i,S,B(i-1,i-1));
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
		getline(cin,s);
	}
}