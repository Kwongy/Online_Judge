# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        dummy=ListNode(0)
        dummy.next=head
        pre=dummy
        for _ in range(1,m):
            pre=pre.next
        # 找到反转的首结点
        head=pre.next
        #head,pre节点始终没变，head.next的所指的节点在循环中不断的移到pre的后面。
        for _ in range(m,n):
            nex=head.next
            head.next,nex.next,pre.next=nex.next,pre.next,nex
        return dummy.next