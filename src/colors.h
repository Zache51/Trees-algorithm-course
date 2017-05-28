#ifndef _COLORS_
#define _COLORS_

const std::string reset("\033[0m");
const std::string bold("\033[1m");
const std::string underline("\033[4m");

namespace TeCo
{
  const std::string red("\033[0;31m");
  const std::string green("\033[1;32m");
  const std::string yellow("\033[1;33m");
  const std::string blue("\033[1;34m");
  const std::string magenta("\033[0;35m");
  const std::string cyan("\033[0;36m");
  const std::string white("\033[0;37m");

  inline std::string color_it(std::string color, std::string message)
  {
    return color + message + reset;
  }
  inline std::string bold_it(std::string message)
  {
    return bold + message + reset;
  }
  inline std::string underline_it(std::string message)
  {
    return underline + message + reset;
  }

}


#endif	/* _COLORS_ */
