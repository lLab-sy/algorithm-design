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
int dp[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    
    int len=0;
    for(int i=0;i<n;++i){
        int x; cin >> x;
        int p = upper_bound(dp, dp+len, x) - dp;
        dp[p] = x;
        len = max(len, p+1);
    }

    cout << len << "\n";

    return 0;
}