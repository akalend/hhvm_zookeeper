HHVM_EXTENSION(zookeeper zookeeper.cpp)


FIND_PATH(LIBZOOKEEPER_LIBRARY_INCLUDE_DIR zookeeper/zookeeper.h)

find_library(LIBZOOKEEPER_LIBRARY NAMES zookeeper_st)

include_directories(${LIBZOOKEEPER_INCLUDE_DIR})

target_link_libraries(zookeeper  ${LIBZOOKEEPER_LIBRARY})

HHVM_SYSTEMLIB(zookeeper ext_zookeeper.php)


