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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    while(n--) {
        int n1, d1, n2, d2;
        char op, c;
        cin >> n1 >> c >> d1 >> op >> n2 >> c >> d2;
        int a = 0, b = 0;
        if(op == '+') {
            a = n1*d2 + n2*d1;
            b = d1*d2;
        }
        if(op == '-') {
            a = n1*d2 - n2*d1;
            b = d1*d2;
        }
        if(op == '*') {
            a = n1*n2;
            b = d1*d2;
        }
        if(op == '/') {
            a = n1*d2;
            b = n2*d1;
        }
        cout << a << '/' << b << " = ";
        int g = __gcd(abs(a), abs(b));
        a /= g, b /= g;
        cout << a << '/' << b << endl;
    }
    return 0; 
}