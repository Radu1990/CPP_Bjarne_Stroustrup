#include "drill.h"
#include "std_lib_facilities.h"

// This program includes the Drill Exercise from
// Chapter 11. Customizing Input and Output



void f_1(){
    // ...
    int birth_year = 1990;
    int age = 29;

    // print birth-year without showing bases
    cout << "print birth-year with visible bases\n";
    cout << "\ndec" << '\t' << dec << birth_year << '\n'
         << "hex" << '\t' << hex << birth_year << '\n'
         << "oct" << '\t' << oct << birth_year << '\n';

    // print age
    cout << "printing age\n";
    cout << dec << age << '\n';

    cout << "print birth-year with not visible bases";
    // print birth-year with showing bases
    cout << showbase << dec;
    cout << "\ndec" << '\t' << dec << birth_year << '\n'
         << "hex" << '\t' << hex << birth_year << '\n'
         << "oct" << '\t' << oct << birth_year << '\n';

}

void f_2(){

    // try reading as octal- hexadecimal etc
    int a, b, c;
    istringstream is {"1234 1234 1234"};

    /* input:
     * interpret integer 1234 as decimal -> a = 1234 decimal
     * interpret integer 1234 as octal -> b = 668 decimal
     * interpret integer 1234 as hexadecimal -> c = 4660 decimal
     * output:
     * print a, b, c.

    for example 1234 as a decimal value = 1*10^3 + 2*10^2 + 3*10^1 + 4*10^0 = 1000 + 200 + 30 + 4 = 1234 decimal
                1234 as a octal value = 1 * 8^3 + 2*8^2 + 3*8^1 + 4*8^0 = 512 + 128 + 24 + 4 = 668 decimal
                1234 as a hexadecimal value = 1 * 16^3 + 2*16^2 + 3*16^1 + 4*16^0 = 4096 + 512 + 48 + 4 = 4660 decimal
    */
    is >> a >> oct >> b >> hex >> c;
    // here we read decimal a 1234 as decimal value 1234
    cout << '\n' << "decimal val 1234 = decimal " << a << '\n'
    // here we read octal b 1234 as decimal value 668
         << "octal val 1234 = decimal " << b << '\n'
    // here we read hex c 1234 as decimal value 4660
         << "hexadecimal val 1234 = decimal " << c << '\n';

    /* input:
     * interpret 1234, 668 and 4660 as integer values:
     * =>       a = 1234, b = 668 and c = 4660
     * output:
     * output integer value a=1234 as decimal value 1234
     * output integer value b=668 as octal value 1234
     * output integer value c=4660 as hexadecimal 1234
     * converting 668 to decimal by repeatedly dividing by 8
     * and writing the remainder from right to left
     * ex: 668/8 = 83 r 4 83/8 = 10 r 3
     * 10/8 = 1 r 2 and 1/8 = 0 r 1
     * result 1234
    */
    istringstream is2 {"1234 668 4660"};
    is2 >> a >> b >> c;
    cout << '\n' << "decimal val 1234 = decimal value " << a << '\n'
         << "decimal val 668 = octal value " << oct << b << '\n'
         << "decimal val 4660 = hexadecimal value " << hex << c << '\n';

}

void f_3(){
    double a = 1234567.89;
    cout << '\n';
    cout << defaultfloat << a << " default float" << '\t'
         << fixed << a << " default float" << '\t'
         << scientific << a << " default float" << '\t';
}
