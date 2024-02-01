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

ll smx(vector<ll> &a, int l, int r){
    ll sum = a[l], mx = a[l];
    for(int i=l+1;i<=r;++i){
        sum += a[i];
        mx = max(mx, sum);
    }
    return mx;
}

ll fmx(vector<ll> &a, int l, int r){
    ll sum = a[r], mx = a[r];
    for(int i=r-1;i>=l;--i){
        sum += a[i];
        mx = max(mx, sum);
    }
    return mx;
}

ll solve(vector<ll> &a, int l, int r){
    if(l == r) return a[l];

    int md = (l+r)/2;
    return max(smx(a, md+1, r)+fmx(a, l, md), max(solve(a, l, md), solve(a, md+1, r)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;++i) cin >> a[i];
    cout << solve(a, 0, n-1);

    return 0;
}