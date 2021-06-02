cmake_minimum_required(VERSION 3.18)
project(sip_lesson_c C)

set(CMAKE_C_STANDARD 11)

add_executable(sip_lesson_c main.c)
add_executable(dec codec/g711dec.c)
add_executable(enc codec/g711enc.c)