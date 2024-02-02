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

int mat[300][300];

void solve(int a, int b, int x, int y){
    if(a == 0){
        mat[x][y] = b;
        return ;
    }

    int md = 1<<(a-1);
    solve(a-1, b, x, y);
    solve(a-1, b-1, x, y+md);
    solve(a-1, b+1, x+md, y);
    solve(a-1, b, x+md, y+md);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b; cin >> a >> b;
    solve(a, b, 0, 0);

    for(int i=0;i<1<<a;++i){
        for(int j=0;j<1<<a;++j){
            cout << mat[i][j] << " ";
        }cout << "\n";
    }

    return 0;
}