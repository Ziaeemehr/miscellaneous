
#include<complex>
#include<math.h>
#include<cmath>
#include<cstdlib>
#include<iostream>

/****** uncomment the following line to run generated source code directly ***************/
#define MANUAL

#define false 0;
#define true 1;

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

#define SQUARE(X) ((X) * (X))

double Heavi(double tin) {
    if(tin>=0)
        return 1.0;
    else
        return 0.0;
}

typedef std::complex<double> Complex;
const Complex ii(0.0, 1.0);
double t;
double *pt_t_ar;
long unsigned int SIM_n;
long unsigned int SIM_size;
#define ABSy1(X) (fabs(X))
#define ABSy3(X) (fabs(X))
#define ABSy2(X) (fabs(X))
#define ABSy5(X) (fabs(X))
#define ABSy4(X) (fabs(X))

/* positions of lags in the arrays */
long unsigned int LIInt1;
long unsigned int LIInt2;
/* arrays holding the variabls */
double *pt_y1_ar;
double *pt_y1_Var;
double *pt_y3_ar;
double *pt_y3_Var;
double *pt_y2_ar;
double *pt_y2_Var;
double *pt_y5_ar;
double *pt_y5_Var;
double *pt_y4_ar;
double *pt_y4_Var;

inline double hermite_y1(const double &, const double &, const double &, const double &, 
                                                   const double &, const double &, const double &);
inline double dt_hermite_y1(const double &, const double &, const double &, const double &, 
                                                   const double &, const double &, const double &);


            
inline double hermite_y3(const double &, const double &, const double &, const double &, 
                                                   const double &, const double &, const double &);
inline double dt_hermite_y3(const double &, const double &, const double &, const double &, 
                                                   const double &, const double &, const double &);


            
inline double hermite_y2(const double &, const double &, const double &, const double &, 
                                                   const double &, const double &, const double &);
inline double dt_hermite_y2(const double &, const double &, const double &, const double &, 
                                                   const double &, const double &, const double &);


            
inline double hermite_y5(const double &, const double &, const double &, const double &, 
                                                   const double &, const double &, const double &);
inline double dt_hermite_y5(const double &, const double &, const double &, const double &, 
                                                   const double &, const double &, const double &);


            
inline double hermite_y4(const double &, const double &, const double &, const double &, 
                                                   const double &, const double &, const double &);
inline double dt_hermite_y4(const double &, const double &, const double &, const double &, 
                                                   const double &, const double &, const double &);


            
double interp_y1(double t, long unsigned int *n0) 
{
    while(pt_t_ar[*n0+1] < t)
        (*n0)++;
    while(pt_t_ar[*n0] > t) 
        (*n0)--;

    return hermite_y1(t, pt_t_ar[*n0],   pt_y1_ar[*n0],   pt_y1_Var[*n0], 
                              pt_t_ar[*n0+1], pt_y1_ar[*n0+1], pt_y1_Var[*n0+1]);
}

//interpolation of d(y1)/dt
double dt_interp_y1(double t, long unsigned int *n0) 
{
    while(pt_t_ar[*n0+1] < t)
        (*n0)++;
    while(pt_t_ar[*n0] > t) 
        (*n0)--;

    return dt_hermite_y1(t, pt_t_ar[*n0],   pt_y1_ar[*n0],   pt_y1_Var[*n0], 
                              pt_t_ar[*n0+1], pt_y1_ar[*n0+1], pt_y1_Var[*n0+1]);
}

//hermite interpolation
inline double hermite_y1(const double &t, const double &tn, const double &Xn, const double &Vn, 
                                     const double &tnp1, const double &Xnp1, const double &Vnp1) 
{
    double h = tnp1 - tn;
    double s = (t - tn) / h;

    return (1.0 + 2 * s) * SQUARE(s-1.0) * Xn + (3.0 - 2 * s) * SQUARE(s) * Xnp1 + h * s * SQUARE(s-1.0) *Vn + h * (s - 1) * SQUARE(s) *Vnp1;
}

