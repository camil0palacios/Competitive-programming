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

const int N = 5050;
int s[N];

void solve(int t) {
    int n, p;
    cin >> n;
    fori(i,0,N) s[i] = 0;
    fori(i,0,n) {
        int a, b;
        cin >> a >> b;
        s[a]++, s[b+1]--;
    }
    fore(i,1,N) s[i] += s[i-1];
    cin >> p;
    fori(i,0,p) {
        int c; cin >> c;
        cout << s[c] << ' ';
    }
    cout << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": ";
        solve(i);
    }
    return 0; 
}