cmake_minimum_required(VERSION 3.1)

project(StanfordAlgorithms)

set(CMAKE_CXX_STANDARD 14)
set(SRC_APP_DIR "src_app")

include_directories("include")

file(GLOB HEADERS "include/*.h" "include/*.hpp")
file(GLOB SRC_LIB "src/*.c" "src/*.cpp")

add_library(StanAlg STATIC ${SRC_LIB} ${HEADERS})

add_executable(invcount "${SRC_APP_DIR}/invcount.cpp" ${HEADERS})
target_link_libraries(invcount StanAlg)

add_executable(mergesort "${SRC_APP_DIR}/mergesort.cpp" ${HEADERS})
target_link_libraries(mergesort StanAlg)

install(TARGETS StanAlg DESTINATION lib)
install(TARGETS invcount DESTINATION bin)
install(FILES ${HEADERS} DESTINATION include)
