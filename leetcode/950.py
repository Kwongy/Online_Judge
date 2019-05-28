class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deck.sort(reverse=True)
        lens = len(deck)
        result = [deck[0]]
        for i in range(1, lens):
            result.insert(0, result[-1])
            result.pop()
            result.insert(0, deck[i])
        return result

