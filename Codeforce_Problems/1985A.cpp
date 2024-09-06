#include <bits/stdc++.h>
using namespace std;

void createStr(string& a, string& b){
    char c;
    c=b[0];
    b[0]=a[0];
    a[0]=c;
}

int main(){
    int n=0;
    string a,b,c;
    cin>>n;
    for(int i;i<n;i++){
        cin>>a>>b;
        createStr(a,b);
        cout<<a<<" "<<b<<endl;
    }
}
