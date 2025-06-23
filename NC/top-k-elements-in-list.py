class Solution:
    def topKFrequentUsingBucketSort(self, nums: List[int], k: int) -> List[int]:
        count = {}
        freq = [[] for i in range(len(nums)+1)]
        ans = []

        for num in nums:
            count[num] = count.get(num, 0) + 1

        for key, value in count.items():
            freq[value].append(key)

        for i in range(len(freq)-1, 0, -1):
            for num in freq[i]:
                ans.append(num)
                if len(ans) == k:
                    break
            if len(ans) == k:
                break

        return ans

    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        count = {}

        heapList = []

        for num in nums:
            count[num] = count.get(num, 0) + 1

        for num, count in count.items():
            heapList.append((count*-1, num))

        heapq.heapify(heapList)

        ans = []

        for i in range(0, k):
            currTuple = heapq.heappop(heapList)
            ans.append(currTuple[1])

        return ans
