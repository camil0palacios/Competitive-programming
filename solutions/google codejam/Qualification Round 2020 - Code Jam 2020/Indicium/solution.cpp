#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef vector<int> vi;
typedef vector<vi> mat;
typedef unordered_set<int> us;
typedef vector<us> vus;

int n, t;

bool backtrack(int i, int j, vus & r, vus & c, mat & a) {
    if(i == n) {
        int sum = 0;
        for(int k = 0; k < n; k++) sum += a[k][k];
        return sum == t;
    }
    for(int k = 1; k <= n; k++) {
        if(!r[i].count(k) && !c[j].count(k)) {
            r[i].insert(k); c[j].insert(k);
            a[i][j] = k;
            bool ans = backtrack((j + 1 == n ? i + 1 : i), (j + 1) % n, r, c, a);
            if(ans) return ans;
            a[i][j] = 0;
            r[i].erase(k); c[j].erase(k);
        }
    }
    return 0;
}

void sol() {
    cin >> n >> t;
    mat a(n, vi(n));
    vus r(n); vus c(n); 
    bool ans = backtrack(0, 0, r, c, a);
    if(ans) {
        cout << "POSSIBLE" << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        sol();
    }
    return 0;
}