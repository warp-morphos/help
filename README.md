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
Help CMD=DIR
```

List every sound-related command:

```
Help DOM=AUDIO
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
