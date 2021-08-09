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

const int oo = 2e9;
const int Mxn = 1e5 + 5;
string a[Mxn], b[Mxn];
unordered_map<string, vi> p;
map<pair<string,string>, int> memo;

int lower(vi & a, int x) {
    int l = 0, r = sz(a)-1, ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(a[mid] <= x) ans = mid, l = mid+1;
        else r = mid-1;
    }
    return ans;
}

int upper(vi & a, int x) {
    int l = 0, r = sz(a)-1, ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(a[mid] >= x) ans = mid, r = mid-1;
        else l = mid+1;
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    string s;
    cin >> s >> q;
    unordered_set<string> m;
    fori(i,0,q) {
        cin >> a[i] >> b[i];
        m.insert(a[i]);
        m.insert(b[i]);
    }
    int n = sz(s);
    fori(i,0,n) {
        fore(l,1,4) {
            if(i+l > n) break;           
            string t = s.substr(i, l);     
            if(m.count(t)) p[t].eb(i);
        }
    }
    fori(i,0,q) {
        string x = a[i], y = b[i];
        if(sz(p[x]) > sz(p[y])) swap(x, y);
        if(!sz(p[x]) || !sz(p[y])) { 
            cout << -1 << endl;
            continue;
        }
        else if(!memo.count({x, y})) {
            int ans = oo;
            fori(i,0,sz(p[x])) {
                int pos = lower(p[y], p[x][i]);
                if(pos != -1) {
                    int l = p[y][pos], r = p[x][i];
                    ans = min(ans, max(r + sz(x) , l + sz(y)) - l);
                    if(pos+1 < sz(p[y])) {
                        int l = p[x][i], r = p[y][pos+1];
                        ans = min(ans, max(r + sz(y), l + sz(x)) - l);
                        
                    }
                } else {
                    pos = upper(p[y], p[x][i]);
                    if(pos != -1) {
                        int l = p[x][i], r = p[y][pos];
                        ans = min(ans, max(r + sz(y), l + sz(x)) - l);
                    }
                }
            }
            memo[{x, y}] = ans == oo ? -1 : ans;
        }
        cout << memo[{x, y}] << endl;
    }
    return 0; 
}