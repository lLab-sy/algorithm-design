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

int bs(vector<int>& A, int l, int r, int k){
	int md = (l+r)/2;
	if(l == r and A[md] <= k) return A[md];
	if(l>=r) return -1;
	
	// cout << A[md] << " hehe\n";
	
	if(A[md] > k){
		return bs(A, l, md-1, k);
	}
	return max(A[md], bs(A, md+1, r, k));
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, Q; cin >> n >> Q;

	vector<int> A(n);
	for(int i=0;i<n;++i) cin >> A[i];

	while(Q--){
		int x; cin >> x;
		cout << bs(A, 0, n, x) << "\n";
	}

	return 0;
}
