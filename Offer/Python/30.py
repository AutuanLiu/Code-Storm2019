class Solution:
    def FindGreatestSumOfSubArray(self, array):
        if not array:
            return 0

        cur_sum, max_sum = array[0], array[0]

        for i in range(1, len(array)):
            cur_sum = array[i] if cur_sum <= 0 else cur_sum + array[i]
            max_sum = cur_sum if cur_sum > max_sum else max_sum

        return max_sum
