#ifndef FORCEINCLUDE_H
#define FORCEINCLUDE_H
// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
// For more information, see "C:\Program Files (x86)\Windows Kits\10\Include\10.0.10069.0\um\SdkDdkver.h"

// list of banned APIs - recommendation from MS SDL
#define _SDL_BANNED_RECOMMENDED
#include <banned.h>


// enable specific compiler warnings
// see Compiler Warnings That Are Off by Default https://msdn.microsoft.com/en-us/library/23k5d385.aspx
//
// C4191 unsafe conversion from 'type of expression' to 'type required'
#pragma  warning(default:4191)
// C4242 - conversion from 'type1' to 'type2', possible loss of data
#pragma  warning(default:4242)
// C4263 - member function does not override any base class virtual member function
#pragma  warning(default:4263)
// C4264 - no override available for virtual member function from base 'class'; function is hidden
#pragma  warning(default:4264)
// C4265 - class has virtual functions, but destructor is not virtual
#pragma  warning(default:4265)
// C4266 - no override available for virtual member function from base 'type'; function is hidden
#pragma  warning(default:4266)
// C4302 - truncation from 'type 1' to 'type 2'
#pragma  warning(default:4302)
// C4826 - conversion from 'type1' to 'type2' is sign-extended. This may cause unexpected runtime behavior
#pragma  warning(default:4826)
// C4905 - wide string literal cast to 'LPSTR'
#pragma  warning(default:4905)
// C4906 - string literal cast to 'LPWSTR'
#pragma  warning(default:4906)
// C4928 - illegal copy-initialization; more than one user-defined conversion has been implicitly applied
#pragma  warning(default:4928)
// C4255 - 'function': no function prototype given : converting '()' to '(void)'
#pragma  warning(default:4255)
// C4355 - 'this' : used in base member initializer list
#pragma  warning(default:4355)
// C4431 - missing type specifier - int assumed.Note: C no longer supports default - int
#pragma  warning(default:4431)
// C4471 - a forward declaration of an unscoped enumeration must have an underlying type( int assumed )
#pragma  warning(default:4471)

#endif
