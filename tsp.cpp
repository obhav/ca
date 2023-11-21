#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

#define MAX 10 
int N;
int M[MAX][MAX];
int cost=INT_MAX;
int bestpath[MAX];

void tsp(int path[MAX],bool visited[MAX],int bound ,int level){
if(level == N){
int currentcost = bound + M[path[N-1]][path[0]];
if(currentcost<cost){
cost=currentcost;
copy(path,path+N,bestpath);
}
}

for(int i=0;i<N;i++){
if(!visited[i]){
int newbound = bound + M[path[level-1]][i];
if(newbound<cost){
path[level]=i;
visited[i]=true;
tsp(path,visited,newbound,level+1);
visited[i]=false;
}
}
}
}

int main(){
cout<<"\nEnter the  size of distance matrix (max " << MAX << " ) : ";
cin>>N;
if(N > MAX){
cout<<"\nEnter the value less than 10";
return 1;
}
cout<<"\nEnter the  Distance matrix :\n" ; 
for(int i=0;i<N;i++){
for(int j=0;j<N;j++){
cin>> M[i][j];
}
}

int path[MAX];
bool visited[MAX]={false};
path[0]=0;
visited[0]=true;

tsp(path,visited,0,1);


cout<<"\nMIN COST : "<<cost;
cout<<"\nBEST PATH : ";
for(int i=0;i<N;i++){
cout<< bestpath[i] << " --> ";
}
cout<< bestpath[0] << endl;
return 0;
}