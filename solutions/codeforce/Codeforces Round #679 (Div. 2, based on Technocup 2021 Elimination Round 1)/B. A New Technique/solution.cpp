#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 5005;
int l[MXN], to[MXN];
int a[MXN][MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
                mp[a[i][j]] = i;
            }
            l[i] = to[i] = -1;
        }
        for(int j = 0; j < m; j++) {
            vector<int> tmp(n);
            for(int i = 0; i < n; i++) {
                int x; cin >> x;
                tmp[i] = x;
            }
            for(int i = 0; i < n - 1; i++) {
                int id = mp[tmp[i]];
                to[id] = mp[tmp[i + 1]];
                l[mp[tmp[i + 1]]] = id;
            }
        }
        for(int i = 0; i < n; i++) {
            if(l[i] == -1) {
                while(i != -1) {
                    for(int j = 0; j < m; j++) {
                        cout << a[i][j] << ' ';
                    }
                    cout << endl;
                    i = to[i];
                }
                break;
            }
        }
    }
    return 0;
}