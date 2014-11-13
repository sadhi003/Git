// conversion of dwavefunction(without array passing)
// This code give right answer
// Date 2014 NOV 08
// Writer : SA

# include <iostream>
# include <cmath>
# include <complex>
# include <fstream>
#include <iomanip>
 


using namespace std;
#define PI 3.14159265


void fd_Paris(double X, int i,double &u, double &w, double &fd_Paris1);
void dwavefunction(int kj,int ksp,int ksn,double theta,double phi,double &uu, double &wd,  double &wf_re, double &wf_im);
typedef complex<double> dcomp;



int main()

{
cout<< setprecision(8)<< endl;
double u, w;
double uu, wd;
int i;
double fd_Paris1;
int p;
double X ;
double theta0 = 30.0;
double phi0 = 18.0;
double theta = (theta0*PI/180.0);
double phi= (phi0*PI/180.0); 
double wf_re;
double wf_im;
double Total_wf_re= 0.0;
double Total_wf_im= 0.0; 
double Total_wf;
double sum= 0.0;
int size = 2000;
X= 0.1;
// calling function(checking using only one moemntum)
/*
fd_Paris( X/0.197328 , i,u, w, fd_Paris1);

cout << "value of u return ==" << u << endl;
cout << "value of w return ==" << w << endl;

uu = u/sqrt(pow(0.197328,3));
wd = w/sqrt(pow(0.197328,3)); 
 
cout << "value of uu== " << uu << endl;
cout << "value of wd== " << wd << endl;



//dwavefunction(0,-1,-1,theta ,phi, uu, wd,wf_re,wf_im);
//cout << "wf_re  == " << wf_re << endl;
//cout << "wf_im  == " << wf_im << endl;




// Outer calling to check inside value in function


fd_Paris( X/0.197328 , i,u, w, fd_Paris1);
//dwavefunction(kj,ksp,ksn,theta ,phi, uu, wd,wf_re,wf_im);


*/


ofstream fout("test.txt");   // defining output function

   for (int p = 0; p <= size; p+=20)
   {

X = p/1000.0;
//cout << "out value of X == " << X << endl;

fd_Paris( X/0.197328 , i,u, w, fd_Paris1);

//cout << "value of u return ==" << u << endl;
//cout << "value of w return ==" << w << endl;

uu = u/sqrt(pow(0.197328,3));
wd = w/sqrt(pow(0.197328,3)); 
 
//cout << "value of uu== " << uu << endl;
//cout << "value of wd== " << wd << endl;



Total_wf = 0.0;
for (int kj = -1; kj <=1; kj++)
{
  for(int ksp = -1; ksp <= 1; ksp++)
  {
    for(int ksn = -1; ksn <= 1; ksn++)
    {
    dwavefunction(kj,ksp,ksn,theta ,phi, uu, wd,wf_re,wf_im);
    //cout << "wf_re  == " << wf_re << endl;
    //cout << "wf_im  == " << wf_im << endl;
    Total_wf =Total_wf + (pow(wf_re,2) + pow(wf_im,2));
    //Total_wf_re += wf_re;
    //Total_wf_im += wf_im;
    //cout << "***********************" << endl;
     // cout << "Total_wf_re== " << Total_wf_re<< endl;
     // cout << "Total_wf_im== " << Total_wf_im<< endl;
     // cout << "***********************" << endl;  
    }
  } 
}

//cout << setw(11) << X << setw(17) << Total_wf << endl;
 fout << setw(11) << X << setw(17) << Total_wf << endl;
//fout<< Total_wf;


}

return 0;

}








void dwavefunction(int kj,int ksp,int ksn,double theta,double phi, double &uu, double &wd  ,double &wf_re, double &wf_im)

