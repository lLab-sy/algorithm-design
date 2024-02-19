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

const int M = 10010;
int dp[M];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    int A[n];
    for(int i=0;i<n;++i) cin >> A[i];

    for(int i=1;i<=m;++i){
        dp[i] = 1e6;
        for(int j=0;j<n;++j){
            if(i >= A[j]) dp[i] = min(dp[i], dp[i-A[j]]+1);
        }
    }

    cout << dp[m] << "\n";


    return 0;
}