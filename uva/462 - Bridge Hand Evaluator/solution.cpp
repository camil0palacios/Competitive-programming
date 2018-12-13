#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    map<char,int> conv;
    int ace[4], king[4], queen[4], jack[4], trump[4], cont[4];
    conv['S'] = 0;
    conv['H'] = 1;
    conv['D'] = 2;
    conv['C'] = 3;
    string s;
    while(cin >> s){

        for(int i = 0; i < 4; i++){
            ace[i] = king[i] = queen[i] = jack[i] = trump[i] = cont[i] = 0;
        }
        int total = 0;
        for(int i = 0; i < 13; i++){
            
            if(i != 0)cin >> s;
            int cur = conv[s[1]];
            cont[cur]++;
            switch(s[0]){
                case 'A':
                    ace[cur] = 1;
                    total += 4;
                    break;
                case 'K':
                    king[cur] = 1;
                    total += 3;
                    break;
                case 'Q':
                    queen[cur] = 1;
                    total += 2;
                    break;
                case 'J':
                    jack[cur] = 1;
                    total += 1;
                    break;
            }
        }
        int plus = 0;
        for(int i = 0; i < 4; i++){
            if(ace[i])trump[i] = true;
            if(king[i] && cont[i] < 2)total--;
            else if(king[i])trump[i] = true;   
            if(queen[i] && cont[i] < 3)total--;
            else if(queen[i])trump[i] = true;
            if(jack[i] && cont[i] < 4)total--;
            if(cont[i] == 2)plus++;
            else if(cont[i] < 2)plus += 2;  
        }
        if(trump[0] && trump[1] && trump[2] && trump[3] && total >= 16)
            cout << "BID NO-TRUMP" << endl;
        else if(total + plus >= 14){
            char ans = 'S';
            char suit[4] = {'S', 'H', 'D', 'C'};
            int cur = cont[0];
            for(int i = 1; i < 4; i++){
                if(cont[i] > cur){
                    ans = suit[i];
                    cur = cont[i];
                }
            }
            cout << "BID " << ans << endl;
        }
        else cout << "PASS" << endl;
    }
    return 0;
}