/****************************************************************
   This file was created automatically by `FlexCat 2.6'
   from "Help.cd".

   Do NOT edit by hand!
****************************************************************/

/****************************************************************
    This file uses the auto initialization possibilities of
    Dice, gcc and SAS/C, respectively.

    Dice does this by using the keywords __autoinit and
    __autoexit, SAS uses names beginning with _STI or
    _STD, respectively. gcc uses the asm() instruction,
    to emulate C++ constructors and destructors.

    Using this file you don't have *all* possibilities of
    the locale.library. (No Locale or Language arguments are
    supported when opening the catalog. However, these are
    *very* rarely used, so this should be sufficient for most
    applications.
****************************************************************/


/*
    Include files and compiler specific stuff
*/
#include <exec/memory.h>
#include <libraries/locale.h>
#include <libraries/iffparse.h>

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/locale.h>
#include <proto/utility.h>
#include <proto/iffparse.h>

#include <stdlib.h>
#include <string.h>



#include "Help_cat.h"


/*
    Variables
*/
struct FC_String Help_Strings[261] = {
    { (STRPTR) "Builds and removes audio modes that AHI can understand", 0 },
    { (STRPTR) "FILES   - Specifies which descriptor(s) to be added to the current mode list.\n"\
	"QUIET   - If specified, will suppress error and output messages\n"\
	"REFRESH - Scan `DEVS:Audiomodes' and add all descriptors found there to\n"\
	"          the current mode list.\n"\
	"REMOVE  - Flush the current audio mode list from memory.\n"\
	"DBLSCAN - Will open and then immediately close a native, double-scan screen.\n"\
	"          On some systems using a graphic card, this will\n"\
	"          enable >28 kHz sample frequencies with the native audio.\n"\
	"          You need an appropriate monitor driver in `DEVS:Monitors'\n"\
	"          to make it work.\n", 1 },
    { (STRPTR) "Defines how many buffers are allocated for a drive", 2 },
    { (STRPTR) "DRIVE   - Drive for which to change allocated buffers\n"\
	"BUFFERS - Number of buffers to add or remove\n\n"\
	"If only drive argument is specified, AddBuffers displays the number of buffers\n"\
	"currently allocated for that drive.\n\n"\
	"Example: AddBuffers dh0: -100\n\n"\
	"=> Removes 100 buffers for the drive DH0:\n", 3 },
    { (STRPTR) "Activates datatypes or adds another datatype", 4 },
    { (STRPTR) "FILES   - names of the data type descriptors to add to the existing list.\n"\
	"QUIET   - suppresses error and output messages.\n"\
	"REFRESH - scans the DEVS:DataTypes dir for new or changed\n"\
	"          data type descriptors.\n\n"\
	"Data type descriptors are stored in DEVS:DataTypes.\n"\
	"These descriptors allow programs such as MultiView to interpret\n"\
	"different data file types. AddDataTypes can also be called by\n"\
	"application installation scripts to add their own data types to the list.\n", 5 },
    { (STRPTR) "Add or remove Classes from the USB stack", 6 },
    { (STRPTR) "QUIET  - if used, no messages are printed into the shell.\n"\
	"REMOVE - remove all classes instead of adding them.\n", 7 },
    { (STRPTR) "Manually add or remove USB hardware to/from MorphOS", 8 },
    { (STRPTR) "DEVICE - required argument containing the (absolute) path and name of\n"\
	"         the USB hardware device driver to add or remove.\n"\
	"UNIT   - optional unit number, if multiple units are supported.\n"\
	"         Default is unit 0.\n"\
	"QUIET  - if used, no messages are printed into the shell.\n"\
	"REMOVE - try to remove the entry, if found, instead of adding it.\n"\
	"         Be careful to use the same path/filename you used to add the\n"\
	"         hardware.\n"\
	"ALL    - tries to add all units of the given device. If REMOVE is\n"\
	"         specified, it removes all entries, effectively taking the\n"\
	"         stack offline.\n\n"\
	"Note: After adding the hardware driver, a class scan is done automatically.\n", 9 },
    { (STRPTR) "Sets or displays command aliases.", 10 },
    { (STRPTR) "NAME   - name of the Alias.\n"\
	"STRING - string to use when this alias is encountered\n\n"\
	"Alias creates aliases, or alternative names, for AmigaDOS commands.\n"\
	"Alias can be used to abbreviate frequently used commands or replace\n"\
	"standard command names with different names.\n\n"\
	"NOTE: You can use arguments in an Alias using '[]' (see example below).\n\n"\
	"Example 1:\n"\
	"  MorphOS:> Alias hi echo \"Hello !\"\n"\
	"  MorphOS:> hi\n"\
	"  Hello !\n"\
	"  MorphOS:>\n\n"\
	"Example 2:\n"\
	"  MorphOS:> alias ls list []\n"\
	"  MorphOS:> ls ram:\n"\
	"  Directory \"ram:\" on Tuesday 25-Jan-05\n"\
	"  T                                  Dir ----rw-d Today 21:56:42\n"\
	"  ENV                                Dir ----rw-d Today 21:32:40\n"\
	"  Clipboards                         Dir ----rw-d Today 21:32:39\n"\
	"  disk.info                         5792 ----rwed Today 21:32:44\n"\
	"  2 files - 3 directories - 6542 bytes used\n", 11 },
    { (STRPTR) "Displays a question at the execution of a script", 12 },
    { (STRPTR) "PROMPT - Text (question) to display.\n\n"\
	"Ask displays a question and waits for an answer.\n"\
	"This answer can be 'Y' (Yes), 'N' (No) or nothing (ie: user simply\n"\
	"pressed [return]). If user answers nothing, Ask will consider the answer\n"\
	"as being negative. To indicate to other commands the answer received,\n"\
	"Ask will set the condition flag to a specific value (see IF command):\n"\
	"if the answer is No, the falg is set to 5 (WARN), 0 Otherwise\n\n"\
	"Example:\n\n"\
	"SYS:> Type my_batch_file\n"\
	"Ask \"Do you own a Pegasos ? (YES/NO) \"\n"\
	"If Warn\n"\
	"    Echo \"You answered Yes.\"\n"\
	"Else\n"\
	"    Echo \"You answered No.\"\n\n"\
	"SYS:> Execute my_batch_file\n"\
	"Do you own a Pegasos ? (YES/NO) yes\n"\
	"You answered Yes.\n"\
	"SYS:>\n", 13 },
    { (STRPTR) "Lists, creates, modifies or removes an assign from MorphOS", 14 },
    { (STRPTR) "NAME     - name of the assign\n"\
	"TARGET   - target of the assign\n"\
	"LIST     - if used, a list of all current assignments is displayed.\n"\
	"DISMOUNT - disconnects a volume or device from the list of mounted devices.\n"\
	"DEFER    - creates a late-binding Assign. This Assign takes effect when\n"\
	"           the assigned object is first referenced, rather than when\n"\
	"           the assignment is made. When the DEFER option is used, the disk\n"\
	"           containing the assigned target is not needed until the object\n"\
	"           is called. The assignment then remains valid until explicitly\n"\
	"           changed.\n"\
	"PATH     - The PATH option creates a non-binding Assign.\n"\
	"           A non-binding Assign acts like a DEFERed Assign, except that\n"\
	"           is re-evaluated each time the assigned name is referenced.\n"\
	"ADD      - does not replace any existing target assigned to NAME.\n"\
	"           This target is added to the Assign list and the system\n"\
	"           searches for all the targets when NAME is encountered.\n"\
	"REMOVE   - deletes a target name from the Assign list.\n"\
	"VOLS     - limits the display to volumes when LIST is used\n"\
	"DIRS     - limits the display to directories when LIST is used\n"\
	"DEVICES  - limits the display to devices when LIST is used\n\n"\
	"Example:\n\n"\
	"SYS:> Assign FONTS: MyFonts:Fontdir\n"\
	"assigns the FONTS: directory to Fontdir on MyFonts:\n", 15 },
    { (STRPTR) "Displays the amount of free memory available", 16 },
    { (STRPTR) "FAST  - Displays the amount of free FAST memory\n"\
	"CHIP  - Displays the amount of free CHIP memory\n"\
	"TOTAL - Displays the total amount of memory available to MorphOS\n"\
	"HUMAN - Uses human-readable units instead of using bytes\n"\
	"FLUSH - Frees all unused libraries, devices, fonts and catalogs\n", 17 },
    { (STRPTR) "Flashes the current front-most screen", 18 },
    { (STRPTR) "This command will flashes current front-most screen\n", 19 },
    { (STRPTR) "Activates device drivers in expansion drawer (outdated)", 20 },
    { (STRPTR) "BindDrivers loads and runs device drivers for add-on hardware.\n"\
	"These devices are automatically configured by the expansion library if\n"\
	"their device drivers are in the SYS:Expansion directory.\n\n"\
	"NOTE: The BindDrivers command must appear in the Startup-sequence\n"\
	"file to configure the hardware when the system is booted.\n", 21 },
    { (STRPTR) "Allows to send a signal (for eg. CTRL+C) to a process", 22 },
    { (STRPTR) "PROCESS - number of the process to send a signal to\n"\
	"ALL     - sends all signals to the process (see below)\n"\
	"C       - sends a CTRL+C\n"\
	"D       - sends a CTRL+D\n"\
	"E       - sends a CTRL+E\n"\
	"F       - sends a CTRL+F\n\n"\
	"Break sets the specified attention flags in the PROCESS indicated.\n"\
	"Use the Status command to display the current process numbers.\n"\
	"By default, only the Ctrl+C flag is set.\n\n"\
	"Break acts the same as selecting the relevant process by clicking\n"\
	"in its window and pressing the appropriate Ctrl+key combinations.\n\n"\
	"Ctrl+C is the default for sending a Break signal to halt a process.\n"\
	"A process that has been aborted this way displays ***Break\n"\
	"in the Shell window. Ctrl+D halts execution of a script file.\n", 23 },
    { (STRPTR) "Changes or displays current directory", 24 },
    { (STRPTR) "DIR - name of the new directory\n\n"\
	"CD with no arguments displays the name of the current directory.\n"\
	"When a valid directory name is given, CD makes the named directory\n"\
	"the current directory.\n\n"\
	"NOTE: To move directly to the root directory of the current device,\n"\
	"      use CD followed by a space and a colon; for example, CD :\n\n"\
	"NOTE2: MorphOS supports an implied CD so that the CD command itself\n"\
	"       can often be left out. Enter the directory name, path, colon,\n"\
	"       or slashes at the prompt.\n\n"\
	"Example 1: SYS:> cd libs\n"\
	"           SYS:libs/>\n\n"\
	"Example 2: SYS:MorphOS/C/> //\n"\
	"           SYS:>\n", 25 },
    { (STRPTR) "Changes the priority of the given process", 26 },
    { (STRPTR) "PRIORITY - new priority of the process\n"\
	"PROCESS  - number of the process to change priority\n\n"\
	"The range of acceptable values for PRIORITY is the integers\n"\
	"from -128 to 127, with higher values yielding a higher priority\n"\
	"(a greater proportion of CPU time is allocated).\n"\
	"However, do not enter values above +10 to avoid disrupting\n"\
	"important system tasks.\n\n"\
	"NOTE: use the Status command to display the current process numbers.\n", 27 },
    { (STRPTR) "Starts a new interactive CLI on the system", 28 },
    { (STRPTR) "This command starts a new interactive CLI on MorphOS.\n"\
	"A new window will be opened rather than opening a new tab\n"\
	"in the current CLI window.\n", 29 },
    { (STRPTR) "Activates or De-activates the Clipboard", 30 },
    { (STRPTR) "CLIPUNIT - clipboard device unit number to use (from 0 to 255).\n"\
	"OFF      - turns off cut/paste in the current Shell.\n\n"\
	"NOTE: Using the OFF option causes the Shell command to stop interacting\n"\
	"      with the system Clipboard during cutting and pasting operations.\n"\
	"      We recommend that you do not use this option.\n", 31 },
    { (STRPTR) "Copies a source file or directory to another directory", 32 },
    { (STRPTR) "FROM    - files or directory to copy.\n"\
	"TO      - destination path-name or file\n"\
	"PATTERN - when FROM is a directory, only files matching this pattern\n"\
	"          will be copied.\n"\
	"BUFFER  - size of the buffer (multiple of 512 bytes)to use during the copy\n"\
	"ALL     - includes sub-directories if FROM is a directory\n"\
	"DIRECT  - copy file without any tests or options\n"\
	"CLONE   - keeps timestamp, comments, and protec. bits of the FROM file.\n"\
	"DATES   - the timestamp of the FROM file is copied to the TO file.\n"\
	"NOPRO   - The protection bits of the FROM file are not copied\n"\
	"          to the TO file. The TO file is given standard protection bits\n"\
	"          or r, w, e, and d.\n"\
	"COMMENT - the comments of the FROM file are copied to the TO file.\n"\
	"QUIET   - suppresses output messages/errors and requesters.\n"\
	"NOREQ   - errors such as disk full, or assign not existing will cause\n"\
	"          the display of a requester. Using this switch will remove them.\n"\
	"ERRWARN - do not proceed when one file failed.\n"\
	"MAKEDIR - produce directories.\n"\
	"MOVE    - delete source files after the copying successful.\n"\
	"DELETE  - do not copy but delete the source files.\n"\
	"HARD    - make a hardlink to source instead of copying.\n"\
	"SOFT    - make a sourcelink to source instead of copying.\n"\
	"FOLNK   - also makes links to directories.\n"\
	"FODEL   - delete protected files as well.\n"\
	"FOOVR   - also overwrites protected files.\n"\
	"DONTOVR - do not overwrite files if they already exist\n"\
	"FORCE   - DEPRECIATED: if files already exist and are write-protected,\n"\
	"          this option will force them to be overwritten\n\n"\
	"Copy copies the file or directory specified with the FROM argument\n"\
	"to the file or directory specified by the TO argument.\n"\
	"You can copy several items at once by giving more than one name/pattern\n"\
	"in the FROM argument; they should be separated by spaces.\n"\
	"If the FROM argument is a pattern or consists of multiple names,\n"\
	"the TO argument must be a directory.\n\n"\
	"If a TO file name already exists, Copy overwrites the TO file with\n"\
	"the FROM file. You can use a pair of double quotation marks (\"\")\n"\
	"to refer to the current directory. When used as the FROM argument,\n"\
	"\"\" copies all the files in the current directory.\n"\
	"Do not put any spaces between the double quotation marks.\n", 33 },
    { (STRPTR) "Displays information about the CPU of the computer", 34 },
    { (STRPTR) "CACHE           - turns on all caches\n"\
	"BURST           - turns on burst mode for both data and instructions\n"\
	"NOCACHE         - turns off all caches\n"\
	"NOBURST         - turns on burst mode for both data and instructions\n"\
	"DATACACHE       - turns on data cache\n"\
	"DATABURST       - turns on burst mode for data\n"\
	"NODATACACHE     - turns off data cache\n"\
	"NODATABURST     - turns off burst mode for data\n"\
	"INSTCACHE       - turns on instruction cache\n"\
	"INSTBURST       - turns on burst mode for instructions\n"\
	"NOINSTCACHE     - turns off instruction cache\n"\
	"NOINSTBURST     - turns off burst mode for instructions\n"\
	"COPYBACK        - activates copyback mode\n"\
	"NOCOPYBACK      - de-activates copyback mode\n"\
	"EXTERNALCACHE   - activates external cache\n"\
	"NOEXTERNALCACHE - de-activates external cache\n"\
	"FASTROM         - with a processor having a supported MMU, copies the\n"\
	"                  system ROM into 32-bit RAM, making access to operating\n"\
	"                  system functions significantly faster. CPU then\n"\
	"                  write-protects the RAM area so that\n"\
	"                  the data cannot be changed.\n"\
	"NOFASTROM       - turns off FASTROM\n"\
	"TRAP            - this option is for developers only.\n"\
	"NOTRAP          - this option is for developers only.\n"\
	"NOMMUTEST       - allows the MMU settings to be changed without checking\n"\
	"                  to see if an MMU is currently in use.\n"\
	"CHECK           - the CHECK option, when given with a keyword\n"\
	"                  (68010, 68020, 68030, 68040, 68881, 68882,\n"\
	"                  or 68851, MMU, FPU) checks for the presence of\n"\
	"                  the processor indicated by the keyword.\n", 35 },
    { (STRPTR) "Displays or sets the date and time of the system", 36 },
    { (STRPTR) "DAY  - sets the day to DAY\n"\
	"DATE - sets the date to DATE\n"\
	"TIME - sets the time to TIME\n"\
	"TO   - sets the date to that of the TO file\n\n"\
	"Date with no argument displays the currently set system time and date,\n"\
	"including the day of the week. Time is displayed using a 24-hour clock.\n\n"\
	"Date DATE sets only the date. The format for entry and display of DATE\n"\
	"is DD-MMM-YY (day-month-year). The hyphens between the arguments\n"\
	"are required. A leading zero in the date is not necessary.\n"\
	"The number or the first three letters of the month (in English)\n"\
	"must be used, as well as the last two digits of the year.\n", 37 },
    { (STRPTR) "Deletes one or more files/directories", 38 },
    { (STRPTR) "FILE        - file, directory or pattern-matching files to delete\n"\
	"ALL         - if specified, deletes sub-directories as well\n"\
	"QUIET       - suppresses error/warning messages\n"\
	"FORCE       - if file is write-protected, un-protect it first\n"\
	"FOLLOWLINKS - if links are detected, will follow the links\n\n"\
	"NOTE: MorphOS does not request confirmation of deletions.\n"\
	"Do not use pattern matching to delete things if your are not familiar\n"\
	"with the procedure; deleted items cannot be recovered,\n"\
	"unless you have an up-to-date backup of the items deleted.\n\n"\
	"Example: SYS:> Delete Dh0:not_important_stuff/#? ALL FORCE\n"\
	"         deletes all the files on Dh0:not_important_stuff,\n"\
	"         even those set as not deletable.\n\n"\
	"See also: Protect command.\n", 39 },
    { (STRPTR) "Displays a list of all devices present in memory", 40 },
    { (STRPTR) "DevList will display a list of all devices, including\n"\
	"their address, version/revision and open count.\n", 41 },
    { (STRPTR) "Lists file and directory names (w/o attributes)", 42 },
    { (STRPTR) "DIR   - directory to list\n"\
	"OPT   - provided for compatibility: depreciated !\n"\
	"ALL   - displays all subdirectories and their files.\n"\
	"DIRS  - only displays directories\n"\
	"FILES - only displays files\n"\
	"INTER - enters an interactive listing mode (see below).\n\n"\
	"Interactive listing mode stops after each name to display a question mark\n"\
	"at which you can enter commands. The acceptable responses are shown below:\n\n"\
	"[Return] - Displays the next name on the list.\n"\
	"[E]      - Enters a directory; the files in that directory are displayed.\n"\
	"[B]      - Goes back one directory level.\n"\
	"[DEL]    - Deletes a file or empty directory. \n"\
	"           DEL does not refer to the Del key; enter the letters D, E, and L.\n"\
	"[T]      - Types the contents of a file.\n"\
	"[C]      - Allows you to enter additional AmigaDOS commands.\n"\
	"[COMMAND]- Idem.\n"\
	"[Q]      - Quits interactive editing.\n"\
	"[?]      - Displays a list of the available interactive-mode commands.\n", 43 },
    { (STRPTR) "Informs MorphOS of a diskchange", 44 },
    { (STRPTR) "DEVICE - name of the device for which to perform a diskchange.\n\n"\
	"NOTE: this command is only provided for compatibility. It was used\n"\
	"      on the Amiga with 5.25 disk drives to inform the OS of a diskchange.\n", 45 },
    { (STRPTR) "Displays available space of specified volume", 46 },
    { (STRPTR) "VOLUME    - volume for which to display free space\n"\
	"NOPOSTFIX - displays free space in bytes\n"\
	"PERCENT   - displays free in percentage instead of MB/GB\n\n"\
	"If no volume is specified, available space on the current volume is\n"\
	"displayed.\n", 47 },
    { (STRPTR) "Controls an USB Radio manufactured by D-Link or GemTek", 48 },
    { (STRPTR) "ON     - turns the radio ON\n"\
	"OFF    - turns the radio OFF again\n"\
	"FREQ   - sets the current frequency to the given value. It must be\n"\
	"         given in kHz and range between 87 MHz and 108 MHz.\n"\
	"SCAN   - starts a frequency scan. It starts at 87 MHz, if no FREQ value\n"\
	"         had been given and stops at 107 MHz. If a radio channel is\n"\
	"         detected it will output its frequency in KHz on the shell.\n"\
	"         The last found channel will be kept. The scan can be aborted\n"\
	"         at any time using Ctrl-C.\n"\
	"AUTO   - only useful in conjunction with the SCAN switch. If a station\n"\
	"         is found, the program will pause for three seconds, asking the\n"\
	"         user to press Ctrl-C to keep the radio station found.\n"\
	"SIGNAL - sets the shell return value to WARN (5), if no radio station\n"\
	"         is detected on the current frequency. If there's a stereo\n"\
	"         signal, it will return OK (0). This switch can be used to\n"\
	"         implement a manual scan routine.\n"\
	"UNIT   - if multiple radios are connected, you can choose the right\n"\
	"         unit with this argument. Defaults to unit 0 of course.\n\n"\
	"Examples:  DRadioTool ON SCAN AUTO\n"\
	"           DRadioTool FREQ 104000\n", 49 },
    { (STRPTR) "Displays the specified message", 50 },
    { (STRPTR) "/M      -\n"\
	"NOLINE  - does not automatically move the cursor to the next line\n"\
	"          after printing the string.\n"\
	"FIRST   - see below\n"\
	"LEN     - see below\n"\
	"TO      - redirects output to TO file\n\n"\
	"The FIRST and LEN options allow the echoing of a substring.\n"\
	"FIRST indicates the character position from which to begin the echo;\n"\
	"LEN indicates the number of characters of the substring to echo,\n"\
	"beginning with the FIRST character. If the FIRST option is omitted\n"\
	"and only the LEN keyword is given, the substring printed consists\n"\
	"of the rightmost <n> characters of the main string.\n"\
	"For example, if your string is 20 characters long and you specify\n"\
	"LEN 4, the 17TH, 18th, 19th, and 20th characters of the string are echoed.\n", 51 },
    { (STRPTR) "Specifies an alternative for an IF statement in a script file.", 52 },
    { (STRPTR) "Else must be used in conjunction with the If command.\n"\
	"Else is used in an If block of a script to specify an alternative action\n"\
	"if the If condition is not true. If the If condition is not true,\n"\
	"execution of the script jumps from the If line to the line after Else;\n"\
	"all intervening commands are skipped. If the If condition is true,\n"\
	"the commands immediately following the If statement are executed\n"\
	"up to the Else. Then, execution skips to the EndIf statement\n"\
	"that concludes the IF block.\n\n"\
	"Example: Assume a script, called Display, contains the following block:\n\n"\
	"IF exists picfile\n"\
	"    MultiView picfile\n"\
	"ELSE\n"\
	"    ECHO \"picfile is not in this directory\"\n"\
	"ENDIF\n\n"\
	"If picfile can be found in the current directory, the MultiView program\n"\
	"is executed and picfile is displayed on the screen.\n"\
	"If picfile cannot be found in the current directory, the script skips\n"\
	"to the ECHO command. The following message is displayed in the Shell window:\n"\
	"'picfile is not in this directory'\n", 53 },
    { (STRPTR) "Closes CLI/Shell Window or Tab", 54 },
    { (STRPTR) "That's it :)\n", 55 },
    { (STRPTR) "Terminates an IF block in a script file.", 56 },
    { (STRPTR) "EndIf must be used when an If command is used. EndIf is used in scripts\n"\
	"at the end of an If block. If the If condition is not true or\n"\
	"if the true-condition commands are executed and an Else is encountered,\n"\
	"the execution of the script skips to the next EndIf command.\n"\
	"Every If statement must be terminated by an EndIf.\n\n"\
	"NOTE: the EndIf applies to the most recent If or Else command.\n"\
	"See also: If, Else for examples using the EndIf command.\n", 57 },
    { (STRPTR) "Closes CLI/Shell Window or Tab", 58 },
    { (STRPTR) "That's it :)\n", 59 },
    { (STRPTR) "Stops a SKIP branch", 60 },
    { (STRPTR) "EndSkip is used in scripts to terminate the execution of a Skip block.\n"\
	"A Skip block allows you to jump over intervening commands if a certain\n"\
	"condition is met. When an EndSkip is encountered, execution of the script\n"\
	"resumes at the line following the EndSkip.\n"\
	"The condition flag is set to 5 (WARN).\n\n"\
	"See also: Skip command.\n", 61 },
    { (STRPTR) "Evaluates a mathematical expression", 62 },
    { (STRPTR) "VALUE1  - value 1: can be decimal, hexadecimal or octal (see below)\n"\
	"OP      - a supported operator (see below)\n"\
	"VALUE2  - value 2: can be decimal, hexadecimal or octal (see below)\n"\
	"TO      - filename where to redirect eval result\n"\
	"LFORMAT - formatting string used to print the answer (see below)\n\n"\
	"About VALUE1 and VALUE2:\n\n"\
	".Hexadecimal numbers are indicated by either a leading Ox or #x.\n"\
	".Octal numbers are indicated by either a leading 0 or a leading #.\n"\
	".Alphabetical characters are indicated by a leading single\n"\
	" quotation mark (`) and are evaluated as their ASCII equivalent.\n\n"\
	"The LFORMAT keyword specifies the formatting string used to print the answer.\n"\
	"You can use %X (hexadecimal), %O (octal), %N (decimal), or %C (character).\n"\
	"The %X and %O options require a number of digits using the LFORMAT keyword,\n"\
	"you can specify to print a new line by including *N in your string.\n\n"\
	"Supported Operations:\n\n"\
	"addition       +\n"\
	"subtraction    -\n"\
	"multiplication *\n"\
	"division       /\n"\
	"modulo         mod, M, m, or %\n"\
	"bitwise AND    &\n"\
	"bitwise OR     |\n"\
	"bitwise NOT    ~\n"\
	"left shift     Ish, L, or |\n"\
	"right shift    rsh, R, or r\n"\
	"negation       -\n"\
	"exclusive OR   xor, X, or x\n"\
	"bitwise        eqv, E, or e\n"\
	"equivalence\n\n"\
	"Example: SYS:> EVAL 0x5f / 010 LFORMAT=\"The answer is %X4*N\"\n"\
	"         The answer is 000B\n"\
	"         SYS:>\n", 63 },
    { (STRPTR) "Executes a batch file", 64 },
    { (STRPTR) "FILE - filename of the batch file to execute\n\n"\
	"Execute is used to run scripts of MorphOS commands.\n"\
	"The lines in the script are executed as if they had been entered\n"\
	"at a Shell prompt. If the s protection bit of a file is set and the file\n"\
	"is in the search path, enter only the file name;\n"\
	"the Execute command is not needed.\n", 65 },
    { (STRPTR) "Changes failure limit for scripts (0=Ok, 5=Warn, 10=Error)", 66 },
    { (STRPTR) "RCLIM - Return Code Limit (initial value: 10)\n\n"\
	"Commands indicate that they have failed by setting a nonzero return code.\n"\
	"The return code, normally 5, 10, or 20, indicates the severity of the error.\n"\
	"A return code greater than or equal to a certain limit, the fail limit,\n"\
	"terminates a sequence of non-interactive commands\n"\
	"(commands specified after RUN or in a script).\n\n"\
	"Use the FailAt command to alter the fail limit RCLIM (Return Code Limit)\n"\
	"from its initial value of 10. If you increase the limit, you indicate that\n"\
	"certain classes of error should not be regarded as fatal and that execution\n"\
	"of subsequent commands can proceed after the error.\n"\
	"The argument must be a positive number. The fail limit is reset to the\n"\
	"initial value of 10 on exit from the command sequence.\n", 67 },
    { (STRPTR) "Translates numeric error codes to ASCII text", 68 },
    { (STRPTR) "/N/M - Numeric value(s) to translate\n\n"\
	"Example: SYS:> fault 204 205\n"\
	"         Fault 204: directory not found\n"\
	"         Fault 205: object not found\n"\
	"         SYS:>\n", 69 },
    { (STRPTR) "Set a comment for a file", 70 },
    { (STRPTR) "FILE    - name of the file to attach a comment\n"\
	"COMMENT - string to attach to the file\n"\
	"          if this argument is omitted, any existing filenote\n"\
	"          is deleted from the named file.\n"\
	"ALL     - adds the COMMENT to all the files and subdirectories\n"\
	"          matching the pattern entered.\n"\
	"QUIET   - suppresses error messages\n\n"\
	"If the COMMENT includes spaces, it must be enclosed in double\n"\
	"quotation marks.\n\n"\
	"NOTE: To include double quotation marks in a filenote, each literal\n"\
	"quotation mark must be immediately preceded by an asterisk (*)\n"\
	"and the entire comment must be enclosed in quotation marks,\n"\
	"regardless of whether the commend contains any spaces.\n\n"\
	"NOTE2: File comments are limited to 79 characters.\n", 71 },
    { (STRPTR) "Removes unused libraries from memory", 72 },
    { (STRPTR) "LIBRARY - name of the libraries to flush\n"\
	"ONCE    - one flush per library only\n"\
	"QUIET   - Suppresses output messages\n", 73 },
    { (STRPTR) "Formats a disk", 74 },
    { (STRPTR) "DRIVE        - name of the device to format\n"\
	"NAME         - label of the formatted device\n"\
	"OFS          - use Old File System (depreciated)\n"\
	"FFS          - use Fast File System\n"\
	"SFS          - use Smart File System\n"\
	"MSDOS        - use MSDOS (FAT) File System\n"\
	"INTL         - for FFS: use international mode\n"\
	"NOINTL       - for FFS: do not use international mode\n"\
	"DIRCACHE     - for FFS: use directory cache\n"\
	"NODIRCACHE   - for FFS: do not use directory cache\n"\
	"LNFS         - for FFS: enable long filenames\n"\
	"NOLNFS       - for FFS: disable long filenames\n"\
	"NOICONS      - do not create an icon on the formatted device\n"\
	"QUICK        - only do a quick-format\n"\
	"NORECYCLED   - for SFS: do not add a recycled directory\n"\
	"SHOWRECYCLED - for SFS: do not hide the recycled directory\n\n"\
	"NOTE: SFS provides a special directory at the root of the device\n"\
	"called '.recycled'. When files are deleted they automatically appear\n"\
	"in this directory so recovering deleted files is just a matter of copying\n"\
	"files from this directory to anywhere else on the disk.\n\n"\
	"Example: SYS:> Format drive DH0: name MorphOS SFS showrecycled\n\n"\
	"         => Will format the device DH0: using SFS filesystem.\n"\
	"            The recycle directory will be available and not hidden\n"\
	"            The disk will be labeled 'MorphOS'\n", 75 },
    { (STRPTR) "Displays a list of all FileSystem present in memory", 76 },
    { (STRPTR) "This command gives a lot information about each FileSysEntry\n"\
	"returned by filesystem.resource.\n\n"\
	"See also: ResList, LibList, TaskList and DevList commands.\n", 77 },
    { (STRPTR) "Benchmarks some basic FileSystem operations", 78 },
    { (STRPTR) "FILE     - Not Documented\n"\
	"SIZE     - Not Documented\n"\
	"OFFSET   - Not Documented\n"\
	"RETRY    - Not Documented\n"\
	"CHIP     - Not Documented\n"\
	"NOACTUAL - Not Documented\n\n"\
	"This command peforms some tests in order to benchmark filesystem\n"\
	"operations.\n\n"\
	"WARNING: This command should be used with *care* as it performs\n"\
	"         not only read tests but also write tests.\n"\
	"         => Bad usage of it can cause loss of data !\n\n"\
	"See also: FSList, HDTest.\n", 79 },
    { (STRPTR) "Displays the contents of a local environment variable", 80 },
    { (STRPTR) "NAME - name of the local variable to display\n\n"\
	"Get is used to retrieve and display the value of a local environment variable.\n"\
	"The value is displayed in the current window.\n\n"\
	"Local environment variables are only recognized by the Shell in which\n"\
	"they are created or by any Shells created from a NewShell command\n"\
	"executed in the original Shell. If you open an additional Shell\n"\
	"by opening the Shell icon or by using the Execute Command menu item,\n"\
	"previously created local environment variables are not available.\n\n"\
	"See also: Set command.\n", 81 },
    { (STRPTR) "Displays the contents of a global environment variable", 82 },
    { (STRPTR) "NAME - name of the global variable to display\n\n"\
	"GetEnv is used to retrieve and display the value of\n"\
	"a global environment variable. The value is displayed in the current window.\n"\
	"Global variables are stored in ENV: and are recognized by all Shells.\n\n"\
	"See also: SetEnv command.\n", 83 },
    { (STRPTR) "Reads sector(s) from device/unit and dumps them to shell", 84 },
    { (STRPTR) "DEVICE     - Device name from where to read\n"\
	"UNIT       - Device unit to use\n"\
	"SECTOR     - Start sector to dump\n"\
	"COUNT      - Number of sectors to read\n"\
	"SECTORSIZE - Optional: sector size\n\n"\
	"See also: HDTest command.\n", 85 },
    { (STRPTR) "Benchmark FileSystem operations using direct device access", 86 },
    { (STRPTR) "DEVICE     - Name of the device to access\n"\
	"UNIT       - Device unit to use\n"\
	"SECTOR     - Not Documented\n"\
	"SIZE       - Not Documented\n"\
	"OFFSET     - Not Documented\n"\
	"CHIP       - Not Documented\n"\
	"NOACTUAL   - Not Documented\n"\
	"NUMDATA    - Not Documented\n"\
	"SECTORSIZE - Not Documented\n\n"\
	"This command acts like FSTest but uses direct device access instead\n"\
	"of file access.\n\n"\
	"WARNING: This command should be used with *CAUTION* as it will not\n"\
	"         only perform read tests but also write tests.\n"\
	"         => Bad usage of it can cause loss of data !\n\n"\
	"See also: FSTest and HDRead commands.\n", 87 },
    { (STRPTR) "Send all active ARexx programs an external halt request.", 88 },
    { (STRPTR) "Sets the global halt flag, which causes all active ARexx programs\n"\
	"to receive an external halt request.\n"\
	"Each program will exit immediately unless its HALT interrupt has been enabled.\n"\
	"The halt flag does not remain set, but is cleared automatically\n"\
	"after all current programs have received the request.\n", 89 },
    { (STRPTR) "Executes a batch file from the desktop (Ambient)", 90 },
    { (STRPTR) "NOTE: IconX is used only as a default tool in a project icon\n"\
	"and cannot be used as a Shell command.\n\n"\
	"To use IconX, create or copy a project icon for the script.\n"\
	"Open the icon's Information window and change the Default Tool\n"\
	"of the icon to C:IconX and select Save to store the changed .info file.\n"\
	"The script can then be executed by double-clicking on the icon.\n"\
	"When the icon is opened, IconX changes the current directory to\n"\
	"the directory containing the project icon before executing the script.\n"\
	"A console window can be opened on the Ambient screen\n"\
	"if the script produces output.\n", 91 },
    { (STRPTR) "Adds intelligent branching to scripts", 92 },
    { (STRPTR) "NOT    - reverses the interpretation of the result.\n"\
	"WARN   - true if previous return code is greater than or equal to 5.\n"\
	"ERROR  - true if previous return codes is greater than or equal to 10;\n"\
	"         only available if FailAt is set to greater than 10.\n"\
	"FAIL   - True if previous return code is greater than or equal to 20;\n"\
	"         only available if FailAt is set to greater than 20.\n"\
	"EQ     - a EQ b: true if the text of a is greater than the text of b\n"\
	"         (disregarding case).\n"\
	"         use NOT GT for less than.\n"\
	"GT     - a GT b: true if the text of a is greater than\n"\
	"         or equal to the text of b (disregarding case).\n"\
	"         use NOT GE for less than or equal to.\n"\
	"GE     - a GE b: true if the text of a is greater than or equal to\n"\
	"         the text of b (disregarding case).\n"\
	"         use NOT GE for less than or equal to.\n"\
	"VAL    - a VAL b: true if the text of a and b is identical (disregarding case).\n"\
	"EXISTS - true if the specified file or directory exists.\n"\
	"NOREQ  - suppresses error requesters\n\n"\
	"NOTES: if more than one of the three condition-flag\n"\
	"       keywords (WARN, ERROR, FAIL) are given, the one\n"\
	"       with the lowest value is used.\n\n"\
	"       You can use local or global variables with If by\n"\
	"       prefacing the variable name with a $ character.\n\n"\
	"Example:\n\n"\
	"If EXISTS Work/Prog\n"\
	"    Type Work/Prog HEX\n"\
	"Else\n"\
	"    Echo \"It's not here\"\n"\
	"EndIf\n", 93 },
    { (STRPTR) "Displays information about mounted filesystems", 94 },
    { (STRPTR) "DISKS    - only shows information about disks\n"\
	"VOLS     - only shows information about volumes\n"\
	"GOODONLY - do not show information about bad (not recognized) disks\n"\
	"BLOCKS   - uses block units instead of GB/MB\n"\
	"VERBOSE  - gives more information\n"\
	"DEVICES  - devices to show (if omitted, displays all devices)\n", 95 },
    { (STRPTR) "Initialises preferences files on startup", 96 },
    { (STRPTR) "IPrefs reads the individual system Preferences files and passes\n"\
	"the information to the system. IPrefs is generally run in\n"\
	"the Startup-Sequence after the Preferences files are copied to ENV:.\n"\
	"Each time a user selects Save or Use from within an editor,\n"\
	"IPrefs is notified and passes the information to the system.\n\n"\
	"If necessary, IPrefs resets Ambient to implement those changes.\n"\
	"If any Shell, project, or tool windows are open,\n"\
	"IPrefs displays a requester asking you to close them.\n", 97 },
    { (STRPTR) "Joins several files into one bigger file", 98 },
    { (STRPTR) "FILE - file(s) or pattern to match\n"\
	"AS   - destination filename\n\n"\
	"Join copies all the listed files, in the order given, to one new file.\n"\
	"This destination file cannot have the same name as any of the source files.\n"\
	"You must supply a destination file name. The original files remain unchanged.\n"\
	"Any number of files can be Joined in one operation.\n\n"\
	"Example: SYS:> Join Part1 Part2 Part3 AS Textfile\n", 99 },
    { (STRPTR) "Defines a label in a batch file", 100 },
    { (STRPTR) "Lab is used in script to define a label that is searched for by the Skip command.\n"\
	"The label can be of any length, but must be alphanumeric. No symbols are allowed.\n"\
	"If the label contains spaces, it must be enclosed in quotation marks.\n\n"\
	"Example:\n\n"\
	"If EXISTS ram:test\n"\
	"    SKIP oky\n"\
	"EndIf\n\n"\
	"echo \"File 'ram:test' does not exist.\"\n"\
	"QUIT\n\n"\
	"LAB oky\n"\
	"echo \"File 'ram:test' exists.\"\n", 101 },
    { (STRPTR) "Compresses or uncompresses files/dirs", 102 },
    { (STRPTR) "This command uses non-standard arguments.\n"\
	"Type 'LHA' in a Shell for a complete documentation of its arguments.\n", 103 },
    { (STRPTR) "Displays information about libraries present in memory", 104 },
    { (STRPTR) "LibList will display a list of all libs present in memory, including\n"\
	"their address, version/revision, flags and open count.\n", 105 },
    { (STRPTR) "Lists the contents of the specified directory", 106 },
    { (STRPTR) "DIR     - directory, filename or pattern to match\n"\
	"PAT     - if specified, only files/dirs matching this pattern will be listed\n"\
	"KEYS    - displays the block number of each file header or directory\n"\
	"DATES   - displays the dates\n"\
	"NODATES - do not display the dates\n"\
	"TO      - specifies an output file or device for List;\n"\
	"          by default, List outputs to the current window\n"\
	"SUB     - lists only files containing the substring SUB\n"\
	"SINCE   - lists only files timestamped on or after the specified date\n"\
	"UPTO    - lists only files timestamped on or before the specified date\n"\
	"QUICK   - lists only the names of files and directories\n"\
	"BLOCK   - displays file sizes in 512-byte blocks, rather than bytes\n"\
	"NOHEAD  - suppresses printing of the header and summary information\n"\
	"FILES   - lists files only (no directories)\n"\
	"DIRS    - lists directories only (no files)\n"\
	"LFORMAT - defines a string to specially format List output\n"\
	"SORT    - see below\n"\
	"USERS   - shows user owner of the files\n"\
	"GROUPS  - shows groups which the files belong to\n"\
	"ALL     - lists the contents of all directories and subdirectories\n\n"\
	"the 'SORT' keyword requires any of N=NAME, D=DATE, S=SIZE, RN=REVERSENAME,\n"\
	"                                   RD=REVERSEDATE,RS=REVERSESIZE\n\n"\
	"The LFORMAT option modifies the output of List and can be used as\n"\
	"a quick method of generating script files. When using LFORMAT,\n"\
	"specify an output format string; this string is output for each file\n"\
	"or directory normally listed. It can contain any text you specify,\n"\
	"plus the usual List output information. When LFORMAT is specified,\n"\
	"the QUICK and NOHEAD options are automatically selected.\n"\
	"To save the output, you must redirect it to a file by using\n"\
	"the > operator or specifying a TO file.\n\n"\
	"The available substitution operators are:\n\n"\
	"%A  Prints file attributes (protection bits).\n"\
	"%B  Prints size of file in blocks.\n"\
	"%C  Prints any comments attached to the file.\n"\
	"%D  Prints the date associated with the file.\n"\
	"%E  Prints just the file extension.\n"\
	"%K  Prints the file key block number.\n"\
	"%L  Prints the length of the file in bytes.\n"\
	"%M  Prints the file name only, omitting any extension.\n"\
	"%N  Prints the name of the file.\n"\
	"%P  Prints the file parent path.\n"\
	"%S  Superseded by %N and %P; still functional.\n"\
	"%T  Prints the time associated with the file.\n"\
	"You can put a length specifier and/or a justification specifier\n"\
	"between the percent sign (%) and the field specifier.\n"\
	"To specify left justification, place a minus sign (-)\n"\
	"before the length specifier. Otherwise, the information\n"\
	"displayed is right justified.\n\n"\
	"NOTE: The default output of the LIST command uses the following specification:\n"\
	"      %-24 %7L %A %D %T\n", 107 },
    { (STRPTR) "Loads monitor (ie: graphic) drivers", 108 },
    { (STRPTR) "EXCEPT    - don't load this monitor\n"\
	"STACKSIZE - specifies the stacksize to use\n", 109 },
    { (STRPTR) "Loads the desktop manager (Ambient)", 110 },
    { (STRPTR) "DEBUG       - provided for compatibility: does nothing\n"\
	"DELAY       - Provided for compatibility: does nothing\n"\
	"CLEANUP     - Provided for compatibility: does nothing\n"\
	"NEWPATH     - specify new search path (see below)\n"\
	"NOWBSTARTUP - do not execute programs found in SYS:WBStartup drawer\n\n"\
	"Ambient snapshots the current paths in effect when the LoadWb command\n"\
	"is executed.\n"\
	"It uses these paths for each Shell started from Ambient.\n"\
	"NEWPATH allows you to specify a new path that is snapshot\n"\
	"from the current Shell.\n", 111 },
    { (STRPTR) "Write-protects a drive", 112 },
    { (STRPTR) "DRIVE   - name of the drive to write-protect\n"\
	"ON      - set write-protect status to ON\n"\
	"OFF     - set write-protect status to OFF\n"\
	"PASSKEY - optional: pass-key; changing again the write-protect status\n"\
	"          of the device will require this passkey\n", 113 },
    { (STRPTR) "Creates a Directory", 114 },
    { (STRPTR) "NAME - name of the directories you wish to create\n\n"\
	"The command works within only one directory level at a time,\n"\
	"so any directories on the given paths must already exist.\n"\
	"The command fails if a directory or a file of the same name already exists\n"\
	"in the directory in which you attempt to create a new one.\n\n"\
	"NOTE: Makedir does not create a drawer icon for the new directory.\n", 115 },
    { (STRPTR) "Creates a hard or soft link", 116 },
    { (STRPTR) "FROM  - file to create a link to\n"\
	"TO    - name and path of the link to create\n"\
	"HARD  - use this option to create a hard link\n"\
	"FORCE - you must use this option in order to create a directory link\n\n"\
	"NOTE: If MakeLink detects that you are creating a circular link,\n"\
	"      such as a link to a parent directory, a Link loop not allowed\n"\
	"      message is issued.\n", 117 },
    { (STRPTR) "Runs a memory test", 118 },
    { (STRPTR) "VERBOSE   - Be more precise on errors found\n"\
	"QUIET     - If specified, no messages are printed to the Shell\n"\
	"DISABLE   - Disables Multitasking while doing the test\n"\
	"EXTENSIVE - Do a more complete memory test\n"\
	"REVERSE   - This allocates memory from the top of the memory pool\n"\
	"DELAY     - Delay (in seconds) to wait between each test\n", 119 },
    { (STRPTR) "Makes a new device known to MorphOS", 120 },
    { (STRPTR) "DEVICE - name of the device to mount (see below)\n"\
	"FROM   - mountlist to use to mount the device (see below)\n"\
	"DEBUG  - outputs a lot of debug text\n\n"\
	"Mount reads a device's configuration parameters from a file.\n"\
	"It then uses the parameter information to mount the devices or\n"\
	"make them available to the system.\n"\
	"Multiple devices can be mounted with a single command. The DEVICE argument\n"\
	"specifies the names of the devices to be mounted.\n\n"\
	"Mount can process either DOSDrivers mount files or a traditional\n"\
	"multiple-entry MountList file, depending on which of the following\n"\
	"three ways the arguments are specified:\n\n"\
	" 1. Given a device name, Mount tries to find a mount file of that name\n"\
	"    in DEVS:DOSDrivers, then in SYS:Storage/DOSDrivers, and finally as an\n"\
	"    entry in DEVS:MountList. This method is best if you have only one\n"\
	"    configuration for that device on your system.\n\n"\
	" 2. Given a path, Mount looks for a mount file in that location.\n"\
	"    Wildcards may be used to mount multiple devices; as in\n"\
	"    Mount DEVS:DOSDrivers/~(#?.info). Use this method when you have\n"\
	"    mount files stored somewhere other than the DOSDrivers drawers\n"\
	"    or if you have several mount file to process at once.\n\n"\
	" 3. Given the FROM keyword and a path, Mount specifies the location\n"\
	"    of a MountList file to process. Use this method if you have a MountList\n"\
	"    stored somewhere other than DEVS: or if you have several MountLists.\n\n"\
	"Example:  SYS:> Mount PIPE:\n"\
	"          This looks for the mount file DEVS:DOSDrivers/PIPE\n"\
	"          and processes it if found. If DEVS:DOSDrivers/PIPE does not exist,\n"\
	"          Mount looks for SYS:Storage/DOSDrivers/PIPE. If this also fails,\n"\
	"          then MOUNT looks for a PIPE: entry in DEVS:MountList.\n\n"\
	"Example2: Mount PIPE: FROM SYS:Mydevs/MountList\n"\
	"          This scans for a PIPE entry in SYS:Mydevs/MountList.\n", 121 },
    { (STRPTR) "Starts a new interactive CLI/SHELL on the system", 122 },
    { (STRPTR) "WINDOW - window specifications\n"\
	"FROM   - CON device to use (use CON: for standard MorphOS shell)\n\n"\
	"NewCli starts a new Shell process. See the NewShell command for more info.\n", 123 },
    { (STRPTR) "Starts a new interactive CLI/SHELL on the system", 124 },
    { (STRPTR) "WINDOW - window specifications (see below)\n"\
	"FROM   - script to execute at shell startup (default is S:Shell-Startup)\n\n"\
	"Using the WINDOW parameter, you specify the initial dimensions, location,\n"\
	"and title of the window with this syntax:\n"\
	"x      number of pixels from the left edge of the screen to\n"\
	"       the left border of the Shell window.\n"\
	"       Use a value (//) to specify the minimum possible pixels.\n"\
	"y      number of pixels from the top of the screen to\n"\
	"       the top of the Shell window.\n"\
	"       Use no value (//) to specify the minimum possible pixels.\n"\
	"width  width of the Shell window, in pixels.\n"\
	"       Use no value (//) to specify the full width of the screen.\n"\
	"height height of the Shell window, in pixels.\n"\
	"       Use no value (//) to specify minimum possible height.\n"\
	"title  text that appears in the Shell window title bar.\n\n"\
	"Options can be one or more of:\n"\
	"AUTO       The window automatically appears when the program\n"\
	"           needs input or produces output. With the Shell window, it opens\n"\
	"           for input immediately. The window can only be closed\n"\
	"           with the EndShell command. Selecting the Shell's close gadget\n"\
	"           closes the window, but it re-opens immediately\n"\
	"           since it is expecting input.\n"\
	"ALT        The window appears in the specified size and position when\n"\
	"           the zoom gadget is clicked. The four parameters must be\n"\
	"           separated with slashes (for example, ALT30/30/200/200).\n"\
	"BACKDROP   The window appears on the backdrop, behind all the\n"\
	"           Ambient windows. This Shell window cannot be brought\n"\
	"           to the front of the screen; you have to resize the\n"\
	"           Ambient windows to see it.\n"\
	"CLOSE      The window has all the standard gadgets, including\n"\
	"           a close gadget. This is the default for Shell windows,\n"\
	"           but you must specify it to get a standard Shell if\n"\
	"           you use the WINDOW argument.\n"\
	"INACTIVE   The window opens, but is not made the active window.\n"\
	"NOBORDER   The window opens without any left or bottom window border.\n"\
	"           Only the zoom, depth, and sizing gadgets are available.\n"\
	"NOCLOSE    The window does not have a close gadget. If you open\n"\
	"           a console normally, there is no close gadget. If you open\n"\
	"           a console using the AUTO option, there is automatically\n"\
	"           a close gadget on the window.\n"\
	"NODEPTH    The window has no window depth gadget.\n"\
	"NODRAG     The window cannot be dragged.\n"\
	"           It has zoom, depth and sizing gadgets, but no close gadget.\n"\
	"NOSIZE     The window only has a depth gadget.\n"\
	"SCREEN     The window opens on a public screen. The screen must already exist.\n"\
	"           You must specify the name of the screen after the SCREEN keyword.\n"\
	"SIMPLE     If you enlarge the window, the text expands to fill the newly\n"\
	"           available space, allowing you to see text that had been\n"\
	"           scrolled out of the window. This is the default\n"\
	"           for standard Shells.\n"\
	"SMART      If you enlarge the window, the text does not expand\n"\
	"           to fill the newly available space. This saves memory.\n"\
	"WAIT       The window can only be closed by selecting the close gadget\n"\
	"           or entering Ctrl+\. If WAIT is the only option,\n"\
	"           there is no close gadget.\n\n"\
	"Example: SYS:> NewShell \"CON://640/480/My Shell/CLOSE\"\n"\
	"         Opens a shell window in top-left corner, of size 640x480,\n"\
	"         a close gadget and of name 'My Shell'.\n", 125 },
    { (STRPTR) "Displays information about PCI cards using OpenPCI.Library", 126 },
    { (STRPTR) "Displays numerous informations about all PCI devices\n"\
	"(including internal devices such as IDE controllers,...) present\n"\
	"on the motherboard: deviceID/vendorID, IRQ, Mem/Rom/IO Address range,...\n", 127 },
    { (STRPTR) "Sets or displays the search path for executables", 128 },
    { (STRPTR) "PATH   - Path to one or more directories\n"\
	"ADD    - If specified, add selected dirs to current search path\n"\
	"SHOW   - If specified, only show a list of current search path\n"\
	"RESET  - If specified, replaces current path with selected dirs\n"\
	"REMOVE - If specified, remove selected dirs from current path\n"\
	"QUIET  - If specified, Path does not display requesters for volumes\n"\
	"         that are not currently mounted.\n\n"\
	"NOTE: the search path is only relevant when MorphOS is searching for\n"\
	"      a command or program to execute.\n"\
	"      Full path specifications are always necessary in arguments\n"\
	"      for commands such as COPY and DELETE.\n", 129 },
    { (STRPTR) "This command outputs extensive information about the PCI bus", 130 },
    { (STRPTR) "DATA    - Display information about data (?)\n"\
	"VERBOSE - Be more verbose\n", 131 },
    { (STRPTR) "Tool to communicate with PCI devices", 132 },
    { (STRPTR) "BUS  - Not documented\n"\
	"DEV  - Not documented\n"\
	"FUNC - Not documented\n"\
	"REG  - Not documented\n"\
	"DATA - Not documented\n"\
	"SIZE - Not documented\n\n"\
	"WARNING: this is a *dangerous* tool: expert users only !\n"\
	"         If you were one of these you wouldn't ask for its documentation :)\n", 133 },
    { (STRPTR) "Read out images from an USB webcam using the STV680 chip", 134 },
    { (STRPTR) "TO       - Mandatory filename to save the picture to\n"\
	"PICNUM   - Number of the picture to load from the camera's RAM,\n"\
	"           starting with 0 for the first picture. If no picture\n"\
	"           exists with this number, you will get garbage\n"\
	"INTERVAL - If this numeric parameter is given, PencamTool will loop\n"\
	"           and take pictures at the given interval (in ticks, 50\n"\
	"           ticks is one second). Interval is only sensible, if you\n"\
	"           don't give PICNUM argument\n"\
	"UPTO     - If specified, multiple pictures can be grabbed in one go,\n"\
	"           starting at the PICNUM number and stopping at the UPTO\n"\
	"           number. Be sure to give a format string such as \"%ld\"\n"\
	"           inside the filename or you will write all pictures to\n"\
	"           the same image. If no PICNUM is given, but INTERVAL\n"\
	"           instead, UPTO describes the image number to stop the\n"\
	"           regular picture taking\n"\
	"NOBEEP   - Disable BEEP on downloading an image\n"\
	"GAMMA    - Enable white balance and gamma correction with the give\n"\
	"           floating point gamma value. 0.45 is a good setting\n"\
	"           If you only want white balance and no gamma correction,\n"\
	"           use a value of 1.0\n"\
	"SHARPEN  - Apply a highly optimized 5x5 sharpen filter on the image\n"\
	"TEXT     - Optionally adds the given line of text to the bottom of\n"\
	"           the picture. If the line is too long to fit, it will be\n"\
	"           truncated\n"\
	"FONT     - Name of the font to use (e.g. xen.font). If this parameter\n"\
	"           is missing, the default system font will be used\n"\
	"FONTSIZE - Size of the font in pixels\n"\
	"UNIT     - If several cameras are connected, specify the unit to use.\n"\
	"           Defaults to unit 0.\n\n"\
	"Examples:\n"\
	"  PencamTool Snap.ppm\n"\
	"  PencamTool Snap.ppm 0 GAMMA 0.45 SHARPEN\n"\
	"  PencamTool Movie%04ld.ppm INTERVAL 0 GAMMA 0.5\n"\
	"  PencamTool Webcam.ppm GAMMA 0.45 SHARPEN TEXT \"Platon's Cam\"\n"\
	"             FONT small.font FONTSIZE 6 NOBEEP\n"\
	"  PencamTool Shotseries%03ld.ppm 0 UPTO 79 GAMMA 0.45 SHARPEN\n", 135 },
    { (STRPTR) "Changes the prompt for the current CLI/Shell", 136 },
    { (STRPTR) "PROMPT - New prompt string\n\n"\
	"The default prompt string is: \"%N.%S>\"\n"\
	"which displays the Shell number, a period, the current directory,\n"\
	"a right angle-bracket, and a space. Entering Prompt without\n"\
	"a string argument resets the prompt to this default.\n\n"\
	"The substitutions available for the <PROMPT> string are:\n"\
	"%N - Displays the process number for the Shell\n"\
	"%S - Displays the current directory\n"\
	"%R - Displays the return code for the last operation\n\n"\
	"NOTE:  a space is not automatically added to the end of the string.\n"\
	"       If you want a space between the prompt and typed-in text, place it\n"\
	"       in the string, and enclose the string in double quotation marks.\n"\
	"NOTE2: You can embed commands in the prompt string by\n"\
	"       enclosing the command in back apostrophes (`).\n\n"\
	"Example:\n"\
	"  1> PROMPT \"%N.%S.%R>\"\n"\
	"  1.MorphOS:Apps.0>\n\n"\
	"  - the Shell number,\n"\
	"  - current directory,\n"\
	"  - return code of the previous command\n", 137 },
    { (STRPTR) "Changes the protection flags of a file", 138 },
    { (STRPTR) "FILE  - Medatory: name/pattern of the files\n"\
	"FLAGS - Flags to modify (see below)\n"\
	"ADD   - Add the specified flags\n"\
	"SUB   - Remove the specified flags\n"\
	"ALL   - Modify flags of all files matching entered pattern\n"\
	"QUIET - Removes text messages\n\n"\
	"The protection bits are represented by letters:\n\n"\
	"s - The file is a script\n"\
	"p - The file is a pure command and can be made resident\n"\
	"a - The file has been archived\n"\
	"r - The file can be read\n"\
	"w - The file can be written to (altered)\n"\
	"e - The file is executable (a program)\n"\
	"d - The file or directory can be deleted.\n"\
	"    (Files within a delete-protected directory can still be deleted.)\n\n"\
	"You have three ways to set or clear protection flags of a file:\n\n"\
	" 1. Specify the protection bits you want to set using the FLAGS\n"\
	"    argument without any other argument.\n"\
	" 2. Use ADD and/or SUB followed by the bits you want to set/clear\n"\
	" 3. Use '+' followed by the bits you want to set and '-' followed by\n"\
	"    the bits you want to clear.\n\n"\
	"Examples:\n"\
	" MorphOS:> Protect myfile +sr\n"\
	" Sets the script and read bit of file 'myfile'\n\n"\
	" MorphOS:> Protect #?.txt w SUB\n"\
	" clears the write bit of all files matching pattern '#?.txt'\n", 139 },
    { (STRPTR) "Exits a batch file with specified return code", 140 },
    { (STRPTR) "RC - Use this option to specify the return code (default = 0)\n", 141 },
    { (STRPTR) "Resets the computer", 142 },
    { (STRPTR) "This command will make an IMMEDIATE reset of the computer.\n\n"\
	"NOTE: Be sure to save your work and stop all disk activites before\n"\
	"running this command as it won't give you any warning before resetting !\n", 143 },
    { (STRPTR) "Changes the name of a disk", 144 },
    { (STRPTR) "DRIVE - Name of the drive to change name\n"\
	"NAME  - New name of the disk\n\n"\
	"Example:\n"\
	" MorphOS:> Relabel MorphOS: MorphOS_Rulez\n\n"\
	" Changes the name of the MorphOS disk to MorphOS_Rulez.\n"\
	" Please note that no colon is necessary after the second name.\n", 145 },
    { (STRPTR) "Removes recoverable RAM-Drive from the system", 146 },
    { (STRPTR) "DEVICE - Name of the recoverable device to be removed\n"\
	"FORCE  - Forces the device to be removed, even if it's in use\n\n"\
	"RemRad allows you to remove the recoverable RAM disk (usually mounted as RAD:)\n"\
	"from memory without powering off the system. If you have mounted more than\n"\
	"one recoverable RAM disk, use the DEVICE specification.\n\n"\
	"RemRad instructs RAD: to delete all of its files and become inactive.\n"\
	"However, the RAD: RAM_0 disk icon does not disappear.\n"\
	"The next time MorphOS is rebooted, RAD: is removed from memory completely\n"\
	"and the icon is no longer displayed.\n\n"\
	"If the device is in use when the REMRAD command is given,\n"\
	"the operation aborts with a device in use message.\n"\
	"To remove it if it is in use, you must use the FORCE option.\n", 147 },
    { (STRPTR) "Removes a resident module from the resident list", 148 },
    { (STRPTR) "MODULE - Name of the module to be removed\n\n"\
	"NOTE: Use Resident to display a list of all resident modules.\n", 149 },
    { (STRPTR) "Renames files and directories", 150 },
    { (STRPTR) "FROM  - Name of the files/directories to rename\n"\
	"TO    - Destination name of file/directory\n"\
	"QUIET - Be quiet\n\n"\
	"Rename renames the FROM file or directory with the specified TO name.\n"\
	"The FROM and TO files or directories must be on the same volume.\n"\
	"If the name refers to a directory, Rename changes the directory name\n"\
	"without changing the names of the files or subdirectories in that directory.\n"\
	"When there are multiple items in the FROM argument,\n"\
	"the TO argument must be a directory.\n\n"\
	"NOTE: If you rename a directory or if you use Rename to give\n"\
	"a file another directory name, MorphOS changes the position\n"\
	"of that directory or file in the filing system hierarchy.\n"\
	"This effectively moves the items.\n", 151 },
    { (STRPTR) "Asks for input via a requester", 152 },
    { (STRPTR) "TITLE     - Title string of the requester\n"\
	"BODY      - Body string of the requester\n"\
	"            Linefeeds can be embedded using *N\n"\
	"GADGETS   - Gadgets of the requester (see below)\n"\
	"            The gadget labels are separated with spaces\n"\
	"PUBSCREEN - Optional: name of the publicscreen to use\n\n"\
	"The number of the selected gadget is printed as a result to the console.\n"\
	"For evaluation in a script file, you can redirect this output\n"\
	"into an environment variable. If the requester cannot be opened,\n"\
	"the command generates a return code of 20.\n\n"\
	"The PUBSCREEN argument allows the requester to open its window on a public screen.\n\n"\
	"Example:\n"\
	" MorphOS:> RequestChoice >ENV:rcnum \"New Title\" \n"\
	"           \"This is my requester*NSelect a gadget\" \"OK\" \"Maybe\" \"Cancel\"\n\n"\
	" => ENV:rcnum contains 0, 1, or 2 after a gadget is selected.\n"\
	"    The script can use this value to control its later execution.\n", 153 },
    { (STRPTR) "Asks for a filename via a file requester", 154 },
    { (STRPTR) "DRAWER         - Initial contents of the Drawer gadget\n"\
	"FILE           - Initial contents of the File gadget\n"\
	"PATTERN        - Initial contents of the Pattern gadget\n"\
	"TITLE          - Title string of the requester\n"\
	"POSITIVE       - Specifies the text to appear in the positive (left)\n"\
	"                 choice of the requester\n"\
	"NEGATIVE       - Specifies the text to appear in the negative (right)\n"\
	"                 choice of the requester\n"\
	"ACCEPTPATTERN  - This option specifies a standard MorphOS pattern.\n"\
	"                 Only files matching this pattern are displayed\n"\
	"                 in the file requester.\n"\
	"REJECTPATTERN  - This option specifies a standard MorphOS pattern.\n"\
	"                 Files matching this pattern are not displayed\n"\
	"                 in the file requester.\n"\
	"SAVEMODE       - Specify this option to use the requester to write files\n"\
	"                 to disk\n"\
	"MULTISELECT    - Allows multi-selection of files\n"\
	"DRAWERSONLY    - Only accept drawers (file requester does not have\n"\
	"                 a file gadget)\n"\
	"NOICONS        - Don't display icons in the file list\n"\
	"PUBSCREEN      - Open the requester on the specified PubScreen\n"\
	"INITIALVOLUMES - Initial volume (default=current dir)\n\n"\
	"The selected files are returned on the command line,\n"\
	"enclosed in double quotation marks and separated with spaces.\n"\
	"The command generates a return code of 0 if you select\n"\
	"a file or 5 if you cancel the requester.\n\n"\
	"NOTE: When entered with no arguments, a file requester\n"\
	"      with OK, Volumes, Parent, and Cancel buttons is created.\n"\
	"      First Drawer and File gadgets are empty and it displays\n"\
	"      the contents of the current directory.\n", 155 },
    { (STRPTR) "Adds or Removes a command in memory", 156 },
    { (STRPTR) "NAME    - Name of the resident to be added into the resident list\n"\
	"FILE    - Full path to the executable to add\n"\
	"ALIAS   - Add an Alias of an existing resident cmd instead of a new one\n"\
	"REMOVE  - Deactivates the specified internal command\n"\
	"REPLACE - Default option\n"\
	"ADD     - Use this option to override REPLACEment and make\n"\
	"          several versions of a command resident simultaneously,\n"\
	"          use the ADD option, giving a different NAME for each version loaded.\n"\
	"PURE    - Forces Resident to load commands that are not marked as pure\n"\
	"          and use them to test the pureness of other commands and programs.\n"\
	"          Use the PURE option with caution. Be sure the programs that you\n"\
	"          make Resident meet the criteria to be resident or be careful\n"\
	"          to use the command in only one process at a time.\n"\
	"SYSTEM  - Add the specified command in the System portion of the list\n"\
	"          The command then becomes available as a system component and\n"\
	"          cannot be removed from the list\n"\
	"DEFER   - Command is loaded to RAM when it's used for the first time\n\n"\
	"Resident with no FILE argument will display the resident list.\n"\
	"You can specify the SYSTEM argument to show only System components.\n\n"\
	"NOTE: To be made resident, a command should be pure, meaning that\n"\
	"      it is both re-entrant and re-executable.\n"\
	"      A re-entrant command can properly support independent use by\n"\
	"      two or more programs at the same time.\n"\
	"      A re-executable command does not have to be reloaded to be executed again.\n"\
	"      Commands that have these characteristics are called 'pure' and\n"\
	"      have the p (pure) protection bit set.\n", 157 },
    { (STRPTR) "Displays a list of all resources in memory", 158 },
    { (STRPTR) "See also: FsList, LibList, TaskList and DevList commands.\n", 159 },
    { (STRPTR) "Starts the ARexx Server", 160 },
    { (STRPTR) "This is used to start the ARexx Server.\n"\
	"You can't use any ARexx capabilities before it has been launched.\n\n"\
	"See also: RX command.\n", 161 },
    { (STRPTR) "Spawns a background shell or process", 162 },
    { (STRPTR) "DETACH  - Runs the command on a fake CLI\n"\
	"QUIET   - Removes text messages\n"\
	"STACK   - Specify the stacksize (in bytes) of the command to run\n"\
	"PRI     - Specify the priority of the command to run\n"\
	"COMMAND - Command to run (must be the LAST argument)\n\n"\
	"Run attempts to run the command COMMAND including specified arguments\n"\
	"in the background. You can run multiple commands by separating them with\n"\
	"a '+'. If you press [Return] after a plus sign, Run interprets the\n"\
	"next line as a continuation of the same command line.\n\n"\
	"NOTE: to be able to close the CLI window after having detached a command,\n"\
	"      you have to redirect the command's output to NIL:\n\n"\
	"Example:\n"\
	"  MorphOS:> run >NIL: SYS:Utilities/Taskmanager\n", 163 },
    { (STRPTR) "Interprets the specified ARexx script", 164 },
    { (STRPTR) "This command is used to execute ARexx Scripts.\n"\
	"You may either pass the full path to a script file or\n"\
	"directly specify some Rexx commands enclosed in \"\".\n\n"\
	"Examples:\n\n"\
	"  MorphOS:> rx \"ADDRESS AMBIENT SCANDIR 'ram:' 'MODE=ICON'\"\n"\
	"  => An Ambient window will be opened, showing the contents of\n"\
	"  the RAM: directory.\n\n"\
	"  MorphOS:> rx s:my_script.txt\n"\
	"  => This would execute the my_script Rexx script found in s:\n\n"\
	"NOTE: The ARexx server must be running in order to use RX.\n\n"\
	"See also: RexxMast command.\n", 165 },
    { (STRPTR) "Closes the resident process", 166 },
    { (STRPTR) "The \"REXX\" public port is withdrawn immediately, and the\n"\
	"resident process exits as soon as the last ARexx program finishes.\n"\
	"No new programs can be launched after a close request.\n", 167 },
    { (STRPTR) "Preadds an arexx library/host to the global list for scripts", 168 },
    { (STRPTR) "NAME     - Not Documented\n"\
	"PRIORITY - Not Documented\n"\
	"OFFSET   - Not Documented\n"\
	"VERSION  - Not Documented\n\n"\
	"If no name is specified this command will list all arexx libs.\n\n"\
	"See also: RX* commands.\n", 169 },
    { (STRPTR) "Adds a (name,value) pair to the Clip List", 170 },
    { (STRPTR) "NAME  - name of the pair\n"\
	"VALUE - value of the pair\n\n"\
	"Name strings are assumed to be in mixed case.\n"\
	"If a pair with the same name already exists, its value is replaced\n"\
	"with the current string. If a name without a value string is given,\n"\
	"the entry is removed from the Clip List.\n"\
	"If RXSET is invoked without arguments, it will list all (name, value) pairs\n"\
	"in the Clip List.\n", 171 },
    { (STRPTR) "Searches a file or pattern for a string", 172 },
    { (STRPTR) "FROM    - Directory where to search\n"\
	"SEARCH  - Search string\n"\
	"ALL     - if FROM is a Dir, will process subdirectories as well\n"\
	"NONUM   - Do not print the line numbers with the string\n"\
	"QUIET   - Searches quietly; file names being searched are not displayed\n"\
	"QUICK   - Use a more compact output format\n"\
	"FILE    - Looks for a file by the specified name,\n"\
	"          rather than for a string in the file\n"\
	"PATTERN - Only files matching this pattern will be processed\n"\
	"CASE    - Search is case-sensitive (default=NO)\n\n"\
	"NOTE: Search leaves a 0 in the condition flag if the object is found,\n"\
	"      and a 5 (WARN) otherwise.\n"\
	"      To abandon the search of the current file and continue\n"\
	"      to the next file, if any, press Ctrl+D.\n"\
	"      Search is aborted when Ctrl+C is pressed.\n\n"\
	"Examples:\n"\
	"  MorphOS:> search c:help $VER\n"\
	"  1083 VER: Help [MOS] 0.6 (19.12.2004)� 2004 by Nicolas Ramz\n\n"\
	"  MorphOS> search utilities #?.info file\n"\
	"  MorphOS:Utilities/Calculator.info\n"\
	"  MorphOS:Utilities/Snoopium.info\n"\
	"  MorphOS:Utilities/TaskManager.info\n", 173 },
    { (STRPTR) "Tracking utility for disk loaded files (inc. libs and devs)", 174 },
    { (STRPTR) "SHOW    - Shows all of the segments being tracked\n"\
	"DUMP    - All of the segment elements being tracked\n"\
	"VERBOSE - Display more information\n"\
	"MAPFILE - Use this option to specify a boot.map\n"\
	"NAME    - Find segments by name (instead of address, like FIND)\n"\
	"FIND    - Find the hex (in $xxxxx format) address in the\n"\
	"          tracked segments. Multiple addresses can be given\n\n"\
	"If placed in the startup-sequence right after SetPatch, it will track\n"\
	"all disk loaded segments (other than those loaded by SetPatch).\n", 175 },
    { (STRPTR) "Creates or modifies specified local environment variable", 176 },
    { (STRPTR) "NAME   - Name of the environment variable\n"\
	"STRING - value to attach to the variable\n\n"\
	"Set with NAME and STRING arguments creates a new environment variable.\n"\
	"The first word after Set is taken as the NAME.\n"\
	"Everything else on the command line is taken as the STRING argument.\n"\
	"Quotation marks are not required.\n\n"\
	"An environment variable created with Set is local to the Shell\n"\
	"in which it was created. If you create a new Shell with the NEWSHELL command,\n"\
	"that Shell also recognizes any variables created in its parent Shell.\n"\
	"However, if you create a new Shell with the Execute Command\n"\
	"Ambient menu item or by opening the Shell icon, variables created\n"\
	"with SET are not recognized in the new Shells.\n\n"\
	"NOTE: Set with no arguments lists the current local variables.\n", 177 },
    { (STRPTR) "Changes system and/or internal clock time", 178 },
    { (STRPTR) "LOAD  - sets the current system time form the battery backed-up clock\n"\
	"        (automatically done by the boot process)\n"\
	"SAVE  - sets the date and time of the battery backed-up hardware clock\n"\
	"        from the current system time\n"\
	"RESET - resets the clock completely\n\n"\
	"Example:\n\n"\
	"  MorphOS:> date\n"\
	"  Thursday 20-Jan-05 15:09:10\n"\
	"  MorphOS:> setclock save\n\n"\
	"=> Saves the date, January 20, 2005, and the time, 15:09,\n"\
	"   to the battery backed-up hardware clock. When the system is booted,\n"\
	"   the system clock is set with the time saved in the hardware clock.\n\n"\
	"NOTE: Use the Date command or the Time preferences panel to\n"\
	"      change the system time and date.\n", 179 },
    { (STRPTR) "Sends commands to CON", 180 },
    { (STRPTR) "COMMAND - Command to send\n\n"\
	"Example:\n\n"\
	"  MorphOS:> SetCON MAPKEY \"F2\" \"BOL\"\n"\
	"  => Map the [F2] key to the Begin of Line function\n\n"\
	"NOTE: SetCON works with standard CON: and may not be supported\n"\
	"      by other CON: replacements such as MUICON.\n", 181 },
    { (STRPTR) "Changes the last modification date of a file", 182 },
    { (STRPTR) "FILE    - File or directory name/pattern to modify\n"\
	"WEEKDAY - New weekday to set\n"\
	"DATE    - New date to set\n"\
	"TIME    - New time to set\n"\
	"ALL     - If specified, changes the date of all files and subdirectories\n"\
	"          matching the entered pattern\n\n"\
	"Example:\n"\
	"  MorphOS:> SetDate my_file.txt Thursday 20-Jan-05 15:09:10\n\n"\
	"NOTE: You can use output from the Date command as input to SetDate.\n", 183 },
    { (STRPTR) "Creates or modifies specified global environment variable", 184 },
    { (STRPTR) "NAME   - Name of the variable to create or modify\n"\
	"SAVE   - Variable will be available after a reboot\n"\
	"STRING - String to attach to the variable\n\n"\
	"Environment variables are called by scripts or other commands\n"\
	"by including a dollar sign ($) in front of the variable name.\n"\
	"To remove a global variable definition, use the UnSetEnv command.\n\n"\
	"Example:\n\n"\
	"  MorphOS:> SetEnv MOS \"MorphOS RULEZ !\"\n"\
	"  MorphOS:> Echo \"$MOS\"\n"\
	"  MorphOS Rulez !\n\n"\
	"NOTE: Use SetEnv without arguments to display a list of current\n"\
	"      global variables.\n"\
	"NOTE2: If a global and a local variable share the same name,\n"\
	"       the local variable is used.\n", 185 },
    { (STRPTR) "Sets keyboard layout", 186 },
    { (STRPTR) "KEYMAP - Name of the keymap to use\n\n"\
	"Example:\n"\
	"  MorphOS:> SetKeyBoard pc105_gb\n"\
	"  => Sets the keyboard layout to match a GB 105 keys\n\n"\
	"NOTE: Keymaps are located in MOSSYS:Devs/Keymaps\n", 187 },
    { (STRPTR) "Skips to the appropriate label", 188 },
    { (STRPTR) "LABEL - Name of the Label\n"\
	"BACK  - Searches from the beginning of the file instead of\n"\
	"        the current line.\n\n"\
	"Skip is used in scripts to allow you to skip ahead in the script\n"\
	"to a LABEL defined by a Lab statement.\n"\
	"If no LABEL is specified, Skip jumps to the next Lab statement.\n\n"\
	"Skip always searches forward from the current line of the file.\n"\
	"However, when the BACK option is used, Skip starts searching\n"\
	"for the label from the beginning of the file.\n"\
	"This allows Skips to points prior to the Skip command.\n\n"\
	"Example: Assume you have a script called check_file containing:\n\n"\
	".KEY name\n"\
	"IF exists <name>\n"\
	"SKIP message\n"\
	"ELSE\n"\
	"ECHO \"<name> is not in this directory.\"\n"\
	"QUIT\n"\
	"ENDIF\n"\
	"LAB message\n"\
	"ECHO \"The <name> file exists.\"\n\n"\
	"- If the specified file exists, the message \"The <name> file exists.\" is\n"\
	"  displayed\n"\
	"- If the file does not exists, the Skip command is not executed and\n"\
	"  the message \"<name> is not in this directory.\" is displayed.\n\n"\
	"See also: Execute and Lab commands.\n", 189 },
    { (STRPTR) "Sorts a file", 190 },
    { (STRPTR) "FROM     - File to sort\n"\
	"TO       - File where to send sorted results\n"\
	"COLSTART - Specifies the character column at which the comparison begins\n"\
	"           Sort starts comparing the lines from that point, wrapping around\n"\
	"           to the beginning of the line if the compared lines match to the end\n"\
	"CASE     - Specify this to output uppercase items first\n"\
	"NUMERIC  - The lines are interpreted as numbers from the first column\n"\
	"           reading to the right, stopping at the first non-numeric character\n"\
	"           Lines not beginning with numbers are treated as 0\n"\
	"           The lines are output in numerical order\n"\
	"           CASE is ignored when NUMERIC is specified\n\n"\
	"Example:\n\n"\
	"  MorphOS:> Sort DH0:Glossary TO RAM:Glossary.alpha\n\n"\
	"  => sorts the lines in the Glossary file, arranges them alphabetically,\n"\
	"  and outputs them to a next file called Glossary.alpha.\n"\
	"  The case of the words is disregarded.\n", 191 },
    { (STRPTR) "Sets or displays the current stack size", 192 },
    { (STRPTR) "SIZE - Size of the new stack (in bytes)\n\n"\
	"Use Stack with no argument to display current stack size.\n\n"\
	"NOTE: Each Shell has a specific stack size.\n", 193 },
    { (STRPTR) "Displays some system stats since boot", 194 },
    { (STRPTR) "This command displays general statistics such as load average,\n"\
	"number of context switches, ...\n\n"\
	"See also: UpTime and Avail commands.\n", 195 },
    { (STRPTR) "Displays a list of currently running CLI processes", 196 },
    { (STRPTR) "PROCESS - Number of the process to spy\n"\
	"FULL    - Gives full details about each process\n"\
	"TCB     - Gives full details but omit the current command\n"\
	"          for each process\n"\
	"CLI     - See TCB\n"\
	"COM     - Searches for the Command COM (see Below)\n\n"\
	"Status without any arguments lists the numbers of\n"\
	"the current Shell processes and the program or command running in each.\n"\
	"The PROCESS argument specifies a process number, limiting Status to giving\n"\
	"information about that process only.\n\n"\
	"When the COM switch is used, Status scans the Shell list,\n"\
	"looking for the specified command. If the command is found,\n"\
	"the Shell's process number is output, and the condition flag is set to 0.\n"\
	"Otherwise, the flag is set to 5 (WARN).\n\n"\
	"Example:\n"\
	"  MorphOS:> Status >RAM:Xyz COM=COPY\n"\
	"  MorphOS:> Break <RAM:Xyz >NIL: ?\n\n"\
	"  => sends a break to the process executing Copy.\n", 197 },
    { (STRPTR) "Displays a detailed list of all running tasks", 198 },
    { (STRPTR) "VERBOSE - Be verbose for each task\n\n"\
	"When using the VERBOSE switch, a lot of details, including\n"\
	"the 68k and PPC stack pointers, Wait signals,... are reported.\n\n"\
	"See also: Status and Break commands.\n", 199 },
    { (STRPTR) "Closes the global tracing console", 200 },
    { (STRPTR) "Closes the global tracing console as soon as all active programs\n"\
	"are no longer using it.\n"\
	"All read requests queued to the console must be satisfied before it can be closed.\n\n"\
	"See also: TCO command.\n", 201 },
    { (STRPTR) "Opens the global tracing console", 202 },
    { (STRPTR) "The tracing output from all active programs is diverted automatically to\n"\
	"the new console.\n"\
	"The console window can be moved and resized by the user and can be closed\n"\
	"with the TCC command.\n\n"\
	"See also: TCC command.\n", 203 },
    { (STRPTR) "Clears the global tracing flag", 204 },
    { (STRPTR) "Clearing the global tracing flag forces the tracing mode to OFF\n"\
	"for all active ARexx programs.\n\n"\
	"See also: TS command.\n", 205 },
    { (STRPTR) "Creates a file", 206 },
    { (STRPTR) "NAME - Path/name of the file to create\n"\
	"ALL  - Recursive touch (goes into subdirs)\n\n"\
	"Touch is used to create empty files. You can specify one or\n"\
	"more files to be created.\n\n"\
	"NOTE: if a file already exists, it won't be modified beside the timestamp.\n", 207 },
    { (STRPTR) "Activates JIT 68k emulation", 208 },
    { (STRPTR) "This command will activate the JIT (Just In Time) Dynamic emulation.\n"\
	"This will cause a huge increase in the speed of about all 68k emulated\n"\
	"programs.\n\n"\
	"NOTE: You normally don't need to execute this command as it should be\n"\
	"      started automatically at startup.\n\n"\
	"NOTE2: Breaking Trance by sending it a CTRL+C is possible but is *not safe*.\n"\
	"       Doing it will cause the 68k emulation to fallback to standard interpreted\n"\
	"       68k emulation.\n", 209 },
    { (STRPTR) "Starts interactive tracing by setting the external trace flag", 210 },
    { (STRPTR) "Starts interactive tracing by setting the external trace flag,\n"\
	"which forces all active ARexx programs into interactive tracing mode.\n"\
	"Programs will start producing trace output and will pause after\n"\
	"the next statement. This command is useful for regaining control\n"\
	"over programs Caught in infinite loops or otherwise misbehaving.\n"\
	"The trace flag remains set until cleared by the TE command,\n"\
	"so subsequent program invocations will be executed\n"\
	"in interactive tracing mode.\n\n"\
	"See also: TE command.\n", 211 },
    { (STRPTR) "Displays the contents of a file to the screen", 212 },
    { (STRPTR) "FROM   - Name/Path of the file to display\n"\
	"TO     - Optional: Destination file where to put results\n"\
	"OPT    - Depreciated: use HEX/NUMBER instead\n"\
	"HEX    - Display content as hexa-decimal instead of plain ASCII\n"\
	"NUMBER - Append the line numbers (can't be used with HEX option)\n\n"\
	"Example:\n"\
	"  MorphOS:> Type c:file.txt HEX\n"\
	"  0000: 4D6F7270 684F5320 52554C45 5A20210A MorphOS RULEZ !.\n", 213 },
    { (STRPTR) "Removes the named alias from the alias list", 214 },
    { (STRPTR) "NAME - Name of the Alias to remove from the list\n\n"\
	"NOTE: With no arguments, UNALIAS lists the current aliases.\n\n"\
	"See also: Alias command.\n", 215 },
    { (STRPTR) "Removes a local variable", 216 },
    { (STRPTR) "NAME - Name of the local variable to remove\n\n"\
	"UnSet removes the named local variable from the variable list\n"\
	"for the current process.\n\n"\
	"NOTE: With no arguments, UNSET lists the current variables.\n\n"\
	"See also: Set, UnSetEnv and SetEnv commands.\n", 217 },
    { (STRPTR) "Removes a global variable", 218 },
    { (STRPTR) "NAME - Name of the variable to remove\n"\
	"SAVE - Permanently remove the variable (see Below)\n\n"\
	"UnSetEnv removes the named global variable from the current variable list.\n"\
	"Please note that if the variable has been Set using the SAVE switch, it\n"\
	"will be available again after a Reboot. To remove it totally,\n"\
	"use the SAVE switch.\n\n"\
	"NOTE: With no arguments, UNSETENV lists the current variables.\n\n"\
	"See also: SetEnv, Set and UnSet.\n", 219 },
    { (STRPTR) "Manages MP3 players that use a common Samsung MP3 chipset", 220 },
    { (STRPTR) "DEVINFO  - Returns the device ID. For Valenica MP3 Player, it's:\n"\
	"           \"Device ID String: '2.1.0.10   20000329CPAD00       '\"\n"\
	"FILELIST - Lists the files found in the internal memory (or external\n"\
	"           when using the EXT switch)\n"\
	"UPLOAD   - Uploads the given file to the MP3 player (either into\n"\
	"           internal memory or external memory, if EXT is given).\n"\
	"           If the file name is longer than 8+3 characters, it will\n"\
	"           be mutilated to fit. When specifying the AS keyword,\n"\
	"           that name will be used instead\n"\
	"DOWNLOAD - Downloads the given file from the MP3 player. The file can\n"\
	"           either be specified by its track number as shown in the\n"\
	"           filelist or by its exact name (case sensitive).\n"\
	"           The downloaded file will be stored under its name in the\n"\
	"           current directory or stored at the location and name\n"\
	"           specified by the AS keyword. To download a file from\n"\
	"           external memory, use the EXT switch\n"\
	"DELETE   - Deletes a file from the MP3 player. As with download,\n"\
	"           the file can be given either as the track number or its exact\n"\
	"           name. To delete a file from external memory, use the EXT switch.\n"\
	"FORMAT   - If given, erases the whole internal or external memory,\n"\
	"           depending on the use of the EXT switch\n"\
	"EXT      - Specifies whether the command should operate on the\n"\
	"           internal memory or on the memory card supplied by the\n"\
	"           MMC/SD slot\n"\
	"AS       - alternate filename to use for downloading or uploading\n\n"\
	"Known bugs:\n"\
	"  - There isn't much error handling.\n"\
	"  - Gets easily out of sync.\n"\
	"  - Doesn't generate a valid date when uploading files.\n"\
	"  - Several fields of the protocol data are unknown.\n", 221 },
    { (STRPTR) "Shows Uptime of MorphOS", 222 },
    { (STRPTR) "Display the time since MorphOS was (re)booted.\n\n"\
	"See also: Stat command.\n", 223 },
    { (STRPTR) "Lists all found USB devices", 224 },
    { (STRPTR) "This command gives lot of information about connected USB devices.\n\n"\
	"See also: USBErrorLog command.\n", 225 },
    { (STRPTR) "Shows all USB-Related messages since the start of the stack", 226 },
    { (STRPTR) "This command displays the complete log of the USB stack since\n"\
	"it was started.\n\n"\
	"NOTE: You may select the level of debug in the USB preferences panel.\n\n"\
	"See also: USBDevLister and USB Preferences panel.\n", 227 },
    { (STRPTR) "Reports the version number of the specified file", 228 },
    { (STRPTR) "NAME     - Name of the lib|device|command to return version info\n"\
	"VERSION  - Optional: Version number to look for\n"\
	"REVISION - Optional: Revision number to look for\n"\
	"FILE     - Forces Version to ignore libraries or device drivers\n"\
	"           currently loaded. This allows you to get the version number\n"\
	"           of a .library or .device file on disk when a library or device\n"\
	"           of that name is already in memory or available in LIBS:\n"\
	"FULL     - prints out the complete version string, including the date\n"\
	"UNIT     - Obsolete\n"\
	"INTERNAL - Obsolete\n"\
	"RES      - Specify this to get the version of Resident commands\n\n"\
	"Version finds the version and revision number of a library, device, command.\n"\
	"It can also test for a specific version/revision and set the condition flags\n"\
	"if the version/revision is greater.\n\n"\
	"Version with no NAME argument prints the Kickstart version number and\n"\
	"the Workbench version number and sets the two corresponding\n"\
	"environment variables. If a name is specified, Version attempts\n"\
	"to open the library, device, drive, or file and read the version information.\n"\
	"Specify a device name, such as DH0:, to get the version\n"\
	"of the file system used by a drive.\n\n"\
	"Example:\n"\
	"  MorphOS:> version morphos FULL\n"\
	"  MorphOS 1.4 (25/04/2003)\n"\
	"  � 1999-2003 by Ralph Schmidt, Frank Mariak, Emmanuel Lesueur,\n"\
	"  Teemu Suikki, Harry Sintonen\n", 229 },
    { (STRPTR) "Waits for an amount of time", 230 },
    { (STRPTR) "TIME  - Amount of time to wait (in seconds)\n"\
	"SECS  - Switch: amount of time is given in seconds\n"\
	"MINS  - Switch: amount of time is given in minutes\n"\
	"UNTIL - Use this option to wait until a particular time of the day\n"\
	"        given in the format HH:MM\n\n"\
	"Example:\n"\
	"  MorphOS:> Wait 10 MINS\n", 231 },
    { (STRPTR) "Waits 10 secs for port to appear", 232 },
    { (STRPTR) "PORTNAME  - Name of the port to wait for\n"\
	"INTERVAL  - Only checks for the port every INTERVAL seconds\n"\
	"LOOP      - Number of time to loop (Default=1)\n"\
	"DISAPPEAR - Check for the port to disappear instead of appear\n\n"\
	"WaitForPort waits 10 seconds for the specified port to appear.\n"\
	"A return code of 0 indicates that the port was found.\n"\
	"A return code of 5 indicates that the application is not\n"\
	"currently running or that the port does not exist.\n\n"\
	"Example:\n"\
	"  MorphOS:> WaitForPort INTERVAL=1 LOOP=5 MIAMI.1\n"\
	"  => Waits 1 second and check for the presence of the 'MIAMI.1' port\n"\
	"     Do that 5 times.\n\n"\
	"NOTE: Port names are case sensitive.\n", 233 },
    { (STRPTR) "Starts the specified command as if it was started from Ambient", 234 },
    { (STRPTR) "PROG  - Name (inc. pathname) of the program to start\n"\
	"ARGS  - Argument(s) to send to the program\n"\
	"STACK - StackSize to use (default: see Ambient prefs)\n"\
	"PRI   - Specifies a priority (default = 0)\n"\
	"DELAY - Waits an amount of time before starting the program\n\n"\
	"Using this command it is possible to fake an Ambient startup.\n"\
	"The specified command will run as if it was started from the Desktop.\n\n"\
	"NOTE: Ambient and the current CLI do not share the same PATH\n"\
	"      nor default stacksize.\n\n"\
	"See also: Run command.\n", 235 },
    { (STRPTR) "Searches the command path for a particular item", 236 },
    { (STRPTR) "FILE  - Name of the command, program or directory to find\n"\
	"NORES - Switch: Do no search the resident list\n"\
	"RES   - Switch: Only search the resident list\n"\
	"ALL   - Continues the search through the full search path, find and list\n"\
	"        all locations of a command or program.\n"\
	"        May lead to multiple listings of the same command if\n"\
	"        that command is reached by more than one route\n"\
	"        (such as C: and the current directory).\n\n"\
	"Example:\n"\
	"  MorphOS:> Which devlist\n"\
	"  MorphOS:morphos/c/DevList\n", 237 },
    { (STRPTR) "Displays return code of last executed command", 238 },
    { (STRPTR) "When a command fails, the screen displays a brief message.\n"\
	"This message typically includes the name of the file,\n"\
	"if that was the problem, but provides no details. If the reason\n"\
	"for a failure is not evident, enter WHY for a more complete explanation.\n", 239 },
    { (STRPTR) "Help Usage:", 240 },
    { (STRPTR) "Displays a small description of all available commands", 241 },
    { (STRPTR) "Displays a more complete description of the 'CMD' command", 242 },
    { (STRPTR) "Displays MorphOS shell arguments HowTo", 243 },
    { (STRPTR) "Shows a complete description of all commands related to DOM", 244 },
    { (STRPTR) "can be", 245 },
    { (STRPTR) "will show a full description of the DIR command", 246 },
    { (STRPTR) "will list all commands related to Sound", 247 },
    { (STRPTR) "Language: built-in English.", 248 },
    { (STRPTR) "Error in command line: value after keyword missing.", 249 },
    { (STRPTR) "Error in command line: too many arguments.", 250 },
    { (STRPTR) "Examples:", 251 },
    { (STRPTR) "Help - Small reminder on MorphOS Shell arguments", 252 },
    { (STRPTR) "MorphOS Shell commands follows a syntax defined by a template.\n"\
	"To display the template type a '?' after the command name.\n\n"\
	"For example: SYS:> AddDataTypes ?\n"\
	"             FILES/M,QUIET/S,REFRESH/S: \n\n"\
	"Pressing [?] will display a description of all parameters, if available.\n"\
	"Pressing [return] will then execute the command if no arguments are required.\n"\
	"You may also enter the some arguments with their keyword and press [return]\n\n"\
	"The arguments are separated with a comma, followed by a '/'\n"\
	"and a capital letter which represents the type of the argument:\n\n"\
	"/A: The argument is always required.\n"\
	"/K: The option's keyword is required if the argument is given.\n"\
	"/S: The option works as a switch.\n"\
	"    The name of the option must be entered to specify it.\n"\
	"    Most options are switches.\n"\
	"/N: The argument is numeric.\n"\
	"/M: Multiple items are accepted for this argument.\n"\
	"    Although there is no limit to the number of possible arguments,\n"\
	"    they must be provided before the next argument or option.\n"\
	"/F: The string must be the final argument on the command line;\n"\
	"    the remainder of the command line is taken as the desired string.\n", 253 },
    { (STRPTR) "No Template", 254 },
    { (STRPTR) "No command or domain having the name", 255 },
    { (STRPTR) "No domain having the name", 256 },
    { (STRPTR) "Commands found in the domain", 257 },
    { (STRPTR) "Total", 258 },
    { (STRPTR) "commands", 259 },
    { (STRPTR) "domains.", 260 }
};

