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

bool is_palindrome(string & s) {
    string t = s;
    reverse(all(t));
    return s == t;
}

void solve() {
    int a, b, n;
    string s;
    cin >> a >> b >> s;
    n = sz(s);
    fori(i,0,n/2) {
        if((s[i] == '0' && s[n-i-1] == '?') || (s[i] == '?' && s[n-i-1] == '0')) {
            if(s[i] == '0') s[n-i-1] = '0';
            else s[i] = '0';
        }
        else if((s[i] == '1' && s[n-i-1] == '?') || (s[i] == '?' && s[n-i-1] == '1')) {
            if(s[i] == '1') s[n-i-1] = '1';
            else s[i] = '1';
        }
    }
    int ca = 0, cb = 0;
    fori(i,0,n) {
        ca += s[i] == '0';
        cb += s[i] == '1';
    }
    int aca = 0, acb = 0;
    fori(i,0,n/2) {
        if(s[i] == '?' && s[n-i-1] == '?') {
            if(aca + 2 + ca <= a) {
                s[i] = s[n-i-1] = '0';
                aca += 2;
            }
            else if(acb + 2 + cb <= b) {
                s[i] = s[n-i-1] = '1';
                acb += 2;
            } else {
                cout << -1 << endl;
                return;
            }
            continue;
        }
        if(s[i] == s[n-i-1]) {
            if(s[i] == '0') aca += 2, ca -= 2;
            else acb += 2, cb -= 2;
            continue;
        }
    }
    if(n & 1 && s[n/2] == '?') {
        if(aca < a) aca++, s[n/2] = '0';
        else acb++, s[n/2] = '1';
    }
    if(aca + ca == a && acb + cb == b && is_palindrome(s)) cout << s << endl;
    else cout << -1 << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}