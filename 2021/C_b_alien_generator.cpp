#include <iostream>

using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		ll G;
		cin >> G;
		ll ans = 0;
		ll n = 0, K;
		while(true) {
			K = (2 * G - n * (n+1)) / (2*n+2);
			if(K < 1) break;
			if(G == ((2*n+2) * K + n * (n+1)) / 2) ++ ans;
			++ n;
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}