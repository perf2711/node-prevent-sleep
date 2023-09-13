var process = require("process");

if (/^win/.test(process.platform)) {
  module.exports = require("./win");
} else if (/^darwin/.test(process.platform)) {
  module.exports = require("./mac");
} else {
  throw new Error("Unsupported platform: " + process.platform);
}
