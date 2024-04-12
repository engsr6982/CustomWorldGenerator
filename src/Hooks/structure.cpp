#include "def.h"


// 海底废墟
// mc/world/level/levelgen/structure/OceanRuinStart.h
// symbol: ?createRuin@OceanRuinStart@@QEAAXAEAVDimension@@AEAVRandom@@HH@Z
#include <mc/world/level/dimension/Dimension.h>
#include <mc/world/level/levelgen/structure/OceanRuinStart.h>
LL_AUTO_TYPE_INSTANCE_HOOK(
    MyHookForCreateRuin,  // 钩子定义的名称
    HookPriority::Normal, // 钩子的优先级
    ::OceanRuinStart,     // 类型，使用全局命名空间解析
    "?createRuin@OceanRuinStart@@QEAAXAEAVDimension@@AEAVRandom@@HH@Z",
    void,
    Dimension& a1,
    Random&    a2,
    int        a3,
    int        a4
) {
    if (cfg.structure.OceanRuin) return;
    origin(a1, a2, a3, a4);
}


// 沉船
// mc/world/level/levelgen/structure/ShipwreckFeature.h
// vIndex: 6, symbol:
// ?createStructureStart@ShipwreckFeature@@MEAA?AV?$unique_ptr@VStructureStart@@U?$default_delete@VStructureStart@@@std@@@std@@AEAVDimension@@AEBVBiomeSource@@AEAVRandom@@AEBVChunkPos@@AEBVIPreliminarySurfaceProvider@@@Z
#include <mc/world/level/levelgen/structure/ShipwreckFeature.h>
#include <mc/world/level/levelgen/structure/ShipwreckStart.h>
LL_AUTO_TYPE_INSTANCE_HOOK(
    MyHookForCreateStructureStartShipwreck, // 钩子定义的名称
    HookPriority::Normal,                   // 钩子的优先级
    ::ShipwreckFeature,                     // 类型，使用全局命名空间解析
    "?createStructureStart@ShipwreckFeature@@MEAA?AV?$unique_ptr@VStructureStart@@U?$default_delete@VStructureStart@@@std@@@std@@AEAVDimension@@AEBVBiomeSource@@AEAVRandom@@AEBVChunkPos@@AEBVIPreliminarySurfaceProvider@@@Z", // 函数的符号
    std::unique_ptr<StructureStart>, // 函数的返回类型
    Dimension&                         a1,
    const BiomeSource&                 a2,
    Random&                            a3,
    const ChunkPos&                    a4,
    const IPreliminarySurfaceProvider& a5
) {
    if (cfg.structure.Shipwreck) {
        // 创建ShipwreckStart的实例并返回
        auto shipwreckStart = std::make_unique<ShipwreckStart>(a2, a3, a4.x, a4.z, /* seaLevel */ 63); // 假设海平面为63，根据需要调整
        return shipwreckStart;
    }
    return origin(a1, a2, a3, a4, a5);
}


// 沉船（生成条件检查）
// mc/world/level/levelgen/structure/ShipwreckFeature.h
// vIndex: 5, symbol: ?isFeatureChunk@ShipwreckFeature@@MEAA_NAEBVBiomeSource@@AEAVRandom@@AEBVChunkPos@@IAEBVIPreliminarySurfaceProvider@@AEBVDimension@@@Z
#include <mc/world/level/levelgen/structure/ShipwreckFeature.h>
LL_AUTO_TYPE_INSTANCE_HOOK(
    MyHookForIsFeatureChunkShipwreck,                                                                                                         // 钩子定义的名称
    HookPriority::Normal,                                                                                                                     // 钩子的优先级
    ::ShipwreckFeature,                                                                                                                       // 类型，使用全局命名空间解析
    "?isFeatureChunk@ShipwreckFeature@@MEAA_NAEBVBiomeSource@@AEAVRandom@@AEBVChunkPos@@IAEBVIPreliminarySurfaceProvider@@AEBVDimension@@@Z", // 函数的符号
    bool,                                                                                                                                     // 函数的返回类型
    const BiomeSource&                 a1,                                                                                                    // 第一个参数类型
    Random&                            a2,                                                                                                    // 第二个参数类型
    const ChunkPos&                    a3,                                                                                                    // 第三个参数类型
    unsigned int                       a4,                                                                                                    // 第四个参数类型
    const IPreliminarySurfaceProvider& a5,                                                                                                    // 第五个参数类型
    const Dimension&                   a6                                                                                                     // 第六个参数类型
) {
    switch (cfg.structure.Shipwreck_Check) {
    case 0:
        return false;
    case 1:
        return true;
    default:
        return origin(a1, a2, a3, a4, a5, a6);
    }
}


