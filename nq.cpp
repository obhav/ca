//nq
#include<iostream>
#include<cmath>
using namespace std;

class nqs {
public:
void Q(int bs);
bool place(int board[],int row,int col);
void display(int board[],int bs);
void snq(int board[],int col,int bs);
};

void nqs :: Q(int bs){
int *board =new int[bs];
for(int i=0;i<bs;i++){
board[i]=0;
}

snq(board,0,bs);
delete[] board;

}

bool nqs :: place(int board[],int row ,int col){
for(int i=0;i<col;i++){
if(board[i]==row || abs(board[i]-row)==abs(i-col)){
return false;
}
}
return true;
}

void nqs :: display(int board[],int bs){
cout<<"\n-----------------------------------------------------------------------\n";
for(int i=0;i<bs;i++){
for(int j=0;j<bs;j++){
cout<< " " << (board[j]==i ? 1 :0);
}
cout<<" \n";
}
}

void nqs :: snq(int board[],int col,int bs){
if(col==bs){
display(board,bs);
return;
}
for(int i=0;i<bs;i++){
if(place(board,i,col)){
board[col]=i;
snq(board,col+1,bs);
}
}


}

int main(){
int n;
cout<<"\nEnter the size of chessboard : ";
cin>>n;
if(n<4){
cout<<"\nSorry, for this value solution is not possible put the value greater than and equal to 4."<<endl;
}
nqs nq;
nq.Q(n);


return 0;
}