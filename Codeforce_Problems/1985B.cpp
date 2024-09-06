#include <bits/stdc++.h>
using namespace std;

int findRes(int x,int n){
    int k=n/x;
    return (k*(k+1)*x/2);
}



int main(){
    int t,n;
    int a=2;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int abx=0;
        a=2;
        for (int x=2;x<=n;x++){
            if (findRes(x,n)>abx){
                a=x;
                abx=findRes(x,n);
            }
        }
        cout<<a<<endl;
    }
}
