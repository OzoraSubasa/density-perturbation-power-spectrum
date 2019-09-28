/* main.c */
void linear_transfer_function();
void test_function();
void linear_growth_factor();
void linear_power_spectrum();
/* cosmology.c */
float Omega_z(float z);
float OmegaLambda_z(float z);
float H_z(float z);
float growth_factor(float z);
float transfer_function(float k);
float top_hat(float x);
float P_k(float k,float z);
float Rho_crit();
/* math.c */
float integral(float low,float high,float M,float (*func)(float x,float y));
float variance_func(float k,float M);
