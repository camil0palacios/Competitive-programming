#include <bits/stdc++.h>
#define endl '\n'
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<ii> path;
    int x = 0, y = 0;
    int dir = 1;
    path.emplace_back(x + 1, y + 1);
    while(true) {
        y += dir;
        if(y == m || y == -1) dir *= -1, y = y == m ? m - 1 : 0, x++;
        if(x == n) break;
        path.emplace_back(x + 1, y + 1);
    }
    for(int i = 0; i < k - 1; i++) {
        cout << 2 << ' ';
        cout << path[2*i].ft << ' ' << path[2*i].sd << ' ';
        cout << path[2*i + 1].ft << ' ' << path[2*i + 1].sd << endl;
    }
    cout << path.size() - 2*(k - 1) << ' ';
    for(int i = 2 * (k - 1); i < path.size(); i++) {
        cout << path[i].ft << ' ' << path[i].sd << ' ';
    }
    cout << endl;
    return 0;
}