# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        if not head:
            return None

        # Step 1: 将链表转为数组（列表）
        nodes = []
        while head:
            nodes.append(head)
            head = head.next

        # Step 2: 重排 nodes 中的元素
        less = [node for node in nodes if node.val < x]
        greater_equal = [node for node in nodes if node.val >= x]

        # Step 3: 拼接两个链表
        reordered = less + greater_equal
        for i in range(len(reordered) - 1):
            reordered[i].next = reordered[i + 1]
        if reordered:
            reordered[-1].next = None
            return reordered[0]
        else:
            return None