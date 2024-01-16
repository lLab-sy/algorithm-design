#include <iostream>
#include <vector>
using namespace std;

void solve(string& seq, int n, int k){
    if(k > n) return;
    if(!n){
        cout << seq << "\n";
        return;
    }

    seq[n-1] = '1';
    if(k>0) solve(seq, n-1, k-1);
    seq[n-1] = '0';
    solve(seq, n-1, k);

    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b;
    cin >> a >> b;

    string seq(b, '0');
    solve(seq, b, a);

    return 0;
}