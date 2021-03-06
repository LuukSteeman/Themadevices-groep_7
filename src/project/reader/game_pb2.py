# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: game.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='game.proto',
  package='',
  syntax='proto2',
  serialized_pb=_b('\n\ngame.proto\"=\n\x06\x44\x61mage\x12\x1b\n\x13originatingPlayerId\x18\x01 \x02(\x05\x12\x16\n\x0e\x61mountOfDamage\x18\x02 \x02(\x05\"B\n\x08GameData\x12\x18\n\x10originalPlayerId\x18\x01 \x02(\x05\x12\x1c\n\x0b\x64\x61magesDone\x18\x02 \x03(\x0b\x32\x07.Damage')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_DAMAGE = _descriptor.Descriptor(
  name='Damage',
  full_name='Damage',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='originatingPlayerId', full_name='Damage.originatingPlayerId', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='amountOfDamage', full_name='Damage.amountOfDamage', index=1,
      number=2, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=14,
  serialized_end=75,
)


_GAMEDATA = _descriptor.Descriptor(
  name='GameData',
  full_name='GameData',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='originalPlayerId', full_name='GameData.originalPlayerId', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='damagesDone', full_name='GameData.damagesDone', index=1,
      number=2, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=77,
  serialized_end=143,
)

_GAMEDATA.fields_by_name['damagesDone'].message_type = _DAMAGE
DESCRIPTOR.message_types_by_name['Damage'] = _DAMAGE
DESCRIPTOR.message_types_by_name['GameData'] = _GAMEDATA

Damage = _reflection.GeneratedProtocolMessageType('Damage', (_message.Message,), dict(
  DESCRIPTOR = _DAMAGE,
  __module__ = 'game_pb2'
  # @@protoc_insertion_point(class_scope:Damage)
  ))
_sym_db.RegisterMessage(Damage)

GameData = _reflection.GeneratedProtocolMessageType('GameData', (_message.Message,), dict(
  DESCRIPTOR = _GAMEDATA,
  __module__ = 'game_pb2'
  # @@protoc_insertion_point(class_scope:GameData)
  ))
_sym_db.RegisterMessage(GameData)


# @@protoc_insertion_point(module_scope)
