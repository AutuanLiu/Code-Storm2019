// 在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
// 也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，
// 那么对应的输出是第一个重复的数字2。
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication)
    {
        // 为空
        if (numbers == nullptr || length <= 0)
            return false;

        // 不满足数值范围条件
        for (int i = 0; i < length; i++) {
            if (numbers[i] < 0 || numbers[i] > length - 1)
                return false;
        }

        // 不断交换数字到属于他的位置上
        for (int i = 0; i < length; i++) {
            // 每次确定一个位置 直到 numbers[i] == i 或者算法返回
            while (numbers[i] != i) {
                if (numbers[i] == numbers[numbers[i]]) {
                    *duplication = numbers[i]; // 重复的数值
                    return true;
                }
                // 否则就将数值放到他应该在的位置
                swap(numbers[i], numbers[numbers[i]]);
            }
        }
        return false;
    }
};