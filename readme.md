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

When `enable()` is used, power request is created using `PowerCreateRequest` and set using `PowerSetRequest` with flags `PowerRequestSystemRequired` and `PowerRequestDisplayRequired`, which prevents system sleeping.

When `disable()` is used, power request is cleared using `PowerClearRequest`, restoring previous behavior.

### Linux

Not supported yet. You are welcome to submit a PR with the functionality.

### Mac

Not supported yet. You are welcome to submit a PR with the functionality.

## License
MIT
