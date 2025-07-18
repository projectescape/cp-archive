# Definition for singly-linked list.

from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseListIterative(self, head: Optional[ListNode]) -> Optional[ListNode]:

        if head == None:
            return head

        prevNode, currNode = None, head

        while currNode != None:
            nextNode = currNode.next
            currNode.next = prevNode
            prevNode = currNode
            currNode = nextNode

        return prevNode
    
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        if head == None:
            return head

        nextNode = head.next
        newHead = head
        if nextNode:
            newHead = self.reverseList(nextNode)
            nextNode.next = head
            
        head.next = None


        return newHead

sol = Solution()

newHead = sol.reverseList(ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5))))))

while newHead:
    print(newHead.val, end=" -> ")
    newHead = newHead.next
print("None")



