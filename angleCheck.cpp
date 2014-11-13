// this program is used to check different part of code when developing 
// wavefunction code for deuteron




# include <iostream>
# include <cmath>
# include <complex>
# include <iomanip>
# define PI 3.14159265
using namespace std;
typedef complex<double> dcomp;
dcomp sum(dcomp C, dcomp D);

void squareArray(int array[]);

int main()

{

cout<<setprecision(13)<<endl;	
int x= 30;
double s_re, wf_re,wf_re1;
double theta, phi;
int y = 30;
phi = (y * PI/180);
theta = (x*PI/180);
long double k= 0.4673895763849;
double l = -0.720739E+03;
// angle check method
//cout << "value of sin30 as sin(theta) is == " << sin(theta) << endl;
//cout << "value of sin30 as sin^2(theta) is == " << pow(sin(theta),2) << endl;

cout<< "value of l==" << l<< endl;

// complex number check
dcomp C(2.0, 3.0);
dcomp D(5.0, 4.7);
//cout << "complex number is "<< C <<endl;
//cout << " sum of complex number is " << sum(C,D) << endl;
// check for array, way of calling array


int array[10];

for (int i; i<10; i++)
{
	array[i] = i+ 1;
}



squareArray(array);
for(int i; i< 10; i++)
{
    cout << "array[i] " << array[i] << endl;
	
}


cout << "value of k== " << k << endl;
s_re = (1.0 + 3.0*cos(2 * theta))/2.0;
wf_re =  1/sqrt(8.0)*3.0*pow(sin(theta),2)*cos(2.0*phi);
wf_re1 = 1/sqrt(2.0) - 1/2.0 * (3.0*pow(cos(theta),2)-1.0);
//s_re = (1.0 + 3.0*cos(2 * theta))/2.0;
cout << "value check for wf_re ==" << wf_re << endl;
cout << "value check for wf_re1 ==" << wf_re1 << endl;
return 0;
}

// function for array
void squareArray(int array[])

{
for (int i; i<10; i++)
{
   array[i] = array[i]*array[i];
}
}






// complex number calculation

dcomp sum(dcomp C, dcomp D)
{
	dcomp result;
	result = C + D;
    
    return result;
} 
