#include<stdio.h>
#include<stdlib.h>

typedef struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
}retire_info;

//typedef _retire_info retire_info;

double calculateBalance(double totalBalance, retire_info retireStatus){
  totalBalance+= totalBalance * retireStatus.rate_of_return;
  return totalBalance+ retireStatus.contribution;
}

void printInfo(int totalMonths, double totalBalance){
  printf("Age %3d month %2d you have $%.2lf\n", totalMonths/12, totalMonths%12, totalBalance);
}
	       

void retirement(int startAge, double initial, retire_info working, retire_info retired){
  double totalBalance=initial;
  int totalMonths=startAge-1;

  for(int i=0;i<working.months;i++){
    totalMonths++;
    printInfo(totalMonths,totalBalance);
    totalBalance=calculateBalance(totalBalance,working);
  }

  for(int i=0;i<retired.months;i++){
    totalMonths++;
    printInfo(totalMonths,totalBalance);
    totalBalance=calculateBalance(totalBalance,retired);
  }
  return;
}

int main(){
  retire_info working;
  retire_info retired;
  working.months=489;
  working.contribution=1000;
  working.rate_of_return=0.045/12;

  retired.months=384;
  retired.contribution=-4000;
  retired.rate_of_return=0.01/12;

  int ageMonths=327;
  double saving=21345;

  retirement(ageMonths,saving,working,retired);
  return 0;
}