STATIC struct Catalog *HelpCatalog = NULL;
#ifdef LOCALIZE_V20
STATIC STRPTR HelpStrings = NULL;
STATIC ULONG HelpStringsSize;
#endif


#if defined(_DCC)
STATIC __autoexit VOID _STDCloseHelpCatalog(VOID)
#elif defined(__SASC)
VOID _STDCloseHelpCatalog(VOID)
#elif defined(__GNUC__)
VOID _STDCloseHelpCatalog(VOID)
#else
VOID CloseHelpCatalog(VOID)
#endif

{
    if (HelpCatalog) {
	CloseCatalog(HelpCatalog);
    }
#ifdef LOCALIZE_V20
    if (HelpStrings) {
	FreeMem(HelpStrings, HelpStringsSize);
    }
#endif
}


#if defined(_DCC)
STATIC __autoinit VOID _STIOpenHelpCatalog(VOID)
#elif defined(__SASC)
VOID _STIOpenHelpCatalog(VOID)
#elif defined(__GNUC__)
VOID _STIOpenHelpCatalog(VOID)
#else
VOID OpenHelpCatalog(VOID)
#endif

{
    if (LocaleBase) {
	if ((HelpCatalog = OpenCatalog(NULL, (STRPTR) "Help.catalog",
				     OC_BuiltInLanguage, "english",
				     OC_Version, 0,
				     TAG_DONE))) {
	    struct FC_String *fc;
	    int i;

	    for (i = 0, fc = Help_Strings;  i < 261;  i++, fc++) {
		 fc->msg = GetCatalogStr(HelpCatalog, fc->id, (STRPTR) fc->msg);
	    }
	}
    }
}

