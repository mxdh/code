#include <cstring>

typedef long long ll;

struct Matrix {
    static const int N = 2;
    int mat[N][N];
    void init(const int num = 0) {
        memset(mat, 0, sizeof mat);
        for (int i = 0; i < N; i++) mat[i][i] = num;
    }
    Matrix(const int num = 0) { init(num); }
    Matrix operator*(const Matrix &b) const {
        Matrix r;
        for (int i = 0; i < N; ++i)
            for (int k = 0; k < N; ++k)
                if (mat[i][k])
                    for (int j = 0; j < N; ++j)
                        r.mat[i][j] =
                            (r.mat[i][j] + (ll)mat[i][k] * b.mat[k][j] % d) % d;
        return r;
    }
    void operator*=(const Matrix &b) { (*this) = (*this) * b; }
    Matrix operator^(ll index) const {
        Matrix r(1), tmp(*this);
        while (index) {
            if (index & 1) r *= tmp;
            tmp *= tmp;
            index >>= 1;
        }
        return r;
    }
    void operator^=(const ll index) { (*this) = (*this) ^ index; }
} mat;