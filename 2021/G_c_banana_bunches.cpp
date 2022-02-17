#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void solve() {
	int N, K;
	cin >> N >> K;
	vector<int> B(N);
	for(int &x : B) cin >> x;
	int ans = N+5;
	vector<ll> s(N+1, 0);
	vector<vector<pair<int, int>>> p(K+1);
	for(int i = 0; i < N; ++i) {
		s[i+1] = s[i] + B[i];
		for(int j = 0; j <= i; ++j) {
			ll b = s[i+1]-s[j];
			if(b > K) continue;
			int c = i+1-j;
			if(b == K) ans = min(ans, c);
			if(p[b].empty() || p[b].back().first > c) p[b].emplace_back(c, i);
		}
	}
	for(int i = N-1; i >= 0; --i) {
		for(int j = i; j < N; ++j) if(s[j+1]-s[i] <= K) {
			int b = K - (s[j+1]-s[i]);
			while(!p[b].empty() && p[b].back().second >= i) p[b].pop_back();
			if(p[b].empty()) continue;
			ans = min(ans, j+1-i+p[b].back().first);
		}
	}
	cout << (ans > N ? -1 : ans) << '\n';
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