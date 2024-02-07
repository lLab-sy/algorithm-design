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

int ones[10];

int solve(int n, int k){
    if(n < 0) return 1e9;
    if(n <= 1) return n;
    int div = n/ones[k];
    return div*k + min(solve(n-ones[k]*div, k-1), k+solve(ones[k]*(div+1)-n, k-1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    ones[1] = 1;
    for(int i=2;i<=10;++i){
        ones[i] = ones[i-1]*10 + 1;
    }
    
    cout << solve(n, 10);

    return 0;
}