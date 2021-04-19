#include <stdlib.h>
#include <stdio.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

double account_balance (retire_info info, int startAge, double initial){
  double balance;
  balance = initial;
  int age;
  age = startAge;
  for (int t = 0; t < info.months; t++){
    age = startAge + t;
    printf("Age %3d month %2d you have $%.2lf\n", (age/12), (age%12), balance);
    balance = balance + info.contribution + (info.rate_of_return / 12 * balance);
  };
  return balance;
}

void retirement (int startAge, double initial, retire_info working, retire_info retired){
  double balance = initial;
  balance = account_balance(working, startAge, balance);
  startAge = startAge + working.months;
  account_balance(retired, startAge, balance);
}

int  main (){
  int start_age = 327;
  double start_balance = 21345;

  retire_info info_work;
  info_work.months = 489;
  info_work.contribution = 1000;
  info_work.rate_of_return = 0.045;

  retire_info info_retire;
  info_retire.months = 384;
  info_retire.contribution = -4000;
  info_retire.rate_of_return = 0.01;
  
  retirement (start_age, start_balance, info_work, info_retire);

  return 0;
}

