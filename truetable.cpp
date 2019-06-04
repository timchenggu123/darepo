#include <iostream>
#include "operations.h"

using namespace std;
int main(int argc, char* argv[] ){
    //static variables:
    const int OPERATOR_AND = 45;
    const int OPERATOR_OR = 43;
    const int OPERATION_AND = 0;
    const int OPERATION_OR = 1;

    //variable declaration:
    int operation = -1;
    char func_in[11];
    int func_in_size = 10;
    for (int i = 0; i < 10; i++){
        func_in[i] = 0;
    }
    //code begins
    char* main_in = argv[1];
    int i = 0;
    int j = 0;
    while (main_in[i] != 0){
        int ascii_code = (int) main_in[i];
        switch (ascii_code){
            case OPERATOR_AND:
                operation = OPERATION_AND;
                break;
            case OPERATOR_OR:
                operation = OPERATION_OR;
                break;
            default:
                func_in[j] = ascii_code;
                j ++;
                break;
        }
        i++;
    }

    func_in_size = j;

    switch (operation){
        case OPERATION_AND:
            func_and(func_in, func_in_size);
            break;
        case OPERATION_OR:
            func_or(func_in, func_in_size);
            break;
        default:
            cout<< "invalid operator"<<endl;
            break;
    }

    return 0;       
}