inline double dt_hermite_y1(const double &t, const double &tn, const double &Xn, const double &Vn, 
                                     const double &tnp1, const double &Xnp1, const double &Vnp1) 
{
    double h = tnp1 - tn;
    double s = (t - tn) / h;

    return (1.0-4.0*s+3.0*SQUARE(s))*Vn + s*(3.0*s-2.0)*Vnp1 + 6.0*(s-1.0)*s*(Xn-Xnp1)/h;
}

        
double interp_y3(double t, long unsigned int *n0) 
{
    while(pt_t_ar[*n0+1] < t)
        (*n0)++;
    while(pt_t_ar[*n0] > t) 
        (*n0)--;

    return hermite_y3(t, pt_t_ar[*n0],   pt_y3_ar[*n0],   pt_y3_Var[*n0], 
                              pt_t_ar[*n0+1], pt_y3_ar[*n0+1], pt_y3_Var[*n0+1]);
}

//interpolation of d(y3)/dt
double dt_interp_y3(double t, long unsigned int *n0) 
{
    while(pt_t_ar[*n0+1] < t)
        (*n0)++;
    while(pt_t_ar[*n0] > t) 
        (*n0)--;

    return dt_hermite_y3(t, pt_t_ar[*n0],   pt_y3_ar[*n0],   pt_y3_Var[*n0], 
                              pt_t_ar[*n0+1], pt_y3_ar[*n0+1], pt_y3_Var[*n0+1]);
}

//hermite interpolation
inline double hermite_y3(const double &t, const double &tn, const double &Xn, const double &Vn, 
                                     const double &tnp1, const double &Xnp1, const double &Vnp1) 
{
    double h = tnp1 - tn;
    double s = (t - tn) / h;

    return (1.0 + 2 * s) * SQUARE(s-1.0) * Xn + (3.0 - 2 * s) * SQUARE(s) * Xnp1 + h * s * SQUARE(s-1.0) *Vn + h * (s - 1) * SQUARE(s) *Vnp1;
}

inline double dt_hermite_y3(const double &t, const double &tn, const double &Xn, const double &Vn, 
                                     const double &tnp1, const double &Xnp1, const double &Vnp1) 
{
    double h = tnp1 - tn;
    double s = (t - tn) / h;

    return (1.0-4.0*s+3.0*SQUARE(s))*Vn + s*(3.0*s-2.0)*Vnp1 + 6.0*(s-1.0)*s*(Xn-Xnp1)/h;
}

        
double interp_y2(double t, long unsigned int *n0) 
{
    while(pt_t_ar[*n0+1] < t)
        (*n0)++;
    while(pt_t_ar[*n0] > t) 
        (*n0)--;

    return hermite_y2(t, pt_t_ar[*n0],   pt_y2_ar[*n0],   pt_y2_Var[*n0], 
                              pt_t_ar[*n0+1], pt_y2_ar[*n0+1], pt_y2_Var[*n0+1]);
}

//interpolation of d(y2)/dt
double dt_interp_y2(double t, long unsigned int *n0) 
{
    while(pt_t_ar[*n0+1] < t)
        (*n0)++;
    while(pt_t_ar[*n0] > t) 
        (*n0)--;

    return dt_hermite_y2(t, pt_t_ar[*n0],   pt_y2_ar[*n0],   pt_y2_Var[*n0], 
                              pt_t_ar[*n0+1], pt_y2_ar[*n0+1], pt_y2_Var[*n0+1]);
}

//hermite interpolation
inline double hermite_y2(const double &t, const double &tn, const double &Xn, const double &Vn, 
                                     const double &tnp1, const double &Xnp1, const double &Vnp1) 
{
    double h = tnp1 - tn;
    double s = (t - tn) / h;

    return (1.0 + 2 * s) * SQUARE(s-1.0) * Xn + (3.0 - 2 * s) * SQUARE(s) * Xnp1 + h * s * SQUARE(s-1.0) *Vn + h * (s - 1) * SQUARE(s) *Vnp1;
}

