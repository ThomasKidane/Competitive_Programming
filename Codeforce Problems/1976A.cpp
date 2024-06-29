#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    int n;
    string s;
    bool done=false;
    while (t--){
        cin>>n;
        cin>>s;
        char arr[n];
        done=false;
        for(int x=0;x<n;x++)
            arr[x]=s[x];
        for(int x=0;x<n-1;x++){
            if(arr[x]<='z' && arr[x]>='a' && arr[x+1]<='9' && arr[x+1]>='0'){
              puts("NO");
              done=true;
              break;
            }}
        if(done) continue;
        for(int x=0;x<n-1;x++){
            if(arr[x]<='z' && arr[x]>='a' && arr[x+1]<='z' && arr[x+1]>='a' && arr[x]>arr[x+1]){
              puts("NO");
              done=true;
              break;
            }}
        if(done) continue;
        for(int x=0;x<n-1;x++){
            if(arr[x]<='9' && arr[x]>='0' && arr[x+1]<='9' && arr[x+1]>='0' && arr[x]>arr[x+1]){
              puts("NO");
              done=true;
              break;
            }}
        if(done) continue;
        puts("YES");
    }

}
