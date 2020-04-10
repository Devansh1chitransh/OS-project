#include <stdio.h>
#include <stdlib.h>
double PFR;
double EAT;

double pagemodifiedper;

double tpm;

double SPFmodified;

double mem_access_time;



double SPFempty_ns;
double SPFmodified_ns;
double SPFempty;
double pf_rate();
void userInput(void);	

void main(){
	int s;
	
	do{
	
	
	printf("press 1 to find page fault rate and 0 to exit \n");
	
	scanf("%d",&s);
	switch(s){
		case 1:userInput();break;
		case 0:exit(0);
	}
	printf("\n\n");

}while(s<3);
}
void userInput(){
	
	
	printf("\n Give the  service Page Fault (unmodified)in ms    ");
	scanf("%lf",&SPFempty);
	printf("Give the Service Page Fault for Modified Page in ms    ");
	scanf("%lf",&SPFmodified);
	printf("Enter memory access in ns    ");
	scanf("%lf",&mem_access_time);
	printf("what modified Percentage of time the page to be replaced:    ");
	scanf("%lf",&tpm);
	printf("Give Effective Access time in ns   ");
	scanf("%lf",&EAT);

	SPFempty_ns = (SPFempty*1000000);
	SPFmodified_ns = (SPFmodified*1000000);
	pagemodifiedper = (tpm/100);   
	printf("\nPage Fault rate calculated For:\n  ");
	printf("Service-Page-Fault   =    %lf \n   ",SPFempty_ns);
	printf("Service-Page-Fault of modified Page     %lf \n  ",SPFmodified_ns);
	printf("memory-access-time     %lf\n     ",mem_access_time);
	printf("Effective Access Time %lf\n",EAT);
    PFR =  pf_rate(SPFempty_ns,SPFmodified_ns,mem_access_time,pagemodifiedper,EAT);
	printf("\nMax. acceptable page fault rate is     %.2e  ",PFR);


}

double pf_rate(double a,double b,double c,double d,double e){
	double c1,c2;
	double num,den;
	double pageFault;
	 c1 = (1- d)*a;
	 c2 = d*b;
	 num = e - c;
     den = (c1+c2);

	pageFault = num/den;
	return pageFault;


}

