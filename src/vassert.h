//
// Created by stas on 9.11.19.
//

#ifndef VIL_TEST_VASSERT_H
#define VIL_TEST_VASSERT_H
#include <string>
#include <sstream>

#include "failed_assert_exception.h"

#define ASSERT_EQ(first, second) vtest::AssertEquals(first, second, __LINE__, __FILE__)

namespace vtest {
    template<typename T1, typename T2>
    void AssertEquals(const T1 &first, const T2 &second, int line, const std::string& file_name) {
        if (first != second) {
            std::stringstream ss;
            ss << "Assert failed on line: " << line <<
                  ".  In file: " << file_name;
            throw vtest::FailedAssertException(&ss.str()[0]);
        }
    }
};
#endif //VIL_TEST_VASSERT_H
