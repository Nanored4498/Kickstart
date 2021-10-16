#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int D, N, K;
		cin >> D >> N >> K;
		multiset<ll> A, B;
		ll sum = 0, ans = 0;
		vector<pair<int, ll>> H;
		while(N--) {
			ll h;
			int s, e;
			cin >> h >> s >> e;
			H.emplace_back(s, h);
			H.emplace_back(e+1, -h);
		}
		sort(H.begin(), H.end());
		int i = 0;
		while(i < H.size()) {
			int i0 = i;
			while(i < H.size() && H[i].first == H[i0].first) {
				ll h = H[i++].second;
				if(h > 0) {
					if(A.size() == K) {
						auto it = A.begin();
						if(*it < h) {
							sum += h - *it;
							B.insert(*it);
							A.erase(it);
							A.insert(h);
						} else {
							B.insert(h);
						}
					} else {
						A.insert(h);
						sum += h;
					}
				} else {
					h = -h;
					auto it = B.find(h);
					if(it == B.end()) {
						it = A.find(h);
						A.erase(it);
						sum -= h;
						if(!B.empty()) {
							it = B.end();
							-- it;
							sum += *it;
							A.insert(*it);
							B.erase(it);
						}
					} else {
						B.erase(it);
					}
				}
			}
			ans = max(ans, sum);
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}