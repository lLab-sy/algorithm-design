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

const int N = 10010;
int dp[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for(int i=2;i<n+2;++i){
        cin >> dp[i];
        dp[i] += dp[i-2];
        dp[i-1] = max(dp[i-1], dp[i-2]);
    }

    cout << max(dp[n+1], dp[n]) << "\n";

    return 0;
}