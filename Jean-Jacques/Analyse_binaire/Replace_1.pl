#!/usr/bin/perl
use strict;
use warnings;

BEGIN {undef $/;}



while (<>) 
{
	s/\s+\\begin{center}\s+\\medskip\s+\\end{center}\s+/\n\\medskip\n/smg;
	s/\s+\\medskip\s+/\n\\medskip\n/;
	print $_ ; 
}
