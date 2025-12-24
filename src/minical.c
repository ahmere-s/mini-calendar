#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year){
  if (year % 400 == 0){return true;}
  else if (year % 100 == 0){return false;}
  else if (year % 4 == 0){return true;}
  else{return false;}
}

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  /* Number of days in each of the twelve
months starting with index one for January ending on index twelve for December */

void add_days_to_date(int* month, int* day, int* year, int days_left_to_add){
  while (days_left_to_add > 0){
    int dim_count = days_in_month[*month]; //get number of days using given param *month
    
    //update dim_count if month is feb AND its a leap year
    if (*month == 2 && is_leap_year(*year) == true){dim_count += 1;}
    int days_left_in_month = dim_count - *day;

    if (days_left_to_add > days_left_in_month){
      days_left_to_add -= (days_left_in_month + 1);
      *day = 1;
      //Return to January if its December, then increment the new year
      if(*month == 12){*month = 1; *year += 1;}
      else{*month += 1;} //Otherwise just increment the month
    }
    else{
      *day += days_left_to_add;
      days_left_to_add = 0;
    }
  }
}

int main(){
  int mm, dd, yy, days_to_add;

  printf("%s\n", "Please enter a date between the years 1800 and 10000 in the format (month# day year) along with the number of days you wish to add to this date. (month# day year numDaysToAdd) Make sure to add a space between each and press enter!: ");
  
  scanf("%d %d %d %d", &mm, &dd, &yy, &days_to_add);
  
  add_days_to_date(&mm, &dd, &yy, days_to_add);

  printf("Your new date is %d/%d/%d\n", mm, dd, yy);

}

