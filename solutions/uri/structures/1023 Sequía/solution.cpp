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
    // cout << fixed << setprecision(2);
    int n, tc = 0;
    while(cin >> n, n) {
        map<int,int> m;
        double pr = 0, tot = 0;
        fori(i,0,n) {
            int x, y;
            cin >> x >> y;
            m[y/x] += x;
            pr += y;
            tot += x;
        }
        pr /= tot;
        if(tc) cout << endl;
        cout << "Cidade# " << ++tc << ":" << endl; 
        bool ok = 0;
        for(auto & p : m) {
            if(ok) cout << ' ';
            cout << p.sd << "-" << p.ft;
            ok = 1;
        }
        string tmp = to_string(pr);
        string ans;
        fori(i,0,sz(tmp)) {
            if(tmp[i] == '.') {
                ans = tmp.substr(0, i+3);
                break;
            } 
        }
        cout << endl;
        cout << "Consumo medio: " << ans << " m3." << endl;
        // printf("Consumo medio: %.2f m3.", pr);
    }
    return 0; 
}