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

int mat[2][2];

int solve(ll n, ll r, ll c){
    if(n == 2){
        return mat[r-1][c-1];
    }

    ll md = n/2;
    if(r <= md and c <= md) return solve(md, r, c);
    else if(r <= md and c > md) return solve(md, c-md, r);
    else if(r > md and c <= md) return -solve(md, r-md, c);
    return -solve(md, c-md, r-md);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, Q; cin >> n >> Q;
    cin >> mat[0][0] >> mat[0][1] >> mat[1][0] >> mat[1][1];
    
    while(Q--){
        ll r, c; cin >> r >> c;
        cout << solve(ll(1) << n, r, c) << "\n";
    }

    return 0;
}