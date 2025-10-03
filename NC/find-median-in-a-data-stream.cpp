class MedianFinder
{
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (left.size() == 0 && right.size() == 0)
        {
            left.push(num);
        }
        else if (left.size() > 0)
        {
            if (num > left.top())
            {
                right.push(num);
            }
            else
            {
                left.push(num);
            }
        }
        else
        {
            if (num < right.top())
            {
                left.push(num);
            }
            else
            {
                right.push(num);
            }
        }

        while (left.size() > right.size())
        {
            right.push(left.top());
            left.pop();
        }
        while (right.size() > left.size() + 1)
        {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian()
    {
        if (left.size() == right.size())
        {
            return (left.top() + right.top()) / 2.0;
        }
        return right.top();
    }
};
