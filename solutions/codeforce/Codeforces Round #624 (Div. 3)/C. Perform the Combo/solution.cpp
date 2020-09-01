#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s;
        vector<int> v(m);
        cin >> s;
        for(int i = 0; i < m; i++){
            cin >> v[i];
        }
        vector< vector<int> > ps(n, vector<int>(26, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 26 && i != 0; j++){
                ps[i][j] = ps[i-1][j];    
            }
            ps[i][s[i] - 'a']++;
        }
        vector<int> ans(26);
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < m; j++){ 
                ans[i] += ps[v[j] - 1][i]; 
            }
        }
        for(int i = 0; i < 26; i++){
            ans[i] += ps[n-1][i];
        }
        for(int i = 0; i < 26; i++){
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}