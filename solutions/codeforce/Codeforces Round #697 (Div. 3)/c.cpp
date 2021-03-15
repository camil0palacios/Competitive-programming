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
        int a, b, k;
        cin >> a >> b >> k;
        vii v(k);
        fori(i,0,k) cin >> v[i].ft;
        fori(i,0,k) cin >> v[i].sd;
        sort(all(v));
        map<int,int> m1, m2;
        map<ii, int> m3;
        fori(i,0,k) {
            m1[v[i].ft]++; 
            m2[v[i].sd]++;
            m3[{v[i].ft, v[i].sd}]++;
        }
        ll ans = 0;
        fori(i,0,k) {
            int x = m1[v[i].ft];
            int y = m2[v[i].sd];
            int z = m3[{v[i].ft, v[i].sd}];
            ans += (k - (x + y - z));
        }
        cout << ans/2 << endl;
    }
    return 0; 
}