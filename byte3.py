import sys


def solution(s):
    # 用列表表示栈， 栈顶是列表尾
    ret, stack = '', []
    for item in s:
        if item == '#':
            tmp = num = ''
            while stack and stack[-1] != '%':
                tmp = stack.pop() + tmp
            stack.pop()
            while stack and stack[-1].isdigit():
                num = stack.pop() + num
            stack.append(int(num) * tmp)
        else:
            stack.append(item)
    return stack


if __name__ == '__main__':
    s = sys.stdin.readline().strip()
    ret = ''.join(solution(s))
    print(ret)