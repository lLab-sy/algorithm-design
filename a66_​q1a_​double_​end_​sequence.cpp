#include <iostream>
using namespace std;
int dp[2003];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;

    for(int i=0;i<=999+999;++i) dp[i] = 300000000;

    int sum = 0, mx = -2e9, x;
    for(int i=0;i<n;++i){
        cin >> x;
        mx = max(mx, max(x, sum+x-dp[x+999]));
        dp[x+999] = min(dp[x+999], sum);
        sum += x;
    }

    cout << mx << "\n";
    return 0;
}