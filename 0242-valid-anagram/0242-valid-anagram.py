class Solution(object):
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
        
        mp = {}

        for ch in s:
            mp[ch] = mp.get(ch , 0) + 1
        
        for ch in t:
            mp[ch] = mp.get(ch , 0) - 1

        for ch in mp:
            if mp[ch] != 0:
                return False
        
        return True

        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        