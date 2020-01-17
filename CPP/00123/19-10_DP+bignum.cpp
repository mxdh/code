//AC O2
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

#include <cstddef>
#include <iostream>
#include <vector>

namespace Jel {

typedef unsigned short numBase;

template <typename Sequence = ::std::vector<numBase> >
class Bignum {
  public:
    Bignum() {}

    Bignum(int num) {
        do {
            c.push_back(num % 10);
            num /= 10;
        } while (num);
    }

    size_t size() const { return c.size(); }

    numBase& operator[](int k) { return c[k]; }

    const numBase& operator[](int k) const { return c[k]; }

    template <typename Tp>
    Bignum<Sequence>& operator=(Tp num) {
        c.clear();
        do {
            c.push_back(num % 10);
            num /= 10;
        } while (num);
        return *this;
    }

    Bignum<Sequence>& operator+=(const Bignum<Sequence>& b) {
        size_t sb = b.size();
        if (sb > size()) c.resize(sb);
        for (size_t i = 0; i < sb; ++i) c[i] += b[i];
        format();
        return *this;
    }

    Bignum<Sequence>& operator*=(const Bignum<Sequence>& b) {
        Bignum<Sequence> a = *this;
        c.clear();
        size_t sa = a.size(), sb = b.size();
        c.resize(sa + sb - 1);
        for (size_t i = 0; i < sa; ++i)
            for (size_t j = 0; j < sb; ++j) c[i + j] += a[i] * b[j];
        format();
        return *this;
    }

  protected:
    Sequence c;

    void format() {
        size_t s = size();
        numBase t = 0;
        for (size_t i = 0; i < s; ++i) {
            c[i] += t;
            t = c[i] / 10;
            c[i] %= 10;
        }
        while (t) {
            c.push_back(t % 10);
            t /= 10;
        }
    }
};

template <typename Sequence>
inline Bignum<Sequence> operator+(const Bignum<Sequence>& a,
                           const Bignum<Sequence>& b) {
    Bignum<Sequence> ret = a;
    ret += b;
    return ret;
}

template <typename Sequence>
inline Bignum<Sequence> operator*(const Bignum<Sequence>& a,
                           const Bignum<Sequence>& b) {
    Bignum<Sequence> ret = a;
    ret *= b;
    return ret;
}

template <typename Tp, typename Sequence>
inline Bignum<Sequence> operator*(const Tp& a, const Bignum<Sequence>& b) {
    Bignum<Sequence> ret = a;
    ret *= b;
    return ret;
}

template <typename Tp, typename Sequence>
inline Bignum<Sequence> operator*(const Bignum<Sequence>& a, const Tp& b) {
    Bignum<Sequence> ret = a;
    ret *= b;
    return ret;
}

template <typename Sequence>
std::ostream& operator<<(std::ostream& output, const Bignum<Sequence>& b) {
    for (int i = b.size()-1; i >= 0; --i) output << b[i];
    return output;
}

template <typename Sequence>
bool operator<(const Bignum<Sequence>& a,const Bignum<Sequence>& b) {
    if (a.size()==b.size())
        for (int i=a.size()-1;i>=0;--i)
            if (a[i]!=b[i]) return a[i]<b[i];
    return a.size()<b.size();
}

}  // namespace Jel

#endif

using Jel::Bignum;
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