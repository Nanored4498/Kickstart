#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        int N, M, P;
        cin >> N >> M >> P;
        vector<int> c(P, 0), o(P);
        for(int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            for(int j = 0; j < P; ++j) c[j] += s[j]-'0';
        }
        unordered_set<vector<bool>> S;
        while(M--) {
            string s;
            cin >> s;
            vector<bool> b(P);
            for(int i = 0; i < P; ++i) b[i] = s[i] == '1';
            S.insert(b);
        }

        vector<bool> ans(P);
        int A = 0;
        for(int i = 0; i < P; ++i) {
            A += min(c[i], N-c[i]);
            ans[i] = 2*c[i] > N;
            c[i] = abs(N - 2*c[i]);
            o[i] = i;
        }

        typedef pair<int, vector<bool>> QEl;
        priority_queue<QEl, vector<QEl>, greater<QEl>> Q;
        Q.emplace(0, ans);
        while(!Q.empty()) {
            auto [s, v] = Q.top(); Q.pop();
            if(!S.count(v)) {
                A += s;
                break;
            }
            for(int i = 0; i < P && v[i]==ans[i]; ++i) {
                v[i] = !ans[i];
                Q.emplace(s+c[i], v);
                v[i] = ans[i];
            }
        }

        cout << "Case #" << t << ": " << A << '\n';
    }

    return 0;
}