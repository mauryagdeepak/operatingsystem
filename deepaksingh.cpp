#include<iostream>
using namespace std;

class input_local{
protected:
 int 	no_of_processes, total, random1, counter, time_quantum_p,counter1; 
      int wait_time_p, turnaround_time_p,qq,z,p[20],prio[20], a_time[20], b_time[20], temp[20],b,local_var; 
float average_wait_time_P, average_turnaround_time_p;  


input_local(){
int 	no_of_processes=0, total=0, random1=0, counter=0, time_quantum_p=0,counter1=0;
float average_wait_time_P=0, average_turnaround_time_p=0;}};


class pro:protected input_local{
public:
int lp=0;
void cool(){
	cout<<"\n|Process ID|\t\t|Burst Time|\t|Turnaround Time|\t |Waiting Time|\t| Priority|"<<endl;
      for(total = 0, lp = 0; random1!= 0;) { 

		    for(z=0;z<no_of_processes;z++){
			 	int temp1;
					qq=z;
			for(local_var=z+1;local_var<no_of_processes;local_var++)
			{
			    if(prio[local_var]<prio[qq])
				qq=local_var;
			}

		temp1=prio[z];

		prio[z]=prio[qq];

		prio[qq]=temp1;

			temp1=b_time[z];
			b_time[z]=b_time[qq];
			b_time[qq]=temp1;
		 			temp1=a_time[z];
				a_time[z]=a_time[qq];
			a_time[qq]=temp1;

			temp1=p[z];
				p[z]=p[qq];
			p[qq]=temp1;

			temp1=temp[z];
				temp[z]=temp[qq];
			temp[qq]=temp1;
		    }
            
			if(temp[lp] <= time_quantum_p && temp[lp] > 0) 
            { 
                  total = total + temp[lp]; 
                  temp[lp] = 0; 
                  counter = 1; 
            } 
            
			else if(temp[lp] > 0) 
            { 
                  temp[lp] = temp[lp] - time_quantum_p; 
                  total = total + time_quantum_p; 
            } 

	for(b=0;b<no_of_processes;b++)
		{
			if(b==lp)
			prio[b]+=1;
			else
			prio[b]+=2;
		}

            if(temp[lp] == 0 && counter == 1) 
            { 
                  random1--; 
                 cout<<"\nProcess"<<"["<<p[lp]<<"]"<<("\t\t");
		cout<<b_time[lp]<<("\t\t");
		cout<<(total - a_time[lp])<<("\t\t");
		cout<<(total - a_time[lp] -b_time[lp])<<("\t\t");
		cout<<prio[lp]<<("\t\t");
                  wait_time_p = (wait_time_p + total - a_time[random1] - b_time[lp]); 
                  turnaround_time_p = (turnaround_time_p + total - a_time[lp]); 
                  counter = 0; 
            } 
            if(lp ==no_of_processes- 1)lp = 0; 
            
	else if(a_time[lp + 1] <= total) 
                  lp++;
            else 
		lp = 0;		
      }

}

};








class var: public  pro{
public :
void Input(){
	cout<<endl<<"Enter Total Number of Processes"<<endl; 

     	cin>>no_of_processes; 

      	random1 =no_of_processes; 

	int  k=0; 

  while(k<no_of_processes) {
	p[k]=k+1;

	prio[k]=0;

	cout<<"\nEnter total Details of Process\n"<<"["<<(k+1)<<"]"<<endl;
            cout<<"Arrival Time:\t"<<endl; 
	cin>>a_time[k]; 
	cout<<"\nBurst Time:\t"<<endl; 
	cin>>b_time[k];
	 temp[k] = b_time[k]; k++;}

	cout<<"\nEnter the Time Quantum:\n"; 
      	cin>>time_quantum_p;
}
};



int main(){
var c;
c.Input();
c.cool();
return 0;
}
