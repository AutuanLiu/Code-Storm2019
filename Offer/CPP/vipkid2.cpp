#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void get_split(int n, int cnt, vector<int>& nums)
{
    if (n == 0) {
        for (int i = 0; i < cnt; i++) {
            if (i == cnt - 1)
                cout << nums[i] << endl;
            else
                cout << nums[i] << "+";
        }
    }

    int k = cnt > 0 ? nums[cnt - 1] : 1;
    for (int i = k; i <= n; i++) {
        nums[cnt] = i;
        get_split(n - i, cnt + 1, nums);
    }
}

int main(void)
{
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        get_split(n, 0, nums);
    }
    return 0;
}
