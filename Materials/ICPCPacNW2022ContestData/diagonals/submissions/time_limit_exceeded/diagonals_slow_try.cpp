#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// KACTL
struct RollbackUF {
    vector<int> e; vector<pair<int, int>> st;
    RollbackUF(int n) : e(n, -1) {}
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }
    int time() { return st.size(); }
    void rollback(int t) {
        for (int i = time(); i --> t;)
            e[st[i].first] = st[i].second;
        st.resize(t);
    }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        st.push_back({a, e[a]});
        st.push_back({b, e[b]});
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

int main() {
    int32_t n;
    cin >> n;

    vector<string> a(n + 1);
    for (auto& x : a)
        cin >> x;

    int uf_size = (n + 1) * (n + 1);
    RollbackUF uf(uf_size);

    vector<string> cur(n, string(n, '.'));
    vector<vector<uint8_t>> hits(n + 1, vector<uint8_t>(n + 1, '0'));

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (a[i][j] == '0' || a[i][j] == '4') {
                bool is_four = a[i][j] == '4';
                if (i - 1 >= 0 && j - 1 >= 0) {
                    cur[i - 1][j - 1] = "/\\"[is_four];
                }
                if (i - 1 >= 0 && j < n) {
                    cur[i - 1][j] = "\\/"[is_four];
                }
                if (i < n && j - 1 >= 0) {
                    cur[i][j - 1] = "\\/"[is_four];
                }
                if (i < n && j < n) {
                    cur[i][j] = "/\\"[is_four];
                }
            }
        }
    }

    for (const auto& s : cur) {
        cerr << s << '\n';
    }

    auto dfs = [&](auto self, int x, int y) -> bool {
        if (y >= n) {
            if (a[x][y] != '+' && a[x][y] != hits[x][y]) {
                return false;
            }
            return self(self, x + 1, 0);
        }
        if (x >= n) {
            for (int i = n; i <= n; ++i) {
                for (int j = 0; j <= n; ++j) {
                    if (a[i][j] != '+' && a[i][j] != hits[i][j]) {
                        return false;
                    }
                }
            }

            return true;
        }

        if (cur[x][y] == '.' || cur[x][y] == '/') {
            // Try placing /
            cur[x][y] = '/';
            int t = uf.time();
            int u = (n + 1) * (x + 1) + y;
            int v = (n + 1) * x + (y + 1);

            ++hits[x + 1][y];
            ++hits[x][y + 1];

            bool valid = uf.join(u, v);
            valid = valid && (a[x][y] == '+' || a[x][y] == hits[x][y]);
            valid = valid && self(self, x, y + 1);

            if (valid) {
                return true;
            } else {
                uf.rollback(t);

                cur[x][y] = '.';

                --hits[x + 1][y];
                --hits[x][y + 1];
            }
        }

        if (cur[x][y] == '.' || cur[x][y] == '\\') {
            cur[x][y] = '\\';
            int t = uf.time();
            int u = (n + 1) * x + y;
            int v = (n + 1) * (x + 1) + (y + 1);

            ++hits[x][y];
            ++hits[x + 1][y + 1];

            bool valid = uf.join(u, v);
            valid = valid && (a[x][y] == '+' || a[x][y] == hits[x][y]);
            valid = valid && self(self, x, y + 1);

            if (valid) {
                return true;
            } else {
                uf.rollback(t);

                cur[x][y] = '.';

                --hits[x][y];
                --hits[x + 1][y + 1];
            }
        }

        return false;
    };

    bool found = dfs(dfs, 0, 0);
    assert(found);
    for (const auto& s : cur) {
        cout << s << '\n';
    }

    return 0;
}
