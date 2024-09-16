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
    string s;
    cin>>s;
    map<char,int> dic;
    vector<int> letters(26,0);
    forn(i,s.length()){
        letters[int(s[i])-'A']+=1;
    }
    // dbga(letters,26);
    int x=0,y=0;
    forn(i,26){
        if(letters[i]%2==0){x++;}
        else y++;
    }
    if(y>1)cout<<"NO SOLUTION";
    else {
        int i=0;
        bool flag=false;
        int toB;
        int freq;
        int la;
        forn(j,26){
            if(letters[j]%2==1){
                toB=j;
                freq=letters[j];
                flag=true;
            }
            else{
                for(int k=0;k<letters[j];k+=2){
                    s[i]=char('A'+j);
                    s[s.length()-i-1]=char('A'+j);
                    i++;
                    la=i;
                }
            }
        }
        if(flag){
            // la++;
            forn(j,freq){
                s[la]=char('A'+toB);
                la++;
            }
        }
        // dbgv(toB);
        cout<<s<<endl;
    }
}

int main() {
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
