#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string tmp = "bugyrt";
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        vi f(26);
        fori(i,0,n) f[s[i]-'a']++;
        string t;
        fori(i,0,sz(tmp)) {
            int c = tmp[i]-'a';
            if(f[c]) {
                t += string(f[c], tmp[i]);
                f[c] = 0;
            }
        }
        fori(i,0,26) {
            if(f[i]) t += string(f[i], char(i + 'a'));
        }
        cout << t << endl;
    }
    return 0; 
}