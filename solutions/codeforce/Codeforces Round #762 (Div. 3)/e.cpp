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
ll a[Mxn], c[Mxn], ans[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fore(i,0,n) c[i] = ans[i] = 0;
        fori(i,0,n) cin >> a[i], c[a[i]]++;
        memset(ans, -1, sizeof ans);
        ll acc = 0, f = 0;
        vii v;
        fore(i,0,n) {
            ans[i] = f ? -1 : c[i] + acc;
            if(!c[i]) {
                int x = sz(v);
                if(x && v[x-1].sd-1 >= 0) {
                    acc += i-v[x-1].ft;
                    v[x-1].sd--;
                    if(!v[x-1].sd) v.pop_back();
                }
                else f = 1;
            } 
            else if(c[i] >= 2) v.eb(i, c[i]-1);
        }
        fore(i,0,n) cout << ans[i] << ' ';
        cout << endl;
    }
    return 0; 
}