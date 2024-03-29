/* Configuration file for PB's DWM build */
/* set at 10.04.2021 */

/* See LICENSE file for copyright and license details. */

/*========== Appearance ========== */
static const unsigned int borderpx = 1; /* border pixel of windows */
static const unsigned int snap = 32;    /* snap pixel */
static const unsigned int gappih = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv = 10;  /* vert inner gap between windows */
static const unsigned int gappoh =
    10; /* horiz outer gap between windows and screen edge */
static const unsigned int gappov =
    10; /* vert outer gap between windows and screen edge */
static int smartgaps =
    1; /* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning =
    1; /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor
          X */
static const unsigned int systrayonleft =
    0; /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 5; /* systray spacing */
static const int systraypinningfailfirst =
    1; /* 1: if pinning fails, display systray on the first monitor, False:
          display systray on the last monitor*/
static const int showsystray = 1; /* 0 means no systray */
static const int showbar = 1;     /* 0 means no bar */
static const int topbar = 1;      /* 0 means bottom bar */
static const int focusonwheel = 0;
static const int horizpadbar = 3;   /* horizontal padding for statusbar */
static const int vertpadbar = 6;    /* vertical padding for statusbar */
static const Bool viewontag = True; /* Switch view on tag switch */

/* ========== Fonts ==========*/
static const char *fonts[] = {
    "Jetbrains Nerd Font:size=11:antialias=true:autohint=true",
    "FontAwesome:size=10:antialias=true:autohint=true"};
static const char dmenufont[] = "monospace:size=10";

/*========== Colors and Opacity ==========*/
static const char col_gray1[] = "#282c34";
static const char col_gray2[] = "#444444";
static const char col_gray3[] = "#ABB2BF";
static const char col_gray4[] = "#eeeeee";
static const char col_cyan[] = "#56B6C2";
static const char col_purple[] = "#c678DD";
static const char col_green[] = "#98c379";
static const char col_blue[] = "#61afef";
static const char col_black[] = "#000000";
static const char col_red[] = "#E06C75";
static const char col_yellow[] = "#E5C07B";
static const char col_white[] = "#ffffff";

static const char *colors[][3] = {
    /*       		      fg         bg          border   */
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel] = {col_gray4, col_cyan, col_purple},
    [SchemeStatus] = {col_gray3, col_gray1,
                      "#000000"}, // Statusbar right {text,background,not used
                                  // but cannot be empty}
    [SchemeTagsSel] = {col_gray4, col_blue,
                       "#000000"}, // Tagbar left selected {text,background,not
                                   // used but cannot be empty}
    [SchemeTagsNorm] =
        {col_gray3, col_gray1,
         "#000000"}, // Tagbar left unselected {text,background,not used but
                     // cannot be empty}
    [SchemeInfoSel] =
        {col_gray4, col_gray1,
         "#000000"}, // infobar middle  selected {text,background,not used but
                     // cannot be empty}
    [SchemeInfoNorm] =
        {col_gray3, col_gray1,
         "#000000"}, // infobar middle  unselected {text,background,not used but
                     // cannot be empty}
};

/*========== Scratchpads ==========*/
typedef struct {
  const char *name;
  const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL};
const char *spcmd2[] = {"st",     "-n", "spfm",   "-g",
                        "144x41", "-e", "ranger", NULL};
const char *spcmd3[] = {"keepassxc", NULL};
static Sp scratchpads[] = {
    /* name          cmd  */
    {"spterm", spcmd1},
    {"spranger", spcmd2},
    {"keepassxc", spcmd3},
};

/*========== Tagging =========== */
static const char *tags[] = {"  1   ", "  2   ", "  3   ",
                             "  4   ", "  5   ", "  6   ",
                             "  7   ", "  8   ", "  9  "};
static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      	 		                    instance  i		title
       tags mask   		isfloating 		  monitor */
    {"Gimp", NULL, NULL, 0, 1, -1},
    //{ "Brave",       		                    NULL,			NULL,		1 << 1,
    //0,			  -1 },
    {"Mailspring", NULL, NULL, 1 << 3, 0, -1},
    //{ "Thunar",      		                    NULL,                 	NULL,
    //1 << 4,                 0,                        -1 },
    {"jetbrains-clion", NULL, NULL, 1 << 2, 0, -1},
    {"jetbrains-idea", NULL, NULL, 1 << 2, 0, -1},
    {"jetbrains-webstorm", NULL, NULL, 1 << 2, 0, -1},
    {"jetbrains-pycharm", NULL, NULL, 1 << 2, 0, -1},
    {"jetbrains-studio", NULL, NULL, 1 << 2, 0, -1},
    {"Signal", NULL, NULL, 1 << 5, 0, 1},
    {"whatsapp-nativefier-d40211", NULL, NULL, 1 << 5, 0, 1},
    {"discord", NULL, NULL, 1 << 5, 0, 1},
    {"zoom", NULL, NULL, 1 << 6, 0, -1},
    {"teams-for-linux", NULL, NULL, 1 << 6, 0, -1},
    {"microsoft teams - preview", NULL, NULL, 1 << 6, 0, -1},
    {"Pavucontrol", NULL, NULL, 0, 1, -1},
    {NULL, "spterm", NULL, SPTAG(0), 1, -1},
    {NULL, "spfm", NULL, SPTAG(1), 1, -1},
    {NULL, "keepassxc", NULL, SPTAG(2), 0, -1},
};

/*========== Layout(s) ========== */
static const float mfact = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    0; /* 1 means respect size hints in tiled resizals */

