<?hh
/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2016 Alexandre Kalendarev                              |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

class Zookeeper {

   /* class constants */
   const PERM_READ   = 1;
   const PERM_WRITE  = 2;
   const PERM_CREATE = 4;
   const PERM_DELETE = 8;
   const PERM_ADMIN  = 16;
   const PERM_ALL    = 31;
   const EPHEMERAL = 1;
   const SEQUENCE  = 2;
   const EXPIRED_SESSION_STATE = -112;
   const AUTH_FAILED_STATE     = -113;
   const CONNECTING_STATE      = 1;
   const ASSOCIATING_STATE     = 2;
   const CONNECTED_STATE       = 3;
   const NOTCONNECTED_STATE    = 999;
   const CREATED_EVENT         = 1;
   const DELETED_EVENT         = 2;
   const CHANGED_EVENT         = 3;
   const CHILD_EVENT           = 4;
   const SESSION_EVENT         = -1;
   const NOTWATCHING_EVENT     = -2;
   const LOG_LEVEL_ERROR = 1;
   const LOG_LEVEL_WARN  = 2;
   const LOG_LEVEL_INFO  = 3;
   const LOG_LEVEL_DEBUG = 4;
   const SYSTEMERROR          = -1;
   const RUNTIMEINCONSISTENCY = -2;
   const DATAINCONSISTENCY    = -3;
   const CONNECTIONLOSS       = -4;
   const MARSHALLINGERROR     = -5;
   const UNIMPLEMENTED        = -6;
   const OPERATIONTIMEOUT     = -7;
   const BADARGUMENTS         = -8;
   const INVALIDSTATE         = -9;
   const OK         = 0;
   const APIERROR   = -100;
   const NONODE     = -101;
   const NOAUTH     = -102;
   const BADVERSION = -103;
   const NOCHILDRENFOREPHEMERALS = -108;
   const NODEEXISTS = -110;
   const NOTEMPTY   = -111;
   const SESSIONEXPIRED  = -112;
   const INVALIDCALLBACK = -113;
   const INVALIDACL      = -114;
   const AUTHFAILED      = -115;
   const CLOSING         = -116;
   const NOTHING         = -117;
   const SESSIONMOVED    = -118;


   private $zooRes = null;

   public function  __construct(private string ?$host = '127.0.0.1:2181', private string ?$watcher_cb = null, private int ?$recv_timeout = 10000)
   {
        if ($recv_timeout < 0) {
            throw new ArgumentException("recv_timeout parameter has to be greater than 0");
         }

         $this->zooRes = init();
   }


   <<__Native>>
   private function init() : void;


   <<__Native>>
   public function connect() : void;

   <<__Native>>
   public function set(string $data) : void;

   <<__Native>>
   public function get(string $path) : string;

   <<__Native>>
   public function list(string $path) : void;

/* if the host is provided, attempt to connect. */
   // public function __construct( $host = '', $watcher_cb = null, $recv_timeout = 10000) {}
   // public function connect( $host, $watcher_cb = null, $recv_timeout = 10000) {}
   // public function create( $path, $value, $acl, $flags = null ) {}
   // public function delete( $path, $version = -1 ) {}
   // public function set( $path, $data, $version = -1, &$stat = null ) {}
   // public function get( $path, $watcher_cb = null, &$stat = null, $max_size = 0) {}
   // public function getChildren( $path, $watcher_cb = null ) {}
   // public function exists( $path, $watcher_cb = null ) {}
   // public function getAcl( $path ) {}
   // public function setAcl( $path, $version, $acls ) {}
   // public function getClientId( ) {}
   // public function setWatcher( $watcher_cb ) {}
   // public function getState( ) {}
   // public function getRecvTimeout( ) {}
   // public function addAuth( $scheme, $cert, $completion_cb = null ) {}
   // public function isRecoverable( ) {}
   // public function setLogStream( $file ) {} // TODO: might be able to set a stream like php://stderr or something
   // public function getResultMessage( ) {}
   // // static methods
   // static public function setDebugLevel( $level ) {}
   // static public function setDeterministicConnOrder( $trueOrFalse ) {}


}
