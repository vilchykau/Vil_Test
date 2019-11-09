//
// Created by stas on 9.11.19.
//

#include <iostream>

#include "../src/vtest.h"

VTEST(Module1, TestName1){
    std::cout << "module1 - test1" << std::endl;
}

VTEST(Module1, TestName2){
    std::cout << "module1 - test2" << std::endl;
}

VTEST(Module2, TestName1){
    std::cout << "module2 - test2" << std::endl;
}


int main(){
    std::cout << "Run module test: " << std::endl;
    vtest::RunTest(vtest::MODULE{"Module2"});
    std::cout << std::endl << std::endl;

    std::cout << "Run all tests: " << std::endl;
    vtest::RunTest(vtest::ALL_TESTS{});
    std::cout << std::endl << std::endl;

    std::cout << "Run single tests: " << std::endl;
    vtest::RunTest(vtest::TEST{"Module1", "TestName2"});
    std::cout << std::endl << std::endl;

    return 0;
}