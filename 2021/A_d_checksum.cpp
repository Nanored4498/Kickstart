#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
const int MAX_N = 501;

int r[2*MAX_N], s[2*MAX_N];

int find(int i) {
	if(r[i] == i) return i;
	return r[i] = find(r[i]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N, ans = 0, tmp;
		vector<tuple<int, int, int>> E;
		cin >> N;
		for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) cin >> tmp;
		for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) {
			cin >> tmp;
			ans += tmp;
			if(tmp) E.emplace_back(tmp, i, j);
		}
		for(int i = 0; i < N; ++i) cin >> tmp;
		for(int i = 0; i < N; ++i) cin >> tmp;

		sort(E.rbegin(), E.rend());
		for(int i = 0; i < 2*N; ++i) {
			r[i] = i;
			s[i] = 1;
		}
		for(auto [b, i, j] : E) {
			i = find(i);
			j = find(N+j);
			if(i == j) continue;
			if(s[i] < s[j]) swap(i, j);
			r[j] = i;
			s[i] += s[j];
			ans -= b;
		}

		cout << "Case #" << t << ": " << ans << "\n";
	}

	return 0;
}