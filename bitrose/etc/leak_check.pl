#!/usr/bin/env perl

use strict;
use warnings;

my $leaks  = 0;
my $errors = 0;
my $invalidRead = 0;
my $invalidWrite = 0;
my $invalidFree = 0;

while (<>) {
    if (/definitely lost: ([0-9,]+) bytes in ([0-9]+) blocks/) { $leaks = $2; }
    if (/ERROR SUMMARY: (\d+) errors from (\d+) contexts/)  { $errors = $2;}
    if (/Invalid read/ ) { ++$invalidRead;  }
    if (/Invalid write/) { ++$invalidWrite; }
    if (/Invalid free/ ) { ++$invalidFree;  }
}

print("\n");
if ($leaks)  { print(sprintf("You have some leaks Dude at %d places  :/\n", $leaks)); }
if ($errors) { print(sprintf("\nYou have some memory corruptions Darling at %d places  :/\n", $errors)); }
if ($invalidRead ) { print(sprintf("  %d invalid read\n", $invalidRead)); }
if ($invalidWrite) { print(sprintf("  %d invalid write\n", $invalidWrite)); }
if ($invalidFree ) { print(sprintf("  %d invalid free\n", $invalidFree)); }

if (0 == $leaks && 0 == $errors) {
    my $title;
    if (`id -un` eq 'magos') { $title = "Queen" } else { $title = "King"; }
    print(sprintf("\nValgrind result is cool. You seem to be the %s of memory handling.\n\n", $title));
}

print("\n");
if ($leaks || $invalidRead || $invalidWrite || $invalidFree) { exit(1); }

