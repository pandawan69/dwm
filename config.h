/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 20;        /* gaps between windows */
static const unsigned int snap      = 5;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Fira Code:style=Medium:pixelsize=12:autohint=true",
					"Font Awesome 5 Free Solid:style=Solid:pixelsize=12",
       				       	"Font Awesome 5 Brands Regular:style=Regular:pixelsize=12",
				      };

/*Nord theme*/
/*
static const char norm_fg[]      = "#D8DEE9";
static const char norm_bg[]      = "#2E3440";
static const char norm_border[]  = "#D8DEE9";

static const char sel_fg[]       = "#2E3440";
static const char sel_bg[]       = "#D8DEE9";
static const char sel_border[]   = "#D8DEE9";

static const char *colors[][3]      = {
	//               fg         bg         border   
	[SchemeNorm] = { norm_fg, norm_bg, norm_bg },
	[SchemeSel]  = { sel_fg, sel_bg,  sel_border },
	[SchemeTitle] = { norm_fg, norm_bg, norm_border },
};
*/

/*gruvbox theme*/
#define dark "#1D2021"
#define light "#FBF1C7"

static const char norm_fg[]      = light;
static const char norm_bg[]      = dark;
static const char norm_border[]  = dark;

static const char sel_fg[]       = dark;
static const char sel_bg[]       = light;
static const char sel_border[]   = light;

static const char *colors[][3]      = {
	//               fg         bg         border   
	[SchemeNorm] = { norm_fg, norm_bg, norm_bg },
	[SchemeSel]  = { sel_fg, sel_bg,  sel_border },
	[SchemeTitle] = { norm_fg, norm_bg, norm_border },
};


/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Float",     NULL,       NULL,       1 << 8,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int attachbelow = 1;    /* 1 means attach after the currently active window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
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
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon};
static const char *termcmd[]  = { "st", NULL };

/* audio commands */
#define volup "amixer sset 'Master' 5%+ && pkill -RTMIN+10 dwmblocks"
#define voldown "amixer sset 'Master' 5%- && pkill -RTMIN+10 dwmblocks"

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,            	 	        XK_q,      killclient,     {0} },
	/* Launch programs with Super + Shift + Key */
	{ MODKEY|ShiftMask,    	        XK_c,      spawn,     	   SHCMD("code") },
	{ MODKEY|ShiftMask,             XK_o,      spawn,     	   SHCMD("obsidian") } ,
	{ MODKEY|ShiftMask,             XK_w,      spawn,     	   SHCMD("$BROWSER") },
	{ MODKEY|ShiftMask,             XK_z,      spawn,     	   SHCMD("zathura") } ,
	{ MODKEY|ShiftMask,             XK_r,      spawn,     	   SHCMD("st -e ranger") } ,
	{ MODKEY|ShiftMask,             XK_v,      spawn,     	   SHCMD("st -e nvim") } ,
	/* Volume */
	{ MODKEY|ShiftMask,             XK_equal,  spawn,     	   SHCMD(volup) },
	{ MODKEY|ShiftMask,             XK_minus,  spawn,          SHCMD(voldown) },
	/* Layout */
	{ MODKEY,                       XK_space,  cyclelayout,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	/* Gaps */
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +5 } },
	/* Monitors */
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	/* Tagkeys */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,		XK_q,      quit,           {1} },
	{ MODKEY|Mod1Mask,             	XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

