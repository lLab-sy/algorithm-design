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

vector<pair<int, pii> > sol;
int print(int n, int sx, int sy, int tx, int ty){
    int nd2 = n/2;

    int b;
    if(tx < sx+nd2){
        if(ty < sy+nd2){
            b = 0;
        }else{
            b = 2;
        }
    }else{
        if(ty < sy+nd2){
            b = 1;
        }else{
            b = 3;
        }
    }

    sol.push_back(mkp(b, mkp(sx+nd2-1, sy+nd2-1)));
    return b;

}

void solve(int n, int sx, int sy, int tx, int ty){
    if(n == 2){
        print(n, sx, sy, tx, ty);
        return ;
    }

    int b = print(n, sx, sy, tx, ty);
    int nd2 = n/2;
    if(b != 0){
        solve(n/2, sx, sy, sx+nd2-1, sy+nd2-1);
    }else{
        solve(n/2, sx, sy, tx, ty);
    }

    if(b != 1){
        solve(n/2, sx+nd2, sy, sx+nd2, sy+nd2-1);
    }else{
        solve(n/2, sx+nd2, sy, tx, ty);
    }

    if(b != 2){
        solve(n/2, sx, sy+nd2, sx+nd2-1, sy+nd2);
    }else{
        solve(n/2, sx, sy+nd2, tx, ty);
    }

    if(b != 3){
        solve(n/2, sx+nd2, sy+nd2, sx+nd2, sy+nd2);
    }else{
        solve(n/2, sx+nd2, sy+nd2, tx, ty);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x, y; cin >> n >> x >> y;
    solve(n, 0, 0, x, y);

    cout << sol.size() << "\n";
    for(auto& ans: sol){
        cout << ans.pf << " " << ans.ps.pf << " " << ans.ps.ps << "\n";
    }

    return 0;
}