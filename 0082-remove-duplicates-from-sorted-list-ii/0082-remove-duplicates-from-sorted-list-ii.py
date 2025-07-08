# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head)  # 哨兵节点，便于处理头结点被删除的情况
        prev = dummy
        cur = head

        while cur:
            # 检查 cur 是否是重复元素的开始
            if cur.next and cur.val == cur.next.val:
                # 跳过所有相同的节点
                while cur.next and cur.val == cur.next.val:
                    cur = cur.next
                # 将 prev 的 next 指向下一个不同的值
                prev.next = cur.next
            else:
                # 如果当前值不重复，前进 prev 指针
                prev = prev.next
            cur = cur.next  # 继续前进 cur 指针

        return dummy.next
        