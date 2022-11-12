#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

vi a;
vector<vi> G;
int best;
pii solve(int i, int p) {
	int ans = 1, ans2 = 0;
	for(int j : G[i]) if(j != p) {
		const auto [x, y] = solve(j, i);
		if(a[j] < a[i]) ans += x;
		else if(a[j] > a[i]) ans2 = max(ans2, y);
	}
	ans2 += ans;
	best = max(best, ans2);
	return {ans, ans2};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int n; cin >> n;
		a.resize(n);
		for(int &x : a) cin >> x;
		G.clear(); G.resize(n);
		for(int i = 1; i < n; ++i) {
			int x, y; cin >> x >> y; --x; --y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		best = 0;
		solve(0, 0);
		cout << "Case #" << t << ": " << best << '\n';
	}

	return 0;
}