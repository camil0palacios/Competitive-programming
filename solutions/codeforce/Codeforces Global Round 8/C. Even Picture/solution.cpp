#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int dx[6] = {1, 0, -1, 0, 1, -1};
int dy[6] = {0, 1, 0, -1, 1, -1};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int x = 1, y = 1;
    set<pair<int, int>> ans;
    for(int i = 0; i < n; i++) {
        ans.insert({x, y});
        for(int j = 0; j < 6; j++) {
            ans.insert({x + dx[j], y + dy[j]});
        }
        x++, y++;
    }
    cout << ans.size() << endl;
    for(auto & i : ans) {
        cout << i.first << ' ' << i.second << endl;
    }
    return 0;
}