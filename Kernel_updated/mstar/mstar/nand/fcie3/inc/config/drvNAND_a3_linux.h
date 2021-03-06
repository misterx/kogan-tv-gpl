#ifndef __UNFD_A3_LINUX_H__
#define __UNFD_A3_LINUX_H__

#include <linux/delay.h>
#include <linux/mm.h>
#include <linux/highmem.h>
#include <linux/string.h>
#include <linux/slab.h>
#include <linux/dma-mapping.h>
#include <linux/interrupt.h>
#include <linux/sched.h>
#include <asm/io.h>
#include <asm/memory.h>
#include <mach/io.h>

#define REG_BANK_CLKGEN						(0x580)
#define REG_BANK_CHIPTOP					(0xF00)
#define REG_BANK_FCIE0						(0x8980)
#define REG_BANK_FCIE2						(0x8A00)
#define REG_BANK_TIMER0						(0x1800)

#define RIU_PM_BASE							(IO_ADDRESS(0x1F000000))
#define RIU_BASE							(IO_ADDRESS(0x1F200000))

#define REG(Reg_Addr)						(*(volatile U16*)(Reg_Addr))
#define REG_OFFSET_SHIFT_BITS				2
#define GET_REG_ADDR(x, y)					(x+((y)<<REG_OFFSET_SHIFT_BITS))

#define REG_WRITE_UINT16(reg_addr, val)		REG(reg_addr) = val
#define REG_READ_UINT16(reg_addr, val)		val = REG(reg_addr)
#define HAL_WRITE_UINT16(reg_addr, val)		(REG(reg_addr) = val)
#define HAL_READ_UINT16(reg_addr, val)		val = REG(reg_addr)
#define REG_SET_BITS_UINT16(reg_addr, val)	REG(reg_addr) |= (val)
#define REG_CLR_BITS_UINT16(reg_addr, val)	REG(reg_addr) &= ~(val)
#define REG_W1C_BITS_UINT16(reg_addr, val)	REG_WRITE_UINT16(reg_addr, REG(reg_addr)&(val))

#define MPLL_CLK_REG_BASE_ADDR				GET_REG_ADDR(RIU_BASE, REG_BANK_CLKGEN)
#define CHIPTOP_REG_BASE_ADDR				GET_REG_ADDR(RIU_BASE, REG_BANK_CHIPTOP)
#define FCIE_REG_BASE_ADDR					GET_REG_ADDR(RIU_BASE, REG_BANK_FCIE0)
#define FCIE_NC_CIFD_BASE					GET_REG_ADDR(RIU_BASE, REG_BANK_FCIE2)
#define TIMER0_REG_BASE_ADDR				GET_REG_ADDR(RIU_PM_BASE, REG_BANK_TIMER0)

#define REG50_ECC_CTRL_INIT_VALUE			0

#define UNFD_ST_PLAT						0x80000000
#define IF_IP_VERIFY						0 // [CAUTION]: to verify IP and HAL code, defaut 0

// debug
#define FCIE3_DUMP_DEBUG_BUS				1

#define SPARE640B_CIFD512B_PATCH    		1

#if (defined(FCIE4_DDR) && FCIE4_DDR)
#define NC_SET_DDR_MODE()           REG_WRITE_UINT16(NC_DDR_CTRL, pNandDrv->u16_Reg58_DDRCtrl);
#define NC_CLR_DDR_MODE()           REG_CLR_BITS_UINT16(NC_DDR_CTRL, BIT_DDR_MASM);
#else
#define NC_SET_DDR_MODE()
#define NC_CLR_DDR_MODE()
#endif

#define NC_SEL_FCIE3						1
#if NC_SEL_FCIE3
#include "drvNAND_reg_v3.h"

#undef ECC_CODE_BYTECNT_4BIT
#undef ECC_CODE_BYTECNT_8BIT
#undef ECC_CODE_BYTECNT_20BIT
#undef ECC_CODE_BYTECNT_24BIT

#define ECC_CODE_BYTECNT_4BIT        8
#define ECC_CODE_BYTECNT_8BIT       14
#define ECC_CODE_BYTECNT_20BIT      34
#define ECC_CODE_BYTECNT_24BIT      40
#else
#error "Error! no FCIE registers selected."
#endif

#define IF_FCIE_SHARE_PINS					1 // 1: need to nand_pads_switch at HAL's functions.
#define IF_FCIE_SHARE_CLK					1 // 1: need to nand_clock_setting at HAL's functions.
#define IF_FCIE_SHARE_IP					1 // A3 might use SD

#define ENABLE_NAND_INTERRUPT_MODE			0

