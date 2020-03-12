#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 1e5 + 5;
const int LG = 18;
int n, m;
int tin[MAXN], low[MAXN], tim, bcc;
int stk[MAXN], it;	//stack
int st[2*MAXN][LG], depth[2*MAXN];	// sparse table
bool cut[MAXN];
map< pair<int,int>, int > bridge;	// bridge as a node
vector<int> g1[MAXN], g2[2*MAXN];

pair<int,int> order(int u, int v){
	return make_pair(min(u, v), max(u, v));
}

void dfs1(int u, int p) {
	tin[u] = low[u] = ++tim;
	stk[it++] = u;
	for(auto & v : g1[u]){
		if(v == p)continue;
		if(!tin[v]){
			dfs1(v, u);
			if(low[v] >= tin[u]){
				cut[u] = 1;
				g2[u].emplace_back(n + bcc);
				do {
					g2[n + bcc].emplace_back(stk[it - 1]);
				} while(stk[--it] != v);
				if(low[v] > tin[u]){
					bridge[order(u, v)] = n + bcc;
				}
				bcc++;
			}
			low[u] = min(low[u], low[v]);
		}else{
			low[u] = min(low[u], tin[v]);
		}
	}
}

void dfs2(int u, int p) {
	st[u][0] = p;
	for(int i = 1; i < LG; i++){
		st[u][i] = st[st[u][i-1]][i-1];
	}
	for(auto & v : g2[u]){
		if(v == p)continue;
		depth[v] = depth[u] + 1;
		dfs2(v, u);
	}
}

int lca(int u, int v) {
	if(depth[u] < depth[v])swap(u, v);
	for(int i = LG - 1; i >= 0; i--) {
		if(depth[u] - (1 << i) >= depth[v]) {
			u = st[u][i];
		}
	}
	if(u == v)return u;
	for(int i = LG - 1; i >= 0; i--) {
		if(st[u][i] != st[v][i]) {
			u = st[u][i];
			v = st[v][i];
		}
	}
	return st[u][0];
}

bool isInPath(int u, int v, int x) {
	int uv = lca(u, v), ux = lca(u, x), vx = lca(v, x);
	if(ux == vx)return uv != x;
	return ux != x && vx != x && uv != x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0, u, v; i < m; i++){
		cin >> u >> v; u--, v--;
		g1[u].emplace_back(v);
		g1[v].emplace_back(u);
	}
	dfs1(0, 0);
	dfs2(0, 0);
	int q;
	cin >> q;
	while(q--){
		int t, u, v;
		cin >> t >> u >> v;
		u--, v--;
		if(t == 1){
			int g1, g2;
			cin >> g1 >> g2;
			g1--, g2--;
			if(!bridge.count(order(g1, g2))) {
				cout << "da" << endl;
			} else {
				int x = bridge[order(g1, g2)];
				if(isInPath(u, v, x)) cout << "da" << endl;
				else cout << "ne" << endl;
			}
		} else {
			int x;
			cin >> x;
			x--;
			if(!cut[x]){
				cout << "da" << endl;
			} else {
				if(isInPath(u, v, x)) cout << "da" << endl;
				else cout << "ne" << endl;
			}
		}
	}
	return 0;
}