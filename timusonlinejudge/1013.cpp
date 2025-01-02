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
#define REP(i, n) for(int i = 0; i < (n); i++)

struct Matrix {
	long long a[2][2];
    ll mod;
	Matrix(ll mm,ll k) {
        mod=mm;
		
        if(k!=0){
            a[0][0]=0;           
            a[0][1]=1;
            a[1][1]=k-1;
            a[1][0]=k-1;
        } else {
            REP(i, 2) {
			REP(j, 2) {
				a[i][j] = 0;
			}
		}
        }
        // a[0][0]=0;
        // a[0][1]=1;
        // a[1][0]=v[1][1]=k-1;
	}
	Matrix operator *(Matrix other) {
		Matrix product = Matrix(this->mod,0);
		REP(i, 2) {
			REP(j, 2) {
				REP(k, 2) {
					product.a[i][k] += (a[i][j] * other.a[j][k])%mod;
					product.a[i][k] %= mod;
				}
			}
		}
		return product;
	}
};
Matrix expo_power(Matrix a, long long n) {
	Matrix res = Matrix(a.mod,0);
	res.a[0][0] = res.a[1][1] = 1;
	while(n) {
		if(n % 2) {
			res = res * a;
		}
		n /= 2;
		a = a * a;
	}
	return res;
}

void solve(){
    ll n,k,m;
    cin>>n>>k>>m;
    // vector<vector<ll>> v(2,vector<ll>(2,k-1));
    // v[0][0]=0;
    // v[0][1]=1;

    Matrix v=Matrix(m,k);
    Matrix res=expo_power(v,n-2);
    // dbgv(res.a[0][0]);
    if(n!=1){
        cout<<((k-1)*((res.a[0][0]+res.a[0][1])+((res.a[1][0]+res.a[1][1])*(k-1))%m)%m)%m<<endl;
    } else {
        cout<<k-1<<endl;
    }
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
