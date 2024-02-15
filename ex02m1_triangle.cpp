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

int dp[2][111];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for(int i=1;i<=n;++i){
        int pv = (i+1)%2, cur = i%2;
        dp[cur][0] = -2e9;
        dp[cur][i+1] = -2e9;
        for(int j=1;j<=i;++j){
            cin >> dp[cur][j];
            dp[cur][j] += max(dp[pv][j], dp[pv][j-1]);
        }
    }

    int mx = -2e9;
    for(int j=1;j<=n;++j) mx = max(mx, dp[n%2][j]);
    
    cout << mx << "\n";
    
    return 0;
}