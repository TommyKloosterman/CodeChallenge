# CodeChallenge
1. i wanted to code this in c++ so i decided to include the following libraries and namespaces to make it easier to code: 

#include <iostream> <- this handles input/output which is important because i want to use the terminal for this code
#include <string> <- this handles strings which is important because roman numerals are in fact strings
#include <map> <- this handles maps which are c++'s associative arrays, and they are important because i want to use them to associate letters for roman numerals to certain numbers
and
using namespace std <- The std namespace is where all the functions and classes defined in these libraries are defined, so it's important to include this statement to avoid naming conflicts with functions or classes defined in other namespaces.

2. next i wanted to create the method romanToNum which would take in roman numerals (a string labeled s) and return their corresponding number value

first i created a map object called roman_map with the roman numerals I through M and their corresponding numbers 1 through 1000

then i used a simple for loop that would go through each character in s. for each character, it checks if the current character is greater than the previous character in s. if so, it subtracts twice the value of the previous character from the current character's value (e.g., 'IV' = 4 - 2*1 = 2). if not, it simply adds the value of the current character to the result

after all this, the method returns the result

3. next i created the method numToRoman which does the same thing as romanToNum, but in reverse

the map is the same as in romanToNum but reversed and additionally i added 4, 9, and their multiples of 10 to make the next part easier

then the for loop starts by creating a reverse iterator 'it' that starts at the last element of roman_map using the rbegin function, and iterates backwards until the first element of the map is reached using the rend function. the reverse iterator is used so that the largest values in roman_map are checked first, which is important for correctly representing numbers like 4 and 9 in roman numerals

the while loop inside the for loop checks if num is greater than or equal to the current value in the map roman_map pointed to by the iterator 'it'. if it is, the corresponding roman numeral symbol for that value is appended to the string roman using the += operator, and the value of num is decreased by the value of the current element of roman_map. this process is repeated until num is less than the current value of roman_map pointed to by the iterator 'it', at which point the loop moves on to the next element in roman_map

this loop constructs the string representation of the roman numeral for num by repeatedly appending the appropriate symbols for the largest values possible in descending order. by the end of the loop, the string roman contains the complete roman numeral representation of num, which is then returned

figuring this out was definately the hardest part of the challenge

3. lastly, i created the main function that simply used cin and cout to get user input. then using the two methods i created, it returns the roman numeral or integer that is desired

i added some tests to make sure the user enters either a properroman numeral or integer. otherwise, the terminal will display an error message and then reprompt the user for another input



this challenge took me about two and a half hours to complete