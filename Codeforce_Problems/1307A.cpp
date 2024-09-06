#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int n=0,d=0;
    while (t--){

        cin>>n>>d;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];}

        for(int x=0;x<d;x++){
            int i=1;
            bool found=false;
            if(n>1){
                for(i;i<n;i++){
                    found=false;
                    if (arr[i]>0){


                        found=true;
                        break;}
                }
                if (found){
                    arr[i]-=1;
                arr[i-1]+=1;
                }

            } else {
            break;
        }

        }
        cout<<arr[0]<<endl;


    }

}


