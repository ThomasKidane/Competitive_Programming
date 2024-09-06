

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    string s;
    int counter;
    bool A=true;
    while (t--){
        cin>>s;
        A=true;
        for(int x=0;x<s.length();x++){
            if (A){
                if (s[x]!='a')
                    s[x]='a';
                else
                    s[x]='b';

                A=!A;
                } else {
                    if (s[x]!='z')
                        s[x]='z';
                    else
                        s[x]='y';
                A=!A;
                }
        }
        cout<<s<<endl;
    }

}


