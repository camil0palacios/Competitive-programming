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
        int n; char c;
        string s;
        cin >> n >> c >> s;
        int eq = 1;
        fori(i,1,n) eq &= s[i] == s[i-1];
        if(eq && s[0] == c) cout << 0 << endl;
        else { 
            bool can = 0;
            int x = 0;
            forr(i,n-1,0) {
                if(s[i] == c) {
                    bool eq = 1;
                    for(int j = i; j < n; j += i+1) {
                        eq &= s[j] == c;
                    }
                    if(eq) {
                        can = 1;
                        x = i;
                        break;
                    }
                }
            }
            if(can) {
                cout << 1 << endl;
                cout << x+1 << endl;
            } else {
                cout << 2 << endl;
                cout << n << ' ' << n-1 << endl;
            }
        }
    }
    return 0; 
}