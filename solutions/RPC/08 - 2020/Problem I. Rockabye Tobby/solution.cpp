#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;  
        string a[n + 1];
        int f[n + 1];
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for(int i = 0; i < n; i++) {
            cin >> a[i] >> f[i]; 
            q.emplace(f[i], i);
        }
        for(int i = 0; i < k; i++) {
            int t = q.top().first;
            int j = q.top().second;
            q.pop();
            q.emplace(t + f[j], j);
            cout << t << ' ' << a[j] << endl; 
        }
    }
    return 0;
}