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

int days[1002];
int n;
vector<vector<int>> stu(22, vector<int>());

int solve(int cur, int total){
    if(total == n) return 0;
    if(cur < 0) return 2e9;
    int notSel = solve(cur-1, total);
    int pls = 0;
    for(auto d:stu[cur]){
        if(days[d] == 0){
            pls++;
        }
        days[d]++;
    }
    int sel = solve(cur-1, total+pls);
    for(auto d:stu[cur]){
        days[d]--;
    }
    return min(notSel, sel+1);

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); 
    int m; cin >> n >> m;
    
    for(int i=0;i<m;++i){
        int k; cin >> k;
        for(int j=0;j<k;++j){
            int x; cin >> x;
            stu[i].push_back(x);
        }
    }

    cout << solve(m-1, 0);

    return 0;
}