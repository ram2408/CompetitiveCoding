#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
#define rep(i,a,n) for(int i=a;i<n;i++)
#define mod 1000000007
#define N 200005
#define se second
#define fi first
#define pie 3.14159265359
#define pll pair<ll,ll>
#define pb push_back
#define sz(x) (int)x.size()
#define endl "\n"
 
#define debug2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
 
typedef long long ll;
ll a[63];
using namespace std;
// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000434b3f/00000000004347b7
void solve(int id){
	ll n,m;
	cin >> n >> m;
	double a[n+5] = {0};
	rep(i, 1, n + 1){
		cin>> a[i];
		a[i] = log10(a[i]) + a[i - 1];
	}
	cout << "Case #" << id << ":\n";
	while(m--){
		ll l,r;
		cin >> l >> r;
		//cout << l << r << endl;
		l += 1;
		r += 1;
		ll diff = r - l + 1;
		double baseValue = a[r] - a[l - 1];
		baseValue /= diff;
		cout << pow(10.0, baseValue) << endl;
	}
}
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout.precision(10);
    int tc=1;
    cin>>tc;
    for(int i = 1; i <= tc; i++){
    	solve(i);
    }
    return 0;
}
