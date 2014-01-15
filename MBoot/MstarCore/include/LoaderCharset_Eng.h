//<MStar Software>
//******************************************************************************
// MStar Software
// Copyright (c) 2010 - 2012 MStar Semiconductor, Inc. All rights reserved.
// All software, firmware and related documentation herein ("MStar Software") are
// intellectual property of MStar Semiconductor, Inc. ("MStar") and protected by
// law, including, but not limited to, copyright law and international treaties.
// Any use, modification, reproduction, retransmission, or republication of all 
// or part of MStar Software is expressly prohibited, unless prior written 
// permission has been granted by MStar. 
//
// By accessing, browsing and/or using MStar Software, you acknowledge that you
// have read, understood, and agree, to be bound by below terms ("Terms") and to
// comply with all applicable laws and regulations:
//
// 1. MStar shall retain any and all right, ownership and interest to MStar
//    Software and any modification/derivatives thereof.
//    No right, ownership, or interest to MStar Software and any
//    modification/derivatives thereof is transferred to you under Terms.
//
// 2. You understand that MStar Software might include, incorporate or be
//    supplied together with third party`s software and the use of MStar
//    Software may require additional licenses from third parties.  
//    Therefore, you hereby agree it is your sole responsibility to separately
//    obtain any and all third party right and license necessary for your use of
//    such third party`s software. 
//
// 3. MStar Software and any modification/derivatives thereof shall be deemed as
//    MStar`s confidential information and you agree to keep MStar`s 
//    confidential information in strictest confidence and not disclose to any
//    third party.  
//
// 4. MStar Software is provided on an "AS IS" basis without warranties of any
//    kind. Any warranties are hereby expressly disclaimed by MStar, including
//    without limitation, any warranties of merchantability, non-infringement of
//    intellectual property rights, fitness for a particular purpose, error free
//    and in conformity with any international standard.  You agree to waive any
//    claim against MStar for any loss, damage, cost or expense that you may
//    incur related to your use of MStar Software.
//    In no event shall MStar be liable for any direct, indirect, incidental or
//    consequential damages, including without limitation, lost of profit or
//    revenues, lost or damage of data, and unauthorized system use.
//    You agree that this Section 4 shall still apply without being affected
//    even if MStar Software has been modified by MStar in accordance with your
//    request or instruction for your use, except otherwise agreed by both
//    parties in writing.
//
// 5. If requested, MStar may from time to time provide technical supports or
//    services in relation with MStar Software to you for your use of
//    MStar Software in conjunction with your or your customer`s product
//    ("Services").
//    You understand and agree that, except otherwise agreed by both parties in
//    writing, Services are provided on an "AS IS" basis and the warranty
//    disclaimer set forth in Section 4 above shall apply.  
//
// 6. Nothing contained herein shall be construed as by implication, estoppels
//    or otherwise:
//    (a) conferring any license or right to use MStar name, trademark, service
//        mark, symbol or any other identification;
//    (b) obligating MStar or any of its affiliates to furnish any person,
//        including without limitation, you and your customers, any assistance
//        of any kind whatsoever, or any information; or 
//    (c) conferring any license or right under any intellectual property right.
//
// 7. These terms shall be governed by and construed in accordance with the laws
//    of Taiwan, R.O.C., excluding its conflict of law rules.
//    Any and all dispute arising out hereof or related hereto shall be finally
//    settled by arbitration referred to the Chinese Arbitration Association,
//    Taipei in accordance with the ROC Arbitration Law and the Arbitration
//    Rules of the Association by three (3) arbitrators appointed in accordance
//    with the said Rules.
//    The place of arbitration shall be in Taipei, Taiwan and the language shall
//    be English.  
//    The arbitration award shall be final and binding to both parties.
//
//******************************************************************************
//<MStar Software>
const char LoaderEngCharacterset[] ={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ%.-,abcdefghijklmnopqrstuvwxyz"};
const unsigned char LoaderEngWidthData[] =
{
    // 0123456789
    13,13,13,13,13,13,13,13,13,13,
    //ABCDEFGHIJ
    18,18,18,19,16,15,19,18, 6,13,
    //KLMNOPQRST
    19,15,22,18,19,17,19,17,17,16,
    //UVWXYZ%.-,
    18,18,23,18,17,16,22, 6,14, 6,
    //abcdefghij
    14,15,13,14,14, 9,14,14, 6, 6,
    //klmnopqrst
    15, 6,20,14,14,15,14,10,13, 9,
    //uvwxyz
    14,14,20,13,15,13
};
const unsigned int LoaderEngFont[]={
0x00000000,0x00000000,0x1F800000,0x3FC00000,0x79E00000,0x70E00000,0x70E00000,0xE0700000,0xE0700000,0xE0700000,0xE0700000,0xE0700000,0xE0700000,0xE0700000,0xE0700000,0x70E00000,0x70E00000,0x79E00000,0x3FC00000,0x1F800000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x03800000,0x03800000,0x07800000,0x3F800000,0x3F800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x1F000000,0x7FC00000,0x71E00000,0xE0E00000,0xE0700000,0xE0700000,0x00700000,0x00E00000,0x01E00000,0x03C00000,0x07800000,0x1F000000,0x3C000000,0x78000000,0xF0000000,0xE0000000,0xFFF00000,0xFFF00000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x1F000000,0x7FC00000,0x71C00000,0xE0E00000,0xE0E00000,0xE0E00000,0x00E00000,0x01C00000,0x0F800000,0x0FE00000,0x00E00000,0x00700000,0x00700000,0xE0700000,0xE0F00000,0x71E00000,0x7FE00000,0x1F800000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x01C00000,0x03C00000,0x03C00000,0x07C00000,0x07C00000,0x0DC00000,0x1DC00000,0x19C00000,0x31C00000,0x71C00000,0x61C00000,0xE1C00000,0xFFF00000,0xFFF00000,0x01C00000,0x01C00000,0x01C00000,0x01C00000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x7FE00000,0x7FE00000,0x70000000,0x70000000,0x70000000,0x70000000,0x7F800000,0x7FC00000,0x71E00000,0x00E00000,0x00700000,0x00700000,0x00700000,0xE0700000,0xE0F00000,0xF1E00000,0x7FC00000,0x1F800000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x0F800000,0x3FE00000,0x78E00000,0x70700000,0xE0700000,0xE0000000,0xE0000000,0xEF000000,0xFFC00000,0xF9E00000,0xF0E00000,0xE0700000,0xE0700000,0xE0700000,0x70E00000,0x79E00000,0x3FC00000,0x1F800000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0xFFF00000,0xFFF00000,0x00F00000,0x00E00000,0x01C00000,0x01C00000,0x03800000,0x03800000,0x07000000,0x07000000,0x0E000000,0x0E000000,0x1E000000,0x1C000000,0x1C000000,0x3C000000,0x38000000,0x38000000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x0F000000,0x3FC00000,0x39C00000,0x70E00000,0x70E00000,0x70E00000,0x70E00000,0x39C00000,0x1F800000,0x3FC00000,0x70E00000,0xE0700000,0xE0700000,0xE0700000,0xE0700000,0x70E00000,0x7FE00000,0x1F800000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x1F800000,0x7FC00000,0x79E00000,0xF0E00000,0xE0700000,0xE0700000,0xE0700000,0xE0700000,0xF0F00000,0x79F00000,0x7FF00000,0x1F700000,0x00700000,0x00700000,0xE0E00000,0xF3E00000,0x7FC00000,0x1F000000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x01E00000,0x01E00000,0x03F00000,0x03F00000,0x07300000,0x07380000,0x07380000,0x0E1C0000,0x0E1C0000,0x0E1C0000,0x1C0E0000,0x1C0E0000,0x1FFE0000,0x3FFF0000,0x38070000,0x38070000,0x70038000,0x70038000,0x70038000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x3FF80000,0x3FFE0000,0x381E0000,0x38070000,0x38070000,0x38070000,0x38070000,0x380E0000,0x3FFC0000,0x3FFE0000,0x38070000,0x38038000,0x38038000,0x38038000,0x38038000,0x38078000,0x381F0000,0x3FFE0000,0x3FF80000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x03F80000,0x0FFE0000,0x1F1F0000,0x3C078000,0x38038000,0x78000000,0x70000000,0x70000000,0x70000000,0x70000000,0x70000000,0x70000000,0x70000000,0x78038000,0x38038000,0x3C078000,0x1F1F0000,0x0FFE0000,0x03F80000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x3FF80000,0x3FFE0000,0x381F0000,0x38078000,0x38038000,0x3803C000,0x3801C000,0x3801C000,0x3801C000,0x3801C000,0x3801C000,0x3801C000,0x3801C000,0x3803C000,0x38038000,0x38078000,0x381F0000,0x3FFE0000,0x3FF80000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x3FFC0000,0x3FFC0000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x3FF80000,0x3FF80000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x3FFE0000,0x3FFE0000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x3FFC0000,0x3FFC0000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x3FF80000,0x3FF80000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x03F80000,0x0FFE0000,0x1F1F0000,0x3C078000,0x38038000,0x78000000,0x70000000,0x70000000,0x70000000,0x703FC000,0x703FC000,0x7001C000,0x7001C000,0x7801C000,0x3803C000,0x3C07C000,0x1F1FC000,0x0FFDC000,0x03F8C000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x38038000,0x38038000,0x38038000,0x38038000,0x38038000,0x38038000,0x38038000,0x38038000,0x3FFF8000,0x3FFF8000,0x38038000,0x38038000,0x38038000,0x38038000,0x38038000,0x38038000,0x38038000,0x38038000,0x38038000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00700000,0x00700000,0x00700000,0x00700000,0x00700000,0x00700000,0x00700000,0x00700000,0x00700000,0x00700000,0x00700000,0x00700000,0x70700000,0x70700000,0x70700000,0x70700000,0x38F00000,0x3FE00000,0x1FC00000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x380F0000,0x381E0000,0x383C0000,0x38780000,0x38F00000,0x39E00000,0x3BC00000,0x3F800000,0x3F800000,0x3FC00000,0x3DE00000,0x38F00000,0x38780000,0x383C0000,0x381E0000,0x380F0000,0x38078000,0x3803C000,0x3801C000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x3FFC0000,0x3FFC0000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x38003800,0x3C007800,0x3C007800,0x3E00F800,0x3E00F800,0x3F01F800,0x3B01B800,0x3B83B800,0x39833800,0x39C73800,0x39C73800,0x38C63800,0x38EE3800,0x38EE3800,0x387C3800,0x387C3800,0x38383800,0x38383800,0x38383800,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x38038000,0x3C038000,0x3C038000,0x3E038000,0x3E038000,0x3F038000,0x3B838000,0x3B838000,0x39C38000,0x38E38000,0x38E38000,0x38738000,0x38338000,0x383B8000,0x381F8000,0x380F8000,0x380F8000,0x38078000,0x38038000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x03F80000,0x0FFE0000,0x1F1F0000,0x3C078000,0x38038000,0x7803C000,0x7001C000,0x7001C000,0x7001C000,0x7001C000,0x7001C000,0x7001C000,0x7001C000,0x7803C000,0x38038000,0x3C078000,0x1F1F0000,0x0FFE0000,0x03F80000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x3FF80000,0x3FFE0000,0x380E0000,0x38070000,0x38070000,0x38070000,0x38070000,0x380E0000,0x3FFE0000,0x3FFC0000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x03F80000,0x0FFE0000,0x1F1F0000,0x3C078000,0x38038000,0x7803C000,0x7001C000,0x7001C000,0x7001C000,0x7001C000,0x7001C000,0x7001C000,0x7001C000,0x7803C000,0x387B8000,0x3C3F8000,0x1F0F0000,0x0FFF8000,0x03FBC000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x3FF80000,0x3FFE0000,0x380E0000,0x38070000,0x38070000,0x38070000,0x38070000,0x380E0000,0x3FFE0000,0x3FFC0000,0x381E0000,0x380E0000,0x38070000,0x38070000,0x38070000,0x38070000,0x38070000,0x38070000,0x38070000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x03F00000,0x0FFC0000,0x1E3E0000,0x3C0E0000,0x380E0000,0x38000000,0x3C000000,0x1F000000,0x0FF00000,0x01FC0000,0x003E0000,0x000F0000,0x00070000,0x70070000,0x70070000,0x780F0000,0x3E3E0000,0x1FFC0000,0x07F00000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0xFFFE0000,0xFFFE0000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x03800000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x38038000,0x38038000,0x38038000,0x38038000,0x38038000,0x38038000,0x38038000,0x38038000,0x38038000,0x38038000,0x38038000,0x38038000,0x38038000,0x38038000,0x3C078000,0x1C070000,0x1F1F0000,0x0FFE0000,0x03F80000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x70038000,0x70038000,0x78078000,0x38070000,0x3C0F0000,0x1C0E0000,0x1C0E0000,0x1E1E0000,0x0E1C0000,0x0E1C0000,0x0F3C0000,0x07380000,0x07380000,0x07380000,0x03F00000,0x03F00000,0x01E00000,0x01E00000,0x01E00000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x70381C00,0x70381C00,0x70381C00,0x70381C00,0x387C3800,0x387C3800,0x386C3800,0x38EE3800,0x18EE3000,0x1CEE7000,0x1CC67000,0x1DC77000,0x0DC76000,0x0DC76000,0x0F83E000,0x0F83E000,0x0701C000,0x0701C000,0x0701C000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x70038000,0x78078000,0x3C0F0000,0x1C0E0000,0x0E1C0000,0x07380000,0x07F80000,0x03F00000,0x01E00000,0x01E00000,0x03F00000,0x07F80000,0x07380000,0x0E1C0000,0x1E1E0000,0x1C0E0000,0x38070000,0x78078000,0x70038000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x70070000,0x780F0000,0x380E0000,0x3C1E0000,0x1C1C0000,0x1E3C0000,0x0E380000,0x0F780000,0x07700000,0x07F00000,0x03E00000,0x03E00000,0x01C00000,0x01C00000,0x01C00000,0x01C00000,0x01C00000,0x01C00000,0x01C00000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x7FFE0000,0x7FFE0000,0x001E0000,0x003C0000,0x00780000,0x00F00000,0x00F00000,0x01E00000,0x03C00000,0x03C00000,0x07800000,0x0F000000,0x0F000000,0x1E000000,0x1C000000,0x3C000000,0x78000000,0x7FFE0000,0x7FFE0000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00070000,0x3E070000,0x7F0E0000,0xE38E0000,0xC19C0000,0xC19C0000,0xE3B80000,0x7F380000,0x3E700000,0x00700000,0x00E3E000,0x00E7F000,0x01CE3800,0x01CC1800,0x038C1800,0x038E3800,0x0707F000,0x0703E000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x38000000,0x38000000,0x38000000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x7FF80000,0x7FF80000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x38000000,0x38000000,0x38000000,0x18000000,0x18000000,0x30000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x0FC00000,0x1FE00000,0x38F00000,0x38700000,0x00700000,0x03F00000,0x1FF00000,0x3E700000,0x78700000,0x70700000,0x70F00000,0x79F00000,0x3FF80000,0x1F380000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x3BE00000,0x3FF00000,0x3E780000,0x3C380000,0x381C0000,0x381C0000,0x381C0000,0x381C0000,0x381C0000,0x381C0000,0x3C380000,0x3E780000,0x3FF00000,0x3BE00000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x0FC00000,0x1FE00000,0x3CF00000,0x38700000,0x70000000,0x70000000,0x70000000,0x70000000,0x70000000,0x70000000,0x38700000,0x3CF00000,0x1FE00000,0x0FC00000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00380000,0x00380000,0x00380000,0x00380000,0x00380000,0x0FB80000,0x1FF80000,0x3CF80000,0x38780000,0x70380000,0x70380000,0x70380000,0x70380000,0x70380000,0x70380000,0x38780000,0x3CF80000,0x1FF80000,0x0FB80000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x07800000,0x1FE00000,0x3CF00000,0x38700000,0x70380000,0x70380000,0x7FF80000,0x7FF80000,0x70000000,0x70000000,0x38380000,0x3C780000,0x1FF00000,0x07C00000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x0F000000,0x1F000000,0x1C000000,0x1C000000,0x1C000000,0x7F000000,0x7F000000,0x1C000000,0x1C000000,0x1C000000,0x1C000000,0x1C000000,0x1C000000,0x1C000000,0x1C000000,0x1C000000,0x1C000000,0x1C000000,0x1C000000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x0FB80000,0x1FF80000,0x3CF80000,0x38780000,0x70380000,0x70380000,0x70380000,0x70380000,0x70380000,0x70380000,0x38780000,0x3CF80000,0x1FF80000,0x0FB80000,0x00380000,0x70380000,0x78700000,0x3FF00000,
0x00000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x3BC00000,0x3FF00000,0x3C700000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x38000000,0x38000000,0x38000000,0x00000000,0x00000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x38000000,0x38000000,0x38000000,0x00000000,0x00000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0xF8000000,
0x00000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38780000,0x38F00000,0x39E00000,0x3BC00000,0x3F800000,0x3F000000,0x3F800000,0x3BC00000,0x39C00000,0x39E00000,0x38F00000,0x38700000,0x38780000,0x383C0000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x3BCF8000,0x3FFFC000,0x3CF9E000,0x3870E000,0x3870E000,0x3870E000,0x3870E000,0x3870E000,0x3870E000,0x3870E000,0x3870E000,0x3870E000,0x3870E000,0x3870E000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x3BE00000,0x3FF00000,0x3C700000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x07800000,0x1FE00000,0x3CF00000,0x38700000,0x70380000,0x70380000,0x70380000,0x70380000,0x70380000,0x70380000,0x38700000,0x3CF00000,0x1FE00000,0x07800000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x3BE00000,0x3FF00000,0x3E780000,0x3C380000,0x381C0000,0x381C0000,0x381C0000,0x381C0000,0x381C0000,0x381C0000,0x3C380000,0x3E780000,0x3FF00000,0x3BE00000,0x38000000,0x38000000,0x38000000,0x38000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x0FB80000,0x1FF80000,0x3CF80000,0x38780000,0x70380000,0x70380000,0x70380000,0x70380000,0x70380000,0x70380000,0x38780000,0x3CF80000,0x1FF80000,0x0FB80000,0x00380000,0x00380000,0x00380000,0x00380000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x39800000,0x3B800000,0x3F800000,0x3C000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x38000000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x1F800000,0x3FC00000,0x79E00000,0x70E00000,0x70000000,0x7E000000,0x3FC00000,0x07E00000,0x00F00000,0x70700000,0x70700000,0x78F00000,0x3FE00000,0x1FC00000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x1C000000,0x1C000000,0x1C000000,0x1C000000,0x7F000000,0x7F000000,0x1C000000,0x1C000000,0x1C000000,0x1C000000,0x1C000000,0x1C000000,0x1C000000,0x1C000000,0x1C000000,0x1C000000,0x1F000000,0x0F000000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x38380000,0x38780000,0x1CF80000,0x1FB80000,0x07380000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x70380000,0x70380000,0x70380000,0x38700000,0x38700000,0x38700000,0x1CE00000,0x1CE00000,0x1CE00000,0x0FC00000,0x0FC00000,0x07800000,0x07800000,0x07800000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0xE0E0E000,0xE0E0E000,0x60E0C000,0x71F1C000,0x71F1C000,0x31B18000,0x33B98000,0x3BBB8000,0x1B1B0000,0x1F1F0000,0x1F1F0000,0x0E0E0000,0x0E0E0000,0x0E0E0000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x70700000,0x78F00000,0x38E00000,0x1DC00000,0x1FC00000,0x0F800000,0x07000000,0x0F800000,0x0F800000,0x1DC00000,0x3DE00000,0x38E00000,0x78F00000,0x70700000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x701C0000,0x701C0000,0x381C0000,0x3C380000,0x1C380000,0x1E780000,0x0E700000,0x0E700000,0x07E00000,0x07E00000,0x03E00000,0x03C00000,0x01C00000,0x01C00000,0x03800000,0x03800000,0x07000000,0x1F000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x7FF00000,0x7FF00000,0x00E00000,0x01C00000,0x03C00000,0x07800000,0x07000000,0x0F000000,0x1E000000,0x1C000000,0x38000000,0x78000000,0x7FF00000,0x7FF00000,0x00000000,0x00000000,0x00000000,0x00000000,
};