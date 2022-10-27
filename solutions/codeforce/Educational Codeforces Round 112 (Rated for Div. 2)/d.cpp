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

const int N = 2e5 + 5;
int ps[6][N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    string s;
    cin >> n >> m >> s;
    int p = 0;
    string t = "abc";
    do {
        int j = 0;
        fori(i,0,n) {
            ps[p][i+1] = ps[p][i] + (s[i] != t[j]);
            j = (j + 1) % 3;
        }
        p++;
    } while(next_permutation(all(t)));
    fori(i,0,m) {
        int l, r;
        cin >> l >> r;
        int tmp = 1e9;
        fori(j,0,6) {
            tmp = min(tmp, ps[j][r] - ps[j][l-1]);
        }
        cout << tmp << endl;
    }
    return 0; 
}