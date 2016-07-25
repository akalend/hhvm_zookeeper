#include "hphp/runtime/ext/extension.h"
#include "hphp/runtime/base/execution-context.h"  // g_context


#define BUFFSIZE 4096

namespace HPHP {

	String HHVM_METHOD(Zookeeper, get, const String& path);
	void HHVM_METHOD(Zookeeper, list, const String& path);
	void HHVM_METHOD(Zookeeper, set, const String& data);





	class Zookeeper {
		public:
			Zookeeper();

			~Zookeeper();

			CLASSNAME_IS("Zookeeper")

	};

	class ZookeeperExtension : public Extension {
		public:
		
			static int BufferSize;
		
			ZookeeperExtension(): Extension("zookeeper", "0.0.1") {}

			void moduleInit() override;
			void moduleShutdown() override;

	} ;



} // namespace HPHP