/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (35.23%)
 * Likes:    1158
 * Dislikes: 0
 * Total Accepted:    61.3K
 * Total Submissions: 173.9K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 *
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 *
 * 你可以假设 nums1 和 nums2 不会同时为空。
 *
 * 示例 1:
 *
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * 则中位数是 2.0
 *
 *
 * 示例 2:
 *
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * 则中位数是 (2 + 3)/2 = 2.5
 *
 *
 */
// vector 默认使用 0 初始化
// c++ 中 long 和 int 是一样的，取值范围 [−2^31, 2^31 − 1]
// 关键在于如何找到中间的位置，主要有三种可能（左边、右边、两边）
// 奇数或者偶数，求平均或者是单个数字
// 永远保证左边的数字小于右边的数字

// 在统计中，中位数被用来： 将一个集合划分为两个长度相等的子集，其中一个子集中的元素总是大于另一个子集中的元素。 
// 因为是索引操作，所以都要相应的－1
// https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu

// 特殊情况
// 1. C1 = 0 数组1整体都在右边了，所以都比中值大，中值在数组2中，简单的说就是数组1割后的左边是空了，所以我们可以假定LMax1 = INT_MIN
// 2. C1 = 2n 数组1整体都在左边了，所以都比中值小，中值在数组2中 ，简单的说就是数组1割后的右边是空了，所以我们可以假定RMin1 = INT_MAX，来保证LMax2 < RMin1恒成立
// 3. C2 = 0—— 数组2整体在右边了，所以都比中值大，中值在数组1中 ，简单的说就是数组2割后的左边是空了，所以我们可以假定LMax2 = INT_MIN
// 4. C2 = 2m—— 数组2整体在左边了，所以都比中值小，中值在数组1中,简单的说就是数组2割后的右边是空了，为了让LMax1 < RMin2恒成立，我们可以假定RMin2 = INT_MAX
                                                                                                                       
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size(), n = nums2.size();
        // 为了效率，要进行二分比较，所以，我们考虑对短的数组进行二分
        // 这里使用 割 的思想和补 # 的思想
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        // num1 的长度为 2m+1，最大索引为 2m, 最小索引为0，对num1进行二分，并比较大小
        // ci 表示对数组 i 的割
        int LMax1, LMax2, RMin1, RMin2, c1, c2, low = 0, high = 2 * m;
        // 二分法的思想
        while (low <= high) {
            // c1 即对数组1的割，其即二分法的中点处，c2 = m + n - c1(索引是从0开始的，这里不加1) 
            c1 = (low + high) / 2;
            c2 = m + n - c1;

            // 判断特殊情况, 这里的割是在右边界
            LMax1 = c1 == 0 ? INT_MIN : nums1[(c1 - 1) / 2];
            RMin1 = c1 == 2 * m ? INT_MAX : nums1[c1 / 2];
            LMax2 = c2 == 0 ? INT_MIN : nums2[(c2 - 1) / 2];
            RMin2 = c2 == 2 * n ? INT_MAX : nums2[c2 / 2];

            // 继续进行分割, 如果找到合理的分割点，那么就停止分割
            if (LMax1 > RMin2)
                high = c1 - 1;
            else if (LMax2 > RMin1)
                low = c1 + 1;
            else
                break;
        }
        return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
    }
};
