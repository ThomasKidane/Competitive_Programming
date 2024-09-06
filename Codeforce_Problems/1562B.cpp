#include <bits/stdc++.h>
using namespace std;
//#define int long long

void solve(string s,int n){
    for(int i=0;i<n;i++){
        if(s[i]=='1' || s[i]=='4' || s[i]=='6' || s[i]=='8' || s[i]=='9') {cout<<"1"<<endl<<s[i]<<endl;return;}
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(s[i]==s[j]) {cout<<"2"<<endl<<s[i]<<s[i]<<endl;return;}
        }
    }
    for(int i=n-1;i>0;i--){
        if(s[i]=='2' || s[i]=='5') {cout<<"2"<<endl<<s[0]<<s[i]<<endl;return;}
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(s[i]=='2' && '7'==s[j]) {cout<<"2"<<endl<<s[i]<<s[j]<<endl;return;}
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(s[i]=='5' && '7'==s[j]) {cout<<"2"<<endl<<s[i]<<s[j]<<endl;return;}
        }
    }

    cout<<n<<endl<<s<<endl;
}

signed main(){
    int t,n;cin>>t;
    string s;
    while(t--){
        cin>>n;
        cin>>s;
        solve(s,n);
    }
}
