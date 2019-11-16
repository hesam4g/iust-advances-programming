#// *****************************************
#//        cplusplus language tutorial
#//                section 3.2
#//
#//            "The Secret Word"
#// Shows:
#//   - strings
#//   - arrays of strings
#//   - cstring functions: strcpy and strlen
#//
#// Briefing:
#//  The user has to discover all the letters
#//  in a secret keyword.
#//  Each letter said that is in the keyword
#//  is shown in its rightful location.
#//  He/She has the opportunity to fail up
#//  to FAILS_ALLOWED times.
#// *****************************************

															#include <iostream.h>
from random import *										#include <stdlib.h>
															#include <time.h>
															#include <string.h>

N_KEYS = 12													#define N_KEYS 12
KEY_MAX_WIDTH = 20											#define KEY_MAX_WIDTH 20
FAILS_ALLOWED = 7											#define FAILS_ALLOWED 7


#// Possible keywords. You may inser new ones if you increase N_KEYS.
#char possiblekeys [N_KEYS][KEY_MAX_WIDTH] = {
#	"mushroom", "pineapple", "neighborhood", "citizen",
#	"programming", "darkness", "fundamental", "encyclopedia",
#	"businessman", "restaurant", "observatory", "civilization"
#};
possiblekeys = ["mushroom", "pineapple", "neighborhood", "citizen",
				"programming", "darkness", "fundamental", "encyclopedia", 
				"businessman", "restaurant", "observatory", "civilization"]

#// This will store the key
key = ""													#char key [KEY_MAX_WIDTH];

#// This will store the string shown on screen with letters already discovered.
outstring = ""												#char outstring [KEY_MAX_WIDTH];

#int CheckLetter (char letter);
#// Function that checks if letter is in key.
#// returns the number of times the letter was found in key
def CheckLetter (letter):										#int CheckLetter (char letter)
																#{
	n = 0														#	unsigned int n;
	found=0;													#	int found=0;
	global outstring
	for n in range(0, len(key)):								#	for (n=0; n<strlen(key); n++)
		if (key[n]==letter and outstring[n]=='-'):				#		if (key[n]==letter && outstring[n]=='-')
																#		{
			found += 1											#			found++;
			outstring =outstring[0:n]+key[n]+outstring[n+1:]	#			outstring[n]=key[n];
																#		}
	return found												#	return found;
																#}
																
def main ():													#int main()
																#{
	#input = ''													#	char input;
	valid = 0													#	int valid;
	fails = FAILS_ALLOWED										#	int fails = FAILS_ALLOWED;
	discovered = 0												#	unsigned int discovered = 0;
	n = 0														#	unsigned int n;

  # Select a key.
																#	srand ( time (NULL) );            // Initialize random number generator
	value = randint(0,N_KEYS)									#	int value = rand()%N_KEYS; // Get random between 0 and NKEYS-1
	global outstring
	global key
	key = possiblekeys[value]									#	strcpy (key,possiblekeys[value]); // Copy key
  #// Set outstring to '-' characters plus terminating null-character
	for n in range(0, len(key)):								#	for (n=0; n<strlen(key); n++)
		outstring = outstring + '-'								#		outstring[n]='-';
																#	outstring[n]='\0';
																
	while True:													#	do {
		#// Prompt user
		print "\nDiscover the secret key: " , outstring			#		cout << "\nDiscover the secret key: " << outstring << "\n";
																#		cout << "Enter a letter (You may fail " << fails << " times): ";
																#		cin >> input; cin.ignore (100,'\n');
		input = raw_input("Enter a letter (You may fail " + str(fails) + " times): ")

		#// check if letter is valid
		valid = CheckLetter (input)								#		valid = CheckLetter (input);

		#// if it is valid, increase discovered letters counter.
		#// if not, decrease allowed fails
		if valid != 0:											#		if (valid!=0)
			discovered += valid									#			discovered+=valid;
		else:													#		else 
			fails -= 1											#			fails--;
		
		if not (discovered < len(key) and fails>0):				#	} while (discovered < strlen(key) && fails>0);
			break	# The loop ends if key is discovered or fails are exhausted.

  # Display CORRECT! only if key was discovered.
	if discovered == len(key):									#	if (discoverd == strlen(key))
		print "CORRECT! "										#		cout << "CORRECT! ";
	print "Key was '" , key , "'.\n"							#	cout "Key was '" << key <<"'.\n";
	return 0													#	return 0;
																#}
																
main()
