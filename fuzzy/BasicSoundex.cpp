/*
**	  SOUNDEX CODING
**
**	  Rules:
**	  1.	  Retain the first letter; ignore non-alphabetic characters.
**	  2.	  Replace second and subsequent characters by a group code.
**			  Group   Letters
**			  1			   BFPV
**			  2			   CGJKSXZ
**			  3			   DT
**			  4			   L
**			  5			   MN
**			  6			   R
**	  3.	  Do not repeat digits
**	  4.	  Truncate or ser-pad to 4-character result.
**
**	  Originally formatted with tabstops set at 4 spaces -- you were warned!
**
**	  Code by: Jonathan Leffler (john@sphinx.co.uk)
**	  This code is shareware -- I wrote it; you can have it for free
**	  if you supply it to anyone else who wants it for free.**
**	  BUGS: Assumes ASCII
*/

#include <string>
#include <iterator>

#include "BasicSoundex.h"
#include "functions.h"

namespace JLeffler
{

using namespace std;

/*

  Old lookup. Doesn't deal with accented characters

static char	lookup[] =
{
	'0',	// A
	'1',	// B
	'2',	// C
	'3',	// D
	'0',	// E
	'1',	// F
	'2',	// G
	'0',	// H
	'0',	// I
	'2',	// J
	'2',	// K
	'4',	// L
	'5',	// M
	'5',	// N
	'0',	// O
	'1',	// P
	'0',	// Q
	'6',	// R
	'2',	// S
	'3',	// T
	'0',	// U
	'1',	// V
	'0',	// W
	'2',	// X
	'0',	// Y
	'2',	// Z
};
*/

/*
	New lookup. Deals with accented vowels, and does lookups for the
	whole fucking character set.

	Maybe there's something in <locale> that does something
	like this?
*/
static char	lookup[] =
{
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',		  /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /**/
	'0',        /* */    // 32
	'0',        /*!*/
	'0',        /*"*/
	'0',        /*#*/
	'0',        /*$*/
	'0',        /*%*/
	'0',        /*&*/
	'0',        /*'*/
	'0',        /*(*/
	'0',        /*)*/
	'0',        /***/
	'0',        /*+*/
	'0',        /*,*/
	'0',        /*-*/
	'0',        /*.*/
	'0',        /*/*/
	'0',        /*0*/
	'0',        /*1*/
	'0',        /*2*/
	'0',        /*3*/
	'0',        /*4*/
	'0',        /*5*/
	'0',        /*6*/
	'0',        /*7*/
	'0',        /*8*/
	'0',        /*9*/
	'0',        /*:*/
	'0',        /*;*/
	'0',        /*<*/
	'0',        /*=*/
	'0',        /*>*/
	'0',        /*?*/
	'0',        /*@*/
	'0',	/* A */
	'1',	/* B */
	'2',	/* C */
	'3',	/* D */
	'0',	/* E */
	'1',	/* F */
	'2',	/* G */
	'0',	/* H */
	'0',	/* I */
	'2',	/* J */
	'2',	/* K */
	'4',	/* L */
	'5',	/* M */
	'5',	/* N */
	'0',	/* O */
	'1',	/* P */
	'0',	/* Q */
	'6',	/* R */
	'2',	/* S */
	'3',	/* T */
	'0',	/* U */
	'1',	/* V */
	'0',	/* W */
	'2',	/* X */
	'0',	/* Y */
	'2',	/* Z */
	'0',        /*[*/
	'0',        /*\*/
	'0',        /*]*/
	'0',        /*^*/
	'0',        /*_*/
	'0',        /*`*/
	'0',	/* a */
	'1',	/* b */
	'2',	/* c */
	'3',	/* d */
	'0',	/* e */
	'1',	/* f */
	'2',	/* g */
	'0',	/* h */
	'0',	/* i */
	'2',	/* j */
	'2',	/* k */
	'4',	/* l */
	'5',	/* m */
	'5',	/* n */
	'0',	/* o */
	'1',	/* p */
	'0',	/* q */
	'6',	/* r */
	'2',	/* s */
	'3',	/* t */
	'0',	/* u */
	'1',	/* v */
	'0',	/* w */
	'2',	/* x */
	'0',	/* y */
	'2',	/* z */
   '0',        /*{*/
   '0',        /*|*/
   '0',        /*}*/
   '0',        /*~*/
   '0',        /**/
   '0',        /*Ä*/
   '0',        /*Å*/
   '0',        /*Ç*/
   '0',        /*É*/
   '0',        /*Ñ*/
   '0',        /*Ö*/
   '0',        /*Ü*/
   '0',        /*á*/
   '0',        /*à*/
   '0',        /*â*/
   '0',        /*ä*/
   '0',        /*ã*/
   '0',        /*å*/
   '0',        /*ç*/
   '0',        /*é*/
   '0',        /*è*/
   '0',        /*ê*/
   '0',        /*ë*/
   '0',        /*í*/
   '0',        /*ì*/
   '0',        /*î*/
   '0',        /*ï*/
   '0',        /*ñ*/
   '0',        /*ó*/
   '0',        /*ò*/
   '0',        /*ô*/
   '0',        /*ö*/
   '0',        /*õ*/
   '0',        /*ú*/
   '0',        /*ù*/
   '0',        /*û*/
   '0',        /*ü*/
   '0',        /*†*/
   '0',        /*°*/
   '0',        /*¢*/
   '0',        /*£*/
   '0',        /*§*/
   '0',        /*•*/
   '0',        /*¶*/
   '0',        /*ß*/
   '0',        /*®*/
   '0',        /*©*/
   '0',        /*™*/
   '0',        /*´*/
   '0',        /*¨*/
   '0',        /*≠*/
   '0',        /*Æ*/
   '0',        /*Ø*/
   '0',        /*∞*/
   '0',        /*±*/
   '0',        /*≤*/
   '0',        /*≥*/
   '0',        /*¥*/
   '0',        /*µ*/
   '0',        /*∂*/
   '0',        /*∑*/
   '0',        /*∏*/
   '0',        /*π*/
   '0',        /*∫*/
   '0',        /*ª*/
   '0',        /*º*/
   '0',        /*Ω*/
   '0',        /*æ*/
   '0',        /*ø*/
   '0',        /*¿*/
   '0',        /*¡*/
   '0',        /*¬*/
   '0',        /*√*/
   '0',        /*ƒ*/
   '0',        /*≈*/
   '0',        /*∆*/
   '2',        /*«*/
   '0',        /*»*/
   '0',        /*…*/
   '0',        /* */
   '0',        /*À*/
   '0',        /*Ã*/
   '0',        /*Õ*/
   '0',        /*Œ*/
   '0',        /*œ*/
   '3',        /*–*/
   '5',        /*—*/
   '0',        /*“*/
   '0',        /*”*/
   '0',        /*‘*/
   '0',        /*’*/
   '0',        /*÷*/
   '2',        /*◊*/
   '0',        /*ÿ*/
   '0',        /*Ÿ*/
   '0',        /*⁄*/
   '0',        /*€*/
   '0',        /*‹*/
   '0',        /*›*/
   '1',        /*ﬁ*/
   '2',        // ﬂ - sounds like ss in german
   '0',        /*‡*/
   '0',        /*·*/
   '0',        /*‚*/
   '0',        /*„*/
   '0',        /*‰*/
   '0',        /*Â*/
   '0',        /*Ê*/
   '2',        /*Á*/
   '0',        /*Ë*/
   '0',        /*È*/
   '0',        /*Í*/
   '0',        /*Î*/
   '0',        /*Ï*/
   '0',        /*Ì*/
   '0',        /*Ó*/
   '0',        /*Ô*/
   '0',        /**/
   '5',        /*Ò*/
   '0',        /*Ú*/
   '0',        /*Û*/
   '0',        /*Ù*/
   '0',        /*ı*/
   '0',        /*ˆ*/
   '0',        /*˜*/
   '0',        /*¯*/
   '0',        /*˘*/
   '0',        /*˙*/
   '0',        /*˚*/
   '0',        /*¸*/
   '0',        /*˝*/
   '3',        /*˛*/
   '0',        /*ˇ*/
}; // end of lookup

/**
	Soundex for arbitrary number of characters of information
*/
string nsoundex ( const string & str, int n )
{
	string retval;
	string::const_iterator s = str.begin();
	insert_iterator<string> t ( retval, retval.end() );

	// this assumes that we're only dealing with alphanumeric characters
	char last = ' ';
	while ( retval.length() < n )
	{
		// pad with 0's
		if ( s == str.end() )
		{
			*t++ = '0';
		}
		else
		{
			char c = *s;
			if ( s == str.begin() )
			{
				*t++ = std::toupper ( (int)c );
			}
			else
			{
				// the cast is to make sure characters > 127
				// still work..
				c = lookup[(unsigned char)c];

				// ignore irrelevant characters and duplicates
				if (c != '0' && c != last )
					*t++ = c;
			}
			last = c;
			++s;
		}
	}

	return retval;
}

/* Normal external interface */
string soundex ( const string & str)
{
	return ( nsoundex ( str, 4 ) );
}

/*
**	  Alternative interface:
**	  void	soundex(given, gets)
**	  char	*given;
**	  char	*gets;
**	  {
**			  strcpy(gets, nsoundex(given, 4));
**	  }
*/


/*
#ifdef TEST
#include <stdio.h> main()
{
		char	buff[30];

		while (fgets(buff, sizeof(buff), stdin) != (char *)0)
				printf("Given: %s Soundex produces %s\n", buff, soundex(buff));
}
}
*/

} // end of JLeffler namespace