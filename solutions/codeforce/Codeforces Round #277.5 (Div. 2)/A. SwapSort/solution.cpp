#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

const int MXN = 1e5 + 5;
int a[MXN];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(all(b));
    vector<ii> p;
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            int j = i+1;
            while(j < n && a[j] != b[i]) j++;
            swap(a[i], a[j]);
            p.pb({i, j});
        }
    } 
    cout << sz(p) << endl;
    for(auto & i : p) {
        cout << i.ft << ' ' << i.sd << endl;
    }
    return 0; 
}