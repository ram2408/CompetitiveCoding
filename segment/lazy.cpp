#pragma GCC optimize("O3")
#include <bits/stdc++.h>   

#define rep(i,a,n) for(int i=a;i<n;i++)
#define mod 1000000007
#define N 1000005
#define se second
#define fi first
#define pie 3.14159265359
#define pll pair<ll,ll> 
#define pb push_back
#define sz(x) (int)x.size()
typedef long long ll;
#define X 11
using namespace std;
ll tree[N];
ll lazy[N];
ll a[N];
ll x;
void build(ll n, ll s, ll e){
	lazy[n]=0;
	if(e==s){
		tree[n]=a[s];
		return;
	}
	ll m = (s + e) / 2;
	build(2*n, s, m);
	build(2*n+1, m+1, e);
	tree[n]=max(tree[2*n],tree[2*n+1]);
}
void relax(ll n, ll s, ll e){
	ll val=lazy[n];
	tree[n]+=val;
	if(s != e){
		lazy[2*n] += val;
		lazy[2*n+1] += val;
	}
	lazy[n] = 0;
}
void update(ll n, ll s, ll e, ll qs, ll qe,ll val){
	//cout<<n<<" "<<s<<" "<<e<<"\n";
	relax(n,s,e);
	if(s>e||qs>e||qe<s)return;
	if(s>=qs&&e<=qe){
		tree[n] += val;
		if(s != e){
			lazy[2*n] += val;
			lazy[2*n + 1] += val;
		}
		return;
	}
	ll m = (s + e) / 2;
	update(2*n, s, m, qs, qe, val);
	update(2*n + 1, m + 1, e, qs, qe, val);
	tree[n]=max(tree[2*n],tree[2*n+1]);
}
ll query(ll n, ll s, ll e, ll qs, ll qe){
	relax(n,s,e);
	if(s > e || qs > e || qe < s){
		return 0;
	}
	if(s >= qs and e <= qe){
		return tree[n];
	}
	ll m = (s + e) / 2;
	return max(query(2*n, s, m, qs, qe),query(2*n+1, m+1, e, qs, qe));
}
void solve(){
	 ll n, q;
	 cin >> n >> q;
	 a[0]=0;
	 rep(i, 0, n){
	 	cin >> a[i+1];
	 }
	 memset(tree,0,sizeof(tree));
	 memset(lazy,0,sizeof(lazy));
	 build(1,1,n);
	 while(q--){
	 	ll t,l,r;
	 	cin >> t >> l >> r;
	 	if(t == 1){
	 		ll val;
	 		cin >> val;
	 		update(1,1,n,l,r,val);
	 	}
	 	else{
	 		cout << query(1, 1, n, l, r) << "\n";
	 	}
	 }
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int tc=1;
	//cin>>tc;
	while(tc--)solve();
  	return 0;
}