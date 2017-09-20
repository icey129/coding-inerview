#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

char* Serialize(TreeNode *root) {
	char* p = NULL;
	if (root == NULL){
		p = (char*)malloc(sizeof(char)* 2);
		strcpy(p, "$");
		return p;
	}
	char* left = NULL, *right = NULL;
	left = Serialize(root->left);
	right = Serialize(root->right);
	char* num = (char*)malloc(33);
	sprintf(num, "%d", root->val);
	int len = strlen(left) + strlen(right) + strlen(num) + 3;
	p = (char*)malloc(sizeof(char)*len);
	memset(p, 0, len);
	char* q = p;
	strcpy(q, num);
	q += strlen(num);
	*q = ',';
	q++;
	strcat(q, left);
	q += strlen(left);
	*q = ',';
	q++;
	strcat(q, right);
	free(left);
	free(right);
	free(num);
	return p;
}

int getNum(char* str){
	int sum = 0;
	while (*str != '\0'){
		sum = sum * 10 + (*str++) - '0';
	}
	return sum;
}

TreeNode* DeserializeNode(char** str){
	if (**str == '\0'){
		return NULL;
	}
	if (**str == '$'){
		(*str)++;
		(*str)++;
		return NULL;
	}
	char* num = (char*)malloc(33), *q = num;
	memset(num, 0, 33);
	while (**str >= '0' && **str <= '9'){
		*q = **str;
		q++;
		(*str)++;
	}
	TreeNode* root = new TreeNode(getNum(num));
	free(num);
	(*str)++;
	root->left = DeserializeNode(str);
	root->right = DeserializeNode(str);
	return root;
}

TreeNode* Deserialize(char *str) {
	if (*str == '$'){
		return NULL;
	}
	TreeNode* root = DeserializeNode(&str);
	return root;
}

bool ReadStream(istream& stream, int* number)
{
	if (stream.eof())
		return false;

	char buffer[32];
	buffer[0] = '\0';

	char ch;
	stream >> ch;
	int i = 0;
	while (!stream.eof() && ch != ',' && ch != '\n') //处理最后一个字符有问题，需要在最后一个字符后加上‘,’
	{
		buffer[i++] = ch;
		stream >> ch;
	}

	bool isNumeric = false;
	if (i > 0 && buffer[0] != '$')
	{
		*number = atoi(buffer);
		isNumeric = true;
	}

	return isNumeric;
}

//使用stream处理字符串
void Serialize1(TreeNode* root, ostream& stream){
	if (root == NULL){
		stream << "$";
		return;
	}
	stream << root->val << ",";
	Serialize1(root->left, stream);
	stream << ",";
	Serialize1(root->right, stream);
	return;
}

TreeNode* Deserialize1(istream& stream){
	TreeNode* root = NULL;
	int number;
	if (ReadStream(stream, &number)){
		root = new TreeNode(number);
		root->left = Deserialize1(stream);
		root->right = Deserialize1(stream);
	}
	return root;
}

int test62(){
	char ch[1000];
	cin >> ch;
	TreeNode* root = Deserialize(ch);
	cout << Serialize(root)<<endl;
	TreeNode* root1 = Deserialize1(cin);
	Serialize1(root1, cout);
	return 0;
}