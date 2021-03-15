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

const int Mxn = 305;
int n;
vector<string> a, b;

string pat[3] = {"OXX", "XOX", "XXO"};

bool doit(int d, int k) {
    b = a;
    fori(i,0,n) {
        for(int j = 0; j < n; j += 3) {
            if(b[i][j] != '.') b[i][j] = pat[(i + d) % 3][0];
            if(j+1 < n && b[i][j+1] != '.') b[i][j+1] = pat[(i + d) % 3][1];
            if(j+2 < n && b[i][j+2] != '.') b[i][j+2] = pat[(i + d) % 3][2];
        }
    }
    int cnt = 0;
    fori(i,0,n) fori(j,0,n) cnt += a[i][j] != b[i][j];
    return cnt <= k;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        a.clear();
        fori(i,0,n) {
            string tmp; cin >> tmp;
            a.eb(tmp);
        }
        int k = 0;
        fori(i,0,n) fori(j,0,n) k += a[i][j] == 'X';
        k /= 3;
        fori(i,0,3) {
            if(doit(i, k)) {
                a = b;
                break;
            }
        }
        fori(i,0,n) cout << a[i] << endl;
    }
    return 0; 
}