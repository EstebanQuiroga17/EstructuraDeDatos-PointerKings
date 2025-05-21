#include "../Model/InputValidator.h"
#include <iostream>
using namespace std;

int main(){
    int number;
    cin>> number;
    bool truth = InputValidator::isFloat(to_string(number));
    cout<<truth<<endl;
}