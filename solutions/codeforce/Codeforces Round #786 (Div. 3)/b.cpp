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
    map<string, int> m;
    int idx = 0;
    fori(i,0,26) {
        fori(j,0,26) {
            if(i == j) continue;
            string s;
            s += char(i + 'a');
            s += char(j + 'a');
            m[s] = ++idx;
        }
    }
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << m[s] << endl;
    }
    return 0; 
}