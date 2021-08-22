#include <iostream>

#include "../CPHeaders/segment_tree.h"

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N, Q;
		ll P;
		cin >> N >> Q >> P;
		Fenwick<ll> A(N), B(N), C(N), D(N);
		for(int i = 1; i <= N; ++i) {
			ll x;
			cin >> x;
			ll m = x%P, v = 0, x0 = x;
			x -= m;
			if(x != 0) while(x % P == 0) {
				++ v;
				x /= P;
			}
			if(m == 0) A.v[i] = v;
			else if(v > 0LL) {
				B.v[i] = v;
				C.v[i] = 1LL;
				x = x0 + m;
				D.v[i] = -1LL;
				while((x&1) == 0) {
					++ D.v[i];
					x >>= 1;
				}
			}
		}
		A.init();
		B.init();
		C.init();
		D.init();

		cout << "Case #" << t << ':';
		while(Q--) {
			char q;
			cin >> q;
			if(q == '1') {
				int i;
				ll x;
				cin >> i >> x;
				ll m = x%P, v = 0, x0 = x;
				x -= m;
				if(x != 0) while(x % P == 0) {
					++ v;
					x /= P;
				}
				if(m == 0) {
					A.set(i, v);
					B.set(i, 0LL);
					C.set(i, 0LL);
					D.set(i, 0LL);
				} else if(v > 0LL) {
					A.set(i, 0LL);
					B.set(i, v);
					C.set(i, 1LL);
					x = x0 + m;
					v = -1;
					while((x&1) == 0) {
						++ v;
						x >>= 1;
					}
					D.set(i, v);
				} else {
					A.set(i, 0LL);
					B.set(i, 0LL);
					C.set(i, 0LL);
					D.set(i, 0LL);
				}
			} else {
				ll S;
				int a, b;
				cin >> S >> a >> b;
				ll v = 0, x = S;
				while(x % P == 0) {
					++ v;
					x /= P;
				}
				ll ans = S * A.querry(a, b) + B.querry(a, b) + v * C.querry(a, b);
				if(P == 2 && !(S&1)) ans += D.querry(a, b);
				cout << ' ' << ans;
			}
		}
		cout << '\n';
	}

	return 0;
}