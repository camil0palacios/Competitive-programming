#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 1010;
int a[MXN][MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int ans = 0;
    map<int,map<int,int>> m;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ans += m[y - x][x - y] + m[y + x][x + y];
        m[y - x][x - y]++, m[y + x][x + y]++;
    }    
    cout << ans << endl;
    return 0;
}