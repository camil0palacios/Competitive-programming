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
int day[Mxn][Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, d;
    cin >> n >> k >> d;
    ll pk = 1;
    fore(i,1,d) {
        if(pk >= n) break;
        pk *= k;
    } 
    if(pk >= n) {
        fori(i,1,n) {
            fori(j,0,d) day[i][j] = day[i-1][j];
            for(int j = d-1; j >= 0; j--) { 
                day[i][j] = (day[i][j] + 1) % k;
                if(day[i][j]) break;
            }
        }
        fori(i,0,d) {
            fori(j,0,n) {
                cout << day[j][i] + 1 << ' ';
            } 
            cout << endl;
        }
    } else cout << -1 << endl;
    return 0; 
}