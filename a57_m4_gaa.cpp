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

string ga0 = " gaa";

char solve(int seq, int idx, int len){
    if(seq == 0){
        return ga0[idx];
    }

    int exp_seq = len - (seq+3);
    int pv_len = exp_seq/2;

    if(idx <= pv_len || idx > pv_len + seq+3) return solve(seq-1, (idx > pv_len)? idx-(pv_len+seq+3):idx, pv_len);
    else if(idx == pv_len+1) return 'g';
    return 'a';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int last = 3, seq=0;
    while(last < n){
        seq++;
        last = last + seq+3 + last;
    }

    cout << solve(seq, n, last);
    return 0;
}