local Device = require("device")

local order = {
    ["KOMenu:menu_buttons"] = {
        "filemanager_settings",
        "setting",
        "tools",
        "search",
        "plus_menu",
        "main",
    },
    filemanager_settings = {
        "filemanager_display_mode",
        "filebrowser_settings",
        "----------------------------",
        "sort_by",
        "reverse_sorting",
        "sort_mixed",
        "----------------------------",
        "start_with",
    },
    setting = {
        -- common settings
        -- those that don't exist will simply be skipped during menu gen
        "frontlight", -- if Device:hasFrontlight()
        "night_mode",
        "----------------------------",
        "network",
        "screen",
        "----------------------------",
        "taps_and_gestures",
        "navigation",
        "document",
        "----------------------------",
        "language",
        "device",
        -- end common settings
    },
    document = {
        "document_metadata_location",
        "document_metadata_location_move",
        "document_auto_save",
        "document_end_action",
        "language_support",
    },
    device = {
        "keyboard_layout",
        "external_keyboard",
        "font_ui_fallbacks",
        "----------------------------",
        "time",
        "units",
        "device_status_alarm",
        "charging_led", -- if Device:canToggleChargingLED()
        "autostandby",
        "autosuspend",
        "autoshutdown",
        "ignore_sleepcover",
        "ignore_open_sleepcover",
        "cover_events",
        "ignore_battery_optimizations",
        "mass_storage_settings", -- if Device:canToggleMassStorage()
        "file_ext_assoc",
        "screenshot",
    },
    navigation = {
        "back_to_exit",
        "back_in_filemanager",
        "back_in_reader",
        "backspace_as_back",
        "----------------------------",
        "physical_buttons_setup",
        "----------------------------",
        "android_volume_keys",
        "android_haptic_feedback",
        "android_back_button",
        "----------------------------",
        "opening_page_location_stack",
        "skim_dialog_position",
    },
    network = {
        "network_wifi",
        "network_proxy",
        "network_powersave",
        "network_restore",
        "network_info",
        "network_before_wifi_action",
        "network_after_wifi_action",
        "network_dismiss_scan",
        "----------------------------",
        "ssh",
    },
    screen = {
        "screensaver",
        "autodim",
        "----------------------------",
        "screen_rotation",
        "----------------------------",
        "screen_dpi",
        "screen_eink_opt",
        "autowarmth",
        "color_rendering",
        "----------------------------",
        "screen_timeout",
        "fullscreen",
        "----------------------------",
        "screen_notification",
    },
    taps_and_gestures = {
        "gesture_manager",
        "gesture_intervals",
        "----------------------------",
        "ignore_hold_corners",
        "screen_disable_double_tab",
        "----------------------------",
        "menu_activate",
    },
    tools = {
        "calibre",
        "exporter",
        "statistics",
        "move_to_archive",
        "cloud_storage",
        "read_timer",
        "wallabag",
        "news_downloader",
        "send2ebook",
        "text_editor",
        "profiles",
        "qrclipboard",
        "----------------------------",
        "more_tools",
    },
    more_tools = {
        "auto_frontlight",
        "battery_statistics",
        "book_shortcuts",
        "synchronize_time",
        "keep_alive",
        "doc_setting_tweak",
        "terminal",
        "----------------------------",
        "plugin_management",
        "patch_management",
        "advanced_settings",
        "developer_options",
    },
    search = {
        "search_settings",
        "----------------------------",
        "dictionary_lookup",
        "dictionary_lookup_history",
        "vocabbuilder",
        "----------------------------",
        "wikipedia_lookup",
        "wikipedia_history",
        "----------------------------",
        "find_book_in_calibre_catalog",
        "find_file",
        "----------------------------",
        "opds",
    },
    search_settings = {
        "dictionary_settings",
        "wikipedia_settings",
    },
    main = {
        "history",
        "open_last_document",
        "----------------------------",
        "favorites",
        "collections",
        "----------------------------",
        "mass_storage_actions", -- if Device:canToggleMassStorage()
        "----------------------------",
        "ota_update", -- if Device:hasOTAUpdates()
        "help",
        "----------------------------",
        "exit_menu",
    },
    help = {
        "quickstart_guide",
        "----------------------------",
        "search_menu",
        "----------------------------",
        "report_bug",
        "----------------------------",
        "system_statistics", -- if enabled (Plugin)
        "version",
        "about",
    },
    plus_menu = {},
    exit_menu = {
        "restart_koreader", -- if Device:canRestart()
        "----------------------------",
        "sleep", -- if Device:canSuspend()
        "poweroff", -- if Device:canPowerOff()
        "reboot", -- if Device:canReboot()
        "----------------------------",
        "start_bq", -- if Device:isCervantes()
        "exit",
    }
}

if not Device:hasExitOptions() then
    order.exit_menu = nil
end
return order