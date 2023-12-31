#ifndef __COLORS_H__
#define __COLORS_H__
 
#define greenItalics       "\033[3;32m"
#define defaultColor       "\033[0m" 

#define RED_ITALICS(str)   "\033[3;31m" str defaultColor
#define GREEN(str)         "\033[32m"   str defaultColor
#define GREEN_ITALICS(str) "\033[3;32m" str defaultColor
#define YELLOW(str)        "\033[33m"   str defaultColor
#define BLUE(str)          "\033[36m"   str defaultColor
#define RED(str)           "\033[31m"   str defaultColor
#define MAGENTA(str)       "\033[35m"   str defaultColor

#endif //__COLORS_H__
