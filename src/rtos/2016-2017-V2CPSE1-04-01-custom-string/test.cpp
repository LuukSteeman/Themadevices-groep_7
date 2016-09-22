#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "string.h"
#include <string>

TEST_CASE( "Test constructors & c_str function", "[String]" ) {
    String<20> noArgs = String<20>();
    String<20> charPArg = String<20>((char *)"abcdefg");
    String<20> stringArg= String<20>(std::string("ABCDEFG"));

    REQUIRE(strcmp(noArgs.c_str(),"\0") == 0);
    REQUIRE(strcmp(charPArg.c_str(),"abcdefg") == 0);
    REQUIRE(strcmp(stringArg.c_str(),"ABCDEFG") == 0);
};

TEST_CASE("Test length function","[String]"){
    String<20> normalString = String<20>("abcdefg");
    String<20> withNullString = String<20>("abcdefg\0abcdef");

    REQUIRE(normalString.length()==7);
    REQUIRE(withNullString.length()==7);

};

TEST_CASE("Test overflow","[String]"){
    String<5> overflowCharString = String<5>((char *)"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrtapsodijpfoijdsaf");
    String<5> overflowStringString = String<5>(std::string("abcdefgaosjdpfijsapdoijfposaidjfpoijsadpofjzkxjpijfas"));

    REQUIRE(overflowCharString.length()==5);
    REQUIRE(overflowStringString.length() == 5);
};