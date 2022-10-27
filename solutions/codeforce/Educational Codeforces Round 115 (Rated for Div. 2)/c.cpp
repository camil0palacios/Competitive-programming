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
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;
typedef __int128_t i128;

const int Mxn = 2e5 + 5;
int a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll ans = 0;
        i128 s = 0;
        fori(i,0,n) cin >> a[i], s += a[i];
        if(s*(n-2) % n == 0) {
            i128 x = s*(n-2)/n;
            map<i128, int> m;
            fori(i,0,n) {
                if(m.count(s - a[i])) {
                    ans += m[s - a[i]];
                }
                m[x + a[i]]++;
            }
        } 
        cout << ans << endl;
    }
    return 0; 
}