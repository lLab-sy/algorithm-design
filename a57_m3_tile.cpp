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

int dp[11][10010];
int A[11];

int solve(int c, int m){
    if(c == 0) return (m==0)?0:1e6;
    if(m <= 0) return 1e6;
    if(dp[c][m] != 0) return dp[c][m];
    dp[c][m] = solve(c-1, m-A[c]*A[c]);
    for(int i=1;i<=100;++i){
        dp[c][m] = min(dp[c][m], (A[c]-i)*(A[c]-i) + solve(c-1, m-i*i));
    }

    return dp[c][m];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i=1;i<=n;++i) cin >> A[i];
    cout << ((solve(n, m) >= 1e6)?-1:dp[n][m]) << "\n";

    return 0;
}