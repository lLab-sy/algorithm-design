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

    int n; cin >> n;
    
    int dp[2][n+1], mx = -2e9;
    dp[1][0] = -2e9;
    for(int j=0;j<=n;++j) dp[0][j] = -2e9;
    for(int i=0;i<n;++i){
        int pv = i%2, cur = (i+1)%2;
        for(int j=1;j<=n;++j){
            int x; cin >> x;
            dp[cur][j] = max(x, dp[pv][j-1]+x);
            mx = max(mx, dp[cur][j]);
        }
    }

    cout << mx << "\n";

    return 0;
}