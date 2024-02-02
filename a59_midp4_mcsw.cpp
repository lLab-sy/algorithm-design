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

    int n, w, sum=0, mx=-1e9; cin >> n >> w;
    deque<pii> dq;
    for(int i=0;i<n;++i){
        int x; cin >> x;
        sum += x;
        
        while(!dq.empty() and i-dq.front().ps >= w) dq.pop_front();
        while(!dq.empty() and dq.back().pf >= sum-x) dq.pop_back();
        dq.push_back(mkp(sum-x, i));
        mx = max(mx, sum-dq.front().pf);
    }

    cout << mx << "\n";

    return 0;
}