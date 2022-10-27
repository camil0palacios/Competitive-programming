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
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        int two = 0;
        vi ts;
        fori(i,0,n) {
            two += s[i] == '2';
            if(s[i] == '2') ts.eb(i);
        }
        if(two == 1 || two == 2) cout << "NO" << endl;
        else {
            string a[n];
            fori(i,0,n) a[i] = string(n, '='), a[i][i] = 'X';
            int m = sz(ts);
            fori(p,0,m) {
                int i = ts[p], j = ts[(p+1) % m];
                a[i][j] = '+';
                a[j][i] = '-';     
            }
            cout << "YES" << endl;
            fori(i,0,n) cout << a[i] << endl;
        }
    }
    return 0; 
}