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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<ll> qs(n+1, 0);

    for(int i=1;i<=n;++i){
        ll x; cin >> x;
        qs[i] = x+k+qs[i-1];
    }

    while(m--){
        int l;
        ll t;
        cin >> l >> t;

        int r = upper_bound(qs.begin(), qs.end(), t+qs[l])-qs.begin()-1;
        if(r<l+1){
            cout << "0\n";
            continue;
        }
        cout << qs[r]-qs[l]-k*(r-l) << "\n";
    }

    return 0;
}