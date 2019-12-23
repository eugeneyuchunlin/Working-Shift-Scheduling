#ifndef __COLOR_H__ 
#define __COLOR_H__
#include "stringlib.h"

namespace fontstyle{
	extern std::string NORMAL;
	extern std::string RED;
	extern std::string GREEN;
	extern std::string YELLOW;
	extern std::string BLUE;
	extern std::string LIGHTRED;
	extern std::string BLINK;
	extern std::string UNDERLINED;
	extern std::string REVERSE;
	extern std::string DIM;
	extern std::string BOLD;
};

std::string colored(std::string text, std::string style, bool normal=true);

#endif
