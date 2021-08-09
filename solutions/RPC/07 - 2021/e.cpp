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
typedef vector<vi> mat;

const int mod = 37;

int char_to_int(char c) {
    if(c == ' ') return 36;
    if(isalpha(c)) return c-'A';
    return 26+(c-'0');
}

char int_to_char(int x) {
    if(x == 36) return ' ';
    if(x < 26) return char(x+'A');
    return char(x-26+'0');
}

vi mult(mat & a, vi & b) {
    int n = sz(a);
    vi v(n);
    fori(i,0,n) {
        fori(j,0,n) {
            v[i] = (v[i] + (a[i][j]*b[j]) % mod) % mod;
        }
    }
    return v;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    cin >> n;
    mat a(n, vi(n));
    fori(i,0,n) fori(j,0,n) cin >> a[i][j];
    cin.ignore();
    getline(cin, s);
    int m = sz(s);
    mat v;
    for(int i = 0; i < m; i += n) {
        vi tmp;
        fori(j,0,n) {
            if(i+j < m) tmp.eb(char_to_int(s[i+j]));
            else tmp.eb(36); 
        }
        v.eb(tmp);
    }
    fori(i,0,sz(v)) v[i] = mult(a, v[i]);
    string ans;
    fori(i,0,sz(v)) {
        fori(j,0,n) {
            ans += int_to_char(v[i][j]);
        }
    }
    cout << ans << endl;
    return 0; 
}