#include <iostream>

using namespace std;

void solve() {
	int N; string s;
	cin >> N >> s;
	bool d = false, u = false, l = false, p = false;
	for(char c : s) {
		if('0' <= c && c <= '9') d = true;
		if('a' <= c && c <= 'z') l = true;
		if('A' <= c && c <= 'Z') u = true;
		if(c == '#' || c == '@' || c == '*' || c == '&') p = true;
	}
	if(!d) s.push_back('0');
	if(!u) s.push_back('A');
	if(!l) s.push_back('a');
	if(!p) s.push_back('#');
	while(s.size() < 7) s.push_back('a');
	cout << s << '\n';
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