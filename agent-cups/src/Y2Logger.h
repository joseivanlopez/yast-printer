/* Y2Logger.h
 *
 * Macros for logging the output.
 *
 * Just #include "Y2Logger.h" and use Y2_DEBUG, Y2_WARNING or Y2_ERROR
 * 
 * If you write Y2_DEBUG("Hello: %d",7) on line 13 in the file Source.cc,
 * the debug output will look like this:
 *   [...]:Source.cc[13] Hello: 7
 *
 * Additionally you can #define Y2_COMPONENT before inclusion and its name
 * will be put just before the Source.cc.
 * And don't forget set (end export the Y2DEBUG shell variable!
 *
 * Also define Y2_DEBUG_YES if you want to get the debugging output!
 *
 * Author: Michal Svec <msvec@suse.cz>
 *         Daniel Vesely <dan@suse.cz>
 *
 * $Id$
 */

#ifndef Y2Logger_h
#define Y2Logger_h

#define y2log_component "ag_cups"
#include <ycp/y2log.h>

//FIXME:
#define Y2_DEBUG_YES 1

extern char last_error[1024];

/*
 * Logging macros
 */
#ifndef Y2_DEBUG_YES
#define Y2_DEBUG(format,args...)
#else
#define Y2_DEBUG(format,args...) \
    y2debug(format,##args)
#endif

#define Y2_WARNING(format,args...) \
    y2warning(format,##args)

#define Y2_ERROR(format,args...) \
    {\
    y2error(format,##args);\
    snprintf (last_error,1023,format,##args);\
    }

/*
 * Log the error and return ...
 */
#define Y2_RETURN_FALSE(format,args...) \
  { y2error(format,##args); return false; }

#define Y2_RETURN_VOID(format,args...) \
  { y2error(format,##args); return YCPVoid(); }

#define Y2_RETURN_STR(format,args...) \
  { y2error(format,##args); return ""; }

#define Y2_RETURN_YCP_FALSE(format,args...) \
  { y2error(format,##args); return YCPBoolean(false); }

#endif /* Y2Logger_h */
