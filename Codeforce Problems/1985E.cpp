#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    string s;
    int x,y,z,k;
    while (t--){
        set<int> factors;

        int Max=0;
        cin>>x>>y>>z>>k;
        if(x!=max(x,max(y,z))){
            if(y<z) swap(x,z);
            else swap(x,y);
        };
        if(y>z) swap(y,z);

        for(int a=1;a<=ceil(pow(k,0.5));a++){
            if(k%a==0 && a<=x){
                factors.insert(a);
                factors.insert(k/a);
            }
        }
        for(auto i: factors){
            int c=k/i;
            for(int a=1;a<=ceil(pow(c,0.5));a++){
                if((c)%a==0 && a<=y && c/a<=z && x>=max(a,max(i,c/a))){
                    Max=max(Max,((x-i+1)*(y-a+1)*(z-(k/(a*i))+1)));
                }

            }

        }
        cout<<Max<<endl;



}

}
