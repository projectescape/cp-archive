package NC.java;

public class ReorderLinkedList {
    private ListNode reverseList(ListNode node) {
        if (node == null || node.next == null) {
            return node;
        }

        ListNode next = node.next;
        node.next = null;
        ListNode newHead = reverseList(next);
        next.next = node;

        return newHead;

    }

    public void reorderList(ListNode head) {
        if (head == null) {
            return;
        }
        ListNode curr = head, temp1, temp2;

        int listLength = 1;
        while (curr.next != null) {
            listLength++;
            curr = curr.next;
        }

        if (listLength == 1) {
            return;
        }

        int breakLength = listLength / 2;

        curr = head;

        for (int i = 0; i < breakLength; i++) {
            curr = curr.next;
        }

        ListNode mid = curr.next;
        curr.next = null;

        mid = reverseList(mid);

        curr = head;

        while (mid != null) {

            temp1 = curr.next;
            temp2 = mid.next;

            curr.next = mid;
            mid.next = temp1;
            curr = temp1;
            mid = temp2;
        }

    }
}