// 村庄
// mc/world/level/levelgen/structure/VillageFeature.h
// vIndex: 5, symbol: ?isFeatureChunk@VillageFeature@@UEAA_NAEBVBiomeSource@@AEAVRandom@@AEBVChunkPos@@IAEBVIPreliminarySurfaceProvider@@AEBVDimension@@@Z
#include <mc/world/level/levelgen/structure/VillageFeature.h>
LL_AUTO_TYPE_INSTANCE_HOOK(
    MyHookForIsFeatureChunkVillage,                                                                                                         // 钩子定义的名称
    HookPriority::Normal,                                                                                                                   // 钩子的优先级
    ::VillageFeature,                                                                                                                       // 类型，使用全局命名空间解析
    "?isFeatureChunk@VillageFeature@@UEAA_NAEBVBiomeSource@@AEAVRandom@@AEBVChunkPos@@IAEBVIPreliminarySurfaceProvider@@AEBVDimension@@@Z", // 函数的符号
    bool,                                                                                                                                   // 函数的返回类型
    const BiomeSource&                 a1,                                                                                                  // 第一个参数类型
    Random&                            a2,                                                                                                  // 第二个参数类型
    const ChunkPos&                    a3,                                                                                                  // 第三个参数类型
    unsigned int                       a4,                                                                                                  // 第四个参数类型
    const IPreliminarySurfaceProvider& a5,                                                                                                  // 第五个参数类型
    const Dimension&                   a6                                                                                                   // 第六个参数类型
) {
    switch (cfg.structure.Village) {
    case 0:
        return false;
    case 1:
        return true;
    default:
        return origin(a1, a2, a3, a4, a5, a6);
    }
}


// 海底神殿
// mc/world/level/levelgen/structure/OceanMonumentFeature.h
// vIndex: 5, symbol: ?isFeatureChunk@OceanMonumentFeature@@UEAA_NAEBVBiomeSource@@AEAVRandom@@AEBVChunkPos@@IAEBVIPreliminarySurfaceProvider@@AEBVDimension@@@Z
#include <mc/world/level/levelgen/structure/OceanMonumentFeature.h>
LL_AUTO_TYPE_INSTANCE_HOOK(
    MyHookForIsFeatureChunkOceanMonument,                                                                                                         // 钩子定义的名称
    HookPriority::Normal,                                                                                                                         // 钩子的优先级
    ::OceanMonumentFeature,                                                                                                                       // 类型，使用全局命名空间解析
    "?isFeatureChunk@OceanMonumentFeature@@UEAA_NAEBVBiomeSource@@AEAVRandom@@AEBVChunkPos@@IAEBVIPreliminarySurfaceProvider@@AEBVDimension@@@Z", // 函数的符号
    bool,                                                                                                                                         // 函数的返回类型
    const BiomeSource&                 a1,                                                                                                        // 第一个参数类型
    Random&                            a2,                                                                                                        // 第二个参数类型
    const ChunkPos&                    a3,                                                                                                        // 第三个参数类型
    unsigned int                       a4,                                                                                                        // 第四个参数类型
    const IPreliminarySurfaceProvider& a5,                                                                                                        // 第五个参数类型
    const Dimension&                   a6                                                                                                         // 第六个参数类型
) {
    switch (cfg.structure.OceanMonument) {
    case 0:
        return false;
    case 1:
        return true;
    default:
        return origin(a1, a2, a3, a4, a5, a6);
    }
}


// 丛林神庙
// mc/world/level/levelgen/structure/JunglePyramidPiece.h
// vIndex: 4, symbol: ?postProcess@JunglePyramidPiece@@UEAA_NAEAVBlockSource@@AEAVRandom@@AEBVBoundingBox@@@Z
#include <mc/world/level/levelgen/structure/JunglePyramidPiece.h>
LL_AUTO_TYPE_INSTANCE_HOOK(
    MyHookForPostProcessJunglePyramid,                                                         // 钩子定义的名称
    HookPriority::Normal,                                                                      // 钩子的优先级
    ::JunglePyramidPiece,                                                                      // 类型，使用全局命名空间解析
    "?postProcess@JunglePyramidPiece@@UEAA_NAEAVBlockSource@@AEAVRandom@@AEBVBoundingBox@@@Z", // 函数的符号
    bool,                                                                                      // 函数的返回类型
    BlockSource&       a1,                                                                     // 第一个参数类型
    Random&            a2,                                                                     // 第二个参数类型
    const BoundingBox& a3                                                                      // 第三个参数类型
) {
    switch (cfg.structure.JunglePyramid) {
    case 0:
        return false;
    case 1:
        return true;
    default:
        return origin(a1, a2, a3);
    }
}


