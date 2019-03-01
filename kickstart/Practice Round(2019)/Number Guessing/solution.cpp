#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, a, b;
    string s;
    cin >> t;
    while(t--){
        cin >> a >> b >> n;
        a = a + 1;
        while(n--){
            int mid = (a+b)/2;
            cout << mid << endl;
            cin >> s;
            if(s == "CORRECT")break;
            if(s == "TOO_SMALL"){
                a = mid + 1;
            }
            else{
                b = mid - 1;
            }
        }
    }
    return 0;
}