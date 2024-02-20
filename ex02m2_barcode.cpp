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

const int N = 33;
bool vis[N][N][N][2];
int dp[N][N][N][2];
int m;

int solve(int n, int c, int k, int co){
    if(c > m or k < 0) return 0;
    if(n == 1) return k == 0;
    if(vis[n][c][k][co]) return dp[n][c][k][co];
    vis[n][c][k][co] = true;
    return dp[n][c][k][co] = solve(n-1, c+1, k, co) + solve(n-1, 1, k-1, (co+1)%2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> m >> k;
    cout << solve(n, 1, k, 0) << "\n";

    return 0;
}