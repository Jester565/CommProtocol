/*
Copyright (C) 2016  Michael Wallace, Mario Garcia.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __CPACKET_MANAGER_H
#define __CPACKET_MANAGER_H

#include <CommProto/pkg/PacketManager.h>
#include <CallBack.h>
#include <ABSPacket.h>

#include <vcclr.h>
#using <mscorlib.dll>


using namespace System;

namespace Comnet {
namespace Pkg {

#pragma managed

/**
  CPacketManager is an interface, meant to allow interchangeable hashing and managing.
*/
public interface class CPacketManager abstract {
public:

  virtual Boolean Insert(ABSPacket^ key, CallBack^ callback) = 0;
  virtual CallBack^ Get(ABSPacket^ key) = 0;
  virtual Boolean Remove(ABSPacket^ key) = 0;
  virtual Boolean Contains(ABSPacket^ key) = 0;
  virtual Boolean Contains(CallBack^ call) = 0;
  virtual Int32 GetSize() = 0;
  virtual Void Resize() = 0;

  virtual ABSPacket^ ProduceFromId(UInt32 key) = 0;
};
}
}
#endif // __CPACKET_MANAGER_H