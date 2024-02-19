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
#define pf first
#define ps second

const int N = 505;
const int MOD = 1997;
int dp[N][N];

int solve(int n, int k){
    if(n == k) return 1;
    if(k == 1) return 1;
    if(dp[n][k] != 0) return dp[n][k];
    return dp[n][k] = (solve(n-1, k-1) + k*solve(n-1, k)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    cout << solve(n, k) << "\n";

    return 0;
}