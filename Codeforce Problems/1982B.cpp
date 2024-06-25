#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    long long x,y,k;
    long long diff;
    for(int a=0;a<t;a++){
        cin>>x>>y>>k;
        diff=max(((x/y)+1)*y-x,1ll);

        if(diff<=k) {
            while(k>0){
                diff=max(((x/y)+1)*y-x,1ll);
                k-=diff;
                x+=diff;
                while(x%y==0){
                    x=x/y;
                }
                if(x==1){
                    if(y==2){
                        k=0;
                        break;
                    } else {
                        k=k%(y-1);
                        x=k+x;
                        k=0;
                        break;
                    }

                }

                diff=max(((x/y)+1)*y-x,1ll);
                if(k<diff){
                    x+=k;
                    k-=k;
                }
            }
        } else {
            x+=k;
        }


        cout<<x<<endl;
    }
    }


