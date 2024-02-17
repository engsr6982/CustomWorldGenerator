#include "voidworlds.h"

#include "./config/mConfig.h"

#include <ll/api/plugin/NativePlugin.h>
#include <memory>


// plugin start

namespace voidworlds {

voidworlds::voidworlds() = default;

voidworlds& voidworlds::getInstance() {
    static voidworlds instance;
    return instance;
}

ll::plugin::NativePlugin& voidworlds::getSelf() const { return *mSelf; }

bool voidworlds::load(ll::plugin::NativePlugin& self) {
    mSelf        = std::addressof(self);
    auto& logger = getSelf().getLogger();

    logger.info("Void-World loding....");
    logger.info("Author: PPOUI");
    logger.info("Version: unknow");

    mConfig::load();

    return true;
}

bool voidworlds::enable() { return true; }

bool voidworlds::disable() { return true; }

extern "C" {
_declspec(dllexport) bool ll_plugin_load(ll::plugin::NativePlugin& self) { return voidworlds::getInstance().load(self); }

_declspec(dllexport) bool ll_plugin_enable(ll::plugin::NativePlugin&) { return voidworlds::getInstance().enable(); }

_declspec(dllexport) bool ll_plugin_disable(ll::plugin::NativePlugin&) { return voidworlds::getInstance().disable(); }

/// @warning Unloading the plugin may cause a crash if the plugin has not released all of its
/// resources. If you are unsure, keep this function commented out.
// _declspec(dllexport) bool ll_plugin_unload(ll::plugin::NativePlugin&) {
//     return voidworlds::getInstance().unload();
// }
}

} // namespace voidworlds
