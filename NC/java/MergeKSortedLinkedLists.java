package NC.java;

public class MergeKSortedLinkedLists {
    public ListNode mergeKLists(ListNode[] lists) {

        if (lists.length == 0) {
            return null;
        }

        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> {
            return a.val - b.val;
        });

        for (var node : lists) {
            pq.add(node);
        }

        ListNode ans = pq.poll();
        ListNode curr = ans;

        if (curr.next != null) {
            pq.add(curr.next);
        }

        while (pq.size() > 1) {
            ListNode temp = pq.poll();
            curr.next = temp;
            curr = temp;
            if (temp.next != null) {
                pq.add(temp.next);
            }
        }

        if (pq.size() == 1) {
            curr.next = pq.poll();
        }

        return ans;
    }
}
