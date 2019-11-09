//
// Created by stas on 9.11.19.
//

/*#define VTEST(ModuleName, TestName) \
void ModuleName##TestName();\
char ModuleName##TestName##_Init(){\
    vtest::TestModules[#ModuleName][#TestName] = &ModuleName##TestName;\
    return 0;\
}\
char ModuleName##TestName##_Init_Value = ModuleName##TestName##_Init();\
void ModuleName##TestName()
*/

#ifndef VIL_TEST_VTEST_FUNCTION_H
#define VIL_TEST_VTEST_FUNCTION_H

#include <map>
#include <vector>
#include <string>
#include <ostream>
#include <iostream>

#include "failed_assert_exception.h"
#include "vtest_function_header.h"


namespace vtest{
    struct ALL_TESTS{};
    struct MODULE{std::string name;};
    struct TEST{std::string module; std::string test;};

    std::ostream *default_ostream = &std::cerr;

    std::map<std::string, std::map<std::string, void (*)()>> TestModules;

    void RunFunction(const std::string& module_name, const std::string& test_name);

    void AddTest(const std::string module_name, const std::string test_name, void (*fun)()){
        TestModules[module_name][test_name] = fun;
    }

    void RunTest(ALL_TESTS allTests){
        for(const auto& module_pair : TestModules){
            for(const auto& test_pair : module_pair.second){
                RunFunction(module_pair.first, test_pair.first);
            }
        }
    }

    void RunTest(MODULE module){
        for(const auto& test_pair : TestModules[module.name]){
            RunFunction(module.name, test_pair.first);
        }
    }

    void RunTest(TEST test){
        RunFunction(test.module, test.test);
    }

    void RunFunction(const std::string& module_name, const std::string& test_name){
        try{
            TestModules[module_name][test_name]();
        }catch (FailedAssertException& e){
            (*default_ostream) << "Failed in Module: " << module_name <<
                               "   Test: " << test_name << '\n' << e.what() << '\n' << std::endl;
        }
    }
};

#endif //VIL_TEST_VTEST_FUNCTION_H
