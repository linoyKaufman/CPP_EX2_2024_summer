
#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <string>
#include <cmath>
#include <sstream>
#include <iostream>

//class for complex number
using namespace std;
class Complex{
private:
    //real part of the complex number 
    double real_;
    //image part of the complex number 
    double image_;

public:
//constractor
    Complex(double real_ = 0.0, double image_ = 0.0) : real_(real_), image_(image_) {}

//return the real part of the complex number
    double get_real() const{
        return real_;
    }
//return the image part of the complex number
    double get_image() const{
        return image_;
    }
//operator >
bool operator>(const Complex& other) const {
    if(real_> other.get_real()|| (real_ == other.get_real() && image_ > other.get_image())){
        return true;
    }
    else {
        return false;
    }
}
//operator ==
bool operator==(const Complex& other) const {
    if(real_== other.real_ && image_== other.image_){
        return true;
    }
    else{
        return false;
    }
}

//operator <<
friend ostream &operator<<(ostream &os, const Complex &complex){
        os << complex.to_string();
        return os;
    }
//help function to operator <<
string to_string() const{
        ostringstream os;
        os << std::fixed << std::setprecision(2); 
        os << "(" << real_<< " + " << image_ << "i)";
        return os.str();
    }
};
#endif
