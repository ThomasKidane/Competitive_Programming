#include <bits/stdc++.h>
using namespace std;
#define int long long

int minDigit(int g){
    int n=g;
    int Min=n%10;
    int d;
    while(n){
        d=n%10;
        n=n/10;
        if(d<Min)Min=d;
    }
    return Min;
}

int maxDigit(int g){
    int n=g;
    int Max=n%10;
    int d;
    while(n){
        d=n%10;
        n=n/10;
        if(d>Max)Max=d;
    }
    return Max;
}

int nextN(int n){
    return (n+minDigit(n)*maxDigit(n));
}

signed main(){
    int t=0,n,d;cin>>t;
    while(t--){
        cin>>n>>d;
        while(minDigit(n)!=0 && d>1){
            n=nextN(n);
            d-=1;
        }
        cout<<n<<endl;

    }

}
