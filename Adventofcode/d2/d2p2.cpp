#include<bits/stdc++.h>
#include <sstream>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';

bool valid(vector<int> v){
    bool sign=v[1]>v[0];
    if(v[1]==v[0] || abs(v[0]-v[1])==0 || abs(v[0]-v[1])>3){
        return false;
    } else {
        for(int i=1;i<v.size()-1;i++){
            if(sign){
                if(v[i+1]<=v[i]){
                    return false;
                }
                if(v[i+1]-v[i]>3){
                    return false;
                }
            } else {
                if(v[i+1]>=v[i]){
                    return false;
                }
                if(v[i]-v[i+1]>3){
                    return false;
                }
            }
        }
        return true;
    }
}


bool validforall(vector<int> v){
    bool any=false;
    any|=valid(v);
    vector<int> d=v;
    for(int i=0;i<v.size();i++){
        d=v;
        d.erase(d.begin()+i);
        any|=valid(d);
    }
    return any;
}


void solve(){
    string line;

    // cout << "Enter a line of text: ";
    int c=0;
    
    while(getline(cin, line)){
        stringstream ss(line);
        int d;
        vector<int> vals;        
        while (ss >> d) {
            // Process each word
            vals.push_back(d);
        }
        // dbga(vals,vals.size());

        if(validforall(vals)){
            c++;
        }
    }

    cout<<c<<endl;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
