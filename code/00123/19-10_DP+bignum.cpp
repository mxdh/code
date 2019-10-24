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

template <typename _Sequence = ::std::vector<unsigned char> >
class Bignum {
  public:
    Bignum() { c.push_back(0); }

    Bignum(int num) {
        do {
            c.push_back(num % 10);
            num /= 10;
        } while (num);
    }

    Bignum& operator=(int num) {
        c.clear();
        do {
            c.push_back(num % 10);
            num /= 10;
        } while (num);
        return *this;
    }

  protected:
    _Sequence c;
};

#endif

using ::std::max;

const int N = 80;
int a[N + 1];
Bignum<> f[N + 1];

int main() {
    int n, m;
    Bignum<> ans;
    std::cin >> n >> m;
    while (n--) {
        Bignum<> tmp = 0;
        for (int i = 1; i <= m; ++i) std::cin >> a[i];
        f[0] = 0;
        for (int i = 1; i <= m; ++i) {
            int tmp = 1 << i;
            f[i] = f[i - 1] + a[i] * tmp;
            for (int j = i - 1; j; --j)
                f[j] =
                    max(f[j - 1] + a[j] * tmp, f[j] + a[m - (i - j) + 1] * tmp);
            f[0] += a[m - i + 1] * tmp;
        }
        for (int i = 1; i <= m; ++i) tmp = max(tmp, f[i]);
        ans += tmp;
    }
    std::cout << ans;
    return 0;
}