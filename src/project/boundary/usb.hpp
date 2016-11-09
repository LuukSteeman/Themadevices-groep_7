///Copyright Robert Bezem, Ricardo Bouwman, Jeroen van Hattem, Luuk Steeman

#pragma once
#include "../entity/damageStorage.hpp"
#include "../nanopb/pb_encode.h"

/**
  USB class transfers damage storage over usb trough protobuf protocol
*/
class USB
{
  public:
    /**
      Encode a DamageStorage into protobuf and send it over usb
      @param ds DamageStorage to be encoded
    */
    static void writeToUSB(DamageStorage ds);

  private:
    static bool damageCallback(pb_ostream_t *stream, const pb_field_t *field, void *const *arg);
};
