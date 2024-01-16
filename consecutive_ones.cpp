#include <iostream>
#include <vector>
using namespace std;

void solve(string& seq, int n, int k, int st){
    if(n < k-st) return ;
    if(!n){
        cout << seq << "\n";
        return;
    }

    int idx = seq.size()-n;

    seq[idx] = '0';
    solve(seq, n-1, k, 0);
    seq[idx] = '1';
    if(st+1 == k) solve(seq, n-1, 0, st+1);
    else solve(seq, n-1, k, st+1);

    return ;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    string res(n, '0');
    solve(res, n, k, 0);
    return 0;
}