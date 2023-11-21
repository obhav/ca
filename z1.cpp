#include<iostream>
using namespace std;


int max(int x,int y){
return (x>y) ? x : y;
}

void selecteditem(int A[][100],int w[],int n,int kc){
int i=n,j=kc;
cout<<"\nItems included in knapsack : "<<endl;
while(i>0 && j>0){
if(A[i][j] != A[i-1][j]){
cout<<"Item " << i << " is included"<<endl;
j -= w[i-1];
}
i--;
}
}

int ks(int kc,int p[],int w[],int n){
int i,j;
int A[n+1][100];
for(i=0;i<=n;i++){
for(j=0;j<=kc;j++){
if(i==0 || j==0){
A[i][j]=0;
}else if(w[i-1]<=j){
A[i][j]=max(A[i-1][j],A[i-1][j-w[i-1]]+p[i-1]);
}else{
A[i][j]=A[i-1][j];
}
}
}

cout<<"\nMatrix for knapsack : "<<endl;
for(i=0;i<=n;i++){
for(j=0;j<=kc;j++){
cout<< " " << A[i][j];
}
cout<< "\n" ;
}
cout<<"\n" ;

cout<<"\nMaximum profit for the knapsack : "<<A[n][kc]<<endl;
selecteditem(A,w,n,kc);

return 0;
}


int main(){
int i,n,kc;
cout<<"\n Enter the knapsack capacity : ";
cin>>kc;
cout<<"\n Enter the number of items : ";
cin>>n;
int p[n],w[n];
for(i=0;i<n;i++){
cout<<"\nEnter the profit and weight for item "<< i+1 << " :";
cin>>p[i]>>w[i];
}

ks(kc,p,w,n);
return 0;

}
