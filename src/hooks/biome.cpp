#include "def.h"


// 世界顶部基岩
// mc/world/level/biome/surface/Utils.h
// symbol: ?placeBedrockCeiling@Utils@VanillaSurfaceBuilders@@YAXAEAVRandom@@AEAVBlockVolume@@AEBVBlockPos@@@Z
LL_AUTO_STATIC_HOOK(
    MyHookForPlaceBedrockCeiling,                                                                          // 钩子定义的名称
    HookPriority::Normal,                                                                                  // 钩子的优先级
    "?placeBedrockCeiling@Utils@VanillaSurfaceBuilders@@YAXAEAVRandom@@AEAVBlockVolume@@AEBVBlockPos@@@Z", // 函数的符号
    void,                                                                                                  // 函数的返回类型
    Random&         a1,                                                                                    // 第一个参数类型
    BlockVolume&    a2,                                                                                    // 第二个参数类型
    const BlockPos& a3                                                                                     // 第三个参数类型
) {
    if (cfg.biome.BedrockCeiling) return;
    origin(a1, a2, a3);
}


// 世界底部基岩
// mc/world/level/biome/surface/Utils.h
// symbol: ?placeBedrockFloor@Utils@VanillaSurfaceBuilders@@YAXAEAVRandom@@AEAVBlockVolume@@AEBVBlockPos@@@Z
LL_AUTO_STATIC_HOOK(
    MyHookForPlaceBedrockFloor,
    HookPriority::Normal,
    "?placeBedrockFloor@Utils@VanillaSurfaceBuilders@@YAXAEAVRandom@@AEAVBlockVolume@@AEBVBlockPos@@@Z",
    void,
    Random&         a1, // 1
    BlockVolume&    a2, // 2
    const BlockPos& a3  // 3
) {
    if (cfg.biome.BedrockFloor) return;
    origin(a1, a2, a3);
}


// 冰冻海洋表面
// mc/world/level/biome/surface/OceanFrozenSurfaceBuilder.h
// vIndex: 2, symbol: ?buildSurfaceAt@OceanFrozenSurfaceBuilder@VanillaSurfaceBuilders@@UEBAXAEBUBuildParameters@ISurfaceBuilder@@@Z
#include <mc/world/level/biome/surface/OceanFrozenSurfaceBuilder.h>
LL_AUTO_INSTANCE_HOOK_IMPL(
    MyHookForBuildSurfaceAt,                                                                                          // 钩子定义的名称
    ::VanillaSurfaceBuilders::OceanFrozenSurfaceBuilder,                                                              // 类型，使用全局命名空间解析
    HookPriority::Normal,                                                                                             // 钩子的优先级
    "?buildSurfaceAt@OceanFrozenSurfaceBuilder@VanillaSurfaceBuilders@@UEBAXAEBUBuildParameters@ISurfaceBuilder@@@Z", // 函数的符号
    void,                                                                                                             // 函数的返回类型
    const ISurfaceBuilder::BuildParameters& a1                                                                        // 第一个参数类型
) {
    if (cfg.biome.OceanFrozenSurface) return;
    origin(a1);
}


// 粘土山生成
// mc/world/level/biome/surface/MesaSurfaceBuilder.h
// vIndex: 2, symbol: ?buildSurfaceAt@MesaSurfaceBuilder@VanillaSurfaceBuilders@@UEBAXAEBUBuildParameters@ISurfaceBuilder@@@Z
#include <mc/world/level/biome/surface/MesaSurfaceBuilder.h>
LL_AUTO_INSTANCE_HOOK_IMPL(
    MyHookForBuildSurfaceAtMesa,                                                                               // 钩子定义的名称
    ::VanillaSurfaceBuilders::MesaSurfaceBuilder,                                                              // 类型，使用全局命名空间解析
    HookPriority::Normal,                                                                                      // 钩子的优先级
    "?buildSurfaceAt@MesaSurfaceBuilder@VanillaSurfaceBuilders@@UEBAXAEBUBuildParameters@ISurfaceBuilder@@@Z", // 函数的符号
    void,                                                                                                      // 函数的返回类型
    const ISurfaceBuilder::BuildParameters& a1                                                                 // 第一个参数类型
) {
    if (cfg.biome.MesaSurface) return;
    origin(a1);
}
