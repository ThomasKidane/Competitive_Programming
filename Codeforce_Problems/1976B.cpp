#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    int n;
    int diffWithLast;
    int diff;
    int lst;
    while (t--){
        cin>>n;
        int a[n];
        int b[n+1];
        diff=0;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<=n;i++)
            cin>>b[i];
        lst=b[n];
        diffWithLast=abs(*max_element(a,a+n)-lst);
        for(int i=0;i<n;i++){
            diff+=abs(a[i]-b[i]);
            diffWithLast=min(diffWithLast,abs(a[i]-lst));
            diffWithLast=min(diffWithLast,abs(b[i]-lst));
            if((a[i]<=lst && lst<=b[i])||(a[i]>=lst && lst>=b[i])) diffWithLast=0;
        }
        cout<<diff+diffWithLast+1<<endl;

    }

}

