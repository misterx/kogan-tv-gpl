////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2006-2007 MStar Semiconductor, Inc.
// All rights reserved.
//
// Unless otherwise stipulated in writing, any and all information contained
// herein regardless in any format shall remain the sole proprietary of
// MStar Semiconductor Inc. and be kept in strict confidence
// (��MStar Confidential Information��) by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////


#ifndef _BD_S5_CUS03_DEMO_BOARD_1_H
#define _BD_S5_CUS03_DEMO_BOARD_1_H


//External crystal clock
#define XTAL_RTC_CLOCK_FREQ         CRYSTAL_32768
#define XTAL_CLOCK_FREQ             12000000    //12 MHz
#define MCU_XTAL_CLK_HZ             (XTAL_CLOCK_FREQ*MCU_PLL_MUL) // Hz
#define MCU_XTAL_CLK_KHZ            (MCU_XTAL_CLK_HZ / 1000)
#define MCU_XTAL_CLK_MHZ            (MCU_XTAL_CLK_KHZ / 1000)


//------Tuner Setting----------------------------------------
#define TS_CLK_INV                      0
#define TS_PARALLEL_OUTPUT              1
#define FRONTEND_DEMOD_TYPE             ZARLINK_ZL10353_DEMODE
#define FRONTEND_TUNER_TYPE             PHILIPS_FQD1216_TUNER//PHILIPS_TDA1316_TUNER //PHILIPS_FQD1216_TUNER

//------Peripheral Device Setting----------------------------
#ifndef IR_TYPE_SEL
#define IR_TYPE_SEL                 IR_TYPE_MSTAR_DTV
#endif

//------Power Setting----------------------------------------


//------Memory Setting---------------------------------------


//------OSD & EPG--------------------------------------------


//------CC & TT----------------------------------------------


//------SVD----------------------------------------------
#define SVD_CLOCK_SEL               SVD_CLOCK_250MHZ
//------Analog Function Setting------------------------------


//------Extra------------------------------------------------
#define CUS03_DEMO_BOARD   //If you are using MSTAR's demo board, you need to unmark "CUS03_DEMO_BOARD" define
#if defined(CUS03_DEMO_BOARD)
#define CUS03_BOARD 1

/*------------------------------------Temp define here for MSTAR--------------------------------------*/
#define S5_AUDIO_PATH_SETTING

#define AUDIO_SOURCE_DTV                AUDIO_DSP1_DVB_INPUT
#define AUDIO_SOURCE_DTV2                  AUDIO_DSP2_DVB_INPUT
#define AUDIO_SOURCE_ATV                  AUDIO_DSP2_SIF_INPUT
#define AUDIO_SOURCE_PC                    AUDIO_AUIN4_INPUT//AUDIO_AUIN0_INPUT
#define AUDIO_SOURCE_YPBPR              AUDIO_AUIN3_INPUT//AUDIO_AUIN4_INPUT
#define AUDIO_SOURCE_YPBPR2            AUDIO_AUIN4_INPUT
#define AUDIO_SOURCE_AV                    AUDIO_AUIN2_INPUT//AUDIO_AUIN1_INPUT
#define AUDIO_SOURCE_AV2                  AUDIO_AUIN1_INPUT
#define AUDIO_SOURCE_AV3                  AUDIO_AUIN1_INPUT
#define AUDIO_SOURCE_SV                    AUDIO_AUIN2_INPUT
#define AUDIO_SOURCE_SV2                  AUDIO_AUIN2_INPUT
#define AUDIO_SOURCE_SCART1              AUDIO_AUIN0_INPUT//AUDIO_AUIN0_INPUT
#define AUDIO_SOURCE_SCART2             AUDIO_AUIN1_INPUT//AUDIO_AUIN0_INPUT
#define AUDIO_SOURCE_HDMI               AUDIO_HDMI_INPUT
#define AUDIO_SOURCE_HDMI2              AUDIO_HDMI_INPUT
#define AUDIO_SOURCE_HDMI3              AUDIO_HDMI_INPUT
#define AUDIO_SOURCE_DVI                   AUDIO_AUIN3_INPUT
#define AUDIO_SOURCE_DVI2                 AUDIO_AUIN3_INPUT
#define AUDIO_SOURCE_DVI3                 AUDIO_AUIN3_INPUT
#define AUDIO_SOURCE_AM_MONO         AUDIO_AUIN5_INPUT
#define AUDIO_SOURCE_SPDIF               AUDIO_SPDIF_INPUT

