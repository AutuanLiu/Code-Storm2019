
def isTree(nums):
    n = len(nums)
    if n == 0:
        return True
    last_root, i = n / 2, 0
    while i < last_root:
        if (nums[2 * i + 1] >= nums[i] or nums[2 * i + 2] <= nums[i]):
            break
        i+=1
    return i == last_root

if __name__=='__main__':
    s = input()
    nums = [int(x) for x in s.split(',')]
    print('True' if isTree(nums) else 'False')