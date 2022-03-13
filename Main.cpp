#include <iostream>
#include "mat.hpp"
#include <string>
#include <stdexcept>
#include <vector>

int main() {

    int const number_1=9;
    int const number_2=7;
    std::cout<<"first mat: 7*9 @- "<<endl;
    std::cout << ariel::mat(number_1, number_2, '@', '-') << endl;

    int const number_3=11;
    int const number_4=3;
    std::cout<<"second mat: 11*3 +# "<<endl;
    std::cout << ariel::mat(number_3, number_4, '+', '#') << endl;

    int const number_5=1;
    int const number_6=9;
    std::cout<<"third mat: 1*9 ^& "<<endl;
    std::cout << ariel::mat(number_5, number_6, '^', '&') << endl;

    std::cout<<"let's see some exceptions:"<<endl;
    try {
        cout << ariel::mat(10, 5, '$', '%') << endl; // Exception - not a valid code
    } catch (exception& ex) {
        cout << "   caught exception: " << ex.what() << endl;  // should print "Mat size is always odd"
    }

    try {
        cout << ariel::mat(0, 7, '$', '%') << endl; // Exception - not a valid code
    } catch (exception& ex) {
        cout << "   caught exception: " << ex.what() << endl;  // should print "zero or negative input error"
    }

    try {
        cout << ariel::mat(5, -7, '$', '%') << endl; // Exception - not a valid code
    } catch (exception& ex) {
        cout << "   caught exception: " << ex.what() << endl;  // should print "zero or negative input error"
    }

    try {
        cout << ariel::mat(5, 3, '\n', '%') << endl; // Exception - not a valid code
    } catch (exception& ex) {
        cout << "   caught exception: " << ex.what() << endl;  // should print "invalid character"
    }
    int a,b;
    char c1,c2;
    std:cout<<"now- try it yourself: enter 2 numbers and 2 characters"<<endl;
    std::cin>>a;
    std::cin>>b;
    std::cin>>c1;
    std::cin>>c2;
    try {
        std::cout<<ariel::mat(a,b,c1,c2)<<endl;
    } catch (exception& ex) {
        cout << "   caught exception: " << ex.what() << endl;
    }


    return 0;
}
