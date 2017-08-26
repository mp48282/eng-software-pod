/**
 * @file		FCU__FCTL__ETHERNET.C
 * @brief		Fligth controller ethernet interface
 * @author		Lachlan Grogan
 * @copyright	rLoop Inc.
 */
/**
 * @addtogroup RLOOP
 * @{ */
/**
 * @addtogroup FCU
 * @ingroup RLOOP
 * @{ */
/**
 * @addtogroup FCU__FCTL__ETHERNET
 * @ingroup FCU
 * @{ */

#include "../../fcu_core.h"

#if C_LOCALDEF__LCCM655__ENABLE_THIS_MODULE == 1U
#if C_LOCALDEF__LCCM655__ENABLE_FLIGHT_CONTROL == 1U
#if C_LOCALDEF__LCCM655__ENABLE_ETHERNET == 1U

extern struct _strFCU sFCU;

/***************************************************************************//**
 * @brief
 * Init Eth
 * 
 * @st_funcMD5		28391E45A0FE140F795717C331017DDF
 * @st_funcID		LCCM655R0.FILE.077.FUNC.001
 */
void vFCU_FCTL_ETH__Init(void)
{

}

/***************************************************************************//**
 * @brief
 * Process FCU Eth
 * 
 * @param[in]		ePacketType				Packet Type
 * @st_funcMD5		B4735D1A5338CCCBF4730A9C9ADCAEEE
 * @st_funcID		LCCM655R0.FILE.077.FUNC.002
 */
void vFCU_FCTL_ETH__Transmit(E_NET__PACKET_T ePacketType)
{

	Lint16 s16Return;
	Luint8 * pu8Buffer;
	Luint8 u8BufferIndex;
	Luint16 u16Length;
	Luint8 u8Counter;

	pu8Buffer = 0;

	//setup length based on packet.
	switch(ePacketType)
	{
		case NET_PKT__FCU_GEN__TX_MISSION_DATA:
			u16Length = 11U;

			u16Length += 20 + (4 * C_LOCALDEF__LCCM487__NUM_DEVICES) + 4U + 4U + 4U + 16U + 8U +  (4U + C_FCU__NUM_LASERS_OPTONCDT) + 4U + 4U + 8U + 16U + 8U;
			break;


		default:
			u16Length = 0U;
			break;

	}//switch(ePacketType)

	//pre-comit
	s16Return = s16SIL3_SAFEUDP_TX__PreCommit(u16Length, (SAFE_UDP__PACKET_T)ePacketType, &pu8Buffer, &u8BufferIndex);
	if(s16Return == 0)
	{
		//handle the packet
		switch(ePacketType)
		{
			case NET_PKT__FCU_GEN__TX_MISSION_DATA:

				//top level fault flags
				vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, u32FCU_FAULTS__Get_FaultFlags());
				pu8Buffer += 4U;

				//mission state
				vSIL3_NUM_CONVERT__Array_U16(pu8Buffer, (Luint16)sFCU.sStateMachine.sm.eCurrentState);
				pu8Buffer += 2U;

				//current track database
				#if C_LOCALDEF__LCCM655__ENABLE_TRACK_DB == 1U
					pu8Buffer[0] = (Luint8)sFCU.sFlightControl.sTrackDB.u32CurrentDB;
					pu8Buffer += 1U;
				#else
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0U);
					pu8Buffer += 4U;
				#endif

				//pod health
				#if C_LOCALDEF__LCCM655__ENABLE_POD_HEALTH == 1U
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, sFCU.sPodHealth.sHealthFlags.u32Flags[0]);
					pu8Buffer += 4U;
				#else
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0U);
					pu8Buffer += 4U;
				#endif

				//Navigation System


				//Valid data sources


				//Thresholding sources


				//Flags
				//top level fault flags
				vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, u32FCU_FAULTS__Get_FaultFlags());
				pu8Buffer += 4U;

				//accel
#if C_LOCALDEF__LCCM655__ENABLE_ACCEL == 1U
				vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, sFCU.sAccel.sFaultFlags.u32Flags[0]);
				pu8Buffer += 4U;
				vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, u32SIL3_MMA8451__Get_FaultFlags(0U));
				pu8Buffer += 4U;
				vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, u32SIL3_MMA8451__Get_FaultFlags(1U));
				pu8Buffer += 4U;
#else
				vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0xFFFFFFFFU);
				pu8Buffer += 4U;
				vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0xFFFFFFFFU);
				pu8Buffer += 4U;
				vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0xFFFFFFFFU);
				pu8Buffer += 4U;
