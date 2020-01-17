#include <deque>
#include <utility>

using std::deque;
using std::make_pair;
using std::pair;

template <typename Cmp>
class MonotoneQueue : deque<pair<int, int> > {
  public:
    void push(const int k, const int num) {
        while (!empty() && !cmp(back().second, num)) pop_back();
        push_back(make_pair(k, num));
    }
    void pop(const int l) {
        update(l);
        pop_front();
    }
    int top(const int l) {
        update(l);
        return front().second;
    }

  private:
    Cmp cmp;

    void update(const int l) {
        while (!empty() && front().first < l) pop_front();
    }
};

const int N=100000;
int f[N+1];

int main() {
    scanf("%d",&n,&k);
    for (int i=0;i<n;++i) scanf("%d",&a+i);
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j)
    }
    return 0;
}