/* function calculate the deuteron wave function with spin and isospin
 component 
      kj = 1,0,-1  - deuteron spin projection
      kt  = 1,-1 - struck out nucleon isospin 1-proton -1 neutron
      ksp = 1,-1 - spin projection of proton
      ksn = 1,-1 - spin projection of neutron
      p, theta, phi - momentum(GeV/c), polar (rad) and azimuthal(rad) angles of 
                       relative p-n momentum
      wf - complex - wave function for given spin 
      iw = 1 - Paris, 2 - v18, 3 - cdbonn, 4 - v14 ->passing different potential
      ini = 1  - initializing, 0-calculating
      
*/

{
  

  

  
 
if (kj==1)
{
    

    if (ksp == 1 && ksn == 1){
      //cout << "it is for 1, 1, 1" << endl;
    	wf_re = uu + wd/sqrt(8.0) * (3.0* pow(cos(theta), 2) -1.0);
    	wf_im = 0.0;
    
    }
    else if(ksp == 1 && ksn == -1) 


    {
    	
      //cout << "it is for 1, 1, -1" << endl;
      wf_re = wd/sqrt(8.0)*3.0*cos(theta)*sin(theta)*cos(phi);
    	wf_im = wd/sqrt(8.0)* 3.0 * cos(theta)*sin(theta)* sin(phi);
    }
    
    else if(ksp == -1 && ksn == 1) 
    {
    	
     // cout << "it is for 1, -1, 1" << endl;
      wf_re = wd/sqrt(8.0)*3.0*cos(theta)*sin(theta)*cos(phi);
    	
      wf_im = wd/sqrt(8.0)* 3.0* cos(theta)*sin(theta)* sin(phi);
    
    }
    else if(ksp == -1 && ksn == -1)
    {
    	
     // cout << "it is for 1, -1, -1" << endl;
      wf_re = wd/sqrt(8.0)*3.0 * pow(sin(theta),2) * cos(2.0*phi);
    	wf_im = wd/sqrt(8.0)*3.0* pow(sin(theta),2)  * cos(2.9*phi);
    }
    else 
      {  

       // cout << "Printing else statement " << endl;
        wf_re = 0.0;
        wf_im = 0.0;
      }
}
else if (kj== 0)
{
   if (ksp == 1 && ksn == 1)
{
  
 // cout << "it is for 0, 1, 1" << endl;
	wf_re = wd* 3.0/2.0 * cos(theta) * sin(theta) * cos(phi);
	wf_im = - wd*3.0/2.0 * cos(theta) * sin(theta) * sin(phi);

}
   else if (ksp == 1 && ksn == -1)
{

	// cout << "it is for 0, 1, -1" << endl;
  wf_re = uu/sqrt(2.0) - (wd/2.0 * (3* pow(cos(theta),2) - 1.0));
	wf_im = 0.0;

}
    else if (ksp = -1 && ksn == 1)
{
	
 // cout << "it is for 0, -1, 1" << endl;
  wf_re = uu/sqrt(2.0) - wd/2.0 * (3* pow(cos(theta), 2) - 1.0);
	wf_im = 0.0;

}
    else if (ksp = -1 && ksn == -1)
{


// cout << "it is for 0,-1, -1" << endl;
wf_re = -wd*3.0/2.0*cos(theta)*sin(theta)*cos(phi);
wf_im = -wd*3.0/2.0*cos(theta)*sin(theta)*sin(phi);

}
else 
      {  

       // cout << "Printing else statement " << endl;
        wf_re = 0.0;
        wf_im = 0.0;
      }
}


else if(kj == -1)

{
if (ksp == 1 && ksn ==1)
{
	   // cout << "it is for -1, 1, 1" << endl;
     wf_re =  wd/sqrt(8.0)*3.0 * pow(sin(theta),2) *cos(2.0*phi);
     wf_im = -wd/sqrt(8.0)*3.0* pow(sin(theta),2) *sin(2.0*phi);
}	

else if(ksp == 1 && ksn == -1) 
{
	   // cout << "it is for -1, 1, -1" << endl;
      wf_re = -wd/sqrt(8.0)*3.0*cos(theta)*sin(theta)*cos(phi);   
      wf_im =  wd/sqrt(8.0)*3.0*cos(theta)*sin(theta)*sin(phi); 

}
else if(ksp == -1 && ksn == 1) 
{
	   // cout << "it is for -1, -1, 1" << endl;
      wf_re = -wd/sqrt(8.0)*3.0*cos(theta)*sin(theta)*cos(phi);   
      wf_im =  wd/sqrt(8.0)*3.0*cos(theta)*sin(theta)*sin(phi); 
}
else if(ksp == -1 && ksn == -1) 
{
    
   // cout << "it is for 1, -1, -1" << endl;
	  wf_re = uu + wd/sqrt(8.0)*(3.0* pow(cos(theta), 2)-1.0);
    wf_im = 0.0;

}
else 
      {  

       // cout << "Printing else statement " << endl;
        wf_re = 0.0;
        wf_im = 0.0;
      }
}


//comp wf(wf_re, wf_im);



}


