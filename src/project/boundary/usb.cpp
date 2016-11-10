#include "usb.hpp"
#include "../entity/Damage.hpp"
#include "../nanopb/game.pb.h"
#include "hwlib.hpp"

bool USB::damageCallback(pb_ostream_t *stream, const pb_field_t *field, void *const *arg)
{
  Damage damage = Damage_init_zero;
  for (int i = 0; i < 100; i++)
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
};

void USB::writeToUSB(DamageStorage ds)
{
  uint8_t buffer[1024];
  size_t message_length;
  bool status;

  GameData message = GameData_init_zero;

  message.originalPlayerId = 13;
  message.damagesDone.funcs.encode = &USB::damageCallback;
  message.damagesDone.arg = &ds;

  pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));
  status = pb_encode(&stream, GameData_fields, &message);
  message_length = stream.bytes_written;

  if (!status)
  {
    hwlib::cout << "Encoding failed: " << PB_GET_ERROR(&stream) << "\n";
    return;
  }
  hwlib::cout << "dataLength:" << message_length << "\n";
  for (unsigned int i = 0; i < message_length; i++)
  {
    hwlib::uart_putc(buffer[i]);
  }
};