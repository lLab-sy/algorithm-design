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

int dp[5005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    dp[0] = 1;
    for(int i=1;i<=n;++i){
        if(i >= k) dp[i] += dp[i-k];
        else dp[i] = 1;
        dp[i] = (dp[i] + dp[i-1]) % MOD;
    }

    cout << dp[n] << "\n";

    return 0;
}