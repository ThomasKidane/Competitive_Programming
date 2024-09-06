#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b,Max=0;
    int cur=0;
    cin>>n;
    for(int i;i<n;i++){
        cin>>a>>b;
        cur=cur-a+b;
        Max=max(0,max(cur,Max));
    }
    cout<<Max;
}
