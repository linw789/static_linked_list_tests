struct SettingsJsonBlob {
    static SettingsJsonBlob* first;
    static SettingsJsonBlob* last;
    SettingsJsonBlob* next;

    virtual const char* GetSettingsJsonBlob() {
        return 0;
    }
};