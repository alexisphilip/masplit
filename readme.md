# MASPLIT

![The MAPSLIT keyboard](https://www.alexisphilip.fr/static/img/articles/2020-02-28-double-view.jpg)

<p style="text-align: center; font-style: italic;">
    The MASPLIT keyboard.
</p>

[*MASPLIT*]((https://www.alexisphilip.fr/masplit) ) (means *magnet* and *split*) is a handmade, 3D printed, ergonomic, ortholinear, split, programmable keyboard. Read  the whole [build log on my website](https://www.alexisphilip.fr/masplit).

In this repository are the 3D models in `STL` format, as well as my QMK keyboard firmare keymap.

## 3D files

All of the 3D `STL` files necessary to 3D print the keyboard.

## QMK code

To flash the keyboard, download and install [QMK firmware](https://docs.qmk.fm/#/).

> I recommend to first lean how to use QMK, then [how to use QMK for split keyboards](https://docs.qmk.fm/#/feature_split_keyboard?id=split-keyboard).

I copied the code from the *Let's Split* keyboard, and changed the keymap.

After QMK is intalled & set up, and your keymap set, compile the firmware.

```cmd
make masplit/rev2:default:avrdude
```

Then flash the right MCU.

```cmd
make masplit/rev2:default:avrdude-split-right
```

Then do the same for left MCU.

```cmd
make masplit/rev2:default:avrdude-split-left
```

> See further instructions on [how to use QMK for split keyboards](https://docs.qmk.fm/#/feature_split_keyboard?id=split-keyboard).