#define AUDIO_PATH_MAIN_SPEAKER    AUDIO_PATH_0
#define AUDIO_PATH_HP                        AUDIO_PATH_1//AUDIO_PATH_0
#define AUDIO_PATH_SCART1                AUDIO_PATH_2//AUDIO_PATH_1
#define AUDIO_PATH_SCART2                AUDIO_PATH_3//AUDIO_PATH_2
#define AUDIO_PATH_LINEOUT              AUDIO_PATH_1
#define AUDIO_PATH_SIFOUT                AUDIO_PATH_2
#define AUDIO_PATH_I2S                       AUDIO_PATH_1
#define AUDIO_PATH_SPDIF                   AUDIO_PATH_3

 #define AUDIO_OUTPUT_MAIN_SPEAKER   AUDIO_I2S_OUTPUT//AUDIO_AUOUT0_OUTPUT
 #define AUDIO_OUTPUT_HP                       AUDIO_AUOUT0_OUTPUT
 #define AUDIO_OUTPUT_SCART1               AUDIO_AUOUT1_OUTPUT//AUDIO_AUOUT2_OUTPUT
 #define AUDIO_OUTPUT_SCART2               AUDIO_AUOUT2_OUTPUT//AUDIO_AUOUT1_OUTPUT       // always output SIF
 #define AUDIO_OUTPUT_LINEOUT             AUDIO_I2S_OUTPUT       // As SCART1
 #define AUDIO_OUTPUT_SIFOUT             AUDIO_AUOUT1_OUTPUT
/*------------------------------------Temp define here for MSTAR--------------------------------------*/
#endif
//------ EEPROM ----------------------------------------------------------------


//------ MEMORY MAP 8051 ---------------------------------------------------------
#define MMAP_8051_TYPE_SEL          MMAP_8051_CFG_1


//------ MEMORY MAP 8051 LITE ----------------------------------------------------
#define MMAP_8051_LITE_TYPE_SEL     MMAP_8051_LITE_CFG_1


//------ MEMORY MAP AEON ---------------------------------------------------------
#define MMAP_AEON_TYPE_SEL          MMAP_AEON_CFG_1

//------Function to PIN mapping ------------------------------------------------
#define PIN_UART1                   0
#define PIN_UART2                   PADS_UART2_MODE1

//#define PIN_I2S_OUT_MUTE            BALL_AA15
#define PIN_I2S_OUT_MUTE            0

#define PIN_I2S_IN                  PADS_I2S
#define PIN_I2S_OUT                 PADS_I2S
#define PIN_SPDIF_IN                BALL_AD9
#define PIN_SPDIF_OUT               BALL_AB12
#define PIN_TS0                     PADS_TS0
#define PIN_TS1                     PADS_TS1
#define PIN_MIIC                    PADS_DDCR
#define PIN_PCMCIA                  PADS_PCM
#define PIN_PF                      PADS_PF

#if 0 /* SDIO and ET is mutal exclusive, board need to be rework */
#define PIN_WF                      PADS_WF_MODE1
#define PIN_ET                      0
#else
#define PIN_WF                      0
#define PIN_ET                      PADS_ET_MODE0
#endif

// SPI_CSN_2 is wrong, need to rework
#define PIN_FLASH_WP0               BALL_F5

#define PIN_PF_WP0                  BALL_E5         // not used yet

