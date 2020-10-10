# SBP userspace code for qmk

My userspace code for my various keyboards; available here.

# Todo

- [ ] Create encoder switch functionality
- [ ] Add OLED support
- [ ] Centralize color definitions for RGB
- [ ] Document all features more extensibly
- [ ] Generate json files to be used with Keyboard-Layout-Editor to produce images.

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

### Planck HOME

* Board: planck/rev6
* Switches: Crystal BOX Navy
* Case: Planck Hi-Pro Bottom Case (MOD version): Matte Black
* Plate: Copper with shiny finish (LaserBoost) 
* Keycaps: Buger TH01 XDA Dye-Subbed PBT
* Artisan: Sparkle Loft Reactor Artisan Keycap

I use this at home.
Has all the extra pinouts exposed to play arounh with.

### Planck SERVER

* Board: jj40
* Switches: BOX Navy
* Case: Clear Acrylic Top and Bottow, with Frosted Acrylic Diffuser (Smashing Acrylics)
* Keycaps: Datamancer Tall Deco Typewriter Keycaps

I'm using this while I'm in between boards; but very usable.
Long term plan is to use this for the server.
The case was initially designed for planck rev4;
I'm replaced the PCB since my rev4 one was derelict
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
* Controller: Proton C
* Switches: Novelkeys Creams
* Keycaps: Random

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
* Keycaps: None

I don't like Infinity Ergodox.
Should sell this soon cause really not seeing myself ever using this.
Lucky me got the case for free due to (then) Massdrop shipping errors.

### Corne

* Board: crkbd/rev1
* Case: IMK Corne Case v2 Polycarbonate
* Switches: Healios V2
* Keycaps: POM Jelly

I'm planning on adding a trackpad for this, as detailed
[here](https://github.com/manna-harbour/crkbd/blob/master/trackpoint/readme.org).

### Corne Lite

* Board: crkbd/rev1
* Case: Custom
* Switches: Choc Low Burnt Orange
* Keycaps: [Scooped Choc Keycaps](https://mkultra.click/collections/keycaps/products/scooped-choc-keycaps?variant=31223543365730)

Getting my friend Irem to design a hipro stacked case for this.

### Kyria

* Board: kyria/rev1
* Case: Matte Black Acrylic High-Profile case
* Switches: Gateron Ink Silent Black
* Keycaps: Oblotzky SA Oblivion

Want to add a joystick to this board for mouse control.
Want to print a metal top plate for this.

### Big Switch

* Board: bigseries/1key
* Case: WoodKeys (KNOWN SCAMMER: DO NOT RECOMMEND)
* Switches: Big Series Pale Blue
* Keycaps: Idea23

Got this before being scammed out of 200$ by Cole Markham: owner of WoodKeys;
The usb port got torn off; and could not fix it.
Expensive paperweight?

# Firmware building

## Archlinux

On archlinux, the package *arm-none-eabi-gcc* is too new.
To fix; add to the environment `CFLAGS="-Wno-error=deprecated"` to compilation commands.
Also; try to run `avr-gcc` version `8.4.0` for smaller firmware.

## Bootloader

If I want to flash a new bootloader for a machine; here are steps;

1. Flash the util/pro_micro_ISP_B6_10.hex to a spare promicro using;
`avrdude -p atmega32u4 -P "$(ls /dev/ttyACM*)" -c avr109 -D -U flash:w:pro_micro_ISP_B6_10.hex`
2. Wire the pins; (first is the ISP pro micro; second is the target)
```
Pro Micro 10 (B6)  <-> Keyboard RESET
Pro Micro 15 (B1)  <-> Keyboard B1 (SCLK)
Pro Micro 16 (B2)  <-> Keyboard B2 (MOSI)
Pro Micro 14 (B3)  <-> Keyboard B3 (MISO)
Pro Micro VCC      <-> Keyboard VCC
Pro Micro GND      <-> Keyboard GND
```
3. Connect the flashed pro micro to my computer and run
`avrdude -c avrisp -P "$(ls /dev/ttyACM*)" -p atmega32u4 -U flash:w:bootloader_atmega32u4_1.0.0.hex:i -U lfuse:w:0x5E:m -U hfuse:w:0xD9:m -U efuse:w:0xC3:m`

The avrisp here refers to the firmware on the ISP flasher pro micro.
The `atmega32u4` refers to the CPU used in the respective breakout boards.
The `avrdude` command interacts with catalina bootloader.
The shell call after the `-P` flag auto finds the port that the pro micro connects to.
The last few arguments are some jumpers apparently.

# Features

My userspace has a lot of shared code between different keyboards.
These files are prefixed with `sbp-` to remove any naming clash.

* [sbp-audio](bb-audio.c): Code dealing with audio playback using onboard sound.
Also contains stuff regarding using the devices as MIDI controllers. (WIP)
* [sbp-backlight](bb-backlight.c): Controls global key single-channel LED stuff.
* [sbp-keylight](bb-keylight.c): Controls per-key RGB LED matrix stuff.
* [sbp-underglow](bb-underglow.c): Controls RGB underglow effects.
* [sbp-process](bb-macro.c): My custom keycodes; macros, tap dances, etc.
* [sbp-rotary](bb-rotary.c): Rotary encoder sutff

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
