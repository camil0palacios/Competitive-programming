#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    int t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        double x = a*log10(2) + 1;
        double y = b*log10(5) + 1;
        cout << floor(x + y) - 1 << endl;
    }
    return 0;
}