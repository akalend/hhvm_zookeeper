/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2015 Alexandre Kalendarev                              |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
	 part this code was derived from:
		  tarantool/msgpuck, author Roman Tsisyk
		  utf-8 detect, author Bjoern Hoehrmann
	 for HHVM version 3.13
  KindOfUninit          = 0x00,  //  00000000
  KindOfNull            = 0x01,  //  00000001
  KindOfBoolean         = 0x09,  //  00001001  9
  KindOfInt64           = 0x11,  //  00010001 17
  KindOfDouble          = 0x19,  //  00011001 25
  KindOfPersistentString = 0x1b, //  00011011 27
  KindOfPersistentArray = 0x1d,  //  00011101 29
  KindOfString          = 0x22,  //  00100010 34
  KindOfArray           = 0x34,  //  00110100 52
  KindOfObject          = 0x40,  //  01000000
*/

#include "hphp/runtime/ext/extension.h"
#include "hphp/runtime/base/execution-context.h"  // g_context
#include "hphp/runtime/base/type-object.h"  	  // Object
#include "hphp/runtime/base/builtin-functions.h"
#include "hphp/runtime/base/req-ptr.h"
#include "hphp/util/string-vsnprintf.h"


// #include "hphp/runtime/base/variable-serializer.h"
// #include "hphp/runtime/base/variable-unserializer.h"

#include "zookeeper.h"

#include "hhvm_zookeeper.h"



namespace HPHP {


/**
* static constant definition
*/
const StaticString
  s_zookeeper("Zookeeper"),
	s_zookeeper_res("zooRes");



//////////////////////////////////////////////////////////////////////////////////////////////

void ZookeeperExtension::moduleInit() {
	
	  HHVM_ME(Zookeeper, get);
    HHVM_ME(Zookeeper, set);
    HHVM_ME(Zookeeper, list);
    HHVM_ME(Zookeeper, connect);

    HHVM_ME(Zookeeper, init);
	


  // Native::registerConstant<KindOfInt64>(s_msgpack_ret_toarray.get(), 	MSGPACK_RET_TOARRAY);

	   loadSystemlib();

}

void ZookeeperExtension::moduleShutdown() {

}


//////////////////    static    /////////////////////////

static ZookeeperExtension s_Zookeeper_extension;


//////////////////    HHVM_FUNCTION     //////////////////

// ------------------------------  Zookeeper ------------------------------------------


  void HHVM_METHOD(Zookeeper, init) 
  {
    // "127.0.0.1:2081", NULL, 2000 
      req::ptr<ZooResource>  ptr = req::make<ZooResource>(); 
      Variant res = Variant(ptr);

      Object ob{Unit::loadClass(s_zookeeper.get())};


      printf("start init()\n");

    ob.o_set( s_zookeeper_res, Variant( 123 ), s_zookeeper);
      //ob.o_set( s_zookeeper_res, Variant( ptr ), s_zookeeper);

  }



  void HHVM_METHOD(Zookeeper, connect) 
  {

  
//      Resource = new ZooResource();

  }


  String HHVM_METHOD(Zookeeper, get, const String& path) 
  {

    return String("***");
  }



  void HHVM_METHOD(Zookeeper, list, const String& path) 
  {

    
  }


  void HHVM_METHOD(Zookeeper, set, const String& data) 
  {

    
  }




HHVM_GET_MODULE(Zookeeper);

} // namespace HPHP