//
// Created by stas on 9.11.19.
//
#include <iostream>

#include "../src/vtest.h"

int main(){
    ASSERT_EQ(4, 4);
    ASSERT_EQ_MSG(4,5, "Hello world");
    ASSERT_EQ(4,5);

    return 0;
}