inline double dt_hermite_y2(const double &t, const double &tn, const double &Xn, const double &Vn, 
                                     const double &tnp1, const double &Xnp1, const double &Vnp1) 
{
    double h = tnp1 - tn;
    double s = (t - tn) / h;

    return (1.0-4.0*s+3.0*SQUARE(s))*Vn + s*(3.0*s-2.0)*Vnp1 + 6.0*(s-1.0)*s*(Xn-Xnp1)/h;
}

        
double interp_y5(double t, long unsigned int *n0) 
{
    while(pt_t_ar[*n0+1] < t)
        (*n0)++;
    while(pt_t_ar[*n0] > t) 
        (*n0)--;

    return hermite_y5(t, pt_t_ar[*n0],   pt_y5_ar[*n0],   pt_y5_Var[*n0], 
                              pt_t_ar[*n0+1], pt_y5_ar[*n0+1], pt_y5_Var[*n0+1]);
}

//interpolation of d(y5)/dt
double dt_interp_y5(double t, long unsigned int *n0) 
{
    while(pt_t_ar[*n0+1] < t)
        (*n0)++;
    while(pt_t_ar[*n0] > t) 
        (*n0)--;

    return dt_hermite_y5(t, pt_t_ar[*n0],   pt_y5_ar[*n0],   pt_y5_Var[*n0], 
                              pt_t_ar[*n0+1], pt_y5_ar[*n0+1], pt_y5_Var[*n0+1]);
}

//hermite interpolation
inline double hermite_y5(const double &t, const double &tn, const double &Xn, const double &Vn, 
                                     const double &tnp1, const double &Xnp1, const double &Vnp1) 
{
    double h = tnp1 - tn;
    double s = (t - tn) / h;

    return (1.0 + 2 * s) * SQUARE(s-1.0) * Xn + (3.0 - 2 * s) * SQUARE(s) * Xnp1 + h * s * SQUARE(s-1.0) *Vn + h * (s - 1) * SQUARE(s) *Vnp1;
}

inline double dt_hermite_y5(const double &t, const double &tn, const double &Xn, const double &Vn, 
                                     const double &tnp1, const double &Xnp1, const double &Vnp1) 
{
    double h = tnp1 - tn;
    double s = (t - tn) / h;

    return (1.0-4.0*s+3.0*SQUARE(s))*Vn + s*(3.0*s-2.0)*Vnp1 + 6.0*(s-1.0)*s*(Xn-Xnp1)/h;
}

        
double interp_y4(double t, long unsigned int *n0) 
{
    while(pt_t_ar[*n0+1] < t)
        (*n0)++;
    while(pt_t_ar[*n0] > t) 
        (*n0)--;

    return hermite_y4(t, pt_t_ar[*n0],   pt_y4_ar[*n0],   pt_y4_Var[*n0], 
                              pt_t_ar[*n0+1], pt_y4_ar[*n0+1], pt_y4_Var[*n0+1]);
}

//interpolation of d(y4)/dt
double dt_interp_y4(double t, long unsigned int *n0) 
{
    while(pt_t_ar[*n0+1] < t)
        (*n0)++;
    while(pt_t_ar[*n0] > t) 
        (*n0)--;

    return dt_hermite_y4(t, pt_t_ar[*n0],   pt_y4_ar[*n0],   pt_y4_Var[*n0], 
                              pt_t_ar[*n0+1], pt_y4_ar[*n0+1], pt_y4_Var[*n0+1]);
}

