#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const int p = 6;
	const int m = 1<<p;
	bool good[m];
	for(int i = 0; i < m; ++i) {
		good[i] = ((((i>>4)&1) != ((i>>0)&1)) || (((i>>3)&1) != ((i>>1)&1)))
					&& ((((i>>5)&1) != ((i>>1)&1)) || (((i>>4)&1) != ((i>>2)&1)))
					&& ((((i>>5)&1) != ((i>>0)&1)) || (((i>>4)&1) != ((i>>1)&1)) || (((i>>3)&1) != ((i>>2)&1)));
	}

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int N; string S;
		cin >> N >> S;
		if(N < p) {
			cout << "Case #" << t << ": " << (N<5 || S[0]!=S[4] || S[1]!=S[3] ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
			continue;
		}
		bool a[m], b[m];
		for(int i = 0; i < m; ++i) {
			a[i] = good[i];
			for(int j = 0; j < p-1; ++j)
				if(S[j] == '0') a[i] &= ~((i>>j)&1);
				else if(S[j] == '1') a[i] &= ((i>>j)&1);
		}
		bool ok;
		for(int j = p-1; j < N; ++j) {
			ok = false;
			for(int i = 0; i < m; ++i) b[i] = false;
			for(int i = 0; i < m; ++i) {
				if(S[j] == '0') a[i] &= ~(i>>(p-1));
				else if(S[j] == '1') a[i] &= (i>>(p-1));
				if(a[i]) {
					ok = true;
					for(int k : {i>>1, (i>>1)|(m>>1)}) b[k] = good[k];
				}
			}
			if(!ok) break;
			swap(a, b);
		}
		cout << "Case #" << t << ": " << (ok ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
	}

	return 0;
}