#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t=0,n;cin>>t;
    string s;
    map<char,int> alph;
    while(t--){
        cin>>s;
        alph.clear();
        for(int i=0;i<s.length();i++){
            alph[s[i]]+=1;
        }
        int GM=s.length();
        for(map<char,int>::iterator it1=alph.begin();it1!=alph.end();it1++){
            int MaxI=0;
            int L=0;
            for(int i=0;i<s.length();i++){
                if(s[i]==it1->first){
                    L=0;
                } else {
                L+=1;
                if(MaxI<L) MaxI=L;
                }
            }
            int steps=0;
            while(MaxI>0){
                if(MaxI>2 && MaxI%2==0) MaxI/=2;
                else if(MaxI>2 && MaxI%2==1) MaxI=MaxI-(MaxI+1)/2;
                else {steps+=MaxI;break;}
                steps++;
            }

            if(GM>steps)GM=steps;
        }
        cout<<GM<<endl;

    }

}


