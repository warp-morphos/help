/* $VER: HELP [MOS] version 0.93
         Help command for MorphOS Shell

   History:

   02.10.2004: - Ajout de nouvelles commandes

   13.11.2004: - Ajout du support locale.library

   20.11.2004: - Parametres parses avec ReadArgs()
               - Usage plus complet
               - Arguments prets
               - Catalogue plus complet
               - Ajout de la version

   10.12.2004  - Fonction de recherche
               - Premieres fonctions completes

   11.12.2004  - Gestion du Domaine
               - Fonction de recherche du domaine

   18.12.2004  - Verifie la taille du nom du domaine
               - Ajout de la desc FULL pour toutes les commandes
               - Affichage complet plus clair

   19.12.2004  - Aide sur les Arguments
               - Correction de qq chaines

   16.01.2005  - Correction de qq chaines

   23.01.2005  - Traduction des chaines FR restantes
               - Description des derniers commandes restantes
                 ajoutee.

   25.01.2005: - Ajout des commandes REXX manquantes
               - Correction d'erreurs/orthographe UK
               - Commande Alias completee ([] = args)

   11.02.2005: - Ajout de la commande MemTest
               - Correction d'erreurs/orthographe UK

   12.02.2005: - Plus besoin de constante pour le nb de cmds

*/

// Standard includes
#include <stdio.h>
#include <string.h>
#include <ctype.h> // tolower()
// MorphOS includes
#include <workbench/startup.h>
#include <dos/rdargs.h>
// Help includes
#include "help_cat.h"

/*
    /A is a required argument
    /S is a switch (specify if you want this option on)
    /K is a keyword (the name of the option is required before any parameters)
    /M means you can specify more than one value

There are combinations of the above, so /A/K means it is a required argument that you have to specify the keyword for. Check out the format template for an example..*/


// Constants
const char RESET[]={0x1B, 0x5B, '0', 'm'};
const char COLOR[]={0x1B, 0x5B, '3', '0', 'm'};
const char COLOR1[]={0x1B, 0x5B, '3', '1', 'm'};
const char COLOR2[]={0x1B, 0x5B, '3', '2', 'm'};
const char COLOR3[]={0x1B, 0x5B, '3', '3', 'm'};

static STRPTR usageTemplate = "ALL/S,DOM=DOMAIN/K,ARGS/S,CMD=COMMAND";

static LONG    args[4];
static struct RDArgs *HelpArgs = NULL;
extern struct WBStartup *_WBenchMsg;

enum { USAGE_ALL = 0, USAGE_DOM, USAGE_ARGS, USAGE_CMD };
enum { DOM_CLI = 0, DOM_USB, DOM_PCI, DOM_GFX, DOM_AUDIO, DOM_FILES, DOM_REXX, DOM_SCRIPT, DOM_RESSOURCES, DOM_MISC, DOM_TASKS };

/**#define NB_COMMANDS 112
#define NB_COMMANDS_FULL 112
#define NB_DOM 13**/

int NB_COMMANDS=0, NB_COMMANDS_FULL=0, NB_DOM=0;
#define RC_OK 0
#define RC_WARN 5

#define _VERSION_ "[MOS] 0.93 (05.03.2005)"
char DVER[]="$VER: Help "_VERSION_"© 2004-2005 by Nicolas Ramz";

typedef struct domains_desc
{
    int nb;
    char *desc;
} domains_desc;

typedef struct commands_info
{
    char *name;
    char *args;
    char *desc;
    char *desc_full;
    int  dom;
} commands_info;

char *domain_names[]={
                     (char*) "Shell",
                     (char*) "USB",
                     (char*) "PCI",
                     (char*) "GFX",
                     (char*) "Audio",
                     (char*) "Files",
                     (char*) "Rexx",
                     (char*) "Script",
                     (char*) "Resources",
                     (char*) "Misc",
                     (char*) "Tasks"
                     };

domains_desc domains[]={
/*{
DOM_CLI,
"cli"
},*/
{
DOM_CLI,
"shell"
},
{
DOM_USB,
"usb"
},
{
DOM_PCI,
"pci"
},
/*{
DOM_CLI,
"cli"
},*/
{
DOM_GFX,
"gfx"
},
{
DOM_AUDIO,
"audio"
},
{
DOM_AUDIO,
"sound"
},
{
DOM_FILES,
"files"
},
{
DOM_FILES,
"io"
},
{
DOM_REXX,
"rexx"
},
{
DOM_RESSOURCES,
"resources"
},
{
DOM_MISC,
"misc"
},
{
DOM_SCRIPT,
"script"
},

{
DOM_TASKS,
"tasks"
},

// Indique la fin du tableau...
{
-1,
NULL
}

};


