#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
 
using namespace std;
 
typedef long long int lld;
 
int main(){
	while (1){
		int N, sum = 0, ct = 0;
		scanf("%d", &N);
		if (N == 0)
			break;
		string str;
		cin >> str;
		int row = str.length() / N, col = N;
		vector<vector<char>> matrix(row, vector<char>(col));
		bool fwd = true;
		for (int i = 0; i < row; i++){
			if (fwd){
				for (int j = 0; j < col; j++)
					matrix[i][j] = str[ct++];
				fwd = false;
			}
			else{
				for (int j = 0; j < col; j++)
					matrix[i][col - j - 1] = str[ct++];
				fwd = true;
			}
		}
		for (int i = 0; i < col; i++){
			for (int j = 0; j < row; j++)
				printf("%c", matrix[j][i]);
		}
		printf("\n");
	}
} 