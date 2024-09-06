#include <bits/stdc++.h>
using namespace std;

int dif(string a,string b,int m){
    int Df=0;
    for(int i=0;i<m;i++){
        Df+=abs(int(a[i])-int(b[i]));
    }
    return Df;
}


signed main(){
    int t,n,m;cin>>t;
    while(t--){
        cin>>n>>m;
        string arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int Min=dif(arr[0],arr[1],m);
        for(int i=0;i<n-1;i++){
            for(int y=i+1;y<n;y++){
                if(dif(arr[i],arr[y],m)<Min) Min=dif(arr[i],arr[y],m);
            }

        }
        cout<<Min<<endl;
    }
}
