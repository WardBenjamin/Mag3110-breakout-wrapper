/* 
 MAGG3110 Breakout Wrapper
 
 by: Benjamin Ward, bwardbsa at gmail dot com
   WardBenjamin (on Github dot com)
   FTC Team 4592
   
   date: 10/12/2014
   licence: rootbeerware, if you use this code and happen to meet me, you 
         can buy me a root beer. Also, I would appreciate an email!
   
   This class provides a wrapper for the Mag3110 Breakout from Sparkfun
   Electronics, providing functions to read the 16-bit x, y, and z values.
   Currently, there is no wrapper to use the INT1 pin, or for polling for
   new data.
   
   Credit to Aaron Weiss (aaron at sparkfun dot com) for my use of the 
   example code that he has provided. (original date: 9/6/11).
*/

class Mag3110
{
  private:
    void config();
    
  public:
    Mag3110();
    void setup();
    int readx(void);
    int ready(void);
    int readz(void);
};
