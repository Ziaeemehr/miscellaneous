
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
#define ABSx2(X) (fabs(X))
#define ABSx1(X) (fabs(X))
#define ABSy2(X) (fabs(X))

/* positions of lags in the arrays */
long unsigned int n_c883993f050c1623becf60b8ca179ab5;
/* arrays holding the variabls */
double *pt_y1_ar;
double *pt_y1_Var;
double *pt_x2_ar;
double *pt_x2_Var;
double *pt_x1_ar;
double *pt_x1_Var;
double *pt_y2_ar;
double *pt_y2_Var;

inline double hermite_y1(const double &, const double &, const double &, const double &, 
                                                   const double &, const double &, const double &);
inline double dt_hermite_y1(const double &, const double &, const double &, const double &, 
                                                   const double &, const double &, const double &);


            
inline double hermite_x2(const double &, const double &, const double &, const double &, 
                                                   const double &, const double &, const double &);
inline double dt_hermite_x2(const double &, const double &, const double &, const double &, 
                                                   const double &, const double &, const double &);


            
inline double hermite_x1(const double &, const double &, const double &, const double &, 
                                                   const double &, const double &, const double &);
inline double dt_hermite_x1(const double &, const double &, const double &, const double &, 
                                                   const double &, const double &, const double &);


            
inline double hermite_y2(const double &, const double &, const double &, const double &, 
                                                   const double &, const double &, const double &);
