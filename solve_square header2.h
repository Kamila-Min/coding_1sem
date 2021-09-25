#ifndef SOLVE_SQUARE_HEADER_H_INCLUDED
#define SOLVE_SQUARE_HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int Check_variables (double* x1, double* x2);

int Solve_square (double a, double b, double c, double* x1, double* x2);

int Check_coefficients (double a, double b, double c);

int Linear_equation (double b, double c, double ** ptrx1, double m);

int Solve_with_discriminant (double a, double b, double c, double ** ptrx1, double ** ptrx2, double m);

int Comparison_with_null (double m);

int F_result (int n_Roots, double x1, double x2);

int Unit_Tests ();

int Test_1 (double x1, double x2);

int Test_2 (double x1, double x2);

int Test_3 (double x1, double x2);

int Test_4 (double x1, double x2);

int Test_5 (double x1, double x2);

int Test_6 (double x1, double x2);


const double cmp_precision = 0.0000001;


#endif // SOLVE_SQUARE_HEADER_H_INCLUDED