void fd_Paris(double X, int i, double &u, double &w, double &fd_Paris1)
{

//every parameter assign in this code are correct, already been checked

double C[13], D[13], BM[13];
int J;

C[0] = 0.88688076;
C[1] = -0.34717093; 
C[2] = -3.050238;
C[3] = 56.207766;                                                    
C[4]=-749.57334;                                                   
C[5]=5336.5279;                                                    
C[6]=-22706.863;                                                   
C[7]=60434.4690;                                                   
C[8]=-102920.58;                                                   
C[9]=112233.57;                                                   
C[10]=-75925.226;                                                  
C[11]=29059.715; 

double A = 0.0;

for(J=0; J< 12; J++)
{
  A = A + C[J];
} 

C[12] = -A;



D[0]=0.023135193;                                                  
D[1]=-0.85604572;                                                  
D[2]=5.6068193;                                                    
D[3]=-69.462922;                                                   
D[4]=416.31118;                                                    
D[5]=-1254.6621;                                                   
D[6]=1238.783;                                                     
D[7]=3373.9172;                                                    
D[8]=-13041.151;                                                   
D[9]=19512.524;        
A = 0.0;
for (int J=0; J< 13; J++)
{
  BM[J]=0.23162461+(J);
}

A = 0.0;
double B = 0.0;
double CC= 0.0; 



for (int J=0; J< 10; J++)
{
  A=A+D[J]/pow(BM[J],2);
  B = B + D[J];
  CC = CC + D[J]* pow(BM[J],2); 
}

D[10]= (pow(BM[10],2)/((pow(BM[12],2)-pow(BM[10],2))*(pow(BM[11],2)- pow(BM[10],2))))*(-pow(BM[11],2)*pow(BM[12],2)*A + (pow(BM[11],2)+ pow(BM[12],2))*B-CC);          


D[11]= (pow(BM[11],2)/((pow(BM[10],2)-pow(BM[11],2))*(pow(BM[12],2)- pow(BM[11],2))))*(-pow(BM[12],2)*pow(BM[10],2)*A + (pow(BM[12],2)+ pow(BM[10],2))*B-CC); 


D[12] = (pow(BM[12],2)/((pow(BM[11],2)-pow(BM[12],2))*(pow(BM[10],2)- pow(BM[12],2))))*(-pow(BM[10],2)*pow(BM[11],2)*A + (pow(BM[10],2)+ pow(BM[11],2))*B-CC); 


cout << "D[10] == " << D[10] << endl;
cout << "D[11] == " << D[11] << endl;
cout << "D[12] == " << D[12] << endl;

A= 0.0;
double F=0.79788456; 
for ( int J=0; J< 13; J++)
  {
    A = A + C[J]/(X*X + pow(BM[J],2));                                                     
         
  }

u =A * F/sqrt(4.0*3.14159265); 


A= 0.0;

  for ( int J=0; J< 13; J++)
  {
    A = D[J]/(X*X+ pow(BM[J],2))+ A;                                                     
            
  }

 
 w =A * F/sqrt(4.0 *3.14159265); 


fd_Paris1 = (pow(u,2)+ pow(w,2))/pow(0.197328,3);



}

































