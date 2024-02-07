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

int helper(int n){
    if(n <= 1){
        return n;
    }
    return 2*helper(n/2) + n%2;
}

int solve(int n, int l, int r, int s, int e){
    if(l>e or r<s) return 0;
    else if(s>=l and e<=r) return helper(n);
    else if(n <= 1) return 0;
    int len = e-s, cen=0;
    if(l <= s+len/2 and r >= s+len/2) cen = n%2;
    return solve(n/2, l, r, s, s+len/2-1) + cen + solve(n/2, l, r, s+len/2+1, e);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, l, r; cin >> n >> l >> r;

    int len = 1, mul = 1;
    for(int i=n;i>1;i/=2){
        len = mul*2 + mul + len - mul;
        mul = mul*2;
    }

    cout << solve(n, l, r, 1, len);


    return 0;
}