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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

void solve() {
    int px, py;
    string s;
    cin >> px >> py >> s;
    int n = sz(s);
    int r = 0, u = 0, d = 0, l = 0;
    fori(i,0,n) {
        r += s[i] == 'R';
        u += s[i] == 'U';
        d += s[i] == 'D';
        l += s[i] == 'L';
    }
    if(px >= 0) {
        if(py >= 0) {
            if(r >= px && u >= py) {
                cout << "YES" << endl;
                return;
            }   
        } else {
            if(r >= px && d >= abs(py)) {
                cout << "YES" << endl;
                return;
            }
        }
    } else {
        if(py >= 0) {
            if(l >= abs(px) && u >= py) {
                cout << "YES" << endl;
                return;
            }
        } else {
            if(l >= abs(px) && d >= abs(py)) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0; 
}