#include <iostream>
#include <string>

using namespace std;

/* 思路分析
分析：递归实现
每次分别在str 和pattern中取一个字符进行匹配，如果匹配，则匹配下一个字符，否则，返回不匹配。 
设匹配递归函数 match(str, pattern)。
如果模式匹配字符的下一个字符是‘*’: 
	•如果pttern当前字符和str的当前字符匹配，有以下三种可能情况 
	1）pttern当前字符能匹配 str 中的 0 个字符：match(str, pattern+2)
	2）pttern当前字符能匹配 str 中的 1 个字符：match(str+1, pattern+2) （可省略）
	3）pttern当前字符能匹配 str 中的 多 个字符：match(str+1, pattern)
	•如果pttern当前字符和和str的当前字符不匹配 
	pttern当前字符能匹配 str 中的 0 个字符：(str, pattern+2)
如果模式匹配字符的下一个字符不是‘*’，进行逐字符匹配。
	相等或*pattern = '.'继续match(str+1,pattern+1); //注意这里要进行str+1,需保证*str!='\0'
	不相等返回false;
对于 ‘.’ 的情况比较简单，’.’ 和一个字符匹配 match(str+1, pattern+1) 
另外需要注意的是：空字符串”” 和 “.*” 是匹配的
*
动态规划
如果 pattern[j] == str[i] || pattern[j] == '.', 此时dp[i][j] = dp[i-1][j-1];
如果 pattern[j] == '*'
    分两种情况:
    1: 如果pattern[j-1] != str[i-1] && pattern[j-1] != '.',
		此时dp[i][j] = dp[i][j-2]   a*匹配0次
    2: 如果pattern[j-1] == str[i-1] || pattern[j-1] == '.' 
        此时dp[i][j] = dp[i][j-2]   a*匹配0次  //匹配str中的i个字符，不匹配a*
        或者 dp[i][j] = dp[i][j-1]  a*匹配1次  //匹配str中的i个字符，匹配一个a （省略）
        或者 dp[i][j] = dp[i-1][j]  a*匹配多次 //匹配str中的i-1个字符，匹配多个a（1个）
*/

bool match_core(char* str, char* pattern);

bool match1(char* str, char* pattern){
	if (str == NULL || pattern == NULL || *pattern == '*'){
		return false;
	}
	return match_core(str, pattern);
}

bool match_core(char* str, char* pattern){
	if (str == NULL || pattern == NULL){
		return false;
	}
	if (*str == '\0' && *pattern == '\0'){
		return true;
	}
	else if (*pattern == '\0'){
		return false;
	}


	if (*(pattern + 1) != '*'){
		if (*str == *pattern || (*pattern == '.'&& *str != NULL)){ //""与"."
			return match_core(str + 1, pattern + 1);
		}
		else{
			return false;
		}
	}
	else{
		if (*pattern == *str || (*pattern == '.'&& *str != NULL)){
			return match_core(str, pattern + 2)	 //跳过*与其之前的字符
				|| match_core(str + 1, pattern); //*之前的字符出现过一次
		}
		else{
			return match_core(str, pattern + 2); // 跳过b*,b取0次
		}
	}
	return false;
}

//动规,dp[i][j]表示前j-1个模式字符匹配前i-1个字符的结果
bool match2(char* str, char* pattern){
	if (str == NULL || pattern == NULL || *pattern == '*'){
		return false;
	}

	int len1 = strlen(str), len2 = strlen(pattern);
	bool **dp = new bool*[len1+1];
	for (int i = 0; i <= len1; i++){
		dp[i] = new bool[len2+1];
		memset(dp[i], false, sizeof(bool)*(len2 + 1));
	}

	dp[0][0] = true; //初始状态，什么也不匹配
	for (int i = 1; i < len2 + 1; i++){
		if (pattern[i - 1] == '*'){ //不匹配a*
			dp[0][i] = dp[0][i - 2];
		}
	}

	for (int i = 1; i <= len1; i++){
		for (int j = 1; j <= len2; j++){
			if (pattern[j - 1] == '*'){
				if (pattern[j - 2] == str[i - 1] || pattern[j - 2] == '.'){
					dp[i][j] = dp[i][j - 2] | dp[i - 1][j]; //分别对应不用pattern[j-2]匹配str[i-1]以及使用pattern[j-2]匹配str[i-1]
				}
				else{
					dp[i][j] = dp[i][j - 2]; //pattern[j - 2]与str[i - 1]不相同，不用pattern[j - 2]匹配str[i - 1]
				}
			}
			else{
				if (pattern[j - 1] == str[i - 1] || pattern[j - 1] == '.') //pattern[j-1]能够匹配str[i-1],匹配结果为pattern[j-2]与str[i-2]的匹配结果
					dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}
	return dp[len1][len2];
}

int test53(){
	char str[50];
	char pat[50];
	cin >> str;
	cin >> pat;
	cout << match2(str, pat) << endl;
	return 0;
}