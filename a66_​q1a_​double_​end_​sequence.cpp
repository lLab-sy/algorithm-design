#include <iostream>
#include <vector>
using namespace std;
vector<int> dp(1999, 300000000);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
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