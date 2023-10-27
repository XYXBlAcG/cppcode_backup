#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

const int INF = INT_MAX; // 无穷大

struct Edge {
    int to, cap, rev;
};

class Dinic {
public:
    Dinic(int V) : V(V) {
        adj.resize(V);
        level.resize(V);
        iter.resize(V);
    }

    void addEdge(int from, int to, int cap) {
        adj[from].push_back({to, cap, static_cast<int>(adj[to].size())});
        adj[to].push_back({from, 0, static_cast<int>(adj[from].size()) - 1});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (const Edge& e : adj[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] >= 0;
    }

    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int& i = iter[v]; i < adj[v].size(); ++i) {
            Edge& e = adj[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    adj[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int maxFlow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            fill(iter.begin(), iter.end(), 0);
            int f;
            while ((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
        }
        return flow;
    }

private:
    int V;
    vector<vector<Edge>> adj;
    vector<int> level;
    vector<int> iter;
};

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges in the graph: ";
    cin >> V >> E;

    Dinic dinic(V);

    cout << "Enter the edges and their capacities:" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        dinic.addEdge(u, v, capacity);
    }

    int src, dest;
    cout << "Enter the source and sink vertices: ";
    cin >> src >> dest;

    int maxFlow = dinic.maxFlow(src, dest);
    cout << "The maximum flow in the given network is: " << maxFlow << endl;

    return 0;
}