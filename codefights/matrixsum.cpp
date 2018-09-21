#include<iostream>
#include<vector>

int matrixElementsSum(std::vector<std::vector<int>> matrix) {
    int plus = 0;
    for(int i=0; i < matrix.size() ; i++){
        for(int j=0 ; j < matrix[i].size() ; j++){
            if(matrix[i][j] != 0){
                if(i>=1)
                    if(matrix[i-1][j]!= 0)
                        plus= plus + matrix[i][j];
                else
                    plus = plus + matrix[i][j];
            }
        }
    }
    return plus;
}

int main(){
	//std::vector<std::vector<int>> matrix;
	std::vector<int> v;
	int matrix[3][4] = [[0, 1, 1, 2], 
          [0, 5, 0, 0], 
          [2, 0, 3, 3]];
    std::cout<<matrixElementsSum(matrix)
}
