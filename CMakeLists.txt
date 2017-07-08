cmake_minimum_required(VERSION 3.1)

project(StanfordAlgorithms)

set(CMAKE_CXX_STANDARD 14)
set(SRC_APP_DIR "src_app")

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
include_directories("include")

file(GLOB HEADERS "include/*.h" "include/*.hpp")
file(GLOB SRC_LIB "src/*.c" "src/*.cpp")

add_library(StanAlg STATIC ${SRC_LIB} ${HEADERS})

add_executable(invcount "${SRC_APP_DIR}/invcount.cpp" ${HEADERS})
target_link_libraries(invcount StanAlg ${Boost_LIBRARIES})

add_executable(mergesort "${SRC_APP_DIR}/mergesort.cpp" ${HEADERS})
target_link_libraries(mergesort StanAlg ${Boost_LIBRARIES})

add_executable(playwithvectors "spikes/playwithvectors.cpp" ${HEADERS})
target_link_libraries(playwithvectors StanAlg ${Boost_LIBRARIES})

install(TARGETS StanAlg DESTINATION lib)
install(TARGETS invcount DESTINATION bin)
install(FILES ${HEADERS} DESTINATION include)
