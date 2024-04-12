#include "Entry.h"

#include <memory>

#include "ll/api/plugin/NativePlugin.h"
#include "ll/api/plugin/RegisterHelper.h"

namespace vid {

static std::unique_ptr<entry> instance;

entry& entry::getInstance() { return *instance; }

bool entry::load() {
    // Code for loading the plugin goes here.
    auto& logger = getSelf().getLogger();

    logger.info("Void-Worlds loding....");
    logger.info("Author: PPOUI");
    logger.info("Version: 1.0.0");

    vid::config::load();
    return true;
}

bool entry::enable() {
    getSelf().getLogger().info("Enabling...");
    // Code for enabling the plugin goes here.
    return true;
}

bool entry::disable() {
    getSelf().getLogger().info("Disabling...");
    // Code for disabling the plugin goes here.
    return true;
}

} // namespace vid

LL_REGISTER_PLUGIN(vid::entry, vid::instance);