/*#if defined(__GNUC__)
__asm ("  .text;  .stabs \"___CTOR_LIST__\",22,0,0,__STIOpenHelpCatalog");
__asm ("  .text;  .stabs \"___DTOR_LIST__\",22,0,0,__STDCloseHelpCatalog");
#endif*/



#ifdef LOCALIZE_V20
VOID InitHelpCatalog(STRPTR language)

{
    struct IFFHandle *iffHandle;

    /*
    **  Use iffparse.library only, if we need to.
    */
    if (LocaleBase  ||  !IFFParseBase  ||  !language  ||
	Stricmp(language, "english") == 0) {
	return;
    }

    if ((iffHandle = AllocIFF())) {
	char path[128]; /* Enough to hold 4 path items (dos.library 3.1)    */
	strcpy(path, "PROGDIR:Catalogs");
	AddPart((STRPTR) path, language, sizeof(path));
	AddPart((STRPTR) path, "Help.catalog", sizeof(path));
	if (!(iffHandle->iff_Stream = Open((STRPTR) path, MODE_OLDFILE))) {
	    strcpy(path, "LOCALE:Catalogs");
	    AddPart((STRPTR) path, language, sizeof(path));
	    AddPart((STRPTR) path, language, sizeof(path));
	    iffHandle->iff_Stream = Open((STRPTR) path, MODE_OLDFILE);
	}

	if (iffHandle->iff_Stream) {
	    InitIFFasDOS(iffHandle);
	    if (!OpenIFF(iffHandle, IFFF_READ)) {
		if (!PropChunk(iffHandle, MAKE_ID('C','T','L','G'),
			       MAKE_ID('S','T','R','S'))) {
		    struct StoredProperty *sp;
		    int error;

		    for (;;) {
			if ((error = ParseIFF(iffHandle, IFFPARSE_STEP))
				   ==  IFFERR_EOC) {
			    continue;
			}
			if (error) {
			    break;
			}

			if ((sp = FindProp(iffHandle, MAKE_ID('C','T','L','G'),
					   MAKE_ID('S','T','R','S')))) {
			    /*
			    **  Check catalog and calculate the needed
			    **  number of bytes.
			    **  A catalog string consists of
			    **      ID (LONG)
			    **      Size (LONG)
			    **      Bytes (long word padded)
			    */
			    LONG bytesRemaining;
			    LONG *ptr;

			    HelpStringsSize = 0;
			    bytesRemaining = sp->sp_Size;
			    ptr = (LONG *) sp->sp_Data;

			    while (bytesRemaining > 0) {
				LONG skipSize, stringSize;

				ptr++;                  /*  Skip ID     */
				stringSize = *ptr++;
				skipSize = ((stringSize+3) >> 2);

				HelpStringsSize += stringSize+1;  /*  NUL */
				bytesRemaining -= 8 + (skipSize << 2);
				ptr += skipSize;
			    }

			    if (!bytesRemaining  &&
				(HelpStrings = AllocMem(HelpStringsSize, MEMF_ANY))) {
				STRPTR sptr;

				bytesRemaining = sp->sp_Size;
				ptr = (LONG *) sp->sp_Data;
				sptr = HelpStrings;

				while (bytesRemaining) {
				    LONG skipSize, stringSize, id;
				    struct FC_String *fc;
				    int i;

				    id = *ptr++;
				    stringSize = *ptr++;
				    skipSize = ((stringSize+3) >> 2);

				    CopyMem(ptr, sptr, stringSize);
				    bytesRemaining -= 8 + (skipSize << 2);
				    ptr += skipSize;

				    for (i = 0, fc = Help_Strings;  i < 261;  i++, fc++) {
					if (fc->id == id) {
					    fc->msg = sptr;
					}
				    }

				    sptr += stringSize;
				    *sptr++ = '\0';
				}
			    }
			    break;
			}
		    }
		}
		CloseIFF(iffHandle);
	    }
	    Close(iffHandle->iff_Stream);
	}
	FreeIFF(iffHandle);
    }
}
#endif
