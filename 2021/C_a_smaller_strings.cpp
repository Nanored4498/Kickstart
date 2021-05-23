#include <iostream>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N, K;
		string S;
		cin >> N >> K >> S;
		ll ans = 0;
		ll mul = 1;
		for(int i = (N-1)/2; i >= 0; --i) {
			ans = (ans + ll(S[i]-'a') * mul) % MOD;
			mul = (mul * K) % MOD;
		}
		for(int i = (N-2)/2, j = N-1-i; i >= 0; --i, ++j) {
			if(S[i] < S[j]) {
				ans = (ans+1) % MOD;
				break;
			}
			if(S[i] != S[j]) break;
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}