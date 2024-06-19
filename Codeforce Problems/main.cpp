#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int cA,cD=0;
    string s;
    cin>>n>>s;
    const char* word=s.c_str();
    for (int i;i<n;i++){
        if (word[i]=='A'){
            cA++;
        } else if(word[i]=='D') {
            cD++;
        }

    }
    if (cA>cD){
        cout<<"Anton";
    } else if(cA<cD){
        cout<<"Danik";
    } else {
        cout<<"Friendship";
    }

}
