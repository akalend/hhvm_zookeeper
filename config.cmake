include_directories(/usr/include/zookeeper)

HHVM_EXTENSION(zookeeper zookeeper.cpp)

add_dependencies(zookeeper zookeeper_st)
target_link_libraries(zookeeper  -lzookeeper_st  /usr/lib/x86_64-linux-gnu/)

HHVM_SYSTEMLIB(zookeeper ext_zookeeper.php)
