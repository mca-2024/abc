#include<iostream>
using namespace std;

void order(int i, int j, int **P, int n){
	if(i == j)
		cout<<"A"<<j;
	else{
		int k = P[i-1][j-i-1];
		cout<<"(";
		order(i, k, P, n);
		order(k+1, j, P, n);
		cout<<")";
	}
}

void minMul(int d[], int **M, int **P, int n){ 
     for(int i=0; i<n; i++)
     	M[i][0] = 0;
     //For i = 1 to n do {M[i, i] = 0; }
     for(int diagonal=1; diagonal<=n-1; diagonal++){
     	for(int i=0; i<=n-diagonal-1; i++){
     		int j =  diagonal; 
     		M[i][j] = M[i][0] + M[i+1][j-1] + d[i]*d[i+1]*d[i+j+1];
     		P[i][j-1] = i+1;
     		for(int k=i+1; k<=i+j-1; k++){
     			if(M[i][k-i]+M[k+1][i+j-k-1]+d[i]*d[k+1]*d[i+j+1] < M[i][j]){
     				M[i][j] = M[i][k-i]+M[k+1][i+j-k-1]+d[i]*d[k+1]*d[i+j+1];
     				P[i][j-1] = k+1;
				 }
			 }
		 }
	 }
     cout<<"\nmatrix M\n";
	 for(int i=0; i<n; i++)	 {
	 	for(int j=0; j<n-i; j++)
	 		cout<<M[i][j]<<"\t";
	 	cout<<"\n";
	 }
	cout<<"\nmatrix P\n";
	 for(int i=0; i<n-1; i++)	 {
	 	for(int j=0; j<n-1-i; j++)
	 		cout<<P[i][j]<<"\t";
	 	cout<<"\n";
	 }
	 order(1, 4, P, n);
}
	 /*
     For diagonal = 1 to n-1 do {
          For i = 1 to n-diagonal do {
               j = i + diagonal;
               M[i, j] = M[i, i] + M[i+1, j] + d[i-1]*d[i]*d[j];
               P[i, j] = i;
               For k = i+1 to j-1 do{
                    If((M[i, k] + M[k+1, j] + d[i-1]*d[k]*d[j]) < M[i, j]) then {
                         M[i, j] = M[i, k] + M[k+1, j] + d[i-1]*d[k]*d[j];
                         P[i, j] = k;
                    }
               }
          }
     }
     return M[1, n];
}
*/ 
int main(){
	int d[] = {5, 2, 3, 4, 6};
	int n = 4;
	int **M = new int*[n];
	for(int i=0; i<n; i++)
		M[i] = new int[n-i];
	int **P = new int*[n-1];
	for(int i=0; i<n-1; i++)
		P[i] = new int[n-i-1];
	minMul(d, M, P, n);
	return 0;
}