#endif


				//SC16 System
				for(u8Counter = 0U; u8Counter < C_LOCALDEF__LCCM487__NUM_DEVICES; u8Counter++)
				{
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, u32SIL3_SC16__Get_FaultFlags(u8Counter));
					pu8Buffer += 4U;

				}



				//ASI
				#if C_LOCALDEF__LCCM655__ENABLE_ASI_RS485 == 1U
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, sFCU.sASI.sFaultFlags.u32Flags[0]);
					pu8Buffer += 4U;
				#else
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0xFFFFFFFFU);
					pu8Buffer += 4U;
				#endif

				//Brakes
				#if C_LOCALDEF__LCCM655__ENABLE_BRAKES == 1U
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, sFCU.sBrakesGlobal.sFaultFlags.u32Flags[0]);
					pu8Buffer += 4U;
				#else
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0xFFFFFFFFU);
					pu8Buffer += 4U;
				#endif


				//DAQ
				vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0U);
				pu8Buffer += 4U;

				//laser contrast sensors
				//Top Level
				#if C_LOCALDEF__LCCM655__ENABLE_LASER_CONTRAST == 1U
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, sFCU.sContrast.sFaultFlags.u32Flags[0]);
					pu8Buffer += 4U;

					//each sensor
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, sFCU.sContrast.sSensors[0].sFaultFlags.u32Flags[0]);
					pu8Buffer += 4U;
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, sFCU.sContrast.sSensors[1].sFaultFlags.u32Flags[0]);
					pu8Buffer += 4U;
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, sFCU.sContrast.sSensors[2].sFaultFlags.u32Flags[0]);
					pu8Buffer += 4U;
				#else
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0xFFFFFFFFU);
					pu8Buffer += 4U;
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0xFFFFFFFFU);
					pu8Buffer += 4U;
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0xFFFFFFFFU);
					pu8Buffer += 4U;
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0xFFFFFFFFU);
					pu8Buffer += 4U;
				#endif



				//laser distance
				#if C_LOCALDEF__LCCM655__ENABLE_LASER_OPTONCDT == 1U
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0U);
					pu8Buffer += 4U;

					//optos, top level
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, sFCU.sLaserOpto.sFaultFlags.u32Flags[0]);
					pu8Buffer += 4U;

					for(u8Counter = 0U; u8Counter < C_FCU__NUM_LASERS_OPTONCDT; u8Counter++)
					{
						vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, sFCU.sLaserOpto.sOptoLaser[u8Counter].sFaultFlags.u32Flags[0]);
						pu8Buffer += 4U;

					}
				#else
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0xFFFFFFFFU);
					pu8Buffer += 4U;

					//optos, top level
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0xFFFFFFFFU);
					pu8Buffer += 4U;

					for(u8Counter = 0U; u8Counter < C_FCU__NUM_LASERS_OPTONCDT; u8Counter++)
					{
						vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0xFFFFFFFFU);
						pu8Buffer += 4U;

					}
				#endif

				//10
				//networking
				vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0U);
				pu8Buffer += 4U;

				//pusher
				#if C_LOCALDEF__LCCM655__ENABLE_PUSHER == 1U
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, sFCU.sPusher.sFaultFlags.u32Flags[0]);
					pu8Buffer += 4U;
				#else
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0xFFFFFFFFU);
					pu8Buffer += 4U;
				#endif

				//Throttle Subsystem
				#if C_LOCALDEF__LCCM655__ENABLE_THROTTLE == 1U
				//AMC7812
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, u32AMC7812__Get_FaultFlags());
					pu8Buffer += 4U;
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, sFCU.sThrottle.sFaultFlags.u32Flags[0]);
					pu8Buffer += 4U;
				#else
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0xFFFFFFFFU);
					pu8Buffer += 4U;
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0xFFFFFFFFU);
					pu8Buffer += 4U;
				#endif

				//pod health
				#if C_LOCALDEF__LCCM655__ENABLE_POD_HEALTH == 1U
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, sFCU.sPodHealth.sHealthFlags.u32Flags[0]);
					pu8Buffer += 4U;
				#elif C_LOCALDEF__LCCM655__ENABLE_POD_HEALTH == 0U
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0U);
					pu8Buffer += 4U;
				#else
					#error
				#endif
				vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0U);
				pu8Buffer += 4U;
				vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0U);
				pu8Buffer += 4U;
				vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0U);
				pu8Buffer += 4U;

				//Flight control system
				vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0U);
				pu8Buffer += 4U;

				#if C_LOCALDEF__LCCM655__ENABLE_TRACK_DB == 1U
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, sFCU.sFlightControl.sTrackDB.sFaultFlags.u32Flags[0]);
					pu8Buffer += 4U;
				#else
					vSIL3_NUM_CONVERT__Array_U32(pu8Buffer, 0xFFFFFFFF);
					pu8Buffer += 4U;
				#endif




				break;

			default:

				break;

		}//switch(ePacketType)

		//send it
		vSIL3_SAFEUDP_TX__Commit(u8BufferIndex, u16Length, C_RLOOP_NET_PORT__FCU, C_RLOOP_NET_PORT__FCU);

	}//if(s16Return == 0)
	else
	{
		//fault

	}//else if(s16Return == 0)

}



#endif //C_LOCALDEF__LCCM655__ENABLE_ETHERNET
#endif //C_LOCALDEF__LCCM655__ENABLE_FLIGHT_CONTROL
#endif //#if C_LOCALDEF__LCCM655__ENABLE_THIS_MODULE == 1U
//safetys
#ifndef C_LOCALDEF__LCCM655__ENABLE_THIS_MODULE
	#error
#endif
/** @} */
/** @} */
/** @} */
