#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;

typedef long long LL;

const int N = 100000, INF = 2147483646;

class segment_tree {
  private:
    struct _node {
        LL val, tag;
        int l, r;
        _node *ls, *rs;

        _node() : ls(NULL), rs(NULL), val(0), tag(0) {}
    } root;

    void _prepare(_node *&k, int l, int r) {
        if (k == NULL) {
            k = new _node;
            k->l = l;
            k->r = r;
        }
    }

    void _push_down(_node *k, int mid) {
        _node *ls = k->ls, *rs = k->rs;
        LL tag = k->tag;
        _prepare(ls, k->l, mid);
        ls->val += tag * ((LL)mid - k->l + 1);
        ls->tag += tag;
        _prepare(rs, mid + 1, k->r);
        rs->val += tag * ((LL)k->r - mid);
        rs->tag += tag;
    }

    void _push_up(_node *k) { k->val = k->ls->val + k->rs->val; }

    void _modify(_node *k, int l, int r, int val) {
        int l_ = k->l, r_ = k->r;
        if (l_ >= l && r_ <= r) {
            k->val += (LL)val * ((LL)r - l + 1);
            k->tag += val;
            return;
        }
        int mid = (l_ + r_) >> 1;
        _push_down(k, mid);
        if (mid >= l) {
            _prepare(k->ls, l_, mid);
            _modify(k->ls, l, mid, val);
        }
        if (mid < r) {
            _prepare(k->rs, mid + 1, r_);
            _modify(k->rs, mid + 1, r, val);
        }
        _push_up(k);
    }

    LL _query(_node *k, int l, int r) {
        int l_ = k->l, r_ = k->r;
        LL ret = 0;
        if (l_ >= l && r_ <= r) return k->val;
        int mid = (l_ + r_) >> 1;
        _push_down(k, mid);
        if (mid >= l && k->ls != NULL) ret += _query(k->ls, l, mid);
        if (mid < r && k->rs != NULL) ret += _query(k->rs, mid + 1, r);
        return ret;
    }

  public:
    segment_tree(int l = 0, int r = INF) {
        root.l = l;
        root.r = r;
    }

    void modify(int l, int r, int val) { _modify(&root, l, r, val); }

    LL query(int l, int r) { return _query(&root, l, r); }
} seg;

int a[N], b[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    for (int i = 0; i < m; ++i) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
            cout << setprecision(4) << seg.query(a, b) << endl;
        else
            seg.modify()
    }
    return 0;
}