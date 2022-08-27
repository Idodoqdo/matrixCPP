#ifndef SRC__MATRIX_OOP_H_
#define SRC__MATRIX_OOP_H_
#include <iostream>
#include <math.h>

#define EPS 1e-7

class Matrix {
 private:
    unsigned int rows = 3, cols = 3;
    double ** matrix;

 public:
    Matrix(unsigned int r, unsigned int c);

    Matrix();

    Matrix(const Matrix &other);

    Matrix(Matrix&& other);

    ~Matrix();

    void operator = (const Matrix &other);

    Matrix operator + (const Matrix &other);

    Matrix operator - (const Matrix &other);

    Matrix operator * (const Matrix &other);

    Matrix operator * (const double);

    bool operator == (const Matrix &other);

    void operator += (const Matrix &other);

    void operator -= (const Matrix & other);

    void operator *= (const Matrix & other);

    void operator *= (const double num);

    double & operator ()(unsigned int i, unsigned int j);

    void operator = (Matrix &&other);

    bool eq_matrix(const Matrix& other);

    void sum_matrix(const Matrix& other);

    void sub_matrix(const Matrix& other);

    void mul_number(const double num);

    void mul_matrix(const Matrix& other);

    Matrix transpose();

    Matrix minor(unsigned int i, unsigned int j);

    double determinant();

    Matrix calc_complements();

    Matrix inverse_matrix();

    int get_rows() const;

    int get_cols() const;
};

#endif  // SRC__MATRIX_OOP_H_
