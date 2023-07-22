#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, m;
vector<int> g[N];
vector<int> path;

void dfs(int u) {
    while (g[u].size()) {
        int v = g[u].back();
        g[u].pop_back();
        dfs(v);
    }
    path.push_back(u);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (g[i].size() % 2 != 0) {
            cout << "No Euler Path" << endl;
            return 0;
        }
    }

    dfs(1);
    reverse(path.begin(), path.end());

    vector<int> ans;
    for (int i = 0; i < path.size() - 1; i++) {
        int u = path[i], v = path[i + 1];
        if (g[u].size() == 1 && g[v].size() == 1) {
            ans.push_back(u);
            ans.push_back(v);
        } else {
            ans.push_back(u);
            cout << ans.size() << " ";
            for (int j = 0; j < ans.size(); j++) {
                cout << ans[j] << " ";
            }
            cout << endl;
            ans.clear();
        }
    }

    return 0;
}