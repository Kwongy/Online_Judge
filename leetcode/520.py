class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if len(word) < 2:
            return True
        else:
            cnt = 0
            for i in word:
                if i >= 'a':
                    cnt += 1
            if (word[0] < 'a' and cnt == len(word) - 1) or (cnt == 0) or (cnt == len(word)):
                return True
            else:
                return False