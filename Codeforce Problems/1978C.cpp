#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t=0;cin>>t;
    long long n;
    long long k;
    for(long long i=0;i<t;i++){
        cin>>n>>k;
        if(k%2==1 || k>n*n/2){
            cout<<"No"<<endl;
        } else {
            cout<<"Yes"<<endl;
            long long arr[n];
            for (long long x=0;x<n;x++){
                arr[x]=x+1;
            }
            long long a=1;
            while (true){
                if (k>2*(n-(2*a-1))){
                    swap(arr[a-1],arr[n-a]);
                    k-=(2*(n-2*a+1));
                    a+=1;
                } else if (k==2*(n-(2*a-1))){
                    swap(arr[a-1],arr[n-a]);
                    break;
                } else {
                    for (long long y=0;y<k/2;y++){
                        swap(arr[a],arr[a+1]);
                        a++;
                    }
                    break;
                }
            }
            for (long long x=0;x<n;x++){
                cout<<arr[x]<<" ";
            }
            cout<<endl;
        }
    }
}
