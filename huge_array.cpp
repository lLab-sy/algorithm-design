#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
#define mkp(a, b) make_pair(a, b)

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, Q; cin >> n >> Q;
	
	vector<pii> A;
	for(int i=0;i<n;++i){
		int x, c; cin >> x >> c;
		A.emplace_back(x, c);
	}
	sort(A.begin(), A.end());

	swap(A[0].first, A[0].second);
	for(int i=1;i<n;++i){
		A[i].second += A[i-1].first;
		swap(A[i].first, A[i].second);
	}

	while(Q--){
		int p; cin >> p;
		cout << (*lower_bound(A.begin(), A.end(), mkp(p, 0))).second << "\n";
	}

	return 0;
}
