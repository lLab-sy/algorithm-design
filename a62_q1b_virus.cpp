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

bool solve(vector<int> dna){
    if(dna.size() == 2) return dna[0] == 0 and dna[1] == 1;

    int len = dna.size();

    vector<int> a(dna.begin(), dna.begin()+(len/2)), b(dna.begin()+(len/2), dna.begin()+len);
    bool can = solve(b);
    bool pa = solve(a);
    reverse(a.begin(), a.end());
    return can and (solve(a) or pa);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k; cin >> n >> k;


    vector<int> dna(1<<k);
    while(n--){
        for(int i=0;i<1<<k;++i) cin >> dna[i];
        if(!solve(dna)) cout << "no\n";
        else cout << "yes\n";
    }

	return 0;
}