#include<bits/stdc++.h>
using namespace std;

void sort(vector<int> &a,int i){
    if(i==a.size()-1) return;
    int index=i;
    for(int j=i+1;j<a.size();j++){
        if(a[j]>a[index]){
            index=j;
        }
    }
    swap(a[i],a[index]);
    sort(a,i+1);
}


int main(){
vector<int> a  ={1,2,3,5,7};
    

    sort(a,0);
    for(int i=0;i<a.size();i++) cout<<a[i]<<endl;
}