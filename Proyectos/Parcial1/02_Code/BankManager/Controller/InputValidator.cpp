#include "../Model/InputValidator.h"
#include <stdexcept>
#include <regex>
#include <conio.h>
using namespace std;


float InputValidator::isFloat(string message) {
    try {
        char c;
        bool dot=false;
        int valor,i=0;
        char dato[10];
        printf("%s",message.c_str());
        while((c=getch())!=13){
            if(c>='0'&& c<='9' || c=='.'){
                if(i==0 && c=='.'){
                    continue;
                }
                if(c=='.'){
                    if(dot){
                        continue;
                    }
                    dot=true;
                }
                dato[i++]=c;
                printf("%c",c);
            }
        }
        dato[i]='\0';
        valor=atof(dato);
        printf("\n");
        return static_cast<float>(atof(dato));
    } catch (...) {
        return 0.0f;
    }
    return 0.0f;
}

int InputValidator::isInteger(string input) {
    try {
        char c;
	int valor,i=0;
	char dato[10];
	printf("%s",input);
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			dato[i++]=c;
			printf("%c",c);
		}
	}
	dato[i]='\0';
	valor=atoi(dato);
	printf("\n");
	return valor;
    } catch (...) {
        return 0;
    }
    return 0;
}

bool InputValidator::isEmail(string input) {
    try {
        regex pattern(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.(com|net|org|gov|edu|edu\.ec|es|info|co|ec)$)");
        if (!regex_match(input, pattern)) {
            throw invalid_argument("Email no valido.");
        }
        return true;
    } catch (...) {
        return false;
    }
    return false;
}
