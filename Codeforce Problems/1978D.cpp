    #include <bits/stdc++.h>
    using namespace std;

    long long LongMax(long long arr[],long long n){
        long long Max=arr[0];
        for (int x=0; x<n;x++){
            Max=max(arr[x],Max);
        }
        return Max;
    }

    int main(){
        long long t=0;cin>>t;
        long long n;
        long long k;
        for(long long i=0;i<t;i++){
            cin>>n>>k;
            long long arr[n];
            for(int x=0; x<n;x++){
                cin>>arr[x];
            }
            long long globMax=LongMax(arr,n);
            int MaxCounter=0;
            long long Sum=k;
            bool MaxCanWin=(globMax>arr[0]+k);
            for (int x=0; x<n;x++){

                if (arr[x]==globMax) {
                    if (MaxCanWin && MaxCounter==0){
                    cout<<0<<" ";
                    Sum+=arr[x];
                } else {
                    cout<<x<<" ";
                    Sum+=arr[x];
                }
                MaxCounter++;
                } else if (Sum+arr[x]>=globMax){
                    cout<<x<<" ";
                    Sum+=arr[x];
                } else {
                    cout<<x+1<<" ";
                    Sum+=arr[x];
                }
            }
            cout<<endl;

        }
    }
