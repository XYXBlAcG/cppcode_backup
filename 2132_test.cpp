#include<iostream>
#include<string>
#include<algorithm>
#define maxsize 25
using namespace std;

int n;
string words[maxsize];
string FirChar;
int visit[maxsize];
int ans;

int match(string str, string word) {
	//这个函数用来判断当前的字符串和word是否能够接上,为了使得长度更大，选更小的值
	int res = 0;
	int strlen=str.size();
	int wordlen = word.size();
	int i, j;
	for (i = 1; i <= strlen&&i < wordlen; i++) {//注意，这里为了配合首字母的第一次情况，strlen使用了<=，而wordlen为了不越界使用了<符号
		for (j = 0; j < i; j++) {
			if (str[strlen - i + j] != word[j])break;
		}
		if (i == j) {
			res = i;
			break;
		}
	}
	return res;
}

string concat(string curstr, string word) {
	//将两个字符串合并，得到新的字符串，字符串尽量长一些
	int matchlen = match(curstr, word);
	for (int i = matchlen; i < word.size(); i++) {
		curstr += word[i];
	}
	return curstr;
}

void dfs(string curstr) {
	int curlen = curstr.size();
	ans = max(ans, curlen);

	for (int i = 0; i < n; i++) {
		if (visit[i] <2 && match(curstr, words[i])>0) {
			//如果该元素没有被访问过，而且和当前的单词可以匹配上，则匹配并深搜
			string tmp = concat(curstr, words[i]);
			if (curstr == tmp)continue;//由于第一个字符使用了<=,因此这里为了防止完全重复，使用了continue，防止了'a'=='a'
			visit[i]++;
			dfs(tmp);
			visit[i]--;
		}
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> words[i];
	}
	cin >> FirChar;
	dfs(FirChar);
	cout << ans;
	return 0;
}