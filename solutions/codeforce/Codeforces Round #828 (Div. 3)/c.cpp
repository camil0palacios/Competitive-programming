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

// typedef __int128_t i128; // only for extreme cases
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
        int n; char c;
        string s;
        cin >> n >> c >> s;
        int x[n+1];
        memset(x, -1, sizeof x);
        forr(i,n-1,0) {
            if(s[i] == 'g') x[i] = i;
            else x[i] = x[i+1]; 
        }
        int mx = 0;
        fori(i,0,n) {
            if(s[i] == c) {
                if(x[i] == -1) mx = max(mx, n - i + x[0]);
                else mx = max(mx, x[i] - i);
            }
        }
        cout << mx << endl;
    }
    return 0; 
}