#include "hphp/runtime/ext/extension.h"
#include "hphp/runtime/base/execution-context.h"  // g_context

#include "zookeeper.h"


#define BUFFSIZE 4096

namespace HPHP {

	void HHVM_METHOD(Zookeeper, connect); 
	String HHVM_METHOD(Zookeeper, get, const String& path);
	void HHVM_METHOD(Zookeeper, list, const String& path);
	void HHVM_METHOD(Zookeeper, set, const String& data);

	Resource HHVM_METHOD(Zookeeper, init); 



	class ZooResource : public ResourceData {
		public:
 
			char* host_port;
			watcher_fn my_watcher_func;
			int timeout;


 			DECLARE_RESOURCE_ALLOCATION_NO_SWEEP(ZooResource)

			 ZooResource() {
    		// create
  
		    // static zhandle_t *zh;
		  }


			~ZooResource() {
				close();
			};

			CLASSNAME_IS("Zookeeper")

			  // overriding ResourceData
  		    const String& o_getClassNameHook() const { return classnameof(); }


  		    void connect() {
			    m_res = (void *) zookeeper_init(host_port, my_watcher_func, timeout, 0, NULL, 0);

			    if (!m_res) {
			      throw Object(SystemLib::AllocExceptionObject(
			        "Unable create Zookeeper context"
			      ));
			    }
  		    }

			void close() {
			    if (!isValid())
			        return;
			    
			    
	 			zookeeper_close((zhandle_t *) m_res);
	 		    m_res = nullptr;
			  }

			  bool isValid() { return m_res != nullptr; }
			  
			  void *get() { return m_res; }

		private:
			void *m_res;


	};

	class ZookeeperExtension : public Extension {
		public:
		
			static int BufferSize;
		
			ZookeeperExtension(): Extension("zookeeper", "0.0.1") {}

			void moduleInit() override;
			void moduleShutdown() override;

	} ;



} // namespace HPHP