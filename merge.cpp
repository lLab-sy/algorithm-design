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

void solve(vector<int>& A, int l, int r, int& k){
	if(k == 0 or A.back() == -1) return ;
	if(k < 0){
		A.back() = -1;
		return;
	}
	if(l+1 == r or l > r){
		return;
	}
	int md = (l+r)/2;
	if(md != 0) swap(A[md-1], A[md]);
	k-=2;
	solve(A, l, md, k);
	solve(A, md, r, k);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, k; cin >> n >> k;
	vector<int> A(n+1);
	for(int i=0;i<=n;++i) A[i] = i+1;
	k--;
	solve(A, 0, n, k);
	if(A[n] == -1 or k != 0){
		cout << "-1";
		return 0;
	}
	A.pop_back();
	for(auto v: A){
		cout << v << " ";
	}

	return 0;
}
