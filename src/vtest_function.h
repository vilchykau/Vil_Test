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
#include "TestComplete.h"


namespace vtest{
    struct ALL_TESTS{};
    struct MODULE{std::string name;};
    struct TEST{std::string module; std::string test;};

    std::ostream *default_ostream = &std::cerr;

    std::map<std::string, std::map<std::string, void (*)()>> TestModules;

    bool RunFunction(const std::string& module_name, const std::string& test_name);

    void AddTest(const std::string module_name, const std::string test_name, void (*fun)()){
        TestModules[module_name][test_name] = fun;
    }

    void RunTest(ALL_TESTS allTests){
        TestComplete testComplete;
        for(const auto& module_pair : TestModules){
            for(const auto& test_pair : module_pair.second){
                testComplete.SetTestStatus(module_pair.first, test_pair.first, RunFunction(module_pair.first, test_pair.first));
            }
        }
        (*default_ostream) << testComplete;
    }

    void RunTest(MODULE module){
        TestComplete testComplete;
        for(const auto& test_pair : TestModules[module.name]){
            testComplete.SetTestStatus(module.name, test_pair.first, RunFunction(module.name, test_pair.first));
        }
        (*default_ostream) << testComplete;
    }

    void RunTest(TEST test){
        TestComplete testComplete;
        testComplete.SetTestStatus(test.module, test.test, RunFunction(test.module, test.test));
        (*default_ostream) << testComplete;
    }

    bool RunFunction(const std::string& module_name, const std::string& test_name){
        try{
            TestModules[module_name][test_name]();
            return true;
        }catch (FailedAssertException& e){
            std::stringstream ss;
            ss << "Failed in Module: " << module_name <<
                                    "   Test: " << test_name << '\n' << e.what() << '\n' << std::endl;
            (*default_ostream) << ss.str();
            return false;
        }
    }
};

#endif //VIL_TEST_VTEST_FUNCTION_H
