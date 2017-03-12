#include <iostream>
#include <armadillo>


using namespace std;
using namespace arma;
typedef pair<int,int> pi;

char T[50];
int n,g=0;
mat S[10];

mat raiz(mat A){
	int n=size(A)(0);
	vec D;
	mat B;
	mat G(n,n,fill::zeros);
	eig_sym(D,B,A);
	for(int i=0;i<n;i++){
		if(D(i)<0 ) D(i)=0;
		G(i,i)=sqrt(D(i));
	}
	return trans(B*G*inv(B));
}

void circulate(){
	int a;
	printf("Insert graph number\n");
	scanf("%d",&a);
	if(a>=g){
		printf("the graph does not exist\n");
		return;
	}
	int x;
	printf("Insert distance\n");
	scanf("%d",&x);
	int s=S[a].n_rows;
	for(int i=0;i<s;i++){
			S[a](i,(i+x)%s)=1;
			S[a]((i+x)%s,i)=1;
	}
}

void booleano(){
	/*
	int a,b;
	printf("Insert graph numbers\n");
	scanf("%d %d",&a,&b);
	if(a>=g || b>=g){
		printf("at least one of those graphs does not exist\n");
		return;
	}
	int x,y;
	scanf("%d %d",&x,&y);
	for(int i=0;i<)


		mat B=raiz(A*A);
	for(int i=0;i<x*S[b].n_rows;i++){
		printf("vertex (%d,%d): %f\n",i%x,i/x,B(i,i));
		total+=B(i,i);
	}
	printf("total energy: %f\n",total);
	printf("Do you wish to save?\n");
	scanf("%s",T);
	if(T[0]=='y'){
		S[g]=A;
		g++;
		printf("there are currently %d graph(s)\n",g);
	}
	*/
}

void rellena(){
	int a;
	printf("Insert graph number\n");
	scanf("%d",&a);
	if(a>=g){
		printf("the graph does not exist\n");
		return;
	}
	int s=S[a].n_rows;
	for(int i=0;i<s;i++){
		for(int j=i+1;j<s;j++){
			S[a](i,j)=1;
			S[a](j,i)=1;
		}
	}
}

void line(){
	int a;
	printf("Insert graph number\n");
	scanf("%d",&a);
	if(a>=g){
		printf("the graph does not exist\n");
		return;
	}
	int x=S[a].n_rows;
	vector <pi> E;
	for(int i=0;i<x;i++){
		for(int j=i+1;j<x;j++){
			if(S[a](i,j)) E.push_back(pi (i,j) );
		}
	}
	int s=E.size();
	mat B(s,s);
	B.zeros();
	for(int i=0;i<E.size();i++){
		for(int j=i+1;j<E.size();j++){
			if(E[i].first== E[j].first || E[i].first == E[j].second || E[i].second == E[j].first || E[i].second == E[j].second){
				B(i,j)=B(j,i)=1;
			}
		}
	}
	mat C=raiz(B*B);
	double total=0;
	for(int i=0;i<s;i++){
		printf("vertex %d: %f\n",i,C(i,i));
		total+=C(i,i);
	}
	printf("total energy: %f\n",total);
	printf("Do you wish to save?\n");
	scanf("%s",T);
	if(T[0]=='y'){
		S[g]=B;
		g++;
		printf("there are currently %d graph(s)\n",g);
	}
}

void newg(){
	printf("insert graph size\n");
	int x;
	scanf("%d",&x);
	S[g].set_size(x,x);
	S[g].fill(0);
	g++;
	printf("there are currently %d graph(s)\n",g);
}

void add(){
	int x=0,a,b;
	if(g>1){
		printf("insert graph number\n");
		scanf("%d",&x);
		if(x>=g){
			printf("no such graph exists\n");
			return;
		}
	}
	printf("insert vertices for edge\n");
	scanf("%d %d",&a,&b);
	if(a>=S[x].n_rows || b>=S[x].n_rows){
		printf("at least one of those vertices does not exist\n");
		return;
	}
	S[x](a,b)=1;
	S[x](b,a)=1;
}

void remove(){
	int x=0,a,b;
	if(g>1){
		printf("Insert graph number\n");
		scanf("%d",&x);
		if(x>=g){
			printf("no such graph exists\n");
			return;
		}
	}
	printf("Insert vertices for edge deletions\n");
	scanf("%d %d",&a,&b);
	if(a>=S[x].n_rows || b>=S[x].n_rows){
		printf("at least one of those vertices does not exist\n");
		return;
	}
	S[x](a,b)=0;
	S[x](b,a)=0;
}

void print(){
	int x=0;
	if(g>1){
		printf("Insert graph number\n");
		scanf("%d",&x);
		if(x>=g){
			printf("no such graph exists\n");
			return;
		}
	}
	double total=0;
	mat A=raiz(S[x]*S[x]);
	for(int i=0;i<S[x].n_rows;i++){
		printf("vertex %d: %f\n",i,A(i,i));
		total+=A(i,i);
	}
	printf("total energy: %f\n",total);
}

