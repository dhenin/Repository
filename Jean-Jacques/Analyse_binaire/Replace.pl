#!/usr/bin/perl
use strict;
use warnings;

BEGIN {undef $/;}



while (<>) 
{
	s/\s+\\medskip\s+/\n\\medskip\n/;
	print $_ ; 
}
