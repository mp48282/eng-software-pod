/**
 * @file		eeprom_params.h
 * @brief		eeprom paramters header
 * @author		Lachlan Grogan
 * @copyright	This file contains proprietary and confidential information of the Lockie Group
 *				of companies, including SIL3 Pty. Ltd (ACN 123 529 064) and
 *				Lockie Safety Systems Pty. Ltd (ACN 132 340 571).  This code may be distributed
 *				under a license from the Lockie Group of companies, and may be used, copied
 *				and/or disclosed only pursuant to the terms of that license agreement.
 *				This copyright notice must be retained as part of this file at all times.
 * @copyright	This file is copyright SIL3 Pty Ltd 2003-2012, All Rights Reserved.
 * @copyright	This file is copyright Lockie Safety Systems Pty Ltd 2008-2012, All Rights Reserved.
 * @st_fileID	LCCM188R0.FILE.002
 */

 
#ifndef _EEPROM_PARAMETERS_H_
#define _EEPROM_PARAMETERS_H_

	#include <localdef.h>
	#if C_LOCALDEF__LCCM188__ENABLE_THIS_MODULE == 1U

		/*******************************************************************************
		Includes
		*******************************************************************************/
		#include <MULTICORE/LCCM118__MULTICORE__NUMERICAL/numerical.h>
		#include <MULTICORE/LCCM118__MULTICORE__NUMERICAL/numerical__structs.h>

		//#define C_LOCALDEF__LCCM188_DELAYED_WRITE								1U
		//#define C_LOCALDEF__LCCM188_IMMEDIATE_WRITE								0U

		/*******************************************************************************
		Types
		*******************************************************************************/
		/** Write delay types */
		typedef enum
		{

			/** Write immedate */
			DELAY_T__IMMEDIATE_WRITE = 0U,

			/** Write delayed */
			DELAY_T__DELAYED_WRITE = 1U

		}E_EEPROM_PARAMS__DELAY_T;


		#ifndef C_LOCALDEF__LCCM188__USE_WITH_LCCM013
			#error
		#endif

		#if C_LOCALDEF__LCCM188__USE_WITH_LCCM013 == 1U
			//do nothing
		#else //#if C_LOCALDEF__LCCM188__USE_WITH_LCCM013 == 1U
	
			#if (C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__PIC18F1220 == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__PIC18F25K20 == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__PIC18F25K80 == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__PIC18F46K20 == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__PIC18F8621 == 1U)
				//eeprom routines (pic18)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U8(addx,val,delay)		vPIC18_EEPROM__Write((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx,val)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_U8(addx)			u8PIC18_EEPROM__Read((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx)
				
				#if C_LOCALDEF__LCCM188__DISABLE__U16 != 1U
					#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U16(addx,val,delay)		vPIC18_EEPROM__WriteU16((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx,val)
					#define C_LOCALDEF__LCCM188__EEPROM_READ_U16(addx)			u16PIC18_EEPROM__Read((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx)
				#endif //C_LOCALDEF__LCCM188__DISABLE__U16
				
				#if C_LOCALDEF__LCCM188__DISABLE__S16 != 1U
					#define C_LOCALDEF__LCCM188__EEPROM_WRITE_S16(addx,val,delay)		vPIC18_EEPROM__WriteS16((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx,val)
					#define C_LOCALDEF__LCCM188__EEPROM_READ_S16(addx)			s16PIC18_EEPROM__Read((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx)
				#endif //C_LOCALDEF__LCCM188__DISABLE__S16
				
				#if C_LOCALDEF__LCCM188__DISABLE__U32 != 1U
					#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U32(addx,val,delay)		vPIC18_EEPROM__WriteU32((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx,val)
					#define C_LOCALDEF__LCCM188__EEPROM_READ_U32(addx)			u32PIC18_EEPROM__Read((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx)
				#endif //C_LOCALDEF__LCCM188__DISABLE__U32
				
				#if C_LOCALDEF__LCCM188__DISABLE__S32 != 1U
					#define C_LOCALDEF__LCCM188__EEPROM_WRITE_S32(addx,val,delay)		vPIC18_EEPROM__WriteS32((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx,val)
					#define C_LOCALDEF__LCCM188__EEPROM_READ_S32(addx)			s32PIC18_EEPROM__Read((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx)
				#endif //C_LOCALDEF__LCCM188__DISABLE__S32
				
				#if C_LOCALDEF__LCCM188__DISABLE__F32 != 1U
					#define C_LOCALDEF__LCCM188__EEPROM_WRITE_F32(addx,val,delay)		vPIC18_EEPROM__WriteF32((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx,val)
					#define C_LOCALDEF__LCCM188__EEPROM_READ_F32(addx)			f32PIC18_EEPROM__Read((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx)
				#endif //C_LOCALDEF__LCCM188__DISABLE__F32
			
			#elif (C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__PIC32MX575F256L == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__PIC32MX460F512L == 1U)
				//eeprom routines (pic32)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U8(addx,val,delay)		vPIC32_NVM__WriteU32((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx, (Luint32)val)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U16(addx,val,delay)		vPIC32_NVM__WriteU32((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx, (Luint32)val)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_S16(addx,val,delay)		vPIC32_NVM__WriteS32((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx, (Lint32)val)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U32(addx,val,delay)		vPIC32_NVM__WriteU32((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx, val)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_S32(addx,val,delay)		vPIC32_NVM__WriteS32((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx, val)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_F32(addx,val,delay)		vPIC32_NVM__WriteF32((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx, val)
				
				#define C_LOCALDEF__LCCM188__EEPROM_READ_U8(addx)			(Luint8)u32PIC32_NVM__Read((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_U16(addx)			(Luint16)u32PIC32_NVM__Read((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_S16(addx)			(Lint16)s32PIC32_NVM__Read((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_U32(addx)			u32PIC32_NVM__Read((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_S32(addx)			s32PIC32_NVM__Read((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_F32(addx)			f32PIC32_NVM__Read((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx)
	
			#elif (C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__DSPIC33FJ128GP802_ISO == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__DSPIC33FJ128GP802_IMM == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__DSPIC33FJ256GP506_IPT == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__DSPIC33FJ128MC802_IMM == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__DSPIC33FJ128MC802_ISO == 1U)
				//eeprom routines (dsPIC)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U8(addx,val,delay)		vDSPIC_EFLASH__WriteU16((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx, (Luint16)val)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U16(addx,val,delay)		vDSPIC_EFLASH__WriteU16((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx, (Luint16)val)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_S16(addx,val,delay)		vDSPIC_EFLASH__WriteS16((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx, (Lint16)val)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U32(addx,val,delay)		vDSPIC_EFLASH__WriteU32((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx, val)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_S32(addx,val,delay)		vDSPIC_EFLASH__WriteS32((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx, val)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_F32(addx,val,delay)		vDSPIC_EFLASH__WriteF32((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx, val)
				
				#define C_LOCALDEF__LCCM188__EEPROM_READ_U8(addx)			(Luint8)u16DSPIC_EFLASH__Read((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_U16(addx)			(Luint16)u16DSPIC_EFLASH__Read((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_S16(addx)			(Lint16)s16DSPIC_EFLASH__Read((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_U32(addx)			u32DSPIC_EFLASH__Read((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_S32(addx)			s32DSPIC_EFLASH__Read((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_F32(addx)			f32DSPIC_EFLASH__Read((Luint16)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint16)addx)
	
			#elif (C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__RM42L432 == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__RM46L852 == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__RM48L952 == 1U || C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__RM57L843 == 1U)
				//eeprom routines (RM4)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U8(addx,val,delay)		vRM4_EEPROM__WriteU32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, (Luint32)val, delay)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U16(addx,val,delay)		vRM4_EEPROM__WriteU32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, (Luint32)val, delay)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_S16(addx,val,delay)		vRM4_EEPROM__WriteS32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, (Lint32)val, delay)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U32(addx,val,delay)		vRM4_EEPROM__WriteU32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, val, delay)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_S32(addx,val,delay)		vRM4_EEPROM__WriteS32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, val, delay)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_F32(addx,val,delay)		vRM4_EEPROM__WriteF32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, val, delay)
	
				#define C_LOCALDEF__LCCM188__EEPROM_READ_U8(addx)			(Luint8)u32RM4_EEPROM__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_U16(addx)			(Luint16)u32RM4_EEPROM__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_S16(addx)			(Lint16)s32RM4_EEPROM__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_U32(addx)			u32RM4_EEPROM__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_S32(addx)			s32RM4_EEPROM__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_F32(addx)			f32RM4_EEPROM__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
	
			#elif C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__WIN32 == 1U
				//eeprom routines (WIN32)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U8(addx,val,delay)		vSIL3_EEPARAM_WIN32__WriteU32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, (Luint32)val)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U16(addx,val,delay)		vSIL3_EEPARAM_WIN32__WriteU32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, (Luint32)val)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_S16(addx,val,delay)		vSIL3_EEPARAM_WIN32__WriteS32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, (Lint32)val)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U32(addx,val,delay)		vSIL3_EEPARAM_WIN32__WriteU32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, val)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_S32(addx,val,delay)		vSIL3_EEPARAM_WIN32__WriteS32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, val)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_F32(addx,val,delay)		vSIL3_EEPARAM_WIN32__WriteF32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, val)
	
				#define C_LOCALDEF__LCCM188__EEPROM_READ_U8(addx)			(Luint8)u32SIL3_EEPARAM_WIN32__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_U16(addx)			(Luint16)u32SIL3_EEPARAM_WIN32__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_S16(addx)			(Lint16)s32SIL3_EEPARAM_WIN32__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_U32(addx)			u32SIL3_EEPARAM_WIN32__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_S32(addx)			s32SIL3_EEPARAM_WIN32__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_F32(addx)			f32SIL3_EEPARAM_WIN32__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				
			#elif (C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__MSP430F5529 == 1U) || (C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__MSP430F5659 == 1U)
				//eeprom routines (MSP430)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U8(addx,val,delay)		vMSP430_EEPROM__WriteU32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, (Luint32)val, (TE_MSP430__FLASH_DELAY)delay)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U16(addx,val,delay)		vMSP430_EEPROM__WriteU32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, (Luint32)val, (TE_MSP430__FLASH_DELAY)delay)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_S16(addx,val,delay)		vMSP430_EEPROM__WriteS32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, (Lint32)val, (TE_MSP430__FLASH_DELAY)delay)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U32(addx,val,delay)		vMSP430_EEPROM__WriteU32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, val, (TE_MSP430__FLASH_DELAY)delay)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_S32(addx,val,delay)		vMSP430_EEPROM__WriteS32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, val, (TE_MSP430__FLASH_DELAY)delay)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_F32(addx,val,delay)		vMSP430_EEPROM__WriteF32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, val, (TE_MSP430__FLASH_DELAY)delay)

				#define C_LOCALDEF__LCCM188__EEPROM_READ_U8(addx)			(Luint8)u32MSP430_EEPROM__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_U16(addx)			(Luint16)u32MSP430_EEPROM__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_S16(addx)			(Lint16)s32MSP430_EEPROM__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_U32(addx)			u32MSP430_EEPROM__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_S32(addx)			s32MSP430_EEPROM__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_F32(addx)			f32MSP430_EEPROM__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
			#elif (C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__CC1310 == 1U) || (C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__CC1350 == 1U) || (C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__CC2650 == 1U)
				//eeprom routines (MSP430)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U8(addx,val,delay)		vCC2650_EEPROM__WriteU32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, (Luint32)val, (TE_CC2650__FLASH_DELAY)delay)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U16(addx,val,delay)		vCC2650_EEPROM__WriteU32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, (Luint32)val, (TE_CC2650__FLASH_DELAY)delay)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_S16(addx,val,delay)		vCC2650_EEPROM__WriteS32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, (Lint32)val, (TE_CC2650__FLASH_DELAY)delay)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_U32(addx,val,delay)		vCC2650_EEPROM__WriteU32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, val, (TE_CC2650__FLASH_DELAY)delay)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_S32(addx,val,delay)		vCC2650_EEPROM__WriteS32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, val, (TE_CC2650__FLASH_DELAY)delay)
				#define C_LOCALDEF__LCCM188__EEPROM_WRITE_F32(addx,val,delay)		vCC2650_EEPROM__WriteF32((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx, val, (TE_CC2650__FLASH_DELAY)delay)

				#define C_LOCALDEF__LCCM188__EEPROM_READ_U8(addx)			(Luint8)u32CC2650_EEPROM__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_U16(addx)			(Luint16)u32CC2650_EEPROM__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_S16(addx)			(Lint16)s32CC2650_EEPROM__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_U32(addx)			u32CC2650_EEPROM__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_S32(addx)			s32CC2650_EEPROM__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)
				#define C_LOCALDEF__LCCM188__EEPROM_READ_F32(addx)			f32CC2650_EEPROM__Read((Luint32)C_LOCALDEF__LCCM188__EEPROM_START_OFFSET + (Luint32)addx)

			#else
				#error
			#endif
		#endif //#if C_LOCALDEF__LCCM188__USE_WITH_LCCM013 == 1U

		/*****************************************************************************
		Structures
		*****************************************************************************/
		struct _strEEPARAM
		{
			//if set to 1 any updated will be delayed
			//until the user so requests.  This can be used
			//to control memory flogging that could occur during
			//large updates (writes) and consequential memory life
			//shortening.
			Luint8 u8DelayUpdate;

		};

		/*******************************************************************************
		Function Prototypes
		*******************************************************************************/
		void vSIL3_EEPARAM__Init(void);
		Luint8 u8SIL3_EEPARAM__Read(Luint16 u16Index);
		Luint16 u16SIL3_EEPARAM__Read(Luint16 u16Index);
		Lint16 s16SIL3_EEPARAM__Read(Luint16 u16Index);
		Luint32 u32SIL3_EEPARAM__Read(Luint16 u16Index);
		Lint32 s32SIL3_EEPARAM__Read(Luint16 u16Index);
		Lfloat32 f32SIL3_EEPARAM__Read(Luint16 u16Index);

		void vSIL3_EEPARAM__WriteU8(Luint16 u16Index, Luint8 u8Value, E_EEPROM_PARAMS__DELAY_T eDelay);
		void vSIL3_EEPARAM__WriteU16(Luint16 u16Index, Luint16 u16Value, E_EEPROM_PARAMS__DELAY_T eDelay);
		void vSIL3_EEPARAM__WriteS16(Luint16 u16Index, Lint16 s16Value, E_EEPROM_PARAMS__DELAY_T eDelay);
		void vSIL3_EEPARAM__WriteU32(Luint16 u16Index, Luint32 u32Value, E_EEPROM_PARAMS__DELAY_T eDelay);
		void vSIL3_EEPARAM__WriteS32(Luint16 u16Index, Lint32 s32Value, E_EEPROM_PARAMS__DELAY_T eDelay);
		void vSIL3_EEPARAM__WriteF32(Luint16 u16Index, Lfloat32 f32Value, E_EEPROM_PARAMS__DELAY_T eDelay);

		#if C_LOCALDEF__LCCM188__ENABLE_VECTORS == 1U
			void vEEPARAM__Write_VS32(Luint16 u16Index, sNUM_s32Vector_3D *pvs32Value, E_EEPROM_PARAMS__DELAY_T eDelay);
			void vs32EEPARAM__Read(Luint16 u16Index, sNUM_s32Vector_3D *pvs32Value);
			void vEEPARAM__Write_VF32(Luint16 u16Index, sNUM_f32Vector_3D *pvf32Value, E_EEPROM_PARAMS__DELAY_T eDelay);
			void vf32EEPARAM__Read(Luint16 u16Index, sNUM_f32Vector_3D *pvf32Value);
		#endif

		//MAC
		void vSIL3_EEPARAM_MAC__Read_MAC8(Luint16 u16Index, Luint8 *pu8MAC);
		void vSIL3_EEPARAM_MAC__Write_MAC8(Luint16 u16Index, const Luint8 *pu8MAC, E_EEPROM_PARAMS__DELAY_T eDelay);

		#if C_LOCALDEF__LCCM188__ENABLE_CRC == 1U
			Luint8 u8SIL3_EEPARAM_CRC__Is_CRC_OK(Luint16 u16StartIndex, Luint16 u16EndIndex, Luint16 u16CRCIndex);
			Luint16 u16SIL3_EEPARAM_CRC__CalculateCRC(Luint16 u16StartIndex, Luint16 u16EndIndex);
			void vSIL3_EEPARAM_CRC__Calculate_And_Store_CRC(Luint16 u16StartIndex, Luint16 u16EndIndex, Luint16 u16CRCIndex);
		#endif //C_LOCALDEF__LCCM188__ENABLE_CRC

		#if C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__WIN32 == 1U
			void vSIL3_EEPARAM_WIN32__WriteU32(Luint32 u32Addx, Luint32 u32Val);
			void vSIL3_EEPARAM_WIN32__WriteS32(Luint32 u32Addx, Lint32 s32Val);
			void vSIL3_EEPARAM_WIN32__WriteF32(Luint32 u32Addx, Lfloat32 f32Val);
			Luint32 u32SIL3_EEPARAM_WIN32__Read(Luint32 u32Addx);
			Lint32 s32SIL3_EEPARAM_WIN32__Read(Luint32 u32Addx);
			Lfloat32 f32SIL3_EEPARAM_WIN32__Read(Luint32 u32Addx);
		#endif
		
		/*******************************************************************************
		Unit Test Prototypes
		*******************************************************************************/
		#if C_LOCALDEF__LCCM188__ENABLE_TEST_SPEC == 1U
			DLL_DECLARATION void vLCCM188_TS_001(void);
			DLL_DECLARATION void vLCCM188_TS_002(void);
			DLL_DECLARATION void vLCCM188_TS_003(void);
			DLL_DECLARATION void vLCCM188_TS_004(void);
			DLL_DECLARATION void vLCCM188_TS_005(void);
			DLL_DECLARATION void vLCCM188_TS_006(void);
			DLL_DECLARATION void vLCCM188_TS_007(void);
			DLL_DECLARATION void vLCCM188_TS_008(void);
			DLL_DECLARATION void vLCCM188_TS_009(void);
			DLL_DECLARATION void vLCCM188_TS_010(void);
			DLL_DECLARATION void vLCCM188_TS_011(void);
			DLL_DECLARATION void vLCCM188_TS_012(void);
			DLL_DECLARATION void vLCCM188_TS_013(void);
			DLL_DECLARATION void vLCCM188_TS_017(void);
			DLL_DECLARATION void vLCCM188_TS_018(void);
			DLL_DECLARATION void vLCCM188_TS_019(void);
			DLL_DECLARATION void vLCCM188R0_TS_021(void);
			DLL_DECLARATION void vLCCM188R0_TS_022(void);
			DLL_DECLARATION void vLCCM188R0_TS_024(void);

	
		#endif //C_LOCALDEF__LCCM188__ENABLE_TEST_SPEC
	
		/*******************************************************************************
		Safetys
		*******************************************************************************/
		#ifndef C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__PIC18F1220
			#error
		#endif
		#ifndef C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__PIC32MX575F256L
			#error
		#endif
		#ifndef C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__DSPIC33FJ128GP802_ISO
			#error
		#endif
		#ifndef C_LOCALDEF__SIL3_GENERIC__CPU_TYPE__RM42L432
			#error
		#endif

	#endif
	#ifndef C_LOCALDEF__LCCM188__ENABLE_THIS_MODULE
		#error
	#endif

#endif //_EEPROM_PARAMETERS_H_
