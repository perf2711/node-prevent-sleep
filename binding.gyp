{
    "targets": [{
        "target_name": "node_prevent_sleep",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "addon/prevent_sleep.cpp"
        ],
        "conditions": [
            ["OS=='linux'", {
                "sources": [ "addon/prevent_sleep_linux.cpp" ]
            }],
            ["OS=='win'", {
                "sources": [ "addon/prevent_sleep_win.cpp" ]
            }]
        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")"
        ],
        'libraries': [],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}
