#include <iomanip>
#include <iostream>
#include <string>
#include "PhoneNumber.h"
using namespace std;

ostream &operator<<( ostream &output, const PhoneNumber &number )
{
   output << "(" << number.areaCode << ") "
      << number.exchange << "-" << number.line;
   return output; // enables cout << a << b << c;
} // end function operator<< 

istream &operator>>( istream &input, PhoneNumber &number )
{
   input.ignore(); // skip (
   input >> setw( 2 ) >> number.areaCode; // Codigo de area são 2 digitos
   input.ignore( 2 ); // skip ) and space

   if(number.areaCode == "11" || number.areaCode == "29")
      input >> setw( 5 ) >> number.exchange; // nono digito
   else
      input >> setw( 4 ) >> number.exchange; 

   input.ignore(); // skip dash (-)
   input >> setw( 4 ) >> number.line; // input line
   return input; 
}