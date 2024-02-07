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

vector<pii> A(100000);

bool cmp(int i, int j){
    if(A[i].pf != A[j].pf) return A[i].pf < A[j].pf;
    return A[i].ps < A[j].ps;
}

bool prtCmp(int i, int j){
    return A[i].pf <= A[j].pf and A[i].ps <= A[j].ps;
}

vector<int> pareto(int l, int r){
    if(l == r) return vector<int>(1, l);

    int md = (l+r)/2;
    vector<int> left = pareto(l, md), right = pareto(md+1, r);

    int nl = left.size(), nr = right.size(), n = left.size()+right.size(), i = 0, j = 0, k = 0;
    vector<int> res(n);
    
    while(i<nl and j<nr){
        if(cmp(left[i], right[j])){
            res[k++] = left[i++];
        }else{
            res[k++] = right[j++];
        }
    }

    while(i<nl) res[k++] = left[i++];
    while(j<nr) res[k++] = right[j++];

    vector<int> prt;
    for(auto& pt: res){
        while(!prt.empty() and prtCmp(prt.back(), pt)) prt.pop_back();
        prt.push_back(pt);
    }

    return prt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for(int i=0;i<n;++i){
        cin >> A[i].pf >> A[i].ps;
    }

    cout << pareto(0, n-1).size();

    return 0;
}