#include <cstdio>
#include <cstring>

const int D = 1E7 + 7;

class Matrix
{
  public:
	Matrix() {}
	void init(const int num = 0)
	{
		for (int i = 0; i < n; i++)
		{
			mat[i] = new int[n];
			memset(mat[i], 0, n * sizeof *mat[i]);
			mat[i][i] = num;
		}
	}
	Matrix(const int _n, const int num = 0) : n(_n)
	{
		mat = new int *[n];
		init(num);
	}
	Matrix(const int n, const int *mat)
	{
		this->n = n;
		this->mat = new int *[n];
		for (int i = 0; i < n; i++)
		{
			this->mat[i] = new int[n];
			memcpy(this->mat[i], mat + i * n, n * sizeof *mat);
		}
	}
	Matrix(const Matrix &b)
	{
		n = b.n;
		mat = new int *[n];
		for (int i = 0; i < n; i++)
		{
			mat[i] = new int[n];
			memcpy(mat[i], b.mat[i], n * sizeof *mat[i]);
		}
	}
	~Matrix()
	{
		for (int i = 0; i < n; i++) delete[] mat[i];
		delete[] mat;
	}
	void input()
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) scanf("%d", &mat[i][j]);
	}
	Matrix *operator*(const Matrix &b)
	{
		Matrix *r = new Matrix(n);
		for (int i = 0; i < n; ++i)
			for (int k = 0; k < n; ++k)
				if (mat[i][k])
					for (int j = 0; j < n; ++j)
						r->mat[i][j] =
							(r->mat[i][j]
							 + mat[i][k] * b.mat[k][j] % D)
							% D;
		return r;
	}
	void operator*=(const Matrix b)
	{
		Matrix *tmp = (*this) * b;
		(*this) = (*tmp);
		delete tmp;
	}
	Matrix *operator^(const int _index)
	{
		Matrix *r = new Matrix(n, 1), tmp(*this);
		int index = _index;
		while (index)
		{
			if (index & 1) (*r) *= tmp;
			tmp *= tmp;
			index >>= 1;
		}
		return r;
	}
	void operator^=(const int index)
	{
		Matrix *tmp = (*this) ^ index;
		(*this) = (*tmp);
		delete tmp;
	}
	int get(const int x, const int y) { return mat[x][y]; }

  private:
	int n, **mat;
};