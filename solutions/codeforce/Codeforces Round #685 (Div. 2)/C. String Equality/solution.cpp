#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

void solve() {
    int n, k;
    string a, b;
    cin >> n >> k >> a >> b;
    vector<int> f1(26), f2(26);
    for(int i = 0; i < n; i++) {
        f1[a[i]-'a']++;
        f2[b[i]-'a']++;
    } 
    for(int i = 0; i < 25; i++) {
        if(f1[i] < f2[i]) {
            cout << "No" << endl;
            return;
        }
        f1[i] -= f2[i];
        if(f1[i] % k != 0) {
            cout << "No" << endl;
            return;
        }
        f1[i + 1] += f1[i];
    }
    cout << (f1[25] != f2[25] ? "No" : "Yes") << endl;

}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0; 
}