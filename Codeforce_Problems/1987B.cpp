#include <bits/stdc++.h>
using namespace std;
#define int long long

long long Ncoins(int arr[],int &forDp){
    int Sum=0;
    if(forDp==0) return 0;
    for(int i=0;i<forDp;i++)
        Sum+=arr[i];
    Sum+=arr[forDp-1];
    return Sum;
}


signed main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int counter=0;
        int curmx=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]<curmx) counter++;
            else if(arr[i]>curmx) curmx=arr[i];
        }
        int difs[counter];
        int forDp=0;
        curmx=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]<curmx) {difs[forDp]=curmx-arr[i];forDp++;}
            else if(arr[i]>curmx) curmx=arr[i];

            if(forDp==counter) break;
        }
        sort(difs,difs+forDp);
        cout<<Ncoins(difs,forDp)<<endl;


    }
}
