#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int check_coefficients (double a, double b, double c);// announcement of function checking coefficients

int solve_with_discriminant (double a, double b, double c, double* x1, double* x2, int result_of_comparison, double m, double _NULL);// announcement of function of solving quadratic square with discriminant

int linear_equation (double b, double c, double* x1, int result_of_comparison, double m, double _NULL); // announcement of function of solving linear square

int comparison_with_null (double m, double _NULL);

int solve_square (double a, double b, double c, double* x1, double* x2, int result_of_comparison, double m, double _NULL); //announcement of function of solving quadratic square

const double _NULL = 0.0000001;

int main ()
{
  printf ("Решение квадратного уравнения\n");
  printf ("Введите a, b, c\n");

  double a = NAN, b = NAN, c = NAN; //announcement of coefficients
  scanf ("%lg %lg %lg", &a, &b, &c);
  printf ("a = %lg, b = %lg, c = %lg\n", a, b, c);

  double x1 = 0, x2 = 0; //announcement of variables showing roots of square

  double m = 0;

  int result_of_comparison = 0;

  int n_Roots = solve_square (a, b, c, &x1, &x2, result_of_comparison, m, _NULL); /* announcement of variable n_Roots showing the number of roots and appropriation it meaning from function solve_square */

  switch (n_Roots) // pass through all possible values of variable n_Roots with last solving of square
  {
   case -1: printf ("Бесконечное количество корней\n");
   break;
   case 0: printf ("Нет корней\n");
   break;
   case 1: printf ("x = %lg\n", x1);
   break;
   case 2: printf ("x1 = %lg, x2 = %lg\n", x1, x2);
   break;
   default: printf ("Ошибка: n_Roots = %d\n", n_Roots);
   return 1;
  }

return 0;
}

  int solve_square (double a, double b, double c, double* x1, double* x2, int result_of_comparison, double m, double _NULL ) /* function solving the square and finding a number of roots*/
   {
    check_coefficients (a, b, c);

    m = a;

    result_of_comparison = comparison_with_null (m, _NULL);

    if (result_of_comparison == 1) // cases of reduction to linear equation

      linear_equation (b, c, x1, result_of_comparison, m, _NULL);

    else // cases of finding discriminant

       solve_with_discriminant (a, b, c, x1, x2, result_of_comparison, m, _NULL);
   }

int linear_equation (double b, double c, double* x1, int result_of_comparison, double m, double _NULL )
  {
    m = b;

    result_of_comparison = comparison_with_null (m, _NULL);

    if (result_of_comparison == 1)
      {
        m = c;

        result_of_comparison = comparison_with_null (m, _NULL);

        if (result_of_comparison == 1)//case with the endless amount of roots
        return -1;

        else     //case without any roots
        return 0;
      }

    else
      {
        *x1 = -c/b; // case with the one root
        return 1;
      }
  }

int check_coefficients (double a, double b, double c)
  {
    assert (isfinite (a)); // checking coefficients a, b, c
    assert (isfinite (b));
    assert (isfinite (c));
  }

int solve_with_discriminant (double a, double b, double c, double* x1, double* x2, int result_of_comparison, double m, double _NULL) // cases of reduction to finding discriminant
    {
       double D = b*b - 4*a*c;

       m = D;

       result_of_comparison = comparison_with_null (m, _NULL);

       if (D < 0) // case without any roots
      return 0;

       if (result_of_comparison == 1) // case with the one root
       {
        *x1 = -b/(2*a);
        return 1;
       }

       if (D > 0) // case with two roots
       {
         double sqrt_D = sqrt (D);

         *x1 = (-b + sqrt_D)/2*a;
         *x2 = (-b - sqrt_D)/2*a;

         return 2;
        }
    }

int comparison_with_null (double m, double _NULL)
  {

    if  ( abs (m - 0) < _NULL) //comparison with null
    return 1;

    else
    return 0;

  }



