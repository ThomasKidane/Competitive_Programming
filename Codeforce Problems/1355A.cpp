#include <bits/stdc++.h>
using namespace std;
#define int long long

int minDigit(int g){
    int n=g;
    int a[(int)log(n)+2];
    int Min=n%10;
    for(int i=0;i<(int)log(n)+2;i++){
        a[i]=n%10;
        n=n/10;
        if(a[i]<Min)Min=a[i];
    }
    return Min;
}

int maxDigit(int g){
    int n=g;
    int a[(int)log(n)+2];
    int Max=n%10;
    for(int i=0;i<(int)log(n)+2;i++){
        a[i]=n%10;
        n=n/10;
        if(a[i]>Max)Max=a[i];
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
