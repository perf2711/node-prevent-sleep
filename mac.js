var child_process = require("child_process");
var process = require("process");

const preventSleep = {
  _caffeinateProcess: undefined,
  enable: () => {
    if (preventSleep._caffeinateProcess) {
      // We are already preventing sleep
      return;
    }
    preventSleep._caffeinateProcess = child_process.spawn("caffeinate", [
      "-w " + process.pid,
    ]);
    preventSleep._caffeinateProcess.on("error", () => {
      preventSleep._caffeinateProcess = undefined;
    });
    preventSleep._caffeinateProcess.on("exit", () => {
      preventSleep._caffeinateProcess = undefined;
    });
  },
  disable: () => {
    if (preventSleep._caffeinateProcess) {
      preventSleep._caffeinateProcess.kill();
      preventSleep._caffeinateProcess = undefined;
    }
  },
};

module.exports = preventSleep;
