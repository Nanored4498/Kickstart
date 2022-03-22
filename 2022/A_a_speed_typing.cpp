#include <iostream>

using namespace std;

int main() {

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		string I, P;
		cin >> I >> P;
		int i = 0;
		for(char c : P) if(i < I.size() && c == I[i]) ++i;
		if(i == I.size()) cout << "Case #" << t << ": " << P.size()-I.size() << endl;
		else cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
	}

	return 0;
}