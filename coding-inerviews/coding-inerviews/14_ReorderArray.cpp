#include <iostream>
#include <vector>

using namespace std;

void mergeArray(vector<int>&arr, int left, int mid, int right);
void mergeSortArray(vector<int> & arr, int left, int right);

/* 
* ǰ���ż ��֤���λ�ò���
* ����һ��ð�����򣬲�������
* ��������ʹ�ö�����ڴ棬�洢�������
* ���������鲢����
* ��
* ���ǳ������չ�� ������ָ����Ϊ��������
*/
void reOrderArray1(vector<int> &array) {
	int len = array.size();
	int flag = 0;
	for (int i = 0; i < len; i++){
		flag = 0;
		for (int j = 0; j < len - i - 1; j++){
			if (!(array[j] & 0x01) && (array[j + 1] & 0x01)){
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				flag = 1;
			}
		}
		if (!flag){
			break;
		}
	}
	return;
}

void reOrderArray2(vector<int> &array){
	vector<int> res;
	int len = array.size(), i = 0;
	for ( i = 0; i < len; i++){
		if (array[i] & 0x01){
			res.push_back(array[i]);
		}
	}
	for (i = 0; i < len; i++){
		if (!(array[i] & 0x01)){
			res.push_back(array[i]);
		}
	}
	array = res;
	return;
}

void reOrderArray3(vector<int> &array){
	if (array.empty()){
		return;
	}
	mergeSortArray(array, 0, array.size() - 1);
}

void mergeEvenArray(vector<int>&arr, int left, int mid, int right){
	int i = left, j = mid + 1;
	vector<int> res;
	while (i <= mid && j <= right){
		if (arr[i] & 0x01){
			res.push_back(arr[i++]);
		}
		else if(arr[j] & 0x01){
			res.push_back(arr[j++]);
		}
		else{
			res.push_back(arr[i++]);
		}
	}
	while (i <= mid){
		res.push_back(arr[i++]);
	}
	while (j <= right){
		res.push_back(arr[j++]);
	}
	int k = 0;
	for (i = left; i <= right; i++){
		arr[i] = res[k++];
	}
	return;
}

void mergeSortArray(vector<int> & arr, int left, int right){
	if (left >= right){
		return;
	}
	int mid = (left + right) / 2;
	mergeSortArray(arr, left, mid);
	mergeSortArray(arr, mid + 1, right);
	mergeEvenArray(arr, left, mid, right);
}

int reorderArr_test(){
	vector<int> arr = { 1, 2, 3, 4, 5, 6, 7 };
	reOrderArray3(arr);
	for (int i = 0; i < arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}