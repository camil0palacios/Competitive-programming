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

const int oo = 1e9;
const int Mxn = 3e5 + 5;
int dist[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, vi> pos;
        fore(i,1,n) {
            int x; cin >> x;
            pos[x].eb(i);
        }
        for(auto & p : pos) p.sd.eb(0), p.sd.eb(n+1);
        for(auto & p : pos) sort(all(p.sd));
        fore(i,0,n) dist[i] = oo;
        for(auto & p : pos) {
            auto v = p.sd;
            int mx = 0;
            fori(i,1,sz(v)) {
                mx = max(mx, v[i]-v[i-1]);
            }
            dist[mx] = min(dist[mx], p.ft);
        }
        int lst = oo;
        fore(i,1,n) {
            if(dist[i] != oo) {
                lst = min(lst, dist[i]);
            }
            cout << (lst == oo ? -1 : lst) << ' ';
        }
        cout << endl;
    }
    return 0; 
}