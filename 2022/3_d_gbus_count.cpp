#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

void solve() {
	vi a(5002, 0);
	int N; cin >> N;
	while(N--) {
		int i, j; cin >> i >> j;
		++ a[i]; -- a[j+1];
	}
	for(int i = 1; i <= 5000; ++i) a[i] += a[i-1];
	int P; cin >> P;
	while(P--) {
		int c; cin >> c;
		cout << a[c] << ' ';
	}
	cout << '\n';
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