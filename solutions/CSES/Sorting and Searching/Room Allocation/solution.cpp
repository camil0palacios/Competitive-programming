#include <bits/stdc++.h>
#define endl '\n'
#define ft first
#define sd second
#define eb emplace_back
#define all(v) v.begin(), v.end()
using namespace std;

typedef pair<int,int> ii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<ii> a;
    for(int i = 1; i <= n; i++) {
        int l, r; 
        cin >> l >> r;  
        a.eb(l, -i);
        a.eb(r, i);
    }
    sort(all(a));
    vector<int> ans(n);
    set<int> ocup, free;
    int mx = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i].sd > 0) {
            int id = a[i].sd - 1;
            ocup.erase(ans[id]);
            free.insert(ans[id]);
        }
        if(a[i].sd < 0) {
            int id = -a[i].sd - 1;
            if(free.empty()) {
                ans[id] = ++mx;
                ocup.insert(ans[id]);
            } else {
                int room = *free.begin();
                ans[id] = room;    
                free.erase(free.begin());
                ocup.insert(room);                
            }
        }
    } 
    cout << mx << endl;
    for(auto & i : ans) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}