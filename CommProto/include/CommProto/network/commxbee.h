/*
  XBee class for handling xbee connections.

  Copyright (C) 2016  Mario Garcia.

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (At your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __COMMXBEE_H
#define __COMMXBEE_H

#include <CommProto/architecture/os/include_defines.h>
#include <CommProto/architecture/connection/serial-config.h>

#include <list>
#include <memory>
#include <xbee.h>//should be libxbee3 

#if (COM_TARGET_OS == COM_OS_WINDOWS)
	#include <Windows.h>
	#pragma comment (lib, "libxbee3.lib")
#endif

namespace comnet {
namespace network {

/**
   XBee communications module. Used for any Xbee protocol connection made to 
   other devices. Still needs work.
*/
class COMM_EXPORT CommXBee {
public:
  /**
    Constructor that autoinitializes when created. function initialize is automatically called from 
    this constructor. 
   */
  CommXBee();

  /**
     Default destructor.
   */
  ~CommXBee();
  /**
    Initialize the port on this device.
   */
  bool Initialize(const char* port, speed_t baudrate);
  /**
  Adds an address to the link.
  */
  bool AddAddress(uint8_t dest_id, const char* address = NULL, uint16_t port = 0);
  /**
  Remove an address from the link.
  */
  bool RemoveAddress(uint8_t dest_id);
  /**
    Send data over to the destination node.
   */
  bool Send(xbee_con *con, uint8_t* txData, uint32_t txLength);
  /**
    Check Receive data.
   */
  bool Recv(xbee_con *con, uint8_t* rxData, uint32_t* rxLength);
  
 

private:
	uint8_t hexCharToInt(unsigned char value);
	uint8_t doubleHexCharToInt(unsigned char c1, unsigned char c2);
	void stringToAddress(const char* str, uint8_t length, xbee_conAddress &address);

	//unordered map of *con

	struct xbee *xbee;
	struct xbee_pkt *pkt;


	struct xbee_con *con;
	struct xbee_conAddress *address;	
	//struct xbee_conSettings *settings;//for broadcast recieve probably wont use
	
	int ret;
	

};
} // namespace Network
} // namespace Comnet
#endif // __COMMXBEE_H
