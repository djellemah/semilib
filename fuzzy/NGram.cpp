#include "NGram.h"

#include <algorithm>

using namespace std;

pair<int,int> NGram::doMatch ( const string & b, const string & a )
{
	int	count = 0;
	int MaxMatch = 0;
	string::const_iterator beginNgram = a.begin();
	string::const_iterator endNgram = beginNgram + length;

	// Make n-grams from search string and look for these in target
	for(; endNgram <= a.end(); ++beginNgram, ++endNgram )
	{
		string temp ( beginNgram, endNgram );
//		MaxMatch += length;
		// number of potential matches should be incremented
		// once per iteration
		++MaxMatch;

		// search for the ngram in the string, using iterators
		if ( b.end() != search ( b.begin(), b.end(), beginNgram, endNgram ) )
			count++;
	}
	// weight according to n-Gram length
	// ie number of n-grams actually matched * n-gram length
	// and the total number of possible n-gram matches in the string
//	return make_pair ( count * length, MaxMatch );
	return make_pair ( count, MaxMatch );
}
