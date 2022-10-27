#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a, b;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(i & 1)b.emplace_back(x);
        else a.emplace_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    bool ok = 1;
    int idx = 0, x = 0, y = 0;
    while(x < a.size() && y < b.size()) {
        if(idx % 2 == 0 && a[x] > b[y]){
            ok = 0;
            break;
        }
        else if(idx % 2 != 0 && b[y] > a[x]) {
            ok = 0;
            break;
        }
        if(idx % 2 == 0)x++;
        else y++;
        idx++;
    }
    if(ok) cout << "OK" << endl;
    else cout << idx << endl;
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