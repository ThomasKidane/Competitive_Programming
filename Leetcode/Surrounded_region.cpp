using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';


    bool enc(int a,int b,vector<vector<int>>& seen,vector<vector<char>> &board,int n,int m){
        bool res=true;
        seen[a][b]=1;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if((abs(i)^abs(j))){
                    // cout<<"Here"<<endl;
                    if(a==0 || a==n-1 || b==0 || b==m-1){
                        return false;
                    } else {
                        if(board[a+i][b+j]!='X' && !seen[a+i][b+j]){
                            res=res&&enc(a+i,b+j,seen,board,n,m);
                            if(!res)return res;
                        }
                    }
                }
            }
        }
        return res;
    }
    void fill(int a,int b,vector<vector<char>> & board,vector<vector<int>>& seen2){
        seen2[a][b]=1;
        cout<<"To be filled"<<endl;
        dbgv(a);
        dbgv(b);
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if((abs(i)^abs(j))){
                    if(board[a+i][b+j]=='X')continue;
                    board[a+i][b+j]='X';
                    cout<<"Execution"<<endl;
                    dbgv(a+i);
                    dbgv(b+j);
                    dbgv(seen2[a+i][b+j]);
                    if(!seen2[a+i][b+j]){
                        cout<<"Did it"<<endl;
                        seen2[a+i][b+j]=1;
                        fill(a+i,b+j,board,seen2);
                    }
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> seen(n,vector<int> (m)); 
        vector<vector<int>> seen2(n,vector<int> (m));
        forn(i,n){
        forn(j,m){
            seen2[i][j]=0;
            seen[i][j]=0;
            }
        }
        forn(i,n){
            forn(j,m){
                cout<<"About"<<endl;
                dbgv(i);
                dbgv(j);
                seen[i][j]=1;
                if(board[i][j]=='X')continue;
                else {
                    dbgv(i);
                    dbgv(j);
                    dbgv(enc(i,j,seen,board,n,m));
                    if(enc(i,j,seen,board,n,m)){
                        fill(i,j,board,seen2);
                    }
                }

            }
        }

    }


int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
