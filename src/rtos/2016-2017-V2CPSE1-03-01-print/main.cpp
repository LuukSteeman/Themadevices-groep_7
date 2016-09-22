//copyright: sqrtroot

#include "hwlib.hpp"

extern "C"
{

   // don't chance this function: it is the bridge
   // between the C and assembler 'world' and C++.
   void put_char( char c )
   {
      hwlib::cout << c;
   }

//   void print_asciz( const char * p ){
//      while( *p != '\0' ){
//         put_char( *p );
//         p++;
//      }
//   }
    extern void print_asciz(const char *p);

//   void application(){
//      print_asciz( "Hello world!? [@] {`} 12345==67890\n" );
//   }

/*  char toLowerCase(char c){
        if(c>='a' && c <='z'){
            return (c - 'a')+'A';
        }else if(c>='A' && c<='Z'){
            return (c - 'A')+'a';
        }
        return c;
    }
*/
    extern void switchCase(char c);
    extern void application();

};

// Do n@ot change the code below. Execution starts in C++,
// then continues in application(). Make your modifications
// there in the extern "C" { . . . }; part, and in the separate .asm file.
int main()
{
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;

      // wait for the PC console to start
   hwlib::wait_ms( 500 );
   application();

}
