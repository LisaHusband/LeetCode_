class Solution:
    def removeNthFromEnd(self, head, n):
        dummy = ListNode(0)
        dummy.next = head

        fast = slow = dummy

        # fast 先走 n+1 步，确保 slow 停在待删除前一个
        for _ in range(n + 1):
            fast = fast.next

        while fast:
            fast = fast.next
            slow = slow.next

        # 删除节点
        slow.next = slow.next.next

        return dummy.next
