add_library(Settings SHARED)

target_sources(Settings
    PRIVATE
        dllmain1.cpp
        dllmain2.cpp
        dxcp_settings_json_blob.cpp
        pal_settings_json_blob.cpp
        settings_json_blob.h
)
