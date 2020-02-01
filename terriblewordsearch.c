//2014 C. Lohr - I hereby place the following code into the public domain.
//You can use it for whatever you want or modify it however you want.
//It's probably riddled with bugs, so I can't promise it'll work for anything.
//Read more: http://cnlohr.blogspot.com/2014/02/to-make-terrible-wordsearches.html

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char * board;
const char * word;
const char * letters;
int letterslen;
int wordlen;
int w, h;
int hits = 0;

int CheckPlace( int x, int y )
{
	int i;

	if( x < 0 || y < 0 || x>=w || y >= h ) return 0;

	//check up.
	for( i = 0; i < wordlen; i++ )
	{
		if( y-i < 0 ) break;
		char c = board[x+(y-i)*w];
		if( c != word[i] ) break;
	}
	if( i == wordlen ) return 1;

	//Check up (reversed)
	for( i = 0; i < wordlen; i++ )
	{
		if( y-i < 0 ) break;
		char c = board[x+(y-i)*w];
		if( c != word[wordlen-i-1] ) break;
	}
	if( i == wordlen ) return 1;

	//check left.
	for( i = 0; i < wordlen; i++ )
	{
		if( x-i < 0 ) break;
		char c = board[(x-i)+y*w];
		if( c != word[i] ) break;
	}
	if( i == wordlen ) return 1;

	//check left (Reversed)
	for( i = 0; i < wordlen; i++ )
	{
		if( x-i < 0 ) break;
		char c = board[(x-i)+y*w];
		if( c != word[wordlen-i-1] ) break;
	}
	if( i == wordlen ) return 1;

	//check down.
	for( i = 0; i < wordlen; i++ )
	{
		if( y+i >= h ) break;
		char c = board[x+(y+i)*w];
		if( c != word[i] ) break;
	}
	if( i == wordlen ) return 1;

	//check right.
	for( i = 0; i < wordlen; i++ )
	{
		if( x+i >= w ) break;
		char c = board[(x+i)+y*w];
		if( c != word[i] ) break;
	}
	if( i == wordlen ) return 1;

	//check upleft.
	for( i = 0; i < wordlen; i++ )
	{
		if( x-i < 0 ) break;
		if( y-i < 0 ) break;
		char c = board[(x-i)+(y-i)*w];
		if( c != word[i] ) break;
	}
	if( i == wordlen ) return 1;

	//check upleft. (reversed)
	for( i = 0; i < wordlen; i++ )
	{
		if( x-i < 0 ) break;
		if( y-i < 0 ) break;
		char c = board[(x-i)+(y-i)*w];
		if( c != word[wordlen-i-1] ) break;
	}
	if( i == wordlen ) return 1;

	//check upright.
	for( i = 0; i < wordlen; i++ )
	{
		if( x+i >= w ) break;
		if( y-i < 0 ) break;
		char c = board[(x+i)+(y-i)*w];
		if( c != word[i] ) break;
	}
	if( i == wordlen ) return 1;

	//Check upright (reversed)
	for( i = 0; i < wordlen; i++ )
	{
		if( x+i >= w ) break;
		if( y-i < 0 ) break;
		char c = board[(x+i)+(y-i)*w];
		if( c != word[wordlen-i-1] ) break;
	}
	if( i == wordlen ) return 1;


	//check downleft.
	for( i = 0; i < wordlen; i++ )
	{
		if( x-i < 0 ) break;
		if( y+i >= h ) break;
		char c = board[(x-i)+(y+i)*w];
		if( c != word[i] ) break;
	}
	if( i == wordlen ) return 1;


	//check downright.
	for( i = 0; i < wordlen; i++ )
	{
		if( x+i >= w ) break;
		if( y+i >= h ) break;
		char c = board[(x+i)+(y+i)*w];
		if( c != word[i] ) break;
	}

	if( i == wordlen ) return 1;


	return 0;
}

int main( int argc, char ** argv )
{
	int x, y;
	int i = 0;

	if( argc < 5 )
	{
		fprintf( stderr, "Error: usage:  ./wordsearch [x] [y] [word] [letters]\n" );
		return -1;
	}

	w = atoi( argv[1] );
	h = atoi( argv[2] );
	word = argv[3];
	letters = argv[4];
	wordlen = strlen( word );
	letterslen = strlen( letters );
	board = malloc( w * h );
	memset( board, 0, w * h );

	for( i = 0; i < w*h; i++ )
	{
		x = i % w;
		y = i / w;

		board[i] = letters[rand()%letterslen];

		if( CheckPlace( x, y ) )
		{
			//Fail -- backup.
			board[i] = 0;
			int backtrack = rand()%100;
			float backt = pow((float)backtrack/80.0, 9.0f);
			i-=(int)backt+1;
			if( i < 0 ) i = 0;
			hits++;
			continue;
		}
	}

	printf( "HITS: %d\n", hits );

	for( y = 0; y < h; y++ )
	{
		for( x = 0; x < w; x++ )
		{
			printf( "%c ", board[x+y*w] );
		}
		printf( "\n" );
	}

	return 0;
}
