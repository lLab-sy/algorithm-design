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

bool solve(int A[], int n){
	int x; cin >> x;
	for(int i=0;i<n-2;++i){
		for(int j=i+1;j<n-1;++j){
			int sum = A[i] + A[j];
			if(x-sum < A[j]) break;
			if(x-sum > A[n-1]) continue;
			if(A[lower_bound(A+j+1, A+n, x-sum)-A] == x-sum) return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, Q; cin >> n >> Q;
	int A[n];
	for(int i=0;i<n;++i) cin >> A[i];

	while(Q--){
		if(solve(A, n)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}