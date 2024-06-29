#include <bits/stdc++.h>
using namespace std;
//#define int long long

const int N=2e2+20;
int a[N],b[N],c[N];
vector<vector <int>> weapons(N);
vector<vector <int>> goodWeapons(N);

bool sortcol(vector<int>& v1,vector<int>& v2)
{
    return v1[0] < v2[0];
}

bool sortcol1(vector<int>& v1,vector<int>& v2)
{
    return v1[0] > v2[0];
}

int maxRet(vector<vector<int>> goodWeapons,int metals,int n){
    int counter=0;
    int score=0;
    int points=metals;
    while(counter<n){
        if(points>=goodWeapons[counter][0]){
            score+=2;
            points-=goodWeapons[counter][1];
        } else {
        counter++;
    }
    }
    return score;
}


signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<m;i++) cin>>c[i];
    for(int i=0;i<n;i++){
        weapons[i]=vector<int>(2);
        weapons[i][0]=a[i];
        weapons[i][1]=a[i]-b[i];
    }
    sort(weapons.begin(),weapons.begin()+n, sortcol);
    goodWeapons[0]=weapons[0];
    int counter=1;
    for(int i=0;i<n-1;i++) {
        if(weapons[i][1]>weapons[i+1][1]) {
        goodWeapons[counter]=weapons[i+1];
        counter++;
        }
    }

    sort(goodWeapons.begin(),goodWeapons.begin()+counter, sortcol1);
    int score=0;
    for(int i=0;i<=n;i++){
        score+=maxRet(goodWeapons,c[i],counter);
    }
    cout<<score<<endl;
}




