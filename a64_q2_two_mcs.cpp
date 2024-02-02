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
#define mkt(a, b, c) make_tuple(a, b, c);
#define pf first
#define ps second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n+1, 0);
    for(int i=1;i<=n;++i) cin >> a[i];
    
    vector<int> dp1(n+1, a[1]), dp2(n+1, a[n]);
    int mx = a[1];
    dp1[0] = 0;
    for(int i=2;i<=n;++i){
        mx = max(mx+a[i], a[i]);
        dp1[i] = max(dp1[i-1], mx);
    }
    mx = a[n];
    for(int i=n-1;i>=1;--i){
        mx = max(mx+a[i], a[i]);
        dp2[i] = max(dp2[i+1], mx);
    }

    for(int i=1;i<=n;++i){
        mx = max(mx, dp1[i-1]+dp2[i]);
    }

    cout << mx << "\n";

    return 0;
}