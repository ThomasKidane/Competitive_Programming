#include <bits/stdc++.h>
using namespace std;

void ApplyToB(string& a,string& b, int n){
    if (n<=2){
    } else {
        for(int x=0;x<n-2;x++){
            if(a[x]=='0' && a[x]==a[x+2]){
                b[x+1]='1';
            }
        }
    }
}

void ApplyToA(string& a,string& b, int n){
    if (n<=2){
    } else {
        for(int x=0;x<n-2;x++){
            if(b[x]=='1' && b[x]==b[x+2]){
                a[x+1]='1';
            }
        }
    }
}

int count1(string a, int n){
    int score=0;
    for(int i=0;i<n;i++){
        if(a[i]=='1') score++;
    }
    return score;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    int n;
    string s;
    string c;
    int q;
    int l;
    int r;
    string a;
    string b;
    int Counter=0;
    for (int test=0;test<t;test++){
        cin>>n;
        cin>>s;cin>>c;
        cin>>q;
        a=s;
        b=c;
        int sums[n];
        ApplyToB(a,b,n);
        ApplyToA(a,b,n);
        int preRes=0;
        for(int i=n-1;i>=0;i--){
            if(a[i]=='1') {
                sums[i]=++preRes;
                }
            else; sums[i]=preRes;
        }
        for (int x=0;x<q;x++){
            cin>>l>>r;
            if(r-l+1<6){
                string w1,w2;
                w1=s.substr(l-1,r-l+1);
                w2=c.substr(l-1,r-l+1);
                ApplyToB(w1,w2,r-l+1);
                ApplyToA(w1,w2,r-l+1);
                cout<<count1(w1,r-l+1)<<endl;
            } else {
                string w1,w2;
                int score=0;
                score+=sums[l+2]-sums[r-3];
                w1=s.substr(l-1,6);
                w2=c.substr(l-1,6);
                ApplyToB(w1,w2,6);
                ApplyToA(w1,w2,6);
                score+=count1(w1.substr(0,3),2);
                w1=s.substr(r-6,6);
                w2=c.substr(r-6,6);
                ApplyToB(w1,w2,6);
                ApplyToA(w1,w2,6);
                score+=count1(w1.substr(4,3),2);
                cout<<score<<endl;
            }

        }
    }

}

