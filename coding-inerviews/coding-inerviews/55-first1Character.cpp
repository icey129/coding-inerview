#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//方法一：使用哈希表存储字符出现的顺序，若是重复出现就设置为负值
// 然后遍历一遍hash表，找到最小hash值的对应的索引，即字符

class CharStatistic{
public:
	CharStatistic() :index(0){ memset(hash, -1, sizeof(hash)); }
	void Insert(char ch){
		int tmp = hash[(unsigned char)ch];
		if (tmp == -1){ //未出现过
			hash[(unsigned char)ch] = index;
		}
		else if (tmp >= 0){ //已出现过
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
思路：时间复杂度O（1），空间复杂度O（n）
1、用一个128大小的数组统计每个字符出现的次数
2、用一个队列，如果第一次遇到ch字符，则插入队列；其他情况不在插入
3、求解第一个出现的字符，判断队首元素是否只出现一次，如果是直接返回，否则删除继续第3步骤
* 相比与方法一会占用更多的空间
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