class Solution:
    # 单调递减栈  不会~~
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        stack = list()
        t_length = len(T)
        res_list = [0 for _ in range(t_length)]
        for key, value in enumerate(T):
            if stack:
                while stack and T[stack[-1]] < value:
                    res_list[stack[-1]] = key - stack[-1]
                    stack.pop()
            stack.append(key)
        return res_list