#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    /* int n=sizeof(word1)/sizeof(char);  Could instead be sizeof(char) for the denominator*/
    int n=s1.length();
    bool Equal=true;
    for (char a: s1){
        if (a!=s2[n-1]){
            Equal=false;
            break;
        }
        n--;
    }
    if(Equal){
        cout<<"YES";
    }else{
    cout<<"NO";
    }

}
