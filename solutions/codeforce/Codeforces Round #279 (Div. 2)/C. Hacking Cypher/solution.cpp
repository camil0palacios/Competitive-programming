#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

const int MXN = 1e6 + 5;
int pf[MXN], sf[MXN];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s; int a, b;
    cin >> s >> a >> b;
    int n = (int) s.size();
    int r = 0;
    for(int i = 0; i < n; i++) {
        r = r*10 + (s[i] - '0');
        r %= a;
        if(r == 0) pf[i] = 1;
    }
    int pow_10 = 1;
    r = 0;
    for(int i = n-1; i >= 0; i--) {
        r = (s[i] - '0') * pow_10 + r;
        r %= b;
        if(r == 0) sf[i] = 1;
        pow_10 = (pow_10 * 10) % b;
    }
    bool ok = 0;
    string left, right;
    for(int i = 0; i < n - 1; i++) {
        if(pf[i] && sf[i + 1]) {
            ok = 1;
            for(int j = 0; j <= i; j++) left += s[j];
            for(int j = i + 1; j < n; j++) right += s[j];
            break;
        }
    }
    int i;
    for(i = 0; right[i] == '0' && i < right.size(); i++) left += right[i];
    if(!ok || i == right.size()) {
        cout << "NO" << endl;
        return 0;
    }
    right = right.substr(i); 
    cout << "YES" << endl;
    cout << left << endl << right << endl;
    return 0; 
}