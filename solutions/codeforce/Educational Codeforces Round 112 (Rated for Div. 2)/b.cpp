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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const ll oo = 1e12;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(10);
    int t;
    cin >> t;
    while(t--) {
        double W, H;
        double x1, y1, x2, y2;
        double w, h;
        cin >> W >> H;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> w >> h;
        double d = oo;
        if(x2-x1 + w <= W) {
            if(max(x1, W-x2) < w) d = min(d, w - max(x1, W-x2));
            else d = 0;
        }
        if(y2-y1 + h <= H){
            if(max(y1, H-y2) < h) d = min(d, h - max(y1, H-y2));
            else d = 0;
        } 
        if(d == oo) cout << "-1" << endl;
        else cout << d << endl;
    }
    return 0; 
}