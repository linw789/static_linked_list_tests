#include "pal_settings_json_blob.h"
#include <settings_json_blob.h>

// Linker will drop this because this is built as static lib and is not
// referenced by any code linker is trying to link.
PalSettingsJsonBlob g_pal_settings_json_blob;
