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

const int N = 110;
int dp[N][N];
int A[N];

int solve(int l, int r){
    if(l==r) return 0;
    if(dp[l][r] != 0) return dp[l][r];
    int mn = 2e9;
    for(int i=l;i<r;++i){
        mn = min(mn, solve(l,i) + solve(i+1, r) + A[l]*A[i+1]*A[r+1]);
    }
    return dp[l][r] = mn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for(int i=0;i<=n;++i) cin >> A[i];
    cout << solve(0, n-1) << "\n";

    return 0;
}