#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        n <<= 1;
        vi a(n);
        multiset<int> s;
        fori(i,0,n) { cin >> a[i]; s.insert(a[i]); }
        sort(all(a));
        vii ans;
        int px = 0;
        fori(i,0,n-1) {
            multiset<int> tmp = s;
            int x = a[n-1] + a[i];
            vii pos;
            while(!tmp.empty()) {
                int mx = *tmp.rbegin();
                if(mx >= x) break;
                tmp.erase(tmp.find(mx));
                auto it = tmp.find(x - mx);
                if(it == tmp.end()) break; 
                tmp.erase(it);
                pos.eb(mx, x - mx);
                x = mx;
            }
            if(tmp.empty()) {
                px = a[n-1] + a[i];
                ans = pos;
                break;
            }
        }
        if(!ans.empty()) {
            cout << "YES" << endl;
            cout << px << endl;
            for(auto & p : ans) cout << p.ft << ' ' << p.sd << endl;
        } else cout << "NO" << endl;
    }
    return 0; 
}