#define NAND_DRIVER_ROM_VERSION				0 // to save code size
#define AUTO_FORMAT_FTL						0

#define ENABLE_CUS_READ_ENHANCEMENT			0

#define __VER_UNFD_FTL__					0
//=====================================================
// Nand Driver configs
//=====================================================
#define NAND_BUF_USE_STACK					0
#define NAND_ENV_FPGA						1
#define NAND_ENV_ASIC						2
#ifdef __FPGA_MODE__	// currently G1 don't care this macro, even in ROM code
#define NAND_DRIVER_ENV						NAND_ENV_FPGA
#else
#define NAND_DRIVER_ENV						NAND_ENV_ASIC
#endif

#define UNFD_CACHE_LINE						0x80
//=====================================================
// tool-chain attributes
//=====================================================
#define UNFD_PACK0
#define UNFD_PACK1							__attribute__((__packed__))
#define UNFD_ALIGN0
#define UNFD_ALIGN1							__attribute__((aligned(UNFD_CACHE_LINE)))

//=====================================================
// debug option
//=====================================================
#define NAND_TEST_IN_DESIGN					0      /* [CAUTION] */

#ifndef NAND_DEBUG_MSG
#define NAND_DEBUG_MSG						1
#endif

/* Define trace levels. */
#define UNFD_DEBUG_LEVEL_ERROR				(1)    /* Error condition debug messages. */
#define UNFD_DEBUG_LEVEL_WARNING			(2)    /* Warning condition debug messages. */
#define UNFD_DEBUG_LEVEL_HIGH				(3)    /* Debug messages (high debugging). */
#define UNFD_DEBUG_LEVEL_MEDIUM				(4)    /* Debug messages. */
#define UNFD_DEBUG_LEVEL_LOW				(5)    /* Debug messages (low debugging). */

/* Higer debug level means more verbose */
#ifndef UNFD_DEBUG_LEVEL
#define UNFD_DEBUG_LEVEL					UNFD_DEBUG_LEVEL_WARNING
#endif

