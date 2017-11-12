/**
 * @file		eth_localdef.h
 * @brief		Localdef template for Ethernet layer
 * @author		Lachlan Grogan
 * @copyright	This file contains proprietary and confidential information of the Lockie Group
 *				of companies, including Lockie Innovation Pty. Ltd (ACN 123 529 064) and
 *				Lockie Safety Systems Pty. Ltd (ACN 132 340 571).  This code may be distributed
 *				under a license from the Lockie Group of companies, and may be used, copied
 *				and/or disclosed only pursuant to the terms of that license agreement.
 *				This copyright notice must be retained as part of this file at all times.
 * @copyright	This file is copyright Lockie Innovation Pty Ltd 2003-2012, All Rights Reserved.
 * @copyright	This file is copyright Lockie Safety Systems Pty Ltd 2008-2012, All Rights Reserved.
 * @st_fileID	LCCM325R0.FILE.004
 */


#if 0

/*******************************************************************************
SIL3 - 802.3 ETHERNET
*******************************************************************************/
	#define C_LOCALDEF__LCCM325__ENABLE_THIS_MODULE							(1U)
	#if C_LOCALDEF__LCCM325__ENABLE_THIS_MODULE == 1U

		/** On Xilinx Architectures we can use NPI burst transfers */
		#define C_LOCALDEF__LCCM325__XILINX_USE_NPI_INTERFACE				(0U)

		//ARP Configuration
		/** Enable ARP Requesting */
		#define C_LOCALDEF__LCCM325__ARP__ENABLE_REQUEST					(0U)
		/** Enable ARP Cache */
		#define C_LOCALDEF__LCCM325__ARP__ENABLE_CACHE						(0U)
		/** If caching is enabled what is the maximum ARP cache size (entries) */
		#define C_LOCALDEF__LCCM325__ARP__MAX_CACHE_SIZE					(4U)
		/** If caching is enabled how long until the entry expires in 100ms
		 * The default is 300 seconds */
		#define C_LOCALDEF__LCCM325__ARP__ENTRY_EXPIRE_X100MS				(3000U)
		/** The amount of time from when a request is sent to a timeout occurring
		 * Currently set at 3 seconds. */
		#define C_LOCALDEF__LCCM325__ARP__RESPONSE_TIMEOUT_X100MS			(30U)

		//DNS Client Configuration
		/** Enable the DNS Client for DNS lookup */
		#define C_LOCALDEF__LCCM325__DNS__ENABLE_DNS_CLIENT					(0U)
		/** Maximum number of host names in the cache */
		#define C_LOCALDEF__LCCM325__DNS__MAX_CACHE_SIZE					(4U)


		//DHCP Client Configuration
		/** DHCP Client */
		#define C_LOCALDEF__LCCM325__DHCP__ENABLE_DHCP_CLIENT				(0U)

		//TCP/IP Settings
		/** TCP/IP Module Enable*/
		#define C_LOCALDEF__LCCM325__TCPIP__ENABLE_TCPIP					(0U)
		/** New TCP data callback */
		#define M_LOCALDEF__LCCM325__TCPIP__NEW_RX_DATA(id, buffer, length)	{}



		//various protocol options
		/** Link Layer Discovery Protocol */
		#define C_LOCALDEF__LCCM325__ENABLE_LLDP							(0U)
		/** Simple Network Management Protocol */
		#define C_LOCALDEF__LCCM325__ENABLE_SNMP							(0U)
		
		//UDP Rx
		#define C_LOCALDEF__LCCM325__UDP_RX_CALLBACK(buffer,length,port)	vSIL3_SAFEUDP_RX__UDPPacket(buffer, length, port)
	
		//testing options
		#define C_LOCALDEF__LCCM325__ENABLE_TEST_SPEC						(0U)
	

		//protocol specific options
		//set to 1 to consider port numbers
		#define C_LOCALDEF__LCCM325__PROTO_UDP__ENABLE_PORT_NUMBERS			(0U)

		//main include file
		#include <MULTICORE/LCCM325__MULTICORE__802_3/eth.h>
	
	#endif //C_LOCALDEF__LCCM325__ENABLE_THIS_MODULE



#endif //0

