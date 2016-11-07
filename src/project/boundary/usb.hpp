#pragma once
#include "../entity/damageStorage.hpp"
#include "../nanopb/pb_encode.h"

class USB
{
  public:
    static void writeToUSB(DamageStorage ds);

  private:
    static bool damageCallback(pb_ostream_t *stream, const pb_field_t *field, void *const *arg);
};