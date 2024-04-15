#include "Entry.h"

#include <memory>

#include "ll/api/plugin/NativePlugin.h"
#include "ll/api/plugin/RegisterHelper.h"

// proj
#include "Config/Config.h"

namespace cwg {

static std::unique_ptr<entry> instance;

entry& entry::getInstance() { return *instance; }

bool entry::load() {
    // Code for loading the plugin goes here.
    auto& logger = getSelf().getLogger();

    logger.info("CustomWorldGenerator loding....");
    logger.info("Author: PPOUI");
    logger.info("Version: 1.0.0");

    cwg::config::load();
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

} // namespace cwg

LL_REGISTER_PLUGIN(cwg::entry, cwg::instance);
