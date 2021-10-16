#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N, M, K;
		cin >> N >> M >> K;
		vi L(N), R(N), A(N);
		for(int i = 0; i < N; ++i) cin >> L[i] >> R[i] >> A[i];
		vector<vi> G(N);
		while(M--) {
			int a, b;
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}

		ll ans = 0;
		int P = 1<<N;
		vector<ll> dp(P, 0);
		for(int i = 0; i < N; ++i) dp[1<<i] = 1; 
		for(int p = 1; p < P; ++p) {
			ll s = 0;
			for(int i = 0; i < N; ++i) if(p&(1<<i)) s += A[i];
			if(s > K) continue;
			if(s == K) ans += dp[p];
			for(int i = 0; i < N; ++i) if(!(p&(1<<i)) && L[i] <= s && s <= R[i])
				for(int j : G[i]) if(p&(1<<j)) {
					dp[p|(1<<i)] += dp[p];
					break;
				}
		}

		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}