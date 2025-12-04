package NC.java;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MeetingSchedule2 {
    public int minMeetingRooms(List<Interval> intervals) {
        List<Integer> start = new ArrayList<>();
        List<Integer> ends = new ArrayList<>();

        for (var interval : intervals) {
            start.add(interval.start);
            ends.add(interval.end);
        }

        Collections.sort(start);
        Collections.sort(ends);

        int ans = 0;

        int curr = 0;

        for (int i = 0, j = 0; i < start.size();) {
            int startTime = start.get(i);
            int endTime = ends.get(j);
            if (startTime == endTime) {
                curr--;
                j++;
            } else if (startTime < endTime) {
                curr++;
                i++;
            } else {
                curr--;
                j++;
            }

            ans = Math.max(ans, curr);
        }

        return ans;
    }
}
