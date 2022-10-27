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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        string a, b;
        cin >> n >> m >> k;
        cin >> a >> b;
        sort(all(a));
        sort(all(b));
        string s;
        int i = 0, j = 0;
        int ca = 0, cb = 0;
        while(i < n && j < m) {
            if(a[i] < b[j] && ca + 1 <= k) {
                s += a[i++];
                ca++, cb = 0;
            } else if(b[j] < a[i] && cb + 1 <= k) {
                s += b[j++];
                cb++, ca = 0;
            } else {
                if(ca < k) s += a[i++], ca++, cb = 0;
                else if(cb < k) s += b[j++], cb++, ca = 0;
            }
        }
        cout << s << endl;
    }
    return 0; 
}