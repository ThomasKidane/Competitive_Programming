#include <bits/stdc++.h>
using namespace std;

signed main(){
    int tt,n,m,d;cin>>tt;
    while(tt--){
        cin>>n>>m;
        int a[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        int x=0;
        if(n*m!=1){
            for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<a[(((x+1)%(m*n))/m)][((x+1)%(m*n))%m]<<" ";
                x++;
            }
            cout<<'\n';
        }
        }
        else cout<<-1<<endl;
    }
}
