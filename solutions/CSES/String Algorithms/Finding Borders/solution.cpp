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

const int p = 65537;
const int m1 = 39916801;
const int m2 = 479001599;

struct Hash_pair {
    size_t operator() (const ii & p) const {
        return hash<int>()(p.ft) ^ hash<int>()(p.sd);
    }
};

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int n = sz(s);
    unordered_set<ii, Hash_pair> st;
    ll h1 = 0, h2 = 0;
    forr(i,n-1,0) {
        h1 = (h1*p + (s[i]-'a'+1)) % m1;
        h2 = (h2*p + (s[i]-'a'+1)) % m2;
        st.insert({h1, h2});
    }
    h1 = h2 = 0;
    ll pw1 = 1, pw2 = 1;
    fori(i,0,n-1) { 
        h1 = (h1 + (s[i]-'a'+1)*pw1) % m1;
        h2 = (h2 + (s[i]-'a'+1)*pw2) % m2;
        if(st.count({h1, h2})) cout << i+1 << ' ';
        pw1 = (pw1*p) % m1;
        pw2 = (pw2*p) % m2; 
    }
    cout << endl;
    return 0; 
}