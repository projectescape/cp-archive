package NC.java;

public class MergeTwoSortedLinkedList {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null) {
            return list2;
        }
        if (list2 == null) {
            return list1;
        }
        ListNode ans, temp;

        if (list1.val < list2.val) {
            ans = list1;
            temp = list1;
            list1 = list1.next;
        } else {
            ans = list2;
            temp = list2;
            list2 = list2.next;
        }

        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                temp.next = list1;
                temp = list1;
                list1 = list1.next;
            } else {
                temp.next = list2;
                temp = list2;
                list2 = list2.next;
            }
        }
        temp.next = list1 != null ? list1 : list2;
        return ans;
    }
}
