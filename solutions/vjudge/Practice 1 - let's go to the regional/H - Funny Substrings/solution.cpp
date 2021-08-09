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

struct Word {
    ll cnt;
    string s;
    Word(): cnt(0) {}
};

int count(string s, string t) {
    int ans = 0;
    int n = sz(s), m = sz(t);
    fori(i,0,n-m+1)
        ans += s.substr(i, m) == t;
    return ans;
}

string get_fst(string s) {
    if(sz(s) < 3) return s;
    return s.substr(0, 3);
}

string get_lst(string s) {
    if(sz(s) < 3) return s;
    return s.substr(sz(s)-3, 3);
}

Word merge(Word a, Word b) {
    Word ans;
    ans.cnt = a.cnt + b.cnt + count(get_lst(a.s) + get_fst(b.s), "haha");
    ans.s = a.s + b.s;
    if(sz(ans.s) >= 7) 
        ans.s = get_fst(ans.s) + "@" + get_lst(ans.s);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        ll ans = 0;
        map<string, Word> m;
        fori(i,0,n) {
            string lst, op;
            cin >> lst >> op;
            if(op == "=") {
                string a, b;
                cin >> a >> op >> b;
                m[lst] = merge(m[a], m[b]);
            } else {
                string t;
                cin >> t;
                m[lst].cnt = count(t, "haha");
                m[lst].s = t;
            }
            ans = m[lst].cnt;
        }
        cout << ans << endl;
    }
    return 0; 
}