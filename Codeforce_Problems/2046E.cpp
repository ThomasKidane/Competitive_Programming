// segtree_sparse.cpp
// Eric K. Zhang; Dec. 31, 2017

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define MAXN 100013
#define MAXLGN 18
#define MAXSEG 262144
#define MAXSEG2 (2 * MAXN * MAXLGN * MAXLGN)

int N;
struct node {
	node *l, *r;
	LL x;
} vals[MAXSEG2]; int t = 0;
node* st[MAXSEG];

void update2(node*& n, int i, int x, int lo=0, int hi=-1) {
	if (hi == -1) hi = N - 1;
	if (hi < i || lo > i) return;
	if (!n) n = &vals[t++];
	if (lo == hi) {
		n->x += x;
		return;
	}
	int mid = (lo + hi) / 2;
	if (i <= mid) update2(n->l, i, x, lo, mid);
	else update2(n->r, i, x, mid + 1, hi);
	n->x += x;
}

void update(int i, int j, int x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	if (hi < i || lo > i) return;
	if (lo == hi) {
		update2(st[node], j, x);
		return;
	}
	int mid = (lo + hi) / 2;
	update(i, j, x, lo, mid, 2 * node + 1);
	update(i, j, x, mid + 1, hi, 2 * node + 2);
	update2(st[node], j, x);
}

LL query2(node* n, int s, int e, int lo=0, int hi=-1) {
	if (hi == -1) hi = N - 1;
	if (hi < s || lo > e || !n) return 0;
	if (s <= lo && hi <= e) return n->x;
	int mid = (lo + hi) / 2;
	return query2(n->l, s, e, lo, mid) + query2(n->r, s, e, mid + 1, hi);
}

LL query(int s, int e, int s2, int e2, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	if (hi < s || lo > e) return 0;
	if (s <= lo && hi <= e) return query2(st[node], s2, e2);
	int mid = (lo + hi) / 2;
	return query(s, e, s2, e2, lo, mid, 2 * node + 1)
			+ query(s, e, s2, e2, mid + 1, hi, 2 * node + 2);
}

// int main() {
// 	// N = 100;
// 	update(0, 0, 5);
// 	// update(0, 2, 30);
// 	// update(3, 1, 10);
// 	// update(0, 2, 10);
// 	cout << query(0, 0, 0, 0) << endl;
// }


// #include<bits/stdc++.h>

// // using ll = long long;
// using ld = long double;
// using namespace std;
// #define endl "\n";
// #define ff first
// #define ss second

// #define forn(i,n) for(int i=0;i<n;i++)
// #define dbgv(v) cout<<#v<<" "<<v<<endl
// #define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';
// void solve(){
//     int n;
// 	cin>>n;
// 	vector<pair<int,int>> points;
// 	forn(i,n){
// 		int x,y;
// 		cin>>x>>y;
// 		update(x,y,1);
// 		points.push_back(make_pair(x,y));
// 	}

// 	pair<int,int> best_point;
// 	LL mi=-1;
// 	forn(i,n){
// 		int x=points[i].ff;
// 		int y=points[i].ss;
// 		dbgv(query(x,(int)1e9+1000,y,(int)1e9+100));
// 		if(mi<min(min(query(x,(int)1e9+1000,y,(int)1e9+100),query(-(int)1e9-1000,x,-(int)1e9-1000,y)),min(query(x,(int)1e9+1000,-(int)1e9-1000,y),query(-(int)1e9-1000,x,y,(int)1e9+1000)))){
// 			mi=min(min(query(x,(int)1e9+1000,y,(int)1e9+100),query(-(int)1e9-1000,x,-(int)1e9-1000,y)),min(query(x,(int)1e9+1000,-(int)1e9-1000,y),query(-(int)1e9-1000,x,y,(int)1e9+1000)));
// 			best_point=points[i];
// 		}
// 	}
// 	cout<<mi<<endl;
// 	cout<<best_point.ff<<' '<<best_point.ss<<endl;

	
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int T = 1;
//     cin >> T;

//     while(T--){
//         solve();
//     }
//     return 0;
// }


