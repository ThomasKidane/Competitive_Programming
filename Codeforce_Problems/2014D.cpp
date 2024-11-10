#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';


#include <vector>
#include <deque>

vector<int> findMaxSlidingWindow(std::vector<int>& arr, int windowSize) {
    int n = arr.size();
    if (windowSize > n) {
        throw std::invalid_argument("Window size cannot be greater than array size.");
    }

    deque<int> dq; // Deque to store indices of elements
    vector<int> result(n - windowSize + 1);

    for (int i = 0; i < n; i++) {
        // Remove elements from the front of the deque that are no longer in the window
        while (!dq.empty() && dq.front() <= i - windowSize) {
            dq.pop_front();
        }

        // Remove elements from the back of the deque that are smaller than the current element
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        // Add the current element's index to the back of the deque
        dq.push_back(i);

        // If the current window size is reached, store the maximum element in the result
        if (i >= windowSize - 1) {
            result[i - windowSize + 1] = arr[dq.front()];
        }
    }

    return result;
}

void solve(){
    int n,d,k;
    cin>>n>>d>>k;
    // vector<pair<int>> jobs;
    vector<int> arr(n,0);
    int ps[n]={0};
    int mi[n]={0};
    forn(i,k){
        int p1,p2;
        cin>>p1>>p2;
        p1--;
        ps[p1]++;
        if(p2<=n-1)mi[p2]--;
    }
    // cout<<"Start"<<endl;
    // dbga(ps,n);
    // dbga(mi,n);
    vector<int> prefS(n-d+1);
    // prefS[0]=arr[0];
    int s=0;
    forn(i,d){
        s+=ps[i];
    }
    prefS[0]=s;
    for(int i=d;i<n;i++){
        prefS[i-d+1]=prefS[i-d];
        prefS[i-d+1]+=ps[i];
        prefS[i-d+1]+=mi[i-d+1];
    }

    // for(int i=1;i<prefS.size();i++){
    //     prefS[i]=prefS[i-1]+arr[i];
    // }
    // cout<<"Pres"<<endl;
    // dbga(prefS,prefS.size());
    
    // vector<int> mini=findMaxSlidingWindow(prefS,d);
    // vector<int> mani=findMaxSlidingWindow(prefS,d);
    // cout<<"this"<<endl;
    // dbga(mini,mini.size());
    // dbga(mani,mani.size());

    // int ps[n]=[]

    int mn=0;
    int mnv=prefS[0];
    int mx=0;
    int mvx=prefS[0];
    forn(i,prefS.size()){
        if(mnv>prefS[i]){
            mnv=prefS[i];
            mn=i+1;
        }
        if(mvx<prefS[i]){
            mvx=prefS[i];
            mx=i+1;
        }
    }

    cout<<max(mx,1)<<' '<<max(1,mn)<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
