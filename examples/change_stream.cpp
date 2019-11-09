//
// Created by stas on 9.11.19.
//
#include <iostream>
#include <fstream>

#include "../src/vtest.h"

VTEST(Default, test1){
    ASSERT_EQ(2, 3);
}

int main(){
    std::ofstream file("log.txt");

    vtest::default_ostream = &file;
    vtest::RunTest(vtest::MODULE{"Default"});

    file.close();
}