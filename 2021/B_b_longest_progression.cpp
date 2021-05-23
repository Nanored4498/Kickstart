#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1 ; t <= T; ++t) {
		int N;
		cin >> N;
		vector<long long> A(N);
		vector<int> lr(N), rl(N);
		for(long long &x : A) cin >> x;
		for(int i = 0; i < N; ++i) {
			if(i == 0) lr[i] = 0;
			else if(i == 1 || A[i] + A[i-2] != 2*A[i-1]) lr[i] = 1;
			else lr[i] = lr[i-1] + 1;
		}
		for(int i = N-1; i >= 0; --i) {
			if(i == N-1) rl[i] = 0;
			else if(i == N-2 || A[i] + A[i+2] != 2*A[i+1]) rl[i] = 1;
			else rl[i] = rl[i+1] + 1;
		}
		int ans = 1;
		for(int i = 0; i < N; ++i) {
			if(i >= 2) {
				long long a = 2*A[i-1] - A[i-2];
				int n = lr[i-1] + 1;
				if(i+1 < N && 2*a == A[i-1] + A[i+1]) {
					++ n;
					if(i+2 < N && 2*A[i+1] == a + A[i+2]) n += rl[i+1];
				}
				ans = max(ans, n);
			}
			if(i+2 < N) {
				long long a = 2*A[i+1] - A[i+2];
				int n = 1 + rl[i+1];
				if(i >= 1 && 2*a == A[i-1] + A[i+1]) {
					++ n;
					if(i >= 2 && 2*A[i-1] == a + A[i-2]) n += lr[i-1];
				}
				ans = max(ans, n);
			}
		}
		++ ans;
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}