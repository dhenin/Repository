#!/usr/bin/perl
use strict;
use warnings;

BEGIN {undef $/;}



while (<>) 
{
       s#\\subsection{\([^}]*\)}#<h4>\1</h4>#   
	s#\\section{\([^}]*\)}#<h3>\1</h3>#    
	%s#\\og#« #g
	%s#\\fg# »#g    
	%s#textsl#emph#g
#	s/\s+\\begin{center}\s+\\medskip\s+\\end{center}\s+/\n\\medskip\n/smg;
#	s/\s+\\medskip\s+/\n\\medskip\n/;
	print $_ ; 
}
