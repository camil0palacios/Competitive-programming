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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int hy, ay, dy;
    int hm, am, dm;
    int h, a, d;
    cin >> hy >> ay >> dy;
    cin >> hm >> am >> dm;
    cin >> h >> a >> d;
    int ans = 1e9;
    fore(i,0,200) {
        fore(k,0,200) {
            if(ay + k <= dm) continue;
            int x = (hm + (ay + k - dm) - 1)/(ay + k - dm); 
            int j = max(0, x*(am - (dy+i)) - hy + 1);
            ans = min(ans, a*k + h*j + d*i);
        }
    }
    cout << ans << endl;
    return 0;
}