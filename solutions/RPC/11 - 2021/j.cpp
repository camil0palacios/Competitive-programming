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

double dist(int x1, int y1, int x2, int y2) {
    double x = x1 - x2;
    double y = y1 - y2;
    return sqrt(x*x + y*y);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(10);
    int x1[2], y1[2];
    int x2[2], y2[2];
    cin >> x1[0] >> y1[0] >> x2[0] >> y2[0];
    cin >> x1[1] >> y1[1] >> x2[1] >> y2[1];
    double mx = 0;
    fori(i,0,2) {
        mx = max(mx, dist(x1[i], y1[i], x2[i], y2[i]));
    }
    cout << mx << endl;
    return 0; 
}