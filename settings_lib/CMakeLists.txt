add_library(SettingsLib STATIC)

target_sources(SettingsLib
    PRIVATE
        libmain.cpp
        settings_json_blob.h
        pal_settings_json_blob.cpp
        pal_settings_json_blob.h
        all_pal_related_settings_json_blobs.h
)

target_include_directories(SettingsLib PUBLIC .)

set_property(TARGET SettingsLib PROPERTY POSITION_INDEPENDENT_CODE ON)