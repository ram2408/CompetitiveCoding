//https://codeforces.com/contest/628/problem/D
#pragma GCC optimize("O3")
#include <bits/stdc++.h>   

#define rep(i,a,n) for(int i=a;i<n;i++)
#define mod 1000000007
#define N 2005
#define se second
#define fi first
#define pie 3.14159265359
#define pll pair<ll,ll> 
#define pb push_back
#define sz(x) (int)x.size()
typedef long long ll;

using namespace std;

ll m,d;
ll dp[N][N][2];
string s;

ll digitDp(ll pos,ll val,ll t){
	if(pos==s.size()){
		return val==0;
	}
	ll &ret=dp[pos][val][t];
	if(ret != -1){
		return ret;
	}
	ll ans=0;
	ll lim;
	if(t)lim=9;
	else lim=s[pos]-'0';
	if(pos%2){
		int nt=t;
		if(t==0&&d>lim)return 0;
		if(t==0&&d<lim)nt=1;
		ans=digitDp(pos+1,(val*10+d)%m,nt) % mod;
	} 
	else{
		rep(i,0,lim+1){
			int nt=t;
			if(t==0&&i<lim)nt=1;
			if(i==d)continue;
			ans+=digitDp(pos+1,((val*10)+i)%m,nt);
			ans %= mod;
		}
	}
	ret=ans;
	return ret;
}

ll solve2(string a){
	memset(dp,-1,sizeof(dp));
	s=a;
	return digitDp(0,0,0);
}
void solve(){
	cin >> m >> d;
	string a,b;
	cin >> a >> b;
	ll ans=solve2(b) - solve2(a);
	int l = a.size(), f = 1, an =0;
	 cout << ans << "\n";
	rep(i, 0, l){
		if(i%2 and (a[i]-'0')!=d) f = 0;
		if(i % 2 == 0 and (a[i]-'0') == d) f = 0;
		an=an*10+(a[i]-'0');
		an %= m;
	}
	if(an)f=0;
	ans += f;
	cout << ans << "\n";	 
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int tc=1;
	//cin>>tc;
	while(tc--)solve();
  	return 0;
}