// 沙漠神殿
// mc/world/level/levelgen/structure/DesertPyramidPiece.h
// vIndex: 4, symbol: ?postProcess@DesertPyramidPiece@@UEAA_NAEAVBlockSource@@AEAVRandom@@AEBVBoundingBox@@@Z
#include <mc/world/level/levelgen/structure/DesertPyramidPiece.h>
LL_AUTO_TYPE_INSTANCE_HOOK(
    MyHookForPostProcessDesertPyramid,                                                         // 钩子定义的名称
    HookPriority::Normal,                                                                      // 钩子的优先级
    ::DesertPyramidPiece,                                                                      // 类型，使用全局命名空间解析
    "?postProcess@DesertPyramidPiece@@UEAA_NAEAVBlockSource@@AEAVRandom@@AEBVBoundingBox@@@Z", // 函数的符号
    bool,                                                                                      // 函数的返回类型
    BlockSource&       a1,                                                                     // 第一个参数类型
    Random&            a2,                                                                     // 第二个参数类型
    const BoundingBox& a3                                                                      // 第三个参数类型
) {
    switch (cfg.structure.DesertPyramid) {
    case 0:
        return false;
    case 1:
        return true;
    default:
        return origin(a1, a2, a3);
    }
}


// 掠夺者前哨站
// mc/world/level/levelgen/structure/PillagerOutpostFeature.h
// vIndex: 5, symbol: ?isFeatureChunk@PillagerOutpostFeature@@UEAA_NAEBVBiomeSource@@AEAVRandom@@AEBVChunkPos@@IAEBVIPreliminarySurfaceProvider@@AEBVDimension@@@Z
#include <mc/world/level/levelgen/structure/PillagerOutpostFeature.h>
LL_AUTO_TYPE_INSTANCE_HOOK(
    MyHookForIsFeatureChunkPillagerOutpost,                                                                                                         // 钩子定义的名称
    HookPriority::Normal,                                                                                                                           // 钩子的优先级
    ::PillagerOutpostFeature,                                                                                                                       // 类型，使用全局命名空间解析
    "?isFeatureChunk@PillagerOutpostFeature@@UEAA_NAEBVBiomeSource@@AEAVRandom@@AEBVChunkPos@@IAEBVIPreliminarySurfaceProvider@@AEBVDimension@@@Z", // 函数的符号
    bool,                                                                                                                                           // 函数的返回类型
    const BiomeSource&                 a1,                                                                                                          // 第一个参数类型
    Random&                            a2,                                                                                                          // 第二个参数类型
    const ChunkPos&                    a3,                                                                                                          // 第三个参数类型
    unsigned int                       a4,                                                                                                          // 第四个参数类型
    const IPreliminarySurfaceProvider& a5,                                                                                                          // 第五个参数类型
    const Dimension&                   a6                                                                                                           // 第六个参数类型
) {
    switch (cfg.structure.PillagerOutpost) {
    case 0:
        return false;
    case 1:
        return true;
    default:
        return origin(a1, a2, a3, a4, a5, a6);
    }
}


// 要塞
// mc/world/level/levelgen/structure/StrongholdFeature.h
// vIndex: 5, symbol: ?isFeatureChunk@StrongholdFeature@@UEAA_NAEBVBiomeSource@@AEAVRandom@@AEBVChunkPos@@IAEBVIPreliminarySurfaceProvider@@AEBVDimension@@@Z
#include <mc/world/level/levelgen/structure/StrongholdFeature.h>
LL_AUTO_TYPE_INSTANCE_HOOK(
    MyHookForIsFeatureChunkStronghold,                                                                                                         // 钩子定义的名称
    HookPriority::Normal,                                                                                                                      // 钩子的优先级
    ::StrongholdFeature,                                                                                                                       // 类型，使用全局命名空间解析
    "?isFeatureChunk@StrongholdFeature@@UEAA_NAEBVBiomeSource@@AEAVRandom@@AEBVChunkPos@@IAEBVIPreliminarySurfaceProvider@@AEBVDimension@@@Z", // 函数的符号
    bool,                                                                                                                                      // 函数的返回类型
    const BiomeSource&                 a1,                                                                                                     // 第一个参数类型
    Random&                            a2,                                                                                                     // 第二个参数类型
    const ChunkPos&                    a3,                                                                                                     // 第三个参数类型
    unsigned int                       a4,                                                                                                     // 第四个参数类型
    const IPreliminarySurfaceProvider& a5,                                                                                                     // 第五个参数类型
    const Dimension&                   a6                                                                                                      // 第六个参数类型
) {
    switch (cfg.structure.Stronghold) {
    case 0:
        return false;
    case 1:
        return true;
    default:
        return origin(a1, a2, a3, a4, a5, a6);
    }
}


