#include <iostream>
#include <vector>

using namespace std;
#define MAX_N 100000

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, N, a;
	cin >> T;
	vector<int> pred(200*MAX_N+1, 0);
	int mid = 100*MAX_N;
	for(int tt = 1; tt <= T; ++tt) {
		cin >> N;
		vector<int> s(N+1);
		s[0] = 0;
		pred[mid] = 1;
		long long res = 0;
		int ms = 100*N;
		for(int i = 1; i <= N; ++i) {
			cin >> a;
			s[i] = s[i-1]+a;
			for(int q = 0; s[i]-q*q >= -ms; ++q) {
				res += pred[s[i]-q*q+mid];
			}
			++ pred[s[i]+mid];
		}
		for(int i : s) pred[i+mid] = 0;
		cout << "Case #" << tt << ": " << res << "\n";
	}

	return 0;
}