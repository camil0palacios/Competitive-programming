#include <bits/stdc++.h>
using namespace std;

int weigth(char s){
    if(tolower(s) == 'q') return 9;
    else if(tolower(s) == 'r') return 5;
    else if(tolower(s) == 'b') return 3;
    else if(tolower(s) == 'n') return 3;
    else if(tolower(s) == 'p') return 1;
    else return 0;
}

int main(){
    vector<string> chess;
    int asum = 0, bsum = 0,i=0;
    while(i < 8){
        string line;
        cin>>line;
        if(line.size()== 8){
            chess.push_back(line);
            i++;
        }
    }
    for(int i= 0; i < chess.size(); i++){
        for(int j= 0; j < chess[i].size(); j++){
            if(chess[i][j] >= 'A' && chess[i][j] <= 'Z')
                asum += weigth(chess[i][j]);
            else bsum += weigth(chess[i][j]);
        }
    }
    if(asum == bsum) printf("%s","Draw");
    else if(asum < bsum) printf("%s","Black");
    else printf("%s","White");
}
