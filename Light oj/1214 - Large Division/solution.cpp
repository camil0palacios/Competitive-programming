#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void sol() {
    string a; long long b;
    cin >> a >> b;
    long long num = 0; 
    int i = 0;
    if(a[0] == '-')i = 1;
    for(; i < a.size(); i++) {
        num = (num * 10 + (a[i] - '0')) % b; 
    }
    cout << (num ? "not divisible" : "divisible") << endl;    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ": ";
        sol();
    }
    return 0;
}