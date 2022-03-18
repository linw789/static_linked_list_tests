Experiments with linking a DLL against a static lib which contains a global
object.

The conclusion is that the global object is removed during linking because it's
never used by the DLL.
