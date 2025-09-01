# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head is None:
            return False

        slow = head
        fast = head.next

        while slow is not fast:
            if fast is None:
                return False
            slow = slow.next
            fast = fast.next
            if slow is None or fast is None:
                return False

            fast = fast.next

        return True
