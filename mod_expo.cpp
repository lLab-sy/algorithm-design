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

unordered_map<int, int> mem;

int solve(int x, int n, int k){
	if(mem.find(n) != mem.end()) return mem[n];
	if(n == 0) return 1%k;
	else if(n == 1) return x%k;
	return mem[n] = (solve(x, n/2, k) * solve(x, n-n/2, k))%k;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int x, n, k; cin >> x >> n >> k;
	cout << solve(x, n, k);
	return 0;
}
