#include <cstdio>
#include <cstring>

const int D = 1E7 + 7;
struct Matrix
{
	static const int N = 30;
	int n, mat[N][N];
	void init(const int num = 0)
	{
		memset(mat, 0, sizeof mat);
		for (int i = 0; i < n; i++) mat[i][i] = num;
	}
	Matrix(const int _n, const int num = 0) : n(_n)
	{
		init(num);
	}
	void input()
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) scanf("%d", &mat[i][j]);
	}
	Matrix operator+(const Matrix &b)
	{
		Matrix r(n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				r.mat[i][j] = (mat[i][j] + b.mat[i][j]) % D;
		return r;
	}
	void operator+=(const Matrix &b) { (*this) = (*this) + b; }
	Matrix operator*(const Matrix &b)
	{
		Matrix r(n);
		for (int i = 0; i < n; i++)
			for (int k = 0; k < n; k++)
				if (mat[i][k])
					for (int j = 0; j < n; j++)
						r.mat[i][j] =
							(r.mat[i][j]
							 + mat[i][k] * b.mat[k][j])
							% D;
		return r;
	}
	void operator*=(const Matrix &b) { (*this) = (*this) * b; }
	Matrix operator^(const int _index)
	{
		Matrix r(n, 1), tmp(*this);
		int index = _index;
		while (index)
		{
			if (index & 1) r *= tmp;
			tmp *= tmp;
			index >>= 1;
		}
		return r;
	}
	void operator^=(const int index)
	{
		(*this) = (*this) ^ index;
	}
};