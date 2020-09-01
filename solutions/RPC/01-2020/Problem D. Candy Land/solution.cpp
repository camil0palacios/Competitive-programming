#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, p;
    cin >> n >> p;
    vector<string> t(n + 1);
    for(int i = 1; i <= n - 1; i++) {
        cin >> t[i];
    }
    int c;
    cin >> c;
    deque< pair<int, string> > q(c);
    for(int i = 0; i < c; i++) {
        cin >> q[i].first >> q[i].second;
    }
    int pos[p];
    memset(pos, 0, sizeof pos);
    int cur = 0, ans = 0;
    while(true) {
        int type = q.front().first;
        string card = q.front().second;
        q.emplace_back(q.front());
        q.pop_front(); 
        bool ok = 1;
        if(type == 1) {
            for(int i = pos[cur] + 1; i <= n - 1; i++) {
                if(t[i] == card){
                    pos[cur] = i;
                    ok = 0;
                    break;
                }
            }
        }
        else if(type == 2){
            int cnt = 0;
            for(int i = pos[cur] + 1; i <= n - 1; i++) {
                if(t[i] == card)cnt++;
                if(cnt == 2){
                    pos[cur] = i;
                    ok = 0;
                    break;
                }
            }
        }
        else {
            for(int i = 1; i <= n - 1; i++) {
                if(t[i] == card) {
                    pos[cur] = i;
                    ok = 0;
                    break;
                }
            }
        }
        if(ok){
            ans = cur;
            break;
        }
        cur = (cur + 1) % p;
    }
    cout << ans + 1 << endl;
    return 0;
}