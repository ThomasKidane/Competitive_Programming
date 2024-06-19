#include <bits/stdc++.h>
using namespace std;

void arrFill(long long arr[],int n){
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
}

int main(){
    int t,n,counter;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        long long arr[n];
        arrFill(arr,n);
        counter=0;
        long long Sum=0;
        long long Max=arr[0];
        for (int i=0;i<n;i++){
            Sum+=arr[i];
            Max=max(arr[i],Max);
            if(Sum-Max==Max){
                counter++;
            }

        }
        cout<<counter<<endl;

    }
}

