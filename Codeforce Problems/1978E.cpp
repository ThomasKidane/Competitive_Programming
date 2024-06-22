#include <bits/stdc++.h>
using namespace std;

void ApplyToB(string& a,string& b, int n){
    if (n<=2){
        continue
    } else {
        for(int x=0;x<n-2;x++){
            if(a[x]==0 && a[x]==a[x+2]){
                b[x+1]='1';
            }
        }
    }
}

int main(){
    int t;cin>>t;
    int n;
    string s;
    string t;
    int q;
    int l;
    int r;
    string a;
    string b;
    for (int test=0;test<n;test++){
        cin>>n;
        cin>>s;cin>>t;
        cin>>q;
        for (int x=0;x<q;x++){
            cin>>l>>r;
            a=s.substr(l-1,l-r-1);
            b=t.substr(l-1,l-r-1);
            len=l-r-1;
            ApplyToB(a,b,len);
        }
    }

}

