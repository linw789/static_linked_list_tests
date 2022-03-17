add_library(SettingsDll SHARED)

target_sources(SettingsDll
    PRIVATE
        dllmain.cpp
        dxcp_settings_json_blob.cpp
)

# get_target_property(SettingsLibIncludes SettingsLib INCLUDE_DIRECTORIES)
# message(FATAL_ERROR "SettingsLib Incudes: ${SettingsLibIncludes}")

target_link_libraries(SettingsDll PRIVATE SettingsLib)
