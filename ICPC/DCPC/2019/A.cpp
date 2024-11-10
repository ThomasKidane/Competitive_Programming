#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';
void solve(){
    int n;
    cin>>n;
    map<int,bool> dic;
    int A=65;
    
    forn(i,n){
        string d;
        cin>>d;
        if(d=="T"){
            dic[A]=true;
        } else {
            dic[A]=false;
        }
        
        A++;
    }
    string line;
    vector<string> lines;

    while (getline(cin, line)) {
        lines.push_back(line);
    }
    

    
    string lastLine = lines.back();
    
    vector<bool> vals;
    for(int i=0;i<lastLine.size();i++){
        if(lastLine[i]!=' ' && lastLine[i]!='+'&& lastLine[i]!='*'&& lastLine[i]!='-'){
            vals.push_back(dic[(int)lastLine[i]]);
        } else if(lastLine[i]=='-'){
            bool val=vals.back();
            vals.pop_back();
            vals.push_back(!val);
        } else if(lastLine[i]=='+'){
            bool a=vals.back();
            vals.pop_back();
            bool b=vals.back();
            vals.pop_back();
            vals.push_back(a||b);
        } else if(lastLine[i]=='*'){
            bool a=vals.back();
            vals.pop_back();
            bool b=vals.back();
            vals.pop_back();
            vals.push_back(a&&b);
        }
    }
    if(vals.back()){
        cout<<"T"<<endl;
    } else {
        cout<<"F"<<endl;
    }

}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
