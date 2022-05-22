#include <iostream>
#include <vector>

#include "../CP-Headers/mod_arith.h"

using namespace std;
typedef mint<int(1e9+7)> mi;
typedef vector<pair<mi,mi>> vi;

void solve() {
	int N; string s;
	cin >> N >> s;
	vector<vi> dp0(N, vi{{0,1}}), dp1(N, vi{{0,1}, {1,1}}), dp2;
	for(int l = 2; l <= N; ++l) {
		dp2.assign(N-l+1, vi(l+1, {0,0}));
		for(int i = 0; i+l <= N; ++i) {
			for(int j = 0; j <= l; ++j) {
				if(j < l) dp2[i][j].first = dp1[i][j].first;
				if(j >= 2 && s[i] == s[i+l-1]) dp2[i][j].first += dp0[i+1][j-2].second;
				dp2[i][j].second = dp2[i][j].first;
				if(j < l) dp2[i][j].second += dp1[i+1][j].second;
			}
		}
		dp0 = move(dp1);
		dp1 = move(dp2);
	}
	vector<mi> fac(N+1, 1); for(int i = 1; i <= N; ++i) fac[i] = fac[i-1]*i;
	mi ans = 0;
	for(int l = 0; l < N; ++l) {
		mi C = fac[N] / (fac[l] * fac[N-l]);
		ans += dp1[0][l].second / C;
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