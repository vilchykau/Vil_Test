//
// Created by stas on 9.11.19.
//

#ifndef VIL_TEST_TESTCOMPLETE_H
#define VIL_TEST_TESTCOMPLETE_H

#include <map>
#include <string>
#include <ostream>

namespace vtest{
  class TestComplete{
  public:
      void SetTestStatus(const std::string& module_name, const std::string& test_name, bool state){
          TestsStates[module_name][test_name] = state;
      }

      std::map<std::string, std::map<std::string, bool>>& GetTestsStates(){
          return TestsStates;
      }
  private:
      std::map<std::string, std::map<std::string, bool>> TestsStates;
  };

  std::string BooleanToStatus(bool b){
      return b ? "OK    " : "FAILED";
  }

  std::ostream& operator<<(std::ostream& stream, TestComplete& testComplite){
      std::stringstream ss;
      ss << "\n#######################\n";
      ss << "State # Module name # Test name\n";
      for(const auto& module_pair : testComplite.GetTestsStates()){
          for(const auto& test_pair : module_pair.second){
              ss << BooleanToStatus(test_pair.second) << "  " <<
                     module_pair.first << "  " <<
                     test_pair.first << '\n';
          }
      }
      ss << "\n#######################\n";
      stream << ss.str();
      return stream;
  }
};
#endif //VIL_TEST_TESTCOMPLETE_H