#if defined(NAND_DEBUG_MSG) && NAND_DEBUG_MSG
#define nand_print_tmt						//msPrintfFunc
#define nand_printf							printk
#define nand_debug(dbg_lv, tag, str, ...)				\
	do {												\
		if (dbg_lv > UNFD_DEBUG_LEVEL)				\
			break;									\
		else {										\
			if (tag)									\
			{                                       \
				nand_printf("[%s]\t",__func__);				\
				/*nand_print_tmt(__func__);*/				\
			}                                       \
													\
			nand_printf(str, ##__VA_ARGS__);			\
			/*nand_print_tmt(str, ##__VA_ARGS__);*/			\
		}											\
	} while(0)
#else /* NAND_DEBUG_MSG */
#define nand_printf(...)
#define nand_debug(enable, tag, str, ...)	{}
#endif /* NAND_DEBUG_MSG */

static __inline void nand_assert(int condition)
{
	if (!condition) {
        panic("%s\n UNFD Assert(%d)\n", __func__, __LINE__);
	}
}

#define nand_die() \
	do { \
		nand_assert(0); \
	} while(0);

#define nand_stop() \
	while(1)  nand_reset_WatchDog();

//=====================================================
// HW Timer for Delay
//=====================================================
#define TIMER0_ENABLE						GET_REG_ADDR(TIMER0_REG_BASE_ADDR, 0x20)
#define TIMER0_HIT							GET_REG_ADDR(TIMER0_REG_BASE_ADDR, 0x21)
#define TIMER0_MAX_LOW						GET_REG_ADDR(TIMER0_REG_BASE_ADDR, 0x22)
#define TIMER0_MAX_HIGH						GET_REG_ADDR(TIMER0_REG_BASE_ADDR, 0x23)
#define TIMER0_CAP_LOW						GET_REG_ADDR(TIMER0_REG_BASE_ADDR, 0x24)
#define TIMER0_CAP_HIGH						GET_REG_ADDR(TIMER0_REG_BASE_ADDR, 0x25)

#define HW_TIMER_DELAY_1us					1
#define HW_TIMER_DELAY_10us					10
#define HW_TIMER_DELAY_100us				100
#define HW_TIMER_DELAY_1ms					(1000 * HW_TIMER_DELAY_1us)
#define HW_TIMER_DELAY_5ms					(5    * HW_TIMER_DELAY_1ms)
#define HW_TIMER_DELAY_10ms					(10   * HW_TIMER_DELAY_1ms)
#define HW_TIMER_DELAY_100ms				(100  * HW_TIMER_DELAY_1ms)
#define HW_TIMER_DELAY_500ms				(500  * HW_TIMER_DELAY_1ms)
#define HW_TIMER_DELAY_1s					(1000 * HW_TIMER_DELAY_1ms)

extern void delay_us( unsigned us );
extern U32  nand_hw_timer_delay(U32 u32usTick);

//=====================================================
// Pads Switch
//=====================================================
#define reg_allpad_in						GET_REG_ADDR(CHIPTOP_REG_BASE_ADDR, 0x50)
#define reg_nf_en							GET_REG_ADDR(CHIPTOP_REG_BASE_ADDR, 0x6F)

extern U32 nand_pads_switch(U32 u32EnableFCIE);

//=====================================================
// set FCIE clock
//=====================================================
#define NFIE_CLK_MASK                       (BIT6|BIT5|BIT4|BIT3|BIT2)
#define NFIE_CLK_GLITCH_FREE_EN             (BIT6)
#define NFIE_CLK_XTAL                       (0)
#define NFIE_CLK_20M                        (BIT6|BIT2)
#define NFIE_CLK_27M                        (BIT6|BIT3)
#define NFIE_CLK_32M                        (BIT6|BIT3|BIT2)
#define NFIE_CLK_36M                        (BIT6|BIT4)
#define NFIE_CLK_40M                        (BIT6|BIT4|BIT2)
#define NFIE_CLK_43M                        (BIT6|BIT4|BIT3)
#define NFIE_CLK_54M                        (BIT6|BIT4|BIT3|BIT2)
#define NFIE_CLK_62M                        (BIT6|BIT5)
#define NFIE_CLK_72M                        (BIT6|BIT5|BIT2)
#define NFIE_CLK_80M                        (BIT6|BIT5|BIT3)
#define NFIE_CLK_86M                        (BIT6|BIT5|BIT3|BIT2)
#define NFIE_CLK_SSC                        (BIT6|BIT5|BIT4)
#define NFIE_CLK_300K                       (BIT6|BIT5|BIT4|BIT2)
#define NFIE_CLK_24M                        (BIT6|BIT5|BIT4|BIT3)
#define NFIE_CLK_48M                        (BIT6|BIT5|BIT4|BIT3|BIT2)

#define DUTY_CYCLE_PATCH					0 // 1: to enlarge low width for tREA's worst case of 25ns
#if DUTY_CYCLE_PATCH
#define FCIE3_SW_DEFAULT_CLK				NFIE_CLK_86M
#define FCIE_REG41_VAL						((2<<9)|(2<<3)) // RE,WR pulse, Low:High=3:1
#define REG57_ECO_FIX_INIT_VALUE			0
#else
#define FCIE3_SW_DEFAULT_CLK				NFIE_CLK_54M
#define FCIE_REG41_VAL						0               // RE,WR pulse, Low:High=1:1
#define REG57_ECO_FIX_INIT_VALUE			BIT_NC_LATCH_DATA_1_0_T	// delay 1.0T
#endif
#define FCIE3_SW_SLOWEST_CLK				NFIE_CLK_20M

#define NAND_SEQ_ACC_TIME_TOL				10 //in unit of ns

#define reg_ckg_fcie						GET_REG_ADDR(MPLL_CLK_REG_BASE_ADDR, 0x64)

extern U32  nand_clock_setting(U32 u32ClkParam);

extern void nand_DumpPadClk(void);

//=====================================================
// transfer DMA Address
//=====================================================
#define MIU_BUS_WIDTH_BITS					3 // Need to confirm
/*
 * Important:
 * The following buffers should be large enough for a whole NAND block
 */
// FIXME, this is only for verifing IP
#define DMA_W_ADDR							0x80C00000
#define DMA_R_ADDR							0x80D00000
#define DMA_W_SPARE_ADDR					0x80E00000
#define DMA_R_SPARE_ADDR					0x80E80000
#define DMA_BAD_BLK_BUF						0x80F00000

#define MIU_CHECK_LAST_DONE					1

//=====================================================
// misc
//=====================================================
//#define BIG_ENDIAN
#define LITTLE_ENDIAN

typedef struct NAND_DRIVER_PLATFORM_DEPENDENT
{
	U8 *pu8_PageSpareBuf;
	U8 *pu8_PageDataBuf;
	U32	u32_DMAAddrOffset;
	U32	u32_RAMBufferOffset;
	U32	u32_RAMBufferLen;

}NAND_DRIVER_PLAT_CTX, *P_NAND_DRIVER_PLAT;

#define NC_REG_MIU_LAST_DONE				NC_MIE_EVENT

#define NANDINFO_ECC_TYPE ECC_TYPE_24BIT1KB
#define  malloc(x) kmalloc(x, GFP_KERNEL)
#define free kfree

#endif
