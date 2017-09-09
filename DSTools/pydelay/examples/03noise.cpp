
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


typedef std::complex<double> Complex;
const Complex ii(0.0, 1.0);
double t;
double *pt_t_ar;
long unsigned int SIM_n;
long unsigned int SIM_size;
#define ABSx(X) (fabs(X))

/* positions of lags in the arrays */
/* arrays holding the variabls */
double *pt_x_ar;
double *pt_x_Var;

inline double hermite_x(const double &, const double &, const double &, const double &, 
                                                   const double &, const double &, const double &);
inline double dt_hermite_x(const double &, const double &, const double &, const double &, 
                                                   const double &, const double &, const double &);


            
double interp_x(double t, long unsigned int *n0) 
{
    while(pt_t_ar[*n0+1] < t)
        (*n0)++;
    while(pt_t_ar[*n0] > t) 
        (*n0)--;

    return hermite_x(t, pt_t_ar[*n0],   pt_x_ar[*n0],   pt_x_Var[*n0], 
                              pt_t_ar[*n0+1], pt_x_ar[*n0+1], pt_x_Var[*n0+1]);
}

//interpolation of d(x)/dt
double dt_interp_x(double t, long unsigned int *n0) 
{
    while(pt_t_ar[*n0+1] < t)
        (*n0)++;
    while(pt_t_ar[*n0] > t) 
        (*n0)--;

    return dt_hermite_x(t, pt_t_ar[*n0],   pt_x_ar[*n0],   pt_x_Var[*n0], 
                              pt_t_ar[*n0+1], pt_x_ar[*n0+1], pt_x_Var[*n0+1]);
}

//hermite interpolation
inline double hermite_x(const double &t, const double &tn, const double &Xn, const double &Vn, 
                                     const double &tnp1, const double &Xnp1, const double &Vnp1) 
{
    double h = tnp1 - tn;
    double s = (t - tn) / h;

    return (1.0 + 2 * s) * SQUARE(s-1.0) * Xn + (3.0 - 2 * s) * SQUARE(s) * Xnp1 + h * s * SQUARE(s-1.0) *Vn + h * (s - 1) * SQUARE(s) *Vnp1;
}

inline double dt_hermite_x(const double &t, const double &tn, const double &Xn, const double &Vn, 
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

    if(iset==0) 
    {
        do 
        {
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
    else 
    {
        iset=0;
        return gset;
    }
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
double PARD = 0.01;

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


pt_x_ar  = (double*) malloc((SIM_n+chunk) * sizeof(double));
pt_x_Var = (double*) malloc((SIM_n+chunk) * sizeof(double));          
pt_t_ar = (double *) malloc((SIM_n+chunk) * sizeof(double));


#ifdef MANUAL
for(i = 0; i < nstart+1; i++) 
    pt_t_ar[i]  = -maxdelay*(nstart-i)/nstart; 

/* set the history here when running generated code directly */
 
for(i = 0; i < nstart+1; i++) {
    pt_x_ar[i]  = 0.0; // history value for the variable
    pt_x_Var[i] = 0.0; // history of the derivatives (0.0 if constant history)
}

#endif

        
double k1x, k2x, k3x, k4x;
double TEMPx;
double ERRORx;
//k1 need to be calculated only for the first step
//due to the FSAL property k1(n+1)=k4(n)
	k1x = - pt_x_ar[SIM_n] +0.1;

while((t <= tfinal || hitdsc) && SIM_n-nstart <= MaxIter) {

	t += dt * 0.5;
	k2x = - (pt_x_ar[SIM_n] + 0.5 * dt * k1x) +0.1;
	t += dt * 0.25;
	k3x = - (pt_x_ar[SIM_n] + 0.75 * dt * k2x) +0.1;
	TEMPx = pt_x_ar[SIM_n] + dt * 1.0/9.0 * (2.0*k1x + 3.0*k2x + 4.0*k3x);
	t += dt * 0.25;
	k4x = - TEMPx +0.1;
	ERRORx = dt/72.0 * (-5.0*k1x + 6.0*k2x + 8.0*k3x - 9.0*k4x);
	RelErr = 0.0;
	ERRORx = ERRORx/MAX( MAX(ABSx(pt_x_ar[SIM_n]), ABSx(TEMPx)), thresh);

	RelErr = MAX(RelErr, ABSx(ERRORx));
	if(RelErr <= RelTol || TakingMinStep ) {
		pt_x_ar[SIM_n+1] = TEMPx + sqrt(dt) * (  PARD *gwn() );
		pt_x_Var[SIM_n+1] = k4x;
		k1x = k4x; //FSAL

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
            
        double *px;
        px = (double *) realloc(pt_x_ar, (SIM_size) * sizeof(double));
        if (!px) {
            std::cout << "realloc fail, there is probably not enough memory" << std::endl;
            exit(1);
        } 
        pt_x_ar = px;

        px = (double *) realloc(pt_x_Var, (SIM_size) * sizeof(double));
        if (!px) {
            std::cout << "realloc fail, there is probably not enough memory" << std::endl;
            exit(1);
        } 
        pt_x_Var = px;
            
    }
}
double *p;
p = (double *) realloc(pt_t_ar, (SIM_n) * sizeof(double));
if (!p) 
    std::cout << "realloc fail when shrinking arrays" << std::endl;
else
    pt_t_ar = p;


double *px;
px = (double *) realloc(pt_x_ar, (SIM_n) * sizeof(double));
if (!px) 
    std::cout << "realloc fail when shrinking arrays" << std::endl;
else
    pt_x_ar = px;

px = (double *) realloc(pt_x_Var, (SIM_n) * sizeof(double));
if (!px) 
    std::cout << "realloc fail when shrinking arrays" << std::endl;
else
    pt_x_Var = px;

#ifdef MANUAL
for(i = 0; i < SIM_n; i++) 
    std:: cout << pt_t_ar[i] << "	" << pt_x_ar[i] << std::endl;
    return 0;
}
#endif

// This hash is included to detect a change in
// the support code and recompile in this case
// 590e65e86b95da99ca57eb7a2e86aa90

