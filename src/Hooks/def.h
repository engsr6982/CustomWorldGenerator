// plugin
#include "Config/Config.h"
#include "Entry/Entry.h"

// ll
#include <ll/api/memory/Hook.h>

// random
#include <mc/deps/crypto/Random.h>
#include <mc/deps/crypto/random/Random.h>
#include <mc/math/Random.h>
#include <mc/util/Random.h>

// block
#include <mc/world/level/BlockPos.h>
#include <mc/world/level/block/BlockVolume.h>
#include <mc/world/level/block/registry/BlockTypeRegistry.h>
#include <mc/world/level/block/utils/VanillaBlockTypeIds.h>

// all define
#define ENABLE_VIRTUAL_FAKESYMBOL_RANDOM = 1
#define mv                               std::move
#define cfg                              cwg::config::cfg
