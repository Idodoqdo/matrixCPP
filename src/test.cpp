#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

void zapolnenie(S21Matrix & A, double num) {
  for (int r = 0; r < A.get_rows(); r++) {
    for (int c = 0; c < A.get_cols(); c++) {
      A(r, c) = num++;
    }
  }
}

TEST(ConstructorTest, default_and_parametrs) {
  S21Matrix A(3, 3);
  zapolnenie(A, 3);
  S21Matrix B(3, 3);
  zapolnenie(B, 3);
  bool check = A.eq_matrix(B);
  EXPECT_EQ(check, true);
  EXPECT_EQ(A.get_rows(), B.get_rows());
  EXPECT_EQ(A.get_cols(), B.get_cols());
}

TEST(ConstructorTest, copy_move) {
  S21Matrix A;
  zapolnenie(A, 1);
  S21Matrix B(A);
  S21Matrix C = std::move(A);
  bool check = B.eq_matrix(C);
  EXPECT_EQ(check, true);
  EXPECT_EQ(B.get_rows(), C.get_rows());
  EXPECT_EQ(B.get_cols(), C.get_cols());
  EXPECT_EQ(B.get_rows(), C.get_rows());
  EXPECT_EQ(B.get_cols(), C.get_cols());
}

TEST(OperatorsTest, assign_eq) {
  S21Matrix A, B;
  zapolnenie(A, 3);
  B = A;
  bool check = A == B;
  EXPECT_EQ(check, true);
}

TEST(OperatorsTest, plus) {
  S21Matrix A(3, 3), B(3,3);
  zapolnenie(A, 2);
  zapolnenie(B, 2);
  S21Matrix C(3,3);
  C(0, 0) = 4;
  C(0, 1) = 6;
  C(0, 2) = 8;
  C(1, 0) = 10;
  C(1, 1) = 12;
  C(1, 2) = 14;
  C(2, 0) = 16;
  C(2, 1) = 18;
  C(2, 2) = 20;
  A = A + A;
  B += B;
  bool check_1 = A.eq_matrix(C);
  bool check_2 = B.eq_matrix(C);
  EXPECT_EQ(check_1, true);
  EXPECT_EQ(check_2, true);
}

TEST(OperatorsTest, minus) {
  S21Matrix A(3, 3), B(3, 3);
  zapolnenie(A, 2.1);
  zapolnenie(B, 1);
  S21Matrix C(3, 3);
  C(0, 0) = 1.1;
  C(0, 1) = 1.1;
  C(0, 2) = 1.1;
  C(1, 0) = 1.1;
  C(1, 1) = 1.1;
  C(1, 2) = 1.1;
  C(2, 0) = 1.1;
  C(2, 1) = 1.1;
  C(2, 2) = 1.1;
  A = A - B;
  bool check_1 = A.eq_matrix(C);
  zapolnenie(A, 2.1);
  A -= B;
  bool check_2 = A.eq_matrix(C);
  EXPECT_EQ(check_1, true);
  EXPECT_EQ(check_2, true);
}

TEST(OperatorsTest, multiplication_number) {
  S21Matrix A(3, 3), B(3, 3);
  zapolnenie(A, 2);
  zapolnenie(B, 2);
  S21Matrix C(3, 3);
  C(0, 0) = 20;
  C(0, 1) = 30;
  C(0, 2) = 40;
  C(1, 0) = 50;
  C(1, 1) = 60;
  C(1, 2) = 70;
  C(2, 0) = 80;
  C(2, 1) = 90;
  C(2, 2) = 100;
  A = A * 10;
  bool check_1 = A.eq_matrix(C);
  B *= 10;
  bool check_2 = A.eq_matrix(C);
  EXPECT_EQ(check_1, true);
  EXPECT_EQ(check_2, true);
}

TEST(OperatorsTest, multiplication) {
  S21Matrix A, B, C;
  A(0, 0) = 1;
  A(0, 1) = 1;
  A(0, 2) = 1;
  A(1, 0) = 2;
  A(1, 1) = 2;
  A(1, 2) = 2;
  A(2, 0) = 3;
  A(2, 1) = 3;
  A(2, 2) = 3;

  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(1, 0) = 1;
  B(1, 1) = 2;
  B(1, 2) = 3;
  B(2, 0) = 1;
  B(2, 1) = 2;
  B(2, 2) = 3;

  C(0, 0) = 3;
  C(0, 1) = 6;
  C(0, 2) = 9;
  C(1, 0) = 6;
  C(1, 1) = 12;
  C(1, 2) = 18;
  C(2, 0) = 9;
  C(2, 1) = 18;
  C(2, 2) = 27;
  S21Matrix res = A * B;
  EXPECT_EQ(res == C, true);

  S21Matrix D, F;
  zapolnenie(D, 1.0);
  D *= D;
  F(0, 0) = 30;
  F(0, 1) = 36;
  F(0, 2) = 42;
  F(1, 0) = 66;
  F(1, 1) = 81;
  F(1, 2) = 96;
  F(2, 0) = 102;
  F(2, 1) = 126;
  F(2, 2) = 150;
  EXPECT_EQ(D == F, true);
}

TEST(MethodsTest, sum_matrix) {
  S21Matrix A, B;
  zapolnenie(A, 1);
  B(0, 0) = 2;
  B(0, 1) = 4;
  B(0, 2) = 6;
  B(1, 0) = 8;
  B(1, 1) = 10;
  B(1, 2) = 12;
  B(2, 0) = 14;
  B(2, 1) = 16;
  B(2, 2) = 18;
  A.sum_matrix(A);
  bool check = A.eq_matrix(B);
  EXPECT_EQ(check, true);
}

