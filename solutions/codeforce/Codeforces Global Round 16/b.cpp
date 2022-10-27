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

bool equal_char(string & s, char c) {
    int n = sz(s);
    bool ok = 1;
    fori(i,0,n) ok &= s[i] == c;
    return ok;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        bool x = equal_char(s, '0');
        bool y = equal_char(s, '1');
        if(!x && !y) {
            int n = sz(s), z = 0;
            fori(i,0,n) {
                if(s[i] == '1') continue;
                int j = i;
                while(j < n && s[j] == '0') j++;
                i = j-1;
                z++;
            }
            if(z == 1) cout << 1 << endl;
            else cout << 2 << endl;
        }
        else if(x) cout << 1 << endl;
        else cout  << 0 << endl;
    }
    return 0; 
}