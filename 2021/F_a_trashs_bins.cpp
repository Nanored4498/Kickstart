#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N;
		string S;
		cin >> N >> S;
		ll ans = 0;
		vector<ll> l(N), r(N);
		l[0] = S[0] == '0' ? N : 0;
		for(int i = 1; i < N; ++i) l[i] = S[i] == '0' ? l[i-1]+1 : 0;
		r[N-1] = S[N-1] == '0' ? N : 0;
		for(int i = N-2; i >= 0; --i) r[i] = S[i] == '0' ? r[i+1]+1 : 0;
		for(int i = 0; i < N; ++i) ans += min(l[i], r[i]);
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}