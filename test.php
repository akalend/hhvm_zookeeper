<?hh // decl

//print_r(get_loaded_extensions());

 $zoo = new Zookeeper('','',1000);

var_dump($zoo);

 $zoo->connect();

