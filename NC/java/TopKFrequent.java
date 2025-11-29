package NC.java;

import java.util.*;

public class TopKFrequent {

    public int[] topKFrequent(int[] nums, int k) {

        Map<Integer, Integer> numCount = new HashMap();

        for (int i : nums) {
            numCount.put(i, numCount.getOrDefault(i, 0) + 1);
        }

        List<List<Integer>> numCountList = new ArrayList();

        for (var entry : numCount.entrySet()) {
            numCountList.add(List.of(entry.getKey(), entry.getValue()));
        }

        Collections.sort(numCountList, (a, b) -> {
            return b.get(1) - a.get(1);
        });

        List<Integer> ans = new ArrayList();

        for (int i = 0; i < k; i++) {
            ans.add(numCountList.get(i).get(0));
        }

        return ans.stream().mapToInt(Integer::intValue).toArray();

    }

    public int[] topKFrequentWithHeap(int[] nums, int k) {

        Map<Integer, Integer> numCount = new HashMap();

        for (int i : nums) {
            numCount.put(i, numCount.getOrDefault(i, 0) + 1);
        }

        List<List<Integer>> numCountList = new ArrayList<>();

        for (var entry : numCount.entrySet()) {
            numCountList.add(List.of(entry.getKey(), entry.getValue()));
        }

        PriorityQueue<List<Integer>> pq = new PriorityQueue<>((a, b) -> {
            return b.get(1) - a.get(1);
        });

        pq.addAll(numCountList);

        int[] ans = new int[k];

        for (int i = 0; i < k; i++) {
            ans[i] = pq.poll().get(0);
        }

        return ans;

    }

}
