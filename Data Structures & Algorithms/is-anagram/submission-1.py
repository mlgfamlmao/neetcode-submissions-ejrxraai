class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        countt, counts= {},{}

        for i in range(len(s)):
            counts[s[i]]= counts.get(s[i],0)+1
            countt[t[i]]= countt.get(t[i],0)+1

        for i in counts:
            if counts[i] != countt.get(i,0):
                return False
        return True