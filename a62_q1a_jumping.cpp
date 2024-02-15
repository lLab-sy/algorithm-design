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

int dp[5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for(int i=0;i<3;++i) dp[i] = -2e9;
    cin >> dp[2];
    for(int i=2;i<=n;++i){
        cin >> dp[3];
        dp[3] += max(dp[0], max(dp[1], dp[2]));
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = dp[3];
    }

    cout << dp[2] << "\n";

    return 0;
}