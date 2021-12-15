file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${aoc2021_SOURCE_DIR}/include/*.hpp")
file(GLOB SOURCEFILES ./*)

add_library(Library SHARED ${SOURCEFILES} ${HEADER_LIST})
target_include_directories(Library PUBLIC "../include")
target_compile_features(Library PUBLIC cxx_std_20)
