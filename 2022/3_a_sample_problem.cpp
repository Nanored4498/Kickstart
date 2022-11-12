#include <iostream>

using namespace std;

void solve() {
	int N, M;
	cin >> N >> M;
	int sc = 0;
	while(N--) {
		int c; cin >> c; sc += c;
	}
	cout << (sc % M) << '\n';
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