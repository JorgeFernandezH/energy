#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

string s;
const int S=8;
const int Ma=10;


mat raiz(mat A){
	int n=size(A)(0);
	vec D;
	mat B;
	mat G(n,n);
	eig_sym(D,B,A);
	G.zeros();
	for(int i=0;i<n;i++){
		if(D(i)<0 ) D(i)=0;
		G(i,i)=sqrt(D(i));
	}
	return(inv(trans(B))*G*(trans(B)));
}

int main(){
	while (getline(cin,s)){
		getline(cin,s);
		mat A(S,S);
		for(int i=0;i<S;i++){
			for(int j=0;j<S;j++){
				int x;
				scanf("%d",&x);
				A(i,j)=x;
			}
		}
		mat B=raiz(A*A);
		continue;
		int t=1;
		double tot=0;
		for(int i=0;i<S;i++){
			tot+=B(i,i);
		}
		if(tot<= 2*(S-1)) t=0;
		if(t){
			printf("\\vbox{\n");
			cout << s << "\\" << endl;
			cout << endl;
			printf("Total energy: $%.3f$ \\\\\\ \n",tot);
			printf("\\begin{tikzpicture}\n");
			for(int i=1;i<=S;i++){
				int r= min(100.0,B(i-1,i-1)*100/pow(Ma,0.5));
				printf("\\node[style={circle,fill=yellow!%d!red!%d,draw,minimum size=1em,inner sep=3pt]}] (%d) at (%d*360/%d:1.5) {$%.3f$};\n",100-r,(int) (20+r*0.8),i,i,S,B(i-1,i-1));
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
		getline(cin,s);
	}
}