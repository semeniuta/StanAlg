cmake_minimum_required(VERSION 3.1)

project(StanfordAlgorithms)

set(CMAKE_CXX_STANDARD 14)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
include_directories("include")

file(GLOB HEADERS "include/*.h")
file(GLOB SRC_LIB "src/*.cpp")
file(GLOB SRC_APP "src_app/*.cpp")
file(GLOB SRC_SPIKE "spikes/*.cpp")

add_library(StanAlg STATIC ${SRC_LIB} ${HEADERS})

foreach(source_file_full ${SRC_APP})
  get_filename_component(appname ${source_file_full} NAME_WE)
  get_filename_component(source_file ${source_file_full} NAME)
  add_executable(${appname} "src_app/${source_file}" ${HEADERS})
  target_link_libraries(${appname} StanAlg ${Boost_LIBRARIES})
endforeach()

foreach(source_file_full ${SRC_SPIKE})
  get_filename_component(appname ${source_file_full} NAME_WE)
  get_filename_component(source_file ${source_file_full} NAME)
  add_executable(${appname} "spikes/${source_file}" ${HEADERS})
  target_link_libraries(${appname} StanAlg ${Boost_LIBRARIES})
endforeach()

#install(TARGETS StanAlg DESTINATION lib)
#install(TARGETS invcount DESTINATION bin)
#install(FILES ${HEADERS} DESTINATION include)
