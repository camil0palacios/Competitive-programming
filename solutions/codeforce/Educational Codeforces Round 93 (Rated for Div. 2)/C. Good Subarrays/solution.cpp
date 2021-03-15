#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi p(n+1, 0);
        fore(i,1,n) {
            char c;
            cin >> c;
            p[i] = p[i-1] + (c-'0');
        }
        map<int,int> m;
        m[0]++;
        ll ans = 0;
        fore(i,1,n) {
            if(m.count(p[i] - i)) {
                ans += m[p[i] - i];
            }
            m[p[i] - i]++;
        }
        cout << ans << endl;
    }
    return 0; 
}