#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	const int ML = 1e5+1;
	vi dp(ML);
	for(int i = 1; i < ML; ++i) {
		dp[i] = i;
		int i2 = i/2+1;
		if(i>6)for(int j = i/7; j < i2; ++j) {
			int x = dp[j]+4+2*((i-j)/j)+((i-j)%j);
			dp[i] = min(dp[i], x);
		}
	}
	for(int t = 1; t <= T; ++t) {
		int n; cin >> n;
		cout << "Case #" << t << ": " << dp[n] << '\n';
	}

	return 0;
}