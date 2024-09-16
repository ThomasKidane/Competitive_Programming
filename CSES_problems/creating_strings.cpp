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

void addString(int n,string s,set<string> &  words,int let[]){
    if(n==1){
        forn(i,26){
            if(let[i]==1){
                words.insert(s+=char('a'+i));
            }
        }
    } else {
        forn(i,26){
            if(let[i]>0){
                //words.insert(s+=char('a'+i));
                let[i]-=1;
                addString(n-1,s+char('a'+i),words,let);
                let[i]+=1;
            }
        }
    }
}


void solve(set<string> words){
    string s;
    cin>>s; 

    int let[26]={0};
    forn(i,s.length()){
        let[s[i]-'a']+=1;
    }
    string d="";
    addString(s.length(),d,words,let);
    cout<<words.size()<<endl;
    for(auto it=words.begin();it!=words.end();it++){
        cout<<(*it)<<endl;
    }
}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        set<string> words;
        solve(words);
    }
    return 0;
}
