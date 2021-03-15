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
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        bool ok = 0;
        if(s.substr(0, 1) == "2" && s.substr(n-3, 3) == "020") ok = 1;
        if(s.substr(0, 2) == "20" && s.substr(n-2, 2) == "20") ok = 1;
        if(s.substr(0, 3) == "202" && s.substr(n-1, 1) == "0") ok = 1;
        if(s.substr(0, 4) == "2020" || s.substr(n-4, 4) == "2020") ok = 1;
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0; 
}