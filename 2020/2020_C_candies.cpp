#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
#define lsb(i) ((i)&(-i))

vector<ll> A, sw, sa;

void update(ll i, ll a) {
	a -= A[i];
	A[i] += a;
	ll aw = i * (i%2==0 ? -a : a);
	ll aa = (i%2==0 ? -a : a);
	while(i < A.size()) {
		sw[i] += aw;
		sa[i] += aa;
		i += lsb(i);
	}
}

ll querry0(const vector<ll> &v, ll i) {
	ll res = 0;
	while(i > 0) {
		res += v[i];
		i -= lsb(i);
	}
	return res;
}

ll querry(ll a, ll b) {
	ll res = querry0(sw, b) - querry0(sw, a-1);
	res -= (a-1) * (querry0(sa, b) - querry0(sa, a-1));
	if(a%2 == 0) res = -res;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, N, Q, a, b;
	cin >> T;
	for(int tt = 1; tt <= T; ++tt) {
		cin >> N >> Q;
		A.assign(N+1, 0); sw.assign(N+1, 0); sa.assign(N+1, 0);
		sw[0] = sa[0] = 0;
		for(int i = 1; i <= N; ++i) {
			cin >> a;
			update(i, a);
		}
		char c;
		long long res = 0;
		for(int i = 0; i < Q; ++i) {
			cin >> c >> a >> b;
			if(c == 'U') update(a, b);
			else res += querry(a, b);
		}
		cout << "Case #" << tt << ": " << res << "\n";
	}

	return 0;
}