#include <iostream>

using namespace std;

int main() {

	int T; cin >> T;
	for(int t = 1; t <= T; ++t) {
		string x;
		cin >> x;
		int s = 0;
		for(char c : x) s += c-'0';
		char c = (9-(s%9)) + '0';
		if(c == '9') x.insert(x.begin()+1, '0');
		else {
			int i = 0;
			while(i < x.size() && x[i] <= c) ++i;
			x.insert(x.begin()+i, c);
		}
		cout << "Case #" << t << ": " << x << endl;
	}

	return 0;
}