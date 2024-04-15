
#include "Config.h"

#include "Entry/Entry.h"

#include <filesystem>
#include <fstream>
#include <ll/api/Config.h>


namespace cwg::config {

config::ConfigStructs config::cfg;

bool config::load() {
    auto& mSelf          = cwg::entry::getInstance().getSelf();
    auto  configFilePath = mSelf.getPluginDir() / "config.json";
    auto& logger         = mSelf.getLogger();

    std::filesystem::path p = configFilePath;
    if (!std::filesystem::exists(p)) {
        logger.info("Saving default configurations");
        if (!ll::config::saveConfig(cfg, configFilePath)) {
            logger.error("Cannot save configurations to {}", configFilePath);
            return false;
        }
    }
    if (!ll::config::loadConfig(cfg, configFilePath)) {
        logger.warn("无法从 {} 加载配置", configFilePath);
        return false;
    }
    return true;
}

} // namespace cwg::config