#include "def.h"


// 下届地形生成
// mc/world/level/levelgen/v1/NetherGenerator.h
// symbol: ?_prepareHeights@NetherGenerator@@AEAAXAEAVBlockVolume@@AEBVChunkPos@@_NPEAV?$vector@FV?$allocator@F@std@@@std@@H@Z
#include <mc/world/level/levelgen/v1/NetherGenerator.h>
LL_AUTO_TYPE_INSTANCE_HOOK(
    MyHookForPrepareHeightsNether,                                                                                         // 钩子定义的名称
    HookPriority::Normal,                                                                                                  // 钩子的优先级
    ::NetherGenerator,                                                                                                     // 类型，使用全局命名空间解析
    "?_prepareHeights@NetherGenerator@@AEAAXAEAVBlockVolume@@AEBVChunkPos@@_NPEAV?$vector@FV?$allocator@F@std@@@std@@H@Z", // 函数的符号
    void,                                                                                                                  // 函数的返回类型
    BlockVolume&        a1,                                                                                                // 第一个参数类型
    const ChunkPos&     a2,                                                                                                // 第二个参数类型
    bool                a3,                                                                                                // 第三个参数类型
    std::vector<short>* a4,                                                                                                // 第四个参数类型
    int                 a5                                                                                                 // 第五个参数类型
) {
    if (cfg.theNether.TerrainGenerator) return;
    origin(a1, a2, a3, a4, a5);
}


// 下届化石
// mc/world/level/levelgen/feature/NetherFossilFeature.h
// vIndex: 3, symbol: ?place@NetherFossilFeature@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEAVRandom@@@Z
#include <mc/world/level/levelgen/feature/NetherFossilFeature.h>
LL_AUTO_TYPE_INSTANCE_HOOK(
    MyHookForPlaceNetherFossil,                                                        // 钩子定义的名称
    HookPriority::Normal,                                                              // 钩子的优先级
    ::NetherFossilFeature,                                                             // 类型，使用全局命名空间解析
    "?place@NetherFossilFeature@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEAVRandom@@@Z", // 函数的符号
    bool,                                                                              // 函数的返回类型
    BlockSource&    a1,                                                                // 第一个参数类型
    const BlockPos& a2,                                                                // 第二个参数类型
    Random&         a3                                                                 // 第三个参数类型
) {
    switch (cfg.theNether.NetherFossil) {
    case 0:
        return false;
    case 1:
        return true;
    default:
        return origin(a1, a2, a3);
    }
}
