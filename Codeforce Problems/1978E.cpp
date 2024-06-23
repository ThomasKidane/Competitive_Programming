#include <bits/stdc++.h>
using namespace std;

void ApplyToB(string& a,string& b, int n){
    if (n<=2){
    } else {
        for(int x=0;x<n-2;x++){
            if(a[x]=='0' && a[x]==a[x+2]){
                b[x+1]='1';
            }
        }
    }
}

void ApplyToA(string& a,string& b, int n){
    if (n<=2){
    } else {
        for(int x=0;x<n-2;x++){
            if(b[x]=='1' && b[x]==b[x+2]){
                a[x+1]='1';
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    int n;
    string s;
    string c;
    int q;
    int l;
    int r;
    string a;
    string b;
    int Counter=0;
    for (int test=0;test<t;test++){
        cin>>n;
        cin>>s;cin>>c;
        cin>>q;
        for (int x=0;x<q;x++){
            cin>>l>>r;
            int len=r-l+1;
            a=s.substr(l-1,len);
            b=c.substr(l-1,len);
            ApplyToB(a,b,len);
            ApplyToA(a,b,len);
            Counter=0;
            for (int y=0;y<len;y++){
                if (a[y]=='1'){
                    Counter++;
                }
            }
            cout<<Counter<<endl;
        }
    }

}

