#include <bits/stdc++.h>
using namespace std;

int shuff[101][53], card[53];

void shuffling(int n){
    int tmp[53];
    memset(tmp, 0, sizeof tmp);
    for(int i = 1; i < 53; i++){
        tmp[i] = card[shuff[n][i]];
    }
    for(int i = 1; i < 53; i++){
        card[i] = tmp[i];
    }
}

void print(){
    vector<string> value = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    vector<string> suit = {"Clubs", "Diamonds", "Hearts", "Spades"};
    for(int i = 1; i <= 52; i++)
        cout << value[card[i] % 13] << " of " << suit[(card[i] - 1)/13] << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 52; j++){
                cin >> shuff[i][j];
            } 
        }
        for(int i = 1; i < 53; i++){
            card[i] = i;
        }
        cin.ignore();
        string s;
        while(getline(cin, s) && s != ""){
            shuffling(stoi(s));
        }
        print();
        if(t)cout << endl;
    }
    return 0;
}