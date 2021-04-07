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
    int n;
    cin >> n;
    string ans;
    fori(i,0,n) {
        string s;
        cin >> s;
        int m = sz(s);
        int p[m+1], k = 0;
        memset(p, 0, sizeof p);
        fori(j,1,m) {
            while(k > 0 && s[k] != s[j]) k = p[k-1];
            if(s[k] == s[j]) k++;
            p[j] = k;
        }
        k = 0;
        fori(j,max(0,sz(ans)-m),sz(ans)) {
            while(k > 0 && s[k] != ans[j]) k = p[k-1];
            if(s[k] == ans[j]) k++;
            if(k == m && j != sz(ans)-1) k = p[k-1];
        }
        fori(j,k,m) ans += s[j];
    }
    cout << ans << endl;
    return 0;
}