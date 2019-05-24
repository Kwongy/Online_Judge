# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        c = self.getnum(l1) + self.getnum(l2)
        ls = []
        if c == 0:
            ls.append(ListNode(0))
        else:
            while c != 0:
                ls.append(ListNode(c % 10))
                c //= 10
            for i in range(len(ls) - 1):
                ls[i].next = ls[i + 1]
        return ls[0]
    def getnum(self, l: ListNode) -> ListNode:
        a = 0;
        i = 1;
        while l:
            a += l.val * i
            i *= 10
            l = l.next
        return a

# 整除使用//    注意python中链表的使用方法