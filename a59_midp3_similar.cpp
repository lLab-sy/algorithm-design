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

bool solve(string &s1, string &s2, int l1, int r1, int l2, int r2){
    if(l1 == r1) return s1[l1] == s2[l2];
    int md1 = (l1+r1)/2, md2 = (l2+r2)/2;
    return (solve(s1, s2, l1, md1, l2, md2) and solve(s1, s2, md1+1, r1, md2+1, r2)) or (solve(s1, s2, l1, md1, md2+1, r2) and solve(s1, s2, md1+1, r1, l2, md2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b; cin >> a >> b;
    int n = a.size();
    if(solve(a, b, 0, n-1, 0, n-1)){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}