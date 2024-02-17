namespace mConfig {

struct ConfigStructs {
    int version = 6;

    // 主世界
    struct OverWorlds {
        bool TerrainGenerator = false; // 地形生成
    } overworld;

    // 地狱
    struct TheNethers {
        bool TerrainGenerator = false; // 地形生成
        int  NetherFossil     = 2;     // 下届化石
    } theNether;

    // 末地
    struct TheEnds {
        bool TerrainGenerator = false; // 地形生成
        bool buildSurfaces    = false;
    } theEnd;

    // 群系
    struct Biomes {
        bool BedrockCeiling     = false; // 顶部基岩
        bool BedrockFloor       = false; // 底部基岩
        bool OceanFrozenSurface = false; // 冰冻海洋表面
        bool MesaSurface        = false; // 粘土山
    } biome;

    // 结构
    struct Structures {
        bool OceanRuin             = false; // 海底废墟
        bool Shipwreck             = false; // 沉船
        int  Shipwreck_Check       = 2;     // 沉船（oj的生成条件检查）
        int  Village               = 2;     // 村庄
        int  OceanMonument         = 2;     // 海底神殿
        int  JunglePyramid         = 2;     // 丛林神庙
        int  DesertPyramid         = 2;     // 沙漠神殿
        int  PillagerOutpost       = 2;     // 掠夺者前哨站
        int  Stronghold            = 2;     // 要塞
        int  WoodlandMansion_Check = 2;     // 林地府邸（生成条件检查）
        bool WoodlandMansion       = false; // 林地府邸
    } structure;

    // 不知道是什么东西
    struct LevelGens {
        bool Iceberg = false; // 冰山
        int  Fossil  = 2;     // 化石
    } levelGen;
};

extern ConfigStructs cfg;

bool load();

} // namespace mConfig