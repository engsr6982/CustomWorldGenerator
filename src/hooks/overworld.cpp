#include "def.h"
#include "ll/api/memory/Hook.h"

#include <mc/world/level/BlockPos.h>
#include <mc/world/level/block/BlockVolume.h>


// 主世界地形生成器(不包含基岩)
// mc/world/level/levelgen/v1/OverworldGeneratorMultinoise.h
// symbol: ?_prepareHeights@OverworldGeneratorMultinoise@@EEAAXAEAVBlockVolume@@AEBVChunkPos@@AEBVWorldGenCache@@PEAVAquifer@@$$QEAV?$function@$$A6AXAEBVBlockPos@@AEBVBlock@@H@Z@std@@_NPEAV?$vector@FV?$allocator@F@std@@@7@H@Z
#include <mc/world/level/levelgen/v1/OverworldGenerator.h>
LL_AUTO_STATIC_HOOK(
    MyHookForPrepareHeights, // 钩子定义的名称
    HookPriority::Normal,    // 钩子的优先级
    "?_prepareHeights@OverworldGeneratorMultinoise@@EEAAXAEAVBlockVolume@@AEBVChunkPos@@AEBVWorldGenCache@@PEAVAquifer@@$$QEAV?$function@$$A6AXAEBVBlockPos@@AEBVBlock@@H@Z@std@@_NPEAV?$vector@FV?$allocator@F@std@@@7@H@Z", // 函数的符号
    void, // 函数的返回类型
    BlockVolume&                                              a1,
    const ChunkPos&                                           a2,
    const WorldGenCache&                                      a3,
    Aquifer*                                                  a4,
    std::function<void(const BlockPos&, const Block&, int)>&& a5,
    bool                                                      a6,
    std::vector<short>*                                       a7,
    int                                                       a8
) {
    if (cfg.overworld.TerrainGenerator) return;
    origin(a1, a2, a3, a4, mv(a5), a6, a7, a8);
}


// symbol: ?decorateWorldGenPostProcess@OverworldGeneratorMultinoise@@EEBAXAEAVBiome@@AEAVLevelChunk@@AEAVBlockSource@@AEAVRandom@@@Z
// LL_AUTO_INSTANCE_HOOK(
//     TestFor1, // name
//     HookPriority::Normal,
//     "?decorateWorldGenPostProcess@OverworldGeneratorMultinoise@@EEBAXAEAVBiome@@AEAVLevelChunk@@AEAVBlockSource@@AEAVRandom@@@Z",
//     void,
//     Biome&       a1,
//     LevelChunk&  a2,
//     BlockSource& a3,
//     Random&      a4
// ) {
//     origin(a1, a2, a3, a4);
// }


// symbol: ?findSpawnPosition@OverworldGeneratorMultinoise@@UEBA?AVBlockPos@@XZ
// virtual class BlockPos findSpawnPosition() const;
