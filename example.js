const preventSleep = require("./index.js");
const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

(async () => {
    rl.write("enabling\n");
    preventSleep.enable();
    await new Promise(resolve => {
        rl.question("q to quit", answer => {
            switch (answer) {
                case "q":
                    rl.write("exiting\n");
                    return resolve();
                default:
                    rl.write("invalid option");
            }
        });
    });
    preventSleep.disable();
    rl.close();
})();
