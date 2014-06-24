/*
 * Insert Interval
 * Total Accepted: 10031 Total Submissions: 49985
 *
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution
{
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
    {
        if (intervals.empty())
        {
            intervals.push_back(newInterval);
            return intervals;
        }

        if (newInterval.start < intervals[0].start || (newInterval.start == intervals[0].start && newInterval.end <= intervals[0].end))
        {
            intervals.insert(intervals.begin(), newInterval);
            size_t tmp = 1;
            while (tmp < intervals.size())
            {
                if (intervals[tmp].start <= intervals[0].end)
                    tmp++;
                else
                    break;
            }
            if (tmp != 1)
            {
                tmp--;
                intervals[tmp].start = min(intervals[0].start, intervals[tmp].start);
                intervals[tmp].end = max(intervals[0].end, intervals[tmp].end);
                intervals.erase(intervals.begin(), intervals.begin() + tmp);
            }
        }
        else if (newInterval.start > intervals[intervals.size() - 1].start || (newInterval.start == intervals[intervals.size() - 1].start && newInterval.end >= intervals[intervals.size() - 1].end))
        {
            intervals.insert(intervals.end(), newInterval);
            if (intervals[intervals.size() - 2].end >= intervals[intervals.size() - 1].start)
            {
                intervals[intervals.size() - 2].end = max(intervals[intervals.size() - 2].end, intervals[intervals.size() - 1].end);
                intervals.resize(intervals.size() - 1);
            }
        }
        else
        {
            size_t insertPosition = 0;
            for (size_t i = 0; i + 1 < intervals.size(); i++)
            {
                if (newInterval.start >= intervals[i].start && newInterval.start <= intervals[i + 1].start)
                {
                    if (newInterval.start == intervals[i].start && newInterval.start == intervals[i + 1].start)
                    {
                        if (newInterval.end >= intervals[i].end && newInterval.end <= intervals[i + 1].end)
                        {
                            intervals.insert(intervals.begin() + i + 1, newInterval);
                            insertPosition = i + 1;
                            break;
                        }
                    }
                    else
                    {
                        intervals.insert(intervals.begin() + i + 1, newInterval);
                        insertPosition = i + 1;
                        break;
                    }
                }
            }
            int it = insertPosition - 1;
            while (it + 1 < intervals.size())
            {
                if (intervals[it].end >= intervals[it + 1].start)
                {
                    if (intervals[it].end < intervals[it + 1].end)
                        intervals[it].end = intervals[it + 1].end;
                    intervals.erase(intervals.begin() + it + 1);
                }
                else
                {
                    it++;
                }
            }
        }

        return intervals;
    }
};
