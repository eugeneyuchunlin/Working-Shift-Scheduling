#include "colored.h"


std::string fontstyle::NORMAL("\e[0m");
std::string fontstyle::RED("\e[31m");
std::string fontstyle::GREEN("\e[32m");
std::string fontstyle::YELLOW("\e[33m");
std::string fontstyle::BLUE("\e[34m");
std::string fontstyle::LIGHTRED("\e[91m");
std::string fontstyle::BLINK("\e[5m");
std::string fontstyle::UNDERLINED("\e[4m");
std::string fontstyle::REVERSE("\e[7m");
std::string fontstyle::DIM("\e[2m");
std::string fontstyle::BOLD("\e[1m");

std::string colored(std::string text, std::string style, bool normal){
	return normal ? style + text + fontstyle::NORMAL : style + text;
}
