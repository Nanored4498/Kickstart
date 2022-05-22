#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int N, L;
	cin >> N >> L;
	vector<pair<int, int>> p(N);
	vector<int> t[2];
	for(int i = 0; i < N; ++i) {
		int D;
		cin >> p[i].first >> D;
		p[i].second = i+1;
		if(D) t[D].push_back(L-p[i].first);
		else t[D].push_back(p[i].first);
	}
	sort(p.begin(), p.end());
	for(int d : {0, 1}) sort(t[d].begin(), t[d].end());
	for(int i = 0; i < t[0].size(); ++i) p[i].first = t[0][i];
	for(int i = 0; i < t[1].size(); ++i) p[N-1-i].first = t[1][i];
	sort(p.begin(), p.end());
	for(auto [t, i] : p) cout << i << ' ';
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