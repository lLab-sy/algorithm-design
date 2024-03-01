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

const int MOD = 100000007;
const int N = 10010;
int dp[2][N]; // [0] end with 0, [1] end with 1

int solve1(ll n){
    dp[0][1] = 1;
    dp[0][2] = 2;
    dp[0][3] = 4;
    dp[1][1] = 1;
    dp[1][2] = 2;
    dp[1][3] = 3;
    for(int i=4;i<=n;++i){
        dp[0][i] = (dp[0][i-1] + dp[1][i-1])%MOD; // no problem with xx0
        dp[1][i] = (dp[1][i-1] + dp[0][i-2])%MOD; // cant end with 101 so dont choose string that end with 10
    }

    return (dp[1][n] + dp[0][n])%MOD;
}
// [dpn0 dpn1 dpp0]
// [1 1 0]
// [0 1 1]
// [1 0 0]
ll mat[44][3][3];

int solve2(ll n){
    mat[0][0][0] = 1;
    mat[0][1][1] = 1;
    mat[0][2][2] = 1;
    
    mat[1][0][0] = 1;
    mat[1][0][1] = 1;
    mat[1][1][1] = 1;
    mat[1][1][2] = 1;
    mat[1][2][0] = 1;



    for(ll i=2;i<=41;++i){
        for(int j=0;j<3;++j){
            for(int z=0;z<3;++z){
                for(int k=0;k<3;++k) mat[i][j][z] = (mat[i][j][z] + mat[i-1][j][k]*mat[i-1][k][z]) % MOD;
            }
        }

        if(ll(ll(1)<<ll(i-2)) & ll(n-3)){
            for(int j=0;j<3;++j){
                for(int z=0;z<3;++z) mat[42][j][z] = 0;
            }

            for(int j=0;j<3;++j){
                for(int z=0;z<3;++z){
                    for(int k=0;k<3;++k) mat[42][j][z] = (mat[42][j][z] + mat[i-1][j][k]*mat[0][k][z])%MOD;
                }
            }

            for(int j=0;j<3;++j){
                for(int z=0;z<3;++z) mat[0][j][z] = mat[42][j][z];
            }
        }
    }


    int X[3]; // at n = 3
    X[0] = 4;
    X[1] = 3;
    X[2] = 2;

    int res = 0;

    for(int j=0;j<2;++j){
        for(int k=0;k<3;++k){
            res = (res + mat[0][j][k]*X[k])%MOD;
        }
    }


    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n; cin >> n;

    // cout << solve1(n) << "\n";
    cout << solve2(n) << "\n";
    
    return 0;
}