commands_info list[]={
{
"AddAudioModes -",
"FILES/M, QUIET/S, REFRESH/S, REMOVE/S, DBLSCAN/S",
(char *)_msgAddAudioModes,
(char *)_msgAddAudioModesFULL,
DOM_AUDIO,
},

{
"AddBuffers    -",
"DRIVE/A, BUFFERS/N",
(char*)_msgAddBuffers,
(char*)_msgAddBuffersFULL,
DOM_FILES,
},

{
"AddDataTypes  -",
"FILES/M, QUIET/S, REFRESH/S",
(char*)_msgAddDataTypes,
(char*)_msgAddDataTypesFULL,
DOM_GFX,
},

{
"AddUSBClasses -",
"QUIET/S, REMOVE/S",
(char*)_msgAddUSBClasses,
(char*)_msgAddUSBClassesFULL,
DOM_USB,
},

{
"AddUSBHardWare-",
"DEVICE, UNIT/N, QUIET/S, REMOVE/S, ALL/S",
(char*)_msgAddUSBHardWare,
(char*)_msgAddUSBHardWareFULL,
DOM_USB,
},

{
"Alias         -",
"NAME, STRING/F",
(char*)_msgAlias,
(char*)_msgAliasFULL,
DOM_CLI,
},


{
"Ask [S]       -",
"PROMPT/A",
(char*)_msgAsk,
(char*)_msgAskFULL,
DOM_SCRIPT,
},

{
"Assign        -",
"NAME, TARGET/M, LIST/S, DISMOUNT/S, DEFER/S, PATH/S, ADD/S, \n\
REMOVE/S, VOLS/S, DIRS/S, DEVICES/S",
(char*)_msgAssign,
(char*)_msgAssignFULL,
DOM_FILES,
},

{
"Avail         -",
"FAST/S, CHIP/S, TOTAL/S, FLUSH/S, H=HUMAN/S",
(char*)_msgAvail,
(char*)_msgAvailFULL,
DOM_RESSOURCES,
},

{
"Beep          -",
NULL,
(char*)_msgBeep,
(char*)_msgBeepFULL,
DOM_MISC,
},

{
"BindDrivers   -",
NULL,
(char*)_msgBindDrivers,
(char*)_msgBindDriversFULL,
DOM_MISC,
},

{
"Break         -",
"PROCESS/A/N, ALL/S, C/S, D/S, E/S, F/S",
(char*)_msgBreak,
(char*)_msgBreakFULL,
DOM_TASKS,
},

{
"CD            -",
"DIR",
(char*)_msgCD,
(char*)_msgCDFULL,
DOM_FILES,
},

{
"ChangeTaskPri -",
"PR=PRIORITY/A/N, PROCESS/K/N",
(char*)_msgChangeTaskPri,
(char*)_msgChangeTaskPriFULL,
DOM_TASKS,
},

{
"CLI           -",
NULL,
(char*)_msgCLI,
(char*)_msgCLIFULL,
DOM_CLI,
},

{
"ConClip       -",
"CLIPUNIT=UNIT/N, OFF/S",
(char*)_msgConClip,
(char*)_msgConClipFULL,
DOM_MISC,
},

{
"Copy          -",
"FROM/M, TO, PAT=PATTERN/K, BUF=BUFFER/K/N, ALL/S, DIRECT/S, \n\
CLONE/S, DATES/S, NOPRO/S, COM=COMMENT/S, QUIET/S, NOREQ/S, \n\
ERRWARN/S, MAKEDIR/S, MOVE/S, DELETE/S, HARD=HARDLINK/S, \n\
SOFT=SOFTLINK/S, FOLNK=FORCELINK/S, FODEL=FORCEDELETE/S, \n\
FOOVR=FORCEOVERWRITE/S,DONTOVR=DONTOVERWRITE/S,FORCE/S",
(char*)_msgCopy,
(char*)_msgCopyFULL,
DOM_FILES,
},

{
"CPU           -",
"CACHE/S, BURST/S, NOCACHE/S, NOBURST/S, DATACACHE/S, DATABURST/S, \n\
NODATACACHE/S, NODATABURST/S, INSTCACHE/S, INSTBURST/S, NOINSTCACHE/S, \n\
NOINSTBURST/S, COPYBACK/S, NOCOPYBACK/S, EXTERNALCACHE/S, NOEXTERNALCACHE/S, \n\
FASTROM/S, NOFASTROM/S, TRAP/S, NOTRAP/S, NOMMUTEST/S, CHECK/K",
(char*)_msgCPU,
(char*)_msgCPUFULL,
DOM_MISC,
},

{
"Date          -",
"DAY, DATE, TIME, TO=VER/K",
(char*)_msgDate,
(char*)_msgDateFULL,
DOM_MISC,
},

{
"Delete        -",
"FILE/M/A, ALL/S, QUIET/S, FORCE/S, FOLLOWLINKS/S",
(char*)_msgDelete,
(char*)_msgDeleteFULL,
DOM_FILES,
},

{
"DevList       -",
NULL,
(char*)_msgDevList,
(char*)_msgDevListFULL,
DOM_RESSOURCES,
},

{
"DIR           -",
"DIR, OPT/K, ALL/S, DIRS/S, FILES/S, INTER/S",
(char*)_msgDIR,
(char*)_msgDIRFULL,
DOM_FILES,
},

{
"DiskChange    -",
"DEVICE/A",
(char*)_msgDiskChange,
(char*)_msgDiskChangeFULL,
DOM_FILES,
},

{
"DiskFree      -",
"VOLUME, NOPOSTFIX/S, PERCENT/S",
(char*)_msgDiskFree,
(char*)_msgDiskFreeFULL,
DOM_FILES,
},

{
"DRadioTool    -",
"ON/S, OFF/S, FREQ/K/N, SCAN/S, AUTO/S, SIGNAL/S, UNIT/N/K",
(char*)_msgDRadioTool,
(char*)_msgDRadioToolFULL,
DOM_USB,
},

{
"Echo          -",
"/M, NOLINE/S, FIRST/K/N, LEN/K/N, TO/K",
(char*)_msgEcho,
(char*)_msgEchoFULL,
DOM_CLI,
},

{
"Else [S]      -",
NULL,
(char*)_msgElse,
(char*)_msgElseFULL,
DOM_SCRIPT,
},

{
"EndCli        -",
NULL,
(char*)_msgEndCli,
(char*)_msgEndCliFULL,
DOM_CLI,
},

{
"EndIf [S]     -",
NULL,
(char*)_msgEndIf,
(char*)_msgEndIfFULL,
DOM_SCRIPT,
},

{
"EndShell      -",
NULL,
(char*)_msgEndShell,
(char*)_msgEndShellFULL,
DOM_CLI,
},

{
"EndSkip [S]   -",
NULL,
(char*)_msgEndSkip,
(char*)_msgEndSkipFULL,
DOM_SCRIPT,
},

{
"Eval [S]      -",
"VALUE1/A, OP, VALUE2/M, TO/K, LFORMAT/K",
(char*)_msgEval,
(char*)_msgEvalFULL,
DOM_SCRIPT,
},

{
"Execute       -",
"FILE/A",
(char*)_msgExecute,
(char*)_msgExecuteFULL,
DOM_CLI,
},

{
"FailAt [S]    -",
"RCLIM/N",
(char*)_msgFailAt,
(char*)_msgFailAtFULL,
DOM_SCRIPT,
},

{
"Fault         -",
"/N/M",
(char*)_msgFault,
(char*)_msgFaultFULL,
DOM_CLI,
},

{
"FileNote      -",
"FILE/A, COMMENT, ALL/S, QUIET/S",
(char*)_msgFileNote,
(char*)_msgFileNoteFULL,
DOM_FILES,
},

{
"FlushLib      -",
"LIBRARY/A/M, ONCE/S, QUIET/S",
(char*)_msgFlushLib,
(char*)_msgFlushLibFULL,
DOM_RESSOURCES,
},

{
"Format        -",
"DEVICE=DRIVE/A/K, NAME/A/K, OFS/S, FFS/S, SFS/S, MSDOS/S, \n\
INTL=INTERNATIONAL=CASESENSITIVE/S, NOINTL=NOINTERNATIONAL/S, \n\
DIRCACHE/S, NODIRCACHE/S, LNFS=LONGFILENAMES/S, \n\
NOLNFS=NOLONGFILENAMES/S, NOICONS/S, QUICK/S, NORECYCLED/S, \n\
SHOWRECYCLED/S",
(char*)_msgFormat,
(char*)_msgFormatFULL,
DOM_FILES,
},

{
"FSList        -",
NULL,
(char*)_msgFSList,
(char*)_msgFSListFULL,
DOM_RESSOURCES,
},

{
"FSTest        -",
NULL,
(char*)_msgFSTest,
(char*)_msgFSTestFULL,
DOM_RESSOURCES,
},

{
"Get           -",
"NAME/A",
(char*)_msgGet,
(char*)_msgGetFULL,
DOM_MISC,
},

{
"GetEnv        -",
"NAME/A",
(char*)_msgGetEnv,
(char*)_msgGetEnvFULL,
DOM_MISC,
},

{
"HDRead        -",
"DEVICE/A, UNIT/A/N, SECTOR/A/N, COUNT/A/N, SECTORSIZE/N",
(char*)_msgHDRead,
(char*)_msgHDReadFULL,
DOM_MISC,
},

{
"HDTest        -",
"DEVICE/K, UNIT/A/N, SECTOR/A/N, SIZE/N, OFFSET/N, RETRY/N, CHIP/S,\n\
NOACTUAL/S, NUMDATA/S,SECTORSIZE/K/N",
(char*)_msgHDTest,
(char*)_msgHDTestFULL,
DOM_MISC,
},

{
"HI [Rexx]     -",
NULL,
(char*)_msgHI,
(char*)_msgHIFULL,
DOM_REXX,
},

{
"IconX         -",
NULL,
(char*)_msgIconX,
(char*)_msgIconXFULL,
DOM_CLI,
},

{
"If [S]        -",
"NOT/S, WARN/S, ERROR/S, FAIL/S, EQ/K, GT/K, GE/K, \n\
VAL/S, EXISTS/K, NOREQ/S",
(char*)_msgIf,
(char*)_msgIfFULL,
DOM_SCRIPT,
},

{
"Info          -",
"DISKS/S, VOLS=VOLUMES/S, GOODONLY/S, BLOCKS/S, \n\
VERBOSE/S,DEVICES/M",
(char*)_msgInfo,
(char*)_msgInfoFULL,
DOM_FILES,
},

{
"IPrefs        -",
NULL,
(char*)_msgIPrefs,
(char*)_msgIPrefsFULL,
DOM_MISC,
},

{
"Join          -",
"FILE/M/A, AS=TO/K/A",
(char*)_msgJoin,
(char*)_msgJoinFULL,
DOM_FILES,
},

{
"Lab [S]       -",
NULL,
(char*)_msgLab,
(char*)_msgLabFULL,
DOM_SCRIPT,
},

{
"Lha           -",
"non-standard arguments, type \"lha\" for more information",
(char*)_msgLha,
(char*)_msgLhaFULL,
DOM_FILES,
},

{
"LibList       -",
NULL,
(char*)_msgLibList,
(char*)_msgLibListFULL,
DOM_RESSOURCES,
},

{
"List          -",
"DIR/M, P=PAT/K, KEYS/S, DATES/S, NODATES/S, TO/K, SUB/K, \n\
SINCE/K, UPTO/K, QUICK/S, BLOCK/S, NOHEAD/S, FILES/S,DIRS/S, \n\
LFORMAT/K, SORT/K, USERS/S, GROUPS/S, ALL/S",
(char*)_msgList,
(char*)_msgListFULL,
DOM_FILES,
},

{
"LoadMonDrvs   -",
"EXCEPT, STACKSIZE/N/K",
(char*)_msgLoadMonDrvs,
(char*)_msgLoadMonDrvsFULL,
DOM_GFX,
},

{
"LoadWB        -",
"DEBUG=-DEBUG/S, DELAY/S, CLEANUP/S, NEWPATH/S, NOWBSTARTUP/S",
(char*)_msgLoadWB,
(char*)_msgLoadWBFULL,
DOM_MISC,
},

{
"Lock          -",
"DRIVE/A, ON/S, OFF/S, PASSKEY",
(char*)_msgLock,
(char*)_msgLockFULL,
DOM_FILES,
},

{
"MakeDir       -",
"NAME/M",
(char*)_msgMakeDir,
(char*)_msgMakeDirFULL,
DOM_FILES,
},

{
"MakeLink      -",
"FROM/A, TO/A, HARD/S, FORCE/S",
(char*)_msgMakeLink,
(char*)_msgMakeLinkFULL,
DOM_FILES,
},

{
"MemTest       -",
"VERBOSE/S, QUIET/S, DISABLE/S, EXTENSIVE/S, REVERSE/S, DELAY/N",
(char*)_msgMemTest,
(char*)_msgMemTestFULL,
DOM_RESSOURCES,
},

{
"Mount         -",
"DEVICE/M, FROM/K, DEBUG/S",
(char*)_msgMount,
(char*)_msgMountFULL,
DOM_FILES,
},

{
"NewCLI        -",
"WINDOW, FROM",
(char*)_msgNewCLI,
(char*)_msgNewCLIFULL,
DOM_CLI,
},

{
"NewShell      -",
"WINDOW, FROM",
(char*)_msgNewShell,
(char*)_msgNewShellFULL,
DOM_CLI,
},

{
"OpenPCIInfo   -",
NULL,
(char*)_msgOpenPCIInfo,
(char*)_msgOpenPCIInfoFULL,
DOM_PCI,
},

{
"Path          -",
"PATH/M, ADD/S, SHOW/S, RESET/S, REMOVE/S, QUIET/S",
(char*)_msgPath,
(char*)_msgPathFULL,
DOM_CLI,
},

{
"PCIScan       -",
"DATA/S, VERBOSE/S",
(char*)_msgPCIScan,
(char*)_msgPCIScanFULL,
DOM_PCI,
},

{
"PCIWrite      -",
"BUS/N, DEV/N, FUNC/N, REG/A, DATA/A, SIZE/N",
(char*)_msgPCIWrite,
(char*)_msgPCIWriteFULL,
DOM_PCI,
},

{
"PenCamTool    -",
"TO/A, PICNUM/N, INTERVAL/N, UPTO/N/K, NOBEEP/S, GAMMA/K, \n\
SHARPEN/S, TEXT/K, FONT/K, FONTSIZE/N/K, UNIT/N/K",
(char*)_msgPenCamTool,
(char*)_msgPenCamToolFULL,
DOM_USB,
},

{
"Prompt        -",
"PROMPT",
(char*)_msgPrompt,
(char*)_msgPromptFULL,
DOM_CLI,
},

{
"Protect       -",
"FILE/A, FLAGS, ADD/S, SUB/S, ALL/S, QUIET/S",
(char*)_msgProtect,
(char*)_msgProtectFULL,
DOM_FILES,
},

{
"Quit [S]      -",
"RC/N",
(char*)_msgQuit,
(char*)_msgQuitFULL,
DOM_SCRIPT,
},

{
"Reboot        -",
NULL,
(char*)_msgReboot,
(char*)_msgRebootFULL,
DOM_MISC,
},

{
"Relabel       -",
"DRIVE/A, NAME/A",
(char*)_msgRelabel,
(char*)_msgRelabelFULL,
DOM_FILES,
},

{
"RemRAD        -",
"DEVICE, FORCE/S",
(char*)_msgRemRAD,
(char*)_msgRemRADFULL,
DOM_FILES,
},

{
"RemResident   -",
"MODULE/A",
(char*)_msgRemResident,
(char*)_msgRemResidentFULL,
DOM_RESSOURCES,
},

{
"Rename        -",
"FROM/A/M, TO=AS/A, QUIET/S",
(char*)_msgRename,
(char*)_msgRenameFULL,
DOM_FILES,
},

{
"RequestChoice -",
"TITLE/A, BODY/A, GADGETS/A/M, PUBSCREEN/K",
(char*)_msgRequestChoice,
(char*)_msgRequestChoiceFULL,
DOM_MISC,
},

{
"RequestFile   -",
"DRAWER, FILE/K, PATTERN/K, TITLE/K, POSITIVE/K, NEGATIVE/K, \n\
ACCEPTPATTERN/K, REJECTPATTERN/K,SAVEMODE/S,MULTISELECT/S, \n\
DRAWERSONLY/S,NOICONS/S,PUBSCREEN/K,INITIALVOLUMES/S",
(char*)_msgRequestFile,
(char*)_msgRequestFileFULL,
DOM_MISC,
},

{
"Resident      -",
"NAME, FILE, ALIAS/K, REMOVE/S, ADD/S, REPLACE/S, \n\
PURE=FORCE/S, SYSTEM/S,DEFER/S",
(char*)_msgResident,
(char*)_msgResidentFULL,
DOM_RESSOURCES,
},

{
"ResList       -",
NULL,
(char*)_msgResList,
(char*)_msgResListFULL,
DOM_RESSOURCES,
},

{
"RexxMast      -",
NULL,
(char*)_msgRexxMast,
(char*)_msgRexxMastFULL,
DOM_REXX,
},

{
"Run           -",
"DETACH/S, QUIET/S, STACK/K/N, PRI/K/N, COMMAND/F",
(char*)_msgRun,
(char*)_msgRunFULL,
DOM_CLI,
},

{
"RX [Rexx]     -",
NULL,
(char*)_msgRX,
(char*)_msgRXFULL,
DOM_REXX,
},

{
"RXC [Rexx]    -",
NULL,
(char*)_msgRXC,
(char*)_msgRXCFULL,
DOM_REXX,
},

{
"RXLIB [Rexx]  -",
"NAME, PRIORITY/N, OFFSET/N, VERSION/N",
(char*)_msgRXLIB,
(char*)_msgRXLIBFULL,
DOM_REXX,
},

{
"RXSET [Rexx]  -",
"NAME, VALUE/F",
(char*)_msgRXSET,
(char*)_msgRXSETFULL,
DOM_REXX,
},

{
"Search        -",
"FROM/M, SEARCH/A, ALL/S, NONUM/S, QUIET/S, QUICK/S, \n\
FILE/S, PATTERN/S, CASE/S",
(char*)_msgSearch,
(char*)_msgSearchFULL,
DOM_FILES,
},

{
"SegTracker    -",
"SHOW/S, DUMP/S, VERBOSE/S, MAPFILE, NAME, FIND/M",
(char*)_msgSegTracker,
(char*)_msgSegTrackerFULL,
DOM_MISC,
},

{
"Set           -",
"NAME, STRING/F",
(char*)_msgSet,
(char*)_msgSetFULL,
DOM_MISC,
},

{
"SetClock      -",
"LOAD/S, SAVE/S, RESET/S",
(char*)_msgSetClock,
(char*)_msgSetClockFULL,
DOM_MISC,
},

{
"SetCon        -",
"COMMAND/F",
(char*)_msgSetCon,
(char*)_msgSetConFULL,
DOM_CLI,
},

{
"SetDate       -",
"FILE/A, WEEKDAY, DATE, TIME, ALL/S",
(char*)_msgSetDate,
(char*)_msgSetDateFULL,
DOM_MISC,
},

{
"SetEnv        -",
"NAME, SAVE/S, STRING/F",
(char*)_msgSetEnv,
(char*)_msgSetEnvFULL,
DOM_MISC,
},

{
"SetKeyboard   -",
"KEYMAP/A",
(char*)_msgSetKeyboard,
(char*)_msgSetKeyboardFULL,
DOM_MISC,
},

{
"Skip [S]      -",
"LABEL, BACK/S",
(char*)_msgSkip,
(char*)_msgSkipFULL,
DOM_SCRIPT,
},

{
"Sort          -",
"FROM/A, TO/A, COLSTART/K, CASE/S, NUMERIC/S",
(char*)_msgSort,
(char*)_msgSortFULL,
DOM_FILES,
},

{
"Stack         -",
"SIZE/N",
(char*)_msgStack,
(char*)_msgStackFULL,
DOM_CLI,
},

{
"Stat          -",
NULL,
(char*)_msgStat,
(char*)_msgStatFULL,
DOM_MISC,
},

{
"Status        -",
"PROCESS/N, FULL/S, TCB/S, CLI=ALL/S, COM=COMMAND/K",
(char*)_msgStatus,
(char*)_msgStatusFULL,
DOM_TASKS,
},

{
"TaskList      -",
"VERBOSE/S",
(char*)_msgTaskList,
(char*)_msgTaskListFULL,
DOM_TASKS,
},

{
"TCC [Rexx]    -",
NULL,
(char*)_msgTCC,
(char*)_msgTCCFULL,
DOM_REXX,
},

{
"TCO [Rexx]    -",
NULL,
(char*)_msgTCO,
(char*)_msgTCOFULL,
DOM_REXX,
},

{
"TE [Rexx]     -",
NULL,
(char*)_msgTE,
(char*)_msgTEFULL,
DOM_REXX,
},

{
"Touch         -",
"NAME/A/M, ALL/S",
(char*)_msgTouch,
(char*)_msgTouchFULL,
DOM_FILES,
},

{
"Trance        -",
NULL,
(char*)_msgTrance,
(char*)_msgTranceFULL,
DOM_MISC,
},

{
"TS [Rexx]     -",
NULL,
(char*)_msgTS,
(char*)_msgTSFULL,
DOM_REXX,
},

{
"Type          -",
"FROM/A/M, TO/K, OPT/K, HEX/S, NUMBER/S",
(char*)_msgType,
(char*)_msgTypeFULL,
DOM_FILES,
},

{
"UnAlias       -",
"NAME",
(char*)_msgUnAlias,
(char*)_msgUnAliasFULL,
DOM_CLI,
},

{
"UnSet         -",
"NAME",
(char*)_msgUnSet,
(char*)_msgUnSetFULL,
DOM_CLI,
},

{
"UnSetEnv      -",
"NAME, SAVE/S",
(char*)_msgUnSetEnv,
(char*)_msgUnSetEnvFULL,
DOM_CLI,
},

{
"UpRoarTool    -",
"DEVINFO/S, FILELIST=FL/S, UPLOAD=UL/K, DOWNLOAD=DL/K, \n\
DELETE=DEL/K, FORMAT/S, EXT/S, AS/K",
(char*)_msgUpRoarTool,
(char*)_msgUpRoarToolFULL,
DOM_USB,
},

{
"UpTime        -",
NULL,
(char*)_msgUpTime,
(char*)_msgUpTimeFULL,
DOM_MISC,
},

{
"USBDevLister  -",
NULL,
(char*)_msgUSBDevLister,
(char*)_msgUSBDevListerFULL,
DOM_USB,
},

{
"USBErrorLog   -",
NULL,
(char*)_msgUSBErrorLog,
(char*)_msgUSBErrorLogFULL,
DOM_USB,
},

{
"Version       -",
"NAME, VERSION/N, REVISION/N, FILE/S, FULL/S, UNIT/N, \n\
INTERNAL/S, RES/S",
(char*)_msgVersion,
(char*)_msgVersionFULL,
DOM_MISC,
},

{
"Wait          -",
"TIME/N, SEC=SECS/S, MIN=MINS/S, UNTIL/K",
(char*)_msgWait,
(char*)_msgWaitFULL,
DOM_MISC,
},

{
"WaitForPort   -",
"PORTNAME/A, I=INTERVAL/K/N, L=LOOP/K/N, D=DISAPPEAR/S",
(char*)_msgWaitForPort,
(char*)_msgWaitForPortFULL,
DOM_MISC,
},

{
"WBRun         -",
"PROG/A, ARGS/M, STACK/K/N, PRI/K/N, DELAY/K/N",
(char*)_msgWBRun,
(char*)_msgWBRunFULL,
DOM_CLI,
},


{
"Which         -",
"FILE/A, NORES/S, RES/S, ALL/S",
(char*)_msgWhich,
(char*)_msgWhichFULL,
DOM_FILES,
},

{
"Why           -",
NULL,
(char*)_msgWhy,
(char*)_msgWhyFULL,
DOM_CLI,
},

// Indique la fin du tableau...
{
NULL,
NULL,
NULL,
NULL,
-1,
}

};

