#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    string s;
    cin >> t;
    for(int j = 1; j <= t; j++){
        cin >> s;
        int bet = 0;
        for(int i = 1; i < (int)s.size(); i++){
            bet += (s[i] == 'B');
        }
        int L = (int)s.size()-1;
        int low = (L/2) + (L%2);
        int high = (L-1);
        cout << "Case #" << j << ": ";
        if(low <= bet && bet <= high){
            cout << "Y" << endl;
        }else{
            cout << "N" << endl;
        }
    }
    return 0;
}