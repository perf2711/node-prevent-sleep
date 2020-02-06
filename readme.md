# node-prevent-sleep

Allows to prevent the system from turning off the display, or suspending the computer.

## Usage

```javascript
const preventSleep = require("node-prevent-sleep");
// import preventSleep from 'node-prevent-sleep';

// Disables sleep
preventSleep.enable();

// Enables sleep
preventSleep.disable();
```

## How it works

### Windows

When `enable()` is used, `SetThreadExecutionState` is run with flags `ES_CONTINUOUS | ES_DISPLAY_REQUIRED`, which disables idle timer of system. The previous execution state is saved.

When `disable()` is used, previous execution state is used as argument to `SetThreadExecutionState`, enabling idle timer again (or just restoring previous behavior).

### Linux

Not supported yet. You are welcome to submit a PR with the functionality.

### Mac

Not supported yet. You are welcome to submit a PR with the functionality.

## License
MIT
