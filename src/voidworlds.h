#pragma once

#include <ll/api/plugin/NativePlugin.h>

namespace voidworlds {

class voidworlds {
    voidworlds();

public:
    voidworlds(voidworlds&&)                 = delete;
    voidworlds(const voidworlds&)            = delete;
    voidworlds& operator=(voidworlds&&)      = delete;
    voidworlds& operator=(const voidworlds&) = delete;

    static voidworlds& getInstance();

    [[nodiscard]] ll::plugin::NativePlugin& getSelf() const;

    /// @return True if the plugin is loaded successfully.
    bool load(ll::plugin::NativePlugin&);

    /// @return True if the plugin is enabled successfully.
    bool enable();

    /// @return True if the plugin is disabled successfully.
    bool disable();

private:
    ll::plugin::NativePlugin* mSelf{};
};

} // namespace rename_this