char usage_text[]= "";

typedef struct commands
{
    commands_info *comms;
    //int nb;
} commands;

commands commands_list={list};  //, NB_COMMANDS};

struct Library *LocaleBase=NULL;

/********* Protos *********/
void DisplayALL(commands *comm);
void SetColor(char col[], int num);
void OpenLibs(void);
void CloseLibs(void);

void DisplayHALF(commands *comm, int nb)
{
    if (nb >= NB_COMMANDS) //comm->nb)
    {
        printf("Ooops ! Erreur innatendue :)\n");
        return;
    }

    printf("%s%s %s%s\n", COLOR2, comm->comms[nb].name, COLOR1, comm->comms[nb].desc);
}

void DisplayALL(commands *comm)
{
    int i=0;
    if (!comm)
        return;

    while (i < NB_COMMANDS) //comm->nb)
    {
        DisplayHALF(comm, i);
        ++i;
    }
    printf("\n%s%s: %d%s %s - %s%d%s %s\n", COLOR2, (char*)msgTotal, NB_COMMANDS, COLOR1, (char*)msgTotalCmds, COLOR2, NB_DOM, COLOR1, (char*)msgTotalDomains);

    return;
}

void DisplayFULL(commands *comm, int nb)
{
    if (nb >= NB_COMMANDS) //comm->nb)
    {
        printf("Ooops ! Unexpected error :)\n");
        return;
    }

    printf("\n%s%s %s%s\n\n", COLOR2, comm->comms[nb].name, COLOR1, comm->comms[nb].desc);
    printf("%s%s\n\n", COLOR2, (comm->comms[nb].args!=NULL) ? comm->comms[nb].args : (char*)msgNoTemplate);
    printf("%s%s\n", COLOR1, comm->comms[nb].desc_full);
}