inline double dt_hermite_y2(const double &, const double &, const double &, const double &, 
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

        
double interp_x2(double t, long unsigned int *n0) 
{
    while(pt_t_ar[*n0+1] < t)
        (*n0)++;
    while(pt_t_ar[*n0] > t) 
        (*n0)--;

    return hermite_x2(t, pt_t_ar[*n0],   pt_x2_ar[*n0],   pt_x2_Var[*n0], 
                              pt_t_ar[*n0+1], pt_x2_ar[*n0+1], pt_x2_Var[*n0+1]);
}

//interpolation of d(x2)/dt
double dt_interp_x2(double t, long unsigned int *n0) 
{
    while(pt_t_ar[*n0+1] < t)
        (*n0)++;
    while(pt_t_ar[*n0] > t) 
        (*n0)--;

    return dt_hermite_x2(t, pt_t_ar[*n0],   pt_x2_ar[*n0],   pt_x2_Var[*n0], 
                              pt_t_ar[*n0+1], pt_x2_ar[*n0+1], pt_x2_Var[*n0+1]);
}

//hermite interpolation
inline double hermite_x2(const double &t, const double &tn, const double &Xn, const double &Vn, 
                                     const double &tnp1, const double &Xnp1, const double &Vnp1) 
{
    double h = tnp1 - tn;
    double s = (t - tn) / h;

    return (1.0 + 2 * s) * SQUARE(s-1.0) * Xn + (3.0 - 2 * s) * SQUARE(s) * Xnp1 + h * s * SQUARE(s-1.0) *Vn + h * (s - 1) * SQUARE(s) *Vnp1;
}

inline double dt_hermite_x2(const double &t, const double &tn, const double &Xn, const double &Vn, 
                                     const double &tnp1, const double &Xnp1, const double &Vnp1) 
{
    double h = tnp1 - tn;
    double s = (t - tn) / h;

    return (1.0-4.0*s+3.0*SQUARE(s))*Vn + s*(3.0*s-2.0)*Vnp1 + 6.0*(s-1.0)*s*(Xn-Xnp1)/h;
}

        
double interp_x1(double t, long unsigned int *n0) 
{
    while(pt_t_ar[*n0+1] < t)
        (*n0)++;
    while(pt_t_ar[*n0] > t) 
        (*n0)--;

    return hermite_x1(t, pt_t_ar[*n0],   pt_x1_ar[*n0],   pt_x1_Var[*n0], 
                              pt_t_ar[*n0+1], pt_x1_ar[*n0+1], pt_x1_Var[*n0+1]);
}

//interpolation of d(x1)/dt
double dt_interp_x1(double t, long unsigned int *n0) 
{
    while(pt_t_ar[*n0+1] < t)
        (*n0)++;
    while(pt_t_ar[*n0] > t) 
        (*n0)--;

    return dt_hermite_x1(t, pt_t_ar[*n0],   pt_x1_ar[*n0],   pt_x1_Var[*n0], 
                              pt_t_ar[*n0+1], pt_x1_ar[*n0+1], pt_x1_Var[*n0+1]);
}

//hermite interpolation
inline double hermite_x1(const double &t, const double &tn, const double &Xn, const double &Vn, 
                                     const double &tnp1, const double &Xnp1, const double &Vnp1) 
{
    double h = tnp1 - tn;
    double s = (t - tn) / h;

    return (1.0 + 2 * s) * SQUARE(s-1.0) * Xn + (3.0 - 2 * s) * SQUARE(s) * Xnp1 + h * s * SQUARE(s-1.0) *Vn + h * (s - 1) * SQUARE(s) *Vnp1;
}

inline double dt_hermite_x1(const double &t, const double &tn, const double &Xn, const double &Vn, 
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

        


#ifdef MANUAL
int main()
{
double dtmin = 0.0001;
double dtmax = 0.1;
double tfinal = 100.0;
double RelTol = 1.0E-3;
double AbsTol = 1.0E-6;
int chunk = 10000;
int nstart = 101;
double dt0 = 0.01;
double maxdelay = ...; // Set the maximum delay here !!!
long unsigned int MaxIter = 10000000;
int NumOfDiscont = 4;
double discont[4] = {maxdelay, 2*maxdelay, 3*maxdelay, tfinal};
double PARa = 1.3;
double PARtau = 3.0;
double PARC = 0.5;
double PAReps = 0.01;

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
srand((unsigned)RSEED);
n_c883993f050c1623becf60b8ca179ab5 = SIM_n;


pt_y1_ar  = (double*) malloc((SIM_n+chunk) * sizeof(double));
pt_y1_Var = (double*) malloc((SIM_n+chunk) * sizeof(double));

            

pt_x2_ar  = (double*) malloc((SIM_n+chunk) * sizeof(double));
pt_x2_Var = (double*) malloc((SIM_n+chunk) * sizeof(double));

            

pt_x1_ar  = (double*) malloc((SIM_n+chunk) * sizeof(double));
pt_x1_Var = (double*) malloc((SIM_n+chunk) * sizeof(double));

            

pt_y2_ar  = (double*) malloc((SIM_n+chunk) * sizeof(double));
pt_y2_Var = (double*) malloc((SIM_n+chunk) * sizeof(double));

            
pt_t_ar = (double *) malloc((SIM_n+chunk) * sizeof(double));

#ifndef MANUAL
        
for(i = 0; i < nstart+1; i++) {
    pt_y1_ar[i]  = histy1_ar[i];
    pt_y1_Var[i] = Vhisty1_ar[i];
}
            
for(i = 0; i < nstart+1; i++) {
    pt_x2_ar[i]  = histx2_ar[i];
    pt_x2_Var[i] = Vhistx2_ar[i];
}
            
for(i = 0; i < nstart+1; i++) {
    pt_x1_ar[i]  = histx1_ar[i];
    pt_x1_Var[i] = Vhistx1_ar[i];
}
            
for(i = 0; i < nstart+1; i++) {
    pt_y2_ar[i]  = histy2_ar[i];
    pt_y2_Var[i] = Vhisty2_ar[i];
}
            
for(i = 0; i < nstart+1; i++) 
    pt_t_ar[i] = Thist_ar[i];
#endif

#ifdef MANUAL
for(i = 0; i < nstart+1; i++) 
    pt_t_ar[i]  = -maxdelay*(nstart-i)/nstart; 

/* set the history here when running generated code directly */
 
for(i = 0; i < nstart+1; i++) {
    pt_y1_ar[i]  = 0.2; // history value for the variable
    pt_y1_Var[i] = 0.0; // history of the derivatives (0.0 if constant history)
}
 
for(i = 0; i < nstart+1; i++) {
    pt_x2_ar[i]  = 0.2; // history value for the variable
    pt_x2_Var[i] = 0.0; // history of the derivatives (0.0 if constant history)
}
 
for(i = 0; i < nstart+1; i++) {
    pt_x1_ar[i]  = 0.2; // history value for the variable
    pt_x1_Var[i] = 0.0; // history of the derivatives (0.0 if constant history)
}
 
for(i = 0; i < nstart+1; i++) {
    pt_y2_ar[i]  = 0.2; // history value for the variable
    pt_y2_Var[i] = 0.0; // history of the derivatives (0.0 if constant history)
}

#endif

        
double k1y1, k2y1, k3y1, k4y1;
double TEMPy1;
double ERRORy1;

double k1x2, k2x2, k3x2, k4x2;
double TEMPx2;
double ERRORx2;

double k1x1, k2x1, k3x1, k4x1;
double TEMPx1;
double ERRORx1;

double k1y2, k2y2, k3y2, k4y2;
double TEMPy2;
double ERRORy2;
//k1 need to be calculated only for the first step
//due to the FSAL property k1(n+1)=k4(n)
	k1y1 =  pt_x1_ar[SIM_n]  +  PARa ;
	k1x2 = ( pt_x2_ar[SIM_n]  - pow( pt_x2_ar[SIM_n] ,3)/3.0 -  pt_y2_ar[SIM_n]  +  PARC *(interp_x1(t - PARtau, &n_c883993f050c1623becf60b8ca179ab5)  -  pt_x2_ar[SIM_n] ))/ PAReps ;
	k1x1 = ( pt_x1_ar[SIM_n]  - pow( pt_x1_ar[SIM_n] ,3)/3.0 -  pt_y1_ar[SIM_n]  +  PARC *(interp_x2(t - PARtau, &n_c883993f050c1623becf60b8ca179ab5)  -  pt_x1_ar[SIM_n] ))/ PAReps ;
	k1y2 =  pt_x2_ar[SIM_n]  +  PARa ;

while((t <= tfinal || hitdsc) && SIM_n-nstart <= MaxIter) {

	t += dt * 0.5;
	k2y1 =  (pt_x1_ar[SIM_n] + 0.5 * dt * k1x1)  +  PARa ;
	k2x2 = ( (pt_x2_ar[SIM_n] + 0.5 * dt * k1x2)  - pow( (pt_x2_ar[SIM_n] + 0.5 * dt * k1x2) ,3)/3.0 -  (pt_y2_ar[SIM_n] + 0.5 * dt * k1y2)  +  PARC *(interp_x1(t - PARtau, &n_c883993f050c1623becf60b8ca179ab5)  -  (pt_x2_ar[SIM_n] + 0.5 * dt * k1x2) ))/ PAReps ;
	k2x1 = ( (pt_x1_ar[SIM_n] + 0.5 * dt * k1x1)  - pow( (pt_x1_ar[SIM_n] + 0.5 * dt * k1x1) ,3)/3.0 -  (pt_y1_ar[SIM_n] + 0.5 * dt * k1y1)  +  PARC *(interp_x2(t - PARtau, &n_c883993f050c1623becf60b8ca179ab5)  -  (pt_x1_ar[SIM_n] + 0.5 * dt * k1x1) ))/ PAReps ;
	k2y2 =  (pt_x2_ar[SIM_n] + 0.5 * dt * k1x2)  +  PARa ;
	t += dt * 0.25;
	k3y1 =  (pt_x1_ar[SIM_n] + 0.75 * dt * k2x1)  +  PARa ;
	k3x2 = ( (pt_x2_ar[SIM_n] + 0.75 * dt * k2x2)  - pow( (pt_x2_ar[SIM_n] + 0.75 * dt * k2x2) ,3)/3.0 -  (pt_y2_ar[SIM_n] + 0.75 * dt * k2y2)  +  PARC *(interp_x1(t - PARtau, &n_c883993f050c1623becf60b8ca179ab5)  -  (pt_x2_ar[SIM_n] + 0.75 * dt * k2x2) ))/ PAReps ;
	k3x1 = ( (pt_x1_ar[SIM_n] + 0.75 * dt * k2x1)  - pow( (pt_x1_ar[SIM_n] + 0.75 * dt * k2x1) ,3)/3.0 -  (pt_y1_ar[SIM_n] + 0.75 * dt * k2y1)  +  PARC *(interp_x2(t - PARtau, &n_c883993f050c1623becf60b8ca179ab5)  -  (pt_x1_ar[SIM_n] + 0.75 * dt * k2x1) ))/ PAReps ;
	k3y2 =  (pt_x2_ar[SIM_n] + 0.75 * dt * k2x2)  +  PARa ;
	TEMPy1 = pt_y1_ar[SIM_n] + dt * 1.0/9.0 * (2.0*k1y1 + 3.0*k2y1 + 4.0*k3y1);
	TEMPx2 = pt_x2_ar[SIM_n] + dt * 1.0/9.0 * (2.0*k1x2 + 3.0*k2x2 + 4.0*k3x2);
	TEMPx1 = pt_x1_ar[SIM_n] + dt * 1.0/9.0 * (2.0*k1x1 + 3.0*k2x1 + 4.0*k3x1);
	TEMPy2 = pt_y2_ar[SIM_n] + dt * 1.0/9.0 * (2.0*k1y2 + 3.0*k2y2 + 4.0*k3y2);
	t += dt * 0.25;
	k4y1 =  TEMPx1  +  PARa ;
	ERRORy1 = dt/72.0 * (-5.0*k1y1 + 6.0*k2y1 + 8.0*k3y1 - 9.0*k4y1);
	k4x2 = ( TEMPx2  - pow( TEMPx2 ,3)/3.0 -  TEMPy2  +  PARC *(interp_x1(t - PARtau, &n_c883993f050c1623becf60b8ca179ab5)  -  TEMPx2 ))/ PAReps ;
	ERRORx2 = dt/72.0 * (-5.0*k1x2 + 6.0*k2x2 + 8.0*k3x2 - 9.0*k4x2);
	k4x1 = ( TEMPx1  - pow( TEMPx1 ,3)/3.0 -  TEMPy1  +  PARC *(interp_x2(t - PARtau, &n_c883993f050c1623becf60b8ca179ab5)  -  TEMPx1 ))/ PAReps ;
	ERRORx1 = dt/72.0 * (-5.0*k1x1 + 6.0*k2x1 + 8.0*k3x1 - 9.0*k4x1);
	k4y2 =  TEMPx2  +  PARa ;
	ERRORy2 = dt/72.0 * (-5.0*k1y2 + 6.0*k2y2 + 8.0*k3y2 - 9.0*k4y2);
	RelErr = 0.0;
	ERRORy1 = ERRORy1/MAX( MAX(ABSy1(pt_y1_ar[SIM_n]), ABSy1(TEMPy1)), thresh);

	ERRORx2 = ERRORx2/MAX( MAX(ABSx2(pt_x2_ar[SIM_n]), ABSx2(TEMPx2)), thresh);

	ERRORx1 = ERRORx1/MAX( MAX(ABSx1(pt_x1_ar[SIM_n]), ABSx1(TEMPx1)), thresh);

	ERRORy2 = ERRORy2/MAX( MAX(ABSy2(pt_y2_ar[SIM_n]), ABSy2(TEMPy2)), thresh);

	RelErr = MAX(RelErr, ABSy1(ERRORy1));
	RelErr = MAX(RelErr, ABSx2(ERRORx2));
	RelErr = MAX(RelErr, ABSx1(ERRORx1));
	RelErr = MAX(RelErr, ABSy2(ERRORy2));
	if(RelErr <= RelTol || TakingMinStep ) {
		pt_y1_ar[SIM_n+1] = TEMPy1;
		pt_y1_Var[SIM_n+1] = k4y1;
		k1y1 = k4y1; //FSAL
		pt_x2_ar[SIM_n+1] = TEMPx2;
		pt_x2_Var[SIM_n+1] = k4x2;
		k1x2 = k4x2; //FSAL
		pt_x1_ar[SIM_n+1] = TEMPx1;
		pt_x1_Var[SIM_n+1] = k4x1;
		k1x1 = k4x1; //FSAL
		pt_y2_ar[SIM_n+1] = TEMPy2;
		pt_y2_Var[SIM_n+1] = k4y2;
		k1y2 = k4y2; //FSAL

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
            
        double *px2;
        px2 = (double *) realloc(pt_x2_ar, (SIM_size) * sizeof(double));
        if (!px2) {
            std::cout << "realloc fail, there is probably not enough memory" << std::endl;
            exit(1);
        } 
        pt_x2_ar = px2;

        px2 = (double *) realloc(pt_x2_Var, (SIM_size) * sizeof(double));
        if (!px2) {
            std::cout << "realloc fail, there is probably not enough memory" << std::endl;
            exit(1);
        } 
        pt_x2_Var = px2;
            
        double *px1;
        px1 = (double *) realloc(pt_x1_ar, (SIM_size) * sizeof(double));
        if (!px1) {
            std::cout << "realloc fail, there is probably not enough memory" << std::endl;
            exit(1);
        } 
        pt_x1_ar = px1;

        px1 = (double *) realloc(pt_x1_Var, (SIM_size) * sizeof(double));
        if (!px1) {
            std::cout << "realloc fail, there is probably not enough memory" << std::endl;
            exit(1);
        } 
        pt_x1_Var = px1;
            
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

            
double *px2;
px2 = (double *) realloc(pt_x2_ar, (SIM_n) * sizeof(double));
if (!px2) 
    std::cout << "realloc fail when shrinking arrays" << std::endl;
else
    pt_x2_ar = px2;

px2 = (double *) realloc(pt_x2_Var, (SIM_n) * sizeof(double));
if (!px2) 
    std::cout << "realloc fail when shrinking arrays" << std::endl;
else
    pt_x2_Var = px2;

            
double *px1;
px1 = (double *) realloc(pt_x1_ar, (SIM_n) * sizeof(double));
if (!px1) 
    std::cout << "realloc fail when shrinking arrays" << std::endl;
else
    pt_x1_ar = px1;

px1 = (double *) realloc(pt_x1_Var, (SIM_n) * sizeof(double));
if (!px1) 
    std::cout << "realloc fail when shrinking arrays" << std::endl;
else
    pt_x1_Var = px1;

            
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


#ifdef MANUAL
for(i = 0; i < SIM_n; i++) 
    std:: cout << pt_t_ar[i] << "	" << pt_y1_ar[i] << "	" << pt_x2_ar[i] << "	" << pt_x1_ar[i] << "	" << pt_y2_ar[i] << std::endl;
    return 0;
}
#endif

// This hash is included to detect a change in
// the support code and recompile in this case
// ecf059d7401a003e9d47a94f0dc6c3fe

