#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(7);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		vector<ll> X(N), Y(N);
		for(int i = 0; i < N; ++i) cin >> X[i] >> Y[i];
		ll x, y;
		cin >> x >> y;
		double ans = -1.;
		for(int i = 2; i < N; ++i)
			for(int j = 1; j < i; ++j)
				for(int k = 0; k < j; ++k) {
					int l[4] = {i, j, k, i};
					bool sign[3], bad = false;
					double p = 0.;
					for(int m = 0; m < 3; ++m) {
						int a = l[m], b = l[m+1];
						ll u = Y[a]-Y[b], v = X[b]-X[a];
						p += sqrt(u*u + v*v);
						ll dot = u*(x-X[a]) + v*(y-Y[a]);
						if(dot == 0) bad = true;
						sign[m] = dot > 0;
					}
					if(bad) continue;
					if(sign[0] != sign[1] || sign[0] != sign[2]) continue;
					if(ans < 0.) ans = p;
					else ans = min(ans, p);
				}
		cout << "Case #" << t << ": ";
		if(ans < 0.) cout << "IMPOSSIBLE";
		else cout << ans;
		cout << '\n';
	}

	return 0;
}