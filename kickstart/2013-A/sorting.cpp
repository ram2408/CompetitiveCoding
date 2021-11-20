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
using namespace std;

void solve(int cases){
	 ll n;
	 cin >> n;
	 vector<int> odd, even, total;
	 int t;
	 for(int i = 0; i < n; i++){
	 	cin >> t;
	 	if(t & 1){
	 		odd.push_back(t);
	 	}
	 	else{
	 		even.push_back(t);
	 	}
	 	total.push_back(t);
	 }
	 sort(odd.begin(), odd.end());
	 sort(even.begin(), even.end());
	 int i = 0, j = 0, k = even.size() - 1;
	 cout << "Case #"<< cases << ": "; 
	 while(i < n){
	 	if(total[i] & 1){
	 		cout << odd[j++] << " ";
	 	}
	 	else{
	 		cout << even[k--] << " ";
	 	}
	 	i++;
	 }
	 cout << endl;

}
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;

    cin>>tc;
    int tc2 = tc;
    while(tc--)solve(tc2 - tc);
    return 0;
}
