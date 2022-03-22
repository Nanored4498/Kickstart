#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;
typedef vector<bool> vb;
typedef pair<int, int> pii;

int N;
vector<string> m;
vector<vb> seen;

void dfs(int i, int j) {
	if(seen[i][j]) return;
	seen[i][j] = true;
	array<pii, 6> v = {pii(i-1, j), pii(i-1, j+1), pii(i, j-1), pii(i, j+1), pii(i+1, j-1), pii(i+1, j)}; 
	for(auto [x, y] : v) if(x >= 0 && x < N && y >= 0 && y < N && m[i][j] == m[x][y]) dfs(x, y);
}

string solve() {
	cin >> N;
	int cr = 0, cb = 0;
	m.resize(N);
	for(string &s : m) {
		cin >> s;
		for(char c : s) cr += c=='R', cb += c=='B';
	}
	if(abs(cr - cb) > 1) return "Impossible";
	bool wr = false, wb = false;
	seen.assign(N, vb(N, false));
	for(int j = 0; j < N; ++j) if(m[0][j] == 'R') dfs(0, j);
	for(int j = 0; j < N; ++j) wr |= m[N-1][j] == 'R' && seen[N-1][j];
	for(int i = 0; i < N; ++i) if(m[i][0] == 'B') dfs(i, 0);
	for(int i = 0; i < N; ++i) wb |= m[i][N-1] == 'B' && seen[i][N-1];
	cerr << '\n';
	for(int i = 0; i < N; ++i) {
		cerr << string(i, ' ');
		for(int j = 0; j < N; ++j) {
			if(m[i][j] == 'R') cerr << "\033[31m";
			else if(m[i][j] == 'B') cerr << "\033[34m";
			cerr << seen[i][j] << ' ';
			cerr << "\033[39m";
		}
		cerr << '\n';
	}
	if(!wr && !wb) return "Nobody wins";
	if(wr && wb) return "Impossible";
	if(cr == cb+1 && wb) return "Impossible";
	if(cb == cr+1 && wr) return "Impossible";
	if(wr) {
		for(string &s : m) for(char &c : s) if(c == 'R') {
			c = '.';
			seen.assign(N, vb(N, false));
			wr = false;
			for(int j = 0; j < N; ++j) if(m[0][j] == 'R') dfs(0, j);
			for(int j = 0; j < N; ++j) wr |= m[N-1][j] == 'R' && seen[N-1][j];
			if(!wr) return "Red wins";
			c = 'R';
		}
	} else {
		for(string &s : m) for(char &c : s) if(c == 'B') {
			c = '.';
			seen.assign(N, vb(N, false));
			wb = false;
			for(int i = 0; i < N; ++i) if(m[i][0] == 'B') dfs(i, 0);
			for(int i = 0; i < N; ++i) wb |= m[i][N-1] == 'B' && seen[i][N-1];
			if(!wb) return "Blue wins";
			c = 'B';
		}
	}
	return "Impossible";
}

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t)
		cout << "Case #" << t << ": " << solve() << '\n';
	return 0;
}