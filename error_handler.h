#ifndef ERROR_HANDLER_H

#define ERROR_HANDLER_H

#include <string>

class ErrorHandler
{
public:
	static int lineNo;
	static void setLineNo(int l) { ErrorHandler::lineNo = l; }
	static void error(std::string);
	static void fatal(std::string);
};

#endif
