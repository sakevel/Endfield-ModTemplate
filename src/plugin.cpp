#include "zml_plugin.h"

namespace {
const ZmlHost* hostApi{};

int initialise(const ZmlHost* host) {
    if (!host || host->size != sizeof(ZmlHost) || host->abi != 1 || !host->log) return 0;
    hostApi = host;
    hostApi->log(hostApi->owner, "SampleMod initialized");
    return 1;
}

const ZmlPlugin plugin{sizeof(ZmlPlugin), 1, "sample-mod", initialise};
}

extern "C" __declspec(dllexport) const ZmlPlugin* ZML_PluginV1() {
    return &plugin;
}
