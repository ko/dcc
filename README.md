dcc
===
Initial goal is to have simple addition working from lexical 
analysis to ASM generation. Build on top of that afterward.

todo
====
log() doesn't work with var args
add more unit tests in mapper.c

extending functionality
=======================
Notes on adding support for anything beyond what is currently
implemented.

lexi
----
* Add the #define to the appropriate .h file in src/lex
* Add the new symbol/token_t.type pair in src/lex/init.c
* Add (to a new or existing) case in the switch statement
found in src/lex/main.c
