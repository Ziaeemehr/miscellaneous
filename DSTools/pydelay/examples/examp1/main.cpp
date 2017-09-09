#include<complex>
#include<math.h>
#include<cmath>
#include<cstdlib>
#include<iostream>
#define MANUAL
#define false 0;
#define true 1;
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define SQUARE(X) ((X) * (X))

using namespace std;

double t;
double *pt_t_ar;
long unsigned int SIM_n;
long unsigned int SIM_size;

/* positions of lags in the arrays */
long unsigned int plag1;
long unsigned int plag2;
/* arrays holding the variabls */

double *pt_y;
double *pt_y1_v;

double hermite_y(const double &t, const double &tn, const double &Xn, const double &Vn, 
                                     const double &tnp1, const double &Xnp1, const double &Vnp1) 
{
    double h = tnp1 - tn;
    double s = (t - tn) / h;

    return (1.0 + 2 * s) * SQUARE(s-1.0) * Xn + (3.0 - 2 * s) * SQUARE(s) * Xnp1 + h * s * SQUARE(s-1.0) *Vn + h * (s - 1) * SQUARE(s) *Vnp1;
}

double dt_hermite_y(const double &t, const double &tn, const double &Xn, const double &Vn, 
                                     const double &tnp1, const double &Xnp1, const double &Vnp1) 
{
    double h = tnp1 - tn;
    double s = (t - tn) / h;

    return (1.0-4.0*s+3.0*SQUARE(s))*Vn + s*(3.0*s-2.0)*Vnp1 + 6.0*(s-1.0)*s*(Xn-Xnp1)/h;
}

double interp_y1(double t, long unsigned int *n0) 
{
    while(pt_t_ar[*n0+1] < t)
        (*n0)++;
    while(pt_t_ar[*n0] > t) 
        (*n0)--;

    return hermite_y1(t, pt_t_ar[*n0],   pt_y1_ar[*n0],   pt_y1_Var[*n0], 
                              pt_t_ar[*n0+1], pt_y1_ar[*n0+1], pt_y1_Var[*n0+1]);
}

double dt_interp_y1(double t, long unsigned int *n0) 
{
    while(pt_t_ar[*n0+1] < t)
        (*n0)++;
    while(pt_t_ar[*n0] > t) 
        (*n0)--;

    return dt_hermite_y1(t, pt_t_ar[*n0],   pt_y1_ar[*n0],   pt_y1_Var[*n0], 
                              pt_t_ar[*n0+1], pt_y1_ar[*n0+1], pt_y1_Var[*n0+1]);
}



int main(int argc, const char *argv[])
{
    double dtmin = 0.0001;
    double dtmax = 0.1;
    double tfinal = 100.0;
    double RelTol = 1.0E-3;
    double AbsTol = 1.0E-6;
    int chunk = 10000;
    int nstart = 101;
    double dt0 = 0.01;
    double maxdelay = 1.; // Set the maximum delay here !!!
    long unsigned int MaxIter = 10000000;
    int NumOfDiscont = 4;
    double discont[4] = {maxdelay, 2*maxdelay, 3*maxdelay, tfinal};
    double PARtau2 = 0.2;
    double PARtau1 = 1.0;
    t = 0.0; 
    long unsigned int i;
    long unsigned int NumberOfMinSteps = 0;
    int nextdsc = 0;
    int hitdsc = false;
    double dist;
    int TakingMinStep = 0;
    SIM_n = nstart; 
    SIM_size = SIM_n + chunk;
    double RelErr;
    double thresh = AbsTol/RelTol;
    double dt = dt0;
    srand((unsigned)123);
    plag1 = SIM_n;
    plag2 = SIM_n;





