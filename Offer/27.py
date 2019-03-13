class Solution:
    def Permutation(self, ss):
        if not ss:
            return []
        if len(ss) == 1:
            return list(ss)

        charList = list(ss).sort()
        pStr = []
        for i in range(0, len(charList)):
            if i > 0 and charList[i] == charList[i - 1]:
                continue
            temp = self.Permutation(''.join(charList[:i]) + ''.join(charList[i + 1:]))
            for j in temp:
                pStr.append(charList[i] + j)

        return pStr
