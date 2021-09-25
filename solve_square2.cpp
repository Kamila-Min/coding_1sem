#include "solve_square header2.h"

//unit tests
// doxygen
// formatting    tabs spaces names
// safe input

int main ()
{
  printf ("Solving the quadratic equation of the form: ax^2 + bx + c = 0\n");

  printf ("Enter a, b, c\n");

  double a = NAN, b = NAN, c = NAN;

  if (scanf ("%lf %lf %lf", &a, &b, &c) != 3) // checking scanf
  {
    printf ("There is entered wrong amount of coefficients\n" );
  }

  printf ("a = %lg, b = %lg, c = %lg\n", a, b, c);

  double x1 = 0, x2 = 0;

  Check_variables (&x1, &x2);

  int n_Roots = Solve_square (a, b, c, &x1, &x2); /* variable n_Roots showing the number of roots and appropriation it meaning from function solve_square */

  F_result (n_Roots, x1, x2);

  Unit_Tests ();

  return 0;
}

//-----------------------------------------------------------------------------
//!    Checking the addresses of variables that are the solution of the
//!                square equation ax^2 + bx + c = 0
//!
//! @param [in]   a   a-coefficient
//! @param [in]   b   b-coefficient
//! @param [in]   c   c-coefficient
//!
//! @note  In case of incorrect variable addresses, the program is interrupted.
//-----------------------------------------------------------------------------

int Check_variables (double * x1, double * x2)
  {
    assert (x1 != x2 != NULL);
  }

//----------------------------------------------------------------------------
//!         Solving a square equation ax^2 + bx + c = 0
//!
//! @param [in]   a   a-coefficient
//! @param [in]   b   b-coefficient
//! @param [in]   c   c-coefficient
//! @param [out]  x1  Pointer to the 1st root
//! @param [out]  x2  Pointer to the 2st root
//!
//! @return  Number of roots
//!
//! @note    Includes the functions of checking coefficients,
//!          solving linear equation, solving equation with discriminant.
//----------------------------------------------------------------------------

int Solve_square (double a, double b, double c, double * x1, double * x2) /* function solving the square and finding a number of roots*/
   {
    Check_coefficients (a, b, c);

    double m = a;

    if (Comparison_with_null (m) == 0) // cases of reduction to linear equation

      Linear_equation (b, c, &x1, m);

    else // cases of finding discriminant

       Solve_with_discriminant (a, b, c, &x1, &x2, m);
   }

//----------------------------------------------------------------------------------
//! Checking coefficient a, b, c
//!
//! @param [in]   a   a-coefficient
//! @param [in]   b   b-coefficient
//! @param [in]   c   c-coefficient
//!
//! @note  In cases with incorrect entered coefficients, the program is interrupted.
//----------------------------------------------------------------------------------

int Check_coefficients (double a, double b, double c)
  {
    assert (isfinite (a)); // checking coefficients a, b, c
    assert (isfinite (b));
    assert (isfinite (c));
  }

//----------------------------------------------------------------------------------
//! Solving a linear equation
//!
//! @param  [in]      b    b-coefficient
//! @param  [in]      c    c-coefficient
//! @param  [out]   ptrx1  Points to pointer to the 1st root
//!
//! @return  Number of roots
//!
//! @note    Is included in function Solve_square.
//----------------------------------------------------------------------------------

int Linear_equation (double b, double c, double ** ptrx1, double m)
   {
    m = b;

    if (Comparison_with_null (m) == 0)
      {
        m = c;

        if (Comparison_with_null (m) == 0)//case with the endless amount of roots
        return -1;

        else     //case without any roots
        return 0;
      }

    else
      {
        **ptrx1 = -c/b; // case with the one root
        return 1;
      }
   }

//----------------------------------------------------------------------------------
//! Solving a equation with finding a discriminant
//!
//! @param  [in]      a    a-coefficient
//! @param  [in]      b    b-coefficient
//! @param  [in]      c    c-coefficient
//! @param  [out]   ptrx1  Points to pointer to the 1st root
//! @param  [out]   ptrx2  Points to pointer to the 2st root
//! @param  [in]      m    Using in comparison with null
//!
//! @return  Number of roots
//!
//! @note    Is included in function Solve_square.
//----------------------------------------------------------------------------------

int Solve_with_discriminant (double a, double b, double c, double ** ptrx1, double ** ptrx2, double m) // cases of reduction to finding discriminant
    {
       double D = b*b - 4*a*c;

       if (D < 0) // case without any roots
      return 0;

      m = D;

       if (Comparison_with_null (m) == 0) // case with the one root
       {
        **ptrx1 = -b/(2*a);
        return 1;
       }

       if (D > 0) // case with two roots
       {
         double sqrt_D = sqrt (D);

         **ptrx1 = (-b + sqrt_D)/2*a;
         **ptrx2 = (-b - sqrt_D)/2*a;

         return 2;
        }
    }

//-------------------------------------------------------------------------------------------
//! Comparison with null
//!
//! @param [in]  m  Using in comparison
//!
//! @return Result of comparison
//!
//! @note   Is included in functions Solve_square, Linear_equation, Solving_with_discriminant
//!         to compare coefficients a, b, c and discriminant with null.
//-------------------------------------------------------------------------------------------

int Comparison_with_null (double m)
   {
     if (abs (m) < cmp_precision)
     return 0;
   }

//-------------------------------------------------------------------------------------------
//! Printing of result of solving square equation
//!
//! @param  [in]  n_Roots  Number of roots
//! @param  [in]    x1     1st root
//! @param  [in]    x2     2st root
//!
//! return   1    In case with wrong amount of roots
//-------------------------------------------------------------------------------------------

