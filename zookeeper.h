#include "hphp/runtime/ext/extension.h"
#include "hphp/runtime/base/execution-context.h"  // g_context


#define BUFFSIZE 4096

namespace HPHP {

// static Array HHVM_FUNCTION(msgpack_unpack, const String& data);



class ZookeeperExtension : public Extension {
	public:
	
	static int BufferSize;
	
	ZookeeperExtension(): Extension("Zookeeper", "0.0.1") {}

	void moduleInit() override;
	void moduleShutdown() override;

} ;



// HHVM_GET_MODULE(msgpack);

} // namespace HPHP