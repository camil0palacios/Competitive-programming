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
typedef vector<ii> vii;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        vector<int> v;
        int n = sz(s);
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                int j = i;
                while(j < n && s[j] == '1') j++;
                v.emplace_back(j - i);
                i = j-1;
            }
        }
        n = sz(v);
        sort(all(v), greater<int>());
        int ans = 0;
        for(int i = 0; i < n; i += 2) {
            ans += v[i];
        }
        cout << ans << endl;
    }
    return 0; 
}