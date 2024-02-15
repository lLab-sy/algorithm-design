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

const int N = 5005;
int dp[2][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for(int j=0;j<=m;++j) dp[0][j] = -2e9;
    dp[0][0] = 0;
    for(int i=1;i<=n;++i){
        int cur = i%2, pv = (i+1)%2;
        dp[cur][0] = -2e9;
        for(int j=1;j<=m;++j){
            cin >> dp[cur][j];
            dp[cur][j] = max(((i!=1)?2*dp[cur][j]:dp[cur][j]) + dp[pv][j-1], dp[cur][j] + max(dp[pv][j], dp[cur][j-1]));
        }
    }

    cout << dp[n%2][m] << "\n";

    return 0;
}