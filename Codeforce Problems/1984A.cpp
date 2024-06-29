#include <bits/stdc++.h>
using namespace std;

signed main(){
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if (arr[n-1]==arr[0]) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            cout<<"RB";
            n-=2;
            while(n--) cout<<"R";
            cout<<endl;
        }

    }
}
