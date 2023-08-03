#pragma once

#include <types.h>

// constants

constexpr u64 SCE_KERNEL_MAIN_DMEM_SIZE = 5376_MB;  // ~ 6GB

// memory types

enum MemoryTypes : u32 {
    SCE_KERNEL_WB_ONION = 0,   // write - back mode (Onion bus)
    SCE_KERNEL_WC_GARLIC = 3,  // write - combining mode (Garlic bus)
    SCE_KERNEL_WB_GARLIC = 10  // write - back mode (Garlic bus)
};

namespace HLE::Libs::LibKernel::MemoryManagement {

u64 PS4_SYSV_ABI sceKernelGetDirectMemorySize();
int PS4_SYSV_ABI sceKernelAllocateDirectMemory(s64 searchStart, s64 searchEnd, u64 len, u64 alignment, int memoryType, s64* physAddrOut);
int PS4_SYSV_ABI sceKernelMapDirectMemory(void** addr, u64 len, int prot, int flags, s64 directMemoryStart, u64 alignment);
};  // namespace HLE::Libs::LibKernel::MemoryManagement