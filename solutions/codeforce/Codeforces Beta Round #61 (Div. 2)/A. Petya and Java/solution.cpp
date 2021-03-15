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

string x[4] = { "127", "32767", "2147483647", "9223372036854775807" };
string ans[5] = { "byte", "short", "int", "long", "BigInteger" };

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    fori(i,0,4) {
        if(sz(s) < sz(x[i])) {
            cout << ans[i] << endl;
            return 0;
        }
        if(sz(s) == sz(x[i])) {
            int n = sz(x[i]);
            fori(j,0,n) {
                if(s[j] == x[i][j]) continue;
                if(s[j] > x[i][j]) {
                    cout << ans[i+1] << endl;
                    return 0;
                } else break;
            }
            cout << ans[i] << endl;
            return 0;
        }
    }
    cout << ans[4] << endl;
    return 0; 
}