//hermite interpolation
inline double hermite_y4(const double &t, const double &tn, const double &Xn, const double &Vn, 
                                     const double &tnp1, const double &Xnp1, const double &Vnp1) 
{
    double h = tnp1 - tn;
    double s = (t - tn) / h;

    return (1.0 + 2 * s) * SQUARE(s-1.0) * Xn + (3.0 - 2 * s) * SQUARE(s) * Xnp1 + h * s * SQUARE(s-1.0) *Vn + h * (s - 1) * SQUARE(s) *Vnp1;
}

inline double dt_hermite_y4(const double &t, const double &tn, const double &Xn, const double &Vn, 
                                     const double &tnp1, const double &Xnp1, const double &Vnp1) 
{
    double h = tnp1 - tn;
    double s = (t - tn) / h;

    return (1.0-4.0*s+3.0*SQUARE(s))*Vn + s*(3.0*s-2.0)*Vnp1 + 6.0*(s-1.0)*s*(Xn-Xnp1)/h;
}

        


#ifdef MANUAL
int main()
{
double dtmin = 0.0001;
double dtmax = 0.1;
double tfinal = 1.0;
double RelTol = 1.0E-6;
double AbsTol = 1.0E-8;
int chunk = 10000;
int nstart = 101;
double dt0 = 0.01;
double maxdelay = 1; // Set the maximum delay here !!!
long unsigned int MaxIter = 10000000;
int NumOfDiscont = 4;
double discont[4] = {maxdelay, 2*maxdelay, 3*maxdelay, tfinal};

#endif

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
LIInt1 = SIM_n;
LIInt2 = SIM_n;


pt_y1_ar  = (double*) malloc((SIM_n+chunk) * sizeof(double));
pt_y1_Var = (double*) malloc((SIM_n+chunk) * sizeof(double));

            

pt_y3_ar  = (double*) malloc((SIM_n+chunk) * sizeof(double));
pt_y3_Var = (double*) malloc((SIM_n+chunk) * sizeof(double));

            

pt_y2_ar  = (double*) malloc((SIM_n+chunk) * sizeof(double));
pt_y2_Var = (double*) malloc((SIM_n+chunk) * sizeof(double));

            

pt_y5_ar  = (double*) malloc((SIM_n+chunk) * sizeof(double));
pt_y5_Var = (double*) malloc((SIM_n+chunk) * sizeof(double));

            

pt_y4_ar  = (double*) malloc((SIM_n+chunk) * sizeof(double));
pt_y4_Var = (double*) malloc((SIM_n+chunk) * sizeof(double));

            
pt_t_ar = (double *) malloc((SIM_n+chunk) * sizeof(double));

#ifndef MANUAL
        
for(i = 0; i < nstart+1; i++) {
    pt_y1_ar[i]  = histy1_ar[i];
    pt_y1_Var[i] = Vhisty1_ar[i];
}
            
for(i = 0; i < nstart+1; i++) {
    pt_y3_ar[i]  = histy3_ar[i];
    pt_y3_Var[i] = Vhisty3_ar[i];
}
            
for(i = 0; i < nstart+1; i++) {
    pt_y2_ar[i]  = histy2_ar[i];
    pt_y2_Var[i] = Vhisty2_ar[i];
}
            
for(i = 0; i < nstart+1; i++) {
    pt_y5_ar[i]  = histy5_ar[i];
    pt_y5_Var[i] = Vhisty5_ar[i];
}
            
for(i = 0; i < nstart+1; i++) {
    pt_y4_ar[i]  = histy4_ar[i];
    pt_y4_Var[i] = Vhisty4_ar[i];
}
            
for(i = 0; i < nstart+1; i++) 
    pt_t_ar[i] = Thist_ar[i];
#endif

#ifdef MANUAL
for(i = 0; i < nstart+1; i++) 
    pt_t_ar[i]  = -maxdelay*(nstart-i)/nstart; 

/* set the history here when running generated code directly */
 
for(i = 0; i < nstart+1; i++) {
    pt_y1_ar[i]  = exp(pt_t_ar[i]+1); // history value for the variable
    pt_y1_Var[i] = exp(pt_t_ar[i]+1);; // history of the derivatives (0.0 if constant history)
}
 
for(i = 0; i < nstart+1; i++) {
    pt_y3_ar[i]  = sin(pt_t_ar[i]+1); // history value for the variable
    pt_y3_Var[i] = cos(pt_t_ar[i]+1); // history of the derivatives (0.0 if constant history)
}
 
for(i = 0; i < nstart+1; i++) {
    pt_y2_ar[i]  = exp(pt_t_ar[i]+0.5);; // history value for the variable
    pt_y2_Var[i] = exp(pt_t_ar[i]+0.5);; // history of the derivatives (0.0 if constant history)
}
 
for(i = 0; i < nstart+1; i++) {
    pt_y5_ar[i]  = pt_y1_ar[i]; // history value for the variable
    pt_y5_Var[i] = pt_y1_Var[i]; // history of the derivatives (0.0 if constant history)
}
 
for(i = 0; i < nstart+1; i++) {
    pt_y4_ar[i]  = pt_y1_ar[i] ; // history value for the variable
    pt_y4_Var[i] = pt_y1_Var[i]; // history of the derivatives (0.0 if constant history)
}

#endif

        
double k1y1, k2y1, k3y1, k4y1;
double TEMPy1;
double ERRORy1;

double k1y3, k2y3, k3y3, k4y3;
double TEMPy3;
double ERRORy3;

double k1y2, k2y2, k3y2, k4y2;
double TEMPy2;
double ERRORy2;

double k1y5, k2y5, k3y5, k4y5;
double TEMPy5;
double ERRORy5;

double k1y4, k2y4, k3y4, k4y4;
double TEMPy4;
double ERRORy4;
//k1 need to be calculated only for the first step
//due to the FSAL property k1(n+1)=k4(n)
	k1y1 = interp_y5(t -1, &LIInt2) +interp_y3(t -1, &LIInt2) ;
	k1y3 = interp_y3(t -1, &LIInt2) +interp_y1(t -0.5, &LIInt1) ;
	k1y2 = interp_y1(t -1, &LIInt2) +interp_y2(t -0.5, &LIInt1) ;
	k1y5 = interp_y1(t -1, &LIInt2) ;
	k1y4 = interp_y5(t -1, &LIInt2) *interp_y4(t -1, &LIInt2) ;

while((t <= tfinal || hitdsc) && SIM_n-nstart <= MaxIter) {

	t += dt * 0.5;
	k2y1 = interp_y5(t -1, &LIInt2) +interp_y3(t -1, &LIInt2) ;
	k2y3 = interp_y3(t -1, &LIInt2) +interp_y1(t -0.5, &LIInt1) ;
	k2y2 = interp_y1(t -1, &LIInt2) +interp_y2(t -0.5, &LIInt1) ;
	k2y5 = interp_y1(t -1, &LIInt2) ;
	k2y4 = interp_y5(t -1, &LIInt2) *interp_y4(t -1, &LIInt2) ;
	t += dt * 0.25;
	k3y1 = interp_y5(t -1, &LIInt2) +interp_y3(t -1, &LIInt2) ;
	k3y3 = interp_y3(t -1, &LIInt2) +interp_y1(t -0.5, &LIInt1) ;
	k3y2 = interp_y1(t -1, &LIInt2) +interp_y2(t -0.5, &LIInt1) ;
	k3y5 = interp_y1(t -1, &LIInt2) ;
	k3y4 = interp_y5(t -1, &LIInt2) *interp_y4(t -1, &LIInt2) ;
	TEMPy1 = pt_y1_ar[SIM_n] + dt * 1.0/9.0 * (2.0*k1y1 + 3.0*k2y1 + 4.0*k3y1);
	TEMPy3 = pt_y3_ar[SIM_n] + dt * 1.0/9.0 * (2.0*k1y3 + 3.0*k2y3 + 4.0*k3y3);
	TEMPy2 = pt_y2_ar[SIM_n] + dt * 1.0/9.0 * (2.0*k1y2 + 3.0*k2y2 + 4.0*k3y2);
	TEMPy5 = pt_y5_ar[SIM_n] + dt * 1.0/9.0 * (2.0*k1y5 + 3.0*k2y5 + 4.0*k3y5);
	TEMPy4 = pt_y4_ar[SIM_n] + dt * 1.0/9.0 * (2.0*k1y4 + 3.0*k2y4 + 4.0*k3y4);
	t += dt * 0.25;
	k4y1 = interp_y5(t -1, &LIInt2) +interp_y3(t -1, &LIInt2) ;
	ERRORy1 = dt/72.0 * (-5.0*k1y1 + 6.0*k2y1 + 8.0*k3y1 - 9.0*k4y1);
	k4y3 = interp_y3(t -1, &LIInt2) +interp_y1(t -0.5, &LIInt1) ;
	ERRORy3 = dt/72.0 * (-5.0*k1y3 + 6.0*k2y3 + 8.0*k3y3 - 9.0*k4y3);
	k4y2 = interp_y1(t -1, &LIInt2) +interp_y2(t -0.5, &LIInt1) ;
	ERRORy2 = dt/72.0 * (-5.0*k1y2 + 6.0*k2y2 + 8.0*k3y2 - 9.0*k4y2);
	k4y5 = interp_y1(t -1, &LIInt2) ;
	ERRORy5 = dt/72.0 * (-5.0*k1y5 + 6.0*k2y5 + 8.0*k3y5 - 9.0*k4y5);
	k4y4 = interp_y5(t -1, &LIInt2) *interp_y4(t -1, &LIInt2) ;
	ERRORy4 = dt/72.0 * (-5.0*k1y4 + 6.0*k2y4 + 8.0*k3y4 - 9.0*k4y4);
	RelErr = 0.0;
	ERRORy1 = ERRORy1/MAX( MAX(ABSy1(pt_y1_ar[SIM_n]), ABSy1(TEMPy1)), thresh);

	ERRORy3 = ERRORy3/MAX( MAX(ABSy3(pt_y3_ar[SIM_n]), ABSy3(TEMPy3)), thresh);

	ERRORy2 = ERRORy2/MAX( MAX(ABSy2(pt_y2_ar[SIM_n]), ABSy2(TEMPy2)), thresh);

	ERRORy5 = ERRORy5/MAX( MAX(ABSy5(pt_y5_ar[SIM_n]), ABSy5(TEMPy5)), thresh);

	ERRORy4 = ERRORy4/MAX( MAX(ABSy4(pt_y4_ar[SIM_n]), ABSy4(TEMPy4)), thresh);

	RelErr = MAX(RelErr, ABSy1(ERRORy1));
	RelErr = MAX(RelErr, ABSy3(ERRORy3));
	RelErr = MAX(RelErr, ABSy2(ERRORy2));
	RelErr = MAX(RelErr, ABSy5(ERRORy5));
	RelErr = MAX(RelErr, ABSy4(ERRORy4));
	if(RelErr <= RelTol || TakingMinStep ) {
		pt_y1_ar[SIM_n+1] = TEMPy1;
		pt_y1_Var[SIM_n+1] = k4y1;
		k1y1 = k4y1; //FSAL
		pt_y3_ar[SIM_n+1] = TEMPy3;
		pt_y3_Var[SIM_n+1] = k4y3;
		k1y3 = k4y3; //FSAL
		pt_y2_ar[SIM_n+1] = TEMPy2;
		pt_y2_Var[SIM_n+1] = k4y2;
		k1y2 = k4y2; //FSAL
		pt_y5_ar[SIM_n+1] = TEMPy5;
		pt_y5_Var[SIM_n+1] = k4y5;
		k1y5 = k4y5; //FSAL
		pt_y4_ar[SIM_n+1] = TEMPy4;
		pt_y4_Var[SIM_n+1] = k4y4;
		k1y4 = k4y4; //FSAL

        pt_t_ar[SIM_n+1] = t;
        SIM_n++;
        if(SIM_n - nstart > MaxIter) {
            std::cerr << "Warning: MaxIter reached! EndTime of simulation: " << t << std::endl << std::flush;
        }
        //std::cout << "pass: " << pow(RelTol/RelErr, 0.3333333333333) << std::endl;
        dt = dt * MAX(0.5, 0.8*pow(RelTol/RelErr, 0.3333333333333));

        // hit discontinuities
        hitdsc = false;
        if(nextdsc<NumOfDiscont) {
            dist = discont[nextdsc] - t;
            //std::cout << t << "	" << discont[nextdsc] << "	" << dist << std::endl;
            if(dist <= MIN(1.1*dt, dtmax)) {
                dt = dist;
                nextdsc++;
                hitdsc=true;
            }
            else if(dist <= 2*dt) {
                dt = 0.5 * dist;
            }
        }

    } else {
        //std::cout << "not passed" << std::endl;
        t-= dt;
        dt = 0.5*dt;
    }
    
    if(dt < dtmin && !hitdsc)  {
        //TODO: fix this    
        //if(NumberOfMinSteps == 0)
        //    std::cerr << "Warning: step size very small" << std::endl;
        NumberOfMinSteps++;
        TakingMinStep = true;
        dt = dtmin;
    } else {
        TakingMinStep = false;
    }
    
    if(dt > dtmax) 
        dt = dtmax;

            
    //grow arrays if they are too small
    if(SIM_n+1 == SIM_size)
    {
        SIM_size += chunk;

        double *p;
        p = (double *) realloc(pt_t_ar, (SIM_size) * sizeof(double));
        if (!p) {
            std::cout << "realloc fail, there is probably not enough memory" << std::endl;
            exit(1);
        } 
        pt_t_ar = p;
            
        double *py1;
        py1 = (double *) realloc(pt_y1_ar, (SIM_size) * sizeof(double));
        if (!py1) {
            std::cout << "realloc fail, there is probably not enough memory" << std::endl;
            exit(1);
        } 
        pt_y1_ar = py1;

        py1 = (double *) realloc(pt_y1_Var, (SIM_size) * sizeof(double));
        if (!py1) {
            std::cout << "realloc fail, there is probably not enough memory" << std::endl;
            exit(1);
        } 
        pt_y1_Var = py1;
            
        double *py3;
        py3 = (double *) realloc(pt_y3_ar, (SIM_size) * sizeof(double));
        if (!py3) {
            std::cout << "realloc fail, there is probably not enough memory" << std::endl;
            exit(1);
        } 
        pt_y3_ar = py3;

        py3 = (double *) realloc(pt_y3_Var, (SIM_size) * sizeof(double));
        if (!py3) {
            std::cout << "realloc fail, there is probably not enough memory" << std::endl;
            exit(1);
        } 
        pt_y3_Var = py3;
            
        double *py2;
        py2 = (double *) realloc(pt_y2_ar, (SIM_size) * sizeof(double));
        if (!py2) {
            std::cout << "realloc fail, there is probably not enough memory" << std::endl;
            exit(1);
        } 
        pt_y2_ar = py2;

        py2 = (double *) realloc(pt_y2_Var, (SIM_size) * sizeof(double));
        if (!py2) {
            std::cout << "realloc fail, there is probably not enough memory" << std::endl;
            exit(1);
        } 
        pt_y2_Var = py2;
            
        double *py5;
        py5 = (double *) realloc(pt_y5_ar, (SIM_size) * sizeof(double));
        if (!py5) {
            std::cout << "realloc fail, there is probably not enough memory" << std::endl;
            exit(1);
        } 
        pt_y5_ar = py5;

        py5 = (double *) realloc(pt_y5_Var, (SIM_size) * sizeof(double));
        if (!py5) {
            std::cout << "realloc fail, there is probably not enough memory" << std::endl;
            exit(1);
        } 
        pt_y5_Var = py5;
            
        double *py4;
        py4 = (double *) realloc(pt_y4_ar, (SIM_size) * sizeof(double));
        if (!py4) {
            std::cout << "realloc fail, there is probably not enough memory" << std::endl;
            exit(1);
        } 
        pt_y4_ar = py4;

        py4 = (double *) realloc(pt_y4_Var, (SIM_size) * sizeof(double));
        if (!py4) {
            std::cout << "realloc fail, there is probably not enough memory" << std::endl;
            exit(1);
        } 
        pt_y4_Var = py4;
            
    }
}
double *p;
p = (double *) realloc(pt_t_ar, (SIM_n) * sizeof(double));
if (!p) 
    std::cout << "realloc fail when shrinking arrays" << std::endl;
else
    pt_t_ar = p;


double *py1;
py1 = (double *) realloc(pt_y1_ar, (SIM_n) * sizeof(double));
if (!py1) 
    std::cout << "realloc fail when shrinking arrays" << std::endl;
else
    pt_y1_ar = py1;

py1 = (double *) realloc(pt_y1_Var, (SIM_n) * sizeof(double));
if (!py1) 
    std::cout << "realloc fail when shrinking arrays" << std::endl;
else
    pt_y1_Var = py1;

            
double *py3;
py3 = (double *) realloc(pt_y3_ar, (SIM_n) * sizeof(double));
if (!py3) 
    std::cout << "realloc fail when shrinking arrays" << std::endl;
else
    pt_y3_ar = py3;

py3 = (double *) realloc(pt_y3_Var, (SIM_n) * sizeof(double));
if (!py3) 
    std::cout << "realloc fail when shrinking arrays" << std::endl;
else
    pt_y3_Var = py3;

            
double *py2;
py2 = (double *) realloc(pt_y2_ar, (SIM_n) * sizeof(double));
if (!py2) 
    std::cout << "realloc fail when shrinking arrays" << std::endl;
else
    pt_y2_ar = py2;

py2 = (double *) realloc(pt_y2_Var, (SIM_n) * sizeof(double));
if (!py2) 
    std::cout << "realloc fail when shrinking arrays" << std::endl;
else
    pt_y2_Var = py2;

            
double *py5;
py5 = (double *) realloc(pt_y5_ar, (SIM_n) * sizeof(double));
if (!py5) 
    std::cout << "realloc fail when shrinking arrays" << std::endl;
else
    pt_y5_ar = py5;

py5 = (double *) realloc(pt_y5_Var, (SIM_n) * sizeof(double));
if (!py5) 
    std::cout << "realloc fail when shrinking arrays" << std::endl;
else
    pt_y5_Var = py5;

            
double *py4;
py4 = (double *) realloc(pt_y4_ar, (SIM_n) * sizeof(double));
if (!py4) 
    std::cout << "realloc fail when shrinking arrays" << std::endl;
else
    pt_y4_ar = py4;

py4 = (double *) realloc(pt_y4_Var, (SIM_n) * sizeof(double));
if (!py4) 
    std::cout << "realloc fail when shrinking arrays" << std::endl;
else
    pt_y4_Var = py4;


#ifdef MANUAL
for(i = 0; i < SIM_n; i++) 
    std:: cout << pt_t_ar[i] << "	" << pt_y1_ar[i] << "	" << pt_y3_ar[i] << "	" << pt_y2_ar[i] << "	" << pt_y5_ar[i] << "	" << pt_y4_ar[i] << std::endl;
    return 0;
}
#endif

// This hash is included to detect a change in
// the support code and recompile in this case
// 142f65686fd42f8450968646c34501f2

