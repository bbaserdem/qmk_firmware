# Bbaserdem

My userspace code for my various keyboards; available here.

# Todo

- [ ] Redo the number and symbol layer
- [ ] Centralize color definitions for RGB
- [ ] Document all features more extensibly
- [ ] Generate json files to be used with Keyboard-Layout-Editor to produce images.
- [ ] Add OLED support

# Keyboards

A list of my code accross the QMK repo accessible here.
(I will sell my built-but-not-using ones.)

## Builds

These are my keyboard builds and info, it allows me to plan out my builds. 

### Planck WORK

* Board: planck/rev6
* Switches: Zilent
* Case: Planck Hi-Pro Bottom Case: Glossy White
* Plate: Stainless steel with shiny finish (LaserBoost) 
* Keycaps: Pudding PBT Doubleshot Keycap Set
* Artisan: B.O.B StoneuCarved Lotus Artisan Keycap
* Artisan: Teamwolf 304 Stainless Steel Transparent Metal Keycaps

I use this at the workplace to not bother coworkers; focus on silence.
Once the daughterboard is complete; this is gonna get it.

### Planck HOME

* Board: planck/rev6
* Switches: Crystal BOX Jade
* Case: Planck Hi-Pro Bottom Case (MOD version): Matte Black
* Plate: Copper with shiny finish (LaserBoost) 
* Keycaps: Buger TH01 XDA Dye-Subbed PBT
* Artisan: Sparkle Loft Reactor Artisan Keycap

I use this at home.
Has all the extra pinouts exposed to play arounh with.
Once the daughterboard is complete; this is gonna get it.

### Planck SERVER

* Board: planck/rev6
* Switches: Crystal BOX Navy
* Case: Clear Acrylic Top and Bottow, with Frosted Acrylic Diffuser (Smashing Acrylics)
* Keycaps: Datamancer Tall Deco Typewriter Keycaps
* Artisan: Hammer Fidget Spinner Artisan Keycap

I'm using this while I'm in between boards; but very usable.
Long term plan is to use this for the server.
The case was initially designed for planck rev4;
I'm replacing the PCB with my first round rev6 since my rev4 one was derelict
due to repeated desolderings.

### Planck CARRY

* Board: planck/light
* Switches: Choc Low Jade
* Case: Stock Planck light case
* Keycaps: Blanck MKB

I carry this around; and is one of my favourite boards.
Found a better keycap profile for these as well.

### XD75RE

* Board: xd75
* Switches: Zealios 67g + Silencios
* Case: Npkc 60% Wooden Case (Rosewood)
* Keycaps: Massdrop x MITO XDA Godspeed
* Artisan: Hammer Fidget Spinner Artisan Keycap
* Artisan: Waffle Key Studio Rosette (Sunset)

My first work board; that is not seing any use due to being big.

### Gherkin PAD

* Board: 40percentclub/gherkin
* Case: Acrylic Case (Smashing Acrylics)
* Controller: Pro Micro 
* Switches: Gateron Yellows
* Keycaps: Random (Replace with blanck XDA)

The point of this is to act like a game/macro pad.
Other than that; i just use this for bragging points.
I have been planning on using my Proton C to turn into a MIDI controller.

### Let's Split Eh?

* Board: lets_split_eh/eh
* Case: Acrylic Case (Smashing Acrylics)
* Switches: Novelkeys BOX Royals 
* Keycaps: G20 Semiotics

I built this; but then I realized that I really don't enjoy ortholinear split.

### Infinity Ergodox

* Board: ergodox_infinity
* Case: Datamancer Wooden case
* Switches: Kailh Speed Gold
* Keycaps: G20 Semiotics

I don't like Infinity Ergodox.
I got lucky with this drop;
but should sell this soon cause really not seeing myself ever using this.
Lucky me got the case for free due to (then) Massdrop shipping errors.

### Corne

* Board: crkbd/rev1
* Case: IMK Corne Case Space Black
* Switches: Healios V2
* Keycaps: ???

Want to add a trackpad to this board for mouse control.
Will join the drop for this case when it comes out.
Going to be lubing these switches.

### Corne THEORYBOARD

* Board: crkbd/rev1
* Case: ???
* Switches: Choc Low Burnt Orange
* Keycaps: ???

Want to use this to test and design using a joystick as a mouse controller.
Has the 6th column broken off.

### Kyria

* Board: kyria/rev1
* Case: ??? 
* Switches: Gateron Ink Silent Black
* Keycaps: Oblotzky SA Oblivion

Want to add a joystick to this board for mouse control.
Have not decided on a case design for this.

### Big Switch

* Board: bigseries/1key
* Case: WoodKeys (KNOWN SCAMMER: DO NOT RECOMMEND)
* Switches: Big Series Pale Blue
* Keycaps: Default

Got this before being scammed out of 200$ by Cole Markham: owner of WoodKeys;
The usb port got torn off; so gonna need to fix it sometime.

## Planned builds

* [Planck](../../layouts/community/ortho_4x12/bbaserdem)
Planning on another `rev6`, to use at home use with Gateron Yellow for my server.
* [Corne](../../layouts/community/split_3x6_3/bbaserdem)
Linear switches (getting a switch tester to check it out
I'm planning on adding a trackpad for this, as detailed
[here](https://github.com/manna-harbour/crkbd/blob/master/trackpoint/readme.org).
* [Kyria](../../keyboards/kyria/keymaps/bbaserdem)
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
Might repair this with a bit of epoxy; as it's just the contact.

# Firmware building

## Archlinux

On archlinux, the package *arm-none-eabi-gcc* is too new.
To fix; add to the environment `CFLAGS="-Wno-error=deprecated"` to compilation commands.

# Features

My userspace has a lot of shared code between different keyboards.
These files are prefixed with `bb-` to remove any naming clash.

* [bb-audio](bb-audio.c): Code dealing with audio playback using onboard sound.
Also contains stuff regarding using the devices as MIDI controllers. (WIP)
* [bb-backlight](bb-backlight.c): Controls global key single-channel LED stuff.
* [bb-keylight](bb-keylight.c): Controls per-key RGB LED matrix stuff.
* [bb-underglow](bb-underglow.c): Controls RGB underglow effects.
* [bb-process](bb-macro.c): My custom keycodes; macros, tap dances, etc.
* [bb-rotary](bb-rotary.c): Rotary encoder sutff

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
