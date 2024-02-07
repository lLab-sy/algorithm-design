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

int calc(pii f, pii s){
    return (f.pf-s.pf)*(f.pf-s.pf) + (f.ps-s.ps)*(f.ps-s.ps);
}

int x2(pii f, pii s){
    return (f.pf-s.pf)*(f.pf-s.pf);
}

int solve(vector<pii>& A, int l, int r){
    if(l==r) return 1e9;
    
    int md = (l+r)/2;
    int sl = solve(A, l, md);
    int sr = solve(A, md+1, r);
    int mn = min(sl, sr);

    vector<pii> sam1,sam2;
    for(int i=l;i<=md;++i){
        if(x2(A[md], A[i]) <= mn){
            sam1.emplace_back(A[i]);
        }
    }

    for(int i=md+1;i<=r;++i){
        if(x2(A[md], A[i]) <= mn){
            sam2.emplace_back(A[i]);
        }
    }

    int n1=sam1.size(), n2=sam2.size();
    for(int i=0;i<n1;++i){
        for(int j=0;j<n2;++j){
            if(x2(sam1[i], sam2[j]) >= mn) break;
            mn = min(mn, calc(sam1[i], sam2[j]));
        }
    }

    return mn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<pii> A(n);
    for(int i=0;i<n;++i){
        int x, y; cin >> x >> y;
        A[i] = mkp(x, y);
    }
    sort(A.begin(), A.end());
    cout << solve(A, 0, n-1);

    return 0;
}