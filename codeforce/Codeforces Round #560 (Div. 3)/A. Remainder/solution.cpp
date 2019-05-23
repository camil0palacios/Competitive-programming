#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y;
    string s;
    cin >> n >> x >> y >> s;
    int sum = 0;
    for(int i = n-x; i < n; i++){
        sum += (i == n-y-1)^(s[i] != '0');
    }
    cout << sum << endl;
    return 0;
}