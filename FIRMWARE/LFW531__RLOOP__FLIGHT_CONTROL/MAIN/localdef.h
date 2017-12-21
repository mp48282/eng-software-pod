#ifndef LOCALDEF_H_
#define LOCALDEF_H_

	//The PCB's main files
	#ifndef WIN32
		#include <../../BOARD_SUPPORT/lpcb235r0__board_support.h>
		#include <../../BOARD_SUPPORT/NETWORKING/rloop_networking__ports.h>
	#else
		#include <../BOARD_SUPPORT/lpcb235r0__board_support.h>
		#include <../BOARD_SUPPORT/NETWORKING/rloop_networking__ports.h>
	#endif




/*******************************************************************************
SIL3 - ETHERNET TRANSPORT
*******************************************************************************/
	#define C_LOCALDEF__LCCM325__ENABLE_THIS_MODULE							(1U)
	#if C_LOCALDEF__LCCM325__ENABLE_THIS_MODULE == 1U

		//various protocol options
		//DHCP Client
		#define C_LOCALDEF__LCCM325__ENABLE_DHCP_CLIENT						(0U)
		//Link Layer Discovery Protocol
		#define C_LOCALDEF__LCCM325__ENABLE_LLDP							(0U)
		#define C_LOCALDEF__LCCM325__ENABLE_SNMP							(0U)

		//UDP Rx
		#define C_LOCALDEF__LCCM325__UDP_RX_CALLBACK(buffer,length,dest_port)	vFCU_NET_RX__RxUDP(buffer, length, dest_port)
		/*vECU_ETHERNET_RX__UDPPacket*/

		//testing options
		#define C_LOCALDEF__LCCM325__ENABLE_TEST_SPEC						(0U)

		//protocol specific options
		//set to 1 to consider port numbers
		#define C_LOCALDEF__LCCM325__PROTO_UDP__ENABLE_PORT_NUMBERS			(1U)

		//main include file
		#include <MULTICORE/LCCM325__MULTICORE__802_3/eth.h>

	#endif //C_LOCALDEF__LCCM325__ENABLE_THIS_MODULE

/*******************************************************************************
SAFETY UDP LAYER
*******************************************************************************/
	#define C_LOCALDEF__LCCM528__ENABLE_THIS_MODULE							(1U)
	#if C_LOCALDEF__LCCM528__ENABLE_THIS_MODULE == 1U

		/** User Rx Callback
		* Payload, Length, Type, DestPort, Faults
		*/
		#define C_LOCALDEF__LCCM528__RX_CALLBACK(p,l,t,d,f)					vFCU_NET_RX__RxSafeUDP(p,l,t,d,f)

		/** The one and only UDP port we can operate on */
		#define C_LOCALDEF__LCCM528__ETHERNET_PORT_NUMBER					(0U)
		#define C_LOCALDEF__LCCM528__ETHERNET_PORT_NUMBER2					(0U)

		/** Vision over SafeUDP Options */
		#define C_LOCALDEF__LCCM528__VISION__ENABLE_TX						(0U)
		#define C_LOCALDEF__LCCM528__VISION__ENABLE_RX						(0U)
		#define C_LOCALDEF__LCCM528__VISION__MAX_BUFFER_SIZE				(640UL * 480UL * 2UL)


		/** Testing Options */
		#define C_LOCALDEF__LCCM528__ENABLE_TEST_SPEC						(0U)

		/** Main include file */
		#include <MULTICORE/LCCM528__MULTICORE__SAFE_UDP/safe_udp.h>
	#endif //#if C_LOCALDEF__LCCM528__ENABLE_THIS_MODULE == 1U

/*******************************************************************************
AMC7812
*******************************************************************************/
	#define C_LOCALDEF__LCCM658__ENABLE_THIS_MODULE							(1U)
	#if C_LOCALDEF__LCCM658__ENABLE_THIS_MODULE == 1U

		//I2C Bus Address
		// See Table 8, p. 49 and p. 51, ACM7812 datasheet
		#define C_LOCALDEF__LCCM658__BUS_ADDX								(0xC2)

		/** Num devices on the bus */
		#define C_LOCALDEF__LCCM658__NUM_DEVICES							(1U)

		/** Testing Options */
		#define C_LOCALDEF__LCCM658__ENABLE_TEST_SPEC						(0U)

		/** The number of main program loops to wait for conversion */
		#define C_LOCALDEF__LCCM658__NUM_CONVERSION_LOOPS					(10000U)

		//Reset pin
		#define C_LOCALDEF__LCCM658__NRESET__TRIS(x)						{vRM4_N2HET_PINS__Set_PinDirection_Output(N2HET_CHANNEL__1, 18U);}
		#define C_LOCALDEF__LCCM658__NRESET__LATCH(x)						{if(x == 0)vRM4_N2HET_PINS__Set_PinLow(N2HET_CHANNEL__1, 18U); else vRM4_N2HET_PINS__Set_PinHigh(N2HET_CHANNEL__1, 18U);}


		/** Main include file */
		#include <MULTICORE/LCCM658__MULTICORE__AMC7812/amc7812.h>
	#endif //#if C_LOCALDEF__LCCM658__ENABLE_THIS_MODULE == 1U


