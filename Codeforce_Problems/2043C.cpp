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

int maxSubarraySum(vector<int> &arr) {
    if(arr.empty()){
        return 0;
    }
    int res = arr[0];
    int maxEnding = arr[0];

    for (int i = 1; i < arr.size(); i++) {
      
        // Find the maximum sum ending at index i by either extending 
        // the maximum sum subarray ending at index i - 1 or by
        // starting a new subarray from index i
        maxEnding = max(maxEnding + arr[i], arr[i]);
      
        // Update res if maximum subarray sum ending at index i > res
        res = max(res, maxEnding);
    }
    return res;
}


int minSubarraySum(vector<int> &arr) {
    if(arr.empty()){
        return 0;
    }
    int res = arr[0];
    int maxEnding = arr[0];
    

    for (int i = 1; i < arr.size(); i++) {
      
        // Find the maximum sum ending at index i by either extending 
        // the maximum sum subarray ending at index i - 1 or by
        // starting a new subarray from index i
        maxEnding = min(maxEnding + arr[i], arr[i]);
      
        // Update res if maximum subarray sum ending at index i > res
        res = min(res, maxEnding);
    }
    return res;
}



void solve(){
    int n;
    cin>>n;
    int a[n];
    bool there=false;
    int ind;
    forn(i,n){
        cin>>a[i];
        if(a[i]!=1 && a[i]!=-1){
            there=true;
            ind=i;
        }
    }

    if(there){
        vector<int> vals1;
        vector<int> vals2;
        for(int i=0;i<ind;i++){
            vals1.push_back(a[i]);
        }
        for(int i=ind+1;i<n;i++){
            vals2.push_back(a[i]);
        }

        int mx1=maxSubarraySum(vals1);
        int mx2=maxSubarraySum(vals2);

        int mi1=minSubarraySum(vals1);
        int mi2=minSubarraySum(vals2);
        set<int> val;
        // set<int> val2;
        for(int i=min(0,mi1);i<=max(0,mx1);i++){
            val.insert(i);
        }
        for(int i=min(0,mi2);i<=max(0,mx2);i++){
            val.insert(i);
        }

        ll mi11=0;
        ll mx11=0;
        ll mi22=0;
        ll mx22=0;
        ll cur=0;
        for(int i=ind+1;i<n;i++){
            cur+=a[i];
            mx11=max(cur,mx11);
            mi11=min(cur,mi11);
        }
        cur=0;
        for(int i=ind-1;i>=0;i--){
            cur+=a[i];
            mx22=max(cur,mx22);
            mi22=min(cur,mi22);
        }
        for(int i=min(0ll,mi11+mi22);i<=max(0ll,mx11+mx22);i++){
            val.insert(a[ind]+i);
        }
        
        cout<<val.size()<<endl;

        for(auto it=val.begin();it!=val.end();it++){
            cout<<*it<<' ';
        }
        cout<<endl;
        
        // maxSubarraySum()
    } else {
        // ind=0;
        vector<int> vals1;
        // vector<int> vals2;
        for(int i=0;i<n;i++){
            vals1.push_back(a[i]);
        }
        // for(int i=ind+1;i<n;i++){
        //     vals2.push_back(a[i]);
        // }

        int mx1=maxSubarraySum(vals1);
        // int mx2=maxSubarraySum(vals2);

        int mi1=minSubarraySum(vals1);
        // int mi2=minSubarraySum(vals2);
        set<int> val;
        // set<int> val2;
        for(int i=min(0,mi1);i<=max(0,mx1);i++){
            val.insert(i);
        }
        // for(int i=min(0,mi2);i<=max(0,mx2);i++){
        //     val.insert(i);
        // }

        // ll mi11=0;
        // ll mx11=0;
        // ll mi22=0;
        // ll mx22=0;
        // ll cur=0;
        // for(int i=ind+1;i<n;i++){
        //     cur+=a[i];
        //     mx11=max(cur,mx11);
        //     mi11=min(cur,mi11);
        // }
        // cur=0;
        // for(int i=ind-1;i>=0;i--){
        //     cur+=a[i];
        //     mx22=max(cur,mx22);
        //     mi22=min(cur,mi22);
        // }
        // for(int i=min(0ll,mi11+mi22);i<=max(0ll,mx11+mx22);i++){
        //     val.insert(a[ind]+i);
        // }
        cout<<val.size()<<endl;
        for(auto it=val.begin();it!=val.end();it++){
            cout<<*it<<' ';
        }
        cout<<endl;
    }

    
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
