#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    int tt,a,b,c;cin>>tt;
    while(tt--){
        cin>>a>>b>>c;
        if(abs(b-c)%2==0 && ((a&&c) || (b&&c) || (a&&c))) cout<<1<<' ';
        else cout<<0<<' ';
        if(abs(a-c)%2==0 && ((a&&c) || (b&&c) || (a&&c))) cout<<1<<' ';
        else cout<<0<<' ';
        if(abs(b-a)%2==0 && ((a&&c) || (b&&c) || (a&&c))) cout<<1<<' ';
        else cout<<0<<' ';
        cout<<'\n';
    }
}


