#include "leetcode_repos.h"

class Solution {
public:
	inline int get_couple(int x)
	{
		return (x & 1) ? x - 1 : x + 1;
	}

	inline int findidx(vector<int>& row, int start, int n, int target)
	{
		int idx = start;
		for (; idx < n && row[idx] != target; idx++) {
		}
		return idx;
	}

	int minSwapsCouples(vector<int>& row)
	{
		int ret = 0, n = row.size();

		// �̶�ż��λ�� ̰��
		for (int i = 0; i < n; i += 2) {
			int couple = get_couple(row[i]); // �ҵ�����ż
			// �ҵ���ż������
			if (couple != row[i + 1]) {
				int idx = findidx(row, i + 1, n, couple);
				swap(row[i + 1], row[idx]);
				ret++;
			}
		}
		return ret;
	}
};


int main()
{
	vector<int> row{ 0, 2, 4, 6, 7, 1, 3, 5 };

	int ret = Solution().minSwapsCouples(row);
	cout << ret << endl;
	return 0;
}
