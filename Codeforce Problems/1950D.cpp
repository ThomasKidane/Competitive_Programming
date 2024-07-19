#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bitset<int(1e5+20)> binary;
bitset<5> Tbs;
int bs[30];

int dec(bitset<5> Tbs){
    int n=Tbs.size();
    int S=0;
    for(int i=0;i<n;i++){
        if(Tbs[i])S+=pow(10,i);
    }
    return S;
}

bool isBinary(int n){
    if(n==1){
        return true;
    } else{
        bool res=false;
        for(int i=0;i<30;i++){
            if(n%bs[i]==0) {
                    res=res||isBinary(n/bs[i]);
                if(res) break;
                }
        }
        return res;
    }
}

void makeRight(){
    for(int i=2;i<32;i++){
        Tbs=i;
        bs[i-2]=dec(Tbs);
    }
    for(int i=1;i<1e5+20;i++){
        if(isBinary(i))binary.set(i);
    }
}


signed main(){
    int tt,n;cin>>tt;
    makeRight();
    while(tt--){
        cin>>n;
        if(binary[n])cout<<"YES\n";
        else cout<<"NO\n";
    }
}
