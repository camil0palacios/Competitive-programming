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

int check(string & n, string & x) {
    int j = 0, del = 0;
    fori(i,0,sz(n)) {
        if(j < sz(x) && n[i] == x[j]) j++;
        else del++;
    }
    return del + (sz(x) - j);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string n;
        cin >> n;
        int ans = 1e9;
        fori(i,0,63) {
            string x = to_string(1ll << i);
            ans = min(ans, check(n, x));
        } 
        cout << ans << endl;
    }
    return 0; 
}