/*******************************************************************************
RLOOP - FLIGHT CONTROL UNIT - CORE
*******************************************************************************/
	#define C_LOCALDEF__LCCM655__ENABLE_THIS_MODULE							(1U)
	#if C_LOCALDEF__LCCM655__ENABLE_THIS_MODULE == 1U

		//special needs for DAQ compile time
		#include <LCCM655__RLOOP__FCU_CORE/fcu_core__daq_settings.h>

		/** Data Acqusition System */
		#define C_LOCALDEF__LCCM655__ENABLE_DAQ								(1U)

		/** Enable the OptoNCDT laser interface */
		#define C_LOCALDEF__LCCM655__ENABLE_LASER_OPTONCDT					(0U)

		/** Enable the Laser contrast sensors */
		#define C_LOCALDEF__LCCM655__ENABLE_LASER_CONTRAST					(0U)

		/** Laser Distance Unit */
		#define C_LOCALDEF__LCCM655__ENABLE_LASER_DISTANCE					(0U)

		/** Enable accel subsystem */
		#define C_LOCALDEF__LCCM655__ENABLE_ACCEL							(1U)

		/** Enable the braking subsystems */
		#define C_LOCALDEF__LCCM655__ENABLE_BRAKES							(1U)

		/** Enable the throttle control */
		#define C_LOCALDEF__LCCM655__ENABLE_THROTTLE						(1U)

		/** Enable the ASI_RS485 */
		#define C_LOCALDEF__LCCM655__ENABLE_ASI_RS485						(1U)

		/** If you have the ASI monitoring on, to simplify things if we have all the
		 * devices on different addresses, set this to one and then daisy-chain*/
		#define C_LOCALDEF__LCCM655__SINGLE_RS485_ONLY						(1U)

		/** Enable the pusher detection system */
		#define C_LOCALDEF__LCCM655__ENABLE_PUSHER							(0U)

		/** Ethernet Systems */
		#define C_LOCALDEF__LCCM655__ENABLE_ETHERNET						(1U)

		/** SpaceX Telemetry Requirements Enable */
		#define C_LOCALDEF__LCCM655__ENABLE_SPACEX_TELEMETRY				(0U)

		/**Geom system */
		#define C_LOCALDEF__LCCM655__ENABLE_GEOM							(0U)

		/** Flight control specifics */
		#define C_LOCALDEF__LCCM655__ENABLE_FLIGHT_CONTROL					(1U)

			/** Main SM */
			#define C_LOCALDEF__LCCM655__ENABLE_MAIN_SM							(1U)

			//Pitch/Roll/Yaw
			#define C_LOCALDEF__LCCM655__ENABLE_FCTL_ORIENTATION				(0U)

			//Brake Controller
			#define C_LOCALDEF__LCCM655__ENABLE_FCTL_BRAKE_CONTROL				(1U)

			//Contrast Sensor Navigation
			#define C_LOCALDEF__LCCM655__ENABLE_FCTL_CONTRAST_NAV				(0U)

			/** Allow us to control the gimbals and include in calculations */
			#define C_LOCALDEF__LCCM655__ENABLE_GIMBAL_CONTROL					(0U)

			/** Track Database */
			#define C_LOCALDEF__LCCM655__ENABLE_TRACK_DB						(1U)

			/** Pod Health System */
			#define C_LOCALDEF__LCCM655__ENABLE_POD_HEALTH						(0U)

			/** Hover Engine Control */
			#define C_LOCALDEF__LCCM655__ENABLE_HOVERENGINES_CONTROL			(0U)

			/** Drive Pod Control */
			#define C_LOCALDEF__LCCM655__ENABLE_DRIVEPOD_CONTROL				(0U)

			/** Eddy Brakes Control */
			#define C_LOCALDEF__LCCM655__ENABLE_EDDY_BRAKES						(0U)

			/** Lift Mechanism Control */
			#define C_LOCALDEF__LCCM655__ENABLE_LIFT_MECH_CONTROL				(0U)

			/** Navigation function */
			#define C_LOCALDEF__LCCM655__ENABLE_FCTL_NAVIGATION 				(0U)

			/** Control Aux Propulsion */
			#define C_LOCALDEF__LCCM655__ENABLE_AUX_PROPULSION_CONTROL 			(0U)

			/** Enable PID for the Brakes */
			#define C_LOCALDEF__LCCM655__ENABLE_BRAKEPID 						(0U)

            /** Enable fault handling out ethernet */
            #define C_LOCALDEF__LCCM655__ENABLE_ETHERNET_FAULTS                 (1U)

		/** ADC Sample Limits */
		#define C_LOCALDEF__LCCM655__ADC_SAMPLE__LOWER_BOUND				(200U)
		#define C_LOCALDEF__LCCM655__ADC_SAMPLE__UPPER_BOUND				(3100U)

		/** Testing Options */
		#define C_LOCALDEF__LCCM655__ENABLE_TEST_SPEC						(0U)

		/** Main include file */
		#include <LCCM655__RLOOP__FCU_CORE/fcu_core.h>
	#endif //#if C_LOCALDEF__LCCM655__ENABLE_THIS_MODULE == 1U


#endif /* LOCALDEF_H_ */
