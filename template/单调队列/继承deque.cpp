#include <deque>
#include <utility>

using std::deque;
using std::make_pair;
using std::pair;

template <typename Cmp>
class MonotoneQueue : deque<pair<int, int>>
{
  public:
    void push(const int k, const int num)
    {
        while (!empty() && !cmp(back().second, num)) pop_back();
        push_back(make_pair(k, num));
    }
    void pop(const int l)
    {
        update(l);
        pop_front();
    }
    int top(const int l)
    {
        update(l);
        return front().second;
    }

  private:
    Cmp cmp;

    void update(const int l)
    {
        while (!empty() && front().first < l)
            pop_front();
    }
};