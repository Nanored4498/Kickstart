#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
typedef unsigned long long ll;
const ll N = 2e6;
const double e = .99e-6;

int main() {
	vector<double> s(N);
	s[0] = 0.;
	for(ll i = 1; i < N; ++i) s[i] = s[i-1] + 1./i;
	int T;
	cin >> T;
	cout << setprecision(10);
	for(int t = 1; t <= T; ++t) {
		ll n;
		cin >> n;
		ll k = min(n, N-1);
		double ans = s[k];
		while(k < n) {
			ll l = min(n, (ll) (k * (1.+e)));
			ans += double(l-k) / double(k+1);
			k = l;
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}
	return 0;
}