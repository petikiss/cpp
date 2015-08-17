#!/usr/bin/perl

use warnings;
use strict;

# ---------------------------------------------------------------------------- #
# This scrip analyze the given (lgov generated) index.html and checks if the
# line coverage reaches a limit
#
# Usage:
#   coverage_check.pl <expected coverage percentage> <index.html to analyze>
# ---------------------------------------------------------------------------- #

my $min_cov = shift;

# <td class="headerCovTableEntryHi">93.6 %</td>

while (<>) {
    if ( my ($cov) = /<td class="headerCovTableEntry\S+">(\d*\.\d*) %<\/td>/ ) {
        open(COV, ">coverage.xml") || die $@;
        if ($cov < $min_cov) {
            print STDERR "\nThis coverage is not enough Dude: $cov%\n\n";

            print COV "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>
<testsuite errors=\"0\" failures=\"1\" tests=\"1\" name=\"coverage\">
  <testcase classname=\"coverage\" name=\"coverage($cov)\" time=\"0\">
    <error message=\"This coverage is not enough Dude: $cov%\" type=\"CoverageFailure\">
      This coverage is not enough Dude: $cov%, expected: $min_cov%
    </error>
  </testcase>
</testsuite>";
            close(COV);
            exit(1);
        }
        else {
            print STDERR "\nOK Dude, you have enough test cases, your coverage is: $cov%\n\n";

            print COV "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>
<testsuite errors=\"0\" failures=\"0\" tests=\"1\" name=\"coverage\">
  <testcase classname=\"coverage\" name=\"coverage($cov)\" time=\"0\" />
</testsuite>";
            close(COV);
            exit(0)
        }
    }
}

