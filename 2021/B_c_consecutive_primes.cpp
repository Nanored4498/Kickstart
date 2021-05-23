#include <iostream>
#include <cmath>

using namespace std;
typedef unsigned long long ll;

bool prime(ll x) {
	if(x == 2) return true;
	if(!(x&1)) return false;
	ll sx = min(x-1, (ll)sqrt(x)+1);
	for(ll d = 3; d <= sx; d += 2) if(x%d == 0) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for(int t = 1 ; t <= T; ++t) {
		ll Z;
		cin >> Z;
		ll sz = std::sqrt(Z);
		ll p2 = sz+1;
		while(!prime(p2)) ++ p2;
		ll p1 = sz;
		while(!prime(p1)) -- p1;
		while(p2*p1 > Z) {
			p2 = p1--;
			while(!prime(p1)) -- p1;
		}
		ll ans = p1 * p2;
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}