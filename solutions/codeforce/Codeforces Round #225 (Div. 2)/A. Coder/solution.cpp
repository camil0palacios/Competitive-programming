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

const int Mxn = 1010;
char a[Mxn][Mxn];
bool ok[Mxn][Mxn];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int ans = 0;
    fori(i,0,n) {
        fori(j,0,n) {
            if(!ok[i][j]) {
                ans++;
                a[i][j] = 'C';
                fori(k,0,4) {
                    int mx = i + dx[k];
                    int my = j + dy[k];
                    if(mx >= 0 && mx < n && my >= 0 && my < n) ok[mx][my] = 1;
                }
            } else a[i][j] = '.'; 
        }
    }
    cout << ans << endl;
    fori(i,0,n) {
        fori(j,0,n) cout << a[i][j];
        cout << endl;
    }
    return 0; 
}