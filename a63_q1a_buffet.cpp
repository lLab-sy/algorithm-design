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

const int N = 200020;
int A[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, m; cin >> n >> k >> m;
    for(int i=1;i<=n;++i){
        cin >> A[i];
        A[i] += A[i-1]-m;
    }

    while(k--){
        int s, w; cin >> s >> w;
        int p = lower_bound(A+s, A+n+1, A[s-1]+w) - A;
        cout << p << "\n";
    }


    return 0;
}