int F_result (int n_Roots, double x1, double x2)
  {
    switch (n_Roots) // pass through all possible values of variable n_Roots with last solving of square
      {
        case -1: printf ("The endless amount of roots\n");
        break;
        case 0: printf ("No roots\n");
        break;
        case 1: printf ("x = %lg\n", x1);
        break;
        case 2: printf ("x1 = %lg, x2 = %lg\n", x1, x2);
        break;
        default: printf ("ERROR: n_Roots = %d\n", n_Roots);
        return 1;
      }

  }

//-------------------------------------------------------------------------------------
//! Testing the program
//!
//! @return  0
//!
//! @note  Included 6 tests and in case of their successfully working prints about that
//-------------------------------------------------------------------------------------

int Unit_Tests ()
  {

   double x1 = NAN, x2 = NAN;

   Test_1 (x1, x2);

   Test_2 (x1, x2);

   Test_3 (x1, x2);

   Test_4 (x1, x2);

   Test_5 (x1, x2);

   Test_6 (x1, x2);

   if ((Test_1 (x1, x2) == 0) & (Test_2 (x1, x2) == 0) & (Test_3 (x1, x2) == 0) & (Test_4 (x1, x2) == 0) & (Test_5 (x1, x2) == 0) & (Test_6 (x1, x2) == 0))
   printf ("All tests passed successfully\n");

   else
   printf ("ERROR in function Unit_Tests");

   return 0;
  }

//-----------------------------------------------------------------------------
//! Test 1 of the 6 include in function Unit_Tests
//!
//! @param  [in]  x1  1st root
//! @param  [in]  x2  2st root
//!
//! @return  0  In case with successfully working
//! @return  1  In case with failing working
//!
//! @note  Testing the case of amount number of roots (a=0, b=0, c=0)
//-----------------------------------------------------------------------------

int Test_1 (double x1, double x2)
  {
    int n_roots = Solve_square (0, 0, 0, &x1, &x2);

    if (n_roots == -1)
    return 0;

    else
    {
    printf ("Test 1 FAILED;\n There is should be the endless amount of roots\n");
    return 1;
    }

  }

//-----------------------------------------------------------------------------
//! Test 2 of the 6 include in function Unit_Tests
//!
//! @param  [in]  x1  1st root
//! @param  [in]  x2  2st root
//!
//! @return  0  In case with successfully working
//! @return  1  In case with failing working
//!
//! @note  Testing the case of no roots (a=0, b=0, c!=0)
//-----------------------------------------------------------------------------

int Test_2 (double x1, double x2)
  {
    int n_roots = Solve_square (0, 0, 9, &x1, &x2);

    if (n_roots == 0)
    return 0;

    else
    {
    printf ("Test 2 FAILED;\n There is should be no roots\n");
    return 1;
    }

  }

//-----------------------------------------------------------------------------
//! Test 3 of the 6 include in function Unit_Tests
//!
//! @param  [in]  x1  1st root
//! @param  [in]  x2  2st root
//!
//! @return  0  In case with successfully working
//! @return  1  In case with failing working
//!
//! @note  Testing the case of one root (a=0, b!=0, c!=0)
//-----------------------------------------------------------------------------

int Test_3 (double x1, double x2)
  {
    int n_roots = Solve_square (0, -2, -5, &x1, &x2);

    if ((n_roots == 1) & (x1 == -2.5))
    return 0;

    else
    {
    printf ("Test 3 FAILED;\n x1 = %lg, n_Roots = %d should be: -2.5, 1\n", x1, n_roots);
    return 1;
    }

  }

//-----------------------------------------------------------------------------
//! Test 4 of the 6 include in function Unit_Tests
//!
//! @param  [in]  x1  1st root
//! @param  [in]  x2  2st root
//!
//! @return  0  In case with successfully working
//! @return  1  In case with failing working
//!
//! @note  Testing the case of no roots (a!=0, b!=0, c!=0, D<0)
//-----------------------------------------------------------------------------

int Test_4 (double x1, double x2)
  {
    int n_roots = Solve_square (1, 2, 3, &x1, &x2);

    if (n_roots == 0)
    return 0;

    else
    {
    printf ("Test 4 FAILED;\n There is should be no roots\n");
    return 1;
    }

  }

//-----------------------------------------------------------------------------
//! Test 5 of the 6 include in function Unit_Tests
//!
//! @param  [in]  x1  1st root
//! @param  [in]  x2  2st root
//!
//! @return  0  In case with successfully working
//! @return  1  In case with failing working
//!
//! @note  Testing the case of one root (a!=0, b!=0, c!=0, D=0)
//-----------------------------------------------------------------------------

int Test_5 (double x1, double x2)
  {
    int n_roots = Solve_square (1, -2, 1, &x1, &x2);

    if (n_roots == 1)
    return 0;

    else
    {
    printf ("Test 5 FAILED;\n x1 = %lg, n_Roots = %d should be: 1, 1\n", x1, n_roots);
    return 1;
    }

  }

//-----------------------------------------------------------------------------
//! Test 1 of the 6 include in function Unit_Tests
//!
//! @param  [in]  x1  1st root
//! @param  [in]  x2  2st root
//!
//! @return  0  In case with successfully working
//! @return  1  In case with failing working
//!
//! @note  Testing the case of two roots (a!=0, b!=0, c!=0, D>0)
//-----------------------------------------------------------------------------

int Test_6 (double x1, double x2)
  {
    int n_roots = Solve_square (1, -5, 6, &x1, &x2);

    if ((n_roots == 2) & (x1 == 3) & (x2 == 2))
    return 0;

    else
    {
    printf ("Test 6 FAILED;\n x1 = %lg, x2 = %lg, n_Roots = %d should be: 3, 2, 2\n", x1, x2, n_roots);
    return 1;
    }

  }

