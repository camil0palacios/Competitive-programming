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

string a[3];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fori(i,0,3) cin >> a[i];
        string ans;
        n *= 2;
        int i = 0, j = 0, k = 0;
        while(i < n && j < n && k < n) {
            if(a[0][i] == a[1][j]) ans += a[0][i], i++, j++;
            else if(a[0][i] == a[2][k]) ans += a[0][i], i++, k++;
            else if(a[1][j] == a[2][k]) ans += a[1][j], j++, k++;
        }
        vector<pair<int,string>> v;
        v.eb(i, a[0]);
        v.eb(j, a[1]);
        v.eb(k, a[2]);
        sort(v.rbegin(), v.rend());
        i = v[1].ft, a[0] = v[1].sd;
        while(i < n) ans += a[0][i++];
        cout << ans << endl;
    }
    return 0; 
}