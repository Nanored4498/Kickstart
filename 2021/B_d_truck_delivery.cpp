#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned long long ll;
typedef vector<int> vi;
const int MAX_L = 2e5+5;
#define LSB(i) (i)&(-(i))

struct Edge {
	int y, l;
	ll a;
	Edge(int y, int l, ll a): y(y), l(l), a(a) {}
};

vector<vector<Edge>> G;
vector<vi> qs;
vi W;
vector<ll> ans;
ll fen[MAX_L];

void f(int x, int x0) {
	for(int q : qs[x]) {
		ans[q] = 0;
		for(int w = W[q]; w > 0; w -= LSB(w))
			ans[q] = __gcd(ans[q], fen[w]);
	}
	for(const Edge &e : G[x]) if(e.y != x0) {
		vector<ll> tmp;
		for(int l = e.l; l < MAX_L; l += LSB(l)) {
			tmp.push_back(fen[l]);
			fen[l] = __gcd(fen[l], e.a);
		}
		f(e.y, x);
		for(int l = e.l, i = 0; l < MAX_L; l += LSB(l), ++i)
			fen[l] = tmp[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1 ; t <= T; ++t) {
		int N, Q;
		cin >> N >> Q;
		G.assign(N+1, vector<Edge>());
		for(int i = 1; i < N; ++i) {
			int x, y, l;
			ll a;
			cin >> x >> y >> l >> a;
			G[x].emplace_back(y, l, a);
			G[y].emplace_back(x, l, a);
		}

		qs.assign(N+1, vi());
		W.resize(Q);
		for(int i = 0; i < Q; ++i) {
			int c;
			cin >> c >> W[i];
			qs[c].push_back(i);
		}

		ans.resize(Q);
		f(1, 1);
		cout << "Case #" << t << ":";
		for(ll x : ans) cout << ' ' << x;
		cout << '\n';

	}

	return 0;
}