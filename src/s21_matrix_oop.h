#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_
#include <iostream>
#include <math.h>

#define EPS 1e-7

class S21Matrix {
 private:
    unsigned int rows = 3, cols = 3;
    double ** matrix;

 public:
    S21Matrix(unsigned int r, unsigned int c);

    S21Matrix();

    S21Matrix(const S21Matrix &other);

    S21Matrix(S21Matrix&& other);

    ~S21Matrix();

    void operator = (const S21Matrix &other);

    S21Matrix operator + (const S21Matrix &other);

    S21Matrix operator - (const S21Matrix &other);

    S21Matrix operator * (const S21Matrix &other);

    S21Matrix operator * (const double);

    bool operator == (const S21Matrix &other);

    void operator += (const S21Matrix &other);

    void operator -= (const S21Matrix & other);

    void operator *= (const S21Matrix & other);

    void operator *= (const double num);

    double & operator ()(unsigned int i, unsigned int j);

    void operator = (S21Matrix &&other);

    bool eq_matrix(const S21Matrix& other);

    void sum_matrix(const S21Matrix& other);

    void sub_matrix(const S21Matrix& other);

    void mul_number(const double num);

    void mul_matrix(const S21Matrix& other);

    S21Matrix transpose();

    S21Matrix minor(unsigned int i, unsigned int j);

    double determinant();

    S21Matrix calc_complements();

    S21Matrix inverse_matrix();

    int get_rows() const;

    int get_cols() const;
};

#endif  // SRC_S21_MATRIX_OOP_H_
