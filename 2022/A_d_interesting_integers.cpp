#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;

const int P = 12;
unordered_map<ll,ll> m[P+1][9*P+1];
ll fact[P];

ll f(ll x) {
	if(x == 0) return 0;
	ll ans = 0;
	if(x == 1e12) {
		--x;
		++ ans;
	}
	vector<int> ds;
	while(x) {
		ds.push_back(x%10);
		x /= 10;
	}
	for(int d = 0; d < ds.size(); ++d) for(int s = 1; s <= 9*d; ++s) {
		ll mul = 0;
		for(int z = 1; z < ds.size()-d; ++z) mul += fact[z+d-1]/fact[z]/fact[d-1];
		for(auto [p, c] : m[d][s]) {
			if(p%s==0) ans += c;
			ans += c*mul;
		}
	}
	int s0 = 0;
	ll p0 = 1;
	for(int d : ds) {
		s0 += d;
		p0 *= d;
	}
	if(p0%s0==0) ++ ans;
	for(int i = 0; i < ds.size(); ++i) {
		s0 = 0;
		p0 = 1;
		for(int j = i+1; j < ds.size(); ++j) {
			s0 += ds[j];
			p0 *= ds[j];
		}
		for(int d = 0; d <= i; ++d) for(int s = 0; s <= 9*d; ++s) {
			int z = i-d;
			ll mul = fact[z+d]/fact[z]/fact[d];
			for(auto [p, c] : m[d][s]) for(int x = s0==0; x < ds[i]; ++x)
				if(z > 0 || (p*p0*x)%(s+s0+x)==0) ans += c*mul;
		}
	}
	return ans;
}

int main() {
	m[0][0][1] = 1;
	for(int d = 0; d < P; ++d) {
		for(int s = 0; s <= 9*d; ++s)
			for(auto [p, c] : m[d][s])
				for(int x = 1; x < 10; ++x)
					m[d+1][s+x][p*x] += c;
	}
	int tot = 0;
	for(int d = 0; d <= P; ++d) for(int s = 1; s <= 9*d; ++s) tot += m[d][s].size();
	cerr << "TOT: " << tot << endl;
	fact[0] = 1;
	for(int n = 1; n < P; ++n) fact[n]=fact[n-1]*n;

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		ll A, B;
		cin >> A >> B;
		cout << "Case #" << t << ": " << f(B) - f(A-1) << endl;
	}

	return 0;
}