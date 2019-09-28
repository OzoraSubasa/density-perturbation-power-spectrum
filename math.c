#include"allvars.h"
#include"proto.h"

float integral(float low,float high,float M,float (*func)(float x,float y))
{
    int i,n=10000;
    float interval,I=0.0,temp;
    if (high<low)
    {
	temp=low;
	low=high;
	high=temp;
    }
    if (high==low)
	return I;
    temp=0.0;
    interval=(high-low)*1.0/n;
    for (i=1;i<=n-1;i++)
	temp+=(*func)(low+i*interval,M);
    I=interval*(0.5*(*func)(low,M)+temp+0.5*(*func)(high,M));
    return I;
}

float variance_func(float k,float M)
{
    float x,R,RhoCrit,P,W,fac;

    RhoCrit=Rho_crit();
    R=pow(3*M/(800*PI*RhoCrit),1./3.);
    fac=4*PI*pow(k,2.)/pow(2*PI,3.0);
    P=P_k(k,0)*1.0e7;
    W=top_hat(k*R);
    W=pow(W,2.0);
    return fac*P*W;
}
