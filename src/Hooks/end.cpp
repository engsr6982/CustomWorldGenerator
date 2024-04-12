#include "def.h"
#include "ll/api/memory/Hook.h"
#include "mc/world/level/ChunkPos.h"
#include "mc/world/level/block/BlockVolume.h"


// 末地地形生成
// mc\world\level\levelgen\v1\TheEndGenerator.h
// symbol: ?_prepareHeights@TheEndGenerator@@AEAAXAEAVBlockVolume@@AEBVChunkPos@@_NPEAV?$vector@FV?$allocator@F@std@@@std@@H@Z
LL_AUTO_INSTANCE_HOOK(
    HookForTheEndGen,
    HookPriority::Normal,
    "?_prepareHeights@TheEndGenerator@@AEAAXAEAVBlockVolume@@AEBVChunkPos@@_NPEAV?$vector@FV?$allocator@F@std@@@std@@H@Z",
    void,
    BlockVolume&        a1,
    ChunkPos const&     a2,
    bool                a3,
    std::vector<short>* a4,
    int                 a5
) {
    if (cfg.theEnd.TerrainGenerator) return;
    origin(a1, a2, a3, a4, a5);
}


// 生成地表，包括地形的主体部分
// symbol: ?buildSurfaces@TheEndGenerator@@QEAAXAEAVBlockVolume@@AEBVChunkPos@@AEAVLevelChunk@@@Z
// MCAPI void buildSurfaces(class BlockVolume& box, class ChunkPos const& chunkPos, class LevelChunk& levelChunk);
#include "mc/world/level/levelgen/WorldGenerator.h"
LL_AUTO_INSTANCE_HOOK(
    HookForTheEnd_Build,
    HookPriority::Normal,
    "?buildSurfaces@TheEndGenerator@@QEAAXAEAVBlockVolume@@AEBVChunkPos@@AEAVLevelChunk@@@Z",
    void,
    BlockVolume&    a1, // 1
    ChunkPos const& a2,
    LevelChunk&     a3
) {
    if (cfg.theEnd.buildSurfaces) return;
    origin(a1, a2, a3);
}