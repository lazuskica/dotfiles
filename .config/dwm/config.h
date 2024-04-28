/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int gappx     = 4;        /* gaps between windows */
static const unsigned int snap      = 16;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int vertpad            = 4;       /* vertical padding of bar */
static const int sidepad           = 160;       /* horizontal padding of bar */
static const int user_bh            = 6;        /* 2 is the default spacing around the bar's font */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 6;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray             = 1;   /* 0 means no systray */
static const char *fonts[]          = { "BitstromWera Nerd Font:size=11" };
static const char dmenufont[]       = "BitstromWera Nerd Font:size=11";
static const char dmenu_w[]	= "152";
static const char dmenu_y[]	= "4";
static const char dmenu_x[]	= "4";
static const char col_2[]       = "#202020";
static const char col_1[]       = "#e0e0e0";
static const unsigned int baralpha = 0xcf;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeSel]  = { col_1, col_2, col_1 },
	[SchemeNorm] = { col_2, col_1, col_2 },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class              instance	title	tags mask     isfloating  	monitor */
	{ "Chromium",		NULL,	NULL,	1 << 0,		0,           	-1 },
	{ "Brave",		NULL,   NULL,	1 << 0,		0,           	-1 },
	{ "Clementine",		NULL,   NULL,	1 << 7,		0,           	-1 },
	{ "qBittorrent",	NULL,	NULL,	1 << 8,		0,	     	-1 },
	{ "Gimp",		NULL,	NULL,	1 << 1,		0,	     	-1 },
	{ "STM32CubeIDE",	NULL,	NULL,	1 << 1,		0,		-1 },
	{ "Stm32cubeide",	NULL,	NULL,	1 << 1,		0,		-1 },
	{ "Qalculate",		NULL,	NULL,	NULL,		1,		-1 },
};

/* layout(s) */
static const float mfact     = 0.64; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "T",      tile },    /* first entry is default */
	{ "F",      NULL },    /* no layout function means floating behavior */
	{ "M",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-x", dmenu_x, "-z", dmenu_w, "-y", dmenu_y, "-m", dmenumon, NULL };
static const char *termcmd[]  = { "st", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.04} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.04} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,	                XK_space,  togglefloating, {0} },
//	sledeca 4 su za multimonitor
	{ MODKEY,                       XK_Left,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_Right, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Left,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Right, tagmon,         {.i = +1 } },
	{ ShiftMask,			XK_Alt_L, spawn,	   SHCMD("pkill -RTMIN+11 dwmblocks") },
	{ MODKEY,			XK_minus,   	spawn,	   SHCMD("pamixer -d 4 | pkill -RTMIN+10 dwmblocks") },
	{ MODKEY,			XK_equal,   	spawn,	   SHCMD("pamixer -i 4 | pkill -RTMIN+10 dwmblocks") },
	{ MODKEY,			XK_0,   	spawn,	   SHCMD("pamixer -t | pkill -RTMIN+10 dwmblocks") },
	//{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	//{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	//{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
 	TAGKEYS(                        XK_2,                      1)
 	TAGKEYS(                        XK_3,                      2)
 	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
 	TAGKEYS(                        XK_6,                      5)
 	TAGKEYS(                        XK_7,                      6)
 	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(			XK_9,			   8)
	{ MODKEY|ShiftMask,             XK_Escape,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
};

