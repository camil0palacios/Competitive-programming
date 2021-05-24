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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

int cnt_dig(int a) {
    int cnt = 0;
    while(a) {
        cnt++;
        a /= 10;
    }
    return cnt;
} 

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int g = pow(10, c-1);
        int x = g, y = g;
        while(cnt_dig(x) < a) x *= 3;
        while(cnt_dig(y) < b) y *= 7;
        cout << x << ' ' << y << endl;
    }
    return 0; 
}