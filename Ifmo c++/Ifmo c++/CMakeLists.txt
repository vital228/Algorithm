SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}  -Wno-deprecated)
FIND_PACKAGE(PkgConfig)
pkg_search_module(LibXML++ REQUIRED libxml++-2.6)

include_directories(${LibXML++_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${LibXML++_LIBRARIES})