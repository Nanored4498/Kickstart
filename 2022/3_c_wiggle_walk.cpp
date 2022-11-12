#include <iostream>
#include <map>

using namespace std;
typedef pair<int, int> pii;

void solve() {
	int N, R, C;
	pii s;
	cin >> N >> R >> C >> s.first >> s.second;
	typedef array<pii, 4> ai;
	map<pii, ai> m;
	auto def = [](const pii &s) {
		ai a = {s,s,s,s};
		a[0].first -= 1;
		a[1].first += 1;
		a[2].second -= 1;
		a[3].second += 1;
		return a;
	};
	map<char, int> c2i {{'N',0},{'S',1},{'W',2},{'E',3}};
	m[s] = def(s);
	string P; cin >> P;
	for(char c : P) {
		s = m[s][c2i[c]];
		m[s] = def(s);
		for(int i = 0; i < 4; ++i) if(m.count(m[s][i])) m[s][i] = m[m[s][i]][i];
		for(int i = 0; i < 4; ++i) m[def(m[s][i^1])[i]][i] = m[s][i];
	}
	cout << s.first << ' ' << s.second << '\n';
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