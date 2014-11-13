# include <iostream>
# include <cmath>

using namespace std;
#define PI 3.14159265
// hello
//void dwavefunction(int kj,int kt,int ksp,int ksn,double p,double theta,double phi,double wf,int iw,int ini);
double zeta(int kj, int ksp, int ksn, double ze_re, double ze_im); 
void stensor(int kj,int ksp,int ksn,double theta,double phi,double &s_re,double &s_im);

int main()
{
int kj, ksp, ksn;
double ze_rea;
double ze_im;
double ze_re;
double s_re;
double s_im;
double s_rea;
double theta0 = 30;
double phi0 = 30;
double theta = (theta0*PI/180.0);
double phi= (phi0*PI/180.0); 
double Total_ze_re;
double Total_s_re = 0.0;
double Total_s_im = 0.0;

 


for (kj = -1; kj <=1; kj++)
{
  for(ksp = -1; ksp <= 1; ksp++)
  {
    for(ksn = -1; ksn <= 1; ksn++)
    {
        stensor( kj,  ksp,  ksn ,theta, phi, s_re, s_im);
        cout << "s_re  == " << s_re << endl;
        cout << "s_im  == " << s_im << endl;
        Total_s_re += s_re;
        Total_s_im += s_im;
        cout << "***********************" << endl;
      cout << "Total_s_re== " << Total_s_re<< endl;
      cout << "Total_s_im== " << Total_s_im<< endl;
      cout << "***********************" << endl;
      
    }
  } 
}

cout << "total wf ==" << Total_s_re + Total_s_im << endl; 

}



/*
        calculates the tensor S by spin and isospin 
*       components for given deuteron spin projection
*       S = [3 (\sigma_p p)(\sigma_n p)/p^2 - \sigma_p\sigma_n]\zeta
*       kj  = 1,0,-1 - deuteron spin projection
*       kt  = 1,-1 - struck out nucleon isospin 1-proton -1 neutron
*       ksp = 1,-1 - spin projection of proton
*       ksn = 1,-1 - spin projection of neutron
*       p, theta, phi - momentum(GeV/c), polar (rad) and azimuthal(rad) angles of 
*                       relative p-n momentum
*       s_re - real part of the tensor 
*       s_im - imaginary part of the tensor wave 
*/

void stensor(int kj,int ksp,int ksn,double theta,double phi,double &s_re, double &s_im)
{




   if (kj == 1)
   {
      if(ksp == 1 && ksn == 1)
      { 
      
      cout << "it is for 1, 1, 1" << endl;
      s_re = (3.0*pow(cos(theta),2)-1.0 );
      s_im = 0.0; 
      
      }
      else if(ksp == 1 && ksn == -1)          //proton up neutron down
      
      {
        
        cout << "it is for 1, 1, -1" << endl;
      	s_re = 3.0*cos(theta)*sin(theta)*cos(phi);   
        s_im = 3.0*cos(theta)*sin(theta)*sin(phi); 
      }  
      else if(ksp == -1 && ksn == 1)           //proton down neutron up
      {

      cout << "it is for 1, -1, 1" << endl;
      s_re = 3.0*cos(theta)*sin(theta)*cos(phi);   
      s_im = 3.0*cos(theta)*sin(theta)*sin(phi); 
      }  
      else if(ksp == -1 && ksn == -1)          //proton down neutron down
      {

      cout << "it is for 1, -1, -1" << endl;
      
     s_re = 3.0* pow(sin(theta),2) *cos(2.0*phi);
     s_im = 3.0* pow(sin(theta),2) *sin(2.0*phi);
      }
      else 
      {  

        cout << "Printing else statement " << endl;
        s_re = 0.0;
        s_im = 0.0;
      }
   }

  else if(kj == 0) {               //  deuteron spin projection 0
      if(ksp == 1 && ksn == 1)  //   spins up
      {	
      
      cout << "it is for 0, 1, 1" << endl;
      s_re =  sqrt(2.0)*3.0*cos(theta)*sin(theta)*cos(phi);
      s_im = -sqrt(2.0)*3.0*cos(theta)*sin(theta)*sin(phi);
      }
      else if(ksp == 1 && ksn == -1)         //then ! proton up neutron down
      {
      
      cout << "it is for 0, 1, -1" << endl;
      s_re = -sqrt(2.0)*(3.0*pow(cos(theta),2)-1.0);
      s_im =  0.0;
         }
      else if(ksp == -1 && ksn == 1)        // then ! proton down neutron up
      {
      
      cout << "it is for 0, -1, 1" << endl;
      s_re = -sqrt(2.0)*(3.0*pow(cos(theta),2)-1.0);
      s_im = 0.0;
      }
      else if(ksp == -1 && ksn == -1)       //then ! proton down neutron down
      {
      

      cout << "it is for 0, -1, -1" << endl;
      s_re = -sqrt(2.0)*3.0*cos(theta)*sin(theta)*cos(phi);
      s_im = -sqrt(2.0)*3.0*cos(theta)*sin(theta)*sin(phi);
      }
      else 
      {  

        cout << "Printing else statement " << endl;
        s_re = 0.0;
        s_im = 0.0;
      }
  }
  else if(kj == -1)                       //then ! deuteron spin projection -1
      {
      if(ksp == 1 && ksn == 1)            //then ! spins up
      {

      cout << "it is for -1, 1, 1" << endl;
      s_re =  3.0 * pow(sin(theta),2) *cos(2.0*phi);
      s_im = -3.0* pow(sin(theta),2) *sin(2.0*phi);
      }
      
      else if(ksp == 1 && ksn == -1)        //  dcc c   then ! proton up neutron down
     {
      
      cout << "it is for -1, 1, -1" << endl;
      s_re = -3.0*cos(theta)*sin(theta)*cos(phi);   
      s_im =  3.0*cos(theta)*sin(theta)*sin(phi);   

     }     
      else if(ksp == -1 && ksn == 1)       //then ! proton down neutron up
     {

      
      cout << "it is for -1, -1, 1" << endl;
      s_re = -3.0*cos(theta)*sin(theta)*cos(phi);  
      s_im =  3.0*cos(theta)*sin(theta)*sin(phi);   

     }
      else if(ksp == -1 && ksn == -1)    //then ! proton down neutron down
      {

      	
        cout << "it is for -1, -1, -1" << endl;
        s_re = 3.0*pow(cos(theta),2)-1.0;
        s_im = 0.0;
      }
      else 
      {  

        cout << "Printing else statement " << endl;
        s_re = 0.0;
        s_im = 0.0;
      }

}

}