//
// Created by stas on 9.11.19.
//

#ifndef VIL_TEST_FAILED_ASSERT_EXCEPTION_H
#define VIL_TEST_FAILED_ASSERT_EXCEPTION_H

#include <exception>
#include <string>

namespace vtest {
    class FailedAssertException : public std::runtime_error {
    public:
        FailedAssertException(const char* msg) : std::runtime_error(msg)
        {

        };
    };
}
#endif //VIL_TEST_FAILED_ASSERT_EXCEPTION_H
