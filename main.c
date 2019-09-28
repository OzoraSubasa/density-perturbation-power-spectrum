#include"allvars.h"
#include"proto.h"
int main(int argc,char **argv)
{
    float rho_c=Rho_crit();
    printf("rho_c=%f\n",rho_c);
    test_function();
}

void test_function()
{
    linear_transfer_function();
    linear_growth_factor();
    linear_power_spectrum();
}
void linear_transfer_function()
{
    float t,k=1.0e-4;
    FILE *fo;
    char buf[100];
    int i;

    sprintf(buf,"output/results/linear_transfer_function.txt");
    fo=fopen(buf,"w");
    if (fo==NULL)
    {
	fprintf(stderr,"write fail...in %s %d lines\n",__func__,__LINE__);
	exit(1);
    }
    while (k/Omega/pow(Hubble_h,2.0)<=10)
    {
        t=transfer_function(k);
	fprintf(fo,"%f %f\n",k/Omega/pow(Hubble_h,2.0),t);
	k+=0.001;
    }
    fclose(fo);
}

void linear_growth_factor()
{
    float D,z=0;
    FILE *fo;
    char buf[100];
    int i;

    sprintf(buf,"output/results/linear_growth_factor.txt");
    fo=fopen(buf,"w");
    if (fo==NULL)
    {
	fprintf(stderr,"write fail...in %s %d lines\n",__func__,__LINE__);
	exit(1);
    }
    while (log10(1+z)<=1.0)
    {
	D=growth_factor(z);
	fprintf(fo,"%f %f\n",log10(1+z),log10(D));
	z+=0.001;
    }
    fclose(fo);
}

void linear_power_spectrum()
{
    float P,k=1.0e-4;
    float z=0;
    FILE *fo;
    char buf[100];
    
    sprintf(buf,"output/results/linear_power_spectrum.txt");
    fo=fopen(buf,"w");
    if (fo==NULL)
    {
	fprintf(stderr,"write fail...in %s %d lines\n",__func__,__LINE__);
	exit(1);
    }
    while (k/Hubble_h<=10)
    {
	P=P_k(k,z)*1.0e7;
        fprintf(fo,"%f %e\n",k/Hubble_h,P);
	k+=0.001;
    }
    fclose(fo);
}
