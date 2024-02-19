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
const int MOD = 1000003;

int dp[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    int A[k];
    for(int i=0;i<k;++i) cin >> A[i];

    dp[0] = 1;
    for(int i=1;i<=n;++i){
        for(int j=0;j<k;++j){
            if(i >= A[j]) dp[i] = (dp[i] + dp[i-A[j]]) % MOD;
        }
    }

    cout << dp[n] << "\n";

    return 0;
}