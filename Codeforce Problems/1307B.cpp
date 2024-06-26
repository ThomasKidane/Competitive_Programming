
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int n=0,d=0;
    int counter;
    while (t--){

        cin>>n>>d;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int Min=d%(*max_element(arr,arr+n))+1;

        if(d<*max_element(arr,arr+n)){ //Could also use arr,arr+n but this is safer
            bool yes=false;
            for(int i=0;i<n;i++){
                if (arr[i]==d) {
                    yes=true;
                    break;
                }
            }
            if(yes){
                cout<<1<<endl;
            } else {
                cout<<2<<endl;
            }
        } else {
            int Min=d/(*max_element(arr,arr+n))+1;
            for(int i=0;i<n;i++){
                if (d%arr[i]==0) {
                    Min=min(Min,d/arr[i]);
                } else {
                    Min=min(Min,d/arr[i]+1);
                }
            }
            cout<<Min<<endl;
        }



    }

}


