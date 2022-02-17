#include <iostream>

using namespace std;
typedef long long ll;

void solve() {
	ll N, D, C, M;
	string S;
	cin >> N >> D >> C >> M >> S;
	int i = 0;
	while(i < N) {
		if(S[i] == 'C') {
			if(C == 0) break;
			else -- C;
		} else {
			if(D == 0) break;
			else {
				-- D;
				C += M;
			}
		}
		++ i;
	}
	while(i < N) if(S[i++] == 'D') {
		cout << "NO\n"; 
		return;
	}
	cout << "YES\n";
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