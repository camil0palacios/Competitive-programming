#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1010;
double x[MXN], y[MXN];
int p[MXN];

struct edge {
    int u, v;
    double w;
    edge() {}
    edge(int u, int v, double w): u(u), v(v), w(w) {}
    bool operator<(const edge& e) const {
        return w < e.w;
    }
};

int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }

bool join(int u, int v) {
    u = find(u), v = find(v);
    if(u != v) {
        p[v] = u;
        return 1;
    }
    return 0;
}

double kruskal(vector<edge>& edges) {
    sort(edges.begin(), edges.end());
    double ans = 0;
    for(auto & e : edges) {
        if(join(e.u, e.v)) {
            ans += e.w;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(2);
    int t;
    cin >> t;
    while(t--) { 
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
            x[i] /= 100, y[i] /= 100;
            p[i] = i;
        }
        vector<edge> edges;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                double dx = x[i] - x[j];
                double dy = y[i] - y[j];
                double dist = sqrt(dx*dx + dy*dy);
                edges.emplace_back(i, j, dist);
                edges.emplace_back(j, i, dist);
            }
        }
        cout << kruskal(edges) << endl;
    }
    return 0;
}