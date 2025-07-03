# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        head = head
        cur = head
        while cur:
            if cur.next:
                tmp = cur.val
                cur.val=cur.next.val
                cur.next.val=tmp
                cur = cur.next.next
            else:
                break

        return head