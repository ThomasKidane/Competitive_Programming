#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    int a,b,n;
    bool won=true;
    while (t--){
        cin>>a>>b>>n;
        int attack[n];
        int health[n];
        int totalDamage=0;
        won=true;
        for(int x=0;x<n;x++)
            cin>>attack[x];

        for(int x=0;x<n;x++)
            cin>>health[x];

        for(int x=0;x<n;x++){
            if(health[x]%a!=0) totalDamage+=(health[x]/a+1)*attack[x];
            else totalDamage+=(health[x]/a)*attack[x];
        }


        if(b-totalDamage>=0 || *max_element(attack,attack+n)>abs(b-totalDamage)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

}
