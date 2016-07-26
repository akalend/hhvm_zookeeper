#include "hphp/runtime/ext/extension.h"
#include "hphp/runtime/base/execution-context.h"  // g_context

#include "zookeeper.h"


#define BUFFSIZE 4096

namespace HPHP {

	void HHVM_METHOD(Zookeeper, connect); 
	String HHVM_METHOD(Zookeeper, get, const String& path);
	void HHVM_METHOD(Zookeeper, list, const String& path);
	void HHVM_METHOD(Zookeeper, set, const String& data);




	class ZooResource : public ResourceData {
		public:
 
 			DECLARE_RESOURCE_ALLOCATION_NO_SWEEP(ZooResource)

			 ZooResource(const char* host_port, watcher_fn my_watcher_func, int timeout ) {
    		// create
  
		    // static zhandle_t *zh;
		    m_zk = (void *) zookeeper_init(host_port, my_watcher_func, timeout, 0, NULL, 0);

		    if (!m_zk) {
		      throw Object(SystemLib::AllocExceptionObject(
		        "Unable create Zookeeper context"
		      ));
		    }

		  }


			~ZooResource() {
				close();
			};

			CLASSNAME_IS("Zookeeper")

			  // overriding ResourceData
  		    const String& o_getClassNameHook() const { return classnameof(); }

			void close() {
			    if (!isValid())
			        return;
			    
			    
	 			zookeeper_close((zhandle_t *) m_zk);
	 		    m_zk = nullptr;
			  }

			  bool isValid() { return m_zk != nullptr; }
			  
			  void *get() { return m_zk; }

		private:
			void *m_zk;


	};

	class ZookeeperExtension : public Extension {
		public:
		
			static int BufferSize;
		
			ZookeeperExtension(): Extension("zookeeper", "0.0.1") {}

			void moduleInit() override;
			void moduleShutdown() override;

	} ;



} // namespace HPHP