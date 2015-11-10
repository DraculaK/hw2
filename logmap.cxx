#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(void){
	double x0 = 0.5;
	double x;
	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations
	int p = Nend-Nskip;
	double y[p];
	
	
	ofstream out("logmap.dat");

	for(double r=0; r <= 4; r += 0.001){
	    
	    int i; 
	    x=x0;
	   
	   for(int i=1; i <= Nskip; i++)
	      x = r*x*(1-x);
	   for(i=Nskip+1; i <= Nend; i++){
	   		   
	      x = r*x*(1-x);
	    
	      y[i-Nskip-1] = x;
	      
	   }
	  
	  for(i=0; i<Nend-Nskip; i++){
		
	    out << "r=" << r << "\t" << "\t" << "y[" << i << "]=" << y[i] << endl; //print to file logmap.dat
	  }
	}
	
out.close(); 

return 0;
}
