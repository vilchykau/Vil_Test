//
// Created by stas on 9.11.19.
//

#ifndef VIL_TEST_UTILITIES_H
#define VIL_TEST_UTILITIES_H

#include <string>
#include <sstream>

namespace vtest{
    template <typename T1, typename T2>
    std::string VAL_TO_STR(const T1 first, const T2 second){
        std::stringstream ss;
        ss << first << "  and  " << second;
        return ss.str();
    }
}
#endif //VIL_TEST_UTILITIES_H
