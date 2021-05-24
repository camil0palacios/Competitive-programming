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
        int x = 0, y = 0;
        fori(i,0,n) {
            if(s[i] == 'T') x++;
            else y++;
        }
        if(x != 2*y) cout << "NO" << endl;
        else {
            int x = n/3, c = 0;
            fori(i,0,n) {
                if(s[i] == 'T') c++;
                else c--;
                if(c < 0 || c > x) break;
            }
            cout << (c == x ? "YES" : "NO") << endl;
        }
    }
    return 0;
}