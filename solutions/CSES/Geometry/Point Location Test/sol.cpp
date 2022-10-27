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

typedef ll T;
struct pt {
    T x, y;
    pt() {}
    pt(T x, T y): x(x), y(y) {}
    pt operator-(pt q) { return pt(x-q.x, y-q.y); }
    pt operator+(pt q) { return pt(x+q.x, y+q.y); }
    pt operator*(T d) { return pt(x*d, y*d); }
    pt operator/(T d) { return pt(x*d, y*d); }
};

// |a x b| = sen(teta)|a||b|
// a.x * b.y - b.x * a.y
T cross(pt p, pt q) {
    return p.x*q.y - p.y*q.x;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        pt a, b, c;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        ll ans = cross(b-a, c-a);
        if(ans > 0) cout << "LEFT";
        else if(ans < 0) cout << "RIGHT";
        else cout << "TOUCH";
        cout << endl;
    }
    return 0; 
}