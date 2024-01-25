#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
#define mkp(a, b) make_pair(a, b)

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	
	vector<int> A(n+1, 0), B(n+1, 0), qs(n+1, 0), qs2(n+1, 0);
	
	for(int i=0;i<n;++i) cin >> A[i+1];

	for(int i=0;i<n;++i) cin >> B[i+1];

	

	for(int i=1;i<=n;++i) qs[i] = qs[i-1] + A[i]*B[i];
	for(int i=n-1;i>0;--i) qs2[i] = qs[i]+qs[i+1];

	ll res = 0;
	// for(int i=1;i<=n;++i) res += qs2[i] - (n-i+1)*qs[i-1];
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			for(int k=i;k<=j;++k){
				res += A[k]*B[k];
			}
		}
	}
	cout << res << "\n";

	return 0;
}
