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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

string pos[3] = {"((", "))", "()"};

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; string s;
        cin >> n >> s;
        int op = 0, i;
        for(i = 0; i < n; i++) {
            bool can = 0;
            fori(j,0,3) {
                if(s.substr(i, sz(pos[j])) == pos[j]) {
                    i += sz(pos[j])-1;
                    can = 1;
                    break;
                }
            }
            if(!can && s[i] == ')') {
                int j = i+1;
                while(j < n && s[j] == '(') j++;
                if(j < n && s[j] == ')') i = j, can = 1;
            }
            if(can) op++;
            else break;
        }
        cout << op << ' ' << n-i << endl;
    }
    return 0; 
}