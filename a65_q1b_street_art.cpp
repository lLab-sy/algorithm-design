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

const ll W = 1e18;
unordered_map<ll, unordered_map<ll, ll> > dp;
ll A[100010];
int n;

ll countInRange(ll l, ll r){
    return upper_bound(A+1, A+n+1, r) - lower_bound(A+1, A+n+1, l);
}

ll solve(ll b, ll c){
    ll res = countInRange(b, c);
    if(c-b+ll(1) < 3 || res == 0) return res;
    
    ll p1, p2, p3;
    ll u = (c-b+ll(1))/ll(3);
    ll v = (c-b+ll(2))/ll(3);
    p1 = solve(b, b+u-ll(1));
    p2 = solve(b+u, b+u+v-ll(1));
    p3 = solve(b+u+v, c);
    ll mn = min(p1, min(p2, p3));
    return res + p1 + p2 + p3 - mn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll w; cin >> w >> n;

    for(int i=1;i<=n;++i) cin >> A[i];
    sort(A+1, A+n+1);

    cout << solve(1, w) << "\n";


    return 0;
}