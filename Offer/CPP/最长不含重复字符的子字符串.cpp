// 最长不含重复字符的子字符串.cpp
// leetcode3
// 滑动窗口(双指针)
// 子字符串是连续的
int lengthOfLongestSubstring(string s)
{
    int ret = 0, n = s.length(), start = 0, end = 0;
    unordered_set<char> sub_set;
    while (start < n && end < n && start <= end) {
        // 如果滑动窗中不存在当前元素则加入 否则删除开头的元素
        if (sub_set.find(s[end]) == sub_set.end()) {
            sub_set.insert(s[end]);
            end += 1;
            ret = max(ret, end - start);
        } else {
            sub_set.erase(s[start]);
            start += 1;
        }
    }
    return ret;
}