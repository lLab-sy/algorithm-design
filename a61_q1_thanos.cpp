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

ll n, a, b;
vector<ll> avg;

ll cavg(ll l, ll r){
    ll pl = lower_bound(avg.begin(), avg.end(), l) - avg.begin();
    ll pr = upper_bound(avg.begin(), avg.end(), r) - avg.begin() - 1;

    if(pr < pl or pl == n or pr < 0 or avg[pr] < l or avg[pl] > r) return 0;
    return pr-pl+1;
}

ll solve(ll l, ll r){
    if(r==l){
        ll cnt = cavg(l, r);
        if(cnt >= 1) return b*cnt;
        return a;
    }

    ll md = (l+r)/2;
    ll cnt = cavg(l, r);
    if(cnt <= 0) return a;

    return min((r-l+1)*b*cnt, solve(l, md) + solve(md+1, r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll p; cin >> p >> n >> a >> b;
    for(ll i=0;i<n;++i){
        ll x; cin >> x;
        avg.emplace_back(x);
    }
    sort(avg.begin(), avg.end());

    cout << solve(1, 1<<p);

    return 0;
}