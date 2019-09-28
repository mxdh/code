#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

typedef long long LL;

const int INF = 2147483646;

template <typename _Tp>
struct segment {
    _Tp val;
    int l, r;
};

class segment_tree {
  private:
    struct _node {
        LL val, tag;
        const int l, r;
        _node *ls, *rs;

        _node(int _l, int _r)
            : val(0), tag(0), l(_l), r(_r), ls(NULL), rs(NULL) {}
    } * root;

    void _prepare(_node *&k, int l, int r) {
        if (k == NULL) k = new _node(l, r);
    }

    void __push_down(_node *k) {
        _node *ls = k->ls, *rs = k->rs;
        LL &tag = k->tag;
        ls->val += tag * ((LL)((k->r - k->l) >> 1) + 1);
        ls->tag += tag;
        rs->val += tag * ((LL)(k->r - k->l + 1) >> 1);
        rs->tag += tag;
        tag = 0;
    }

    void _push_down(_node *k) {
        if (k->tag) {
            _prepare(k->ls, k->l, (k->l + k->r) >> 1);
            _prepare(k->rs, ((k->l + k->r) >> 1) + 1, k->r);
            __push_down(k);
        }
    }

    void _push_up(_node *k) {
        k->val = 0;
        if (k->ls != NULL) k->val += k->ls->val;
        if (k->rs != NULL) k->val += k->rs->val;
    }

    void _modify(_node *k, int l, int r, int val) {
        int l_ = k->l, r_ = k->r;
        if (l_ >= l && r_ <= r) {
            k->val += (LL)val * ((LL)r_ - l_ + 1);
            k->tag += val;
            return;
        }
        int mid = (l_ + r_) >> 1;
        _push_down(k);
        if (mid >= l) {
            _prepare(k->ls, l_, mid);
            _modify(k->ls, l, r, val);
        }
        if (mid < r) {
            _prepare(k->rs, mid + 1, r_);
            _modify(k->rs, l, r, val);
        }
        _push_up(k);
    }

    LL _query(_node *k, int l, int r) {
        int l_ = k->l, r_ = k->r;
        if (l_ >= l && r_ <= r) return k->val;
        LL ret = 0;
        _push_down(k);
        if ((l_ + r_) >> 1 >= l && k->ls != NULL) ret += _query(k->ls, l, r);
        if ((l_ + r_) >> 1 < r && k->rs != NULL) ret += _query(k->rs, l, r);
        return ret;
    }

  public:
    segment_tree(int l = 0, int r = INF) { _prepare(root, l, r); }

    void modify(int l, int r, int val) { _modify(root, l, r, val); }

    LL query(int l, int r) { return _query(root, l, r); }
} seg(1, INF);

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        seg.modify(a, INF, b);
    }
    for (int i = 0; i < m; ++i) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
            cout << fixed << setprecision(4)
                 << (double)seg.query(a, b) / (b - a + 1) << endl;
        else
            seg.modify(a, INF, b);
    }
    return 0;
}