// 林地府邸（生成条件检查）
// mc/world/level/levelgen/structure/WoodlandMansionFeature.h
// vIndex: 5, symbol: ?isFeatureChunk@WoodlandMansionFeature@@MEAA_NAEBVBiomeSource@@AEAVRandom@@AEBVChunkPos@@IAEBVIPreliminarySurfaceProvider@@AEBVDimension@@@Z
#include <mc/world/level/levelgen/structure/WoodlandMansionFeature.h>
LL_AUTO_TYPE_INSTANCE_HOOK(
    MyHookForIsFeatureChunkWoodlandMansion,                                                                                                         // 钩子定义的名称
    HookPriority::Normal,                                                                                                                           // 钩子的优先级
    ::WoodlandMansionFeature,                                                                                                                       // 类型，使用全局命名空间解析
    "?isFeatureChunk@WoodlandMansionFeature@@MEAA_NAEBVBiomeSource@@AEAVRandom@@AEBVChunkPos@@IAEBVIPreliminarySurfaceProvider@@AEBVDimension@@@Z", // 函数的符号
    bool,                                                                                                                                           // 函数的返回类型
    const BiomeSource&                 a1,                                                                                                          // 第一个参数类型
    Random&                            a2,                                                                                                          // 第二个参数类型
    const ChunkPos&                    a3,                                                                                                          // 第三个参数类型
    unsigned int                       a4,                                                                                                          // 第四个参数类型
    const IPreliminarySurfaceProvider& a5,                                                                                                          // 第五个参数类型
    const Dimension&                   a6                                                                                                           // 第六个参数类型
) {
    switch (cfg.structure.WoodlandMansion_Check) {
    case 0:
        return false;
    case 1:
        return true;
    default:
        return origin(a1, a2, a3, a4, a5, a6);
    }
}


// 林地府邸
// mc/world/level/levelgen/structure/WoodlandMansionPieces.h
// symbol:
// ?createMansion@MansionPiecePlacer@WoodlandMansionPieces@@QEAAXAEBVBlockPos@@W4Rotation@@AEAV?$vector@V?$unique_ptr@VStructurePiece@@U?$default_delete@VStructurePiece@@@std@@@std@@V?$allocator@V?$unique_ptr@VStructurePiece@@U?$default_delete@VStructurePiece@@@std@@@std@@@2@@std@@AEAVMansionGrid@2@@Z
#include <mc/world/level/levelgen/structure/WoodlandMansionPieces.h>
LL_AUTO_TYPE_INSTANCE_HOOK(
    MyHookForCreateMansion,                                                         // 钩子定义的名称
    HookPriority::Normal,                                                           // 钩子的优先级
    ::WoodlandMansionPieces::MansionPiecePlacer,                                    // 类型，使用全局命名空间解析
                                                                                    // clang-format off
    "?createMansion@MansionPiecePlacer@WoodlandMansionPieces@@QEAAXAEBVBlockPos@@W4Rotation@@AEAV?$vector@V?$unique_ptr@VStructurePiece@@U?$default_delete@VStructurePiece@@@std@@@std@@V?$allocator@V?$unique_ptr@VStructurePiece@@U?$default_delete@VStructurePiece@@@std@@@std@@@2@@std@@AEAVMansionGrid@2@@Z", // 函数的符号
                                                                                    // clang-format on
    void,                                                                           // 函数的返回类型
    const BlockPos&                               a1,                               // 第一个参数类型
    Rotation                                      a2,                               // 第二个参数类型
    std::vector<std::unique_ptr<StructurePiece>>& a3,                               // 第三个参数类型，注意处理复杂类型
    WoodlandMansionPieces::MansionGrid&           a4                                // 第四个参数类型
) {
    if (cfg.structure.WoodlandMansion) return;
    origin(a1, a2, a3, a4);
};