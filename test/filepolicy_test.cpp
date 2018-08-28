#include <iostream>
#include <string>
#include "../policy.hpp"

int main(void){
    
    FilePolicy fpy("vogro.log");

    fpy.open_ostream();

    fpy.write("hello,world");

    fpy.close_ostream();

    return 0;
}