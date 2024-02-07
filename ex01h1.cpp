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

const int N = 683055;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> qs(N+1, 0), qs2(N+1, 0);
    qs[1] = 1;
    qs[2] = 1;
    qs2[1] = 1;

    int tail = 2;
    for(int i=2;i<=N;++i){
        qs[i] += qs[i-1];
        qs2[i] = qs2[i-1]+qs[i];
        tail += qs[i];
        if(tail > N) continue;
        qs[tail]++;
    }

    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        cout << lower_bound(qs2.begin(), qs2.end(), x) - qs2.begin() << "\n";
    }


    return 0;
}