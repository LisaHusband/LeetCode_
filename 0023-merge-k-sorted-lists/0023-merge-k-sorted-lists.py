# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        head=ListNode()
        try:
            v_list = []
            for i in lists:
                while i :
                    v_list.append(i.val)
                    i = i.next
            
            v_list.sort()
            cur = head
            for i in v_list:
                cur.next = ListNode()
                cur.next.val = i
                cur = cur.next
            return head.next
        except:
            return head.next
