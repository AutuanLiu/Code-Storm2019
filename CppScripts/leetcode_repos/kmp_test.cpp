#include "leetcode_repos.h"

vector<int> kmpProcess(string needle)
{
	int n = needle.size();
	vector<int> lps(n, 0);
	for (int i = 1, len = 0; i < n;) {
		if (needle[i] == needle[len]) {
			lps[i++] = ++len;
		}
		else if (len) {
			len = lps[len - 1];
		}
		else {
			lps[i++] = 0;
		}
	}
	return lps;
}

vector<int> maxMatch(string needle)
{
	int n = needle.length();
	vector<int> ret(n);
	for (int it = 1, max_length = 0; it < n; it++) {
		while (max_length > 0 && needle[max_length] != needle[it]) {
			max_length = ret[max_length - 1];
		}

		if (needle[it] == needle[max_length])
			max_length++;

		ret[it] = max_length;
	}
	return ret;
}

int strStr(string haystack, string needle)
{
	if (needle.empty())
		return 0;
	vector<int> maxLengths = maxMatch(needle);
	int m = haystack.size(), n = needle.size();
	for (int it = 0, cnt = 0; it < m; it++) {
		while (cnt > 0 && haystack[it] != needle[cnt]) {
			cnt = maxLengths[cnt - 1];
		}

		if (haystack[it] == needle[cnt])
			cnt++;

		if (cnt == n)
			return it - n + 1;
	}
	return -1;
}

int strStr1(string haystack, string needle) {
	if (needle.empty())
		return 0;
	int m = haystack.size(), n = needle.size();
	vector<int> lps = kmpProcess(needle);
	for (int i = 0, j = 0; i < m;) {
		if (haystack[i] == needle[j]) {
			i++, j++;
		}
		if (j == n) {
			return i - j;
		}
		if (i < m && haystack[i] != needle[j]) {
			j ? j = lps[j - 1] : i++;
		}
	}
	return -1;
}

// 返回所有满足条件的匹配位置
vector<int> strStr2(string haystack, string needle)
{
	vector<int> maxLengths = maxMatch(needle), positions;
	int m = haystack.size(), n = needle.size();
	for (int it = 0, cnt = 0; it < m; it++) {
		while (cnt > 0 && haystack[it] != needle[cnt]) {
			cnt = maxLengths[cnt - 1];
		}

		if (haystack[it] == needle[cnt])
			cnt++;

		if (cnt == n) {
			positions.push_back(it - n + 1);
			cnt = maxLengths[cnt - 1];
		}
	}
	return positions;
}

int main(int argc, char** argv)
{
	string s = "abababcaabca";
	string x = "abc";
	vector<int> ret1 = kmpProcess(s);
	vector<int> ret2 = maxMatch(s);
	print_vector(ret1);
	print_vector(ret2);
	vector<int> next = maxMatch(x);
	cout << strStr(s, x) << endl;
	cout << strStr1(s, x) << endl;
	vector<int> positions = strStr2(s, x);
	print_vector(positions);
	return 0;
}
