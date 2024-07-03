#include <bits/stdc++.h>
using namespace std;

#define int long long
/*
bool isPrime(int n,map<int,map<int,int>> Mem){
    if(Mem.count(n)){
        return (Mem[n][n]);
    } else {
        if(n==1ll) return false;
    if (n==2ll) return true;
    int a=2ll,b=(int)(pow(n,0.5));
    while(a<=b){
        if(n%a==0ll) return false;
        a++;
    }
    Mem[n][n]+=1;
    return true;
    }


}

map<int,int> primeDivisors(int n,map<int,map<int,int>> Mem){
    if(!Mem.count(n)){
       map<int,int> prime_fact;
    if(n==1ll) return prime_fact;
    int counter=2ll;
    while(counter<=n){

        if((n%counter)==0ll){
            prime_fact[counter]+=1ll;
            n=(n/counter);
            if(isPrime(n,Mem)){
            prime_fact[n]+=1;
            break;
        }
            while(n%counter==0ll){
                prime_fact[counter]+=1ll;
                n=(n/counter);
                if(isPrime(n,Mem)){
            prime_fact[n]+=1;
            break;
        }
            }
        }
        counter++;
    }

    Mem[n]=prime_fact;
    return Mem[n];

    } else return Mem[n];

}

map<int,int> gcd(map<int,int> a1,map<int,int> a2){
    map<int,int> Min;
    for(map<int,int>::iterator it1=a1.begin();it1!=a1.end();it1++){
        Min[it1->first]=min(it1->second,a2[it1->first]);
    }
    return Min;
}

int Num(map<int,int> a1){
    int i=1ll;
    for(map<int,int>::iterator it1=a1.begin();it1!=a1.end();it1++){
        i*=(int)(pow(it1->first,it1->second));
    }
    return i;
}
*/

signed main(){
    int t,n,c;cin>>t;

    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0ll;i<n;i++){
            cin>>arr[i];
        }
        c=arr[0];
        for(int i=1ll;i<n;i++){
            c=__gcd(c,arr[i]);
        }
        if(c==1ll){cout<<0ll<<endl;}
        else if(__gcd(c,__gcd(arr[n-1],n))==1ll) {cout<<1ll<<endl;}
        else if(__gcd(c,__gcd(arr[n-2],n-1))==1ll) {cout<<2ll<<endl;}
        else {cout<<3ll<<endl;}

    }
}
