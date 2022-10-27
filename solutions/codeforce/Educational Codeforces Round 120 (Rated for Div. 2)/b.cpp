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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 2e5 + 5;
int p[Mxn], q[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        fori(i,0,n) cin >> p[i];
        cin >> s;
        vii o, z;
        fori(i,0,n) {
            if(s[i] == '0') z.eb(mp(p[i], i));
            else o.eb(mp(p[i], i));
        }
        sort(all(o));
        sort(all(z));
        int j = sz(z)-1;
        forr(i,sz(o)-1,0) {
            if(j >= 0 && o[i].ft <= n-sz(o)) {
                swap(o[i].ft, z[j].ft);
                j--;
            }
            q[o[i].sd] = o[i].ft;
        }
        fori(i,0,sz(z)) q[z[i].sd] = z[i].ft;
        fori(i,0,n) cout << q[i] << ' ';
        cout << endl;
    }
    return 0; 
}