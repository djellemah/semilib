#include <ctype.h>

char stripThings ( char aChar )
{
	char retval = tolower(aChar);
	// Removing punctuation
	if (retval < '0')
		retval = ' ';
	else
		switch(retval)
		{
			case 196: retval = (char)228; break; /* ANSI-Umlaute	*/
			case 214: retval = (char)246; break;
			case 220: retval = (char)252; break;
			case 142: retval = (char)132; break; /* ASCII-Umlaute */
			case 153: retval = (char)148; break;
			case 154: retval = (char)129; break;
			case ':': retval = ' '; break;
			case ';': retval = ' '; break;
			case '<': retval = ' '; break;
			case '>': retval = ' '; break;
			case '=': retval = ' '; break;
			case '?': retval = ' '; break;
			case '[': retval = ' '; break;
			case ']': retval = ' '; break;
		}
	return retval;
}

