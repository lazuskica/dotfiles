/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 0;                      /* -b  option; if 0, dmenu appears at bottom     */
static const unsigned int alpha = 0xcf;     /* Amount of opacity. 0xff is opaque             */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"BitstromWera Nerd Font:size=11"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
char c2[8] = "#202020";
char c1[8] = "#e0e0e0";
static const char *colors[SchemeLast][2] = {
	/*		    	fg	bg    */
	[SchemeNorm] = { 	c1, 	c2 },
	[SchemeSel]  = { 	c2, 	c1 },
	[SchemeOut]  = { 	c2, 	c1 },
};

static const unsigned int alphas[SchemeLast][2] = {
	[SchemeNorm] = { OPAQUE, alpha },
	[SchemeSel] = { OPAQUE, alpha },
	[SchemeOut] = { OPAQUE, alpha },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 12;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static unsigned int border_width = 2;
