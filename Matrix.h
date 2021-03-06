#include <iostream>

using namespace std;

#ifndef MATRIX_CPP
#define MATRIX_CPP

class Matrix {
public:
	int **mas;
	int n;
	int m;

	Matrix() {
		mas = nullptr;
		n = 0;
		m = 0;
	}

	~Matrix() {
		for (int i = 0; i < n; i++)
			delete mas[i];
		delete mas;
	}

	Matrix* createM(int n, int m) {
		mas = reinterpret_cast<int **>(new double*[n]);
		for (int i = 0; i < n; i++) {
			mas[i] = reinterpret_cast<int *>(new double[m]);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				mas[i][j] = 0;

		this->m = m;
		this->n = n;
		return this;
	}

	Matrix* createM1(int n, int m) {
		mas = reinterpret_cast<int **>(new double*[n]);
		for (int i = 0; i < n; i++) {
			mas[i] = reinterpret_cast<int *>(new double[m]);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				mas[i][j] = 1;

		this->m = m;
		this->n = n;
		return this;
	}

	Matrix* printMatrix() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << mas[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return this;
	}

	Matrix* createSimpleMatrix(int size) {
		this->createM(size, size);
		for (int i = 0; i < size; i++)
			mas[i][i] = 1;
		this->n = size;
		this->m = size;
		return this;
	}

	Matrix* mul(Matrix *mat) {
		if (this->m == mat->n) {
			Matrix *tmp = new Matrix();
			tmp->createM(this->n, mat->m);
			for (int i = 0; i < this->n; i++) {
				for (int j = 0; j < mat->m; j++) {
					int rez = 0;
					for (int r = 0; r < this->m; r++) {
						rez += this->mas[i][r] * mat->mas[r][j];
					}
					tmp->mas[i][j] = rez;
				}
			}
			return tmp;
		}
		return nullptr;
	}

	Matrix* generateMoveMatrix(double dx, double dy) {
		this->createSimpleMatrix(3);
		this->mas[2][0] = dx;
		this->mas[2][1] = dy;
		return this;
	}

	// TODO: fix scale
	Matrix* generateScaleMatrix(double sx, double sy) {
		this->createSimpleMatrix(3);
		this->mas[0][0] = sx;
		this->mas[0][0] = sy;
		return this;
	}

};

#endif // MATRIX_CPP
