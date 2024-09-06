#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t,n;
    cin>>t;
    list<int> secs;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        secs.push_front(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            secs.push_front(max(secs.front()+1,arr[i]));
        }
        cout<<secs.front()<<endl;
        secs.clear();
    }
}

