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

const int N = 1010;
int dp[2][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    int mx = 0;
    for(int i=1;i<=n;++i){
        string line; cin >> line;
        int cur = i%2, pv = (i+1)%2;
        for(int j=0;j<m;++j){
            dp[cur][j+1] = 0;
            if(line[j] == '1'){
                dp[cur][j+1] = min(dp[pv][j], min(dp[cur][j], dp[pv][j+1]))+1;
            }
            mx = max(mx, dp[cur][j+1]);
        }
    }

    cout << mx << "\n";
    return 0;
}