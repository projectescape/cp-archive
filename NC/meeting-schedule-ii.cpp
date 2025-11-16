/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution
{
public:
    int minMeetingRooms(vector<Interval> &intervals)
    {
        if (intervals.size() == 0)
        {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b)
             { return a.start < b.start; });

        vector<vector<Interval>> schedules;
        schedules.push_back({intervals[0]});

        for (int i = 1; i < intervals.size(); i++)
        {
            Interval curr = intervals[i];
            bool inserted = false;

            for (auto &s : schedules)
            {
                Interval prev = s[s.size() - 1];
                if (prev.end <= curr.start)
                {
                    inserted = true;
                    s.push_back(curr);
                    inserted = true;
                    break;
                }
            }

            if (!inserted)
            {
                schedules.push_back({curr});
            }
        }

        return schedules.size();
    }
};
