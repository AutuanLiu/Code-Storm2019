def find(students, target):
    if len(students) <= 0 or target < 0:
        return None

    hash, res = {}, []
    hash[students[0]] = 0
    for s_id in range(1, len(students)):
        if students[s_id] <= target:
            continue
        else:
            stu1 = students[s_id] - target
            stu2 = students[s_id] + target
            hash[students[s_id]] = s_id
            if stu1 in hash.keys():
                if hash[stu1] < s_id:
                    res.append((hash[stu1], s_id))
            if stu2 in hash.keys():
                if hash[stu2] < s_id:
                    res.append((hash[stu2], s_id))
    return res


if __name__ == '__main__':
    students = [15, 18, 21, 12, 21, 19]
    target = 3
    res = find(students, target)  # [(0, 1), (0, 3), (1, 2), (1, 4)]
    print(res)

    students = [1, 15, 18, 21, 12]  # 数值小于 target
    target = 3
    res = find(students, target)    # [(2, 3), (1, 2), (1, 4)]
    print(res)

    students = [1, 15, 21, 18, 12]  # 逆序
    target = 3
    res = find(students, target)    # [(1, 3), (2, 3), (1, 4)]
    print(res)

    students = [1]  # 逆序
    target = 3
    res = find(students, target)    # []
    print(res)
