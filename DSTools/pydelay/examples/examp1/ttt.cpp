
#include<complex>
#include<math.h>
#include<cmath>
#include<cstdlib>
#include<iostream>

/****** uncomment the following line to run generated source code directly ***************/
//#define MANUAL

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

/* positions of lags in the arrays */
long unsigned int plag1;
long unsigned int plag0;
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
double PARtau2 = 0.2;
double PARtau1 = 1.0;

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
plag1 = SIM_n;
plag0 = SIM_n;


pt_y1_ar  = (double*) malloc((SIM_n+chunk) * sizeof(double));
pt_y1_Var = (double*) malloc((SIM_n+chunk) * sizeof(double));

            

pt_y3_ar  = (double*) malloc((SIM_n+chunk) * sizeof(double));
pt_y3_Var = (double*) malloc((SIM_n+chunk) * sizeof(double));

            

pt_y2_ar  = (double*) malloc((SIM_n+chunk) * sizeof(double));
pt_y2_Var = (double*) malloc((SIM_n+chunk) * sizeof(double));

            
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
    pt_y3_ar[i]  = 0.2; // history value for the variable
    pt_y3_Var[i] = 0.0; // history of the derivatives (0.0 if constant history)
}
 
for(i = 0; i < nstart+1; i++) {
    pt_y2_ar[i]  = 0.2; // history value for the variable
    pt_y2_Var[i] = 0.0; // history of the derivatives (0.0 if constant history)
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
//k1 need to be calculated only for the first step
//due to the FSAL property k1(n+1)=k4(n)
	k1y1 = interp_y1(t - PARtau1, &plag0) ;
	k1y2 = interp_y1(t - PARtau1, &plag0) +interp_y2(t - PARtau2, &plag1) ;
	k1y3 =  pt_y2_ar[SIM_n] ;

while((t <= tfinal || hitdsc) && SIM_n-nstart <= MaxIter) {

	t += dt * 0.5;
	k2y1 = interp_y1(t - PARtau1, &plag0) ;
	k2y2 = interp_y1(t - PARtau1, &plag0) +interp_y2(t - PARtau2, &plag1) ;
	k2y3 =  (pt_y2_ar[SIM_n] + 0.5 * dt * k1y2) ;
	t += dt * 0.25;
	k3y1 = interp_y1(t - PARtau1, &plag0) ;
	k3y2 = interp_y1(t - PARtau1, &plag0) +interp_y2(t - PARtau2, &plag1) ;
	k3y3 =  (pt_y2_ar[SIM_n] + 0.75 * dt * k2y2) ;
	TEMPy1 = pt_y1_ar[SIM_n] + dt * 1.0/9.0 * (2.0*k1y1 + 3.0*k2y1 + 4.0*k3y1);
	TEMPy2 = pt_y2_ar[SIM_n] + dt * 1.0/9.0 * (2.0*k1y2 + 3.0*k2y2 + 4.0*k3y2);
	TEMPy3 = pt_y3_ar[SIM_n] + dt * 1.0/9.0 * (2.0*k1y3 + 3.0*k2y3 + 4.0*k3y3);
	t += dt * 0.25;
	k4y1 = interp_y1(t - PARtau1, &plag0) ;
	k4y2 = interp_y1(t - PARtau1, &plag0) +interp_y2(t - PARtau2, &plag1) ;
	k4y3 =  TEMPy2 ;
	ERRORy1 = dt/72.0 * (-5.0*k1y1 + 6.0*k2y1 + 8.0*k3y1 - 9.0*k4y1);
	ERRORy2 = dt/72.0 * (-5.0*k1y2 + 6.0*k2y2 + 8.0*k3y2 - 9.0*k4y2);
	ERRORy3 = dt/72.0 * (-5.0*k1y3 + 6.0*k2y3 + 8.0*k3y3 - 9.0*k4y3);
	RelErr = 0.0;
	ERRORy1 = ERRORy1/MAX( MAX(ABSy1(pt_y1_ar[SIM_n]), ABSy1(TEMPy1)), thresh);
	ERRORy3 = ERRORy3/MAX( MAX(ABSy3(pt_y3_ar[SIM_n]), ABSy3(TEMPy3)), thresh);
	ERRORy2 = ERRORy2/MAX( MAX(ABSy2(pt_y2_ar[SIM_n]), ABSy2(TEMPy2)), thresh);

	RelErr = MAX(RelErr, ABSy1(ERRORy1));
	RelErr = MAX(RelErr, ABSy3(ERRORy3));
	RelErr = MAX(RelErr, ABSy2(ERRORy2));
	if(RelErr <= RelTol || TakingMinStep ) {
		pt_y1_ar[SIM_n+1] = TEMPy1;
		pt_y2_ar[SIM_n+1] = TEMPy2;
		pt_y3_ar[SIM_n+1] = TEMPy3;
		
        pt_y1_Var[SIM_n+1] = k4y1;
		pt_y2_Var[SIM_n+1] = k4y2;
		pt_y3_Var[SIM_n+1] = k4y3;
		
        k1y1 = k4y1; //FSAL
		k1y3 = k4y3; //FSAL
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

            
#ifndef MANUAL
PyObject *erg;
erg = PyDict_New();

PyObject *myarray;
double *array_buf;
npy_intp dim = SIM_n;

myarray = PyArray_SimpleNew(1, &dim, NPY_DOUBLE);

array_buf = (double *) PyArray_DATA(myarray);

for(i = 0; i < SIM_n; i++) 
    *array_buf++ = pt_t_ar[i];
free(pt_t_ar);

PyDict_SetItem(erg, PyString_InternFromString("t"), myarray);
Py_DECREF(myarray);

        
PyObject *myarray_y1;
//PyObject *myarray_Vy1;
double *array_bufy1; 
//double *array_bufVy1;

myarray_y1 = PyArray_SimpleNew(1, &dim, NPY_DOUBLE);
//myarray_Vy1 = PyArray_SimpleNew(1, &dim, NPY_DOUBLE);

array_bufy1 = (double *) PyArray_DATA(myarray_y1);
//array_bufVy1 = (double *) PyArray_DATA(myarray_Vy1);

for(i = 0; i < SIM_n; i++) {
    *array_bufy1++ = pt_y1_ar[i];
    //*array_bufVy1++ = pt_y1_Var[i];
}
free(pt_y1_ar);
free(pt_y1_Var);

PyDict_SetItem(erg, PyString_InternFromString("y1"), myarray_y1);
//PyDict_SetItem(erg, PyString_InternFromString("Vy1"), myarray_Vy1);
Py_DECREF(myarray_y1);
//Py_DECREF(myarray_Vy1);

            
PyObject *myarray_y3;
//PyObject *myarray_Vy3;
double *array_bufy3; 
//double *array_bufVy3;

myarray_y3 = PyArray_SimpleNew(1, &dim, NPY_DOUBLE);
//myarray_Vy3 = PyArray_SimpleNew(1, &dim, NPY_DOUBLE);

array_bufy3 = (double *) PyArray_DATA(myarray_y3);
//array_bufVy3 = (double *) PyArray_DATA(myarray_Vy3);

for(i = 0; i < SIM_n; i++) {
    *array_bufy3++ = pt_y3_ar[i];
    //*array_bufVy3++ = pt_y3_Var[i];
}
free(pt_y3_ar);
free(pt_y3_Var);

PyDict_SetItem(erg, PyString_InternFromString("y3"), myarray_y3);
//PyDict_SetItem(erg, PyString_InternFromString("Vy3"), myarray_Vy3);
Py_DECREF(myarray_y3);
//Py_DECREF(myarray_Vy3);

            
PyObject *myarray_y2;
//PyObject *myarray_Vy2;
double *array_bufy2; 
//double *array_bufVy2;

myarray_y2 = PyArray_SimpleNew(1, &dim, NPY_DOUBLE);
//myarray_Vy2 = PyArray_SimpleNew(1, &dim, NPY_DOUBLE);

array_bufy2 = (double *) PyArray_DATA(myarray_y2);
//array_bufVy2 = (double *) PyArray_DATA(myarray_Vy2);

for(i = 0; i < SIM_n; i++) {
    *array_bufy2++ = pt_y2_ar[i];
    //*array_bufVy2++ = pt_y2_Var[i];
}
free(pt_y2_ar);
free(pt_y2_Var);

PyDict_SetItem(erg, PyString_InternFromString("y2"), myarray_y2);
//PyDict_SetItem(erg, PyString_InternFromString("Vy2"), myarray_Vy2);
Py_DECREF(myarray_y2);
//Py_DECREF(myarray_Vy2);

            
if(NumberOfMinSteps>1)
    std::cerr << "Number of Minimum steps taken: " << NumberOfMinSteps << std::endl;

return_val =  erg;
Py_DECREF(erg);
#endif
 
#ifdef MANUAL
for(i = 0; i < SIM_n; i++) 
    std:: cout << pt_t_ar[i] << "	" << pt_y1_ar[i] << "	" << pt_y3_ar[i] << "	" << pt_y2_ar[i] << std::endl;
    return 0;
}
#endif

// This hash is included to detect a change in
// the support code and recompile in this case
// b4396d7ee242b1f6d89c0fcc9ab889d8

