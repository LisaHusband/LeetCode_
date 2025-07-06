# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next or k == 0:
            return head
        
        # 计算链表长度
        n = 1
        tail = head
        while tail.next:
            tail = tail.next
            n += 1

        k %= n
        if k == 0:
            return head

        # 设置快慢指针
        fast = head
        slow = head

        # fast 先走 k 步
        for _ in range(k):
            fast = fast.next

        # 然后 fast 和 slow 一起走，直到 fast 到达末尾
        while fast.next:
            fast = fast.next
            slow = slow.next

        # 断开链表，重新连接
        new_head = slow.next
        slow.next = None
        fast.next = head

        return new_head