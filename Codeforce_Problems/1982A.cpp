#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int a1=0,b1=0;
    int a2=0,b2=0;
    for(int x=0;x<t;x++){
        cin>>a1>>b1;
        cin>>a2>>b2;
        if((a1>b1)!=(a2>b2)){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }

    }
}
