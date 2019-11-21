//
// Created by stas on 21.11.2019.
//

#ifndef VIL_TEST_GLOBALS_H
#define VIL_TEST_GLOBALS_H

#include <map>
#include <string>

namespace vtest{
    std::ostream *default_ostream = &std::cerr;
    std::map<std::string, std::map<std::string, void (*)()>> TestModules;
}

#endif //VIL_TEST_GLOBALS_H
