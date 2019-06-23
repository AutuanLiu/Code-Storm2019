def func(pattern, string):
    if not string or not pattern:
        return False
    string = string.split(' ')
    if len(string) != len(pattern):
        return False
    hash = {}
    for idx in range(len(string)):
        if string[idx] not in hash.keys():
            hash[string[idx]] = pattern[idx]
        else:
            if hash[string[idx]] == pattern[idx]:
                continue
            else:
                return False
        return True
    
print(func('abba', '北京 杭州 杭州 北京'))
print(func('aabb', '北京 北京 杭州 杭州'))
print(func('aabb', '北京 北京 杭州'))
print(func('abc', '北京 北京 南京'))