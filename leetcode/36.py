class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [{} for _ in range(9)]
        columns = [{} for _ in range(9)]
        boxes = [{} for _ in range(9)]
        for i in range(9):
            for j in range(9):
                num = board[i][j]
                box_index = i//3+(j//3)*3
                if num == ".":
                    continue
                else:
                    if num in rows[i] or num in columns[j] or num in boxes[box_index]:
                        return False
                    else:
                        rows[i][num] = 1
                        columns[j][num] = 1
                        boxes[box_index][num] = 1       
        return True