#define FORCE_VSPLIT                                                           \
  1 /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"|M|", centeredmaster},
    {"[]=", tile}, /* first entry is default */
    {"[M]", monocle},
    {"TTT", bstack},
    {"###", nrowgrid},
    {":::", gaplessgrid},
    {"===", bstackhoriz},
    {"><>", NULL}, /* no layout function means floating behavior */
    {NULL, NULL},
};

/*========== Key definitions ===========*/
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},    \
      {MODKEY | Mod1Mask, KEY, tagnextmon, {.ui = 1 << TAG}},                  \
      {MODKEY | Mod1Mask | ShiftMask, KEY, tagprevmon, {.ui = 1 << TAG}},

#define CMD(cmd)                                                               \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }
/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

/*========== Commands ==========*/
static char dmenumon[2] =
    "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
    "dmenu_run", "-m",      dmenumon, "-fn",    dmenufont, "-nb",     col_gray1,
    "-nf",       col_gray3, "-sb",    col_cyan, "-sf",     col_gray4, NULL};
static const char *termcmd[] = {"st", NULL};

#include "movestack.c"
#include <X11/XF86keysym.h>
static Key keys[] = {
    /* modifier                     key        function             argument */
    {Mod1Mask, XK_space, spawn, CMD("rofi -show drun")},
    {MODKEY, XK_Return, spawn, {.v = termcmd}},
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_Up, incnmaster, {.i = +1}},
    {MODKEY, XK_Down, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY | ShiftMask, XK_j, movestack, {.i = +1}},
    {MODKEY | ShiftMask, XK_k, movestack, {.i = -1}},
    {MODKEY | ShiftMask, XK_Return, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY, XK_q, killclient, {0}},

    /* Layout manipulation */
    {MODKEY | ControlMask, XK_comma, cyclelayout, {.i = -1}},
    {MODKEY | ControlMask, XK_period, cyclelayout, {.i = +1}},

    /* Switch to specific layouts */
    {MODKEY, XK_m, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_f, fullscreen, {1}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},

    /* switching between monitors */
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ControlMask, XK_Left, tagmon, {.i = -1}},
    {MODKEY | ControlMask, XK_Right, tagmon, {.i = +1}},

    /* Gaps */
    {MODKEY, XK_y, incrgaps, {.i = +5}},
    {MODKEY | ShiftMask, XK_y, incrgaps, {.i = -5}},
    {MODKEY | ControlMask, XK_y, togglegaps, {0}},
    {MODKEY | Mod1Mask, XK_y, defaultgaps, {0}},

    /* Scratchpads */
    {MODKEY, XK_p, togglescratch, {.ui = 0}},
    {MODKEY, XK_minus, scratchpad_show, {0}},
    {MODKEY | ShiftMask, XK_minus, scratchpad_hide, {0}},
    {MODKEY, XK_equal, scratchpad_remove, {0}},

    /* Tags */
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8){
                MODKEY, XK_BackSpace, spawn,
                CMD("rofi -show p -modi p:~/.local/bin/rofi-power-menu "
                    "-theme-str 'window {width: 10%;} listview {lines: 5;}'")},
    {MODKEY | ShiftMask, XK_BackSpace, quit, {0}},
    {MODKEY | ShiftMask, XK_r, quit, {1}},

    /* Apps */
    {MODKEY, XK_c, spawn, CMD("brave")},
    {MODKEY, XK_x, spawn, CMD("st -e 'ranger'")},
    {MODKEY, XK_e, spawn, CMD("thunar")},
    {MODKEY | ControlMask, XK_l, spawn, CMD("multilockscreen -l dimblur")},
    //{ MODKEY|ShiftMask,  	 	XK_c, 	  spawn, CMD("signal-desktop;
    //whatsapp-for-linux; discord") },
    {MODKEY | ShiftMask, XK_c, spawn, CMD("~/.local/bin/communications.sh")},
    {MODKEY | ShiftMask, XK_t, spawn, CMD("pkill picom")},
    {MODKEY | ControlMask, XK_t, spawn, CMD("picom -b")},
    {MODKEY | ControlMask, XK_m, spawn, CMD("pavucontrol")},
    {MODKEY | ShiftMask, XK_m, spawn, CMD("mailspring")},
    {MODKEY | ShiftMask, XK_s, spawn, CMD("flameshot gui")},
    {MODKEY | ControlMask, XK_e, spawn, CMD("~/.local/bin/uskeys")},
    {MODKEY | ControlMask, XK_d, spawn, CMD("~/.local/bin/dekeys")},

    /* Media */
    {0, XF86XK_AudioLowerVolume, spawn,
     CMD("ponymix decrease 2; ~/.local/bin/volume.sh")},
    {0, XF86XK_AudioRaiseVolume, spawn,
     CMD("ponymix increase 2; ~/.local/bin/volume.sh")},
    {0, XF86XK_AudioMute, spawn, CMD("ponymix toggle; ~/.local/bin/volume.sh")},
    {MODKEY | ControlMask, XK_h, spawn, CMD("~/.local/bin/audio2HDMI")},
    {MODKEY | ControlMask, XK_u, spawn, CMD("~/.local/bin/audio2USB")},

    /* Brightness */
    {0, XF86XK_MonBrightnessUp, spawn,
     CMD("xbacklight -inc 10; ~/.local/bin/brightness.sh")},
    {0, XF86XK_MonBrightnessDown, spawn,
     CMD("xbacklight -dec 10; ~/.local/bin/brightness.sh")},

    /* Hue Control */
    {MODKEY | ControlMask, XK_l, spawn, CMD("~/.local/bin/lightsOn")},
    {MODKEY | ShiftMask, XK_l, spawn, CMD("~/.local/bin/lightsOff")},

};

/*========== Button definitions ==========*/
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function argument
     */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, tilemovemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY | ShiftMask, Button1, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