int DisplayDOM(commands *comm, int dom)
{
    int i=0, j=0;

    if (!comm)
        return 0;

    while (i < NB_COMMANDS) //comm->nb)
    {
        if (comm->comms[i].dom == dom)
        {
            DisplayHALF(comm, i);
            j++;
        }
        ++i;
    }
}

DisplayARGS(void)
{
    printf("%s%s \n\n%s%s\n", COLOR2, msgArgs1, COLOR1, msgArgs2);

}

void SetColor(char col[], int num)
{
    if (col)
        col[3]=num;
    return;
}

void Usage(void)
{
    printf("%s%s %s%s%s\n\n", COLOR2, msgHelpUsage, COLOR2, usageTemplate, COLOR1);
    printf("ALL:  %s\n", msgUsageALL);
    printf("CMD:  %s\n", msgUsageCMD);
    printf("ARGS: %s\n", msgUsageARGS);
    printf("DOM:  %s\n", msgUsageDOM);
    printf("      DOM %s: SHELL, USB, PCI, GFX, AUDIO|SOUND, FILES|IO,\n      REXX, TASKS, MISC, RESOURCES, SCRIPT\n\n", msgUsageDOM2);
    printf("%s%s%s\n\n", COLOR2, msgUsageExamples, COLOR1);
    printf("Help CMD=DIR %s\n", msgUsageEX1);
    printf("Help DOM=AUDIO %s\n", msgUsageEX2);
    printf("\nHelp %s\n", _VERSION_);
    printf("Copyright © 2004-2005 Nicolas Ramz\n");
    printf("%s\n", msgUsageLANG);
}

