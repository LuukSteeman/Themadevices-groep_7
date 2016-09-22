#include <iostream>
#include <fstream>
#include <string>

// ===========================================================================
//
// standard notes
//
// ===========================================================================

class note {
public:
   const int frequency;
   const int duration;
   
   // from https://www.seventhstring.com/resources/notefrequencies.html
   static const int A4  = 440;
   static const int A4s = 466;
   static const int B4  = 494;
   static const int C5  = 523;
   static const int C5s = 554;
   static const int D5  = 587;
   static const int D5s = 622;
   static const int E5  = 659;
   static const int F5  = 698;
   static const int F5s = 740;
   static const int G5  = 784;
   static const int G5s = 830;
   static const int A5  = 880;
   static const int A5s = 932;
   static const int B5  = 987;
   
   static const int dF = 1000000;
   static const int dH = dF / 2;
   static const int dQ = dF / 4;
};


// ===========================================================================
//
// interface for a note player
//
// ===========================================================================

class player {
public:   
   virtual void play( const note & n ) = 0;
};

class FilePlayer:public player{
    public:
    FilePlayer(){
    
    }
    
    void play(const note &n){
     std::cout << "p.play( note{" << n.frequency << ","<<n.duration<<"});\\" <<std::endl;   
    };
};


// ===========================================================================
//
// rtttl string player
//
// ===========================================================================

bool is_digit( char c ){ return ( c >= '0' ) && ( c <= '9' ); }
bool is_lowercase( char c ){ return ( c >= 'a' ) && ( c <= 'z' ); }
int frequencies[] = { 440, 494, 523, 587, 659, 698, 784 };

void play(player & lsp, const char *s ){
   int def_duration = 4, def_octave = 6, value;
   int duration, octave, frequency;
   int state = 0;
   char def;
   bool dot;
   for( const char * p = s; state >= 0; p++ ){
      const char c = *p;
      switch(state ){
         // title 
         case 0:
            if( c == ':' ){
               state = 1;
            } else {
               //std::cout << c;
            } 
            break;
               
          // defaults  
          case 1:
            if( c == ':' ){
               state = 3;
            } if( is_lowercase( c )){
               def = c;
               value = 0;
               state = 2;
            } else {
               //std::cout << "c=[" << c << "]";
            } 
            break;   

         // defaults, letter stored in def
         case 2:
            if( c == '=' ){
               // ignore the =
            } else if( is_digit( c )){
               value = ( 10 * value ) + ( c - '0' );
            } else if(( c == ':' ) || ( c == ',' )) {
               if( def == 'o'){
                  def_octave = value;
               } else if( def == 'd' ){
                  def_duration = value;
               } else if( def == 'b' ){
                  // ignore
               } else {
                  //std::cout << "def=[" << def << "]";
               }   
               state = ( c == ':' ) ? 3 : 1;
            } else {
               //std::cout << "c=[" << c << "]";
            }
            break;
            
         // note start, set defaults
         case 3:  
            duration = def_duration;
            octave = def_octave;
            state = 4;
            dot = 0;
            // fallthrough!!
               
         // duration 1  
         case 4:   
            if( c == '\0' ){
               state = -1;
               break;
            } else if( is_digit( c )){
               duration = c -'0';
               state = 5;
               break;
            }            
            // fallthrough!
            
         // duration 2 
         case 5:   
            if( is_digit( c )){
               duration = ( duration * 10 ) + ( c -'0' );
               state = 6;
               break;
            }            
            // fallthrough!
               
         // note letter   
         case 6:   
            if( is_lowercase( c )){
               if( c == 'p' ){
                   frequency = 0;
               } else {
                  frequency = frequencies[ c - 'a' ]; 
               }   
            } else {
               //std::cout << "c=[" << c << "]";
            }   
            state = 7;
            break;
               
         // optional #   
         case 7:   
            if( c == '#' ){
               frequency = 10595 * frequency / 10000;
               state = 8;
               break;
            }
            // fallthrough!

         // optional .
         case 8:
            if( c == '.' ){
               dot = 1;
               state = 9;
               break;
            }            
            // fallthrough!

         case 9:
            if( is_digit( c )){
               octave = c - '0';
               state = 10;
               break;
            }        
            // fallthrough!
               
         case 10:   
            if( ( c == ',' ) || ( c == '\0') ){
               while( octave > 5 ){ --octave; frequency *= 2; }
               duration = 2000000 / duration;
               if( dot ){
                  duration = 3 * duration / 2;
               }

               lsp.play( note{ frequency, duration } ); 
               state = 4;
            } else {
               //std::cout << "c=[" << c << "]";
            }
            if( c == '\0' ){
               state = -1;
            }
            break;            
      }         
   }
   //std::cout << "done";
}   
   
   
// ===========================================================================
//
// main: play an rtttl string
//
// ===========================================================================   

int main(int argc, char *argv[]){ 
   auto p = FilePlayer();
   std::cout << "#define ringtoneString ";

   std::ifstream infile(argv[1]);
   std::string song;
   if(infile.good()){
        std::getline(infile,song);
        play(p,song.c_str());
   }else{
        play(p,argv[1]); 
   }
   std::cout <<"\n\n";
}
