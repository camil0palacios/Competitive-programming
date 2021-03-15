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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;


struct pt {
    int x, y, a, b;
    // pt(){}
};

pt rotate(pt p){ 
    p.x -= p.a, p.y -= p.b;
    int tmp = p.x;
    p.x = -p.y;
    p.y = tmp;
    p.x += p.a, p.y += p.b;
    return p;
}

int dist(pt a, pt b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx*dx + dy*dy;
} 

bool check(vector<pt> & p) {
    int pe[4] = {0,1,2,3};
    int d1 = dist(p[0], p[1]);
    int d2 = dist(p[0], p[2]);
    int d3 = dist(p[0], p[3]);
    if(!d1 || !d2 || !d3) return 0;
    if(d1 == d2 && 2*d1 == d3 && 2*dist(p[1], p[3]) == dist(p[1], p[2])) return 1;
    if(d2 == d3 && 2*d2 == d1 && 2*dist(p[2], p[1]) == dist(p[2], p[3])) return 1;
    if(d1 == d3 && 2*d1 == d2 && 2*dist(p[1], p[2]) == dist(p[1], p[3])) return 1;
    return 0;
}

void go(int idx, int s, vector<pt> & p, int & mn) {
    if(idx == 4) {
        if(check(p)) mn = min(mn, s);
        return;
    }
    pt t = p[idx];
    go(idx + 1, s, p, mn);
    fore(i,1,3) {
        p[idx] = rotate(p[idx]);
        go(idx + 1, s + i, p, mn);
    }
    p[idx] = t;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) {
        vector<pt> p(4);
        fori(j,0,4) 
            cin >> p[j].x >> p[j].y >> p[j].a >> p[j].b;
        int mn = 1e9;
        go(0,0,p,mn);
        if(mn == 1e9) mn = -1;
        cout << mn << endl;
    }
    return 0; 
}