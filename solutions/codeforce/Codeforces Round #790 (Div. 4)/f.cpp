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

const int N = 2e5 + 5;
int a[N];
ii b[N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        fori(i,0,n) cin >> a[i];
        sort(a, a+n);
        int m = 0;
        fori(i,0,n) {
            int j = i;
            while(j < n && a[i] == a[j]) j++;
            b[m++] = {a[i], j-i};
            i = j-1;
        }
        int pl = -1, pr = -1, lst = -1;
        int l = -1, mx = -1;
        fori(i,0,m) {
            if(b[i].sd >= k) {
                if(lst+1 != b[i].ft) l = i;
                if(b[i].ft - b[l].ft > mx) {
                    mx = b[i].ft - b[l].ft;
                    pl = l, pr = i;
                }
                lst = b[i].ft;
            } else lst = -1;
        }
        if(pl != -1) cout << b[pl].ft << ' ' << b[pr].ft << endl;
        else cout << -1 << endl;
    }
    return 0; 
}