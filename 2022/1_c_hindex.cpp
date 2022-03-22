#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve() {
	int N; cin >> N;
	priority_queue<int> Q;
	priority_queue<int, vector<int>, greater<int>> C;
	int h = 0;
	while(N--) {
		int c; cin >> c;
		Q.push(c);
		while(!Q.empty() && Q.top() > h) {
			C.push(Q.top());
			Q.pop();
			++ h;
			while(!C.empty() && C.top() < h) {
				Q.push(C.top());
				C.pop();
				-- h;
			}
		}
		cout << ' ' << h;
	}
}

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ":";
		solve();
		cout << '\n';
	}
	return 0;
}