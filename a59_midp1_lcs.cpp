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

const int N = 1010;
int dp[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    string s1, s2; cin >> s1 >> s2;

    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            cin >> dp[i][j];
        }
    }

    stack<char> stk;
    int i = n, j = m;
    while(i > 0 and j > 0){
        if(dp[i-1][j] == dp[i][j]){
            i--;
        }else if(dp[i][j-1] == dp[i][j]){
            j--;
        }else{
            stk.push(s1[i-1]);
            i--;
            j--;
        }
    }

    while(!stk.empty()){
        cout << stk.top();
        stk.pop();
    }

    return 0;
}