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

const int N = 200002;
int dp[2][N], n, w, k;
int dp2[55][2][N];

int solve1(){
    for(int i=1;i<=n;++i) cin >> dp[0][i];
    for(int i=1;i<=n;++i) cin >> dp[1][i];

    for(int i=1;i<=n;++i){
        if(i > w) {
            dp[0][i] += dp[1][i-w-1];
            dp[1][i] += dp[0][i-w-1];
        }
        dp[0][i] = max(dp[0][i], dp[0][i-1]);
        dp[1][i] = max(dp[1][i], dp[1][i-1]);
    }

    return max(dp[0][n], dp[1][n]);
}

int solve2(){
    for(int i=1;i<=n;++i) cin >> dp2[0][0][i];
    for(int i=1;i<=n;++i) cin >> dp2[0][1][i];

    for(int i=1;i<=n;++i){
        dp2[1][0][i] = max(dp2[1][0][i-1], dp2[0][0][i]);
        dp2[1][1][i] = max(dp2[1][1][i-1], dp2[0][1][i]);
    }
    for(int i=2;i<=k;++i){
        for(int j=1;j<=n;++j){
            if(j <= w){
                dp2[i][0][j] = dp2[i-1][0][j];
                dp2[i][1][j] = dp2[i-1][1][j];
            }else{
                dp2[i][0][j] = dp2[i-1][1][j-w-1] + dp2[0][0][j];
                dp2[i][1][j] = dp2[i-1][0][j-w-1] + dp2[0][1][j];
            }
            dp2[i][0][j] = max(dp2[i][0][j-1], dp2[i][0][j]);
            dp2[i][1][j] = max(dp2[i][1][j-1], dp2[i][1][j]);
        }
    }

    return max(dp2[k][0][n], dp2[k][1][n]);
}

int recur2(int r, int isL, int u){
    if(u<1 || r<1) return 0;
    if(dp2[r][isL][u] != 0) return dp2[r][isL][u];
    return dp2[r][isL][u] = max(recur2(r, isL, u-1), dp2[0][isL][u] + recur2(r-1, (isL+1)%2, u-w-1));
}

int solve2recur(){
    for(int i=1;i<=n;++i) cin >> dp2[0][0][i];
    for(int i=1;i<=n;++i) cin >> dp2[0][1][i];
    return max(recur2(k, 0, n), recur2(k, 1, n));
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> w >> k;
    cout << ((n==k)?solve1():solve2recur()) << "\n";

    return 0;
}