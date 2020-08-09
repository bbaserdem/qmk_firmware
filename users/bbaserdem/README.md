# Bbaserdem

My userspace code for my various keyboards; available here.

# Todo

- [x] Merge tapdance, macro and unicode into process.
- [x] Fix general naming and clean the code
- [x] Transition to new layers
- [x] Revamp RGB light codes
- [x] Fix music mode codes
- [ ] Transfer code to layout

# Keyboards

A list of my code accross the QMK repo accessible here.
(I will sell my built-but-not-using ones.)

## Currently Using

* [Planck](../../keyboards/planck/keymaps/bbaserdem): I have 3 plancks;
  * `rev6`, Office with Zilents
  * `rev6`, Home use with BOX Navys
  * `light`, Choc low Navy

## Built; but not really using

* [Planck](../../keyboards/planck/keymaps/bbaserdem)
A `rev4` from the past, with 
* [XD75](../../keyboards/xd75/keymaps/bbaserdem)
* [Let's Split Eh?](../../keyboards/lets_split_eh/keymaps/default)
* [Infinity Ergodox](../../keyboards/ergodox_infinity/keymaps/bbaserdem)
* [Gherkin](../../keyboards/gherkin/keymaps/bbaserdem), as a game pad.

## Planned builds

* [Corne](../../keyboards/crkbd/)
Linear switches (either BOX Dark Yellow, or Orange Healios V2)
I'm planning on adding a trackpad for this, as detailed 
[here](https://github.com/manna-harbour/crkbd/blob/master/trackpoint/readme.org).
* [Kyria](../../keyboards/kyria/)
Planning on using Choc low burnt orange on this board,
but possibly can go for tall switches.
I want to add a
[thumb slidepad](https://www.sparkfun.com/products/9426), or a 
[thumb joystick](https://www.sparkfun.com/products/15168) to this keyboard.

## Broken builds

* [Bigseries](../../keyboards/bigseries/1key/keymaps/bbaserdem)
While I used a big switch Pale Blue; this PCB is unavailable due to
Cole Markham (novelkeys) being a scammer and disappeared after not delivering
his group buys.
Hence can't get my hands on this PCB to rebuild things.
(No one else should attempt to purchase this; as his website is still up to
collect funds.)

# Features

My userspace has a lot of shared code between different keyboards.
These files are prefixed with `sbp-` to differentiate between main repo code.

* [bb-audio](bb-audio.c): Code dealing with audio playback using onboard sound.
Also contains stuff regarding using the devices as MIDI controllers. (WIP)
* [bb-backlight](bb-backlight.c): Controls global key single-channel LED stuff.
* [bb-keylight](bb-keylight.c): Controls per-key RGB LED matrix stuff.
* [bb-layout](bb-layout.h): My layout packaged for keymap files.
* [bb-mouse](bb-mouse.c): Contains new key definitions (diagonal navigation)
* [bb-process](bb-process.c): My custom keycodes; macros, tap dances, etc.
* [bb-underglow](bb-underglow.c): Controls RGB underglow effects.

## Current keyboards

* [Bigseries](../../keyboards/bigseries/1key/keymaps/bbaserdem)
* [Gherkin](../../keyboards/40percentclub/gherkin/keymaps/bbaserdem)
* [Let's Split Eh](../../keyboards/lets_split_eh/keymaps/bbaserdem)
* [Planck (rev 4, light and rev6)](../../keyboards/planck/keymaps/bbaserdem)
* [XD75](../../keyboards/xd75/keymaps/bbaserdem)

Unfortunately, the output on my bigswitch pcb broke,
and the producer woodkeys is AWOL, (along with my 200$ for the APX case)
thus I cannot really test it out.
Also, I'm using my planck all the time,
and am not testing the other layouts for bugs.

## Planned keyboards

* [Let's Split](../../keyboards/lets_split/keymaps/bbaserdem)
I have two proton C's, and i want to build a board that uses choc low switches.
I have the pcb for it, but I do need a case to solder in the switches.
For which, I have not seen anything.
* [Infinity Ergodox](../../keyboards/ergodox_infinity/keymaps/bbaserdem)
I have this at hand, but never could get the LED display to work.

# Layout

![Corne layout](https://i.imgur.com/6VvQZ2I.png)

My personal layout is mostly inspired by the
[Miryoku layout](../manna-harbour_miryoku/miryoku.org).
There are some changes to make it friendlier to international keyboards.
My board is compatible with software implementation of Dvorak and Turkish F.

## Base

Base layer uses tap-hold functionality to have access to modifiers.
The modifiers are mirrored on each half of the layout;
as to make those modifiers accessible to the keys that overlap them.
Besides the Alt key; each side has the proper L/R version of the modifier.
Since Right Alt key is the AltGr key;
both the L and R versions are availabel on each side.

The top-right key is there for artisan keycaps; but also triggers layer locks.
A layer lock happens when a layer is activated using a down-and-hold press;
and the lock key is activated.
When this happens; the layer activator key does not terminate the layer when released.

## Right Half

### Numeric

Creates a semi-numpad on the left half.
There are macros for paranthesis and bracket entries.
There is unicode entry in ellipsis on this layer.
The `MOD` key changes the macro and unicode entry code to be compliant with
software dvorak/turkish-f/qwerty.
Brackets seperately available on the thumb keys here as well.

### Symbol

Shifted version of the numeric layer to reduce the need to press three buttons.
Angular and curly bracket macros are on this layer as well.

### Function

Converts the keys into function keys.
Also overloads the tap-hold keys with regular counterparts to enable hold-entry.
Specifically for this layer; using it in conjunction with the center-left key
in the right half will activate game mode for the left half.

## Left Half

### Navigation

Navigation keys are on the home row in vim style.
Corresponding jump navigation is on the lower row; with insert here as well.
On the top row are Windows style macros;
* Ctrl-Z: Undo
* Ctrl-Y: Redo
* Ctrl+C: Copy
* Ctrl-X: Cut
* Ctrl-V: Paste

### Mouse

Used to utilize mouse movements.
The home row moves the cursor; the row below that scrolls in different directions.
The row below issues scroll in the given direction.

### Media

Used to control RGB effects and music playback.

## Game

Makes the left half into a standart planck qwety down.

## Music

Makes the full board into a midi playback device.
(WIP) make this into 19-TET tuning.

# Shoutout

Shoutout to drashna for getting the userspace shenanigans started;
all my code is pretty much inspired from his.
Shoutout to [Manna Harbour](../manna-harbour_miryoku/README.org) for their
amazing keymap that inspired me to recreate mine and allowed me to move to
smaller split keyboards.
Also a big shoutout to Alison Oğuz and Veysi Erkcan Özcan,
my professors in college,
for getting me started with the C language, and teaching me coding.
