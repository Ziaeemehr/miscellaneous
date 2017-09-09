#include<complex>
#include<math.h>
#include <time.h> 
#include<cmath>
#include<cstdlib>
#include<iostream>
#define false 0;
#define true 1;
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define SQUARE(X) ((X) * (X))
#define ABSy1(X) (fabs(X))
#define ABSy3(X) (fabs(X))
#define ABSy2(X) (fabs(X))

double t;
double *pt_t_ar;
long unsigned int SIM_n;
long unsigned int SIM_size;

/* positions of lags in the arrays */
long unsigned int plag2;
long unsigned int plag1;
/* arrays holding the variabls */
double *pt_y1_ar;
double *pt_y1_Var;
double *pt_y3_ar;
double *pt_y3_Var;
double *pt_y2_ar;
double *pt_y2_Var;

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

        
double ra01()
{  
    return(double(rand())/RAND_MAX);
}

double gwn()
{
    static int iset=0;
    static double gset;
    double fac,rsq,v1,v2;
    if(iset==0) {
        do {
            v1=2.0*ra01()-1.;
            v2=2.0*ra01()-1.;
            rsq=v1*v1+v2*v2;
        } 
        while(rsq>1.0 || rsq==0);

        fac=sqrt(-2.0*log(rsq)/rsq);
        gset=v1*fac;
        iset=1;
        return v2*fac;
    } 
    else {
        iset=0;
        return gset;
    }
}

