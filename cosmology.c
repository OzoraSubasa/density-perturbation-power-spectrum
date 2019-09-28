#include"allvars.h"
#include"proto.h"
float E_z(float z)
{
    float zplus1;
    zplus1=1+z;
    return sqrt(OmegaLambda+(1-Omega-OmegaLambda)*pow(zplus1,2.0)+Omega*pow(zplus1,3.0));
}

float Omega_z(float z)
{
    return Omega*pow(1+z,3.0)/E_z(z)/E_z(z);
}

float OmegaLambda_z(float z)
{
    return OmegaLambda/E_z(z)/E_z(z);
}

float H_z(float z)
{
    return H0*E_z(z);
}

float growth_factor(float z)
{
    float g,omegaz,omegalambdaz;
    omegaz=Omega_z(z);
    omegalambdaz=OmegaLambda_z(z);
    g=5./2.*omegaz/(pow(omegaz,4./7.)-omegalambdaz+(1+omegaz/2.)*(1+omegalambdaz/70.));
    return g/(1+z);
}

float transfer_function(float k)
{
    float gamma,q,T;
    float fac;
    gamma=Omega*Hubble_h;
    q=1/gamma*(k/Hubble_h);
    fac=1+3.89*q+pow(16.1*q,2.)+pow(5.46*q,3.)+pow(6.71*q,4.);
    T=log(1+2.34*q)/(2.34*q)*pow(fac,-0.25);
    return T;
}

float top_hat(float x)
{
    return 3*(sin(x)-x*cos(x))/pow(x,3.0);
}

float P_k(float k,float z)
{
    return k*pow(transfer_function(k),2.0)*pow(growth_factor(z),2.);
}

float Rho_crit()
{
    return 3*pow(H0,2.0)/8/PI/G;	//27.75505 (h^2.10^10Msun.Mpc^-3)
}
