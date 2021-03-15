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
    string s;
    while(cin >> s) {
        int n = sz(s);
        int cnt = 0;
        fori(i,0,n) {
            if(s[i] != '(' && s[i] != ')') continue;
            cnt += s[i] == '(' ? 1 : -1;
            if(cnt < 0) break;
        }
        cout << (!cnt ? "correct" : "incorrect") << endl;
    }
    return 0; 
}