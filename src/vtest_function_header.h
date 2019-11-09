//
// Created by stas on 9.11.19.
//

#ifndef VIL_TEST_VTEST_FUNCTION_HEADER_H
#define VIL_TEST_VTEST_FUNCTION_HEADER_H
//Чтобы зарегать функцию создается функция инициализации.
//Чтобы вызвать функцию инициализации создается мусорная ссылка,
//которая присваивается функции.


int _VTEST_VALUE_FOR_FUN_DEFINE = 0;
int& _V_TEST_CALL_REGISTR_FUN(void (*fun)()){
    fun();
    return _VTEST_VALUE_FOR_FUN_DEFINE;
}

#define VTEST(ModuleName, TestName) \
void ModuleName##TestName();\
_VTEST_CREATE_INIT_FUNCTION(ModuleName, TestName)\
_VTEST_CALL_INIT_FUNCTION(ModuleName, TestName) \
void ModuleName##TestName()

#define _VTEST_CREATE_INIT_FUNCTION(ModuleName, TestName)\
void ModuleName##TestName##_Init(){\
    vtest::TestModules[#ModuleName][#TestName] = &ModuleName##TestName;\
}

#define _VTEST_CALL_INIT_FUNCTION(ModuleName, TestName) \
int& ModuleName##TestName##_Init_Value = _V_TEST_CALL_REGISTR_FUN(ModuleName##TestName##_Init);

#endif //VIL_TEST_VTEST_FUNCTION_HEADER_H
