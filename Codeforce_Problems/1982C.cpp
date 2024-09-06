#include <bits/stdc++.h>
using namespace std;

void CopyArr(long long arr1[],long long arr2[],int s, int e){
    int counter=0;
    for (int x=s;x<=e;x++){
        arr1[counter]=arr2[x];
        counter++;
    }
}

bool Savable(long long Sum, long long arr[],int s, int e, long long l, long long r){
    long long arrSum[e-s+1];
    CopyArr(arrSum,arr,s,e);
    for(int x=0;x<=e-s;x++){
        if(Sum-arrSum[x]>=l && Sum-arrSum[x]<=r) {
            return true;
        } else {
            Sum-=arrSum[x];

        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    int n=0,wins;
    long long l,r,Sum;
    int s=0,e=0;
    for(int x=0; x<t;x++){
        cin>>n>>l>>r;
        wins=0;
        Sum=0ll;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        e=0;
        s=0;
        for (int i=0;i<n;i++) {
            if(Sum+arr[i]>=l && Sum+arr[i]<=r){
                wins+=1;
                Sum=0ll;
                s=i+1;
                e=i+1;
            } else if(arr[i]>=l && arr[i]<=r){
                wins+=1;
                Sum=0ll;
                s=i+1;
                e=i+1;
            } else if(arr[i]>r){
                Sum=0ll;
                s=i+1;
                e=i+1;
            } else if(Sum+arr[i]>r){
                e=i;
                Sum+=arr[i];
                if (Savable(Sum,arr,s,e,l,r)) {
                    wins+=1;
                    Sum=0ll;
                    s=i+1;
                    e=i+1;
                } else {
                    continue;
                }
            }  else {
                Sum+=arr[i];
                e=i;
            }
        }
        cout<<wins<<endl;
    }

}


