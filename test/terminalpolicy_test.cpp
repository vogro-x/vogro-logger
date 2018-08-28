#include <iostream>
#include "../policy.hpp"

int main(void){
    TerminalPolicy tpy("placehold");

    tpy.open_ostream();

    tpy.write("hello,wolrd");

    tpy.close_ostream();
    
    return 0;
}