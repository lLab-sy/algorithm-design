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

const int N = 50001;
const int D = 501;
int lc[N], rc[N], deg[N], res, d;

vector<int> solve(int u){
    if(u == 0) return vector<int>(D, 0);

    vector<int> ld = solve(lc[u]), rd = solve(rc[u]), dis(D, 0);
    dis[0] = 1;
    dis[d] = rd[d-1] + ld[d-1];
    res += dis[d];
    for(int i=1;i<d;++i){
        res += ld[i-1]*rd[d-i-1];
        dis[i] = ld[i-1] + rd[i-1];
    }
    return dis;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n >> d;
    for(int i=0;i<n-1;++i){
        int a, b; cin >> a >> b;
        if(lc[a] == 0) lc[a] = b;
        else rc[a] = b;
    }

    solve(1);
    cout << res;

    return 0;
}