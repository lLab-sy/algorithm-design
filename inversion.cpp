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

int solve(vector<int>& A, int l, int r){
	if(l >= r) return 0;
	int m = (l+r)/2, n = r-l+1;
	int res = solve(A, l, m) + solve(A, m+1, r);

	vector<int> s(n);
	int i = 0, j = 0, k = 0;
	int nl = m-l+1, nr = r-m;
	while(i < nl and j < nr){
		if(A[m+1+j] < A[l+i]){
			s[k++] = A[m+1+j++];
			res += nl-i;
		}else{
			s[k++] = A[l+i++];
		}
	}

	while(i < nl) s[k++] = A[l+i++];
	while(j < nr) s[k++] = A[m+1+j++];

	for(int i=0;i<n;++i){
		A[l+i] = s[i];
	}

	return res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	vector<int> A(n);
	for(int i=0;i<n;++i) cin >> A[i];
	cout << solve(A, 0, n-1) << "\n";

	return 0;
}
