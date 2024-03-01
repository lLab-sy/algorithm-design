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
int A[N], k;
int dp[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n >> k;
    for(int i=1;i<=n;++i) cin >> A[i];
    
    dp[0] = 2e9;
    for(int i=1;i<=k+1 and i<=n;++i) dp[i] = A[i];
    for(int i=1;i<=n;++i){
        if(i>k+1) dp[i] = dp[i-1] + A[i];
        for(int j=max(i-2*k-1, 1);j<i;++j){
            dp[i] = min(dp[i], dp[j]+A[i]);
        }
    }

    int mn = dp[n];
    for(int i=max(n-k, 1);i<=n;++i) mn = min(mn, dp[i]);

    cout << mn << "\n";
    return 0;
}