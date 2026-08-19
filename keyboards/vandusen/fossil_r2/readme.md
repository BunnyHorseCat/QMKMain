# vandusen/fossil_r2

![fosl](imgur.com image replace me!)

The Fossil is a full sized keyboard sold by Carolina Mech and manufactured by Van Dusen Mfg.

* Keyboard Maintainer: [vandusen](https://www.vdmfg.com/) and [bunnyhorsecat](https://github.com/BunnyHorseCat/)
* Hardware Supported: Carolina Mech Fossil R2
* Hardware Availability: https://carolinamech.com/

Make example for this keyboard (after setting up your build environment):

For the standard Fossil R2 PCB:
    make vandusen/fossil_r2/standard:default

For the southpaw Fossil R2 PCB
    make vandusen/fossil_r2/southpaw:default

Flashing example for this keyboard:

For the standard Fossil R2 PCB:
    make vandusen/fossil_r2/standard:default:flash

For the southpaw Fossil R2 PCB
    make vandusen/fossil_r2/southpaw:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (Escape on both standard and southpaw PCBs) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
