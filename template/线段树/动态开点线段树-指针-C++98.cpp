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
struct TRUE {
    bool operator()(const _Tp &val) const { return true; }
};

template <typename _Tp, typename _Node, typename __merge, typename __push_down,
          typename __cover, typename __check = TRUE<_Node> >
class segment_tree {
  private:
    __merge merge;
    __push_down push_down;
    __cover cover;
    __check check;

    struct _node {
        _Node val;
        const int l, r;
        _node *ls, *rs;

        _node(int _l, int _r) : l(_l), r(_r), ls(NULL), rs(NULL) {}
    } * root;

    void _prepare(_node *&k, int l, int r) {
        if (k == NULL) k = new _node(l, r);
    }

    void _push_down(_node *k) {
        if (check(k->val)) {
            int l = k->l, r = k->r;
            _prepare(k->ls, l, (l + r) >> 1);
            _prepare(k->rs, ((l + r) >> 1) + 1, r);
            push_down(&(k->val), &(k->ls->val), &(k->rs->val), r - l + 1);
        }
    }

    void _push_up(_node *k) {
        k->val = merge(k->ls != NULL ? &(k->ls->val) : NULL,
                       k->rs != NULL ? &(k->rs->val) : NULL);
    }

    void _modify(_node *k, int l, int r, void (*op)(_Node *, _Tp, int),
                 _Tp val) {
        int l_ = k->l, r_ = k->r;
        if (l_ >= l && r_ <= r) {
            op(&(k->val), val, r_ - l_ + 1);
            return;
        }
        int mid = (l_ + r_) >> 1;
        _push_down(k);
        if (mid >= l) {
            _prepare(k->ls, l_, mid);
            _modify(k->ls, l, r, op, val);
        }
        if (mid < r) {
            _prepare(k->rs, mid + 1, r_);
            _modify(k->rs, l, r, op, val);
        }
        _push_up(k);
    }

    _Node _query(_node *k, int l, int r) {
        int l_ = k->l, r_ = k->r;
        if (l_ >= l && r_ <= r) return k->val;
        _Node a, b;
        _push_down(k);
        if ((l_ + r_) >> 1 >= l && k->ls != NULL)
            a = _Node(_query(k->ls, l, r));
        if ((l_ + r_) >> 1 < r && k->rs != NULL) b = _Node(_query(k->rs, l, r));
        return merge(&a, &b);
    }

  public:
    segment_tree(int l = 0, int r = INF) : root(new _node(l, r)) {}

    void modify(int l, int r, void (*op)(_Node *, _Tp, int), int val) {
        _modify(root, l, r, op, val);
    }

    _Tp query(int l, int r) { return cover(_query(root, l, r)); }
};

struct node {
    LL val, tag;
    node() : val(0), tag(0) {}
};

void opt(node *k, LL val, int len) {
    k->val += (LL)val * len;
    k->tag += val;
}

struct push_down {
    void operator()(node *k, node *ls, node *rs, int len) const {
        LL &tag = k->tag;
        ls->val += tag * (len - (len >> 1));
        ls->tag += tag;
        rs->val += tag * (len >> 1);
        rs->tag += tag;
        tag = 0;
    }
};

struct merge {
    node operator()(node *ls, node *rs) const {
        node ret;
        if (ls != NULL) ret.val += ls->val;
        if (rs != NULL) ret.val += rs->val;
        return ret;
    }
};

struct cover {
    LL operator()(const node &val) const { return val.val; }
};

struct check {
    bool operator()(const node &val) const { return val.tag; }
};

int main() {
    int n, m;
    segment_tree<LL, node, merge, push_down, cover, check> seg(1, INF);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        seg.modify(a, INF, opt, b);
    }
    for (int i = 0; i < m; ++i) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
            cout << fixed << setprecision(4)
                 << (double)seg.query(a, b) / (b - a + 1) << endl;
        else
            seg.modify(a, INF, opt, b);
    }
    return 0;
}