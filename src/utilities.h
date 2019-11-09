//
// Created by stas on 9.11.19.
//

#ifndef VIL_TEST_UTILITIES_H
#define VIL_TEST_UTILITIES_H

#include <string>
#include <sstream>

#include "failed_assert_exception.h"
#include "vtest_function.h"

#define HIDE_EXC(fun) try {\
fun;\
}\
catch (vtest::FailedAssertException& e){\
(*vtest::default_ostream) << e.what() << '\n';\
}

namespace vtest{
    template <typename T1, typename T2>
    std::string VAL_TO_STR(const T1 first, const T2 second){
        std::stringstream ss;
        ss << first << "  and  " << second;
        return ss.str();
    }

    void HideException(void(*fun)()){
        try {
            fun();
        }
        catch (FailedAssertException& e){
            (*vtest::default_ostream) << e.what() << '\n' << '\n';
        }
    }
}
#endif //VIL_TEST_UTILITIES_H
