#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//����һ��ʹ�ù�ϣ��洢�ַ����ֵ�˳�������ظ����־�����Ϊ��ֵ
// Ȼ�����һ��hash���ҵ���Сhashֵ�Ķ�Ӧ�����������ַ�

class CharStatistic{
public:
	CharStatistic() :index(0){ memset(hash, -1, sizeof(hash)); }
	void Insert(char ch){
		int tmp = hash[(unsigned char)ch];
		if (tmp == -1){ //δ���ֹ�
			hash[(unsigned char)ch] = index;
		}
		else if (tmp >= 0){ //�ѳ��ֹ�
			hash[(unsigned char)ch] = -2;
		}
		index++;
		return;
	}

	char FirstAppearingOnce(){
		int tmp = 256;
		char res = '#';
		for (int i = 0; i < 256; i++){
			if (hash[i] >= 0 && hash[i] < tmp){
				tmp = hash[i];
				res = i;
			}
		}
		return res;
	}
private:
	int hash[256];
	int index;
};

/*
˼·��ʱ�临�Ӷ�O��1�����ռ临�Ӷ�O��n��
1����һ��128��С������ͳ��ÿ���ַ����ֵĴ���
2����һ�����У������һ������ch�ַ����������У�����������ڲ���
3������һ�����ֵ��ַ����ж϶���Ԫ���Ƿ�ֻ����һ�Σ������ֱ�ӷ��أ�����ɾ��������3����
* ����뷽��һ��ռ�ø���Ŀռ�
*/

class CharStatistic2{
public:
	void Insert(char ch){
		cnt[ch]++;
		if (cnt[ch] == 1){
			q.push(ch);
		}
	}

	char FirstAppearingOnce(){
		while (!q.empty() && cnt[q.front()] > 1){
			q.pop();
		}
		if (q.empty()){
			return '#';
		}
		else{
			return q.front();
		}
	}

	CharStatistic2(){
		memset(cnt, 0, sizeof(cnt));
	}
private:
	queue<char> q;
	int cnt[256];
};

int test55(){
	char ch;
	CharStatistic2 cs;
	while (1){
		cin >> ch;
		if (ch == '-')
			break;
		cs.Insert(ch);
		cout << cs.FirstAppearingOnce() << endl;
	}
	return 0;
}