TEST(MethodsTest, sub_matrix) {
  S21Matrix A, B, C;
  C(0, 0) = 9.1;
  C(0, 1) = 9.1;
  C(0, 2) = 9.1;
  C(1, 0) = 9.1;
  C(1, 1) = 9.1;
  C(1, 2) = 9.1;
  C(2, 0) = 9.1;
  C(2, 1) = 9.1;
  C(2, 2) = 9.1;
  zapolnenie(A, 10.1);
  zapolnenie(B, 1);
  A.sub_matrix(B);
  bool check = A.eq_matrix(C);
  EXPECT_EQ(check, true);
}

TEST(MethodsTest, mul_number) {
  S21Matrix A, B;
  zapolnenie(A, 1.1);
  B(0, 0) = 11.0;
  B(0, 1) = 21.0;
  B(0, 2) = 31.0;
  B(1, 0) = 41.0;
  B(1, 1) = 51.0;
  B(1, 2) = 61.0;
  B(2, 0) = 71.0;
  B(2, 1) = 81.0;
  B(2, 2) = 91.0;
  A = A * 10;
  bool check = A.eq_matrix(B);
  EXPECT_EQ(check, true);
}

TEST(MethodsTest, mul_matrix) {
  S21Matrix A, B, C;
  zapolnenie(A, 1);
  zapolnenie(B, 10);
  C(0, 0) = 84;
  C(0, 1) = 90;
  C(0, 2) = 96;
  C(1, 0) = 201;
  C(1, 1) = 216;
  C(1, 2) = 231;
  C(2, 0) = 318;
  C(2, 1) = 342;
  C(2, 2) = 366;
  A.mul_matrix(B);
  bool check = A.eq_matrix(C);
  EXPECT_EQ(check, true);
}

TEST(MethodsTest, transpose) {
  S21Matrix A;
  zapolnenie(A, 1);
  S21Matrix B = A.transpose();
  S21Matrix C;
  C(0, 0) = 1.0;
  C(0, 1) = 4.0;
  C(0, 2) = 7.0;
  C(1, 0) = 2.0;
  C(1, 1) = 5.0;
  C(1, 2) = 8.0;
  C(2, 0) = 3.0;
  C(2, 1) = 6.0;
  C(2, 2) = 9.0;
  EXPECT_EQ(B == C, true);
}

TEST(MethodsTest, determinant) {
  S21Matrix A;
  zapolnenie(A, 10);
  ASSERT_NEAR(A.determinant(), 0, EPS);
  S21Matrix B;
  B(0, 0) = 1.0;
  B(0, 1) = 7.0;
  B(0, 2) = 5.0;
  B(1, 0) = 4.0;
  B(1, 1) = 0.0;
  B(1, 2) = 3.0;
  B(2, 0) = 7.0;
  B(2, 1) = 9.0;
  B(2, 2) = 6.0;
  ASSERT_NEAR(B.determinant(), 132.0, EPS);
}

TEST(MethodsTest, calc_complements) {
  S21Matrix A;
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(0, 2) = 3.0;
  A(1, 0) = 0.0;
  A(1, 1) = 4.0;
  A(1, 2) = 2.0;
  A(2, 0) = 5.0;
  A(2, 1) = 2.0;
  A(2, 2) = 1.0;
  S21Matrix B;
  B(0, 0) = 0.0;
  B(0, 1) = 10.0;
  B(0, 2) = -20.0;
  B(1, 0) = 4.0;
  B(1, 1) = -14.0;
  B(1, 2) = 8.0;
  B(2, 0) = -8.0;
  B(2, 1) = -2.0;
  B(2, 2) = 4.0;
  S21Matrix C = A.calc_complements();
  EXPECT_EQ(B == C, true);
  S21Matrix AA;
  AA(0, 0) = 1.0;
  AA(0, 1) = 1.0;
  AA(0, 2) = 1.0;
  AA(1, 0) = 1.0;
  AA(1, 1) = 1.0;
  AA(1, 2) = 1.0;
  AA(2, 0) = 1.0;
  AA(2, 1) = 1.0;
  AA(2, 2) = 1.0;
  S21Matrix BB;
  BB(0, 0) = 0.0;
  BB(0, 1) = 0.0;
  BB(0, 2) = 0.0;
  BB(1, 0) = 0.0;
  BB(1, 1) = 0.0;
  BB(1, 2) = 0.0;
  BB(2, 0) = 0.0;
  BB(2, 1) = 0.0;
  BB(2, 2) = 0.0;
  S21Matrix CC = AA.calc_complements();
  EXPECT_EQ(BB == CC, true);
}

TEST(MethodsTest, inverse_matrix) {
  S21Matrix A;
  A(0, 0) = 2.0;
  A(0, 1) = 5.0;
  A(0, 2) = 7.0;
  A(1, 0) = 6.0;
  A(1, 1) = 3.0;
  A(1, 2) = 4.0;
  A(2, 0) = 5.0;
  A(2, 1) = -2.0;
  A(2, 2) = -3.0;
  S21Matrix B = A.inverse_matrix();
  S21Matrix C;
  C(0, 0) = 1.0;
  C(0, 1) = -1.0;
  C(0, 2) = 1.0;
  C(1, 0) = -38.0;
  C(1, 1) = 41.0;
  C(1, 2) = -34.0;
  C(2, 0) = 27.0;
  C(2, 1) = -29.0;
  C(2, 2) = 24.0;
}

TEST(MethodsTest, assesor_mutator) {
  S21Matrix A;
  zapolnenie(A, 1);
  EXPECT_EQ(A.get_rows(), 3);
  EXPECT_EQ(A.get_cols(), 3);
  S21Matrix B(6,6);  
  EXPECT_EQ(B.get_rows(), 6);
  EXPECT_EQ(B.get_cols(), 6);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}