void OpenLibs(void)
{
    LocaleBase=(struct Library*)OpenLibrary("locale.library", 0);
    _STIOpenHelpCatalog();
}

void CloseLibs(void)
{
    _STDCloseHelpCatalog();
    if (LocaleBase)
        CloseLibrary(LocaleBase);
}

void localize_array(char *array[])
{
    char **x;
    x=array;
    *x = (char *)((struct FC_String *)(*x))->msg;
}

void localize_stuff(void)
{
    int i;

    for (i=0; i<NB_COMMANDS; ++i)
        localize_array(&list[i].desc);

    for (i=0; i<NB_COMMANDS_FULL; ++i)
        localize_array(&list[i].desc_full);
}

int find_cmd(char *name)
{
    int i, j;

    char tmp[255];
    char tmp2[255];

    sprintf(tmp, "%s", name);
    for (i=0; i<strlen(name); ++i)
        tmp[i] = tolower(name[i]);

    for (i=0; i<NB_COMMANDS_FULL; ++i)
    {
        sprintf(tmp2, "%s", list[i].name);
        for (j=0; j<strlen(tmp2); ++j)
            tmp2[j] = tolower(tmp2[j]);

        //printf("Recherche de '%s' ds '%s'\n", tmp2, tmp);

        if (strstr(tmp2, tmp))
        {
            // On regarde si c assez long...
            sprintf(tmp2, "%s", list[i].name);
            for (j=0; j<strlen(tmp2); ++j)
                if (tmp2[j]==' ' || tmp2[j] == '-')
                    break;
            //**printf("j='%d' et strlen='%d'\n", j, strlen(tmp));
            //printf("Trouve: '%s'\n", list[i].name);
            if (j == strlen(tmp))
                return(i);
        }
    }

    return(-1);
}

