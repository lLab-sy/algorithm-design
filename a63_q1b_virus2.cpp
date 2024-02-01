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

int solve(vector<int>& dna, int l, int r){
    if(r<l) return 0;
    if(r==l) return dna[l] == 1;

    int md = (l+r)/2;
    int sl = solve(dna, l, md);
    int sr = solve(dna, md+1, r);
    if(abs(sl-sr) > 1) return -1e5;
    return sl+sr;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k; cin >> n >> k;


    vector<int> dna(1<<k);
    while(n--){
        for(int i=0;i<1<<k;++i) cin >> dna[i];
        if(solve(dna, 0, (1<<k)-1) < 0) cout << "no\n";
        else cout << "yes\n";
    }

	return 0;
}