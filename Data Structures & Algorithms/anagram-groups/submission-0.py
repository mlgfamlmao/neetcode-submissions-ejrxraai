class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hasher = defaultdict(list)

        for i in strs:
            count= [0]*26

            for j in i:
                count[ord(j)- ord('a')]+=1
            hasher[tuple(count)].append(i)        
        return hasher.values()

        