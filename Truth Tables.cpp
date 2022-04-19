#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	
	
bool p[8]= {true, true,true, true,false,false,false,false};
bool q[8] = {true, true,false,false,true,true,false,false};
bool r[8] = {true,false,true,false,true,false,true,false};


cout<<"Truth Table of p Implies q is: \n";
cout<<"p"<<setw(15)<<"q"<<setw(20)<<"p --> q" <<endl;




cout<<"_______________________________________________"<<endl;
for(int i=0; i<8; i++)
{
cout<<p[i]<<setw(15)<<q[i]<<setw(15)<<(!(p[i]) || q[i])<<endl;
}


cout<<"\n\nTruth Table of q Implies r is: \n";
cout<<"q"<<setw(15)<<"r"<<setw(20)<<"q --> r" <<endl;



cout<<"_______________________________________________"<<endl;
for(int i=0; i<8; i++)
{
cout<<q[i]<<setw(15)<<r[i]<<setw(15)<<(!(q[i]) || r[i])<<endl;
}
cout<<"\n\nTruth Table of p Implies r is: \n";
cout<<"p"<<setw(15)<<"r"<<setw(20)<<"p --> r" <<endl;
cout<<"_______________________________________________"<<endl;
for(int i=0; i<8; i++)
{
cout<<p[i]<<setw(15)<<r[i]<<setw(15)<<(!(p[i]) || r[i])<<endl;
}
cout<<"\nHence, above arguments are tested.";
}
