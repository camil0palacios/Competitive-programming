#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        unordered_map<int, vector<int>> seg;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            seg[a].emplace_back(i);
        }
        int ans = 1e9;
        for(auto & p : seg) {
            auto & a = p.second;
            int sz = a.size();
            int tmp = 0;
            if(a[0] != 0) tmp++;
            for(int i = 1; i < sz; i++) {
                if(a[i] != a[i - 1] + 1) tmp++;
            }
            if(a[sz - 1] != n-1) tmp++;
            ans = min(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0; 
}