cmake_minimum_required(VERSION 3.15)
project(food_ordering C)

set(CMAKE_C_STANDARD 99)

add_executable(food_ordering main.c dataInput.h dataInput.c extra.h extra.c orderConfirmation.h orderConfirmation.c displayData.h displayData.c constants.h create.h create.c memoryHandler.c memoryHandler.h)