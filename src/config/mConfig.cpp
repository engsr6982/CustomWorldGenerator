
#include "mConfig.h"

#include "../voidworlds.h"

#include <filesystem>
#include <fstream>
#include <ll/api/Config.h>


namespace mConfig {

mConfig::ConfigStructs mConfig::cfg;

bool mConfig::load() {
    auto& mSelf          = voidworlds::voidworlds::getInstance().getSelf();
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

} // namespace mConfig