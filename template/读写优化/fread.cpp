#include <cctype>
#include <cstdio>

inline char GetChar() {
    static const int SIZE = 1 << 20;
    static char buf[SIZE], *s, *t;
    return s == t && (t = (s = buf) + fread(buf, 1, SIZE, stdin), s == t)
               ? EOF
               : *s++;
}

#define getchar GetChar

template <typename T>
inline int GetNum(T &num) {
    char c;
    num = 0;
    bool p = false;
    for (c = getchar(); !isdigit(c); c = getchar()) {
        p |= c == '-';
        if (c == EOF) return EOF;
    }
    for (; isdigit(c); c = getchar()) num = (num << 1) + (num << 3) + (c ^ 48);
    num = p ? -num : num;
    return 1;
}