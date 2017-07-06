# Returns Windows SDK number via out variable "ret"
function(vcpkg_get_windows_sdk ret)
    execute_process(
        COMMAND powershell.exe -NoProfile -ExecutionPolicy Bypass -Command "& {& '${VCPKG_ROOT_DIR}/scripts/getWindowsSDK.ps1'}" 2>&1
        OUTPUT_VARIABLE WINDOWS_SDK
        RESULT_VARIABLE error_code)

    if (error_code)
        message(FATAL_ERROR "Could not find Windows SDK")
    endif()

    # Remove trailing newline
    string(REGEX REPLACE "\n$" "" WINDOWS_SDK "${WINDOWS_SDK}")
    set(${ret} ${WINDOWS_SDK} PARENT_SCOPE)
endfunction()