#include <iostream>
#include "Complex.cpp" // Here is inclusion the complex.cpp library

int main() {
    // Create any two complex numbers
    Complex a(3, 4);
    Complex b(1, 2);
    
 
    Complex c = a + b;
    
    // Output the result
    std::cout << "Sum: " << c << std::endl;
    
    return 0;
}
