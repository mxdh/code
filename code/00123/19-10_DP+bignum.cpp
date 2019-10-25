#include <algorithm>
#include <iostream>

/**
 * @file Bignum.h
 * @author mxdh (a27573@outlook.com).
 * @brief Big number library
 * @version 0.1
 * @date 2019-10-24
 *
 * @copyright Copyright (c) 2019
 *
 */
#ifndef _BIGNUM_H_
#define _BIGNUM_H_ 1

#include <vector>

namespace bignum {

template <typename _Base = unsigned short,
          typename _Sequence = ::std::vector<_Base> >
class Bignum {
  public:
    Bignum() {}

    Bignum(int num) {
        do {
            c.push_back(num % 10);
            num /= 10;
        } while (num);
    }

    Bignum<_Base, _Sequence>& operator=(int num) {
        c.clear();
        do {
            c.push_back(num % 10);
            num /= 10;
        } while (num);
        return *this;
    }

    Bignum<_Base, _Sequence>& operator+=(const Bignum<_Base, _Sequence>& b) {
        _Base tmp = 0;
        for (int i = 0; i < c.size() && i < b.c.size(); ++i) c[i] += b.c[i];
        for (int i = c.size(); i < b.c.size(); ++i) c.push_back(b.c[i]);
        for (int i = 0; i < c.size(); ++i) {
            c[i] += t;
            t = c[i] / 10;
            c[i] %= 10;
        }
        while (t) {
            c.push_back(t % 10);
            t /= 10;
        }
        return *this;
    }

    Bignum<_Base, _Sequence>& operator*=(const Bignum<_Base, _Sequence>& b) {
        Bignum<_Base, _Sequence> a = *this;
        *this = 0;
        for (int i = 0; i < a.c.size(); ++i)
            for (int j = 0; j < b.c.size(); ++j) {
            }
        return *this;
    }

  protected:
    _Sequence c;
};

template <typename _Base, typename _Sequence>
Bignum<_Base, _Sequence> operator+(const Bignum<_Base, _Sequence>& a,
                                   const Bignum<_Base, _Sequence>& b) {
    Bignum<_Base, _Sequence> ret = a;
    ret += b;
    return ret;
}

template <typename _Base, typename _Sequence>
Bignum<_Base, _Sequence> operator*(const Bignum<_Base, _Sequence>& a,
                                   const Bignum<_Base, _Sequence>& b) {
    return ret;
}

}  // namespace bignum

#endif

using bignum::Bignum;
using ::std::max;

const int N = 80;
int a[N + 1];
Bignum<> f[N + 1];

int main() {
    int n, m;
    Bignum<> ans = 0;
    std::cin >> n >> m;
    while (n--) {
        Bignum<> tmp = 1;
        for (int i = 1; i <= m; ++i) std::cin >> a[i];
        f[0] = 0;
        for (int i = 1; i <= m; ++i) {
            tmp *= 2;
            f[i] = f[i - 1] + a[i] * tmp;
            for (int j = i - 1; j; --j)
                f[j] =
                    max(f[j - 1] + a[j] * tmp, f[j] + a[m - (i - j) + 1] * tmp);
            f[0] += a[m - i + 1] * tmp;
        }
        tmp = 0;
        for (int i = 1; i <= m; ++i) tmp = max(tmp, f[i]);
        ans += tmp;
    }
    std::cout << ans;
    return 0;
}