#include <bitset>
#include <iostream>

// Poziv funkcije printBits rezultovace sa ispisom
// proslijedjenog broja u binarnoj formi.
//
// Primjer:
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// unsigned short s = 5;
// printBits(s);
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Ispis:
// 0000000000000101
// 
void printBits(unsigned short reg) {
  std::bitset<16> bits(reg);
  std::cout << bits << std::endl;
}


int main() {

  unsigned int regValue=0;

  std::cout << "1. Print register" << std::endl;
  std::cout << "2. Set bit in register" << std::endl;
  std::cout << "3. Reset bit in register" << std::endl;
  std::cout << "4. Exit" << std::endl;
  std::cout << "Enter option: ";
  int option;
  std::cin >> option;
  
  while(true) {
    if (option == 1) {
        printBits(regValue);
        break;
    } else if (option == 2) {
        int bitNum;
        std::cout << "Enter bit number: ";
        std::cin >> bitNum;
        regValue=regValue | (1<<bitNum); // 0000 0001<<2 -> 0000 0100 = 4
        std::cout << "New register value: " << regValue << std::endl;
        printBits(regValue);
        break;
    } else if (option == 3) {
        int bitNum;
        std::cout << "Enter bit number: ";
        std::cin >> bitNum;
        regValue=regValue & ~(1<<bitNum);
        std::cout << "New register value: " << regValue << std::endl; 
        printBits(regValue);
        break;
    } else if (option == 4) {
      break;
    }
    std::cout << std::endl;
  }

  return 0;
}
