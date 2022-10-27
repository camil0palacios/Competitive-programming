#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void sol() {
    int x, y; string s;
    cin >> x >> y >> s;
    int time = 1, ans = -1;
    for(int i = 0; i < s.size(); i++) {
        x += s[i] == 'E';
        x -= s[i] == 'W';
        y += s[i] == 'N';
        y -= s[i] == 'S';
        // cout << x << ' ' << y << endl;
        if(abs(x) + abs(y) <= time) {
            ans = time;
            break;
        }
        time++;
    }
    if(ans != -1) {
        cout << ans << endl;
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