#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;
    int n;
    int mn=0,cur_am=0;
    int minI=0;
    while(t--){
        cin>>n;
        int arr[n];
        cur_am=0;
        mn=0;
        minI=0;
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++){
            cur_am+=arr[i];
            if(cur_am<mn){mn=cur_am;minI=i;}
        }
        cur_am=0;
        for(int i=0;i<n;i++){
            if(i==minI) cur_am=abs(arr[i]+cur_am);
            else cur_am+=arr[i];
        }
        cout<<cur_am<<endl;
    }
}


