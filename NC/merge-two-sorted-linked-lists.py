# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2

        if not list2:
            return list1

        curr1 = list1
        curr2 = list2

        head = None

        if curr1.val < curr2.val:
            head = curr1
            curr1 = curr1.next
        else:
            head = curr2
            curr2 = curr2.next

        curr = head

        while curr1 or curr2:
            if not curr1:
                curr.next = curr2
                break

            elif not curr2:
                curr.next = curr1
                break

            elif curr1.val < curr2.val:
                curr.next = curr1
                curr = curr1
                curr1 = curr1.next
            else:
                curr.next = curr2
                curr = curr2
                curr2 = curr2.next

        return head
