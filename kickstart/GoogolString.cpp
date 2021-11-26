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
// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000434b3f/0000000000434adc
void solve(int id){
	 ll k;
	 cin >> k;
	 string s = "001";
	 bool toggle = false;
	 while(k > 3){
	 	ll val = *lower_bound(a, a + 63, k);
	 	if(val > k){
	 		val /= 2;
	 	}
	 	k = val - (k - val);
	 	if(k == val){
	 		k = 1;
	 		break;
	 	}
	 	toggle = !toggle;
	 }
	 if(toggle){
	 	s = "110";
	 }
	 cout << "Case #" << id << ": " <<  s[k - 1] << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	a[0] = 1;
	for(int i = 1; i < 63; i++){
		a[i] = a[i - 1] * 2;
	}
    int tc=1;
    cin>>tc;
    for(int i = 1; i <= tc; i++){
    	solve(i);
    }
    return 0;
}
