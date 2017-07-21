#include <iostream>
#include <vector>

using namespace std;

int findMinNumber(vector<int> v){
	if (v.empty()){
		return 0;
	}

	for (int i = 0; i < v.size() - 1; i++){
		if (v[i] > v[i + 1]){
			return v[i + 1];
		}
	}
	return v[0];
}

//考虑1,2,3,4,5的有序情况，以及101111与111101的情况
int findMinNumber1(vector<int> v){
	if (v.empty()){
		return 0;
	}
	int i = 0, j = v.size() - 1, mid = 0;
	if (v[i] < v[j]){
		return v[i];
	}
	while (j > i + 1){
		mid = (i + j) / 2;
		if (v[mid] == v[j] && v[mid] == v[i]){
			for (int k = i; k < j; k++){
				if (v[k]>v[k + 1]){
					return v[k + 1];
				}
			}
		}
		else if(v[mid] <= v[j]){
			j = mid;
		}
		else{
			i = mid;
		}
	}
	return v[j];
}

int minNumRotateArr(){
	vector<int> v = { 1, 0, 1, 1, 1 };
	int res = findMinNumber1(v);
	cout << res << endl;
	return 0;
}