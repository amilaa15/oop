#include <iostream>

int main(void)
{

int opcija;

char opcija1;
double const celukel=273.15;
double const celufahr=33.8;
double const fahrukel=255.92778;
double celsius;
double fahr;
double kelvin;

char opcija2;
double miles;
double kmeter;
double const mphukph=1.609344;
double const kphumph=0.621371192;

char opcija3;
double lighty;
double kmeters;
double foot;
double meters;
double inch;
double cmeters;
//long double const lyukm=9.4605284*10^12;
//long double const kmuly=1.05702341*10^(-13);
double const fum=0.3048;
double const muf=3.2808399;
double const inchucm=2.54;
double const cmuinch=0.393700787;

std::cout << "Welcome to Unit converter. Please enter one of the following options:\n";
std::cout << " 1. Temperature\n 2. Speed\n 3. Length\n 4. Weight\n 5. Fuel economy\n" << std::endl;

std::cin >> opcija;

std::cout << "Your choice: " << opcija << std::endl;

if(opcija==1){
  std::cout << "Please choose converter:\n";
  std::cout << " 1. Celsius to Fahrenheit\n 2. Fahrenheit to Celsius\n 3. Celsius to Kelvin\n 4. Kelvin to Celsius\n 5. Fahrenheit to Kelvin\n 6. Kelvin to Fahrenheit\n" << std::endl;
  std::cin >> opcija1;
  std::cout << "Your choice: " << opcija1 << std::endl;

  switch (opcija1){

    case '1':
      std::cout << "Enter temperature in degrees Celsius: ";
      std::cin >> celsius;
      std::cout << celsius << " degrees Celsius is " << celsius+celufahr << " degrees Fahrenheit." << std::endl;
    
    case '2':  
      std::cout << "Enter temperature in degrees Fahrenheit: ";
      std::cin >> fahr;
      std::cout << fahr << " degrees Fahrenheit is " << ((fahr-32)*5)/9 << " degrees Celsius." << std::endl;

    case '3':
      std::cout << "Enter temperature in degrees Celsius: ";
      std::cin >> celsius;
      std::cout << celsius << " degrees Fahrenheit is " << celsius+celukel << " degrees Kelvin." << std::endl;
    
    case '4':  
      std::cout << "Enter temperature in degrees Kelvin: ";
      std::cin >> kelvin;
      std::cout << kelvin << " degrees Kelvin is " << kelvin-celukel << " degrees Celsius." << std::endl;

    case '5':
      std::cout << "Enter temperature in degrees Fahrenheit: ";
      std::cin >> fahr;
      std::cout << fahr << " degrees Fahrenheit is " << fahr+fahrukel << " degrees Kelvin." << std::endl;
 
    case '6':  
      std::cout << "Enter temperature in degrees Kelvin: ";
      std::cin >> kelvin;
      std::cout << kelvin << " degrees Kelvin is " << 1.8*(kelvin-273)+32 << " degrees Fahrenheit." << std::endl;
  }
}
else if (opcija==2){
  std::cout << "Please choose converter:\n";
  std::cout << " 1. Miles per hour to kilometer per hour\n 2. Kilometer per hour to miles per hour\n" << std::endl;
  std::cin >> opcija2;
  std::cout << "Your choice: " << opcija2<< std::endl;

  switch (opcija2){

    case '1':
      std::cout << "Enter speed in miles per hour:\n";
      std::cin >> miles;
      std::cout << miles << " miles per hour is " << miles*mphukph << " kilometer per hour." << std::endl;

    case '2':
      std::cout << "Enter speed in kilometer per hour:\n";
      std::cin >> kmeter;
      std::cout << kmeter << " kilometer per hour is " << miles*kphumph << "miles per hour." << std::endl;
  }
}
else if (opcija==3){
  std::cout << "Please choose converter:\n";
  std::cout << " 1. Light years to kilometers\n 2. Kilometers to light years\n 3. Foot to meters\n 4. Meters to foot\n 5. Inch to centimeter\n 6. Centimeter to inch " << std::endl;
  std::cin >> opcija3;
  std::cout << "Your choice: " << opcija3 << std::endl;

  switch (opcija3){

    case '1':
      std::cout << "Enter lenght in degrees light years: ";
      std::cin >> lighty;
      //std::cout << lighty << " light years is " << lighty*9.4605284*10^12 << " kilometers." << std::endl;
    
    case '2':  
      std::cout << "Enter lenght in kilometers: ";
      std::cin >> kmeters;
     // std::cout << kmeters << " kilometers is " << kmeters*1.05702341*10^(-13) << " light years." << std::endl;

    case '3':
      std::cout << "Enter lenght in foot: ";
      std::cin >> foot;
      std::cout << foot << " foot is " << foot*fum << " meters." << std::endl;
    
    case '4':  
      std::cout << "Enter lenght in meters: ";
      std::cin >> meters;
      std::cout << meters << " meters is " << meters*muf << " foot." << std::endl;

    case '5':
      std::cout << "Enter lenght in inches: ";
      std::cin >> inch;
      std::cout << inch << " inch is " << inch*inchucm << " centimeters." << std::endl;
 
    case '6':  
      std::cout << "Enter lenght in centimeters: ";
      std::cin >> cmeters;
      std::cout << cmeters << " centimeters is " << cmeters*cmuinch << " inch." << std::endl;
  }

//sve na isti fazon.
}
  return 0;
}
