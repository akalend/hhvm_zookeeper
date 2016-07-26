include_directories(/usr/include/zookeeper)

HHVM_EXTENSION(zookeeper zookeeper.cpp)

 target_link_libraries(zookeeper /usr/lib/x86_64-linux-gnu/)

HHVM_SYSTEMLIB(zookeeper ext_zookeeper.php)



