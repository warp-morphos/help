# Introduction

Help is an inline help tool for [MorphOS](http://www.morphos-team.net) Shell.

It's like *man* for [MorphOS](http://www.morphos-team.net).

# Features

- FULL documentation of 111 shell commands (MorphOS 1.4)
- Small howto on the Shell arguments
- Many examples included
- Search by name or domain
- Localization support

# Requirements

Any PowerPC computer running MorphOS 1.4+.

# Usage

Help understands the following arguments:

- **ALL**:  Displays a small description of all available commands
- **CMD**:  Displays a more complete description of the 'CMD' command
- **ARGS**: Displays MorphOS shell arguments HowTo
- **DOM**: Shows a complete description of all commands related to DOM ; DOM can be: SHELL, USB, PCI, GFX, AUDIO|SOUND, FILES|IO, REXX, TASKS, MISC, RESOURCES

# Examples

Show the full description of the dir command:

```
Ram Disk:> help CMD=DIR

DIR          - Lists files and directory names (w/o attributes)

DIR, OPT/K, ALL/S, DIRS/S, FILES/S, INTER/S

DIR    - directory to list
OPT    - provided for compatibility: depreciated!
AL     - displays all subdirectories and their files.
DIRS   - only displays directories
FILES  - only displays files
INTER  - enters an interactive listing mode (see below).

Interactive listing mode stops after each name to display a question mark
at which you can enter commands. The acceptable responses are show below:

[Return] - Displays the next name on the list.
[E]      - Enters a directory; the files in that directory are displayed.
[B]      - Goes back one directory level.
[DEL]    - Deletes a file or empty directory.
           DEL does not refers to the Del key; enter the letter D, E and L.
[T]      - Types the contents of a file
[C]      - Allows you to enter additional AmigaDOS commands.
[COMMAND]- Idem
[Q]      - Quits interactive editing.
[?]      - Displays a list of the available interactive-mode commands.
```
List every sound-related command:

```
Help DOM=USB

Commands found in the domain 'USB':

AddUSBClasses - Add or remove Classes from the USB stack
AddUSBHardware- Manually add or remove hardware to/from MorphOS
DRadioTool    - Controls an USB Radio manufactured by D-Link or GemTek
PenCamTool    - Read out images from an USB webcam using the STV680 chipset
USBDevLister  - Lists all found USB devices
USBErrorLog   - Shows all USB-Related messages since the start of the stack
```

> **NOTE:** If a string is given without the CMD nor DOM arguments, Help will first look for the command list and then the domain

```
MorphOS:> Help why
=> display the description of the Why command.
```

```
MorphOS:> Help shell
=> displays a list of the commands found in the 'Shell' domain.
```

# Building from sources

To build Help for MorphOS, you only need the MorphOS SDK, no other components are needed. Once configured, building Help is as simple as typing:

````
make
````

By default, make will invoke `ppc-morphos-gcc`: this can be configured in the makefile if needed.

# Notes about files encoding

MorphOS (just like AmigaOS) only supports 8bit text-encoding throughout the OS so every text file must be encoded using an ISO code page.

Each catalog `.ct` file must be encoded using the correct ISO variant: check the keyboard preferences to see
which one to use as that's what MorphOS uses as the encoding to display text files.

For example, the `français.ct` file is encoded using `ISO8859-1`.

UTF-8 could have been used but it meant every a string was to be printed in the shell it had to be encoded
from UTF-8 to the local ANSI ISO page.

# Background

This project started in September 2004.
I had it in mind for a long time but didn't start it
because I had some other projects in mind.

After having read a thread on some Amiga/MorphOS forum
where people were discussing a lack of such a tool for our
beloved OS, I said: "Ok, it's time to DO IT !"

After months of research, guesses (a lot of MorphOS commands
have extra options which are not documented anywhere
when compared with their AmigaOS equivalent), coding,
typing (the whole .cd file consists of no less than 1651 lines !),
I'm pleased to have documented almost all 111 shell commands :)
Only some undocumented arguments are missing.

# Thanks to

- Everyone who helped me (MDC, #morphos,...) on the documentation of all the commands.

- People sending spell errors and missing command args.

# Licence

Help
Copyright © 2004-2005 by Nicolas Ramz
Help is distributed under the MIT licence.

The MIT License (MIT)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
