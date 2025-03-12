#include "temperature.h"
#include<stdio.h>

int main() {
  int choice;
  double temp, result;
  
  printf("Select 1 to enter temperature in Celsius \nSelect 2 to enter temperature in Farhenheit\n");
  scanf("%d", &choice);

  if(choice == 1) {
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &temp);
    result = celsius_to_fahrenheit(temp);
    printf("Temperature in Fahrenheit: %.2lf°F\n", result);
  }
  else if(choice == 2) {
    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &temp);
    result = fahrenheit_to_celsius(temp);
    printf("Temperature in Celsius: %.2lf°C\n", result);
  }
  else {
    printf("Invalid Choice!\n");
  }
  return 0;
}

