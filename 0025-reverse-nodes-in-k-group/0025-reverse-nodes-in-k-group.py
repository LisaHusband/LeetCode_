# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        res_head = ListNode()
        res_cur = res_head
        count=0
        tmpl = []
        tmp = []

        while head:
            count+=1
            tmp.append(head.val)
            if count==k:
                count=0
                tmp.reverse()
                tmpl.append(tmp)
                tmp = []
            head = head.next
        if tmp:
            tmpl.append(tmp)

        for j in tmpl:
            for i in j:
                res_cur.next = ListNode()
                res_cur.next.val = i
                res_cur = res_cur.next
        return res_head.next
            
