#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string s; cin >> s;
        if(s.size() == 3){
            int c1 = 0, c2 = 0;
            string one = "one", two = "two";
            for(int i = 0; i < 3; i++)if(s[i] == one[i])c1++;
            for(int i = 0; i < 3; i++)if(s[i] == two[i])c2++;
            cout << (c1 > c2 ? 1:2);
        }
        else cout << 3;
        cout << endl;
    }
    return 0;
}