//------GPIO setting------------------------------------------------------------
//#define BALL_AA24_IS_GPIO           GPIO_OUT_LOW    // POWER_SW     High: turn off
#define BALL_A17_IS_GPIO            GPIO_OUT_HIGH   // AMP_STB      High: mute
#define BALL_AA16_IS_GPIO           GPIO_OUT_HIGH   // MUTE_S       Low:  mute
//#define BALL_AC16_IS_GPIO           GPIO_OUT_HIGH   // MUTE_POP EAR-OUT FIXME
#define BALL_F5_IS_GPIO             GPIO_OUT_HIGH   // FLASH_WPN    Low - protector
#define BALL_AB21_IS_GPIO           GPIO_OUT_HIGH   // Panel_ON     High: Off
#define BALL_AB18_IS_GPIO           GPIO_OUT_HIGH   // VBLCTRL      High: Off
#define BALL_AC23_IS_GPIO           GPIO_IN         // USB_OCD
#define BALL_K1_IS_GPIO             GPIO_IN         // M-LINK SW I2C
#define BALL_K3_IS_GPIO             GPIO_IN         // M-LINK SW I2C
#define BALL_AA18_IS_GPIO           GPIO_OUT_LOW    // PCM_PWR_CTL  Low:  Off
#define BALL_AB10_IS_GPIO           GPIO_IN         // MS_INS, FIXME
#define BALL_AA12_IS_GPIO           GPIO_IN         // ETH-RST, FIXME
// Audio Amplifier
#define Audio_Amplifier_ON()             MDrv_GPIO_Set_High(12);MDrv_GPIO_Set_Low(42)
#define Audio_Amplifier_OFF()            MDrv_GPIO_Set_High(12);MDrv_GPIO_Set_Low(42)


#ifdef CUS03_BOARD
#define HeadPhone_ON()                      MDrv_GPIO_Set_High(96)
#define HeadPhone_OFF()                     MDrv_GPIO_Set_Low(96)
#define CUS03_AMP_MUTE_ON()                MDrv_GPIO_Set_High(90)
#define CUS03_AMP_MUTE_OFF()               MDrv_GPIO_Set_Low(90)
#endif
//------Chip Type---------------------------------------------------------------
//#include "chip/msd3102eq.h"
#include "chip/msd3108ev.h"

//------MIU setting ----------------------------------------------------------------
#define MIU_0_02                        0x0545
#define MIU_1_02                        0x0545
#define MIU_0_36                        0x0241
#define MIU_0_38                        0x0010
#define ENABLE_MIU_1                    1
#define DDRII_ODT

//------ SYSTEM MEMORY MAP ---------------------------------------------------------
#if defined(CONFIG_MSTAR_TITANIA_MMAP_32MB)
#include "mmap/mmap_32mb.h"
#elif defined(CONFIG_MSTAR_TITANIA_MMAP_64MB)
#include "mmap/mmap_64mb.h"
#elif defined(CONFIG_MSTAR_TITANIA_MMAP_32MB_32MB)
#include "mmap/mmap_32mb_32mb.h"
#elif defined(CONFIG_MSTAR_TITANIA_MMAP_64MB_32MB)
#include "mmap/mmap_64mb_32mb.h"
#elif defined(CONFIG_MSTAR_TITANIA_MMAP_64MB_64MB)
#include "mmap/mmap_64mb_64mb.h"
#elif defined(CONFIG_MSTAR_TITANIA_MMAP_128MB_128MB)
#include "mmap/mmap_128mb_128mb.h"
#elif defined(CONFIG_MSTAR_TITANIA_MMAP_4MB_FLASH)
#endif

//------ SCALER INPUT SOURCE MUX ---------------------------------------------------
#define SC_VGA_AMUX         0x1
#define SC_YPBPR_AMUX       0x2
#define SC_ATV_YMUX         0x0
#define SC_ATV_CMUX         0xF
#define SC_CVBS_YMUX        0x3
#define SC_CVBS_CMUX        0xF
#define SC_SVIDEO_YMUX      0x4
#define SC_SVIDEO_CMUX      0x6
#define SC_SCART1_YMUX      0x1
#define SC_SCART1_CMUX      0x0
#define SC_SCART2_YMUX      0x2
#define SC_SCART2_CMUX      0x0

#endif // _BD_S5_CUS03_DEMO_BOARD_1_H
