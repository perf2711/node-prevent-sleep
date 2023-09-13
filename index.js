var os = require("os");

if (os.platform === "win32") {
  module.exports = require("./win");
} else if (os.platform === "darwin") {
  module.exports = require("./mac");
} else {
  throw new Error("Unsupported platform: " + os.platform);
}
