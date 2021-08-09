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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    set<string> x;
    fori(i,0,3) {
        string s;
        cin >> s;
        if(s[1] == '<') {
            string t = s;
            s = t[2]; s += ">"; s += t[0];
        }
        x.insert(s);
    }
    string c[3] = {"A", "B", "C"};
    int p[3] = {0, 1, 2};
    string ans = "Impossible";
    do {
        set<string> y;
        y.insert(c[p[1]]+">"+c[p[0]]);
        y.insert(c[p[2]]+">"+c[p[0]]);
        y.insert(c[p[2]]+">"+c[p[1]]);
        if(x == y) {
            ans = c[p[0]]+c[p[1]]+c[p[2]];
            break;
        }
    } while(next_permutation(p, p+3));
    cout << ans << endl;
    return 0; 
}