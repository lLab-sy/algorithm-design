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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, Q; cin >> n >> m >> Q;

    int dp[n+1][m+1];
    for(int i=0;i<=n;++i) dp[i][0] = 0;
    for(int j=0;j<=m;++j) dp[0][j] = 0;

    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin >> dp[i][j];
            dp[i][j] = dp[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    while(Q--){
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        cout << dp[r2+1][c2+1] - dp[r1][c2+1] - dp[r2+1][c1] + dp[r1][c1] << "\n";
    }

    return 0;
}