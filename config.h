
/* Configuration file for PB's DWM build */
/* set at 10.04.2021 */


/* See LICENSE file for copyright and license details. */

/*========== Appearance ========== */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static                int smartgaps = 1;        /* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning = 1;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 5;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int focusonwheel       = 0;
static const int horizpadbar        = 3;        /* horizontal padding for statusbar */
static const int vertpadbar         = 6;        /* vertical padding for statusbar */
static const Bool viewontag         = True;     /* Switch view on tag switch */

/* ========== Fonts ==========*/
static const char *fonts[]          = { "Jetbrains Nerd Font:size=11:antialias=true:autohint=true",
					"FontAwesome:size=10:antialias=true:autohint=true" };
static const char dmenufont[]       = "monospace:size=10";

/*========== Colors and Opacity ==========*/
static const char col_gray1[]       = "#282c34";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#ABB2BF";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#56B6C2";
static const char col_purple[]      = "#c678DD";
static const char col_green[]       = "#98c379";
static const char col_blue[]        = "#61afef";
static const char col_black[]       = "#000000";
static const char col_red[]         = "#E06C75";
static const char col_yellow[]      = "#E5C07B";
static const char col_white[]       = "#ffffff";

static const char *colors[][3]      = {
/*       		      fg         bg          border   */
	[SchemeNorm]      = { col_gray3, col_gray1,  col_gray2  },
	[SchemeSel]       = { col_gray4, col_cyan,   col_purple },
	[SchemeStatus]    = { col_gray3, col_gray1,  "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel]   = { col_gray4, col_blue,   "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
    	[SchemeTagsNorm]  = { col_gray3, col_gray1,  "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
    	[SchemeInfoSel]   = { col_gray4, col_gray1,  "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
    	[SchemeInfoNorm]  = { col_gray3, col_gray1,  "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};

/*========== Scratchpads ==========*/
typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {"st", "-n", "spfm", "-g", "144x41", "-e", "ranger", NULL };
const char *spcmd3[] = {"keepassxc", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spranger",    spcmd2},
	{"keepassxc",   spcmd3},
};

/*========== Tagging =========== */
static const char *tags[] = { "  1   ", "  2   ", "  3   ", "  4   ", "  5   ", "  6   ", "  7   ", "  8   ", "  9  " };
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      	 		 instance  i		title 	       	tags mask   		isfloating 		  monitor */
	{ "Gimp",	 		 NULL,			NULL,		0,			1,			  -1 },
	//{ "Brave",       		 NULL,			NULL,		1 << 1,			0,			  -1 },
	{ "Mailspring",  		 NULL,                 	NULL,           1 << 3,                 0,                        -1 },
	//{ "Thunar",      		 NULL,                 	NULL,           1 << 4,                 0,                        -1 },
	{ "jetbrains-clion",         	 NULL,                 	NULL,           1 << 2,                 0,                        -1 },
	{ "jetbrains-idea",           	 NULL,                 	NULL,           1 << 2,                 0,                        -1 },
	{ "jetbrains-webstorm",       	 NULL,                 	NULL,           1 << 2,                 0,                        -1 },
	{ "jetbrains-pycharm",       	 NULL,                 	NULL,           1 << 2,                 0,                        -1 },
	{ "jetbrains-studio",        	 NULL,                 	NULL,           1 << 2,                 0,                        -1 },
	{ "Signal", 	       		 NULL,                 	NULL,           1 << 5,                 0,                         -1 },
	{ "Whatsapp-for-linux", 	 NULL,                 	NULL,           1 << 5,                 0,                         -1 },
	{ "discord", 	 		 NULL,                 	NULL,           1 << 5,                 0,                         -1 },
	{ "zoom", 	 		 NULL,                 	NULL,           1 << 6,                 0,                        -1 },
	{ "teams-for-linux", 	 NULL,                 	NULL,           1 << 6,                 0,                        -1 },
	{ "Pavucontrol",	 	 NULL,                 	NULL,           0,   	  	        1,                        -1 },
	{ NULL,		  		"spterm",		NULL,		SPTAG(0),		1,			  -1 },
	{ NULL,		  		"spfm",			NULL,		SPTAG(1),		1,			  -1 },
	{ NULL,		  		"keepassxc",		NULL,		SPTAG(2),		0,			  -1 },
};

/*========== Layout(s) ========== */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "###",      nrowgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/*========== Key definitions ===========*/
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask,              KEY,      tagnextmon,     {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask|ShiftMask,    KEY,      tagprevmon,     {.ui = 1 << TAG} },

#define CMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/*========== Commands ==========*/
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };


#include "movestack.c"
#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier                     key        function             argument */
	{ Mod1Mask,                     65,  spawn,               CMD("rofi -show drun") },
	{ MODKEY,  	 	                36, spawn,               {.v = termcmd } },
	{ MODKEY,                       56,      togglebar,           {0} },
	{ MODKEY,                       44,      focusstack,          {.i = +1 } },
	{ MODKEY,                       45,      focusstack,          {.i = -1 } },
	{ MODKEY,                       111,     incnmaster,          {.i = +1 } },
	{ MODKEY,                       116,   incnmaster,          {.i = -1 } },
	{ MODKEY,                       43,      setmfact,            {.f = -0.05} },
	{ MODKEY,                       46,      setmfact,            {.f = +0.05} },
	{ MODKEY|ShiftMask,             44,      movestack,           {.i = +1 } },
	{ MODKEY|ShiftMask,             45,      movestack,           {.i = -1 } },
	{ MODKEY|ShiftMask,             36, zoom,                {0} },
	{ MODKEY,                       23,    view,                {0} },
	{ MODKEY,     	        	    24,      killclient,          {0} },

	/* Layout manipulation */
	{ MODKEY|ControlMask,		59,  cyclelayout,         {.i = -1 } },
	{ MODKEY|ControlMask,           60, cyclelayout,         {.i = +1 } },

	/* Switch to specific layouts */
	{ MODKEY,                       58,      setlayout,           {.v = &layouts[0]} },
	{ MODKEY,             		41,      fullscreen,          {1} },
	{ MODKEY,                       65,  setlayout,           {0} },
	{ MODKEY|ShiftMask,             65,  togglefloating,      {0} },
	{ MODKEY,                       19,      view,                {.ui = ~0 } },
	{ MODKEY|ShiftMask,             19,      tag,                 {.ui = ~0 } },

	/* switching between monitors */
	{ MODKEY,                       59,  focusmon,            {.i = -1 } },
	{ MODKEY,                       60, focusmon,            {.i = +1 } },
	{ MODKEY|ControlMask,           113,   tagmon,              {.i = -1 } },
	{ MODKEY|ControlMask,           114,  tagmon,              {.i = +1 } },

	/* Gaps */
	{ MODKEY,                       52,      incrgaps,       	{.i = +5 } },
	{ MODKEY|ShiftMask,             52,      incrgaps,       	{.i = -5 } },
	{ MODKEY|ControlMask,           52,      togglegaps,     	{0} },
	{ MODKEY|Mod1Mask,    		52,      defaultgaps,    	{0} },

	/* Scratchpads */
	{ MODKEY,      			33,  	   togglescratch,  	{.ui = 0 } },
	{ MODKEY,                       61, scratchpad_show, 	{0} },
	{ MODKEY|ShiftMask,             61, scratchpad_hide, 	{0} },
	//{ MODKEY,                       ,scratchpad_remove,	{0} },

	/* Tags */    
	TAGKEYS(                        10,                      	0)
	TAGKEYS(                        11,                      	1)
	TAGKEYS(                        12,                      	2)
	TAGKEYS(                        13,                      	3)
	TAGKEYS(                        14,                      	4)
	TAGKEYS(                        15,                      	5)
	TAGKEYS(                        16,                      	6)
	TAGKEYS(                        17,                      	7)
	TAGKEYS(                        18,                     	8)
	{ MODKEY,             		22,	spawn,         CMD("rofi -show p -modi p:~/.local/bin/rofi-power-menu -width 20 -lines 5") },
	{ MODKEY|ShiftMask,             22,	quit,          {0} },
	{ MODKEY|ShiftMask, 		27,      	quit,          {1} },

	/* Apps */
	{ MODKEY,  	 	        54, 	  spawn,               CMD("brave") },
	{ MODKEY,  	 	        53, 	  spawn,               CMD("st -e 'ranger'") },
	{ MODKEY,  	 	        26, 	  spawn,               CMD("thunar") },
	{ MODKEY|ControlMask,  	 	        XK_l, 	  spawn,               CMD("multilockscreen -l dimblur") },
//{ MODKEY|ShiftMask,  	 	XK_c, 	  spawn,               CMD("signal-desktop; whatsapp-for-linux; discord") },
	{ MODKEY|ShiftMask,  	 	54, 	  spawn,               CMD("~/.local/bin/communications.sh") },
	{ MODKEY|ShiftMask,  	 	28, 	  spawn,               CMD("pkill picom") },
	{ MODKEY|ControlMask,  	 	28, 	  spawn,               CMD("picom -b") },
	{ MODKEY|ControlMask,  	 	58, 	  spawn,               CMD("pavucontrol") },
	{ MODKEY|ShiftMask,  	 	58, 	  spawn,               CMD("mailspring") },
	{ MODKEY|ShiftMask,  	 	39, 	  spawn,               CMD("flameshot gui") },
	{ MODKEY|ControlMask,  	 	26, 	  spawn,               CMD("~/.local/bin/enkeys") },
	{ MODKEY|ControlMask,  	 	40, 	  spawn,               CMD("~/.local/bin/dekeys") },

	/* Media */
	{ 0	,			114, spawn, CMD("ponymix decrease 5") },
	{ 0	,			115, spawn, CMD("ponymix increase 5") },
	{ 0	,			113, spawn, CMD("ponymix toggle") },

    /* Brightness */
	{ 0	,			225, spawn, CMD("xbacklight -inc 10; notify-send 'brightness up'") },
	{ 0	,			224, spawn, CMD("xbacklight -dec 10; notify-send 'brightness down'") },

};

/*========== Button definitions ==========*/
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button1,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