int main() {
    
double dtmin = 0.0001;
double dtmax = 0.1;
double tfinal = 5.0;
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
double PARD = 0.1;

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
// srand(time(NULL));
srand(123);
plag2 = SIM_n;
plag1 = SIM_n;

pt_y1_ar  = (double*) malloc((SIM_n+chunk) * sizeof(double));
pt_y1_Var = (double*) malloc((SIM_n+chunk) * sizeof(double));
pt_y3_ar  = (double*) malloc((SIM_n+chunk) * sizeof(double));
pt_y3_Var = (double*) malloc((SIM_n+chunk) * sizeof(double));
pt_y2_ar  = (double*) malloc((SIM_n+chunk) * sizeof(double));
pt_y2_Var = (double*) malloc((SIM_n+chunk) * sizeof(double));
pt_t_ar   = (double*) malloc((SIM_n+chunk) * sizeof(double));

for(i = 0; i < nstart+1; i++) 
    pt_t_ar[i]  = -maxdelay*(nstart-i)/nstart; 

/* set the history here when running generated code directly */
for(i = 0; i < nstart+1; i++) {
    pt_y1_ar[i]  = 1.; // history value for the variable
    pt_y1_Var[i] = 0.0; // history of the derivatives (0.0 if constant history)
} 
for(i = 0; i < nstart+1; i++) {
    pt_y3_ar[i]  = 1.; // history value for the variable
    pt_y3_Var[i] = 0.0; // history of the derivatives (0.0 if constant history)
}
for(i = 0; i < nstart+1; i++) {
    pt_y2_ar[i]  = 1.; // history value for the variable
    pt_y2_Var[i] = 0.0; // history of the derivatives (0.0 if constant history)
}
        
double k1y1, k2y1, k3y1, k4y1;
double TEMPy1;
double ERRORy1;

double k1y3, k2y3, k3y3, k4y3;
double TEMPy3;
double ERRORy3;

double k1y2, k2y2, k3y2, k4y2;
double TEMPy2;
double ERRORy2;
//k1 need to be calculated only for the first step
//due to the FSAL property k1(n+1)=k4(n)
	k1y1 = interp_y1(t - PARtau1, &plag1) ;
	k1y2 = interp_y1(t - PARtau1, &plag1) -interp_y2(t - PARtau2, &plag2) ;
    k1y3 =  pt_y2_ar[SIM_n] -interp_y3(t - PARtau1, &plag1) ;

while((t <= tfinal || hitdsc) && SIM_n-nstart <= MaxIter) {

	t += dt * 0.5;
	k2y1 = interp_y1(t - PARtau1, &plag1) ;
	k2y2 = interp_y1(t - PARtau1, &plag1) -interp_y2(t - PARtau2, &plag2) ;
    k2y3 =  (pt_y2_ar[SIM_n] + 0.5 * dt * k1y2) -interp_y3(t - PARtau1, &plag1) ;
	t += dt * 0.25;
	k3y1 = interp_y1(t - PARtau1, &plag1) ;
	k3y2 = interp_y1(t - PARtau1, &plag1) -interp_y2(t - PARtau2, &plag2) ;
    k3y3 =  (pt_y2_ar[SIM_n] + 0.75 * dt * k2y2) -interp_y3(t - PARtau1, &plag1) ;
	TEMPy1 = pt_y1_ar[SIM_n] + dt * 1.0/9.0 * (2.0*k1y1 + 3.0*k2y1 + 4.0*k3y1);
	TEMPy2 = pt_y2_ar[SIM_n] + dt * 1.0/9.0 * (2.0*k1y2 + 3.0*k2y2 + 4.0*k3y2);
    TEMPy3 = pt_y3_ar[SIM_n] + dt * 1.0/9.0 * (2.0*k1y3 + 3.0*k2y3 + 4.0*k3y3);
	t += dt * 0.25;
	k4y1 = interp_y1(t - PARtau1, &plag1) ;
	ERRORy1 = dt/72.0 * (-5.0*k1y1 + 6.0*k2y1 + 8.0*k3y1 - 9.0*k4y1);
	k4y2 = interp_y1(t - PARtau1, &plag1) -interp_y2(t - PARtau2, &plag2) ;
	ERRORy2 = dt/72.0 * (-5.0*k1y2 + 6.0*k2y2 + 8.0*k3y2 - 9.0*k4y2);
    k4y3 =  TEMPy2 -interp_y3(t - PARtau1, &plag1) ;
	ERRORy3 = dt/72.0 * (-5.0*k1y3 + 6.0*k2y3 + 8.0*k3y3 - 9.0*k4y3);
	RelErr = 0.0;
    
	ERRORy1 = ERRORy1/MAX( MAX(ABSy1(pt_y1_ar[SIM_n]), ABSy1(TEMPy1)), thresh);
	ERRORy2 = ERRORy2/MAX( MAX(ABSy2(pt_y2_ar[SIM_n]), ABSy2(TEMPy2)), thresh);
    ERRORy3 = ERRORy3/MAX( MAX(ABSy3(pt_y3_ar[SIM_n]), ABSy3(TEMPy3)), thresh);

	RelErr = MAX(RelErr, ABSy1(ERRORy1));
	RelErr = MAX(RelErr, ABSy3(ERRORy3));
	RelErr = MAX(RelErr, ABSy2(ERRORy2));
    
	if(RelErr <= RelTol || TakingMinStep ) {
		pt_y1_ar[SIM_n+1] = TEMPy1 + sqrt(dt) * (  PARD *gwn() );
		pt_y1_Var[SIM_n+1] = k4y1;
		k1y1 = k4y1; //FSAL
		pt_y2_ar[SIM_n+1] = TEMPy2 + sqrt(dt) * (  PARD *gwn() );
		pt_y2_Var[SIM_n+1] = k4y2;
		k1y2 = k4y2; //FSAL
		pt_y3_ar[SIM_n+1] = TEMPy3 + sqrt(dt) * (  PARD *gwn() );
		pt_y3_Var[SIM_n+1] = k4y3;
		k1y3 = k4y3; //FSAL

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

for(i = 0; i < SIM_n; i++) 
    std:: cout << pt_t_ar[i] << "	" << pt_y1_ar[i] << "	" << pt_y3_ar[i] << "	" << pt_y2_ar[i] << std::endl;
    return 0;
}

// This hash is included to detect a change in
// the support code and recompile in this case
// e83c441f1ebbffeda28a70a92d2ebb8d

