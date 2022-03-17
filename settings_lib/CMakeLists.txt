add_library(SettingsLib STATIC)

target_sources(SettingsLib
    PRIVATE
        libmain.cpp
        pal_settings_json_blob.cpp
        settings_json_blob.h
)

target_include_directories(SettingsLib PUBLIC .)
