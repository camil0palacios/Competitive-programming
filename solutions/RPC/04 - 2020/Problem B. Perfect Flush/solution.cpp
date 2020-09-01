#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int n, k, a[MXN], lst[MXN], vis[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        lst[a[i]] = i;
    }
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(!vis[a[i]]) {
            while(!ans.empty() && a[i] < ans.back() && i < lst[ans.back()]) {
                vis[ans.back()] = 0;
                ans.pop_back();
            }
            vis[a[i]] = 1;
            ans.push_back(a[i]);
        }
    } 
    for(int i = 0; i < ans.size(); i++) {
        if(i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}