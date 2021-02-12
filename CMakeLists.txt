cmake_minimum_required(VERSION 3.17)
project(LogisticRegression C)

set(CMAKE_C_STANDARD 99)

add_executable(LogisticRegression main.c util/numc.c util/numc.h util/printer.c util/printer.h)