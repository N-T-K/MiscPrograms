# MiscPrograms
Miscellaneous programs. 

bitwiseDivision.c
--------
Implements division utilizing subtraction and bit shifting to evaluate a 16 bit dividend and 8 bit divisor producing a 16 bit quotient and 8 bit remainder (8 bits after the radix). Useful for when an Instruction Set Architecture (ISA) doesn't have an explicit `mult` instruction. 
* Example: 21/4 = 0101.01 (format: quotient.fraction)
