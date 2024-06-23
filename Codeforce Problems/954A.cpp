#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    int a;
    int b;
    int c;
    int disA;
    int disB;
    int disC;
    for(int i=0;i<t;i++){
        cin>>a>>b>>c;
        disA=abs(b-a)+abs(c-a);
        disB=abs(a-b)+abs(c-b);
        disC=abs(b-c)+abs(a-c);
        cout<<min(disA,min(disB,disC))<<endl;
    }

}

