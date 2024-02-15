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

const int MOD = 100000007;

int dp[3][10000010];
// 0 for end with 0\n0
// 1 -> 1\n0
// 2 -> 0\n1

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    dp[0][1] = 1;
    dp[1][1] = 1;
    dp[2][1] = 1;
    for(int i=2;i<=n;++i){
        dp[0][i] = (dp[0][i-1] + dp[1][i-1] + dp[2][i-1]) % MOD;
        dp[1][i] = (dp[0][i-1] + dp[2][i-1]) % MOD;
        dp[2][i] = (dp[0][i-1] + dp[1][i-1]) % MOD;
    }

    cout << (dp[0][n] + dp[1][n] + dp[2][n]) % MOD << "\n";

    return 0;
}