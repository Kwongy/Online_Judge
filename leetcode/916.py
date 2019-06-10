class Solution:
    def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
        Bhash = {}
        for str in B:
            bhash = {}
                if not s in bhash:
                    bhash[s] = 1
                else: bhash[s] +=1
            for i in bhash:
                if not i in Bhash:
                    Bhash[i] = bhash[i]
                else : Bhash[i] = max(Bhash[i],bhash[i])

        res = []
        for str in A:
            ahash = {}
            flag = 1
            for s in str:
                if not s in ahash:
                    ahash[s] = 1
                else: ahash[s] +=1
            for i in Bhash:
                if not i in ahash:
                    flag = 0
                    break
                elif ahash[i] < Bhash[i]:
                    flag = 0
                    break
            if flag == 0:
                continue
            else :
                res.append(str)
        return res