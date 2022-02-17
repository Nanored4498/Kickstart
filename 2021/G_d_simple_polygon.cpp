#include <iostream>	

using namespace std;

void solve() {
	int N, A;
	cin >> N >> A;
	int t = N-2;
	if(A < t) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	cout << "POSSIBLE\n";
	if(N == 3) {
		cout << "0 0\n1 0\n0 " << A << "\n";
		return;
	}
	int b = t/4;
	for(int i = 0; i < b; ++i)
		cout << 2*i << " 1\n" << 2*i+1 << " 0\n";
	cout << 2*b << " 1\n";
	if((t&3) == 1) cout << 2*b+1 << " 1\n";
	else if((t&3) == 2) cout << 2*b+1 << " 0\n" << 2*b+1 << " 1\n";
	else if((t&3) == 3) cout << 2*b+1 << " 0\n" << 2*b+2 << " 1\n" << 2*b+1 << " 1\n";
	for(int i = b; i > 0; --i)
		cout << 2*i << " 2\n" << 2*i-1 << " 1\n";
	cout << "0 " << 2+A-t << "\n";
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