#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    int t,n;cin>>t;
    set<pair<int,int>> vals;
    while(t--){
        cin>>n;
        vals.clear();
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int counter=0;
        for(int i=0;i<n-1;i++){
            for(int j=((int)(2*(i+1)/arr[i])+1)*arr[i]-i-2;j<n;j+=arr[i]){
                if(arr[i]*arr[j]==(i+j+2) && i<j) vals.insert(pair<int,int> {i,j});
            }
        }
        cout<<vals.size()<<endl;
    }


}
