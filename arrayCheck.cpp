/* if you want to check something making function then void 
function is good, otherwise if you want to return something
than function must be return type
*/

// checking type program




# include <iostream>
# include <cmath>
#include <iomanip>


using namespace std;

void fd_Paris(double X, int i,double &u, double &w, double &fd_Paris1);
//void U(double X, double &u);
//void W(double X);


int main()
{

double u;
double  w;
double C[12];
double X =0.1;
int i;
double fd_Paris1;
fd_Paris( X/0.197328 , i,u, w, fd_Paris1);



//U( X/0.197328, u);
//W( X/0.197328);
cout << "value of u return ==" << u << endl;
cout << "value of w return ==" << w << endl;
//cout << "value of fd_Paris1== " << fd_Paris1 << endl;

}




void fd_Paris(double X, int i,double &u, double &w, double &fd_Paris1)
{

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
for(J=0; J< 13; J++)
{
	cout << "output for all C ==" << C[J] << endl;
 }

//cout << "C[7] == "<< setprecision(8)<< C[7] << endl;

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
//cout << "BM[0]== " << BM[0] << endl;
A = 0.0;
double B = 0.0;
double CC= 0.0; 

for (int J=0; J< 10; J++)
{
	A=A+D[J]/pow(BM[J],2);
	B = B + D[J];
	CC = CC + D[J]* pow(BM[J],2); 
}

//cout << "A ==" << setprecision(8) << A << endl;
//cout << "B ==" << B << endl;
//cout << "CC ==" << CC << endl;

//cout << "BM[9] == " << BM[9] << endl;
//cout << "BM[10] == " << BM[10] << endl;
//cout << "BM[11] == " << BM[11] << endl;
//cout << "BM[12] == " << BM[12] << endl;


D[10]= (pow(BM[10],2)/((pow(BM[12],2)-pow(BM[10],2))*(pow(BM[11],2)- pow(BM[10],2))))*(-pow(BM[11],2)*pow(BM[12],2)*A + (pow(BM[11],2)+ pow(BM[12],2))*B-CC);          


D[11]= (pow(BM[11],2)/((pow(BM[10],2)-pow(BM[11],2))*(pow(BM[12],2)- pow(BM[11],2))))*(-pow(BM[12],2)*pow(BM[10],2)*A + (pow(BM[12],2)+ pow(BM[10],2))*B-CC); 


D[12] = (pow(BM[12],2)/((pow(BM[11],2)-pow(BM[12],2))*(pow(BM[10],2)- pow(BM[12],2))))*(-pow(BM[10],2)*pow(BM[11],2)*A + (pow(BM[10],2)+ pow(BM[11],2))*B-CC); 

//cout << "BM[12] == " << BM[12] << endl;
//cout << "D[9] == " << D[9] << endl;
//cout << "D[10] == " << D[10] << endl;
//cout << "D[11] == " << D[11] << endl;
//cout << "D[12] == " << D[12] << endl;

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
//cout << "value of fd_Paris1== " << fd_Paris1 << endl;


}
