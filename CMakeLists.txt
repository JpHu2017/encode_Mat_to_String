cmake_minimum_required(VERSION 2.8)

project(cvmat2string)

set(OpenCV_DIR "/home/cvrsg/opencv-build/opencv-3.2.0/share/OpenCV")

find_package(OpenCV REQUIRED)

add_executable(cvmat2string example.cpp)

target_link_libraries(cvmat2string ${OpenCV_LIBS})