int find_dom(char *dom)
{
    int i=0;
    char tmp[255];

    if (!dom)
        return -1;

    sprintf(tmp, "%s", dom);
    for (i=0; i<strlen(dom); ++i)
        tmp[i] = tolower(dom[i]);

    for (i=0; i<NB_DOM; ++i)
    {
        if (strstr(domains[i].desc, tmp))
        {
            if (strlen(tmp) == strlen(domains[i].desc))
                return(domains[i].nb);

        }
    }

    return(-1);
}

void calculate_size(void)
{
    int i=0;
    while (domains[i].desc)
        ++i;

    //printf("nb_dom=%d\n", i);
    NB_DOM=i;

    i=0;
    while (list[i].name)
        ++i;

    //printf("nb de cmd=%d\n", i);
    NB_COMMANDS=i;
    NB_COMMANDS_FULL=i;
}

int main(int argc, char *argv[])
{
    //printf("%sHelp version 0.1\n----\n\n%s", COLOR3, RESET);
    int option;
    int num_opt=0;
    int trouve=-1;
    int return_code=0;

    OpenLibs();
    calculate_size();
    localize_stuff();

    //printf("***test***\n");
    //printf("%s\n", msgAddAudioModesFULL);
    //printf("***/test***\n");


    memset(args, '\0', sizeof (args));
    if (_WBenchMsg == NULL)
    {
        /* Parse the command line here */
        HelpArgs = (struct RDArgs*)ReadArgs(usageTemplate, (LONG*)args, NULL);
        if (HelpArgs == NULL)
        {
            //printf("**NULL**\n");
            if (argc >2)
            {
                printf("%s\n\n", msgUsageERR2);
                return_code = RC_WARN;
            }
            else
            if (argc >1)
            {
                printf("%s\n\n", msgUsageERR1);
                return_code = RC_WARN;
            }
            //**printf("%s\n\n", msgUsageERR1);
            Usage();
            //printf("*** 1 ***\n");
        }
        else
        {
            if (args[USAGE_ALL])
            {
                option=USAGE_ALL;
                num_opt++;
            }

            if (args[USAGE_DOM])
            {
                option=USAGE_DOM;
                num_opt++;
            }

            if (args[USAGE_ARGS])
            {
                option=USAGE_ARGS;
                num_opt++;
            }

            if (args[USAGE_CMD])
            {
                option=USAGE_CMD;
                num_opt++;
            }

            if (num_opt>1)
            {
                printf("%s\n\n", msgUsageERR2);
                Usage();
                return_code = RC_WARN;
                //printf("*** 2 ***\n");
            }
            else
            {
                switch(option)
                {
                    case USAGE_ALL:
                        DisplayALL(&commands_list);
                    break;

                    case USAGE_DOM:
                        //**printf("Dom '%s' detecté\n", args[USAGE_DOM]);
                        //**printf("Option pas encore codée :)\n");
                        trouve = find_dom((char*)args[USAGE_DOM]);
                        if (trouve >-1)
                        {
                            //** printf("Domaine '%s' => '%d'\n", (char*)args[USAGE_DOM], trouve);
                            printf("%s%s '%s': %s\n\n", COLOR2, (char*)msgDomainFound, (char*)domain_names[trouve], COLOR1);
                            DisplayDOM(&commands_list, trouve);
                        }
                        else
                        {
                            printf("%s '%s'.\n", (char*)msgNotFound2, (char*)args[USAGE_DOM]);
                            return_code = RC_WARN;
                        }
                            //DisplayALL(&commands_list);
                    break;

                    case USAGE_ARGS:
                        //**printf("Args detecté\n", args[USAGE_ARGS]);
                        //**printf("Option pas encore codée :)\n");
                        DisplayARGS();
                        //DisplayALL(&commands_list);
                    break;

                    case USAGE_CMD:
                        //**printf("Cmd '%s' detecté\n", args[USAGE_CMD]);
                        trouve = find_cmd((char*)args[USAGE_CMD]);
                        if (trouve>-1)
                        {
                            DisplayFULL(&commands_list, trouve);
                        }
                        else
                        {
                            //**printf("Introuvable => Rechercher le domaine...\n");
                            trouve = find_dom((char*)args[USAGE_CMD]);
                            if (trouve >-1)
                            {
                                //**printf("Domaine '%s' => '%d'\n", (char*)args[USAGE_CMD], trouve);
                                printf("%s%s '%s': %s\n\n", COLOR2, (char*)msgDomainFound, (char*)domain_names[trouve], COLOR1);
                                DisplayDOM(&commands_list, trouve);
                            }
                        }
                        if (trouve < 0)
                        {
                            printf("%s '%s'.\n",  (char*)msgNotFound, (char*)args[USAGE_CMD]);
                            return_code = RC_WARN;
                        }
                        //**printf("trouve = '%d'\n", trouve);
                        //printf("Option pas encore codée :)\n");
                        //DisplayALL(&commands_list);
                    break;

                    default:
                        Usage();
                        //printf("*** 3 ***\n");
                    break;
                 }
            }
        }
    }

    CloseLibs();
    //printf("RC = %d\n", return_code);
    return(return_code);
}
