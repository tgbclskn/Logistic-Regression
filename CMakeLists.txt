cmake_minimum_required(VERSION 3.17)
project(LogisticRegression C)

set(CMAKE_C_STANDARD 99)

add_executable(LogisticRegression main.c numerical/matrix.c numerical/matrix.h util/printer.c util/printer.h regression/logistic.c regression/logistic.h preprocessing/load.c preprocessing/load.h)

target_link_libraries(LogisticRegression m)