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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	vector<int> r(n, 0);
	int mx = 0;
	for(int i=0;i<n;++i){
		int cnt = 0;
		for(int j=0;j<n;++j){
			int x; cin >> x;
			cnt += x;
		}
		mx = max(mx, cnt);
		r[cnt]++;
	}

	for(int i=0;i<=mx;++i) cout << r[i] << " ";

	return 0;
}
