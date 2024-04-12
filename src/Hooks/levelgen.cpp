#include "def.h"


// 冰山
// mc/world/level/levelgen/feature/IcebergFeature.h
// symbol: ?generateIcebergBlock@IcebergFeature@@AEBAXAEAVBlockSource@@AEAVRandom@@AEBVBlockPos@@HHHHHH_N3MHAEBVBlock@@@Z
#include <mc/world/level/levelgen/feature/IcebergFeature.h>
LL_AUTO_TYPE_INSTANCE_HOOK(
    MyHookForGenerateIcebergBlock,                                                                                    // 钩子定义的名称
    HookPriority::Normal,                                                                                             // 钩子的优先级
    ::IcebergFeature,                                                                                                 // 类型，使用全局命名空间解析
    "?generateIcebergBlock@IcebergFeature@@AEBAXAEAVBlockSource@@AEAVRandom@@AEBVBlockPos@@HHHHHH_N3MHAEBVBlock@@@Z", // 函数的符号
    void,                                                                                                             // 函数的返回类型
    BlockSource&    a1,                                                                                               // 第一个参数类型
    Random&         a2,                                                                                               // 第二个参数类型
    const BlockPos& a3,                                                                                               // 第三个参数类型
    int             a4,                                                                                               // 第四个参数类型
    int             a5,                                                                                               // 第五个参数类型
    int             a6,                                                                                               // 第六个参数类型
    int             a7,                                                                                               // 第七个参数类型
    int             a8,                                                                                               // 第八个参数类型
    int             a9,                                                                                               // 第九个参数类型
    bool            a10,                                                                                              // 第十个参数类型
    bool            a11,                                                                                              // 第十一个参数类型
    float           a12,                                                                                              // 第十二个参数类型
    int             a13,                                                                                              // 第十三个参数类型
    const Block&    a14                                                                                               // 第十四个参数类型
) {
    if (cfg.levelGen.Iceberg) return;
    origin(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
}


// 化石
// mc/world/level/levelgen/feature/FossilFeature.h
// vIndex: 3, symbol: ?place@FossilFeature@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEAVRandom@@@Z
#include <mc/world/level/levelgen/feature/FossilFeature.h>
LL_AUTO_TYPE_INSTANCE_HOOK(
    MyHookForPlaceFossil,                                                        // 钩子定义的名称
    HookPriority::Normal,                                                        // 钩子的优先级
    ::FossilFeature,                                                             // 类型，使用全局命名空间解析
    "?place@FossilFeature@@UEBA_NAEAVBlockSource@@AEBVBlockPos@@AEAVRandom@@@Z", // 函数的符号
    bool,                                                                        // 函数的返回类型
    BlockSource&    a1,                                                          // 第一个参数类型
    const BlockPos& a2,                                                          // 第二个参数类型
    Random&         a3                                                           // 第三个参数类型
) {
    switch (cfg.levelGen.Fossil) {
    case 0:
        return false;
    case 1:
        return true;
    default:
        return origin(a1, a2, a3);
    }
}
