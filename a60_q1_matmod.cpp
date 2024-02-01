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

int a, b, c, d, k;

vector<int> mul(vector<int> v1, vector<int> v2){
    return vector<int>{(v1[0]*v2[0]+v1[1]*v2[2])%k, (v1[0]*v2[1]+v1[1]*v2[3])%k, (v1[2]*v2[0]+v1[3]*v2[2])%k, (v1[2]*v2[1]+v1[3]*v2[3])%k};
}

vector<int> solve(int n){
    if(n == 0) return vector<int>{1, 0, 0, 1};
    if(n == 1) return {a, b, c, d};

    vector<int> nd2 = solve(n/2);
    vector<int> res = mul(nd2, nd2);
    if(n%2 == 1) res = mul(res, vector<int>{a, b, c, d});
    return res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n >> k;
    cin >> a >> b >> c >> d;

    for(auto r: solve(n)){
        cout << r << " ";
    }

	return 0;
}