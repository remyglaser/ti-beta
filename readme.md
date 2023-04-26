# ti-beta

This source code can be used for ti-83 and ti-83+ compatible calculators.
The source can be assembled with the TASM assembler. Get it from http://home.comcast.net/~tasm/

Assembled ti-83 and ti-83+ comaptible versions are NOT interchangeable and will probably crash your calculator if you try it.
The ti-83 version will work only on a ti-83
The ti-83+ compatible version will work on all ti-83+ compatible calculators. At the moment of writing, those are the ti-83+, ti-83+ silver edition, ti-84+ and ti-84+ silver edition.

The same soure code is used for both ti-83 and ti-83+. To assemble the source for a particular platform, change the assembler variable TI83P.

The source code uses include files to access system routines and macros. My include files are somewhat modified, so you are probably unable to use the standard versions as provided by Texas Instruments.

Understanding and editing the source code will probably be hard work. This program is pretty old and has continously been changed in bits and pieces. Assembly is always hard to read, and a lot of comments are missing, some are in dutch.

The current source code comes with 7 languages. English, Dutch, German, French, Italien, Spanish and Latin. The english and dutch versions are quite correct, I'm not so sure about the others;). Of course, your suggestions are welcome.
Languages are hard-coded. To change the language, use the assembler variables LAN_EN, LAN_NL etc.

I use the following command to assemble the source code on windows:

TASM32.EXE -t80 -b -i -dTI83P -dLAN_EN beta3\beta.asm beta3\beta.bin


Tasm works in wine, so you can assemble the code on linux:

wine TASM32.EXE -t80 -b -i -dTI83P -dLAN_EN beta3/beta.asm beta3/beta.bin

This produces a binary file for Ti-83+ in english. You'll need a linker after this to create a file to send to your calculator.
