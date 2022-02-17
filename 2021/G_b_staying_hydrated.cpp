#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void solve() {
	int K;
	cin >> K;
	ll x = -1e9-5, y = -1e9-5;
	ll sx = 0, sy = 0;
	ll ax = -K, ay = -K;
	vector<ll> xs(2*K), ys(2*K);
	for(int i = 0; i < K; ++i) {
		cin >> xs[2*i] >> ys[2*i];
		cin >> xs[2*i+1] >> ys[2*i+1];
		sx += xs[2*i] - x;
		sy += ys[2*i] - y;
	}
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());
	ll xb = x, yb = y;
	ll sxb = sx, syb = sy;
	for(ll x2 : xs) {
		sx += ax * (x2 - x);
		++ ax;
		x = x2;
		if(sx < sxb) {
			xb = x;
			sxb = sx;
		}
	}
	for(ll y2 : ys) {
		sy += ay * (y2 - y);
		++ ay;
		y = y2;
		if(sy < syb) {
			yb = y;
			syb = sy;
		}
	}
	cout << xb << ' ' << yb << '\n';
}

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}