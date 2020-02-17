const internalSleep = require('./build/Release/node_prevent_sleep.node');

const preventSleep = {
    _timerId: 0,
    _intervalTime: 5000,
    enable: () => {
        preventSleep._timerId = setInterval(internalSleep.enable, preventSleep._intervalTime);
    },
    disable: () => {
        clearInterval(preventSleep._timerId);
        internalSleep.disable();
    }
};

module.exports = preventSleep;
