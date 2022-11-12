#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int n; cin >> n;
		vi p(n), c(n+1, 0);
		for(int &x : p) { cin >> x; --x; }
		vector<bool> seen(n, false);
		for(int i = 0; i < n; ++i) if(!seen[i]) {
			int j = i, l = 0;
			while(!seen[j]) {
				++ l;
				seen[j] = true;
				j = p[j];
			}
			++ c[l];
		}
		vi d(n+1, n); d[0] = 0;
		for(int l = 1; l <= n; ++l) if(c[l] > 0) {
			vector<priority_queue<pair<ll,int>>> Q(l);
			for(int i = 0; i <= n; ++i) {
				int m = i%l;
				Q[m].emplace(i - (ll)l*(ll)d[i], i);
				while(!Q[m].empty()) {
					const auto [a, j] = Q[m].top();
					if(j >= i-l*c[l]) {
						d[i] = (i-a)/l;
						break;
					} else Q[m].pop();
				}
			}
		}
		int x = n;
		for(int l = n; l > 0; --l) {
			d[l] = min(d[l], x+1);
			x = min(x, d[l]);
		}
		cout << "Case #" << t << ":";
		for(int l = 1; l <= n; ++l) cout << ' ' << d[l]-1;
		cout << '\n';
	}

	return 0;
}