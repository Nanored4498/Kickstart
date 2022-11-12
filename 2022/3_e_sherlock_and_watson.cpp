#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const ll MOD = 1000000007;

ll pow(ll x, int p, ll m) {
	ll ans = 1%m;
	while(p) {
		if(p&1) ans = (ans * x) % m;
		p >>= 1;
		x = (x*x)%m;
	}
	return ans;
}

void solve() {
	int A, B;
	ll N, K;
	cin >> A >> B >> N >> K;
	ll num = N/K;
	vi a(K, 0);
	ll ans = 0;
	for(ll i = 0; i < K; ++i) {
		ll ia = pow(i, A, K);
		a[ia] += num;
		if(i && num*K + i <= N) ++ a[ia];
		a[ia] %= MOD;
	}
	for(ll i = 0; i < K; ++i) {
		ll ib = pow(i, B, K);
		ll count = num;
		if(i && num*K + i <= N) ++ count;
		count %= MOD;
		ll ia = (K-ib)%K;
		ans = (ans + count * a[ia]) % MOD;
	}
	for(ll i = 0; i < K; ++i) if(((pow(i, A, K) + pow(i, B, K)) % K) == 0) {
		ll count = num;
		if(i && num*K + i <= N) ++ count;
		count %= MOD;
		ans = (ans + MOD - count) % MOD;
	}
	cout << ans << '\n';
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