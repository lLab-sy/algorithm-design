#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
#define mkp(a, b) make_pair(a, b)

ll maxQ(vector<int>& t, ll k){
	ll mx = 0;
	for(auto e: t){
		mx += k/(ll(e)) + 1;
	}
	return mx;
}

void solve(vector<int>& t){
	ll x; cin >> x;
	ll l = 0, r = 1e15;
	ll res = r;
	while(l<=r){
		ll md = (l+r)/2;

		if(maxQ(t, md) >= x){
			r = md-1;
			res = min(res, md);
		}else{
			l = md+1;
		}

	}

	cout << res << "\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, Q; cin >> n >> Q;

	vector<int> t(n);
	for(int i=0;i<n;++i) cin >> t[i];

	while(Q--) solve(t);

	return 0;
}
