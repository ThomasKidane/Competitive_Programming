#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
// #define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';

pair<int,int> padding(int a,int b,int m,int o){
    // Missing number of bits
    
    if(o==1){
        int aa=a;
        int bb=b;
        // forn(i,m){
        //     bb|=(1<<i);
        // }
        aa|=(1<<m);
        bb|=(1<<m);
        return make_pair(aa,bb);
    } else if(o==2){
        int aa=a;
        int bb=b;
        forn(i,m+1){
            aa|=(1<<i);
        }
        forn(i,m){
            bb|=(1<<i);
        }
        return make_pair(aa,bb);
    } else {
        int aa=a;
        aa|=(1<<m);
        return make_pair(aa,b);
    }
}

pair<int,int> ask(int a,int b, int p,int o,int m){
    // dbgv(o);
    // dbgv(p);
    // dbgv(m);
    // parity is the order of questions, normal is 0 with a>b, 1 is b<a and is asked accordingly
    // o - operation number 1- check for equality of bits in unequal numbers, 2-check if bit of a is set, 3 - check bit of equal numbers
    int v=0;
    if(o==1){
        // Numbers are unequal, check if bit m is set of a
        
        if(p%2==0){
            // a is bigger
            pair<int,int> ques=padding(a,b,m,o);
            int aa=ques.ff;
            int bb=ques.ss;
            cout<<"? "<<aa<<' '<<bb<<endl;
            cin>>v;
            if(v==-1){
                // bit is set
                a|=(1<<m);
            } else {
                // check for the sign of the equal bits
                pair<int,int> ques=padding(a,b,m,2);
                int aa=ques.ff;
                int bb=ques.ss;
                cout<<"? "<<aa<<' '<<bb<<endl; 
                cin>>v;
                if(v==-1){
                    a|=(1<<m);
                    b|=(1<<m);
                }
            }
        }else {
            // b is bigger
            pair<int,int> ques=padding(b,a,m,o);
            int aa=ques.ss;
            int bb=ques.ff;
            cout<<"? "<<aa<<' '<<bb<<endl<<endl;
            cin>>v;
            if(v==1){
                // bit is set
                b|=(1<<m);
            } else {
                // check for the sign of the equal bits
                pair<int,int> ques=padding(b,a,m,2);
                int aa=ques.ss;
                int bb=ques.ff;
                cout<<"? "<<aa<<' '<<bb<<endl; 
                cin>>v;
                if(v==1){
                    a|=(1<<m);
                    b|=(1<<m);
                }
            }
        }
        
    } else if(o==3){
        pair<int,int> ques=padding(a,b,m,3);
        int aa=ques.ff;
        int bb=ques.ss;
        cout<<"? "<<aa<<' '<<bb<<endl;
        cin>>v;
        if(v==-1){
            a|=(1<<m);
            b|=(1<<m);
        }
    }

    return make_pair(a,b);
}

void solve(){
    bool equal=false;
    // Check for Equality
    cout<<"? 0 0"<<endl;
    int v;
    cin>>v;
    int a=0;
    int b=0;
    int o=1;
    if(v==0){
        // Equal
        for(int i=29;i>=0;i--){
            pair<int,int> vals=ask(a,b,0,3,i);
            a=vals.ff;
            b=vals.ss;
        }
    } else{
        // a greater than b or something
        int p;
        int pa=0;
        int pb=0;
        if(v==1){
            p=0;
        } else {
            p=1;
        }
        for(int i=29;i>=0;i--){
            
            pair<int,int> vals=ask(a,b,p,o,i);
            a=vals.ff;
            b=vals.ss;
            if(a>pa && (a&(1<<i))!=(b&(1<<i)) && p==0){
                cout<<"? "<<a<<' '<<b<<endl;
                cin>>v;
                if(v==1){
                    // a is still greater than b
                    p=0;
                } else if(v==-1){
                    p=1;
                    //
                } else {
                    o=3;
                }
            } else if(b>pb &&(a&(1<<i))!=(b&(1<<i))&& p==1){
               cout<<"? "<<a<<' '<<b<<endl;
                cin>>v;
                if(v==1){
                    // a is still greater than b
                    p=0;
                } else if(v==-1){
                    p=1;
                    //
                } else {
                    o=3;
                } 
            }
            pa=a;
            pb=b;
            // if(a>b){
                
            // }
        }
    }
    cout<<"! "<<a<<' '<<b<<endl;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
