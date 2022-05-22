#include <iostream>

using namespace std;
typedef long long ll;

void solve() {
	ll N, X, Y;
	cin >> N >> X >> Y;
	ll s = (N*(N+1))/2;
	ll n = s*X, d = X+Y;
	if(n%d == 0) {
		cout << "POSSIBLE\n";
		ll a = n/d;
		vector<ll> ans;
		for(ll i = N; i > 0; --i) if(i <= a) {
			a -= i;
			ans.push_back(i);
		}
		cout << ans.size() << '\n';
		for(ll x : ans) cout << x << ' ';
		cout << '\n';
	} else cout << "IMPOSSIBLE\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}

	return 0;
}