void matrix(){
	int x=0;
	if(g>1){
		printf("Insert graph number\n");
		scanf("%d",&x);
		if(x>=g){
			printf("no such graph exists\n");
			return;
		}
	}
	cout << S[x];
}

void cartesian(){
	int a,b;
	printf("Insert graph numbers\n");
	scanf("%d %d",&a,&b);
	if(a>=g || b>=g){
		printf("at least one of those graphs does not exist\n");
		return;
	}
	int x=S[a].n_rows;
	mat A(x*S[b].n_rows,x*S[b].n_rows);
	A.fill(0);
	double total=0;
	for (int i=0;i<x*S[b].n_rows;i++){
		for(int j=0;j<x*S[b].n_rows;j++){
			int f1=i%x,s1=i/x,f2=j%x,s2=j/x;
			if(f1==f2 && S[b](s1,s2) ) A(i,j)=1;
			if(S[a](f1,f2) && s1==s2 ) A(i,j)=1;
		}
	}
	mat B=raiz(A*A);
	for(int i=0;i<x*S[b].n_rows;i++){
		printf("vertex (%d,%d): %f\n",i%x,i/x,B(i,i));
		total+=B(i,i);
	}
	printf("total energy: %f\n",total);
	printf("Do you wish to save?\n");
	scanf("%s",T);
	if(T[0]=='y'){
		S[g]=A;
		g++;
		printf("there are currently %d graph(s)\n",g);
	}
}

void graphs(){
	for(int i=0;i<g;i++){
		double en=0;
		mat B=raiz(S[i]*S[i]);
		for(int j=0;j<S[i].n_rows;j++){
			en+=B(j,j);
		}
		printf("graph %d: %d vertices and energy %f\n",i,S[i].n_rows,en);
	}
}

void end(){
	ofstream output_file("out3.txt");
	output_file.precision(3);
	for(int a=0;a<g;a++){
		output_file << "\\vbox{\n" ;
		mat A=S[a];
		mat B=raiz(A*A);
		int s=S[a].n_rows;
		double tot=0;
		for(int i=0;i<s;i++){
			tot+=B(i,i);
		}
		output_file << endl;
		output_file << "Total energy: " << tot << " \\\\\\ \n";
		output_file << ("\\begin{tikzpicture}\n");
		for(int i=1;i<=s;i++){
			int r= min(100.0,B(i-1,i-1)*100/2);
			output_file << "\\node[style={circle,fill=yellow!" << 100-r << "!red!" << (int) (20+r*0.8) << ",draw,minimum size=2.5em,inner sep=3pt]}] (" << i <<") at (" << i <<  "*360/" << s << ":"<< 1.5+0.1*s <<") {$\\scriptstyle{" << B(i-1,i-1) << "}$};\n";
		}
		for(int i=0;i<s;i++){
			for(int j=i+1;j<s;j++){
				if(A(i,j)) output_file << "\\path[draw,thick](" << i+1 << ") edge node {} (" << j+1 << ");\n";
			}
		}
		output_file << ("\\end{tikzpicture}\n");
		output_file << ("\\\\");
		output_file << ("}\n");
		output_file << ("\n\n");
	}
	output_file.close();
	exit(0);
}

void isolated(){
	int a;
	printf("Insert graph number\n");
	scanf("%d",&a);
	if(a>=g){
		printf("the graph does not exist\n");
		return;
	}
	int s=S[a].n_rows;
	mat A(s+1,s+1);
	A.zeros();
	for(int i=0;i<s;i++){
		for(int j=0;j<s;j++){
			A(i,j)=S[a](i,j);
		}
	}
	S[a]=A;
}

int main(){
	printf("welcome, the available commands are:\n");
	printf("new (creates a new empty graph)\n");
	printf ("add (adds a vertex to a graph)\n");
	printf("fill (adds all possible edges to a pre-existing graph\n");
	printf("circulate (adds all edges at a certain numerical distance\n");
	printf("remove (removes a vertex from a graph)\n");
	printf("isolated (add an isolated vertex to a graph)\n");
	printf("print (prints the energies of a graph)\n");
	printf("matrix (shows adjacency matrix for a graph)\n");
	printf("cartesian (creates the cartesian product of two graphs)\n");
	printf("graphs (prints list of graph orders and total energies)\n");
	printf("line (creates the line graph of an old graph\n");
	printf("exit\n");
	printf("warning: note that all numeration is 0-based\n");
	printf("type new to create the first graph\n");
	while(printf("input command:\n") && scanf("%s",T) != EOF){
		int a,b;
		if(T[0]=='n') {newg();continue;}
		if(T[0]=='a') {add();continue;}
		if(T[0]=='i') {isolated();continue;}
		if(T[0]=='r') {remove();continue;}
		if(T[0]=='p') {print();continue;}
		if(T[0]=='m') {matrix();continue;}
		if(T[0]=='c' && T[1]=='a') {cartesian();continue;}
		if(T[0]=='g') {graphs();continue;}
		if(T[0]=='l') {line();continue;}
		if(T[0]=='f') {rellena();continue;}
		if(T[0]=='c') {circulate();continue;}
		if(T[0]=='e') end();
		printf("invalid\n");
	}
}