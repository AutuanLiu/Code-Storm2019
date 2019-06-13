# 二分法解题
class Solution:
    def minNumberInRotateArray(self, rotateArray):
        if len(rotateArray) == 0:
            return 0
        front = 0
        rear = len(rotateArray) - 1
        mid = 0
        while rotateArray[front] >= rotateArray[rear]:
            if rear - front == 1:
                mid = rear
                break
            mid = (front + rear) // 2
            if rotateArray[mid] >= rotateArray[front]:
                front = mid
            elif rotateArray[mid] <= rotateArray[rear]:
                rear = mid
            elif rotateArray[front] == rotateArray[rear] == rotateArray[mid]:
                minval = rotateArray[0]
                for i in range(1, len(rotateArray)):
                    if rotateArray[i] < minval:
                        minval = rotateArray[i]
                        mid = i
        return rotateArray[mid]


# 顺序搜索只需要找到分界点即可
class Solution:
    def minNumberInRotateArray(self, rotateArray):
        if len(rotateArray) == 0:
            return 0
        flag = False
        for i in range(len(rotateArray) - 1):
            if rotateArray[i] > rotateArray[i + 1]:
                flag = True
                break
        return rotateArray[i + 1] if flag else rotateArray[0]
