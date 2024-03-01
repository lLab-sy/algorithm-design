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

const int N = 505;
int dp[N][N], A[N];
bool vis[N][N];

int solve(int l, int r){
    if(l >= r) return 0;
    if(vis[l][r]) return dp[l][r];
    vis[l][r] = true;
    dp[l][r] = solve(l+1, r);
    for(int i=l+1;i<=r;++i){
        dp[l][r] = max(dp[l][r], A[l]*A[i] + solve(l+1, i-1) + solve(i+1, r));
    }
    return dp[l][r];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for(int i=1;i<=n;++i) cin >> A[i];
    cout << solve(1, n) << "\n";


    return 0;
}