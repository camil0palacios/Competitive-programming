#include <bits/stdc++.h>
using namespace std;

int face(char c){
    int put = 0;
    if(c == 'A')put = 4;
    else if(c == 'K')put = 3;  
    else if(c == 'Q')put = 2;
    else if(c == 'J')put = 1;
    return put;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin >> s && s != "#"){
        deque<string> heap;
        queue<string> players[2];
        heap.push_back(s);
        bool turn = 0;
        for(int i = 0; i < 51; i++){
            cin >> s;
            heap.push_back(s);
        }

        while(!heap.empty()){
            players[0].push(heap.back());
            heap.pop_back();
            players[1].push(heap.back());
            heap.pop_back();
        }

        turn = 1;
        int put = 0;
        while(true){
            if(players[turn].empty())
                break;
            heap.push_back(players[turn].front());
            players[turn].pop();
            string card = heap.back();
            int aux = face(card[1]);
            if(aux){
                put = aux + 1; 
                turn ^= 1;
            }
            if(put > 0){
                put--;
                if(put == 0){
                    turn ^= 1;
                    while(!heap.empty()){
                        players[turn].push(heap.front());
                        heap.pop_front();
                    }
                }
            }
            else turn ^= 1;
        }

        turn ^= 1;
        if(turn)
            cout << "2 " << (players[1].size() < 10 ? " " : "") << players[1].size() << endl;
        else 
            cout << "1 " << (players[0].size() < 10 ? " " : "") << players[0].size() << endl;
    }
    
    return 0;
}