#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& p, vector<int>& h, vector<int>& t, int w, int idx){
    if(!idx){
        int sum = 0;
        for(auto e: h) sum += e;
        return sum;
    }

    int mn = solve(p, h, t, w, idx-1);

    for(int i=0;i<p.size();++i){
        if(p[i] >= t[idx-1]-w and p[i] <= t[idx-1]+w and h[i] > 0){
            h[i]--;
            mn = min(mn, solve(p, h, t, w, idx-1));
            h[i]++;
        }
    }
    
    return mn;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k, w;
    cin >> n >> m >> k >> w;

    vector<int> p(m), h(m), t(k);
    for(int i=0;i<m;++i) cin >> p[i];
    for(int i=0;i<m;++i) cin >> h[i]; 
    for(int i=0;i<n;++i) cin >> t[i];

    cout << solve(p, h, t, w, k);

    return 0;
}