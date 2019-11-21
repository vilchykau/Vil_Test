add_executable(expample_asserts asserts.cpp)
add_executable(vtest_fun vtest_function.cpp)
add_executable(change_stream change_stream.cpp)

target_link_libraries(vtestLib asserts.cpp)
target_link_libraries(vtestLib vtest_function.cpp)
target_link_libraries(vtestLib change_stream.cpp)