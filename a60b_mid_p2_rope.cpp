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

int dp[4004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b, c; cin >> n >> a >> b >> c;
    for(int i=1;i<=n;++i){
        dp[i] = -1e6;
        if(i>=a) dp[i] = max(dp[i], dp[i-a]+1);
        if(i>=b) dp[i] = max(dp[i], dp[i-b]+1);
        if(i>=c) dp[i] = max(dp[i], dp[i-c]+1);
    }

    cout << dp[n] << "\n";

    return 0;
}