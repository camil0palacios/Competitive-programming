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

const int Mxn = 1010;
char r[Mxn], b[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fori(i,0,n) cin >> r[i];
        fori(i,0,n) cin >> b[i];
        int cnt1 = 0, cnt2 = 0;
        fori(i,0,n) {
            int x = r[i] - '0';
            int y = b[i] - '0';
            if(x > y) cnt1++;
            if(x < y) cnt2++;
        }
        if(cnt1 > cnt2) cout << "RED" << endl;
        else if(cnt1 < cnt2) cout << "BLUE" << endl;
        else cout << "EQUAL" << endl;
    }
    return 0; 
}