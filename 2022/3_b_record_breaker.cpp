#include <iostream>

using namespace std;

void solve() {
	int N; cin >> N;
	int m = -1, last = -1, ans = 0;
	while(N--) {
		int v; cin >> v;
		if(last > max(m, v)) ++ ans;
		m = max(m, last);
		last = v;
	}
	if(last > m) ++ ans;
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