This file contains my [4x12 ortho](../../../default/ortho_4x12) board layouts
Check out the [user readme](../../../../users/bbaserdem/README.md) for more info.

# Planck

I use a couple [planck](../../../../keyboards/planck/readme.md) keyboards.

* Use the [light](../../../../keyboards/planck/light/readme.md) version.
* Use the [rev6](../../../../keyboards/planck/rev6/readme.md) version.

I have a daughter board that I'm trying to use for perkey leds.
Both the per-key board LED's and the built in print for underglow LED's
use the `RGB_MATRIX` code.
One needs to be disabled in favor of the other.
I employed a `PLANCK_DAUGHTER_BOARD` variable in `rules.mk`;
flip it on/off to make a keymap for either.

## Status

* [x] Layout adapted
* [ ] Have not tested build yet.
* [ ] Have not confirmed on board

Build command: `CFLAGS="-Wno-error=deprecated" TBF`

# Let's Split Eh?

I have a [let's split eh?](../../../../keyboards/lets_split_eh/README.md).

## Status

* [x] Layout adapted
* [ ] Have not tested build yet.
* [ ] Have not confirmed on board

Build command: `CFLAGS="-Wno-error=deprecated" TBF`
