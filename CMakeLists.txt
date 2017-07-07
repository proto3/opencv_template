cmake_minimum_required(VERSION 2.8)
project(myProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

################################################################################
#PACKAGES
find_package(OpenCV REQUIRED)
#find_package(yaml-cpp REQUIRED)
#find_package(Boost REQUIRED COMPONENTS system filesystem)
#find_package (Threads)

################################################################################
#INCLUDES
include_directories(
    include
#    ${Boost_INCLUDE_DIRS}
#    ${YAML_CPP_INCLUDE_DIR}
)

################################################################################
#SOURCES
file(GLOB_RECURSE MYPROJECT_SRC "src/MyProject/*.cpp")

################################################################################
#LINK
LIST(APPEND LINK_LIBS
   ${OpenCV_LIBS}
#   ${YAML_CPP_LIBRARIES}
#   ${Boost_SYSTEM_LIBRARY}
#   ${Boost_FILESYSTEM_LIBRARY}
#   ${CMAKE_THREAD_LIBS_INIT}
)

################################################################################
#EXECUTABLE
add_executable(${PROJECT_NAME} ${MYPROJECT_SRC} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${LINK_LIBS})
