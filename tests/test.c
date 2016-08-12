/**
* gcc  -o test.o  -c  -I/usr/include/zookeeper test.c
* gcc  -lzookeeper_st   test.o
*/

#include <string.h>
#include <errno.h>
#include <stdio.h>

#include "zookeeper.h"

  static zhandle_t *zh;


   static zhandle_t *zh;
   typedef struct String_vector zoo_string;
   /* An empty Watcher function */
   void my_watcher_func(zhandle_t *zzh, int type, int state, const char *path, void *watcherCtx) {}
   /* Main Function */
   int
   main(int argc, char *argv[])
   {
     int i, retval;
     char *host_port = "127.0.0.1:2181";
     
     char *zoo_root = "/";

     zoo_string *children_list =
       (zoo_string *) malloc(sizeof(zoo_string));
     /* Connect to ZooKeeper server */
     
     zh = zookeeper_init(host_port, my_watcher_func, 2000, 0, NULL, 0);
     


     
     if (zh == NULL)
     {
       fprintf(stderr, "Error connecting  to ZooKeeper server!\n");
       exit(EXIT_FAILURE);
     }
     
     /* Get the list of children synchronously */
     retval = zoo_get_children(zh, zoo_root, 0, children_list);
     if (retval != ZOK)
     {
       fprintf(stderr, "Error retrieving znode from path %s!\n",
         zoo_root);
         exit(EXIT_FAILURE);
      }

    fprintf(stderr, "\nnodes count %d ret : %d", children_list->count, retval);
    fprintf(stderr, "\n=== znode listing === [ %s ]", zoo_root);

     for (i = 0; i < children_list->count; i++)
     {
       fprintf(stderr, "\n(%d): %s", i+1, children_list->data[i]);
     }
     fprintf(stderr, "\n=== done ===\n");
     /* Finally close the ZooKeeper handle */

    const char buffer[] = "***";

    retval = zoo_set ( zh,"/a",  buffer, 3, 1);

    fprintf(stderr, "\nset result : %d\n\n", retval);

     zookeeper_close(zh);
     return 0;
}