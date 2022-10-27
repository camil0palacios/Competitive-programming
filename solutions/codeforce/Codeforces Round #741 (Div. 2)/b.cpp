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


bool is_prime(int x) {
    if(x < 2) return 0;
    if(x == 2) return 1;
    if(x % 2 == 0) return 0;
    for(int i = 3; i*i <= x; i += 2) {
        if(x % i == 0) return 0;
    }
    return 1;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    fori(i,0,n) {
        int x = s[i]-'0';
        if(!is_prime(x)) {
            cout << 1 << endl;
            cout << x << endl;
            return;
        }
    }
    fori(i,0,n) {
        int x = (s[i]-'0')*10;
        fori(j,i+1,n) {
            int y = (s[j]-'0');
            if(!is_prime(x+y)) {
                cout << 2 << endl;
                cout << x+y << endl;
                return;
            }
        }
    }

}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}