HHVM_EXTENSION(zookeeper zookeeper.cpp)

include_directories(include)

HHVM_SYSTEMLIB(zookeeper ext_zookeeper.php)


