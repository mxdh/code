/**
 * @file Bignum.h
 * @author mxdh (a27573@outlook.com)
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