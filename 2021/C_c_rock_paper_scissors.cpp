#include <iostream>
#include <map>

using namespace std;
const int D = 60;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, X;
	cin >> T >> X;
	map<int, string> m;
	for(int t = 1; t <= T; ++t) {
		int W, E;
		cin >> W >> E;
		int rat = E == 0 ? 0 : W/E;
		if(!m.count(rat)) {
			double dp[D+1][D+1][D+1];
			char mv[D+1][D+1][D+1];
			for(int r = D; r >= 0; --r)
				for(int p = D; p >= 0; --p)
					for(int s = D; s >= 0; --s) {
						double sum = r+p+s;
						if(sum >= D) dp[r][p][s] = 0.;
						else {
							mv[r][p][s] = 'R';
							dp[r][p][s] = W * p / sum + E * s / sum + dp[r+1][p][s];
							double e = W * s / sum + E * r / sum + dp[r][p+1][s];
							if(e > dp[r][p][s]) {
								mv[r][p][s] = 'P';
								dp[r][p][s] = e;
							}
							e = W * r / sum + E * p / sum + dp[r][p][s+1];
							if(e > dp[r][p][s]) {
								mv[r][p][s] = 'S';
								dp[r][p][s] = e;
							}
						}
					}
			dp[0][0][0] = (W + E) / 3 + dp[1][0][0];
			mv[0][0][0] = 'R';
			int r=0, p=0, s=0;
			string a = "";
			for(int i = 0; i < D; ++i) {
				a += mv[r][p][s];
				if(a.back() == 'R') ++r;
				else if(a.back() == 'P') ++p;
				else ++s;
			}
			m[rat] = a;
		}
		cout << "Case #" << t << ": " << m[rat] << '\n';
	}

	return 0;
}