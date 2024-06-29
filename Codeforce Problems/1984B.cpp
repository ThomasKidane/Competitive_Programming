#include <bits/stdc++.h>
using namespace std;

signed main(){
    int t;
    cin>>t;
    long long n;
    string s;
    bool done=true;
    while(t--){
        cin>>n;
        done=true;
        s=to_string(n);
        if(s[s.length()-1]=='9' || s[0]!='1'){
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=s.length()-2;i>=0;i--){
            if (s[i]=='0'){
                done=false;
                cout<<"NO"<<endl;
                break;
            }
        }
        if(done) cout<<"YES"<<endl;
    }
}

