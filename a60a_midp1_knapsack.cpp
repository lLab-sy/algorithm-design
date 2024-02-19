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
int dp[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    int V[n+1], W[n+1];
    for(int i=1;i<=n;++i) cin >> V[i];
    for(int i=1;i<=n;++i) cin >> W[i];

    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j) cin >> dp[i][j];
    }

    int len = 0, ans[n], i=n, j=m;

    while(len < n and i > 0 and j > 0){
        if(j >= W[i] and dp[i-1][j-W[i]] == dp[i][j]-V[i]){
            ans[len++] = i;
            j-=W[i];
            i--;
        }
        else if(dp[i-1][j] == dp[i][j]){
            i--;
        }else{
            j--;
        }
    }

    cout << len << "\n";
    for(int i=0;i<len;++i) cout << ans[i] << " ";

    return 0;
}