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
    
    string s1, s2; cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();

    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s1[i-1] == s2[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
        }
    }

    cout << dp[n][m] << "\n";

    return 0;
}