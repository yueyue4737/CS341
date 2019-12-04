// Creating and Using a C++ class in successive files
//
// This paper gives a sample layout of how a C++ class would be developed
// by a software developer and then transmitted to a user programmer to
// use in that user's software applications.
//
// I will use my FirstClass example to illustrate the development process.
// This eample will be dicided up into four steps instead of the three
// which I presented in class.  The four steps are as follows:
//
// 1. The entire definition of my FirstClass class, which will consist of 
//    two files: (1) The definition of the class, which includes the name
//    of the class, the names of the data members, and the prototypes of
//    the methods, and (2) the file which gives the full definitions of 
//    the methods of the class. These two files are compiled together at
//    our software developer's site to produce a .dll object-library file
//    which will be shipped to the user.
//    After this in Item 3 is a source-code extract file in which is a
//    stripped-down version of the full .h file.
//    Finally, Item 4 is the appliations programmer's source code.

// FirstClass.h   This file along with the FirtsClass.cpp file is used to 
//    compile the .dll library file which is sent to the user.  However,
//    this file is not sent to the user. An extract of this file, which is 
//    shown below under item 2, is sent to the user.

// Demo Program Abstraction
// Item 1   The full class file which we keep at our software development
//     site

// Item 2   This source code file is not sent to the user, only the .dll
//     file which is produced from teh compile of this find
// FirstClass.cpp  File 1B
// Full method definitions

 // Include the original class definition above.


// Item 3 The version of the FirstClass.h file which is sent to the user
//    as source code.  It provides only those symbols, i.e. definitions
//    of function prototypes and definitions of symbolic constants which
//    compilation will need.


// Item 4  -- the user's application code which uses the FirstClass class.

// FirstClassDemo.cpp   
// Demo Program Abstraction
// Customer creates this program to use FirstClass class


  // contains the available symbols of the FirstClass 
                         //  class for the compile of this program

