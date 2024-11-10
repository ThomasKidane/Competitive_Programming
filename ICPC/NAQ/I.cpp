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

// p: 0=down
// p: 1=up
// p: 2=right
// p: 3=left

int howMD(int a,int b,int p,vector<vector<char>> board,int n){
    if(p==0){
        if(board[a][b]=='?'){
            return 1;
        } else if(board[a][b]=='X' || board[a][b]=='0' || board[a][b]=='1' || board[a][b]=='2' || board[a][b]=='3' || board[a][b]=='4'){
            return 0;
        } else if(a==n-1){
            return 0;
        } else {
            return howMD(a+1,b,p,board,n);
        }
    } else if(p==1){
        if(board[a][b]=='?'){
            return 1;
        } else if(board[a][b]=='X' || board[a][b]=='0' || board[a][b]=='1' || board[a][b]=='2' || board[a][b]=='3' || board[a][b]=='4'){
            return 0;
        } else if(a==0){
            return 0;
        } else {
            return howMD(a-1,b,p,board,n);
        }
    }else if(p==2){
        if(board[a][b]=='?'){
            return 1;
        } else if(board[a][b]=='X' || board[a][b]=='0' || board[a][b]=='1' || board[a][b]=='2' || board[a][b]=='3' || board[a][b]=='4'){
            return 0;
        } else if(b==n-1){
            return 0;
        } else {
            return howMD(a,b+1,p,board,n);
        }
    }else if(p==3){
        if(board[a][b]=='?'){
            return 1;
        } else if(board[a][b]=='X' || board[a][b]=='0' || board[a][b]=='1' || board[a][b]=='2' || board[a][b]=='3' || board[a][b]=='4'){
            return 0;
        } else if(b==0){
            return 0;
        } else {
            return howMD(a,b-1,p,board,n);
        }
    }
}
// p: 0=down
// p: 1=up
// p: 2=right
// p: 3=left
int howMFE(int a,int b,vector<vector<char>> board,int n){
    int c=0;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(abs(i)^abs(j)){
                
                if(a+i>=0 && a+i<n && b+j>=0 && b+j<n){
                    // cout<<"Form MFE"<<endl;
                    // dbgv(i);
                    // dbgv(j);
                    // dbgv(a);
                    // dbgv(b);
                    // dbgv(howMD(a,b+j,2,board,n));
                    if(i==1){
                        c+=howMD(a+i,b,0,board,n);
                    } else if(i==-1){
                        c+=howMD(a+i,b,1,board,n);
                    }else if(j==-1){
                        c+=howMD(a,b+j,3,board,n);
                    }else if(j==1){
                        c+=howMD(a,b+j,2,board,n);
                    }
                }
            }
        }
    }
    return c;
}

int howM(int a,int b,vector<vector<char>> board,int n){
    int c=0;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(abs(i)^abs(j)){
                if(a+i>=0 && a+i<n && b+j>=0 && b+j<n){
                    if(board[a+i][b+j]=='?'){c++;}
                }
            }
        }
    }
    return c;
}







void solve(){
    int n;
    cin>>n;

    vector<vector<char>> board(n,vector<char> (n));
    forn(i,n){
        string a;
        cin>>a;
        forn(j,n){
            board[i][j]=a[j];
        }
    }
    forn(i,n){
        forn(j,n){
            if(board[i][j]=='X')continue;
            else if(board[i][j]=='?'){
                if(howMFE(i,j,board,n)!=0){

                    cout<<0<<endl;
                    return;
                }
            }
            else if(board[i][j]=='.'){
                if(howMFE(i,j,board,n)==0){

                    cout<<0<<endl;
                    return;
                }
            } else if(board[i][j]=='0' && howM(i,j,board,n)!=0){
                cout<<0<<endl;
                return;
            } else if(board[i][j]=='1' && howM(i,j,board,n)!=1){
                cout<<0<<endl;
                return;
            }
             else if(board[i][j]=='2' && howM(i,j,board,n)!=2){
                cout<<0<<endl;
                return;
            }
             else if(board[i][j]=='3' && howM(i,j,board,n)!=3){
                cout<<0<<endl;
                return;
            } else if(board[i][j]=='4' && howM(i,j,board,n)!=4){
                cout<<0<<endl;
                return;
            }
        }
    }
    cout<<1<<endl;

}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
