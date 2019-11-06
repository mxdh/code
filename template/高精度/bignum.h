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
    for (int i = b.size() - 1; i >= 0; --i) output << b[i];
    return output;
}

template <typename Sequence>
bool operator<(const Bignum<Sequence>& a, const Bignum<Sequence>& b) {
    if (a.size() == b.size())
        for (int i = a.size() - 1; i >= 0; --i)
            if (a[i] != b[i]) return a[i] < b[i];
    return a.size() < b.size();
}

}  // namespace Jel

#endif