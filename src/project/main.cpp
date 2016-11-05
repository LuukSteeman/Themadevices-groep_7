#include <hwlib.hpp>
#include <rtos.hpp>

#include "entity/damageStorage.hpp"
#include "entity/Damage.hpp"
#include "nanopb/game.pb.h"
#include "nanopb/pb_encode.h"

bool damageCallback(pb_ostream_t *stream, const pb_field_t *field, void *const *arg)
{
  Damage damage = Damage_init_zero;
  for (int i = 0; i < 3; i++)
  {
    if (!pb_encode_tag_for_field(stream, field))
    {
      return false;
    }

    damage.originatingPlayerId = ((DamageStorage *)*arg)->getDamage(i).getPlayerID();
    damage.amountOfDamage = ((DamageStorage *)*arg)->getDamage(i).getDamageAmount();

    if (!pb_encode_submessage(stream, Damage_fields, &damage))
    {
      return false;
    }
  }
  return true;
}

void writeProtobuf(DamageStorage ds)
{
  uint8_t buffer[1024];
  size_t message_length;
  bool status;

  GameData message = GameData_init_zero;

  message.originalPlayerId = 13;
  message.damagesDone.funcs.encode = &damageCallback;
  message.damagesDone.arg = &ds;

  pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));
  status = pb_encode(&stream, GameData_fields, &message);
  message_length = stream.bytes_written;

  if (!status)
  {
    hwlib::cout << "Encoding failed: " << PB_GET_ERROR(&stream) << "\n";
    return;
  }
  hwlib::cout << message_length << "\n";
  for (unsigned int i = 0; i < message_length; i++)
  {
    hwlib::uart_putc(buffer[i]);
  }
}

int main()
{
  WDT->WDT_MR = WDT_MR_WDDIS;
  hwlib::wait_ms(500);

  DamageStorage ds;

  ds.addDamage(10, 3);
  ds.addDamage(5, 4);
  ds.addDamage(6, 5);

  while(hwlib::cin.getc() != '\n');
  writeProtobuf(ds);
  return 0;
}