#include "leetcode_repos.h"

using namespace std;

class Solution
{
  public:
	static bool cmp(vector<int>& a, vector<int>& b) {
		if (a[0] == b[0])
			return a[1] < b[1];
		else
			return a[0] < b[0];
	}
	
	vector<vector<int> > merge(vector< vector<int> >& nums) {
		sort(nums.begin(), nums.end(), cmp);
		vector< vector<int> > ret;
		for (auto& item : nums) {
			if (ret.empty() || ret.back()[1] < item[0])
				ret.push_back(item);
			else
				ret.back()[1] = max(ret.back()[1], item[1]); 
		}
		return ret;
	} 
	
	void print_vector(vector<vector<int> >& nums) {
		for (auto& it : nums)
			cout << '[' << it[0] << ',' << it[1] << ']' << endl;
	}
};

int main(int argc, char** argv)
{
	Solution slu;
	vector<vector<int>> nums = {{1, 3}, {1, 5}, {2, 7}, {8, 12}}, ret;
	ret = slu.merge(nums);
	slu.print_vector(ret);
	return 0;
}
