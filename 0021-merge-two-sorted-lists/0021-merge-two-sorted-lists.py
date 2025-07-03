# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode()
        result = head
        v_list=[]
        try:
            while list1 or list2:
                if list1 and list2:
                    v_list.append(list1.val)
                    v_list.append(list2.val)
                    list1=list1.next
                    list2=list2.next
                elif list1:
                    v_list.append(list1.val)
                    list1=list1.next
                else:
                    v_list.append(list2.val)
                    list2=list2.next
            v_list.sort()
            for i in v_list:
                result.next = ListNode()
                result.next.val = i
                result = result.next
            return head.next
        except:
            if list1==list2:
                return None
            else:
                return head