# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        # 如果左边和右边相等，说明无需反转，直接返回原链表
        if left == right:
            return head
        
        # 创建一个虚拟头节点，方便处理头节点需要反转的情况
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        
        # 1. 找到 left - 1 的位置
        for _ in range(left - 1):
            prev = prev.next
        
        # 2. 当前指针指向 left 位置
        current = prev.next
        # 3. 反转从 left 到 right 之间的链表
        for _ in range(right - left):
            tmp = current.next
            current.next = tmp.next
            tmp.next = prev.next
            prev.next = tmp
        
        return dummy.next  # 返回反转后的链表头