#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    int r = 0, g = 0, b = 0;
    for(int i = 0; i < n; i++){
        r += s[i] == 'R';
        g += s[i] == 'G';
        b += s[i] == 'B';
    }
    if((r && g && b) || (r >= 2 && g >= 2) || (g >= 2 && b >= 2) || (r >= 2 && b >= 2)){
        cout << "BGR" << endl;
    }
    else if((r && g >= 2) || (b && g >= 2)){
        cout << "BR" << endl;
    }
    else if((r >= 2 && g) || (r >= 2 && b)){
        cout << "BG" << endl;
    }
    else if((b >= 2 && g) || (b >= 2 && r)){
        cout << "GR" << endl;
    }
    else if(r && g){
        cout << "B" << endl;
    }
    else if(g && b){
        cout << "R" << endl;
    }
    else if(r && b){
        cout << "G" << endl;
    }
    else if(r)cout << "R" << endl;
    else if(g)cout << "G" << endl;
    else cout << "B" << endl;
    return 0;
}