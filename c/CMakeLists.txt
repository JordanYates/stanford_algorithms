cmake_minimum_required (VERSION 2.6)
project (StanfordAssignments)

add_executable(karatsuba.out executables/karatsuba_multiplication.c)
target_link_libraries(karatsuba.out m)
