#include <iostream>
#include <vector>

using namespace std;

void printOneLoop(vector<vector<int>> matrix, vector<int>& res, int start, int row, int col);

// 输入的矩阵不一定是n*n
vector<int> printMatrix(vector<vector<int>> matrix){
	int height = matrix.size(), width = matrix[0].size();
	int top = 0, bottom = height - 1;
	int left = 0, right = width - 1;
	int i = 0;
	vector<int> res;
	while (top <= bottom && left <= right){
		for (i = left; i <= right; i++){
			res.push_back(matrix[top][i]);
		}
		top += 1;
		if (top > bottom){
			break;
		}

		for (i = top; i <= bottom; i++){
			res.push_back(matrix[i][right]);
		}
		right -= 1;
		if (right < left){
			break;
		}

		for (i = right; i >= left; i--){
			res.push_back(matrix[bottom][i]);
		}
		bottom -= 1;
		if (bottom < top){
			break;
		}

		for (i = bottom; i >= top; i--){
			res.push_back(matrix[i][left]);
		}
		left += 1;

	}
	return res;
}

// 书上的方法，按圈数判断循环终止，循环条件是x>2*start&&y>2*start,(start,start)为打印一圈的顶点
vector<int> printMatrix1(vector<vector<int>> matrix){
	vector<int> res;
	int height = matrix.size(), width = matrix[0].size();
	int start = 0;
	while (height > start * 2 && width > start * 2){
		printOneLoop(matrix, res, start, height - 1, width - 1);
		start += 1;
	}
	return res;
}

void printOneLoop(vector<vector<int>> matrix, vector<int>& res, int start, int row, int col){
	int i = 0;
	int endX = col - start; //列
	int endY = row - start;
	for (i = start; i <= endX; i++){
		res.push_back(matrix[start][i]);
	}
	if (start < endY){
		for (i = start + 1; i <= endY; i++){
			res.push_back(matrix[i][endX]);
		}
	}
	if (start < endX && start < endY){
		for (i = endX - 1; i >= start; i--){
			res.push_back(matrix[endY][i]);
		}
	}
	if (start < endX && start < endY - 1){
		for (i = endY - 1; i > start; i--){
			res.push_back(matrix[i][start]);
		}
	}
	return;
}

int print_matrix_test(){
	vector<vector<int>> a;
	vector<int> res;
	int n, count = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		vector<int> row;
		for (int j = 0; j < n; j++){
			row.push_back(++count);
		}
		a.push_back(row);
	}
	res = printMatrix1(a);
	for (int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
	return 0;
}