/// @file safetyhook/easy.hpp
/// @brief Easy to use API for creating hooks.

#pragma once

#include "safetyhook/common.hpp"
#include "safetyhook/inline_hook.hpp"
#include "safetyhook/mid_hook.hpp"
#include "safetyhook/utility.hpp"
#include "safetyhook/vmt_hook.hpp"

namespace safetyhook {
/// @brief Easy to use API for creating an InlineHook.
/// @param target The address of the function to hook.
/// @param destination The address of the destination function.
/// @return The InlineHook object.
[[nodiscard]] InlineHook SAFETYHOOK_API create_inline(void* target, void* destination);

/// @brief Easy to use API for creating an InlineHook.
/// @param target The address of the function to hook.
/// @param destination The address of the destination function.
/// @return The InlineHook object.
[[nodiscard]] InlineHook create_inline(FnPtr auto target, FnPtr auto destination) {
    return create_inline(reinterpret_cast<void*>(target), reinterpret_cast<void*>(destination));
}

/// @brief Easy to use API for creating a MidHook.
/// @param target the address of the function to hook.
/// @param destination The destination function.
/// @return The MidHook object.
[[nodiscard]] MidHook SAFETYHOOK_API create_mid(void* target, MidHookFn destination);

/// @brief Easy to use API for creating a MidHook.
/// @param target the address of the function to hook.
/// @param destination The destination function.
/// @return The MidHook object.
[[nodiscard]] MidHook create_mid(FnPtr auto target, MidHookFn destination) {
    return create_mid(reinterpret_cast<void*>(target), destination);
}

/// @brief Easy to use API for creating a VmtHook.
/// @param object The object to hook.
/// @return The VmtHook object.
[[nodiscard]] VmtHook SAFETYHOOK_API create_vmt(void* object);

/// @brief Easy to use API for creating a VmHook.
/// @param vmt The VmtHook to use to create the VmHook.
/// @param index The index of the method to hook.
/// @param destination The destination function.
/// @return The VmHook object.
[[nodiscard]] VmHook create_vm(VmtHook& vmt, size_t index, FnPtr auto destination) {
    if (auto hook = vmt.hook_method(index, destination)) {
        return std::move(*hook);
    } else {
        return {};
    }
}

} // namespace safetyhook