#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

struct Item {
int profit,weight;
Item () : profit(0),weight(0) {}
Item (int p,int w) : profit(p),weight(w) {}
};

bool cp( const Item& a ,const Item& b ){
    return a.profit > b.profit ; 

}

bool cw(const Item& a, const Item& b){
    return a.weight < b.weight ;

}

bool cpw(const Item& a, const Item& b){
    return (double)(a.profit) / a.weight > (double)(b.profit) / b.weight;

}

double fk(Item items[],int cap,int num, function<bool(const Item& ,const Item&)> comp){
sort(items,items+num,comp);
int cw=0;
double tp=0.0;
for(int i=0;i<num;i++) {
if(cw+items[i].weight<=cap){
    cw += items[i].weight;
    tp += items[i].profit;
}else{
    int rc=cap-cw;
    tp += items[i].profit * (double)(rc) / items[i].weight;
    break;
}

}
return tp;
}

int main(){
  int cap , num ;
  int p,w;
  cout<<"\nEnter the knapsack capacity : ";
  cin>>cap;
  cout<<"\nEnter the number of items : ";
  cin>>num;
Item items[num];
  for(int i=0;i<num;i++){
    cout<<"\nEnter the profit and weight for item " << i << " : " ;
    cin>> p >> w;
    items[i]=Item(p,w);
  }
cout<<"MAX profit (by maxprofit) : " <<fk(items,cap,num,cp) << endl;
cout<<"MAX profit (by minweight) : " <<fk(items,cap,num,cw) << endl; 
cout<<"MAX profit (by maxp/w) : " <<fk(items,cap,num,cpw) << endl;
    return 0;
}