/*
Program: gamex86.dll
Functions decompiled: top 620 by body size
*/

/* FUN_1003bc26 @ 1003bc26 size 2597 */

int __thiscall FUN_1003bc26(void *this,int *param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  undefined4 *puVar2;
  int *piVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  void *this_00;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  void *this_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *piVar7;
  byte bVar8;
  byte *pbVar9;
  byte *pbVar10;
  char *pcVar11;
  char *pcVar12;
  WCHAR *pWVar13;
  undefined *puVar14;
  int iVar15;
  bool bVar16;
  int *piVar17;
  char local_1c8;
  char local_1c7 [351];
  byte local_68 [32];
  undefined4 *local_48;
  WCHAR local_42;
  uint local_40;
  byte local_3c;
  undefined1 local_3b;
  byte local_39;
  int local_38;
  WCHAR *local_34;
  WCHAR *local_30;
  undefined8 local_2c;
  int local_24;
  int local_20;
  byte local_1c;
  char local_1b;
  char local_1a;
  char local_19;
  int *local_18;
  char local_13;
  char local_12;
  char local_11;
  int local_10;
  char local_9;
  undefined *local_8;
  
  local_19 = '\0';
  bVar1 = *param_2;
  local_8 = (undefined *)0x0;
  local_38 = 0;
  pbVar9 = param_2;
  piVar7 = (int *)PTR_DAT_1005fcc8;
  do {
    PTR_DAT_1005fcc8 = (undefined *)piVar7;
    if (bVar1 == 0) {
LAB_1003c62c:
      if (local_18 == (int *)0xffffffff) {
LAB_1003c632:
        if ((local_38 == 0) && (local_19 == '\0')) {
          local_38 = -1;
        }
      }
      return local_38;
    }
    if ((int)DAT_1005fed4 < 2) {
      uVar5 = *(byte *)((int)piVar7 + (uint)bVar1 * 2) & 8;
    }
    else {
      piVar7 = (int *)0x8;
      uVar5 = FUN_1003b258(this,(uint)bVar1,8);
    }
    if (uVar5 != 0) {
      local_8 = local_8 + -1;
      piVar7 = param_1;
      uVar5 = FUN_1003c6b3((int *)&local_8,param_1);
      FUN_1003c69c(uVar5,piVar7);
      uVar5 = FUN_10040b0b(this_00,(uint)pbVar9[1]);
      piVar7 = extraout_ECX;
      pbVar10 = pbVar9;
      while (pbVar9 = pbVar10 + 1, uVar5 != 0) {
        piVar17 = (int *)(uint)pbVar10[2];
        uVar5 = FUN_10040b0b(piVar7,(int)(uint)pbVar10[2]);
        piVar7 = piVar17;
        pbVar10 = pbVar9;
      }
    }
    if (*pbVar9 == 0x25) {
      local_39 = 0;
      local_1c = 0;
      local_1b = '\0';
      local_12 = '\0';
      local_13 = '\0';
      local_1a = '\0';
      puVar14 = (undefined *)0x0;
      local_9 = '\0';
      local_20 = 0;
      local_24 = 0;
      local_10 = 0;
      local_11 = '\x01';
      local_34 = (WCHAR *)0x0;
      do {
        uVar5 = (uint)pbVar9[1];
        param_2 = pbVar9 + 1;
        if ((int)DAT_1005fed4 < 2) {
          uVar6 = (byte)PTR_DAT_1005fcc8[uVar5 * 2] & 4;
          piVar7 = (int *)PTR_DAT_1005fcc8;
        }
        else {
          piVar17 = (int *)0x4;
          uVar6 = FUN_1003b258(piVar7,uVar5,4);
          piVar7 = piVar17;
        }
        if (uVar6 == 0) {
          if (uVar5 < 0x4f) {
            if (uVar5 != 0x4e) {
              if (uVar5 == 0x2a) {
                local_12 = local_12 + '\x01';
              }
              else if (uVar5 != 0x46) {
                if (uVar5 == 0x49) {
                  if ((pbVar9[2] != 0x36) || (pbVar9[3] != 0x34)) goto LAB_1003bd81;
                  local_34 = (WCHAR *)((int)local_34 + 1);
                  local_2c = 0;
                  param_2 = pbVar9 + 3;
                }
                else if (uVar5 == 0x4c) {
                  local_11 = local_11 + '\x01';
                }
                else {
LAB_1003bd81:
                  local_13 = local_13 + '\x01';
                }
              }
            }
          }
          else if (uVar5 == 0x68) {
            local_11 = local_11 + -1;
            local_9 = local_9 + -1;
          }
          else {
            if (uVar5 == 0x6c) {
              local_11 = local_11 + '\x01';
            }
            else if (uVar5 != 0x77) goto LAB_1003bd81;
            local_9 = local_9 + '\x01';
          }
        }
        else {
          local_24 = local_24 + 1;
          local_10 = (uVar5 - 0x30) + local_10 * 10;
        }
        pbVar9 = param_2;
      } while (local_13 == '\0');
      puVar2 = param_3;
      if (local_12 == '\0') {
        local_30 = (WCHAR *)*param_3;
        puVar2 = param_3 + 1;
        local_48 = param_3;
      }
      param_3 = puVar2;
      local_13 = '\0';
      if (local_9 == '\0') {
        if ((*param_2 == 0x53) || (*param_2 == 0x43)) {
          local_9 = '\x01';
        }
        else {
          local_9 = -1;
        }
      }
      uVar5 = *param_2 | 0x20;
      local_40 = uVar5;
      if (uVar5 != 0x6e) {
        if ((uVar5 == 99) || (uVar5 == 0x7b)) {
          local_8 = local_8 + 1;
          piVar7 = param_1;
          local_18 = (int *)FUN_1003c682(param_1);
        }
        else {
          piVar7 = param_1;
          local_18 = (int *)FUN_1003c6b3((int *)&local_8,param_1);
        }
      }
      if ((local_24 != 0) && (local_10 == 0)) {
LAB_1003c60c:
        local_8 = local_8 + -1;
        FUN_1003c69c((uint)local_18,param_1);
        goto LAB_1003c62c;
      }
      if (uVar5 < 0x70) {
        if (uVar5 == 0x6f) {
LAB_1003c339:
          if (local_18 == (int *)0x2d) {
            local_1b = '\x01';
          }
          else if (local_18 != (int *)0x2b) goto LAB_1003c36e;
          local_10 = local_10 + -1;
          if ((local_10 == 0) && (local_24 != 0)) {
            local_13 = '\x01';
          }
          else {
            local_8 = local_8 + 1;
            piVar7 = param_1;
            local_18 = (int *)FUN_1003c682(param_1);
          }
          goto LAB_1003c36e;
        }
        if (uVar5 != 99) {
          if (uVar5 == 100) goto LAB_1003c339;
          if (uVar5 < 0x65) {
LAB_1003c0b1:
            if ((int *)(uint)*param_2 != local_18) goto LAB_1003c60c;
            local_19 = local_19 + -1;
            if (local_12 == '\0') {
              param_3 = local_48;
            }
            goto LAB_1003c58d;
          }
          if (0x67 < uVar5) {
            if (uVar5 == 0x69) {
              uVar5 = 100;
              goto LAB_1003be6f;
            }
            if (uVar5 != 0x6e) goto LAB_1003c0b1;
            puVar14 = local_8;
            if (local_12 != '\0') goto LAB_1003c58d;
            goto LAB_1003c567;
          }
          pcVar11 = &local_1c8;
          if (local_18 == (int *)0x2d) {
            local_1c8 = '-';
            pcVar11 = local_1c7;
LAB_1003bea5:
            local_10 = local_10 + -1;
            local_8 = local_8 + 1;
            piVar7 = param_1;
            local_18 = (int *)FUN_1003c682(param_1);
          }
          else if (local_18 == (int *)0x2b) goto LAB_1003bea5;
          if ((local_24 == 0) || (0x15d < local_10)) {
            local_10 = 0x15d;
          }
          while( true ) {
            piVar17 = local_18;
            if ((int)DAT_1005fed4 < 2) {
              uVar5 = (byte)PTR_DAT_1005fcc8[(int)local_18 * 2] & 4;
            }
            else {
              uVar5 = FUN_1003b258(piVar7,(int)local_18,4);
            }
            if ((uVar5 == 0) ||
               (iVar15 = local_10 + -1, bVar16 = local_10 == 0, local_10 = iVar15, bVar16)) break;
            local_20 = local_20 + 1;
            *pcVar11 = (char)piVar17;
            pcVar11 = pcVar11 + 1;
            local_8 = local_8 + 1;
            piVar7 = param_1;
            local_18 = (int *)FUN_1003c682(param_1);
          }
          if ((DAT_1005fed8 == (char)piVar17) &&
             (iVar15 = local_10 + -1, bVar16 = local_10 != 0, local_10 = iVar15, bVar16)) {
            local_8 = local_8 + 1;
            piVar7 = param_1;
            piVar17 = (int *)FUN_1003c682(param_1);
            *pcVar11 = DAT_1005fed8;
            while( true ) {
              pcVar11 = pcVar11 + 1;
              local_18 = piVar17;
              if ((int)DAT_1005fed4 < 2) {
                uVar5 = (byte)PTR_DAT_1005fcc8[(int)piVar17 * 2] & 4;
              }
              else {
                uVar5 = FUN_1003b258(piVar7,(int)piVar17,4);
              }
              if ((uVar5 == 0) ||
                 (iVar15 = local_10 + -1, bVar16 = local_10 == 0, local_10 = iVar15, bVar16)) break;
              local_20 = local_20 + 1;
              *pcVar11 = (char)piVar17;
              local_8 = local_8 + 1;
              piVar7 = param_1;
              piVar17 = (int *)FUN_1003c682(param_1);
            }
          }
          pcVar12 = pcVar11;
          if ((local_20 != 0) &&
             (((piVar17 == (int *)0x65 || (piVar17 == (int *)0x45)) &&
              (iVar15 = local_10 + -1, bVar16 = local_10 != 0, local_10 = iVar15, bVar16)))) {
            *pcVar11 = 'e';
            pcVar12 = pcVar11 + 1;
            local_8 = local_8 + 1;
            piVar7 = param_1;
            piVar17 = (int *)FUN_1003c682(param_1);
            local_18 = piVar17;
            if (piVar17 == (int *)0x2d) {
              *pcVar12 = '-';
              pcVar12 = pcVar11 + 2;
LAB_1003bfcc:
              bVar16 = local_10 != 0;
              local_10 = local_10 + -1;
              if (bVar16) goto LAB_1003bfdb;
              local_10 = 0;
            }
            else if (piVar17 == (int *)0x2b) goto LAB_1003bfcc;
            while( true ) {
              if ((int)DAT_1005fed4 < 2) {
                uVar5 = (byte)PTR_DAT_1005fcc8[(int)piVar17 * 2] & 4;
              }
              else {
                uVar5 = FUN_1003b258(piVar7,(int)piVar17,4);
              }
              if ((uVar5 == 0) ||
                 (iVar15 = local_10 + -1, bVar16 = local_10 == 0, local_10 = iVar15, bVar16)) break;
              local_20 = local_20 + 1;
              *pcVar12 = (char)piVar17;
              pcVar12 = pcVar12 + 1;
LAB_1003bfdb:
              local_8 = local_8 + 1;
              piVar7 = param_1;
              piVar17 = (int *)FUN_1003c682(param_1);
              local_18 = piVar17;
            }
          }
          local_8 = local_8 + -1;
          piVar7 = param_1;
          FUN_1003c69c((uint)piVar17,param_1);
          if (local_20 != 0) {
            if (local_12 == '\0') {
              local_38 = local_38 + 1;
              *pcVar12 = '\0';
              (*(code *)PTR___fptrap_1005fb9c)(local_11 + -1,local_30,&local_1c8);
              piVar7 = extraout_ECX_00;
            }
            goto LAB_1003c58d;
          }
          goto LAB_1003c62c;
        }
        if (local_24 == 0) {
          local_10 = local_10 + 1;
          local_24 = 1;
        }
        if ('\0' < local_9) {
          local_1a = '\x01';
        }
        pcVar11 = &DAT_1005fef0;
LAB_1003c192:
        local_1c = 0xff;
        pbVar9 = (byte *)pcVar11;
        pbVar10 = param_2;
LAB_1003c196:
        param_2 = pbVar10;
        _memset(local_68,0,0x20);
        if ((local_40 == 0x7b) && (*pbVar9 == 0x5d)) {
          uVar5 = 0x5d;
          local_68[0xb] = 0x20;
          pbVar9 = pbVar9 + 1;
        }
        else {
          uVar5 = (uint)local_39;
        }
        while (pWVar13 = local_30, bVar1 = *pbVar9, bVar1 != 0x5d) {
          if (((bVar1 == 0x2d) && (bVar8 = (byte)uVar5, bVar8 != 0)) &&
             (bVar4 = pbVar9[1], bVar4 != 0x5d)) {
            if (bVar4 <= bVar8) {
              uVar5 = (uint)bVar4;
              bVar4 = bVar8;
            }
            if ((byte)uVar5 <= bVar4) {
              iVar15 = (bVar4 - uVar5) + 1;
              do {
                local_68[uVar5 >> 3] = local_68[uVar5 >> 3] | '\x01' << ((byte)uVar5 & 7);
                uVar5 = uVar5 + 1;
                iVar15 = iVar15 + -1;
              } while (iVar15 != 0);
            }
            uVar5 = 0;
            pbVar9 = pbVar9 + 2;
          }
          else {
            uVar5 = (uint)bVar1;
            local_68[bVar1 >> 3] = local_68[bVar1 >> 3] | '\x01' << (bVar1 & 7);
            pbVar9 = pbVar9 + 1;
          }
        }
        if (*pbVar9 == 0) goto LAB_1003c62c;
        if (local_40 == 0x7b) {
          param_2 = pbVar9;
        }
        local_8 = local_8 + -1;
        local_34 = local_30;
        piVar7 = param_1;
        FUN_1003c69c((uint)local_18,param_1);
        while( true ) {
          if ((local_24 != 0) &&
             (iVar15 = local_10 + -1, bVar16 = local_10 == 0, local_10 = iVar15, bVar16))
          goto LAB_1003c2fb;
          local_8 = local_8 + 1;
          local_18 = (int *)FUN_1003c682(param_1);
          if (local_18 == (int *)0xffffffff) break;
          bVar1 = (byte)local_18;
          piVar7 = (int *)(int)(char)(local_68[(int)local_18 >> 3] ^ local_1c);
          if (((uint)piVar7 & 1 << (bVar1 & 7)) == 0) break;
          if (local_12 == '\0') {
            if (local_1a == '\0') {
              *(byte *)pWVar13 = bVar1;
              pWVar13 = (WCHAR *)((int)pWVar13 + 1);
              local_30 = pWVar13;
            }
            else {
              local_3c = bVar1;
              if ((PTR_DAT_1005fcc8[((uint)local_18 & 0xff) * 2 + 1] & 0x80) != 0) {
                local_8 = local_8 + 1;
                uVar5 = FUN_1003c682(param_1);
                local_3b = (undefined1)uVar5;
              }
              FUN_100409e5(&local_42,&local_3c,DAT_1005fed4);
              *pWVar13 = local_42;
              pWVar13 = pWVar13 + 1;
              piVar7 = extraout_ECX_01;
              local_30 = pWVar13;
            }
          }
          else {
            local_34 = (WCHAR *)((int)local_34 + 1);
          }
        }
        local_8 = local_8 + -1;
        piVar7 = param_1;
        FUN_1003c69c((uint)local_18,param_1);
LAB_1003c2fb:
        if (local_34 == pWVar13) goto LAB_1003c62c;
        if ((local_12 == '\0') && (local_38 = local_38 + 1, local_40 != 99)) {
          if (local_1a == '\0') {
            *(byte *)local_30 = 0;
          }
          else {
            *local_30 = L'\0';
          }
        }
      }
      else {
        if (uVar5 == 0x70) {
          local_11 = '\x01';
          goto LAB_1003c339;
        }
        if (uVar5 == 0x73) {
          if ('\0' < local_9) {
            local_1a = '\x01';
          }
          pcVar11 = s_____1005fee8;
          goto LAB_1003c192;
        }
        if (uVar5 == 0x75) goto LAB_1003c339;
        if (uVar5 != 0x78) {
          if (uVar5 != 0x7b) goto LAB_1003c0b1;
          if ('\0' < local_9) {
            local_1a = '\x01';
          }
          pbVar9 = param_2 + 1;
          pbVar10 = pbVar9;
          if (*pbVar9 == 0x5e) {
            pcVar11 = (char *)(param_2 + 2);
            param_2 = pbVar9;
            goto LAB_1003c192;
          }
          goto LAB_1003c196;
        }
LAB_1003be6f:
        if (local_18 == (int *)0x2d) {
          local_1b = '\x01';
LAB_1003c0fe:
          local_10 = local_10 + -1;
          if ((local_10 == 0) && (local_24 != 0)) {
            local_13 = '\x01';
          }
          else {
            local_8 = local_8 + 1;
            piVar7 = param_1;
            local_18 = (int *)FUN_1003c682(param_1);
          }
        }
        else if (local_18 == (int *)0x2b) goto LAB_1003c0fe;
        if (local_18 == (int *)0x30) {
          local_8 = local_8 + 1;
          piVar7 = param_1;
          local_18 = (int *)FUN_1003c682(param_1);
          if (((char)local_18 == 'x') || ((char)local_18 == 'X')) {
            local_8 = local_8 + 1;
            piVar7 = param_1;
            local_18 = (int *)FUN_1003c682(param_1);
            uVar5 = 0x78;
          }
          else {
            local_20 = 1;
            if (uVar5 == 0x78) {
              local_8 = local_8 + -1;
              piVar7 = param_1;
              FUN_1003c69c((uint)local_18,param_1);
              local_18 = (int *)0x30;
            }
            else {
              uVar5 = 0x6f;
            }
          }
        }
LAB_1003c36e:
        if (local_34 == (WCHAR *)0x0) {
          if (local_13 == '\0') {
            while ((piVar17 = local_18, uVar5 != 0x78 && (uVar5 != 0x70))) {
              if ((int)DAT_1005fed4 < 2) {
                uVar6 = (byte)PTR_DAT_1005fcc8[(int)local_18 * 2] & 4;
              }
              else {
                piVar3 = (int *)0x4;
                uVar6 = FUN_1003b258(piVar7,(int)local_18,4);
                piVar7 = piVar3;
              }
              if (uVar6 == 0) goto LAB_1003c535;
              if (uVar5 == 0x6f) {
                if (0x37 < (int)piVar17) goto LAB_1003c535;
                iVar15 = (int)puVar14 << 3;
              }
              else {
                iVar15 = (int)puVar14 * 10;
              }
LAB_1003c50d:
              local_20 = local_20 + 1;
              puVar14 = (undefined *)(iVar15 + -0x30 + (int)piVar17);
              if ((local_24 != 0) && (local_10 = local_10 + -1, local_10 == 0)) goto LAB_1003c543;
              local_8 = local_8 + 1;
              piVar7 = param_1;
              local_18 = (int *)FUN_1003c682(param_1);
            }
            if ((int)DAT_1005fed4 < 2) {
              uVar6 = (byte)PTR_DAT_1005fcc8[(int)local_18 * 2] & 0x80;
            }
            else {
              piVar3 = (int *)0x80;
              uVar6 = FUN_1003b258(piVar7,(int)local_18,0x80);
              piVar7 = piVar3;
            }
            if (uVar6 != 0) {
              iVar15 = (int)puVar14 << 4;
              piVar3 = piVar17;
              piVar17 = (int *)FUN_1003c64b(piVar7,(uint)piVar17);
              piVar7 = piVar3;
              local_18 = piVar17;
              goto LAB_1003c50d;
            }
LAB_1003c535:
            local_8 = local_8 + -1;
            piVar7 = param_1;
            FUN_1003c69c((uint)piVar17,param_1);
          }
LAB_1003c543:
          if (local_1b != '\0') {
            puVar14 = (undefined *)-(int)puVar14;
          }
        }
        else {
          if (local_13 == '\0') {
            while (piVar17 = local_18, uVar5 != 0x78) {
              if ((int)DAT_1005fed4 < 2) {
                uVar6 = (byte)PTR_DAT_1005fcc8[(int)local_18 * 2] & 4;
              }
              else {
                uVar6 = FUN_1003b258(piVar7,(int)local_18,4);
              }
              if (uVar6 == 0) goto LAB_1003c457;
              if (uVar5 == 0x6f) {
                if (0x37 < (int)piVar17) goto LAB_1003c457;
                local_2c = __allshl(3,(int)local_2c._4_4_);
                piVar7 = extraout_ECX_02;
              }
              else {
                local_2c = __allmul((uint)local_2c,(int)local_2c._4_4_,10,0);
                piVar7 = extraout_ECX_03;
              }
LAB_1003c429:
              local_20 = local_20 + 1;
              piVar17 = piVar17 + -0xc;
              local_2c = CONCAT44((int)local_2c._4_4_ + ((int)piVar17 >> 0x1f) +
                                  (uint)CARRY4((uint)local_2c,(uint)piVar17),
                                  (undefined *)((uint)local_2c + (int)piVar17));
              if ((local_24 != 0) && (local_10 = local_10 + -1, local_10 == 0)) goto LAB_1003c465;
              local_8 = local_8 + 1;
              piVar7 = param_1;
              local_18 = (int *)FUN_1003c682(param_1);
            }
            if ((int)DAT_1005fed4 < 2) {
              uVar6 = (byte)PTR_DAT_1005fcc8[(int)local_18 * 2] & 0x80;
            }
            else {
              uVar6 = FUN_1003b258(piVar7,(int)local_18,0x80);
            }
            if (uVar6 != 0) {
              local_2c = __allshl(4,(int)local_2c._4_4_);
              piVar7 = piVar17;
              piVar17 = (int *)FUN_1003c64b(this_01,(uint)piVar17);
              local_18 = piVar17;
              goto LAB_1003c429;
            }
LAB_1003c457:
            local_8 = local_8 + -1;
            piVar7 = param_1;
            FUN_1003c69c((uint)piVar17,param_1);
          }
LAB_1003c465:
          if (local_1b != '\0') {
            piVar7 = (int *)-((int)local_2c._4_4_ + (uint)((uint)local_2c != 0));
            local_2c = CONCAT44(piVar7,-(uint)local_2c);
          }
        }
        if (uVar5 == 0x46) {
          local_20 = 0;
        }
        if (local_20 == 0) goto LAB_1003c62c;
        if (local_12 == '\0') {
          local_38 = local_38 + 1;
LAB_1003c567:
          if (local_34 == (WCHAR *)0x0) {
            if (local_11 == '\0') {
              *local_30 = (WCHAR)puVar14;
            }
            else {
              *(undefined **)local_30 = puVar14;
            }
          }
          else {
            *(uint *)local_30 = (uint)local_2c;
            *(int **)(local_30 + 2) = local_2c._4_4_;
            piVar7 = local_2c._4_4_;
          }
        }
      }
LAB_1003c58d:
      local_19 = local_19 + '\x01';
      param_2 = param_2 + 1;
      this = piVar7;
    }
    else {
      local_8 = local_8 + 1;
      piVar7 = (int *)FUN_1003c682(param_1);
      param_2 = pbVar9 + 1;
      local_18 = piVar7;
      if ((int *)(uint)*pbVar9 != piVar7) goto LAB_1003c60c;
      this = PTR_DAT_1005fcc8;
      if ((PTR_DAT_1005fcc8[((uint)piVar7 & 0xff) * 2 + 1] & 0x80) != 0) {
        local_8 = local_8 + 1;
        piVar17 = (int *)FUN_1003c682(param_1);
        this = (void *)(uint)*param_2;
        param_2 = pbVar9 + 2;
        if (this != piVar17) {
          local_8 = local_8 + -1;
          FUN_1003c69c((uint)piVar17,param_1);
          local_8 = local_8 + -1;
          FUN_1003c69c((uint)piVar7,param_1);
          goto LAB_1003c62c;
        }
        local_8 = local_8 + -1;
      }
    }
    if ((local_18 == (int *)0xffffffff) && ((*param_2 != 0x25 || (param_2[1] != 0x6e))))
    goto LAB_1003c632;
    bVar1 = *param_2;
    pbVar9 = param_2;
    piVar7 = (int *)PTR_DAT_1005fcc8;
  } while( true );
}



/* FUN_1003b41c @ 1003b41c size 1825 */

int __cdecl FUN_1003b41c(int *param_1,byte *param_2,undefined4 *param_3)

{
  byte *pbVar1;
  uint uVar2;
  WCHAR *pWVar3;
  WCHAR *pWVar4;
  undefined4 uVar5;
  short *psVar6;
  int *piVar7;
  int iVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  undefined1 *puVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  undefined1 local_24c [511];
  undefined1 local_4d;
  undefined4 local_4c;
  undefined4 local_48;
  uint local_44;
  uint local_40;
  CHAR local_3c [4];
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  char local_1a;
  char local_19;
  int local_18;
  int local_14;
  undefined1 *local_10;
  WCHAR *local_c;
  uint local_8;
  
  local_34 = 0;
  bVar9 = *param_2;
  local_10 = (undefined1 *)0x0;
  local_18 = 0;
  pbVar1 = param_2;
  do {
    if ((bVar9 == 0) || (param_2 = pbVar1 + 1, local_18 < 0)) {
      return local_18;
    }
    if (((char)bVar9 < ' ') || ('x' < (char)bVar9)) {
      uVar2 = 0;
    }
    else {
      uVar2 = (byte)(&DAT_1004456c)[(char)bVar9] & 0xf;
    }
    local_34 = (int)(char)(&DAT_1004458c)[uVar2 * 8 + local_34] >> 4;
    switch(local_34) {
    case 0:
switchD_1003b48a_caseD_0:
      local_28 = 0;
      if ((PTR_DAT_1005fcc8[(uint)bVar9 * 2 + 1] & 0x80) != 0) {
        FUN_1003bb5d((int)(char)bVar9,param_1,&local_18);
        bVar9 = *param_2;
        param_2 = pbVar1 + 2;
      }
      FUN_1003bb5d((int)(char)bVar9,param_1,&local_18);
      break;
    case 1:
      local_14 = -1;
      local_38 = 0;
      local_2c = 0;
      local_24 = 0;
      local_20 = 0;
      local_8 = 0;
      local_28 = 0;
      break;
    case 2:
      if (bVar9 == 0x20) {
        local_8 = local_8 | 2;
      }
      else if (bVar9 == 0x23) {
        local_8 = local_8 | 0x80;
      }
      else if (bVar9 == 0x2b) {
        local_8 = local_8 | 1;
      }
      else if (bVar9 == 0x2d) {
        local_8 = local_8 | 4;
      }
      else if (bVar9 == 0x30) {
        local_8 = local_8 | 8;
      }
      break;
    case 3:
      if (bVar9 == 0x2a) {
        local_24 = FUN_1003bbfb((int *)&param_3);
        if (local_24 < 0) {
          local_8 = local_8 | 4;
          local_24 = -local_24;
        }
      }
      else {
        local_24 = (char)bVar9 + -0x30 + local_24 * 10;
      }
      break;
    case 4:
      local_14 = 0;
      break;
    case 5:
      if (bVar9 == 0x2a) {
        local_14 = FUN_1003bbfb((int *)&param_3);
        if (local_14 < 0) {
          local_14 = -1;
        }
      }
      else {
        local_14 = (char)bVar9 + -0x30 + local_14 * 10;
      }
      break;
    case 6:
      if (bVar9 == 0x49) {
        if ((*param_2 != 0x36) || (pbVar1[2] != 0x34)) {
          local_34 = 0;
          goto switchD_1003b48a_caseD_0;
        }
        param_2 = pbVar1 + 3;
        local_8 = local_8 | 0x8000;
      }
      else if (bVar9 == 0x68) {
        local_8 = local_8 | 0x20;
      }
      else if (bVar9 == 0x6c) {
        local_8 = local_8 | 0x10;
      }
      else if (bVar9 == 0x77) {
        local_8 = local_8 | 0x800;
      }
      break;
    case 7:
      pWVar4 = local_c;
      if ((char)bVar9 < 'h') {
        if ((char)bVar9 < 'e') {
          if ((char)bVar9 < 'Y') {
            if (bVar9 == 0x58) {
LAB_1003b89b:
              local_30 = 7;
LAB_1003b8a2:
              local_10 = (undefined1 *)0x10;
              if ((local_8 & 0x80) != 0) {
                local_1a = '0';
                local_19 = (char)local_30 + 'Q';
                local_20 = 2;
              }
              goto LAB_1003b90c;
            }
            if (bVar9 != 0x43) {
              if ((bVar9 != 0x45) && (bVar9 != 0x47)) {
                if (bVar9 == 0x53) {
                  if ((local_8 & 0x830) == 0) {
                    local_8 = local_8 | 0x800;
                  }
                  goto LAB_1003b649;
                }
                goto LAB_1003ba26;
              }
              local_38 = 1;
              bVar9 = bVar9 + 0x20;
              goto LAB_1003b6aa;
            }
            if ((local_8 & 0x830) == 0) {
              local_8 = local_8 | 0x800;
            }
LAB_1003b6d7:
            if ((local_8 & 0x810) == 0) {
              uVar5 = FUN_1003bbfb((int *)&param_3);
              local_24c[0] = (char)uVar5;
              local_10 = (undefined1 *)0x1;
            }
            else {
              uVar5 = FUN_1003bc18((int *)&param_3);
              local_10 = (undefined1 *)FUN_10040831(local_24c,(WCHAR)uVar5);
              if ((int)local_10 < 0) {
                local_2c = 1;
              }
            }
            pWVar4 = (WCHAR *)local_24c;
          }
          else if (bVar9 == 0x5a) {
            psVar6 = (short *)FUN_1003bbfb((int *)&param_3);
            if ((psVar6 == (short *)0x0) ||
               (pWVar4 = *(WCHAR **)(psVar6 + 2), pWVar4 == (WCHAR *)0x0)) {
              local_c = (WCHAR *)PTR_DAT_1005fee0;
              pWVar4 = (WCHAR *)PTR_DAT_1005fee0;
              goto LAB_1003b81c;
            }
            if ((local_8 & 0x800) == 0) {
              local_28 = 0;
              local_10 = (undefined1 *)(int)*psVar6;
            }
            else {
              local_28 = 1;
              local_10 = (undefined1 *)((uint)(int)*psVar6 >> 1);
            }
          }
          else {
            if (bVar9 == 99) goto LAB_1003b6d7;
            if (bVar9 == 100) goto LAB_1003b901;
          }
        }
        else {
LAB_1003b6aa:
          local_8 = local_8 | 0x40;
          pWVar4 = (WCHAR *)local_24c;
          if (local_14 < 0) {
            local_14 = 6;
          }
          else if ((local_14 == 0) && (bVar9 == 0x67)) {
            local_14 = 1;
          }
          local_4c = *param_3;
          local_48 = param_3[1];
          param_3 = param_3 + 2;
          local_c = pWVar4;
          (*(code *)PTR___fptrap_1005fb94)(&local_4c,local_24c,(int)(char)bVar9,local_14,local_38);
          uVar2 = local_8 & 0x80;
          if ((uVar2 != 0) && (local_14 == 0)) {
            (*(code *)PTR___fptrap_1005fba0)(local_24c);
          }
          if ((bVar9 == 0x67) && (uVar2 == 0)) {
            (*(code *)PTR___fptrap_1005fb98)(local_24c);
          }
          if (local_24c[0] == '-') {
            local_8 = local_8 | 0x100;
            pWVar4 = (WCHAR *)(local_24c + 1);
            local_c = pWVar4;
          }
LAB_1003b81c:
          local_10 = (undefined1 *)_strlen((char *)pWVar4);
          pWVar4 = local_c;
        }
      }
      else {
        if (bVar9 == 0x69) {
LAB_1003b901:
          local_8 = local_8 | 0x40;
        }
        else {
          if (bVar9 == 0x6e) {
            piVar7 = (int *)FUN_1003bbfb((int *)&param_3);
            if ((local_8 & 0x20) == 0) {
              *piVar7 = local_18;
            }
            else {
              *(undefined2 *)piVar7 = (undefined2)local_18;
            }
            local_2c = 1;
            break;
          }
          if (bVar9 == 0x6f) {
            local_10 = (undefined1 *)0x8;
            if ((local_8 & 0x80) != 0) {
              local_8 = local_8 | 0x200;
            }
            goto LAB_1003b90c;
          }
          if (bVar9 == 0x70) {
            local_14 = 8;
            goto LAB_1003b89b;
          }
          if (bVar9 == 0x73) {
LAB_1003b649:
            iVar10 = local_14;
            if (local_14 == -1) {
              iVar10 = 0x7fffffff;
            }
            pWVar3 = (WCHAR *)FUN_1003bbfb((int *)&param_3);
            if ((local_8 & 0x810) == 0) {
              pWVar4 = pWVar3;
              if (pWVar3 == (WCHAR *)0x0) {
                pWVar3 = (WCHAR *)PTR_DAT_1005fee0;
                pWVar4 = (WCHAR *)PTR_DAT_1005fee0;
              }
              for (; (iVar10 != 0 && ((char)*pWVar3 != '\0')); pWVar3 = (WCHAR *)((int)pWVar3 + 1))
              {
                iVar10 = iVar10 + -1;
              }
              local_10 = (undefined1 *)((int)pWVar3 - (int)pWVar4);
            }
            else {
              if (pWVar3 == (WCHAR *)0x0) {
                pWVar3 = (WCHAR *)PTR_DAT_1005fee4;
              }
              local_28 = 1;
              for (pWVar4 = pWVar3; (iVar10 != 0 && (*pWVar4 != L'\0')); pWVar4 = pWVar4 + 1) {
                iVar10 = iVar10 + -1;
              }
              local_10 = (undefined1 *)((int)pWVar4 - (int)pWVar3 >> 1);
              pWVar4 = pWVar3;
            }
            goto LAB_1003ba26;
          }
          if (bVar9 != 0x75) {
            if (bVar9 != 0x78) goto LAB_1003ba26;
            local_30 = 0x27;
            goto LAB_1003b8a2;
          }
        }
        local_10 = (undefined1 *)0xa;
LAB_1003b90c:
        if ((local_8 & 0x8000) == 0) {
          if ((local_8 & 0x20) == 0) {
            if ((local_8 & 0x40) == 0) {
              uVar2 = FUN_1003bbfb((int *)&param_3);
              uVar13 = (ulonglong)uVar2;
              goto LAB_1003b95f;
            }
            uVar2 = FUN_1003bbfb((int *)&param_3);
          }
          else if ((local_8 & 0x40) == 0) {
            uVar2 = FUN_1003bbfb((int *)&param_3);
            uVar2 = uVar2 & 0xffff;
          }
          else {
            uVar5 = FUN_1003bbfb((int *)&param_3);
            uVar2 = (uint)(short)uVar5;
          }
          uVar13 = (ulonglong)(int)uVar2;
        }
        else {
          uVar13 = FUN_1003bc08((int *)&param_3);
        }
LAB_1003b95f:
        iVar10 = (int)(uVar13 >> 0x20);
        if ((((local_8 & 0x40) != 0) && (iVar10 == 0 || (longlong)uVar13 < 0)) &&
           ((longlong)uVar13 < 0)) {
          local_8 = local_8 | 0x100;
          uVar13 = CONCAT44(-(iVar10 + (uint)((int)uVar13 != 0)),-(int)uVar13);
        }
        uVar2 = (uint)(uVar13 >> 0x20);
        uVar15 = uVar13 & 0xffffffff;
        if ((local_8 & 0x8000) == 0) {
          uVar2 = 0;
        }
        if (local_14 < 0) {
          local_14 = 1;
        }
        else {
          local_8 = local_8 & 0xfffffff7;
        }
        if ((int)uVar13 == 0 && uVar2 == 0) {
          local_20 = 0;
        }
        local_c = (WCHAR *)&local_4d;
        while( true ) {
          uVar11 = (uint)uVar15;
          iVar10 = local_14 + -1;
          if ((local_14 < 1) && (uVar11 == 0 && uVar2 == 0)) break;
          local_40 = (int)local_10 >> 0x1f;
          local_44 = (uint)local_10;
          local_14 = iVar10;
          uVar14 = __aullrem(uVar11,uVar2,(uint)local_10,local_40);
          iVar10 = (int)uVar14 + 0x30;
          uVar15 = __aulldiv(uVar11,uVar2,local_44,local_40);
          uVar2 = (uint)(uVar15 >> 0x20);
          if (0x39 < iVar10) {
            iVar10 = iVar10 + local_30;
          }
          pWVar4 = (WCHAR *)((int)local_c + -1);
          *(char *)local_c = (char)iVar10;
          local_c = pWVar4;
        }
        iVar8 = -(int)local_c;
        local_10 = &local_4d + iVar8;
        pWVar4 = (WCHAR *)((int)local_c + 1);
        local_14 = iVar10;
        if (((local_8 & 0x200) != 0) &&
           ((*(char *)pWVar4 != '0' || (local_10 == (undefined1 *)0x0)))) {
          *(char *)local_c = '0';
          local_10 = (undefined1 *)((int)&local_4c + iVar8);
          pWVar4 = local_c;
        }
      }
LAB_1003ba26:
      local_c = pWVar4;
      uVar2 = local_8;
      if (local_2c == 0) {
        if ((local_8 & 0x40) != 0) {
          if ((local_8 & 0x100) == 0) {
            if ((local_8 & 1) == 0) {
              if ((local_8 & 2) == 0) goto LAB_1003ba5e;
              local_1a = ' ';
            }
            else {
              local_1a = '+';
            }
          }
          else {
            local_1a = '-';
          }
          local_20 = 1;
        }
LAB_1003ba5e:
        iVar10 = (local_24 - local_20) - (int)local_10;
        if ((local_8 & 0xc) == 0) {
          FUN_1003bb92(0x20,iVar10,param_1,&local_18);
        }
        FUN_1003bbc3(&local_1a,local_20,param_1,&local_18);
        if (((uVar2 & 8) != 0) && ((uVar2 & 4) == 0)) {
          FUN_1003bb92(0x30,iVar10,param_1,&local_18);
        }
        if ((local_28 == 0) || (puVar12 = local_10, pWVar4 = local_c, (int)local_10 < 1)) {
          FUN_1003bbc3((char *)local_c,(int)local_10,param_1,&local_18);
        }
        else {
          do {
            puVar12 = puVar12 + -1;
            iVar8 = FUN_10040831(local_3c,*pWVar4);
            if (iVar8 < 1) break;
            FUN_1003bbc3(local_3c,iVar8,param_1,&local_18);
            pWVar4 = pWVar4 + 1;
          } while (puVar12 != (undefined1 *)0x0);
        }
        if ((local_8 & 4) != 0) {
          FUN_1003bb92(0x20,iVar10,param_1,&local_18);
        }
      }
    }
    bVar9 = *param_2;
    pbVar1 = param_2;
  } while( true );
}



/* FUN_10034310 @ 10034310 size 1554 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10034310(void)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  float fVar4;
  undefined4 uVar5;
  uint uVar6;
  ulonglong uVar7;
  int iVar8;
  
  if (*(int *)(DAT_10061394 + 0x104) == 1) {
    *(float *)(DAT_10061394 + 0x194) = DAT_1006c2e4 + _DAT_10044244;
    return;
  }
  iVar2 = *(int *)(DAT_10061394 + 0x2a8);
  iVar8 = *(int *)(DAT_100613bc + 0xe90);
  *(int *)(DAT_100613bc + 0xe90) = iVar2;
  fVar4 = (float)DAT_1006c2e0;
  fVar1 = *(float *)(DAT_100613bc + 0xeb4);
  bVar3 = fVar4 < *(float *)(DAT_100613bc + 0xeb8);
  if (iVar8 == 0) {
    if (iVar2 == 0) goto LAB_100344c1;
    FUN_100350a0(DAT_10061394,(float *)(DAT_10061394 + 4),0);
    uVar6 = *(uint *)(DAT_10061394 + 0x2a4);
    if ((uVar6 & 8) == 0) {
      if ((uVar6 & 0x10) != 0) {
        uVar5 = (*DAT_1006c1e4)(s_player_watr_in_wav_100496bc,0x3f800000,0x3f800000,0);
        goto LAB_10034437;
      }
      if ((uVar6 & 0x20) != 0) {
        uVar5 = (*DAT_1006c1e4)(s_player_watr_in_wav_100496bc,0x3f800000,0x3f800000,0);
        goto LAB_10034437;
      }
    }
    else {
      uVar5 = (*DAT_1006c1e4)(s_player_lava_in_wav_1005f6d8,0x3f800000,0x3f800000,0);
LAB_10034437:
      (*DAT_1006c1d0)(DAT_10061394,4,uVar5);
    }
    *(uint *)(DAT_10061394 + 0x108) = *(uint *)(DAT_10061394 + 0x108) | 8;
    *(float *)(DAT_10061394 + 0x214) = DAT_1006c2e4 - _DAT_10044104;
LAB_100344c1:
    if (iVar2 == 3) {
      uVar5 = (*DAT_1006c1e4)(s_player_watr_un_wav_1004b60c,0x3f800000,0x3f800000,0);
      (*DAT_1006c1d0)(DAT_10061394,4,uVar5);
    }
    if (iVar8 == 3) goto LAB_100344fb;
LAB_100345a8:
    if (iVar2 != 3) {
      *(float *)(DAT_10061394 + 0x194) = DAT_1006c2e4 + _DAT_10044244;
      *(undefined4 *)(DAT_10061394 + 0x244) = 2;
      if (iVar2 == 0) {
        return;
      }
      goto LAB_100347ed;
    }
  }
  else {
    if (iVar2 == 0) {
      FUN_100350a0(DAT_10061394,(float *)(DAT_10061394 + 4),0);
      uVar5 = (*DAT_1006c1e4)(s_player_watr_out_wav_100496f8,0x3f800000,0x3f800000,0);
      (*DAT_1006c1d0)(DAT_10061394,4,uVar5);
      *(uint *)(DAT_10061394 + 0x108) = *(uint *)(DAT_10061394 + 0x108) & 0xfffffff7;
    }
    if (iVar8 != 3) goto LAB_100344c1;
LAB_100344fb:
    if (iVar2 != 3) {
      if (DAT_1006c2e4 <= *(float *)(DAT_10061394 + 0x194)) {
        if (*(float *)(DAT_10061394 + 0x194) < DAT_1006c2e4 + _DAT_10044430) {
          uVar5 = (*DAT_1006c1e4)(s_player_gasp2_wav_1004b620,0x3f800000,0x3f800000,0);
          (*DAT_1006c1d0)(DAT_10061394,2,uVar5);
        }
      }
      else {
        uVar5 = (*DAT_1006c1e4)(s_player_gasp1_wav_1004b634,0x3f800000,0x3f800000,0);
        (*DAT_1006c1d0)(DAT_10061394,2,uVar5);
        FUN_100350a0(DAT_10061394,(float *)(DAT_10061394 + 4),0);
      }
      goto LAB_100345a8;
    }
  }
  if ((fVar4 < fVar1) || (bVar3)) {
    *(float *)(DAT_10061394 + 0x194) = DAT_1006c2e4 + _DAT_100441b0;
    iVar8 = DAT_100613bc;
    uVar7 = __ftol();
    if ((int)((longlong)((ulonglong)(uint)((int)uVar7 >> 0x1f) << 0x20 | uVar7 & 0xffffffff) % 0x19)
        == 0) {
      if (*(int *)(iVar8 + 0xe94) == 0) {
        uVar5 = (*DAT_1006c1e4)(s_player_u_breath1_wav_1004b5f4);
      }
      else {
        uVar5 = (*DAT_1006c1e4)(s_player_u_breath2_wav_1004b5dc,0x3f800000,0x3f800000,0);
      }
      (*DAT_1006c1d0)(DAT_10061394,0,uVar5);
      *(uint *)(DAT_100613bc + 0xe94) = *(uint *)(DAT_100613bc + 0xe94) ^ 1;
      FUN_100350a0(DAT_10061394,(float *)(DAT_10061394 + 4),0);
    }
  }
  if (((*(float *)(DAT_10061394 + 0x194) < DAT_1006c2e4) &&
      (*(float *)(*(int *)(DAT_10061394 + 0x54) + 0xe8c) < DAT_1006c2e4)) &&
     (0 < *(int *)(DAT_10061394 + 0x220))) {
    *(float *)(*(int *)(DAT_10061394 + 0x54) + 0xe8c) = DAT_1006c2e4 + _DAT_10044104;
    *(int *)(DAT_10061394 + 0x244) = *(int *)(DAT_10061394 + 0x244) + 2;
    if (0xf < *(int *)(DAT_10061394 + 0x244)) {
      *(undefined4 *)(DAT_10061394 + 0x244) = 0xf;
    }
    if (*(int *)(DAT_10061394 + 0x244) < *(int *)(DAT_10061394 + 0x220)) {
      uVar6 = _rand();
      if ((uVar6 & 1) == 0) {
        uVar5 = (*DAT_1006c1e4)(s__gurp2_wav_1004b6d4,0x3f800000,0x3f800000,0);
      }
      else {
        uVar5 = (*DAT_1006c1e4)(s__gurp1_wav_1004b6e0);
      }
    }
    else {
      uVar5 = (*DAT_1006c1e4)(s_player_drown1_wav_1005f6c4,0x3f800000,0x3f800000,0);
    }
    (*DAT_1006c1d0)(DAT_10061394,2,uVar5);
    *(float *)(DAT_10061394 + 0x210) = DAT_1006c2e4;
    FUN_100060d0(DAT_10061394,DAT_1006c2c4,DAT_1006c2c4,(float *)&DAT_10061c18,
                 (float *)(DAT_10061394 + 4),&DAT_10061c18,*(int *)(DAT_10061394 + 0x244),0,2,0x11);
  }
LAB_100347ed:
  if ((*(uint *)(DAT_10061394 + 0x2a4) & 0x18) != 0) {
    if ((*(uint *)(DAT_10061394 + 0x2a4) & 8) != 0) {
      if (((0 < *(int *)(DAT_10061394 + 0x220)) &&
          (*(float *)(DAT_10061394 + 0x210) <= DAT_1006c2e4)) &&
         (*(float *)(DAT_100613bc + 0xeb0) < (float)DAT_1006c2e0)) {
        uVar6 = _rand();
        if ((uVar6 & 1) == 0) {
          uVar5 = (*DAT_1006c1e4)(s_player_burn2_wav_1005f69c,0x3f800000,0x3f800000,0);
        }
        else {
          uVar5 = (*DAT_1006c1e4)(s_player_burn1_wav_1005f6b0);
        }
        (*DAT_1006c1d0)(DAT_10061394,2,uVar5);
        *(float *)(DAT_10061394 + 0x210) = DAT_1006c2e4 + _DAT_10044104;
      }
      iVar8 = iVar2;
      if (!bVar3) {
        iVar8 = iVar2 * 3;
      }
      FUN_100060d0(DAT_10061394,DAT_1006c2c4,DAT_1006c2c4,(float *)&DAT_10061c18,
                   (float *)(DAT_10061394 + 4),&DAT_10061c18,iVar8,0,0,0x13);
    }
    if (((*(byte *)(DAT_10061394 + 0x2a4) & 0x10) != 0) && (!bVar3)) {
      FUN_100060d0(DAT_10061394,DAT_1006c2c4,DAT_1006c2c4,(float *)&DAT_10061c18,
                   (float *)(DAT_10061394 + 4),&DAT_10061c18,iVar2,0,0,0x12);
    }
  }
  return;
}



/* FUN_1001b8c0 @ 1001b8c0 size 1512 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_1001b8c0(int param_1,float *param_2,float *param_3,int param_4,int param_5,undefined4 param_6,
            int param_7,int param_8,uint param_9)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  byte *pbVar8;
  char *pcVar9;
  float *pfVar10;
  bool bVar11;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float fStack_c0;
  undefined8 uStack_bc;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  int local_a0;
  float afStack_9c [4];
  float fStack_8c;
  float fStack_88;
  undefined1 auStack_84 [20];
  byte *pbStack_70;
  byte bStack_6c;
  uint uStack_68;
  double dStack_64;
  float afStack_5c [3];
  float afStack_50 [3];
  float afStack_44 [3];
  undefined1 local_38 [56];
  
  local_a0 = 0;
  uVar7 = 0x600003b;
  pfVar4 = (float *)(*DAT_1006c1f0)(local_38,param_1 + 4,0,0,param_2,param_1,0x6000003);
  pfVar10 = afStack_9c;
  for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {
    *pfVar10 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pfVar10 = pfVar10 + 1;
  }
  if (afStack_9c[2] < (float)_DAT_10044120) goto LAB_1001bca0;
  FUN_1001b1e0(param_3,&fStack_b0);
  FUN_10038700(&fStack_b0,afStack_5c,afStack_50,afStack_44);
  dStack_64 = (double)param_7;
  uVar5 = _rand();
  fVar2 = (float)(uVar5 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  fStack_a4 = (fVar2 + fVar2) * (float)dStack_64;
  uStack_bc = (double)param_8;
  uVar5 = _rand();
  fVar2 = (float)(uVar5 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  fVar3 = (float)uStack_bc;
  FUN_10038950(param_2,8192.0,afStack_5c,&fStack_c8);
  FUN_10038950(&fStack_c8,fStack_a4,afStack_50,&fStack_c8);
  FUN_10038950(&fStack_c8,(fVar2 + fVar2) * fVar3,afStack_44,&fStack_c8);
  uVar5 = (*DAT_1006c1f4)(param_2);
  if ((uVar5 & 0x38) != 0) {
    fStack_d4 = *param_2;
    fStack_d0 = param_2[1];
    fStack_cc = param_2[2];
    local_a0 = 1;
    uVar7 = 0x6000003;
  }
  pfVar4 = (float *)(*DAT_1006c1f0)(local_38,param_2,0,0,&fStack_c8,param_1,uVar7);
  pfVar10 = afStack_9c;
  for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {
    *pfVar10 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pfVar10 = pfVar10 + 1;
  }
  if ((bStack_6c & 0x38) == 0) goto LAB_1001bca0;
  fStack_d4 = afStack_9c[3];
  local_a0 = 1;
  fStack_d0 = fStack_8c;
  fStack_cc = fStack_88;
  iVar6 = FUN_100388c0(param_2,afStack_9c + 3);
  if (iVar6 == 0) {
    if ((bStack_6c & 0x20) == 0) {
      if ((bStack_6c & 0x10) != 0) {
        iVar6 = 4;
        goto LAB_1001bb21;
      }
      if ((bStack_6c & 8) != 0) {
        iVar6 = 5;
        goto LAB_1001bb21;
      }
    }
    else {
      pcVar9 = s__brwater_1004be68;
      pbVar8 = pbStack_70;
      do {
        bVar1 = *pbVar8;
        bVar11 = bVar1 < (byte)*pcVar9;
        if (bVar1 != *pcVar9) {
LAB_1001bafd:
          iVar6 = 3 - (uint)(1 - bVar11 != (uint)(bVar11 != 0));
          goto LAB_1001bb21;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar8[1];
        bVar11 = bVar1 < (byte)pcVar9[1];
        if (bVar1 != pcVar9[1]) goto LAB_1001bafd;
        pbVar8 = pbVar8 + 2;
        pcVar9 = pcVar9 + 2;
      } while (bVar1 != 0);
      iVar6 = 3;
LAB_1001bb21:
      (*DAT_1006c224)(3);
      (*DAT_1006c224)(10);
      (*DAT_1006c224)(8);
      (*DAT_1006c238)(afStack_9c + 3);
      (*DAT_1006c23c)(auStack_84);
      (*DAT_1006c224)(iVar6);
      (*DAT_1006c218)(afStack_9c + 3,2);
    }
    fStack_b0 = fStack_c8 - *param_2;
    fStack_ac = fStack_c4 - param_2[1];
    fStack_a8 = fStack_c0 - param_2[2];
    FUN_1001b1e0(&fStack_b0,&fStack_b0);
    FUN_10038700(&fStack_b0,afStack_5c,afStack_50,afStack_44);
    uVar5 = _rand();
    fVar2 = (float)(uVar5 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
    fStack_a4 = (fVar2 + fVar2) * (float)dStack_64;
    fStack_a4 = fStack_a4 + fStack_a4;
    uVar5 = _rand();
    fVar2 = (float)(uVar5 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
    fVar2 = (fVar2 + fVar2) * (float)uStack_bc;
    FUN_10038950(&fStack_d4,8192.0,afStack_5c,&fStack_c8);
    FUN_10038950(&fStack_c8,fStack_a4,afStack_50,&fStack_c8);
    FUN_10038950(&fStack_c8,fVar2 + fVar2,afStack_44,&fStack_c8);
  }
  pfVar4 = (float *)(*DAT_1006c1f0)(local_38,&fStack_d4,0,0,&fStack_c8,param_1,0x6000003);
  pfVar10 = afStack_9c;
  for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {
    *pfVar10 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pfVar10 = pfVar10 + 1;
  }
LAB_1001bca0:
  if (((pbStack_70 == (byte *)0x0) || ((pbStack_70[0x10] & 4) == 0)) &&
     (afStack_9c[2] < (float)_DAT_10044120)) {
    if (*(int *)(uStack_68 + 0x240) == 0) {
      iVar6 = _strncmp((char *)pbStack_70,&DAT_10049fd8,3);
      if (iVar6 != 0) {
        (*DAT_1006c224)(3);
        (*DAT_1006c224)(param_6);
        (*DAT_1006c238)(afStack_9c + 3);
        (*DAT_1006c23c)(auStack_84);
        (*DAT_1006c218)(afStack_9c + 3,2);
        if (*(int *)(param_1 + 0x54) != 0) {
          FUN_100350a0(param_1,afStack_9c + 3,2);
        }
      }
    }
    else {
      FUN_100060d0(uStack_68,param_1,param_1,param_3,afStack_9c + 3,auStack_84,param_4,param_5,0x10,
                   param_9);
    }
  }
  if (local_a0 != 0) {
    fStack_b0 = afStack_9c[3] - fStack_d4;
    fStack_ac = fStack_8c - fStack_d0;
    fStack_a8 = fStack_88 - fStack_cc;
    FUN_10038900(&fStack_b0);
    FUN_10038950(afStack_9c + 3,-2.0,&fStack_b0,(float *)&uStack_bc);
    uVar5 = (*DAT_1006c1f4)(&uStack_bc);
    if ((uVar5 & 0x38) == 0) {
      pfVar4 = (float *)(*DAT_1006c1f0)(local_38,&uStack_bc,0,0,&fStack_d4,uStack_68,0x38);
      pfVar10 = afStack_9c;
      for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {
        *pfVar10 = *pfVar4;
        pfVar4 = pfVar4 + 1;
        pfVar10 = pfVar10 + 1;
      }
    }
    else {
      afStack_9c[3] = (float)uStack_bc;
      fStack_8c = uStack_bc._4_4_;
      fStack_88 = fStack_b4;
    }
    uStack_bc = (double)CONCAT44(fStack_8c + fStack_d0,afStack_9c[3] + fStack_d4);
    fStack_b4 = fStack_88 + fStack_cc;
    FUN_10038a20((float *)&uStack_bc,0.5,(float *)&uStack_bc);
    (*DAT_1006c224)(3);
    (*DAT_1006c224)(0xb);
    (*DAT_1006c238)(&fStack_d4);
    (*DAT_1006c238)(afStack_9c + 3);
    (*DAT_1006c218)(&uStack_bc,2);
  }
  return;
}



/* FUN_1002a330 @ 1002a330 size 1299 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1002a330(int param_1,float *param_2,int param_3)

{
  byte bVar1;
  float fVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  int local_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  float fStack_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  int aiStack_b4 [2];
  float fStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  float fStack_a0;
  int iStack_80;
  float local_7c;
  float local_78;
  float local_74;
  undefined1 local_70 [56];
  undefined1 auStack_38 [56];
  
  local_dc = *param_2 + *(float *)(param_1 + 4);
  local_c0 = *(undefined4 *)(param_1 + 4);
  local_bc = *(undefined4 *)(param_1 + 8);
  local_b8 = *(undefined4 *)(param_1 + 0xc);
  local_d8 = *(float *)(param_1 + 8) + param_2[1];
  if ((*(byte *)(param_1 + 0x108) & 3) == 0) {
    local_e0 = 18.0;
    if ((*(uint *)(param_1 + 0x35c) & 0x400) != 0) {
      local_e0 = 1.0;
    }
    local_d4 = local_e0 + *(float *)(param_1 + 0xc) + param_2[2];
    local_74 = local_d4 - (local_e0 + local_e0);
    local_7c = local_dc;
    local_78 = local_d8;
    piVar3 = (int *)(*DAT_1006c1f0)(local_70,&local_dc,param_1 + 0xbc,param_1 + 200,&local_7c,
                                    param_1,0x2020003);
    piVar6 = aiStack_b4;
    for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar6 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar6 = piVar6 + 1;
    }
    if (aiStack_b4[0] != 0) {
      return 0;
    }
    if (aiStack_b4[1] != 0) {
      local_d4 = local_d4 - local_e0;
      piVar3 = (int *)(*DAT_1006c1f0)(auStack_38,&local_dc,param_1 + 0xbc,param_1 + 200,&local_7c,
                                      param_1,0x2020003);
      piVar6 = aiStack_b4;
      for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {
        *piVar6 = *piVar3;
        piVar3 = piVar3 + 1;
        piVar6 = piVar6 + 1;
      }
      if ((aiStack_b4[0] != 0) || (aiStack_b4[1] != 0)) {
        return 0;
      }
    }
    if (*(int *)(param_1 + 0x2a8) == 0) {
      uStack_cc = uStack_a8;
      fStack_c4 = fStack_a0 + *(float *)(param_1 + 0xc4) + _DAT_10044104;
      uStack_c8 = uStack_a4;
      uVar4 = (*DAT_1006c1f4)(&uStack_cc);
      if ((uVar4 & 0x38) != 0) {
        return 0;
      }
    }
    if (fStack_ac == _DAT_10044104) {
      if ((*(uint *)(param_1 + 0x108) & 0x100) == 0) {
        return 0;
      }
      *(float *)(param_1 + 4) = *param_2 + *(float *)(param_1 + 4);
      *(float *)(param_1 + 8) = *(float *)(param_1 + 8) + param_2[1];
      *(float *)(param_1 + 0xc) = *(float *)(param_1 + 0xc) + param_2[2];
      if (param_3 != 0) {
        (*DAT_1006c208)(param_1);
        FUN_1001b480();
      }
      *(undefined4 *)(param_1 + 0x268) = 0;
      return 1;
    }
    *(undefined4 *)(param_1 + 4) = uStack_a8;
    *(undefined4 *)(param_1 + 8) = uStack_a4;
    *(float *)(param_1 + 0xc) = fStack_a0;
    iVar5 = FUN_1002a0c0(param_1);
    uVar4 = *(uint *)(param_1 + 0x108);
    if (iVar5 == 0) {
      if ((uVar4 & 0x100) == 0) {
        *(undefined4 *)(param_1 + 4) = local_c0;
        *(undefined4 *)(param_1 + 8) = local_bc;
        *(undefined4 *)(param_1 + 0xc) = local_b8;
        return 0;
      }
    }
    else {
      if ((uVar4 & 0x100) != 0) {
        *(uint *)(param_1 + 0x108) = uVar4 & 0xfffffeff;
      }
      *(int *)(param_1 + 0x268) = iStack_80;
      *(undefined4 *)(param_1 + 0x26c) = *(undefined4 *)(iStack_80 + 0x5c);
    }
  }
  else {
    local_d0 = 0;
    while( true ) {
      local_dc = *param_2 + *(float *)(param_1 + 4);
      local_d8 = *(float *)(param_1 + 8) + param_2[1];
      local_d4 = *(float *)(param_1 + 0xc) + param_2[2];
      if ((local_d0 == 0) && (*(int *)(param_1 + 0x25c) != 0)) {
        if (*(int *)(param_1 + 0x1dc) == 0) {
          *(int *)(param_1 + 0x1dc) = *(int *)(param_1 + 0x25c);
        }
        fVar2 = *(float *)(param_1 + 0xc) - *(float *)(*(int *)(param_1 + 0x1dc) + 0xc);
        if (*(int *)(*(int *)(param_1 + 0x1dc) + 0x54) == 0) {
          if (fVar2 <= _DAT_10044164) {
            if (fVar2 <= _DAT_1004410c) {
              if (_DAT_100443a8 <= fVar2) {
                local_d4 = fVar2 + local_d4;
              }
              else {
                local_d4 = local_d4 + _DAT_10044164;
              }
            }
            else {
              local_d4 = local_d4 - fVar2;
            }
          }
          else {
            local_d4 = local_d4 - _DAT_10044164;
          }
        }
        else {
          if (_DAT_10044288 < fVar2) {
            local_d4 = local_d4 - _DAT_10044164;
          }
          if ((((*(byte *)(param_1 + 0x108) & 2) == 0) || (1 < *(int *)(param_1 + 0x2a8))) &&
             (fVar2 < _DAT_10044220)) {
            local_d4 = local_d4 + _DAT_10044164;
          }
        }
      }
      piVar3 = (int *)(*DAT_1006c1f0)(local_70,param_1 + 4,param_1 + 0xbc,param_1 + 200,&local_dc,
                                      param_1,0x2020003);
      bVar1 = *(byte *)(param_1 + 0x108);
      piVar6 = aiStack_b4;
      for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {
        *piVar6 = *piVar3;
        piVar3 = piVar3 + 1;
        piVar6 = piVar6 + 1;
      }
      if (((bVar1 & 1) != 0) && (*(int *)(param_1 + 0x2a8) == 0)) {
        uStack_cc = uStack_a8;
        fStack_c4 = fStack_a0 + *(float *)(param_1 + 0xc4) + _DAT_10044104;
        uStack_c8 = uStack_a4;
        uVar4 = (*DAT_1006c1f4)(&uStack_cc);
        if ((uVar4 & 0x38) != 0) {
          return 0;
        }
      }
      if (((*(byte *)(param_1 + 0x108) & 2) != 0) && (*(int *)(param_1 + 0x2a8) < 2)) {
        uStack_cc = uStack_a8;
        fStack_c4 = fStack_a0 + *(float *)(param_1 + 0xc4) + _DAT_10044104;
        uStack_c8 = uStack_a4;
        uVar4 = (*DAT_1006c1f4)(&uStack_cc);
        if ((uVar4 & 0x38) == 0) {
          return 0;
        }
      }
      if (fStack_ac == _DAT_10044104) break;
      if (*(int *)(param_1 + 0x25c) == 0) {
        return 0;
      }
      local_d0 = local_d0 + 1;
      if (1 < local_d0) {
        return 0;
      }
    }
    *(undefined4 *)(param_1 + 8) = uStack_a4;
    *(undefined4 *)(param_1 + 4) = uStack_a8;
    *(float *)(param_1 + 0xc) = fStack_a0;
  }
  if (param_3 != 0) {
    (*DAT_1006c208)(param_1);
    FUN_1001b480();
  }
  return 1;
}



/* FUN_10013460 @ 10013460 size 1296 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10013460(int param_1,float *param_2,float *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  float *pfVar4;
  float *pfVar5;
  uint uVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  longlong lVar10;
  float local_60;
  float local_5c;
  float local_58;
  float local_54 [7];
  float fStack_38;
  float fStack_34;
  float local_30;
  float fStack_2c;
  float fStack_28;
  float local_24;
  float fStack_20;
  float fStack_1c;
  float fStack_14;
  float fStack_10;
  float fStack_8;
  float fStack_4;
  
  pfVar4 = param_2;
  iVar9 = 3;
  pfVar5 = param_2;
  do {
    lVar10 = __ftol();
    iVar9 = iVar9 + -1;
    *pfVar5 = (float)(int)lVar10 * (float)_DAT_10044260;
    pfVar5 = pfVar5 + 1;
  } while (iVar9 != 0);
  iVar9 = 3;
  pfVar5 = param_2;
  pfVar7 = (float *)(param_1 + 0xe0);
  do {
    iVar9 = iVar9 + -1;
    *(float *)((int)pfVar5 + (int)local_54 + (0xc - (int)param_2)) = pfVar7[-3] + *pfVar5;
    *(float *)((int)pfVar5 + ((int)local_54 - (int)param_2)) = *pfVar5 + *pfVar7;
    pfVar5 = pfVar5 + 1;
    pfVar7 = pfVar7 + 1;
  } while (iVar9 != 0);
  local_60 = DAT_10061c18 - *param_3;
  local_5c = DAT_10061c1c - param_3[1];
  local_58 = DAT_10061c20 - param_3[2];
  FUN_10038700(&local_60,local_54 + 6,&local_30,&local_24);
  *DAT_100640f0 = param_1;
  DAT_100640f0[1] = *(int *)(param_1 + 4);
  DAT_100640f0[2] = *(int *)(param_1 + 8);
  DAT_100640f0[3] = *(int *)(param_1 + 0xc);
  DAT_100640f0[4] = *(int *)(param_1 + 0x10);
  DAT_100640f0[5] = *(int *)(param_1 + 0x14);
  DAT_100640f0[6] = *(int *)(param_1 + 0x18);
  if (*(int *)(param_1 + 0x54) != 0) {
    DAT_100640f0[7] = (int)(float)(int)*(short *)(*(int *)(param_1 + 0x54) + 0x16);
  }
  DAT_100640f0 = DAT_100640f0 + 8;
  *(float *)(param_1 + 4) = *param_2 + *(float *)(param_1 + 4);
  *(float *)(param_1 + 8) = *(float *)(param_1 + 8) + param_2[1];
  *(float *)(param_1 + 0xc) = *(float *)(param_1 + 0xc) + param_2[2];
  *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x10) + *param_3;
  *(float *)(param_1 + 0x14) = param_3[1] + *(float *)(param_1 + 0x14);
  *(float *)(param_1 + 0x18) = param_3[2] + *(float *)(param_1 + 0x18);
  (*DAT_1006c208)(param_1);
  param_2 = (float *)0x1;
  iVar9 = DAT_1006c2c4;
  piVar3 = DAT_100640f0;
  if (1 < DAT_1006c168) {
    do {
      iVar8 = iVar9 + 0x3d0;
      if (((((*(int *)(iVar9 + 0x428) != 0) && (iVar1 = *(int *)(iVar9 + 0x4d4), iVar1 != 2)) &&
           (iVar1 != 3)) && (((iVar1 != 0 && (iVar1 != 1)) && (*(int *)(iVar9 + 0x430) != 0)))) &&
         ((*(int *)(iVar9 + 0x638) == param_1 ||
          (((*(float *)(iVar9 + 0x4a4) < local_54[0] && (*(float *)(iVar9 + 0x4a8) < local_54[1]))
           && ((*(float *)(iVar9 + 0x4ac) < local_54[2] &&
               ((((local_54[3] < *(float *)(iVar9 + 0x4b0) &&
                  (local_54[4] < *(float *)(iVar9 + 0x4b4))) &&
                 (local_54[5] < *(float *)(iVar9 + 0x4b8))) &&
                (uVar6 = FUN_10012cc0(iVar8), uVar6 != 0)))))))))) {
        if ((*(int *)(param_1 + 0x104) != 2) &&
           (piVar3 = DAT_100640f0, *(int *)(iVar9 + 0x638) != param_1)) {
joined_r0x10013909:
          while (DAT_1006c100 = iVar8, piVar2 = piVar3 + -8, (int *)0x100640ff < piVar2) {
            *(int *)(*piVar2 + 4) = piVar3[-7];
            *(int *)(*piVar2 + 8) = piVar3[-6];
            *(int *)(*piVar2 + 0xc) = piVar3[-5];
            *(int *)(*piVar2 + 0x10) = piVar3[-4];
            *(int *)(*piVar2 + 0x14) = piVar3[-3];
            *(int *)(*piVar2 + 0x18) = piVar3[-2];
            iVar9 = *(int *)(*piVar2 + 0x54);
            if (iVar9 != 0) {
              lVar10 = __ftol();
              *(short *)(iVar9 + 0x16) = (short)lVar10;
            }
            (*DAT_1006c208)(*piVar2);
            iVar8 = DAT_1006c100;
            piVar3 = piVar2;
          }
          return 0;
        }
        *DAT_100640f0 = iVar8;
        DAT_100640f0[1] = *(int *)(iVar9 + 0x3d4);
        DAT_100640f0[2] = *(int *)(iVar9 + 0x3d8);
        DAT_100640f0[3] = *(int *)(iVar9 + 0x3dc);
        DAT_100640f0[4] = *(int *)(iVar9 + 0x3e0);
        DAT_100640f0[5] = *(int *)(iVar9 + 0x3e4);
        DAT_100640f0[6] = *(int *)(iVar9 + 1000);
        DAT_100640f0 = DAT_100640f0 + 8;
        iVar1 = *(int *)(iVar9 + 0x424);
        *(float *)(iVar9 + 0x3d4) = *(float *)(iVar9 + 0x3d4) + *pfVar4;
        *(float *)(iVar9 + 0x3d8) = *(float *)(iVar9 + 0x3d8) + pfVar4[1];
        *(float *)(iVar9 + 0x3dc) = *(float *)(iVar9 + 0x3dc) + pfVar4[2];
        if (iVar1 != 0) {
          lVar10 = __ftol();
          *(short *)(iVar1 + 0x16) = (short)lVar10;
        }
        local_60 = *(float *)(iVar9 + 0x3d4) - *(float *)(param_1 + 4);
        local_5c = *(float *)(iVar9 + 0x3d8) - *(float *)(param_1 + 8);
        local_58 = *(float *)(iVar9 + 0x3dc) - *(float *)(param_1 + 0xc);
        fStack_14 = -(local_30 * local_60 + fStack_2c * local_5c + fStack_28 * local_58);
        fStack_10 = local_24 * local_60 + fStack_20 * local_5c + fStack_1c * local_58;
        fStack_8 = fStack_14 - local_5c;
        fStack_4 = fStack_10 - local_58;
        *(float *)(iVar9 + 0x3d4) =
             ((local_54[6] * local_60 + fStack_38 * local_5c + fStack_34 * local_58) - local_60) +
             *(float *)(iVar9 + 0x3d4);
        *(float *)(iVar9 + 0x3d8) = fStack_8 + *(float *)(iVar9 + 0x3d8);
        *(float *)(iVar9 + 0x3dc) = fStack_4 + *(float *)(iVar9 + 0x3dc);
        if (*(int *)(iVar9 + 0x638) != param_1) {
          *(undefined4 *)(iVar9 + 0x638) = 0;
        }
        uVar6 = FUN_10012cc0(iVar8);
        if (uVar6 == 0) {
          (*DAT_1006c208)(iVar8);
        }
        else {
          *(float *)(iVar9 + 0x3d4) = *(float *)(iVar9 + 0x3d4) - *pfVar4;
          *(float *)(iVar9 + 0x3d8) = *(float *)(iVar9 + 0x3d8) - pfVar4[1];
          *(float *)(iVar9 + 0x3dc) = *(float *)(iVar9 + 0x3dc) - pfVar4[2];
          uVar6 = FUN_10012cc0(iVar8);
          piVar3 = DAT_100640f0;
          if (uVar6 != 0) goto joined_r0x10013909;
          DAT_100640f0 = DAT_100640f0 + -8;
        }
      }
      param_2 = (float *)((int)param_2 + 1);
      iVar9 = iVar8;
      piVar3 = DAT_100640f0;
    } while ((int)param_2 < DAT_1006c168);
  }
  while ((int *)0x100640ff < piVar3 + -8) {
    FUN_1001b480();
    piVar3 = piVar3 + -8;
  }
  return 1;
}



/* FUN_10031070 @ 10031070 size 1278 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10031070(int param_1)

{
  undefined4 *puVar1;
  bool bVar2;
  float fVar3;
  byte *pbVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  void *this;
  undefined4 *puVar8;
  undefined4 *puVar9;
  longlong lVar10;
  ulonglong uVar11;
  int local_f24;
  undefined4 local_f18;
  undefined4 local_f14;
  float local_f10;
  undefined4 local_f0c;
  undefined4 uStack_f08;
  byte local_f00 [512];
  undefined4 local_d00 [410];
  undefined4 local_698;
  undefined4 local_694;
  int local_688;
  undefined4 local_674 [413];
  
  FUN_10030970(param_1,&local_f18,&local_f0c);
  iVar6 = param_1 - DAT_1006c2c4;
  puVar1 = *(undefined4 **)(param_1 + 0x54);
  if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
    if (*(float *)(DAT_1006c42c + 0x14) == _DAT_1004410c) {
      puVar9 = local_d00;
      for (iVar7 = 0x1a3; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
    }
    else {
      uVar5 = puVar1[0x1c9];
      puVar9 = puVar1 + 0x1cc;
      puVar8 = local_d00;
      for (iVar7 = 0x1a3; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar8 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar8 = puVar8 + 1;
      }
      puVar9 = puVar1 + 0x2f;
      pbVar4 = local_f00;
      for (iVar7 = 0x80; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(undefined4 *)pbVar4 = *puVar9;
        puVar9 = puVar9 + 1;
        pbVar4 = pbVar4 + 4;
      }
      local_698 = uVar5;
      local_694 = puVar1[0x1ca];
      puVar9 = local_d00;
      puVar8 = puVar1 + 0x2f;
      for (iVar7 = 0x19d; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar8 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar8 = puVar8 + 1;
      }
      FUN_10031760(param_1,local_f00);
      if ((int)puVar1[0x1c8] < local_688) {
        puVar1[0x1c8] = local_688;
      }
    }
  }
  else {
    puVar9 = puVar1 + 0x1cc;
    puVar8 = local_d00;
    for (iVar7 = 0x1a3; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar8 = puVar8 + 1;
    }
    puVar9 = puVar1 + 0x2f;
    pbVar4 = local_f00;
    for (iVar7 = 0x80; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined4 *)pbVar4 = *puVar9;
      puVar9 = puVar9 + 1;
      pbVar4 = pbVar4 + 4;
    }
    FUN_10030460((int)puVar1);
    FUN_10031760(param_1,local_f00);
  }
  puVar9 = puVar1 + 0x2f;
  puVar8 = local_674;
  for (iVar7 = 0x19d; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar8 = puVar8 + 1;
  }
  puVar9 = puVar1;
  for (iVar7 = 0x3cd; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  puVar9 = local_674;
  puVar8 = puVar1 + 0x2f;
  for (iVar7 = 0x19d; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar8 = puVar8 + 1;
  }
  if ((int)puVar1[0xb5] < 1) {
    FUN_10030460((int)puVar1);
  }
  puVar9 = local_d00;
  puVar8 = puVar1 + 0x1cc;
  for (iVar7 = 0x1a3; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar8 = puVar8 + 1;
  }
  FUN_10030650(param_1);
  *(undefined4 *)(param_1 + 0x268) = 0;
  *(int *)(param_1 + 0x54) = DAT_1006c844 + (iVar6 / 0x3d0 + -1) * 0xf34;
  *(undefined4 *)(param_1 + 0x240) = 2;
  *(undefined4 *)(param_1 + 0x104) = 4;
  *(undefined4 *)(param_1 + 0x23c) = 0x16;
  *(undefined4 *)(param_1 + 0x58) = 1;
  *(char **)(param_1 + 0x118) = s_player_10046030;
  *(undefined4 *)(param_1 + 400) = 200;
  *(undefined4 *)(param_1 + 0xf8) = 2;
  *(undefined4 *)(param_1 + 0x22c) = 0;
  fVar3 = DAT_1006c2e4 + _DAT_10044244;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffd;
  *(undefined4 *)(param_1 + 0xbc) = 0xc1800000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc1800000;
  *(float *)(param_1 + 0x194) = fVar3;
  *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) & 0xfffff7ff;
  *(undefined4 *)(param_1 + 200) = 0x41800000;
  *(undefined4 *)(param_1 + 0xcc) = 0x41800000;
  *(undefined4 *)(param_1 + 0xfc) = 0x2010003;
  *(char **)(param_1 + 0x10c) = s_players_male_tris_md2_1005f3cc;
  *(undefined1 **)(param_1 + 0x204) = &LAB_10002c90;
  *(code **)(param_1 + 0x208) = FUN_10030160;
  *(undefined4 *)(param_1 + 0x2a8) = 0;
  *(undefined4 *)(param_1 + 0x2a4) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0xc1c00000;
  *(undefined4 *)(param_1 + 0xd0) = 0x42000000;
  *(undefined4 *)(param_1 + 0x180) = 0;
  *(undefined4 *)(param_1 + 0x17c) = 0;
  *(undefined4 *)(param_1 + 0x178) = 0;
  puVar9 = *(undefined4 **)(param_1 + 0x54);
  for (iVar6 = 0x2e; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  lVar10 = __ftol();
  *(short *)(puVar1 + 1) = (short)lVar10;
  lVar10 = __ftol();
  *(short *)((int)puVar1 + 6) = (short)lVar10;
  lVar10 = __ftol();
  *(short *)(puVar1 + 2) = (short)lVar10;
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    uVar11 = __ftol();
    if ((uVar11 & 0x8000) != 0) {
      puVar1[0x1c] = 0x42b40000;
      goto LAB_100313e8;
    }
  }
  pbVar4 = FUN_10038bb0((byte *)(puVar1 + 0x2f),&DAT_1005f3c8);
  iVar6 = FUN_10039237(this,pbVar4);
  bVar2 = _DAT_10044104 <= (float)iVar6;
  puVar1[0x1c] = (float)iVar6;
  if (bVar2) {
    if (_DAT_100443d0 < (float)iVar6) {
      puVar1[0x1c] = 0x43200000;
    }
  }
  else {
    puVar1[0x1c] = 0x42b40000;
  }
LAB_100313e8:
  uVar5 = (*DAT_1006c1e0)(*(undefined4 *)(puVar1[0x1c5] + 0x20));
  puVar1[0x16] = uVar5;
  *(undefined4 *)(param_1 + 0x40) = 0;
  iVar6 = param_1 - DAT_1006c2c4;
  local_f10 = local_f10 + _DAT_10044104;
  *(float *)(param_1 + 0xc) = local_f10;
  *(float *)(param_1 + 0x24) = local_f10;
  *(undefined4 *)(param_1 + 0x38) = 0;
  puVar9 = puVar1 + 5;
  *(int *)(param_1 + 0x3c) = iVar6 / 0x3d0 + -1;
  *(undefined4 *)(param_1 + 0x28) = 0xff;
  *(undefined4 *)(param_1 + 0x2c) = 0xff;
  *(undefined4 *)(param_1 + 4) = local_f18;
  *(undefined4 *)(param_1 + 8) = local_f14;
  *(undefined4 *)(param_1 + 0x1c) = local_f18;
  *(undefined4 *)(param_1 + 0x20) = local_f14;
  local_f24 = 3;
  do {
    lVar10 = __ftol();
    *(short *)puVar9 = (short)lVar10;
    puVar9 = (undefined4 *)((int)puVar9 + 2);
    local_f24 = local_f24 + -1;
  } while (local_f24 != 0);
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = uStack_f08;
  *(undefined4 *)(param_1 + 0x18) = 0;
  puVar1[7] = 0;
  puVar1[8] = *(undefined4 *)(param_1 + 0x14);
  puVar1[9] = *(undefined4 *)(param_1 + 0x18);
  puVar1[0x399] = *(undefined4 *)(param_1 + 0x10);
  puVar1[0x39a] = *(undefined4 *)(param_1 + 0x14);
  puVar1[0x39b] = *(undefined4 *)(param_1 + 0x18);
  if (puVar1[0x1cb] != 0) {
    puVar1[0x3c1] = 0;
    puVar1[0x36e] = 1;
    *(undefined4 *)(param_1 + 0x104) = 1;
    *(undefined4 *)(param_1 + 0xf8) = 0;
    *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x58) = 0;
    (*DAT_1006c208)(param_1);
    return;
  }
  puVar1[0x36e] = 0;
  FUN_1001b510(param_1);
  (*DAT_1006c208)(param_1);
  puVar1[0x37f] = puVar1[0x1c5];
  FUN_10035420(param_1);
  return;
}



/* FUN_100060d0 @ 100060d0 size 1239 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_100060d0(uint param_1,undefined4 param_2,uint param_3,float *param_4,float *param_5,
            undefined4 param_6,int param_7,int param_8,uint param_9,uint param_10)

{
  int iVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ulonglong uVar10;
  longlong lVar11;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(int *)(param_1 + 0x240) != 0) {
    if (((param_1 != param_3) &&
        (((*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c &&
          (uVar10 = __ftol(), (uVar10 & 0xc0) != 0)) ||
         (*(float *)(DAT_1006c42c + 0x14) != _DAT_1004410c)))) &&
       (uVar10 = FUN_10003d00(param_1,param_3), (int)uVar10 != 0)) {
      uVar10 = __ftol();
      if ((uVar10 & 0x100) == 0) {
        param_10 = param_10 | 0x8000000;
      }
      else {
        param_7 = 0;
      }
    }
    DAT_1006c104 = param_10;
    if (((*(float *)(DAT_1006c41c + 0x14) == _DAT_1004410c) &&
        (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c)) && (*(int *)(param_1 + 0x54) != 0)) {
      lVar11 = __ftol();
      param_7 = (int)lVar11;
      if (param_7 == 0) {
        param_7 = 1;
      }
    }
    iVar1 = *(int *)(param_1 + 0x54);
    iVar8 = (-(uint)((param_9 & 0x10) != 0) & 5) + 9;
    FUN_10038900(param_4);
    if ((((param_9 & 1) == 0) && ((*(byte *)(param_1 + 0xb8) & 4) != 0)) &&
       ((*(int *)(param_3 + 0x54) != 0 &&
        ((*(int *)(param_1 + 0x25c) == 0 && (0 < *(int *)(param_1 + 0x220))))))) {
      param_7 = param_7 * 2;
    }
    if ((*(uint *)(param_1 + 0x108) & 0x800) != 0) {
      param_8 = 0;
    }
    if ((((((param_9 & 8) == 0) && (param_8 != 0)) &&
         (iVar9 = *(int *)(param_1 + 0x104), iVar9 != 0)) && ((iVar9 != 9 && (iVar9 != 2)))) &&
       (iVar9 != 3)) {
      fVar2 = _DAT_10044190;
      if (0x31 < *(int *)(param_1 + 400)) {
        fVar2 = (float)*(int *)(param_1 + 400);
      }
      if ((*(int *)(param_1 + 0x54) == 0) || (param_3 != param_1)) {
        fVar3 = (float)param_8 * (float)_DAT_10044180;
      }
      else {
        fVar3 = (float)param_8 * (float)_DAT_10044188;
      }
      FUN_10038a20(param_4,fVar3 / fVar2,&local_c);
      *(float *)(param_1 + 0x178) = local_c + *(float *)(param_1 + 0x178);
      *(float *)(param_1 + 0x17c) = local_8 + *(float *)(param_1 + 0x17c);
      *(float *)(param_1 + 0x180) = local_4 + *(float *)(param_1 + 0x180);
    }
    param_10 = 0;
    iVar9 = param_7;
    if (((*(byte *)(param_1 + 0x108) & 0x10) != 0) && ((param_9 & 0x20) == 0)) {
      iVar9 = 0;
      param_10 = param_7;
      FUN_10005df0(iVar8,param_5,param_6);
    }
    if (((iVar1 != 0) && ((float)DAT_1006c2e0 < *(float *)(iVar1 + 0xeb0))) &&
       ((param_9 & 0x20) == 0)) {
      if (*(float *)(param_1 + 0x210) < DAT_1006c2e4) {
        uVar4 = (*DAT_1006c1e4)(s_items_protect4_wav_10046618,0x3f800000,0x3f800000,0);
        (*DAT_1006c1d0)(param_1,3,uVar4);
        *(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_1004413c;
      }
      iVar9 = 0;
      param_10 = param_7;
    }
    iVar5 = FUN_100065b0(param_1,param_5,param_6,iVar9,param_9);
    iVar6 = FUN_10006790(param_1,param_5,param_6,iVar9 - iVar5,iVar8,(byte)param_9);
    iVar9 = (iVar9 - iVar5) - iVar6;
    if (((param_9 & 0x20) != 0) || (iVar7 = FUN_100060c0(), iVar7 == 0)) {
      if (iVar9 != 0) {
        if (((*(byte *)(param_1 + 0xb8) & 4) != 0) || (iVar1 != 0)) {
          iVar8 = 1;
        }
        FUN_10005df0(iVar8,param_5,param_6);
        iVar8 = *(int *)(param_1 + 0x220) - iVar9;
        *(int *)(param_1 + 0x220) = iVar8;
        if (iVar8 < 1) {
          if (((*(byte *)(param_1 + 0xb8) & 4) != 0) || (iVar1 != 0)) {
            *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) | 0x800;
          }
          FUN_10005ce0(param_1,param_2,param_3,iVar9,param_5);
          return;
        }
      }
      if ((*(byte *)(param_1 + 0xb8) & 4) == 0) {
        if (iVar1 == 0) {
          if (iVar9 == 0) {
            return;
          }
          if (*(code **)(param_1 + 0x204) == (code *)0x0) {
            return;
          }
          (**(code **)(param_1 + 0x204))(param_1,param_3,(float)param_8,iVar9);
          return;
        }
        if (((*(byte *)(param_1 + 0x108) & 0x10) == 0) && (iVar9 != 0)) {
          (**(code **)(param_1 + 0x204))(param_1,param_3,(float)param_8,iVar9);
        }
      }
      else {
        FUN_10005e30(param_1,param_3);
        if ((((*(uint *)(param_1 + 0x35c) & 0x800) == 0) && (iVar9 != 0)) &&
           ((**(code **)(param_1 + 0x204))(param_1,param_3,(float)param_8,iVar9),
           *(int *)(DAT_1006c41c + 0x14) == 0x40400000)) {
          *(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_1004414c;
        }
      }
      if (iVar1 != 0) {
        *(int *)(iVar1 + 0xe08) = *(int *)(iVar1 + 0xe08) + iVar9;
        *(int *)(iVar1 + 0xe04) = *(int *)(iVar1 + 0xe04) + iVar5;
        *(uint *)(iVar1 + 0xe00) = *(int *)(iVar1 + 0xe00) + iVar6 + param_10;
        *(int *)(iVar1 + 0xe0c) = *(int *)(iVar1 + 0xe0c) + param_8;
        *(float *)(iVar1 + 0xe10) = *param_5;
        *(float *)(iVar1 + 0xe14) = param_5[1];
        *(float *)(iVar1 + 0xe18) = param_5[2];
      }
    }
  }
  return;
}



/* FUN_10016ef0 @ 10016ef0 size 1232 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10016ef0(int param_1)

{
  char cVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  longlong lVar8;
  undefined *puVar9;
  char *pcVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  
  *(undefined4 *)(param_1 + 0x104) = 2;
  *(undefined4 *)(param_1 + 0xf8) = 3;
  *(undefined4 *)(param_1 + 0x58) = 1;
  *(undefined4 *)(param_1 + 0x28) = 1;
  FUN_10030a90();
  FUN_1000d350();
  if (DAT_1006c294 != (char *)0x0) {
    uVar5 = 0xffffffff;
    pcVar10 = DAT_1006c294;
    do {
      pcVar7 = pcVar10;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar7 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar7;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar10 = pcVar7 + -uVar5;
    pcVar7 = (char *)&DAT_1006c368;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar7 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar7 = pcVar7 + 1;
    }
  }
  pcVar10 = *(char **)(param_1 + 0x114);
  if ((pcVar10 == (char *)0x0) || (*pcVar10 == '\0')) {
    _strncpy(&DAT_1006c2e8,&DAT_1006c328,0x40);
  }
  else {
    (*DAT_1006c1d8)(0,pcVar10);
    _strncpy(&DAT_1006c2e8,*(char **)(param_1 + 0x114),0x40);
  }
  if ((DAT_1006c280 == (char *)0x0) || (pcVar10 = DAT_1006c280, *DAT_1006c280 == '\0')) {
    pcVar10 = s_unit1__1004b77c;
  }
  (*DAT_1006c1d8)(2,pcVar10);
  FUN_10038a50(&DAT_1004b3fc);
  (*DAT_1006c1d8)();
  dVar13 = (double)_DAT_1006c290;
  dVar12 = (double)_DAT_1006c28c;
  dVar11 = (double)_DAT_1006c288;
  pcVar10 = s__f__f__f_10046688;
  puVar2 = FUN_10038a50((byte *)s__f__f__f_10046688);
  (*DAT_1006c1d8)(3,puVar2,pcVar10,dVar11,dVar12,dVar13);
  uVar3 = *(undefined4 *)(param_1 + 0x250);
  puVar9 = &DAT_1004b778;
  puVar2 = FUN_10038a50(&DAT_1004b778);
  (*DAT_1006c1d8)(1,puVar2,puVar9,uVar3);
  lVar8 = __ftol();
  uVar3 = (undefined4)lVar8;
  puVar9 = &DAT_1004b778;
  puVar2 = FUN_10038a50(&DAT_1004b778);
  (*DAT_1006c1d8)(0x1e,puVar2,puVar9,uVar3);
  puVar2 = PTR_s_yb__24_xv_0_hnum_xv_50_pic_0_if_2_1004a998;
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    puVar2 = PTR_s_yb__24_xv_0_hnum_xv_50_pic_0_if_2_1004a99c;
  }
  (*DAT_1006c1d8)(5,puVar2);
  (*DAT_1006c1e8)(s_i_help_1004b770);
  _DAT_1006c3e8 = (*DAT_1006c1e8)(s_i_health_100478f4);
  (*DAT_1006c1e8)();
  (*DAT_1006c1e8)(s_field_3_1004b768);
  puVar2 = DAT_1006c2b0;
  if (DAT_1006c2b0 == (undefined *)0x0) {
    puVar2 = &DAT_1004a440;
  }
  (*DAT_1006c254)(s_sv_gravity_1004a434,puVar2);
  DAT_1006c1a0 = (*DAT_1006c1e4)(s_player_fry_wav_1004b758);
  puVar4 = FUN_1000b150((byte *)s_Blaster_10048c1c);
  FUN_1000cd00(puVar4);
  (*DAT_1006c1e4)(s_player_lava1_wav_100496e4);
  (*DAT_1006c1e4)();
  (*DAT_1006c1e4)(s_misc_pc_up_wav_1004b748);
  (*DAT_1006c1e4)();
  (*DAT_1006c1e4)(s_misc_udeath_wav_100493f8);
  (*DAT_1006c1e4)(s_items_respawn1_wav_1004b734);
  (*DAT_1006c1e4)(s__death1_wav_1004b728);
  (*DAT_1006c1e4)(s__death2_wav_1004b71c);
  (*DAT_1006c1e4)(s__death3_wav_1004b710);
  (*DAT_1006c1e4)(s__death4_wav_1004b704);
  (*DAT_1006c1e4)(s__fall1_wav_1004b6f8);
  (*DAT_1006c1e4)(s__fall2_wav_1004b6ec);
  (*DAT_1006c1e4)(s__gurp1_wav_1004b6e0);
  (*DAT_1006c1e4)(s__gurp2_wav_1004b6d4);
  (*DAT_1006c1e4)(s__jump1_wav_1004b6c8);
  (*DAT_1006c1e4)();
  (*DAT_1006c1e4)(s__pain25_2_wav_1004b6a8);
  (*DAT_1006c1e4)();
  (*DAT_1006c1e4)(s__pain50_2_wav_1004b688);
  (*DAT_1006c1e4)();
  (*DAT_1006c1e4)(s__pain75_2_wav_1004b668);
  (*DAT_1006c1e4)(s__pain100_1_wav_1004b658);
  (*DAT_1006c1e4)(s__pain100_2_wav_1004b648);
  (*DAT_1006c1e4)(s_player_gasp1_wav_1004b634);
  (*DAT_1006c1e4)(s_player_gasp2_wav_1004b620);
  (*DAT_1006c1e4)(s_player_watr_in_wav_100496bc);
  (*DAT_1006c1e4)(s_player_watr_out_wav_100496f8);
  (*DAT_1006c1e4)(s_player_watr_un_wav_1004b60c);
  (*DAT_1006c1e4)(s_player_u_breath1_wav_1004b5f4);
  (*DAT_1006c1e4)(s_player_u_breath2_wav_1004b5dc);
  (*DAT_1006c1e4)(s_items_pkup_wav_10047ec8);
  (*DAT_1006c1e4)();
  (*DAT_1006c1e4)(s_misc_h2ohit1_wav_10049844);
  (*DAT_1006c1e4)();
  (*DAT_1006c1e4)(s_items_protect_wav_10048f3c);
  (*DAT_1006c1e4)();
  (*DAT_1006c1e4)(s_weapons_noammo_wav_1004b5c8);
  (*DAT_1006c1e4)(s_infantry_inflies1_wav_100496a4);
  DAT_1006c418 = (*DAT_1006c1e0)(s_models_objects_gibs_sm_meat_tris_100493d0);
  (*DAT_1006c1e0)(s_models_objects_gibs_arm_tris_md2_10049564);
  (*DAT_1006c1e0)(s_models_objects_gibs_bone_tris_md_1004b5a4);
  (*DAT_1006c1e0)(s_models_objects_gibs_bone2_tris_m_1004b580);
  (*DAT_1006c1e0)(s_models_objects_gibs_chest_tris_m_1004b55c);
  (*DAT_1006c1e0)(s_models_objects_gibs_skull_tris_m_100491b0);
  (*DAT_1006c1e0)(s_models_objects_gibs_head2_tris_m_100491d4);
  (*DAT_1006c1d8)(800,&DAT_10049280);
  (*DAT_1006c1d8)(0x321,s_mmnmmommommnonmmonqnmmo_1004b544);
  (*DAT_1006c1d8)(0x322,s_abcdefghijklmnopqrstuvwxyzyxwvut_1004b510);
  (*DAT_1006c1d8)(0x323,s_mmmmmaaaaammmmmaaaaaabcdefgabcde_1004b4ec);
  (*DAT_1006c1d8)(0x324,s_mamamamamama_1004b4dc);
  (*DAT_1006c1d8)(0x325,s_jklmnopqrstuvwxyzyxwvutsrqponmlk_1004b4b8);
  (*DAT_1006c1d8)(0x326,s_nmonqnmomnmomomno_1004b4a4);
  (*DAT_1006c1d8)(0x327,s_mmmaaaabcdefgmmmmaaaammmaamm_1004b484);
  (*DAT_1006c1d8)(0x328,s_mmmaaammmaaammmabcdefaaaammmmabc_1004b458);
  (*DAT_1006c1d8)(0x329,s_aaaaaaaazzzzzzzz_1004b444);
  (*DAT_1006c1d8)(0x32a,s_mmamammmmammamamaaamammma_1004b428);
  (*DAT_1006c1d8)(0x32b,s_abcdefghijklmnopqrrqponmlkjihgfe_1004b400);
  (*DAT_1006c1d8)(0x35f,&DAT_10049284);
  return;
}



/* FUN_10041425 @ 10041425 size 1185 */

undefined4 __thiscall
FUN_10041425(void *this,ushort *param_1,int *param_2,byte *param_3,int param_4,int param_5,
            int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  byte bVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  byte *pbVar10;
  char local_60 [23];
  char local_49;
  ushort local_44;
  undefined2 uStack_42;
  undefined2 uStack_40;
  byte *local_3e;
  ushort local_3a;
  int local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  byte *local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  char *local_10;
  int local_c;
  uint local_8;
  
  local_10 = local_60;
  local_2c = 0;
  local_1c = 1;
  local_8 = 0;
  local_14 = 0;
  local_28 = 0;
  local_24 = 0;
  local_30 = 0;
  local_34 = 0;
  local_20 = (byte *)0x0;
  local_c = 0;
  local_18 = 0;
  pbVar8 = param_3;
  while( true ) {
    bVar6 = *pbVar8;
    this = (void *)CONCAT31((int3)((uint)this >> 8),bVar6);
    if ((((bVar6 != 0x20) && (bVar6 != 9)) && (bVar6 != 10)) && (bVar6 != 0xd)) break;
    pbVar8 = pbVar8 + 1;
  }
  iVar1 = 4;
  iVar9 = 0;
  iVar5 = local_14;
LAB_1004147c:
  local_14 = iVar5;
  pbVar7 = pbVar8;
  iVar5 = 1;
  bVar6 = *pbVar7;
  pbVar8 = pbVar7 + 1;
  iVar2 = local_14;
  switch(iVar9) {
  case 0:
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) {
LAB_10041499:
      local_14 = iVar2;
      iVar9 = 3;
      goto LAB_100416be;
    }
    if (bVar6 == DAT_1005fed8) goto LAB_100414a8;
    if (bVar6 == 0x2b) {
      local_2c = 0;
      iVar9 = 2;
      iVar5 = local_14;
    }
    else if (bVar6 == 0x2d) {
      local_2c = 0x8000;
      iVar9 = 2;
      iVar5 = local_14;
    }
    else {
      iVar9 = iVar5;
      iVar5 = local_14;
      if (bVar6 != 0x30) goto LAB_10041798;
    }
    goto LAB_1004147c;
  case 1:
    local_14 = 1;
    if (('0' < (char)bVar6) && (iVar2 = iVar5, (char)bVar6 < ':')) goto LAB_10041499;
    iVar9 = iVar1;
    if (bVar6 != DAT_1005fed8) {
      iVar9 = iVar5;
      if ((bVar6 == 0x2b) || (iVar9 = local_14, bVar6 == 0x2d)) goto LAB_1004152d;
      iVar9 = iVar5;
      local_14 = iVar5;
      if (bVar6 != 0x30) goto LAB_10041506;
    }
    goto LAB_1004147c;
  case 2:
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) goto LAB_10041499;
    if (bVar6 == DAT_1005fed8) {
LAB_100414a8:
      iVar9 = 5;
      iVar5 = local_14;
    }
    else {
      iVar9 = iVar5;
      pbVar7 = param_3;
      iVar5 = local_14;
      if (bVar6 != 0x30) goto LAB_1004179d;
    }
    goto LAB_1004147c;
  case 3:
    local_14 = iVar5;
    while( true ) {
      if (DAT_1005fed4 < 2) {
        uVar3 = (byte)PTR_DAT_1005fcc8[(uint)bVar6 * 2] & 4;
        this = PTR_DAT_1005fcc8;
      }
      else {
        pbVar7 = (byte *)0x4;
        uVar3 = FUN_1003b258(this,(uint)bVar6,4);
        this = pbVar7;
      }
      if (uVar3 == 0) break;
      if (local_8 < 0x19) {
        local_8 = local_8 + 1;
        pcVar4 = local_10 + 1;
        *local_10 = bVar6 - 0x30;
        local_10 = pcVar4;
      }
      else {
        local_c = local_c + 1;
      }
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    }
    iVar9 = iVar1;
    iVar5 = local_14;
    if (bVar6 != DAT_1005fed8) goto LAB_1004161a;
    goto LAB_1004147c;
  case 4:
    local_14 = 1;
    local_28 = 1;
    iVar9 = iVar5;
    if (local_8 == 0) {
      while (iVar5 = local_28, iVar9 = local_14, bVar6 == 0x30) {
        local_c = local_c + -1;
        bVar6 = *pbVar8;
        pbVar8 = pbVar8 + 1;
      }
    }
    while( true ) {
      local_14 = iVar9;
      local_28 = iVar5;
      if (DAT_1005fed4 < 2) {
        uVar3 = (byte)PTR_DAT_1005fcc8[(uint)bVar6 * 2] & 4;
        this = PTR_DAT_1005fcc8;
      }
      else {
        pbVar7 = (byte *)0x4;
        uVar3 = FUN_1003b258(this,(uint)bVar6,4);
        this = pbVar7;
      }
      if (uVar3 == 0) break;
      if (local_8 < 0x19) {
        local_8 = local_8 + 1;
        local_c = local_c + -1;
        pcVar4 = local_10 + 1;
        *local_10 = bVar6 - 0x30;
        local_10 = pcVar4;
      }
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
      iVar5 = local_28;
      iVar9 = local_14;
    }
LAB_1004161a:
    iVar9 = local_14;
    if ((bVar6 == 0x2b) || (bVar6 == 0x2d)) {
LAB_1004152d:
      local_14 = iVar9;
      iVar9 = 0xb;
      pbVar8 = pbVar8 + -1;
      iVar5 = local_14;
    }
    else {
LAB_10041506:
      if (((char)bVar6 < 'D') ||
         (('E' < (char)bVar6 && (((char)bVar6 < 'd' || ('e' < (char)bVar6)))))) goto LAB_10041798;
      iVar9 = 6;
      iVar5 = local_14;
    }
    goto LAB_1004147c;
  case 5:
    local_28 = iVar5;
    if (DAT_1005fed4 < 2) {
      uVar3 = (byte)PTR_DAT_1005fcc8[(uint)bVar6 * 2] & 4;
      this = PTR_DAT_1005fcc8;
    }
    else {
      pbVar7 = (byte *)0x4;
      uVar3 = FUN_1003b258(this,(uint)bVar6,4);
      this = pbVar7;
    }
    iVar9 = iVar1;
    pbVar7 = param_3;
    if (uVar3 != 0) goto LAB_100416be;
    goto LAB_1004179d;
  case 6:
    pbVar7 = pbVar7 + -1;
    this = pbVar7;
    param_3 = pbVar7;
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) {
      if (bVar6 == 0x2b) goto LAB_100416f3;
      if (bVar6 == 0x2d) goto LAB_100416e7;
      if (bVar6 != 0x30) goto LAB_1004179d;
LAB_1004168c:
      iVar9 = 8;
      iVar5 = local_14;
      goto LAB_1004147c;
    }
    break;
  case 7:
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) {
      pbVar7 = param_3;
      if (bVar6 == 0x30) goto LAB_1004168c;
      goto LAB_1004179d;
    }
    break;
  case 8:
    local_24 = 1;
    while (bVar6 == 0x30) {
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    }
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) goto LAB_10041798;
    break;
  case 9:
    local_24 = 1;
    pbVar7 = (byte *)0x0;
    goto LAB_1004171e;
  default:
    goto switchD_10041488_caseD_a;
  case 0xb:
    if (param_7 != 0) {
      if (bVar6 == 0x2b) {
LAB_100416f3:
        iVar9 = 7;
        this = pbVar7;
        param_3 = pbVar7;
        iVar5 = local_14;
      }
      else {
        param_3 = pbVar7;
        if (bVar6 != 0x2d) goto LAB_1004179d;
LAB_100416e7:
        local_1c = -1;
        iVar9 = 7;
        this = pbVar7;
        param_3 = pbVar7;
        iVar5 = local_14;
      }
      goto LAB_1004147c;
    }
    iVar9 = 10;
    pbVar8 = pbVar7;
switchD_10041488_caseD_a:
    pbVar7 = pbVar8;
    iVar5 = local_14;
    if (iVar9 != 10) goto LAB_1004147c;
    goto LAB_1004179d;
  }
  iVar9 = 9;
LAB_100416be:
  pbVar8 = pbVar8 + -1;
  iVar5 = local_14;
  goto LAB_1004147c;
LAB_1004171e:
  if (DAT_1005fed4 < 2) {
    uVar3 = (byte)PTR_DAT_1005fcc8[(uint)bVar6 * 2] & 4;
    this = PTR_DAT_1005fcc8;
  }
  else {
    pbVar10 = (byte *)0x4;
    uVar3 = FUN_1003b258(this,(uint)bVar6,4);
    this = pbVar10;
  }
  if (uVar3 == 0) goto LAB_10041768;
  this = (void *)(int)(char)bVar6;
  pbVar7 = (byte *)((int)this + (int)pbVar7 * 10 + -0x30);
  if (0x1450 < (int)pbVar7) goto LAB_10041760;
  bVar6 = *pbVar8;
  pbVar8 = pbVar8 + 1;
  goto LAB_1004171e;
LAB_10041760:
  pbVar7 = (byte *)0x1451;
LAB_10041768:
  while( true ) {
    local_20 = pbVar7;
    if (DAT_1005fed4 < 2) {
      uVar3 = (byte)PTR_DAT_1005fcc8[(uint)bVar6 * 2] & 4;
      this = PTR_DAT_1005fcc8;
    }
    else {
      pbVar7 = (byte *)0x4;
      uVar3 = FUN_1003b258(this,(uint)bVar6,4);
      this = pbVar7;
    }
    if (uVar3 == 0) break;
    bVar6 = *pbVar8;
    pbVar8 = pbVar8 + 1;
    pbVar7 = local_20;
  }
LAB_10041798:
  pbVar7 = pbVar8 + -1;
LAB_1004179d:
  *param_2 = (int)pbVar7;
  if (local_14 == 0) {
    local_44 = 0;
    local_3a = 0;
    local_3e = (byte *)0x0;
    param_3 = (byte *)0x0;
    local_18 = 4;
    goto LAB_100418ab;
  }
  pcVar4 = local_10;
  if (0x18 < local_8) {
    if ('\x04' < local_49) {
      local_49 = local_49 + '\x01';
    }
    local_8 = 0x18;
    local_c = local_c + 1;
    pcVar4 = local_10 + -1;
  }
  if (local_8 == 0) {
    local_44 = 0;
    local_3a = 0;
    local_3e = (byte *)0x0;
    param_3 = (byte *)0x0;
  }
  else {
    while (pcVar4 = pcVar4 + -1, *pcVar4 == '\0') {
      local_8 = local_8 - 1;
      local_c = local_c + 1;
    }
    FUN_100421c5(local_60,local_8,(uint *)&local_44);
    pbVar8 = local_20;
    if (local_1c < 0) {
      pbVar8 = (byte *)-(int)local_20;
    }
    pbVar8 = pbVar8 + local_c;
    if (local_24 == 0) {
      pbVar8 = pbVar8 + param_5;
    }
    if (local_28 == 0) {
      pbVar8 = pbVar8 + -param_6;
    }
    if ((int)pbVar8 < 0x1451) {
      if (-0x1451 < (int)pbVar8) {
        FUN_10042afe((int *)&local_44,(uint)pbVar8,param_4);
        param_3 = (byte *)CONCAT22(uStack_40,uStack_42);
        goto LAB_10041830;
      }
      local_34 = 1;
    }
    else {
      local_30 = 1;
    }
    local_3a = (ushort)param_3;
    local_3e = param_3;
    local_44 = local_3a;
  }
LAB_10041830:
  if (local_30 == 0) {
    if (local_34 != 0) {
      local_44 = 0;
      local_3a = 0;
      local_3e = (byte *)0x0;
      param_3 = (byte *)0x0;
      local_18 = 1;
    }
  }
  else {
    param_3 = (byte *)0x0;
    local_3a = 0x7fff;
    local_3e = (byte *)0x80000000;
    local_44 = 0;
    local_18 = 2;
  }
LAB_100418ab:
  *(byte **)(param_1 + 3) = local_3e;
  *(byte **)(param_1 + 1) = param_3;
  param_1[5] = local_3a | (ushort)local_2c;
  *param_1 = local_44;
  return local_18;
}



/* FUN_10032ca0 @ 10032ca0 size 1142 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10032ca0(int param_1)

{
  float fVar1;
  bool bVar2;
  undefined2 uVar3;
  undefined3 extraout_var;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  longlong lVar9;
  char *pcVar10;
  
  *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x78) = DAT_1006c3e8;
  *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x7a) = *(undefined2 *)(param_1 + 0x220);
  iVar7 = *(int *)(*(int *)(param_1 + 0x54) + 0xde8);
  if (iVar7 == 0) {
    *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x7c) = 0;
    *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x7e) = 0;
  }
  else {
    uVar3 = (*DAT_1006c1e8)(*(undefined4 *)(&DAT_1004694c + iVar7 * 0x48));
    *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x7c) = uVar3;
    iVar7 = *(int *)(param_1 + 0x54);
    *(undefined2 *)(iVar7 + 0x7e) = *(undefined2 *)(iVar7 + 0x2e4 + *(int *)(iVar7 + 0xde8) * 4);
  }
  bVar2 = FUN_1000c460(param_1);
  iVar8 = CONCAT31(extraout_var,bVar2);
  iVar7 = param_1;
  if (iVar8 != 0) {
    puVar4 = FUN_1000b150((byte *)s_cells_10049004);
    iVar7 = *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar4 + -0x4011a4a) / 0x48) * 4);
    if (iVar7 == 0) {
      *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) & 0xffffefff;
      uVar5 = (*DAT_1006c1e4)(s_misc_power2_wav_1004900c,0x3f800000,0x3f800000,0);
      (*DAT_1006c1d0)(param_1,3,uVar5);
      iVar8 = 0;
    }
  }
  uVar6 = FUN_1000c290(param_1);
  if ((iVar8 == 0) || ((uVar6 != 0 && ((DAT_1006c2e0 & 8) == 0)))) {
    if (uVar6 == 0) {
      *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x80) = 0;
      *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x82) = 0;
    }
    else {
      puVar4 = FUN_1000b0e0(uVar6);
      uVar3 = (*DAT_1006c1e8)(puVar4[9]);
      *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x80) = uVar3;
      *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x82) =
           *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x2e4 + uVar6 * 4);
    }
  }
  else {
    uVar3 = (*DAT_1006c1e8)(s_i_powershield_10048d38);
    *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x80) = uVar3;
    *(short *)(*(int *)(param_1 + 0x54) + 0x82) = (short)iVar7;
  }
  if (*(float *)(*(int *)(param_1 + 0x54) + 0xecc) < DAT_1006c2e4) {
    *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x86) = 0;
    *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x88) = 0;
  }
  fVar1 = (float)(int)DAT_1006c2e0;
  iVar7 = *(int *)(param_1 + 0x54);
  if (*(float *)(iVar7 + 0xeac) <= fVar1) {
    if (*(float *)(iVar7 + 0xeb0) <= fVar1) {
      if (*(float *)(iVar7 + 0xeb8) <= fVar1) {
        if (*(float *)(iVar7 + 0xeb4) <= fVar1) {
          *(undefined2 *)(iVar7 + 0x8a) = 0;
          *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x8c) = 0;
        }
        else {
          uVar3 = (*DAT_1006c1e8)(s_p_rebreather_10047d40);
          *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x8a) = uVar3;
          iVar7 = *(int *)(param_1 + 0x54);
          lVar9 = __ftol();
          *(short *)(iVar7 + 0x8c) = (short)lVar9;
        }
      }
      else {
        uVar3 = (*DAT_1006c1e8)(s_p_envirosuit_10047ce4);
        *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x8a) = uVar3;
        iVar7 = *(int *)(param_1 + 0x54);
        lVar9 = __ftol();
        *(short *)(iVar7 + 0x8c) = (short)lVar9;
      }
    }
    else {
      uVar3 = (*DAT_1006c1e8)(s_p_invulnerability_10047e10);
      *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x8a) = uVar3;
      iVar7 = *(int *)(param_1 + 0x54);
      lVar9 = __ftol();
      *(short *)(iVar7 + 0x8c) = (short)lVar9;
    }
  }
  else {
    uVar3 = (*DAT_1006c1e8)(s_p_quad_10047ea0);
    *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x8a) = uVar3;
    iVar7 = *(int *)(param_1 + 0x54);
    lVar9 = __ftol();
    *(short *)(iVar7 + 0x8c) = (short)lVar9;
  }
  iVar7 = *(int *)(*(int *)(param_1 + 0x54) + 0x2e0);
  if (iVar7 == -1) {
    *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x84) = 0;
  }
  else {
    uVar3 = (*DAT_1006c1e8)(*(undefined4 *)(&DAT_1004694c + iVar7 * 0x48));
    *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x84) = uVar3;
  }
  *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x90) =
       *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x2e0);
  *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x92) = 0;
  if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
    iVar7 = *(int *)(param_1 + 0x54);
    if ((*(int *)(iVar7 + 0xdd8) != 0) || (*(int *)(iVar7 + 0xde0) != 0)) {
      *(byte *)(iVar7 + 0x92) = *(byte *)(iVar7 + 0x92) | 1;
    }
    iVar7 = *(int *)(param_1 + 0x54);
    if (*(int *)(iVar7 + 0xddc) == 0) goto LAB_1003308e;
    iVar8 = *(int *)(iVar7 + 0x2d4);
  }
  else {
    iVar7 = *(int *)(param_1 + 0x54);
    if (((*(int *)(iVar7 + 0x2d4) < 1) || (_DAT_1006c3a8 != _DAT_1004410c)) ||
       (*(int *)(iVar7 + 0xdd8) != 0)) {
      *(byte *)(iVar7 + 0x92) = *(byte *)(iVar7 + 0x92) | 1;
    }
    iVar7 = *(int *)(param_1 + 0x54);
    if (*(int *)(iVar7 + 0xddc) == 0) goto LAB_1003308e;
    iVar8 = *(int *)(iVar7 + 0x2d4);
  }
  if (0 < iVar8) {
    *(ushort *)(iVar7 + 0x92) = *(ushort *)(iVar7 + 0x92) | 2;
  }
LAB_1003308e:
  *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x94) =
       *(undefined2 *)(*(int *)(param_1 + 0x54) + 0xda8);
  iVar7 = *(int *)(param_1 + 0x54);
  if ((*(int *)(iVar7 + 0x728) == 0) || ((DAT_1006c2e0 & 8) == 0)) {
    if (((*(int *)(iVar7 + 0x2cc) != 2) && (*(float *)(iVar7 + 0x70) <= _DAT_100443e4)) ||
       (*(int *)(iVar7 + 0x714) == 0)) {
      *(undefined2 *)(iVar7 + 0x8e) = 0;
      *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x9a) = 0;
      return;
    }
    pcVar10 = *(char **)(*(int *)(iVar7 + 0x714) + 0x24);
  }
  else {
    pcVar10 = s_i_help_1004b770;
  }
  uVar3 = (*DAT_1006c1e8)(pcVar10);
  *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x8e) = uVar3;
  *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x9a) = 0;
  return;
}



/* FUN_1002f8f0 @ 1002f8f0 size 1130 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1002f8f0(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  
  if ((*(float *)(DAT_1006c42c + 0x14) != _DAT_1004410c) && (*(int *)(param_3 + 0x54) != 0)) {
    DAT_1006c104 = DAT_1006c104 | 0x8000000;
  }
  if ((*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) ||
     (*(float *)(DAT_1006c42c + 0x14) != _DAT_1004410c)) {
    uVar4 = DAT_1006c104 & 0xf7ffffff;
    uVar5 = DAT_1006c104 & 0x8000000;
    pcVar2 = (char *)0x0;
    pcVar6 = &DAT_10060c60;
    switch(uVar4) {
    case 0x11:
      pcVar2 = s_sank_like_a_rock_1005f284;
      break;
    case 0x12:
      pcVar2 = s_melted_1005f27c;
      break;
    case 0x13:
      pcVar2 = s_does_a_back_flip_into_the_lava_1005f25c;
      break;
    case 0x14:
      pcVar2 = s_was_squished_1005f298;
      break;
    case 0x16:
      pcVar2 = s_cratered_1005f2a8;
      break;
    case 0x17:
      pcVar2 = s_suicides_1005f2b4;
      break;
    case 0x19:
    case 0x1a:
      pcVar2 = s_blew_up_1005f254;
      break;
    case 0x1b:
    case 0x1d:
    case 0x1f:
      pcVar2 = s_was_in_the_wrong_place_1005f204;
      break;
    case 0x1c:
      pcVar2 = s_found_a_way_out_1005f244;
      break;
    case 0x1e:
      if (param_3 == DAT_1006c2c4) {
        pcVar2 = s_saw_the_light_1005f234;
      }
      break;
    case 0x21:
      pcVar2 = s_got_blasted_1005f228;
      break;
    case 0x22:
      pcVar2 = s_got_railed_1005f21c;
    }
    if (param_3 == param_1) {
      switch(uVar4) {
      case 7:
      case 0x10:
        iVar3 = FUN_1002f8b0(param_1);
        if (iVar3 == 0) {
          iVar3 = FUN_1002f870(param_1);
          if (iVar3 == 0) {
            pcVar2 = s_tripped_on_his_own_grenade_1005f190;
          }
          else {
            pcVar2 = s_tripped_on_her_own_grenade_1005f1ac;
          }
        }
        else {
          pcVar2 = s_tripped_on_its_own_grenade_1005f1c8;
        }
        break;
      default:
        iVar3 = FUN_1002f8b0(param_1);
        if (iVar3 == 0) {
          iVar3 = FUN_1002f870(param_1);
          pcVar2 = s_killed_herself_1005f10c;
          if (iVar3 == 0) {
            pcVar2 = s_killed_himself_1005f0fc;
          }
        }
        else {
          pcVar2 = s_killed_itself_1005f11c;
        }
        break;
      case 9:
        iVar3 = FUN_1002f8b0(param_1);
        if (iVar3 == 0) {
          iVar3 = FUN_1002f870(param_1);
          if (iVar3 == 0) {
            pcVar2 = s_blew_himself_up_1005f160;
          }
          else {
            pcVar2 = s_blew_herself_up_1005f170;
          }
        }
        else {
          pcVar2 = s_blew_itself_up_1005f180;
        }
        break;
      case 0xd:
        pcVar2 = s_should_have_used_a_smaller_gun_1005f140;
        break;
      case 0x18:
        pcVar2 = s_tried_to_put_the_pin_back_in_1005f1e4;
        break;
      case 0x1e:
      case 0x2a:
        pcVar2 = s_has_a_short_memory_1005f12c;
      }
    }
    if (pcVar2 != (char *)0x0) {
      (*DAT_1006c1c0)(1,s__s__s__1005f0f4,*(int *)(param_1 + 0x54) + 700,pcVar2);
      if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
        piVar1 = (int *)(*(int *)(param_1 + 0x54) + 0xda8);
        *piVar1 = *piVar1 + -1;
      }
      *(undefined4 *)(param_1 + 0x25c) = 0;
      return;
    }
    *(int *)(param_1 + 0x25c) = param_3;
    if ((param_3 != 0) && (*(int *)(param_3 + 0x54) != 0)) {
      switch(uVar4) {
      case 1:
        pcVar2 = s_was_blasted_by_1005f0e4;
        break;
      case 2:
        pcVar2 = s_was_gunned_down_by_1005f0d0;
        break;
      case 3:
        pcVar2 = s_was_blown_away_by_1005f0bc;
        pcVar6 = s__s_super_shotgun_1005f0a8;
        break;
      case 4:
        pcVar2 = s_was_machinegunned_by_1005f090;
        break;
      case 5:
        pcVar2 = s_was_cut_in_half_by_1005f07c;
        pcVar6 = s__s_chaingun_1005f070;
        break;
      case 6:
        pcVar2 = s_was_popped_by_1005f060;
        pcVar6 = s__s_grenade_1005f054;
        break;
      case 7:
        pcVar2 = s_was_shredded_by_1005f044;
        pcVar6 = s__s_shrapnel_1005f038;
        break;
      case 8:
        pcVar2 = &DAT_1005f034;
        pcVar6 = s__s_rocket_1005f028;
        break;
      case 9:
        pcVar2 = s_almost_dodged_1005f018;
        pcVar6 = s__s_rocket_1005f028;
        break;
      case 10:
        pcVar2 = s_was_melted_by_1005f008;
        pcVar6 = s__s_hyperblaster_1005eff8;
        break;
      case 0xb:
        pcVar2 = s_was_railed_by_1005efe8;
        break;
      case 0xc:
        pcVar2 = s_saw_the_pretty_lights_from_1005efcc;
        pcVar6 = s__s_BFG_1005efc4;
        break;
      case 0xd:
        pcVar2 = s_was_disintegrated_by_1005efac;
        pcVar6 = s__s_BFG_blast_1005ef9c;
        break;
      case 0xe:
        pcVar2 = s_couldn_t_hide_from_1005ef88;
        pcVar6 = s__s_BFG_1005efc4;
        break;
      case 0xf:
        pcVar2 = s_caught_1005ef80;
        pcVar6 = s__s_handgrenade_1005ef70;
        break;
      case 0x10:
        pcVar2 = s_didn_t_see_1005ef64;
        pcVar6 = s__s_handgrenade_1005ef70;
        break;
      default:
        pcVar2 = s_was_killed_by_1005edc4;
        pcVar6 = s_somehow_1005edb8;
        break;
      case 0x15:
        pcVar2 = s_tried_to_invade_1005ef44;
        pcVar6 = s__s_personal_space_1005ef30;
        break;
      case 0x18:
        pcVar2 = s_feels_1005ef5c;
        pcVar6 = s__s_pain_1005ef54;
        break;
      case 0x1e:
      case 0x2a:
        pcVar2 = s_found_that_mine_1005ede4;
        pcVar6 = s_had_misplaced_1005edd4;
        break;
      case 0x23:
        iVar3 = FUN_1002f8b0(param_1);
        if (iVar3 == 0) {
          iVar3 = FUN_1002f870(param_1);
          if (iVar3 == 0) {
            pcVar2 = s_had_his_electrons_unbound_by_1005eed0;
          }
          else {
            pcVar2 = s_had_her_electrons_unbound_by_1005eef0;
          }
        }
        else {
          pcVar2 = s_had_its_electrons_unbound_by_1005ef10;
        }
        break;
      case 0x24:
        pcVar2 = s_was_pistol_whipped_by_1005eeb8;
        break;
      case 0x25:
        pcVar2 = s_was_smeared_by_1005eea8;
        pcVar6 = s__s_hot_sticky_plasma_1005ee90;
        break;
      case 0x26:
        pcVar2 = s_stepped_on_1005ee84;
        pcVar6 = s__s_dog_sh____er___detonation_pac_1005ee60;
        break;
      case 0x27:
        pcVar2 = s_was_sliced_and_diced_by_1005ee48;
        pcVar6 = s__s_obliterator_1005ee38;
        break;
      case 0x28:
        pcVar2 = s_took_a_bite_of_1005ee28;
        pcVar6 = s__s_donut_1005ee1c;
        break;
      case 0x29:
        pcVar2 = s_caught_some_of_1005ee0c;
        pcVar6 = s__s_remote_cannon_lovin__1005edf4;
      }
      if (pcVar2 != (char *)0x0) {
        (*DAT_1006c1c0)(1,s__s__s__s_s_1005edac,*(int *)(param_1 + 0x54) + 700,pcVar2,
                        *(int *)(param_3 + 0x54) + 700,pcVar6);
        if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
          return;
        }
        if (uVar5 == 0) {
          piVar1 = (int *)(*(int *)(param_3 + 0x54) + 0xda8);
          *piVar1 = *piVar1 + 1;
          return;
        }
        piVar1 = (int *)(*(int *)(param_3 + 0x54) + 0xda8);
        *piVar1 = *piVar1 + -1;
        return;
      }
    }
  }
  (*DAT_1006c1c0)(1,s__s_died__1005eda0,*(int *)(param_1 + 0x54) + 700);
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    piVar1 = (int *)(*(int *)(param_1 + 0x54) + 0xda8);
    *piVar1 = *piVar1 + -1;
  }
  return;
}



/* FUN_100333c0 @ 100333c0 size 1110 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100333c0(float param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined *puVar8;
  char *pcVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  float local_14;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  fVar4 = param_1;
  iVar2 = *(int *)((int)param_1 + 0x54);
  *(undefined2 *)(iVar2 + 0x96) = 0;
  if (*(int *)(iVar2 + 0xe08) != 0) {
    *(undefined2 *)(iVar2 + 0x96) = 1;
  }
  if (((*(int *)(iVar2 + 0xe00) != 0) && ((*(byte *)((int)param_1 + 0x108) & 0x10) == 0)) &&
     (*(float *)(iVar2 + 0xeb0) <= (float)DAT_1006c2e0)) {
    *(byte *)(iVar2 + 0x96) = *(byte *)(iVar2 + 0x96) | 2;
  }
  iVar5 = *(int *)(iVar2 + 0xe04) + *(int *)(iVar2 + 0xe00) + *(int *)(iVar2 + 0xe08);
  fVar1 = (float)iVar5;
  if ((float)iVar5 != _DAT_1004410c) {
    if ((*(int *)(iVar2 + 0xea0) < 3) && (*(int *)((int)param_1 + 0x28) == 0xff)) {
      *(undefined4 *)(iVar2 + 0xea0) = 3;
      if ((*(byte *)(iVar2 + 0x10) & 1) == 0) {
        DAT_10061390 = (DAT_10061390 + 1) % 3;
        if (DAT_10061390 == 0) {
          *(undefined4 *)((int)param_1 + 0x38) = 0x35;
          *(undefined4 *)(iVar2 + 0xe9c) = 0x39;
        }
        else if (DAT_10061390 == 1) {
          *(undefined4 *)((int)param_1 + 0x38) = 0x39;
          *(undefined4 *)(iVar2 + 0xe9c) = 0x3d;
        }
        else if (DAT_10061390 == 2) {
          *(undefined4 *)((int)param_1 + 0x38) = 0x3d;
          *(undefined4 *)(iVar2 + 0xe9c) = 0x41;
        }
      }
      else {
        *(undefined4 *)((int)param_1 + 0x38) = 0xa8;
        *(undefined4 *)(iVar2 + 0xe9c) = 0xac;
      }
    }
    local_14 = fVar1;
    if (fVar1 < _DAT_100441b0) {
      local_14 = 10.0;
    }
    if (((*(float *)((int)param_1 + 0x210) < DAT_1006c2e4) &&
        ((*(byte *)((int)param_1 + 0x108) & 0x10) == 0)) &&
       (*(float *)(iVar2 + 0xeb0) <= (float)DAT_1006c2e0)) {
      uVar6 = _rand();
      iVar5 = *(int *)((int)param_1 + 0x220);
      iVar7 = (uVar6 & 1) + 1;
      *(float *)((int)param_1 + 0x210) = DAT_1006c2e4 + (float)_DAT_10044228;
      if (iVar5 < 0x19) {
        iVar5 = 0x19;
      }
      else if (iVar5 < 0x32) {
        iVar5 = 0x32;
      }
      else {
        iVar5 = ((0x4a < iVar5) - 1 & 0xffffffe7) + 100;
      }
      uVar12 = 0;
      uVar11 = 0x3f800000;
      uVar10 = 0x3f800000;
      pcVar9 = s__pain_i__i_wav_1005f664;
      puVar8 = FUN_10038a50((byte *)s__pain_i__i_wav_1005f664);
      uVar10 = (*DAT_1006c1e4)(puVar8,pcVar9,iVar5,iVar7,uVar10,uVar11,uVar12);
      (*DAT_1006c1d0)(param_1,2,uVar10);
    }
    if (*(float *)(iVar2 + 0xe50) < _DAT_1004410c) {
      *(undefined4 *)(iVar2 + 0xe50) = 0;
    }
    fVar3 = local_14 * (float)_DAT_100443f0 + *(float *)(iVar2 + 0xe50);
    *(float *)(iVar2 + 0xe50) = fVar3;
    if (fVar3 < (float)_DAT_10044198) {
      *(undefined4 *)(iVar2 + 0xe50) = 0x3e4ccccd;
    }
    if ((float)_DAT_10044330 < *(float *)(iVar2 + 0xe50)) {
      *(undefined4 *)(iVar2 + 0xe50) = 0x3f19999a;
    }
    fStack_4 = 0.0;
    fStack_8 = 0.0;
    fStack_c = 0.0;
    if (*(int *)(iVar2 + 0xe04) != 0) {
      FUN_10038950(&fStack_c,(float)*(int *)(iVar2 + 0xe04) / fVar1,(float *)&DAT_1005f640,&fStack_c
                  );
    }
    if (*(int *)(iVar2 + 0xe00) != 0) {
      FUN_10038950(&fStack_c,(float)*(int *)(iVar2 + 0xe00) / fVar1,(float *)&DAT_1005f64c,&fStack_c
                  );
    }
    if (*(int *)(iVar2 + 0xe08) != 0) {
      FUN_10038950(&fStack_c,(float)*(int *)(iVar2 + 0xe08) / fVar1,(float *)&DAT_1005f658,&fStack_c
                  );
    }
    *(float *)(iVar2 + 0xe58) = fStack_c;
    *(float *)(iVar2 + 0xe5c) = fStack_8;
    *(float *)(iVar2 + 0xe60) = fStack_4;
    uVar6 = (int)*(uint *)(iVar2 + 0xe0c) >> 0x1f;
    iVar5 = (*(uint *)(iVar2 + 0xe0c) ^ uVar6) - uVar6;
    if (((float)iVar5 != _DAT_1004410c) && (0 < *(int *)((int)param_1 + 0x220))) {
      param_1 = ((float)iVar5 * _DAT_10044130) / (float)*(int *)((int)param_1 + 0x220);
      if (param_1 < local_14 * (float)_DAT_10044140) {
        param_1 = local_14 * (float)_DAT_10044140;
      }
      if (_DAT_10044190 < param_1) {
        param_1 = 50.0;
      }
      fStack_c = *(float *)(iVar2 + 0xe10) - *(float *)((int)fVar4 + 4);
      fStack_8 = *(float *)(iVar2 + 0xe14) - *(float *)((int)fVar4 + 8);
      fStack_4 = *(float *)(iVar2 + 0xe18) - *(float *)((int)fVar4 + 0xc);
      FUN_10038900(&fStack_c);
      *(float *)(iVar2 + 0xe3c) =
           (_DAT_100613ac * fStack_4 + DAT_100613a8 * fStack_8 + DAT_100613a4 * fStack_c) * param_1
           * (float)_DAT_10044128;
      *(float *)(iVar2 + 0xe40) =
           -(_DAT_100613a0 * fStack_4 + DAT_1006139c * fStack_8 + DAT_10061398 * fStack_c) * param_1
           * (float)_DAT_10044128;
      *(float *)(iVar2 + 0xe44) = DAT_1006c2e4 + (float)_DAT_10044140;
    }
    *(undefined4 *)(iVar2 + 0xe08) = 0;
    *(undefined4 *)(iVar2 + 0xe00) = 0;
    *(undefined4 *)(iVar2 + 0xe04) = 0;
    *(undefined4 *)(iVar2 + 0xe0c) = 0;
  }
  return;
}



/* FUN_10014c50 @ 10014c50 size 1076 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10014c50(float param_1,float *param_2,undefined4 param_3)

{
  float *pfVar1;
  float fVar2;
  bool bVar3;
  float fVar4;
  float10 fVar5;
  float local_30;
  float local_2c;
  float local_28;
  float local_24 [9];
  
  local_30 = 0.0;
  *(undefined4 *)((int)param_1 + 0x180) = 0;
  *(undefined4 *)((int)param_1 + 0x17c) = 0;
  *(undefined4 *)((int)param_1 + 0x178) = 0;
  local_2c = 0.0;
  local_28 = 0.0;
  local_24[0] = 1.0;
  local_24[1] = 0.0;
  local_24[2] = 0.0;
  *(float *)((int)param_1 + 0x334) = *param_2 - *(float *)((int)param_1 + 4);
  local_24[3] = 0.0;
  local_24[4] = 1.0;
  local_24[5] = 0.0;
  local_24[6] = 0.0;
  local_24[7] = 0.0;
  local_24[8] = 1.0;
  *(float *)((int)param_1 + 0x338) = param_2[1] - *(float *)((int)param_1 + 8);
  *(float *)((int)param_1 + 0x33c) = param_2[2] - *(float *)((int)param_1 + 0xc);
  fVar5 = (float10)FUN_10038900((float *)((int)param_1 + 0x334));
  *(float *)((int)param_1 + 0x34c) = (float)fVar5;
  fVar4 = _DAT_1004410c;
  *(undefined4 *)((int)param_1 + 0x354) = param_3;
  if (fVar4 < *(float *)((int)param_1 + 0x298)) {
    *(float *)((int)param_1 + 800) = (float)(fVar5 / (float10)*(float *)((int)param_1 + 0x298));
  }
  fVar4 = (float)FUN_100388c0((float *)((int)param_1 + 0x1d0),(float *)&DAT_10061c18);
  if (fVar4 == 0.0) {
    fVar2 = *(float *)((int)param_1 + 0x1d0);
    bVar3 = fVar2 != _DAT_1004410c;
    *(undefined4 *)((int)param_1 + 0x174) = 0;
    *(undefined4 *)((int)param_1 + 0x170) = 0;
    *(undefined4 *)((int)param_1 + 0x16c) = 0;
    pfVar1 = (float *)((int)param_1 + 0x10);
    *(undefined4 *)((int)param_1 + 0x168) = *(undefined4 *)((int)param_1 + 0x18);
    *(undefined4 *)((int)param_1 + 0x160) = *(undefined4 *)((int)param_1 + 0x10);
    *(undefined4 *)((int)param_1 + 0x164) = *(undefined4 *)((int)param_1 + 0x14);
    local_30 = fVar4;
    local_2c = fVar4;
    local_28 = fVar4;
    if (bVar3) {
      FUN_10038950(pfVar1,fVar2,local_24,&local_30);
      *(float *)((int)param_1 + 0x16c) = local_30 + *(float *)((int)param_1 + 0x16c);
      *(float *)((int)param_1 + 0x170) = local_2c + *(float *)((int)param_1 + 0x170);
      *(float *)((int)param_1 + 0x174) = local_28 + *(float *)((int)param_1 + 0x174);
    }
    if (*(float *)((int)param_1 + 0x1d4) != _DAT_1004410c) {
      FUN_10038950(pfVar1,*(float *)((int)param_1 + 0x1d4),local_24 + 3,&local_30);
      *(float *)((int)param_1 + 0x16c) = local_30 + *(float *)((int)param_1 + 0x16c);
      *(float *)((int)param_1 + 0x170) = local_2c + *(float *)((int)param_1 + 0x170);
      *(float *)((int)param_1 + 0x174) = local_28 + *(float *)((int)param_1 + 0x174);
    }
    if (*(float *)((int)param_1 + 0x1d8) != _DAT_1004410c) {
      FUN_10038950(pfVar1,*(float *)((int)param_1 + 0x1d8),local_24 + 6,&local_30);
      *(float *)((int)param_1 + 0x16c) = local_30 + *(float *)((int)param_1 + 0x16c);
      *(float *)((int)param_1 + 0x170) = local_2c + *(float *)((int)param_1 + 0x170);
      *(float *)((int)param_1 + 0x174) = local_28 + *(float *)((int)param_1 + 0x174);
    }
    *(undefined4 *)((int)param_1 + 0x2ec) = *(undefined4 *)((int)param_1 + 0x160);
    *(undefined4 *)((int)param_1 + 0x2f0) = *(undefined4 *)((int)param_1 + 0x164);
    *(undefined4 *)((int)param_1 + 0x2f4) = *(undefined4 *)((int)param_1 + 0x168);
    *(undefined4 *)((int)param_1 + 0x304) = *(undefined4 *)((int)param_1 + 0x16c);
    *(undefined4 *)((int)param_1 + 0x308) = *(undefined4 *)((int)param_1 + 0x170);
    *(undefined4 *)((int)param_1 + 0x30c) = *(undefined4 *)((int)param_1 + 0x174);
  }
  else {
    fVar4 = (float)FUN_100388c0((float *)((int)param_1 + 0x1ac),(float *)&DAT_10061c18);
    if (fVar4 == 0.0) {
      fVar2 = *(float *)((int)param_1 + 0x1ac);
      local_30 = 0.0;
      local_2c = 0.0;
      local_28 = 0.0;
      if (fVar2 != _DAT_1004410c) {
        local_30 = fVar4;
        local_2c = fVar4;
        local_28 = fVar4;
        FUN_10038a20(local_24,fVar2,(float *)((int)param_1 + 0x184));
        local_30 = local_30 + *(float *)((int)param_1 + 0x184);
        local_2c = local_2c + *(float *)((int)param_1 + 0x188);
        local_28 = local_28 + *(float *)((int)param_1 + 0x18c);
      }
      if (*(float *)((int)param_1 + 0x1b0) != _DAT_1004410c) {
        FUN_10038a20(local_24 + 3,*(float *)((int)param_1 + 0x1b0),(float *)((int)param_1 + 0x184));
        local_30 = local_30 + *(float *)((int)param_1 + 0x184);
        local_2c = local_2c + *(float *)((int)param_1 + 0x188);
        local_28 = local_28 + *(float *)((int)param_1 + 0x18c);
      }
      if (*(float *)((int)param_1 + 0x1b4) != _DAT_1004410c) {
        FUN_10038a20(local_24 + 6,*(float *)((int)param_1 + 0x1b4),(float *)((int)param_1 + 0x184));
        local_30 = local_30 + *(float *)((int)param_1 + 0x184);
        local_2c = local_2c + *(float *)((int)param_1 + 0x188);
        local_28 = local_28 + *(float *)((int)param_1 + 0x18c);
      }
      *(float *)((int)param_1 + 0x184) = local_30;
      *(float *)((int)param_1 + 0x188) = local_2c;
      *(float *)((int)param_1 + 0x18c) = local_28;
    }
  }
  fVar4 = param_1;
  if ((*(uint *)((int)param_1 + 0x108) & 0x400) != 0) {
    fVar4 = *(float *)((int)param_1 + 0x274);
  }
  if (DAT_1006c404 != fVar4) {
    fVar4 = DAT_1006c2e4 + (float)_DAT_10044168;
    *(code **)((int)param_1 + 500) = FUN_10014ad0;
    *(float *)((int)param_1 + 0x1ec) = fVar4;
    return;
  }
  FUN_10014ad0(param_1);
  return;
}



/* FUN_10003f20 @ 10003f20 size 1061 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10003f20(int param_1)

{
  bool bVar1;
  byte *pbVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  int *piVar8;
  void *this;
  int iVar9;
  void *this_00;
  char *pcVar10;
  
  if ((*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) &&
     (*(float *)(DAT_1006c1a4 + 0x14) == _DAT_1004410c)) {
    (*DAT_1006c1c8)(param_1,2,s_You_must_run_the_server_with___s_10046214);
    return;
  }
  pbVar2 = (byte *)(*DAT_1006c264)();
  iVar3 = FUN_10038b20(pbVar2,&DAT_10046210);
  if (iVar3 == 0) {
    bVar1 = true;
LAB_10003fad:
    iVar3 = (*DAT_1006c25c)();
    if (iVar3 == 3) {
      pbVar2 = (byte *)(*DAT_1006c260)(2);
      uVar5 = FUN_10039237(this,pbVar2);
    }
    else {
      uVar5 = *(undefined4 *)(param_1 + 0x224);
    }
    *(undefined4 *)(param_1 + 0x220) = uVar5;
    if (!bVar1) {
      return;
    }
LAB_10003ff3:
    iVar3 = 0;
    if (0 < DAT_1006ca54) {
      iVar9 = 0x2e4;
      pbVar2 = &DAT_10046960;
      do {
        if ((*(int *)(pbVar2 + -0x34) != 0) && ((*pbVar2 & 1) != 0)) {
          piVar6 = (int *)(*(int *)(param_1 + 0x54) + iVar9);
          *piVar6 = *piVar6 + 1;
        }
        iVar3 = iVar3 + 1;
        iVar9 = iVar9 + 4;
        pbVar2 = pbVar2 + 0x48;
      } while (iVar3 < DAT_1006ca54);
    }
    if (!bVar1) {
      return;
    }
LAB_10004047:
    iVar3 = 0;
    if (0 < DAT_1006ca54) {
      pbVar2 = &DAT_10046960;
      do {
        if ((*(int *)(pbVar2 + -0x34) != 0) && ((*pbVar2 & 2) != 0)) {
          FUN_1000bdf0(param_1,(int)(pbVar2 + -0x38),1000);
        }
        iVar3 = iVar3 + 1;
        pbVar2 = pbVar2 + 0x48;
      } while (iVar3 < DAT_1006ca54);
    }
    if (!bVar1) {
      return;
    }
LAB_100040a2:
    puVar7 = FUN_1000b150((byte *)s_Jacket_Armor_100461e0);
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar7 + -0x4011a4a) / 0x48) * 4) = 0;
    puVar7 = FUN_1000b150((byte *)s_Combat_Armor_100461d0);
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar7 + -0x4011a4a) / 0x48) * 4) = 0;
    puVar7 = FUN_1000b150((byte *)s_Body_Armor_100461c4);
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar7 + -0x4011a4a) / 0x48) * 4) =
         *(undefined4 *)(puVar7[0xf] + 4);
    if (!bVar1) {
      return;
    }
  }
  else {
    pcVar10 = s_health_10046208;
    bVar1 = false;
    pvVar4 = (void *)(*DAT_1006c260)(1);
    iVar3 = FUN_10038b20(pvVar4,(byte *)pcVar10);
    if (iVar3 == 0) goto LAB_10003fad;
    iVar3 = FUN_10038b20(pbVar2,(byte *)s_weapons_10046200);
    if (iVar3 == 0) goto LAB_10003ff3;
    iVar3 = FUN_10038b20(pbVar2,&DAT_100461f8);
    if (iVar3 == 0) goto LAB_10004047;
    iVar3 = FUN_10038b20(pbVar2,(byte *)s_armor_100461f0);
    if (iVar3 == 0) goto LAB_100040a2;
    iVar3 = FUN_10038b20(pbVar2,(byte *)s_Power_Shield_100461b4);
    if (iVar3 != 0) {
      iVar3 = FUN_10038b20(pbVar2,(byte *)s_Rifle_Plasma_100461a4);
      if (iVar3 != 0) {
        piVar6 = FUN_1000b150(pbVar2);
        if (piVar6 == (int *)0x0) {
          pbVar2 = (byte *)(*DAT_1006c260)(1);
          piVar6 = FUN_1000b150(pbVar2);
          if (piVar6 == (int *)0x0) {
            (*DAT_1006c1c8)(param_1,2,s_unknown_item_10046194);
            return;
          }
        }
        if (piVar6[1] == 0) {
          (*DAT_1006c1c8)(param_1,2,s_non_pickup_item_10046180);
          return;
        }
        if ((*(byte *)(piVar6 + 0xe) & 2) != 0) {
          iVar3 = (*DAT_1006c25c)();
          if (iVar3 == 3) {
            pbVar2 = (byte *)(*DAT_1006c260)(2);
            uVar5 = FUN_10039237(this_00,pbVar2);
            *(undefined4 *)
             (*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(piVar6 + -0x4011a4a) / 0x48) * 4) = uVar5;
            return;
          }
          piVar8 = (int *)(*(int *)(param_1 + 0x54) + 0x2e4 +
                          ((int)(piVar6 + -0x4011a4a) / 0x48) * 4);
          *piVar8 = *piVar8 + piVar6[0xc];
          return;
        }
        piVar8 = FUN_1001b350();
        piVar8[0x46] = *piVar6;
        FUN_1000cf20(piVar8,piVar6);
        FUN_1000c650(piVar8,param_1);
        if (piVar8[0x16] == 0) {
          return;
        }
        FUN_1001b400(piVar8);
        return;
      }
      goto LAB_100041ad;
    }
  }
  piVar6 = FUN_1000b150((byte *)s_Power_Shield_100461b4);
  piVar8 = FUN_1001b350();
  piVar8[0x46] = *piVar6;
  FUN_1000cf20(piVar8,piVar6);
  FUN_1000c650(piVar8,param_1);
  if (piVar8[0x16] != 0) {
    FUN_1001b400(piVar8);
  }
  if (!bVar1) {
    return;
  }
LAB_100041ad:
  piVar6 = FUN_1000b150((byte *)s_Rifle_Plasma_100461a4);
  piVar8 = FUN_1001b350();
  piVar8[0x46] = *piVar6;
  FUN_1000cf20(piVar8,piVar6);
  FUN_1000c650(piVar8,param_1);
  if (piVar8[0x16] != 0) {
    FUN_1001b400(piVar8);
  }
  if ((bVar1) && (iVar3 = 0, 0 < DAT_1006ca54)) {
    iVar9 = 0x2e4;
    pbVar2 = &DAT_10046960;
    do {
      if ((*(int *)(pbVar2 + -0x34) != 0) && ((*pbVar2 & 7) == 0)) {
        *(undefined4 *)(*(int *)(param_1 + 0x54) + iVar9) = 1;
      }
      iVar3 = iVar3 + 1;
      iVar9 = iVar9 + 4;
      pbVar2 = pbVar2 + 0x48;
    } while (iVar3 < DAT_1006ca54);
    return;
  }
  return;
}



/* FUN_10033d00 @ 10033d00 size 1027 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10033d00(int param_1)

{
  int iVar1;
  uint uVar2;
  float *pfVar3;
  undefined4 uVar4;
  uint uVar5;
  ulonglong uVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float local_c;
  float local_8;
  float local_4;
  
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x6c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x68) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 100) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x60) = 0;
  iVar1 = *(int *)(param_1 + 0x54);
  if (*(int *)(iVar1 + 0xf0c) == 0) {
    local_c = *(float *)(iVar1 + 0x28) + *(float *)(param_1 + 4);
    pfVar3 = &local_c;
    local_8 = *(float *)(iVar1 + 0x2c) + *(float *)(param_1 + 8);
    local_4 = *(float *)(iVar1 + 0x30) + *(float *)(param_1 + 0xc);
  }
  else {
    pfVar3 = (float *)(*(int *)(iVar1 + 0xf18) + 4);
  }
  uVar2 = (*DAT_1006c1f4)(pfVar3);
  uVar5 = *(uint *)(*(int *)(param_1 + 0x54) + 0x74);
  if ((uVar2 & 0x38) == 0) {
    uVar5 = uVar5 & 0xfffffffe;
  }
  else {
    uVar5 = uVar5 | 1;
  }
  *(uint *)(*(int *)(param_1 + 0x54) + 0x74) = uVar5;
  if ((uVar2 & 9) == 0) {
    if ((uVar2 & 0x10) != 0) {
      pfVar3 = (float *)(*(int *)(param_1 + 0x54) + 0x60);
      fVar10 = 0.6;
      fVar9 = 0.05;
      fVar8 = 0.1;
      fVar7 = 0.0;
      goto LAB_10033dd4;
    }
    if ((uVar2 & 0x20) != 0) {
      pfVar3 = (float *)(*(int *)(param_1 + 0x54) + 0x60);
      fVar10 = 0.4;
      fVar9 = 0.2;
      fVar8 = 0.3;
      fVar7 = 0.5;
      goto LAB_10033dd4;
    }
  }
  else {
    pfVar3 = (float *)(*(int *)(param_1 + 0x54) + 0x60);
    fVar10 = 0.6;
    fVar9 = 0.0;
    fVar8 = 0.3;
    fVar7 = 1.0;
LAB_10033dd4:
    FUN_10033c90(fVar7,fVar8,fVar9,fVar10,pfVar3);
  }
  fVar7 = (float)DAT_1006c2e0;
  iVar1 = *(int *)(param_1 + 0x54);
  if (*(float *)(iVar1 + 0xeac) <= fVar7) {
    if (*(float *)(iVar1 + 0xeb0) <= fVar7) {
      if (*(float *)(iVar1 + 0xeb8) <= fVar7) {
        if (*(float *)(iVar1 + 0xeb4) <= fVar7) goto LAB_10033fc2;
        uVar6 = __ftol();
        if ((int)uVar6 == 0x1e) {
          uVar4 = (*DAT_1006c1e4)(s_items_airout_wav_10047d20,0x3f800000,0x3f800000,0);
          (*DAT_1006c1d0)(param_1,3,uVar4);
LAB_10033f96:
          if ((uVar6 & 4) == 0) goto LAB_10033fc2;
        }
        else if ((int)uVar6 < 0x1f) goto LAB_10033f96;
        FUN_10033c90(0.4,1.0,0.4,0.04,(float *)(*(int *)(param_1 + 0x54) + 0x60));
        goto LAB_10033fc2;
      }
      uVar6 = __ftol();
      if ((int)uVar6 == 0x1e) {
        uVar4 = (*DAT_1006c1e4)(s_items_airout_wav_10047d20,0x3f800000,0x3f800000,0);
        (*DAT_1006c1d0)(param_1,3,uVar4);
LAB_10033f23:
        if ((uVar6 & 4) == 0) goto LAB_10033fc2;
      }
      else if ((int)uVar6 < 0x1f) goto LAB_10033f23;
      FUN_10033c90(0.0,1.0,0.0,0.08,(float *)(*(int *)(param_1 + 0x54) + 0x60));
      goto LAB_10033fc2;
    }
    uVar6 = __ftol();
    if ((int)uVar6 == 0x1e) {
      uVar4 = (*DAT_1006c1e4)(s_items_protect2_wav_1005f674,0x3f800000,0x3f800000,0);
      (*DAT_1006c1d0)(param_1,3,uVar4);
LAB_10033ea9:
      if ((uVar6 & 4) == 0) goto LAB_10033fc2;
    }
    else if ((int)uVar6 < 0x1f) goto LAB_10033ea9;
    FUN_10033c90(1.0,1.0,0.0,0.08,(float *)(*(int *)(param_1 + 0x54) + 0x60));
    goto LAB_10033fc2;
  }
  uVar6 = __ftol();
  if ((int)uVar6 == 0x1e) {
    uVar4 = (*DAT_1006c1e4)(s_items_damage2_wav_1005f688,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_1,3,uVar4);
LAB_10033e33:
    if ((uVar6 & 4) == 0) goto LAB_10033fc2;
  }
  else if ((int)uVar6 < 0x1f) goto LAB_10033e33;
  FUN_10033c90(0.0,0.0,1.0,0.08,(float *)(*(int *)(param_1 + 0x54) + 0x60));
LAB_10033fc2:
  iVar1 = *(int *)(param_1 + 0x54);
  if (_DAT_1004410c < *(float *)(iVar1 + 0xe50)) {
    FUN_10033c90(*(float *)(iVar1 + 0xe58),*(float *)(iVar1 + 0xe5c),*(float *)(iVar1 + 0xe60),
                 *(float *)(iVar1 + 0xe50),(float *)(iVar1 + 0x60));
  }
  fVar7 = *(float *)(*(int *)(param_1 + 0x54) + 0xe54);
  if (_DAT_1004410c < fVar7) {
    FUN_10033c90(0.85,0.7,0.3,fVar7,(float *)(*(int *)(param_1 + 0x54) + 0x60));
  }
  FUN_10033c90(*(float *)(DAT_1006c2c4 + 0x2d0),*(float *)(DAT_1006c2c4 + 0x2d4),
               *(float *)(DAT_1006c2c4 + 0x2d8),*(float *)(DAT_1006c2c4 + 0x2dc),
               (float *)(*(int *)(param_1 + 0x54) + 0x60));
  *(undefined4 *)(DAT_1006c2c4 + 0x2dc) = 0;
  *(undefined4 *)(DAT_1006c2c4 + 0x2d8) = 0;
  *(undefined4 *)(DAT_1006c2c4 + 0x2d4) = 0;
  *(undefined4 *)(DAT_1006c2c4 + 0x2d0) = 0;
  *(float *)(*(int *)(param_1 + 0x54) + 0xe50) =
       *(float *)(*(int *)(param_1 + 0x54) + 0xe50) - (float)_DAT_10044418;
  if (*(float *)(*(int *)(param_1 + 0x54) + 0xe50) < _DAT_1004410c) {
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe50) = 0;
  }
  *(float *)(*(int *)(param_1 + 0x54) + 0xe54) =
       *(float *)(*(int *)(param_1 + 0x54) + 0xe54) - (float)_DAT_10044168;
  if (*(float *)(*(int *)(param_1 + 0x54) + 0xe54) < _DAT_1004410c) {
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe54) = 0;
  }
  return;
}



/* FUN_10012f00 @ 10012f00 size 998 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl FUN_10012f00(float *param_1,float param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  float *pfVar7;
  uint local_fc;
  float *pfStack_f8;
  int iStack_f4;
  float local_f0;
  int local_ec;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  int aiStack_b8 [2];
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_84;
  float local_80 [18];
  undefined1 local_38 [56];
  
  iVar5 = 0;
  local_dc = param_1[0x5e];
  local_d8 = param_1[0x5f];
  local_d4 = param_1[0x60];
  local_fc = 0;
  local_f0 = param_2;
  param_1[0x9a] = 0.0;
  local_ec = 0;
  local_d0 = local_dc;
  local_cc = local_d8;
  local_c8 = local_d4;
  while( true ) {
    iVar4 = 3;
    pfVar3 = local_80;
    pfVar7 = param_1;
    do {
      iVar4 = iVar4 + -1;
      *pfVar3 = local_f0 * pfVar7[0x5e] + pfVar7[1];
      pfVar3 = pfVar3 + 1;
      pfVar7 = pfVar7 + 1;
    } while (iVar4 != 0);
    piVar1 = (int *)(*DAT_1006c1f0)(local_38,param_1 + 1,param_1 + 0x2f,param_1 + 0x32,local_80,
                                    param_1,param_3);
    piVar6 = aiStack_b8;
    for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar6 = *piVar1;
      piVar1 = piVar1 + 1;
      piVar6 = piVar6 + 1;
    }
    if (aiStack_b8[0] != 0) break;
    iVar4 = iVar5;
    if (_DAT_1004410c < fStack_b0) {
      param_1[1] = fStack_ac;
      local_dc = param_1[0x5e];
      param_1[2] = fStack_a8;
      local_d8 = param_1[0x5f];
      param_1[3] = fStack_a4;
      local_d4 = param_1[0x60];
      iVar4 = 0;
    }
    if (fStack_b0 == _DAT_10044104) {
      return local_fc;
    }
    if (((float)_DAT_10044228 < fStack_98) &&
       (local_fc = local_fc | 1, *(int *)((int)fStack_84 + 0xf8) == 3)) {
      param_1[0x9a] = fStack_84;
      param_1[0x9b] = *(float *)((int)fStack_84 + 0x5c);
    }
    if (fStack_98 == _DAT_1004410c) {
      local_fc = local_fc | 2;
    }
    FUN_10012df0((int)param_1,(int)aiStack_b8);
    if (param_1[0x16] == 0.0) {
      return local_fc;
    }
    local_f0 = local_f0 - fStack_b0 * local_f0;
    if (4 < iVar4) break;
    iStack_f4 = 0;
    iVar5 = iVar4 + 1;
    local_80[iVar4 * 3 + 3] = fStack_a0;
    local_80[iVar4 * 3 + 4] = fStack_9c;
    local_80[iVar4 * 3 + 5] = fStack_98;
    if (0 < iVar5) {
      pfStack_f8 = local_80;
      do {
        pfStack_f8 = pfStack_f8 + 3;
        FUN_10012e50(&local_dc,pfStack_f8,&fStack_e8,1.0);
        iVar4 = 0;
        pfVar7 = local_80;
        do {
          pfVar7 = pfVar7 + 3;
          if (((iVar4 != iStack_f4) && (iVar2 = FUN_100388c0(pfStack_f8,pfVar7), iVar2 == 0)) &&
             (fStack_e8 * *pfVar7 + fStack_e4 * pfVar7[1] + fStack_e0 * pfVar7[2] < _DAT_1004410c))
          break;
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar5);
        if (iVar4 == iVar5) break;
        iStack_f4 = iStack_f4 + 1;
      } while (iStack_f4 < iVar5);
    }
    if (iStack_f4 == iVar5) {
      if (iVar5 != 2) {
        param_1[0x5e] = DAT_10061c18;
        param_1[0x5f] = DAT_10061c1c;
        param_1[0x60] = DAT_10061c20;
        return 7;
      }
      FUN_100389b0(local_80 + 3,local_80 + 6,&fStack_c4);
      FUN_10038a20(&fStack_c4,
                   fStack_c4 * param_1[0x5e] + fStack_bc * param_1[0x60] + fStack_c0 * param_1[0x5f]
                   ,param_1 + 0x5e);
    }
    else {
      param_1[0x5f] = fStack_e4;
      param_1[0x60] = fStack_e0;
      param_1[0x5e] = fStack_e8;
    }
    if (local_d0 * param_1[0x5e] + local_c8 * param_1[0x60] + local_cc * param_1[0x5f] <=
        _DAT_1004410c) {
      param_1[0x5e] = DAT_10061c18;
      param_1[0x5f] = DAT_10061c1c;
      param_1[0x60] = DAT_10061c20;
      return local_fc;
    }
    local_ec = local_ec + 1;
    if (3 < local_ec) {
      return local_fc;
    }
  }
  param_1[0x5e] = DAT_10061c18;
  param_1[0x5f] = DAT_10061c1c;
  param_1[0x60] = DAT_10061c20;
  return 3;
}



/* FUN_10009bd0 @ 10009bd0 size 968 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10009bd0(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  undefined4 uVar4;
  
  pfVar1 = (float *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  pfVar2 = (float *)(param_1 + 0x154);
  *pfVar1 = 0.0;
  *(undefined4 *)(param_1 + 0x15c) = 0;
  *(undefined4 *)(param_1 + 0x158) = 0;
  *pfVar2 = 0.0;
  if ((*(uint *)(param_1 + 0x11c) & 0x40) == 0) {
    if ((*(uint *)(param_1 + 0x11c) & 0x80) == 0) {
      *(undefined4 *)(param_1 + 0x158) = 0x3f800000;
    }
    else {
      *pfVar2 = 1.0;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x15c) = 0x3f800000;
  }
  if ((*(byte *)(param_1 + 0x11c) & 2) != 0) {
    *pfVar2 = -*pfVar2;
    *(float *)(param_1 + 0x158) = -*(float *)(param_1 + 0x158);
    *(float *)(param_1 + 0x15c) = -*(float *)(param_1 + 0x15c);
  }
  if (DAT_1006c29c == 0) {
    DAT_1006c29c = 0x5a;
  }
  pfVar3 = (float *)(param_1 + 0x16c);
  *(float *)(param_1 + 0x160) = *pfVar1;
  *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(param_1 + 0x18);
  FUN_10038950(pfVar1,(float)DAT_1006c29c,pfVar2,pfVar3);
  *(float *)(param_1 + 0x328) = (float)DAT_1006c29c;
  *(undefined4 *)(param_1 + 0x104) = 2;
  *(undefined4 *)(param_1 + 0xf8) = 3;
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  *(undefined1 **)(param_1 + 0x1f8) = &LAB_10009670;
  *(code **)(param_1 + 0x200) = FUN_10009340;
  if (*(float *)(param_1 + 0x148) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x148) = 0x42c80000;
  }
  if (*(float *)(param_1 + 0x14c) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_1 + 0x148);
  }
  if (*(float *)(param_1 + 0x150) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(param_1 + 0x148);
  }
  if (*(float *)(param_1 + 0x290) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x290) = 0x40400000;
  }
  if (*(int *)(param_1 + 0x244) == 0) {
    *(undefined4 *)(param_1 + 0x244) = 2;
  }
  if (*(int *)(param_1 + 0x250) != 1) {
    uVar4 = (*DAT_1006c1e4)(s_doors_dr1_strt_wav_10046700);
    *(undefined4 *)(param_1 + 0x310) = uVar4;
    uVar4 = (*DAT_1006c1e4)(s_doors_dr1_mid_wav_100466ec);
    *(undefined4 *)(param_1 + 0x314) = uVar4;
    uVar4 = (*DAT_1006c1e4)(s_doors_dr1_end_wav_100466d8);
    *(undefined4 *)(param_1 + 0x318) = uVar4;
  }
  if ((*(byte *)(param_1 + 0x11c) & 1) != 0) {
    *pfVar1 = *pfVar3;
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x170);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x174);
    *pfVar3 = *(float *)(param_1 + 0x160);
    *(undefined4 *)(param_1 + 0x170) = *(undefined4 *)(param_1 + 0x164);
    *(undefined4 *)(param_1 + 0x174) = *(undefined4 *)(param_1 + 0x168);
    *(float *)(param_1 + 0x160) = *pfVar1;
    *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(param_1 + 0x18);
    *pfVar2 = -*pfVar2;
    *(float *)(param_1 + 0x158) = -*(float *)(param_1 + 0x158);
    *(float *)(param_1 + 0x15c) = -*(float *)(param_1 + 0x15c);
  }
  if (*(int *)(param_1 + 0x220) != 0) {
    *(undefined4 *)(param_1 + 0x240) = 1;
    *(undefined1 **)(param_1 + 0x208) = &LAB_10009760;
    *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x220);
  }
  if ((*(int *)(param_1 + 300) != 0) && (*(int *)(param_1 + 0x114) != 0)) {
    (*DAT_1006c1e4)(s_misc_talk_wav_10046158);
    *(code **)(param_1 + 0x1fc) = FUN_100097b0;
  }
  *(undefined4 *)(param_1 + 800) = *(undefined4 *)(param_1 + 0x148);
  *(undefined4 *)(param_1 + 0x31c) = *(undefined4 *)(param_1 + 0x14c);
  *(undefined4 *)(param_1 + 0x32c) = *(undefined4 *)(param_1 + 0x290);
  *(undefined4 *)(param_1 + 0x324) = *(undefined4 *)(param_1 + 0x150);
  *(undefined4 *)(param_1 + 0x2e8) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0x2e0) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x2f4) = *(undefined4 *)(param_1 + 0x168);
  *(undefined4 *)(param_1 + 0x2e4) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x300) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0x2ec) = *(undefined4 *)(param_1 + 0x160);
  *(undefined4 *)(param_1 + 0x2f0) = *(undefined4 *)(param_1 + 0x164);
  *(undefined4 *)(param_1 + 0x30c) = *(undefined4 *)(param_1 + 0x174);
  *(undefined4 *)(param_1 + 0x2f8) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x2fc) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x330) = 1;
  *(float *)(param_1 + 0x304) = *pfVar3;
  *(undefined4 *)(param_1 + 0x308) = *(undefined4 *)(param_1 + 0x170);
  if ((*(byte *)(param_1 + 0x11c) & 0x10) != 0) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x1000;
  }
  if (*(int *)(param_1 + 0x134) == 0) {
    *(int *)(param_1 + 0x274) = param_1;
  }
  (*DAT_1006c208)(param_1);
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  if ((*(int *)(param_1 + 0x220) == 0) && (*(int *)(param_1 + 300) == 0)) {
    *(undefined1 **)(param_1 + 500) = &LAB_10009500;
    return;
  }
  *(code **)(param_1 + 500) = FUN_10009430;
  return;
}



/* FUN_1001a100 @ 1001a100 size 938 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1001a100(int param_1)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float10 fVar5;
  float10 fVar6;
  float local_18;
  float local_14;
  undefined4 local_10;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  local_c = *(float *)(param_1 + 0x10);
  local_8 = *(float *)(param_1 + 0x14);
  local_4 = *(undefined4 *)(param_1 + 0x18);
  FUN_10019e90(&local_c);
  pfVar1 = (float *)(param_1 + 0x2b8);
  FUN_10019e90(pfVar1);
  if (_DAT_100442c4 < *pfVar1) {
    *pfVar1 = *pfVar1 - _DAT_100442b0;
  }
  if (*pfVar1 <= *(float *)(param_1 + 0x160)) {
    if (*pfVar1 < *(float *)(param_1 + 0x16c)) {
      *pfVar1 = *(float *)(param_1 + 0x16c);
    }
  }
  else {
    *pfVar1 = *(float *)(param_1 + 0x160);
  }
  if ((*(float *)(param_1 + 700) < *(float *)(param_1 + 0x164)) ||
     (*(float *)(param_1 + 0x170) < *(float *)(param_1 + 700))) {
    fVar3 = ABS(*(float *)(param_1 + 0x164) - *(float *)(param_1 + 700));
    if (_DAT_100442c0 <= fVar3) {
      if (_DAT_100442c4 < fVar3) {
        fVar3 = fVar3 - _DAT_100442b0;
      }
    }
    else {
      fVar3 = fVar3 + _DAT_100442b0;
    }
    fVar4 = ABS(*(float *)(param_1 + 0x170) - *(float *)(param_1 + 700));
    if (_DAT_100442c0 <= fVar4) {
      if (_DAT_100442c4 < fVar4) {
        fVar4 = fVar4 - _DAT_100442b0;
      }
    }
    else {
      fVar4 = fVar4 + _DAT_100442b0;
    }
    if (ABS(fVar4) <= ABS(fVar3)) {
      *(undefined4 *)(param_1 + 700) = *(undefined4 *)(param_1 + 0x170);
    }
    else {
      *(undefined4 *)(param_1 + 700) = *(undefined4 *)(param_1 + 0x164);
    }
  }
  local_18 = *pfVar1 - local_c;
  local_14 = *(float *)(param_1 + 700) - local_8;
  if (_DAT_100442c0 <= local_18) {
    if (_DAT_100442c4 < local_18) {
      local_18 = local_18 - _DAT_100442b0;
    }
  }
  else {
    local_18 = local_18 + _DAT_100442b0;
  }
  if (_DAT_100442c0 <= local_14) {
    if (_DAT_100442c4 < local_14) {
      local_14 = local_14 - _DAT_100442b0;
    }
  }
  else {
    local_14 = local_14 + _DAT_100442b0;
  }
  fVar3 = *(float *)(param_1 + 0x148) * (float)_DAT_10044168;
  local_10 = 0;
  if (fVar3 < local_18) {
    local_18 = fVar3;
  }
  fVar4 = *(float *)(param_1 + 0x148) * _DAT_100441bc * (float)_DAT_10044168;
  if (local_18 < fVar4) {
    local_18 = fVar4;
  }
  if (fVar3 < local_14) {
    local_14 = fVar3;
  }
  if (local_14 < fVar4) {
    local_14 = fVar4;
  }
  FUN_10038a20(&local_18,10.0,(float *)(param_1 + 0x184));
  iVar2 = *(int *)(param_1 + 0x274);
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x270)) {
    *(undefined4 *)(iVar2 + 0x188) = *(undefined4 *)(param_1 + 0x188);
  }
  if (*(int *)(param_1 + 0x100) != 0) {
    *(float *)(*(int *)(param_1 + 0x100) + 0x184) = *(float *)(param_1 + 0x184);
    *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x188) = *(undefined4 *)(param_1 + 0x188);
    fVar5 = ((float10)*(float *)(*(int *)(param_1 + 0x100) + 0x2b0) +
            (float10)*(float *)(param_1 + 0x14)) * (float10)_DAT_100442b8;
    fVar6 = (float10)fcos(fVar5);
    fVar6 = FUN_10019f40((float)(fVar6 * (float10)*(float *)(*(int *)(param_1 + 0x100) + 0x2ac) +
                                (float10)*(float *)(param_1 + 4)));
    fVar5 = (float10)fsin((float10)(float)fVar5);
    fVar5 = FUN_10019f40((float)(fVar5 * (float10)*(float *)(*(int *)(param_1 + 0x100) + 0x2ac) +
                                (float10)*(float *)(param_1 + 8)));
    iVar2 = *(int *)(param_1 + 0x100);
    *(float *)(iVar2 + 0x178) = ((float)fVar6 - *(float *)(iVar2 + 4)) * (float)_DAT_10044170;
    *(float *)(*(int *)(param_1 + 0x100) + 0x17c) =
         (float)((fVar5 - (float10)*(float *)(iVar2 + 8)) * (float10)_DAT_10044170);
    fVar5 = (float10)fptan((float10)*(float *)(param_1 + 0x10) * (float10)_DAT_100442b8);
    fVar5 = FUN_10019f40((float)(fVar5 * (float10)*(float *)(*(int *)(param_1 + 0x100) + 0x2ac) +
                                 (float10)*(float *)(*(int *)(param_1 + 0x100) + 0x2b4) +
                                (float10)*(float *)(param_1 + 0xc)));
    *(float *)(*(int *)(param_1 + 0x100) + 0x180) =
         (float)((fVar5 - (float10)*(float *)(*(int *)(param_1 + 0x100) + 0xc)) *
                (float10)_DAT_10044170);
    if ((*(uint *)(param_1 + 0x11c) & 0x10000) != 0) {
      FUN_10019fe0(param_1);
      *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) & 0xfffeffff;
    }
  }
  return;
}



/* FUN_10009830 @ 10009830 size 919 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10009830(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float fVar4;
  undefined4 uVar5;
  
  if (*(int *)(param_1 + 0x250) != 1) {
    uVar5 = (*DAT_1006c1e4)(s_doors_dr1_strt_wav_10046700);
    *(undefined4 *)(param_1 + 0x310) = uVar5;
    uVar5 = (*DAT_1006c1e4)(s_doors_dr1_mid_wav_100466ec);
    *(undefined4 *)(param_1 + 0x314) = uVar5;
    uVar5 = (*DAT_1006c1e4)(s_doors_dr1_end_wav_100466d8);
    *(undefined4 *)(param_1 + 0x318) = uVar5;
  }
  *(undefined4 *)(param_1 + 0x104) = 2;
  *(undefined4 *)(param_1 + 0xf8) = 3;
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  *(undefined1 **)(param_1 + 0x1f8) = &LAB_10009670;
  *(code **)(param_1 + 0x200) = FUN_10009340;
  if (*(float *)(param_1 + 0x148) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x148) = 0x42c80000;
  }
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    *(float *)(param_1 + 0x148) = *(float *)(param_1 + 0x148) + *(float *)(param_1 + 0x148);
  }
  if (*(float *)(param_1 + 0x14c) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_1 + 0x148);
  }
  if (*(float *)(param_1 + 0x150) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(param_1 + 0x148);
  }
  if (*(float *)(param_1 + 0x290) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x290) = 0x40400000;
  }
  if (DAT_1006c298 == 0) {
    DAT_1006c298 = 8;
  }
  if (*(int *)(param_1 + 0x244) == 0) {
    *(undefined4 *)(param_1 + 0x244) = 2;
  }
  pfVar1 = (float *)(param_1 + 0x10);
  FUN_1001b0c0(pfVar1,(float *)(param_1 + 0x154));
  pfVar2 = (float *)(param_1 + 0x160);
  *pfVar2 = *(float *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(param_1 + 0xc);
  pfVar3 = (float *)(param_1 + 0x16c);
  fVar4 = (ABS(*(float *)(param_1 + 0x154)) * *(float *)(param_1 + 0xec) +
          ABS(*(float *)(param_1 + 0x158)) * *(float *)(param_1 + 0xf0) +
          ABS(*(float *)(param_1 + 0x15c)) * *(float *)(param_1 + 0xf4)) - (float)DAT_1006c298;
  *(float *)(param_1 + 0x328) = fVar4;
  FUN_10038950(pfVar2,fVar4,(float *)(param_1 + 0x154),pfVar3);
  if ((*(byte *)(param_1 + 0x11c) & 1) != 0) {
    *(float *)(param_1 + 4) = *pfVar3;
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x170);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x174);
    *pfVar3 = *pfVar2;
    *(undefined4 *)(param_1 + 0x170) = *(undefined4 *)(param_1 + 0x164);
    *(undefined4 *)(param_1 + 0x174) = *(undefined4 *)(param_1 + 0x168);
    *pfVar2 = *(float *)(param_1 + 4);
    *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(param_1 + 0xc);
  }
  *(float *)(param_1 + 0x2e0) = *pfVar2;
  *(undefined4 *)(param_1 + 0x2e4) = *(undefined4 *)(param_1 + 0x164);
  *(undefined4 *)(param_1 + 0x2e8) = *(undefined4 *)(param_1 + 0x168);
  *(undefined4 *)(param_1 + 0x2f0) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x2f4) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x2fc) = *(undefined4 *)(param_1 + 0x170);
  *(float *)(param_1 + 0x2ec) = *pfVar1;
  *(undefined4 *)(param_1 + 0x300) = *(undefined4 *)(param_1 + 0x174);
  *(undefined4 *)(param_1 + 0x308) = *(undefined4 *)(param_1 + 0x14);
  *(float *)(param_1 + 0x2f8) = *pfVar3;
  *(undefined4 *)(param_1 + 0x30c) = *(undefined4 *)(param_1 + 0x18);
  *(float *)(param_1 + 0x304) = *pfVar1;
  *(undefined4 *)(param_1 + 0x330) = 1;
  if (*(int *)(param_1 + 0x220) == 0) {
    if ((*(int *)(param_1 + 300) != 0) && (*(int *)(param_1 + 0x114) != 0)) {
      (*DAT_1006c1e4)(s_misc_talk_wav_10046158);
      *(code **)(param_1 + 0x1fc) = FUN_100097b0;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x240) = 1;
    *(undefined1 **)(param_1 + 0x208) = &LAB_10009760;
    *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x220);
  }
  *(undefined4 *)(param_1 + 0x31c) = *(undefined4 *)(param_1 + 0x14c);
  *(undefined4 *)(param_1 + 800) = *(undefined4 *)(param_1 + 0x148);
  *(undefined4 *)(param_1 + 0x324) = *(undefined4 *)(param_1 + 0x150);
  *(undefined4 *)(param_1 + 0x32c) = *(undefined4 *)(param_1 + 0x290);
  if ((*(uint *)(param_1 + 0x11c) & 0x10) != 0) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x1000;
  }
  if ((*(uint *)(param_1 + 0x11c) & 0x40) != 0) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x2000;
  }
  if (*(int *)(param_1 + 0x134) == 0) {
    *(int *)(param_1 + 0x274) = param_1;
  }
  (*DAT_1006c208)(param_1);
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  if ((*(int *)(param_1 + 0x220) == 0) && (*(int *)(param_1 + 300) == 0)) {
    *(undefined1 **)(param_1 + 500) = &LAB_10009500;
    return;
  }
  *(code **)(param_1 + 500) = FUN_10009430;
  return;
}



/* FUN_100050c0 @ 100050c0 size 901 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100050c0(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  ulonglong uVar10;
  longlong lVar11;
  char acStack_800 [150];
  undefined1 uStack_76a;
  
  iVar2 = (*DAT_1006c25c)();
  if ((iVar2 < 2) && (param_3 == 0)) {
    return;
  }
  uVar10 = __ftol();
  if ((uVar10 & 0xc0) == 0) {
    param_2 = 0;
  }
  else if (param_2 != 0) {
    FUN_10038b40();
    goto LAB_10005132;
  }
  FUN_10038b40();
LAB_10005132:
  if (param_3 == 0) {
    pcVar3 = (char *)(*DAT_1006c264)();
    if (*pcVar3 == '\"') {
      pcVar3 = pcVar3 + 1;
      uVar4 = 0xffffffff;
      pcVar7 = pcVar3;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      pcVar3[~uVar4 - 2] = '\0';
    }
    uVar4 = 0xffffffff;
    do {
      pcVar7 = pcVar3;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar7 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar7;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar7 = pcVar7 + -uVar4;
  }
  else {
    pcVar3 = (char *)(*DAT_1006c260)(0);
    uVar4 = 0xffffffff;
    do {
      pcVar7 = pcVar3;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar7 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar7;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar2 = -1;
    pcVar3 = acStack_800;
    do {
      pcVar8 = pcVar3;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      pcVar8 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar8;
    } while (cVar1 != '\0');
    pcVar3 = pcVar7 + -uVar4;
    pcVar7 = pcVar8 + -1;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar7 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      pcVar7 = pcVar7 + 1;
    }
    uVar4 = 0xffffffff;
    pcVar3 = &DAT_10046390;
    do {
      pcVar7 = pcVar3;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar7 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar7;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar2 = -1;
    pcVar3 = acStack_800;
    do {
      pcVar8 = pcVar3;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      pcVar8 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar8;
    } while (cVar1 != '\0');
    pcVar3 = pcVar7 + -uVar4;
    pcVar7 = pcVar8 + -1;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar7 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      pcVar7 = pcVar7 + 1;
    }
    pcVar3 = (char *)(*DAT_1006c264)();
    uVar4 = 0xffffffff;
    do {
      pcVar7 = pcVar3;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar7 = pcVar3 + 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar7;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar7 = pcVar7 + -uVar4;
  }
  iVar2 = -1;
  pcVar3 = acStack_800;
  do {
    pcVar8 = pcVar3;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar8 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar8;
  } while (cVar1 != '\0');
  pcVar3 = pcVar8 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar3 = pcVar3 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar3 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar3 = pcVar3 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar3 = acStack_800;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (0x96 < ~uVar4 - 1) {
    uStack_76a = 0;
  }
  uVar4 = 0xffffffff;
  pcVar3 = &DAT_10046478;
  do {
    pcVar7 = pcVar3;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar7 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar7;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar2 = -1;
  pcVar3 = acStack_800;
  do {
    pcVar8 = pcVar3;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar8 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar8;
  } while (cVar1 != '\0');
  pcVar3 = pcVar7 + -uVar4;
  pcVar7 = pcVar8 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    pcVar7 = pcVar7 + 1;
  }
  if (*(float *)(DAT_1006c114 + 0x14) != _DAT_1004410c) {
    iVar2 = *(int *)(param_1 + 0x54);
    if (DAT_1006c2e4 < *(float *)(iVar2 + 0xed0)) {
      lVar11 = __ftol();
      (*DAT_1006c1c8)(param_1,2,s_You_can_t_talk_for__d_more_secon_10046454,(int)lVar11);
      return;
    }
    iVar9 = *(int *)(iVar2 + 0xefc);
    lVar11 = __ftol();
    iVar6 = (int)lVar11;
    if (iVar6 < 0) {
      iVar6 = iVar6 + 10;
    }
    if ((*(float *)(iVar2 + 0xed4 + iVar6 * 4) != _DAT_1004410c) &&
       (DAT_1006c2e4 - *(float *)(iVar2 + 0xed4 + iVar6 * 4) < *(float *)(DAT_1006c188 + 0x14))) {
      *(float *)(iVar2 + 0xed0) = DAT_1006c2e4 + *(float *)(DAT_1006c2cc + 0x14);
      lVar11 = __ftol();
      (*DAT_1006c1c8)(param_1,3,s_Flood_protection__You_can_t_talk_10046420,(int)lVar11);
      return;
    }
    uVar4 = (iVar9 + 1U) % 10;
    *(uint *)(iVar2 + 0xefc) = uVar4;
    *(float *)(iVar2 + 0xed4 + uVar4 * 4) = DAT_1006c2e4;
  }
  if (*(float *)(DAT_1006c10c + 0x14) != _DAT_1004410c) {
    (*DAT_1006c1c8)(0,3,&DAT_10046140,acStack_800);
  }
  iVar2 = 1;
  if (0 < DAT_1006ca48) {
    iVar9 = 0x3d0;
    do {
      iVar6 = iVar9 + DAT_1006c2c4;
      if (((*(int *)(iVar9 + 0x58 + DAT_1006c2c4) != 0) && (*(int *)(iVar6 + 0x54) != 0)) &&
         ((param_2 == 0 || (uVar10 = FUN_10003d00(param_1,iVar6), (int)uVar10 != 0)))) {
        (*DAT_1006c1c8)(iVar6,3,&DAT_10046140,acStack_800);
      }
      iVar2 = iVar2 + 1;
      iVar9 = iVar9 + 0x3d0;
    } while (iVar2 <= DAT_1006ca48);
  }
  return;
}



/* FUN_10005990 @ 10005990 size 840 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __cdecl FUN_10005990(int param_1,int param_2)

{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float local_7c;
  float local_78;
  float local_74;
  float local_70 [13];
  int iStack_3c;
  undefined1 auStack_38 [56];
  
  if (*(int *)(param_1 + 0x104) == 2) {
    local_7c = *(float *)(param_1 + 0xe0) + *(float *)(param_1 + 0xd4);
    local_78 = *(float *)(param_1 + 0xe4) + *(float *)(param_1 + 0xd8);
    local_74 = *(float *)(param_1 + 0xe8) + *(float *)(param_1 + 0xdc);
    FUN_10038a20(&local_7c,0.5,&local_7c);
    pfVar1 = (float *)(*DAT_1006c1f0)(local_70,param_2 + 4,&DAT_10061c18,&DAT_10061c18,&local_7c,
                                      param_2,3);
    pfVar2 = local_70;
    for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pfVar2 = *pfVar1;
      pfVar1 = pfVar1 + 1;
      pfVar2 = pfVar2 + 1;
    }
    if (local_70[2] == (float)_DAT_10044120) {
      return true;
    }
    return iStack_3c == param_1;
  }
  pfVar1 = (float *)(param_1 + 4);
  iVar3 = param_2 + 4;
  pfVar2 = (float *)(*DAT_1006c1f0)(local_70,iVar3,&DAT_10061c18,&DAT_10061c18,pfVar1,param_2,3);
  pfVar5 = local_70;
  for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar5 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar5 = pfVar5 + 1;
  }
  if (local_70[2] == (float)_DAT_10044120) {
    return true;
  }
  local_7c = *pfVar1 + (float)_DAT_10044178;
  local_74 = *(float *)(param_1 + 0xc);
  local_78 = *(float *)(param_1 + 8) + (float)_DAT_10044178;
  pfVar2 = (float *)(*DAT_1006c1f0)(auStack_38,iVar3,&DAT_10061c18,&DAT_10061c18,&local_7c,param_2,3
                                   );
  pfVar5 = local_70;
  for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar5 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar5 = pfVar5 + 1;
  }
  if (local_70[2] == (float)_DAT_10044120) {
    return true;
  }
  local_7c = *pfVar1 + (float)_DAT_10044178;
  local_74 = *(float *)(param_1 + 0xc);
  local_78 = *(float *)(param_1 + 8) - (float)_DAT_10044178;
  pfVar2 = (float *)(*DAT_1006c1f0)(auStack_38,iVar3,&DAT_10061c18,&DAT_10061c18,&local_7c,param_2,3
                                   );
  pfVar5 = local_70;
  for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar5 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar5 = pfVar5 + 1;
  }
  if (local_70[2] == (float)_DAT_10044120) {
    return true;
  }
  local_7c = *pfVar1 - (float)_DAT_10044178;
  local_74 = *(float *)(param_1 + 0xc);
  local_78 = *(float *)(param_1 + 8) + (float)_DAT_10044178;
  pfVar2 = (float *)(*DAT_1006c1f0)(auStack_38,iVar3,&DAT_10061c18,&DAT_10061c18,&local_7c,param_2,3
                                   );
  pfVar5 = local_70;
  for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar5 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar5 = pfVar5 + 1;
  }
  if (local_70[2] == (float)_DAT_10044120) {
    return true;
  }
  local_7c = *pfVar1 - (float)_DAT_10044178;
  local_74 = *(float *)(param_1 + 0xc);
  local_78 = *(float *)(param_1 + 8) - (float)_DAT_10044178;
  pfVar1 = (float *)(*DAT_1006c1f0)(auStack_38,iVar3,&DAT_10061c18,&DAT_10061c18,&local_7c,param_2,3
                                   );
  pfVar2 = local_70;
  for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar2 = *pfVar1;
    pfVar1 = pfVar1 + 1;
    pfVar2 = pfVar2 + 1;
  }
  if (local_70[2] == (float)_DAT_10044120) {
    return true;
  }
  return false;
}



/* FUN_1002aa20 @ 1002aa20 size 825 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1002aa20(int param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  float10 fVar8;
  longlong lVar9;
  longlong lVar10;
  float local_8;
  float local_4;
  
  if (param_2 == 0.0) {
    return;
  }
  __ftol();
  fVar8 = FUN_10038850();
  fVar1 = (float)fVar8;
  fVar8 = FUN_10038850();
  fVar2 = (float)fVar8;
  fVar3 = *(float *)((int)param_2 + 4) - *(float *)(param_1 + 4);
  fVar4 = *(float *)((int)param_2 + 8) - *(float *)(param_1 + 8);
  if (fVar3 <= _DAT_100441b0) {
    local_8 = 180.0;
    if (_DAT_100443ac <= fVar3) {
      local_8 = -1.0;
    }
  }
  else {
    local_8 = 0.0;
  }
  if (_DAT_100443ac <= fVar4) {
    local_4 = 90.0;
    if (fVar4 <= _DAT_100441b0) {
      local_4 = -1.0;
    }
  }
  else {
    local_4 = 270.0;
  }
  fVar3 = local_4;
  if ((local_8 != _DAT_100441bc) && (local_4 != _DAT_100441bc)) {
    if (local_8 == _DAT_1004410c) {
      param_2 = 6.30584e-44;
      if (local_4 != _DAT_100442d4) {
        param_2 = 4.41409e-43;
      }
    }
    else {
      param_2 = 1.89175e-43;
      if (local_4 != _DAT_100442d4) {
        param_2 = 3.01279e-43;
      }
    }
    if (((float)(int)param_2 != fVar2) &&
       (iVar5 = FUN_1002a920(param_1,(float)(int)param_2,param_3), iVar5 != 0)) {
      return;
    }
  }
  uVar6 = _rand();
  if ((uVar6 & 1) == 0) {
    lVar9 = __ftol();
    uVar6 = (int)(uint)lVar9 >> 0x1f;
    lVar10 = __ftol();
    uVar7 = (int)(uint)lVar10 >> 0x1f;
    if ((int)(((uint)lVar9 ^ uVar6) - uVar6) <= (int)(((uint)lVar10 ^ uVar7) - uVar7))
    goto LAB_1002abe0;
  }
  local_4 = local_8;
  local_8 = fVar3;
LAB_1002abe0:
  if (((((local_8 == _DAT_100441bc) || (local_8 == fVar2)) ||
       (iVar5 = FUN_1002a920(param_1,local_8,param_3), iVar5 == 0)) &&
      (((local_4 == _DAT_100441bc || (local_4 == fVar2)) ||
       (iVar5 = FUN_1002a920(param_1,local_4,param_3), iVar5 == 0)))) &&
     ((fVar1 == _DAT_100441bc || (iVar5 = FUN_1002a920(param_1,fVar1,param_3), iVar5 == 0)))) {
    uVar6 = _rand();
    if ((uVar6 & 1) == 0) {
      param_2 = 315.0;
      do {
        if ((param_2 != fVar2) && (iVar5 = FUN_1002a920(param_1,param_2,param_3), iVar5 != 0)) {
          return;
        }
        param_2 = param_2 - _DAT_10044138;
      } while (_DAT_1004410c <= param_2);
    }
    else {
      param_2 = 0.0;
      do {
        if ((param_2 != fVar2) && (iVar5 = FUN_1002a920(param_1,param_2,param_3), iVar5 != 0)) {
          return;
        }
        param_2 = param_2 + _DAT_10044138;
      } while (param_2 <= _DAT_10044134);
    }
    if ((fVar2 == _DAT_100441bc) || (iVar5 = FUN_1002a920(param_1,fVar2,param_3), iVar5 == 0)) {
      *(float *)(param_1 + 0x1e8) = fVar1;
      iVar5 = FUN_1002a0c0(param_1);
      if (iVar5 == 0) {
        FUN_1002aa00(param_1);
      }
    }
  }
  return;
}



/* FUN_1000b650 @ 1000b650 size 824 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1000b650(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (*(int *)(*(int *)(param_2 + 0x54) + 0x6e4) < 300) {
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0x6e4) = 300;
  }
  if (*(int *)(*(int *)(param_2 + 0x54) + 0x6e8) < 200) {
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0x6e8) = 200;
  }
  if (*(int *)(*(int *)(param_2 + 0x54) + 0x6ec) < 100) {
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0x6ec) = 100;
  }
  if (*(int *)(*(int *)(param_2 + 0x54) + 0x6f0) < 100) {
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0x6f0) = 100;
  }
  if (*(int *)(*(int *)(param_2 + 0x54) + 0x6f4) < 10) {
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0x6f4) = 10;
  }
  if (*(int *)(*(int *)(param_2 + 0x54) + 0x6f8) < 300) {
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0x6f8) = 300;
  }
  if (*(int *)(*(int *)(param_2 + 0x54) + 0x6fc) < 100) {
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0x6fc) = 100;
  }
  if (*(int *)(*(int *)(param_2 + 0x54) + 0x708) < 5) {
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0x708) = 5;
  }
  if (*(int *)(*(int *)(param_2 + 0x54) + 0x70c) < 2) {
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0x70c) = 2;
  }
  puVar4 = FUN_1000b150((byte *)s_Bullets_10048a60);
  if (puVar4 != (undefined4 *)0x0) {
    iVar3 = (int)(puVar4 + -0x4011a4a) / 0x48;
    *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) =
         *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) + puVar4[0xc];
    iVar2 = *(int *)(param_2 + 0x54);
    if (*(int *)(iVar2 + 0x6e4) < *(int *)(iVar2 + 0x2e4 + iVar3 * 4)) {
      *(int *)(iVar2 + 0x2e4 + iVar3 * 4) = *(int *)(iVar2 + 0x6e4);
    }
  }
  puVar4 = FUN_1000b150((byte *)s_Shells_10048b88);
  if (puVar4 != (undefined4 *)0x0) {
    iVar3 = (int)(puVar4 + -0x4011a4a) / 0x48;
    *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) =
         *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) + puVar4[0xc];
    iVar2 = *(int *)(param_2 + 0x54);
    if (*(int *)(iVar2 + 0x6e8) < *(int *)(iVar2 + 0x2e4 + iVar3 * 4)) {
      *(int *)(iVar2 + 0x2e4 + iVar3 * 4) = *(int *)(iVar2 + 0x6e8);
    }
  }
  puVar4 = FUN_1000b150((byte *)s_Cells_1004662c);
  if (puVar4 != (undefined4 *)0x0) {
    iVar3 = (int)(puVar4 + -0x4011a4a) / 0x48;
    *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) =
         *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) + puVar4[0xc];
    iVar2 = *(int *)(param_2 + 0x54);
    if (*(int *)(iVar2 + 0x6f8) < *(int *)(iVar2 + 0x2e4 + iVar3 * 4)) {
      *(int *)(iVar2 + 0x2e4 + iVar3 * 4) = *(int *)(iVar2 + 0x6f8);
    }
  }
  puVar4 = FUN_1000b150((byte *)s_Grenades_10046384);
  if (puVar4 != (undefined4 *)0x0) {
    iVar3 = (int)(puVar4 + -0x4011a4a) / 0x48;
    *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) =
         *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) + puVar4[0xc];
    iVar2 = *(int *)(param_2 + 0x54);
    if (*(int *)(iVar2 + 0x6f0) < *(int *)(iVar2 + 0x2e4 + iVar3 * 4)) {
      *(int *)(iVar2 + 0x2e4 + iVar3 * 4) = *(int *)(iVar2 + 0x6f0);
    }
  }
  puVar4 = FUN_1000b150((byte *)s_Rockets_100485a0);
  if (puVar4 != (undefined4 *)0x0) {
    iVar3 = (int)(puVar4 + -0x4011a4a) / 0x48;
    *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) =
         *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) + puVar4[0xc];
    iVar2 = *(int *)(param_2 + 0x54);
    if (*(int *)(iVar2 + 0x6ec) < *(int *)(iVar2 + 0x2e4 + iVar3 * 4)) {
      *(int *)(iVar2 + 0x2e4 + iVar3 * 4) = *(int *)(iVar2 + 0x6ec);
    }
  }
  puVar4 = FUN_1000b150((byte *)s_Slugs_10048370);
  if (puVar4 != (undefined4 *)0x0) {
    iVar3 = (int)(puVar4 + -0x4011a4a) / 0x48;
    piVar1 = (int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4);
    *piVar1 = *piVar1 + puVar4[0xc];
    iVar2 = *(int *)(param_2 + 0x54);
    if (*(int *)(iVar2 + 0x6fc) < *(int *)(iVar2 + 0x2e4 + iVar3 * 4)) {
      *(int *)(iVar2 + 0x2e4 + iVar3 * 4) = *(int *)(iVar2 + 0x6fc);
    }
  }
  if (((*(uint *)(param_1 + 0x11c) & 0x10000) == 0) &&
     (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c)) {
    FUN_1000b210(param_1,(float)*(int *)(*(int *)(param_1 + 0x2cc) + 0x30));
  }
  return 1;
}



/* FUN_10001bc0 @ 10001bc0 size 817 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10001bc0(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  char *pcVar8;
  bool bVar9;
  float10 fVar10;
  float local_c;
  float local_8;
  float local_4;
  
  uVar2 = *(uint *)(param_1 + 0x35c);
  if ((uVar2 & 0x100) == 0) {
    if ((uVar2 & 0x1000) == 0) {
      bVar9 = false;
      iVar3 = DAT_1006c2e0 + -1;
      if ((DAT_1006c3d4 < iVar3) || ((*(byte *)(param_1 + 0x11c) & 1) != 0)) {
        if (DAT_1006c3dc < iVar3) {
          if (((*(int *)(param_1 + 0x25c) == 0) && (iVar3 <= DAT_1006c3e4)) &&
             ((*(byte *)(param_1 + 0x11c) & 1) == 0)) {
            bVar9 = true;
            iVar3 = DAT_1006c3e0;
          }
          else {
            iVar3 = DAT_1006c3cc;
            if (DAT_1006c3cc == 0) {
              return 0;
            }
          }
        }
        else {
          bVar9 = true;
          iVar3 = DAT_1006c3d8;
        }
      }
      else {
        iVar3 = DAT_1006c3d0;
        if (*(int *)(DAT_1006c3d0 + 0x25c) == *(int *)(param_1 + 0x25c)) {
          return 0;
        }
      }
      if (*(int *)(iVar3 + 0x58) != 0) {
        if (iVar3 == *(int *)(param_1 + 0x25c)) {
          return 1;
        }
        if (*(int *)(iVar3 + 0x54) == 0) {
          if ((*(byte *)(iVar3 + 0xb8) & 4) == 0) {
            if (!bVar9) {
              return 0;
            }
            bVar1 = *(byte *)(*(int *)(iVar3 + 0x100) + 0x108);
          }
          else {
            if (*(int *)(iVar3 + 0x25c) == 0) {
              return 0;
            }
            bVar1 = *(byte *)(*(int *)(iVar3 + 0x25c) + 0x108);
          }
        }
        else {
          bVar1 = *(byte *)(iVar3 + 0x108);
        }
        if ((bVar1 & 0x20) == 0) {
          if (bVar9) {
            if ((*(byte *)(param_1 + 0x11c) & 1) == 0) {
              iVar5 = (*DAT_1006c1fc)(param_1 + 4,iVar3 + 4);
              if (iVar5 == 0) {
                return 0;
              }
            }
            else {
              iVar5 = FUN_10001560(param_1,iVar3);
              if (iVar5 == 0) {
                return 0;
              }
            }
            local_c = *(float *)(iVar3 + 4) - *(float *)(param_1 + 4);
            local_8 = *(float *)(iVar3 + 8) - *(float *)(param_1 + 8);
            local_4 = *(float *)(iVar3 + 0xc) - *(float *)(param_1 + 0xc);
            fVar10 = FUN_100389f0(&local_c);
            if (fVar10 <= (float10)_DAT_10044110) {
              if ((*(int *)(iVar3 + 0xb0) == *(int *)(param_1 + 0xb0)) ||
                 (iVar5 = (*DAT_1006c204)(*(int *)(param_1 + 0xb0),*(int *)(iVar3 + 0xb0)),
                 iVar5 != 0)) {
                fVar10 = FUN_1001b160(&local_c);
                *(float *)(param_1 + 0x1e8) = (float)fVar10;
                FUN_1002a850(param_1);
                *(int *)(param_1 + 0x25c) = iVar3;
                *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) | 4;
                goto LAB_10001ebb;
              }
            }
          }
          else {
            iVar5 = FUN_100014e0(param_1,iVar3);
            if (((iVar5 != 3) && (5 < *(int *)(iVar3 + 0x2c4))) &&
               (iVar6 = FUN_10001560(param_1,iVar3), iVar6 != 0)) {
              if (iVar5 == 1) {
                if (((float)*(int *)(iVar3 + 0x230) < DAT_1006c2e4) &&
                   (iVar5 = FUN_10001600(param_1,iVar3), iVar5 == 0)) {
                  return 0;
                }
              }
              else if ((iVar5 == 2) && (iVar5 = FUN_10001600(param_1,iVar3), iVar5 == 0)) {
                return 0;
              }
              *(int *)(param_1 + 0x25c) = iVar3;
              pbVar7 = *(byte **)(iVar3 + 0x118);
              pcVar8 = s_player_noise_10046038;
              do {
                bVar1 = *pbVar7;
                bVar9 = bVar1 < (byte)*pcVar8;
                if (bVar1 != *pcVar8) {
LAB_10001da7:
                  iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
                  goto LAB_10001dac;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar7[1];
                bVar9 = bVar1 < (byte)pcVar8[1];
                if (bVar1 != pcVar8[1]) goto LAB_10001da7;
                pbVar7 = pbVar7 + 2;
                pcVar8 = pcVar8 + 2;
              } while (bVar1 != 0);
              iVar5 = 0;
LAB_10001dac:
              if (((iVar5 != 0) &&
                  (*(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) & 0xfffffffb,
                  *(int *)(iVar3 + 0x54) == 0)) &&
                 (iVar3 = *(int *)(iVar3 + 0x25c), *(int *)(param_1 + 0x25c) = iVar3,
                 *(int *)(iVar3 + 0x54) == 0)) {
                *(undefined4 *)(param_1 + 0x25c) = 0;
                return 0;
              }
LAB_10001ebb:
              FUN_10001ac0(param_1);
              if (((*(byte *)(param_1 + 0x35c) & 4) == 0) &&
                 (*(code **)(param_1 + 0x388) != (code *)0x0)) {
                (**(code **)(param_1 + 0x388))(param_1,*(undefined4 *)(param_1 + 0x25c));
              }
              return 1;
            }
          }
        }
      }
    }
  }
  else if ((uVar2 & 0x2000000) != 0) {
    if (((uVar2 & 0x1000000) != 0) && (iVar3 = FUN_10001730(param_1), iVar3 != 0)) {
      return 1;
    }
    uVar4 = FUN_10001910(param_1);
    return uVar4;
  }
  return 0;
}



/* FUN_1003c980 @ 1003c980 size 811 */

void __cdecl FUN_1003c980(uint *param_1,uint param_2)

{
  char *pcVar1;
  uint *puVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int local_10;
  
  uVar5 = param_1[4];
  iVar6 = *(int *)(param_2 - 4);
  piVar9 = (int *)(param_2 - 4);
  uVar10 = param_2 - param_1[3] >> 0xf;
  uVar7 = *(uint *)(param_2 - 8);
  local_10 = iVar6 + -1;
  piVar3 = (int *)(uVar10 * 0x204 + 0x144 + uVar5);
  uVar12 = *(uint *)(local_10 + (int)piVar9);
  if ((uVar12 & 1) == 0) {
    param_2 = ((int)uVar12 >> 4) - 1;
    if (0x3f < param_2) {
      param_2 = 0x3f;
    }
    if (*(int *)(iVar6 + 3 + (int)piVar9) == *(int *)(iVar6 + 7 + (int)piVar9)) {
      if (param_2 < 0x20) {
        pcVar1 = (char *)(param_2 + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)param_2 & 0x1f));
        puVar2 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        *puVar2 = *puVar2 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar11;
        }
      }
      else {
        pcVar1 = (char *)(param_2 + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)param_2 - 0x20 & 0x1f));
        puVar2 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        *puVar2 = *puVar2 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar11;
        }
      }
    }
    *(undefined4 *)(*(int *)(iVar6 + 7 + (int)piVar9) + 4) =
         *(undefined4 *)(iVar6 + 3 + (int)piVar9);
    local_10 = local_10 + uVar12;
    *(undefined4 *)(*(int *)(iVar6 + 3 + (int)piVar9) + 8) =
         *(undefined4 *)(iVar6 + 7 + (int)piVar9);
  }
  uVar12 = (local_10 >> 4) - 1;
  if (0x3f < uVar12) {
    uVar12 = 0x3f;
  }
  if ((uVar7 & 1) == 0) {
    piVar9 = (int *)((int)piVar9 - uVar7);
    param_2 = ((int)uVar7 >> 4) - 1;
    if (0x3f < param_2) {
      param_2 = 0x3f;
    }
    local_10 = local_10 + uVar7;
    uVar12 = (local_10 >> 4) - 1;
    if (0x3f < uVar12) {
      uVar12 = 0x3f;
    }
    if (param_2 != uVar12) {
      if (piVar9[1] == piVar9[2]) {
        if (param_2 < 0x20) {
          pcVar1 = (char *)(param_2 + 4 + uVar5);
          uVar11 = ~(0x80000000U >> ((byte)param_2 & 0x1f));
          puVar2 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar11;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *param_1 = *param_1 & uVar11;
          }
        }
        else {
          pcVar1 = (char *)(param_2 + 4 + uVar5);
          uVar11 = ~(0x80000000U >> ((byte)param_2 - 0x20 & 0x1f));
          puVar2 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar11;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            param_1[1] = param_1[1] & uVar11;
          }
        }
      }
      *(int *)(piVar9[2] + 4) = piVar9[1];
      *(int *)(piVar9[1] + 8) = piVar9[2];
    }
  }
  if (((uVar7 & 1) != 0) || (param_2 != uVar12)) {
    piVar9[1] = piVar3[uVar12 * 2 + 1];
    piVar9[2] = (int)(piVar3 + uVar12 * 2);
    (piVar3 + uVar12 * 2)[1] = (int)piVar9;
    *(int **)(piVar9[1] + 8) = piVar9;
    if (piVar9[1] == piVar9[2]) {
      cVar4 = *(char *)(uVar12 + 4 + uVar5);
      *(char *)(uVar12 + 4 + uVar5) = cVar4 + '\x01';
      bVar8 = (byte)uVar12;
      if (uVar12 < 0x20) {
        if (cVar4 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
        }
        puVar2 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        *puVar2 = *puVar2 | 0x80000000U >> (bVar8 & 0x1f);
      }
      else {
        if (cVar4 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
        }
        puVar2 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        *puVar2 = *puVar2 | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
      }
    }
  }
  *piVar9 = local_10;
  *(int *)(local_10 + -4 + (int)piVar9) = local_10;
  *piVar3 = *piVar3 + -1;
  uVar5 = DAT_1006dde8;
  puVar2 = DAT_1006ddf0;
  if ((*piVar3 == 0) && (uVar5 = uVar10, puVar2 = param_1, DAT_1006ddf0 != (uint *)0x0)) {
    VirtualFree((LPVOID)(DAT_1006dde8 * 0x8000 + DAT_1006ddf0[3]),0x8000,0x4000);
    DAT_1006ddf0[2] = DAT_1006ddf0[2] | 0x80000000U >> ((byte)DAT_1006dde8 & 0x1f);
    *(undefined4 *)(DAT_1006ddf0[4] + 0xc4 + DAT_1006dde8 * 4) = 0;
    *(char *)(DAT_1006ddf0[4] + 0x43) = *(char *)(DAT_1006ddf0[4] + 0x43) + -1;
    if (*(char *)(DAT_1006ddf0[4] + 0x43) == '\0') {
      DAT_1006ddf0[1] = DAT_1006ddf0[1] & 0xfffffffe;
    }
    puVar2 = param_1;
    if (DAT_1006ddf0[2] == 0xffffffff) {
      VirtualFree((LPVOID)DAT_1006ddf0[3],0,0x8000);
      HeapFree(DAT_1006ddfc,0,(LPVOID)DAT_1006ddf0[4]);
      FUN_10040150(DAT_1006ddf0,DAT_1006ddf0 + 5,
                   (DAT_1006ddf4 * 0x14 - (int)DAT_1006ddf0) + -0x14 + DAT_1006ddf8);
      DAT_1006ddf4 = DAT_1006ddf4 + -1;
      if (DAT_1006ddf0 < param_1) {
        param_1 = param_1 + -5;
      }
      DAT_1006ddec = DAT_1006ddf8;
      puVar2 = param_1;
    }
  }
  DAT_1006ddf0 = puVar2;
  DAT_1006dde8 = uVar5;
  return;
}



/* FUN_10012750 @ 10012750 size 809 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10012750(int param_1)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  undefined *puVar4;
  byte *pbVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  byte *pbVar10;
  int iVar11;
  char *pcVar12;
  bool bVar13;
  bool bVar14;
  float10 fVar15;
  longlong lVar16;
  undefined4 uVar17;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  bVar14 = false;
  if (*(int *)(param_1 + 0x220) < 1) {
    return;
  }
  if (*(byte **)(param_1 + 0x128) != (byte *)0x0) {
    bVar2 = false;
    uVar3 = FUN_1001ac00(0,300,*(byte **)(param_1 + 0x128));
    if (uVar3 != 0) {
      do {
        pbVar10 = *(byte **)(uVar3 + 0x118);
        pcVar12 = s_point_combat_100497cc;
        do {
          bVar1 = *pbVar10;
          bVar13 = bVar1 < (byte)*pcVar12;
          if (bVar1 != *pcVar12) {
LAB_100127c3:
            iVar11 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
            goto LAB_100127c8;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar10[1];
          bVar13 = bVar1 < (byte)pcVar12[1];
          if (bVar1 != pcVar12[1]) goto LAB_100127c3;
          pbVar10 = pbVar10 + 2;
          pcVar12 = pcVar12 + 2;
        } while (bVar1 != 0);
        iVar11 = 0;
LAB_100127c8:
        if (iVar11 == 0) {
          bVar14 = true;
          *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(param_1 + 0x128);
        }
        else {
          bVar2 = true;
        }
        uVar3 = FUN_1001ac00(uVar3,300,*(byte **)(param_1 + 0x128));
      } while (uVar3 != 0);
      if ((bVar2) && (*(int *)(param_1 + 0x140) != 0)) {
        iVar11 = param_1 + 4;
        puVar4 = FUN_1001b070();
        (*DAT_1006c1c4)(s__s_at__s_has_target_with_mixed_t_100497a4,*(undefined4 *)(param_1 + 0x118)
                        ,puVar4,iVar11);
      }
      if (bVar14) {
        *(undefined4 *)(param_1 + 0x128) = 0;
      }
    }
  }
  if (*(byte **)(param_1 + 0x140) != (byte *)0x0) {
    for (uVar3 = FUN_1001ac00(0,300,*(byte **)(param_1 + 0x140)); uVar3 != 0;
        uVar3 = FUN_1001ac00(uVar3,300,*(byte **)(param_1 + 0x140))) {
      pbVar10 = *(byte **)(uVar3 + 0x118);
      pcVar12 = s_point_combat_100497cc;
      pbVar5 = pbVar10;
      do {
        bVar1 = *pbVar5;
        bVar14 = bVar1 < (byte)*pcVar12;
        if (bVar1 != *pcVar12) {
LAB_1001289a:
          iVar11 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
          goto LAB_1001289f;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar5[1];
        bVar14 = bVar1 < (byte)pcVar12[1];
        if (bVar1 != pcVar12[1]) goto LAB_1001289a;
        pbVar5 = pbVar5 + 2;
        pcVar12 = pcVar12 + 2;
      } while (bVar1 != 0);
      iVar11 = 0;
LAB_1001289f:
      if (iVar11 != 0) {
        __ftol();
        lVar16 = __ftol();
        uVar6 = (undefined4)lVar16;
        lVar16 = __ftol();
        uVar7 = (undefined4)lVar16;
        uVar17 = *(undefined4 *)(param_1 + 0x140);
        lVar16 = __ftol();
        uVar8 = (undefined4)lVar16;
        lVar16 = __ftol();
        uVar9 = (undefined4)lVar16;
        lVar16 = __ftol();
        (*DAT_1006c1c4)(s__s_at___i__i__i__has_a_bad_comba_10049764,*(undefined4 *)(param_1 + 0x118)
                        ,(int)lVar16,uVar9,uVar8,uVar17,pbVar10,uVar7,uVar6);
      }
    }
  }
  if (*(byte **)(param_1 + 0x128) == (byte *)0x0) {
LAB_100129fe:
    *(undefined4 *)(param_1 + 0x390) = 0x4cbebc20;
    (**(code **)(param_1 + 0x368))(param_1);
  }
  else {
    uVar3 = FUN_1001ad80(*(byte **)(param_1 + 0x128));
    *(uint *)(param_1 + 0x1e0) = uVar3;
    *(uint *)(param_1 + 0x1dc) = uVar3;
    if (uVar3 == 0) {
      iVar11 = param_1 + 4;
      puVar4 = FUN_1001b070();
      (*DAT_1006c1c4)(s__s_can_t_find_target__s_at__s_10049744,*(undefined4 *)(param_1 + 0x118),
                      *(undefined4 *)(param_1 + 0x128),puVar4,iVar11);
      *(undefined4 *)(param_1 + 0x128) = 0;
      *(undefined4 *)(param_1 + 0x390) = 0x4cbebc20;
      (**(code **)(param_1 + 0x368))(param_1);
      goto LAB_10012a12;
    }
    pbVar10 = *(byte **)(uVar3 + 0x118);
    pcVar12 = s_path_corner_10049738;
    pbVar5 = pbVar10;
    do {
      bVar1 = *pbVar5;
      bVar14 = bVar1 < (byte)*pcVar12;
      if (bVar1 != *pcVar12) {
LAB_100129b3:
        iVar11 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
        goto LAB_100129ba;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar14 = bVar1 < (byte)pcVar12[1];
      if (bVar1 != pcVar12[1]) goto LAB_100129b3;
      pbVar5 = pbVar5 + 2;
      pcVar12 = pcVar12 + 2;
    } while (bVar1 != 0);
    iVar11 = 0;
LAB_100129ba:
    if (iVar11 != 0) {
      pcVar12 = s_target_actor_10049728;
      do {
        bVar1 = *pbVar10;
        bVar14 = bVar1 < (byte)*pcVar12;
        if (bVar1 != *pcVar12) {
LAB_100129e9:
          iVar11 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
          goto LAB_100129ee;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar10[1];
        bVar14 = bVar1 < (byte)pcVar12[1];
        if (bVar1 != pcVar12[1]) goto LAB_100129e9;
        pbVar10 = pbVar10 + 2;
        pcVar12 = pcVar12 + 2;
      } while (bVar1 != 0);
      iVar11 = 0;
LAB_100129ee:
      if (iVar11 != 0) {
        *(undefined4 *)(param_1 + 0x1e0) = 0;
        *(undefined4 *)(param_1 + 0x1dc) = 0;
        goto LAB_100129fe;
      }
    }
    fStack_c = *(float *)(uVar3 + 4) - *(float *)(param_1 + 4);
    fStack_8 = *(float *)(uVar3 + 8) - *(float *)(param_1 + 8);
    fStack_4 = *(float *)(uVar3 + 0xc) - *(float *)(param_1 + 0xc);
    fVar15 = FUN_1001b160(&fStack_c);
    *(float *)(param_1 + 0x14) = (float)fVar15;
    *(float *)(param_1 + 0x1e8) = (float)fVar15;
    (**(code **)(param_1 + 0x374))(param_1);
    *(undefined4 *)(param_1 + 0x128) = 0;
  }
LAB_10012a12:
  *(code **)(param_1 + 500) = FUN_100123c0;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  return;
}



/* FUN_10011e50 @ 10011e50 size 794 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10011e50(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  longlong lVar4;
  char *pcVar5;
  
  if (0 < *(int *)(param_1 + 0x220)) {
    if ((*(byte *)(param_1 + 0x108) & 2) == 0) {
      if (*(int *)(param_1 + 0x2a8) < 3) {
        *(float *)(param_1 + 0x194) = DAT_1006c2e4 + _DAT_10044244;
      }
      else if ((*(float *)(param_1 + 0x194) < DAT_1006c2e4) &&
              (*(float *)(param_1 + 0x210) < DAT_1006c2e4)) {
        FUN_1003900b((double)(DAT_1006c2e4 - *(float *)(param_1 + 0x194)));
        lVar4 = __ftol();
        iVar1 = (int)lVar4;
        if (0xf < iVar1) {
          iVar1 = 0xf;
        }
LAB_10011f88:
        FUN_100060d0(param_1,DAT_1006c2c4,DAT_1006c2c4,(float *)&DAT_10061c18,(float *)(param_1 + 4)
                     ,&DAT_10061c18,iVar1,0,2,0x11);
        *(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_10044104;
      }
    }
    else if (*(int *)(param_1 + 0x2a8) < 1) {
      if ((*(float *)(param_1 + 0x194) < DAT_1006c2e4) &&
         (*(float *)(param_1 + 0x210) < DAT_1006c2e4)) {
        FUN_1003900b((double)(DAT_1006c2e4 - *(float *)(param_1 + 0x194)));
        lVar4 = __ftol();
        iVar1 = (int)lVar4;
        if (0xf < iVar1) {
          iVar1 = 0xf;
        }
        goto LAB_10011f88;
      }
    }
    else {
      *(float *)(param_1 + 0x194) = DAT_1006c2e4 + _DAT_10044240;
    }
  }
  if (*(int *)(param_1 + 0x2a8) == 0) {
    if ((*(byte *)(param_1 + 0x108) & 8) == 0) {
      return;
    }
    uVar2 = (*DAT_1006c1e4)(s_player_watr_out_wav_100496f8,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_1,4,uVar2);
    *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) & 0xfffffff7;
    return;
  }
  if ((((*(byte *)(param_1 + 0x2a4) & 8) != 0) && ((*(byte *)(param_1 + 0x108) & 0x80) == 0)) &&
     (*(float *)(param_1 + 0x214) < DAT_1006c2e4)) {
    *(float *)(param_1 + 0x214) = DAT_1006c2e4 + (float)_DAT_10044198;
    FUN_100060d0(param_1,DAT_1006c2c4,DAT_1006c2c4,(float *)&DAT_10061c18,(float *)(param_1 + 4),
                 &DAT_10061c18,*(int *)(param_1 + 0x2a8) * 10,0,0,0x13);
  }
  if ((((*(byte *)(param_1 + 0x2a4) & 0x10) != 0) && ((*(byte *)(param_1 + 0x108) & 0x40) == 0)) &&
     (*(float *)(param_1 + 0x214) < DAT_1006c2e4)) {
    *(float *)(param_1 + 0x214) = DAT_1006c2e4 + _DAT_10044104;
    FUN_100060d0(param_1,DAT_1006c2c4,DAT_1006c2c4,(float *)&DAT_10061c18,(float *)(param_1 + 4),
                 &DAT_10061c18,*(int *)(param_1 + 0x2a8) << 2,0,0,0x12);
  }
  if ((*(byte *)(param_1 + 0x108) & 8) != 0) {
    return;
  }
  if ((*(byte *)(param_1 + 0xb8) & 2) == 0) {
    uVar3 = *(uint *)(param_1 + 0x2a4);
    if ((uVar3 & 8) == 0) {
      if (((uVar3 & 0x10) == 0) && ((uVar3 & 0x20) == 0)) goto LAB_10012150;
      pcVar5 = s_player_watr_in_wav_100496bc;
    }
    else {
      uVar3 = _rand();
      if ((float)_DAT_10044140 < (float)(uVar3 & 0x7fff) * _DAT_10044108) {
        pcVar5 = s_player_lava2_wav_100496d0;
      }
      else {
        pcVar5 = s_player_lava1_wav_100496e4;
      }
    }
    uVar2 = (*DAT_1006c1e4)(pcVar5,0x3f800000,0x3f800000);
    (*DAT_1006c1d0)(param_1,4,uVar2);
  }
LAB_10012150:
  *(undefined4 *)(param_1 + 0x214) = 0;
  *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) | 8;
  return;
}



/* FUN_10034d80 @ 10034d80 size 790 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10034d80(float param_1)

{
  float *pfVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float10 extraout_ST0;
  longlong lVar7;
  
  DAT_10061394 = param_1;
  DAT_100613bc = *(int *)((int)param_1 + 0x54);
  if (*(int *)(DAT_100613bc + 0xf0c) == 0) {
    iVar4 = 10;
    do {
      iVar5 = DAT_100613bc;
      lVar7 = __ftol();
      *(short *)(iVar4 + -6 + iVar5) = (short)lVar7;
      lVar7 = __ftol();
      iVar5 = iVar4 + 2;
      *(short *)(iVar4 + DAT_100613bc) = (short)lVar7;
      iVar4 = iVar5;
    } while (iVar5 < 0x10);
  }
  if (_DAT_1006c3a8 != _DAT_1004410c) {
    *(undefined4 *)(DAT_100613bc + 0x6c) = 0;
    *(undefined4 *)(DAT_100613bc + 0x70) = 0x42b40000;
    FUN_10032ca0((int)param_1);
    return;
  }
  FUN_10038700((float *)(*(int *)((int)param_1 + 0x54) + 0xe64),(float *)&DAT_10061398,
               (float *)&DAT_100613a4,(float *)&DAT_100613b0);
  FUN_10034310();
  iVar4 = *(int *)((int)param_1 + 0x54);
  fVar2 = *(float *)(iVar4 + 0xe64);
  if (_DAT_100442c4 < *(float *)(iVar4 + 0xe64)) {
    fVar2 = fVar2 - _DAT_100442b0;
  }
  pfVar1 = (float *)((int)param_1 + 0x178);
  *(float *)((int)param_1 + 0x10) = fVar2 * _DAT_10044444;
  uVar3 = *(undefined4 *)(iVar4 + 0xe68);
  *(undefined4 *)((int)param_1 + 0x18) = 0;
  *(undefined4 *)((int)param_1 + 0x14) = uVar3;
  fVar6 = FUN_10033340((float *)((int)param_1 + 0x10),pfVar1);
  *(float *)((int)param_1 + 0x18) = (float)(fVar6 * (float10)_DAT_100441a8);
  _DAT_10062080 =
       SQRT(*(float *)((int)param_1 + 0x17c) * *(float *)((int)param_1 + 0x17c) + *pfVar1 * *pfVar1)
  ;
  if (_DAT_1004414c <= _DAT_10062080) {
    if (*(int *)((int)param_1 + 0x268) != 0) {
      if (_DAT_10062080 <= _DAT_10044440) {
        _DAT_10062084 = 0.125;
        if (_DAT_10062080 <= _DAT_10044130) {
          _DAT_10062084 = 0.0625;
        }
      }
      else {
        _DAT_10062084 = 0.25;
      }
    }
  }
  else {
    _DAT_10062084 = 0.0;
    *(undefined4 *)(DAT_100613bc + 0xe70) = 0;
  }
  *(float *)(DAT_100613bc + 0xe70) = _DAT_10062084 + *(float *)(DAT_100613bc + 0xe70);
  lVar7 = __ftol();
  DAT_10062088 = (undefined4)lVar7;
  fVar6 = (float10)fsin(extraout_ST0 * (float10)_DAT_10044438);
  _DAT_1006208c = (float)ABS(fVar6);
  FUN_10034110((uint)param_1);
  FUN_100333c0(param_1);
  if (*(int *)(*(int *)((int)param_1 + 0x54) + 0xf0c) == 0) {
    FUN_10033820((int)param_1);
    FUN_10033b10((int)param_1);
  }
  FUN_10033d00((int)param_1);
  FUN_10032ca0((int)param_1);
  FUN_10034a40((int)param_1);
  FUN_10034930((int)param_1);
  FUN_10034a90((int)param_1);
  FUN_10034bf0((int)param_1);
  if (*(int *)(*(int *)((int)param_1 + 0x54) + 0xf0c) != 0) {
    FUN_10002e20((int)param_1);
    FUN_10002ca0((int)param_1);
  }
  *(float *)(*(int *)((int)param_1 + 0x54) + 0xe80) = *pfVar1;
  *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xe84) = *(undefined4 *)((int)param_1 + 0x17c);
  *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xe88) = *(undefined4 *)((int)param_1 + 0x180);
  *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xe74) =
       *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0x1c);
  *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xe78) =
       *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0x20);
  *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xe7c) =
       *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0x24);
  *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xe38) = 0;
  *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xe34) = 0;
  *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xe30) = 0;
  *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xe2c) = 0;
  *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xe28) = 0;
  *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xe24) = 0;
  if ((*(int *)(*(int *)((int)param_1 + 0x54) + 0xdd8) != 0) && (((byte)DAT_1006c2e0 & 0x1f) == 0))
  {
    FUN_100327c0((int)param_1,*(int *)((int)param_1 + 0x25c));
    (*DAT_1006c21c)(param_1,0);
  }
  return;
}



/* FUN_10013e60 @ 10013e60 size 785 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10013e60(float *param_1)

{
  float fVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  bool bVar7;
  
  bVar2 = false;
  if (param_1[0x9a] == 0.0) {
    FUN_10011c90((int)param_1);
  }
  fVar1 = param_1[0x9a];
  FUN_10012d20((int)param_1);
  bVar7 = fVar1 != 0.0;
  if (((param_1[0x61] != _DAT_1004410c) || (param_1[0x62] != _DAT_1004410c)) ||
     (param_1[99] != _DAT_1004410c)) {
    FUN_10013df0((int)param_1);
  }
  if ((((!bVar7) && (((uint)param_1[0x42] & 1) == 0)) &&
      ((((uint)param_1[0x42] & 2) == 0 || ((int)param_1[0xaa] < 3)))) &&
     (bVar2 = param_1[0x60] < *(float *)(DAT_1006c420 + 0x14) * (float)_DAT_10044258,
     param_1[0xaa] == 0.0)) {
    FUN_100132f0((int)param_1);
  }
  fVar1 = param_1[0x42];
  if ((((uint)fVar1 & 1) != 0) && (param_1[0x60] != _DAT_1004410c)) {
    fVar3 = ABS(param_1[0x60]);
    fVar4 = fVar3;
    if (fVar3 < _DAT_10044130) {
      fVar4 = _DAT_10044130;
    }
    fVar4 = fVar3 - fVar4 * (float)_DAT_10044198;
    if (fVar4 < _DAT_1004410c) {
      fVar4 = _DAT_1004410c;
    }
    param_1[0x60] = (fVar4 / fVar3) * param_1[0x60];
  }
  if ((((uint)fVar1 & 2) != 0) && (param_1[0x60] != _DAT_1004410c)) {
    fVar3 = ABS(param_1[0x60]);
    fVar4 = fVar3;
    if (fVar3 < _DAT_10044130) {
      fVar4 = _DAT_10044130;
    }
    fVar4 = fVar3 - fVar4 * (float)(int)param_1[0xaa] * (float)_DAT_10044168;
    if (fVar4 < _DAT_1004410c) {
      fVar4 = _DAT_1004410c;
    }
    param_1[0x60] = (fVar4 / fVar3) * param_1[0x60];
  }
  if (((param_1[0x60] != _DAT_1004410c) || (param_1[0x5f] != _DAT_1004410c)) ||
     (param_1[0x5e] != _DAT_1004410c)) {
    if ((((bVar7) || (((uint)fVar1 & 3) != 0)) &&
        ((_DAT_10044268 < (double)(int)param_1[0x88] ||
         (iVar5 = FUN_1002a0c0((int)param_1), iVar5 != 0)))) &&
       (fVar1 = SQRT(param_1[0x5f] * param_1[0x5f] + param_1[0x5e] * param_1[0x5e]),
       fVar1 != _DAT_1004410c)) {
      fVar3 = fVar1;
      if (fVar1 < _DAT_10044130) {
        fVar3 = _DAT_10044130;
      }
      fVar3 = fVar1 - fVar3 * (float)_DAT_10044278;
      if (fVar3 < _DAT_1004410c) {
        fVar3 = _DAT_1004410c;
      }
      param_1[0x5e] = (fVar3 / fVar1) * param_1[0x5e];
      param_1[0x5f] = (fVar3 / fVar1) * param_1[0x5f];
    }
    FUN_10012f00(param_1,0.1,(-(uint)(((uint)param_1[0x2e] & 4) != 0) & 0x2020000) + 3);
    (*DAT_1006c208)(param_1);
    FUN_1001b480();
    if (param_1[0x16] == 0.0) {
      return;
    }
    if (((param_1[0x9a] != 0.0) && (!bVar7)) && (bVar2)) {
      uVar6 = (*DAT_1006c1e4)(s_world_land_wav_10049858,0x3f800000,0x3f800000,0);
      (*DAT_1006c1d0)(param_1,0,uVar6);
    }
  }
  FUN_10012d80((int)param_1);
  return;
}



/* FUN_1003ccab @ 1003ccab size 777 */

int * __cdecl FUN_1003ccab(uint *param_1)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  int *piVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  int iVar14;
  uint local_10;
  uint local_c;
  int local_8;
  
  puVar8 = DAT_1006ddf8 + DAT_1006ddf4 * 5;
  uVar6 = (int)param_1 + 0x17U & 0xfffffff0;
  iVar7 = ((int)((int)param_1 + 0x17U) >> 4) + -1;
  bVar5 = (byte)iVar7;
  param_1 = DAT_1006ddec;
  if (iVar7 < 0x20) {
    local_10 = 0xffffffff >> (bVar5 & 0x1f);
    local_c = 0xffffffff;
  }
  else {
    local_c = 0xffffffff >> (bVar5 - 0x20 & 0x1f);
    local_10 = 0;
  }
  for (; (param_1 < puVar8 && ((param_1[1] & local_c) == 0 && (*param_1 & local_10) == 0));
      param_1 = param_1 + 5) {
  }
  puVar11 = DAT_1006ddf8;
  if (param_1 == puVar8) {
    for (; (puVar11 < DAT_1006ddec && ((puVar11[1] & local_c) == 0 && (*puVar11 & local_10) == 0));
        puVar11 = puVar11 + 5) {
    }
    param_1 = puVar11;
    if (puVar11 == DAT_1006ddec) {
      for (; (puVar11 < puVar8 && (puVar11[2] == 0)); puVar11 = puVar11 + 5) {
      }
      puVar12 = DAT_1006ddf8;
      param_1 = puVar11;
      if (puVar11 == puVar8) {
        for (; (puVar12 < DAT_1006ddec && (puVar12[2] == 0)); puVar12 = puVar12 + 5) {
        }
        param_1 = puVar12;
        if ((puVar12 == DAT_1006ddec) && (param_1 = FUN_1003cfb4(), param_1 == (uint *)0x0)) {
          return (int *)0x0;
        }
      }
      iVar7 = FUN_1003d065((int)param_1);
      *(int *)param_1[4] = iVar7;
      if (*(int *)param_1[4] == -1) {
        return (int *)0x0;
      }
    }
  }
  piVar4 = (int *)param_1[4];
  local_8 = *piVar4;
  if ((local_8 == -1) ||
     ((piVar4[local_8 + 0x31] & local_c) == 0 && (piVar4[local_8 + 0x11] & local_10) == 0)) {
    local_8 = 0;
    puVar8 = (uint *)(piVar4 + 0x11);
    if ((piVar4[0x31] & local_c) == 0 && (piVar4[0x11] & local_10) == 0) {
      do {
        puVar11 = puVar8 + 0x21;
        local_8 = local_8 + 1;
        puVar8 = puVar8 + 1;
      } while ((*puVar11 & local_c) == 0 && (local_10 & *puVar8) == 0);
    }
  }
  iVar7 = 0;
  piVar2 = piVar4 + local_8 * 0x81 + 0x51;
  local_10 = piVar4[local_8 + 0x11] & local_10;
  if (local_10 == 0) {
    local_10 = piVar4[local_8 + 0x31] & local_c;
    iVar7 = 0x20;
  }
  for (; -1 < (int)local_10; local_10 = local_10 << 1) {
    iVar7 = iVar7 + 1;
  }
  piVar10 = (int *)piVar2[iVar7 * 2 + 1];
  iVar9 = *piVar10 - uVar6;
  iVar14 = (iVar9 >> 4) + -1;
  if (0x3f < iVar14) {
    iVar14 = 0x3f;
  }
  DAT_1006ddec = param_1;
  if (iVar14 != iVar7) {
    if (piVar10[1] == piVar10[2]) {
      if (iVar7 < 0x20) {
        pcVar1 = (char *)((int)piVar4 + iVar7 + 4);
        uVar13 = ~(0x80000000U >> ((byte)iVar7 & 0x1f));
        piVar4[local_8 + 0x11] = uVar13 & piVar4[local_8 + 0x11];
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar13;
        }
      }
      else {
        pcVar1 = (char *)((int)piVar4 + iVar7 + 4);
        uVar13 = ~(0x80000000U >> ((byte)iVar7 - 0x20 & 0x1f));
        piVar4[local_8 + 0x31] = piVar4[local_8 + 0x31] & uVar13;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar13;
        }
      }
    }
    *(int *)(piVar10[2] + 4) = piVar10[1];
    *(int *)(piVar10[1] + 8) = piVar10[2];
    if (iVar9 == 0) goto LAB_1003cf71;
    piVar10[1] = piVar2[iVar14 * 2 + 1];
    piVar10[2] = (int)(piVar2 + iVar14 * 2);
    (piVar2 + iVar14 * 2)[1] = (int)piVar10;
    *(int **)(piVar10[1] + 8) = piVar10;
    if (piVar10[1] == piVar10[2]) {
      cVar3 = *(char *)(iVar14 + 4 + (int)piVar4);
      bVar5 = (byte)iVar14;
      if (iVar14 < 0x20) {
        *(char *)(iVar14 + 4 + (int)piVar4) = cVar3 + '\x01';
        if (cVar3 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar5 & 0x1f);
        }
        piVar4[local_8 + 0x11] = piVar4[local_8 + 0x11] | 0x80000000U >> (bVar5 & 0x1f);
      }
      else {
        *(char *)(iVar14 + 4 + (int)piVar4) = cVar3 + '\x01';
        if (cVar3 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar5 - 0x20 & 0x1f);
        }
        piVar4[local_8 + 0x31] = piVar4[local_8 + 0x31] | 0x80000000U >> (bVar5 - 0x20 & 0x1f);
      }
    }
  }
  if (iVar9 != 0) {
    *piVar10 = iVar9;
    *(int *)(iVar9 + -4 + (int)piVar10) = iVar9;
  }
LAB_1003cf71:
  piVar10 = (int *)((int)piVar10 + iVar9);
  *piVar10 = uVar6 + 1;
  *(uint *)((int)piVar10 + (uVar6 - 4)) = uVar6 + 1;
  iVar7 = *piVar2;
  *piVar2 = iVar7 + 1;
  if (((iVar7 == 0) && (param_1 == DAT_1006ddf0)) && (local_8 == DAT_1006dde8)) {
    DAT_1006ddf0 = (uint *)0x0;
  }
  *piVar4 = local_8;
  return piVar10 + 1;
}



/* FUN_10030d60 @ 10030d60 size 774 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10030d60(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  int *piVar7;
  byte *pbVar8;
  int iVar9;
  bool bVar10;
  char *pcVar11;
  
  iVar2 = param_1;
  iVar6 = *(int *)(param_1 + 0x54);
  if (*(int *)(iVar6 + 0x72c) == 0) {
    pbVar3 = FUN_10038bb0((byte *)(iVar6 + 0xbc),(byte *)s_password_1004a370);
    pbVar4 = *(byte **)(DAT_1006c2c8 + 4);
    if (*pbVar4 == 0) goto LAB_10030f91;
    pbVar8 = &DAT_1005f3b4;
    pbVar5 = pbVar4;
    do {
      bVar1 = *pbVar5;
      bVar10 = bVar1 < *pbVar8;
      if (bVar1 != *pbVar8) {
LAB_10030f2a:
        iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        goto LAB_10030f2f;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar10 = bVar1 < pbVar8[1];
      if (bVar1 != pbVar8[1]) goto LAB_10030f2a;
      pbVar5 = pbVar5 + 2;
      pbVar8 = pbVar8 + 2;
    } while (bVar1 != 0);
    iVar6 = 0;
LAB_10030f2f:
    if (iVar6 == 0) goto LAB_10030f91;
    do {
      bVar1 = *pbVar4;
      bVar10 = bVar1 < *pbVar3;
      if (bVar1 != *pbVar3) {
LAB_10030f5b:
        iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        goto LAB_10030f60;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar10 = bVar1 < pbVar3[1];
      if (bVar1 != pbVar3[1]) goto LAB_10030f5b;
      pbVar4 = pbVar4 + 2;
      pbVar3 = pbVar3 + 2;
    } while (bVar1 != 0);
    iVar6 = 0;
LAB_10030f60:
    if (iVar6 == 0) goto LAB_10030f91;
    (*DAT_1006c1c8)(param_1,2,s_Password_incorrect__1005f34c);
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x72c) = 1;
    (*DAT_1006c224)(0xb);
    pcVar11 = s_spectator_1_1005f33c;
    goto LAB_10030e2c;
  }
  pbVar3 = FUN_10038bb0((byte *)(iVar6 + 0xbc),(byte *)s_spectator_1005f3bc);
  pbVar4 = *(byte **)(DAT_1006c108 + 4);
  if (*pbVar4 == 0) {
LAB_10030e43:
    iVar9 = 0;
    iVar6 = 1;
    param_1 = 0;
    if (_DAT_10044104 <= *(float *)(DAT_1006ca60 + 0x14)) {
      piVar7 = (int *)(DAT_1006c2c4 + 0x424);
      do {
        if ((piVar7[1] != 0) && (*(int *)(*piVar7 + 0x72c) != 0)) {
          iVar9 = iVar9 + 1;
        }
        iVar6 = iVar6 + 1;
        piVar7 = piVar7 + 0xf4;
        param_1 = iVar9;
      } while ((float)iVar6 <= *(float *)(DAT_1006ca60 + 0x14));
    }
    if ((float)param_1 < *(float *)(DAT_1006c410 + 0x14)) {
LAB_10030f91:
      *(undefined4 *)(*(int *)(iVar2 + 0x54) + 0x720) = 0;
      *(undefined4 *)(*(int *)(iVar2 + 0x54) + 0xda8) = 0;
      *(uint *)(iVar2 + 0xb8) = *(uint *)(iVar2 + 0xb8) & 0xfffffffe;
      FUN_10031070(iVar2);
      if (*(int *)(*(int *)(iVar2 + 0x54) + 0x72c) == 0) {
        (*DAT_1006c224)(1);
        (*DAT_1006c228)((iVar2 - DAT_1006c2c4) / 0x3d0);
        (*DAT_1006c224)(9);
        (*DAT_1006c218)(iVar2 + 4,2);
        *(undefined1 *)(*(int *)(iVar2 + 0x54) + 0x10) = 0x20;
        *(undefined1 *)(*(int *)(iVar2 + 0x54) + 0x11) = 0xe;
      }
      *(undefined4 *)(*(int *)(iVar2 + 0x54) + 0xf00) = DAT_1006c2e4;
      iVar6 = *(int *)(iVar2 + 0x54);
      if (*(int *)(iVar6 + 0x72c) == 0) {
        (*DAT_1006c1c0)(2,s__s_joined_the_game_1005f308,iVar6 + 700);
        return;
      }
      (*DAT_1006c1c0)(2,s__s_has_moved_to_the_sidelines_1005f31c,iVar6 + 700);
      return;
    }
    (*DAT_1006c1c8)(iVar2,2,s_Server_spectator_limit_is_full__1005f364);
    *(undefined4 *)(*(int *)(iVar2 + 0x54) + 0x72c) = 0;
  }
  else {
    pbVar8 = &DAT_1005f3b4;
    pbVar5 = pbVar4;
    do {
      bVar1 = *pbVar5;
      bVar10 = bVar1 < *pbVar8;
      if (bVar1 != *pbVar8) {
LAB_10030dca:
        iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        goto LAB_10030dcf;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar10 = bVar1 < pbVar8[1];
      if (bVar1 != pbVar8[1]) goto LAB_10030dca;
      pbVar5 = pbVar5 + 2;
      pbVar8 = pbVar8 + 2;
    } while (bVar1 != 0);
    iVar6 = 0;
LAB_10030dcf:
    if (iVar6 == 0) goto LAB_10030e43;
    do {
      bVar1 = *pbVar4;
      bVar10 = bVar1 < *pbVar3;
      if (bVar1 != *pbVar3) {
LAB_10030dfb:
        iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        goto LAB_10030e00;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar10 = bVar1 < pbVar3[1];
      if (bVar1 != pbVar3[1]) goto LAB_10030dfb;
      pbVar4 = pbVar4 + 2;
      pbVar3 = pbVar3 + 2;
    } while (bVar1 != 0);
    iVar6 = 0;
LAB_10030e00:
    if (iVar6 == 0) goto LAB_10030e43;
    (*DAT_1006c1c8)(param_1,2,s_Spectator_password_incorrect__1005f394);
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x72c) = 0;
  }
  (*DAT_1006c224)(0xb);
  pcVar11 = s_spectator_0_1005f384;
LAB_10030e2c:
  (*DAT_1006c234)(pcVar11);
  (*DAT_1006c21c)(iVar2,1);
  return;
}



/* FUN_10030160 @ 10030160 size 768 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10030160(float param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  *(undefined4 *)((int)param_1 + 0x18c) = 0;
  *(undefined4 *)((int)param_1 + 0x188) = 0;
  *(undefined4 *)((int)param_1 + 0x184) = 0;
  *(undefined4 *)((int)param_1 + 0x240) = 1;
  *(undefined4 *)((int)param_1 + 0x104) = 7;
  *(undefined4 *)((int)param_1 + 0x2c) = 0;
  *(undefined4 *)((int)param_1 + 0x10) = 0;
  *(undefined4 *)((int)param_1 + 0x18) = 0;
  *(undefined4 *)((int)param_1 + 0x4c) = 0;
  *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xec8) = 0;
  *(undefined4 *)((int)param_1 + 0xd0) = 0xc1000000;
  *(uint *)((int)param_1 + 0xb8) = *(uint *)((int)param_1 + 0xb8) | 2;
  if (*(int *)((int)param_1 + 0x22c) == 0) {
    *(float *)(*(int *)((int)param_1 + 0x54) + 0xf00) = DAT_1006c2e4 + (float)_DAT_10044120;
    FUN_10030060((int)param_1,param_2,param_3);
    **(undefined4 **)((int)param_1 + 0x54) = 2;
    FUN_1002f8f0((int)param_1,param_2,param_3);
    FUN_1002fe80(param_1);
    if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
      FUN_10032c20((int)param_1);
    }
    iVar5 = 0;
    if (0 < DAT_1006ca54) {
      iVar4 = 0x2e4;
      pbVar6 = &DAT_10046960;
      do {
        if ((*(float *)(DAT_1006c42c + 0x14) != _DAT_1004410c) && ((*pbVar6 & 0x10) != 0)) {
          *(undefined4 *)(iVar4 + 0x674 + *(int *)((int)param_1 + 0x54)) =
               *(undefined4 *)(iVar4 + *(int *)((int)param_1 + 0x54));
        }
        iVar5 = iVar5 + 1;
        pbVar6 = pbVar6 + 0x48;
        *(undefined4 *)(*(int *)((int)param_1 + 0x54) + iVar4) = 0;
        iVar4 = iVar4 + 4;
      } while (iVar5 < DAT_1006ca54);
    }
  }
  *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xeac) = 0;
  *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xeb0) = 0;
  *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xeb4) = 0;
  *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xeb8) = 0;
  *(uint *)((int)param_1 + 0x108) = *(uint *)((int)param_1 + 0x108) & 0xffffefff;
  if (DAT_1006c104 == 0x23) {
    (*DAT_1006c224)(1);
    (*DAT_1006c228)(((int)param_1 - DAT_1006c2c4) / 0x3d0);
    (*DAT_1006c224)(0x8a);
    (*DAT_1006c218)((int)param_1 + 4,2);
    *(undefined4 *)((int)param_1 + 0x50) = 6;
    *(undefined4 *)((int)param_1 + 0x240) = 0;
    FUN_1000e0e0((int)param_1,param_4);
  }
  else if (*(int *)((int)param_1 + 0x220) < -0x28) {
    uVar1 = (*DAT_1006c1e4)(s_misc_udeath_wav_100493f8,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_1,4,uVar1);
    iVar5 = 4;
    do {
      FUN_1000dd30(param_1,s_models_objects_gibs_sm_meat_tris_100493d0,param_4,0);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    FUN_1000e0e0((int)param_1,param_4);
    *(undefined4 *)((int)param_1 + 0x240) = 0;
  }
  else if (*(int *)((int)param_1 + 0x22c) == 0) {
    DAT_10061388 = (DAT_10061388 + 1) % 3;
    *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xea0) = 5;
    iVar5 = *(int *)((int)param_1 + 0x54);
    if ((*(byte *)(iVar5 + 0x10) & 1) == 0) {
      if (DAT_10061388 == 0) {
        *(undefined4 *)((int)param_1 + 0x38) = 0xb1;
        *(undefined4 *)(iVar5 + 0xe9c) = 0xb7;
      }
      else if (DAT_10061388 == 1) {
        *(undefined4 *)((int)param_1 + 0x38) = 0xb7;
        *(undefined4 *)(iVar5 + 0xe9c) = 0xbd;
      }
      else if (DAT_10061388 == 2) {
        *(undefined4 *)((int)param_1 + 0x38) = 0xbd;
        *(undefined4 *)(iVar5 + 0xe9c) = 0xc5;
      }
    }
    else {
      *(undefined4 *)((int)param_1 + 0x38) = 0xac;
      *(undefined4 *)(iVar5 + 0xe9c) = 0xb1;
    }
    uVar9 = 0;
    uVar8 = 0x3f800000;
    uVar1 = 0x3f800000;
    uVar2 = _rand();
    uVar2 = uVar2 & 0x80000003;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xfffffffc) + 1;
    }
    iVar5 = uVar2 + 1;
    pcVar7 = s__death_i_wav_1005f2c0;
    puVar3 = FUN_10038a50((byte *)s__death_i_wav_1005f2c0);
    uVar1 = (*DAT_1006c1e4)(puVar3,pcVar7,iVar5,uVar1,uVar8,uVar9);
    (*DAT_1006c1d0)(param_1,2,uVar1);
  }
  *(undefined4 *)((int)param_1 + 0x22c) = 2;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_100327c0 @ 100327c0 size 764 */

void __cdecl FUN_100327c0(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  char *pcVar14;
  int *local_d90;
  int local_d8c;
  int local_d88;
  int *local_d84;
  int local_d78 [256];
  int local_978 [256];
  char local_578 [1400];
  
  iVar12 = 0;
  local_d90 = (int *)0x0;
  local_d88 = 0;
  if (0 < DAT_1006ca48) {
    iVar11 = -4;
    piVar9 = (int *)(DAT_1006c844 + 0xda8);
    piVar5 = (int *)(DAT_1006c2c4 + 0x428);
    do {
      local_d90 = piVar5;
      if ((*local_d90 != 0) && (piVar9[4] == 0)) {
        iVar2 = *piVar9;
        iVar3 = 0;
        if (iVar11 < -3) {
LAB_10032832:
          if (iVar3 < iVar12) {
            iVar10 = iVar12 - iVar3;
            iVar6 = iVar11;
            do {
              *(undefined4 *)((int)local_978 + iVar6 + 4) = *(undefined4 *)((int)local_978 + iVar6);
              *(undefined4 *)((int)local_d78 + iVar6 + 4) = *(undefined4 *)((int)local_d78 + iVar6);
              iVar6 = iVar6 + -4;
              iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
          }
        }
        else {
          piVar5 = local_d78;
          do {
            if (*piVar5 < iVar2) goto LAB_10032832;
            iVar3 = iVar3 + 1;
            piVar5 = piVar5 + 1;
          } while (iVar3 < iVar12);
        }
        iVar12 = iVar12 + 1;
        local_978[iVar3] = local_d88;
        local_d78[iVar3] = iVar2;
        iVar11 = iVar11 + 4;
      }
      local_d88 = local_d88 + 1;
      piVar5 = local_d90 + 0xf4;
      piVar9 = piVar9 + 0x3cd;
      local_d90 = (int *)iVar12;
    } while (local_d88 < DAT_1006ca48);
  }
  uVar7 = 0xffffffff;
  local_578[0] = '\0';
  pcVar13 = local_578;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar13 + 1;
  } while (cVar1 != '\0');
  if (0xc < (int)local_d90) {
    local_d90 = (int *)0xc;
  }
  local_d88 = 0;
  if (0 < (int)local_d90) {
    local_d84 = local_978;
    local_d8c = ~uVar7 - 1;
    do {
      iVar12 = (*local_d84 + 1) * 0x3d0 + DAT_1006c2c4;
      (*DAT_1006c1e8)(s_i_fixme_10047c94);
      if (iVar12 == param_1) {
        puVar4 = &DAT_1005f524;
LAB_1003296b:
        if (puVar4 != (undefined *)0x0) {
          FUN_10038b40();
          uVar7 = 0xffffffff;
          piVar9 = local_d78;
          do {
            if (uVar7 == 0) break;
            uVar7 = uVar7 - 1;
            iVar12 = *piVar9;
            piVar9 = (int *)((int)piVar9 + 1);
          } while ((char)iVar12 != '\0');
          iVar12 = local_d8c + (~uVar7 - 1);
          if (0x400 < iVar12) break;
          uVar7 = 0xffffffff;
          piVar9 = local_d78;
          do {
            piVar5 = piVar9;
            if (uVar7 == 0) break;
            uVar7 = uVar7 - 1;
            piVar5 = (int *)((int)piVar9 + 1);
            iVar11 = *piVar9;
            piVar9 = piVar5;
          } while ((char)iVar11 != '\0');
          uVar7 = ~uVar7;
          pcVar13 = (char *)((int)piVar5 - uVar7);
          pcVar14 = local_578 + local_d8c;
          for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined4 *)pcVar14 = *(undefined4 *)pcVar13;
            pcVar13 = pcVar13 + 4;
            pcVar14 = pcVar14 + 4;
          }
          for (uVar7 = uVar7 & 3; local_d8c = iVar12, uVar7 != 0; uVar7 = uVar7 - 1) {
            *pcVar14 = *pcVar13;
            pcVar13 = pcVar13 + 1;
            pcVar14 = pcVar14 + 1;
          }
        }
      }
      else if (iVar12 == param_2) {
        puVar4 = &DAT_1005f51c;
        goto LAB_1003296b;
      }
      FUN_10038b40();
      uVar7 = 0xffffffff;
      piVar9 = local_d78;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        iVar12 = *piVar9;
        piVar9 = (int *)((int)piVar9 + 1);
      } while ((char)iVar12 != '\0');
      iVar12 = local_d8c + (~uVar7 - 1);
      if (0x400 < iVar12) break;
      uVar7 = 0xffffffff;
      piVar9 = local_d78;
      do {
        piVar5 = piVar9;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        piVar5 = (int *)((int)piVar9 + 1);
        iVar11 = *piVar9;
        piVar9 = piVar5;
      } while ((char)iVar11 != '\0');
      uVar7 = ~uVar7;
      pcVar13 = (char *)((int)piVar5 - uVar7);
      pcVar14 = local_578 + local_d8c;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar14 = *(undefined4 *)pcVar13;
        pcVar13 = pcVar13 + 4;
        pcVar14 = pcVar14 + 4;
      }
      local_d88 = local_d88 + 1;
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar14 = *pcVar13;
        pcVar13 = pcVar13 + 1;
        pcVar14 = pcVar14 + 1;
      }
      local_d84 = local_d84 + 1;
      local_d8c = iVar12;
    } while (local_d88 < (int)local_d90);
  }
  (*DAT_1006c224)(4);
  (*DAT_1006c234)(local_578);
  return;
}



/* FUN_1003d160 @ 1003d160 size 758 */

undefined4 __cdecl FUN_1003d160(uint *param_1,int param_2,int param_3)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint local_c;
  
  uVar5 = param_1[4];
  uVar12 = param_3 + 0x17U & 0xfffffff0;
  uVar10 = param_2 - param_1[3] >> 0xf;
  iVar3 = uVar10 * 0x204 + 0x144 + uVar5;
  iVar6 = *(int *)(param_2 + -4);
  iVar9 = iVar6 + -1;
  uVar13 = *(uint *)(iVar6 + -5 + param_2);
  iVar6 = iVar6 + -5 + param_2;
  if (iVar9 < (int)uVar12) {
    if (((uVar13 & 1) != 0) || ((int)(uVar13 + iVar9) < (int)uVar12)) {
      return 0;
    }
    local_c = ((int)uVar13 >> 4) - 1;
    if (0x3f < local_c) {
      local_c = 0x3f;
    }
    if (*(int *)(iVar6 + 4) == *(int *)(iVar6 + 8)) {
      if (local_c < 0x20) {
        pcVar1 = (char *)(local_c + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)local_c & 0x1f));
        puVar7 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        *puVar7 = *puVar7 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar11;
        }
      }
      else {
        pcVar1 = (char *)(local_c + 4 + uVar5);
        uVar11 = ~(0x80000000U >> ((byte)local_c - 0x20 & 0x1f));
        puVar7 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        *puVar7 = *puVar7 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar11;
        }
      }
    }
    *(undefined4 *)(*(int *)(iVar6 + 8) + 4) = *(undefined4 *)(iVar6 + 4);
    *(undefined4 *)(*(int *)(iVar6 + 4) + 8) = *(undefined4 *)(iVar6 + 8);
    iVar6 = uVar13 + (iVar9 - uVar12);
    if (0 < iVar6) {
      uVar13 = (iVar6 >> 4) - 1;
      iVar9 = param_2 + -4 + uVar12;
      if (0x3f < uVar13) {
        uVar13 = 0x3f;
      }
      iVar3 = iVar3 + uVar13 * 8;
      *(undefined4 *)(iVar9 + 4) = *(undefined4 *)(iVar3 + 4);
      *(int *)(iVar9 + 8) = iVar3;
      *(int *)(iVar3 + 4) = iVar9;
      *(int *)(*(int *)(iVar9 + 4) + 8) = iVar9;
      if (*(int *)(iVar9 + 4) == *(int *)(iVar9 + 8)) {
        cVar4 = *(char *)(uVar13 + 4 + uVar5);
        *(char *)(uVar13 + 4 + uVar5) = cVar4 + '\x01';
        bVar8 = (byte)uVar13;
        if (uVar13 < 0x20) {
          if (cVar4 == '\0') {
            *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
          }
          puVar7 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
        }
        else {
          if (cVar4 == '\0') {
            param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
          }
          puVar7 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
          bVar8 = bVar8 - 0x20;
        }
        *puVar7 = *puVar7 | 0x80000000U >> (bVar8 & 0x1f);
      }
      piVar2 = (int *)(param_2 + -4 + uVar12);
      *piVar2 = iVar6;
      *(int *)(iVar6 + -4 + (int)piVar2) = iVar6;
    }
    *(uint *)(param_2 + -4) = uVar12 + 1;
    *(uint *)(param_2 + -8 + uVar12) = uVar12 + 1;
  }
  else if ((int)uVar12 < iVar9) {
    param_3 = iVar9 - uVar12;
    *(uint *)(param_2 + -4) = uVar12 + 1;
    piVar2 = (int *)(param_2 + -4 + uVar12);
    uVar11 = (param_3 >> 4) - 1;
    piVar2[-1] = uVar12 + 1;
    if (0x3f < uVar11) {
      uVar11 = 0x3f;
    }
    if ((uVar13 & 1) == 0) {
      uVar12 = ((int)uVar13 >> 4) - 1;
      if (0x3f < uVar12) {
        uVar12 = 0x3f;
      }
      if (*(int *)(iVar6 + 4) == *(int *)(iVar6 + 8)) {
        if (uVar12 < 0x20) {
          pcVar1 = (char *)(uVar12 + 4 + uVar5);
          uVar12 = ~(0x80000000U >> ((byte)uVar12 & 0x1f));
          puVar7 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
          *puVar7 = *puVar7 & uVar12;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *param_1 = *param_1 & uVar12;
          }
        }
        else {
          pcVar1 = (char *)(uVar12 + 4 + uVar5);
          uVar12 = ~(0x80000000U >> ((byte)uVar12 - 0x20 & 0x1f));
          puVar7 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
          *puVar7 = *puVar7 & uVar12;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            param_1[1] = param_1[1] & uVar12;
          }
        }
      }
      *(undefined4 *)(*(int *)(iVar6 + 8) + 4) = *(undefined4 *)(iVar6 + 4);
      *(undefined4 *)(*(int *)(iVar6 + 4) + 8) = *(undefined4 *)(iVar6 + 8);
      param_3 = param_3 + uVar13;
      uVar11 = (param_3 >> 4) - 1;
      if (0x3f < uVar11) {
        uVar11 = 0x3f;
      }
    }
    iVar6 = iVar3 + uVar11 * 8;
    piVar2[1] = *(int *)(iVar3 + 4 + uVar11 * 8);
    piVar2[2] = iVar6;
    *(int **)(iVar6 + 4) = piVar2;
    *(int **)(piVar2[1] + 8) = piVar2;
    if (piVar2[1] == piVar2[2]) {
      cVar4 = *(char *)(uVar11 + 4 + uVar5);
      *(char *)(uVar11 + 4 + uVar5) = cVar4 + '\x01';
      bVar8 = (byte)uVar11;
      if (uVar11 < 0x20) {
        if (cVar4 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
        }
        puVar7 = (uint *)(uVar5 + 0x44 + uVar10 * 4);
      }
      else {
        if (cVar4 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
        }
        puVar7 = (uint *)(uVar5 + 0xc4 + uVar10 * 4);
        bVar8 = bVar8 - 0x20;
      }
      *puVar7 = *puVar7 | 0x80000000U >> (bVar8 & 0x1f);
    }
    *piVar2 = param_3;
    *(int *)(param_3 + -4 + (int)piVar2) = param_3;
  }
  return 1;
}



/* FUN_10035530 @ 10035530 size 756 */

void __cdecl FUN_10035530(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  char *pcVar3;
  
  iVar1 = FUN_10038b20((void *)**(undefined4 **)(*(int *)(param_1 + 0x54) + 0x714),
                       (byte *)s_weapon_plasma_rifle_100481ac);
  if (iVar1 != 0) {
    puVar2 = FUN_1000b150((byte *)s_slugs_1005f93c);
    if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0) {
      puVar2 = FUN_1000b150((byte *)s_railgun_1005f934);
      if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0)
      {
        pcVar3 = s_railgun_1005f934;
        goto LAB_100357f9;
      }
    }
    puVar2 = FUN_1000b150((byte *)s_cells_10049004);
    if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0) {
      puVar2 = FUN_1000b150((byte *)s_hyperblaster_1005f924);
      if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0)
      {
        pcVar3 = s_hyperblaster_1005f924;
        goto LAB_100357f9;
      }
    }
    puVar2 = FUN_1000b150((byte *)s_bullets_1005f91c);
    if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0) {
      puVar2 = FUN_1000b150((byte *)s_chaingun_1005f910);
      if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0)
      {
        pcVar3 = s_chaingun_1005f910;
        goto LAB_100357f9;
      }
    }
    puVar2 = FUN_1000b150((byte *)s_bullets_1005f91c);
    if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0) {
      puVar2 = FUN_1000b150((byte *)s_machinegun_1005f904);
      if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0)
      {
        pcVar3 = s_machinegun_1005f904;
        goto LAB_100357f9;
      }
    }
    puVar2 = FUN_1000b150((byte *)s_shells_1005f8fc);
    if (1 < *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4)) {
      puVar2 = FUN_1000b150((byte *)s_super_shotgun_1005f8ec);
      if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0)
      {
        pcVar3 = s_super_shotgun_1005f8ec;
        goto LAB_100357f9;
      }
    }
    puVar2 = FUN_1000b150((byte *)s_shells_1005f8fc);
    if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0) {
      puVar2 = FUN_1000b150((byte *)s_shotgun_1005f8e4);
      if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0)
      {
        pcVar3 = s_shotgun_1005f8e4;
LAB_100357f9:
        puVar2 = FUN_1000b150((byte *)pcVar3);
        *(undefined4 **)(*(int *)(param_1 + 0x54) + 0xdfc) = puVar2;
        return;
      }
    }
    puVar2 = FUN_1000b150((byte *)s_Plasma_Pistol_10048cb0);
    *(undefined4 **)(*(int *)(param_1 + 0x54) + 0xdfc) = puVar2;
  }
  return;
}



/* FUN_10033820 @ 10033820 size 752 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10033820(int param_1)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float local_c;
  float local_8;
  
  iVar2 = *(int *)(param_1 + 0x54);
  pfVar1 = (float *)(iVar2 + 0x34);
  if (*(int *)(param_1 + 0x22c) == 0) {
    *pfVar1 = *(float *)(iVar2 + 0xe24);
    *(undefined4 *)(iVar2 + 0x38) = *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe28);
    *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe2c);
    fVar3 = *(float *)(*(int *)(param_1 + 0x54) + 0xe44) - DAT_1006c2e4;
    fVar3 = fVar3 + fVar3;
    if (fVar3 < _DAT_1004410c) {
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe40) = 0;
      fVar3 = _DAT_1004410c;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe3c) = 0;
    }
    *pfVar1 = fVar3 * *(float *)(*(int *)(param_1 + 0x54) + 0xe40) + *pfVar1;
    *(float *)(iVar2 + 0x3c) =
         fVar3 * *(float *)(*(int *)(param_1 + 0x54) + 0xe3c) + *(float *)(iVar2 + 0x3c);
    fVar3 = (*(float *)(*(int *)(param_1 + 0x54) + 0xe48) - DAT_1006c2e4) * (float)_DAT_10044408;
    if (fVar3 < _DAT_1004410c) {
      fVar3 = _DAT_1004410c;
    }
    fVar3 = fVar3 * *(float *)(*(int *)(param_1 + 0x54) + 0xe4c) + *pfVar1;
    *pfVar1 = fVar3;
    *pfVar1 = (DAT_1006139c * *(float *)(param_1 + 0x17c) +
              _DAT_100613a0 * *(float *)(param_1 + 0x180) +
              DAT_10061398 * *(float *)(param_1 + 0x178)) * *(float *)(DAT_1006c17c + 0x14) + fVar3;
    *(float *)(iVar2 + 0x3c) =
         (DAT_100613a8 * *(float *)(param_1 + 0x17c) +
         _DAT_100613ac * *(float *)(param_1 + 0x180) + DAT_100613a4 * *(float *)(param_1 + 0x178)) *
         *(float *)(DAT_1006c424 + 0x14) + *(float *)(iVar2 + 0x3c);
    fVar3 = _DAT_10062080 * *(float *)(DAT_1006c198 + 0x14) * _DAT_1006208c;
    if ((*(byte *)(*(int *)(param_1 + 0x54) + 0x10) & 1) != 0) {
      fVar3 = fVar3 * _DAT_10044404;
    }
    *pfVar1 = fVar3 + *pfVar1;
    fVar3 = _DAT_10062080 * *(float *)(DAT_1006c19c + 0x14) * _DAT_1006208c;
    if ((*(byte *)(*(int *)(param_1 + 0x54) + 0x10) & 1) != 0) {
      fVar3 = fVar3 * _DAT_10044404;
    }
    if (((byte)DAT_10062088 & 1) != 0) {
      fVar3 = -fVar3;
    }
    *(float *)(iVar2 + 0x3c) = fVar3 + *(float *)(iVar2 + 0x3c);
  }
  else {
    *(undefined4 *)(iVar2 + 0x3c) = 0;
    *(undefined4 *)(iVar2 + 0x38) = 0;
    *pfVar1 = 0.0;
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x24) = 0x42200000;
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x1c) = 0xc1700000;
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x20) =
         *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe1c);
  }
  iVar2 = *(int *)(param_1 + 0x54);
  fVar3 = (*(float *)(iVar2 + 0xe48) - DAT_1006c2e4) * (float)_DAT_10044408;
  if (fVar3 < _DAT_1004410c) {
    fVar3 = _DAT_1004410c;
  }
  fVar4 = _DAT_10062080 * *(float *)(DAT_1006ca5c + 0x14) * _DAT_1006208c;
  if (_DAT_10044404 < fVar4) {
    fVar4 = _DAT_10044404;
  }
  local_c = *(float *)(iVar2 + 0xe30);
  local_8 = *(float *)(iVar2 + 0xe34);
  fVar3 = fVar4 + ((float)*(int *)(param_1 + 0x23c) -
                  fVar3 * *(float *)(iVar2 + 0xe4c) * (float)_DAT_10044308) +
          *(float *)(iVar2 + 0xe38);
  if (_DAT_10044400 <= local_c) {
    if (_DAT_100443fc < local_c) {
      local_c = 14.0;
    }
  }
  else {
    local_c = -14.0;
  }
  if (_DAT_10044400 <= local_8) {
    if (_DAT_100443fc < local_8) {
      local_8 = 14.0;
    }
  }
  else {
    local_8 = -14.0;
  }
  fVar4 = _DAT_100443f8;
  if ((_DAT_100443f8 <= fVar3) && (fVar4 = fVar3, _DAT_10044220 < fVar3)) {
    fVar4 = _DAT_10044220;
  }
  *(float *)(iVar2 + 0x28) = local_c;
  *(float *)(*(int *)(param_1 + 0x54) + 0x2c) = local_8;
  *(float *)(*(int *)(param_1 + 0x54) + 0x30) = fVar4;
  return;
}



/* FUN_1000ef10 @ 1000ef10 size 735 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000ef10(undefined4 *param_1,int param_2,uint param_3)

{
  float *pfVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  FUN_10038a20((float *)(param_1 + 0x3b),0.5,&local_24);
  local_18 = local_24 + (float)param_1[0x35];
  param_1[0x90] = 0;
  local_14 = local_20 + (float)param_1[0x36];
  local_10 = local_1c + (float)param_1[0x37];
  param_1[2] = local_14;
  param_1[1] = local_18;
  param_1[3] = local_10;
  if (param_1[0x95] != 0) {
    FUN_10006860((float)param_1,param_3,(float)(int)(param_1[0x91] * param_1[0x95]),0,
                 (float)param_1[0xa4],0x19);
  }
  pfVar1 = (float *)(param_1 + 0x5e);
  *pfVar1 = (float)param_1[1] - *(float *)(param_2 + 4);
  param_1[0x5f] = (float)param_1[2] - *(float *)(param_2 + 8);
  param_1[0x60] = (float)param_1[3] - *(float *)(param_2 + 0xc);
  FUN_10038900(pfVar1);
  FUN_10038a20(pfVar1,150.0,pfVar1);
  FUN_10038a20(&local_24,0.5,&local_24);
  iVar5 = param_1[100];
  if (iVar5 == 0) {
    iVar5 = 0x4b;
  }
  else if (99 < iVar5) {
    iVar4 = iVar5 / 100;
    if (8 < iVar4) {
      iVar4 = 8;
    }
    for (; iVar4 != 0; iVar4 = iVar4 + -1) {
      uVar3 = _rand();
      fVar2 = (float)(uVar3 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
      local_c = (fVar2 + fVar2) * local_24 + local_18;
      uVar3 = _rand();
      fVar2 = (float)(uVar3 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
      local_8 = (fVar2 + fVar2) * local_20 + local_14;
      uVar3 = _rand();
      fVar2 = (float)(uVar3 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
      local_4 = (fVar2 + fVar2) * local_1c + local_10;
      FUN_1000e210((int)param_1,s_models_objects_debris1_tris_md2_100492cc,1.0,(int *)&local_c);
    }
  }
  iVar5 = iVar5 / 0x19;
  if (0x10 < iVar5) {
    iVar5 = 0x10;
  }
  for (; iVar5 != 0; iVar5 = iVar5 + -1) {
    uVar3 = _rand();
    fVar2 = (float)(uVar3 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
    local_c = (fVar2 + fVar2) * local_24 + local_18;
    uVar3 = _rand();
    fVar2 = (float)(uVar3 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
    local_8 = (fVar2 + fVar2) * local_20 + local_14;
    uVar3 = _rand();
    fVar2 = (float)(uVar3 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
    local_4 = (fVar2 + fVar2) * local_1c + local_10;
    FUN_1000e210((int)param_1,s_models_objects_debris2_tris_md2_100492ac,2.0,(int *)&local_c);
  }
  FUN_1001ae20((uint)param_1,param_3);
  if (param_1[0x91] == 0) {
    FUN_1001b400(param_1);
    return;
  }
  FUN_1000e3e0(param_1);
  return;
}



/* FUN_1001e240 @ 1001e240 size 733 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1001e240(float param_1,int *param_2,float *param_3,int param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float fVar4;
  int *piVar5;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  float10 fVar9;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float afStack_38 [13];
  int iStack_4;
  
  pfVar3 = param_3;
  FUN_10038900(param_3);
  piVar5 = FUN_1001b350();
  piVar5[0x2e] = 2;
  piVar5[1] = *param_2;
  piVar5[2] = param_2[1];
  piVar5[3] = param_2[2];
  piVar5[7] = *param_2;
  piVar5[8] = param_2[1];
  piVar5[9] = param_2[2];
  FUN_1001b1e0(param_3,(float *)(piVar5 + 4));
  piVar5[0x52] = (int)(float)(int)param_5;
  FUN_10038a20(param_3,(float)(int)param_5,(float *)(piVar5 + 0x5e));
  piVar5[0x55] = (int)*param_3;
  piVar5[0x56] = (int)param_3[1];
  fVar1 = param_3[2];
  piVar5[0x3e] = 2;
  piVar5[0x57] = (int)fVar1;
  piVar5[99] = 0x43f00000;
  piVar5[0x41] = 8;
  piVar5[0x3f] = 0x6000003;
  piVar5[0x31] = 0;
  piVar5[0x30] = 0;
  piVar5[0x2f] = 0;
  piVar5[0x34] = 0;
  piVar5[0x33] = 0;
  piVar5[0x32] = 0;
  iVar6 = (*DAT_1006c1e0)(s_models_objects_deatom_tris_md2_1004c078);
  piVar5[10] = iVar6;
  iVar6 = (*DAT_1006c1e4)(s_deatom_dfly_wav_1004c068);
  piVar5[0x13] = iVar6;
  piVar5[0x10] = 0x40080000;
  piVar5[0x11] = 0x1008;
  piVar5[0x3e] = 2;
  piVar5[0xe] = 0;
  piVar5[0x40] = (int)param_1;
  piVar5[0x7f] = (int)FUN_1001df80;
  piVar5[0x91] = param_4;
  piVar5[0x46] = (int)s_deatom_bolt_1004c05c;
  (*DAT_1006c208)(piVar5);
  pfVar7 = (float *)(*DAT_1006c1f0)(afStack_38,(int)param_1 + 4,0,0,piVar5 + 1,piVar5,0x6000003);
  pfVar8 = afStack_38;
  for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {
    *pfVar8 = *pfVar7;
    pfVar7 = pfVar7 + 1;
    pfVar8 = pfVar8 + 1;
  }
  if (afStack_38[2] < (float)_DAT_10044120) {
    FUN_10038950((float *)(piVar5 + 1),-10.0,param_3,(float *)(piVar5 + 1));
    if (iStack_4 == piVar5[0x40]) {
      FUN_1001b400(piVar5);
    }
    else {
      (*(code *)piVar5[0x7f])(piVar5,iStack_4,0,0);
    }
  }
  fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
  pfVar8 = (float *)0x0;
  piVar5[0x7d] = (int)&LAB_1001e070;
  param_1 = 0.85;
  param_5 = 9999999.0;
  param_3 = (float *)0x0;
  piVar5[0x7b] = (int)fVar1;
  fVar1 = param_1;
  pfVar7 = param_3;
  fVar4 = param_5;
  while( true ) {
    param_5 = fVar4;
    param_3 = pfVar7;
    param_1 = fVar1;
    pfVar8 = (float *)FUN_1001aca0((int)pfVar8,(int)(piVar5 + 1),1024.0);
    if (pfVar8 == (float *)0x0) break;
    fVar1 = param_1;
    pfVar7 = param_3;
    fVar4 = param_5;
    if ((pfVar8[0x90] == 2.8026e-45) && (iVar6 = FUN_10001560((int)piVar5,(int)pfVar8), iVar6 != 0))
    {
      fStack_44 = pfVar8[1] - (float)piVar5[1];
      fStack_40 = pfVar8[2] - (float)piVar5[2];
      fStack_3c = pfVar8[3] - (float)piVar5[3];
      fVar9 = (float10)FUN_10038900(&fStack_44);
      fVar2 = fStack_3c * pfVar3[2] + fStack_44 * *pfVar3 + fStack_40 * pfVar3[1];
      if (((param_1 <= (float)_DAT_100442f8) ||
          ((fVar2 <= (float)_DAT_100442f8 ||
           (fVar1 = fVar2, pfVar7 = pfVar8, fVar4 = (float)fVar9, param_5 <= (float)fVar9)))) &&
         (fVar1 = param_1, pfVar7 = param_3, fVar4 = param_5, param_1 < fVar2)) {
        fVar1 = fVar2;
        pfVar7 = pfVar8;
      }
    }
  }
  piVar5[0x97] = (int)param_3;
  return;
}



/* FUN_10031950 @ 10031950 size 732 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10031950(int param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  char *pcVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  int *piVar7;
  byte *pbVar8;
  byte *pbVar9;
  bool bVar10;
  longlong lVar11;
  
  pbVar2 = param_2;
  pcVar3 = FUN_10038bb0(param_2,&DAT_1005f4a0);
  lVar11 = FUN_100173e0(pcVar3);
  if ((int)lVar11 != 0) {
    pcVar3 = s_Banned__1005f498;
LAB_10031b62:
    FUN_10038da0(pbVar2,(byte *)s_rejmsg_1005f444,pcVar3);
    return 0;
  }
  pbVar4 = FUN_10038bb0(param_2,(byte *)s_spectator_1005f3bc);
  if ((*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) && (*pbVar4 != 0)) {
    pbVar8 = &DAT_1004a49c;
    pbVar5 = pbVar4;
    do {
      bVar1 = *pbVar5;
      bVar10 = bVar1 < *pbVar8;
      if (bVar1 != *pbVar8) {
LAB_100319d7:
        iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        goto LAB_100319dc;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar10 = bVar1 < pbVar8[1];
      if (bVar1 != pbVar8[1]) goto LAB_100319d7;
      pbVar5 = pbVar5 + 2;
      pbVar8 = pbVar8 + 2;
    } while (bVar1 != 0);
    iVar6 = 0;
LAB_100319dc:
    if (iVar6 != 0) {
      pbVar5 = *(byte **)(DAT_1006c108 + 4);
      if (*pbVar5 != 0) {
        pbVar9 = &DAT_1005f3b4;
        pbVar8 = pbVar5;
        do {
          bVar1 = *pbVar8;
          bVar10 = bVar1 < *pbVar9;
          if (bVar1 != *pbVar9) {
LAB_10031a1d:
            iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
            goto LAB_10031a22;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar8[1];
          bVar10 = bVar1 < pbVar9[1];
          if (bVar1 != pbVar9[1]) goto LAB_10031a1d;
          pbVar8 = pbVar8 + 2;
          pbVar9 = pbVar9 + 2;
        } while (bVar1 != 0);
        iVar6 = 0;
LAB_10031a22:
        if (iVar6 != 0) {
          do {
            bVar1 = *pbVar5;
            bVar10 = bVar1 < *pbVar4;
            if (bVar1 != *pbVar4) {
LAB_10031a4c:
              iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
              goto LAB_10031a51;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar5[1];
            bVar10 = bVar1 < pbVar4[1];
            if (bVar1 != pbVar4[1]) goto LAB_10031a4c;
            pbVar5 = pbVar5 + 2;
            pbVar4 = pbVar4 + 2;
          } while (bVar1 != 0);
          iVar6 = 0;
LAB_10031a51:
          if (iVar6 != 0) {
            pcVar3 = s_Spectator_password_required_or_i_1005f46c;
            goto LAB_10031b62;
          }
        }
      }
      pbVar4 = (byte *)0x0;
      iVar6 = 0;
      param_2 = (byte *)0x0;
      if (_DAT_1004410c < *(float *)(DAT_1006ca60 + 0x14)) {
        piVar7 = (int *)(DAT_1006c2c4 + 0x424);
        do {
          if ((piVar7[1] != 0) && (*(int *)(*piVar7 + 0x72c) != 0)) {
            pbVar4 = pbVar4 + 1;
          }
          iVar6 = iVar6 + 1;
          piVar7 = piVar7 + 0xf4;
          param_2 = pbVar4;
        } while ((float)iVar6 < *(float *)(DAT_1006ca60 + 0x14));
      }
      if (*(float *)(DAT_1006c410 + 0x14) <= (float)(int)param_2) {
        pcVar3 = s_Server_spectator_limit_is_full__1005f364;
        goto LAB_10031b62;
      }
      goto LAB_10031b77;
    }
  }
  pbVar5 = FUN_10038bb0(param_2,(byte *)s_password_1004a370);
  pbVar4 = *(byte **)(DAT_1006c2c8 + 4);
  if (*pbVar4 != 0) {
    pbVar9 = &DAT_1005f3b4;
    pbVar8 = pbVar4;
    do {
      bVar1 = *pbVar8;
      bVar10 = bVar1 < *pbVar9;
      if (bVar1 != *pbVar9) {
LAB_10031b25:
        iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        goto LAB_10031b2a;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar8[1];
      bVar10 = bVar1 < pbVar9[1];
      if (bVar1 != pbVar9[1]) goto LAB_10031b25;
      pbVar8 = pbVar8 + 2;
      pbVar9 = pbVar9 + 2;
    } while (bVar1 != 0);
    iVar6 = 0;
LAB_10031b2a:
    if (iVar6 != 0) {
      do {
        bVar1 = *pbVar4;
        bVar10 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_10031b54:
          iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_10031b59;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar4[1];
        bVar10 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_10031b54;
        pbVar4 = pbVar4 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar6 = 0;
LAB_10031b59:
      if (iVar6 != 0) {
        pcVar3 = s_Password_required_or_incorrect__1005f44c;
        goto LAB_10031b62;
      }
    }
  }
LAB_10031b77:
  iVar6 = DAT_1006c844 + -0xf34 + ((param_1 - DAT_1006c2c4) / 0x3d0) * 0xf34;
  *(int *)(param_1 + 0x54) = iVar6;
  if ((*(int *)(param_1 + 0x58) == 0) &&
     ((FUN_10030560(iVar6), DAT_1006ca58 == 0 || (*(int *)(*(int *)(param_1 + 0x54) + 0x714) == 0)))
     ) {
    FUN_10030460(*(int *)(param_1 + 0x54));
  }
  FUN_10031760(param_1,pbVar2);
  if (1 < DAT_1006ca48) {
    (*DAT_1006c1c4)(s__s_connected_1005f434,*(int *)(param_1 + 0x54) + 700);
  }
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x2d0) = 1;
  return 1;
}



/* FUN_100083c0 @ 100083c0 size 726 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100083c0(int param_1)

{
  bool bVar1;
  float fVar2;
  float local_30;
  float local_2c;
  float local_28;
  float local_24 [9];
  
  local_30 = 0.0;
  local_2c = 0.0;
  local_28 = 0.0;
  local_24[0] = 1.0;
  local_24[1] = 0.0;
  local_24[2] = 0.0;
  local_24[3] = 0.0;
  local_24[4] = 1.0;
  local_24[5] = 0.0;
  local_24[6] = 0.0;
  local_24[7] = 0.0;
  local_24[8] = 1.0;
  if (*(int *)(param_1 + 0x1a8) == 0) {
    if ((*(int *)(param_1 + 0x330) == 1) || (*(int *)(param_1 + 0x330) == 2)) {
      if (*(float *)(param_1 + 0x150) == _DAT_1004410c) {
        *(undefined4 *)(param_1 + 0x18c) = 0;
        *(undefined4 *)(param_1 + 0x188) = 0;
        *(undefined4 *)(param_1 + 0x184) = 0;
        *(undefined4 *)(param_1 + 0x340) = 0;
        *(undefined4 *)(param_1 + 0x1fc) = 0;
        *(undefined4 *)(param_1 + 500) = 0;
        *(undefined4 *)(param_1 + 0x330) = 0;
      }
      else {
        *(undefined1 **)(param_1 + 500) = &LAB_10007bf0;
        fVar2 = DAT_1006c2e4 + (float)_DAT_10044168;
        *(undefined4 *)(param_1 + 0x330) = 3;
        *(float *)(param_1 + 0x1ec) = fVar2;
      }
      if ((*(byte *)(param_1 + 0x11c) & 2) != 0) {
        *(undefined1 **)(param_1 + 0x1fc) = &LAB_10008350;
      }
    }
    else {
      bVar1 = *(float *)(param_1 + 0x14c) == _DAT_1004410c;
      *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x314);
      if (bVar1) {
        if (*(float *)(param_1 + 0x1ac) != _DAT_1004410c) {
          FUN_10038a20(local_24,*(float *)(param_1 + 0x1ac),(float *)(param_1 + 0x184));
          local_30 = *(float *)(param_1 + 0x184);
          local_2c = *(float *)(param_1 + 0x188);
          local_28 = *(float *)(param_1 + 0x18c);
        }
        if (*(float *)(param_1 + 0x1b0) != _DAT_1004410c) {
          FUN_10038a20(local_24 + 3,*(float *)(param_1 + 0x1b0),(float *)(param_1 + 0x184));
          local_30 = local_30 + *(float *)(param_1 + 0x184);
          local_2c = local_2c + *(float *)(param_1 + 0x188);
          local_28 = local_28 + *(float *)(param_1 + 0x18c);
        }
        if (*(float *)(param_1 + 0x1b4) != _DAT_1004410c) {
          FUN_10038a20(local_24 + 6,*(float *)(param_1 + 0x1b4),(float *)(param_1 + 0x184));
          local_30 = local_30 + *(float *)(param_1 + 0x184);
          local_2c = local_2c + *(float *)(param_1 + 0x188);
          local_28 = local_28 + *(float *)(param_1 + 0x18c);
        }
        *(float *)(param_1 + 0x184) = local_30;
        *(float *)(param_1 + 0x188) = local_2c;
        *(float *)(param_1 + 0x18c) = local_28;
        *(undefined4 *)(param_1 + 0x330) = 2;
      }
      else {
        *(undefined1 **)(param_1 + 500) = &LAB_10007790;
        fVar2 = DAT_1006c2e4 + (float)_DAT_10044168;
        *(undefined4 *)(param_1 + 0x330) = 1;
        *(float *)(param_1 + 0x1ec) = fVar2;
      }
      if ((*(byte *)(param_1 + 0x11c) & 2) != 0) {
        *(undefined1 **)(param_1 + 0x1fc) = &LAB_10008350;
        return;
      }
    }
  }
  else {
    *(undefined1 **)(param_1 + 500) = &LAB_10008220;
    fVar2 = DAT_1006c2e4 + (float)_DAT_10044168;
    *(undefined4 *)(param_1 + 0x330) = 1;
    *(undefined4 *)(param_1 + 0x200) = 0;
    *(float *)(param_1 + 0x1ec) = fVar2;
    if ((*(byte *)(param_1 + 0x11c) & 2) != 0) {
      *(undefined1 **)(param_1 + 0x1fc) = &LAB_10008350;
      return;
    }
  }
  return;
}



/* FUN_10041156 @ 10041156 size 719 */

uint __cdecl FUN_10041156(LPCSTR param_1,uint param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  DWORD *pDVar4;
  HANDLE hFile;
  DWORD DVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  _SECURITY_ATTRIBUTES local_20;
  DWORD local_14;
  DWORD local_10;
  DWORD local_c;
  byte local_5;
  
  bVar8 = (param_2 & 0x80) == 0;
  local_20.nLength = 0xc;
  local_20.lpSecurityDescriptor = (LPVOID)0x0;
  if (bVar8) {
    local_5 = 0;
  }
  else {
    local_5 = 0x10;
  }
  local_20.bInheritHandle = (BOOL)bVar8;
  if (((param_2 & 0x8000) == 0) && (((param_2 & 0x4000) != 0 || (DAT_10061fc8 != 0x8000)))) {
    local_5 = local_5 | 0x80;
  }
  uVar2 = param_2 & 3;
  if (uVar2 == 0) {
    local_10 = 0x80000000;
  }
  else if (uVar2 == 1) {
    local_10 = 0x40000000;
  }
  else {
    if (uVar2 != 2) goto LAB_1004125a;
    local_10 = 0xc0000000;
  }
  if (param_3 == 0x10) {
    local_14 = 0;
  }
  else if (param_3 == 0x20) {
    local_14 = 1;
  }
  else if (param_3 == 0x30) {
    local_14 = 2;
  }
  else {
    if (param_3 != 0x40) goto LAB_1004125a;
    local_14 = 3;
  }
  uVar2 = param_2 & 0x700;
  if (uVar2 < 0x401) {
    if ((uVar2 == 0x400) || (uVar2 == 0)) {
      local_c = 3;
    }
    else if (uVar2 == 0x100) {
      local_c = 4;
    }
    else {
      if (uVar2 == 0x200) goto LAB_10041274;
      if (uVar2 != 0x300) goto LAB_1004125a;
      local_c = 2;
    }
  }
  else {
    if (uVar2 != 0x500) {
      if (uVar2 == 0x600) {
LAB_10041274:
        local_c = 5;
        goto LAB_10041284;
      }
      if (uVar2 != 0x700) {
LAB_1004125a:
        pDVar4 = FUN_1004058e();
        *pDVar4 = 0x16;
        pDVar4 = FUN_10040597();
        *pDVar4 = 0;
        return 0xffffffff;
      }
    }
    local_c = 1;
  }
LAB_10041284:
  uVar2 = 0x80;
  if (((param_2 & 0x100) != 0) && ((~DAT_10061ddc & param_4 & 0x80) == 0)) {
    uVar2 = 1;
  }
  if ((param_2 & 0x40) != 0) {
    uVar2 = uVar2 | 0x4000000;
    local_10 = CONCAT13(local_10._3_1_,0x10000);
  }
  if ((param_2 & 0x1000) != 0) {
    uVar2 = uVar2 | 0x100;
  }
  if ((param_2 & 0x20) == 0) {
    if ((param_2 & 0x10) != 0) {
      uVar2 = uVar2 | 0x10000000;
    }
  }
  else {
    uVar2 = uVar2 | 0x8000000;
  }
  uVar3 = FUN_10040de2();
  if (uVar3 == 0xffffffff) {
    pDVar4 = FUN_1004058e();
    *pDVar4 = 0x18;
    pDVar4 = FUN_10040597();
    *pDVar4 = 0;
    return 0xffffffff;
  }
  hFile = CreateFileA(param_1,local_10,local_14,&local_20,local_c,uVar2,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    DVar5 = GetFileType(hFile);
    if (DVar5 != 0) {
      if (DVar5 == 2) {
        local_5 = local_5 | 0x40;
      }
      else if (DVar5 == 3) {
        local_5 = local_5 | 8;
      }
      FUN_10040f05(uVar3,hFile);
      iVar7 = (uVar3 & 0x1f) * 0x24;
      param_1._3_1_ = local_5 & 0x48;
      *(byte *)((&DAT_1006ccc0)[(int)uVar3 >> 5] + 4 + iVar7) = local_5 | 1;
      if ((((local_5 & 0x48) == 0) && ((local_5 & 0x80) != 0)) && ((param_2 & 2) != 0)) {
        local_14 = FUN_10040751(uVar3,-1,2);
        if (local_14 == 0xffffffff) {
          pDVar4 = FUN_10040597();
          if (*pDVar4 == 0x83) goto LAB_100413fe;
        }
        else {
          param_3 = param_3 & 0xffffff;
          iVar6 = FUN_1003e4e6(uVar3,(char *)((int)&param_3 + 3),(char *)0x1);
          if ((((iVar6 != 0) || (param_3._3_1_ != '\x1a')) ||
              (iVar6 = FUN_100427b9(uVar3,local_14), iVar6 != -1)) &&
             (DVar5 = FUN_10040751(uVar3,0,0), DVar5 != 0xffffffff)) goto LAB_100413fe;
        }
        FUN_1003e6bf(uVar3);
        uVar2 = 0xffffffff;
      }
      else {
LAB_100413fe:
        uVar2 = uVar3;
        if ((param_1._3_1_ == 0) && ((param_2 & 8) != 0)) {
          pbVar1 = (byte *)((&DAT_1006ccc0)[(int)uVar3 >> 5] + 4 + iVar7);
          *pbVar1 = *pbVar1 | 0x20;
        }
      }
      goto LAB_10041417;
    }
    CloseHandle(hFile);
  }
  DVar5 = GetLastError();
  FUN_1004051b(DVar5);
  uVar2 = 0xffffffff;
LAB_10041417:
  FUN_100410a1(uVar3);
  return uVar2;
}



/* FUN_1001d870 @ 1001d870 size 707 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1001d870(int param_1,int *param_2,float *param_3,int param_4)

{
  float *pfVar1;
  byte bVar2;
  float fVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  byte *pbVar8;
  int *piVar9;
  byte *pbVar10;
  bool bVar11;
  float *pfVar12;
  float *pfVar13;
  float local_30 [3];
  float local_24 [3];
  float local_18 [3];
  float local_c [3];
  
  FUN_1001b1e0(param_3,local_30);
  FUN_10038700(local_30,local_c,local_18,local_24);
  piVar4 = FUN_1001b350();
  pfVar1 = (float *)(piVar4 + 0x5e);
  piVar4[1] = *param_2;
  piVar4[2] = param_2[1];
  piVar4[3] = param_2[2];
  FUN_10038a20(param_3,(float)param_4,pfVar1);
  pfVar12 = local_24;
  pfVar13 = pfVar1;
  uVar5 = _rand();
  fVar3 = (float)(uVar5 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  FUN_10038950(pfVar1,(fVar3 + fVar3) * (float)_DAT_10044170 + (float)_DAT_100441d8,pfVar12,pfVar13)
  ;
  pfVar12 = local_18;
  pfVar13 = pfVar1;
  uVar5 = _rand();
  fVar3 = (float)(uVar5 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  FUN_10038950(pfVar1,(fVar3 + fVar3) * (float)_DAT_10044170,pfVar12,pfVar13);
  piVar4[0x41] = 7;
  piVar4[0x61] = 0x43960000;
  piVar4[0x62] = 0x43960000;
  piVar4[99] = 0x43960000;
  piVar4[0x3f] = 0x2010003;
  piVar4[0x3e] = 2;
  piVar4[0x2f] = -0x40000000;
  piVar4[0x30] = -0x40000000;
  piVar4[0x31] = -0x40000000;
  piVar4[0x10] = piVar4[0x10] | 0x20;
  piVar4[0x32] = 0x40000000;
  piVar4[0x33] = 0x40000000;
  piVar4[0x34] = 0x40000000;
  iVar6 = (*DAT_1006c1e0)(s_models_objects_mine_tris_md2_1004c01c);
  piVar4[10] = iVar6;
  piVar4[0x40] = param_1;
  piVar4[0x7f] = (int)&LAB_1001ded0;
  piVar4[0x7b] = 0;
  piVar4[0x7d] = (int)&LAB_1001dc00;
  piVar4[0x90] = 1;
  piVar4[0x82] = (int)&LAB_1001df50;
  piVar4[0x46] = (int)&DAT_1004c014;
  piVar4[0x91] = 0x96;
  piVar4[0x93] = 0x43340000;
  piVar4[0x92] = 100;
  piVar4[0x89] = 10;
  piVar4[0x88] = 10;
  uVar7 = (*DAT_1006c1e4)(s_weapons_hgrent1a_wav_1004bf14,0x3f800000,0x3f800000,0);
  (*DAT_1006c1d0)(param_1,1,uVar7);
  (*DAT_1006c208)(piVar4);
  piVar4[0x48] = DAT_1006c2e4;
  param_3 = (float *)0x0;
  piVar9 = DAT_1006c2c4;
  if (DAT_1006c2c4 < DAT_1006c2c4 + DAT_1006c168 * 0xf4) {
    do {
      if (((piVar9[0x16] != 0) && (piVar9[0x40] == param_1)) &&
         (pbVar8 = (byte *)piVar9[0x46], pbVar8 != (byte *)0x0)) {
        pbVar10 = &DAT_1004c014;
        do {
          bVar2 = *pbVar8;
          bVar11 = bVar2 < *pbVar10;
          if (bVar2 != *pbVar10) {
LAB_1001daea:
            iVar6 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
            goto LAB_1001daef;
          }
          if (bVar2 == 0) break;
          bVar2 = pbVar8[1];
          bVar11 = bVar2 < pbVar10[1];
          if (bVar2 != pbVar10[1]) goto LAB_1001daea;
          pbVar8 = pbVar8 + 2;
          pbVar10 = pbVar10 + 2;
        } while (bVar2 != 0);
        iVar6 = 0;
LAB_1001daef:
        if ((iVar6 == 0) &&
           (param_3 = (float *)((int)param_3 + 1), (float)piVar9[0x48] <= (float)piVar4[0x48])) {
          piVar4 = piVar9;
        }
      }
      piVar9 = piVar9 + 0xf4;
    } while (piVar9 < DAT_1006c2c4 + DAT_1006c168 * 0xf4);
    if (5 < (int)param_3) {
      FUN_1001db40(piVar4);
    }
  }
  return;
}



/* FUN_1001e8f0 @ 1001e8f0 size 701 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_1001e8f0(int param_1,int *param_2,float *param_3,int param_4,int param_5,float param_6,
            float param_7)

{
  float *pfVar1;
  byte bVar2;
  float fVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  int *piVar8;
  char *pcVar9;
  bool bVar10;
  float *pfVar11;
  float *pfVar12;
  float local_3c;
  float local_38;
  float local_34;
  float local_30 [3];
  float local_24 [3];
  float local_18 [3];
  float local_c [3];
  
  FUN_1001b1e0(param_3,local_30);
  FUN_10038700(local_30,local_c,local_18,local_24);
  piVar4 = FUN_1001b350();
  pfVar1 = (float *)(piVar4 + 0x5e);
  piVar4[1] = *param_2;
  piVar4[2] = param_2[1];
  piVar4[3] = param_2[2];
  FUN_10038a20(param_3,param_6,pfVar1);
  pfVar11 = local_24;
  pfVar12 = pfVar1;
  uVar5 = _rand();
  fVar3 = (float)(uVar5 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  FUN_10038950(pfVar1,(fVar3 + fVar3) * (float)_DAT_10044170 + (float)_DAT_10044300,pfVar11,pfVar12)
  ;
  pfVar11 = local_18;
  pfVar12 = pfVar1;
  uVar5 = _rand();
  fVar3 = (float)(uVar5 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  FUN_10038950(pfVar1,(fVar3 + fVar3) * (float)_DAT_10044170,pfVar11,pfVar12);
  local_3c = -*param_3;
  local_38 = -param_3[1];
  local_34 = -param_3[2];
  FUN_1001b1e0(&local_3c,(float *)(piVar4 + 4));
  piVar4[6] = -0x3de00000;
  piVar4[0x61] = -0x3ccc0000;
  piVar4[0x41] = 7;
  piVar4[0x3f] = 0x6000003;
  piVar4[0x3e] = 2;
  piVar4[0x42] = piVar4[0x42] | 0x800;
  piVar4[0x90] = 1;
  piVar4[0x31] = 0;
  piVar4[0x30] = 0;
  piVar4[0x2f] = 0;
  piVar4[0x34] = 0;
  piVar4[0x33] = 0;
  piVar4[0x32] = 0;
  iVar6 = (*DAT_1006c1e0)(s_models_objects_detpack_tris_md2_1004c108);
  bVar10 = param_7 != _DAT_1004410c;
  piVar4[10] = iVar6;
  piVar4[0x40] = param_1;
  piVar4[0x7f] = (int)&LAB_1001ebf0;
  if (bVar10) {
    fVar3 = DAT_1006c2e4 + param_7;
    piVar4[0x7d] = (int)FUN_1001e820;
    piVar4[0x7b] = (int)fVar3;
  }
  piVar4[0x82] = (int)&LAB_1001ebb0;
  piVar4[0x91] = param_4;
  piVar4[0x93] = param_5;
  piVar4[0x46] = (int)s_detpack_1004c100;
  piVar4[0x48] = (int)DAT_1006c2e4;
  (*DAT_1006c208)(piVar4);
  param_7 = 0.0;
  piVar8 = DAT_1006c2c4;
  if (DAT_1006c2c4 < DAT_1006c2c4 + DAT_1006c168 * 0xf4) {
    do {
      if (((piVar8[0x16] != 0) && (piVar8[0x40] == param_1)) &&
         (pbVar7 = (byte *)piVar8[0x46], pbVar7 != (byte *)0x0)) {
        pcVar9 = s_detpack_1004c100;
        do {
          bVar2 = *pbVar7;
          bVar10 = bVar2 < (byte)*pcVar9;
          if (bVar2 != *pcVar9) {
LAB_1001eb60:
            iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
            goto LAB_1001eb65;
          }
          if (bVar2 == 0) break;
          bVar2 = pbVar7[1];
          bVar10 = bVar2 < (byte)pcVar9[1];
          if (bVar2 != pcVar9[1]) goto LAB_1001eb60;
          pbVar7 = pbVar7 + 2;
          pcVar9 = pcVar9 + 2;
        } while (bVar2 != 0);
        iVar6 = 0;
LAB_1001eb65:
        if ((iVar6 == 0) &&
           (param_7 = (float)((int)param_7 + 1), (float)piVar8[0x48] <= (float)piVar4[0x48])) {
          piVar4 = piVar8;
        }
      }
      piVar8 = piVar8 + 0xf4;
    } while (piVar8 < DAT_1006c2c4 + DAT_1006c168 * 0xf4);
    if (5 < (int)param_7) {
      FUN_1001e820(piVar4);
    }
  }
  return;
}



/* FUN_1003aaa0 @ 1003aaa0 size 691 */

void __cdecl
FUN_1003aaa0(uint *param_1,uint *param_2,uint param_3,uint param_4,undefined8 *param_5,
            undefined8 *param_6)

{
  uint *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  
  uVar3 = param_3;
  puVar1 = param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if ((param_3 & 0x10) != 0) {
    param_3 = 0xc000008f;
    param_1[1] = param_1[1] | 1;
  }
  if ((uVar3 & 2) != 0) {
    param_3 = 0xc0000093;
    param_1[1] = param_1[1] | 2;
  }
  if ((uVar3 & 1) != 0) {
    param_3 = 0xc0000091;
    param_1[1] = param_1[1] | 4;
  }
  if ((uVar3 & 4) != 0) {
    param_3 = 0xc000008e;
    param_1[1] = param_1[1] | 8;
  }
  if ((uVar3 & 8) != 0) {
    param_3 = 0xc0000090;
    param_1[1] = param_1[1] | 0x10;
  }
  param_1[2] = (~*param_2 & 1) << 4 | param_1[2] & 0xffffffef;
  param_1[2] = (~*param_2 & 4) << 1 | param_1[2] & 0xfffffff7;
  param_1[2] = ~*param_2 >> 1 & 4 | param_1[2] & 0xfffffffb;
  param_1[2] = ~*param_2 >> 3 & 2 | param_1[2] & 0xfffffffd;
  param_1[2] = ~*param_2 >> 5 & 1 | param_1[2] & 0xfffffffe;
  uVar3 = FUN_1003b1c2();
  puVar2 = param_6;
  if ((uVar3 & 1) != 0) {
    param_1[3] = param_1[3] | 0x10;
  }
  if ((uVar3 & 4) != 0) {
    param_1[3] = param_1[3] | 8;
  }
  if ((uVar3 & 8) != 0) {
    param_1[3] = param_1[3] | 4;
  }
  if ((uVar3 & 0x10) != 0) {
    param_1[3] = param_1[3] | 2;
  }
  if ((uVar3 & 0x20) != 0) {
    param_1[3] = param_1[3] | 1;
  }
  uVar3 = *puVar1 & 0xc00;
  if (uVar3 == 0) {
    *param_1 = *param_1 & 0xfffffffc;
  }
  else {
    if (uVar3 == 0x400) {
      uVar3 = *param_1 & 0xfffffffd | 1;
    }
    else {
      if (uVar3 != 0x800) {
        if (uVar3 == 0xc00) {
          *param_1 = *param_1 | 3;
        }
        goto LAB_1003ac15;
      }
      uVar3 = *param_1 & 0xfffffffe | 2;
    }
    *param_1 = uVar3;
  }
LAB_1003ac15:
  uVar3 = *puVar1 & 0x300;
  if (uVar3 == 0) {
    uVar3 = *param_1 & 0xffffffeb | 8;
LAB_1003ac4b:
    *param_1 = uVar3;
  }
  else {
    if (uVar3 == 0x200) {
      uVar3 = *param_1 & 0xffffffe7 | 4;
      goto LAB_1003ac4b;
    }
    if (uVar3 == 0x300) {
      *param_1 = *param_1 & 0xffffffe3;
    }
  }
  *param_1 = (param_4 & 0xfff) << 5 | *param_1 & 0xfffe001f;
  param_1[8] = param_1[8] | 1;
  param_1[8] = param_1[8] & 0xffffffe3 | 2;
  *(undefined8 *)(param_1 + 4) = *param_5;
  param_1[0x14] = param_1[0x14] | 1;
  param_1[0x14] = param_1[0x14] & 0xffffffe3 | 2;
  *(undefined8 *)(param_1 + 0x10) = *param_6;
  FUN_1003b1d0();
  RaiseException(param_3,0,1,(ULONG_PTR *)&param_1);
  if ((param_1[2] & 0x10) != 0) {
    *puVar1 = *puVar1 & 0xfffffffe;
  }
  if ((param_1[2] & 8) != 0) {
    *puVar1 = *puVar1 & 0xfffffffb;
  }
  if ((param_1[2] & 4) != 0) {
    *puVar1 = *puVar1 & 0xfffffff7;
  }
  if ((param_1[2] & 2) != 0) {
    *puVar1 = *puVar1 & 0xffffffef;
  }
  if ((param_1[2] & 1) != 0) {
    *puVar1 = *puVar1 & 0xffffffdf;
  }
  uVar3 = *param_1 & 3;
  if (uVar3 == 0) {
    *puVar1 = *puVar1 & 0xfffff3ff;
  }
  else {
    if (uVar3 == 1) {
      uVar3 = *puVar1 & 0xfffff7ff | 0x400;
    }
    else {
      if (uVar3 != 2) {
        if (uVar3 == 3) {
          *(byte *)((int)puVar1 + 1) = *(byte *)((int)puVar1 + 1) | 0xc;
        }
        goto LAB_1003ad20;
      }
      uVar3 = *puVar1 & 0xfffffbff | 0x800;
    }
    *puVar1 = uVar3;
  }
LAB_1003ad20:
  uVar3 = *param_1 >> 2 & 7;
  if (uVar3 == 0) {
    uVar3 = *puVar1 & 0xfffff3ff | 0x300;
  }
  else {
    if (uVar3 != 1) {
      if (uVar3 == 2) {
        *puVar1 = *puVar1 & 0xfffff3ff;
      }
      goto LAB_1003ad49;
    }
    uVar3 = *puVar1 & 0xfffff3ff | 0x200;
  }
  *puVar1 = uVar3;
LAB_1003ad49:
  *puVar2 = *(undefined8 *)(param_1 + 0x10);
  return;
}



/* FUN_100074f0 @ 100074f0 size 670 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100074f0(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 3;
  *(undefined4 *)(param_1 + 0x104) = 2;
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  *(code **)(param_1 + 0x1f8) = FUN_10007280;
  if (*(float *)(param_1 + 0x148) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x148) = 0x41a00000;
  }
  else {
    *(float *)(param_1 + 0x148) = *(float *)(param_1 + 0x148) * (float)_DAT_10044168;
  }
  if (*(float *)(param_1 + 0x14c) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x14c) = 0x40a00000;
  }
  else {
    *(float *)(param_1 + 0x14c) = *(float *)(param_1 + 0x14c) * (float)_DAT_10044168;
  }
  if (*(float *)(param_1 + 0x150) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x150) = 0x40a00000;
  }
  else {
    *(float *)(param_1 + 0x150) = *(float *)(param_1 + 0x150) * (float)_DAT_10044168;
  }
  if (*(int *)(param_1 + 0x244) == 0) {
    *(undefined4 *)(param_1 + 0x244) = 2;
  }
  if (DAT_1006c298 == 0) {
    DAT_1006c298 = 8;
  }
  *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)(param_1 + 4);
  *(float *)(param_1 + 0x174) = *(float *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0x16c) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x170) = *(undefined4 *)(param_1 + 8);
  if (DAT_1006c2a0 == 0) {
    fVar1 = (*(float *)(param_1 + 0xd0) - *(float *)(param_1 + 0xc4)) - (float)DAT_1006c298;
  }
  else {
    fVar1 = (float)DAT_1006c2a0;
  }
  *(undefined1 **)(param_1 + 0x200) = &LAB_10007320;
  *(float *)(param_1 + 0x174) = *(float *)(param_1 + 0xc) - fVar1;
  FUN_10007390(param_1);
  if (*(int *)(param_1 + 300) == 0) {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0x16c);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x170);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x174);
    (*DAT_1006c208)(param_1);
    *(undefined4 *)(param_1 + 0x330) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x330) = 2;
  }
  *(undefined4 *)(param_1 + 800) = *(undefined4 *)(param_1 + 0x148);
  *(undefined4 *)(param_1 + 0x31c) = *(undefined4 *)(param_1 + 0x14c);
  *(undefined4 *)(param_1 + 0x324) = *(undefined4 *)(param_1 + 0x150);
  *(undefined4 *)(param_1 + 0x32c) = *(undefined4 *)(param_1 + 0x290);
  *(undefined4 *)(param_1 + 0x2e0) = *(undefined4 *)(param_1 + 0x160);
  *(undefined4 *)(param_1 + 0x2e4) = *(undefined4 *)(param_1 + 0x164);
  *(undefined4 *)(param_1 + 0x2e8) = *(undefined4 *)(param_1 + 0x168);
  *(undefined4 *)(param_1 + 0x2ec) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x2f0) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x2f4) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x2f8) = *(undefined4 *)(param_1 + 0x16c);
  *(undefined4 *)(param_1 + 0x2fc) = *(undefined4 *)(param_1 + 0x170);
  *(undefined4 *)(param_1 + 0x300) = *(undefined4 *)(param_1 + 0x174);
  *(undefined4 *)(param_1 + 0x304) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x308) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x30c) = *(undefined4 *)(param_1 + 0x18);
  uVar2 = (*DAT_1006c1e4)(s_plats_pt1_strt_wav_1004665c);
  *(undefined4 *)(param_1 + 0x310) = uVar2;
  uVar2 = (*DAT_1006c1e4)(s_plats_pt1_mid_wav_10046648);
  *(undefined4 *)(param_1 + 0x314) = uVar2;
  uVar2 = (*DAT_1006c1e4)(s_plats_pt1_end_wav_10046634);
  *(undefined4 *)(param_1 + 0x318) = uVar2;
  return;
}



/* FUN_10013b50 @ 10013b50 size 668 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10013b50(int param_1)

{
  undefined4 *puVar1;
  float *pfVar2;
  int iVar3;
  uint uVar4;
  float *pfVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  float *pfVar9;
  undefined4 *puVar10;
  float local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  float local_7c [3];
  float local_70 [6];
  float local_58 [2];
  float local_50;
  int local_3c;
  float local_38 [14];
  
  FUN_10012d80(param_1);
  if ((*(uint *)(param_1 + 0x108) & 0x400) != 0) {
    return;
  }
  if (_DAT_1004410c < *(float *)(param_1 + 0x180)) {
    *(undefined4 *)(param_1 + 0x268) = 0;
  }
  if ((*(int *)(param_1 + 0x268) != 0) && (*(int *)(*(int *)(param_1 + 0x268) + 0x58) == 0)) {
    *(undefined4 *)(param_1 + 0x268) = 0;
  }
  if (*(int *)(param_1 + 0x268) != 0) {
    return;
  }
  local_88 = *(undefined4 *)(param_1 + 4);
  local_84 = *(undefined4 *)(param_1 + 8);
  local_80 = *(undefined4 *)(param_1 + 0xc);
  FUN_10012d20(param_1);
  if ((*(int *)(param_1 + 0x104) != 6) && (*(int *)(param_1 + 0x104) != 8)) {
    FUN_100132f0(param_1);
  }
  FUN_10038950((float *)(param_1 + 0x10),0.1,(float *)(param_1 + 0x184),(float *)(param_1 + 0x10));
  pfVar2 = (float *)(param_1 + 0x178);
  FUN_10038a20(pfVar2,0.1,local_7c);
  pfVar5 = (float *)FUN_10013320(local_38,param_1,local_7c);
  iVar3 = *(int *)(param_1 + 0x58);
  pfVar9 = local_70;
  for (iVar8 = 0xe; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pfVar9 = *pfVar5;
    pfVar5 = pfVar5 + 1;
    pfVar9 = pfVar9 + 1;
  }
  if (iVar3 == 0) {
    return;
  }
  if (local_70[2] < _DAT_10044104) {
    local_8c = 1.5;
    if (*(int *)(param_1 + 0x104) != 9) {
      local_8c = 1.0;
    }
    FUN_10012e50(pfVar2,local_58,pfVar2,local_8c);
    if (((float)_DAT_10044228 < local_50) &&
       ((*(float *)(param_1 + 0x180) < _DAT_100441c0 || (*(int *)(param_1 + 0x104) != 9)))) {
      *(int *)(param_1 + 0x268) = local_3c;
      *(undefined4 *)(param_1 + 0x26c) = *(undefined4 *)(local_3c + 0x5c);
      *pfVar2 = DAT_10061c18;
      *(undefined4 *)(param_1 + 0x17c) = DAT_10061c1c;
      *(undefined4 *)(param_1 + 0x180) = DAT_10061c20;
      *(float *)(param_1 + 0x184) = DAT_10061c18;
      *(undefined4 *)(param_1 + 0x188) = DAT_10061c1c;
      *(undefined4 *)(param_1 + 0x18c) = DAT_10061c20;
    }
  }
  uVar4 = *(uint *)(param_1 + 0x2a4);
  puVar1 = (undefined4 *)(param_1 + 4);
  uVar6 = (*DAT_1006c1f4)(puVar1);
  *(uint *)(param_1 + 0x2a4) = uVar6;
  uVar6 = uVar6 & 0x38;
  if (uVar6 == 0) {
    *(undefined4 *)(param_1 + 0x2a8) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x2a8) = 1;
  }
  if ((uVar4 & 0x38) == 0) {
    if (uVar6 == 0) goto LAB_10013db2;
    uVar7 = (*DAT_1006c1e4)(s_misc_h2ohit1_wav_10049844,0x3f800000,0x3f800000,0);
    puVar10 = &local_88;
  }
  else {
    if (uVar6 != 0) goto LAB_10013db2;
    uVar7 = (*DAT_1006c1e4)(s_misc_h2ohit1_wav_10049844,0x3f800000,0x3f800000,0);
    puVar10 = puVar1;
  }
  (*DAT_1006c1d4)(puVar10,DAT_1006c2c4,0,uVar7);
LAB_10013db2:
  for (iVar3 = *(int *)(param_1 + 0x270); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x270)) {
    *(undefined4 *)(iVar3 + 4) = *puVar1;
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(param_1 + 0xc);
    (*DAT_1006c208)(iVar3);
  }
  return;
}



/* FUN_1003e070 @ 1003e070 size 664 */

undefined4 * __cdecl FUN_1003e070(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_1003e227_caseD_2;
        case 3:
          goto switchD_1003e227_caseD_3;
        }
        goto switchD_1003e227_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_1003e227_caseD_0;
      case 1:
        goto switchD_1003e227_caseD_1;
      case 2:
        goto switchD_1003e227_caseD_2;
      case 3:
        goto switchD_1003e227_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_1003e227_caseD_2;
            case 3:
              goto switchD_1003e227_caseD_3;
            }
            goto switchD_1003e227_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_1003e227_caseD_2;
            case 3:
              goto switchD_1003e227_caseD_3;
            }
            goto switchD_1003e227_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_1003e227_caseD_2;
            case 3:
              goto switchD_1003e227_caseD_3;
            }
            goto switchD_1003e227_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_1003e227_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_1003e227_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_1003e227_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_1003e227_caseD_0:
    return param_1;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_1003e0a5_caseD_2;
      case 3:
        goto switchD_1003e0a5_caseD_3;
      }
      goto switchD_1003e0a5_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_1003e0a5_caseD_0;
    case 1:
      goto switchD_1003e0a5_caseD_1;
    case 2:
      goto switchD_1003e0a5_caseD_2;
    case 3:
      goto switchD_1003e0a5_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_1003e0a5_caseD_2;
          case 3:
            goto switchD_1003e0a5_caseD_3;
          }
          goto switchD_1003e0a5_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_1003e0a5_caseD_2;
          case 3:
            goto switchD_1003e0a5_caseD_3;
          }
          goto switchD_1003e0a5_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_1003e0a5_caseD_2;
          case 3:
            goto switchD_1003e0a5_caseD_3;
          }
          goto switchD_1003e0a5_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar3[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar3[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar3[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar3[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar3[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar3[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_1003e0a5_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_1003e0a5_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_1003e0a5_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_1003e0a5_caseD_0:
  return param_1;
}



/* FUN_10040150 @ 10040150 size 664 */

undefined4 * __cdecl FUN_10040150(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)(param_3 + (int)param_2))) {
    puVar3 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar4 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = param_3 >> 2;
      uVar2 = param_3 & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return param_1;
        case 2:
          goto switchD_10040307_caseD_2;
        case 3:
          goto switchD_10040307_caseD_3;
        }
        goto switchD_10040307_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_10040307_caseD_0;
      case 1:
        goto switchD_10040307_caseD_1;
      case 2:
        goto switchD_10040307_caseD_2;
      case 3:
        goto switchD_10040307_caseD_3;
      default:
        uVar1 = param_3 - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_10040307_caseD_2;
            case 3:
              goto switchD_10040307_caseD_3;
            }
            goto switchD_10040307_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_10040307_caseD_2;
            case 3:
              goto switchD_10040307_caseD_3;
            }
            goto switchD_10040307_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return param_1;
            case 2:
              goto switchD_10040307_caseD_2;
            case 3:
              goto switchD_10040307_caseD_3;
            }
            goto switchD_10040307_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_10040307_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return param_1;
    case 2:
switchD_10040307_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return param_1;
    case 3:
switchD_10040307_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return param_1;
    }
switchD_10040307_caseD_0:
    return param_1;
  }
  puVar3 = param_1;
  if (((uint)param_1 & 3) == 0) {
    uVar1 = param_3 >> 2;
    uVar2 = param_3 & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return param_1;
      case 2:
        goto switchD_10040185_caseD_2;
      case 3:
        goto switchD_10040185_caseD_3;
      }
      goto switchD_10040185_caseD_1;
    }
  }
  else {
    switch(param_3) {
    case 0:
      goto switchD_10040185_caseD_0;
    case 1:
      goto switchD_10040185_caseD_1;
    case 2:
      goto switchD_10040185_caseD_2;
    case 3:
      goto switchD_10040185_caseD_3;
    default:
      uVar1 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined4 *)((int)param_2 + 3);
        puVar3 = (undefined4 *)((int)param_1 + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_10040185_caseD_2;
          case 3:
            goto switchD_10040185_caseD_3;
          }
          goto switchD_10040185_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined4 *)((int)param_2 + 2);
        puVar3 = (undefined4 *)((int)param_1 + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_10040185_caseD_2;
          case 3:
            goto switchD_10040185_caseD_3;
          }
          goto switchD_10040185_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)param_1 + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *param_2;
            param_2 = param_2 + 1;
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return param_1;
          case 2:
            goto switchD_10040185_caseD_2;
          case 3:
            goto switchD_10040185_caseD_3;
          }
          goto switchD_10040185_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = param_2[uVar1 - 7];
  case 6:
    puVar3[uVar1 - 6] = param_2[uVar1 - 6];
  case 5:
    puVar3[uVar1 - 5] = param_2[uVar1 - 5];
  case 4:
    puVar3[uVar1 - 4] = param_2[uVar1 - 4];
  case 3:
    puVar3[uVar1 - 3] = param_2[uVar1 - 3];
  case 2:
    puVar3[uVar1 - 2] = param_2[uVar1 - 2];
  case 1:
    puVar3[uVar1 - 1] = param_2[uVar1 - 1];
    param_2 = param_2 + uVar1;
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_10040185_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return param_1;
  case 2:
switchD_10040185_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_10040185_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_10040185_caseD_0:
  return param_1;
}



/* FUN_1004228c @ 1004228c size 659 */

undefined4 __cdecl
FUN_1004228c(uint param_1,uint param_2,uint param_3,int param_4,byte param_5,short *param_6)

{
  short *psVar1;
  uint uVar2;
  short *psVar3;
  char cVar4;
  uint uVar5;
  short *psVar6;
  short *psVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined2 local_14;
  undefined4 local_12;
  undefined4 local_e;
  undefined1 local_a;
  char cStack_9;
  undefined4 local_8;
  
  psVar3 = param_6;
  uVar5 = param_3 & 0x7fff;
  local_20 = 0xcc;
  local_1f = 0xcc;
  local_1e = 0xcc;
  local_1d = 0xcc;
  local_1c = 0xcc;
  local_1b = 0xcc;
  local_1a = 0xcc;
  local_19 = 0xcc;
  local_18 = 0xcc;
  local_17 = 0xcc;
  local_16 = 0xfb;
  local_15 = 0x3f;
  local_8 = 1;
  if ((param_3 & 0x8000) == 0) {
    *(undefined1 *)(param_6 + 1) = 0x20;
  }
  else {
    *(undefined1 *)(param_6 + 1) = 0x2d;
  }
  if ((((short)uVar5 != 0) || (param_2 != 0)) || (param_1 != 0)) {
    if ((short)uVar5 == 0x7fff) {
      *param_6 = 1;
      if (((param_2 == 0x80000000) && (param_1 == 0)) || ((param_2 & 0x40000000) != 0)) {
        if (((param_3 & 0x8000) == 0) || (param_2 != 0xc0000000)) {
          if ((param_2 != 0x80000000) || (param_1 != 0)) goto LAB_10042381;
          pcVar11 = "1#INF";
        }
        else {
          if (param_1 != 0) {
LAB_10042381:
            pcVar11 = "1#QNAN";
            goto LAB_10042386;
          }
          pcVar11 = "1#IND";
        }
        FUN_10040000((uint *)(param_6 + 2),(uint *)pcVar11);
        *(undefined1 *)((int)psVar3 + 3) = 5;
      }
      else {
        pcVar11 = "1#SNAN";
LAB_10042386:
        FUN_10040000((uint *)(param_6 + 2),(uint *)pcVar11);
        *(undefined1 *)((int)psVar3 + 3) = 6;
      }
      return 0;
    }
    local_14 = 0;
    local_a = (undefined1)uVar5;
    cStack_9 = (char)(uVar5 >> 8);
    sVar8 = (short)(((uVar5 >> 8) + (param_2 >> 0x18) * 2) * 0x4d + -0x134312f4 + uVar5 * 0x4d10 >>
                   0x10);
    local_e = param_2;
    local_12 = param_1;
    FUN_10042afe((int *)&local_14,-(int)sVar8,1);
    if (0x3ffe < CONCAT11(cStack_9,local_a)) {
      sVar8 = sVar8 + 1;
      FUN_100428de((int *)&local_14,(int *)&local_20);
    }
    *psVar3 = sVar8;
    iVar10 = param_4;
    if (((param_5 & 1) == 0) || (iVar10 = param_4 + sVar8, 0 < param_4 + sVar8)) {
      if (0x15 < iVar10) {
        iVar10 = 0x15;
      }
      iVar9 = CONCAT11(cStack_9,local_a) - 0x3ffe;
      local_a = 0;
      cStack_9 = '\0';
      param_6 = (short *)0x8;
      do {
        FUN_1004216a((uint *)&local_14);
        param_6 = (short *)((int)param_6 + -1);
      } while (param_6 != (short *)0x0);
      if (iVar9 < 0) {
        param_6 = (short *)0x0;
        for (uVar5 = -iVar9 & 0xff; uVar5 != 0; uVar5 = uVar5 - 1) {
          FUN_10042198((uint *)&local_14);
        }
      }
      param_4 = iVar10 + 1;
      psVar6 = psVar3 + 2;
      param_6 = psVar6;
      uVar5 = local_12;
      uVar2 = local_e;
      if (0 < param_4) {
        do {
          local_e._2_2_ = (undefined2)(uVar2 >> 0x10);
          local_e._0_2_ = (undefined2)uVar2;
          local_12._2_2_ = (undefined2)(uVar5 >> 0x10);
          local_12._0_2_ = (undefined2)uVar5;
          param_1 = CONCAT22((undefined2)local_12,local_14);
          param_2 = CONCAT22((undefined2)local_e,local_12._2_2_);
          param_3 = CONCAT13(cStack_9,CONCAT12(local_a,local_e._2_2_));
          local_12 = uVar5;
          local_e = uVar2;
          FUN_1004216a((uint *)&local_14);
          FUN_1004216a((uint *)&local_14);
          ___add_12((uint *)&local_14,&param_1);
          FUN_1004216a((uint *)&local_14);
          cVar4 = cStack_9;
          cStack_9 = '\0';
          psVar6 = (short *)((int)param_6 + 1);
          param_4 = param_4 + -1;
          *(char *)param_6 = cVar4 + '0';
          param_6 = psVar6;
          uVar5 = local_12;
          uVar2 = local_e;
        } while (param_4 != 0);
      }
      psVar7 = psVar6 + -1;
      psVar1 = psVar3 + 2;
      if ('4' < *(char *)((int)psVar6 + -1)) {
        for (; psVar1 <= psVar7; psVar7 = (short *)((int)psVar7 + -1)) {
          if ((char)*psVar7 != '9') {
            if (psVar1 <= psVar7) goto LAB_100424de;
            break;
          }
          *(char *)psVar7 = '0';
        }
        psVar7 = (short *)((int)psVar7 + 1);
        *psVar3 = *psVar3 + 1;
LAB_100424de:
        *(char *)psVar7 = (char)*psVar7 + '\x01';
LAB_100424e0:
        cVar4 = ((char)psVar7 - (char)psVar3) + -3;
        *(char *)((int)psVar3 + 3) = cVar4;
        *(undefined1 *)(cVar4 + 4 + (int)psVar3) = 0;
        return local_8;
      }
      for (; psVar1 <= psVar7; psVar7 = (short *)((int)psVar7 + -1)) {
        if ((char)*psVar7 != '0') {
          if (psVar1 <= psVar7) goto LAB_100424e0;
          break;
        }
      }
      *psVar3 = 0;
      *(undefined1 *)(psVar3 + 1) = 0x20;
      *(undefined1 *)((int)psVar3 + 3) = 1;
      *(char *)psVar1 = '0';
      goto LAB_10042516;
    }
  }
  *psVar3 = 0;
  *(undefined1 *)(psVar3 + 1) = 0x20;
  *(undefined1 *)((int)psVar3 + 3) = 1;
  *(undefined1 *)(psVar3 + 2) = 0x30;
LAB_10042516:
  *(undefined1 *)((int)psVar3 + 5) = 0;
  return 1;
}



/* FUN_10005e30 @ 10005e30 size 652 */

void __cdecl FUN_10005e30(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  char *pcVar8;
  bool bVar9;
  
  iVar4 = *(int *)(param_2 + 0x54);
  if (((((iVar4 != 0) || ((*(byte *)(param_2 + 0xb8) & 4) != 0)) && (param_2 != param_1)) &&
      (iVar2 = *(int *)(param_1 + 0x25c), param_2 != iVar2)) &&
     ((uVar3 = *(uint *)(param_1 + 0x35c), (uVar3 & 0x100) == 0 ||
      ((iVar4 == 0 && ((*(uint *)(param_2 + 0x35c) & 0x100) == 0)))))) {
    if (iVar4 == 0) {
      if (((*(uint *)(param_1 + 0x108) ^ *(uint *)(param_2 + 0x108)) & 3) == 0) {
        pbVar6 = *(byte **)(param_2 + 0x118);
        pbVar5 = *(byte **)(param_1 + 0x118);
        pbVar7 = pbVar6;
        do {
          bVar1 = *pbVar5;
          bVar9 = bVar1 < *pbVar7;
          if (bVar1 != *pbVar7) {
LAB_10005f35:
            iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
            goto LAB_10005f3a;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar5[1];
          bVar9 = bVar1 < pbVar7[1];
          if (bVar1 != pbVar7[1]) goto LAB_10005f35;
          pbVar5 = pbVar5 + 2;
          pbVar7 = pbVar7 + 2;
        } while (bVar1 != 0);
        iVar4 = 0;
LAB_10005f3a:
        if (iVar4 != 0) {
          pcVar8 = s_monster_tank_10046608;
          pbVar5 = pbVar6;
          do {
            bVar1 = *pbVar5;
            bVar9 = bVar1 < (byte)*pcVar8;
            if (bVar1 != *pcVar8) {
LAB_10005f6d:
              iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
              goto LAB_10005f72;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar5[1];
            bVar9 = bVar1 < (byte)pcVar8[1];
            if (bVar1 != pcVar8[1]) goto LAB_10005f6d;
            pbVar5 = pbVar5 + 2;
            pcVar8 = pcVar8 + 2;
          } while (bVar1 != 0);
          iVar4 = 0;
LAB_10005f72:
          if (iVar4 != 0) {
            pcVar8 = s_monster_supertank_100465f4;
            pbVar5 = pbVar6;
            do {
              bVar1 = *pbVar5;
              bVar9 = bVar1 < (byte)*pcVar8;
              if (bVar1 != *pcVar8) {
LAB_10005fa5:
                iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
                goto LAB_10005faa;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar5[1];
              bVar9 = bVar1 < (byte)pcVar8[1];
              if (bVar1 != pcVar8[1]) goto LAB_10005fa5;
              pbVar5 = pbVar5 + 2;
              pcVar8 = pcVar8 + 2;
            } while (bVar1 != 0);
            iVar4 = 0;
LAB_10005faa:
            if (iVar4 != 0) {
              pcVar8 = s_monster_makron_100465e4;
              pbVar5 = pbVar6;
              do {
                bVar1 = *pbVar5;
                bVar9 = bVar1 < (byte)*pcVar8;
                if (bVar1 != *pcVar8) {
LAB_10005fdd:
                  iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
                  goto LAB_10005fe2;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar5[1];
                bVar9 = bVar1 < (byte)pcVar8[1];
                if (bVar1 != pcVar8[1]) goto LAB_10005fdd;
                pbVar5 = pbVar5 + 2;
                pcVar8 = pcVar8 + 2;
              } while (bVar1 != 0);
              iVar4 = 0;
LAB_10005fe2:
              if (iVar4 != 0) {
                pcVar8 = s_monster_jorg_100465d4;
                do {
                  bVar1 = *pbVar6;
                  bVar9 = bVar1 < (byte)*pcVar8;
                  if (bVar1 != *pcVar8) {
LAB_10006011:
                    iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
                    goto LAB_10006016;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar6[1];
                  bVar9 = bVar1 < (byte)pcVar8[1];
                  if (bVar1 != pcVar8[1]) goto LAB_10006011;
                  pbVar6 = pbVar6 + 2;
                  pcVar8 = pcVar8 + 2;
                } while (bVar1 != 0);
                iVar4 = 0;
LAB_10006016:
                if (iVar4 != 0) {
                  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x54) != 0)) {
                    *(int *)(param_1 + 0x260) = iVar2;
                  }
                  *(int *)(param_1 + 0x25c) = param_2;
                  if ((uVar3 & 0x800) != 0) {
                    return;
                  }
                  FUN_10001ac0(param_1);
                  return;
                }
              }
            }
          }
        }
      }
      if (*(int *)(param_2 + 0x25c) == param_1) {
        if ((iVar2 != 0) && (*(int *)(iVar2 + 0x54) != 0)) {
          *(int *)(param_1 + 0x260) = iVar2;
        }
        *(int *)(param_1 + 0x25c) = param_2;
        if ((uVar3 & 0x800) == 0) {
          FUN_10001ac0(param_1);
          return;
        }
      }
      else if (*(int *)(param_2 + 0x25c) != 0) {
        if ((iVar2 != 0) && (*(int *)(iVar2 + 0x54) != 0)) {
          *(int *)(param_1 + 0x260) = iVar2;
        }
        *(undefined4 *)(param_1 + 0x25c) = *(undefined4 *)(param_2 + 0x25c);
        if ((uVar3 & 0x800) == 0) {
          FUN_10001ac0(param_1);
        }
      }
    }
    else {
      *(uint *)(param_1 + 0x35c) = uVar3 & 0xfffffffb;
      if ((iVar2 != 0) && (*(int *)(iVar2 + 0x54) != 0)) {
        iVar4 = FUN_10001560(param_1,iVar2);
        if (iVar4 != 0) {
          *(int *)(param_1 + 0x260) = param_2;
          return;
        }
        *(undefined4 *)(param_1 + 0x260) = *(undefined4 *)(param_1 + 0x25c);
      }
      *(int *)(param_1 + 0x25c) = param_2;
      if ((*(uint *)(param_1 + 0x35c) & 0x800) == 0) {
        FUN_10001ac0(param_1);
        return;
      }
    }
  }
  return;
}



/* FUN_1003d484 @ 1003d484 size 647 */

void FUN_1003d484(void)

{
  char cVar1;
  char cVar2;
  uint *_Str1;
  DWORD DVar3;
  int iVar4;
  size_t sVar5;
  void *this;
  uint *_Source;
  int local_8;
  
  FUN_1003c8a1(0xc);
  DAT_10060070 = 0xffffffff;
  DAT_10060060 = 0xffffffff;
  DAT_10061cc0 = 0;
  _Str1 = (uint *)FUN_10040ce4("TZ");
  if (_Str1 == (uint *)0x0) {
    FUN_1003c902(0xc);
    DVar3 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_10061cc8);
    if (DVar3 == 0xffffffff) {
      return;
    }
    DAT_1005ffc8 = (void *)(DAT_10061cc8 * 0x3c);
    DAT_10061cc0 = 1;
    if (DAT_10061d0e != 0) {
      DAT_1005ffc8 = (void *)((int)DAT_1005ffc8 + DAT_10061d1c * 0x3c);
    }
    if ((DAT_10061d62 == 0) || (DAT_10061d70 == 0)) {
      DAT_1005ffcc = 0;
      DAT_1005ffd0 = 0;
    }
    else {
      DAT_1005ffcc = 1;
      DAT_1005ffd0 = (DAT_10061d70 - DAT_10061d1c) * 0x3c;
    }
    iVar4 = WideCharToMultiByte(DAT_10061dc8,0x220,(LPCWSTR)&DAT_10061ccc,-1,PTR_DAT_10060054,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((iVar4 == 0) || (local_8 != 0)) {
      *PTR_DAT_10060054 = 0;
    }
    else {
      PTR_DAT_10060054[0x3f] = 0;
    }
    iVar4 = WideCharToMultiByte(DAT_10061dc8,0x220,(LPCWSTR)&DAT_10061d20,-1,PTR_DAT_10060058,0x3f,
                                (LPCSTR)0x0,&local_8);
    if ((iVar4 != 0) && (local_8 == 0)) {
      PTR_DAT_10060058[0x3f] = 0;
      return;
    }
LAB_1003d6f5:
    *PTR_DAT_10060058 = 0;
  }
  else {
    if (((char)*_Str1 != '\0') &&
       ((DAT_10061d74 == (uint *)0x0 ||
        (iVar4 = _strcmp((char *)_Str1,(char *)DAT_10061d74), iVar4 != 0)))) {
      FUN_100396e7(DAT_10061d74);
      sVar5 = _strlen((char *)_Str1);
      DAT_10061d74 = _malloc(sVar5 + 1);
      if (DAT_10061d74 != (uint *)0x0) {
        FUN_10040000(DAT_10061d74,_Str1);
        FUN_1003c902(0xc);
        _strncpy(PTR_DAT_10060054,(char *)_Str1,3);
        _Source = (uint *)((int)_Str1 + 3);
        PTR_DAT_10060054[3] = 0;
        cVar1 = *(char *)_Source;
        if (cVar1 == '-') {
          _Source = _Str1 + 1;
        }
        iVar4 = FUN_100391ac(this,(byte *)_Source);
        DAT_1005ffc8 = (void *)(iVar4 * 0xe10);
        for (; (cVar2 = (char)*_Source, cVar2 == '+' || (('/' < cVar2 && (cVar2 < ':'))));
            _Source = (uint *)((int)_Source + 1)) {
        }
        if ((char)*_Source == ':') {
          _Source = (uint *)((int)_Source + 1);
          iVar4 = FUN_100391ac(DAT_1005ffc8,(byte *)_Source);
          DAT_1005ffc8 = (void *)((int)DAT_1005ffc8 + iVar4 * 0x3c);
          for (; ('/' < (char)*_Source && ((char)*_Source < ':'));
              _Source = (uint *)((int)_Source + 1)) {
          }
          if ((char)*_Source == ':') {
            _Source = (uint *)((int)_Source + 1);
            iVar4 = FUN_100391ac(DAT_1005ffc8,(byte *)_Source);
            DAT_1005ffc8 = (void *)((int)DAT_1005ffc8 + iVar4);
            for (; ('/' < (char)*_Source && ((char)*_Source < ':'));
                _Source = (uint *)((int)_Source + 1)) {
            }
          }
        }
        if (cVar1 == '-') {
          DAT_1005ffc8 = (void *)-(int)DAT_1005ffc8;
        }
        DAT_1005ffcc = (int)(char)*_Source;
        if (DAT_1005ffcc != 0) {
          _strncpy(PTR_DAT_10060058,(char *)_Source,3);
          PTR_DAT_10060058[3] = 0;
          return;
        }
        goto LAB_1003d6f5;
      }
    }
    FUN_1003c902(0xc);
  }
  return;
}



/* FUN_10035a10 @ 10035a10 size 644 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_10035a10(int param_1,int param_2,int param_3,int param_4,int param_5,int *param_6,int *param_7,
            undefined *param_8)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  
  iVar1 = *(int *)(param_1 + 0x54);
  iVar3 = *(int *)(iVar1 + 0xe20);
  if (iVar3 == 2) {
    iVar3 = *(int *)(iVar1 + 0x5c);
    if (*(int *)(iVar1 + 0x5c) == param_5) {
      FUN_10035420(param_1);
      return;
    }
  }
  else {
    if (iVar3 != 1) {
      if ((*(int *)(iVar1 + 0xdfc) != 0) && (iVar3 != 3)) {
        *(undefined4 *)(iVar1 + 0xe20) = 2;
        *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = param_4 + 1;
        return;
      }
      if (iVar3 == 0) {
        if (((*(uint *)(iVar1 + 0xdec) | *(uint *)(iVar1 + 0xdf4)) & 1) == 0) {
          iVar3 = param_3;
          if (*(int *)(iVar1 + 0x5c) != param_4) {
            if (param_6 != (int *)0x0) {
              iVar1 = *param_6;
              while (iVar1 != 0) {
                if ((*(int *)(*(int *)(param_1 + 0x54) + 0x5c) == *param_6) &&
                   (uVar4 = _rand(), (uVar4 & 0xf) != 0)) {
                  return;
                }
                piVar5 = param_6 + 1;
                param_6 = param_6 + 1;
                iVar1 = *piVar5;
              }
            }
            *(int *)(*(int *)(param_1 + 0x54) + 0x5c) =
                 *(int *)(*(int *)(param_1 + 0x54) + 0x5c) + 1;
            return;
          }
          goto LAB_10035bdc;
        }
        *(uint *)(iVar1 + 0xdf4) = *(uint *)(iVar1 + 0xdf4) & 0xfffffffe;
        iVar1 = *(int *)(param_1 + 0x54);
        if ((*(int *)(iVar1 + 0xde8) == 0) ||
           (*(int *)(*(int *)(iVar1 + 0x714) + 0x30) <=
            *(int *)(iVar1 + 0x2e4 + *(int *)(iVar1 + 0xde8) * 4))) {
          *(int *)(iVar1 + 0x5c) = param_2 + 1;
          *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe20) = 3;
          *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xea0) = 4;
          iVar1 = *(int *)(param_1 + 0x54);
          if ((*(byte *)(iVar1 + 0x10) & 1) == 0) {
            *(undefined4 *)(param_1 + 0x38) = 0x2d;
            *(undefined4 *)(iVar1 + 0xe9c) = 0x35;
          }
          else {
            *(undefined4 *)(param_1 + 0x38) = 0x9f;
            *(undefined4 *)(iVar1 + 0xe9c) = 0xa8;
          }
        }
        else {
          if (*(float *)(param_1 + 0x210) <= DAT_1006c2e4) {
            uVar2 = (*DAT_1006c1e4)(s_weapons_noammo_wav_1004b5c8,0x3f800000,0x3f800000,0);
            (*DAT_1006c1d0)(param_1,2,uVar2);
            *(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_10044104;
          }
          FUN_10035530(param_1);
        }
      }
      iVar1 = *(int *)(param_1 + 0x54);
      if (*(int *)(iVar1 + 0xe20) == 3) {
        iVar6 = 0;
        iVar3 = *param_7;
        if (iVar3 != 0) {
          piVar5 = param_7;
          do {
            if (*(int *)(iVar1 + 0x5c) == iVar3) {
              if ((float)DAT_1006c2e0 < *(float *)(iVar1 + 0xeac)) {
                uVar2 = (*DAT_1006c1e4)(s_items_damage3_wav_1005f96c,0x3f800000,0x3f800000,0);
                (*DAT_1006c1d0)(param_1,3,uVar2);
              }
              (*(code *)param_8)(param_1);
              break;
            }
            iVar3 = piVar5[1];
            piVar5 = piVar5 + 1;
            iVar6 = iVar6 + 1;
          } while (iVar3 != 0);
        }
        if (param_7[iVar6] == 0) {
          piVar5 = (int *)(*(int *)(param_1 + 0x54) + 0x5c);
          *piVar5 = *piVar5 + 1;
        }
        if (*(int *)(*(int *)(param_1 + 0x54) + 0x5c) == param_3 + 2) {
          *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe20) = 0;
        }
      }
      return;
    }
    iVar3 = *(int *)(iVar1 + 0x5c);
    if (*(int *)(iVar1 + 0x5c) == param_2) {
      *(undefined4 *)(iVar1 + 0xe20) = 0;
      *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = param_3 + 1;
      return;
    }
  }
LAB_10035bdc:
  *(int *)(iVar1 + 0x5c) = iVar3 + 1;
  return;
}



/* FUN_100022a0 @ 100022a0 size 642 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_100022a0(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  float10 fVar4;
  longlong lVar5;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(int *)(param_1 + 0x1dc) != 0) {
    uVar1 = *(uint *)(param_1 + 0x35c);
    if ((uVar1 & 0x1000) != 0) {
      return 0;
    }
    if ((uVar1 & 4) != 0) {
      if (DAT_1006c2e4 - *(float *)(*(int *)(param_1 + 0x25c) + 0x2a0) <= (float)_DAT_10044150) {
        lVar5 = __ftol();
        *(int *)(param_1 + 0x230) = (int)lVar5;
        return 0;
      }
      if (*(int *)(param_1 + 0x1dc) == *(int *)(param_1 + 0x25c)) {
        *(undefined4 *)(param_1 + 0x1dc) = *(undefined4 *)(param_1 + 0x1e0);
      }
      *(uint *)(param_1 + 0x35c) = uVar1 & 0xfffffffb;
      if ((uVar1 & 2) != 0) {
        *(uint *)(param_1 + 0x35c) = uVar1 & 0xfffffff8;
      }
    }
  }
  DAT_1006ca64 = 0;
  iVar2 = *(int *)(param_1 + 0x25c);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x58) != 0)) {
    uVar1 = *(uint *)(param_1 + 0x35c);
    if ((uVar1 & 0x2000) == 0) {
      if ((uVar1 & 0x200) == 0) {
        if (0 < *(int *)(iVar2 + 0x220)) goto LAB_100023bf;
      }
      else if (-0x50 < *(int *)(iVar2 + 0x220)) goto LAB_100023bf;
    }
    else {
      if (*(int *)(iVar2 + 0x220) < 1) goto LAB_100023bf;
      *(uint *)(param_1 + 0x35c) = uVar1 & 0xffffdfff;
    }
  }
  iVar2 = *(int *)(param_1 + 0x260);
  *(undefined4 *)(param_1 + 0x25c) = 0;
  if ((iVar2 == 0) || (*(int *)(iVar2 + 0x220) < 1)) {
    if (*(int *)(param_1 + 0x1e0) == 0) {
      *(float *)(param_1 + 0x390) = DAT_1006c2e4 + _DAT_10044148;
      (**(code **)(param_1 + 0x368))(param_1);
      return 1;
    }
    *(int *)(param_1 + 0x1dc) = *(int *)(param_1 + 0x1e0);
    (**(code **)(param_1 + 0x374))(param_1);
    return 1;
  }
  *(int *)(param_1 + 0x25c) = iVar2;
  *(undefined4 *)(param_1 + 0x260) = 0;
  FUN_10001690(param_1);
LAB_100023bf:
  lVar5 = __ftol();
  *(int *)(param_1 + 0x230) = (int)lVar5;
  DAT_1006ca64 = FUN_10001560(param_1,*(int *)(param_1 + 0x25c));
  if (DAT_1006ca64 != 0) {
    iVar2 = *(int *)(param_1 + 0x25c);
    *(float *)(param_1 + 0x3a4) = DAT_1006c2e4 + _DAT_1004414c;
    *(undefined4 *)(param_1 + 0x3ac) = *(undefined4 *)(iVar2 + 4);
    *(undefined4 *)(param_1 + 0x3b0) = *(undefined4 *)(iVar2 + 8);
    *(undefined4 *)(param_1 + 0x3b4) = *(undefined4 *)(iVar2 + 0xc);
  }
  _DAT_1006ca70 = FUN_10001600(param_1,*(int *)(param_1 + 0x25c));
  DAT_1006ca6c = FUN_100014e0(param_1,*(int *)(param_1 + 0x25c));
  iVar2 = *(int *)(param_1 + 0x25c);
  local_c = *(float *)(iVar2 + 4) - *(float *)(param_1 + 4);
  local_8 = *(float *)(iVar2 + 8) - *(float *)(param_1 + 8);
  local_4 = *(float *)(iVar2 + 0xc) - *(float *)(param_1 + 0xc);
  fVar4 = FUN_1001b160(&local_c);
  DAT_1006ca68 = (float)fVar4;
  if (*(int *)(param_1 + 0x3b8) == 4) {
    FUN_100021d0(param_1);
    return 1;
  }
  if (*(int *)(param_1 + 0x3b8) == 3) {
    FUN_10002190(param_1);
    return 1;
  }
  if (DAT_1006ca64 != 0) {
    uVar3 = (**(code **)(param_1 + 0x38c))(param_1);
    return uVar3;
  }
  return 0;
}



/* FUN_10035e20 @ 10035e20 size 642 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10035e20(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0x54);
  if ((*(int *)(iVar1 + 0xdfc) != 0) && (*(int *)(iVar1 + 0xe20) == 0)) {
    FUN_10035420(param_1);
    return;
  }
  iVar2 = *(int *)(iVar1 + 0xe20);
  if (iVar2 == 1) {
    *(undefined4 *)(iVar1 + 0xe20) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x5c) = 0x10;
    return;
  }
  if (iVar2 == 0) {
    if (((*(uint *)(iVar1 + 0xdec) | *(uint *)(iVar1 + 0xdf4)) & 1) != 0) {
      *(uint *)(iVar1 + 0xdf4) = *(uint *)(iVar1 + 0xdf4) & 0xfffffffe;
      iVar1 = *(int *)(param_1 + 0x54);
      if (*(int *)(iVar1 + 0x2e4 + *(int *)(iVar1 + 0xde8) * 4) == 0) {
        if (*(float *)(param_1 + 0x210) <= DAT_1006c2e4) {
          uVar3 = (*DAT_1006c1e4)(s_weapons_noammo_wav_1004b5c8,0x3f800000,0x3f800000,0);
          (*DAT_1006c1d0)(param_1,2,uVar3);
          *(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_10044104;
        }
        FUN_10035530(param_1);
        return;
      }
      *(undefined4 *)(iVar1 + 0x5c) = 1;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe20) = 3;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xec0) = 0;
      return;
    }
    iVar1 = *(int *)(iVar1 + 0x5c);
    if (((((iVar1 == 0x1d) || (iVar1 == 0x22)) || (iVar1 == 0x27)) || (iVar1 == 0x30)) &&
       (uVar4 = _rand(), (uVar4 & 0xf) != 0)) {
      return;
    }
    *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = *(int *)(*(int *)(param_1 + 0x54) + 0x5c) + 1;
    if (0x30 < *(int *)(*(int *)(param_1 + 0x54) + 0x5c)) {
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x5c) = 0x10;
      return;
    }
  }
  else if (iVar2 == 3) {
    if (*(int *)(iVar1 + 0x5c) == 5) {
      uVar3 = (*DAT_1006c1e4)(s_weapons_hgrena1b_wav_1005f980,0x3f800000,0x3f800000,0);
      (*DAT_1006c1d0)(param_1,1,uVar3);
    }
    iVar1 = *(int *)(param_1 + 0x54);
    if (*(int *)(iVar1 + 0x5c) == 0xb) {
      if (*(float *)(iVar1 + 0xec0) == _DAT_1004410c) {
        *(float *)(iVar1 + 0xec0) = DAT_1006c2e4 + (float)_DAT_10044458;
        uVar3 = (*DAT_1006c1e4)(s_weapons_hgrenc1b_wav_1004bf2c);
        *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xec8) = uVar3;
      }
      iVar1 = *(int *)(param_1 + 0x54);
      if ((*(int *)(iVar1 + 0xebc) == 0) && (*(float *)(iVar1 + 0xec0) <= DAT_1006c2e4)) {
        *(undefined4 *)(iVar1 + 0xec8) = 0;
        FUN_10035ca0(param_1,1);
        *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xebc) = 1;
      }
      iVar1 = *(int *)(param_1 + 0x54);
      if ((*(byte *)(iVar1 + 0xdec) & 1) != 0) {
        return;
      }
      if (*(int *)(iVar1 + 0xebc) != 0) {
        if (DAT_1006c2e4 < *(float *)(iVar1 + 0xec0)) {
          return;
        }
        *(undefined4 *)(iVar1 + 0x5c) = 0xf;
        *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xebc) = 0;
      }
    }
    if (*(int *)(*(int *)(param_1 + 0x54) + 0x5c) == 0xc) {
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xec8) = 0;
      FUN_10035ca0(param_1,0);
    }
    iVar1 = *(int *)(param_1 + 0x54);
    if ((*(int *)(iVar1 + 0x5c) != 0xf) || (*(float *)(iVar1 + 0xec0) <= DAT_1006c2e4)) {
      *(int *)(iVar1 + 0x5c) = *(int *)(iVar1 + 0x5c) + 1;
      if (*(int *)(*(int *)(param_1 + 0x54) + 0x5c) == 0x10) {
        *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xec0) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe20) = 0;
      }
    }
  }
  return;
}



/* FUN_10032530 @ 10032530 size 641 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10032530(int param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  
  if (_DAT_1006c3a8 == _DAT_1004410c) {
    DAT_1006ca58 = 0;
    iVar8 = 0;
    if (_DAT_1004410c < *(float *)(DAT_1006ca60 + 0x14)) {
      iVar7 = 0x3d0;
      do {
        if ((*(int *)(iVar7 + 0x58 + DAT_1006c2c4) != 0) &&
           (((int *)(iVar7 + DAT_1006c2c4))[0x88] < 1)) {
          FUN_10030cd0((int *)(iVar7 + DAT_1006c2c4));
        }
        iVar8 = iVar8 + 1;
        iVar7 = iVar7 + 0x3d0;
      } while ((float)iVar8 < *(float *)(DAT_1006ca60 + 0x14));
    }
    _DAT_1006c3a8 = DAT_1006c2e4;
    DAT_1006c3ac = *(char **)(param_1 + 0x238);
    pcVar2 = _strstr(DAT_1006c3ac,&DAT_1004b974);
    if (pcVar2 == (char *)0x0) {
      if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
        DAT_1006c3b0 = 1;
        return;
      }
    }
    else if ((*(float *)(DAT_1006c42c + 0x14) != _DAT_1004410c) &&
            (iVar8 = 0, _DAT_1004410c < *(float *)(DAT_1006ca60 + 0x14))) {
      iVar7 = 0x3d0;
      do {
        iVar1 = iVar7 + DAT_1006c2c4;
        if (*(int *)(iVar7 + 0x58 + DAT_1006c2c4) != 0) {
          iVar3 = 0x2e4;
          pbVar6 = &DAT_10046960;
          do {
            if ((*pbVar6 & 0x10) != 0) {
              *(undefined4 *)(iVar3 + *(int *)(iVar1 + 0x54)) = 0;
            }
            iVar3 = iVar3 + 4;
            pbVar6 = pbVar6 + 0x48;
          } while (iVar3 < 0x6e4);
        }
        iVar8 = iVar8 + 1;
        iVar7 = iVar7 + 0x3d0;
      } while ((float)iVar8 < *(float *)(DAT_1006ca60 + 0x14));
    }
    DAT_1006c3b0 = 0;
    uVar4 = FUN_1001ac00(0,0x118,(byte *)s_info_player_intermission_1004b23c);
    if (uVar4 == 0) {
      uVar4 = FUN_1001ac00(0,0x118,(byte *)s_info_player_start_1004b284);
      if (uVar4 == 0) {
        uVar4 = FUN_1001ac00(0,0x118,(byte *)s_info_player_deathmatch_1004b26c);
      }
    }
    else {
      uVar5 = _rand();
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        uVar4 = FUN_1001ac00(uVar4,0x118,(byte *)s_info_player_intermission_1004b23c);
        if (uVar4 == 0) {
          uVar4 = FUN_1001ac00(0,0x118,(byte *)s_info_player_intermission_1004b23c);
        }
      }
    }
    DAT_1006c3b4 = *(undefined4 *)(uVar4 + 4);
    iVar8 = 0;
    DAT_1006c3b8 = *(undefined4 *)(uVar4 + 8);
    DAT_1006c3bc = *(undefined4 *)(uVar4 + 0xc);
    DAT_1006c3c0 = *(undefined4 *)(uVar4 + 0x10);
    DAT_1006c3c4 = *(undefined4 *)(uVar4 + 0x14);
    DAT_1006c3c8 = *(undefined4 *)(uVar4 + 0x18);
    if (_DAT_1004410c < *(float *)(DAT_1006ca60 + 0x14)) {
      iVar7 = 0x3d0;
      do {
        if (*(int *)(DAT_1006c2c4 + iVar7 + 0x58) != 0) {
          FUN_100323b0(DAT_1006c2c4 + iVar7);
        }
        iVar8 = iVar8 + 1;
        iVar7 = iVar7 + 0x3d0;
      } while ((float)iVar8 < *(float *)(DAT_1006ca60 + 0x14));
    }
  }
  return;
}



/* FUN_10037790 @ 10037790 size 639 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10037790(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0x54);
  if ((*(int *)(iVar1 + 0xdfc) != 0) && (*(int *)(iVar1 + 0xe20) == 0)) {
    FUN_10035420(param_1);
    return;
  }
  iVar2 = *(int *)(iVar1 + 0xe20);
  if (iVar2 == 1) {
    *(undefined4 *)(iVar1 + 0xe20) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x5c) = 0x10;
    return;
  }
  if (iVar2 == 0) {
    if (((*(uint *)(iVar1 + 0xdec) | *(uint *)(iVar1 + 0xdf4)) & 1) != 0) {
      *(uint *)(iVar1 + 0xdf4) = *(uint *)(iVar1 + 0xdf4) & 0xfffffffe;
      iVar1 = *(int *)(param_1 + 0x54);
      if (*(int *)(iVar1 + 0x2e4 + *(int *)(iVar1 + 0xde8) * 4) == 0) {
        if (*(float *)(param_1 + 0x210) <= DAT_1006c2e4) {
          uVar3 = (*DAT_1006c1e4)(s_weapons_noammo_wav_1004b5c8,0x3f800000,0x3f800000,0);
          (*DAT_1006c1d0)(param_1,2,uVar3);
          *(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_10044104;
        }
        FUN_10035530(param_1);
        return;
      }
      *(undefined4 *)(iVar1 + 0x5c) = 1;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe20) = 3;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xec0) = 0;
      return;
    }
    iVar1 = *(int *)(iVar1 + 0x5c);
    if (((((iVar1 == 0x1d) || (iVar1 == 0x22)) || (iVar1 == 0x27)) || (iVar1 == 0x30)) &&
       (uVar4 = _rand(), (uVar4 & 0xf) != 0)) {
      return;
    }
    *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = *(int *)(*(int *)(param_1 + 0x54) + 0x5c) + 1;
    if (0x30 < *(int *)(*(int *)(param_1 + 0x54) + 0x5c)) {
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x5c) = 0x10;
      return;
    }
  }
  else if (iVar2 == 3) {
    if (*(int *)(iVar1 + 0x5c) == 5) {
      uVar3 = (*DAT_1006c1e4)(s_weapons_hgrena1b_wav_1005f980,0x3f800000,0x3f800000,0);
      (*DAT_1006c1d0)(param_1,1,uVar3);
    }
    iVar1 = *(int *)(param_1 + 0x54);
    if (*(int *)(iVar1 + 0x5c) == 0xb) {
      if (*(float *)(iVar1 + 0xec0) == _DAT_1004410c) {
        *(float *)(iVar1 + 0xec0) = DAT_1006c2e4 + (float)_DAT_10044458;
        uVar3 = (*DAT_1006c1e4)(s_weapons_hgrenc1b_wav_1004bf2c);
        *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xec8) = uVar3;
      }
      iVar1 = *(int *)(param_1 + 0x54);
      if ((*(int *)(iVar1 + 0xebc) == 0) && (*(float *)(iVar1 + 0xec0) <= DAT_1006c2e4)) {
        *(undefined4 *)(iVar1 + 0xec8) = 0;
        FUN_100376b0(param_1);
        *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xebc) = 1;
      }
      iVar1 = *(int *)(param_1 + 0x54);
      if ((*(byte *)(iVar1 + 0xdec) & 1) != 0) {
        return;
      }
      if (*(int *)(iVar1 + 0xebc) != 0) {
        if (DAT_1006c2e4 < *(float *)(iVar1 + 0xec0)) {
          return;
        }
        *(undefined4 *)(iVar1 + 0x5c) = 0xf;
        *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xebc) = 0;
      }
    }
    if (*(int *)(*(int *)(param_1 + 0x54) + 0x5c) == 0xc) {
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xec8) = 0;
      FUN_100376b0(param_1);
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xec0) = 0;
    }
    iVar1 = *(int *)(param_1 + 0x54);
    if ((*(int *)(iVar1 + 0x5c) != 0xf) || (*(float *)(iVar1 + 0xec0) <= DAT_1006c2e4)) {
      *(int *)(iVar1 + 0x5c) = *(int *)(iVar1 + 0x5c) + 1;
      if (*(int *)(*(int *)(param_1 + 0x54) + 0x5c) == 0x10) {
        *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe20) = 0;
      }
    }
  }
  return;
}



/* FUN_1002cef0 @ 1002cef0 size 632 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1002cef0(undefined4 *param_1)

{
  float fVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = (*DAT_1006c1e0)(s_models_monsters_soldier_tris_md2_1005c668);
  param_1[10] = uVar2;
  param_1[0xd9] = 0x3f99999a;
  param_1[0x2f] = 0xc1800000;
  param_1[0x30] = 0xc1800000;
  param_1[0x31] = 0xc1c00000;
  param_1[0x32] = 0x41800000;
  param_1[0x33] = 0x41800000;
  param_1[0x34] = 0x42000000;
  param_1[0x41] = 5;
  param_1[0x3e] = 2;
  param_1[100] = 100;
  if ((*(byte *)(param_1 + 0x47) & 8) != 0) {
    uVar3 = _rand();
    fVar1 = (float)(uVar3 & 0x7fff) * _DAT_10044108;
    if ((float)_DAT_10044320 <= fVar1) {
      if ((float)_DAT_10044128 <= fVar1) {
        if ((fVar1 < (float)_DAT_10044128) || ((float)_DAT_10044140 <= fVar1)) {
          if ((fVar1 < (float)_DAT_10044140) || ((float)_DAT_100443c8 <= fVar1)) {
            if ((fVar1 < (float)_DAT_100443c8) || ((float)_DAT_10044368 <= fVar1)) {
              param_1[0xe] = 0x1da;
            }
            else {
              param_1[0xe] = 0x1d0;
            }
          }
          else {
            param_1[0xe] = 0x1b8;
          }
        }
        else {
          param_1[0xe] = 0x183;
        }
      }
      else {
        param_1[0xe] = 0x156;
      }
    }
    else {
      param_1[0xe] = 0x133;
    }
    param_1[0xf] = param_1[0xf] | 1;
    param_1[0x8b] = 2;
    param_1[0x2f] = 0xc1800000;
    param_1[0x30] = 0xc1800000;
    param_1[0x31] = 0xc1c00000;
    param_1[0x32] = 0x41800000;
    param_1[0x33] = 0x41800000;
    param_1[0x34] = 0xc1000000;
    param_1[0x2e] = param_1[0x2e] | 2;
    param_1[0x7b] = 0;
    (*DAT_1006c208)(param_1);
    return;
  }
  _DAT_10061314 = (*DAT_1006c1e4)(s_soldier_solidle1_wav_1005c650);
  DAT_10061304 = (*DAT_1006c1e4)(s_soldier_solsght1_wav_1005c638);
  DAT_10061300 = (*DAT_1006c1e4)(s_soldier_solsrch1_wav_1005c620);
  _DAT_10061310 = (*DAT_1006c1e4)(s_infantry_infatck3_wav_10057674);
  param_1[0x81] = FUN_1002c400;
  param_1[0x82] = &LAB_1002cd90;
  param_1[0xda] = FUN_1002c2d0;
  param_1[0xdd] = &LAB_1002c360;
  param_1[0xde] = &LAB_1002c3b0;
  param_1[0xdf] = &LAB_1002cc90;
  param_1[0xe0] = FUN_1002cb80;
  param_1[0xe1] = 0;
  param_1[0xe2] = &LAB_1002cbe0;
  (*DAT_1006c208)(param_1);
  (*(code *)param_1[0xda])(param_1);
  FUN_10012b30(param_1);
  return;
}



/* FUN_10015250 @ 10015250 size 619 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10015250(float param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  bool bVar4;
  byte *pbVar5;
  uint uVar6;
  undefined *puVar7;
  int iVar8;
  float fStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  pbVar5 = *(byte **)((int)param_1 + 0x128);
  bVar4 = true;
  if (pbVar5 != (byte *)0x0) {
    while( true ) {
      uVar6 = FUN_1001ad80(pbVar5);
      if (uVar6 == 0) {
        (*DAT_1006c1c4)(s_train_next__bad_target__s_1004676c,*(undefined4 *)((int)param_1 + 0x128));
        return;
      }
      *(undefined4 *)((int)param_1 + 0x128) = *(undefined4 *)(uVar6 + 0x128);
      if ((*(byte *)(uVar6 + 0x11c) & 1) == 0) break;
      if (!bVar4) {
        iVar8 = uVar6 + 4;
        puVar7 = FUN_1001b070();
        (*DAT_1006c1c4)(s_connected_teleport_path_corners__1004673c,*(undefined4 *)(uVar6 + 0x118),
                        puVar7,iVar8);
        return;
      }
      uVar1 = *(undefined4 *)(uVar6 + 4);
      *(undefined4 *)((int)param_1 + 4) = uVar1;
      uVar2 = *(undefined4 *)(uVar6 + 8);
      *(undefined4 *)((int)param_1 + 8) = uVar2;
      uVar3 = *(undefined4 *)(uVar6 + 0xc);
      bVar4 = false;
      *(undefined4 *)((int)param_1 + 0xc) = uVar3;
      *(undefined4 *)((int)param_1 + 0x1c) = uVar1;
      *(undefined4 *)((int)param_1 + 0x20) = uVar2;
      *(undefined4 *)((int)param_1 + 0x24) = uVar3;
      (*DAT_1006c208)(param_1);
      pbVar5 = *(byte **)((int)param_1 + 0x128);
      if (pbVar5 == (byte *)0x0) {
        return;
      }
    }
    *(undefined4 *)((int)param_1 + 0x32c) = *(undefined4 *)(uVar6 + 0x290);
    *(uint *)((int)param_1 + 0x144) = uVar6;
    if ((*(uint *)((int)param_1 + 0x108) & 0x400) == 0) {
      if (*(int *)((int)param_1 + 0x310) != 0) {
        (*DAT_1006c1d0)(param_1,10,*(int *)((int)param_1 + 0x310),0x3f800000,0x40400000,0);
      }
      *(undefined4 *)((int)param_1 + 0x4c) = *(undefined4 *)((int)param_1 + 0x314);
    }
    if (*(float *)(uVar6 + 0x298) <= _DAT_1004410c) {
      *(undefined4 *)((int)param_1 + 0x298) = 0;
    }
    else {
      *(undefined4 *)((int)param_1 + 0x298) = *(undefined4 *)(uVar6 + 0x298);
    }
    if (*(float *)(uVar6 + 0x148) != _DAT_1004410c) {
      *(undefined4 *)((int)param_1 + 800) = *(undefined4 *)(uVar6 + 0x148);
    }
    iVar8 = FUN_100388c0((float *)(uVar6 + 0x1d0),(float *)&DAT_10061c18);
    if (iVar8 == 0) {
      *(float *)((int)param_1 + 0x1d0) = *(float *)(uVar6 + 0x1d0);
      *(undefined4 *)((int)param_1 + 0x1d4) = *(undefined4 *)(uVar6 + 0x1d4);
      *(undefined4 *)((int)param_1 + 0x1d8) = *(undefined4 *)(uVar6 + 0x1d8);
    }
    else {
      *(undefined4 *)((int)param_1 + 0x1d8) = 0;
      *(undefined4 *)((int)param_1 + 0x1d4) = 0;
      *(undefined4 *)((int)param_1 + 0x1d0) = 0;
    }
    iVar8 = FUN_100388c0((float *)(uVar6 + 0x1ac),(float *)&DAT_10061c18);
    if (iVar8 == 0) {
      *(float *)((int)param_1 + 0x1ac) = *(float *)(uVar6 + 0x1ac);
      *(undefined4 *)((int)param_1 + 0x1b0) = *(undefined4 *)(uVar6 + 0x1b0);
      *(undefined4 *)((int)param_1 + 0x1b4) = *(undefined4 *)(uVar6 + 0x1b4);
    }
    else {
      *(undefined4 *)((int)param_1 + 0x1b4) = 0;
      *(undefined4 *)((int)param_1 + 0x1b0) = 0;
      *(undefined4 *)((int)param_1 + 0x1ac) = 0;
    }
    fStack_c = *(float *)(uVar6 + 4);
    uStack_8 = *(undefined4 *)(uVar6 + 8);
    uStack_4 = *(undefined4 *)(uVar6 + 0xc);
    *(undefined4 *)((int)param_1 + 0x2e0) = *(undefined4 *)((int)param_1 + 4);
    *(undefined4 *)((int)param_1 + 0x2e8) = *(undefined4 *)((int)param_1 + 0xc);
    *(float *)((int)param_1 + 0x2f8) = fStack_c;
    *(undefined4 *)((int)param_1 + 0x2e4) = *(undefined4 *)((int)param_1 + 8);
    *(undefined4 *)((int)param_1 + 0x330) = 0;
    *(undefined4 *)((int)param_1 + 0x2fc) = uStack_8;
    *(undefined4 *)((int)param_1 + 0x300) = uStack_4;
    FUN_10014c50(param_1,&fStack_c,&LAB_10015140);
    *(uint *)((int)param_1 + 0x11c) = *(uint *)((int)param_1 + 0x11c) | 1;
  }
  return;
}



/* FUN_1002a0c0 @ 1002a0c0 size 609 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1002a0c0(int param_1)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  int iStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float local_80;
  float local_7c;
  float fStack_74;
  float afStack_70 [5];
  float fStack_5c;
  undefined1 auStack_38 [56];
  
  iVar4 = 0;
  local_a0 = *(float *)(param_1 + 0xbc) + *(float *)(param_1 + 4);
  local_9c = *(float *)(param_1 + 0xc0) + *(float *)(param_1 + 8);
  local_98 = *(float *)(param_1 + 0xc4) + *(float *)(param_1 + 0xc);
  local_80 = *(float *)(param_1 + 200) + *(float *)(param_1 + 4);
  local_7c = *(float *)(param_1 + 0xcc) + *(float *)(param_1 + 8);
  local_a4 = local_98 - _DAT_10044104;
  do {
    iVar3 = 0;
    do {
      if (iVar4 == 0) {
        local_ac = local_a0;
      }
      else {
        local_ac = local_80;
      }
      if (iVar3 == 0) {
        local_a8 = local_9c;
      }
      else {
        local_a8 = local_7c;
      }
      iVar1 = (*DAT_1006c1f4)(&local_ac);
      if (iVar1 != 1) {
        local_ac = (local_80 + local_a0) * (float)_DAT_10044140;
        local_a4 = local_98;
        DAT_100620cc = DAT_100620cc + 1;
        local_a8 = (local_7c + local_9c) * (float)_DAT_10044140;
        fStack_88 = local_98 - _DAT_100443a4;
        fStack_90 = local_ac;
        fStack_8c = local_a8;
        pfVar2 = (float *)(*DAT_1006c1f0)(afStack_70,&local_ac,&DAT_10061c18,&DAT_10061c18,
                                          &fStack_90,param_1,0x2020003);
        pfVar5 = afStack_70;
        for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
          *pfVar5 = *pfVar2;
          pfVar2 = pfVar2 + 1;
          pfVar5 = pfVar5 + 1;
        }
        if (afStack_70[2] == (float)_DAT_10044120) {
          return 0;
        }
        iStack_94 = 0;
        fStack_84 = fStack_5c;
        fStack_74 = fStack_5c;
        do {
          iVar4 = 0;
          do {
            local_ac = local_a0;
            if (iStack_94 != 0) {
              local_ac = local_80;
            }
            local_a8 = local_9c;
            if (iVar4 != 0) {
              local_a8 = local_7c;
            }
            fStack_90 = local_ac;
            fStack_8c = local_a8;
            pfVar2 = (float *)(*DAT_1006c1f0)(auStack_38,&local_ac,&DAT_10061c18,&DAT_10061c18,
                                              &fStack_90,param_1,0x2020003);
            pfVar5 = afStack_70;
            for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
              *pfVar5 = *pfVar2;
              pfVar2 = pfVar2 + 1;
              pfVar5 = pfVar5 + 1;
            }
            if ((afStack_70[2] != (float)_DAT_10044120) && (fStack_84 < fStack_5c)) {
              fStack_84 = fStack_5c;
            }
            if (afStack_70[2] == (float)_DAT_10044120) {
              return 0;
            }
            if (_DAT_100443a0 < fStack_74 - fStack_5c) {
              return 0;
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < 2);
          iStack_94 = iStack_94 + 1;
        } while (iStack_94 < 2);
        goto LAB_1002a306;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
    iVar4 = iVar4 + 1;
    if (1 < iVar4) {
LAB_1002a306:
      DAT_100620c8 = DAT_100620c8 + 1;
      return 1;
    }
  } while( true );
}



/* FUN_10008d30 @ 10008d30 size 599 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10008d30(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  undefined4 uVar3;
  
  pfVar1 = (float *)(param_1 + 0x154);
  FUN_1001b0c0((float *)(param_1 + 0x10),pfVar1);
  *(undefined4 *)(param_1 + 0x104) = 3;
  *(undefined4 *)(param_1 + 0xf8) = 3;
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  if (*(int *)(param_1 + 0x250) != 1) {
    uVar3 = (*DAT_1006c1e4)(s_switches_butn2_wav_10046694);
    *(undefined4 *)(param_1 + 0x310) = uVar3;
  }
  if (*(float *)(param_1 + 0x148) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x148) = 0x42200000;
  }
  if (*(float *)(param_1 + 0x14c) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_1 + 0x148);
  }
  if (*(float *)(param_1 + 0x150) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(param_1 + 0x148);
  }
  if (*(float *)(param_1 + 0x290) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x290) = 0x40400000;
  }
  if (DAT_1006c298 == 0) {
    DAT_1006c298 = 4;
  }
  pfVar2 = (float *)(param_1 + 0x160);
  *pfVar2 = *(float *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(param_1 + 0xc);
  FUN_10038950(pfVar2,(ABS(*pfVar1) * *(float *)(param_1 + 0xec) +
                      ABS(*(float *)(param_1 + 0x158)) * *(float *)(param_1 + 0xf0) +
                      ABS(*(float *)(param_1 + 0x15c)) * *(float *)(param_1 + 0xf4)) -
                      (float)DAT_1006c298,pfVar1,(float *)(param_1 + 0x16c));
  *(undefined1 **)(param_1 + 0x200) = &LAB_10008cb0;
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x400;
  if (*(int *)(param_1 + 0x220) == 0) {
    if (*(int *)(param_1 + 300) == 0) {
      *(undefined1 **)(param_1 + 0x1fc) = &LAB_10008cd0;
    }
  }
  else {
    *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x220);
    *(undefined1 **)(param_1 + 0x208) = &LAB_10008d00;
    *(undefined4 *)(param_1 + 0x240) = 1;
  }
  *(undefined4 *)(param_1 + 800) = *(undefined4 *)(param_1 + 0x148);
  *(undefined4 *)(param_1 + 0x31c) = *(undefined4 *)(param_1 + 0x14c);
  *(undefined4 *)(param_1 + 0x324) = *(undefined4 *)(param_1 + 0x150);
  *(undefined4 *)(param_1 + 0x32c) = *(undefined4 *)(param_1 + 0x290);
  *(float *)(param_1 + 0x2e0) = *pfVar2;
  *(undefined4 *)(param_1 + 0x2e4) = *(undefined4 *)(param_1 + 0x164);
  *(undefined4 *)(param_1 + 0x2e8) = *(undefined4 *)(param_1 + 0x168);
  *(undefined4 *)(param_1 + 0x2ec) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x2f0) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x2f4) = *(undefined4 *)(param_1 + 0x18);
  *(float *)(param_1 + 0x2f8) = *(float *)(param_1 + 0x16c);
  *(undefined4 *)(param_1 + 0x2fc) = *(undefined4 *)(param_1 + 0x170);
  *(undefined4 *)(param_1 + 0x300) = *(undefined4 *)(param_1 + 0x174);
  *(undefined4 *)(param_1 + 0x330) = 1;
  *(undefined4 *)(param_1 + 0x304) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x308) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x30c) = *(undefined4 *)(param_1 + 0x18);
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10042c81 @ 10042c81 size 597 */

int __cdecl
FUN_10042c81(LCID param_1,DWORD param_2,byte *param_3,int param_4,byte *param_5,int param_6,
            UINT param_7)

{
  undefined1 *puVar1;
  int iVar2;
  BOOL BVar3;
  BYTE *pBVar4;
  int iVar5;
  _cpinfo local_40;
  undefined1 *local_2c;
  PCNZWCH local_28;
  int local_24;
  int local_20;
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_10044b38;
  puStack_10 = &LAB_10042634;
  local_14 = ExceptionList;
  local_1c = &stack0xffffffb0;
  ExceptionList = &local_14;
  puVar1 = &stack0xffffffb0;
  if (DAT_10061fdc == 0) {
    ExceptionList = &local_14;
    iVar2 = CompareStringW(0,0,L"",1,L"",1);
    if (iVar2 == 0) {
      iVar2 = CompareStringA(0,0,"",1,"",1);
      if (iVar2 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_10061fdc = 2;
      puVar1 = local_1c;
    }
    else {
      DAT_10061fdc = 1;
      puVar1 = local_1c;
    }
  }
  local_1c = puVar1;
  if (0 < param_4) {
    param_4 = FUN_10042efe((char *)param_3,param_4);
  }
  if (0 < param_6) {
    param_6 = FUN_10042efe((char *)param_5,param_6);
  }
  if (DAT_10061fdc == 2) {
    iVar2 = CompareStringA(param_1,param_2,(PCNZCH)param_3,param_4,(PCNZCH)param_5,param_6);
    ExceptionList = local_14;
    return iVar2;
  }
  if (DAT_10061fdc == 1) {
    if (param_7 == 0) {
      param_7 = DAT_10061dc8;
    }
    if ((param_4 == 0) || (param_6 == 0)) {
      if (param_4 == param_6) {
        ExceptionList = local_14;
        return 2;
      }
      if (1 < param_6) {
        ExceptionList = local_14;
        return 1;
      }
      if (1 < param_4) {
        ExceptionList = local_14;
        return 3;
      }
      BVar3 = GetCPInfo(param_7,&local_40);
      if (BVar3 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      if (0 < param_4) {
        if (local_40.MaxCharSize < 2) {
          ExceptionList = local_14;
          return 3;
        }
        pBVar4 = local_40.LeadByte;
        while( true ) {
          if (local_40.LeadByte[0] == 0) {
            ExceptionList = local_14;
            return 3;
          }
          if (pBVar4[1] == 0) break;
          if ((*pBVar4 <= *param_3) && (*param_3 <= pBVar4[1])) {
            ExceptionList = local_14;
            return 2;
          }
          pBVar4 = pBVar4 + 2;
          local_40.LeadByte[0] = *pBVar4;
        }
        ExceptionList = local_14;
        return 3;
      }
      if (0 < param_6) {
        if (local_40.MaxCharSize < 2) {
          ExceptionList = local_14;
          return 1;
        }
        pBVar4 = local_40.LeadByte;
        while( true ) {
          if (local_40.LeadByte[0] == 0) {
            ExceptionList = local_14;
            return 1;
          }
          if (pBVar4[1] == 0) break;
          if ((*pBVar4 <= *param_5) && (*param_5 <= pBVar4[1])) {
            ExceptionList = local_14;
            return 2;
          }
          pBVar4 = pBVar4 + 2;
          local_40.LeadByte[0] = *pBVar4;
        }
        ExceptionList = local_14;
        return 1;
      }
    }
    local_20 = MultiByteToWideChar(param_7,9,(LPCSTR)param_3,param_4,(LPWSTR)0x0,0);
    if (local_20 != 0) {
      local_8 = 0;
      FUN_10039f80();
      local_8 = 0xffffffff;
      if ((&stack0x00000000 != (undefined1 *)0x50) &&
         (local_28 = (PCNZWCH)&stack0xffffffb0, local_1c = &stack0xffffffb0,
         iVar2 = MultiByteToWideChar(param_7,1,(LPCSTR)param_3,param_4,(LPWSTR)&stack0xffffffb0,
                                     local_20), iVar2 != 0)) {
        iVar2 = MultiByteToWideChar(param_7,9,(LPCSTR)param_5,param_6,(LPWSTR)0x0,0);
        if (iVar2 != 0) {
          local_8 = 1;
          local_24 = iVar2;
          FUN_10039f80();
          local_8 = 0xffffffff;
          if ((&stack0x00000000 != (undefined1 *)0x50) &&
             (local_2c = &stack0xffffffb0, local_1c = &stack0xffffffb0,
             iVar5 = MultiByteToWideChar(param_7,1,(LPCSTR)param_5,param_6,(LPWSTR)&stack0xffffffb0,
                                         iVar2), iVar5 != 0)) {
            iVar2 = CompareStringW(param_1,param_2,local_28,local_20,(PCNZWCH)&stack0xffffffb0,iVar2
                                  );
            ExceptionList = local_14;
            return iVar2;
          }
        }
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}



/* FUN_10001f40 @ 10001f40 size 583 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10001f40(float param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  undefined4 local_38 [13];
  int iStack_4;
  
  fVar3 = param_1;
  iVar1 = *(int *)((int)param_1 + 0x25c);
  if (0 < *(int *)(iVar1 + 0x220)) {
    local_44 = *(undefined4 *)((int)param_1 + 4);
    local_40 = *(undefined4 *)((int)param_1 + 8);
    local_3c = (float)*(int *)((int)param_1 + 0x23c) + *(float *)((int)param_1 + 0xc);
    local_50 = *(undefined4 *)(iVar1 + 4);
    local_4c = *(undefined4 *)(iVar1 + 8);
    local_48 = (float)*(int *)(iVar1 + 0x23c) + *(float *)(iVar1 + 0xc);
    puVar4 = (undefined4 *)(*DAT_1006c1f0)(local_38,&local_44,0,0,&local_50,param_1,0x200001b);
    iVar1 = *(int *)((int)param_1 + 0x25c);
    puVar7 = local_38;
    for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar7 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar7 = puVar7 + 1;
    }
    if (iStack_4 != iVar1) {
      return 0;
    }
  }
  if (DAT_1006ca6c == 0) {
    if ((*(float *)(DAT_1006c41c + 0x14) != _DAT_1004410c) || (uVar5 = _rand(), (uVar5 & 3) == 0)) {
      if (*(int *)((int)param_1 + 900) != 0) {
        *(undefined4 *)((int)param_1 + 0x3b8) = 3;
        return 1;
      }
      *(undefined4 *)((int)param_1 + 0x3b8) = 4;
      return 1;
    }
  }
  else if (((*(int *)((int)param_1 + 0x380) != 0) &&
           (*(float *)((int)param_1 + 0x394) <= DAT_1006c2e4)) && (DAT_1006ca6c != 3)) {
    if ((*(byte *)((int)param_1 + 0x35c) & 1) == 0) {
      if (DAT_1006ca6c == 1) {
        param_1 = 0.1;
      }
      else {
        if (DAT_1006ca6c != 2) {
          return 0;
        }
        param_1 = 0.02;
      }
    }
    else {
      param_1 = 0.4;
    }
    if (*(float *)(DAT_1006c41c + 0x14) == _DAT_1004410c) {
      param_1 = param_1 * (float)_DAT_10044140;
    }
    else if (_DAT_1004413c <= *(float *)(DAT_1006c41c + 0x14)) {
      param_1 = param_1 + param_1;
    }
    uVar5 = _rand();
    if ((float)(uVar5 & 0x7fff) * _DAT_10044108 < param_1) {
      *(undefined4 *)((int)fVar3 + 0x3b8) = 4;
      uVar5 = _rand();
      fVar2 = (float)(uVar5 & 0x7fff) * _DAT_10044108;
      *(float *)((int)fVar3 + 0x394) = fVar2 + fVar2 + DAT_1006c2e4;
      return 1;
    }
    if ((*(byte *)((int)fVar3 + 0x108) & 1) != 0) {
      uVar5 = _rand();
      if ((float)(uVar5 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044128) {
        *(undefined4 *)((int)fVar3 + 0x3b8) = 2;
        return 0;
      }
      *(undefined4 *)((int)fVar3 + 0x3b8) = 1;
    }
  }
  return 0;
}



/* FUN_10009fa0 @ 10009fa0 size 580 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10009fa0(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  bool bVar4;
  float fVar5;
  undefined4 uVar6;
  
  pfVar1 = (float *)(param_1 + 0x154);
  FUN_1001b0c0((float *)(param_1 + 0x10),pfVar1);
  *(undefined4 *)(param_1 + 0x104) = 2;
  *(undefined4 *)(param_1 + 0xf8) = 3;
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  if ((*(int *)(param_1 + 0x250) == 1) || (*(int *)(param_1 + 0x250) == 2)) {
    uVar6 = (*DAT_1006c1e4)(s_world_mov_watr_wav_10046728);
    *(undefined4 *)(param_1 + 0x310) = uVar6;
    uVar6 = (*DAT_1006c1e4)(s_world_stp_watr_wav_10046714);
    *(undefined4 *)(param_1 + 0x318) = uVar6;
  }
  pfVar2 = (float *)(param_1 + 0x160);
  pfVar3 = (float *)(param_1 + 0x16c);
  *pfVar2 = *(float *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(param_1 + 0xc);
  fVar5 = (ABS(*pfVar1) * *(float *)(param_1 + 0xec) +
          ABS(*(float *)(param_1 + 0x158)) * *(float *)(param_1 + 0xf0) +
          ABS(*(float *)(param_1 + 0x15c)) * *(float *)(param_1 + 0xf4)) - (float)DAT_1006c298;
  *(float *)(param_1 + 0x328) = fVar5;
  FUN_10038950(pfVar2,fVar5,pfVar1,pfVar3);
  if ((*(uint *)(param_1 + 0x11c) & 1) != 0) {
    *(float *)(param_1 + 4) = *pfVar3;
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x170);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x174);
    *pfVar3 = *pfVar2;
    *(undefined4 *)(param_1 + 0x170) = *(undefined4 *)(param_1 + 0x164);
    *(undefined4 *)(param_1 + 0x174) = *(undefined4 *)(param_1 + 0x168);
    *pfVar2 = *(float *)(param_1 + 4);
    *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(param_1 + 0xc);
  }
  *(float *)(param_1 + 0x2e0) = *pfVar2;
  *(undefined4 *)(param_1 + 0x2e8) = *(undefined4 *)(param_1 + 0x168);
  bVar4 = *(float *)(param_1 + 0x148) == _DAT_1004410c;
  *(undefined4 *)(param_1 + 0x2e4) = *(undefined4 *)(param_1 + 0x164);
  *(undefined4 *)(param_1 + 0x2f0) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x2ec) = *(undefined4 *)(param_1 + 0x10);
  *(float *)(param_1 + 0x2f8) = *pfVar3;
  *(undefined4 *)(param_1 + 0x2f4) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x300) = *(undefined4 *)(param_1 + 0x174);
  *(undefined4 *)(param_1 + 0x2fc) = *(undefined4 *)(param_1 + 0x170);
  *(undefined4 *)(param_1 + 0x308) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x304) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x330) = 1;
  *(undefined4 *)(param_1 + 0x30c) = *(undefined4 *)(param_1 + 0x18);
  if (bVar4) {
    *(undefined4 *)(param_1 + 0x148) = 0x41c80000;
  }
  uVar6 = *(undefined4 *)(param_1 + 0x148);
  *(undefined4 *)(param_1 + 800) = uVar6;
  *(undefined4 *)(param_1 + 0x324) = uVar6;
  *(undefined4 *)(param_1 + 0x31c) = uVar6;
  if (*(float *)(param_1 + 0x290) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x290) = 0xbf800000;
  }
  *(code **)(param_1 + 0x200) = FUN_10009340;
  *(int *)(param_1 + 0x32c) = *(int *)(param_1 + 0x290);
  if (*(int *)(param_1 + 0x290) == -0x40800000) {
    *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) | 0x20;
  }
  *(char **)(param_1 + 0x118) = s_func_door_100466cc;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10018540 @ 10018540 size 579 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10018540(uint param_1)

{
  uint uVar1;
  int iVar2;
  float *pfVar3;
  uint uVar4;
  float *pfVar5;
  float local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  float local_94;
  undefined4 local_90;
  undefined4 local_8c;
  float local_88;
  float local_84;
  float local_80;
  float afStack_7c [4];
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined1 auStack_64 [28];
  uint uStack_48;
  float local_44 [3];
  undefined1 local_38 [56];
  
  uVar1 = *(uint *)(param_1 + 0x11c);
  iVar2 = *(int *)(param_1 + 0x25c);
  if (iVar2 != 0) {
    local_94 = *(float *)(param_1 + 0x154);
    local_90 = *(undefined4 *)(param_1 + 0x158);
    pfVar3 = (float *)(param_1 + 0x154);
    local_8c = *(undefined4 *)(param_1 + 0x15c);
    FUN_10038950((float *)(iVar2 + 0xd4),0.5,(float *)(iVar2 + 0xec),&local_88);
    *pfVar3 = local_88 - *(float *)(param_1 + 4);
    *(float *)(param_1 + 0x158) = local_84 - *(float *)(param_1 + 8);
    *(float *)(param_1 + 0x15c) = local_80 - *(float *)(param_1 + 0xc);
    FUN_10038900(pfVar3);
    iVar2 = FUN_100388c0(pfVar3,&local_94);
    if (iVar2 == 0) {
      *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) | 0x80000000;
    }
  }
  local_a0 = *(float *)(param_1 + 4);
  local_9c = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x100) = DAT_1006c2c4;
  local_98 = *(undefined4 *)(param_1 + 0xc);
  FUN_10038950(&local_a0,2048.0,(float *)(param_1 + 0x154),local_44);
  uVar4 = param_1;
  while( true ) {
    pfVar3 = (float *)(*DAT_1006c1f0)(local_38,&local_a0,0,0,local_44,uVar4,0x6000001);
    pfVar5 = afStack_7c;
    for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
      *pfVar5 = *pfVar3;
      pfVar3 = pfVar3 + 1;
      pfVar5 = pfVar5 + 1;
    }
    if (uStack_48 == 0) goto LAB_10018751;
    if ((*(int *)(uStack_48 + 0x240) != 0) && ((*(byte *)(uStack_48 + 0x108) & 4) == 0)) {
      FUN_100060d0(uStack_48,param_1,*(uint *)(param_1 + 0x264),(float *)(param_1 + 0x154),
                   afStack_7c + 3,&DAT_10061c18,*(int *)(param_1 + 0x244),1,4,0x1e);
    }
    if (((*(byte *)(uStack_48 + 0xb8) & 4) == 0) && (*(int *)(uStack_48 + 0x54) == 0)) break;
    local_a0 = afStack_7c[3];
    local_98 = uStack_68;
    local_9c = uStack_6c;
    uVar4 = uStack_48;
  }
  if ((*(uint *)(param_1 + 0x11c) & 0x80000000) != 0) {
    *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) & 0x7fffffff;
    (*DAT_1006c224)(3);
    (*DAT_1006c224)(0xf);
    (*DAT_1006c224)((-((uVar1 & 0x80000000) != 0) & 4U) + 4);
    (*DAT_1006c238)(afStack_7c + 3);
    (*DAT_1006c23c)(auStack_64);
    (*DAT_1006c224)(*(undefined4 *)(param_1 + 0x3c));
    (*DAT_1006c218)(afStack_7c + 3,2);
  }
LAB_10018751:
  *(float *)(param_1 + 0x1c) = afStack_7c[3];
  *(undefined4 *)(param_1 + 0x20) = uStack_6c;
  *(undefined4 *)(param_1 + 0x24) = uStack_68;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  return;
}



/* FUN_1000cf20 @ 1000cf20 size 575 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000cf20(undefined4 *param_1,undefined4 *param_2)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  float fVar4;
  byte *pbVar5;
  int iVar6;
  undefined *puVar7;
  char *pcVar8;
  bool bVar9;
  ulonglong uVar10;
  undefined4 *puVar11;
  
  FUN_1000cd00(param_2);
  if (param_1[0x47] != 0) {
    pbVar5 = (byte *)param_1[0x46];
    pcVar8 = s_key_power_cube_10047b64;
    do {
      bVar1 = *pbVar5;
      bVar9 = bVar1 < (byte)*pcVar8;
      if (bVar1 != *pcVar8) {
LAB_1000cf6d:
        iVar6 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_1000cf72;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar9 = bVar1 < (byte)pcVar8[1];
      if (bVar1 != pcVar8[1]) goto LAB_1000cf6d;
      pbVar5 = pbVar5 + 2;
      pcVar8 = pcVar8 + 2;
    } while (bVar1 != 0);
    iVar6 = 0;
LAB_1000cf72:
    if (iVar6 != 0) {
      puVar11 = param_1 + 1;
      param_1[0x47] = 0;
      puVar7 = FUN_1001b070();
      (*DAT_1006c1c4)(s__s_at__s_has_invalid_spawnflags_s_1004907c,param_1[0x46],puVar7,puVar11);
    }
  }
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    uVar10 = __ftol();
    if (((uVar10 & 0x800) != 0) &&
       (((code *)param_2[1] == FUN_1000c2e0 || ((code *)param_2[1] == FUN_1000c560)))) {
      FUN_1001b400(param_1);
      return;
    }
    if (((uVar10 & 2) != 0) && ((code *)param_2[1] == FUN_1000b270)) {
      FUN_1001b400(param_1);
      return;
    }
    if (((uVar10 & 1) != 0) &&
       (((puVar2 = (undefined1 *)param_2[1], puVar2 == &DAT_1000c150 || (puVar2 == &LAB_1000b410))
        || (puVar2 == &LAB_1000b490)))) {
      FUN_1001b400(param_1);
      return;
    }
    if ((uVar10 & 0x2000) != 0) {
      if (param_2[0xe] != 2) {
        pbVar5 = (byte *)param_1[0x46];
        pcVar8 = s_weapon_bfg_10048350;
        do {
          bVar1 = *pbVar5;
          bVar9 = bVar1 < (byte)*pcVar8;
          if (bVar1 != *pcVar8) {
LAB_1000d06b:
            iVar6 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
            goto LAB_1000d070;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar5[1];
          bVar9 = bVar1 < (byte)pcVar8[1];
          if (bVar1 != pcVar8[1]) goto LAB_1000d06b;
          pbVar5 = pbVar5 + 2;
          pcVar8 = pcVar8 + 2;
        } while (bVar1 != 0);
        iVar6 = 0;
LAB_1000d070:
        if (iVar6 != 0) goto LAB_1000d081;
      }
      FUN_1001b400(param_1);
      return;
    }
  }
LAB_1000d081:
  if (*(float *)(DAT_1006c42c + 0x14) != _DAT_1004410c) {
    pbVar5 = (byte *)param_1[0x46];
    pcVar8 = s_key_power_cube_10047b64;
    do {
      bVar1 = *pbVar5;
      bVar9 = bVar1 < (byte)*pcVar8;
      if (bVar1 != *pcVar8) {
LAB_1000d0c5:
        iVar6 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_1000d0ca;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar9 = bVar1 < (byte)pcVar8[1];
      if (bVar1 != pcVar8[1]) goto LAB_1000d0c5;
      pbVar5 = pbVar5 + 2;
      pcVar8 = pcVar8 + 2;
    } while (bVar1 != 0);
    iVar6 = 0;
LAB_1000d0ca:
    if (iVar6 == 0) {
      param_1[0x47] = param_1[0x47] | 1 << ((char)DAT_1006c40c + 8U & 0x1f);
      DAT_1006c40c = DAT_1006c40c + 1;
    }
  }
  if ((*(float *)(DAT_1006c42c + 0x14) != _DAT_1004410c) && ((*(byte *)(param_2 + 0xe) & 8) != 0)) {
    param_2[3] = 0;
  }
  param_1[0xb3] = param_2;
  fVar4 = DAT_1006c2e4 + (float)_DAT_10044198;
  param_1[0x7d] = &LAB_1000cae0;
  param_1[0x7b] = fVar4;
  uVar3 = param_2[7];
  param_1[0x11] = 0x200;
  param_1[0x10] = uVar3;
  if (param_1[0x43] != 0) {
    (*DAT_1006c1e0)(param_1[0x43]);
  }
  return;
}



/* FUN_1000dd30 @ 1000dd30 size 566 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000dd30(float param_1,undefined4 param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  uint uVar4;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float afStack_c [3];
  
  fVar2 = param_1;
  piVar3 = FUN_1001b350();
  FUN_10038a20((float *)((int)param_1 + 0xec),0.5,&local_24);
  local_18 = local_24 + *(float *)((int)param_1 + 0xd4);
  local_14 = local_20 + *(float *)((int)param_1 + 0xd8);
  local_10 = local_1c + *(float *)((int)param_1 + 0xdc);
  uVar4 = _rand();
  fVar1 = (float)(uVar4 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  piVar3[1] = (int)((fVar1 + fVar1) * local_24 + local_18);
  uVar4 = _rand();
  fVar1 = (float)(uVar4 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  piVar3[2] = (int)((fVar1 + fVar1) * local_20 + local_14);
  uVar4 = _rand();
  fVar1 = (float)(uVar4 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  piVar3[3] = (int)((fVar1 + fVar1) * local_1c + local_10);
  (*DAT_1006c1ec)(piVar3,param_2);
  piVar3[0x3e] = 0;
  piVar3[0x10] = piVar3[0x10] | 2;
  piVar3[0x42] = piVar3[0x42] | 0x800;
  piVar3[0x90] = 1;
  piVar3[0x82] = (int)&LAB_1000fd20;
  if (param_4 == 0) {
    piVar3[0x41] = 7;
    piVar3[0x7f] = (int)&LAB_1000dc70;
    param_1 = 0.5;
  }
  else {
    piVar3[0x41] = 9;
    param_1 = 1.0;
  }
  FUN_1000da90(param_3,afStack_c);
  FUN_10038950((float *)((int)fVar2 + 0x178),param_1,afStack_c,(float *)(piVar3 + 0x5e));
  FUN_1000db40((int)piVar3);
  uVar4 = _rand();
  piVar3[0x61] = (int)((float)(uVar4 & 0x7fff) * _DAT_10044108 * _DAT_100441f0);
  uVar4 = _rand();
  piVar3[0x62] = (int)((float)(uVar4 & 0x7fff) * _DAT_10044108 * _DAT_100441f0);
  uVar4 = _rand();
  piVar3[0x7d] = (int)FUN_1001b400;
  piVar3[99] = (int)((float)(uVar4 & 0x7fff) * _DAT_10044108 * _DAT_100441f0);
  uVar4 = _rand();
  piVar3[0x7b] = (int)(((float)(uVar4 & 0x7fff) * _DAT_10044108 + _DAT_10044104) * _DAT_100441b0 +
                      DAT_1006c2e4);
  (*DAT_1006c208)(piVar3);
  return;
}



/* FUN_1001cd20 @ 1001cd20 size 555 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_1001cd20(int param_1,int *param_2,float *param_3,int param_4,int param_5,int param_6,int param_7
            )

{
  float *pfVar1;
  float fVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  
  piVar3 = FUN_1001b350();
  piVar3[1] = *param_2;
  piVar3[2] = param_2[1];
  piVar3[3] = param_2[2];
  piVar3[0x74] = (int)*param_3;
  piVar3[0x75] = (int)param_3[1];
  piVar3[0x76] = (int)param_3[2];
  FUN_1001b1e0(param_3,(float *)(piVar3 + 4));
  pfVar1 = (float *)(piVar3 + 0x5b);
  pfVar6 = (float *)(piVar3 + 0x58);
  FUN_10038700((float *)(piVar3 + 4),(float *)0x0,pfVar6,pfVar1);
  FUN_10038a20(pfVar6,0.1,pfVar6);
  FUN_10038a20(pfVar1,0.1,pfVar1);
  piVar3[0x55] = piVar3[0x74];
  pfVar1 = (float *)(param_1 + 0x154);
  pfVar6 = (float *)(param_1 + 0x160);
  piVar3[0x56] = piVar3[0x75];
  piVar3[0x57] = piVar3[0x76];
  pfVar7 = pfVar1;
  uVar4 = _rand();
  fVar2 = (float)(uVar4 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  FUN_10038950(pfVar1,fVar2 + fVar2,pfVar6,pfVar7);
  pfVar6 = (float *)(param_1 + 0x16c);
  pfVar7 = pfVar1;
  uVar4 = _rand();
  fVar2 = (float)(uVar4 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  FUN_10038950(pfVar1,fVar2 + fVar2,pfVar6,pfVar7);
  piVar3[0x52] = (int)(float)param_5;
  FUN_10038a20((float *)(piVar3 + 0x55),(float)param_5,(float *)(piVar3 + 0x5e));
  piVar3[0x41] = 8;
  piVar3[0x10] = piVar3[0x10] | 0x20;
  piVar3[0x3f] = 0x6000003;
  piVar3[0x3e] = 2;
  piVar3[0x31] = 0;
  piVar3[0x30] = 0;
  piVar3[0x2f] = 0;
  piVar3[0x34] = 0;
  piVar3[0x33] = 0;
  piVar3[0x32] = 0;
  iVar5 = (*DAT_1006c1e0)(s_models_objects_rocket_tris_md2_1004bf90);
  piVar3[10] = iVar5;
  piVar3[0x40] = param_1;
  piVar3[0x7f] = (int)&LAB_1001c960;
  piVar3[0x91] = param_4;
  piVar3[0x92] = param_7;
  piVar3[0x93] = param_6;
  iVar5 = (*DAT_1006c1e4)(s_weapons_rockfly_wav_1004bf7c);
  piVar3[0x13] = iVar5;
  piVar3[0x46] = (int)s_rocket_1004bf74;
  fVar2 = DAT_1006c2e4;
  piVar3[0x7d] = (int)FUN_1001cc30;
  piVar3[0x48] = (int)fVar2;
  piVar3[0x7b] = (int)(DAT_1006c2e4 + (float)_DAT_10044198);
  if (*(int *)(param_1 + 0x54) != 0) {
    FUN_1001c1c0(param_1,(float *)(piVar3 + 1),param_3,param_5);
  }
  (*DAT_1006c208)(piVar3);
  return;
}



/* FUN_100428de @ 100428de size 544 */

void __cdecl FUN_100428de(int *param_1,int *param_2)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  ushort uVar9;
  uint uVar10;
  ushort uVar11;
  byte local_28;
  undefined1 uStack_27;
  undefined2 uStack_26;
  short local_24;
  undefined2 uStack_22;
  undefined2 local_20;
  undefined1 uStack_1e;
  byte bStack_1d;
  int *local_1c;
  int local_18;
  int local_14;
  ushort *local_10;
  ushort *local_c;
  short *local_8;
  
  piVar5 = param_2;
  piVar4 = param_1;
  local_18 = 0;
  local_28 = 0;
  uStack_27 = 0;
  uStack_26 = 0;
  local_24 = 0;
  uStack_22 = 0;
  local_20 = 0;
  uStack_1e = 0;
  bStack_1d = 0;
  uVar7 = *(ushort *)((int)param_1 + 10) & 0x7fff;
  uVar10 = *(ushort *)((int)param_2 + 10) & 0x7fff;
  uVar11 = (*(ushort *)((int)param_2 + 10) ^ *(ushort *)((int)param_1 + 10)) & 0x8000;
  uVar6 = (ushort)uVar7;
  piVar1 = (int *)(uVar10 + uVar7);
  if (((uVar6 < 0x7fff) && (uVar9 = (ushort)uVar10, uVar9 < 0x7fff)) && ((ushort)piVar1 < 0xbffe)) {
    if ((ushort)piVar1 < 0x3fc0) {
LAB_10042981:
      piVar4[2] = 0;
      piVar4[1] = 0;
      *piVar4 = 0;
      return;
    }
    if (((uVar6 != 0) || (piVar1 = (int *)((int)piVar1 + 1), (param_1[2] & 0x7fffffffU) != 0)) ||
       ((uVar6 = 0, param_1[1] != 0 || (*param_1 != 0)))) {
      param_1 = piVar1;
      if (((uVar9 == 0) && (param_1 = (int *)((int)param_1 + 1), (param_2[2] & 0x7fffffffU) == 0))
         && ((param_2[1] == 0 && (*param_2 == 0)))) goto LAB_10042981;
      local_14 = 0;
      local_8 = &local_24;
      param_2 = (int *)0x5;
      do {
        if (0 < (int)param_2) {
          local_c = (ushort *)(local_14 * 2 + (int)piVar4);
          local_10 = (ushort *)(piVar5 + 2);
          local_1c = param_2;
          do {
            iVar8 = FUN_100420eb(*(uint *)(local_8 + -2),(uint)*local_c * (uint)*local_10,
                                 (uint *)(local_8 + -2));
            if (iVar8 != 0) {
              *local_8 = *local_8 + 1;
            }
            local_c = local_c + 1;
            local_10 = local_10 + -1;
            local_1c = (int *)((int)local_1c + -1);
          } while (local_1c != (int *)0x0);
        }
        local_8 = local_8 + 1;
        local_14 = local_14 + 1;
        param_2 = (int *)((int)param_2 + -1);
      } while (0 < (int)param_2);
      param_1 = (int *)((int)param_1 + 0xc002);
      if ((short)(ushort)param_1 < 1) {
LAB_10042a35:
        param_1._0_2_ = (ushort)param_1 - 1;
        if ((short)(ushort)param_1 < 0) {
          iVar8 = -(int)(short)(ushort)param_1;
          param_1._0_2_ = (ushort)param_1 + (short)iVar8;
          do {
            if ((local_28 & 1) != 0) {
              local_18 = local_18 + 1;
            }
            FUN_10042198((uint *)&local_28);
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
          if (local_18 != 0) {
            local_28 = local_28 | 1;
          }
        }
      }
      else {
        do {
          if ((bStack_1d & 0x80) != 0) break;
          FUN_1004216a((uint *)&local_28);
          param_1 = (int *)((int)param_1 + 0xffff);
        } while (0 < (short)(ushort)param_1);
        if ((short)(ushort)param_1 < 1) goto LAB_10042a35;
      }
      if ((0x8000 < CONCAT11(uStack_27,local_28)) ||
         (sVar2 = CONCAT11(bStack_1d,uStack_1e), iVar3 = CONCAT22(local_20,uStack_22),
         iVar8 = CONCAT22(local_24,uStack_26),
         (CONCAT22(uStack_26,CONCAT11(uStack_27,local_28)) & 0x1ffff) == 0x18000)) {
        if (CONCAT22(local_24,uStack_26) == -1) {
          iVar8 = 0;
          if (CONCAT22(local_20,uStack_22) == -1) {
            if (CONCAT11(bStack_1d,uStack_1e) == -1) {
              param_1._0_2_ = (ushort)param_1 + 1;
              sVar2 = -0x8000;
              iVar3 = 0;
              iVar8 = 0;
            }
            else {
              sVar2 = CONCAT11(bStack_1d,uStack_1e) + 1;
              iVar3 = 0;
              iVar8 = 0;
            }
          }
          else {
            sVar2 = CONCAT11(bStack_1d,uStack_1e);
            iVar3 = CONCAT22(local_20,uStack_22) + 1;
          }
        }
        else {
          iVar8 = CONCAT22(local_24,uStack_26) + 1;
          sVar2 = CONCAT11(bStack_1d,uStack_1e);
          iVar3 = CONCAT22(local_20,uStack_22);
        }
      }
      local_24 = (short)((uint)iVar8 >> 0x10);
      uStack_26 = (undefined2)iVar8;
      local_20 = (undefined2)((uint)iVar3 >> 0x10);
      uStack_22 = (undefined2)iVar3;
      bStack_1d = (byte)((ushort)sVar2 >> 8);
      uStack_1e = (undefined1)sVar2;
      if (0x7ffe < (ushort)param_1) goto LAB_10042ade;
      uVar6 = (ushort)param_1 | uVar11;
      *(undefined2 *)piVar4 = uStack_26;
      *(uint *)((int)piVar4 + 2) = CONCAT22(uStack_22,local_24);
      *(uint *)((int)piVar4 + 6) = CONCAT13(bStack_1d,CONCAT12(uStack_1e,local_20));
    }
    *(ushort *)((int)piVar4 + 10) = uVar6;
  }
  else {
LAB_10042ade:
    piVar4[1] = 0;
    *piVar4 = 0;
    piVar4[2] = (-(uint)(uVar11 != 0) & 0x80000000) + 0x7fff8000;
  }
  return;
}



/* FUN_10002f70 @ 10002f70 size 543 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10002f70(int param_1)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  float10 fVar5;
  float10 fVar6;
  
  fVar2 = _DAT_1004410c;
  switch(*(undefined4 *)(param_1 + 0x330)) {
  case 0:
  case 1:
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x32c) = 0;
    if (fVar2 < *(float *)(param_1 + 0x34c)) {
      *(float *)(param_1 + 800) = *(float *)(param_1 + 0x348);
      *(float *)(param_1 + 0x32c) = *(float *)(param_1 + 0x34c) / *(float *)(param_1 + 0x348);
      *(undefined4 *)(param_1 + 0x294) = *(undefined4 *)(*(int *)(param_1 + 0x1e0) + 0x294);
    }
    *(undefined4 *)(param_1 + 0x34c) = 0;
    *(undefined4 *)(param_1 + 0x348) = 0;
    fVar2 = DAT_1006c2e4 + *(float *)(param_1 + 0x32c);
    *(undefined4 *)(param_1 + 0x330) = 3;
    *(float *)(param_1 + 0x32c) = fVar2;
    return;
  case 3:
    if (*(int *)(param_1 + 0x294) == -0x40800000) {
      *(undefined4 *)(param_1 + 0x32c) = 0;
      *(undefined4 *)(param_1 + 0x330) = 0;
    }
    else {
      fVar2 = DAT_1006c2e4 + *(float *)(param_1 + 0x294);
      *(undefined4 *)(param_1 + 0x330) = 1;
      *(undefined4 *)(param_1 + 0x294) = 0;
      *(float *)(param_1 + 0x32c) = fVar2;
    }
    uVar4 = FUN_1001ad80(*(byte **)(*(int *)(param_1 + 0x1e0) + 0x128));
    *(uint *)(param_1 + 0x1e0) = uVar4;
    *(undefined4 *)(param_1 + 0x180) = 0;
    *(undefined4 *)(param_1 + 0x17c) = 0;
    *(undefined4 *)(param_1 + 0x178) = 0;
    *(undefined4 *)(param_1 + 0x18c) = 0;
    *(undefined4 *)(param_1 + 0x188) = 0;
    *(undefined4 *)(param_1 + 0x184) = 0;
  default:
    return;
  }
  iVar3 = *(int *)(param_1 + 0x1e0);
  if (iVar3 != 0) {
    pfVar1 = (float *)(param_1 + 0x334);
    *pfVar1 = *(float *)(iVar3 + 4) - *(float *)(param_1 + 4);
    *(float *)(param_1 + 0x338) = *(float *)(iVar3 + 8) - *(float *)(param_1 + 8);
    *(float *)(param_1 + 0x33c) = *(float *)(iVar3 + 0xc) - *(float *)(param_1 + 0xc);
    fVar5 = FUN_100389f0(pfVar1);
    *(float *)(param_1 + 0x34c) = (float)fVar5;
    FUN_10038900(pfVar1);
    fVar2 = *(float *)(param_1 + 0x34c) / *(float *)(param_1 + 800);
    fVar5 = FUN_1003900b((double)(fVar2 * (float)_DAT_10044170));
    fVar5 = fVar5 * (float10)_DAT_10044168;
    *(undefined4 *)(param_1 + 0x330) = 2;
    *(float *)(param_1 + 0x32c) = (float)fVar5;
    fVar2 = (float)((float10)fVar2 - fVar5);
    fVar6 = (float10)*(float *)(param_1 + 0x34c) - fVar5 * (float10)*(float *)(param_1 + 800);
    *(float *)(param_1 + 0x34c) = (float)fVar6;
    *(float *)(param_1 + 0x348) = (float)(fVar6 / (float10)fVar2);
    if (fVar5 == (float10)_DAT_1004410c) {
      *(float *)(param_1 + 0x32c) = fVar2;
      (*DAT_1006c1c0)(2,s_no_main_move_10046058);
    }
    else {
      FUN_10038a20(pfVar1,*(float *)(param_1 + 800),(float *)(param_1 + 0x178));
    }
    *(float *)(param_1 + 0x32c) = DAT_1006c2e4 + *(float *)(param_1 + 0x32c);
    return;
  }
  *(undefined4 *)(param_1 + 0x32c) = 0;
  *(undefined4 *)(param_1 + 0x294) = 0xbf800000;
  return;
}



/* FUN_1001c740 @ 1001c740 size 543 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_1001c740(int param_1,int *param_2,float *param_3,int param_4,int param_5,float param_6,
            int param_7,int param_8)

{
  float *pfVar1;
  float fVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  float *pfVar7;
  float *pfVar8;
  float local_30 [3];
  float local_24 [3];
  float local_18 [3];
  float local_c [3];
  
  FUN_1001b1e0(param_3,local_30);
  FUN_10038700(local_30,local_c,local_18,local_24);
  piVar3 = FUN_1001b350();
  pfVar1 = (float *)(piVar3 + 0x5e);
  piVar3[1] = *param_2;
  piVar3[2] = param_2[1];
  piVar3[3] = param_2[2];
  FUN_10038a20(param_3,(float)param_5,pfVar1);
  pfVar7 = local_24;
  pfVar8 = pfVar1;
  uVar4 = _rand();
  fVar2 = (float)(uVar4 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  FUN_10038950(pfVar1,(fVar2 + fVar2) * (float)_DAT_10044170 + (float)_DAT_100441d8,pfVar7,pfVar8);
  pfVar7 = local_18;
  pfVar8 = pfVar1;
  uVar4 = _rand();
  fVar2 = (float)(uVar4 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  FUN_10038950(pfVar1,(fVar2 + fVar2) * (float)_DAT_10044170,pfVar7,pfVar8);
  piVar3[0x61] = 0x43960000;
  piVar3[0x62] = 0x43960000;
  piVar3[99] = 0x43960000;
  piVar3[0x41] = 9;
  piVar3[0x3f] = 0x6000003;
  piVar3[0x3e] = 2;
  piVar3[0x10] = piVar3[0x10] | 0x20;
  piVar3[0x31] = 0;
  piVar3[0x30] = 0;
  piVar3[0x2f] = 0;
  piVar3[0x34] = 0;
  piVar3[0x33] = 0;
  piVar3[0x32] = 0;
  iVar5 = (*DAT_1006c1e0)(s_models_objects_grenade2_tris_md2_1004bf50);
  piVar3[10] = iVar5;
  piVar3[0x40] = param_1;
  piVar3[0x7f] = (int)&LAB_1001c680;
  fVar2 = DAT_1006c2e4 + param_6;
  piVar3[0x93] = param_7;
  piVar3[0x7d] = (int)FUN_1001c4a0;
  piVar3[0x91] = param_4;
  piVar3[0x7b] = (int)fVar2;
  piVar3[0x46] = (int)s_hgrenade_1004bf44;
  if (param_8 == 0) {
    piVar3[0x47] = 1;
  }
  else {
    piVar3[0x47] = 3;
  }
  iVar5 = (*DAT_1006c1e4)(s_weapons_hgrenc1b_wav_1004bf2c);
  fVar2 = (float)_DAT_10044268;
  piVar3[0x13] = iVar5;
  if (param_6 <= fVar2) {
    FUN_1001c4a0(piVar3);
    return;
  }
  uVar6 = (*DAT_1006c1e4)(s_weapons_hgrent1a_wav_1004bf14,0x3f800000,0x3f800000,0);
  (*DAT_1006c1d0)(param_1,1,uVar6);
  (*DAT_1006c208)(piVar3);
  return;
}



/* FUN_1000cd00 @ 1000cd00 size 537 */

void __cdecl FUN_1000cd00(undefined4 *param_1)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  byte *pbVar10;
  char *pcVar11;
  bool bVar12;
  undefined4 uStack_44;
  char acStack_40 [64];
  
  if (param_1 != (undefined4 *)0x0) {
    if (param_1[5] != 0) {
      (*DAT_1006c1e4)(param_1[5]);
    }
    if (param_1[6] != 0) {
      (*DAT_1006c1e0)(param_1[6]);
    }
    if (param_1[8] != 0) {
      (*DAT_1006c1e0)(param_1[8]);
    }
    if (param_1[9] != 0) {
      (*DAT_1006c1e8)(param_1[9]);
    }
    pbVar6 = (byte *)param_1[0xd];
    if (((pbVar6 != (byte *)0x0) && (*pbVar6 != 0)) &&
       (puVar3 = FUN_1000b150(pbVar6), puVar3 != param_1)) {
      FUN_1000cd00(puVar3);
    }
    pcVar9 = (char *)param_1[0x11];
    if (pcVar9 != (char *)0x0) {
      cVar1 = *pcVar9;
      while (uStack_44 = pcVar9, cVar1 != '\0') {
        while ((cVar1 != '\0' && (cVar1 != ' '))) {
          cVar1 = uStack_44[1];
          uStack_44 = uStack_44 + 1;
        }
        uVar8 = (int)uStack_44 - (int)pcVar9;
        if ((0x3f < (int)uVar8) || ((int)uVar8 < 5)) {
          (*DAT_1006c1dc)(s_PrecacheItem___s_has_bad_precach_10049050,*param_1);
        }
        pcVar11 = acStack_40;
        for (uVar7 = uVar8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
          pcVar9 = pcVar9 + 4;
          pcVar11 = pcVar11 + 4;
        }
        for (uVar7 = uVar8 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
          *pcVar11 = *pcVar9;
          pcVar9 = pcVar9 + 1;
          pcVar11 = pcVar11 + 1;
        }
        acStack_40[uVar8] = '\0';
        if (*uStack_44 != '\0') {
          uStack_44 = uStack_44 + 1;
        }
        pbVar6 = (byte *)(acStack_40 + (uVar8 - 3));
        pbVar10 = &DAT_1004904c;
        pbVar4 = pbVar6;
        do {
          bVar2 = *pbVar4;
          bVar12 = bVar2 < *pbVar10;
          if (bVar2 != *pbVar10) {
LAB_1000ce26:
            iVar5 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
            goto LAB_1000ce2b;
          }
          if (bVar2 == 0) break;
          bVar2 = pbVar4[1];
          bVar12 = bVar2 < pbVar10[1];
          if (bVar2 != pbVar10[1]) goto LAB_1000ce26;
          pbVar4 = pbVar4 + 2;
          pbVar10 = pbVar10 + 2;
        } while (bVar2 != 0);
        iVar5 = 0;
LAB_1000ce2b:
        if (iVar5 == 0) {
          (*DAT_1006c1e0)(acStack_40);
        }
        else {
          pbVar10 = &DAT_10049048;
          pbVar4 = pbVar6;
          do {
            bVar2 = *pbVar4;
            bVar12 = bVar2 < *pbVar10;
            if (bVar2 != *pbVar10) {
LAB_1000ce6a:
              iVar5 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
              goto LAB_1000ce6f;
            }
            if (bVar2 == 0) break;
            bVar2 = pbVar4[1];
            bVar12 = bVar2 < pbVar10[1];
            if (bVar2 != pbVar10[1]) goto LAB_1000ce6a;
            pbVar4 = pbVar4 + 2;
            pbVar10 = pbVar10 + 2;
          } while (bVar2 != 0);
          iVar5 = 0;
LAB_1000ce6f:
          if (iVar5 == 0) {
            (*DAT_1006c1e0)(acStack_40);
          }
          else {
            pbVar10 = &DAT_10049044;
            pbVar4 = pbVar6;
            do {
              bVar2 = *pbVar4;
              bVar12 = bVar2 < *pbVar10;
              if (bVar2 != *pbVar10) {
LAB_1000ceab:
                iVar5 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
                goto LAB_1000ceb0;
              }
              if (bVar2 == 0) break;
              bVar2 = pbVar4[1];
              bVar12 = bVar2 < pbVar10[1];
              if (bVar2 != pbVar10[1]) goto LAB_1000ceab;
              pbVar4 = pbVar4 + 2;
              pbVar10 = pbVar10 + 2;
            } while (bVar2 != 0);
            iVar5 = 0;
LAB_1000ceb0:
            if (iVar5 == 0) {
              (*DAT_1006c1e4)(acStack_40);
            }
          }
        }
        pbVar4 = &DAT_10049040;
        do {
          bVar2 = *pbVar6;
          bVar12 = bVar2 < *pbVar4;
          if (bVar2 != *pbVar4) {
LAB_1000ceed:
            iVar5 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
            goto LAB_1000cef2;
          }
          if (bVar2 == 0) break;
          bVar2 = pbVar6[1];
          bVar12 = bVar2 < pbVar4[1];
          if (bVar2 != pbVar4[1]) goto LAB_1000ceed;
          pbVar6 = pbVar6 + 2;
          pbVar4 = pbVar4 + 2;
        } while (bVar2 != 0);
        iVar5 = 0;
LAB_1000cef2:
        if (iVar5 == 0) {
          (*DAT_1006c1e8)(acStack_40);
        }
        pcVar9 = uStack_44;
        cVar1 = *uStack_44;
      }
    }
  }
  return;
}



/* FUN_1003ad53 @ 1003ad53 size 535 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __cdecl FUN_1003ad53(uint param_1,double *param_2,uint param_3)

{
  double dVar1;
  bool bVar2;
  uint uVar3;
  bool bVar4;
  float10 fVar5;
  undefined8 local_10;
  int local_8;
  
  uVar3 = param_1 & 0x1f;
  bVar2 = true;
  if (((param_1 & 8) != 0) && ((param_3 & 1) != 0)) {
    FUN_1003b202();
    uVar3 = param_1 & 0x17;
    goto LAB_1003af48;
  }
  if (((param_1 & 4) != 0) && ((param_3 & 4) != 0)) {
    FUN_1003b202();
    uVar3 = param_1 & 0x1b;
    goto LAB_1003af48;
  }
  if (((param_1 & 1) == 0) || ((param_3 & 8) == 0)) {
    if (((param_1 & 2) != 0) && ((param_3 & 0x10) != 0)) {
      bVar4 = (param_1 & 0x10) != 0;
      dVar1 = *param_2;
      if (dVar1 != _DAT_10044268) {
        fVar5 = FUN_1003b101(SUB84(dVar1,0),(uint)((ulonglong)dVar1 >> 0x20),&local_8);
        local_8 = local_8 + -0x600;
        if (local_8 < -0x432) {
          local_10 = 0.0;
          bVar4 = bVar2;
        }
        else {
          local_10 = (double)(ulonglong)
                             (SUB87((double)fVar5,0) & 0xfffffffffffff | 0x10000000000000);
          if (local_8 < -0x3fd) {
            local_8 = -0x3fd - local_8;
            do {
              if ((((ulonglong)local_10 & 1) != 0) && (!bVar4)) {
                bVar4 = bVar2;
              }
              uVar3 = (uint)local_10 >> 1;
              if (((ulonglong)local_10 & 0x100000000) != 0) {
                local_10._3_1_ = (byte)((ulonglong)local_10 >> 0x18) >> 1;
                local_10._0_3_ = (undefined3)uVar3;
                local_10._0_4_ = CONCAT13(local_10._3_1_,(undefined3)local_10) | 0x80000000;
                uVar3 = (uint)local_10;
              }
              local_10._0_4_ = uVar3;
              local_10 = (double)CONCAT44(local_10._4_4_ >> 1,(uint)local_10);
              local_8 = local_8 + -1;
            } while (local_8 != 0);
          }
          if ((double)fVar5 < _DAT_10044268) {
            local_10 = -local_10;
          }
        }
        *param_2 = local_10;
        bVar2 = bVar4;
      }
      if (bVar2) {
        FUN_1003b202();
      }
      uVar3 = param_1 & 0x1d;
    }
    goto LAB_1003af48;
  }
  FUN_1003b202();
  uVar3 = param_3 & 0xc00;
  dVar1 = _DAT_1005fc88;
  if (uVar3 == 0) {
    if (*param_2 <= _DAT_10044268) {
      dVar1 = -_DAT_1005fc88;
    }
LAB_1003ae68:
    *param_2 = dVar1;
  }
  else {
    if (uVar3 == 0x400) {
      dVar1 = _DAT_1005fc98;
      if (*param_2 <= _DAT_10044268) {
        dVar1 = -_DAT_1005fc88;
      }
      goto LAB_1003ae68;
    }
    if (uVar3 == 0x800) {
      if (*param_2 <= _DAT_10044268) {
        dVar1 = -_DAT_1005fc98;
      }
      goto LAB_1003ae68;
    }
    if (uVar3 == 0xc00) {
      dVar1 = _DAT_1005fc98;
      if (*param_2 <= _DAT_10044268) {
        dVar1 = -_DAT_1005fc98;
      }
      goto LAB_1003ae68;
    }
  }
  uVar3 = param_1 & 0x1e;
LAB_1003af48:
  if (((param_1 & 0x10) != 0) && ((param_3 & 0x20) != 0)) {
    FUN_1003b202();
    uVar3 = uVar3 & 0xffffffef;
  }
  return uVar3 == 0;
}



/* FUN_1001ae20 @ 1001ae20 size 534 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1001ae20(uint param_1,int param_2)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  if (*(float *)(param_1 + 0x294) != _DAT_1004410c) {
    piVar2 = FUN_1001b350();
    piVar2[0x46] = (int)s_DelayedUse_1004be24;
    fVar1 = DAT_1006c2e4 + *(float *)(param_1 + 0x294);
    piVar2[0x7d] = (int)FUN_1001ae00;
    piVar2[0x99] = param_2;
    piVar2[0x7b] = (int)fVar1;
    if (param_2 == 0) {
      (*DAT_1006c1c4)(s_Think_Delay_with_no_activator_1004be04);
    }
    piVar2[0x45] = *(int *)(param_1 + 0x114);
    piVar2[0x4a] = *(int *)(param_1 + 0x128);
    piVar2[0x4c] = *(int *)(param_1 + 0x130);
    return;
  }
  if ((*(int *)(param_1 + 0x114) != 0) && ((*(byte *)(param_2 + 0xb8) & 4) == 0)) {
    (*DAT_1006c1cc)(param_2,&DAT_10046140,*(int *)(param_1 + 0x114));
    iVar3 = *(int *)(param_1 + 0x280);
    if (iVar3 == 0) {
      iVar3 = (*DAT_1006c1e4)(s_misc_talk1_wav_10046130,0x3f800000,0x3f800000,0);
    }
    (*DAT_1006c1d0)(param_2,0,iVar3);
  }
  if (*(byte **)(param_1 + 0x130) != (byte *)0x0) {
    for (puVar4 = (undefined4 *)FUN_1001ac00(0,300,*(byte **)(param_1 + 0x130));
        puVar4 != (undefined4 *)0x0;
        puVar4 = (undefined4 *)FUN_1001ac00((int)puVar4,300,*(byte **)(param_1 + 0x130))) {
      FUN_1001b400(puVar4);
      if (*(int *)(param_1 + 0x58) == 0) {
        (*DAT_1006c1c4)(s_entity_was_removed_while_using_k_1004bdb8);
        return;
      }
    }
  }
  if ((*(byte **)(param_1 + 0x128) != (byte *)0x0) &&
     (uVar5 = FUN_1001ac00(0,300,*(byte **)(param_1 + 0x128)), uVar5 != 0)) {
    do {
      iVar3 = FUN_10038b20(*(void **)(uVar5 + 0x118),(byte *)s_func_areaportal_100466a8);
      if ((iVar3 != 0) ||
         ((iVar3 = FUN_10038b20(*(void **)(param_1 + 0x118),(byte *)s_func_door_100466cc),
          iVar3 != 0 &&
          (iVar3 = FUN_10038b20(*(void **)(param_1 + 0x118),(byte *)s_func_door_rotating_100466b8),
          iVar3 != 0)))) {
        if (uVar5 == param_1) {
          (*DAT_1006c1c4)(s_WARNING__Entity_used_itself__1004bde4);
        }
        else if (*(code **)(uVar5 + 0x200) != (code *)0x0) {
          (**(code **)(uVar5 + 0x200))(uVar5,param_1,param_2);
        }
        if (*(int *)(param_1 + 0x58) == 0) {
          (*DAT_1006c1c4)(s_entity_was_removed_while_using_t_1004bd90);
          return;
        }
      }
      uVar5 = FUN_1001ac00(uVar5,300,*(byte **)(param_1 + 0x128));
      if (uVar5 == 0) {
        return;
      }
    } while( true );
  }
  return;
}



/* FUN_10007f60 @ 10007f60 size 517 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10007f60(int param_1)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float10 extraout_ST0;
  float10 fVar6;
  ulonglong uVar7;
  float local_30;
  float local_2c;
  float local_24;
  float local_14;
  float local_4;
  
  local_24 = 1.0;
  local_14 = 1.0;
  local_4 = 1.0;
  if ((_DAT_1004410c < *(float *)(param_1 + 0x32c)) &&
     (uVar1 = *(uint *)(param_1 + 0x11c), (uVar1 & 0x20) != 0)) {
    local_2c = 0.0;
    *(undefined4 *)(param_1 + 0x18c) = 0;
    *(undefined4 *)(param_1 + 0x188) = 0;
    *(undefined4 *)(param_1 + 0x184) = 0;
    local_30 = 0.0;
    *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(param_1 + 0x18);
    uVar7 = __ftol();
    fVar2 = (float)(int)((longlong)
                         ((ulonglong)(uint)((int)uVar7 >> 0x1f) << 0x20 | uVar7 & 0xffffffff) %
                        0x168);
    *(float *)(param_1 + 0x10) = fVar2;
    uVar7 = __ftol();
    fVar3 = (float)(int)((longlong)
                         ((ulonglong)(uint)((int)uVar7 >> 0x1f) << 0x20 | uVar7 & 0xffffffff) %
                        0x168);
    *(float *)(param_1 + 0x14) = fVar3;
    uVar7 = __ftol();
    iVar5 = (int)((longlong)((ulonglong)(uint)((int)uVar7 >> 0x1f) << 0x20 | uVar7 & 0xffffffff) %
                 0x168);
    fVar4 = (float)iVar5;
    *(float *)(param_1 + 0x18) = fVar4;
    if (_DAT_1004410c < *(float *)(param_1 + 0x1d0)) {
      if ((uVar1 & 2) != 0) {
        local_24 = -1.0;
      }
      local_30 = local_24 * *(float *)(param_1 + 0x1d0) + fVar2;
    }
    if (_DAT_1004410c < *(float *)(param_1 + 0x1d4)) {
      if ((uVar1 & 4) != 0) {
        local_14 = -1.0;
      }
      local_2c = local_14 * *(float *)(param_1 + 0x1d4) + fVar3;
    }
    fVar6 = extraout_ST0;
    if (_DAT_1004410c < *(float *)(param_1 + 0x1d8)) {
      if ((uVar1 & 8) != 0) {
        local_4 = -1.0;
      }
      fVar6 = (float10)local_4 * (float10)*(float *)(param_1 + 0x1d8) + (float10)iVar5;
    }
    *(float *)(param_1 + 0x304) = local_30;
    *(float *)(param_1 + 0x308) = local_2c;
    *(float *)(param_1 + 0x2ec) = fVar2;
    *(float *)(param_1 + 0x30c) = (float)fVar6;
    *(float *)(param_1 + 0x2f0) = fVar3;
    *(float *)(param_1 + 0x2f4) = fVar4;
    *(undefined1 **)(param_1 + 500) = &LAB_10008220;
    *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + *(float *)(param_1 + 0x32c);
    return;
  }
  *(undefined4 *)(param_1 + 0x18c) = 0;
  *(undefined4 *)(param_1 + 0x188) = 0;
  *(undefined4 *)(param_1 + 0x184) = 0;
  *(undefined4 *)(param_1 + 500) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  return;
}



/* FUN_10041a4a @ 10041a4a size 511 */

int __cdecl
FUN_10041a4a(LCID param_1,uint param_2,char *param_3,int param_4,LPWSTR param_5,int param_6,
            UINT param_7,int param_8)

{
  int iVar1;
  int iVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_100449a0;
  puStack_10 = &LAB_10042634;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_10061f98 == 0) {
    ExceptionList = &local_14;
    iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_10061f98 = 2;
    }
    else {
      DAT_10061f98 = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_10042efe(param_3,param_4);
  }
  if (DAT_10061f98 == 2) {
    iVar1 = LCMapStringA(param_1,param_2,param_3,param_4,(LPSTR)param_5,param_6);
    ExceptionList = local_14;
    return iVar1;
  }
  if (DAT_10061f98 == 1) {
    if (param_7 == 0) {
      param_7 = DAT_10061dc8;
    }
    iVar1 = MultiByteToWideChar(param_7,(-(uint)(param_8 != 0) & 8) + 1,param_3,param_4,(LPWSTR)0x0,
                                0);
    if (iVar1 != 0) {
      local_8 = 0;
      FUN_10039f80();
      local_8 = 0xffffffff;
      if ((&stack0x00000000 != (undefined1 *)0x3c) &&
         (iVar2 = MultiByteToWideChar(param_7,1,param_3,param_4,(LPWSTR)&stack0xffffffc4,iVar1),
         iVar2 != 0)) {
        iVar2 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,(LPWSTR)0x0,0);
        if (iVar2 != 0) {
          if ((param_2 & 0x400) == 0) {
            local_8 = 1;
            FUN_10039f80();
            local_8 = 0xffffffff;
            if (&stack0x00000000 == (undefined1 *)0x3c) {
              ExceptionList = local_14;
              return 0;
            }
            iVar1 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,
                                 (LPWSTR)&stack0xffffffc4,iVar2);
            if (iVar1 == 0) {
              ExceptionList = local_14;
              return 0;
            }
            if (param_6 == 0) {
              param_6 = 0;
              param_5 = (LPWSTR)0x0;
            }
            iVar2 = WideCharToMultiByte(param_7,0x220,(LPCWSTR)&stack0xffffffc4,iVar2,(LPSTR)param_5
                                        ,param_6,(LPCSTR)0x0,(LPBOOL)0x0);
            iVar1 = iVar2;
          }
          else {
            if (param_6 == 0) {
              ExceptionList = local_14;
              return iVar2;
            }
            if (param_6 < iVar2) {
              ExceptionList = local_14;
              return 0;
            }
            iVar1 = LCMapStringW(param_1,param_2,(LPCWSTR)&stack0xffffffc4,iVar1,param_5,param_6);
          }
          if (iVar1 != 0) {
            ExceptionList = local_14;
            return iVar2;
          }
        }
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}



/* FUN_1000c650 @ 1000c650 size 510 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000c650(undefined4 *param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  
  if (*(int *)(param_2 + 0x54) == 0) {
    return;
  }
  if (*(int *)(param_2 + 0x220) < 1) {
    return;
  }
  if (*(code **)(param_1[0xb3] + 4) == (code *)0x0) {
    return;
  }
  iVar2 = (**(code **)(param_1[0xb3] + 4))(param_1,param_2);
  if (iVar2 != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0xe54) = 0x3e800000;
    uVar1 = (*DAT_1006c1e8)(*(undefined4 *)(param_1[0xb3] + 0x24));
    *(undefined2 *)(*(int *)(param_2 + 0x54) + 0x86) = uVar1;
    iVar4 = param_1[0xb3] + -0x10046928;
    *(short *)(*(int *)(param_2 + 0x54) + 0x88) =
         ((short)(iVar4 / 0x48) + (short)(iVar4 >> 0x1f) + 0x420) -
         (short)((longlong)iVar4 * 0x38e38e39 >> 0x3f);
    *(float *)(*(int *)(param_2 + 0x54) + 0xecc) = DAT_1006c2e4 + (float)_DAT_100441c8;
    if (*(int *)(param_1[0xb3] + 8) != 0) {
      iVar4 = param_1[0xb3] + -0x10046928;
      *(short *)(*(int *)(param_2 + 0x54) + 0x90) =
           ((short)(iVar4 / 0x48) + (short)(iVar4 >> 0x1f)) -
           (short)((longlong)iVar4 * 0x38e38e39 >> 0x3f);
      *(int *)(*(int *)(param_2 + 0x54) + 0x2e0) = (int)*(short *)(*(int *)(param_2 + 0x54) + 0x90);
    }
    if (*(undefined **)(param_1[0xb3] + 4) == &DAT_1000c150) {
      iVar4 = param_1[0x95];
      if (iVar4 == 2) {
        pcVar5 = s_items_s_health_wav_10048fc4;
      }
      else if (iVar4 == 10) {
        pcVar5 = s_items_n_health_wav_10048fb0;
      }
      else if (iVar4 == 0x19) {
        pcVar5 = s_items_l_health_wav_10048f9c;
      }
      else {
        pcVar5 = s_items_m_health_wav_10048f88;
      }
    }
    else {
      pcVar5 = *(char **)(param_1[0xb3] + 0x14);
      if (pcVar5 == (char *)0x0) goto LAB_1000c7cd;
    }
    uVar3 = (*DAT_1006c1e4)(pcVar5,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_2,3,uVar3);
  }
LAB_1000c7cd:
  if ((param_1[0x47] & 0x40000) == 0) {
    FUN_1001ae20((uint)param_1,param_2);
    param_1[0x47] = param_1[0x47] | 0x40000;
  }
  if ((iVar2 != 0) &&
     (((*(float *)(DAT_1006c42c + 0x14) == _DAT_1004410c ||
       ((*(byte *)(param_1[0xb3] + 0x38) & 8) == 0)) || ((param_1[0x47] & 0x30000) != 0)))) {
    if ((param_1[0x42] & 0x80000000) != 0) {
      param_1[0x42] = param_1[0x42] & 0x7fffffff;
      return;
    }
    FUN_1001b400(param_1);
  }
  return;
}



/* FUN_10034110 @ 10034110 size 505 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10034110(uint param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  float local_c [3];
  
  if (*(int *)(param_1 + 0x28) != 0xff) {
    return;
  }
  if (*(int *)(param_1 + 0x104) == 1) {
    return;
  }
  iVar3 = *(int *)(param_1 + 0x54);
  if ((_DAT_1004410c <= *(float *)(iVar3 + 0xe88)) ||
     (*(float *)(param_1 + 0x180) <= *(float *)(iVar3 + 0xe88))) {
    if (*(int *)(param_1 + 0x268) == 0) {
      return;
    }
  }
  else if (*(int *)(param_1 + 0x268) == 0) {
    fVar1 = *(float *)(iVar3 + 0xe88);
    goto LAB_10034188;
  }
  fVar1 = *(float *)(param_1 + 0x180) - *(float *)(iVar3 + 0xe88);
LAB_10034188:
  iVar2 = *(int *)(param_1 + 0x2a8);
  fVar1 = fVar1 * fVar1 * (float)_DAT_10044428;
  if (iVar2 != 3) {
    if (iVar2 == 2) {
      fVar1 = fVar1 * (float)_DAT_10044230;
    }
    if (iVar2 == 1) {
      fVar1 = fVar1 * (float)_DAT_10044140;
    }
    if (_DAT_10044104 <= fVar1) {
      if (fVar1 < _DAT_10044100) {
        *(undefined4 *)(param_1 + 0x50) = 2;
        return;
      }
      *(float *)(iVar3 + 0xe4c) = fVar1 * (float)_DAT_10044140;
      if (_DAT_10044288 < *(float *)(*(int *)(param_1 + 0x54) + 0xe4c)) {
        *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe4c) = 0x42200000;
      }
      *(float *)(*(int *)(param_1 + 0x54) + 0xe48) = DAT_1006c2e4 + (float)_DAT_10044128;
      if (fVar1 <= _DAT_10044220) {
        *(undefined4 *)(param_1 + 0x50) = 3;
        return;
      }
      if (0 < *(int *)(param_1 + 0x220)) {
        if (fVar1 < _DAT_10044420) {
          *(undefined4 *)(param_1 + 0x50) = 4;
        }
        else {
          *(undefined4 *)(param_1 + 0x50) = 5;
        }
      }
      *(float *)(param_1 + 0x210) = DAT_1006c2e4;
      lVar4 = __ftol();
      iVar3 = (int)lVar4;
      if (iVar3 < 1) {
        iVar3 = 1;
      }
      local_c[0] = 0.0;
      local_c[1] = 0.0;
      local_c[2] = 1.0;
      if ((*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) || (uVar5 = __ftol(), (uVar5 & 8) == 0)
         ) {
        FUN_100060d0(param_1,DAT_1006c2c4,DAT_1006c2c4,local_c,(float *)(param_1 + 4),&DAT_10061c18,
                     iVar3,0,0,0x16);
        return;
      }
    }
  }
  return;
}



/* FUN_10004560 @ 10004560 size 491 */

void __cdecl FUN_10004560(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  char *pcVar3;
  byte *pbStack_4;
  
  pbStack_4 = (byte *)(*DAT_1006c264)();
  iVar1 = FUN_10038b20(pbStack_4,(byte *)s_Grenades_10046384);
  pcVar3 = s_Mines_1004637c;
  if (iVar1 != 0) {
    iVar1 = FUN_10038b20(pbStack_4,(byte *)s_Mines_1004637c);
    if (iVar1 == 0) {
      pcVar3 = s_Grenades_10046384;
    }
    else {
      iVar1 = FUN_10038b20(pbStack_4,(byte *)s_Machinegun_10046370);
      pcVar3 = s_Plasma_Rifle_10046360;
      if (iVar1 != 0) {
        iVar1 = FUN_10038b20(pbStack_4,(byte *)s_Plasma_Rifle_10046360);
        if (iVar1 == 0) {
          pcVar3 = s_Machinegun_10046370;
        }
        else {
          iVar1 = FUN_10038b20(pbStack_4,(byte *)s_Deatomizer_10046354);
          pcVar3 = s_Hyperblaster_10046344;
          if (iVar1 != 0) {
            iVar1 = FUN_10038b20(pbStack_4,(byte *)s_Hyperblaster_10046344);
            if (iVar1 == 0) {
              pcVar3 = s_Deatomizer_10046354;
            }
            else {
              iVar1 = FUN_10038b20(pbStack_4,(byte *)s_Obliterator_10046338);
              pcVar3 = s_BFG10K_10046330;
              if (iVar1 != 0) {
                iVar1 = FUN_10038b20(pbStack_4,(byte *)s_BFG10K_10046330);
                if (iVar1 == 0) {
                  pcVar3 = s_Obliterator_10046338;
                }
                else {
                  iVar1 = FUN_10038b20(pbStack_4,(byte *)s_Detonation_Pack_10046320);
                  if (iVar1 == 0) {
                    pcVar3 = s_Remote_Detonator_1004630c;
                  }
                  else {
                    iVar1 = FUN_10038b20(pbStack_4,(byte *)s_Rocket_Launcher_100462fc);
                    if (iVar1 != 0) goto LAB_100046b2;
                    pcVar3 = s_HellFury_100462f0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  FUN_100044e0(param_1,(int *)&pbStack_4,(int)pcVar3);
LAB_100046b2:
  puVar2 = FUN_1000b150(pbStack_4);
  if (puVar2 == (undefined4 *)0x0) {
    (*DAT_1006c1c8)(param_1,2,s_unknown_item___s_100462dc,pbStack_4);
    return;
  }
  if ((code *)puVar2[2] != (code *)0x0) {
    if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0) {
      (*(code *)puVar2[2])(param_1,puVar2);
      return;
    }
    (*DAT_1006c1c8)(param_1,2,s_Out_of_item___s_100462b0,pbStack_4);
    return;
  }
  (*DAT_1006c1c8)(param_1,2,s_Item_is_not_usable__100462c4);
  return;
}



/* FUN_10021b60 @ 10021b60 size 489 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10021b60(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  *(undefined4 *)(param_1 + 0x4c) = 0;
  if (*(float *)(param_1 + 0x210) <= DAT_1006c2e4) {
    if ((param_4 < 0x29) &&
       (uVar1 = _rand(), (float)(uVar1 & 0x7fff) * _DAT_10044108 <= (float)_DAT_10044330)) {
      return;
    }
    if (((-1 < *(int *)(param_1 + 0x38)) && (*(int *)(param_1 + 0x38) < 8)) &&
       (uVar1 = _rand(), (float)(uVar1 & 0x7fff) * _DAT_10044108 <= (float)_DAT_10044350)) {
      return;
    }
    if (((7 < *(int *)(param_1 + 0x38)) && (*(int *)(param_1 + 0x38) < 0xe)) &&
       (uVar1 = _rand(), (float)(uVar1 & 0x7fff) * _DAT_10044108 <= (float)_DAT_10044348)) {
      return;
    }
    if (((0x11 < *(int *)(param_1 + 0x38)) && (*(int *)(param_1 + 0x38) < 0x1a)) &&
       (uVar1 = _rand(), (float)(uVar1 & 0x7fff) * _DAT_10044108 <= (float)_DAT_10044350)) {
      return;
    }
    *(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4;
    if (*(int *)(DAT_1006c41c + 0x14) != 0x40400000) {
      if (param_4 < 0x33) {
        (*DAT_1006c1d0)(param_1,2,DAT_1006105c,0x3f800000,0x3f800000,0);
        *(undefined **)(param_1 + 0x358) = &DAT_1004e858;
        return;
      }
      if (param_4 < 0x65) {
        (*DAT_1006c1d0)(param_1,2,DAT_10061050,0x3f800000,0x3f800000,0);
        *(undefined **)(param_1 + 0x358) = &DAT_1004e820;
        return;
      }
      uVar1 = _rand();
      if ((float)(uVar1 & 0x7fff) * _DAT_10044108 <= (float)_DAT_10044128) {
        (*DAT_1006c1d0)(param_1,2,DAT_10061054,0x3f800000,0x3f800000,0);
        *(undefined **)(param_1 + 0x358) = &DAT_1004e7e8;
      }
    }
  }
  return;
}



/* FUN_10031760 @ 10031760 size 485 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10031760(int param_1,byte *param_2)

{
  byte bVar1;
  bool bVar2;
  undefined3 extraout_var;
  char *pcVar3;
  byte *pbVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  void *this;
  uint uVar10;
  byte *pbVar11;
  ulonglong uVar12;
  
  bVar2 = FUN_10038d70((char *)param_2);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    pcVar3 = s__name_badinfo_skin_male_grunt_1005f414;
    pbVar4 = param_2;
    for (iVar8 = 7; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(undefined4 *)pbVar4 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      pbVar4 = pbVar4 + 4;
    }
    *(undefined2 *)pbVar4 = *(undefined2 *)pcVar3;
  }
  pcVar3 = FUN_10038bb0(param_2,&DAT_1005f40c);
  _strncpy((char *)(*(int *)(param_1 + 0x54) + 700),pcVar3,0xf);
  pbVar4 = FUN_10038bb0(param_2,(byte *)s_spectator_1005f3bc);
  if ((*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) || (*pbVar4 == 0)) {
LAB_10031813:
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x72c) = 0;
  }
  else {
    pbVar11 = &DAT_1004a49c;
    do {
      bVar1 = *pbVar4;
      bVar2 = bVar1 < *pbVar11;
      if (bVar1 != *pbVar11) {
LAB_100317fb:
        iVar8 = (1 - (uint)bVar2) - (uint)(bVar2 != 0);
        goto LAB_10031800;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar2 = bVar1 < pbVar11[1];
      if (bVar1 != pbVar11[1]) goto LAB_100317fb;
      pbVar4 = pbVar4 + 2;
      pbVar11 = pbVar11 + 2;
    } while (bVar1 != 0);
    iVar8 = 0;
LAB_10031800:
    if (iVar8 == 0) goto LAB_10031813;
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x72c) = 1;
  }
  puVar5 = FUN_10038bb0(param_2,&DAT_10046178);
  iVar8 = param_1 - DAT_1006c2c4;
  iVar9 = *(int *)(param_1 + 0x54) + 700;
  pcVar3 = s__s__s_1005f404;
  puVar6 = FUN_10038a50((byte *)s__s__s_1005f404);
  (*DAT_1006c1d8)(iVar8 / 0x3d0 + 0x51f,puVar6,pcVar3,iVar9,puVar5);
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    uVar12 = __ftol();
    if ((uVar12 & 0x8000) != 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x70) = 0x42b40000;
      goto LAB_100318f8;
    }
  }
  pbVar4 = FUN_10038bb0(param_2,&DAT_1005f3c8);
  iVar8 = FUN_10039237(this,pbVar4);
  *(float *)(*(int *)(param_1 + 0x54) + 0x70) = (float)iVar8;
  iVar8 = *(int *)(param_1 + 0x54);
  if (_DAT_10044104 <= *(float *)(iVar8 + 0x70)) {
    if (_DAT_100443d0 < *(float *)(iVar8 + 0x70)) {
      *(undefined4 *)(iVar8 + 0x70) = 0x43200000;
    }
  }
  else {
    *(undefined4 *)(iVar8 + 0x70) = 0x42b40000;
  }
LAB_100318f8:
  pbVar11 = FUN_10038bb0(param_2,&DAT_1005f3fc);
  uVar10 = 0xffffffff;
  pbVar4 = pbVar11;
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
  } while (bVar1 != 0);
  if ((void *)(~uVar10 - 1) != (void *)0x0) {
    uVar7 = FUN_10039237((void *)(~uVar10 - 1),pbVar11);
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x2cc) = uVar7;
  }
  _strncpy((char *)(*(int *)(param_1 + 0x54) + 0xbc),(char *)param_2,0x1ff);
  return;
}



/* FUN_1001e640 @ 1001e640 size 475 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_1001e640(int param_1,float *param_2,float *param_3,int param_4,int param_5,int param_6)

{
  float *pfVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  char *pcVar7;
  float afStack_38 [13];
  undefined4 uStack_4;
  
  FUN_10038900(param_3);
  piVar3 = FUN_1001b350();
  piVar3[0x2e] = 2;
  pfVar1 = (float *)(piVar3 + 1);
  *pfVar1 = *param_2;
  piVar3[2] = (int)param_2[1];
  piVar3[3] = (int)param_2[2];
  piVar3[7] = (int)*param_2;
  piVar3[8] = (int)param_2[1];
  piVar3[9] = (int)param_2[2];
  FUN_1001b1e0(param_3,(float *)(piVar3 + 4));
  FUN_10038a20(param_3,(float)param_5,(float *)(piVar3 + 0x5e));
  piVar3[0x3e] = 2;
  piVar3[0x41] = 8;
  piVar3[0x3f] = 0x6000003;
  piVar3[0x31] = 0;
  piVar3[0x30] = 0;
  piVar3[0x2f] = 0;
  piVar3[0x34] = 0;
  piVar3[0x33] = 0;
  piVar3[0x32] = 0;
  piVar3[0x11] = piVar3[0x11] | 0x1c00;
  piVar3[0x10] = piVar3[0x10] | 0x4000108;
  if (param_6 == 0) {
    pcVar7 = s_models_objects_pistolplasma_tris_1004c0b8;
  }
  else {
    pcVar7 = s_models_objects_plasma_tris_md2_1004c0e0;
  }
  iVar4 = (*DAT_1006c1e0)(pcVar7);
  piVar3[10] = iVar4;
  iVar4 = (*DAT_1006c1e4)(s_misc_lasfly_wav_1004be7c);
  piVar3[0x13] = iVar4;
  piVar3[0x40] = param_1;
  piVar3[0x7f] = (int)FUN_1001e520;
  fVar2 = DAT_1006c2e4 + _DAT_100441a8;
  piVar3[0x91] = param_4;
  piVar3[0x7d] = (int)FUN_1001b400;
  piVar3[0x46] = (int)&DAT_1004be74;
  piVar3[0x7b] = (int)fVar2;
  if (param_6 != 0) {
    piVar3[0x47] = 1;
  }
  (*DAT_1006c208)(piVar3);
  if (*(int *)(param_1 + 0x54) != 0) {
    FUN_1001c1c0(param_1,pfVar1,param_3,param_5);
  }
  pfVar5 = (float *)(*DAT_1006c1f0)(afStack_38,param_1 + 4,0,0,pfVar1,piVar3,0x6000003);
  pfVar6 = afStack_38;
  for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar6 = *pfVar5;
    pfVar5 = pfVar5 + 1;
    pfVar6 = pfVar6 + 1;
  }
  if (afStack_38[2] < (float)_DAT_10044120) {
    FUN_10038950(pfVar1,-10.0,param_3,pfVar1);
    (*(code *)piVar3[0x7f])(piVar3,uStack_4,0,0);
  }
  return;
}



/* FUN_1003e4e6 @ 1003e4e6 size 473 */

int __cdecl FUN_1003e4e6(uint param_1,char *param_2,char *param_3)

{
  int *piVar1;
  byte *pbVar2;
  char cVar3;
  byte bVar4;
  BOOL BVar5;
  DWORD DVar6;
  DWORD *pDVar7;
  char *pcVar8;
  int iVar9;
  DWORD local_10;
  char *local_c;
  char local_5;
  
  local_c = (char *)0x0;
  if (param_3 != (char *)0x0) {
    piVar1 = &DAT_1006ccc0 + ((int)param_1 >> 5);
    iVar9 = (param_1 & 0x1f) * 0x24;
    bVar4 = *(byte *)((&DAT_1006ccc0)[(int)param_1 >> 5] + iVar9 + 4);
    if ((bVar4 & 2) == 0) {
      pcVar8 = param_2;
      if (((bVar4 & 0x48) != 0) &&
         (cVar3 = *(char *)((&DAT_1006ccc0)[(int)param_1 >> 5] + iVar9 + 5), cVar3 != '\n')) {
        param_3 = param_3 + -1;
        *param_2 = cVar3;
        pcVar8 = param_2 + 1;
        local_c = (char *)0x1;
        *(undefined1 *)(*piVar1 + 5 + iVar9) = 10;
      }
      BVar5 = ReadFile(*(HANDLE *)(*piVar1 + iVar9),pcVar8,(DWORD)param_3,&local_10,
                       (LPOVERLAPPED)0x0);
      if (BVar5 == 0) {
        DVar6 = GetLastError();
        if (DVar6 == 5) {
          pDVar7 = FUN_1004058e();
          *pDVar7 = 9;
          pDVar7 = FUN_10040597();
          *pDVar7 = 5;
        }
        else {
          if (DVar6 == 0x6d) {
            return 0;
          }
          FUN_1004051b(DVar6);
        }
        return -1;
      }
      bVar4 = *(byte *)(*piVar1 + 4 + iVar9);
      if ((bVar4 & 0x80) == 0) {
        return (int)local_c + local_10;
      }
      if ((local_10 == 0) || (*param_2 != '\n')) {
        bVar4 = bVar4 & 0xfb;
      }
      else {
        bVar4 = bVar4 | 4;
      }
      *(byte *)(*piVar1 + 4 + iVar9) = bVar4;
      param_3 = param_2;
      local_c = param_2 + (int)local_c + local_10;
      pcVar8 = param_2;
      if (param_2 < local_c) {
        do {
          cVar3 = *param_3;
          if (cVar3 == '\x1a') {
            pbVar2 = (byte *)(*piVar1 + 4 + iVar9);
            bVar4 = *pbVar2;
            if ((bVar4 & 0x40) == 0) {
              *pbVar2 = bVar4 | 2;
            }
            break;
          }
          if (cVar3 == '\r') {
            if (param_3 < local_c + -1) {
              if (param_3[1] == '\n') {
                param_3 = param_3 + 2;
                goto LAB_1003e671;
              }
              *pcVar8 = '\r';
              pcVar8 = pcVar8 + 1;
              param_3 = param_3 + 1;
            }
            else {
              param_3 = param_3 + 1;
              BVar5 = ReadFile(*(HANDLE *)(*piVar1 + iVar9),&local_5,1,&local_10,(LPOVERLAPPED)0x0);
              if (((BVar5 == 0) && (DVar6 = GetLastError(), DVar6 != 0)) || (local_10 == 0)) {
LAB_1003e68b:
                *pcVar8 = '\r';
LAB_1003e68e:
                pcVar8 = pcVar8 + 1;
              }
              else if ((*(byte *)(*piVar1 + 4 + iVar9) & 0x48) == 0) {
                if ((pcVar8 == param_2) && (local_5 == '\n')) {
LAB_1003e671:
                  *pcVar8 = '\n';
                  goto LAB_1003e68e;
                }
                FUN_10040751(param_1,-1,1);
                if (local_5 != '\n') goto LAB_1003e68b;
              }
              else {
                if (local_5 == '\n') goto LAB_1003e671;
                *pcVar8 = '\r';
                pcVar8 = pcVar8 + 1;
                *(char *)(*piVar1 + 5 + iVar9) = local_5;
              }
            }
          }
          else {
            *pcVar8 = cVar3;
            pcVar8 = pcVar8 + 1;
            param_3 = param_3 + 1;
          }
        } while (param_3 < local_c);
      }
      return (int)pcVar8 - (int)param_2;
    }
  }
  return 0;
}



/* FUN_1001c4a0 @ 1001c4a0 size 472 */

void __cdecl FUN_1001c4a0(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  undefined4 uVar5;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c [3];
  
  if (*(int *)(param_1[0x40] + 0x54) != 0) {
    FUN_100350a0(param_1[0x40],(float *)(param_1 + 1),2);
  }
  iVar1 = param_1[0x97];
  if (iVar1 != 0) {
    local_24 = *(float *)(iVar1 + 200) + *(float *)(iVar1 + 0xbc);
    local_20 = *(float *)(iVar1 + 0xcc) + *(float *)(iVar1 + 0xc0);
    local_1c = *(float *)(iVar1 + 0xd0) + *(float *)(iVar1 + 0xc4);
    FUN_10038950((float *)(iVar1 + 4),0.5,&local_24,&local_24);
    local_24 = (float)param_1[1] - local_24;
    local_20 = (float)param_1[2] - local_20;
    local_1c = (float)param_1[3] - local_1c;
    FUN_100389f0(&local_24);
    uVar3 = param_1[0x97];
    uVar2 = param_1[0x47];
    local_18 = *(float *)(uVar3 + 4) - (float)param_1[1];
    local_14 = *(float *)(uVar3 + 8) - (float)param_1[2];
    local_10 = *(float *)(uVar3 + 0xc) - (float)param_1[3];
    lVar4 = __ftol();
    FUN_100060d0(uVar3,param_1,param_1[0x40],&local_18,(float *)(param_1 + 1),&DAT_10061c18,
                 (int)lVar4,(int)lVar4,1,(-(uint)((uVar2 & 1) != 0) & 9) + 6);
  }
  if ((param_1[0x47] & 2) == 0) {
    uVar3 = (-(uint)((param_1[0x47] & 1) != 0) & 9) + 7;
  }
  else {
    uVar3 = 0x18;
  }
  FUN_10006860((float)param_1,param_1[0x40],(float)(int)param_1[0x91],param_1[0x97],
               (float)param_1[0x93],uVar3);
  FUN_10038950((float *)(param_1 + 1),-0.02,(float *)(param_1 + 0x5e),local_c);
  (*DAT_1006c224)(3);
  if (param_1[0xaa] == 0) {
    if (param_1[0x9a] == 0) {
      uVar5 = 7;
    }
    else {
      uVar5 = 8;
    }
  }
  else if (param_1[0x9a] == 0) {
    uVar5 = 0x11;
  }
  else {
    uVar5 = 0x12;
  }
  (*DAT_1006c224)(uVar5);
  (*DAT_1006c238)(local_c);
  (*DAT_1006c218)(param_1 + 1,1);
  FUN_1001b400(param_1);
  return;
}



/* FUN_10037a10 @ 10037a10 size 472 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10037a10(float param_1,float *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  float local_30;
  float local_2c;
  float local_28;
  float local_24 [3];
  float local_18 [3];
  float local_c [3];
  
  piVar1 = (int *)(*(int *)((int)param_1 + 0x54) + 0x2e4 +
                  *(int *)(*(int *)((int)param_1 + 0x54) + 0xde8) * 4);
  iVar2 = *piVar1;
  if (9 < iVar2) {
    *piVar1 = iVar2 + -10;
    if (DAT_100613c0 != 0) {
      param_3 = param_3 * 4;
    }
    FUN_10038700((float *)(*(int *)((int)param_1 + 0x54) + 0xe64),local_24,local_c,(float *)0x0);
    local_30 = *param_2 + _DAT_10044480;
    local_2c = param_2[1] + _DAT_10044164;
    local_28 = (float)(*(int *)((int)param_1 + 0x23c) + -8) + param_2[2];
    FUN_10035db0(*(int *)((int)param_1 + 0x54),(float *)((int)param_1 + 4),&local_30,local_24,
                 local_c,local_18);
    FUN_10038a20(local_24,-2.0,(float *)(*(int *)((int)param_1 + 0x54) + 0xe30));
    *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xe24) = 0xbf800000;
    FUN_1001e240(param_1,(int *)local_18,local_24,param_3,1.4013e-42);
    (*DAT_1006c224)(1);
    (*DAT_1006c228)(((int)param_1 - DAT_1006c2c4) / 0x3d0);
    (*DAT_1006c224)(0x86);
    (*DAT_1006c218)((float *)((int)param_1 + 4),2);
    if ((char)DAT_100613c4 == '\0') {
      uVar3 = 0x3f800000;
    }
    else {
      uVar3 = 0x3f000000;
    }
    uVar3 = (*DAT_1006c1e4)(s_deatom_dfire_wav_1005fa10,uVar3,0x3f800000,0);
    (*DAT_1006c1d0)(param_1,2,uVar3);
    FUN_100350a0((int)param_1,local_18,1);
    return;
  }
  if (*(float *)((int)param_1 + 0x210) <= DAT_1006c2e4) {
    uVar3 = (*DAT_1006c1e4)(s_weapons_noammo_wav_1004b5c8,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_1,2,uVar3);
    *(float *)((int)param_1 + 0x210) = DAT_1006c2e4 + _DAT_10044104;
  }
  FUN_10035530((int)param_1);
  return;
}



/* FUN_100065b0 @ 100065b0 size 469 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_100065b0(int param_1,float *param_2,undefined4 param_3,int param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined3 extraout_var;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar2 = param_1;
  if ((param_4 != 0) && (iVar1 = *(int *)(param_1 + 0x54), (param_5 & 2) == 0)) {
    if (iVar1 == 0) {
      if ((*(byte *)(param_1 + 0xb8) & 4) == 0) {
        return 0;
      }
      iVar6 = *(int *)(param_1 + 0x3c8);
      param_1 = *(int *)(param_1 + 0x3cc);
    }
    else {
      bVar3 = FUN_1000c460(param_1);
      iVar6 = CONCAT31(extraout_var,bVar3);
      if (iVar6 == 0) {
        return 0;
      }
      puVar4 = FUN_1000b150((byte *)s_Cells_1004662c);
      param_5 = (int)(puVar4 + -0x4011a4a) / 0x48;
      param_1 = *(int *)(iVar1 + 0x2e4 + param_5 * 4);
    }
    if ((iVar6 != 0) && (param_1 != 0)) {
      if (iVar6 == 1) {
        FUN_10038700((float *)(iVar2 + 0x10),&local_c,(float *)0x0,(float *)0x0);
        local_18 = *param_2 - *(float *)(iVar2 + 4);
        local_14 = param_2[1] - *(float *)(iVar2 + 8);
        local_10 = param_2[2] - *(float *)(iVar2 + 0xc);
        FUN_10038900(&local_18);
        if (local_c * local_18 + local_8 * local_14 + local_4 * local_10 <= (float)_DAT_10044128) {
          return 0;
        }
        iVar8 = 1;
        iVar6 = param_4 / 3 + (param_4 >> 0x1f);
        uVar5 = 0xc;
      }
      else {
        iVar8 = 2;
        uVar5 = 0xd;
        iVar6 = (param_4 * 2) / 3 + (param_4 * 2 >> 0x1f);
      }
      iVar7 = iVar8 * param_1;
      iVar6 = iVar6 - (iVar6 >> 0x1f);
      if (iVar7 != 0) {
        if (iVar7 - iVar6 != 0 && iVar6 <= iVar7) {
          iVar7 = iVar6;
        }
        FUN_10005df0(uVar5,param_2,param_3);
        *(float *)(iVar2 + 0x234) = DAT_1006c2e4 + (float)_DAT_10044198;
        if (iVar1 == 0) {
          *(int *)(iVar2 + 0x3cc) = *(int *)(iVar2 + 0x3cc) - iVar7 / iVar8;
          return iVar7;
        }
        *(int *)(iVar1 + 0x2e4 + param_5 * 4) =
             *(int *)(iVar1 + 0x2e4 + param_5 * 4) - iVar7 / iVar8;
        return iVar7;
      }
    }
  }
  return 0;
}



/* FUN_1002fe80 @ 1002fe80 size 465 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1002fe80(float param_1)

{
  byte bVar1;
  int iVar2;
  float fVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  int *piVar7;
  char *pcVar8;
  bool bVar9;
  ulonglong uVar10;
  
  fVar3 = param_1;
  if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
    return;
  }
  iVar2 = *(int *)((int)param_1 + 0x54);
  piVar7 = *(int **)(iVar2 + 0x714);
  if (*(int *)(iVar2 + 0x2e4 + *(int *)(iVar2 + 0xde8) * 4) != 0) {
    if (piVar7 == (int *)0x0) goto LAB_1002ff31;
    pbVar6 = (byte *)piVar7[10];
    pcVar8 = s_Blaster_10048c1c;
    pbVar4 = pbVar6;
    do {
      bVar1 = *pbVar4;
      bVar9 = bVar1 < (byte)*pcVar8;
      if (bVar1 != *pcVar8) {
LAB_1002fef2:
        iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_1002fef7;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar9 = bVar1 < (byte)pcVar8[1];
      if (bVar1 != pcVar8[1]) goto LAB_1002fef2;
      pbVar4 = pbVar4 + 2;
      pcVar8 = pcVar8 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_1002fef7:
    if (iVar5 != 0) {
      pcVar8 = s_Plasma_Pistol_10048cb0;
      do {
        bVar1 = *pbVar6;
        bVar9 = bVar1 < (byte)*pcVar8;
        if (bVar1 != *pcVar8) {
LAB_1002ff26:
          iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_1002ff2b;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar6[1];
        bVar9 = bVar1 < (byte)pcVar8[1];
        if (bVar1 != pcVar8[1]) goto LAB_1002ff26;
        pbVar6 = pbVar6 + 2;
        pcVar8 = pcVar8 + 2;
      } while (bVar1 != 0);
      iVar5 = 0;
LAB_1002ff2b:
      if (iVar5 != 0) goto LAB_1002ff31;
    }
  }
  piVar7 = (int *)0x0;
LAB_1002ff31:
  uVar10 = __ftol();
  if ((uVar10 & 0x4000) == 0) {
    bVar9 = false;
  }
  else if (*(float *)(iVar2 + 0xeac) <= (float)(DAT_1006c2e0 + 10)) {
    bVar9 = false;
  }
  else {
    bVar9 = true;
  }
  if ((piVar7 == (int *)0x0) || (param_1 = 22.5, !bVar9)) {
    param_1 = 0.0;
  }
  if (piVar7 != (int *)0x0) {
    *(float *)(iVar2 + 0xe68) = *(float *)(iVar2 + 0xe68) - param_1;
    piVar7 = FUN_1000c850((int)fVar3,piVar7);
    *(float *)(*(int *)((int)fVar3 + 0x54) + 0xe68) =
         param_1 + *(float *)(*(int *)((int)fVar3 + 0x54) + 0xe68);
    piVar7[0x47] = 0x20000;
  }
  if (bVar9) {
    *(float *)(*(int *)((int)fVar3 + 0x54) + 0xe68) =
         param_1 + *(float *)(*(int *)((int)fVar3 + 0x54) + 0xe68);
    piVar7 = FUN_1000b100((byte *)s_item_quad_10047ed8);
    piVar7 = FUN_1000c850((int)fVar3,piVar7);
    *(float *)(*(int *)((int)fVar3 + 0x54) + 0xe68) =
         *(float *)(*(int *)((int)fVar3 + 0x54) + 0xe68) - param_1;
    piVar7[0x7f] = (int)FUN_1000c650;
    piVar7[0x47] = piVar7[0x47] | 0x20000;
    fVar3 = (*(float *)(*(int *)((int)fVar3 + 0x54) + 0xeac) - (float)DAT_1006c2e0) *
            (float)_DAT_10044168 + DAT_1006c2e4;
    piVar7[0x7d] = (int)FUN_1001b400;
    piVar7[0x7b] = (int)fVar3;
  }
  return;
}



/* FUN_1001dd00 @ 1001dd00 size 458 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1001dd00(int *param_1)

{
  undefined4 *puVar1;
  float fVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  float *pfVar7;
  int *piVar8;
  
  piVar3 = param_1;
  if ((double)param_1[0x95] != _DAT_100442e8) {
    if (param_1[0x95] == 0) {
      param_1[0x3e] = 0;
      param_1[0x5e] = 0;
      param_1[0x5f] = 0;
      param_1[0x60] = 0;
      param_1[0x61] = 0;
      param_1[0x62] = 0x42940000;
      param_1[99] = 0;
      param_1 = (int *)0x4;
      piVar8 = piVar3;
      do {
        piVar5 = FUN_1001b350();
        pfVar7 = (float *)(piVar5 + 0x55);
        piVar5[0x99] = piVar3[0x40];
        piVar5[0x40] = piVar3[0x40];
        piVar5[0x47] = 0x89;
        FUN_10038700((float *)(piVar8 + 4),(float *)0x0,pfVar7,(float *)0x0);
        FUN_10038900(pfVar7);
        FUN_1001b1e0(pfVar7,(float *)(piVar5 + 4));
        piVar5[1] = piVar3[1];
        piVar5[2] = piVar3[2];
        piVar5[3] = piVar3[3];
        piVar5[0x91] = 0x28;
        piVar5[0x46] = (int)s_mine_laser_1004c03c;
        piVar8[0x96] = (int)piVar5;
        FUN_10018830((uint)piVar5);
        (*DAT_1006c208)(piVar5);
        param_1 = (int *)((int)param_1 + -1);
        piVar8 = piVar5;
      } while (param_1 != (int *)0x0);
    }
    pfVar7 = (float *)(piVar3 + 4);
    param_1 = (int *)0x4;
    piVar8 = piVar3;
    do {
      FUN_10038700(pfVar7,(float *)0x0,(float *)(piVar8[0x96] + 0x154),(float *)0x0);
      piVar8 = (int *)piVar8[0x96];
      FUN_10038900((float *)(piVar8 + 0x55));
      pfVar7 = (float *)(piVar8 + 4);
      FUN_1001b1e0((float *)(piVar8 + 0x55),pfVar7);
      param_1 = (int *)((int)param_1 + -1);
      piVar8[0x47] = piVar8[0x47] | 0x80000000;
    } while (param_1 != (int *)0x0);
    piVar3[0x95] = piVar3[0x95] + 1;
    piVar3[0x7b] = (int)(DAT_1006c2e4 + (float)_DAT_10044168);
    return;
  }
  iVar6 = 4;
  puVar4 = (undefined4 *)param_1[0x96];
  do {
    puVar1 = (undefined4 *)puVar4[0x96];
    FUN_1001b400(puVar4);
    iVar6 = iVar6 + -1;
    puVar4 = puVar1;
  } while (iVar6 != 0);
  fVar2 = DAT_1006c2e4 + (float)_DAT_10044168;
  param_1[0x7d] = (int)FUN_1001db40;
  param_1[0x7b] = (int)fVar2;
  return;
}



/* FUN_1000e210 @ 1000e210 size 457 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000e210(int param_1,undefined4 param_2,float param_3,int *param_4)

{
  float fVar1;
  int *piVar2;
  uint uVar3;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  piVar2 = FUN_1001b350();
  piVar2[1] = *param_4;
  piVar2[2] = param_4[1];
  piVar2[3] = param_4[2];
  (*DAT_1006c1ec)(piVar2,param_2);
  uVar3 = _rand();
  fVar1 = (float)(uVar3 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  fStack_c = (fVar1 + fVar1) * (float)_DAT_100441e0;
  uVar3 = _rand();
  fVar1 = (float)(uVar3 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  fStack_8 = (fVar1 + fVar1) * (float)_DAT_100441e0;
  uVar3 = _rand();
  fVar1 = (float)(uVar3 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  fStack_4 = (fVar1 + fVar1 + (float)_DAT_10044120) * (float)_DAT_100441e0;
  FUN_10038950((float *)(param_1 + 0x178),param_3,&fStack_c,(float *)(piVar2 + 0x5e));
  piVar2[0x41] = 9;
  piVar2[0x3e] = 0;
  uVar3 = _rand();
  piVar2[0x61] = (int)((float)(uVar3 & 0x7fff) * _DAT_10044108 * _DAT_100441f0);
  uVar3 = _rand();
  piVar2[0x62] = (int)((float)(uVar3 & 0x7fff) * _DAT_10044108 * _DAT_100441f0);
  uVar3 = _rand();
  piVar2[0x7d] = (int)FUN_1001b400;
  piVar2[99] = (int)((float)(uVar3 & 0x7fff) * _DAT_10044108 * _DAT_100441f0);
  uVar3 = _rand();
  fVar1 = ((float)(uVar3 & 0x7fff) * _DAT_10044108 + _DAT_10044104) * _DAT_1004414c + DAT_1006c2e4;
  piVar2[0xe] = 0;
  piVar2[0x42] = 0;
  piVar2[0x46] = (int)s_debris_100491f8;
  piVar2[0x90] = 1;
  piVar2[0x82] = (int)&LAB_1000fd20;
  piVar2[0x7b] = (int)fVar1;
  (*DAT_1006c208)(piVar2);
  return;
}



/* FUN_10038da0 @ 10038da0 size 457 */

void __cdecl FUN_10038da0(byte *param_1,byte *param_2,char *param_3)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte local_200 [512];
  
  pcVar3 = _strstr((char *)param_2,&DAT_1005fa70);
  if ((pcVar3 != (char *)0x0) || (pcVar3 = _strstr(param_3,&DAT_1005fa70), pcVar3 != (char *)0x0)) {
    FUN_1000d560((byte *)s_Can_t_use_keys_or_values_with_a___1005fa7c);
    return;
  }
  pcVar3 = _strstr((char *)param_2,&DAT_1005fa74);
  if (pcVar3 != (char *)0x0) {
    FUN_1000d560((byte *)s_Can_t_use_keys_or_values_with_a_s_1005fb18);
    return;
  }
  pcVar3 = _strstr((char *)param_2,&DAT_1005fa78);
  if ((pcVar3 != (char *)0x0) || (pcVar3 = _strstr(param_3,&DAT_1005fa78), pcVar3 != (char *)0x0)) {
    FUN_1000d560((byte *)s_Can_t_use_keys_or_values_with_a___1005faa0);
    return;
  }
  uVar4 = 0xffffffff;
  pbVar7 = param_2;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    bVar2 = *pbVar7;
    pbVar7 = pbVar7 + 1;
  } while (bVar2 != 0);
  if (~uVar4 - 1 < 0x40) {
    uVar4 = 0xffffffff;
    pcVar3 = param_3;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (~uVar4 - 1 < 0x40) {
      FUN_10038c90(param_1,param_2);
      if (param_3 == (char *)0x0) {
        return;
      }
      iVar5 = -1;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        cVar1 = *param_3;
        param_3 = param_3 + 1;
      } while (cVar1 != '\0');
      if (iVar5 == -2) {
        return;
      }
      FUN_10038b40();
      uVar4 = 0xffffffff;
      pbVar7 = param_1;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        bVar2 = *pbVar7;
        pbVar7 = pbVar7 + 1;
      } while (bVar2 != 0);
      uVar6 = 0xffffffff;
      pbVar7 = local_200;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        bVar2 = *pbVar7;
        pbVar7 = pbVar7 + 1;
      } while (bVar2 != 0);
      if (0x200 < ~uVar4 + (~uVar6 - 2)) {
        FUN_1000d560((byte *)s_Info_string_length_exceeded_1005faf0);
        return;
      }
      uVar4 = 0xffffffff;
      pbVar7 = param_1;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        bVar2 = *pbVar7;
        pbVar7 = pbVar7 + 1;
      } while (bVar2 != 0);
      pbVar8 = param_1 + (~uVar4 - 1);
      pbVar7 = local_200;
      while (local_200[0] != 0) {
        bVar2 = *pbVar7 & 0x7f;
        pbVar7 = pbVar7 + 1;
        if ((0x1f < bVar2) && (bVar2 < 0x7f)) {
          *pbVar8 = bVar2;
          pbVar8 = pbVar8 + 1;
        }
        local_200[0] = *pbVar7;
      }
      *pbVar8 = 0;
      return;
    }
  }
  FUN_1000d560((byte *)s_Keys_and_values_must_be_<_64_cha_1005fac4);
  return;
}



/* FUN_1001cf50 @ 1001cf50 size 449 */

void __cdecl FUN_1001cf50(uint param_1,float *param_2,float *param_3,int param_4,int param_5)

{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  int iVar6;
  uint uVar7;
  float *pfVar8;
  uint local_90;
  float local_88;
  float local_84;
  float local_80;
  float afStack_7c [4];
  float fStack_6c;
  float fStack_68;
  undefined1 auStack_64 [24];
  byte bStack_4c;
  uint uStack_48;
  float local_44 [3];
  undefined1 local_38 [56];
  
  FUN_10038950(param_2,8192.0,param_3,local_44);
  bVar1 = false;
  local_90 = 0x600001b;
  fVar2 = *param_2;
  fVar3 = param_2[1];
  fVar4 = param_2[2];
  uVar7 = param_1;
  while (local_80 = fVar4, local_84 = fVar3, local_88 = fVar2, uVar7 != 0) {
    pfVar5 = (float *)(*DAT_1006c1f0)(local_38,&local_88,0,0,local_44,uVar7,local_90);
    pfVar8 = afStack_7c;
    for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {
      *pfVar8 = *pfVar5;
      pfVar5 = pfVar5 + 1;
      pfVar8 = pfVar8 + 1;
    }
    if ((bStack_4c & 0x18) == 0) {
      uVar7 = uStack_48;
      if ((((*(byte *)(uStack_48 + 0xb8) & 4) == 0) && (*(int *)(uStack_48 + 0x54) == 0)) &&
         (*(int *)(uStack_48 + 0xf8) != 2)) {
        uVar7 = 0;
      }
      fVar2 = afStack_7c[3];
      fVar3 = fStack_6c;
      fVar4 = fStack_68;
      if ((uStack_48 != param_1) &&
         (fVar2 = afStack_7c[3], fVar3 = fStack_6c, fVar4 = fStack_68,
         *(int *)(uStack_48 + 0x240) != 0)) {
        FUN_100060d0(uStack_48,param_1,param_1,param_3,afStack_7c + 3,auStack_64,param_4,param_5,0,
                     0xb);
        fVar2 = afStack_7c[3];
        fVar3 = fStack_6c;
        fVar4 = fStack_68;
      }
    }
    else {
      bVar1 = true;
      local_90 = local_90 & 0xffffffe7;
      fVar2 = afStack_7c[3];
      fVar3 = fStack_6c;
      fVar4 = fStack_68;
    }
  }
  (*DAT_1006c224)(3);
  (*DAT_1006c224)(3);
  (*DAT_1006c238)(param_2);
  (*DAT_1006c238)(afStack_7c + 3);
  (*DAT_1006c218)(param_1 + 4,1);
  if (bVar1) {
    (*DAT_1006c224)(3);
    (*DAT_1006c224)(3);
    (*DAT_1006c238)(param_2);
    (*DAT_1006c238)(afStack_7c + 3);
    (*DAT_1006c218)(afStack_7c + 3,1);
  }
  if (*(int *)(param_1 + 0x54) != 0) {
    FUN_100350a0(param_1,afStack_7c + 3,2);
  }
  return;
}



/* FUN_1001c000 @ 1001c000 size 445 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_1001c000(int param_1,float *param_2,float *param_3,int param_4,int param_5,uint param_6,
            int param_7)

{
  float *pfVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  float afStack_38 [13];
  undefined4 uStack_4;
  
  FUN_10038900(param_3);
  piVar3 = FUN_1001b350();
  piVar3[0x2e] = 2;
  pfVar1 = (float *)(piVar3 + 1);
  *pfVar1 = *param_2;
  piVar3[2] = (int)param_2[1];
  piVar3[3] = (int)param_2[2];
  piVar3[7] = (int)*param_2;
  piVar3[8] = (int)param_2[1];
  piVar3[9] = (int)param_2[2];
  FUN_1001b1e0(param_3,(float *)(piVar3 + 4));
  FUN_10038a20(param_3,(float)param_5,(float *)(piVar3 + 0x5e));
  piVar3[0x3e] = 2;
  piVar3[0x41] = 8;
  piVar3[0x10] = piVar3[0x10] | param_6;
  piVar3[0x3f] = 0x6000003;
  piVar3[0x31] = 0;
  piVar3[0x30] = 0;
  piVar3[0x2f] = 0;
  piVar3[0x34] = 0;
  piVar3[0x33] = 0;
  piVar3[0x32] = 0;
  iVar4 = (*DAT_1006c1e0)(s_models_objects_laser_tris_md2_1004be8c);
  piVar3[10] = iVar4;
  iVar4 = (*DAT_1006c1e4)(s_misc_lasfly_wav_1004be7c);
  piVar3[0x13] = iVar4;
  piVar3[0x40] = param_1;
  piVar3[0x7f] = (int)FUN_1001bf10;
  fVar2 = DAT_1006c2e4 + _DAT_1004413c;
  piVar3[0x7d] = (int)FUN_1001b400;
  piVar3[0x91] = param_4;
  piVar3[0x46] = (int)&DAT_1004be74;
  piVar3[0x7b] = (int)fVar2;
  if (param_7 != 0) {
    piVar3[0x47] = 1;
  }
  (*DAT_1006c208)(piVar3);
  if (*(int *)(param_1 + 0x54) != 0) {
    FUN_1001c1c0(param_1,pfVar1,param_3,param_5);
  }
  pfVar5 = (float *)(*DAT_1006c1f0)(afStack_38,param_1 + 4,0,0,pfVar1,piVar3,0x6000003);
  pfVar6 = afStack_38;
  for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar6 = *pfVar5;
    pfVar5 = pfVar5 + 1;
    pfVar6 = pfVar6 + 1;
  }
  if (afStack_38[2] < (float)_DAT_10044120) {
    FUN_10038950(pfVar1,-10.0,param_3,pfVar1);
    (*(code *)piVar3[0x7f])(piVar3,uStack_4,0,0);
  }
  return;
}



/* FUN_1003f14b @ 1003f14b size 444 */

void FUN_1003f14b(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  HANDLE hFile;
  UINT *pUVar5;
  int iVar6;
  uint uVar7;
  UINT UVar8;
  UINT UVar9;
  _STARTUPINFOA local_4c;
  byte *local_8;
  
  puVar2 = _malloc(0x480);
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_1006cdc0 = 0x20;
  DAT_1006ccc0 = puVar2;
  for (; puVar2 < DAT_1006ccc0 + 0x120; puVar2 = puVar2 + 9) {
    *(undefined1 *)(puVar2 + 1) = 0;
    *puVar2 = 0xffffffff;
    puVar2[2] = 0;
    *(undefined1 *)((int)puVar2 + 5) = 10;
  }
  GetStartupInfoA(&local_4c);
  if ((local_4c.cbReserved2 != 0) && ((UINT *)local_4c.lpReserved2 != (UINT *)0x0)) {
    UVar8 = *(UINT *)local_4c.lpReserved2;
    pUVar5 = (UINT *)((int)local_4c.lpReserved2 + 4);
    local_8 = (byte *)((int)pUVar5 + UVar8);
    if (0x7ff < (int)UVar8) {
      UVar8 = 0x800;
    }
    UVar9 = UVar8;
    if ((int)DAT_1006cdc0 < (int)UVar8) {
      puVar2 = &DAT_1006ccc4;
      do {
        puVar3 = _malloc(0x480);
        UVar9 = DAT_1006cdc0;
        if (puVar3 == (undefined4 *)0x0) break;
        DAT_1006cdc0 = DAT_1006cdc0 + 0x20;
        *puVar2 = puVar3;
        puVar1 = puVar3;
        for (; puVar3 < puVar1 + 0x120; puVar3 = puVar3 + 9) {
          *(undefined1 *)(puVar3 + 1) = 0;
          *puVar3 = 0xffffffff;
          puVar3[2] = 0;
          *(undefined1 *)((int)puVar3 + 5) = 10;
          puVar1 = (undefined4 *)*puVar2;
        }
        puVar2 = puVar2 + 1;
        UVar9 = UVar8;
      } while ((int)DAT_1006cdc0 < (int)UVar8);
    }
    uVar7 = 0;
    if (0 < (int)UVar9) {
      do {
        if (((*(HANDLE *)local_8 != (HANDLE)0xffffffff) && ((*pUVar5 & 1) != 0)) &&
           (((*pUVar5 & 8) != 0 || (DVar4 = GetFileType(*(HANDLE *)local_8), DVar4 != 0)))) {
          puVar2 = (undefined4 *)((int)(&DAT_1006ccc0)[(int)uVar7 >> 5] + (uVar7 & 0x1f) * 0x24);
          *puVar2 = *(undefined4 *)local_8;
          *(byte *)(puVar2 + 1) = (byte)*pUVar5;
        }
        local_8 = local_8 + 4;
        uVar7 = uVar7 + 1;
        pUVar5 = (UINT *)((int)pUVar5 + 1);
      } while ((int)uVar7 < (int)UVar9);
    }
  }
  iVar6 = 0;
  do {
    puVar2 = DAT_1006ccc0 + iVar6 * 9;
    if (DAT_1006ccc0[iVar6 * 9] == -1) {
      *(undefined1 *)(puVar2 + 1) = 0x81;
      if (iVar6 == 0) {
        DVar4 = 0xfffffff6;
      }
      else {
        DVar4 = 0xfffffff5 - (iVar6 != 1);
      }
      hFile = GetStdHandle(DVar4);
      if ((hFile != (HANDLE)0xffffffff) && (DVar4 = GetFileType(hFile), DVar4 != 0)) {
        *puVar2 = hFile;
        if ((DVar4 & 0xff) != 2) {
          if ((DVar4 & 0xff) == 3) {
            *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 8;
          }
          goto LAB_1003f2f0;
        }
      }
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x40;
    }
    else {
      *(byte *)(puVar2 + 1) = *(byte *)(puVar2 + 1) | 0x80;
    }
LAB_1003f2f0:
    iVar6 = iVar6 + 1;
    if (2 < iVar6) {
      SetHandleCount(DAT_1006cdc0);
      return;
    }
  } while( true );
}



/* FUN_10035260 @ 10035260 size 443 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong __cdecl FUN_10035260(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint extraout_EDX;
  uint uVar3;
  uint extraout_EDX_00;
  uint extraout_EDX_01;
  ulonglong uVar4;
  int iVar5;
  
  iVar1 = (*(int *)(param_1 + 0x2cc) + -0x10046928) / 0x48;
  uVar4 = __ftol();
  uVar3 = (uint)(uVar4 >> 0x20);
  if (((((uVar4 & 4) != 0) ||
       (uVar3 = DAT_1006c42c, *(float *)(DAT_1006c42c + 0x14) != _DAT_1004410c)) &&
      (*(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar1 * 4) != 0)) &&
     ((*(uint *)(param_1 + 0x11c) & 0x30000) == 0)) {
    return (ulonglong)uVar3 << 0x20;
  }
  *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar1 * 4) =
       *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar1 * 4) + 1;
  if ((*(uint *)(param_1 + 0x11c) & 0x10000) == 0) {
    puVar2 = FUN_1000b150(*(byte **)(*(int *)(param_1 + 0x2cc) + 0x34));
    uVar4 = __ftol();
    if ((uVar4 & 0x2000) == 0) {
      iVar5 = FUN_10038b20(*(void **)(param_1 + 0x118),(byte *)s_weapon_hellfury_10048510);
      if (iVar5 == 0) {
        iVar5 = 0x10;
      }
      else {
        iVar5 = puVar2[0xc];
      }
    }
    else {
      iVar5 = 1000;
    }
    FUN_1000bdf0(param_2,(int)puVar2,iVar5);
    uVar3 = extraout_EDX;
    if ((*(uint *)(param_1 + 0x11c) & 0x20000) == 0) {
      if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
        uVar4 = __ftol();
        uVar3 = (uint)(uVar4 >> 0x20);
        if ((uVar4 & 4) == 0) {
          FUN_1000b210(param_1,30.0);
          uVar3 = extraout_EDX_00;
        }
        else {
          *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) | 0x80000000;
        }
      }
      if (*(float *)(DAT_1006c42c + 0x14) != _DAT_1004410c) {
        *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) | 0x80000000;
      }
    }
  }
  iVar5 = *(int *)(param_2 + 0x54);
  if ((*(int *)(iVar5 + 0x714) != *(int *)(param_1 + 0x2cc)) &&
     (*(int *)(iVar5 + 0x2e4 + iVar1 * 4) == 1)) {
    uVar3 = DAT_1006c118;
    if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
      puVar2 = FUN_1000b150((byte *)s_Plasma_Pistol_10048cb0);
      uVar3 = extraout_EDX_01;
      if (*(undefined4 **)(iVar5 + 0x714) != puVar2) goto LAB_10035411;
    }
    *(undefined4 *)(iVar5 + 0xdfc) = *(undefined4 *)(param_1 + 0x2cc);
  }
LAB_10035411:
  return CONCAT44(uVar3,1);
}



/* FUN_1000c850 @ 1000c850 size 442 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __cdecl FUN_1000c850(int param_1,int *param_2)

{
  float *pfVar1;
  int *piVar2;
  float *pfVar3;
  int iVar4;
  float *pfVar5;
  float afStack_5c [6];
  float afStack_44 [3];
  float afStack_38 [4];
  int iStack_28;
  int iStack_24;
  
  piVar2 = FUN_1001b350();
  piVar2[0x46] = *param_2;
  piVar2[0xb3] = (int)param_2;
  piVar2[0x47] = 0x10000;
  piVar2[0x10] = param_2[7];
  piVar2[0x2f] = -0x3e900000;
  piVar2[0x30] = -0x3e900000;
  piVar2[0x31] = -0x3e900000;
  piVar2[0x11] = 0x200;
  piVar2[0x32] = 0x41700000;
  piVar2[0x33] = 0x41700000;
  piVar2[0x34] = 0x41700000;
  (*DAT_1006c1ec)(piVar2,param_2[6]);
  piVar2[0x3e] = 1;
  piVar2[0x41] = 7;
  piVar2[0x7f] = (int)&LAB_1000ca10;
  piVar2[0x40] = param_1;
  if (*(int *)(param_1 + 0x54) == 0) {
    FUN_10038700((float *)(param_1 + 0x10),afStack_5c + 3,afStack_44,(float *)0x0);
    piVar2[1] = *(int *)(param_1 + 4);
    piVar2[2] = *(int *)(param_1 + 8);
    piVar2[3] = *(int *)(param_1 + 0xc);
  }
  else {
    FUN_10038700((float *)(*(int *)(param_1 + 0x54) + 0xe64),afStack_5c + 3,afStack_44,(float *)0x0)
    ;
    pfVar1 = (float *)(piVar2 + 1);
    afStack_5c[0] = 24.0;
    afStack_5c[1] = 0.0;
    afStack_5c[2] = -16.0;
    FUN_1001aba0((float *)(param_1 + 4),afStack_5c,afStack_5c + 3,afStack_44,pfVar1);
    pfVar3 = (float *)(*DAT_1006c1f0)(afStack_38,(float *)(param_1 + 4),piVar2 + 0x2f,piVar2 + 0x32,
                                      pfVar1,param_1,1);
    pfVar5 = afStack_38;
    for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pfVar5 = *pfVar3;
      pfVar3 = pfVar3 + 1;
      pfVar5 = pfVar5 + 1;
    }
    *pfVar1 = afStack_38[3];
    piVar2[2] = iStack_28;
    piVar2[3] = iStack_24;
  }
  FUN_10038a20(afStack_5c + 3,100.0,(float *)(piVar2 + 0x5e));
  piVar2[0x60] = 0x43960000;
  piVar2[0x7d] = (int)&LAB_1000ca40;
  piVar2[0x7b] = (int)(DAT_1006c2e4 + _DAT_10044104);
  (*DAT_1006c208)(piVar2);
  return piVar2;
}



/* FUN_100350a0 @ 100350a0 size 442 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100350a0(int param_1,float *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  if (param_3 == 1) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x54) + 0xec4);
    if (iVar2 != 0) {
      *(int *)(*(int *)(param_1 + 0x54) + 0xec4) = iVar2 + -1;
      return;
    }
  }
  if ((*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) &&
     ((*(byte *)(param_1 + 0x108) & 0x20) == 0)) {
    if (*(int *)(param_1 + 0x278) == 0) {
      piVar1 = FUN_1001b350();
      piVar1[0x46] = (int)s_player_noise_10046038;
      piVar1[0x2f] = -0x3f000000;
      piVar1[0x30] = -0x3f000000;
      piVar1[0x31] = -0x3f000000;
      piVar1[0x32] = 0x41000000;
      piVar1[0x33] = 0x41000000;
      piVar1[0x34] = 0x41000000;
      piVar1[0x40] = param_1;
      piVar1[0x2e] = 1;
      *(int **)(param_1 + 0x278) = piVar1;
      piVar1 = FUN_1001b350();
      piVar1[0x32] = 0x41000000;
      piVar1[0x33] = 0x41000000;
      piVar1[0x34] = 0x41000000;
      piVar1[0x46] = (int)s_player_noise_10046038;
      piVar1[0x2f] = -0x3f000000;
      piVar1[0x30] = -0x3f000000;
      piVar1[0x31] = -0x3f000000;
      piVar1[0x40] = param_1;
      piVar1[0x2e] = 1;
      *(int **)(param_1 + 0x27c) = piVar1;
    }
    if ((param_3 == 0) || (param_3 == 1)) {
      iVar2 = *(int *)(param_1 + 0x278);
      DAT_1006c3dc = DAT_1006c2e0;
      DAT_1006c3d8 = iVar2;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x27c);
      DAT_1006c3e4 = DAT_1006c2e0;
      DAT_1006c3e0 = iVar2;
    }
    *(float *)(iVar2 + 4) = *param_2;
    *(float *)(iVar2 + 8) = param_2[1];
    *(float *)(iVar2 + 0xc) = param_2[2];
    *(float *)(iVar2 + 0xd4) = *param_2 - *(float *)(iVar2 + 200);
    *(float *)(iVar2 + 0xd8) = param_2[1] - *(float *)(iVar2 + 0xcc);
    *(float *)(iVar2 + 0xdc) = param_2[2] - *(float *)(iVar2 + 0xd0);
    *(float *)(iVar2 + 0xe0) = *(float *)(iVar2 + 200) + *param_2;
    *(float *)(iVar2 + 0xe4) = param_2[1] + *(float *)(iVar2 + 0xcc);
    *(float *)(iVar2 + 0xe8) = param_2[2] + *(float *)(iVar2 + 0xd0);
    *(undefined4 *)(iVar2 + 0x2a0) = DAT_1006c2e4;
    (*DAT_1006c208)(iVar2);
  }
  return;
}



/* FUN_1000a300 @ 1000a300 size 438 */

void __cdecl FUN_1000a300(int param_1)

{
  float fVar1;
  bool bVar2;
  byte *pbVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  float local_c;
  float local_8;
  float fStack_4;
  
  bVar2 = true;
  pbVar3 = *(byte **)(param_1 + 0x128);
  if (pbVar3 != (byte *)0x0) {
    while( true ) {
      uVar4 = FUN_1001ad80(pbVar3);
      if (uVar4 == 0) {
        (*DAT_1006c1c4)(s_train_next__bad_target__s_1004676c,*(undefined4 *)(param_1 + 0x128));
        return;
      }
      *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(uVar4 + 0x128);
      if ((*(byte *)(uVar4 + 0x11c) & 1) == 0) break;
      if (!bVar2) {
        iVar6 = uVar4 + 4;
        puVar5 = FUN_1001b070();
        (*DAT_1006c1c4)(s_connected_teleport_path_corners__1004673c,*(undefined4 *)(uVar4 + 0x118),
                        puVar5,iVar6);
        return;
      }
      bVar2 = false;
      *(float *)(param_1 + 4) = *(float *)(uVar4 + 4) - *(float *)(param_1 + 0xbc);
      *(float *)(param_1 + 8) = *(float *)(uVar4 + 8) - *(float *)(param_1 + 0xc0);
      fVar1 = *(float *)(uVar4 + 0xc);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 4);
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 8);
      *(float *)(param_1 + 0xc) = fVar1 - *(float *)(param_1 + 0xc4);
      *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0xc);
      (*DAT_1006c208)(param_1);
      pbVar3 = *(byte **)(param_1 + 0x128);
      if (pbVar3 == (byte *)0x0) {
        return;
      }
    }
    *(undefined4 *)(param_1 + 0x32c) = *(undefined4 *)(uVar4 + 0x290);
    *(uint *)(param_1 + 0x144) = uVar4;
    if ((*(uint *)(param_1 + 0x108) & 0x400) == 0) {
      if (*(int *)(param_1 + 0x310) != 0) {
        (*DAT_1006c1d0)(param_1,10,*(int *)(param_1 + 0x310),0x3f800000,0x40400000,0);
      }
      *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x314);
    }
    local_c = *(float *)(uVar4 + 4) - *(float *)(param_1 + 0xbc);
    local_8 = *(float *)(uVar4 + 8) - *(float *)(param_1 + 0xc0);
    fStack_4 = *(float *)(uVar4 + 0xc) - *(float *)(param_1 + 0xc4);
    *(undefined4 *)(param_1 + 0x2e8) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x2e0) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(param_1 + 0x2e4) = *(undefined4 *)(param_1 + 8);
    *(float *)(param_1 + 0x2f8) = local_c;
    *(undefined4 *)(param_1 + 0x330) = 0;
    *(float *)(param_1 + 0x2fc) = local_8;
    *(float *)(param_1 + 0x300) = fStack_4;
    FUN_10006b20(param_1,&local_c,&LAB_1000a1f0);
    *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) | 1;
  }
  return;
}



/* FUN_10037de0 @ 10037de0 size 437 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10037de0(int param_1,float *param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  float local_30;
  float local_2c;
  float local_28;
  float local_24 [3];
  float local_18 [3];
  float local_c [3];
  
  if (DAT_100613c0 != 0) {
    param_3 = param_3 * 4;
  }
  FUN_10038700((float *)(*(int *)(param_1 + 0x54) + 0xe64),local_24,local_c,(float *)0x0);
  local_30 = *param_2 + _DAT_10044480;
  local_2c = param_2[1] + _DAT_10044164;
  local_28 = (float)(*(int *)(param_1 + 0x23c) + -8) + param_2[2];
  FUN_10035db0(*(int *)(param_1 + 0x54),(float *)(param_1 + 4),&local_30,local_24,local_c,local_18);
  FUN_10038a20(local_24,-2.0,(float *)(*(int *)(param_1 + 0x54) + 0xe30));
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe24) = 0xbf800000;
  FUN_1001e640(param_1,local_18,local_24,param_3,2000,param_4);
  if (param_4 == 0) {
    puVar1 = FUN_1000b150((byte *)s_PistolPlasma_10048ca0);
    piVar2 = (int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar1 + -0x4011a4a) / 0x48) * 4);
    iVar3 = *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar1 + -0x4011a4a) / 0x48) * 4) +
            -1;
  }
  else {
    puVar1 = FUN_1000b150((byte *)s_Rifle_Plasma_100461a4);
    piVar2 = (int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar1 + -0x4011a4a) / 0x48) * 4);
    iVar3 = *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar1 + -0x4011a4a) / 0x48) * 4) +
            -5;
  }
  *piVar2 = iVar3;
  (*DAT_1006c224)(1);
  (*DAT_1006c228)((param_1 - DAT_1006c2c4) / 0x3d0);
  (*DAT_1006c224)(DAT_100613c4 & 0xff | 0x22);
  (*DAT_1006c218)((float *)(param_1 + 4),2);
  FUN_100350a0(param_1,local_18,1);
  return;
}



/* FUN_1003f4ad @ 1003f4ad size 436 */

void __cdecl FUN_1003f4ad(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  *param_5 = 0;
  *param_4 = 1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_3;
    param_2 = param_2 + 1;
  }
  if (*param_1 == 0x22) {
    while( true ) {
      bVar1 = param_1[1];
      pbVar4 = param_1 + 1;
      if ((bVar1 == 0x22) || (bVar1 == 0)) break;
      if (((*(byte *)((int)&DAT_1006cba0 + bVar1 + 1) & 4) != 0) &&
         (*param_5 = *param_5 + 1, param_3 != (byte *)0x0)) {
        *param_3 = *pbVar4;
        param_3 = param_3 + 1;
        pbVar4 = param_1 + 2;
      }
      *param_5 = *param_5 + 1;
      param_1 = pbVar4;
      if (param_3 != (byte *)0x0) {
        *param_3 = *pbVar4;
        param_3 = param_3 + 1;
      }
    }
    *param_5 = *param_5 + 1;
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    if (*pbVar4 == 0x22) {
      pbVar4 = param_1 + 2;
    }
  }
  else {
    do {
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *param_1;
        param_3 = param_3 + 1;
      }
      bVar1 = *param_1;
      pbVar4 = param_1 + 1;
      if ((*(byte *)((int)&DAT_1006cba0 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar4;
          param_3 = param_3 + 1;
        }
        pbVar4 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_1003f558;
      param_1 = pbVar4;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_1003f558:
      pbVar4 = pbVar4 + -1;
    }
    else if (param_3 != (byte *)0x0) {
      param_3[-1] = 0;
    }
  }
  bVar2 = false;
  puVar7 = param_2;
  while (*pbVar4 != 0) {
    for (; (*pbVar4 == 0x20 || (*pbVar4 == 9)); pbVar4 = pbVar4 + 1) {
    }
    if (*pbVar4 == 0) break;
    if (puVar7 != (undefined4 *)0x0) {
      *puVar7 = param_3;
      puVar7 = puVar7 + 1;
      param_2 = puVar7;
    }
    *param_4 = *param_4 + 1;
    while( true ) {
      bVar3 = true;
      uVar6 = 0;
      for (; *pbVar4 == 0x5c; pbVar4 = pbVar4 + 1) {
        uVar6 = uVar6 + 1;
      }
      if (*pbVar4 == 0x22) {
        pbVar5 = pbVar4;
        if ((uVar6 & 1) == 0) {
          if ((!bVar2) || (pbVar5 = pbVar4 + 1, pbVar4[1] != 0x22)) {
            bVar3 = false;
            pbVar5 = pbVar4;
          }
          bVar2 = !bVar2;
          puVar7 = param_2;
        }
        uVar6 = uVar6 >> 1;
        pbVar4 = pbVar5;
      }
      for (; uVar6 != 0; uVar6 = uVar6 - 1) {
        if (param_3 != (byte *)0x0) {
          *param_3 = 0x5c;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      bVar1 = *pbVar4;
      if ((bVar1 == 0) || ((!bVar2 && ((bVar1 == 0x20 || (bVar1 == 9)))))) break;
      if (bVar3) {
        if (param_3 == (byte *)0x0) {
          if ((*(byte *)((int)&DAT_1006cba0 + bVar1 + 1) & 4) != 0) {
            pbVar4 = pbVar4 + 1;
            *param_5 = *param_5 + 1;
          }
        }
        else {
          if ((*(byte *)((int)&DAT_1006cba0 + bVar1 + 1) & 4) != 0) {
            *param_3 = bVar1;
            param_3 = param_3 + 1;
            pbVar4 = pbVar4 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_3 = *pbVar4;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      pbVar4 = pbVar4 + 1;
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *param_5 = *param_5 + 1;
  }
  if (puVar7 != (undefined4 *)0x0) {
    *puVar7 = 0;
  }
  *param_4 = *param_4 + 1;
  return;
}



/* FUN_10003930 @ 10003930 size 434 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10003930(int param_1)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (*(float *)(param_1 + 0x1ec) == _DAT_1004410c) {
    if ((*(int *)(param_1 + 0x114) != 0) && ((*(byte *)(*(int *)(param_1 + 0x264) + 0xb8) & 4) == 0)
       ) {
      (*DAT_1006c1cc)(*(int *)(param_1 + 0x264),&DAT_10046140,*(int *)(param_1 + 0x114));
      iVar3 = *(int *)(param_1 + 0x280);
      if (iVar3 == 0) {
        iVar3 = (*DAT_1006c1e4)(s_misc_talk1_wav_10046130,0x3f800000,0x3f800000,0);
        uVar4 = *(undefined4 *)(param_1 + 0x264);
      }
      else {
        uVar4 = *(undefined4 *)(param_1 + 0x264);
      }
      (*DAT_1006c1d0)(uVar4,0,iVar3);
    }
    if (*(byte **)(param_1 + 0x128) != (byte *)0x0) {
      for (uVar2 = FUN_1001ac00(0,300,*(byte **)(param_1 + 0x128)); uVar2 != 0;
          uVar2 = FUN_1001ac00(uVar2,300,*(byte **)(param_1 + 0x128))) {
        iVar3 = FUN_10038b20(*(void **)(uVar2 + 0x118),(byte *)s_misc_camera_10046124);
        if (iVar3 == 0) {
          if (*(float *)(param_1 + 0x290) != _DAT_1004410c) {
            *(undefined4 *)(uVar2 + 0x290) = *(undefined4 *)(param_1 + 0x290);
          }
          if (*(int *)(param_1 + 0x138) == 0) {
            *(undefined4 *)(uVar2 + 0x25c) = *(undefined4 *)(param_1 + 0x264);
          }
          else {
            *(int *)(uVar2 + 0x128) = *(int *)(param_1 + 0x138);
          }
          if (*(int *)(uVar2 + 0x254) == 0) {
            FUN_100035d0(uVar2);
          }
          else {
            *(float *)(uVar2 + 0x120) = DAT_1006c2e4;
          }
          break;
        }
        (*DAT_1006c1c0)(2,s_Illegal_target_for_trigger_misc__100460fc);
      }
    }
    if (_DAT_1004410c < *(float *)(param_1 + 0x294)) {
      *(undefined1 **)(param_1 + 500) = &LAB_10018fa0;
      *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + *(float *)(param_1 + 0x294);
      return;
    }
    *(undefined4 *)(param_1 + 0x1fc) = 0;
    fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
    *(code **)(param_1 + 500) = FUN_1001b400;
    *(float *)(param_1 + 0x1ec) = fVar1;
  }
  return;
}



/* FUN_10041c6e @ 10041c6e size 429 */

undefined4 __cdecl FUN_10041c6e(int param_1)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  UINT CodePage;
  UINT *pUVar5;
  BOOL BVar6;
  uint uVar7;
  uint uVar8;
  BYTE *pBVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  byte *pbVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  _cpinfo local_1c;
  uint local_8;
  
  FUN_1003c8a1(0x19);
  CodePage = FUN_10041e1b(param_1);
  if (CodePage != DAT_1006ca74) {
    if (CodePage != 0) {
      iVar12 = 0;
      pUVar5 = &DAT_100607a8;
LAB_10041cab:
      if (*pUVar5 != CodePage) goto code_r0x10041caf;
      local_8 = 0;
      puVar15 = &DAT_1006cba0;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      iVar12 = iVar12 * 0x30;
      *(undefined1 *)puVar15 = 0;
      pbVar13 = (byte *)(iVar12 + 0x100607b8);
      do {
        bVar3 = *pbVar13;
        pbVar11 = pbVar13;
        while ((bVar3 != 0 && (bVar3 = pbVar11[1], bVar3 != 0))) {
          uVar8 = (uint)*pbVar11;
          if (uVar8 <= bVar3) {
            bVar4 = (&DAT_100607a0)[local_8];
            do {
              pbVar2 = (byte *)((int)&DAT_1006cba0 + uVar8 + 1);
              *pbVar2 = *pbVar2 | bVar4;
              uVar8 = uVar8 + 1;
            } while (uVar8 <= bVar3);
          }
          pbVar11 = pbVar11 + 2;
          bVar3 = *pbVar11;
        }
        local_8 = local_8 + 1;
        pbVar13 = pbVar13 + 8;
      } while (local_8 < 4);
      DAT_1006ca8c = 1;
      DAT_1006ca74 = CodePage;
      DAT_1006cca4 = FUN_10041e65(CodePage);
      DAT_1006ca80 = *(undefined4 *)(iVar12 + 0x100607ac);
      DAT_1006ca84 = *(undefined4 *)(iVar12 + 0x100607b0);
      DAT_1006ca88 = *(undefined4 *)(iVar12 + 0x100607b4);
      goto LAB_10041dff;
    }
    goto LAB_10041dfa;
  }
  goto LAB_10041c95;
code_r0x10041caf:
  pUVar5 = pUVar5 + 0xc;
  iVar12 = iVar12 + 1;
  if (0x10060897 < (int)pUVar5) goto code_r0x10041cba;
  goto LAB_10041cab;
code_r0x10041cba:
  BVar6 = GetCPInfo(CodePage,&local_1c);
  uVar8 = 1;
  if (BVar6 == 1) {
    DAT_1006cca4 = 0;
    puVar15 = &DAT_1006cba0;
    for (iVar12 = 0x40; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    }
    *(undefined1 *)puVar15 = 0;
    if (local_1c.MaxCharSize < 2) {
      DAT_1006ca8c = 0;
      DAT_1006ca74 = CodePage;
    }
    else {
      DAT_1006ca74 = CodePage;
      if (local_1c.LeadByte[0] != '\0') {
        pBVar9 = local_1c.LeadByte + 1;
        do {
          bVar3 = *pBVar9;
          if (bVar3 == 0) break;
          for (uVar7 = (uint)pBVar9[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
            pbVar13 = (byte *)((int)&DAT_1006cba0 + uVar7 + 1);
            *pbVar13 = *pbVar13 | 4;
          }
          pBVar1 = pBVar9 + 1;
          pBVar9 = pBVar9 + 2;
        } while (*pBVar1 != 0);
      }
      do {
        pbVar13 = (byte *)((int)&DAT_1006cba0 + uVar8 + 1);
        *pbVar13 = *pbVar13 | 8;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 0xff);
      DAT_1006cca4 = FUN_10041e65(CodePage);
      DAT_1006ca8c = 1;
    }
    DAT_1006ca80 = 0;
    DAT_1006ca84 = 0;
    DAT_1006ca88 = 0;
  }
  else {
    if (DAT_10061f9c == 0) {
      uVar14 = 0xffffffff;
      goto LAB_10041e0c;
    }
LAB_10041dfa:
    FUN_10041e98();
  }
LAB_10041dff:
  FUN_10041ec1();
LAB_10041c95:
  uVar14 = 0;
LAB_10041e0c:
  FUN_1003c902(0x19);
  return uVar14;
}



/* FUN_1003d72c @ 1003d72c size 428 */

bool __cdecl FUN_1003d72c(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (DAT_1005ffcc != 0) {
    uVar5 = param_1[5];
    if ((uVar5 != DAT_10060060) || (uVar5 != DAT_10060070)) {
      if (DAT_10061cc0 == 0) {
        FUN_1003d8d8(1,1,uVar5,4,1,0,0,2,0,0,0);
        FUN_1003d8d8(0,1,param_1[5],10,5,0,0,2,0,0,0);
      }
      else {
        if (DAT_10061d60 != 0) {
          uVar6 = (uint)DAT_10061d66;
          uVar3 = 0;
          uVar4 = 0;
        }
        else {
          uVar3 = (uint)DAT_10061d64;
          uVar6 = 0;
          uVar4 = (uint)DAT_10061d66;
        }
        FUN_1003d8d8(1,(uint)(DAT_10061d60 == 0),uVar5,(uint)DAT_10061d62,uVar4,uVar3,uVar6,
                     (uint)DAT_10061d68,(uint)DAT_10061d6a,(uint)DAT_10061d6c,(uint)DAT_10061d6e);
        if (DAT_10061d0c != 0) {
          uVar6 = (uint)DAT_10061d12;
          uVar3 = 0;
          uVar4 = 0;
          uVar5 = param_1[5];
        }
        else {
          uVar3 = (uint)DAT_10061d10;
          uVar6 = 0;
          uVar4 = (uint)DAT_10061d12;
          uVar5 = param_1[5];
        }
        FUN_1003d8d8(0,(uint)(DAT_10061d0c == 0),uVar5,(uint)DAT_10061d0e,uVar4,uVar3,uVar6,
                     (uint)DAT_10061d14,(uint)DAT_10061d16,(uint)DAT_10061d18,(uint)DAT_10061d1a);
      }
    }
    iVar1 = param_1[7];
    if (DAT_10060064 < DAT_10060074) {
      if ((DAT_10060064 <= iVar1) && (iVar1 <= DAT_10060074)) {
        if ((DAT_10060064 < iVar1) && (iVar1 < DAT_10060074)) {
          return true;
        }
LAB_1003d8a4:
        iVar2 = ((param_1[2] * 0x3c + param_1[1]) * 0x3c + *param_1) * 1000;
        if (iVar1 == DAT_10060064) {
          return DAT_10060068 <= iVar2;
        }
        return iVar2 < DAT_10060078;
      }
    }
    else {
      if (iVar1 < DAT_10060074) {
        return true;
      }
      if (DAT_10060064 < iVar1) {
        return true;
      }
      if ((iVar1 <= DAT_10060074) || (DAT_10060064 <= iVar1)) goto LAB_1003d8a4;
    }
  }
  return false;
}



/* FUN_1001c2f0 @ 1001c2f0 size 425 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_1001c2f0(int param_1,int *param_2,float *param_3,int param_4,int param_5,float param_6,
            int param_7)

{
  float *pfVar1;
  float fVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  float local_30 [3];
  float local_24 [3];
  float local_18 [3];
  float local_c [3];
  
  FUN_1001b1e0(param_3,local_30);
  FUN_10038700(local_30,local_c,local_18,local_24);
  piVar3 = FUN_1001b350();
  pfVar1 = (float *)(piVar3 + 0x5e);
  piVar3[1] = *param_2;
  piVar3[2] = param_2[1];
  piVar3[3] = param_2[2];
  FUN_10038a20(param_3,(float)param_5,pfVar1);
  pfVar6 = local_24;
  pfVar7 = pfVar1;
  uVar4 = _rand();
  fVar2 = (float)(uVar4 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  FUN_10038950(pfVar1,(fVar2 + fVar2) * (float)_DAT_10044170 + (float)_DAT_100441d8,pfVar6,pfVar7);
  pfVar6 = local_18;
  pfVar7 = pfVar1;
  uVar4 = _rand();
  fVar2 = (float)(uVar4 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  FUN_10038950(pfVar1,(fVar2 + fVar2) * (float)_DAT_10044170,pfVar6,pfVar7);
  piVar3[0x61] = 0x43960000;
  piVar3[0x62] = 0x43960000;
  piVar3[99] = 0x43960000;
  piVar3[0x41] = 9;
  piVar3[0x3f] = 0x6000003;
  piVar3[0x3e] = 2;
  piVar3[0x10] = piVar3[0x10] | 0x20;
  piVar3[0x31] = 0;
  piVar3[0x30] = 0;
  piVar3[0x2f] = 0;
  piVar3[0x34] = 0;
  piVar3[0x33] = 0;
  piVar3[0x32] = 0;
  iVar5 = (*DAT_1006c1e0)(s_models_objects_grenade_tris_md2_1004beac);
  piVar3[10] = iVar5;
  piVar3[0x40] = param_1;
  piVar3[0x7f] = (int)&LAB_1001c680;
  fVar2 = DAT_1006c2e4 + param_6;
  piVar3[0x7d] = (int)FUN_1001c4a0;
  piVar3[0x91] = param_4;
  piVar3[0x93] = param_7;
  piVar3[0x46] = (int)s_grenade_1004bbc8;
  piVar3[0x7b] = (int)fVar2;
  (*DAT_1006c208)(piVar3);
  return;
}



/* FUN_10001910 @ 10001910 size 418 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10001910(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  float10 fVar5;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  uVar3 = 0;
  local_10 = 999999.0;
  if ((((*(uint *)(param_1 + 0x35c) & 0x8000000) != 0) &&
      (iVar1 = FUN_10001880(*(int *)(param_1 + 0x1dc)), iVar1 != 0)) &&
     (uVar3 = *(uint *)(param_1 + 0x1dc), uVar3 != 0)) {
LAB_10001a12:
    local_c = *(float *)(uVar3 + 4) - *(float *)(param_1 + 4);
    local_8 = *(float *)(uVar3 + 8) - *(float *)(param_1 + 8);
    local_4 = *(float *)(uVar3 + 0xc) - *(float *)(param_1 + 0xc);
    fVar5 = FUN_1001b160(&local_c);
    *(float *)(param_1 + 0x1e8) = (float)fVar5;
    FUN_1002a850(param_1);
    *(uint *)(param_1 + 0x1e0) = uVar3;
    *(uint *)(param_1 + 0x1dc) = uVar3;
    *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) | 0x8000000;
    fVar5 = FUN_100389f0(&local_c);
    if (fVar5 <= (float10)_DAT_10044130) {
      (**(code **)(param_1 + 0x368))(param_1);
      return 1;
    }
    (**(code **)(param_1 + 0x374))();
    return 1;
  }
  iVar1 = DAT_1006c168;
  uVar4 = DAT_1006c2c4;
  if (DAT_1006c2c4 < DAT_1006c168 * 0x3d0 + DAT_1006c2c4) {
    do {
      if (((*(int *)(uVar4 + 0x54) != 0) || ((*(uint *)(uVar4 + 0x35c) & 0x100) != 0)) &&
         (iVar2 = FUN_10001560(param_1,uVar4), iVar1 = DAT_1006c168, iVar2 != 0)) {
        local_c = *(float *)(uVar4 + 4) - *(float *)(param_1 + 4);
        local_8 = *(float *)(uVar4 + 8) - *(float *)(param_1 + 8);
        local_4 = *(float *)(uVar4 + 0xc) - *(float *)(param_1 + 0xc);
        fVar5 = FUN_100389f0(&local_c);
        iVar1 = DAT_1006c168;
        if ((fVar5 < (float10)local_10) &&
           (iVar2 = FUN_10001880(uVar4), iVar1 = DAT_1006c168, iVar2 != 0)) {
          uVar3 = uVar4;
          local_10 = (float)fVar5;
        }
      }
      uVar4 = uVar4 + 0x3d0;
    } while (uVar4 < iVar1 * 0x3d0 + DAT_1006c2c4);
    if (uVar3 != 0) goto LAB_10001a12;
  }
  return 0;
}



/* FUN_10003280 @ 10003280 size 414 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10003280(int param_1)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (*(byte **)(param_1 + 0x128) != (byte *)0x0) {
    uVar1 = FUN_1001ad80(*(byte **)(param_1 + 0x128));
    *(uint *)(param_1 + 0x25c) = uVar1;
    if (uVar1 == 0) {
      uVar5 = *(undefined4 *)(param_1 + 0x128);
      puVar2 = FUN_1001b070();
      (*DAT_1006c1c0)(2,s__s__s_at__s__invalid_target__s_1004608c,*(undefined4 *)(param_1 + 0x118),
                      *(undefined4 *)(param_1 + 300),puVar2,uVar5);
    }
  }
  if ((*(int *)(param_1 + 0x1e0) == 0) && (*(byte **)(param_1 + 0x138) != (byte *)0x0)) {
    uVar1 = FUN_1001ac00(0,300,*(byte **)(param_1 + 0x138));
    *(uint *)(param_1 + 0x1e0) = uVar1;
    if (uVar1 == 0) {
      uVar5 = *(undefined4 *)(param_1 + 0x138);
      puVar2 = FUN_1001b070();
      (*DAT_1006c1c0)(2,s__s_at__s__invalid_pathtarget__s_10046068,*(undefined4 *)(param_1 + 0x118),
                      puVar2,uVar5);
    }
    else {
      *(float *)(param_1 + 800) = *(float *)(param_1 + 0x148);
      if (*(float *)(param_1 + 0x148) == _DAT_1004410c) {
        *(undefined4 *)(param_1 + 800) = 0x42c80000;
      }
      *(undefined4 *)(param_1 + 0x330) = 0;
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(uVar1 + 4);
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(uVar1 + 8);
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(uVar1 + 0xc);
      *(float *)(param_1 + 0x32c) = DAT_1006c2e4;
    }
  }
  PTR_LAB_10046048 = &LAB_100031a0;
  iVar3 = DAT_1006c168;
  uVar1 = DAT_1006c2c4;
  uVar4 = DAT_1006c2c4;
  if (DAT_1006c2c4 < DAT_1006c168 * 0x3d0 + DAT_1006c2c4) {
    do {
      if ((*(int *)(uVar4 + 0x58) != 0) && (*(int *)(uVar4 + 0x54) != 0)) {
        FUN_10002eb0(uVar4,param_1);
        iVar3 = DAT_1006c168;
        uVar1 = DAT_1006c2c4;
      }
      uVar4 = uVar4 + 0x3d0;
    } while (uVar4 < iVar3 * 0x3d0 + uVar1);
  }
  PTR_LAB_10046048 = (undefined *)0x0;
  *(undefined4 *)(param_1 + 0x254) = 1;
  *(float *)(param_1 + 0x120) = DAT_1006c2e4;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  return;
}



/* FUN_10005450 @ 10005450 size 413 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10005450(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char local_5c8 [79];
  char acStack_579 [1401];
  
  acStack_579[1] = 0;
  iVar6 = 0;
  if (_DAT_1004410c < *(float *)(DAT_1006ca60 + 0x14)) {
    iVar5 = DAT_1006c2c4 + 0x424;
    do {
      if (*(int *)(iVar5 + 4) != 0) {
        FUN_10038b40();
        uVar2 = 0xffffffff;
        pcVar7 = local_5c8;
        do {
          if (uVar2 == 0) break;
          uVar2 = uVar2 - 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        pcVar7 = acStack_579;
        uVar3 = 0xffffffff;
        do {
          pcVar7 = pcVar7 + 1;
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
        } while (*pcVar7 != '\0');
        if (0x546 < ~uVar2 + (~uVar3 - 2)) {
          pcVar7 = acStack_579;
          uVar2 = 0xffffffff;
          goto code_r0x100055b6;
        }
        uVar2 = 0xffffffff;
        pcVar7 = local_5c8;
        do {
          pcVar9 = pcVar7;
          if (uVar2 == 0) break;
          uVar2 = uVar2 - 1;
          pcVar9 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar9;
        } while (cVar1 != '\0');
        uVar2 = ~uVar2;
        iVar4 = -1;
        pcVar7 = acStack_579 + 1;
        do {
          pcVar8 = pcVar7;
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          pcVar8 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar8;
        } while (cVar1 != '\0');
        pcVar7 = pcVar9 + -uVar2;
        pcVar9 = pcVar8 + -1;
        for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar9 = pcVar9 + 4;
        }
        for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *pcVar9 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          pcVar9 = pcVar9 + 1;
        }
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 0x3d0;
    } while ((float)iVar6 < *(float *)(DAT_1006ca60 + 0x14));
  }
  (*DAT_1006c1c8)(param_1,2,&DAT_10046140,acStack_579 + 1);
  return;
  while( true ) {
    uVar2 = uVar2 - 1;
    if (*pcVar7 == '\0') break;
code_r0x100055b6:
    pcVar7 = pcVar7 + 1;
    if (uVar2 == 0) break;
  }
  FUN_10039541(acStack_579 + ~uVar2,(byte *)s_And_more____1004648c);
  (*DAT_1006c1c8)(param_1,2,&DAT_10046140,acStack_579 + 1);
  return;
}



/* FUN_1000a680 @ 1000a680 size 403 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000a680(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  
  *(undefined4 *)(param_1 + 0x104) = 2;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(code **)(param_1 + 0x1f8) = FUN_10015090;
  if ((*(byte *)(param_1 + 0x11c) & 4) == 0) {
    if (*(int *)(param_1 + 0x244) == 0) {
      *(undefined4 *)(param_1 + 0x244) = 0x14;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x244) = 0;
  }
  *(undefined4 *)(param_1 + 0xf8) = 3;
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  if (DAT_1006c2a4 != 0) {
    uVar2 = (*DAT_1006c1e4)(DAT_1006c2a4);
    *(undefined4 *)(param_1 + 0x314) = uVar2;
  }
  if (*(float *)(param_1 + 0x148) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x148) = 0x42c80000;
  }
  if ((*(byte *)(param_1 + 0x11c) & 8) != 0) {
    if (*(int *)(param_1 + 0x220) == 0) {
      *(undefined4 *)(param_1 + 0x220) = 100;
    }
    if (*(int *)(param_1 + 0x254) == 0) {
      *(undefined4 *)(param_1 + 0x254) = 10;
    }
    if (*(float *)(param_1 + 0x290) == _DAT_1004410c) {
      *(float *)(param_1 + 0x290) =
           (float)(*(int *)(param_1 + 0x244) * *(int *)(param_1 + 0x254) + 0x28);
    }
    *(code **)(param_1 + 0x208) = FUN_1000ef10;
    *(undefined4 *)(param_1 + 0x240) = 1;
    if (*(int *)(param_1 + 400) == 0) {
      *(undefined4 *)(param_1 + 400) = 0x4b;
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0x148);
  *(code **)(param_1 + 0x200) = FUN_1000a620;
  *(undefined4 *)(param_1 + 800) = uVar2;
  *(undefined4 *)(param_1 + 0x324) = uVar2;
  *(undefined4 *)(param_1 + 0x31c) = uVar2;
  (*DAT_1006c208)(param_1);
  if (*(int *)(param_1 + 0x128) != 0) {
    fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
    *(code **)(param_1 + 500) = FUN_1000a560;
    *(float *)(param_1 + 0x1ec) = fVar1;
    return;
  }
  iVar4 = param_1 + 0xd4;
  puVar3 = FUN_1001b070();
  (*DAT_1006c1c4)(s_func_train_without_a_target_at___100467c4,puVar3,iVar4);
  return;
}



/* FUN_10030b40 @ 10030b40 size 400 */

void __cdecl FUN_10030b40(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  longlong lVar5;
  
  lVar5 = __ftol();
  piVar2 = (int *)(((int)lVar5 + 1 + DAT_1006c408) * 0x3d0 + DAT_1006c2c4);
  DAT_1006c408 = DAT_1006c408 + 1 & 0x80000007;
  if ((int)DAT_1006c408 < 0) {
    DAT_1006c408 = (DAT_1006c408 - 1 | 0xfffffff8) + 1;
  }
  (*DAT_1006c20c)(param_1);
  (*DAT_1006c20c)(piVar2);
  piVar3 = param_1;
  piVar4 = piVar2;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar4 = *piVar3;
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
  }
  *piVar2 = ((int)piVar2 - DAT_1006c2c4) / 0x3d0;
  piVar2[0x2e] = param_1[0x2e];
  piVar2[0x2f] = param_1[0x2f];
  piVar2[0x30] = param_1[0x30];
  piVar2[0x31] = param_1[0x31];
  piVar2[0x32] = param_1[0x32];
  piVar2[0x33] = param_1[0x33];
  piVar2[0x34] = param_1[0x34];
  piVar2[0x35] = param_1[0x35];
  piVar2[0x36] = param_1[0x36];
  piVar2[0x37] = param_1[0x37];
  piVar2[0x38] = param_1[0x38];
  piVar2[0x39] = param_1[0x39];
  piVar2[0x3a] = param_1[0x3a];
  piVar2[0x3b] = param_1[0x3b];
  piVar2[0x3c] = param_1[0x3c];
  piVar2[0x3d] = param_1[0x3d];
  piVar2[0x3e] = param_1[0x3e];
  piVar2[0x3f] = param_1[0x3f];
  piVar2[0x40] = param_1[0x40];
  piVar2[0x41] = param_1[0x41];
  piVar2[0x82] = (int)FUN_10030ac0;
  piVar2[0x90] = 1;
  (*DAT_1006c208)(piVar2);
  return;
}



/* FUN_1003dda9 @ 1003dda9 size 395 */

int __cdecl FUN_1003dda9(DWORD param_1,char *param_2,uint param_3)

{
  int *piVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  BOOL BVar6;
  DWORD *pDVar7;
  char local_418 [1028];
  int local_14;
  DWORD local_10;
  DWORD local_c;
  char *local_8;
  
  local_c = 0;
  local_14 = 0;
  if (param_3 == 0) {
LAB_1003ddc2:
    iVar4 = 0;
  }
  else {
    piVar1 = &DAT_1006ccc0 + ((int)param_1 >> 5);
    iVar4 = (param_1 & 0x1f) * 0x24;
    if ((*(byte *)(*piVar1 + 4 + iVar4) & 0x20) != 0) {
      FUN_10040751(param_1,0,2);
    }
    if ((*(byte *)((undefined4 *)(*piVar1 + iVar4) + 1) & 0x80) == 0) {
      BVar6 = WriteFile(*(HANDLE *)(*piVar1 + iVar4),param_2,param_3,&local_10,(LPOVERLAPPED)0x0);
      if (BVar6 == 0) {
        param_1 = GetLastError();
      }
      else {
        local_c = local_10;
        param_1 = 0;
      }
LAB_1003de91:
      if (local_c != 0) {
        return local_c - local_14;
      }
      if (param_1 == 0) goto LAB_1003df03;
      if (param_1 == 5) {
        pDVar7 = FUN_1004058e();
        *pDVar7 = 9;
        pDVar7 = FUN_10040597();
        *pDVar7 = 5;
      }
      else {
        FUN_1004051b(param_1);
      }
    }
    else {
      local_8 = param_2;
      param_1 = 0;
      if (param_3 != 0) {
        do {
          pcVar5 = local_418;
          do {
            if (param_3 <= (uint)((int)local_8 - (int)param_2)) break;
            pcVar2 = local_8 + 1;
            cVar3 = *local_8;
            local_8 = pcVar2;
            if (cVar3 == '\n') {
              local_14 = local_14 + 1;
              *pcVar5 = '\r';
              pcVar5 = pcVar5 + 1;
            }
            *pcVar5 = cVar3;
            pcVar5 = pcVar5 + 1;
          } while ((int)pcVar5 - (int)local_418 < 0x400);
          BVar6 = WriteFile(*(HANDLE *)(*piVar1 + iVar4),local_418,(int)pcVar5 - (int)local_418,
                            &local_10,(LPOVERLAPPED)0x0);
          if (BVar6 == 0) {
            param_1 = GetLastError();
            goto LAB_1003de91;
          }
          local_c = local_c + local_10;
          if (((int)local_10 < (int)pcVar5 - (int)local_418) ||
             (param_3 <= (uint)((int)local_8 - (int)param_2))) goto LAB_1003de91;
        } while( true );
      }
LAB_1003df03:
      if (((*(byte *)(*piVar1 + 4 + iVar4) & 0x40) != 0) && (*param_2 == '\x1a')) goto LAB_1003ddc2;
      pDVar7 = FUN_1004058e();
      *pDVar7 = 0x1c;
      pDVar7 = FUN_10040597();
      *pDVar7 = 0;
    }
    iVar4 = -1;
  }
  return iVar4;
}



/* FUN_10004e10 @ 10004e10 size 392 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10004e10(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  char *pcVar8;
  int *piVar9;
  char *pcVar10;
  char *pcVar11;
  undefined4 *local_944;
  char local_940 [64];
  char local_900 [1280];
  int local_400 [256];
  
  puVar7 = (undefined4 *)0x0;
  iVar2 = 0;
  local_944 = (undefined4 *)0x0;
  if (_DAT_1004410c < *(float *)(DAT_1006ca60 + 0x14)) {
    piVar6 = local_400;
    piVar9 = (int *)(DAT_1006c844 + 0x2d0);
    do {
      if (*piVar9 != 0) {
        *piVar6 = iVar2;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
        piVar6 = piVar6 + 1;
      }
      iVar2 = iVar2 + 1;
      piVar9 = piVar9 + 0x3cd;
      local_944 = puVar7;
    } while ((float)iVar2 < *(float *)(DAT_1006ca60 + 0x14));
  }
  FUN_10039373(local_400,local_944,4,&LAB_10004dc0);
  iVar2 = 0;
  local_900[0] = '\0';
  if (0 < (int)local_944) {
    do {
      FUN_10038b40();
      uVar3 = 0xffffffff;
      pcVar8 = local_940;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      uVar4 = 0xffffffff;
      pcVar8 = local_900;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      if (0x49c < ~uVar3 + (~uVar4 - 2)) {
        uVar3 = 0xffffffff;
        pcVar8 = &DAT_100463e4;
        goto code_r0x10004f4b;
      }
      uVar3 = 0xffffffff;
      pcVar8 = local_940;
      do {
        pcVar11 = pcVar8;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar11 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar11;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar5 = -1;
      pcVar8 = local_900;
      do {
        pcVar10 = pcVar8;
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar10 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar10;
      } while (cVar1 != '\0');
      pcVar8 = pcVar11 + -uVar3;
      pcVar11 = pcVar10 + -1;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar11 = pcVar11 + 4;
      }
      iVar2 = iVar2 + 1;
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar11 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar11 = pcVar11 + 1;
      }
    } while (iVar2 < (int)local_944);
  }
  goto LAB_10004f6f;
  while( true ) {
    uVar3 = uVar3 - 1;
    pcVar11 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar11;
    if (cVar1 == '\0') break;
code_r0x10004f4b:
    pcVar11 = pcVar8;
    if (uVar3 == 0) break;
  }
  uVar3 = ~uVar3;
  iVar2 = -1;
  pcVar8 = local_900;
  do {
    pcVar10 = pcVar8;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar10 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar10;
  } while (cVar1 != '\0');
  pcVar8 = pcVar11 + -uVar3;
  pcVar11 = pcVar10 + -1;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar11 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar11 = pcVar11 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar11 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar11 = pcVar11 + 1;
  }
LAB_10004f6f:
  (*DAT_1006c1c8)(param_1,2,s__s__i_players_100463d4,local_900,local_944);
  return;
}



/* FUN_10042f29 @ 10042f29 size 391 */

undefined4 __cdecl FUN_10042f29(uint *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  size_t sVar4;
  uint *lpName;
  byte *pbVar5;
  int *piVar6;
  bool bVar7;
  
  if (param_1 == (uint *)0x0) {
    return 0xffffffff;
  }
  puVar1 = (uint *)FUN_10043308((byte *)param_1,0x3d);
  if (puVar1 == (uint *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == puVar1) {
    return 0xffffffff;
  }
  bVar7 = *(byte *)((int)puVar1 + 1) == 0;
  if (DAT_10061dfc == DAT_10061e00) {
    DAT_10061dfc = FUN_10043108(DAT_10061dfc);
  }
  if (DAT_10061dfc == (int *)0x0) {
    if ((param_2 == 0) || (DAT_10061e04 == (undefined4 *)0x0)) {
      if (bVar7) {
        return 0;
      }
      DAT_10061dfc = _malloc(4);
      if (DAT_10061dfc == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_10061dfc = 0;
      if (DAT_10061e04 == (undefined4 *)0x0) {
        DAT_10061e04 = _malloc(4);
        if (DAT_10061e04 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_10061e04 = 0;
      }
    }
    else {
      iVar2 = FUN_1004274b();
      if (iVar2 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar3 = DAT_10061dfc;
  iVar2 = FUN_100430b0((uchar *)param_1,(int)puVar1 - (int)param_1);
  if ((iVar2 < 0) || (*piVar3 == 0)) {
    if (bVar7) {
      return 0;
    }
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    piVar3 = FUN_100431d0(piVar3,(uint *)(iVar2 * 4 + 8));
    if (piVar3 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar3[iVar2] = (int)param_1;
    piVar3[iVar2 + 1] = 0;
  }
  else {
    if (!bVar7) {
      piVar3[iVar2] = (int)param_1;
      goto LAB_1004305d;
    }
    piVar6 = piVar3 + iVar2;
    FUN_100396e7((LPVOID)piVar3[iVar2]);
    for (; *piVar6 != 0; piVar6 = piVar6 + 1) {
      iVar2 = iVar2 + 1;
      *piVar6 = piVar6[1];
    }
    piVar3 = FUN_100431d0(piVar3,(uint *)(iVar2 << 2));
    if (piVar3 == (int *)0x0) goto LAB_1004305d;
  }
  DAT_10061dfc = piVar3;
LAB_1004305d:
  if (param_2 != 0) {
    sVar4 = _strlen((char *)param_1);
    lpName = _malloc(sVar4 + 2);
    if (lpName != (uint *)0x0) {
      FUN_10040000(lpName,param_1);
      pbVar5 = (byte *)(((int)lpName - (int)param_1) + (int)puVar1);
      *pbVar5 = 0;
      SetEnvironmentVariableA((LPCSTR)lpName,(LPCSTR)(~-(uint)bVar7 & (uint)(pbVar5 + 1)));
      FUN_100396e7(lpName);
    }
  }
  return 0;
}



/* FUN_10034bf0 @ 10034bf0 size 390 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10034bf0(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (*(int *)(param_1 + 0x28) != 0xff) {
    return;
  }
  iVar2 = *(int *)(param_1 + 0x54);
  bVar1 = *(byte *)(iVar2 + 0x10);
  uVar5 = (uint)(_DAT_10062080 != _DAT_1004410c);
  if (((((bVar1 & 1) == *(uint *)(iVar2 + 0xea4)) || (4 < *(int *)(iVar2 + 0xea0))) &&
      ((uVar5 == *(uint *)(iVar2 + 0xea8) || (*(int *)(iVar2 + 0xea0) != 0)))) &&
     ((*(int *)(param_1 + 0x268) != 0 || (1 < *(int *)(iVar2 + 0xea0))))) {
    iVar3 = *(int *)(iVar2 + 0xea0);
    iVar4 = *(int *)(param_1 + 0x38);
    if (iVar3 == 6) {
      if (*(int *)(iVar2 + 0xe9c) < iVar4) {
        *(int *)(param_1 + 0x38) = iVar4 + -1;
        return;
      }
    }
    else if (iVar4 < *(int *)(iVar2 + 0xe9c)) {
      *(int *)(param_1 + 0x38) = iVar4 + 1;
      return;
    }
    if (iVar3 == 5) {
      return;
    }
    if (iVar3 == 2) {
      if (*(int *)(param_1 + 0x268) == 0) {
        return;
      }
      *(undefined4 *)(iVar2 + 0xea0) = 1;
      *(undefined4 *)(param_1 + 0x38) = 0x44;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe9c) = 0x47;
      return;
    }
  }
  *(uint *)(iVar2 + 0xea4) = bVar1 & 1;
  *(undefined4 *)(iVar2 + 0xea0) = 0;
  *(uint *)(iVar2 + 0xea8) = uVar5;
  if (*(int *)(param_1 + 0x268) == 0) {
    *(undefined4 *)(iVar2 + 0xea0) = 2;
    if (*(int *)(param_1 + 0x38) != 0x43) {
      *(undefined4 *)(param_1 + 0x38) = 0x42;
    }
    *(undefined4 *)(iVar2 + 0xe9c) = 0x43;
    return;
  }
  if (uVar5 == 0) {
    if ((bVar1 & 1) == 0) {
      *(undefined4 *)(param_1 + 0x38) = 0;
      *(undefined4 *)(iVar2 + 0xe9c) = 0x27;
      return;
    }
    *(undefined4 *)(param_1 + 0x38) = 0x87;
    *(undefined4 *)(iVar2 + 0xe9c) = 0x99;
    return;
  }
  if ((bVar1 & 1) == 0) {
    *(undefined4 *)(param_1 + 0x38) = 0x28;
    *(undefined4 *)(iVar2 + 0xe9c) = 0x2d;
    return;
  }
  *(undefined4 *)(param_1 + 0x38) = 0x9a;
  *(undefined4 *)(iVar2 + 0xe9c) = 0x9f;
  return;
}



/* FUN_10041ec1 @ 10041ec1 size 389 */

void FUN_10041ec1(void)

{
  byte *pbVar1;
  BOOL BVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  undefined1 uVar8;
  BYTE *pBVar9;
  CHAR *pCVar10;
  WORD local_518 [256];
  WCHAR local_318 [128];
  WCHAR local_218 [128];
  CHAR local_118 [256];
  _cpinfo local_18;
  
  BVar2 = GetCPInfo(DAT_1006ca74,&local_18);
  if (BVar2 == 1) {
    uVar3 = 0;
    do {
      local_118[uVar3] = (CHAR)uVar3;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
    local_118[0] = ' ';
    if (local_18.LeadByte[0] != 0) {
      pBVar9 = local_18.LeadByte + 1;
      do {
        uVar3 = (uint)local_18.LeadByte[0];
        if (uVar3 <= *pBVar9) {
          uVar5 = (*pBVar9 - uVar3) + 1;
          uVar6 = uVar5 >> 2;
          pCVar10 = local_118 + uVar3;
          while (uVar6 != 0) {
            uVar6 = uVar6 - 1;
            builtin_memcpy(pCVar10,"    ",4);
            pCVar10 = pCVar10 + 4;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *pCVar10 = ' ';
            pCVar10 = pCVar10 + 1;
          }
        }
        local_18.LeadByte[0] = pBVar9[1];
        pBVar9 = pBVar9 + 2;
      } while (local_18.LeadByte[0] != 0);
    }
    FUN_100405a3(1,local_118,0x100,local_518,DAT_1006ca74,DAT_1006cca4,0);
    FUN_10041a4a(DAT_1006cca4,0x100,local_118,0x100,local_218,0x100,DAT_1006ca74,0);
    FUN_10041a4a(DAT_1006cca4,0x200,local_118,0x100,local_318,0x100,DAT_1006ca74,0);
    uVar3 = 0;
    puVar7 = local_518;
    do {
      if ((*puVar7 & 1) == 0) {
        if ((*puVar7 & 2) != 0) {
          pbVar1 = (byte *)((int)&DAT_1006cba0 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          uVar8 = *(undefined1 *)((int)local_318 + uVar3);
          goto LAB_10041fcd;
        }
        (&DAT_1006caa0)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_1006cba0 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        uVar8 = *(undefined1 *)((int)local_218 + uVar3);
LAB_10041fcd:
        (&DAT_1006caa0)[uVar3] = uVar8;
      }
      uVar3 = uVar3 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar3 < 0x100);
  }
  else {
    uVar3 = 0;
    do {
      if ((uVar3 < 0x41) || (0x5a < uVar3)) {
        if ((0x60 < uVar3) && (uVar3 < 0x7b)) {
          pbVar1 = (byte *)((int)&DAT_1006cba0 + uVar3 + 1);
          *pbVar1 = *pbVar1 | 0x20;
          cVar4 = (char)uVar3 + -0x20;
          goto LAB_10042017;
        }
        (&DAT_1006caa0)[uVar3] = 0;
      }
      else {
        pbVar1 = (byte *)((int)&DAT_1006cba0 + uVar3 + 1);
        *pbVar1 = *pbVar1 | 0x10;
        cVar4 = (char)uVar3 + ' ';
LAB_10042017:
        (&DAT_1006caa0)[uVar3] = cVar4;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
  }
  return;
}



/* FUN_10018830 @ 10018830 size 382 */

void __cdecl FUN_10018830(uint param_1)

{
  uint uVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x11c);
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0xa0;
  *(undefined4 *)(param_1 + 0x28) = 1;
  if ((uVar1 & 0x40) == 0) {
    if ((uVar1 & 0x80) == 0) {
      *(undefined4 *)(param_1 + 0x38) = 4;
    }
    else {
      *(undefined4 *)(param_1 + 0x38) = 2;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x38) = 0x10;
  }
  if ((uVar1 & 2) == 0) {
    if ((uVar1 & 4) == 0) {
      if ((uVar1 & 8) == 0) {
        if ((uVar1 & 0x10) == 0) {
          if ((uVar1 & 0x20) != 0) {
            *(undefined4 *)(param_1 + 0x3c) = 0xe0e1e2e3;
          }
        }
        else {
          *(undefined4 *)(param_1 + 0x3c) = 0xdcdddedf;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x3c) = 0xf3f3f1f1;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x3c) = 0xd0d1d2d3;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x3c) = 0xf2f2f0f0;
  }
  if (*(int *)(param_1 + 0x25c) == 0) {
    if (*(byte **)(param_1 + 0x128) == (byte *)0x0) {
      FUN_1001b0c0((float *)(param_1 + 0x10),(float *)(param_1 + 0x154));
    }
    else {
      uVar1 = FUN_1001ac00(0,300,*(byte **)(param_1 + 0x128));
      if (uVar1 == 0) {
        uVar3 = *(undefined4 *)(param_1 + 0x128);
        puVar2 = FUN_1001b070();
        (*DAT_1006c1c4)(s__s_at__s___s_is_a_bad_target_1004ba1c,*(undefined4 *)(param_1 + 0x118),
                        puVar2,uVar3);
      }
      *(uint *)(param_1 + 0x25c) = uVar1;
    }
  }
  *(undefined1 **)(param_1 + 0x200) = &LAB_10018800;
  *(code **)(param_1 + 500) = FUN_10018540;
  if (*(int *)(param_1 + 0x244) == 0) {
    *(undefined4 *)(param_1 + 0x244) = 1;
  }
  *(undefined4 *)(param_1 + 0xbc) = 0xc1000000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc1000000;
  *(undefined4 *)(param_1 + 0xc4) = 0xc1000000;
  *(undefined4 *)(param_1 + 200) = 0x41000000;
  *(undefined4 *)(param_1 + 0xcc) = 0x41000000;
  *(undefined4 *)(param_1 + 0xd0) = 0x41000000;
  (*DAT_1006c208)(param_1);
  if ((*(byte *)(param_1 + 0x11c) & 1) != 0) {
    FUN_10018790(param_1);
    return;
  }
  FUN_100187d0(param_1);
  return;
}



/* FUN_10013970 @ 10013970 size 380 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10013970(int param_1)

{
  int iVar1;
  int iVar2;
  float local_18 [3];
  float local_c [3];
  
  if ((*(uint *)(param_1 + 0x108) & 0x400) == 0) {
    DAT_100640f0 = (undefined4 *)&DAT_10064100;
    iVar2 = param_1;
    if (param_1 != 0) {
      do {
        if ((((*(float *)(iVar2 + 0x178) != _DAT_1004410c) ||
             (*(float *)(iVar2 + 0x17c) != _DAT_1004410c)) ||
            (*(float *)(iVar2 + 0x180) != _DAT_1004410c)) ||
           (((*(float *)(iVar2 + 0x184) != _DAT_1004410c ||
             (*(float *)(iVar2 + 0x188) != _DAT_1004410c)) ||
            (*(float *)(iVar2 + 0x18c) != _DAT_1004410c)))) {
          FUN_10038a20((float *)(iVar2 + 0x178),0.1,local_c);
          FUN_10038a20((float *)(iVar2 + 0x184),0.1,local_18);
          iVar1 = FUN_10013460(iVar2,local_c,local_18);
          if (iVar1 == 0) break;
        }
        iVar2 = *(int *)(iVar2 + 0x270);
      } while (iVar2 != 0);
      if (&DAT_1006c100 < DAT_100640f0) {
        (*DAT_1006c1dc)(0,s_pushed_p_>__pushed_MAX_EDICTS___m_10049810);
      }
      if (iVar2 != 0) {
        do {
          if (_DAT_1004410c < *(float *)(param_1 + 0x1ec)) {
            *(float *)(param_1 + 0x1ec) = *(float *)(param_1 + 0x1ec) + (float)_DAT_10044168;
          }
          param_1 = *(int *)(param_1 + 0x270);
        } while (param_1 != 0);
        if (*(code **)(iVar2 + 0x1f8) == (code *)0x0) {
          return;
        }
        (**(code **)(iVar2 + 0x1f8))(iVar2,DAT_1006c100);
        return;
      }
    }
    for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x270)) {
      FUN_10012d80(param_1);
    }
  }
  return;
}



/* FUN_1001d6f0 @ 1001d6f0 size 380 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_1001d6f0(int param_1,float *param_2,float *param_3,int param_4,int param_5,int param_6)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = FUN_1001b350();
  piVar2[1] = (int)*param_2;
  piVar2[2] = (int)param_2[1];
  piVar2[3] = (int)param_2[2];
  piVar2[0x55] = (int)*param_3;
  piVar2[0x56] = (int)param_3[1];
  piVar2[0x57] = (int)param_3[2];
  FUN_1001b1e0(param_3,(float *)(piVar2 + 4));
  FUN_10038a20(param_3,(float)param_5,(float *)(piVar2 + 0x5e));
  piVar2[0x41] = 8;
  piVar2[0x10] = piVar2[0x10] | 0x2080;
  piVar2[0x3f] = 0x6000003;
  piVar2[0x3e] = 2;
  piVar2[0x31] = 0;
  piVar2[0x30] = 0;
  piVar2[0x2f] = 0;
  piVar2[0x34] = 0;
  piVar2[0x33] = 0;
  piVar2[0x32] = 0;
  iVar3 = (*DAT_1006c1e0)(s_sprites_s_bfg1_sp2_1004c000);
  piVar2[10] = iVar3;
  piVar2[0x40] = param_1;
  piVar2[0x7f] = (int)&LAB_1001d2e0;
  fVar1 = (float)(int)(8000 / (longlong)param_5) + DAT_1006c2e4;
  piVar2[0x7d] = (int)FUN_1001b400;
  piVar2[0x92] = param_4;
  piVar2[0x93] = param_6;
  piVar2[0x46] = (int)s_bfg_blast_1004bfdc;
  piVar2[0x7b] = (int)fVar1;
  iVar3 = (*DAT_1006c1e4)(s_weapons_bfg__l1a_wav_1004bfe8);
  piVar2[0x13] = iVar3;
  piVar2[0x7d] = (int)&LAB_1001d440;
  fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
  piVar2[0x9d] = (int)piVar2;
  piVar2[0x9c] = 0;
  piVar2[0x7b] = (int)fVar1;
  if (*(int *)(param_1 + 0x54) != 0) {
    FUN_1001c1c0(param_1,(float *)(piVar2 + 1),param_3,param_5);
  }
  (*DAT_1006c208)(piVar2);
  return;
}



/* FUN_1000c2e0 @ 1000c2e0 size 376 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1000c2e0(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  longlong lVar7;
  
  piVar2 = *(int **)(*(int *)(param_1 + 0x2cc) + 0x3c);
  uVar3 = FUN_1000c290(param_2);
  if (*(int *)(*(int *)(param_1 + 0x2cc) + 0x40) == 4) {
    if (uVar3 == 0) {
      *(undefined4 *)(*(int *)(param_2 + 0x54) + 0x2e4 + DAT_10060e74 * 4) = 2;
    }
    else {
      piVar2 = (int *)(*(int *)(param_2 + 0x54) + 0x2e4 + uVar3 * 4);
      *piVar2 = *piVar2 + 2;
    }
  }
  else if (uVar3 == 0) {
    *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 +
            ((*(int *)(param_1 + 0x2cc) + -0x10046928) / 0x48) * 4) = *piVar2;
  }
  else {
    if (uVar3 == DAT_10060e74) {
      puVar6 = &DAT_100468e0;
    }
    else {
      puVar6 = &DAT_100468f8;
      if (uVar3 != DAT_10060e70) {
        puVar6 = &DAT_10046910;
      }
    }
    piVar1 = (int *)(*(int *)(param_2 + 0x54) + 0x2e4 + uVar3 * 4);
    if ((float)piVar2[2] <= *(float *)(puVar6 + 8)) {
      iVar5 = *piVar1;
      lVar7 = __ftol();
      iVar4 = (int)lVar7 + iVar5;
      if (*(int *)(puVar6 + 4) < iVar4) {
        iVar4 = *(int *)(puVar6 + 4);
      }
      if (iVar4 <= iVar5) {
        return 0;
      }
      *piVar1 = iVar4;
    }
    else {
      lVar7 = __ftol();
      iVar5 = (int)lVar7 + *piVar2;
      if (piVar2[1] < iVar5) {
        iVar5 = piVar2[1];
      }
      *piVar1 = 0;
      *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 +
              ((*(int *)(param_1 + 0x2cc) + -0x10046928) / 0x48) * 4) = iVar5;
    }
  }
  if (((*(uint *)(param_1 + 0x11c) & 0x10000) == 0) &&
     (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c)) {
    FUN_1000b210(param_1,20.0);
  }
  return 1;
}



/* FUN_10014ad0 @ 10014ad0 size 375 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10014ad0(float param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float10 fVar4;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  fVar2 = param_1;
  if (*(float *)((int)param_1 + 0x34c) <= *(float *)((int)param_1 + 800) * (float)_DAT_10044168) {
    FUN_100149d0((int)param_1);
    return;
  }
  FUN_10038a20((float *)((int)param_1 + 0x334),*(float *)((int)param_1 + 800),
               (float *)((int)param_1 + 0x178));
  fVar4 = FUN_1003900b((double)((*(float *)((int)param_1 + 0x34c) / *(float *)((int)param_1 + 800))
                               * (float)_DAT_10044170));
  local_10 = (float)fVar4;
  *(float *)((int)param_1 + 0x34c) =
       *(float *)((int)param_1 + 0x34c) -
       local_10 * *(float *)((int)param_1 + 800) * (float)_DAT_10044168;
  iVar3 = FUN_100388c0((float *)((int)param_1 + 0x1d0),(float *)&DAT_10061c18);
  if (iVar3 == 0) {
    local_c = *(float *)((int)param_1 + 0x304) - *(float *)((int)param_1 + 0x2ec);
    local_8 = *(float *)((int)param_1 + 0x308) - *(float *)((int)param_1 + 0x2f0);
    local_4 = *(float *)((int)param_1 + 0x30c) - *(float *)((int)param_1 + 0x2f4);
    fVar4 = FUN_100389f0(&local_c);
    if (*(float *)((int)param_1 + 0x298) <= _DAT_1004410c) {
      param_1 = (float)(fVar4 / (float10)*(float *)((int)param_1 + 800));
    }
    else {
      param_1 = *(float *)((int)param_1 + 0x298);
    }
    fVar4 = FUN_1003900b((double)(param_1 * (float)_DAT_10044170));
    local_10 = (float)fVar4;
    FUN_10038a20(&local_c,(float)_DAT_10044120 / param_1,(float *)((int)fVar2 + 0x184));
  }
  fVar1 = local_10 * (float)_DAT_10044168 + DAT_1006c2e4;
  *(code **)((int)fVar2 + 500) = FUN_100149d0;
  *(float *)((int)fVar2 + 0x1ec) = fVar1;
  return;
}



/* FUN_100323b0 @ 100323b0 size 374 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100323b0(int param_1)

{
  longlong lVar1;
  
  if ((*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) ||
     (*(float *)(DAT_1006c42c + 0x14) != _DAT_1004410c)) {
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xdd8) = 1;
  }
  *(undefined4 *)(param_1 + 4) = DAT_1006c3b4;
  *(undefined4 *)(param_1 + 8) = DAT_1006c3b8;
  *(undefined4 *)(param_1 + 0xc) = DAT_1006c3bc;
  lVar1 = __ftol();
  *(short *)(*(int *)(param_1 + 0x54) + 4) = (short)lVar1;
  lVar1 = __ftol();
  *(short *)(*(int *)(param_1 + 0x54) + 6) = (short)lVar1;
  lVar1 = __ftol();
  *(short *)(*(int *)(param_1 + 0x54) + 8) = (short)lVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x1c) = DAT_1006c3c0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x20) = DAT_1006c3c4;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x24) = DAT_1006c3c8;
  **(undefined4 **)(param_1 + 0x54) = 4;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x58) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x6c) = 0;
  *(uint *)(*(int *)(param_1 + 0x54) + 0x74) =
       *(uint *)(*(int *)(param_1 + 0x54) + 0x74) & 0xfffffffe;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xeac) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xeb0) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xeb4) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xeb8) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xebc) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xec0) = 0;
  *(undefined4 *)(param_1 + 0x23c) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  if ((*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) ||
     (*(float *)(DAT_1006c42c + 0x14) != _DAT_1004410c)) {
    FUN_100327c0(param_1,0);
    (*DAT_1006c21c)(param_1,1);
  }
  return;
}



/* FUN_10033b10 @ 10033b10 size 374 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10033b10(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  
  *(float *)(*(int *)(param_1 + 0x54) + 0x48) = _DAT_1006208c * _DAT_10062080 * (float)_DAT_10044350
  ;
  *(float *)(*(int *)(param_1 + 0x54) + 0x44) = _DAT_1006208c * _DAT_10062080 * (float)_DAT_100443f0
  ;
  if (((byte)DAT_10062088 & 1) != 0) {
    *(float *)(*(int *)(param_1 + 0x54) + 0x48) = -*(float *)(*(int *)(param_1 + 0x54) + 0x48);
    *(float *)(*(int *)(param_1 + 0x54) + 0x44) = -*(float *)(*(int *)(param_1 + 0x54) + 0x44);
  }
  iVar6 = 0;
  *(float *)(*(int *)(param_1 + 0x54) + 0x40) = _DAT_1006208c * _DAT_10062080 * (float)_DAT_10044350
  ;
  do {
    iVar3 = *(int *)(param_1 + 0x54);
    fVar4 = *(float *)(iVar3 + 0xe74 + iVar6 * 4) - *(float *)(iVar3 + 0x1c + iVar6 * 4);
    if (_DAT_100442c4 < fVar4) {
      fVar4 = fVar4 - _DAT_100442b0;
    }
    if (fVar4 < _DAT_100442c0) {
      fVar4 = fVar4 + _DAT_100442b0;
    }
    fVar5 = _DAT_10044138;
    if ((fVar4 <= _DAT_10044138) && (fVar5 = fVar4, fVar4 < _DAT_10044410)) {
      fVar5 = _DAT_10044410;
    }
    if (iVar6 == 1) {
      *(float *)(iVar3 + 0x48) = fVar5 * (float)_DAT_10044168 + *(float *)(iVar3 + 0x48);
    }
    pfVar1 = (float *)(*(int *)(param_1 + 0x54) + 0x40 + iVar6 * 4);
    iVar6 = iVar6 + 1;
    *pfVar1 = fVar5 * (float)_DAT_10044198 + *pfVar1;
  } while (iVar6 < 3);
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x54) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x50) = 0;
  iVar6 = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x4c) = 0;
  do {
    pfVar1 = (float *)(iVar6 + 0x4c + *(int *)(param_1 + 0x54));
    *pfVar1 = *(float *)(DAT_1006c190 + 0x14) * *(float *)((int)&DAT_10061398 + iVar6) + *pfVar1;
    pfVar1 = (float *)(iVar6 + 0x4c + *(int *)(param_1 + 0x54));
    *pfVar1 = *(float *)((int)&DAT_100613a4 + iVar6) * *(float *)(DAT_1006c18c + 0x14) + *pfVar1;
    pfVar1 = (float *)((int)&DAT_100613b0 + iVar6);
    pfVar2 = (float *)(iVar6 + 0x4c + *(int *)(param_1 + 0x54));
    iVar6 = iVar6 + 4;
    *pfVar2 = -*(float *)(DAT_1006c194 + 0x14) * *pfVar1 + *pfVar2;
  } while (iVar6 < 0xc);
  return;
}



/* FUN_10015750 @ 10015750 size 372 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10015750(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  
  *(undefined4 *)(param_1 + 0x104) = 2;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(code **)(param_1 + 0x1f8) = FUN_10015090;
  if ((*(byte *)(param_1 + 0x11c) & 4) == 0) {
    if (*(int *)(param_1 + 0x244) == 0) {
      *(undefined4 *)(param_1 + 0x244) = 100;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x244) = 0;
  }
  *(undefined4 *)(param_1 + 0xf8) = 3;
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  if (DAT_1006c2a4 != 0) {
    uVar2 = (*DAT_1006c1e4)(DAT_1006c2a4);
    *(undefined4 *)(param_1 + 0x314) = uVar2;
  }
  if (*(float *)(param_1 + 0x148) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x148) = 0x42c80000;
  }
  if (*(float *)(param_1 + 0x298) <= _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x298) = 0;
  }
  if (*(char **)(param_1 + 0x1a8) != (char *)0x0) {
    FUN_10039662(*(char **)(param_1 + 0x1a8),(byte *)s__f__f__f_10046688);
  }
  if (*(char **)(param_1 + 0x19c) != (char *)0x0) {
    FUN_10039662(*(char **)(param_1 + 0x19c),(byte *)s__f__f__f_10046688);
  }
  *(undefined4 *)(param_1 + 800) = *(undefined4 *)(param_1 + 0x148);
  *(undefined1 **)(param_1 + 0x200) = &LAB_100156f0;
  (*DAT_1006c208)(param_1);
  if (*(int *)(param_1 + 0x128) != 0) {
    fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
    *(undefined1 **)(param_1 + 500) = &LAB_10015560;
    *(float *)(param_1 + 0x1ec) = fVar1;
    return;
  }
  iVar4 = param_1 + 0xd4;
  puVar3 = FUN_1001b070();
  (*DAT_1006c1c4)(s_func_train_without_a_target_at___100467c4,puVar3,iVar4);
  return;
}



/* FUN_10019ba0 @ 10019ba0 size 370 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10019ba0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  
  if ((*(byte *)(param_2 + 0xb8) & 4) == 0) {
    if (*(int *)(param_2 + 0x54) == 0) {
      return;
    }
    bVar3 = *(byte *)(param_1 + 0x11c) & 2;
  }
  else {
    bVar3 = *(byte *)(param_1 + 0x11c) & 1;
  }
  if (bVar3 == 0) {
    uVar5 = FUN_1001ac00(0,300,*(byte **)(param_1 + 0x128));
    if (uVar5 == 0) {
      (*DAT_1006c1c4)(s_Couldn_t_find_destination_1004961c);
      return;
    }
    (*DAT_1006c20c)(param_2);
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(uVar5 + 4);
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(uVar5 + 8);
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(uVar5 + 0xc);
    fVar4 = *(float *)(param_2 + 0xc) + _DAT_100441b0;
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(uVar5 + 4);
    *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(uVar5 + 8);
    uVar1 = *(undefined4 *)(uVar5 + 0xc);
    *(float *)(param_2 + 0xc) = fVar4;
    *(undefined4 *)(param_2 + 0x24) = uVar1;
    *(undefined4 *)(param_2 + 0x180) = 0;
    *(undefined4 *)(param_2 + 0x17c) = 0;
    *(undefined4 *)(param_2 + 0x178) = 0;
    *(undefined1 *)(*(int *)(param_2 + 0x54) + 0x11) = 0x14;
    *(byte *)(*(int *)(param_2 + 0x54) + 0x10) = *(byte *)(*(int *)(param_2 + 0x54) + 0x10) | 0x20;
    if ((*(byte *)(param_1 + 0x11c) & 8) == 0) {
      *(undefined4 *)(param_1 + 0x50) = 6;
      *(undefined4 *)(param_2 + 0x50) = 6;
    }
    param_1 = 0x14;
    iVar6 = 0xdac;
    do {
      iVar2 = *(int *)(param_2 + 0x54);
      lVar7 = __ftol();
      iVar6 = iVar6 + 4;
      *(short *)(param_1 + iVar2) = (short)lVar7;
      param_1 = param_1 + 2;
    } while (iVar6 < 0xdb8);
    *(undefined4 *)(param_2 + 0x18) = 0;
    *(undefined4 *)(param_2 + 0x14) = 0;
    *(undefined4 *)(param_2 + 0x10) = 0;
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0x24) = 0;
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0x20) = 0;
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0x1c) = 0;
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0xe6c) = 0;
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0xe68) = 0;
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0xe64) = 0;
    FUN_1001b510(param_2);
    (*DAT_1006c208)(param_2);
  }
  return;
}



/* FUN_1003e7ca @ 1003e7ca size 368 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __cdecl FUN_1003e7ca(LPCSTR param_1,char *param_2,uint param_3,undefined4 *param_4)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  
  bVar4 = false;
  bVar3 = false;
  cVar1 = *param_2;
  if (cVar1 == 'a') {
    uVar5 = 0x109;
  }
  else {
    if (cVar1 == 'r') {
      uVar5 = 0;
      uVar6 = DAT_10061f30 | 1;
      goto LAB_1003e80b;
    }
    if (cVar1 != 'w') {
      return (undefined4 *)0x0;
    }
    uVar5 = 0x301;
  }
  uVar6 = DAT_10061f30 | 2;
LAB_1003e80b:
  bVar2 = true;
LAB_1003e80e:
  cVar1 = param_2[1];
  param_2 = param_2 + 1;
  if ((cVar1 == '\0') || (!bVar2)) {
    uVar5 = FUN_10041156(param_1,uVar5,param_3,0x1a4);
    if ((int)uVar5 < 0) {
      return (undefined4 *)0x0;
    }
    _DAT_10061da4 = _DAT_10061da4 + 1;
    param_4[3] = uVar6;
    param_4[1] = 0;
    *param_4 = 0;
    param_4[2] = 0;
    param_4[7] = 0;
    param_4[4] = uVar5;
    return param_4;
  }
  if (cVar1 < 'U') {
    if (cVar1 == 'T') {
      if ((uVar5 & 0x1000) == 0) {
        uVar5 = uVar5 | 0x1000;
        goto LAB_1003e80e;
      }
    }
    else if (cVar1 == '+') {
      if ((uVar5 & 2) == 0) {
        uVar5 = uVar5 & 0xfffffffe | 2;
        uVar6 = uVar6 & 0xfffffffc | 0x80;
        goto LAB_1003e80e;
      }
    }
    else if (cVar1 == 'D') {
      if ((uVar5 & 0x40) == 0) {
        uVar5 = uVar5 | 0x40;
        goto LAB_1003e80e;
      }
    }
    else if (cVar1 == 'R') {
      if (!bVar3) {
        bVar3 = true;
        uVar5 = uVar5 | 0x10;
        goto LAB_1003e80e;
      }
    }
    else if ((cVar1 == 'S') && (!bVar3)) {
      bVar3 = true;
      uVar5 = uVar5 | 0x20;
      goto LAB_1003e80e;
    }
  }
  else {
    if (cVar1 == 'b') {
      if ((uVar5 & 0xc000) != 0) goto LAB_1003e8ee;
      uVar5 = uVar5 | 0x8000;
      goto LAB_1003e80e;
    }
    if (cVar1 == 'c') {
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 | 0x4000;
        goto LAB_1003e80e;
      }
    }
    else {
      if (cVar1 != 'n') {
        if ((cVar1 != 't') || ((uVar5 & 0xc000) != 0)) goto LAB_1003e8ee;
        uVar5 = uVar5 | 0x4000;
        goto LAB_1003e80e;
      }
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 & 0xffffbfff;
        goto LAB_1003e80e;
      }
    }
  }
LAB_1003e8ee:
  bVar2 = false;
  goto LAB_1003e80e;
}



/* FUN_1003fc85 @ 1003fc85 size 364 */

undefined4 __cdecl FUN_1003fc85(ushort *param_1,uint *param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_1c [3];
  uint local_10;
  uint local_c;
  int local_8;
  
  uVar1 = param_1[5];
  local_10 = *(uint *)(param_1 + 3);
  local_c = *(uint *)(param_1 + 1);
  uVar3 = uVar1 & 0x7fff;
  iVar4 = uVar3 - 0x3fff;
  local_8 = (uint)*param_1 << 0x10;
  if (iVar4 == -0x3fff) {
    iVar4 = 0;
    iVar2 = FUN_1003fbdd((int *)&local_10);
    if (iVar2 != 0) {
LAB_1003fdb1:
      uVar5 = 0;
      goto LAB_1003fdb3;
    }
    FUN_1003fbd1(&local_10);
  }
  else {
    FUN_1003fbb6((int)local_1c,&local_10);
    iVar2 = FUN_1003fb2a((int)&local_10,param_3[2]);
    if (iVar2 != 0) {
      iVar4 = uVar3 - 0x3ffe;
    }
    iVar2 = param_3[1];
    if (iVar4 < iVar2 - param_3[2]) {
      FUN_1003fbd1(&local_10);
    }
    else {
      if (iVar2 < iVar4) {
        if (*param_3 <= iVar4) {
          FUN_1003fbd1(&local_10);
          local_10 = local_10 | 0x80000000;
          FUN_1003fbf8(&local_10,param_3[3]);
          iVar4 = param_3[5] + *param_3;
          uVar5 = 1;
          goto LAB_1003fdb3;
        }
        local_10 = local_10 & 0x7fffffff;
        iVar4 = param_3[5] + iVar4;
        FUN_1003fbf8(&local_10,param_3[3]);
        goto LAB_1003fdb1;
      }
      FUN_1003fbb6((int)&local_10,local_1c);
      FUN_1003fbf8(&local_10,iVar2 - iVar4);
      FUN_1003fb2a((int)&local_10,param_3[2]);
      FUN_1003fbf8(&local_10,param_3[3] + 1);
    }
  }
  iVar4 = 0;
  uVar5 = 2;
LAB_1003fdb3:
  local_10 = iVar4 << (0x1fU - (char)param_3[3] & 0x1f) |
             -(uint)((uVar1 & 0x8000) != 0) & 0x80000000 | local_10;
  if (param_3[4] == 0x40) {
    param_2[1] = local_10;
    *param_2 = local_c;
  }
  else if (param_3[4] == 0x20) {
    *param_2 = local_10;
  }
  return uVar5;
}



/* FUN_10006860 @ 10006860 size 362 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_10006860(float param_1,uint param_2,float param_3,uint param_4,float param_5,uint param_6)

{
  float *pfVar1;
  float fVar2;
  bool bVar3;
  uint uVar4;
  undefined3 extraout_var;
  float10 fVar5;
  longlong lVar6;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  fVar2 = param_1;
  pfVar1 = (float *)((int)param_1 + 4);
  for (uVar4 = FUN_1001aca0(0,(int)pfVar1,param_5); uVar4 != 0;
      uVar4 = FUN_1001aca0(uVar4,(int)pfVar1,param_5)) {
    if ((uVar4 != param_4) && (*(int *)(uVar4 + 0x240) != 0)) {
      local_18 = *(float *)(uVar4 + 200) + *(float *)(uVar4 + 0xbc);
      local_14 = *(float *)(uVar4 + 0xcc) + *(float *)(uVar4 + 0xc0);
      local_10 = *(float *)(uVar4 + 0xd0) + *(float *)(uVar4 + 0xc4);
      FUN_10038950((float *)(uVar4 + 4),0.5,&local_18,&local_18);
      local_18 = *pfVar1 - local_18;
      local_14 = *(float *)((int)fVar2 + 8) - local_14;
      local_10 = *(float *)((int)fVar2 + 0xc) - local_10;
      fVar5 = FUN_100389f0(&local_18);
      param_1 = (float)((float10)param_3 - fVar5 * (float10)_DAT_10044140);
      if (uVar4 == param_2) {
        param_1 = param_1 * (float)_DAT_10044140;
      }
      if ((_DAT_1004410c < param_1) &&
         (bVar3 = FUN_10005990(uVar4,(int)fVar2), CONCAT31(extraout_var,bVar3) != 0)) {
        local_c = *(float *)(uVar4 + 4) - *pfVar1;
        local_8 = *(float *)(uVar4 + 8) - *(float *)((int)fVar2 + 8);
        local_4 = *(float *)(uVar4 + 0xc) - *(float *)((int)fVar2 + 0xc);
        lVar6 = __ftol();
        FUN_100060d0(uVar4,fVar2,param_2,&local_c,pfVar1,&DAT_10061c18,(int)lVar6,(int)lVar6,1,
                     param_6);
      }
    }
  }
  return;
}



/* FUN_100125e0 @ 100125e0 size 362 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_100125e0(undefined4 *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  float fVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  int iVar7;
  byte *pbVar8;
  
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    FUN_1001b400(param_1);
    return 0;
  }
  if (((param_1[0x47] & 4) != 0) && ((param_1[0xd7] & 0x100) == 0)) {
    param_1[0x47] = param_1[0x47] & 0xfffffffb | 1;
  }
  if ((param_1[0xd7] & 0x100) == 0) {
    DAT_1006c3fc = DAT_1006c3fc + 1;
  }
  fVar4 = DAT_1006c2e4 + (float)_DAT_10044168;
  uVar1 = param_1[0x2e];
  param_1[0x2e] = uVar1 | 4;
  param_1[0x7b] = fVar4;
  param_1[0x11] = param_1[0x11] | 0x40;
  param_1[0x90] = 2;
  fVar4 = DAT_1006c2e4 + _DAT_10044244;
  param_1[0x2e] = uVar1 & 0xfffffffd | 4;
  param_1[0x80] = &LAB_10012410;
  param_1[0x89] = param_1[0x88];
  param_1[0x65] = fVar4;
  param_1[0x3f] = 0x2020003;
  param_1[0xf] = 0;
  param_1[0x8b] = 0;
  if (param_1[0xe3] == 0) {
    param_1[0xe3] = FUN_10001f40;
  }
  param_1[7] = param_1[1];
  param_1[8] = param_1[2];
  param_1[9] = param_1[3];
  if (DAT_1006c2ac != (byte *)0x0) {
    puVar5 = FUN_1000b100(DAT_1006c2ac);
    param_1[0xb3] = puVar5;
    if (puVar5 == (undefined4 *)0x0) {
      pbVar8 = DAT_1006c2ac;
      puVar6 = FUN_1001b070();
      (*DAT_1006c1c4)(s__s_at__s_has_bad_item___s_1004970c,param_1[0x46],puVar6,pbVar8);
    }
  }
  piVar2 = (int *)param_1[0xd6];
  if (piVar2 != (int *)0x0) {
    iVar3 = *piVar2;
    iVar7 = _rand();
    param_1[0xe] = iVar7 % ((piVar2[1] - iVar3) + 1) + iVar3;
  }
  return 1;
}



/* FUN_10016af0 @ 10016af0 size 361 */

void FUN_10016af0(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  local_c = 0;
  local_10 = 0;
  if (1 < DAT_1006c168) {
    local_4 = 2;
    iVar4 = DAT_1006c168;
    iVar2 = DAT_1006c2c4;
    do {
      iVar6 = iVar2 + 0x3d0;
      if (((*(int *)(iVar2 + 0x428) != 0) && (*(int *)(iVar2 + 0x504) != 0)) &&
         ((*(uint *)(iVar2 + 0x4d8) & 0x400) == 0)) {
        local_c = local_c + 1;
        *(int *)(iVar2 + 0x644) = iVar6;
        local_10 = local_10 + 1;
        iVar3 = iVar2 + 0x7a0;
        iVar5 = iVar6;
        iVar4 = DAT_1006c168;
        local_8 = local_4;
        if (local_4 < DAT_1006c168) {
          do {
            if (((*(int *)(iVar3 + 0x58) != 0) &&
                (pbVar8 = *(byte **)(iVar3 + 0x134), pbVar8 != (byte *)0x0)) &&
               ((*(uint *)(iVar3 + 0x108) & 0x400) == 0)) {
              pbVar7 = *(byte **)(iVar2 + 0x504);
              do {
                bVar1 = *pbVar7;
                bVar9 = bVar1 < *pbVar8;
                if (bVar1 != *pbVar8) {
LAB_10016bc9:
                  iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
                  goto LAB_10016bce;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar7[1];
                bVar9 = bVar1 < pbVar8[1];
                if (bVar1 != pbVar8[1]) goto LAB_10016bc9;
                pbVar7 = pbVar7 + 2;
                pbVar8 = pbVar8 + 2;
              } while (bVar1 != 0);
              iVar4 = 0;
LAB_10016bce:
              if (iVar4 == 0) {
                *(int *)(iVar5 + 0x270) = iVar3;
                local_10 = local_10 + 1;
                *(int *)(iVar3 + 0x274) = iVar6;
                *(uint *)(iVar3 + 0x108) = *(uint *)(iVar3 + 0x108) | 0x400;
                iVar5 = iVar3;
              }
            }
            local_8 = local_8 + 1;
            iVar3 = iVar3 + 0x3d0;
            iVar4 = DAT_1006c168;
          } while (local_8 < DAT_1006c168);
        }
      }
      bVar9 = local_4 < iVar4;
      iVar2 = iVar6;
      local_4 = local_4 + 1;
    } while (bVar9);
  }
  (*DAT_1006c1c4)(s__i_teams_with__i_entities_1004b390,local_c,local_10);
  return;
}



/* FUN_1000df70 @ 1000df70 size 360 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000df70(float param_1,undefined4 param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float afStack_c [3];
  
  fVar2 = param_1;
  *(undefined4 *)((int)param_1 + 0x3c) = 0;
  *(undefined4 *)((int)param_1 + 0x38) = 0;
  *(undefined4 *)((int)param_1 + 0xc4) = 0;
  *(undefined4 *)((int)param_1 + 0xc0) = 0;
  *(undefined4 *)((int)param_1 + 0xbc) = 0;
  *(undefined4 *)((int)param_1 + 0xd0) = 0;
  *(undefined4 *)((int)param_1 + 0xcc) = 0;
  *(undefined4 *)((int)param_1 + 200) = 0;
  *(undefined4 *)((int)param_1 + 0x2c) = 0;
  (*DAT_1006c1ec)(param_1,param_2);
  *(uint *)((int)param_1 + 0x40) = *(uint *)((int)param_1 + 0x40) & 0xffffbfff | 2;
  *(undefined4 *)((int)param_1 + 0xf8) = 0;
  *(undefined4 *)((int)param_1 + 0x4c) = 0;
  *(uint *)((int)param_1 + 0x108) = *(uint *)((int)param_1 + 0x108) | 0x800;
  *(uint *)((int)param_1 + 0xb8) = *(uint *)((int)param_1 + 0xb8) & 0xfffffffb;
  *(undefined4 *)((int)param_1 + 0x240) = 1;
  *(undefined1 **)((int)param_1 + 0x208) = &LAB_1000fd20;
  if (param_4 == 0) {
    *(undefined4 *)((int)param_1 + 0x104) = 7;
    *(undefined1 **)((int)param_1 + 0x1fc) = &LAB_1000dc70;
    param_1 = 0.5;
  }
  else {
    *(undefined4 *)((int)param_1 + 0x104) = 9;
    param_1 = 1.0;
  }
  FUN_1000da90(param_3,afStack_c);
  FUN_10038950((float *)((int)fVar2 + 0x178),param_1,afStack_c,(float *)((int)fVar2 + 0x178));
  FUN_1000db40((int)fVar2);
  uVar3 = _rand();
  *(code **)((int)fVar2 + 500) = FUN_1001b400;
  fVar1 = (float)(uVar3 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  *(float *)((int)fVar2 + 0x188) = (fVar1 + fVar1) * (float)_DAT_100441f8;
  uVar3 = _rand();
  *(float *)((int)fVar2 + 0x1ec) =
       ((float)(uVar3 & 0x7fff) * _DAT_10044108 + _DAT_10044104) * _DAT_100441b0 + DAT_1006c2e4;
  (*DAT_1006c208)(fVar2);
  return;
}



/* FUN_1000e670 @ 1000e670 size 359 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000e670(undefined4 *param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  if (param_1[0x4b] == 0) {
    puVar2 = param_1 + 1;
    puVar1 = FUN_1001b070();
    (*DAT_1006c1c4)(s_path_corner_with_no_targetname_a_10049200,puVar1,puVar2);
    FUN_1001b400(param_1);
    return;
  }
  if ((float)param_1[0x52] == _DAT_1004410c) {
    param_1[0x52] = 0x42c80000;
  }
  if ((float)param_1[0xa6] <= _DAT_1004410c) {
    param_1[0xa6] = 0;
  }
  if ((char *)param_1[0x6a] != (char *)0x0) {
    FUN_10039662((char *)param_1[0x6a],(byte *)s__f__f__f_10046688);
  }
  if ((char *)param_1[0x67] != (char *)0x0) {
    FUN_10039662((char *)param_1[0x67],(byte *)s__f__f__f_10046688);
    if ((float)param_1[0x6b] < _DAT_1004410c) {
      param_1[0x6b] = 0.0;
    }
    if ((float)param_1[0x6c] < _DAT_1004410c) {
      param_1[0x6c] = 0.0;
    }
    if ((float)param_1[0x6d] < _DAT_1004410c) {
      param_1[0x6d] = 0.0;
    }
  }
  param_1[0x2f] = 0xc1000000;
  param_1[0x30] = 0xc1000000;
  param_1[0x31] = 0xc1000000;
  param_1[0x3e] = 1;
  param_1[0x7f] = &LAB_1000e500;
  param_1[0x32] = 0x41000000;
  param_1[0x33] = 0x41000000;
  param_1[0x34] = 0x41000000;
  param_1[0x2e] = param_1[0x2e] | 1;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_100147d0 @ 100147d0 size 357 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100147d0(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  
  *(undefined4 *)(param_1 + 0xbc) = 0xc1400000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc1400000;
  *(undefined4 *)(param_1 + 0xf8) = 2;
  *(undefined4 *)(param_1 + 0xfc) = 0x2010003;
  *(undefined4 *)(param_1 + 0x104) = 7;
  *(undefined4 *)(param_1 + 0xc4) = 0xc1600000;
  *(undefined4 *)(param_1 + 200) = 0x41400000;
  *(undefined4 *)(param_1 + 0xcc) = 0x41400000;
  *(undefined4 *)(param_1 + 0xd0) = 0x41500000;
  *(undefined **)(param_1 + 0x118) = &DAT_10048094;
  uVar2 = (*DAT_1006c1e0)(s_models_objects_rtdu_rtdu_md2_100480a4);
  *(undefined4 *)(param_1 + 0x28) = uVar2;
  *(undefined4 *)(param_1 + 0x38) = 0;
  puVar3 = FUN_1000b150(&DAT_100498d4);
  *(undefined4 **)(param_1 + 0x2cc) = puVar3;
  *(undefined4 *)(param_1 + 0x220) = 0x3c;
  *(undefined4 *)(param_1 + 0x254) = 200;
  *(undefined4 *)(param_1 + 0x120) = 0;
  fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
  *(code **)(param_1 + 500) = FUN_10014320;
  *(code **)(param_1 + 0x208) = FUN_100144c0;
  *(float *)(param_1 + 0x1ec) = fVar1;
  (*DAT_1006c208)(param_1);
  piVar4 = FUN_1001b350();
  piVar4[0x3e] = 0;
  piVar4[0x41] = 6;
  piVar4[0x3f] = 0x2010003;
  piVar4[0x46] = (int)(s_pARTDUTripod_100498a6 + 2);
  iVar5 = (*DAT_1006c1e0)(s_models_objects_rtdu_tripod_md2_100498b4);
  piVar4[10] = iVar5;
  piVar4[0x2f] = -0x3d380000;
  piVar4[0x30] = -0x3d380000;
  piVar4[0x31] = -0x3d380000;
  piVar4[0xe] = 0;
  piVar4[0x32] = 0x42c80000;
  piVar4[0x33] = 0x42c80000;
  piVar4[0x34] = 0x42c80000;
  piVar4[1] = *(int *)(param_1 + 4);
  piVar4[2] = *(int *)(param_1 + 8);
  piVar4[3] = (int)(*(float *)(param_1 + 0xc) + _DAT_10044288);
  (*DAT_1006c208)(piVar4);
  *(int **)(param_1 + 600) = piVar4;
  return;
}



/* FUN_10027f30 @ 10027f30 size 354 */

void __cdecl FUN_10027f30(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_1006c104 == 0x23) {
    FUN_1000e460(param_1);
    return;
  }
  if ((int)param_1[0x88] <= (int)param_1[0x8a]) {
    uVar1 = (*DAT_1006c1e4)(s_misc_udeath_wav_100493f8,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_1,2,uVar1);
    iVar2 = 2;
    do {
      FUN_1000dd30((float)param_1,s_models_objects_gibs_bone_tris_md_1004b5a4,param_4,0);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar2 = 4;
    do {
      FUN_1000dd30((float)param_1,s_models_objects_gibs_sm_meat_tris_100493d0,param_4,0);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    FUN_1000df70((float)param_1,s_models_objects_gibs_head2_tris_m_100491d4,param_4,0);
    param_1[0x8b] = 2;
    return;
  }
  if (param_1[0x8b] != 2) {
    param_1[0x8b] = 2;
    param_1[0x90] = 1;
    iVar2 = _rand();
    if (iVar2 % 3 == 0) {
      param_1[0xd6] = &DAT_100572a8;
      (*DAT_1006c1d0)(param_1,2,DAT_10061214,0x3f800000,0x3f800000,0);
      return;
    }
    if (iVar2 % 3 == 1) {
      param_1[0xd6] = &DAT_100573e8;
      (*DAT_1006c1d0)(param_1,2,DAT_10061210,0x3f800000,0x3f800000,0);
      return;
    }
    param_1[0xd6] = &DAT_10057468;
    (*DAT_1006c1d0)(param_1,2,DAT_10061214,0x3f800000,0x3f800000,0);
  }
  return;
}



/* FUN_10039818 @ 10039818 size 352 */

int * __cdecl FUN_10039818(int *param_1)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  
  piVar2 = param_1;
  if (*param_1 < 0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_1003d456();
    iVar3 = *piVar2;
    if ((iVar3 < 0x3f481) || (0x7ffc0b7e < iVar3)) {
      piVar2 = FUN_1003da18(piVar2);
      bVar1 = FUN_1003d70b(piVar2);
      iVar3 = *piVar2;
      if (CONCAT31(extraout_var_00,bVar1) != 0) {
        iVar3 = iVar3 - DAT_1005ffd0;
      }
      param_1 = (int *)(iVar3 - DAT_1005ffc8);
      iVar3 = (int)param_1 % 0x3c;
      *piVar2 = iVar3;
      if (iVar3 < 0) {
        *piVar2 = iVar3 + 0x3c;
        param_1 = param_1 + -0xf;
      }
      param_1 = (int *)((int)param_1 / 0x3c + piVar2[1]);
      iVar3 = (int)param_1 % 0x3c;
      piVar2[1] = iVar3;
      if (iVar3 < 0) {
        piVar2[1] = iVar3 + 0x3c;
        param_1 = param_1 + -0xf;
      }
      param_1 = (int *)((int)param_1 / 0x3c + piVar2[2]);
      iVar3 = (int)param_1 % 0x18;
      piVar2[2] = iVar3;
      if (iVar3 < 0) {
        piVar2[2] = iVar3 + 0x18;
        param_1 = param_1 + -6;
      }
      iVar3 = (int)param_1 / 0x18;
      if (iVar3 < 1) {
        if (-1 < iVar3) {
          return piVar2;
        }
        piVar2[6] = (piVar2[6] + 7 + iVar3) % 7;
        piVar2[3] = piVar2[3] + iVar3;
        if (piVar2[3] < 1) {
          piVar2[5] = piVar2[5] + -1;
          piVar2[3] = piVar2[3] + 0x1f;
          piVar2[7] = 0x16c;
          piVar2[4] = 0xb;
          return piVar2;
        }
      }
      else {
        piVar2[6] = (piVar2[6] + iVar3) % 7;
        piVar2[3] = piVar2[3] + iVar3;
      }
      piVar2[7] = piVar2[7] + iVar3;
    }
    else {
      param_1 = (int *)(iVar3 - DAT_1005ffc8);
      piVar2 = FUN_1003da18((int *)&param_1);
      if ((DAT_1005ffcc != 0) && (bVar1 = FUN_1003d70b(piVar2), CONCAT31(extraout_var,bVar1) != 0))
      {
        param_1 = (int *)((int)param_1 - DAT_1005ffd0);
        piVar2 = FUN_1003da18((int *)&param_1);
        piVar2[8] = 1;
      }
    }
  }
  return piVar2;
}



/* FUN_10034a90 @ 10034a90 size 350 */

void __cdecl FUN_10034a90(int param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  char *pcVar7;
  bool bVar8;
  
  if (*(int *)(*(int *)(param_1 + 0x54) + 0x724) != DAT_1006c840) {
    *(int *)(*(int *)(param_1 + 0x54) + 0x724) = DAT_1006c840;
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x728) = 1;
  }
  iVar5 = *(int *)(*(int *)(param_1 + 0x54) + 0x728);
  if (((iVar5 != 0) && (iVar5 < 4)) && (((byte)DAT_1006c2e0 & 0x3f) == 0)) {
    *(int *)(*(int *)(param_1 + 0x54) + 0x728) = iVar5 + 1;
    uVar3 = (*DAT_1006c1e4)(s_misc_pc_up_wav_1004b748,0x3f800000,0x40400000,0);
    (*DAT_1006c1d0)(param_1,2,uVar3);
  }
  puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x54) + 0x714);
  if (puVar2 == (undefined4 *)0x0) {
    pbVar6 = &DAT_10060c60;
  }
  else {
    pbVar6 = (byte *)*puVar2;
  }
  if ((*(int *)(param_1 + 0x2a8) != 0) && ((*(byte *)(param_1 + 0x2a4) & 0x18) != 0)) {
    *(undefined4 *)(param_1 + 0x4c) = DAT_1006c1a0;
    return;
  }
  pcVar7 = s_weapon_railgun_100483cc;
  pbVar4 = pbVar6;
  do {
    bVar1 = *pbVar4;
    bVar8 = bVar1 < (byte)*pcVar7;
    if (bVar1 != *pcVar7) {
LAB_10034b67:
      iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      goto LAB_10034b6c;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar4[1];
    bVar8 = bVar1 < (byte)pcVar7[1];
    if (bVar1 != pcVar7[1]) goto LAB_10034b67;
    pbVar4 = pbVar4 + 2;
    pcVar7 = pcVar7 + 2;
  } while (bVar1 != 0);
  iVar5 = 0;
LAB_10034b6c:
  if (iVar5 == 0) {
    uVar3 = (*DAT_1006c1e4)(s_weapons_rg_hum_wav_1004835c);
    *(undefined4 *)(param_1 + 0x4c) = uVar3;
    return;
  }
  pcVar7 = s_weapon_bfg_10048350;
  do {
    bVar1 = *pbVar6;
    bVar8 = bVar1 < (byte)*pcVar7;
    if (bVar1 != *pcVar7) {
LAB_10034bb1:
      iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      goto LAB_10034bb6;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar6[1];
    bVar8 = bVar1 < (byte)pcVar7[1];
    if (bVar1 != pcVar7[1]) goto LAB_10034bb1;
    pbVar6 = pbVar6 + 2;
    pcVar7 = pcVar7 + 2;
  } while (bVar1 != 0);
  iVar5 = 0;
LAB_10034bb6:
  if (iVar5 == 0) {
    uVar3 = (*DAT_1006c1e4)(s_weapons_bfg_hum_wav_1005f6ec);
    *(undefined4 *)(param_1 + 0x4c) = uVar3;
    return;
  }
  iVar5 = *(int *)(*(int *)(param_1 + 0x54) + 0xec8);
  if (iVar5 != 0) {
    *(int *)(param_1 + 0x4c) = iVar5;
    return;
  }
  *(undefined4 *)(param_1 + 0x4c) = 0;
  return;
}



/* FUN_10036400 @ 10036400 size 348 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10036400(int param_1,float *param_2,int param_3,int param_4,uint param_5)

{
  uint uVar1;
  float local_30;
  float local_2c;
  float local_28;
  float local_24 [3];
  float local_18 [3];
  float local_c [3];
  
  if (DAT_100613c0 != 0) {
    param_3 = param_3 * 4;
  }
  FUN_10038700((float *)(*(int *)(param_1 + 0x54) + 0xe64),local_24,local_c,(float *)0x0);
  local_30 = *param_2 + _DAT_100443d8;
  local_2c = param_2[1] + _DAT_10044164;
  local_28 = (float)(*(int *)(param_1 + 0x23c) + -8) + param_2[2];
  FUN_10035db0(*(int *)(param_1 + 0x54),(float *)(param_1 + 4),&local_30,local_24,local_c,local_18);
  FUN_10038a20(local_24,-2.0,(float *)(*(int *)(param_1 + 0x54) + 0xe30));
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe24) = 0xbf800000;
  FUN_1001c000(param_1,local_18,local_24,param_3,1000,param_5,param_4);
  (*DAT_1006c224)(1);
  (*DAT_1006c228)((param_1 - DAT_1006c2c4) / 0x3d0);
  if (param_4 == 0) {
    uVar1 = DAT_100613c4 & 0xff;
  }
  else {
    uVar1 = DAT_100613c4 & 0xff | 0xe;
  }
  (*DAT_1006c224)(uVar1);
  (*DAT_1006c218)((float *)(param_1 + 4),2);
  FUN_100350a0(param_1,local_18,1);
  return;
}



/* FUN_1001cad0 @ 1001cad0 size 347 */

void __cdecl
FUN_1001cad0(int param_1,float *param_2,float *param_3,int param_4,int param_5,int param_6,
            int param_7)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = FUN_1001b350();
  piVar2[1] = (int)*param_2;
  piVar2[2] = (int)param_2[1];
  piVar2[3] = (int)param_2[2];
  piVar2[0x55] = (int)*param_3;
  piVar2[0x56] = (int)param_3[1];
  piVar2[0x57] = (int)param_3[2];
  FUN_1001b1e0(param_3,(float *)(piVar2 + 4));
  FUN_10038a20(param_3,(float)param_5,(float *)(piVar2 + 0x5e));
  piVar2[0x41] = 8;
  piVar2[0x10] = piVar2[0x10] | 0x10;
  piVar2[0x3f] = 0x6000003;
  piVar2[0x3e] = 2;
  piVar2[0x31] = 0;
  piVar2[0x30] = 0;
  piVar2[0x2f] = 0;
  piVar2[0x34] = 0;
  piVar2[0x33] = 0;
  piVar2[0x32] = 0;
  iVar3 = (*DAT_1006c1e0)(s_models_objects_rocket_tris_md2_1004bf90);
  piVar2[10] = iVar3;
  piVar2[0x40] = param_1;
  piVar2[0x7f] = (int)&LAB_1001c960;
  fVar1 = (float)(int)(8000 / (longlong)param_5) + DAT_1006c2e4;
  piVar2[0x7d] = (int)FUN_1001b400;
  piVar2[0x91] = param_4;
  piVar2[0x92] = param_7;
  piVar2[0x93] = param_6;
  piVar2[0x7b] = (int)fVar1;
  iVar3 = (*DAT_1006c1e4)(s_weapons_rockfly_wav_1004bf7c);
  piVar2[0x13] = iVar3;
  piVar2[0x46] = (int)s_rocket_1004bf74;
  if (*(int *)(param_1 + 0x54) != 0) {
    FUN_1001c1c0(param_1,(float *)(piVar2 + 1),param_3,param_5);
  }
  (*DAT_1006c208)(piVar2);
  return;
}



/* FUN_10007390 @ 10007390 size 346 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10007390(int param_1)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  
  piVar3 = FUN_1001b350();
  piVar3[0x7f] = (int)&LAB_10007340;
  piVar3[0x41] = 0;
  piVar3[0x3e] = 1;
  piVar3[0x97] = param_1;
  local_c = *(float *)(param_1 + 0xbc) + _DAT_100441b8;
  fVar1 = *(float *)(param_1 + 0xc0) + _DAT_100441b8;
  local_18 = *(float *)(param_1 + 200) - _DAT_100441b8;
  local_14 = *(float *)(param_1 + 0xcc) - _DAT_100441b8;
  local_10 = *(float *)(param_1 + 0xd0) + _DAT_10044164;
  fVar2 = local_10 -
          ((*(float *)(param_1 + 0x168) - *(float *)(param_1 + 0x174)) + (float)DAT_1006c298);
  if ((*(byte *)(param_1 + 0x11c) & 1) != 0) {
    local_10 = fVar2 + _DAT_10044164;
  }
  if (local_18 - local_c <= _DAT_1004410c) {
    local_c = (*(float *)(param_1 + 200) + *(float *)(param_1 + 0xbc)) * (float)_DAT_10044140;
    local_18 = local_c + _DAT_10044104;
  }
  if (local_14 - fVar1 <= _DAT_1004410c) {
    fVar1 = (*(float *)(param_1 + 0xcc) + *(float *)(param_1 + 0xc0)) * (float)_DAT_10044140;
    local_14 = fVar1 + _DAT_10044104;
  }
  piVar3[0x30] = (int)fVar1;
  piVar3[0x2f] = (int)local_c;
  piVar3[0x31] = (int)fVar2;
  piVar3[0x32] = (int)local_18;
  piVar3[0x33] = (int)local_14;
  piVar3[0x34] = (int)local_10;
  (*DAT_1006c208)(piVar3);
  return;
}



/* FUN_1002c400 @ 1002c400 size 345 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1002c400(int param_1)

{
  undefined *puVar1;
  float fVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 1;
  }
  if (*(float *)(param_1 + 0x210) <= DAT_1006c2e4) {
    uVar3 = *(uint *)(param_1 + 0x3c) | 1;
    *(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4;
    uVar4 = DAT_10061308;
    if ((uVar3 != 1) && (uVar4 = DAT_1006131c, uVar3 == 3)) {
      uVar4 = DAT_1006130c;
    }
    (*DAT_1006c1d0)(param_1,2,uVar4,0x3f800000,0x3f800000,0);
    if (_DAT_10044130 < *(float *)(param_1 + 0x180)) {
      *(undefined **)(param_1 + 0x358) = &DAT_1005b858;
      return;
    }
    if (*(int *)(DAT_1006c41c + 0x14) != 0x40400000) {
      uVar3 = _rand();
      fVar2 = (float)(uVar3 & 0x7fff) * _DAT_10044108;
      if (fVar2 < (float)_DAT_10044378) {
        *(undefined **)(param_1 + 0x358) = &DAT_1005b628;
        return;
      }
      if (fVar2 < (float)_DAT_10044370) {
        *(undefined **)(param_1 + 0x358) = &DAT_1005b690;
        return;
      }
      *(undefined **)(param_1 + 0x358) = &DAT_1005b778;
    }
  }
  else if ((_DAT_10044130 < *(float *)(param_1 + 0x180)) &&
          (((puVar1 = *(undefined **)(param_1 + 0x358), puVar1 == &DAT_1005b628 ||
            (puVar1 == &DAT_1005b690)) || (puVar1 == &DAT_1005b778)))) {
    *(undefined **)(param_1 + 0x358) = &DAT_1005b858;
    return;
  }
  return;
}



/* FUN_10032250 @ 10032250 size 342 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10032250(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  
  if (_DAT_1006c3a8 == _DAT_1004410c) {
    iVar1 = param_1[0x15];
    if (((*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) &&
        (*(int *)(iVar1 + 0x72c) != *(int *)(iVar1 + 0xdb8))) &&
       (_DAT_1004414c <= DAT_1006c2e4 - *(float *)(iVar1 + 0xf00))) {
      FUN_10030d60((int)param_1);
      return;
    }
    if ((*(int *)(iVar1 + 0xdf8) == 0) && (*(int *)(iVar1 + 0xdb8) == 0)) {
      FUN_10035830((int)param_1);
    }
    else {
      *(undefined4 *)(iVar1 + 0xdf8) = 0;
    }
    if (param_1[0x8b] == 0) {
      if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
        iVar3 = FUN_10033320();
        iVar3 = FUN_10001560((int)param_1,iVar3);
        if (iVar3 == 0) {
          FUN_10033170((float *)(param_1 + 7));
        }
      }
      *(undefined4 *)(iVar1 + 0xdf4) = 0;
    }
    else if (*(float *)(iVar1 + 0xf00) < DAT_1006c2e4) {
      if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = 1;
      }
      if ((*(uint *)(iVar1 + 0xdf4) & uVar2) != 0) {
LAB_1003234f:
        FUN_10030cd0(param_1);
        *(undefined4 *)(iVar1 + 0xdf4) = 0;
        return;
      }
      if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
        uVar4 = __ftol();
        if ((uVar4 & 0x400) != 0) goto LAB_1003234f;
      }
    }
  }
  return;
}



/* FUN_10039373 @ 10039373 size 340 */

void __cdecl FUN_10039373(int *param_1,undefined4 *param_2,uint param_3,undefined *param_4)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 local_fc [30];
  int local_84 [30];
  int *local_c;
  int local_8;
  
  if ((param_2 < (undefined4 *)0x2) || (param_3 == 0)) {
    return;
  }
  local_8 = 0;
  iVar4 = (int)param_2 + -1;
  param_2 = local_fc;
  piVar5 = (int *)(iVar4 * param_3 + (int)param_1);
  piVar3 = param_1;
  param_1 = local_84;
LAB_100393b2:
  uVar2 = (uint)((int)piVar5 - (int)piVar3) / param_3 + 1;
  if (8 < uVar2) {
    FUN_10039515((undefined1 *)((uVar2 >> 1) * param_3 + (int)piVar3),(undefined1 *)piVar3,param_3);
    piVar6 = (int *)(param_3 + (int)piVar5);
    local_c = piVar3;
LAB_10039409:
    local_c = (int *)((int)local_c + param_3);
    if (local_c <= piVar5) goto code_r0x10039416;
    goto LAB_10039421;
  }
  FUN_100394c7((undefined1 *)piVar3,(undefined1 *)piVar5,param_3,param_4);
  goto LAB_100393d1;
code_r0x10039416:
  iVar4 = (*(code *)param_4)(local_c,piVar3);
  if (iVar4 < 1) goto LAB_10039409;
LAB_10039421:
  do {
    piVar6 = (int *)((int)piVar6 - param_3);
    if (piVar6 <= piVar3) break;
    iVar4 = (*(code *)param_4)(piVar6,piVar3);
  } while (-1 < iVar4);
  if (local_c <= piVar6) {
    FUN_10039515((undefined1 *)local_c,(undefined1 *)piVar6,param_3);
    goto LAB_10039409;
  }
  FUN_10039515((undefined1 *)piVar3,(undefined1 *)piVar6,param_3);
  piVar1 = local_c;
  if ((int)((int)piVar6 + (-1 - (int)piVar3)) < (int)piVar5 - (int)local_c) {
    if (local_c < piVar5) {
      local_8 = local_8 + 1;
      *param_2 = local_c;
      *param_1 = (int)piVar5;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    if ((int *)(param_3 + (int)piVar3) < piVar6) {
      piVar5 = (int *)((int)piVar6 - param_3);
      goto LAB_100393b2;
    }
  }
  else {
    if ((int *)((int)piVar3 + param_3) < piVar6) {
      local_8 = local_8 + 1;
      *param_2 = piVar3;
      *param_1 = (int)piVar6 - param_3;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    piVar3 = piVar1;
    if (piVar1 < piVar5) goto LAB_100393b2;
  }
LAB_100393d1:
  local_8 = local_8 + -1;
  param_2 = param_2 + -1;
  param_1 = param_1 + -1;
  if (local_8 < 0) {
    return;
  }
  piVar5 = (int *)*param_1;
  piVar3 = (int *)*param_2;
  goto LAB_100393b2;
}



/* FUN_1000e7e0 @ 1000e7e0 size 339 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000e7e0(uint param_1,int param_2)

{
  byte *pbVar1;
  float fVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 uVar6;
  
  if (*(uint *)(param_2 + 0x1e0) == param_1) {
    pbVar1 = *(byte **)(param_1 + 0x128);
    if (pbVar1 == (byte *)0x0) {
      if (((*(byte *)(param_1 + 0x11c) & 1) != 0) && ((*(byte *)(param_2 + 0x108) & 3) == 0)) {
        fVar2 = DAT_1006c2e4 + _DAT_10044148;
        *(uint *)(param_2 + 0x35c) = *(uint *)(param_2 + 0x35c) | 1;
        *(float *)(param_2 + 0x390) = fVar2;
        (**(code **)(param_2 + 0x368))(param_2);
      }
    }
    else {
      *(byte **)(param_2 + 0x128) = pbVar1;
      uVar3 = FUN_1001ad80(pbVar1);
      *(uint *)(param_2 + 0x1e0) = uVar3;
      *(uint *)(param_2 + 0x1dc) = uVar3;
      if (uVar3 == 0) {
        uVar6 = *(undefined4 *)(param_1 + 0x128);
        puVar4 = FUN_1001b070();
        (*DAT_1006c1c4)(s__s_at__s_target__s_does_not_exis_10049228,*(undefined4 *)(param_1 + 0x118)
                        ,puVar4,uVar6);
        *(uint *)(param_2 + 0x1e0) = param_1;
      }
      *(undefined4 *)(param_1 + 0x128) = 0;
    }
    if (*(uint *)(param_2 + 0x1e0) == param_1) {
      *(undefined4 *)(param_2 + 0x128) = 0;
      *(undefined4 *)(param_2 + 0x1dc) = *(undefined4 *)(param_2 + 0x25c);
      *(undefined4 *)(param_2 + 0x1e0) = 0;
      *(uint *)(param_2 + 0x35c) = *(uint *)(param_2 + 0x35c) & 0xffffefff;
    }
    if (*(int *)(param_1 + 0x138) != 0) {
      uVar6 = *(undefined4 *)(param_1 + 0x128);
      *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x138);
      iVar5 = *(int *)(param_2 + 0x25c);
      if ((((iVar5 == 0) || (*(int *)(iVar5 + 0x54) == 0)) &&
          ((iVar5 = *(int *)(param_2 + 0x260), iVar5 == 0 || (*(int *)(iVar5 + 0x54) == 0)))) &&
         ((iVar5 = *(int *)(param_2 + 0x264), iVar5 == 0 || (*(int *)(iVar5 + 0x54) == 0)))) {
        iVar5 = param_2;
      }
      FUN_1001ae20(param_1,iVar5);
      *(undefined4 *)(param_1 + 0x128) = uVar6;
    }
  }
  return;
}



/* FUN_1003f7d2 @ 1003f7d2 size 339 */

void __cdecl FUN_1003f7d2(DWORD param_1)

{
  undefined4 *puVar1;
  DWORD *pDVar2;
  DWORD DVar3;
  size_t sVar4;
  HANDLE hFile;
  int iVar5;
  uint *_Dest;
  undefined1 auStackY_1e3 [7];
  LPCVOID lpBuffer;
  LPOVERLAPPED lpOverlapped;
  uint local_1a8 [65];
  uint local_a4 [40];
  
  iVar5 = 0;
  pDVar2 = &DAT_10060468;
  do {
    if (param_1 == *pDVar2) break;
    pDVar2 = pDVar2 + 2;
    iVar5 = iVar5 + 1;
  } while ((int)pDVar2 < 0x100604f8);
  if (param_1 == (&DAT_10060468)[iVar5 * 2]) {
    if ((DAT_10061c54 == 1) || ((DAT_10061c54 == 0 && (DAT_10061c58 == 1)))) {
      pDVar2 = &param_1;
      puVar1 = (undefined4 *)(iVar5 * 8 + 0x1006046c);
      lpOverlapped = (LPOVERLAPPED)0x0;
      sVar4 = _strlen((char *)*puVar1);
      lpBuffer = (LPCVOID)*puVar1;
      hFile = GetStdHandle(0xfffffff4);
      WriteFile(hFile,lpBuffer,sVar4,pDVar2,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_1a8,0x104);
      if (DVar3 == 0) {
        FUN_10040000(local_1a8,(uint *)"<program name unknown>");
      }
      _Dest = local_1a8;
      sVar4 = _strlen((char *)local_1a8);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen((char *)local_1a8);
        _Dest = (uint *)(auStackY_1e3 + sVar4);
        _strncpy((char *)_Dest,"...",3);
      }
      FUN_10040000(local_a4,(uint *)"Runtime Error!\n\nProgram: ");
      FUN_10040010(local_a4,_Dest);
      FUN_10040010(local_a4,(uint *)&DAT_10044948);
      FUN_10040010(local_a4,*(uint **)(iVar5 * 8 + 0x1006046c));
      auStackY_1e3._3_4_ = 0x1003f8f6;
      FUN_10042062(local_a4,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}



/* FUN_1000b4f0 @ 1000b4f0 size 337 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1000b4f0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (*(int *)(*(int *)(param_2 + 0x54) + 0x6e4) < 0xfa) {
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0x6e4) = 0xfa;
  }
  if (*(int *)(*(int *)(param_2 + 0x54) + 0x6e8) < 0x96) {
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0x6e8) = 0x96;
  }
  if (*(int *)(*(int *)(param_2 + 0x54) + 0x6f8) < 0xfa) {
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0x6f8) = 0xfa;
  }
  if (*(int *)(*(int *)(param_2 + 0x54) + 0x6fc) < 0x4b) {
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0x6fc) = 0x4b;
  }
  puVar4 = FUN_1000b150((byte *)s_Bullets_10048a60);
  if (puVar4 != (undefined4 *)0x0) {
    iVar3 = (int)(puVar4 + -0x4011a4a) / 0x48;
    piVar1 = (int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4);
    *piVar1 = *piVar1 + puVar4[0xc];
    iVar2 = *(int *)(param_2 + 0x54);
    if (*(int *)(iVar2 + 0x6e4) < *(int *)(iVar2 + 0x2e4 + iVar3 * 4)) {
      *(int *)(iVar2 + 0x2e4 + iVar3 * 4) = *(int *)(iVar2 + 0x6e4);
    }
  }
  puVar4 = FUN_1000b150((byte *)s_Shells_10048b88);
  if (puVar4 != (undefined4 *)0x0) {
    iVar3 = (int)(puVar4 + -0x4011a4a) / 0x48;
    piVar1 = (int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4);
    *piVar1 = *piVar1 + puVar4[0xc];
    iVar2 = *(int *)(param_2 + 0x54);
    if (*(int *)(iVar2 + 0x6e8) < *(int *)(iVar2 + 0x2e4 + iVar3 * 4)) {
      *(int *)(iVar2 + 0x2e4 + iVar3 * 4) = *(int *)(iVar2 + 0x6e8);
    }
  }
  if (((*(uint *)(param_1 + 0x11c) & 0x10000) == 0) &&
     (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c)) {
    FUN_1000b210(param_1,(float)*(int *)(*(int *)(param_1 + 0x2cc) + 0x30));
  }
  return 1;
}



/* FUN_10018d10 @ 10018d10 size 334 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10018d10(int param_1)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  if (*(float *)(param_1 + 0x21c) < DAT_1006c2e4) {
    (*DAT_1006c1d4)(param_1 + 4,param_1,0,*(undefined4 *)(param_1 + 0x280),0x3f800000,0,0);
    *(float *)(param_1 + 0x21c) = DAT_1006c2e4 + (float)_DAT_10044140;
  }
  iVar3 = 1;
  if (1 < DAT_1006c168) {
    piVar4 = (int *)(DAT_1006c2c4 + 0x638);
    do {
      if (((piVar4[-0x84] != 0) && (piVar4[-0x85] != 0)) && (*piVar4 != 0)) {
        *piVar4 = 0;
        uVar2 = _rand();
        fVar1 = (float)(uVar2 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
        piVar4[-0x3c] = (int)((fVar1 + fVar1) * (float)_DAT_100442a0 + (float)piVar4[-0x3c]);
        uVar2 = _rand();
        fVar1 = (float)(uVar2 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
        piVar4[-0x3b] = (int)((fVar1 + fVar1) * (float)_DAT_100442a0 + (float)piVar4[-0x3b]);
        piVar4[-0x3a] =
             (int)(((float)_DAT_100441e0 / (float)piVar4[-0x36]) * *(float *)(param_1 + 0x148));
      }
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 0xf4;
    } while (iVar3 < DAT_1006c168);
  }
  if (DAT_1006c2e4 < *(float *)(param_1 + 0x120)) {
    *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  }
  return;
}



/* FUN_10038700 @ 10038700 size 329 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10038700(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float10 fVar1;
  
  fVar1 = (float10)fsin((float10)param_1[1] * (float10)_DAT_100442b8);
  _DAT_10061bf4 = (float)fVar1;
  fVar1 = (float10)fcos((float10)param_1[1] * (float10)_DAT_100442b8);
  _DAT_10061be8 = (float)fVar1;
  fVar1 = (float10)fsin((float10)*param_1 * (float10)_DAT_100442b8);
  _DAT_100613d8 = (float)fVar1;
  fVar1 = (float10)fcos((float10)*param_1 * (float10)_DAT_100442b8);
  _DAT_10061bec = (float)fVar1;
  fVar1 = (float10)fsin((float10)param_1[2] * (float10)_DAT_100442b8);
  _DAT_100613d0 = (float)fVar1;
  fVar1 = (float10)fcos((float10)param_1[2] * (float10)_DAT_100442b8);
  _DAT_100613d4 = (float)fVar1;
  if (param_2 != (float *)0x0) {
    *param_2 = _DAT_10061bec * _DAT_10061be8;
    param_2[1] = _DAT_10061bec * _DAT_10061bf4;
    param_2[2] = -_DAT_100613d8;
  }
  if (param_3 != (float *)0x0) {
    *param_3 = _DAT_100613d4 * _DAT_10061bf4 - _DAT_100613d0 * _DAT_100613d8 * _DAT_10061be8;
    param_3[1] = (_DAT_100613d4 * _DAT_10061be8 + _DAT_100613d0 * _DAT_100613d8 * _DAT_10061bf4) *
                 _DAT_100441bc;
    param_3[2] = _DAT_100613d0 * _DAT_10061bec * _DAT_100441bc;
  }
  if (param_4 != (float *)0x0) {
    *param_4 = _DAT_100613d0 * _DAT_10061bf4 + _DAT_100613d4 * _DAT_100613d8 * _DAT_10061be8;
    param_4[1] = _DAT_100613d4 * _DAT_100613d8 * _DAT_10061bf4 - _DAT_100613d0 * _DAT_10061be8;
    param_4[2] = _DAT_100613d4 * _DAT_10061bec;
  }
  return;
}



/* FUN_10001730 @ 10001730 size 323 */

undefined4 __cdecl FUN_10001730(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  float10 fVar5;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  uVar3 = 0;
  local_10 = 999999.0;
  iVar2 = DAT_1006c168;
  uVar4 = DAT_1006c2c4;
  if (DAT_1006c2c4 < DAT_1006c168 * 0x3d0 + DAT_1006c2c4) {
    do {
      if (((((*(uint *)(uVar4 + 0xb8) & 4) != 0) && ((*(uint *)(uVar4 + 0xb8) & 2) == 0)) &&
          (*(int *)(uVar4 + 0x22c) != 1)) &&
         (((*(int *)(uVar4 + 0x22c) != 2 && ((*(uint *)(uVar4 + 0x35c) & 0x100) == 0)) &&
          (iVar1 = FUN_10001560(param_1,uVar4), iVar2 = DAT_1006c168, iVar1 != 0)))) {
        local_c = *(float *)(uVar4 + 4) - *(float *)(param_1 + 4);
        local_8 = *(float *)(uVar4 + 8) - *(float *)(param_1 + 8);
        local_4 = *(float *)(uVar4 + 0xc) - *(float *)(param_1 + 0xc);
        fVar5 = FUN_100389f0(&local_c);
        iVar2 = DAT_1006c168;
        if (fVar5 < (float10)local_10) {
          local_10 = (float)fVar5;
          uVar3 = uVar4;
        }
      }
      uVar4 = uVar4 + 0x3d0;
    } while (uVar4 < iVar2 * 0x3d0 + DAT_1006c2c4);
    if (uVar3 != 0) {
      *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) & 0xf7ffffff;
      local_c = *(float *)(uVar3 + 4) - *(float *)(param_1 + 4);
      local_8 = *(float *)(uVar3 + 8) - *(float *)(param_1 + 8);
      local_4 = *(float *)(uVar3 + 0xc) - *(float *)(param_1 + 0xc);
      fVar5 = FUN_1001b160(&local_c);
      *(float *)(param_1 + 0x1e8) = (float)fVar5;
      FUN_1002a850(param_1);
      *(uint *)(param_1 + 0x25c) = uVar3;
      FUN_10001690(param_1);
      return 1;
    }
  }
  return 0;
}



/* FUN_1000b270 @ 1000b270 size 322 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1000b270(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  piVar1 = (int *)(*(int *)(param_2 + 0x54) + 0x2e4 +
                  ((*(int *)(param_1 + 0x2cc) + -0x10046928) / 0x48) * 4);
  iVar2 = *piVar1;
  if (((*(int *)(DAT_1006c41c + 0x14) != 0x3f800000) || (iVar2 < 2)) &&
     ((*(float *)(DAT_1006c41c + 0x14) < _DAT_1004413c || (iVar2 < 1)))) {
    if (((*(float *)(DAT_1006c42c + 0x14) != _DAT_1004410c) &&
        ((*(byte *)(*(int *)(param_1 + 0x2cc) + 0x38) & 8) != 0)) && (0 < iVar2)) {
      return 0;
    }
    *piVar1 = iVar2 + 1;
    if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
      if ((*(uint *)(param_1 + 0x11c) & 0x10000) == 0) {
        FUN_1000b210(param_1,(float)*(int *)(*(int *)(param_1 + 0x2cc) + 0x30));
      }
      uVar3 = __ftol();
      if (((uVar3 & 0x10) != 0) ||
         ((*(undefined1 **)(*(int *)(param_1 + 0x2cc) + 8) == &LAB_1000b990 &&
          ((*(uint *)(param_1 + 0x11c) & 0x20000) != 0)))) {
        if ((*(undefined1 **)(*(int *)(param_1 + 0x2cc) + 8) == &LAB_1000b990) &&
           ((*(uint *)(param_1 + 0x11c) & 0x20000) != 0)) {
          lVar4 = __ftol();
          DAT_10060e68 = (undefined4)lVar4;
        }
        (**(code **)(*(int *)(param_1 + 0x2cc) + 8))(param_2,*(int *)(param_1 + 0x2cc));
      }
    }
    return 1;
  }
  return 0;
}



/* FUN_10011240 @ 10011240 size 321 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10011240(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  
  iVar5 = param_2;
  if (*(int *)(param_2 + 0x54) != 0) {
    uVar6 = FUN_1001ac00(0,300,*(byte **)(param_1 + 0x128));
    if (uVar6 == 0) {
      (*DAT_1006c1c4)(s_Couldn_t_find_destination_1004961c);
      return;
    }
    (*DAT_1006c20c)(param_2);
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(uVar6 + 4);
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(uVar6 + 8);
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(uVar6 + 0xc);
    fVar4 = *(float *)(param_2 + 0xc) + _DAT_100441b0;
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(uVar6 + 4);
    *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(uVar6 + 8);
    uVar2 = *(undefined4 *)(uVar6 + 0xc);
    *(float *)(param_2 + 0xc) = fVar4;
    *(undefined4 *)(param_2 + 0x24) = uVar2;
    *(undefined4 *)(param_2 + 0x180) = 0;
    *(undefined4 *)(param_2 + 0x17c) = 0;
    *(undefined4 *)(param_2 + 0x178) = 0;
    *(undefined1 *)(*(int *)(param_2 + 0x54) + 0x11) = 0x14;
    piVar1 = (int *)(param_2 + 0x54);
    param_2 = 0x14;
    *(byte *)(*piVar1 + 0x10) = *(byte *)(*piVar1 + 0x10) | 0x20;
    iVar7 = 0xdac;
    *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x50) = 6;
    *(undefined4 *)(iVar5 + 0x50) = 6;
    do {
      iVar3 = *(int *)(iVar5 + 0x54);
      lVar8 = __ftol();
      iVar7 = iVar7 + 4;
      *(short *)(param_2 + iVar3) = (short)lVar8;
      param_2 = param_2 + 2;
    } while (iVar7 < 0xdb8);
    *(undefined4 *)(iVar5 + 0x18) = 0;
    *(undefined4 *)(iVar5 + 0x14) = 0;
    *(undefined4 *)(iVar5 + 0x10) = 0;
    *(undefined4 *)(*(int *)(iVar5 + 0x54) + 0x24) = 0;
    *(undefined4 *)(*(int *)(iVar5 + 0x54) + 0x20) = 0;
    *(undefined4 *)(*(int *)(iVar5 + 0x54) + 0x1c) = 0;
    *(undefined4 *)(*(int *)(iVar5 + 0x54) + 0xe6c) = 0;
    *(undefined4 *)(*(int *)(iVar5 + 0x54) + 0xe68) = 0;
    *(undefined4 *)(*(int *)(iVar5 + 0x54) + 0xe64) = 0;
    FUN_1001b510(iVar5);
    (*DAT_1006c208)(iVar5);
  }
  return;
}



/* FUN_10006f10 @ 10006f10 size 320 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10006f10(int param_1)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  if (*(float *)(param_1 + 0x70) < *(float *)(param_1 + 0x6c)) {
    if ((*(float *)(param_1 + 0x60) == *(float *)(param_1 + 100)) &&
       (*(float *)(param_1 + 0x6c) - *(float *)(param_1 + 0x60) < *(float *)(param_1 + 0x70))) {
      fVar2 = *(float *)(param_1 + 0x6c) - *(float *)(param_1 + 0x70);
      *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 100);
      fVar3 = ((float)_DAT_10044120 - fVar2 / *(float *)(param_1 + 100)) * *(float *)(param_1 + 100)
      ;
      *(float *)(param_1 + 0x68) =
           *(float *)(param_1 + 100) - (fVar3 / (fVar3 + fVar2)) * *(float *)(param_1 + 0x44);
      return;
    }
    if (*(float *)(param_1 + 0x60) < *(float *)(param_1 + 0x40)) {
      fVar3 = *(float *)(param_1 + 0x3c) + *(float *)(param_1 + 0x60);
      fVar2 = *(float *)(param_1 + 0x60);
      *(float *)(param_1 + 0x60) = fVar3;
      if (*(float *)(param_1 + 0x40) < fVar3) {
        *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0x40);
      }
      if (*(float *)(param_1 + 0x6c) - *(float *)(param_1 + 0x60) < *(float *)(param_1 + 0x70)) {
        fVar3 = *(float *)(param_1 + 0x6c) - *(float *)(param_1 + 0x70);
        fVar5 = (fVar2 + *(float *)(param_1 + 100)) * (float)_DAT_10044140;
        fVar4 = ((float)_DAT_10044120 - fVar3 / fVar5) * *(float *)(param_1 + 100);
        fVar2 = fVar4 + fVar3;
        fVar4 = fVar4 / fVar2;
        *(float *)(param_1 + 0x60) = fVar4 * *(float *)(param_1 + 100) + (fVar3 / fVar2) * fVar5;
        *(float *)(param_1 + 0x68) = *(float *)(param_1 + 100) - fVar4 * *(float *)(param_1 + 0x44);
      }
    }
  }
  else if (*(float *)(param_1 + 0x6c) < *(float *)(param_1 + 0x70)) {
    if (*(float *)(param_1 + 0x68) != _DAT_1004410c) {
      uVar1 = *(undefined4 *)(param_1 + 0x68);
      *(undefined4 *)(param_1 + 0x68) = 0;
      *(undefined4 *)(param_1 + 0x60) = uVar1;
      return;
    }
    if (*(float *)(param_1 + 0x44) < *(float *)(param_1 + 0x60)) {
      *(float *)(param_1 + 0x60) = *(float *)(param_1 + 0x60) - *(float *)(param_1 + 0x44);
      return;
    }
  }
  return;
}



/* FUN_1003d8d8 @ 1003d8d8 size 320 */

void __cdecl
FUN_1003d8d8(int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10,int param_11)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 1) {
    if ((param_3 & 3) == 0) {
      iVar1 = *(int *)(&DAT_1006072c + param_4 * 4);
    }
    else {
      iVar1 = *(int *)(&DAT_10060760 + param_4 * 4);
    }
    iVar2 = (int)(param_3 * 0x16d + -0x63db + iVar1 + 1 + ((int)(param_3 - 1) >> 2)) % 7;
    if (iVar2 < param_6) {
      iVar1 = iVar1 + -6 + (param_5 * 7 - iVar2) + param_6;
    }
    else {
      iVar1 = iVar1 + 1 + (param_5 * 7 - iVar2) + param_6;
    }
    if (param_5 == 5) {
      if ((param_3 & 3) == 0) {
        iVar2 = *(int *)(&DAT_10060730 + param_4 * 4);
      }
      else {
        iVar2 = *(int *)(&DAT_10060764 + param_4 * 4);
      }
      if (iVar2 < iVar1) {
        iVar1 = iVar1 + -7;
      }
    }
  }
  else {
    if ((param_3 & 3) == 0) {
      iVar1 = *(int *)(&DAT_1006072c + param_4 * 4);
    }
    else {
      iVar1 = *(int *)(&DAT_10060760 + param_4 * 4);
    }
    iVar1 = iVar1 + param_7;
  }
  if (param_1 == 1) {
    DAT_10060060 = param_3;
    DAT_10060068 = ((param_8 * 0x3c + param_9) * 0x3c + param_10) * 1000 + param_11;
    DAT_10060064 = iVar1;
  }
  else {
    DAT_10060078 = ((param_8 * 0x3c + param_9) * 0x3c + DAT_1005ffd0 + param_10) * 1000 + param_11;
    if (DAT_10060078 < 0) {
      DAT_10060078 = DAT_10060078 + 86400000;
      DAT_10060074 = iVar1 + -1;
    }
    else {
      DAT_10060074 = iVar1;
      if (86399999 < DAT_10060078) {
        DAT_10060078 = DAT_10060078 + -86400000;
        DAT_10060074 = iVar1 + 1;
      }
    }
    DAT_10060070 = param_3;
  }
  return;
}



/* FUN_10004870 @ 10004870 size 319 */

void __cdecl FUN_10004870(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iStack_48;
  int iStack_44;
  byte abStack_40 [64];
  
  iVar1 = param_1;
  iVar2 = (*DAT_1006c25c)();
  iStack_44 = 0;
  iStack_48 = 1;
  if (1 < iVar2) {
    do {
      FUN_10004750((char *)abStack_40,&iStack_48,iVar2);
      puVar3 = FUN_1000b150(abStack_40);
      if (((puVar3 != (undefined4 *)0x0) && (puVar3[2] != 0)) &&
         (*(undefined4 **)(*(int *)(param_1 + 0x54) + 0x714) == puVar3)) {
        iStack_44 = iStack_48;
        break;
      }
      iStack_48 = iStack_48 + 1;
    } while (iStack_48 < iVar2);
  }
  param_1 = 1;
  iStack_48 = iStack_44;
  if (1 < iVar2) {
    do {
      iStack_48 = iStack_48 + 1;
      if (iStack_48 == iVar2) {
        if (iStack_44 == 0) {
          return;
        }
        iStack_48 = 1;
      }
      FUN_10004750((char *)abStack_40,&iStack_48,iVar2);
      puVar3 = FUN_1000b150(abStack_40);
      if ((puVar3 != (undefined4 *)0x0) && ((code *)puVar3[2] != (code *)0x0)) {
        if (*(int *)(*(int *)(iVar1 + 0x54) + 0x2e4 + ((int)(puVar3 + -0x4011a4a) / 0x48) * 4) == 0)
        {
          (*DAT_1006c1c8)(iVar1,2,s_Out_of_item___s_100462b0,abStack_40);
        }
        else {
          (*(code *)puVar3[2])(iVar1,puVar3);
        }
        if (*(undefined4 **)(*(int *)(iVar1 + 0x54) + 0xdfc) == puVar3) {
          return;
        }
      }
      param_1 = param_1 + 1;
    } while (param_1 < iVar2);
  }
  return;
}



/* FUN_100405a3 @ 100405a3 size 318 */

BOOL __cdecl
FUN_100405a3(DWORD param_1,LPCSTR param_2,int param_3,LPWORD param_4,UINT param_5,LCID param_6,
            int param_7)

{
  undefined1 *puVar1;
  BOOL BVar2;
  int iVar3;
  WORD local_20 [2];
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_10044990;
  puStack_10 = &LAB_10042634;
  local_14 = ExceptionList;
  local_1c = &stack0xffffffc8;
  iVar3 = DAT_10061f2c;
  ExceptionList = &local_14;
  puVar1 = &stack0xffffffc8;
  if (DAT_10061f2c == 0) {
    ExceptionList = &local_14;
    BVar2 = GetStringTypeW(1,L"",1,local_20);
    iVar3 = 1;
    puVar1 = local_1c;
    if (BVar2 == 0) {
      BVar2 = GetStringTypeA(0,1,"",1,local_20);
      if (BVar2 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      iVar3 = 2;
      puVar1 = local_1c;
    }
  }
  local_1c = puVar1;
  DAT_10061f2c = iVar3;
  if (DAT_10061f2c != 2) {
    if (DAT_10061f2c == 1) {
      if (param_5 == 0) {
        param_5 = DAT_10061dc8;
      }
      iVar3 = MultiByteToWideChar(param_5,(-(uint)(param_7 != 0) & 8) + 1,param_2,param_3,
                                  (LPWSTR)0x0,0);
      if (iVar3 != 0) {
        local_8 = 0;
        FUN_10039f80();
        local_1c = &stack0xffffffc8;
        _memset(&stack0xffffffc8,0,iVar3 * 2);
        local_8 = 0xffffffff;
        if ((&stack0x00000000 != (undefined1 *)0x38) &&
           (iVar3 = MultiByteToWideChar(param_5,1,param_2,param_3,(LPWSTR)&stack0xffffffc8,iVar3),
           iVar3 != 0)) {
          BVar2 = GetStringTypeW(param_1,(LPCWSTR)&stack0xffffffc8,iVar3,param_4);
          ExceptionList = local_14;
          return BVar2;
        }
      }
    }
    ExceptionList = local_14;
    return 0;
  }
  if (param_6 == 0) {
    param_6 = DAT_10061db8;
  }
  BVar2 = GetStringTypeA(param_6,param_1,param_2,param_3,param_4);
  ExceptionList = local_14;
  return BVar2;
}



/* FUN_10009200 @ 10009200 size 317 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10009200(uint param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  char *pcVar5;
  bool bVar6;
  
  if (*(int *)(param_1 + 0x330) != 2) {
    if (*(int *)(param_1 + 0x330) == 0) {
      if (_DAT_1004410c <= *(float *)(param_1 + 0x32c)) {
        *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + *(float *)(param_1 + 0x32c);
        return;
      }
    }
    else {
      if ((*(uint *)(param_1 + 0x108) & 0x400) == 0) {
        if (*(int *)(param_1 + 0x310) != 0) {
          (*DAT_1006c1d0)(param_1,10,*(int *)(param_1 + 0x310),0x3f800000,0x40400000,0);
        }
        *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x314);
      }
      pbVar4 = *(byte **)(param_1 + 0x118);
      *(undefined4 *)(param_1 + 0x330) = 2;
      pcVar5 = s_func_door_100466cc;
      pbVar2 = pbVar4;
      do {
        bVar1 = *pbVar2;
        bVar6 = bVar1 < (byte)*pcVar5;
        if (bVar1 != *pcVar5) {
LAB_100092bc:
          iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_100092c1;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar2[1];
        bVar6 = bVar1 < (byte)pcVar5[1];
        if (bVar1 != pcVar5[1]) goto LAB_100092bc;
        pbVar2 = pbVar2 + 2;
        pcVar5 = pcVar5 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_100092c1:
      if (iVar3 == 0) {
        FUN_10006b20(param_1,(float *)(param_1 + 0x2f8),FUN_10009010);
      }
      else {
        pcVar5 = s_func_door_rotating_100466b8;
        do {
          bVar1 = *pbVar4;
          bVar6 = bVar1 < (byte)*pcVar5;
          if (bVar1 != *pcVar5) {
LAB_1000930b:
            iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
            goto LAB_10009310;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar6 = bVar1 < (byte)pcVar5[1];
          if (bVar1 != pcVar5[1]) goto LAB_1000930b;
          pbVar4 = pbVar4 + 2;
          pcVar5 = pcVar5 + 2;
        } while (bVar1 != 0);
        iVar3 = 0;
LAB_10009310:
        if (iVar3 == 0) {
          FUN_10006df0(param_1,FUN_10009010);
        }
      }
      FUN_1001ae20(param_1,param_2);
      FUN_10008f90(param_1,1);
    }
  }
  return;
}



/* FUN_10018bd0 @ 10018bd0 size 316 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10018bd0(undefined4 *param_1)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  undefined *puVar4;
  int iVar5;
  char *pcVar6;
  undefined4 *puVar7;
  
  pcVar3 = (char *)param_1[0x45];
  if (pcVar3 != (char *)0x0) {
    iVar5 = -1;
    pcVar6 = pcVar3;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    if ((((iVar5 == -4) && (cVar1 = *pcVar3, '`' < cVar1)) && (cVar1 < '{')) &&
       (((cVar2 = pcVar3[1], '`' < cVar2 && (cVar2 < '{')) && (cVar1 != cVar2)))) {
      if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
        FUN_1001b400(param_1);
        return;
      }
      if (param_1[0x4a] == 0) {
        puVar7 = param_1 + 1;
        puVar4 = FUN_1001b070();
        (*DAT_1006c1c4)(s__s_with_no_target_at__s_10049600,param_1[0x46],puVar4,puVar7);
        FUN_1001b400(param_1);
        return;
      }
      param_1[0x80] = FUN_10018ab0;
      param_1[0x7d] = FUN_100189e0;
      param_1[0x2e] = param_1[0x2e] | 1;
      param_1[0x55] = (float)(*pcVar3 + -0x61);
      cVar1 = pcVar3[1];
      param_1[0x56] = (float)(cVar1 + -0x61);
      param_1[0x57] =
           ((float)(cVar1 + -0x61) - (float)param_1[0x55]) /
           ((float)param_1[0x52] * (float)_DAT_10044170);
      return;
    }
  }
  puVar7 = param_1 + 1;
  puVar4 = FUN_1001b070();
  (*DAT_1006c1c4)(s_target_lightramp_has_bad_ramp____1004ba90,param_1[0x45],puVar4,puVar7);
  FUN_1001b400(param_1);
  return;
}



/* FUN_1001ed70 @ 1001ed70 size 315 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1001ed70(int param_1,int *param_2)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar2 = FUN_1001b350();
  piVar2[1] = *param_2;
  piVar2[2] = param_2[1];
  piVar2[3] = param_2[2];
  piVar2[0x2f] = -0x3e800000;
  piVar2[0x30] = -0x3e800000;
  piVar2[0x31] = -0x3e800000;
  piVar2[0x60] = 0;
  piVar2[0x5f] = 0;
  piVar2[0x5e] = 0;
  piVar2[99] = 0;
  piVar2[0x61] = 0;
  piVar2[0x62] = 0x42b40000;
  piVar2[6] = 0;
  piVar2[5] = 0;
  piVar2[4] = 0;
  piVar2[0x41] = 6;
  piVar2[0x3e] = 2;
  piVar2[0x90] = 0;
  piVar2[0x32] = 0x41800000;
  piVar2[0x33] = 0x41800000;
  piVar2[0x34] = 0x41800000;
  iVar3 = (*DAT_1006c1e0)(s_models_objects_dod_tris_md2_1004c138);
  piVar2[10] = iVar3;
  piVar2[0xe] = 0;
  piVar2[0x11] = 8;
  piVar2[0x40] = param_1;
  fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
  piVar2[0x7d] = (int)&LAB_1001ecc0;
  piVar2[0x91] = 0x32;
  piVar2[0x7b] = (int)fVar1;
  piVar2[0x93] = 0x42800000;
  piVar2[0x46] = (int)&DAT_1004c128;
  uVar4 = (*DAT_1006c1e4)(s_dod_dod_wav_1004c12c,0x3f800000,0x3f800000,0);
  (*DAT_1006c1d0)(param_1,2,uVar4);
  (*DAT_1006c208)(piVar2);
  if (*(int *)(param_1 + 0x54) != 0) {
    *(undefined1 **)(*(int *)(param_1 + 0x54) + 0xf10) = &LAB_1001eca0;
  }
  return;
}



/* FUN_100431d0 @ 100431d0 size 312 */

int * __cdecl FUN_100431d0(int *param_1,uint *param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  
  if (param_1 == (int *)0x0) {
    piVar1 = _malloc((size_t)param_2);
  }
  else {
    if (param_2 == (uint *)0x0) {
      FUN_100396e7(param_1);
    }
    else {
      do {
        if (param_2 < (uint *)0xffffffe1) {
          FUN_1003c8a1(9);
          puVar2 = (uint *)FUN_1003c955((int)param_1);
          if (puVar2 == (uint *)0x0) {
            FUN_1003c902(9);
            if (param_2 == (uint *)0x0) {
              param_2 = (uint *)0x1;
            }
            param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
            piVar1 = HeapReAlloc(DAT_1006ddfc,0,param_1,(SIZE_T)param_2);
          }
          else {
            if (DAT_1005ffc4 < param_2) {
LAB_1004326f:
              if (param_2 == (uint *)0x0) {
                param_2 = (uint *)0x1;
              }
              param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
              piVar1 = HeapAlloc(DAT_1006ddfc,0,(SIZE_T)param_2);
              if (piVar1 != (int *)0x0) {
                puVar4 = (uint *)(param_1[-1] - 1U);
                if (param_2 <= (uint *)(param_1[-1] - 1U)) {
                  puVar4 = param_2;
                }
                FUN_1003e070(piVar1,param_1,(uint)puVar4);
                FUN_1003c980(puVar2,(uint)param_1);
              }
            }
            else {
              iVar3 = FUN_1003d160(puVar2,(int)param_1,(int)param_2);
              piVar1 = param_1;
              if (iVar3 == 0) {
                piVar1 = FUN_1003ccab(param_2);
                if (piVar1 == (int *)0x0) goto LAB_1004326f;
                puVar4 = (uint *)(param_1[-1] - 1U);
                if (param_2 <= (uint *)(param_1[-1] - 1U)) {
                  puVar4 = param_2;
                }
                FUN_1003e070(piVar1,param_1,(uint)puVar4);
                FUN_1003c980(puVar2,(uint)param_1);
              }
              if (piVar1 == (int *)0x0) goto LAB_1004326f;
            }
            FUN_1003c902(9);
          }
          if (piVar1 != (int *)0x0) {
            return piVar1;
          }
        }
        if (DAT_10061fc4 == 0) {
          return (int *)0x0;
        }
        iVar3 = FUN_1004251f(param_2);
      } while (iVar3 != 0);
    }
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



/* FUN_10014610 @ 10014610 size 311 */

void __cdecl FUN_10014610(int param_1)

{
  int *piVar1;
  int iVar2;
  float local_24 [3];
  float local_18 [3];
  float local_c [3];
  
  if (*(int *)(param_1 + 0x254) < 1) {
    FUN_100144c0(param_1);
    return;
  }
  *(int *)(param_1 + 0x254) = *(int *)(param_1 + 0x254) + -1;
  piVar1 = (int *)(*(int *)(*(int *)(param_1 + 0x100) + 0x54) + 0x2e4 +
                  ((*(int *)(param_1 + 0x2cc) + -0x10046928) / 0x48) * 4);
  *piVar1 = *piVar1 + -1;
  FUN_10038700((float *)(param_1 + 0x10),local_24,local_c,(float *)0x0);
  FUN_1001aba0((float *)(param_1 + 4),(float *)(&DAT_10049884 + *(int *)(param_1 + 0x38) * 0xc),
               local_24,local_c,local_18);
  FUN_1001b880(param_1,local_18,local_24,10,0,300,500,0x29);
  iVar2 = *(int *)(param_1 + 0x38) + 1;
  *(int *)(param_1 + 0x38) = iVar2;
  if (0xf < iVar2) {
    *(undefined4 *)(param_1 + 0x38) = 7;
  }
  (*DAT_1006c224)(1);
  (*DAT_1006c228)((param_1 - DAT_1006c2c4) / 0x3d0);
  (*DAT_1006c224)(1);
  (*DAT_1006c218)((float *)(param_1 + 4),2);
  FUN_100350a0(*(int *)(param_1 + 0x100),local_18,1);
  return;
}



/* FUN_100236f0 @ 100236f0 size 309 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100236f0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  param_1[0x10] = 0;
  param_1[0xf2] = 0;
  if (DAT_1006c104 == 0x23) {
    FUN_1000e460(param_1);
    return;
  }
  if ((int)param_1[0x88] <= (int)param_1[0x8a]) {
    uVar1 = (*DAT_1006c1e4)(s_misc_udeath_wav_100493f8,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_1,2,uVar1);
    iVar3 = 2;
    do {
      FUN_1000dd30((float)param_1,s_models_objects_gibs_bone_tris_md_1004b5a4,param_4,0);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar3 = 4;
    do {
      FUN_1000dd30((float)param_1,s_models_objects_gibs_sm_meat_tris_100493d0,param_4,0);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    FUN_1000df70((float)param_1,s_models_objects_gibs_head2_tris_m_100491d4,param_4,0);
    param_1[0x8b] = 2;
    return;
  }
  if (param_1[0x8b] != 2) {
    (*DAT_1006c1d0)(param_1,2,DAT_100610c4,0x3f800000,0x3f800000,0);
    param_1[0x8b] = 2;
    param_1[0x90] = 1;
    uVar2 = _rand();
    if ((float)(uVar2 & 0x7fff) * _DAT_10044108 <= (float)_DAT_10044140) {
      param_1[0xd6] = &DAT_10050540;
      return;
    }
    param_1[0xd6] = &DAT_10050458;
  }
  return;
}



/* FUN_1002e090 @ 1002e090 size 307 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1002e090(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  if (*(float *)(param_1 + 0x210) <= DAT_1006c2e4) {
    if ((param_4 < 0x1a) &&
       (uVar1 = _rand(), (float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044198)) {
      return;
    }
    if ((((*(float *)(DAT_1006c41c + 0x14) < _DAT_1004413c) || (*(int *)(param_1 + 0x38) < 0x14)) ||
        (0x21 < *(int *)(param_1 + 0x38))) &&
       (*(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4,
       *(int *)(DAT_1006c41c + 0x14) != 0x40400000)) {
      if (param_4 < 0xb) {
        (*DAT_1006c1d0)(param_1,2,DAT_10061364,0x3f800000,0x3f800000,0);
        *(undefined **)(param_1 + 0x358) = &DAT_1005d780;
        return;
      }
      if (param_4 < 0x1a) {
        (*DAT_1006c1d0)(param_1,2,DAT_1006135c);
        *(undefined **)(param_1 + 0x358) = &DAT_1005d740;
        return;
      }
      (*DAT_1006c1d0)(param_1,2,DAT_10061358,0x3f800000,0x3f800000,0);
      *(undefined **)(param_1 + 0x358) = &DAT_1005d700;
    }
  }
  return;
}



/* FUN_1003f661 @ 1003f661 size 306 */

LPSTR FUN_1003f661(void)

{
  char cVar1;
  WCHAR WVar2;
  WCHAR *pWVar3;
  WCHAR *pWVar4;
  int iVar5;
  size_t _Size;
  LPSTR pCVar6;
  char *pcVar7;
  LPWCH lpWideCharStr;
  LPCH pCVar9;
  LPSTR local_8;
  char *pcVar8;
  
  lpWideCharStr = (LPWCH)0x0;
  pCVar9 = (LPCH)0x0;
  if (DAT_10061f24 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr != (LPWCH)0x0) {
      DAT_10061f24 = 1;
LAB_1003f6b8:
      if ((lpWideCharStr == (LPWCH)0x0) &&
         (lpWideCharStr = GetEnvironmentStringsW(), lpWideCharStr == (LPWCH)0x0)) {
        return (LPSTR)0x0;
      }
      WVar2 = *lpWideCharStr;
      pWVar4 = lpWideCharStr;
      while (WVar2 != L'\0') {
        do {
          pWVar3 = pWVar4;
          pWVar4 = pWVar3 + 1;
        } while (*pWVar4 != L'\0');
        pWVar4 = pWVar3 + 2;
        WVar2 = *pWVar4;
      }
      iVar5 = ((int)pWVar4 - (int)lpWideCharStr >> 1) + 1;
      _Size = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
      local_8 = (LPSTR)0x0;
      if (((_Size != 0) && (pCVar6 = _malloc(_Size), pCVar6 != (LPSTR)0x0)) &&
         (iVar5 = WideCharToMultiByte(0,0,lpWideCharStr,iVar5,pCVar6,_Size,(LPCSTR)0x0,(LPBOOL)0x0),
         local_8 = pCVar6, iVar5 == 0)) {
        FUN_100396e7(pCVar6);
        local_8 = (LPSTR)0x0;
      }
      FreeEnvironmentStringsW(lpWideCharStr);
      return local_8;
    }
    pCVar9 = GetEnvironmentStrings();
    if (pCVar9 == (LPCH)0x0) {
      return (LPSTR)0x0;
    }
    DAT_10061f24 = 2;
  }
  else {
    if (DAT_10061f24 == 1) goto LAB_1003f6b8;
    if (DAT_10061f24 != 2) {
      return (LPSTR)0x0;
    }
  }
  if ((pCVar9 == (LPCH)0x0) && (pCVar9 = GetEnvironmentStrings(), pCVar9 == (LPCH)0x0)) {
    return (LPSTR)0x0;
  }
  cVar1 = *pCVar9;
  pcVar7 = pCVar9;
  while (cVar1 != '\0') {
    do {
      pcVar8 = pcVar7;
      pcVar7 = pcVar8 + 1;
    } while (*pcVar7 != '\0');
    pcVar7 = pcVar8 + 2;
    cVar1 = *pcVar7;
  }
  pCVar6 = _malloc((size_t)(pcVar7 + (1 - (int)pCVar9)));
  if (pCVar6 == (LPSTR)0x0) {
    pCVar6 = (LPSTR)0x0;
  }
  else {
    FUN_1003e070((undefined4 *)pCVar6,(undefined4 *)pCVar9,(uint)(pcVar7 + (1 - (int)pCVar9)));
  }
  FreeEnvironmentStringsA(pCVar9);
  return pCVar6;
}



/* FUN_10013320 @ 10013320 size 305 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10013320(float *param_1,int param_2,float *param_3)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float afStack_70 [4];
  undefined4 uStack_60;
  undefined4 uStack_5c;
  int iStack_3c;
  undefined1 local_38 [56];
  
  local_88 = *(float *)(param_2 + 4);
  local_84 = *(float *)(param_2 + 8);
  local_7c = local_88 + *param_3;
  local_80 = *(float *)(param_2 + 0xc);
  local_78 = local_84 + param_3[1];
  local_74 = local_80 + param_3[2];
  while( true ) {
    iVar1 = *(int *)(param_2 + 0xfc);
    if (iVar1 == 0) {
      iVar1 = 3;
    }
    pfVar2 = (float *)(*DAT_1006c1f0)(local_38,&local_88,param_2 + 0xbc,param_2 + 200,&local_7c,
                                      param_2,iVar1);
    pfVar3 = afStack_70;
    for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
      *pfVar3 = *pfVar2;
      pfVar2 = pfVar2 + 1;
      pfVar3 = pfVar3 + 1;
    }
    *(float *)(param_2 + 4) = afStack_70[3];
    *(undefined4 *)(param_2 + 8) = uStack_60;
    *(undefined4 *)(param_2 + 0xc) = uStack_5c;
    (*DAT_1006c208)(param_2);
    if (afStack_70[2] == (float)_DAT_10044120) break;
    FUN_10012df0(param_2,(int)afStack_70);
    if (*(int *)(iStack_3c + 0x58) != 0) break;
    if (*(int *)(param_2 + 0x58) == 0) goto LAB_10013432;
    *(float *)(param_2 + 4) = local_88;
    *(float *)(param_2 + 8) = local_84;
    *(float *)(param_2 + 0xc) = local_80;
    (*DAT_1006c208)(param_2);
  }
  if (*(int *)(param_2 + 0x58) != 0) {
    FUN_1001b480();
  }
LAB_10013432:
  pfVar2 = afStack_70;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}



/* FUN_1000ede0 @ 1000ede0 size 303 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000ede0(int param_1)

{
  uint uVar1;
  
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  *(float *)(param_1 + 0xbc) = *(float *)(param_1 + 0xbc) + _DAT_10044104;
  *(float *)(param_1 + 0xc0) = *(float *)(param_1 + 0xc0) + _DAT_10044104;
  *(float *)(param_1 + 0xc4) = *(float *)(param_1 + 0xc4) + _DAT_10044104;
  *(float *)(param_1 + 200) = *(float *)(param_1 + 200) - _DAT_10044104;
  *(float *)(param_1 + 0xcc) = *(float *)(param_1 + 0xcc) - _DAT_10044104;
  *(float *)(param_1 + 0xd0) = *(float *)(param_1 + 0xd0) - _DAT_10044104;
  if (*(int *)(param_1 + 0x244) == 0) {
    *(undefined4 *)(param_1 + 0x244) = 100;
  }
  uVar1 = *(uint *)(param_1 + 0x11c);
  if (uVar1 == 0) {
    *(undefined4 *)(param_1 + 0xf8) = 3;
    *(undefined4 *)(param_1 + 0x104) = 2;
    *(code **)(param_1 + 500) = FUN_1000ed80;
    *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044198;
  }
  else {
    *(undefined4 *)(param_1 + 0xf8) = 0;
    *(undefined4 *)(param_1 + 0x104) = 2;
    *(code **)(param_1 + 0x200) = FUN_1000eda0;
    *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  }
  if ((uVar1 & 2) != 0) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x1000;
  }
  if ((uVar1 & 4) != 0) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x2000;
  }
  *(undefined4 *)(param_1 + 0xfc) = 0x2020003;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_1001a540 @ 1001a540 size 303 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1001a540(int param_1)

{
  float fVar1;
  
  *(undefined4 *)(param_1 + 0xf8) = 3;
  *(undefined4 *)(param_1 + 0x104) = 2;
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  if (*(float *)(param_1 + 0x148) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x148) = 0x42480000;
  }
  if (*(int *)(param_1 + 0x244) == 0) {
    *(undefined4 *)(param_1 + 0x244) = 10;
  }
  if (_DAT_1006c2bc == _DAT_1004410c) {
    _DAT_1006c2bc = -30.0;
  }
  if (_DAT_1006c2c0 == _DAT_1004410c) {
    _DAT_1006c2c0 = 30.0;
  }
  if (DAT_1006c2b8 == _DAT_1004410c) {
    DAT_1006c2b8 = 360.0;
  }
  *(float *)(param_1 + 0x160) = _DAT_1006c2bc * _DAT_100441bc;
  *(undefined4 *)(param_1 + 0x164) = DAT_1006c2b4;
  *(float *)(param_1 + 0x16c) = _DAT_1006c2c0 * _DAT_100441bc;
  fVar1 = DAT_1006c2b8;
  *(undefined1 **)(param_1 + 0x1f8) = &LAB_10019f90;
  *(undefined4 *)(param_1 + 0x1e8) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 700) = *(undefined4 *)(param_1 + 0x14);
  *(float *)(param_1 + 0x170) = fVar1;
  *(code **)(param_1 + 500) = FUN_1001a4b0;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_1000e0e0 @ 1000e0e0 size 301 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000e0e0(int param_1,int param_2)

{
  float fVar1;
  uint uVar2;
  char *pcVar3;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  uVar2 = _rand();
  if ((uVar2 & 1) == 0) {
    pcVar3 = s_models_objects_gibs_skull_tris_m_100491b0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  else {
    pcVar3 = s_models_objects_gibs_head2_tris_m_100491d4;
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  fVar1 = *(float *)(param_1 + 0xc) + _DAT_10044200;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(float *)(param_1 + 0xc) = fVar1;
  (*DAT_1006c1ec)(param_1,pcVar3);
  *(undefined4 *)(param_1 + 0xbc) = 0xc1800000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc1800000;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 200) = 0x41800000;
  *(undefined4 *)(param_1 + 0xcc) = 0x41800000;
  *(undefined4 *)(param_1 + 0xd0) = 0x41800000;
  *(undefined4 *)(param_1 + 0x240) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0x40) = 2;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) | 0x800;
  *(undefined4 *)(param_1 + 0x104) = 9;
  FUN_1000da90(param_2,&fStack_c);
  *(float *)(param_1 + 0x178) = fStack_c + *(float *)(param_1 + 0x178);
  *(float *)(param_1 + 0x17c) = fStack_8 + *(float *)(param_1 + 0x17c);
  *(float *)(param_1 + 0x180) = fStack_4 + *(float *)(param_1 + 0x180);
  if (*(int *)(param_1 + 0x54) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xea0) = 5;
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe9c) = *(undefined4 *)(param_1 + 0x38);
    (*DAT_1006c208)(param_1);
    return;
  }
  *(undefined4 *)(param_1 + 500) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10019700 @ 10019700 size 301 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10019700(undefined4 *param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  char *pcVar4;
  bool bVar5;
  
  pcVar4 = s_grenade_1004bbc8;
  pbVar2 = *(byte **)(param_2 + 0x118);
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < (byte)*pcVar4;
    if (bVar1 != *pcVar4) {
LAB_1001973a:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_1001973f;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < (byte)pcVar4[1];
    if (bVar1 != pcVar4[1]) goto LAB_1001973a;
    pbVar2 = pbVar2 + 2;
    pcVar4 = pcVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_1001973f:
  if (iVar3 == 0) {
    FUN_10038a20((float *)(param_1 + 0x55),(float)param_1[0x52] * _DAT_100441b0,
                 (float *)(param_2 + 0x178));
  }
  else if (0 < *(int *)(param_2 + 0x220)) {
    FUN_10038a20((float *)(param_1 + 0x55),(float)param_1[0x52] * _DAT_100441b0,
                 (float *)(param_2 + 0x178));
    if (*(int *)(param_2 + 0x54) != 0) {
      *(float *)(*(int *)(param_2 + 0x54) + 0xe80) = *(float *)(param_2 + 0x178);
      *(undefined4 *)(*(int *)(param_2 + 0x54) + 0xe84) = *(undefined4 *)(param_2 + 0x17c);
      *(undefined4 *)(*(int *)(param_2 + 0x54) + 0xe88) = *(undefined4 *)(param_2 + 0x180);
      if (*(float *)(param_2 + 0x218) < DAT_1006c2e4) {
        *(float *)(param_2 + 0x218) = DAT_1006c2e4 + (float)_DAT_100442a8;
        (*DAT_1006c1d0)(param_2,0,DAT_10060e7c,0x3f800000,0x3f800000,0);
      }
    }
  }
  if ((*(byte *)(param_1 + 0x47) & 1) != 0) {
    FUN_1001b400(param_1);
  }
  return;
}



/* FUN_100168b0 @ 100168b0 size 300 */

void __cdecl FUN_100168b0(byte *param_1,byte *param_2,undefined4 *param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *extraout_ECX;
  undefined **ppuVar4;
  undefined4 *puVar5;
  float10 fVar6;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  ppuVar4 = &PTR_s_classname_100498e0;
  puVar1 = PTR_s_classname_100498e0;
  while( true ) {
    if (puVar1 == (undefined *)0x0) {
      (*DAT_1006c1c4)(s__s_is_not_a_field_1004b324,param_1);
      return;
    }
    if ((((uint)ppuVar4[3] & 2) == 0) && (iVar2 = FUN_10038b20(*ppuVar4,param_1), iVar2 == 0))
    break;
    puVar1 = ppuVar4[4];
    ppuVar4 = ppuVar4 + 4;
  }
  puVar5 = &DAT_1006c280;
  if (((uint)ppuVar4[3] & 1) == 0) {
    puVar5 = param_3;
  }
  switch(ppuVar4[2]) {
  case (undefined *)0x0:
    uVar3 = FUN_10039237(param_2,param_2);
    *(undefined4 *)(ppuVar4[1] + (int)puVar5) = uVar3;
    return;
  case (undefined *)0x1:
    fVar6 = FUN_10039d65(extraout_ECX,param_2);
    *(float *)(ppuVar4[1] + (int)puVar5) = (float)fVar6;
    return;
  case (undefined *)0x2:
    uVar3 = FUN_10016850((char *)param_2);
    *(undefined4 *)(ppuVar4[1] + (int)puVar5) = uVar3;
    return;
  default:
    return;
  case (undefined *)0x4:
    FUN_10039662((char *)param_2,(byte *)s__f__f__f_10046688);
    *(undefined4 *)(ppuVar4[1] + (int)puVar5) = local_c;
    *(undefined4 *)(ppuVar4[1] + 4 + (int)puVar5) = local_8;
    *(undefined4 *)(ppuVar4[1] + 8 + (int)puVar5) = local_4;
    return;
  case (undefined *)0x5:
    fVar6 = FUN_10039d65(extraout_ECX,param_2);
    *(undefined4 *)(ppuVar4[1] + (int)puVar5) = 0;
    *(float *)(ppuVar4[1] + 4 + (int)puVar5) = (float)fVar6;
    *(undefined4 *)(ppuVar4[1] + 8 + (int)puVar5) = 0;
    return;
  }
}



/* FUN_1001b1e0 @ 1001b1e0 size 294 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1001b1e0(float *param_1,float *param_2)

{
  float fVar1;
  float10 extraout_ST1;
  longlong lVar2;
  
  fVar1 = _DAT_1004410c;
  if ((param_1[1] == _DAT_1004410c) && (*param_1 == _DAT_1004410c)) {
    if (_DAT_1004410c < param_1[2]) {
      *param_2 = -_DAT_100442d4;
      param_2[2] = 0.0;
      param_2[1] = fVar1;
      return;
    }
    *param_2 = -_DAT_100442d8;
    param_2[2] = 0.0;
    param_2[1] = fVar1;
    return;
  }
  if (*param_1 != _DAT_1004410c) {
    fpatan((float10)param_1[1],(float10)*param_1);
    __ftol();
  }
  fpatan((float10)param_1[2],
         SQRT((float10)param_1[1] * (float10)param_1[1] + (float10)*param_1 * (float10)*param_1));
  lVar2 = __ftol();
  fVar1 = (float)(int)lVar2;
  if (fVar1 < _DAT_1004410c) {
    fVar1 = fVar1 + _DAT_100442b0;
  }
  *param_2 = -fVar1;
  param_2[2] = 0.0;
  param_2[1] = (float)extraout_ST1;
  return;
}



/* FUN_1001c1c0 @ 1001c1c0 size 293 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1001c1c0(int param_1,float *param_2,float *param_3,int param_4)

{
  uint uVar1;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  float10 fVar5;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float local_7c [3];
  float afStack_70 [4];
  float fStack_60;
  float fStack_5c;
  int iStack_3c;
  undefined1 local_38 [56];
  
  if ((*(float *)(DAT_1006c41c + 0x14) == _DAT_1004410c) &&
     (uVar1 = _rand(), (float)_DAT_10044230 < (float)(uVar1 & 0x7fff) * _DAT_10044108)) {
    return;
  }
  FUN_10038950(param_2,8192.0,param_3,local_7c);
  pfVar2 = (float *)(*DAT_1006c1f0)(local_38,param_2,0,0,local_7c,param_1,0x6000003);
  pfVar4 = afStack_70;
  for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar4 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar4 = pfVar4 + 1;
  }
  if ((((iStack_3c != 0) && ((*(byte *)(iStack_3c + 0xb8) & 4) != 0)) &&
      (0 < *(int *)(iStack_3c + 0x220))) &&
     ((*(int *)(iStack_3c + 0x37c) != 0 && (iVar3 = FUN_10001600(iStack_3c,param_1), iVar3 != 0))))
  {
    fStack_88 = afStack_70[3] - *param_2;
    fStack_84 = fStack_60 - param_2[1];
    fStack_80 = fStack_5c - param_2[2];
    fVar5 = FUN_100389f0(&fStack_88);
    (**(code **)(iStack_3c + 0x37c))
              (iStack_3c,param_1,
               (float)((fVar5 - (float10)*(float *)(iStack_3c + 200)) / (float10)param_4));
  }
  return;
}



/* FUN_100427b9 @ 100427b9 size 293 */

int __cdecl FUN_100427b9(uint param_1,int param_2)

{
  DWORD DVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  DWORD *pDVar6;
  HANDLE hFile;
  BOOL BVar7;
  int iVar8;
  uint uVar9;
  char local_1008 [4064];
  undefined4 uStackY_28;
  
  FUN_10039f80();
  iVar8 = 0;
  DVar1 = FUN_10040751(param_1,0,1);
  if ((DVar1 == 0xffffffff) || (DVar2 = FUN_10040751(param_1,0,2), DVar2 == 0xffffffff)) {
    iVar8 = -1;
  }
  else {
    uVar9 = param_2 - DVar2;
    if ((int)uVar9 < 1) {
      if ((int)uVar9 < 0) {
        FUN_10040751(param_1,param_2,0);
        hFile = (HANDLE)FUN_10041000(param_1);
        BVar7 = SetEndOfFile(hFile);
        iVar8 = (BVar7 != 0) - 1;
        if (iVar8 == -1) {
          pDVar6 = FUN_1004058e();
          *pDVar6 = 0xd;
          DVar2 = GetLastError();
          pDVar6 = FUN_10040597();
          *pDVar6 = DVar2;
        }
      }
    }
    else {
      _memset(local_1008,0,0x1000);
      uStackY_28 = 0x10042826;
      iVar3 = FUN_1004316f(param_1,0x8000);
      do {
        uVar4 = 0x1000;
        if ((int)uVar9 < 0x1000) {
          uVar4 = uVar9;
        }
        iVar5 = FUN_1003dda9(param_1,local_1008,uVar4);
        if (iVar5 == -1) {
          pDVar6 = FUN_10040597();
          if (*pDVar6 == 5) {
            pDVar6 = FUN_1004058e();
            *pDVar6 = 0xd;
          }
          iVar8 = -1;
          break;
        }
        uVar9 = uVar9 - iVar5;
      } while (0 < (int)uVar9);
      FUN_1004316f(param_1,iVar3);
    }
    FUN_10040751(param_1,DVar1,0);
  }
  return iVar8;
}



/* _strncat @ 10039250 size 291 */

/* Library Function - Single Match
    _strncat
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strncat(char *_Dest,char *_Source,size_t _Count)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  puVar5 = (uint *)_Dest;
  if (_Count == 0) {
    return _Dest;
  }
  do {
    if (((uint)puVar5 & 3) == 0) goto LAB_1003927a;
    uVar4 = *puVar5;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_100392ab;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar6 = (uint *)((int)puVar6 + 2);
      goto LAB_100392bb;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_1003927a:
    do {
      puVar6 = puVar5;
      puVar5 = puVar6 + 1;
    } while (((*puVar6 ^ 0xffffffff ^ *puVar6 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar6;
    if ((char)uVar4 == '\0') goto LAB_100392bb;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar6 = (uint *)((int)puVar6 + 1);
      goto LAB_100392bb;
    }
  }
LAB_100392ab:
  puVar6 = (uint *)((int)puVar5 + -1);
LAB_100392bb:
  if (((uint)_Source & 3) == 0) {
    uVar3 = _Count >> 2;
  }
  else {
    do {
      bVar1 = (byte)*(uint *)_Source;
      uVar4 = (uint)bVar1;
      _Source = (char *)((int)_Source + 1);
      if (bVar1 == 0) goto LAB_1003930a;
      *(byte *)puVar6 = bVar1;
      puVar6 = (uint *)((int)puVar6 + 1);
      _Count = _Count - 1;
      if (_Count == 0) goto LAB_10039300;
    } while (((uint)_Source & 3) != 0);
    uVar3 = _Count >> 2;
  }
  do {
    if (uVar3 == 0) {
      for (uVar4 = _Count & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        uVar3 = *(uint *)_Source;
        _Source = (char *)((int)_Source + 1);
        *(byte *)puVar6 = (byte)uVar3;
        puVar6 = (uint *)((int)puVar6 + 1);
        if ((byte)uVar3 == 0) {
          return _Dest;
        }
      }
LAB_10039300:
      *(byte *)puVar6 = 0;
      return _Dest;
    }
    uVar2 = *(uint *)_Source;
    uVar4 = *(uint *)_Source;
    _Source = (char *)((int)_Source + 4);
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar4 == '\0') {
LAB_1003930a:
        *(byte *)puVar6 = (byte)uVar4;
        return _Dest;
      }
      if ((char)(uVar4 >> 8) == '\0') {
        *(short *)puVar6 = (short)uVar4;
        return _Dest;
      }
      if ((uVar4 & 0xff0000) == 0) {
        *(short *)puVar6 = (short)uVar4;
        *(byte *)((int)puVar6 + 2) = 0;
        return _Dest;
      }
      if ((uVar4 & 0xff000000) == 0) {
        *puVar6 = uVar4;
        return _Dest;
      }
    }
    *puVar6 = uVar4;
    puVar6 = puVar6 + 1;
    uVar3 = uVar3 - 1;
  } while( true );
}



/* FUN_10040de2 @ 10040de2 size 291 */

uint FUN_10040de2(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int local_8;
  int local_4;
  
  uVar4 = 0xffffffff;
  FUN_1003c8a1(0x12);
  local_8 = 0;
  local_4 = 0;
  piVar3 = &DAT_1006ccc0;
  while (puVar2 = (undefined4 *)*piVar3, puVar1 = puVar2, puVar2 != (undefined4 *)0x0) {
    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {
      if ((*(byte *)(puVar2 + 1) & 1) == 0) {
        if (puVar2[2] == 0) {
          FUN_1003c8a1(0x11);
          if (puVar2[2] == 0) {
            InitializeCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
            puVar2[2] = puVar2[2] + 1;
          }
          FUN_1003c902(0x11);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
        if ((*(byte *)(puVar2 + 1) & 1) == 0) {
          *puVar2 = 0xffffffff;
          uVar4 = ((int)puVar2 - *piVar3) / 0x24 + local_4;
          if (uVar4 != 0xffffffff) goto LAB_10040ef4;
          break;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(puVar2 + 3));
      }
      puVar1 = (undefined4 *)*piVar3;
    }
    local_4 = local_4 + 0x20;
    piVar3 = piVar3 + 1;
    local_8 = local_8 + 1;
    if (0x1006cdbf < (int)piVar3) goto LAB_10040ef4;
  }
  puVar2 = _malloc(0x480);
  if (puVar2 != (undefined4 *)0x0) {
    DAT_1006cdc0 = DAT_1006cdc0 + 0x20;
    (&DAT_1006ccc0)[local_8] = puVar2;
    puVar1 = puVar2;
    for (; puVar2 < puVar1 + 0x120; puVar2 = puVar2 + 9) {
      *(undefined1 *)(puVar2 + 1) = 0;
      *puVar2 = 0xffffffff;
      puVar2[2] = 0;
      *(undefined1 *)((int)puVar2 + 5) = 10;
      puVar1 = (undefined4 *)(&DAT_1006ccc0)[local_8];
    }
    uVar4 = local_8 << 5;
    FUN_10041042(uVar4);
  }
LAB_10040ef4:
  FUN_1003c902(0x12);
  return uVar4;
}



/* FUN_10003760 @ 10003760 size 285 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10003760(int param_1)

{
  uint uVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x254) == 0) {
    *(undefined4 *)(param_1 + 0x254) = 1;
    if ((*(int *)(param_1 + 0x1e0) == 0) && (*(byte **)(param_1 + 0x128) != (byte *)0x0)) {
      uVar1 = FUN_1001ac00(0,300,*(byte **)(param_1 + 0x128));
      *(uint *)(param_1 + 0x1e0) = uVar1;
      if (uVar1 == 0) {
        uVar3 = *(undefined4 *)(param_1 + 0x128);
        puVar2 = FUN_1001b070();
        (*DAT_1006c1c0)(2,s__s_at__s__invalid_target__s_100460dc,*(undefined4 *)(param_1 + 0x118),
                        puVar2,uVar3);
      }
      else {
        *(float *)(param_1 + 800) = *(float *)(param_1 + 0x148);
        if (*(float *)(param_1 + 0x148) == _DAT_1004410c) {
          *(undefined4 *)(param_1 + 800) = 0x42c80000;
        }
        *(undefined4 *)(param_1 + 0x330) = 0;
        *(undefined4 *)(param_1 + 4) = *(undefined4 *)(uVar1 + 4);
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(uVar1 + 8);
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(uVar1 + 0xc);
        *(float *)(param_1 + 0x32c) = DAT_1006c2e4;
      }
    }
    *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
    return;
  }
  *(undefined4 *)(param_1 + 0x294) = 0;
  *(undefined4 *)(param_1 + 0x254) = 0;
  *(undefined4 *)(param_1 + 0x180) = 0;
  *(undefined4 *)(param_1 + 0x17c) = 0;
  *(undefined4 *)(param_1 + 0x178) = 0;
  *(undefined4 *)(param_1 + 0x18c) = 0;
  *(undefined4 *)(param_1 + 0x188) = 0;
  *(undefined4 *)(param_1 + 0x184) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x330) = 0;
  return;
}



/* FUN_10017730 @ 10017730 size 284 */

void FUN_10017730(void)

{
  FILE *pFVar1;
  int iVar2;
  CHAR aCStack_80 [128];
  
  (*DAT_1006c250)(&DAT_1004b8a4,&DAT_10060c60,0);
  FUN_10039541(aCStack_80,(byte *)s__s_listip_cfg_1004b894);
  (*DAT_1006c1c8)(0,2,s_Writing__s__1004b884,aCStack_80);
  pFVar1 = (FILE *)FUN_10039d52(aCStack_80,&DAT_1004a508);
  if (pFVar1 == (FILE *)0x0) {
    (*DAT_1006c1c8)(0,2,s_Couldn_t_open__s_1004b870,aCStack_80);
    return;
  }
  __ftol();
  FUN_10039ebe((int *)pFVar1,(byte *)s_set_filterban__d_1004b85c);
  iVar2 = 0;
  if (0 < DAT_100620d0) {
    do {
      FUN_10039ebe((int *)pFVar1,(byte *)s_sv_addip__i__i__i__i_1004b844);
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_100620d0);
  }
  FUN_10039ca4(pFVar1);
  return;
}



/* FUN_1000d650 @ 1000d650 size 280 */

void FUN_1000d650(void)

{
  int *piVar1;
  uint *puVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  void *pvVar6;
  ulonglong uVar7;
  
  uVar7 = __ftol();
  if ((uVar7 & 0x20) == 0) {
    if ((char)**(uint **)(DAT_1006c170 + 4) != '\0') {
      puVar2 = FUN_1004339f(*(uint **)(DAT_1006c170 + 4));
      pvVar6 = (void *)0x0;
      pvVar3 = (void *)FUN_1003972f((byte *)puVar2,PTR_DAT_10049138);
      while (pvVar3 != (void *)0x0) {
        iVar4 = FUN_10038b20(pvVar3,&DAT_1006c328);
        if (iVar4 == 0) {
          FUN_1003972f((byte *)0x0,PTR_DAT_10049138);
          piVar1 = FUN_1000d610();
          FUN_10032530((int)piVar1);
          FUN_100396e7(puVar2);
          return;
        }
        if (pvVar6 == (void *)0x0) {
          pvVar6 = pvVar3;
        }
        pvVar3 = (void *)FUN_1003972f((byte *)0x0,PTR_DAT_10049138);
      }
      FUN_100396e7(puVar2);
    }
    if ((char)DAT_1006c368 != '\0') {
      piVar1 = FUN_1000d610();
      FUN_10032530((int)piVar1);
      return;
    }
    uVar5 = FUN_1001ac00(0,0x118,(byte *)s_target_changelevel_1004915c);
    if (uVar5 != 0) {
      FUN_10032530(uVar5);
      return;
    }
  }
  piVar1 = FUN_1000d610();
  FUN_10032530((int)piVar1);
  return;
}



/* FUN_1003b304 @ 1003b304 size 280 */

uint __cdecl FUN_1003b304(uint param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  byte bVar5;
  undefined3 extraout_var;
  undefined *puVar6;
  int *piVar7;
  
  piVar4 = param_2;
  uVar1 = param_2[3];
  uVar2 = param_2[4];
  if (((uVar1 & 0x82) == 0) || ((uVar1 & 0x40) != 0)) {
LAB_1003b410:
    param_2[3] = uVar1 | 0x20;
  }
  else {
    if ((uVar1 & 1) != 0) {
      param_2[1] = 0;
      if ((uVar1 & 0x10) == 0) goto LAB_1003b410;
      *param_2 = param_2[2];
      param_2[3] = uVar1 & 0xfffffffe;
    }
    uVar1 = param_2[3];
    param_2[1] = 0;
    param_2 = (int *)0x0;
    piVar4[3] = uVar1 & 0xffffffef | 2;
    if (((uVar1 & 0x10c) == 0) &&
       (((piVar4 != (int *)&DAT_100600a0 && (piVar4 != (int *)&DAT_100600c0)) ||
        (bVar5 = FUN_10040808(uVar2), CONCAT31(extraout_var,bVar5) == 0)))) {
      FUN_100407c4(piVar4);
    }
    if ((*(ushort *)(piVar4 + 3) & 0x108) == 0) {
      piVar7 = (int *)0x1;
      param_2 = (int *)FUN_1003dd44(uVar2,(char *)&param_1,1);
    }
    else {
      pcVar3 = (char *)piVar4[2];
      piVar7 = (int *)(*piVar4 - (int)pcVar3);
      *piVar4 = (int)(pcVar3 + 1);
      piVar4[1] = piVar4[6] + -1;
      if ((int)piVar7 < 1) {
        if (uVar2 == 0xffffffff) {
          puVar6 = &DAT_10060440;
        }
        else {
          puVar6 = (undefined *)((&DAT_1006ccc0)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
        }
        if ((puVar6[4] & 0x20) != 0) {
          FUN_100406ec(uVar2,0,2);
        }
      }
      else {
        param_2 = (int *)FUN_1003dd44(uVar2,pcVar3,(uint)piVar7);
      }
      *(undefined1 *)piVar4[2] = (undefined1)param_1;
    }
    if (param_2 == piVar7) {
      return param_1 & 0xff;
    }
    piVar4[3] = piVar4[3] | 0x20;
  }
  return 0xffffffff;
}



/* FUN_10018ab0 @ 10018ab0 size 279 */

void __cdecl FUN_10018ab0(undefined4 *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  undefined *puVar4;
  char *pcVar5;
  uint uVar6;
  bool bVar7;
  undefined4 *puVar8;
  
  if (param_1[0x97] == 0) {
    uVar6 = 0;
    while( true ) {
      uVar6 = FUN_1001ac00(uVar6,300,(byte *)param_1[0x4a]);
      if (uVar6 == 0) break;
      pbVar2 = *(byte **)(uVar6 + 0x118);
      pcVar5 = s_light_1004a1d0;
      do {
        bVar1 = *pbVar2;
        bVar7 = bVar1 < (byte)*pcVar5;
        if (bVar1 != *pcVar5) {
LAB_10018b1a:
          iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_10018b1f;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar2[1];
        bVar7 = bVar1 < (byte)pcVar5[1];
        if (bVar1 != pcVar5[1]) goto LAB_10018b1a;
        pbVar2 = pbVar2 + 2;
        pcVar5 = pcVar5 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_10018b1f:
      if (iVar3 == 0) {
        param_1[0x97] = uVar6;
      }
      else {
        puVar8 = param_1 + 1;
        puVar4 = FUN_1001b070();
        (*DAT_1006c1c4)(s__s_at__s_1004ba84,param_1[0x46],puVar4,puVar8);
        iVar3 = uVar6 + 4;
        puVar4 = FUN_1001b070();
        (*DAT_1006c1c4)(s_target__s___s_at__s__is_not_a_li_1004ba5c,param_1[0x4a],
                        *(undefined4 *)(uVar6 + 0x118),puVar4,iVar3);
      }
    }
    if (param_1[0x97] == 0) {
      puVar8 = param_1 + 1;
      puVar4 = FUN_1001b070();
      (*DAT_1006c1c4)(s__s_target__s_not_found_at__s_1004ba3c,param_1[0x46],param_1[0x4a],puVar4,
                      puVar8);
      FUN_1001b400(param_1);
      return;
    }
  }
  param_1[0x48] = DAT_1006c2e4;
  FUN_100189e0((int)param_1);
  return;
}



/* FUN_1000bef0 @ 1000bef0 size 278 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1000bef0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  
  iVar2 = *(int *)(param_1 + 0x2cc);
  uVar5 = *(uint *)(iVar2 + 0x38) & 1;
  if ((uVar5 == 0) || (uVar6 = __ftol(), (uVar6 & 0x2000) == 0)) {
    iVar4 = *(int *)(param_1 + 0x254);
    if (iVar4 == 0) {
      iVar4 = *(int *)(iVar2 + 0x30);
    }
  }
  else {
    iVar4 = 1000;
  }
  iVar1 = *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + ((iVar2 + -0x10046928) / 0x48) * 4);
  iVar2 = FUN_1000bdf0(param_2,iVar2,iVar4);
  if (iVar2 != 0) {
    if ((((uVar5 != 0) && (iVar1 == 0)) &&
        (iVar2 = *(int *)(param_2 + 0x54), *(int *)(iVar2 + 0x714) != *(int *)(param_1 + 0x2cc))) &&
       ((*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c ||
        (puVar3 = FUN_1000b150((byte *)s_blaster_10048f64),
        *(undefined4 **)(iVar2 + 0x714) == puVar3)))) {
      *(undefined4 *)(iVar2 + 0xdfc) = *(undefined4 *)(param_1 + 0x2cc);
    }
    if (((*(uint *)(param_1 + 0x11c) & 0x30000) == 0) &&
       (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c)) {
      FUN_1000b210(param_1,30.0);
    }
    return 1;
  }
  return 0;
}



/* FUN_10011000 @ 10011000 size 278 */

void __cdecl FUN_10011000(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x2c8);
  if (iVar1 == 0) {
    FUN_10038b40();
    return;
  }
  if (iVar1 == 1) {
    FUN_10038b40();
    if (*(char *)(*(int *)(param_1 + 0x114) + 3) == ' ') {
      *(undefined1 *)(*(int *)(param_1 + 0x114) + 3) = 0x30;
      return;
    }
  }
  else if (iVar1 == 2) {
    FUN_10038b40();
    if (*(char *)(*(int *)(param_1 + 0x114) + 3) == ' ') {
      *(undefined1 *)(*(int *)(param_1 + 0x114) + 3) = 0x30;
    }
    if (*(char *)(*(int *)(param_1 + 0x114) + 6) == ' ') {
      *(undefined1 *)(*(int *)(param_1 + 0x114) + 6) = 0x30;
    }
  }
  return;
}



/* FUN_10030970 @ 10030970 size 278 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10030970(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  byte *pbVar2;
  
  if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
    if (*(float *)(DAT_1006c42c + 0x14) != _DAT_1004410c) {
      uVar1 = FUN_10030900(param_1);
      goto LAB_100309b0;
    }
  }
  else {
    uVar1 = FUN_100308e0();
LAB_100309b0:
    if (uVar1 != 0) goto LAB_10030a54;
  }
  for (uVar1 = FUN_1001ac00(0,0x118,(byte *)s_info_player_start_1004b284); uVar1 != 0;
      uVar1 = FUN_1001ac00(uVar1,0x118,(byte *)s_info_player_start_1004b284)) {
    pbVar2 = *(byte **)(uVar1 + 300);
    if (DAT_1006c848 == '\0') {
joined_r0x100309fd:
      if (pbVar2 == (byte *)0x0) {
        if (uVar1 != 0) goto LAB_10030a54;
        break;
      }
    }
    else if (pbVar2 != (byte *)0x0) {
      pbVar2 = (byte *)FUN_10038b20(&DAT_1006c848,pbVar2);
      goto joined_r0x100309fd;
    }
  }
  if ((DAT_1006c848 != '\0') ||
     (uVar1 = FUN_1001ac00(0,0x118,(byte *)s_info_player_start_1004b284), uVar1 == 0)) {
    (*DAT_1006c1dc)(s_Couldn_t_find_spawn_point__s_1005f2d0,&DAT_1006c848);
  }
LAB_10030a54:
  *param_2 = *(undefined4 *)(uVar1 + 4);
  param_2[1] = *(undefined4 *)(uVar1 + 8);
  param_2[2] = *(float *)(uVar1 + 0xc) + _DAT_10044240;
  *param_3 = *(undefined4 *)(uVar1 + 0x10);
  param_3[1] = *(undefined4 *)(uVar1 + 0x14);
  param_3[2] = *(undefined4 *)(uVar1 + 0x18);
  return;
}



/* FUN_1001e520 @ 1001e520 size 277 */

void __cdecl FUN_1001e520(undefined4 *param_1,uint param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  uVar1 = param_1[0x40];
  if (param_2 != uVar1) {
    if ((param_4 == 0) || ((*(byte *)(param_4 + 0x10) & 4) == 0)) {
      if (*(int *)(uVar1 + 0x54) != 0) {
        FUN_100350a0(uVar1,(float *)(param_1 + 1),2);
      }
      if ((*(byte *)(param_1 + 0x47) & 1) == 0) {
        pcVar3 = s_plasma1_hit_wav_1004c098;
      }
      else {
        pcVar3 = s_plasma2_hit_wav_1004c0a8;
      }
      uVar2 = (*DAT_1006c1e4)(pcVar3,0x3f800000,0x3f800000,0);
      (*DAT_1006c1d0)(param_1,2,uVar2);
      if (*(int *)(param_2 + 0x240) != 0) {
        FUN_100060d0(param_2,param_1,param_1[0x40],(float *)(param_1 + 0x5e),(float *)(param_1 + 1),
                     param_3,param_1[0x91],1,4,(uint)(*(byte *)(param_1 + 0x47) & 1 | 0x24));
        FUN_1001b400(param_1);
        return;
      }
      (*DAT_1006c224)(3);
      (*DAT_1006c224)(0x1e);
      (*DAT_1006c238)(param_1 + 1);
      if (param_3 == (undefined4 *)0x0) {
        param_3 = &DAT_10061c18;
      }
      (*DAT_1006c23c)(param_3);
      (*DAT_1006c218)(param_1 + 1,2);
    }
    FUN_1001b400(param_1);
  }
  return;
}



/* FUN_1002e9c0 @ 1002e9c0 size 276 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1002e9c0(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 1;
  }
  if ((10 < param_4) && (*(float *)(param_1 + 0x210) <= DAT_1006c2e4)) {
    if ((param_4 < 0x1f) &&
       (uVar2 = _rand(), (float)_DAT_10044198 < (float)(uVar2 & 0x7fff) * _DAT_10044108)) {
      return;
    }
    if ((*(float *)(DAT_1006c41c + 0x14) < _DAT_1004413c) ||
       (((iVar1 = *(int *)(param_1 + 0x38), iVar1 < 0x73 || (0x90 < iVar1)) &&
        ((iVar1 < 0x37 || (0x46 < iVar1)))))) {
      *(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4;
      (*DAT_1006c1d0)(param_1,2,DAT_10061368,0x3f800000,0x3f800000,0);
      if (*(int *)(DAT_1006c41c + 0x14) != 0x40400000) {
        if (param_4 < 0x1f) {
          *(undefined **)(param_1 + 0x358) = &DAT_1005e2f0;
          return;
        }
        if (param_4 < 0x3d) {
          *(undefined **)(param_1 + 0x358) = &DAT_1005e340;
          return;
        }
        *(undefined **)(param_1 + 0x358) = &DAT_1005e410;
      }
    }
  }
  return;
}



/* FUN_10019fe0 @ 10019fe0 size 274 */

void __cdecl FUN_10019fe0(int param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  float local_30 [3];
  float local_24 [3];
  float local_18 [3];
  float local_c [3];
  
  FUN_10038700((float *)(param_1 + 0x10),local_24,local_18,local_c);
  FUN_10038950((float *)(param_1 + 4),*(float *)(param_1 + 0x2ac),local_24,local_30);
  FUN_10038950(local_30,*(float *)(param_1 + 0x2b0),local_18,local_30);
  FUN_10038950(local_30,*(float *)(param_1 + 0x2b4),local_c,local_30);
  _rand();
  lVar2 = __ftol();
  iVar4 = 0x43160000;
  iVar5 = (int)lVar2;
  lVar3 = __ftol();
  FUN_1001cad0(*(int *)(*(int *)(param_1 + 0x274) + 0x100),local_30,local_24,(int)lVar2,(int)lVar3,
               iVar4,iVar5);
  uVar1 = (*DAT_1006c1e4)(s_weapons_rocklf1a_wav_1004ba04,0x3f800000,0x3f800000,0);
  (*DAT_1006c1d4)(local_30,param_1,1,uVar1);
  return;
}



/* FUN_10004750 @ 10004750 size 273 */

void __cdecl FUN_10004750(char *param_1,int *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  pcVar2 = (char *)(*DAT_1006c260)(*param_2);
  *param_1 = '\0';
  if (*pcVar2 == '\'') {
    pcVar2 = pcVar2 + 1;
    if (*param_2 < param_3) {
      do {
        iVar3 = -1;
        pcVar7 = pcVar2;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        if (iVar3 != -2) {
          uVar4 = 0xffffffff;
          pcVar7 = pcVar2;
          do {
            if (uVar4 == 0) break;
            uVar4 = uVar4 - 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          if (pcVar2[~uVar4 - 2] == '\'') {
            uVar4 = 0xffffffff;
            pcVar7 = pcVar2;
            goto code_r0x10004826;
          }
        }
        uVar4 = 0xffffffff;
        do {
          pcVar7 = pcVar2;
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          pcVar7 = pcVar2 + 1;
          cVar1 = *pcVar2;
          pcVar2 = pcVar7;
        } while (cVar1 != '\0');
        uVar4 = ~uVar4;
        iVar3 = -1;
        pcVar2 = param_1;
        do {
          pcVar6 = pcVar2;
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          pcVar6 = pcVar2 + 1;
          cVar1 = *pcVar2;
          pcVar2 = pcVar6;
        } while (cVar1 != '\0');
        pcVar2 = pcVar7 + -uVar4;
        pcVar7 = pcVar6 + -1;
        for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar2;
          pcVar2 = pcVar2 + 4;
          pcVar7 = pcVar7 + 4;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *pcVar7 = *pcVar2;
          pcVar2 = pcVar2 + 1;
          pcVar7 = pcVar7 + 1;
        }
        uVar4 = 0xffffffff;
        pcVar2 = &DAT_10046390;
        do {
          pcVar7 = pcVar2;
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          pcVar7 = pcVar2 + 1;
          cVar1 = *pcVar2;
          pcVar2 = pcVar7;
        } while (cVar1 != '\0');
        uVar4 = ~uVar4;
        iVar3 = -1;
        pcVar2 = param_1;
        do {
          pcVar6 = pcVar2;
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          pcVar6 = pcVar2 + 1;
          cVar1 = *pcVar2;
          pcVar2 = pcVar6;
        } while (cVar1 != '\0');
        pcVar2 = pcVar7 + -uVar4;
        pcVar7 = pcVar6 + -1;
        for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar2;
          pcVar2 = pcVar2 + 4;
          pcVar7 = pcVar7 + 4;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *pcVar7 = *pcVar2;
          pcVar2 = pcVar2 + 1;
          pcVar7 = pcVar7 + 1;
        }
        iVar3 = *param_2;
        *param_2 = iVar3 + 1;
        pcVar2 = (char *)(*DAT_1006c260)(iVar3 + 1);
        if (param_3 <= *param_2) {
          return;
        }
      } while( true );
    }
  }
  else {
    uVar4 = 0xffffffff;
    do {
      pcVar7 = pcVar2;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar7 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar7;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar2 = pcVar7 + -uVar4;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)param_1 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      param_1 = param_1 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *param_1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
  while( true ) {
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    if (cVar1 == '\0') break;
code_r0x10004826:
    if (uVar4 == 0) break;
  }
  _strncat(param_1,pcVar2,~uVar4 - 2);
  return;
}



/* FUN_10011390 @ 10011390 size 271 */

void __cdecl FUN_10011390(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1[0x4a] == 0) {
    (*DAT_1006c1c4)(s_teleporter_without_a_target__10049668);
    FUN_1001b400(param_1);
    return;
  }
  (*DAT_1006c1ec)(param_1,s_models_objects_dmspot_tris_md2_10049648);
  param_1[0xf] = 1;
  param_1[0x10] = 0x20000;
  uVar2 = (*DAT_1006c1e4)(s_world_amb10_wav_10049638);
  param_1[0x13] = uVar2;
  param_1[0x2f] = 0xc2000000;
  param_1[0x30] = 0xc2000000;
  param_1[0x3e] = 2;
  param_1[0x31] = 0xc1c00000;
  param_1[0x32] = 0x42000000;
  param_1[0x33] = 0x42000000;
  param_1[0x34] = 0xc1800000;
  (*DAT_1006c208)(param_1);
  piVar3 = FUN_1001b350();
  piVar3[0x7f] = (int)FUN_10011240;
  piVar3[0x3e] = 1;
  iVar1 = param_1[0x4a];
  piVar3[0x40] = (int)param_1;
  piVar3[0x4a] = iVar1;
  piVar3[1] = param_1[1];
  piVar3[2] = param_1[2];
  iVar1 = param_1[3];
  piVar3[0x2f] = -0x3f000000;
  piVar3[0x30] = -0x3f000000;
  piVar3[3] = iVar1;
  piVar3[0x31] = 0x41000000;
  piVar3[0x32] = 0x41000000;
  piVar3[0x33] = 0x41000000;
  piVar3[0x34] = 0x41c00000;
  (*DAT_1006c208)(piVar3);
  return;
}



/* FUN_10022b40 @ 10022b40 size 271 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10022b40(float param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  float fVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  
  *(undefined4 *)((int)param_1 + 0x4c) = 0;
  if (*(int *)((int)param_1 + 0x220) <= *(int *)((int)param_1 + 0x228)) {
    uVar2 = (*DAT_1006c1e4)(s_misc_udeath_wav_100493f8,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_1,2,uVar2);
    FUN_1000dd30(param_1,s_models_objects_gibs_sm_meat_tris_100493d0,param_4,0);
    iVar4 = 4;
    do {
      FUN_1000dd30(param_1,s_models_objects_gibs_sm_metal_tri_1004fc88,param_4,1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_1000df70(param_1,s_models_objects_gibs_gear_tris_md_1004fc64,param_4,1);
    *(undefined4 *)((int)param_1 + 0x22c) = 2;
    return;
  }
  if (*(int *)((int)param_1 + 0x22c) != 2) {
    (*DAT_1006c1d0)(param_1,2,DAT_1006108c,0x3f800000,0,0);
    *(undefined4 *)((int)param_1 + 0x22c) = 2;
    *(undefined4 *)((int)param_1 + 0x240) = 1;
    piVar3 = FUN_1001b350();
    piVar3[1] = *(int *)((int)param_1 + 4);
    piVar3[2] = *(int *)((int)param_1 + 8);
    fVar1 = (float)piVar3[2] - _DAT_10044360;
    piVar3[3] = *(int *)((int)param_1 + 0xc);
    piVar3[4] = *(int *)((int)param_1 + 0x10);
    piVar3[5] = *(int *)((int)param_1 + 0x14);
    iVar4 = *(int *)((int)param_1 + 0x18);
    piVar3[2] = (int)fVar1;
    piVar3[6] = iVar4;
    FUN_10022a50((int)piVar3);
    *(undefined **)((int)param_1 + 0x358) = &DAT_1004f808;
  }
  return;
}



/* FUN_10035420 @ 10035420 size 271 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10035420(int param_1)

{
  int iVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if (*(float *)(*(int *)(param_1 + 0x54) + 0xec0) != _DAT_1004410c) {
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xec0) = DAT_1006c2e4;
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xec8) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xec0) = 0;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x718) =
       *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x714);
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x714) =
       *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xdfc);
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xdfc) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe98) = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0x714);
  if ((iVar1 == 0) || (pbVar2 = *(byte **)(iVar1 + 0x34), pbVar2 == (byte *)0x0)) {
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xde8) = 0;
  }
  else {
    puVar3 = FUN_1000b150(pbVar2);
    *(int *)(*(int *)(param_1 + 0x54) + 0xde8) = (int)(puVar3 + -0x4011a4a) / 0x48;
  }
  iVar1 = *(int *)(param_1 + 0x54);
  if (*(int *)(iVar1 + 0x714) == 0) {
    *(undefined4 *)(iVar1 + 0x58) = 0;
    return;
  }
  *(undefined4 *)(iVar1 + 0xe20) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x5c) = 0;
  uVar4 = (*DAT_1006c1e0)(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x714) + 0x20));
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xf28) = uVar4;
  iVar1 = *(int *)(param_1 + 0x54);
  if (*(int *)(iVar1 + 0xf18) != 0) {
    *(undefined4 *)(iVar1 + 0x58) = 0;
    return;
  }
  *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(iVar1 + 0xf28);
  return;
}



/* FUN_10004fa0 @ 10004fa0 size 269 */

void __cdecl FUN_10004fa0(int param_1)

{
  int iVar1;
  byte *pbVar2;
  undefined4 uVar3;
  void *this;
  
  pbVar2 = (byte *)(*DAT_1006c260)(1);
  uVar3 = FUN_10039237(this,pbVar2);
  iVar1 = *(int *)(param_1 + 0x54);
  if (((*(byte *)(iVar1 + 0x10) & 1) == 0) && (*(int *)(iVar1 + 0xea0) < 2)) {
    *(undefined4 *)(iVar1 + 0xea0) = 1;
    switch(uVar3) {
    case 0:
      (*DAT_1006c1c8)(param_1,2,s_flipoff_10046414);
      *(undefined4 *)(param_1 + 0x38) = 0x47;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe9c) = 0x53;
      return;
    case 1:
      (*DAT_1006c1c8)(param_1,2,s_salute_1004640c);
      *(undefined4 *)(param_1 + 0x38) = 0x53;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe9c) = 0x5e;
      return;
    case 2:
      (*DAT_1006c1c8)(param_1,2,s_taunt_10046404);
      *(undefined4 *)(param_1 + 0x38) = 0x5e;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe9c) = 0x6f;
      return;
    case 3:
      (*DAT_1006c1c8)(param_1,2,s_wave_100463fc);
      *(undefined4 *)(param_1 + 0x38) = 0x6f;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe9c) = 0x7a;
      return;
    default:
      (*DAT_1006c1c8)(param_1,2,s_point_100463f4);
      *(undefined4 *)(param_1 + 0x38) = 0x7a;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe9c) = 0x86;
    }
  }
  return;
}



/* FUN_10035ca0 @ 10035ca0 size 269 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10035ca0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  float fVar5;
  int iVar6;
  float local_30 [3];
  float local_24 [3];
  float local_18 [3];
  float local_c [3];
  
  iVar2 = 0x7d;
  if (DAT_100613c0 != 0) {
    iVar2 = 500;
  }
  local_30[2] = (float)(*(int *)(param_1 + 0x23c) + -8);
  local_30[0] = 8.0;
  local_30[1] = 8.0;
  FUN_10038700((float *)(*(int *)(param_1 + 0x54) + 0xe64),local_24,local_18,(float *)0x0);
  FUN_10035db0(*(int *)(param_1 + 0x54),(float *)(param_1 + 4),local_30,local_24,local_18,local_c);
  iVar6 = 0x43250000;
  fVar5 = *(float *)(*(int *)(param_1 + 0x54) + 0xec0) - DAT_1006c2e4;
  lVar3 = __ftol();
  FUN_1001c740(param_1,(int *)local_c,local_24,iVar2,(int)lVar3,fVar5,iVar6,param_2);
  uVar4 = __ftol();
  if ((uVar4 & 0x2000) == 0) {
    piVar1 = (int *)(*(int *)(param_1 + 0x54) + 0x2e4 +
                    *(int *)(*(int *)(param_1 + 0x54) + 0xde8) * 4);
    *piVar1 = *piVar1 + -1;
  }
  *(float *)(*(int *)(param_1 + 0x54) + 0xec0) = DAT_1006c2e4 + (float)_DAT_10044120;
  return;
}



/* FUN_100298e0 @ 100298e0 size 267 */

void __cdecl FUN_100298e0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_1[0x97];
  if ((iVar2 != 0) && (*(undefined4 **)(iVar2 + 0x100) == param_1)) {
    *(undefined4 *)(iVar2 + 0x100) = 0;
  }
  if (DAT_1006c104 == 0x23) {
    FUN_1000e460(param_1);
    return;
  }
  if ((int)param_1[0x88] <= (int)param_1[0x8a]) {
    uVar1 = (*DAT_1006c1e4)(s_misc_udeath_wav_100493f8,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_1,2,uVar1);
    iVar2 = 2;
    do {
      FUN_1000dd30((float)param_1,s_models_objects_gibs_bone_tris_md_1004b5a4,param_4,0);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar2 = 4;
    do {
      FUN_1000dd30((float)param_1,s_models_objects_gibs_sm_meat_tris_100493d0,param_4,0);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    FUN_1000df70((float)param_1,s_models_objects_gibs_head2_tris_m_100491d4,param_4,0);
    param_1[0x8b] = 2;
    return;
  }
  if (param_1[0x8b] != 2) {
    (*DAT_1006c1d0)(param_1,2,DAT_10061280,0x3f800000,0x3f800000,0);
    param_1[0x8b] = 2;
    param_1[0x90] = 1;
    param_1[0xd6] = &DAT_100599a0;
  }
  return;
}



/* FUN_10005ce0 @ 10005ce0 size 266 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_10005ce0(uint param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  char *pcVar5;
  bool bVar6;
  
  if (*(int *)(param_1 + 0x220) < -999) {
    *(undefined4 *)(param_1 + 0x220) = 0xfffffc19;
  }
  *(int *)(param_1 + 0x25c) = param_3;
  if ((((*(byte *)(param_1 + 0xb8) & 4) != 0) && (*(int *)(param_1 + 0x22c) != 2)) &&
     ((*(uint *)(param_1 + 0x35c) & 0x100) == 0)) {
    DAT_1006c400 = DAT_1006c400 + 1;
    if ((*(float *)(DAT_1006c42c + 0x14) != _DAT_1004410c) && (*(int *)(param_3 + 0x54) != 0)) {
      piVar1 = (int *)(*(int *)(param_3 + 0x54) + 0xda8);
      *piVar1 = *piVar1 + 1;
    }
    pbVar3 = *(byte **)(param_3 + 0x118);
    pcVar5 = s_monster_medic_100465c4;
    do {
      bVar2 = *pbVar3;
      bVar6 = bVar2 < (byte)*pcVar5;
      if (bVar2 != *pcVar5) {
LAB_10005d85:
        iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_10005d8a;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar3[1];
      bVar6 = bVar2 < (byte)pcVar5[1];
      if (bVar2 != pcVar5[1]) goto LAB_10005d85;
      pbVar3 = pbVar3 + 2;
      pcVar5 = pcVar5 + 2;
    } while (bVar2 != 0);
    iVar4 = 0;
LAB_10005d8a:
    if (iVar4 == 0) {
      *(int *)(param_1 + 0x100) = param_3;
    }
  }
  iVar4 = *(int *)(param_1 + 0x104);
  if (((iVar4 != 2) && (iVar4 != 3)) &&
     ((iVar4 != 0 && (((*(byte *)(param_1 + 0xb8) & 4) != 0 && (*(int *)(param_1 + 0x22c) != 2))))))
  {
    *(undefined4 *)(param_1 + 0x1fc) = 0;
    FUN_10012570(param_1);
  }
  (**(code **)(param_1 + 0x208))(param_1,param_2,param_3,param_4,param_5);
  return;
}



/* FUN_10039a83 @ 10039a83 size 266 */

uint __cdecl FUN_10039a83(char *param_1,uint param_2,uint param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  piVar1 = param_4;
  piVar6 = (int *)(param_2 * param_3);
  if (piVar6 == (int *)0x0) {
    param_3 = 0;
  }
  else {
    piVar5 = piVar6;
    if ((*(ushort *)(param_4 + 3) & 0x10c) == 0) {
      param_4 = (int *)0x1000;
    }
    else {
      param_4 = (int *)param_4[6];
    }
    do {
      if (((piVar1[3] & 0x108U) == 0) || (piVar7 = (int *)piVar1[1], piVar7 == (int *)0x0)) {
        if (param_4 <= piVar5) {
          if (((piVar1[3] & 0x108U) != 0) && (iVar2 = FUN_1003df62(piVar1), iVar2 != 0)) {
LAB_10039b84:
            return (uint)((int)piVar6 - (int)piVar5) / param_2;
          }
          piVar7 = piVar5;
          if (param_4 != (int *)0x0) {
            piVar7 = (int *)((int)piVar5 - (uint)piVar5 % (uint)param_4);
          }
          piVar3 = (int *)FUN_1003dd44(piVar1[4],param_1,(uint)piVar7);
          if ((piVar3 == (int *)0xffffffff) ||
             (piVar5 = (int *)((int)piVar5 - (int)piVar3), piVar3 < piVar7)) {
            piVar1[3] = piVar1[3] | 0x20;
            goto LAB_10039b84;
          }
          goto LAB_10039b3b;
        }
        uVar4 = FUN_1003b304((int)*param_1,piVar1);
        if (uVar4 == 0xffffffff) goto LAB_10039b84;
        param_1 = param_1 + 1;
        param_4 = (int *)piVar1[6];
        piVar5 = (int *)((int)piVar5 - 1);
        if ((int)param_4 < 1) {
          param_4 = (int *)0x1;
        }
      }
      else {
        piVar3 = piVar5;
        if (piVar7 <= piVar5) {
          piVar3 = piVar7;
        }
        FUN_1003e070((undefined4 *)*piVar1,(undefined4 *)param_1,(uint)piVar3);
        piVar1[1] = piVar1[1] - (int)piVar3;
        *piVar1 = *piVar1 + (int)piVar3;
        piVar5 = (int *)((int)piVar5 - (int)piVar3);
LAB_10039b3b:
        param_1 = param_1 + (int)piVar3;
      }
    } while (piVar5 != (int *)0x0);
  }
  return param_3;
}



/* FUN_1003da18 @ 1003da18 size 266 */

int * __cdecl FUN_1003da18(int *param_1)

{
  bool bVar1;
  DWORD *pDVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  
  iVar4 = *param_1;
  bVar1 = false;
  pDVar2 = FUN_1003a8ad();
  if (iVar4 < 0) {
    return (int *)0x0;
  }
  if (pDVar2[0x10] == 0) {
    pvVar3 = _malloc(0x24);
    pDVar2[0x10] = (DWORD)pvVar3;
    piVar5 = (int *)&DAT_10061d80;
    if (pvVar3 == (void *)0x0) goto LAB_1003da52;
  }
  piVar5 = (int *)pDVar2[0x10];
LAB_1003da52:
  iVar8 = iVar4 % 0x7861f80;
  iVar4 = (iVar4 / 0x7861f80) * 4;
  iVar6 = iVar4 + 0x46;
  iVar9 = iVar8;
  if (0x1e1337f < iVar8) {
    iVar9 = iVar8 + -0x1e13380;
    iVar6 = iVar4 + 0x47;
    if (0x1e1337f < iVar9) {
      iVar9 = iVar8 + -0x3c26700;
      iVar6 = iVar4 + 0x48;
      if (iVar9 < 0x1e28500) {
        bVar1 = true;
      }
      else {
        iVar6 = iVar4 + 0x49;
        iVar9 = iVar8 + -0x5a4ec00;
      }
    }
  }
  piVar5[5] = iVar6;
  piVar10 = (int *)&DAT_10060730;
  piVar5[7] = iVar9 / 0x15180;
  if (!bVar1) {
    piVar10 = (int *)&DAT_10060764;
  }
  iVar4 = 1;
  piVar7 = piVar10;
  while (piVar7 = piVar7 + 1, *piVar7 < piVar5[7]) {
    iVar4 = iVar4 + 1;
  }
  piVar5[4] = iVar4 + -1;
  piVar5[3] = piVar5[7] - piVar10[iVar4 + -1];
  piVar5[6] = (*param_1 / 0x15180 + 4) % 7;
  piVar5[2] = (iVar9 % 0x15180) / 0xe10;
  iVar4 = (iVar9 % 0x15180) % 0xe10;
  piVar5[1] = iVar4 / 0x3c;
  piVar5[8] = 0;
  *piVar5 = iVar4 % 0x3c;
  return piVar5;
}



/* FUN_10015e00 @ 10015e00 size 264 */

void __cdecl FUN_10015e00(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  char *pcVar2;
  uint *puVar3;
  
  if ((*(byte *)(param_2 + 0xc) & 1) == 0) {
    puVar3 = (uint *)(*(int *)(param_2 + 4) + param_3);
    switch(*(undefined4 *)(param_2 + 8)) {
    case 0:
    case 1:
    case 4:
    case 5:
    case 0xb:
      break;
    case 2:
      uVar1 = *puVar3;
      if (uVar1 == 0) {
        *puVar3 = 0;
        return;
      }
      pcVar2 = (char *)(*DAT_1006c244)(uVar1,0x2fe);
      *puVar3 = (uint)pcVar2;
      FUN_10039b8d(pcVar2,uVar1,1,param_1);
      return;
    default:
      (*DAT_1006c1dc)(s_ReadEdict__unknown_field_type_1004a4d4);
      break;
    case 6:
      if (*puVar3 == 0xffffffff) {
        *puVar3 = 0;
        return;
      }
      *puVar3 = *puVar3 * 0x3d0 + DAT_1006c2c4;
      return;
    case 7:
      if (*puVar3 == 0xffffffff) {
        *puVar3 = 0;
        return;
      }
      *puVar3 = (uint)(&DAT_10046928 + *puVar3 * 0x12);
      return;
    case 8:
      if (*puVar3 == 0xffffffff) {
        *puVar3 = 0;
        return;
      }
      *puVar3 = DAT_1006c844 + *puVar3 * 0xf34;
      return;
    case 9:
      if (*puVar3 == 0) {
        *puVar3 = 0;
        return;
      }
      *puVar3 = (uint)(&LAB_100158d0 + *puVar3);
      return;
    case 10:
      if (*puVar3 == 0) {
        *puVar3 = 0;
        return;
      }
      *puVar3 = (uint)(&DAT_100640e0 + *puVar3);
      return;
    }
  }
  return;
}



/* FUN_100107f0 @ 100107f0 size 263 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100107f0(undefined4 *param_1)

{
  float fVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  if (param_1[0x4a] == 0) {
    puVar4 = param_1 + 0x35;
    puVar2 = FUN_1001b070();
    (*DAT_1006c1c4)(s__s_without_a_target_at__s_100494d4,param_1[0x46],puVar2,puVar4);
    FUN_1001b400(param_1);
    return;
  }
  if ((float)param_1[0x52] == _DAT_1004410c) {
    param_1[0x52] = 0x43960000;
  }
  param_1[0x41] = 2;
  param_1[0x3e] = 0;
  uVar3 = (*DAT_1006c1e0)(s_models_ships_strogg1_tris_md2_100494b4);
  param_1[10] = uVar3;
  param_1[0x2f] = 0xc1800000;
  param_1[0x30] = 0xc1800000;
  param_1[0x31] = 0;
  param_1[0x32] = 0x41800000;
  param_1[0x33] = 0x41800000;
  param_1[0x34] = 0x42000000;
  param_1[0x7d] = FUN_1000a560;
  fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
  param_1[0x80] = &LAB_100107b0;
  param_1[0x2e] = param_1[0x2e] | 1;
  param_1[0x7b] = fVar1;
  uVar3 = param_1[0x52];
  param_1[200] = uVar3;
  param_1[0xc9] = uVar3;
  param_1[199] = uVar3;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_100090f0 @ 100090f0 size 262 */

void __cdecl FUN_100090f0(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  char *pcVar5;
  bool bVar6;
  
  if ((*(uint *)(param_1 + 0x108) & 0x400) == 0) {
    if (*(int *)(param_1 + 0x310) != 0) {
      (*DAT_1006c1d0)(param_1,10,*(int *)(param_1 + 0x310),0x3f800000,0x40400000,0);
    }
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x314);
  }
  if (*(int *)(param_1 + 0x224) != 0) {
    *(undefined4 *)(param_1 + 0x240) = 1;
    *(int *)(param_1 + 0x220) = *(int *)(param_1 + 0x224);
  }
  pbVar4 = *(byte **)(param_1 + 0x118);
  *(undefined4 *)(param_1 + 0x330) = 3;
  pcVar5 = s_func_door_100466cc;
  pbVar2 = pbVar4;
  do {
    bVar1 = *pbVar2;
    bVar6 = bVar1 < (byte)*pcVar5;
    if (bVar1 != *pcVar5) {
LAB_10009188:
      iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      goto LAB_1000918d;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar6 = bVar1 < (byte)pcVar5[1];
    if (bVar1 != pcVar5[1]) goto LAB_10009188;
    pbVar2 = pbVar2 + 2;
    pcVar5 = pcVar5 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_1000918d:
  if (iVar3 == 0) {
    FUN_10006b20(param_1,(float *)(param_1 + 0x2e0),FUN_10009090);
    return;
  }
  pcVar5 = s_func_door_rotating_100466b8;
  do {
    bVar1 = *pbVar4;
    bVar6 = bVar1 < (byte)*pcVar5;
    if (bVar1 != *pcVar5) {
LAB_100091da:
      iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      goto LAB_100091df;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar4[1];
    bVar6 = bVar1 < (byte)pcVar5[1];
    if (bVar1 != pcVar5[1]) goto LAB_100091da;
    pbVar4 = pbVar4 + 2;
    pcVar5 = pcVar5 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_100091df:
  if (iVar3 == 0) {
    FUN_10006df0(param_1,FUN_10009090);
  }
  return;
}



/* FUN_10034930 @ 10034930 size 262 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10034930(int param_1)

{
  int iVar1;
  bool bVar2;
  undefined3 extraout_var;
  ulonglong uVar3;
  
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  if ((0 < *(int *)(param_1 + 0x220)) && (_DAT_1006c3a8 == _DAT_1004410c)) {
    if (DAT_1006c2e4 < *(float *)(param_1 + 0x234)) {
      bVar2 = FUN_1000c460(param_1);
      if (CONCAT31(extraout_var,bVar2) == 1) {
        *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x200;
      }
      else if (CONCAT31(extraout_var,bVar2) == 2) {
        *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x100;
        *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0x800;
      }
    }
    iVar1 = *(int *)(param_1 + 0x54);
    if (((float)DAT_1006c2e0 < *(float *)(iVar1 + 0xeac)) &&
       ((uVar3 = __ftol(), 0x1e < (int)uVar3 || ((uVar3 & 4) != 0)))) {
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x8000;
    }
    if (((float)DAT_1006c2e0 < *(float *)(iVar1 + 0xeb0)) &&
       ((uVar3 = __ftol(), 0x1e < (int)uVar3 || ((uVar3 & 4) != 0)))) {
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x10000;
    }
    if ((*(byte *)(param_1 + 0x108) & 0x10) != 0) {
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x100;
      *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0x1c00;
    }
  }
  return;
}



/* FUN_1000d350 @ 1000d350 size 261 */

void FUN_1000d350(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (0 < DAT_1006ca54) {
    puVar2 = &DAT_10046950;
    do {
      (*DAT_1006c1d8)(iVar1 + 0x420,*puVar2);
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 0x12;
    } while (iVar1 < DAT_1006ca54);
  }
  puVar2 = FUN_1000b150((byte *)s_Jacket_Armor_100461e0);
  DAT_10060e74 = (int)(puVar2 + -0x4011a4a) / 0x48;
  puVar2 = FUN_1000b150((byte *)s_Combat_Armor_100461d0);
  DAT_10060e70 = (int)(puVar2 + -0x4011a4a) / 0x48;
  puVar2 = FUN_1000b150((byte *)s_Body_Armor_100461c4);
  DAT_10060e78 = (int)(puVar2 + -0x4011a4a) / 0x48;
  puVar2 = FUN_1000b150((byte *)s_Power_Screen_10048d80);
  DAT_10060e6c = (int)(puVar2 + -0x4011a4a) / 0x48;
  puVar2 = FUN_1000b150((byte *)s_Power_Shield_100461b4);
  DAT_10060e64 = (int)(puVar2 + -0x4011a4a) / 0x48;
  return;
}



/* FUN_100235e0 @ 100235e0 size 260 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100235e0(int param_1)

{
  float fVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  if ((*(float *)(param_1 + 0x210) <= DAT_1006c2e4) &&
     (*(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4,
     *(int *)(DAT_1006c41c + 0x14) != 0x40400000)) {
    uVar2 = _rand();
    fVar1 = (float)(uVar2 & 0x7fff) * _DAT_10044108;
    if (fVar1 < (float)_DAT_10044378) {
      (*DAT_1006c1d0)(param_1,2,DAT_100610c8,0x3f800000,0x3f800000,0);
      *(undefined **)(param_1 + 0x358) = &DAT_10050398;
      return;
    }
    if (fVar1 < (float)_DAT_10044370) {
      (*DAT_1006c1d0)(param_1,2,DAT_100610c0);
      *(undefined **)(param_1 + 0x358) = &DAT_10050288;
      return;
    }
    (*DAT_1006c1d0)(param_1,2,DAT_100610c8,0x3f800000,0x3f800000,0);
    *(undefined **)(param_1 + 0x358) = &DAT_10050218;
  }
  return;
}



/* FUN_1002b580 @ 1002b580 size 260 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1002b580(int param_1)

{
  float fVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  if ((*(float *)(param_1 + 0x210) <= DAT_1006c2e4) &&
     (*(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4,
     *(int *)(DAT_1006c41c + 0x14) != 0x40400000)) {
    uVar2 = _rand();
    fVar1 = (float)(uVar2 & 0x7fff) * _DAT_10044108;
    if (fVar1 < (float)_DAT_10044378) {
      (*DAT_1006c1d0)(param_1,2,DAT_100612c8,0x3f800000,0x3f800000,0);
      *(undefined **)(param_1 + 0x358) = &DAT_1005a450;
      return;
    }
    if (fVar1 < (float)_DAT_10044370) {
      (*DAT_1006c1d0)(param_1,2,DAT_100612c0);
      *(undefined **)(param_1 + 0x358) = &DAT_1005a4a8;
      return;
    }
    (*DAT_1006c1d0)(param_1,2,DAT_100612c8,0x3f800000,0x3f800000,0);
    *(undefined **)(param_1 + 0x358) = &DAT_1005a540;
  }
  return;
}



/* FUN_10037cd0 @ 10037cd0 size 259 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10037cd0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_1 + 0x54) != 0) {
    if (*(float *)(*(int *)(param_1 + 0x54) + 0xf2c) + (float)_DAT_10044120 < DAT_1006c2e4) {
      puVar3 = FUN_1000b150((byte *)s_PistolPlasma_10048ca0);
      iVar1 = *(int *)(param_1 + 0x54);
      iVar2 = *(int *)(iVar1 + 0x2e4 + ((int)(puVar3 + -0x4011a4a) / 0x48) * 4);
      if (iVar2 < *(int *)(iVar1 + 0x700)) {
        *(int *)(iVar1 + 0x2e4 + ((int)(puVar3 + -0x4011a4a) / 0x48) * 4) = iVar2 + 1;
      }
      *(float *)(*(int *)(param_1 + 0x54) + 0xf2c) = DAT_1006c2e4;
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0x710);
    if ((iVar1 != 0) &&
       ((float)_DAT_10044120 / (float)iVar1 + *(float *)(*(int *)(param_1 + 0x54) + 0xf30) <
        DAT_1006c2e4)) {
      puVar3 = FUN_1000b150((byte *)s_Rifle_Plasma_100461a4);
      iVar1 = *(int *)(param_1 + 0x54);
      iVar2 = *(int *)(iVar1 + 0x2e4 + ((int)(puVar3 + -0x4011a4a) / 0x48) * 4);
      if (iVar2 < *(int *)(iVar1 + 0x704)) {
        *(int *)(iVar1 + 0x2e4 + ((int)(puVar3 + -0x4011a4a) / 0x48) * 4) = iVar2 + 1;
      }
      *(float *)(*(int *)(param_1 + 0x54) + 0xf30) = DAT_1006c2e4;
    }
  }
  return;
}



/* FUN_10042b80 @ 10042b80 size 257 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10042b80(byte *param_1,char *param_2,void *param_3)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  undefined4 uVar6;
  void *this;
  uint uVar7;
  bool bVar8;
  uint uVar9;
  
  iVar2 = _DAT_1006cdd8;
  uVar6 = 0;
  if (param_3 != (void *)0x0) {
    if (DAT_10061db8 == 0) {
      do {
        bVar3 = *param_1;
        cVar1 = *param_2;
        uVar4 = CONCAT11(bVar3,cVar1);
        if (bVar3 == 0) break;
        uVar4 = CONCAT11(bVar3,cVar1);
        uVar7 = (uint)uVar4;
        if (cVar1 == '\0') break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        if ((0x40 < bVar3) && (bVar3 < 0x5b)) {
          uVar7 = (uint)CONCAT11(bVar3 + 0x20,cVar1);
        }
        uVar4 = (ushort)uVar7;
        bVar3 = (byte)uVar7;
        if ((0x40 < bVar3) && (bVar3 < 0x5b)) {
          uVar4 = (ushort)CONCAT31((int3)(uVar7 >> 8),bVar3 + 0x20);
        }
        bVar3 = (byte)(uVar4 >> 8);
        bVar8 = bVar3 < (byte)uVar4;
        if (bVar3 != (byte)uVar4) goto LAB_10042bdf;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar6 = 0;
      bVar3 = (byte)(uVar4 >> 8);
      bVar8 = bVar3 < (byte)uVar4;
      if (bVar3 != (byte)uVar4) {
LAB_10042bdf:
        uVar6 = 0xffffffff;
        if (!bVar8) {
          uVar6 = 1;
        }
      }
    }
    else {
      LOCK();
      _DAT_1006cdd8 = _DAT_1006cdd8 + 1;
      UNLOCK();
      bVar8 = 0 < DAT_1006cdd4;
      if (bVar8) {
        LOCK();
        UNLOCK();
        _DAT_1006cdd8 = iVar2;
        FUN_1003c8a1(0x13);
      }
      uVar9 = (uint)bVar8;
      uVar5 = 0;
      uVar7 = 0;
      do {
        uVar5 = CONCAT31((int3)(uVar5 >> 8),*param_1);
        uVar7 = CONCAT31((int3)(uVar7 >> 8),*param_2);
        if ((uVar5 == 0) || (uVar7 == 0)) break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        uVar7 = FUN_1003ef62(param_3,uVar7);
        uVar5 = FUN_1003ef62(this,uVar5);
        bVar8 = uVar5 < uVar7;
        if (uVar5 != uVar7) goto LAB_10042c55;
        param_3 = (void *)((int)param_3 + -1);
      } while (param_3 != (void *)0x0);
      uVar6 = 0;
      bVar8 = uVar5 < uVar7;
      if (uVar5 != uVar7) {
LAB_10042c55:
        uVar6 = 0xffffffff;
        if (!bVar8) {
          uVar6 = 1;
        }
      }
      if (uVar9 == 0) {
        LOCK();
        _DAT_1006cdd8 = _DAT_1006cdd8 + -1;
        UNLOCK();
      }
      else {
        FUN_1003c902(0x13);
      }
    }
  }
  return uVar6;
}



/* FUN_100103f0 @ 100103f0 size 256 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100103f0(undefined4 *param_1)

{
  float fVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  if (param_1[0x4a] == 0) {
    puVar4 = param_1 + 0x35;
    puVar2 = FUN_1001b070();
    (*DAT_1006c1c4)(s_misc_viper_without_a_target_at___10049444,puVar2,puVar4);
    FUN_1001b400(param_1);
    return;
  }
  if ((float)param_1[0x52] == _DAT_1004410c) {
    param_1[0x52] = 0x43960000;
  }
  param_1[0x41] = 2;
  param_1[0x3e] = 0;
  uVar3 = (*DAT_1006c1e0)(s_models_ships_viper_tris_md2_10049428);
  param_1[10] = uVar3;
  param_1[0x2f] = 0xc1800000;
  param_1[0x30] = 0xc1800000;
  param_1[0x31] = 0;
  param_1[0x32] = 0x41800000;
  param_1[0x33] = 0x41800000;
  param_1[0x34] = 0x42000000;
  param_1[0x7d] = FUN_1000a560;
  fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
  param_1[0x80] = &LAB_100107b0;
  param_1[0x2e] = param_1[0x2e] | 1;
  param_1[0x7b] = fVar1;
  uVar3 = param_1[0x52];
  param_1[200] = uVar3;
  param_1[0xc9] = uVar3;
  param_1[199] = uVar3;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10011c90 @ 10011c90 size 256 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10011c90(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_7c;
  undefined4 local_78;
  float local_74;
  int aiStack_70 [4];
  undefined4 uStack_60;
  undefined4 uStack_5c;
  float fStack_50;
  int iStack_3c;
  undefined1 local_38 [56];
  
  if ((*(byte *)(param_1 + 0x108) & 3) == 0) {
    if (_DAT_10044130 < *(float *)(param_1 + 0x180)) {
      *(undefined4 *)(param_1 + 0x268) = 0;
      return;
    }
    local_7c = *(undefined4 *)(param_1 + 4);
    local_78 = *(undefined4 *)(param_1 + 8);
    local_74 = *(float *)(param_1 + 0xc) - (float)_DAT_10044230;
    piVar2 = (int *)(*DAT_1006c1f0)(local_38,(undefined4 *)(param_1 + 4),param_1 + 0xbc,
                                    param_1 + 200,&local_7c,param_1,0x2020003);
    piVar4 = aiStack_70;
    for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar4 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar4 = piVar4 + 1;
    }
    if ((float)_DAT_10044228 <= fStack_50) {
      if ((aiStack_70[1] == 0) && (aiStack_70[0] == 0)) {
        *(undefined4 *)(param_1 + 4) = aiStack_70[3];
        *(undefined4 *)(param_1 + 8) = uStack_60;
        *(undefined4 *)(param_1 + 0xc) = uStack_5c;
        *(int *)(param_1 + 0x268) = iStack_3c;
        uVar1 = *(undefined4 *)(iStack_3c + 0x5c);
        *(undefined4 *)(param_1 + 0x180) = 0;
        *(undefined4 *)(param_1 + 0x26c) = uVar1;
      }
    }
    else if (aiStack_70[1] == 0) {
      *(undefined4 *)(param_1 + 0x268) = 0;
      return;
    }
  }
  return;
}



/* FUN_10026830 @ 10026830 size 255 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10026830(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  if (*(float *)(param_1 + 0x210) <= DAT_1006c2e4) {
    *(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4;
    uVar1 = _rand();
    uVar2 = DAT_100611c0;
    if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044140) {
      uVar2 = DAT_100611c4;
    }
    (*DAT_1006c1d0)(param_1,2,uVar2,0x3f800000,0x3f800000,0);
    if (*(int *)(DAT_1006c41c + 0x14) != 0x40400000) {
      if (_DAT_10044130 < *(float *)(param_1 + 0x180)) {
        *(undefined **)(param_1 + 0x358) = &DAT_10054f50;
        return;
      }
      *(undefined **)(param_1 + 0x358) = &DAT_10054ee8;
    }
  }
  else if ((_DAT_10044130 < *(float *)(param_1 + 0x180)) &&
          (*(undefined **)(param_1 + 0x358) == &DAT_10054ee8)) {
    *(undefined **)(param_1 + 0x358) = &DAT_10054f50;
    return;
  }
  return;
}



/* FUN_10016750 @ 10016750 size 254 */

void __cdecl FUN_10016750(undefined4 *param_1)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  undefined **ppuVar8;
  bool bVar9;
  
  pbVar2 = (byte *)param_1[0x46];
  if (pbVar2 == (byte *)0x0) {
    (*DAT_1006c1c4)(s_ED_CallSpawn__NULL_classname_1004b304);
    return;
  }
  iVar5 = 0;
  puVar7 = &DAT_10046928;
  if (0 < DAT_1006ca54) {
    do {
      pbVar3 = (byte *)*puVar7;
      pbVar6 = pbVar2;
      if (pbVar3 != (byte *)0x0) {
        do {
          bVar1 = *pbVar3;
          bVar9 = bVar1 < *pbVar6;
          if (bVar1 != *pbVar6) {
LAB_100167b8:
            iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
            goto LAB_100167bd;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar3[1];
          bVar9 = bVar1 < pbVar6[1];
          if (bVar1 != pbVar6[1]) goto LAB_100167b8;
          pbVar3 = pbVar3 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar1 != 0);
        iVar4 = 0;
LAB_100167bd:
        if (iVar4 == 0) {
          FUN_1000cf20(param_1,puVar7);
          return;
        }
      }
      iVar5 = iVar5 + 1;
      puVar7 = puVar7 + 0x12;
    } while (iVar5 < DAT_1006ca54);
  }
  ppuVar8 = &PTR_s_item_health_1004a5c0;
  pbVar3 = PTR_s_item_health_1004a5c0;
  do {
    pbVar6 = pbVar2;
    if (pbVar3 == (byte *)0x0) {
      (*DAT_1006c1c4)(s__s_doesn_t_have_a_spawn_function_1004b2e0,pbVar2);
      return;
    }
    do {
      bVar1 = *pbVar3;
      bVar9 = bVar1 < *pbVar6;
      if (bVar1 != *pbVar6) {
LAB_10016815:
        iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_1001681a;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar9 = bVar1 < pbVar6[1];
      if (bVar1 != pbVar6[1]) goto LAB_10016815;
      pbVar3 = pbVar3 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_1001681a:
    if (iVar5 == 0) {
      (*(code *)ppuVar8[1])(param_1);
      return;
    }
    pbVar3 = ppuVar8[2];
    ppuVar8 = ppuVar8 + 2;
  } while( true );
}



/* FUN_10030460 @ 10030460 size 254 */

void __cdecl FUN_10030460(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(param_1 + 0xbc);
  for (iVar2 = 0x19d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  puVar1 = FUN_1000b150((byte *)s_Plasma_Pistol_10048cb0);
  *(int *)(param_1 + 0x2e0) = (int)(puVar1 + -0x4011a4a) / 0x48;
  *(undefined4 *)(param_1 + 0x2e4 + ((int)(puVar1 + -0x4011a4a) / 0x48) * 4) = 1;
  *(undefined4 **)(param_1 + 0x714) = puVar1;
  puVar1 = FUN_1000b150((byte *)s_PistolPlasma_10048ca0);
  *(undefined4 *)(param_1 + 0x2e4 + ((int)(puVar1 + -0x4011a4a) / 0x48) * 4) = 0x32;
  *(undefined4 *)(param_1 + 0x2d4) = 100;
  *(undefined4 *)(param_1 + 0x2d8) = 100;
  *(undefined4 *)(param_1 + 0x6e4) = 200;
  *(undefined4 *)(param_1 + 0x6e8) = 100;
  *(undefined4 *)(param_1 + 0x6ec) = 0x32;
  *(undefined4 *)(param_1 + 0x6f0) = 0x32;
  *(undefined4 *)(param_1 + 0x6f4) = 0x19;
  *(undefined4 *)(param_1 + 0x6f8) = 200;
  *(undefined4 *)(param_1 + 0x6fc) = 0x32;
  *(undefined4 *)(param_1 + 0x700) = 0x32;
  *(undefined4 *)(param_1 + 0x704) = 0x32;
  *(undefined4 *)(param_1 + 0x708) = 10;
  *(undefined4 *)(param_1 + 0x70c) = 2;
  *(undefined4 *)(param_1 + 0x710) = 0;
  *(undefined4 *)(param_1 + 0x2d0) = 1;
  return;
}



/* _strncpy @ 10039dc0 size 254 */

/* Library Function - Single Match
    _strncpy
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strncpy(char *_Dest,char *_Source,size_t _Count)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  
  if (_Count == 0) {
    return _Dest;
  }
  puVar5 = (uint *)_Dest;
  if (((uint)_Source & 3) != 0) {
    while( true ) {
      uVar4 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 1);
      *(char *)puVar5 = (char)uVar4;
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
      if (_Count == 0) {
        return _Dest;
      }
      if ((char)uVar4 == '\0') break;
      if (((uint)_Source & 3) == 0) {
        uVar4 = _Count >> 2;
        goto joined_r0x10039dfe;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_10039e3b;
        goto LAB_10039ea9;
      }
      *(char *)puVar5 = '\0';
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
    } while (_Count != 0);
    return _Dest;
  }
  uVar4 = _Count >> 2;
  if (uVar4 != 0) {
    do {
      uVar1 = *(uint *)_Source;
      uVar2 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 4);
      if (((uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uVar2 == '\0') {
          *puVar5 = 0;
joined_r0x10039ea5:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_10039ea9:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_10039e3b;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x10039ea5;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x10039ea5;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x10039ea5;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x10039dfe:
    } while (uVar4 != 0);
    _Count = _Count & 3;
    if (_Count == 0) {
      return _Dest;
    }
  }
  do {
    cVar3 = (char)*(uint *)_Source;
    _Source = (char *)((int)_Source + 1);
    *(char *)puVar5 = cVar3;
    puVar5 = (uint *)((int)puVar5 + 1);
    if (cVar3 == '\0') {
      while (_Count = _Count - 1, _Count != 0) {
LAB_10039e3b:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}



/* FUN_1000bdf0 @ 1000bdf0 size 253 */

undefined4 __cdecl FUN_1000bdf0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x54);
  if (iVar2 != 0) {
    iVar4 = *(int *)(param_2 + 0x40);
    if (iVar4 == 0) {
      iVar4 = *(int *)(iVar2 + 0x6e4);
    }
    else if (iVar4 == 1) {
      iVar4 = *(int *)(iVar2 + 0x6e8);
    }
    else if (iVar4 == 2) {
      iVar4 = *(int *)(iVar2 + 0x6ec);
    }
    else if (iVar4 == 3) {
      iVar4 = *(int *)(iVar2 + 0x6f0);
    }
    else if (iVar4 == 4) {
      iVar4 = *(int *)(iVar2 + 0x6f4);
    }
    else if (iVar4 == 5) {
      iVar4 = *(int *)(iVar2 + 0x6f8);
    }
    else if (iVar4 == 6) {
      iVar4 = *(int *)(iVar2 + 0x6fc);
    }
    else if (iVar4 == 7) {
      iVar4 = *(int *)(iVar2 + 0x700);
    }
    else if (iVar4 == 8) {
      iVar4 = *(int *)(iVar2 + 0x704);
    }
    else if (iVar4 == 9) {
      iVar4 = *(int *)(iVar2 + 0x708);
    }
    else {
      if (iVar4 != 10) {
        (*DAT_1006c1c4)(s_Couldn_t_get_max_10048f50);
        return 0;
      }
      iVar4 = *(int *)(iVar2 + 0x70c);
    }
    iVar1 = ((param_2 + -0x10046928) / 0x48) * 4 + 0x2e4;
    if (*(int *)(iVar1 + iVar2) != iVar4) {
      *(int *)(iVar1 + iVar2) = *(int *)(iVar1 + iVar2) + param_3;
      piVar3 = (int *)(iVar1 + *(int *)(param_1 + 0x54));
      if (iVar4 < *piVar3) {
        *piVar3 = iVar4;
      }
      return 1;
    }
  }
  return 0;
}



/* FUN_10027730 @ 10027730 size 252 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10027730(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  if ((*(float *)(param_1 + 0x210) <= DAT_1006c2e4) &&
     (*(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4,
     *(int *)(DAT_1006c41c + 0x14) != 0x40400000)) {
    if (param_4 < 0x1a) {
      uVar1 = _rand();
      if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044140) {
        (*DAT_1006c1d0)(param_1,2,DAT_10061204);
        *(undefined **)(param_1 + 0x358) = &DAT_10056100;
        return;
      }
      (*DAT_1006c1d0)(param_1,2,DAT_10061200,0x3f800000,0x3f800000,0);
      *(undefined **)(param_1 + 0x358) = &DAT_100561a0;
      return;
    }
    (*DAT_1006c1d0)(param_1,2,DAT_10061204,0x3f800000,0x3f800000,0);
    *(undefined **)(param_1 + 0x358) = &DAT_10056300;
  }
  return;
}



/* FUN_1000d770 @ 1000d770 size 251 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000d770(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  
  if (_DAT_1006c3a8 != _DAT_1004410c) {
    return;
  }
  if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
    return;
  }
  if ((*(float *)(DAT_1006c428 + 0x14) == _DAT_1004410c) ||
     (DAT_1006c2e4 < *(float *)(DAT_1006c428 + 0x14) * _DAT_100441c0)) {
    if (*(float *)(DAT_1006c180 + 0x14) == _DAT_1004410c) {
      return;
    }
    iVar3 = 0;
    if (*(float *)(DAT_1006ca60 + 0x14) <= _DAT_1004410c) {
      return;
    }
    piVar2 = (int *)(DAT_1006c844 + 0xda8);
    piVar1 = (int *)(DAT_1006c2c4 + 0x428);
    while ((*piVar1 == 0 || ((float)*piVar2 < *(float *)(DAT_1006c180 + 0x14)))) {
      iVar3 = iVar3 + 1;
      piVar1 = piVar1 + 0xf4;
      piVar2 = piVar2 + 0x3cd;
      if (*(float *)(DAT_1006ca60 + 0x14) <= (float)iVar3) {
        return;
      }
    }
    pcVar4 = s_Fraglimit_hit__10049170;
  }
  else {
    pcVar4 = s_Timelimit_hit__10049180;
  }
  (*DAT_1006c1c0)(2,pcVar4);
  FUN_1000d650();
  return;
}



/* FUN_1003d065 @ 1003d065 size 251 */

int __cdecl FUN_1003d065(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  LPVOID pvVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *lpAddress;
  
  iVar3 = *(int *)(param_1 + 0x10);
  iVar9 = 0;
  for (iVar4 = *(int *)(param_1 + 8); -1 < iVar4; iVar4 = iVar4 << 1) {
    iVar9 = iVar9 + 1;
  }
  iVar8 = 0x3f;
  iVar4 = iVar9 * 0x204 + 0x144 + iVar3;
  iVar5 = iVar4;
  do {
    *(int *)(iVar5 + 8) = iVar5;
    *(int *)(iVar5 + 4) = iVar5;
    iVar5 = iVar5 + 8;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  lpAddress = (int *)(iVar9 * 0x8000 + *(int *)(param_1 + 0xc));
  pvVar6 = VirtualAlloc(lpAddress,0x8000,0x1000,4);
  if (pvVar6 == (LPVOID)0x0) {
    iVar9 = -1;
  }
  else {
    if (lpAddress <= lpAddress + 0x1c00) {
      piVar7 = lpAddress + 4;
      do {
        piVar7[-2] = -1;
        piVar7[0x3fb] = -1;
        piVar7[-1] = 0xff0;
        *piVar7 = (int)(piVar7 + 0x3ff);
        piVar7[1] = (int)(piVar7 + -0x401);
        piVar7[0x3fa] = 0xff0;
        piVar1 = piVar7 + 0x3fc;
        piVar7 = piVar7 + 0x400;
      } while (piVar1 <= lpAddress + 0x1c00);
    }
    *(int **)(iVar4 + 0x1fc) = lpAddress + 3;
    lpAddress[5] = iVar4 + 0x1f8;
    *(int **)(iVar4 + 0x200) = lpAddress + 0x1c03;
    lpAddress[0x1c04] = iVar4 + 0x1f8;
    *(undefined4 *)(iVar3 + 0x44 + iVar9 * 4) = 0;
    *(undefined4 *)(iVar3 + 0xc4 + iVar9 * 4) = 1;
    cVar2 = *(char *)(iVar3 + 0x43);
    *(char *)(iVar3 + 0x43) = cVar2 + '\x01';
    if (cVar2 == '\0') {
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
    }
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & ~(0x80000000U >> ((byte)iVar9 & 0x1f));
  }
  return iVar9;
}



/* FUN_10015c90 @ 10015c90 size 250 */

uint __cdecl FUN_10015c90(undefined4 param_1,uint param_2,int param_3)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  char *pcVar6;
  
  if ((*(byte *)(param_2 + 0xc) & 1) == 0) {
    piVar1 = (int *)(param_2 + 4);
    param_2 = *(uint *)(param_2 + 8);
    puVar5 = (uint *)(*piVar1 + param_3);
    switch(param_2) {
    case 0:
    case 1:
    case 4:
    case 5:
    case 0xb:
      break;
    case 2:
    case 3:
      if ((char *)*puVar5 == (char *)0x0) {
        *puVar5 = 0;
        return param_2;
      }
      uVar4 = 0xffffffff;
      pcVar6 = (char *)*puVar5;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar2 != '\0');
      *puVar5 = ~uVar4;
      return 0;
    case 6:
      if (*puVar5 != 0) {
        iVar3 = *puVar5 - DAT_1006c2c4;
        *puVar5 = iVar3 / 0x3d0;
        return -(iVar3 >> 0x1f);
      }
      *puVar5 = 0xffffffff;
      return 0;
    case 7:
      if (*puVar5 != 0) {
        iVar3 = *puVar5 + 0xeffb96d8;
        *puVar5 = iVar3 / 0x48;
        return -(iVar3 >> 0x1f);
      }
      *puVar5 = 0xffffffff;
      return 0;
    case 8:
      if (*puVar5 != 0) {
        iVar3 = *puVar5 - DAT_1006c844;
        *puVar5 = iVar3 / 0xf34;
        return iVar3 * 0x10d6b155;
      }
      *puVar5 = 0xffffffff;
      return 0;
    case 9:
      if (*puVar5 != 0) {
        uVar4 = *puVar5 + 0xeffea730;
        *puVar5 = uVar4;
        return uVar4;
      }
      *puVar5 = 0;
      return 0;
    case 10:
      if (*puVar5 != 0) {
        uVar4 = *puVar5 + 0xeff9bf20;
        *puVar5 = uVar4;
        return uVar4;
      }
      *puVar5 = 0;
      return 0;
    default:
      param_2 = (*DAT_1006c1dc)(s_WriteEdict__unknown_field_type_1004a4b4);
    }
  }
  return param_2;
}



/* FUN_10023c30 @ 10023c30 size 250 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10023c30(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  float fVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  if (*(float *)(param_1 + 0x210) <= DAT_1006c2e4) {
    *(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4;
    uVar2 = _rand();
    fVar1 = (float)(uVar2 & 0x7fff) * _DAT_10044108;
    uVar3 = DAT_10061108;
    if (((float)_DAT_10044378 <= fVar1) && (uVar3 = DAT_10061104, fVar1 < (float)_DAT_10044370)) {
      uVar3 = DAT_10061100;
    }
    (*DAT_1006c1d0)(param_1,2,uVar3,0x3f800000,0x3f800000,0);
    if (*(int *)(DAT_1006c41c + 0x14) != 0x40400000) {
      if (param_4 < 0xb) {
        *(undefined **)(param_1 + 0x358) = &DAT_10050db0;
        return;
      }
      if (param_4 < 0x1a) {
        *(undefined **)(param_1 + 0x358) = &DAT_10050e00;
        return;
      }
      *(undefined **)(param_1 + 0x358) = &DAT_10050f10;
    }
  }
  return;
}



/* FUN_100122c0 @ 100122c0 size 247 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100122c0(int param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  
  iVar2 = *(int *)(param_1 + 0x360);
  piVar3 = *(int **)(param_1 + 0x358);
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  if (((iVar2 == 0) || (iVar2 < *piVar3)) || (piVar3[1] < iVar2)) {
    if ((*(int *)(param_1 + 0x38) == piVar3[1]) && ((code *)piVar3[3] != (code *)0x0)) {
      (*(code *)piVar3[3])(param_1);
      piVar3 = *(int **)(param_1 + 0x358);
      if ((*(byte *)(param_1 + 0xb8) & 2) != 0) {
        return;
      }
    }
    iVar2 = *(int *)(param_1 + 0x38);
    if ((iVar2 < *piVar3) || (piVar3[1] < iVar2)) {
      *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) & 0xffffff7f;
      *(int *)(param_1 + 0x38) = *piVar3;
    }
    else if (((*(byte *)(param_1 + 0x35c) & 0x80) == 0) &&
            (*(int *)(param_1 + 0x38) = iVar2 + 1, piVar3[1] < iVar2 + 1)) {
      *(int *)(param_1 + 0x38) = *piVar3;
    }
  }
  else {
    *(int *)(param_1 + 0x38) = iVar2;
    *(undefined4 *)(param_1 + 0x360) = 0;
  }
  iVar2 = (*(int *)(param_1 + 0x38) - *piVar3) * 0xc;
  pcVar1 = *(code **)(piVar3[2] + iVar2);
  if (pcVar1 != (code *)0x0) {
    if ((*(byte *)(param_1 + 0x35c) & 0x80) == 0) {
      fVar4 = *(float *)(piVar3[2] + iVar2 + 4) * *(float *)(param_1 + 0x364);
    }
    else {
      fVar4 = 0.0;
    }
    (*pcVar1)(param_1,fVar4);
  }
  pcVar1 = *(code **)(piVar3[2] + 8 + iVar2);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(param_1);
  }
  return;
}



/* FUN_10001ac0 @ 10001ac0 size 245 */

void __cdecl FUN_10001ac0(int param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  
  if (*(int *)(*(int *)(param_1 + 0x25c) + 0x54) != 0) {
    DAT_1006c3d0 = param_1;
    DAT_1006c3d4 = DAT_1006c2e0;
    *(undefined4 *)(param_1 + 0x2c4) = 0x80;
  }
  lVar3 = __ftol();
  *(int *)(param_1 + 0x230) = (int)lVar3;
  iVar1 = *(int *)(param_1 + 0x25c);
  *(undefined4 *)(param_1 + 0x3ac) = *(undefined4 *)(iVar1 + 4);
  *(undefined4 *)(param_1 + 0x3b0) = *(undefined4 *)(iVar1 + 8);
  *(undefined4 *)(param_1 + 0x3b4) = *(undefined4 *)(iVar1 + 0xc);
  *(undefined4 *)(param_1 + 0x3a8) = DAT_1006c2e4;
  if (*(byte **)(param_1 + 0x140) == (byte *)0x0) {
    FUN_10001690(param_1);
    return;
  }
  uVar2 = FUN_1001ad80(*(byte **)(param_1 + 0x140));
  *(uint *)(param_1 + 0x1e0) = uVar2;
  *(uint *)(param_1 + 0x1dc) = uVar2;
  if (uVar2 == 0) {
    *(undefined4 *)(param_1 + 0x1e0) = *(undefined4 *)(param_1 + 0x25c);
    *(undefined4 *)(param_1 + 0x1dc) = *(undefined4 *)(param_1 + 0x25c);
    FUN_10001690(param_1);
    return;
  }
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) | 0x1000;
  *(undefined4 *)(uVar2 + 300) = 0;
  *(undefined4 *)(param_1 + 0x390) = 0;
  (**(code **)(param_1 + 0x378))(param_1);
  return;
}



/* FUN_10030060 @ 10030060 size 242 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10030060(int param_1,int param_2,int param_3)

{
  int iVar1;
  float10 fVar2;
  float fVar3;
  float10 fVar4;
  
  if ((((param_3 == 0) || (param_3 == DAT_1006c2c4)) || (param_3 == param_1)) &&
     (((param_2 == 0 || (param_2 == DAT_1006c2c4)) || (param_3 = param_2, param_2 == param_1)))) {
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe1c) = *(undefined4 *)(param_1 + 0x14);
  }
  else {
    fVar3 = *(float *)(param_3 + 4) - *(float *)(param_1 + 4);
    fVar4 = (float10)*(float *)(param_3 + 8) - (float10)*(float *)(param_1 + 8);
    if (fVar3 == _DAT_1004410c) {
      fVar2 = (float10)_DAT_1004410c;
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe1c) = 0;
      if (fVar4 <= fVar2) {
        if (fVar4 < (float10)_DAT_1004410c) {
          *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe1c) = 0xc2b40000;
        }
      }
      else {
        *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe1c) = 0x42b40000;
      }
    }
    else {
      fVar4 = (float10)fpatan(fVar4,(float10)fVar3);
      *(float *)(*(int *)(param_1 + 0x54) + 0xe1c) = (float)(fVar4 * (float10)_DAT_100442c8);
    }
    iVar1 = *(int *)(param_1 + 0x54);
    if (*(float *)(iVar1 + 0xe1c) < _DAT_1004410c) {
      *(float *)(iVar1 + 0xe1c) = *(float *)(iVar1 + 0xe1c) + _DAT_100442b0;
      return;
    }
  }
  return;
}



/* FUN_100149d0 @ 100149d0 size 241 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100149d0(int param_1)

{
  int iVar1;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(float *)(param_1 + 0x34c) == _DAT_1004410c) {
    FUN_10014940(param_1);
    return;
  }
  FUN_10038a20((float *)(param_1 + 0x334),*(float *)(param_1 + 0x34c) * (float)_DAT_10044170,
               (float *)(param_1 + 0x178));
  iVar1 = FUN_100388c0((float *)(param_1 + 0x1d0),(float *)&DAT_10061c18);
  if (iVar1 == 0) {
    local_c = *(float *)(param_1 + 0x304) - *(float *)(param_1 + 0x10);
    local_8 = *(float *)(param_1 + 0x308) - *(float *)(param_1 + 0x14);
    local_4 = *(float *)(param_1 + 0x30c) - *(float *)(param_1 + 0x18);
    iVar1 = FUN_100388c0(&local_c,(float *)&DAT_10061c18);
    if (iVar1 == 0) {
      FUN_10038a20(&local_c,10.0,(float *)(param_1 + 0x184));
    }
    else {
      *(undefined4 *)(param_1 + 0x18c) = 0;
      *(undefined4 *)(param_1 + 0x188) = 0;
      *(undefined4 *)(param_1 + 0x184) = 0;
    }
  }
  *(code **)(param_1 + 500) = FUN_10014940;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  return;
}



/* FUN_10006b20 @ 10006b20 size 239 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10006b20(int param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  
  *(undefined4 *)(param_1 + 0x180) = 0;
  *(undefined4 *)(param_1 + 0x17c) = 0;
  *(undefined4 *)(param_1 + 0x178) = 0;
  *(float *)(param_1 + 0x334) = *param_2 - *(float *)(param_1 + 4);
  *(float *)(param_1 + 0x338) = param_2[1] - *(float *)(param_1 + 8);
  *(float *)(param_1 + 0x33c) = param_2[2] - *(float *)(param_1 + 0xc);
  fVar3 = (float10)FUN_10038900((float *)(param_1 + 0x334));
  *(float *)(param_1 + 0x34c) = (float)fVar3;
  *(undefined4 *)(param_1 + 0x354) = param_3;
  if ((*(float *)(param_1 + 800) != *(float *)(param_1 + 0x31c)) ||
     (*(float *)(param_1 + 800) != *(float *)(param_1 + 0x324))) {
    *(undefined4 *)(param_1 + 0x340) = 0;
    *(code **)(param_1 + 500) = FUN_10007050;
    *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
    return;
  }
  iVar2 = param_1;
  if ((*(uint *)(param_1 + 0x108) & 0x400) != 0) {
    iVar2 = *(int *)(param_1 + 0x274);
  }
  if (DAT_1006c404 != iVar2) {
    fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
    *(code **)(param_1 + 500) = FUN_10006a70;
    *(float *)(param_1 + 0x1ec) = fVar1;
    return;
  }
  FUN_10006a70(param_1);
  return;
}



/* FUN_10006d00 @ 10006d00 size 239 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10006d00(int param_1)

{
  float fVar1;
  float10 fVar2;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(int *)(param_1 + 0x330) == 2) {
    local_c = *(float *)(param_1 + 0x304) - *(float *)(param_1 + 0x10);
    local_8 = *(float *)(param_1 + 0x308) - *(float *)(param_1 + 0x14);
    local_4 = *(float *)(param_1 + 0x30c);
  }
  else {
    local_c = *(float *)(param_1 + 0x2ec) - *(float *)(param_1 + 0x10);
    local_8 = *(float *)(param_1 + 0x2f0) - *(float *)(param_1 + 0x14);
    local_4 = *(float *)(param_1 + 0x2f4);
  }
  local_4 = local_4 - *(float *)(param_1 + 0x18);
  fVar2 = FUN_100389f0(&local_c);
  fVar2 = fVar2 / (float10)*(float *)(param_1 + 800);
  fVar1 = (float)fVar2;
  if (fVar2 < (float10)_DAT_10044168) {
    FUN_10006c40(param_1);
    return;
  }
  fVar2 = FUN_1003900b((double)(fVar1 * (float)_DAT_10044170));
  FUN_10038a20(&local_c,(float)_DAT_10044120 / fVar1,(float *)(param_1 + 0x184));
  fVar1 = (float)fVar2 * (float)_DAT_10044168 + DAT_1006c2e4;
  *(code **)(param_1 + 500) = FUN_10006c40;
  *(float *)(param_1 + 0x1ec) = fVar1;
  return;
}



/* FUN_10010a50 @ 10010a50 size 239 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10010a50(int param_1)

{
  uint uVar1;
  
  (*DAT_1006c1ec)(param_1,s_models_objects_gibs_arm_tris_md2_10049564);
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 2;
  *(undefined4 *)(param_1 + 0x240) = 1;
  *(undefined1 **)(param_1 + 0x208) = &LAB_1000fd20;
  *(undefined4 *)(param_1 + 0x104) = 7;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 4;
  *(undefined4 *)(param_1 + 0x22c) = 2;
  uVar1 = _rand();
  *(float *)(param_1 + 0x184) = (float)(uVar1 & 0x7fff) * _DAT_10044108 * _DAT_100441e8;
  uVar1 = _rand();
  *(float *)(param_1 + 0x188) = (float)(uVar1 & 0x7fff) * _DAT_10044108 * _DAT_100441e8;
  uVar1 = _rand();
  *(code **)(param_1 + 500) = FUN_1001b400;
  *(float *)(param_1 + 0x18c) = (float)(uVar1 & 0x7fff) * _DAT_10044108 * _DAT_100441e8;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + _DAT_10044220;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10010b40 @ 10010b40 size 239 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10010b40(int param_1)

{
  uint uVar1;
  
  (*DAT_1006c1ec)(param_1,s_models_objects_gibs_leg_tris_md2_10049588);
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 2;
  *(undefined4 *)(param_1 + 0x240) = 1;
  *(undefined1 **)(param_1 + 0x208) = &LAB_1000fd20;
  *(undefined4 *)(param_1 + 0x104) = 7;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 4;
  *(undefined4 *)(param_1 + 0x22c) = 2;
  uVar1 = _rand();
  *(float *)(param_1 + 0x184) = (float)(uVar1 & 0x7fff) * _DAT_10044108 * _DAT_100441e8;
  uVar1 = _rand();
  *(float *)(param_1 + 0x188) = (float)(uVar1 & 0x7fff) * _DAT_10044108 * _DAT_100441e8;
  uVar1 = _rand();
  *(code **)(param_1 + 500) = FUN_1001b400;
  *(float *)(param_1 + 0x18c) = (float)(uVar1 & 0x7fff) * _DAT_10044108 * _DAT_100441e8;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + _DAT_10044220;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10010c30 @ 10010c30 size 239 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10010c30(int param_1)

{
  uint uVar1;
  
  (*DAT_1006c1ec)(param_1,s_models_objects_gibs_head_tris_md_100495ac);
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 2;
  *(undefined4 *)(param_1 + 0x240) = 1;
  *(undefined1 **)(param_1 + 0x208) = &LAB_1000fd20;
  *(undefined4 *)(param_1 + 0x104) = 7;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 4;
  *(undefined4 *)(param_1 + 0x22c) = 2;
  uVar1 = _rand();
  *(float *)(param_1 + 0x184) = (float)(uVar1 & 0x7fff) * _DAT_10044108 * _DAT_100441e8;
  uVar1 = _rand();
  *(float *)(param_1 + 0x188) = (float)(uVar1 & 0x7fff) * _DAT_10044108 * _DAT_100441e8;
  uVar1 = _rand();
  *(code **)(param_1 + 500) = FUN_1001b400;
  *(float *)(param_1 + 0x18c) = (float)(uVar1 & 0x7fff) * _DAT_10044108 * _DAT_100441e8;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + _DAT_10044220;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10022e90 @ 10022e90 size 239 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10022e90(void)

{
  _DAT_10061084 = (*DAT_1006c1e4)(s_makron_pain3_wav_1004fdb0);
  _DAT_10061088 = (*DAT_1006c1e4)(s_makron_pain2_wav_1004fd9c);
  _DAT_10061080 = (*DAT_1006c1e4)(s_makron_pain1_wav_1004fd88);
  DAT_1006108c = (*DAT_1006c1e4)(s_makron_death_wav_1004fd74);
  _DAT_10061078 = (*DAT_1006c1e4)(s_makron_step1_wav_1004fd60);
  _DAT_1006109c = (*DAT_1006c1e4)(s_makron_step2_wav_1004fd4c);
  _DAT_1006107c = (*DAT_1006c1e4)(s_makron_bfg_fire_wav_1004fd38);
  _DAT_10061090 = (*DAT_1006c1e4)(s_makron_brain1_wav_1004fd24);
  _DAT_100610a0 = (*DAT_1006c1e4)(s_makron_rail_up_wav_1004fd10);
  _DAT_10061098 = (*DAT_1006c1e4)(s_makron_popup_wav_1004fcfc);
  _DAT_1006106c = (*DAT_1006c1e4)(s_makron_voice4_wav_1004fce8);
  _DAT_10061074 = (*DAT_1006c1e4)(s_makron_voice3_wav_1004fcd4);
  _DAT_10061070 = (*DAT_1006c1e4)(s_makron_voice_wav_1004fcc0);
  _DAT_10061094 = (*DAT_1006c1e4)(s_makron_bhit_wav_1004fcb0);
  (*DAT_1006c1e0)(s_models_monsters_boss3_rider_tris_1004e1fc);
  return;
}



/* FUN_1001cc30 @ 1001cc30 size 238 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1001cc30(int param_1)

{
  float *pfVar1;
  float fVar2;
  uint uVar3;
  float *pfVar4;
  float *pfVar5;
  
  pfVar1 = (float *)(param_1 + 0x154);
  *(undefined4 *)(param_1 + 0x158) = *(undefined4 *)(param_1 + 0x1d4);
  *pfVar1 = *(float *)(param_1 + 0x1d0);
  pfVar4 = (float *)(param_1 + 0x160);
  *(undefined4 *)(param_1 + 0x15c) = *(undefined4 *)(param_1 + 0x1d8);
  pfVar5 = pfVar1;
  uVar3 = _rand();
  fVar2 = (float)(uVar3 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  FUN_10038950(pfVar1,fVar2 + fVar2,pfVar4,pfVar5);
  pfVar4 = (float *)(param_1 + 0x16c);
  pfVar5 = pfVar1;
  uVar3 = _rand();
  fVar2 = (float)(uVar3 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  FUN_10038950(pfVar1,fVar2 + fVar2,pfVar4,pfVar5);
  FUN_10038a20(pfVar1,*(float *)(param_1 + 0x148),(float *)(param_1 + 0x178));
  FUN_1001b1e0(pfVar1,(float *)(param_1 + 0x10));
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044198;
  if (*(float *)(param_1 + 0x120) + (float)_DAT_100442e0 < DAT_1006c2e4) {
    *(code **)(param_1 + 500) = FUN_1001b400;
  }
  return;
}



/* FUN_10019120 @ 10019120 size 235 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10019120(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = *(int *)(param_1 + 0x250);
  if (iVar2 == 1) {
    pcVar3 = s_misc_secret_wav_10046168;
  }
  else if (iVar2 == 2) {
    pcVar3 = s_misc_talk_wav_10046158;
  }
  else {
    if (iVar2 != 3) goto LAB_10019161;
    pcVar3 = s_misc_trigger1_wav_10046144;
  }
  uVar1 = (*DAT_1006c1e4)(pcVar3);
  *(undefined4 *)(param_1 + 0x280) = uVar1;
LAB_10019161:
  if (*(float *)(param_1 + 0x290) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x290) = 0x3e4ccccd;
  }
  *(undefined1 **)(param_1 + 0x1fc) = &LAB_10019060;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  if ((*(byte *)(param_1 + 0x11c) & 4) == 0) {
    *(undefined4 *)(param_1 + 0xf8) = 1;
    *(undefined1 **)(param_1 + 0x200) = &LAB_10019040;
  }
  else {
    *(undefined4 *)(param_1 + 0xf8) = 0;
    *(undefined1 **)(param_1 + 0x200) = &LAB_100190f0;
  }
  iVar2 = FUN_100388c0((float *)(param_1 + 0x10),(float *)&DAT_10061c18);
  if (iVar2 == 0) {
    FUN_1001b0c0((float *)(param_1 + 0x10),(float *)(param_1 + 0x154));
  }
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_1001df80 @ 1001df80 size 234 */

void __cdecl FUN_1001df80(undefined4 *param_1,uint param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = param_1[0x40];
  if (param_2 != uVar1) {
    if ((param_4 != 0) && ((*(byte *)(param_4 + 0x10) & 4) != 0)) {
      FUN_1001b400(param_1);
      return;
    }
    if (*(int *)(uVar1 + 0x54) != 0) {
      FUN_100350a0(uVar1,(float *)(param_1 + 1),2);
    }
    uVar2 = (*DAT_1006c1e4)(s_deatom_dimpact_wav_1004c048,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_1,2,uVar2);
    if (*(int *)(param_2 + 0x240) != 0) {
      FUN_100060d0(param_2,param_1,param_1[0x40],(float *)(param_1 + 0x5e),(float *)(param_1 + 1),
                   param_3,param_1[0x91],1,4,0x23);
    }
    if (param_2 == DAT_1006c2c4) {
      (*DAT_1006c224)(3);
      (*DAT_1006c224)(0x37);
      (*DAT_1006c238)(param_1 + 1);
      (*DAT_1006c23c)(param_3);
      (*DAT_1006c218)(param_1 + 1,2);
    }
    FUN_1001b400(param_1);
  }
  return;
}



/* FUN_10039bbc @ 10039bbc size 232 */

uint __cdecl FUN_10039bbc(char *param_1,uint param_2,uint param_3,int *param_4)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  piVar1 = param_4;
  pcVar6 = (char *)(param_2 * param_3);
  if (pcVar6 == (char *)0x0) {
    param_3 = 0;
  }
  else {
    pcVar5 = param_1;
    param_1 = pcVar6;
    if ((*(ushort *)(param_4 + 3) & 0x10c) == 0) {
      param_4 = (int *)0x1000;
    }
    else {
      param_4 = (int *)param_4[6];
    }
    do {
      if (((*(ushort *)(piVar1 + 3) & 0x10c) == 0) ||
         (pcVar2 = (char *)piVar1[1], pcVar2 == (char *)0x0)) {
        if (param_1 < param_4) {
          uVar4 = FUN_1003e3a5(piVar1);
          if (uVar4 == 0xffffffff) goto LAB_10039c98;
          *pcVar5 = (char)uVar4;
          param_4 = (int *)piVar1[6];
          pcVar5 = pcVar5 + 1;
          param_1 = param_1 + -1;
        }
        else {
          pcVar2 = param_1;
          if (param_4 != (int *)0x0) {
            pcVar2 = param_1 + -((uint)param_1 % (uint)param_4);
          }
          iVar3 = FUN_1003e481(piVar1[4],pcVar5,pcVar2);
          if (iVar3 == 0) {
            piVar1[3] = piVar1[3] | 0x10;
LAB_10039c98:
            return (uint)((int)pcVar6 - (int)param_1) / param_2;
          }
          if (iVar3 == -1) {
            piVar1[3] = piVar1[3] | 0x20;
            goto LAB_10039c98;
          }
          param_1 = param_1 + -iVar3;
          pcVar5 = pcVar5 + iVar3;
        }
      }
      else {
        pcVar7 = param_1;
        if (pcVar2 <= param_1) {
          pcVar7 = pcVar2;
        }
        FUN_1003e070((undefined4 *)pcVar5,(undefined4 *)*piVar1,(uint)pcVar7);
        param_1 = param_1 + -(int)pcVar7;
        piVar1[1] = piVar1[1] - (int)pcVar7;
        *piVar1 = (int)(pcVar7 + *piVar1);
        pcVar5 = pcVar5 + (int)pcVar7;
      }
    } while (param_1 != (char *)0x0);
  }
  return param_3;
}



/* FUN_10003d00 @ 10003d00 size 229 */

ulonglong __cdecl FUN_10003d00(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar9;
  char *pcVar10;
  byte *pbVar11;
  bool bVar12;
  ulonglong uVar13;
  byte local_400 [512];
  byte local_200 [512];
  undefined3 uVar8;
  
  uVar13 = __ftol();
  if ((uVar13 & 0xc0) == 0) {
    return uVar13 & 0xffffffff00000000;
  }
  pcVar3 = FUN_10003c70(param_1);
  uVar5 = 0xffffffff;
  do {
    pcVar10 = pcVar3;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar10 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar10;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pbVar7 = (byte *)(pcVar10 + -uVar5);
  pbVar9 = local_200;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pbVar9 = *(undefined4 *)pbVar7;
    pbVar7 = pbVar7 + 4;
    pbVar9 = pbVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pbVar9 = *pbVar7;
    pbVar7 = pbVar7 + 1;
    pbVar9 = pbVar9 + 1;
  }
  pcVar3 = FUN_10003c70(param_2);
  uVar5 = 0xffffffff;
  do {
    pcVar10 = pcVar3;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar10 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar10;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pbVar7 = local_400;
  pbVar9 = (byte *)(pcVar10 + -uVar5);
  pbVar11 = pbVar7;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pbVar11 = *(undefined4 *)pbVar9;
    pbVar9 = pbVar9 + 4;
    pbVar11 = pbVar11 + 4;
  }
  pbVar4 = local_200;
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pbVar11 = *pbVar9;
    pbVar9 = pbVar9 + 1;
    pbVar11 = pbVar11 + 1;
  }
  pbVar9 = local_400;
  do {
    bVar2 = *pbVar4;
    uVar8 = (undefined3)((uint)pbVar7 >> 8);
    pbVar7 = (byte *)CONCAT31(uVar8,bVar2);
    bVar12 = bVar2 < *pbVar9;
    if (bVar2 != *pbVar9) {
LAB_10003dcd:
      return CONCAT44(pbVar7,(uint)(1 - bVar12 == (uint)(bVar12 != 0)));
    }
    if (bVar2 == 0) break;
    bVar2 = pbVar4[1];
    pbVar7 = (byte *)CONCAT31(uVar8,bVar2);
    bVar12 = bVar2 < pbVar9[1];
    if (bVar2 != pbVar9[1]) goto LAB_10003dcd;
    pbVar4 = pbVar4 + 2;
    pbVar9 = pbVar9 + 2;
  } while (bVar2 != 0);
  return CONCAT44(pbVar7,1);
}



/* FUN_10016a00 @ 10016a00 size 229 */

int __cdecl FUN_10016a00(int param_1,undefined4 *param_2)

{
  bool bVar1;
  char *_Source;
  byte *pbVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  byte local_100 [256];
  
  puVar5 = param_2;
  bVar1 = false;
  puVar4 = &DAT_1006c280;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  while (_Source = FUN_10038a70(&param_1), *_Source != '}') {
    if (param_1 == 0) {
      (*DAT_1006c1dc)(s_ED_ParseEntity__EOF_without_clos_1004b364);
    }
    _strncpy((char *)local_100,_Source,0xff);
    pbVar2 = FUN_10038a70(&param_1);
    if (param_1 == 0) {
      (*DAT_1006c1dc)(s_ED_ParseEntity__EOF_without_clos_1004b364);
    }
    if (*pbVar2 == 0x7d) {
      (*DAT_1006c1dc)(s_ED_ParseEntity__closing_brace_wi_1004b338);
    }
    bVar1 = true;
    if (local_100[0] != 0x5f) {
      FUN_100168b0(local_100,pbVar2,puVar5);
    }
  }
  if (!bVar1) {
    for (iVar3 = 0xf4; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
  }
  return param_1;
}



/* FUN_10026230 @ 10026230 size 229 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10026230(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  if ((*(float *)(param_1 + 0x210) <= DAT_1006c2e4) &&
     (*(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4,
     *(int *)(DAT_1006c41c + 0x14) != 0x40400000)) {
    iVar1 = _rand();
    if (iVar1 % 3 == 0) {
      (*DAT_1006c1d0)(param_1,2,DAT_100611a0,0x3f800000,0x3f800000,0);
      *(undefined **)(param_1 + 0x358) = &DAT_10054788;
      return;
    }
    if (iVar1 % 3 == 1) {
      (*DAT_1006c1d0)(param_1,2,DAT_1006119c);
      *(undefined **)(param_1 + 0x358) = &DAT_10054708;
      return;
    }
    (*DAT_1006c1d0)(param_1,2,DAT_100611a0,0x3f800000,0x3f800000,0);
    *(undefined **)(param_1 + 0x358) = &DAT_100546c8;
  }
  return;
}



/* FUN_1001bf10 @ 1001bf10 size 225 */

void __cdecl FUN_1001bf10(undefined4 *param_1,uint param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = param_1[0x40];
  if (param_2 != uVar1) {
    if ((param_4 == 0) || ((*(byte *)(param_4 + 0x10) & 4) == 0)) {
      if (*(int *)(uVar1 + 0x54) != 0) {
        FUN_100350a0(uVar1,(float *)(param_1 + 1),2);
      }
      if (*(int *)(param_2 + 0x240) != 0) {
        FUN_100060d0(param_2,param_1,param_1[0x40],(float *)(param_1 + 0x5e),(float *)(param_1 + 1),
                     param_3,param_1[0x91],1,4,(-(uint)((param_1[0x47] & 1) != 0) & 9) + 1);
        FUN_1001b400(param_1);
        return;
      }
      (*DAT_1006c224)(3);
      (*DAT_1006c224)(2);
      (*DAT_1006c238)(param_1 + 1);
      if (param_3 == (undefined4 *)0x0) {
        param_3 = &DAT_10061c18;
      }
      (*DAT_1006c23c)(param_3);
      (*DAT_1006c218)(param_1 + 1,2);
    }
    FUN_1001b400(param_1);
  }
  return;
}



/* FUN_10040010 @ 10040010 size 224 */

uint * __cdecl FUN_10040010(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = param_1;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_1004002c;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_1004005f;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x1004007b;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_1004002c:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x1004007b;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x1004007b;
    }
  }
LAB_1004005f:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x1004007b:
  do {
    if (((uint)param_2 & 3) == 0) {
      do {
        uVar2 = *param_2;
        uVar4 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_100400e8:
            *(byte *)puVar5 = (byte)uVar4;
            return param_1;
          }
          if ((char)(uVar4 >> 8) == '\0') {
            *(short *)puVar5 = (short)uVar4;
            return param_1;
          }
          if ((uVar4 & 0xff0000) == 0) {
            *(short *)puVar5 = (short)uVar4;
            *(byte *)((int)puVar5 + 2) = 0;
            return param_1;
          }
          if ((uVar4 & 0xff000000) == 0) {
            *puVar5 = uVar4;
            return param_1;
          }
        }
        *puVar5 = uVar4;
        puVar5 = puVar5 + 1;
      } while( true );
    }
    bVar1 = (byte)*param_2;
    uVar4 = (uint)bVar1;
    param_2 = (uint *)((int)param_2 + 1);
    if (bVar1 == 0) goto LAB_100400e8;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}



/* FUN_10019db0 @ 10019db0 size 223 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10019db0(int param_1)

{
  uint uVar1;
  
  if (*(float *)(param_1 + 0x290) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x290) = 0x3e4ccccd;
  }
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  uVar1 = *(uint *)(param_1 + 0x11c);
  *(undefined4 *)(param_1 + 0xf8) = 1;
  *(undefined4 *)(param_1 + 0x104) = 0;
  if ((uVar1 & 0x10) == 0) {
    *(undefined1 **)(param_1 + 0x200) = &LAB_10019d90;
    if ((uVar1 & 4) == 0) {
      *(code **)(param_1 + 0x1fc) = FUN_10019ba0;
    }
    else {
      *(undefined4 *)(param_1 + 0x1fc) = 0;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1fc) = 0;
    *(code **)(param_1 + 0x200) = FUN_10019d60;
    if ((uVar1 & 1) != 0) {
      (*DAT_1006c1c0)(2,s_ignored_NOMONSTER_spawnflag_on_t_1004bc9c);
    }
    if ((*(byte *)(param_1 + 0x11c) & 2) != 0) {
      (*DAT_1006c1c0)(2,s_ignored_NOPLAYER_spawnflag_on_tr_1004bc6c);
    }
    if ((*(byte *)(param_1 + 0x11c) & 0x10) != 0) {
      (*DAT_1006c1c0)(2,s_ignored_NOTOUCH_spawnflag_on_tri_1004bc3c);
    }
  }
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_1000ec40 @ 1000ec40 size 222 */

void __cdecl FUN_1000ec40(int param_1)

{
  uint uVar1;
  
  *(undefined4 *)(param_1 + 0x104) = 2;
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  uVar1 = *(uint *)(param_1 + 0x11c);
  if ((uVar1 & 8) != 0) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x1000;
  }
  if ((uVar1 & 0x10) != 0) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x2000;
  }
  if ((uVar1 & 7) == 0) {
    *(undefined4 *)(param_1 + 0xf8) = 3;
    (*DAT_1006c208)(param_1);
    return;
  }
  if ((uVar1 & 1) == 0) {
    *(uint *)(param_1 + 0x11c) = uVar1 | 1;
  }
  if (((*(uint *)(param_1 + 0x11c) & 4) != 0) && ((*(uint *)(param_1 + 0x11c) & 2) == 0)) {
    (*DAT_1006c1c4)(s_func_wall_START_ON_without_TOGGL_10049288);
    *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) | 2;
  }
  *(code **)(param_1 + 0x200) = FUN_1000ebd0;
  if ((*(byte *)(param_1 + 0x11c) & 4) != 0) {
    *(undefined4 *)(param_1 + 0xf8) = 3;
    (*DAT_1006c208)(param_1);
    return;
  }
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10038bb0 @ 10038bb0 size 222 */

undefined * __cdecl FUN_10038bb0(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  bool bVar5;
  byte local_200 [512];
  
  DAT_100617e4 = DAT_100617e4 ^ 1;
  if (*param_1 == 0x5c) {
    param_1 = param_1 + 1;
  }
  do {
    pbVar4 = local_200;
    bVar1 = *param_1;
    while (bVar1 != 0x5c) {
      if (bVar1 == 0) goto LAB_10038c7e;
      *pbVar4 = bVar1;
      pbVar3 = param_1 + 1;
      pbVar4 = pbVar4 + 1;
      param_1 = param_1 + 1;
      bVar1 = *pbVar3;
    }
    bVar1 = param_1[1];
    pbVar3 = &DAT_100617e8 + DAT_100617e4 * 0x200;
    *pbVar4 = 0;
    while ((bVar1 != 0x5c && (bVar1 != 0))) {
      *pbVar3 = bVar1;
      pbVar3 = pbVar3 + 1;
      bVar1 = param_1[2];
      param_1 = param_1 + 1;
    }
    *pbVar3 = 0;
    pbVar4 = local_200;
    pbVar3 = param_2;
    do {
      bVar1 = *pbVar3;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_10038c4c:
        iVar2 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
        goto LAB_10038c51;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_10038c4c;
      pbVar3 = pbVar3 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar2 = 0;
LAB_10038c51:
    if (iVar2 == 0) {
      return &DAT_100617e8 + DAT_100617e4 * 0x200;
    }
    if (param_1[1] == 0) {
LAB_10038c7e:
      return &DAT_10060c60;
    }
    param_1 = param_1 + 2;
  } while( true );
}



/* FUN_10038c90 @ 10038c90 size 221 */

void __cdecl FUN_10038c90(byte *param_1,byte *param_2)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  byte local_400 [512];
  byte local_200 [512];
  
  pcVar2 = _strstr((char *)param_2,&DAT_1005fa70);
  if (pcVar2 != (char *)0x0) {
    return;
  }
  do {
    pbVar7 = param_1;
    if (*param_1 == 0x5c) {
      pbVar7 = param_1 + 1;
    }
    pbVar4 = local_400;
    bVar1 = *pbVar7;
    while (bVar1 != 0x5c) {
      if (bVar1 == 0) {
        return;
      }
      *pbVar4 = bVar1;
      pbVar8 = pbVar7 + 1;
      pbVar4 = pbVar4 + 1;
      pbVar7 = pbVar7 + 1;
      bVar1 = *pbVar8;
    }
    bVar1 = pbVar7[1];
    *pbVar4 = 0;
    pbVar4 = local_200;
    while ((pbVar8 = pbVar7 + 1, bVar1 != 0x5c && (bVar1 != 0))) {
      *pbVar4 = bVar1;
      pbVar4 = pbVar4 + 1;
      bVar1 = pbVar7[2];
      pbVar7 = pbVar8;
    }
    *pbVar4 = 0;
    pbVar7 = local_400;
    pbVar4 = param_2;
    do {
      bVar1 = *pbVar4;
      bVar9 = bVar1 < *pbVar7;
      if (bVar1 != *pbVar7) {
LAB_10038d32:
        iVar3 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_10038d37;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar9 = bVar1 < pbVar7[1];
      if (bVar1 != pbVar7[1]) goto LAB_10038d32;
      pbVar4 = pbVar4 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_10038d37:
    if (iVar3 == 0) {
      uVar5 = 0xffffffff;
      break;
    }
    param_1 = pbVar8;
    if (*pbVar8 == 0) {
      return;
    }
  } while( true );
  while( true ) {
    uVar5 = uVar5 - 1;
    pbVar7 = pbVar8 + 1;
    bVar1 = *pbVar8;
    pbVar8 = pbVar7;
    if (bVar1 == 0) break;
    pbVar7 = pbVar8;
    if (uVar5 == 0) break;
  }
  uVar5 = ~uVar5;
  pbVar7 = pbVar7 + -uVar5;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)param_1 = *(undefined4 *)pbVar7;
    pbVar7 = pbVar7 + 4;
    param_1 = param_1 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *param_1 = *pbVar7;
    pbVar7 = pbVar7 + 1;
    param_1 = param_1 + 1;
  }
  return;
}



/* FUN_10039978 @ 10039978 size 220 */

void __cdecl FUN_10039978(int *param_1)

{
  DWORD DVar1;
  int iVar2;
  _TIME_ZONE_INFORMATION local_d0;
  _SYSTEMTIME local_24;
  _SYSTEMTIME local_14;
  
  GetLocalTime(&local_14);
  GetSystemTime(&local_24);
  if (local_24.wMinute == DAT_10061c40._2_2_) {
    if (local_24.wHour == (WORD)DAT_10061c40) {
      if (local_24.wDay == DAT_10061c3c._2_2_) {
        if (local_24.wMonth == DAT_10061c38._2_2_) {
          if (local_24.wYear == (WORD)DAT_10061c38) goto LAB_10039a22;
        }
      }
    }
  }
  DVar1 = GetTimeZoneInformation(&local_d0);
  if (DVar1 == 0xffffffff) {
    DAT_10061c30 = -1;
  }
  else if (((DVar1 == 2) && (local_d0.DaylightDate.wMonth != 0)) && (local_d0.DaylightBias != 0)) {
    DAT_10061c30 = 1;
  }
  else {
    DAT_10061c30 = 0;
  }
  DAT_10061c38._0_2_ = local_24.wYear;
  DAT_10061c38._2_2_ = local_24.wMonth;
  DAT_10061c3c._0_2_ = local_24.wDayOfWeek;
  DAT_10061c3c._2_2_ = local_24.wDay;
  DAT_10061c40._0_2_ = local_24.wHour;
  DAT_10061c40._2_2_ = local_24.wMinute;
  DAT_10061c44._0_2_ = local_24.wSecond;
  DAT_10061c44._2_2_ = local_24.wMilliseconds;
LAB_10039a22:
  iVar2 = FUN_1003db22((uint)local_14.wYear,(uint)local_14.wMonth,(uint)local_14.wDay,
                       (uint)local_14.wHour,(uint)local_14.wMinute,(uint)local_14.wSecond,
                       DAT_10061c30);
  if (param_1 != (int *)0x0) {
    *param_1 = iVar2;
  }
  return;
}



/* FUN_1003e3a5 @ 1003e3a5 size 220 */

uint __cdecl FUN_1003e3a5(undefined4 *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  uVar2 = param_1[3];
  if (((uVar2 & 0x83) != 0) && ((uVar2 & 0x40) == 0)) {
    if ((uVar2 & 2) == 0) {
      param_1[3] = uVar2 | 1;
      if ((uVar2 & 0x10c) == 0) {
        FUN_100407c4(param_1);
      }
      else {
        *param_1 = param_1[2];
      }
      iVar3 = FUN_1003e481(param_1[4],(char *)param_1[2],(char *)param_1[6]);
      param_1[1] = iVar3;
      if ((iVar3 != 0) && (iVar3 != -1)) {
        if ((param_1[3] & 0x82) == 0) {
          uVar2 = param_1[4];
          if (uVar2 == 0xffffffff) {
            puVar4 = &DAT_10060440;
          }
          else {
            puVar4 = (undefined *)((&DAT_1006ccc0)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
          }
          if ((puVar4[4] & 0x82) == 0x82) {
            param_1[3] = param_1[3] | 0x2000;
          }
        }
        if (((param_1[6] == 0x200) && ((param_1[3] & 8) != 0)) && ((param_1[3] & 0x400) == 0)) {
          param_1[6] = 0x1000;
        }
        param_1[1] = iVar3 + -1;
        bVar1 = *(byte *)*param_1;
        *param_1 = (byte *)*param_1 + 1;
        return (uint)bVar1;
      }
      param_1[3] = param_1[3] | (-(uint)(iVar3 != 0) & 0x10) + 0x10;
      param_1[1] = 0;
    }
    else {
      param_1[3] = uVar2 | 0x20;
    }
  }
  return 0xffffffff;
}



/* FUN_10024f10 @ 10024f10 size 218 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10024f10(int param_1)

{
  int iVar1;
  uint uVar2;
  float10 fVar3;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  iVar1 = *(int *)(param_1 + 0x25c);
  if (*(float *)(iVar1 + 0xf4) * (float)_DAT_10044328 + *(float *)(iVar1 + 0xdc) <
      *(float *)(param_1 + 0xdc)) {
    return 0;
  }
  if (*(float *)(param_1 + 0xe8) <
      *(float *)(iVar1 + 0xf4) * (float)_DAT_10044230 + *(float *)(iVar1 + 0xdc)) {
    return 0;
  }
  local_c = *(float *)(param_1 + 4) - *(float *)(iVar1 + 4);
  local_8 = *(float *)(param_1 + 8) - *(float *)(iVar1 + 8);
  local_4 = 0;
  fVar3 = FUN_100389f0(&local_c);
  if (fVar3 < (float10)_DAT_10044130) {
    return 0;
  }
  if ((float10)_DAT_10044130 < fVar3) {
    uVar2 = _rand();
    if ((float)(uVar2 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044198) {
      return 0;
    }
  }
  return 1;
}



/* FUN_1002b440 @ 1002b440 size 218 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1002b440(int param_1)

{
  int iVar1;
  uint uVar2;
  float10 fVar3;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  iVar1 = *(int *)(param_1 + 0x25c);
  if (*(float *)(iVar1 + 0xf4) * (float)_DAT_10044328 + *(float *)(iVar1 + 0xdc) <
      *(float *)(param_1 + 0xdc)) {
    return 0;
  }
  if (*(float *)(param_1 + 0xe8) <
      *(float *)(iVar1 + 0xf4) * (float)_DAT_10044230 + *(float *)(iVar1 + 0xdc)) {
    return 0;
  }
  local_c = *(float *)(param_1 + 4) - *(float *)(iVar1 + 4);
  local_8 = *(float *)(param_1 + 8) - *(float *)(iVar1 + 8);
  local_4 = 0;
  fVar3 = FUN_100389f0(&local_c);
  if (fVar3 < (float10)_DAT_10044130) {
    return 0;
  }
  if ((float10)_DAT_10044130 < fVar3) {
    uVar2 = _rand();
    if ((float)(uVar2 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044340) {
      return 0;
    }
  }
  return 1;
}



/* FUN_10011160 @ 10011160 size 217 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10011160(undefined4 *param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (param_1[0x4a] == 0) {
    puVar3 = param_1 + 1;
    puVar1 = FUN_1001b070();
    (*DAT_1006c1c4)(s__s_with_no_target_at__s_10049600,param_1[0x46],puVar1,puVar3);
    FUN_1001b400(param_1);
    return;
  }
  if (((param_1[0x47] & 2) != 0) && (param_1[0x95] == 0)) {
    puVar3 = param_1 + 1;
    puVar1 = FUN_1001b070();
    (*DAT_1006c1c4)(s__s_with_no_count_at__s_100495e8,param_1[0x46],puVar1,puVar3);
    FUN_1001b400(param_1);
    return;
  }
  if (((param_1[0x47] & 1) != 0) && (param_1[0x95] == 0)) {
    param_1[0x95] = 0xe10;
  }
  FUN_10010fb0((int)param_1);
  uVar2 = (*DAT_1006c244)(0x10,0x2fe);
  param_1[0x45] = uVar2;
  param_1[0x7d] = &LAB_10010e10;
  if ((*(byte *)(param_1 + 0x47) & 4) != 0) {
    param_1[0x80] = &LAB_10011120;
    return;
  }
  param_1[0x7b] = DAT_1006c2e4 + _DAT_10044104;
  return;
}



/* FUN_1003a1e0 @ 1003a1e0 size 217 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1003a1e0(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 1) {
    DAT_10061de0 = GetVersion();
    iVar1 = FUN_1003c75b(1);
    if (iVar1 != 0) {
      _DAT_10061dec = DAT_10061de0 >> 8 & 0xff;
      _DAT_10061de8 = DAT_10061de0 & 0xff;
      DAT_10061de0 = DAT_10061de0 >> 0x10;
      _DAT_10061de4 = _DAT_10061de8 * 0x100 + _DAT_10061dec;
      iVar1 = FUN_1003a828();
      if (iVar1 != 0) {
        DAT_1006de00 = GetCommandLineA();
        DAT_10061c4c = FUN_1003f661();
        FUN_1003f14b();
        FUN_1003f414();
        FUN_1003f35b();
        FUN_1003f02d();
        DAT_10061c48 = DAT_10061c48 + 1;
        goto LAB_1003a2b3;
      }
      FUN_1003c797();
    }
LAB_1003a240:
    uVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      if (DAT_10061c48 < 1) goto LAB_1003a240;
      DAT_10061c48 = DAT_10061c48 + -1;
      if (DAT_10061e18 == 0) {
        FUN_1003f06b();
      }
      FUN_1003f307();
      FUN_1003a87c();
      FUN_1003c797();
    }
    else if (param_2 == 3) {
      FUN_1003a914((LPVOID)0x0);
    }
LAB_1003a2b3:
    uVar2 = 1;
  }
  return uVar2;
}



/* FUN_1000aa60 @ 1000aa60 size 216 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000aa60(int param_1)

{
  float fVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  
  if (*(float *)(param_1 + 0x290) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x290) = 0x3f800000;
  }
  *(undefined1 **)(param_1 + 0x200) = &LAB_1000aa00;
  *(code **)(param_1 + 500) = FUN_1000a9a0;
  if (*(float *)(param_1 + 0x290) <= *(float *)(param_1 + 0x29c)) {
    iVar4 = param_1 + 4;
    *(float *)(param_1 + 0x29c) = *(float *)(param_1 + 0x290) - (float)_DAT_10044168;
    puVar2 = FUN_1001b070();
    (*DAT_1006c1c4)(s_func_timer_at__s_has_random_>__w_100468b8,puVar2,iVar4);
  }
  if ((*(byte *)(param_1 + 0x11c) & 1) != 0) {
    uVar3 = _rand();
    fVar1 = (float)(uVar3 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
    fVar1 = (fVar1 + fVar1) * *(float *)(param_1 + 0x29c) + *(float *)(param_1 + 0x294) +
            _DAT_1006c2a8 + DAT_1006c2e4;
    *(int *)(param_1 + 0x264) = param_1;
    *(float *)(param_1 + 0x1ec) = fVar1 + *(float *)(param_1 + 0x290) + (float)_DAT_10044120;
  }
  *(undefined4 *)(param_1 + 0xb8) = 1;
  return;
}



/* FUN_1001aca0 @ 1001aca0 size 216 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl FUN_1001aca0(int param_1,int param_2,float param_3)

{
  float *pfVar1;
  float *pfVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  float local_c [3];
  
  uVar4 = DAT_1006c2c4;
  if (param_1 != 0) {
    uVar4 = param_1 + 0x3d0;
  }
  iVar5 = DAT_1006c168;
  uVar3 = DAT_1006c2c4;
  if (uVar4 < DAT_1006c168 * 0x3d0 + DAT_1006c2c4) {
    do {
      if ((*(int *)(uVar4 + 0x58) != 0) && (*(int *)(uVar4 + 0xf8) != 0)) {
        iVar5 = 3;
        pfVar1 = (float *)(uVar4 + 0xbc);
        pfVar2 = local_c;
        do {
          iVar5 = iVar5 + -1;
          *pfVar2 = *(float *)((param_2 - (int)local_c) + (int)pfVar2) -
                    ((pfVar1[3] + *pfVar1) * (float)_DAT_10044140 + pfVar1[-0x2e]);
          pfVar1 = pfVar1 + 1;
          pfVar2 = pfVar2 + 1;
        } while (iVar5 != 0);
        fVar6 = FUN_100389f0(local_c);
        iVar5 = DAT_1006c168;
        uVar3 = DAT_1006c2c4;
        if (fVar6 <= (float10)param_3) {
          return uVar4;
        }
      }
      uVar4 = uVar4 + 0x3d0;
    } while (uVar4 < iVar5 * 0x3d0 + uVar3);
  }
  return 0;
}



/* FUN_1001f380 @ 1001f380 size 215 */

void __cdecl FUN_1001f380(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  char *pcVar5;
  bool bVar6;
  float10 fVar7;
  float local_c;
  float local_8;
  float local_4;
  
  uVar2 = FUN_1001ad80(*(byte **)(param_1 + 0x128));
  *(uint *)(param_1 + 0x1e0) = uVar2;
  *(uint *)(param_1 + 0x1dc) = uVar2;
  if (uVar2 != 0) {
    pbVar4 = *(byte **)(uVar2 + 0x118);
    pcVar5 = s_target_actor_10049728;
    do {
      bVar1 = *pbVar4;
      bVar6 = bVar1 < (byte)*pcVar5;
      if (bVar1 != *pcVar5) {
LAB_1001f3de:
        iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_1001f3e3;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar6 = bVar1 < (byte)pcVar5[1];
      if (bVar1 != pcVar5[1]) goto LAB_1001f3de;
      pbVar4 = pbVar4 + 2;
      pcVar5 = pcVar5 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_1001f3e3:
    if (iVar3 == 0) {
      local_c = *(float *)(uVar2 + 4) - *(float *)(param_1 + 4);
      local_8 = *(float *)(uVar2 + 8) - *(float *)(param_1 + 8);
      local_4 = *(float *)(uVar2 + 0xc) - *(float *)(param_1 + 0xc);
      fVar7 = FUN_1001b160(&local_c);
      *(float *)(param_1 + 0x14) = (float)fVar7;
      *(float *)(param_1 + 0x1e8) = (float)fVar7;
      (**(code **)(param_1 + 0x374))(param_1);
      *(undefined4 *)(param_1 + 0x128) = 0;
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 0x390) = 0x4cbebc20;
  (**(code **)(param_1 + 0x368))(param_1);
  return;
}



/* FUN_1002a920 @ 1002a920 size 214 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1002a920(int param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  int iVar5;
  float10 fVar6;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  *(float *)(param_1 + 0x1e8) = param_2;
  FUN_1002a850(param_1);
  uVar1 = *(undefined4 *)(param_1 + 4);
  uVar2 = *(undefined4 *)(param_1 + 8);
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  fVar6 = (float10)fcos((float10)param_2 * (float10)_DAT_100442b8);
  local_4 = 0;
  local_c = (float)(fVar6 * (float10)param_3);
  fVar6 = (float10)fsin((float10)param_2 * (float10)_DAT_100442b8);
  local_8 = (float)(fVar6 * (float10)param_3);
  iVar5 = FUN_1002a330(param_1,&local_c,0);
  if (iVar5 == 0) {
    (*DAT_1006c208)(param_1);
    FUN_1001b480();
    return 0;
  }
  fVar4 = *(float *)(param_1 + 0x14) - *(float *)(param_1 + 0x1e8);
  if ((_DAT_10044138 < fVar4) && (fVar4 < _DAT_10044134)) {
    *(undefined4 *)(param_1 + 4) = uVar1;
    *(undefined4 *)(param_1 + 8) = uVar2;
    *(undefined4 *)(param_1 + 0xc) = uVar3;
  }
  (*DAT_1006c208)(param_1);
  FUN_1001b480();
  return 1;
}



/* FUN_10030780 @ 10030780 size 212 */

uint FUN_10030780(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  float local_8;
  float local_4;
  
  uVar3 = 0;
  local_4 = 99999.0;
  local_8 = 99999.0;
  uVar4 = 0;
  uVar1 = FUN_1001ac00(0,0x118,(byte *)s_info_player_deathmatch_1004b26c);
  iVar5 = 0;
  if (uVar1 != 0) {
    do {
      iVar2 = iVar5;
      iVar5 = iVar2 + 1;
      fVar6 = FUN_100306b0(uVar1);
      if ((float10)local_8 <= fVar6) {
        if (fVar6 < (float10)local_4) {
          local_4 = (float)fVar6;
          uVar4 = uVar1;
        }
      }
      else {
        local_8 = (float)fVar6;
        uVar3 = uVar1;
      }
      uVar1 = FUN_1001ac00(uVar1,0x118,(byte *)s_info_player_deathmatch_1004b26c);
    } while (uVar1 != 0);
    if (iVar5 != 0) {
      if (iVar5 < 3) {
        uVar4 = 0;
        uVar3 = 0;
      }
      else {
        iVar5 = iVar2 + -1;
      }
      iVar2 = _rand();
      iVar2 = iVar2 % iVar5;
      uVar1 = 0;
      do {
        uVar1 = FUN_1001ac00(uVar1,0x118,(byte *)s_info_player_deathmatch_1004b26c);
        if ((uVar1 == uVar3) || (iVar5 = iVar2, uVar1 == uVar4)) {
          iVar5 = iVar2 + 1;
        }
        iVar2 = iVar5 + -1;
      } while (iVar5 != 0);
      return uVar1;
    }
  }
  return 0;
}



/* FUN_10029720 @ 10029720 size 211 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10029720(int param_1)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  if ((*(float *)(param_1 + 0x210) <= DAT_1006c2e4) &&
     (*(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4,
     *(int *)(DAT_1006c41c + 0x14) != 0x40400000)) {
    uVar1 = _rand();
    if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044140) {
      *(undefined **)(param_1 + 0x358) = &DAT_10059760;
      (*DAT_1006c1d0)(param_1,2,DAT_10061294,0x3f800000,0x3f800000,0);
      return;
    }
    *(undefined **)(param_1 + 0x358) = &DAT_10059828;
    (*DAT_1006c1d0)(param_1,2,DAT_10061290,0x3f800000,0x3f800000,0);
  }
  return;
}



/* FUN_100175d0 @ 100175d0 size 210 */

void FUN_100175d0(void)

{
  int iVar1;
  byte *pbVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iStack_8;
  int iStack_4;
  
  iVar1 = (*DAT_1006c25c)();
  if (iVar1 < 3) {
    (*DAT_1006c1c8)(0,2,s_Usage__sv_removeip_<ip_mask>_1004b800);
    return;
  }
  piVar5 = &iStack_8;
  pbVar2 = (byte *)(*DAT_1006c260)(2);
  iVar1 = FUN_10017520(pbVar2,piVar5);
  if (iVar1 != 0) {
    iVar1 = 0;
    if (0 < DAT_100620d0) {
      piVar5 = &DAT_100620e4;
      do {
        if ((piVar5[-1] == iStack_8) && (*piVar5 == iStack_4)) {
          iVar1 = iVar1 + 1;
          if (iVar1 < DAT_100620d0) {
            puVar4 = &DAT_100620e0 + iVar1 * 2;
            iVar1 = DAT_100620d0 - iVar1;
            do {
              puVar4[-2] = *puVar4;
              puVar4[-1] = puVar4[1];
              puVar4 = puVar4 + 2;
              iVar1 = iVar1 + -1;
            } while (iVar1 != 0);
          }
          DAT_100620d0 = DAT_100620d0 + -1;
          (*DAT_1006c1c8)(0,2,s_Removed__1004b7e0);
          return;
        }
        iVar1 = iVar1 + 1;
        piVar5 = piVar5 + 2;
      } while (iVar1 < DAT_100620d0);
    }
    uVar3 = (*DAT_1006c260)(2);
    (*DAT_1006c1c8)(0,2,s_Didn_t_find__s__1004b7ec,uVar3);
  }
  return;
}



/* FUN_100376b0 @ 100376b0 size 209 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100376b0(int param_1)

{
  int *piVar1;
  longlong lVar2;
  float local_30 [3];
  float local_24 [3];
  float local_18 [3];
  float local_c [3];
  
  local_30[2] = (float)(*(int *)(param_1 + 0x23c) + -8);
  local_30[0] = 8.0;
  local_30[1] = 8.0;
  FUN_10038700((float *)(*(int *)(param_1 + 0x54) + 0xe64),local_24,local_18,(float *)0x0);
  FUN_10035db0(*(int *)(param_1 + 0x54),(float *)(param_1 + 4),local_30,local_24,local_18,local_c);
  lVar2 = __ftol();
  FUN_1001d870(param_1,(int *)local_c,local_24,(int)lVar2);
  piVar1 = (int *)(*(int *)(param_1 + 0x54) + 0x2e4 + *(int *)(*(int *)(param_1 + 0x54) + 0xde8) * 4
                  );
  *piVar1 = *piVar1 + -1;
  *(float *)(*(int *)(param_1 + 0x54) + 0xec0) = DAT_1006c2e4 + (float)_DAT_10044120;
  return;
}



/* FUN_100116e0 @ 100116e0 size 208 */

void __cdecl FUN_100116e0(undefined4 *param_1)

{
  int iVar1;
  
  param_1[0x2e] = param_1[0x2e] | 1;
  param_1[0x3e] = 0;
  iVar1 = FUN_10039662((char *)param_1[0x4e],(byte *)s__f__f__f__f_10049698);
  if (iVar1 < 4) {
    FUN_1001b400(param_1);
    return;
  }
  iVar1 = FUN_10039662((char *)param_1[0x4f],(byte *)s__f__f__f__f_10049698);
  if (iVar1 < 4) {
    FUN_1001b400(param_1);
    return;
  }
  param_1[0x80] = FUN_10011640;
  param_1[0xa4] = (float)(int)param_1[0x95];
  if ((*(byte *)(param_1 + 0x47) & 1) != 0) {
    FUN_10011640((uint)param_1);
  }
  return;
}



/* FUN_1003a110 @ 1003a110 size 208 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_1003a110(void *this,byte *param_1,byte *param_2)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  void *extraout_ECX;
  void *this_00;
  void *extraout_ECX_00;
  uint uVar8;
  uint uVar9;
  uint uVar7;
  
  iVar2 = _DAT_1006cdd8;
  if (DAT_10061db8 == 0) {
    bVar5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (bVar5 == 0) goto LAB_1003a15e;
        bVar5 = *param_2;
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        param_1 = param_1 + 1;
      } while (bVar4 == bVar5);
      bVar3 = bVar5 + 0xbf + (-((byte)(bVar5 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar4 = bVar4 + 0xbf;
      bVar5 = bVar4 + (-(bVar4 < 0x1a) & 0x20U) + 0x41;
    } while (bVar5 == bVar3);
    cVar6 = (bVar5 < bVar3) * -2 + '\x01';
LAB_1003a15e:
    uVar7 = (uint)cVar6;
  }
  else {
    LOCK();
    _DAT_1006cdd8 = _DAT_1006cdd8 + 1;
    UNLOCK();
    bVar1 = 0 < DAT_1006cdd4;
    if (bVar1) {
      LOCK();
      UNLOCK();
      _DAT_1006cdd8 = iVar2;
      FUN_1003c8a1(0x13);
      this = extraout_ECX;
    }
    uVar9 = (uint)bVar1;
    uVar7 = 0xff;
    uVar8 = 0;
    do {
      do {
        if ((char)uVar7 == '\0') goto LAB_1003a1bf;
        bVar5 = *param_2;
        uVar7 = CONCAT31((int3)(uVar7 >> 8),bVar5);
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        uVar8 = CONCAT31((int3)(uVar8 >> 8),bVar4);
        param_1 = param_1 + 1;
      } while (bVar5 == bVar4);
      uVar8 = FUN_1003ef62(this,uVar8);
      uVar7 = FUN_1003ef62(this_00,uVar7);
      this = extraout_ECX_00;
    } while ((byte)uVar8 == (byte)uVar7);
    uVar8 = (uint)((byte)uVar8 < (byte)uVar7);
    uVar7 = (1 - uVar8) - (uint)(uVar8 != 0);
LAB_1003a1bf:
    if (uVar9 == 0) {
      LOCK();
      _DAT_1006cdd8 = _DAT_1006cdd8 + -1;
      UNLOCK();
    }
    else {
      FUN_1003c902(0x13);
    }
  }
  return uVar7;
}



/* FUN_100418f6 @ 100418f6 size 208 */

void __cdecl FUN_100418f6(uint param_1,int *param_2,ushort *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  uint local_5c [10];
  undefined8 local_34;
  uint local_24;
  
  param_3 = (ushort *)(uint)*param_3;
  iVar2 = *param_2;
  if (iVar2 == 1) {
LAB_1004193b:
    uVar3 = 8;
  }
  else if (iVar2 == 2) {
    uVar3 = 4;
  }
  else if (iVar2 == 3) {
    uVar3 = 0x11;
  }
  else if (iVar2 == 4) {
    uVar3 = 0x12;
  }
  else {
    if (iVar2 == 5) goto LAB_1004193b;
    if (iVar2 == 7) {
      *param_2 = 1;
      goto LAB_10041991;
    }
    if (iVar2 != 8) goto LAB_10041991;
    uVar3 = 0x10;
  }
  bVar1 = FUN_1003ad53(uVar3,(double *)(param_2 + 6),(uint)param_3);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    if (((param_1 == 0x10) || (param_1 == 0x16)) || (param_1 == 0x1d)) {
      local_34 = *(undefined8 *)(param_2 + 4);
      local_24 = local_24 & 0xffffffe3 | 3;
    }
    else {
      local_24 = local_24 & 0xfffffffe;
    }
    FUN_1003aaa0(local_5c,(uint *)&param_3,uVar3,param_1,(undefined8 *)(param_2 + 2),
                 (undefined8 *)(param_2 + 6));
  }
LAB_10041991:
  FUN_1003b1df();
  if (((*param_2 != 8) && (DAT_10060720 == 0)) && (iVar2 = FUN_100405a0(), iVar2 != 0)) {
    return;
  }
  FUN_1003aff2(*param_2);
  return;
}



/* FUN_1003900b @ 1003900b size 207 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_1003900b(double param_1)

{
  double dVar1;
  uint uVar2;
  int iVar3;
  float10 fVar4;
  uint uVar5;
  
  uVar2 = FUN_1003b1df();
  if ((param_1._6_2_ & 0x7ff0) == 0x7ff0) {
    iVar3 = FUN_1003b0a7(SUB84(param_1,0),(uint)((ulonglong)param_1 >> 0x20));
    if (0 < iVar3) {
      if (iVar3 < 3) {
        FUN_1003b1df();
        return (float10)param_1;
      }
      if (iVar3 == 3) {
        fVar4 = FUN_1003a9b4(0xb,param_1);
        return fVar4;
      }
    }
    dVar1 = param_1 + _DAT_10044120;
    uVar5 = 8;
  }
  else {
    fVar4 = __frnd(param_1);
    dVar1 = (double)fVar4;
    if ((dVar1 == param_1) || ((uVar2 & 0x20) != 0)) {
      FUN_1003b1df();
      return (float10)dVar1;
    }
    uVar5 = 0x10;
  }
  fVar4 = FUN_1003aa08(uVar5,0xb,param_1,dVar1,uVar2);
  return fVar4;
}



/* FUN_10039593 @ 10039593 size 207 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_10039593(double param_1)

{
  double dVar1;
  uint uVar2;
  int iVar3;
  float10 fVar4;
  uint uVar5;
  
  uVar2 = FUN_1003b1df();
  if ((param_1._6_2_ & 0x7ff0) == 0x7ff0) {
    iVar3 = FUN_1003b0a7(SUB84(param_1,0),(uint)((ulonglong)param_1 >> 0x20));
    if (0 < iVar3) {
      if (iVar3 < 3) {
        FUN_1003b1df();
        return (float10)param_1;
      }
      if (iVar3 == 3) {
        fVar4 = FUN_1003a9b4(0xc,param_1);
        return fVar4;
      }
    }
    dVar1 = param_1 + _DAT_10044120;
    uVar5 = 8;
  }
  else {
    fVar4 = __frnd(param_1);
    dVar1 = (double)fVar4;
    if ((dVar1 == param_1) || ((uVar2 & 0x20) != 0)) {
      FUN_1003b1df();
      return (float10)dVar1;
    }
    uVar5 = 0x10;
  }
  fVar4 = FUN_1003aa08(uVar5,0xc,param_1,dVar1,uVar2);
  return fVar4;
}



/* FUN_10003ba0 @ 10003ba0 size 206 */

void __cdecl FUN_10003ba0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = *(int *)(param_1 + 0x250);
  if (iVar2 == 1) {
    pcVar3 = s_misc_secret_wav_10046168;
  }
  else if (iVar2 == 2) {
    pcVar3 = s_misc_talk_wav_10046158;
  }
  else {
    if (iVar2 != 3) goto LAB_10003be1;
    pcVar3 = s_misc_trigger1_wav_10046144;
  }
  uVar1 = (*DAT_1006c1e4)(pcVar3);
  *(undefined4 *)(param_1 + 0x280) = uVar1;
LAB_10003be1:
  *(undefined1 **)(param_1 + 0x1fc) = &LAB_10003b10;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  if ((*(byte *)(param_1 + 0x11c) & 4) == 0) {
    *(undefined4 *)(param_1 + 0xf8) = 1;
    *(undefined1 **)(param_1 + 0x200) = &LAB_10003af0;
  }
  else {
    *(undefined4 *)(param_1 + 0xf8) = 0;
    *(undefined1 **)(param_1 + 0x200) = &LAB_100190f0;
  }
  iVar2 = FUN_100388c0((float *)(param_1 + 0x10),(float *)&DAT_10061c18);
  if (iVar2 == 0) {
    FUN_1001b0c0((float *)(param_1 + 0x10),(float *)(param_1 + 0x154));
  }
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_1001e820 @ 1001e820 size 205 */

void __cdecl FUN_1001e820(undefined4 *param_1)

{
  undefined4 uVar1;
  float local_c [3];
  
  param_1[0x90] = 0;
  if (*(int *)(param_1[0x40] + 0x54) != 0) {
    FUN_100350a0(param_1[0x40],(float *)(param_1 + 1),2);
  }
  FUN_10006860((float)param_1,param_1[0x40],(float)(int)param_1[0x91],param_1[0x97],
               (float)param_1[0x93],0x26);
  FUN_10038950((float *)(param_1 + 1),-0.02,(float *)(param_1 + 0x5e),local_c);
  (*DAT_1006c224)(3);
  if (param_1[0xaa] == 0) {
    if (param_1[0x9a] == 0) {
      uVar1 = 7;
    }
    else {
      uVar1 = 8;
    }
  }
  else if (param_1[0x9a] == 0) {
    uVar1 = 0x11;
  }
  else {
    uVar1 = 0x12;
  }
  (*DAT_1006c224)(uVar1);
  (*DAT_1006c238)(local_c);
  (*DAT_1006c218)(param_1 + 1,1);
  FUN_1001b400(param_1);
  return;
}



/* FUN_100189e0 @ 100189e0 size 204 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100189e0(int param_1)

{
  int iVar1;
  longlong lVar2;
  
  iVar1 = param_1;
  lVar2 = __ftol();
  param_1._0_2_ = (ushort)(byte)lVar2;
  (*DAT_1006c1d8)(*(int *)(*(int *)(iVar1 + 0x25c) + 0x2c8) + 800,&param_1);
  if (DAT_1006c2e4 - *(float *)(iVar1 + 0x120) < *(float *)(iVar1 + 0x148)) {
    *(float *)(iVar1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
    return;
  }
  if ((*(byte *)(iVar1 + 0x11c) & 1) != 0) {
    lVar2 = __ftol();
    *(undefined4 *)(iVar1 + 0x154) = *(undefined4 *)(iVar1 + 0x158);
    *(float *)(iVar1 + 0x158) = (float)(int)(char)lVar2;
    *(float *)(iVar1 + 0x15c) = *(float *)(iVar1 + 0x15c) * _DAT_100441bc;
  }
  return;
}



/* FUN_10009430 @ 10009430 size 203 */

void __cdecl FUN_10009430(int param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  if ((*(uint *)(param_1 + 0x108) & 0x400) == 0) {
    fVar3 = ABS(*(float *)(param_1 + 0x328));
    for (iVar2 = *(int *)(param_1 + 0x270); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x270)) {
      if (ABS(*(float *)(iVar2 + 0x328)) < fVar3) {
        fVar3 = ABS(*(float *)(iVar2 + 0x328));
      }
    }
    fVar1 = *(float *)(param_1 + 800);
    for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x270)) {
      fVar4 = ABS(*(float *)(param_1 + 0x328)) / (fVar3 / fVar1);
      fVar6 = fVar4 / *(float *)(param_1 + 800);
      fVar5 = fVar4;
      if (*(float *)(param_1 + 0x31c) != *(float *)(param_1 + 800)) {
        fVar5 = fVar6 * *(float *)(param_1 + 0x31c);
      }
      *(float *)(param_1 + 0x31c) = fVar5;
      if (*(float *)(param_1 + 0x324) == *(float *)(param_1 + 800)) {
        *(float *)(param_1 + 0x324) = fVar4;
      }
      else {
        *(float *)(param_1 + 0x324) = fVar6 * *(float *)(param_1 + 0x324);
      }
      *(float *)(param_1 + 800) = fVar4;
    }
  }
  return;
}



/* FUN_10010100 @ 10010100 size 203 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10010100(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 2;
  *(char **)(param_1 + 0x10c) = s_models_monsters_commandr_tris_md_100493ac;
  uVar1 = (*DAT_1006c1e0)(s_models_monsters_commandr_tris_md_100493ac);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  *(undefined4 *)(param_1 + 0xbc) = 0xc2000000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc2000000;
  *(undefined4 *)(param_1 + 200) = 0x42000000;
  *(undefined4 *)(param_1 + 0xcc) = 0x42000000;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0x42400000;
  *(code **)(param_1 + 0x200) = FUN_10010090;
  *(undefined4 *)(param_1 + 0x240) = 1;
  *(undefined4 *)(param_1 + 0x108) = 0x10;
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0x40;
  (*DAT_1006c208)(param_1);
  (*DAT_1006c1e4)(s_tank_thud_wav_1004938c);
  (*DAT_1006c1e4)(s_tank_pain_wav_1004939c);
  *(undefined1 **)(param_1 + 500) = &LAB_100100e0;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044140;
  return;
}



/* FUN_1003ef62 @ 1003ef62 size 203 */

uint __thiscall FUN_1003ef62(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  void *local_8;
  
  uVar1 = param_1;
  if (DAT_10061db8 == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      uVar1 = param_1 + 0x20;
    }
  }
  else {
    iVar3 = 1;
    local_8 = this;
    if ((int)param_1 < 0x100) {
      if (DAT_1005fed4 < 2) {
        uVar2 = (byte)PTR_DAT_1005fcc8[param_1 * 2] & 1;
      }
      else {
        uVar2 = FUN_1003b258(this,param_1,1);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    if ((PTR_DAT_1005fcc8[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;
    }
    else {
      uVar2 = param_1 >> 0x10;
      param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
      param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;
      iVar3 = 2;
    }
    iVar3 = FUN_10041a4a(DAT_10061db8,0x100,(char *)&param_1,iVar3,(LPWSTR)&local_8,3,0,1);
    if (iVar3 != 0) {
      if (iVar3 == 1) {
        uVar1 = (uint)local_8 & 0xff;
      }
      else {
        uVar1 = (uint)local_8 & 0xffff;
      }
    }
  }
  return uVar1;
}



/* FUN_1000d870 @ 1000d870 size 202 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000d870(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined1 local_100 [256];
  
  puVar5 = local_100;
  pcVar7 = s_gamemap___s__10049190;
  uVar6 = 0x100;
  uVar8 = DAT_1006c3ac;
  FUN_10038b40();
  (*DAT_1006c268)(local_100,puVar5,uVar6,pcVar7,uVar8);
  DAT_1006c3ac = 0;
  DAT_1006c3b0 = 0;
  _DAT_1006c3a8 = 0;
  FUN_1000d5a0();
  iVar4 = 0;
  if (_DAT_1004410c < *(float *)(DAT_1006ca60 + 0x14)) {
    iVar2 = 0x3d0;
    iVar3 = DAT_1006c2c4;
    do {
      if (*(int *)(iVar2 + 0x58 + iVar3) != 0) {
        iVar1 = *(int *)(*(int *)(iVar2 + 0x54 + iVar3) + 0x2d8);
        if (iVar1 < *(int *)(iVar2 + 0x220 + iVar3)) {
          *(int *)(iVar2 + 0x220 + iVar3) = iVar1;
          iVar3 = DAT_1006c2c4;
        }
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 0x3d0;
    } while ((float)iVar4 < *(float *)(DAT_1006ca60 + 0x14));
  }
  return;
}



/* FUN_10011570 @ 10011570 size 202 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10011570(uint param_1)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  
  fVar1 = DAT_1006c2e4 - *(float *)(param_1 + 0x120);
  if (fVar1 < *(float *)(param_1 + 0x290)) {
    fVar1 = fVar1 / *(float *)(param_1 + 0x290);
    iVar3 = 3;
    pfVar2 = (float *)(param_1 + 0x160);
    do {
      iVar3 = iVar3 + -1;
      pfVar2[0x5c] = (pfVar2[3] - *pfVar2) * fVar1 + *pfVar2;
      pfVar2 = pfVar2 + 1;
    } while (iVar3 != 0);
    fVar1 = (*(float *)(param_1 + 0x24c) - *(float *)(param_1 + 0x148)) * fVar1 +
            *(float *)(param_1 + 0x148);
    *(float *)(param_1 + 0x2dc) = fVar1;
    FUN_10033c90(*(float *)(param_1 + 0x2d0),*(float *)(param_1 + 0x2d4),*(float *)(param_1 + 0x2d8)
                 ,fVar1,(float *)(DAT_1006c2c4 + 0x2d0));
    *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
    return;
  }
  FUN_1001ae20(param_1,DAT_1006c2c4);
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 500) = 0;
  return;
}



/* FUN_1001f930 @ 1001f930 size 202 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1001f930(int param_1)

{
  *(undefined4 *)(param_1 + 0xbc) = 0xc1000000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc1000000;
  *(undefined4 *)(param_1 + 0xc4) = 0xc1000000;
  *(undefined4 *)(param_1 + 200) = 0x41000000;
  *(undefined4 *)(param_1 + 0xcc) = 0x41000000;
  *(undefined4 *)(param_1 + 0xd0) = 0x41000000;
  *(undefined4 *)(param_1 + 0xf8) = 1;
  *(undefined1 **)(param_1 + 0x1fc) = &LAB_1001f690;
  *(undefined4 *)(param_1 + 0xb8) = 1;
  if ((*(byte *)(param_1 + 0x11c) & 1) != 0) {
    if (*(float *)(param_1 + 0x148) == _DAT_1004410c) {
      *(undefined4 *)(param_1 + 0x148) = 0x43480000;
    }
    if (DAT_1006c2a0 == 0) {
      DAT_1006c2a0 = 200;
    }
    if (*(float *)(param_1 + 0x14) == _DAT_1004410c) {
      *(undefined4 *)(param_1 + 0x14) = 0x43b40000;
    }
    FUN_1001b0c0((float *)(param_1 + 0x10),(float *)(param_1 + 0x154));
    *(float *)(param_1 + 0x15c) = (float)DAT_1006c2a0;
  }
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10040a42 @ 10040a42 size 201 */

uint __cdecl FUN_10040a42(LPWSTR param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  DWORD *pDVar3;
  
  if ((param_2 != (byte *)0x0) && (param_3 != 0)) {
    bVar1 = *param_2;
    if (bVar1 != 0) {
      if (DAT_10061db8 == 0) {
        if (param_1 != (LPWSTR)0x0) {
          *param_1 = (ushort)bVar1;
        }
        return 1;
      }
      if ((PTR_DAT_1005fcc8[(uint)bVar1 * 2 + 1] & 0x80) == 0) {
        iVar2 = MultiByteToWideChar(DAT_10061dc8,9,(LPCSTR)param_2,1,param_1,
                                    (uint)(param_1 != (LPWSTR)0x0));
        if (iVar2 != 0) {
          return 1;
        }
      }
      else {
        if (1 < (int)DAT_1005fed4) {
          if ((int)param_3 < (int)DAT_1005fed4) goto LAB_10040ad4;
          iVar2 = MultiByteToWideChar(DAT_10061dc8,9,(LPCSTR)param_2,DAT_1005fed4,param_1,
                                      (uint)(param_1 != (LPWSTR)0x0));
          if (iVar2 != 0) {
            return DAT_1005fed4;
          }
        }
        if ((DAT_1005fed4 <= param_3) && (param_2[1] != 0)) {
          return DAT_1005fed4;
        }
      }
LAB_10040ad4:
      pDVar3 = FUN_1004058e();
      *pDVar3 = 0x2a;
      return 0xffffffff;
    }
    if (param_1 != (LPWSTR)0x0) {
      *param_1 = L'\0';
    }
  }
  return 0;
}



/* FUN_100306b0 @ 100306b0 size 200 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_100306b0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_10 = 9999999.0;
  iVar2 = 1;
  if (*(float *)(DAT_1006ca60 + 0x14) < _DAT_10044104) {
    return (float10)9999999.0;
  }
  iVar3 = 0x3d0;
  iVar1 = DAT_1006c2c4;
  do {
    if ((*(int *)(iVar3 + 0x58 + iVar1) != 0) && (0 < *(int *)(iVar3 + 0x220 + iVar1))) {
      local_c = *(float *)(param_1 + 4) - *(float *)(iVar3 + 4 + iVar1);
      local_8 = *(float *)(param_1 + 8) - *(float *)(iVar3 + 8 + iVar1);
      local_4 = *(float *)(param_1 + 0xc) - *(float *)(iVar3 + 0xc + iVar1);
      fVar4 = FUN_100389f0(&local_c);
      iVar1 = DAT_1006c2c4;
      if (fVar4 < (float10)local_10) {
        local_10 = (float)fVar4;
      }
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x3d0;
  } while ((float)iVar2 <= *(float *)(DAT_1006ca60 + 0x14));
  return (float10)local_10;
}



/* FUN_1003e93a @ 1003e93a size 200 */

undefined4 * FUN_1003e93a(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)0x0;
  FUN_1003c8a1(2);
  iVar3 = 0;
  if (0 < DAT_1006dde0) {
    do {
      iVar1 = *(int *)(DAT_1006cddc + iVar3 * 4);
      if (iVar1 == 0) {
        iVar3 = iVar3 * 4;
        pvVar2 = _malloc(0x38);
        *(void **)(iVar3 + DAT_1006cddc) = pvVar2;
        if (*(int *)(iVar3 + DAT_1006cddc) != 0) {
          InitializeCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_1006cddc) + 0x20));
          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_1006cddc) + 0x20));
          puVar4 = *(undefined4 **)(iVar3 + DAT_1006cddc);
LAB_1003e9de:
          if (puVar4 != (undefined4 *)0x0) {
            puVar4[4] = 0xffffffff;
            puVar4[1] = 0;
            puVar4[3] = 0;
            puVar4[2] = 0;
            *puVar4 = 0;
            puVar4[7] = 0;
          }
        }
        break;
      }
      if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
        FUN_1003dccf(iVar3,iVar1);
        iVar1 = *(int *)(DAT_1006cddc + iVar3 * 4);
        if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
          puVar4 = *(undefined4 **)(DAT_1006cddc + iVar3 * 4);
          goto LAB_1003e9de;
        }
        FUN_1003dd21(iVar3,iVar1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_1006dde0);
  }
  FUN_1003c902(2);
  return puVar4;
}



/* FUN_100183a0 @ 100183a0 size 199 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100183a0(int param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  
  *(code **)(param_1 + 0x200) = FUN_10018340;
  FUN_1001b0c0((float *)(param_1 + 0x10),(float *)(param_1 + 0x154));
  uVar1 = (*DAT_1006c1e4)(s_weapons_rocklf1a_wav_1004ba04);
  *(undefined4 *)(param_1 + 0x280) = uVar1;
  if (*(int *)(param_1 + 0x244) == 0) {
    _rand();
    lVar2 = __ftol();
    *(int *)(param_1 + 0x244) = 100 - (int)lVar2;
  }
  if (*(int *)(param_1 + 0x254) == 0) {
    *(undefined4 *)(param_1 + 0x254) = 0x78;
  }
  if (*(float *)(param_1 + 0x294) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x294) = 0x42f00000;
  }
  if (*(float *)(param_1 + 0x148) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x148) = 0x44228000;
  }
  *(undefined4 *)(param_1 + 0xb8) = 1;
  return;
}



/* FUN_100246a0 @ 100246a0 size 199 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100246a0(int param_1)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  if ((*(float *)(param_1 + 0x210) <= DAT_1006c2e4) &&
     (*(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4,
     *(int *)(DAT_1006c41c + 0x14) != 0x40400000)) {
    uVar1 = _rand();
    if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044378) {
      (*DAT_1006c1d0)(param_1,2,DAT_10061140);
      *(undefined **)(param_1 + 0x358) = &DAT_100516f8;
      return;
    }
    (*DAT_1006c1d0)(param_1,2,DAT_1006113c,0x3f800000,0x3f800000,0);
    *(undefined **)(param_1 + 0x358) = &DAT_10051730;
  }
  return;
}



/* FUN_100421c5 @ 100421c5 size 199 */

void __cdecl FUN_100421c5(char *param_1,int param_2,uint *param_3)

{
  uint *puVar1;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  puVar1 = param_3;
  local_8 = 0x404e;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  if (param_2 != 0) {
    param_3 = (uint *)param_2;
    do {
      local_14 = *puVar1;
      local_10 = puVar1[1];
      local_c = puVar1[2];
      FUN_1004216a(puVar1);
      FUN_1004216a(puVar1);
      ___add_12(puVar1,&local_14);
      FUN_1004216a(puVar1);
      local_10 = 0;
      local_c = 0;
      local_14 = (uint)*param_1;
      ___add_12(puVar1,&local_14);
      param_1 = param_1 + 1;
      param_3 = (uint *)((int)param_3 + -1);
    } while (param_3 != (uint *)0x0);
  }
  while (puVar1[2] == 0) {
    puVar1[2] = puVar1[1] >> 0x10;
    local_8 = local_8 + 0xfff0;
    puVar1[1] = *puVar1 >> 0x10 | puVar1[1] << 0x10;
    *puVar1 = *puVar1 << 0x10;
  }
  while ((puVar1[2] & 0x8000) == 0) {
    FUN_1004216a(puVar1);
    local_8 = local_8 + 0xffff;
  }
  *(undefined2 *)((int)puVar1 + 10) = (undefined2)local_8;
  return;
}



/* FUN_1002a850 @ 1002a850 size 198 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1002a850(int param_1)

{
  float10 fVar1;
  
  fVar1 = FUN_10038850();
  if (fVar1 != (float10)*(float *)(param_1 + 0x1e8)) {
    fVar1 = FUN_10038850();
    *(float *)(param_1 + 0x14) = (float)fVar1;
    return;
  }
  return;
}



/* GetGameAPI @ 1000d490 size 196 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * __cdecl GetGameAPI(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_1006c1c0;
                    /* 0xd490  1  GetGameAPI */
  for (iVar1 = 0x2c; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  _DAT_1006c120 = 3;
  _DAT_1006c124 = &LAB_100158d0;
  _DAT_1006c128 = &LAB_1000d460;
  _DAT_1006c12c = &LAB_10016c60;
  _DAT_1006c130 = &LAB_10016020;
  _DAT_1006c134 = &LAB_10016100;
  _DAT_1006c138 = &LAB_10016400;
  _DAT_1006c13c = &LAB_100164e0;
  _DAT_1006c154 = &LAB_10031d70;
  _DAT_1006c140 = FUN_10031950;
  _DAT_1006c148 = FUN_10031760;
  _DAT_1006c14c = FUN_10031c30;
  _DAT_1006c144 = &LAB_10031610;
  _DAT_1006c150 = &LAB_100055f0;
  _DAT_1006c158 = &LAB_1000d940;
  _DAT_1006c15c = &LAB_10017850;
  _DAT_1006c164 = 0x3d0;
  return &DAT_1006c120;
}



/* FUN_10014320 @ 10014320 size 195 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10014320(int param_1)

{
  if ((*(int *)(*(int *)(param_1 + 0x100) + 0x58) == 0) ||
     (*(int *)(*(int *)(*(int *)(param_1 + 0x100) + 0x54) + 0xf18) != param_1)) {
    FUN_100144c0(param_1);
  }
  if (_DAT_1004410c < *(float *)(param_1 + 0x120)) {
    *(float *)(param_1 + 0x120) = DAT_1006c2e4;
  }
  if (*(int *)(param_1 + 600) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 600) + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(*(int *)(param_1 + 600) + 8) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(*(int *)(param_1 + 600) + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(*(int *)(param_1 + 600) + 0x178) = *(undefined4 *)(param_1 + 0x178);
    *(undefined4 *)(*(int *)(param_1 + 600) + 0x17c) = *(undefined4 *)(param_1 + 0x17c);
    *(undefined4 *)(*(int *)(param_1 + 600) + 0x180) = *(undefined4 *)(param_1 + 0x180);
  }
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  return;
}



/* FUN_10006790 @ 10006790 size 194 */

int __cdecl
FUN_10006790(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
            byte param_6)

{
  int iVar1;
  int iVar2;
  float fVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  longlong lVar7;
  
  if (param_4 == 0) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x54);
  if (iVar1 == 0) {
    return 0;
  }
  if ((param_6 & 2) != 0) {
    return 0;
  }
  uVar4 = FUN_1000c290(param_1);
  if (uVar4 == 0) {
    return 0;
  }
  puVar5 = FUN_1000b0e0(uVar4);
  if ((param_6 & 4) == 0) {
    fVar3 = (float)param_4 * *(float *)(puVar5[0xf] + 8);
  }
  else {
    fVar3 = (float)param_4 * *(float *)(puVar5[0xf] + 0xc);
  }
  FUN_10039593((double)fVar3);
  lVar7 = __ftol();
  iVar2 = *(int *)(iVar1 + 0x2e4 + uVar4 * 4);
  iVar6 = (int)lVar7;
  if (iVar2 <= (int)lVar7) {
    iVar6 = iVar2;
  }
  if (iVar6 == 0) {
    return 0;
  }
  *(int *)(iVar1 + 0x2e4 + uVar4 * 4) = iVar2 - iVar6;
  FUN_10005df0(param_5,param_2,param_3);
  return iVar6;
}



/* FUN_10032b50 @ 10032b50 size 194 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10032b50(undefined4 param_1)

{
  char *pcVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined1 local_400 [1024];
  
  if (*(float *)(DAT_1006c41c + 0x14) == _DAT_1004410c) {
    pcVar1 = &DAT_1005f628;
  }
  else if (*(int *)(DAT_1006c41c + 0x14) == 0x3f800000) {
    pcVar1 = s_medium_1005f620;
  }
  else {
    pcVar1 = &DAT_1005f618;
    if (*(int *)(DAT_1006c41c + 0x14) != 0x40000000) {
      pcVar1 = s_hard__1005f610;
    }
  }
  puVar7 = &DAT_1006c640;
  puVar6 = &DAT_1006c440;
  puVar5 = &DAT_1006c2e8;
  pcVar4 = s_xv_32_yv_8_picn_help_xv_202_yv_1_1005f52c;
  puVar2 = local_400;
  uVar3 = 0x400;
  uVar8 = DAT_1006c400;
  uVar9 = DAT_1006c3fc;
  uVar10 = DAT_1006c3f8;
  uVar11 = DAT_1006c3f4;
  uVar12 = DAT_1006c3f0;
  uVar13 = DAT_1006c3ec;
  FUN_10038b40();
  (*DAT_1006c224)(4,puVar2,uVar3,pcVar4,pcVar1,puVar5,puVar6,puVar7,uVar8,uVar9,uVar10,uVar11,uVar12
                  ,uVar13);
  (*DAT_1006c234)(local_400);
  (*DAT_1006c21c)(param_1,1);
  return;
}



/* FUN_1003a561 @ 1003a561 size 194 */

undefined1 * __cdecl
FUN_1003a561(undefined1 *param_1,int param_2,int param_3,int *param_4,char param_5)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint *puVar3;
  int iVar4;
  
  if (param_5 != '\0') {
    FUN_1003a803(param_1 + (*param_4 == 0x2d),(uint)(0 < param_2));
  }
  puVar1 = param_1;
  if (*param_4 == 0x2d) {
    *param_1 = 0x2d;
    puVar1 = param_1 + 1;
  }
  puVar2 = puVar1;
  if (0 < param_2) {
    puVar2 = puVar1 + 1;
    *puVar1 = puVar1[1];
    *puVar2 = DAT_1005fed8;
  }
  puVar3 = FUN_10040000((uint *)(puVar2 + param_2 + (uint)(param_5 == '\0')),(uint *)"e+000");
  if (param_3 != 0) {
    *(undefined1 *)puVar3 = 0x45;
  }
  if (*(char *)param_4[3] != '0') {
    iVar4 = param_4[1] + -1;
    if (iVar4 < 0) {
      iVar4 = -iVar4;
      *(undefined1 *)((int)puVar3 + 1) = 0x2d;
    }
    if (99 < iVar4) {
      *(char *)((int)puVar3 + 2) = *(char *)((int)puVar3 + 2) + (char)(iVar4 / 100);
      iVar4 = iVar4 % 100;
    }
    if (9 < iVar4) {
      *(char *)((int)puVar3 + 3) = *(char *)((int)puVar3 + 3) + (char)(iVar4 / 10);
      iVar4 = iVar4 % 10;
    }
    *(char *)(puVar3 + 1) = (char)puVar3[1] + (char)iVar4;
  }
  return param_1;
}



/* FUN_1003db22 @ 1003db22 size 194 */

int __cdecl
FUN_1003db22(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_28 [2];
  int local_20;
  int local_18;
  uint local_14;
  int local_c;
  
  uVar3 = param_1 - 0x76c;
  if (((int)uVar3 < 0x46) || (0x8a < (int)uVar3)) {
    iVar2 = -1;
  }
  else {
    iVar4 = *(int *)(&DAT_10060760 + param_2 * 4) + param_3;
    if (((uVar3 & 3) == 0) && (2 < param_2)) {
      iVar4 = iVar4 + 1;
    }
    FUN_1003d456();
    local_20 = param_4;
    local_18 = param_2 + -1;
    iVar2 = ((param_4 + (uVar3 * 0x16d + iVar4 + (param_1 + -0x76d >> 2)) * 0x18) * 0x3c + param_5)
            * 0x3c + DAT_1005ffc8 + 0x7c558180 + param_6;
    if ((param_7 == 1) ||
       (((param_7 == -1 && (DAT_1005ffcc != 0)) &&
        (local_14 = uVar3, local_c = iVar4, bVar1 = FUN_1003d70b(local_28),
        CONCAT31(extraout_var,bVar1) != 0)))) {
      iVar2 = iVar2 + DAT_1005ffd0;
    }
  }
  return iVar2;
}



/* FUN_1000c010 @ 1000c010 size 193 */

void __cdecl FUN_1000c010(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = (int)(param_2 + -0x4011a4a) / 0x48;
  piVar4 = FUN_1000c850(param_1,param_2);
  iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + iVar3 * 4);
  if (iVar1 < param_2[0xc]) {
    piVar4[0x95] = iVar1;
  }
  else {
    piVar4[0x95] = param_2[0xc];
  }
  iVar1 = *(int *)(param_1 + 0x54);
  if ((((*(int *)(iVar1 + 0x714) != 0) && (*(int *)(*(int *)(iVar1 + 0x714) + 0x40) == 3)) &&
      (param_2[0x10] == 3)) &&
     (iVar2 = *(int *)(iVar1 + 0x2e4 + iVar3 * 4), iVar2 == piVar4[0x95] || iVar2 - piVar4[0x95] < 0
     )) {
    (*DAT_1006c1c8)(param_1,2,s_Can_t_drop_current_weapon_10048f6c);
    FUN_1001b400(piVar4);
    return;
  }
  *(int *)(iVar1 + 0x2e4 + iVar3 * 4) = *(int *)(iVar1 + 0x2e4 + iVar3 * 4) - piVar4[0x95];
  FUN_10003ef0(param_1);
  return;
}



/* FUN_10027c40 @ 10027c40 size 193 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10027c40(int param_1)

{
  uint uVar1;
  bool bVar2;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  if ((*(float *)(param_1 + 0x210) <= DAT_1006c2e4) &&
     (*(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4,
     *(int *)(DAT_1006c41c + 0x14) != 0x40400000)) {
    uVar1 = _rand();
    uVar1 = uVar1 & 0x80000001;
    bVar2 = uVar1 == 0;
    if ((int)uVar1 < 0) {
      bVar2 = (uVar1 - 1 | 0xfffffffe) == 0xffffffff;
    }
    if (bVar2) {
      *(undefined **)(param_1 + 0x358) = &DAT_10057090;
      (*DAT_1006c1d0)(param_1,2,DAT_1006122c,0x3f800000,0x3f800000,0);
      return;
    }
    *(undefined **)(param_1 + 0x358) = &DAT_10057118;
    (*DAT_1006c1d0)(param_1,2,DAT_10061228,0x3f800000,0x3f800000,0);
  }
  return;
}



/* FUN_10033170 @ 10033170 size 193 */

void __cdecl FUN_10033170(float *param_1)

{
  int iVar1;
  float10 fVar2;
  float local_c;
  float local_8;
  float local_4;
  
  if (DAT_1006138c != 0) {
    *(float *)((&DAT_100620a0)[DAT_100620c0] + 4) = *param_1;
    *(float *)((&DAT_100620a0)[DAT_100620c0] + 8) = param_1[1];
    *(float *)((&DAT_100620a0)[DAT_100620c0] + 0xc) = param_1[2];
    *(undefined4 *)((&DAT_100620a0)[DAT_100620c0] + 0x120) = DAT_1006c2e4;
    iVar1 = (&DAT_100620a0)[DAT_100620c0 - 1 & 7];
    local_c = *param_1 - *(float *)(iVar1 + 4);
    local_8 = param_1[1] - *(float *)(iVar1 + 8);
    local_4 = param_1[2] - *(float *)(iVar1 + 0xc);
    fVar2 = FUN_1001b160(&local_c);
    *(float *)((&DAT_100620a0)[DAT_100620c0] + 0x14) = (float)fVar2;
    DAT_100620c0 = DAT_100620c0 + 1 & 7;
  }
  return;
}



/* _strchr @ 100390f0 size 193 */

/* Library Function - Single Match
    _strchr
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strchr(char *_Str,int _Val)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  while (((uint)_Str & 3) != 0) {
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    _Str = (char *)((int)_Str + 1);
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
  }
  while( true ) {
    while( true ) {
      uVar1 = *(uint *)_Str;
      uVar4 = uVar1 ^ CONCAT22(CONCAT11((char)_Val,(char)_Val),CONCAT11((char)_Val,(char)_Val));
      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;
      puVar5 = (uint *)((int)_Str + 4);
      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;
      _Str = (char *)puVar5;
      if ((uVar3 & 0x81010100) != 0) {
        if ((uVar3 & 0x1010100) != 0) {
          return (char *)0x0;
        }
        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {
          return (char *)0x0;
        }
      }
    }
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 8);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 1);
    }
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 0x10);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 2);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uVar1 >> 0x18);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 3);
    }
    _Str = (char *)puVar5;
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
  }
  return (char *)0x0;
}



/* FUN_1003b101 @ 1003b101 size 193 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_1003b101(uint param_1,uint param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  float10 fVar5;
  undefined8 local_c;
  
  if ((double)CONCAT17(param_2._3_1_,CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1))) ==
      _DAT_10044268) {
    iVar4 = 0;
    local_c = 0.0;
  }
  else if (((param_2 & 0x7ff00000) == 0) && (((param_2 & 0xfffff) != 0 || (param_1 != 0)))) {
    iVar4 = -0x3fd;
    if (_DAT_10044268 <=
        (double)CONCAT17(param_2._3_1_,CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1)))) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    while ((param_2._2_1_ & 0x10) == 0) {
      iVar2 = CONCAT13(param_2._3_1_,CONCAT12(param_2._2_1_,(ushort)param_2)) << 1;
      param_2._0_2_ = (ushort)iVar2;
      param_2._2_1_ = (byte)((uint)iVar2 >> 0x10);
      param_2._3_1_ = (byte)((uint)iVar2 >> 0x18);
      if ((param_1 & 0x80000000) != 0) {
        param_2._0_2_ = (ushort)param_2 | 1;
      }
      param_1 = param_1 << 1;
      iVar4 = iVar4 + -1;
    }
    uVar1 = CONCAT11(param_2._3_1_,param_2._2_1_) & 0xffef;
    param_2._2_1_ = (byte)uVar1;
    param_2._3_1_ = (byte)(uVar1 >> 8);
    if (bVar3) {
      param_2._3_1_ = param_2._3_1_ | 0x80;
    }
    fVar5 = FUN_1003b07e(CONCAT17(param_2._3_1_,
                                  CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1))),0);
    local_c = (double)fVar5;
  }
  else {
    fVar5 = FUN_1003b07e(CONCAT17(param_2._3_1_,
                                  CONCAT16(param_2._2_1_,CONCAT24((ushort)param_2,param_1))),0);
    local_c = (double)fVar5;
    iVar4 = (short)((ushort)(param_2 >> 0x14) & 0x7ff) + -0x3fe;
  }
  *param_3 = iVar4;
  return (float10)local_c;
}



/* FUN_100195e0 @ 100195e0 size 191 */

void __cdecl FUN_100195e0(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x254) != 0) {
    iVar1 = *(int *)(param_1 + 0x254) + -1;
    *(int *)(param_1 + 0x254) = iVar1;
    if (iVar1 == 0) {
      if ((*(byte *)(param_1 + 0x11c) & 1) == 0) {
        (*DAT_1006c1cc)(param_3,s_Sequence_completed__1004bba0);
        uVar2 = (*DAT_1006c1e4)(s_misc_talk1_wav_10046130,0x3f800000,0x3f800000,0);
        (*DAT_1006c1d0)(param_3,0,uVar2);
      }
      *(undefined4 *)(param_1 + 0x264) = param_3;
      FUN_10018fb0(param_1);
    }
    else if ((*(byte *)(param_1 + 0x11c) & 1) == 0) {
      (*DAT_1006c1cc)(param_3,s__i_more_to_go____1004bbb4,iVar1);
      uVar2 = (*DAT_1006c1e4)(s_misc_talk1_wav_10046130,0x3f800000,0x3f800000,0);
      (*DAT_1006c1d0)(param_3,0,uVar2);
      return;
    }
  }
  return;
}



/* FUN_1000a560 @ 1000a560 size 190 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000a560(int param_1)

{
  float fVar1;
  uint uVar2;
  
  if (*(byte **)(param_1 + 0x128) == (byte *)0x0) {
    (*DAT_1006c1c4)(s_train_find__no_target_100467ac);
    return;
  }
  uVar2 = FUN_1001ad80(*(byte **)(param_1 + 0x128));
  if (uVar2 == 0) {
    (*DAT_1006c1c4)(s_train_find__target__s_not_found_10046788,*(undefined4 *)(param_1 + 0x128));
    return;
  }
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(uVar2 + 0x128);
  *(float *)(param_1 + 4) = *(float *)(uVar2 + 4) - *(float *)(param_1 + 0xbc);
  *(float *)(param_1 + 8) = *(float *)(uVar2 + 8) - *(float *)(param_1 + 0xc0);
  *(float *)(param_1 + 0xc) = *(float *)(uVar2 + 0xc) - *(float *)(param_1 + 0xc4);
  (*DAT_1006c208)(param_1);
  if (*(int *)(param_1 + 300) == 0) {
    *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) | 1;
  }
  if ((*(byte *)(param_1 + 0x11c) & 1) != 0) {
    fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
    *(code **)(param_1 + 500) = FUN_1000a300;
    *(int *)(param_1 + 0x264) = param_1;
    *(float *)(param_1 + 0x1ec) = fVar1;
  }
  return;
}



/* FUN_1001db40 @ 1001db40 size 190 */

void __cdecl FUN_1001db40(undefined4 *param_1)

{
  undefined4 uVar1;
  float local_c [3];
  
  param_1[0x60] = 0;
  param_1[0x5f] = 0;
  param_1[0x5e] = 0.0;
  FUN_10006860((float)param_1,param_1[0x40],(float)(int)param_1[0x91],0,(float)param_1[0x93],0x2a);
  FUN_10038950((float *)(param_1 + 1),-0.02,(float *)(param_1 + 0x5e),local_c);
  (*DAT_1006c224)(3);
  if (param_1[0xaa] == 0) {
    if (param_1[0x9a] == 0) {
      uVar1 = 7;
    }
    else {
      uVar1 = 8;
    }
  }
  else if (param_1[0x9a] == 0) {
    uVar1 = 0x11;
  }
  else {
    uVar1 = 0x12;
  }
  (*DAT_1006c224)(uVar1);
  (*DAT_1006c238)(local_c);
  (*DAT_1006c218)(param_1 + 1,2);
  FUN_1001b400(param_1);
  return;
}



/* FUN_100035f0 @ 100035f0 size 187 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100035f0(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0x104) = 8;
  *(undefined4 *)(param_1 + 0xb8) = 1;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 200) = 0;
  if (*(int *)(param_1 + 300) == 0) {
    (*DAT_1006c1c0)(2,s__s_with_no_targetname_100460c4,*(undefined4 *)(param_1 + 0x118));
    *(undefined **)(param_1 + 300) = &DAT_10060c60;
  }
  if (*(float *)(param_1 + 0x290) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x290) = 0x40400000;
  }
  *(code **)(param_1 + 0x200) = FUN_100035d0;
  *(undefined1 **)(param_1 + 500) = &LAB_10003420;
  uVar1 = (*DAT_1006c1e0)(s_sprites_s_deatom1_sp2_100460ac);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_100208c0 @ 100208c0 size 187 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100208c0(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  if (*(float *)(param_1 + 0x210) <= DAT_1006c2e4) {
    *(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4;
    (*DAT_1006c1d0)(param_1,2,DAT_10061008,0x3f800000,0x3f800000,0);
    if (*(int *)(DAT_1006c41c + 0x14) != 0x40400000) {
      if (0x13 < param_4) {
        uVar1 = _rand();
        if ((float)_DAT_10044140 <= (float)(uVar1 & 0x7fff) * _DAT_10044108) {
          *(undefined **)(param_1 + 0x358) = &DAT_1004d520;
          return;
        }
      }
      *(undefined **)(param_1 + 0x358) = &DAT_1004d420;
    }
  }
  return;
}



/* FUN_10026da0 @ 10026da0 size 187 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10026da0(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  if (*(float *)(param_1 + 0x210) <= DAT_1006c2e4) {
    *(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4;
    uVar1 = _rand();
    uVar2 = DAT_100611e0;
    if ((uVar1 & 1) != 0) {
      uVar2 = DAT_100611d0;
    }
    (*DAT_1006c1d0)(param_1,2,uVar2,0x3f800000,0x3f800000,0);
    if (*(int *)(DAT_1006c41c + 0x14) != 0x40400000) {
      if (param_4 < 0xb) {
        *(undefined **)(param_1 + 0x358) = &DAT_10055718;
        return;
      }
      if (param_4 < 0x1a) {
        *(undefined **)(param_1 + 0x358) = &DAT_10055788;
        return;
      }
      *(undefined **)(param_1 + 0x358) = &DAT_10055870;
    }
  }
  return;
}



/* FUN_10012b50 @ 10012b50 size 186 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10012b50(int param_1)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = FUN_1002ae40(param_1,0.0,0.0);
  if (iVar1 == 0) {
    iVar1 = param_1 + 4;
    puVar2 = FUN_1001b070();
    (*DAT_1006c1c4)(s__s_in_solid_at__s_100497dc,*(undefined4 *)(param_1 + 0x118),puVar2,iVar1);
  }
  if (*(float *)(param_1 + 0x1e4) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x1e4) = 0x41200000;
  }
  iVar1 = FUN_10038b20(*(void **)(param_1 + 0x118),(byte *)s_monster_flyer_100497f0);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x23c) = 0;
  }
  else {
    iVar1 = FUN_10038b20(*(void **)(param_1 + 0x118),(byte *)s_monster_flyer_100497f0);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x23c) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x23c) = 0x19;
    }
  }
  FUN_10012750(param_1);
  if ((*(byte *)(param_1 + 0x11c) & 2) != 0) {
    FUN_10012530(param_1);
  }
  return;
}



/* FUN_10031c30 @ 10031c30 size 185 */

void __cdecl FUN_10031c30(int param_1)

{
  if (*(int *)(param_1 + 0x54) != 0) {
    (*DAT_1006c1c0)(2,s__s_disconnected_1005f4b4,*(int *)(param_1 + 0x54) + 700);
    (*DAT_1006c224)(1);
    (*DAT_1006c228)((param_1 - DAT_1006c2c4) / 0x3d0);
    (*DAT_1006c224)(10);
    (*DAT_1006c218)(param_1 + 4,2);
    (*DAT_1006c20c)(param_1);
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0xf8) = 0;
    *(undefined4 *)(param_1 + 0x58) = 0;
    *(char **)(param_1 + 0x118) = s_disconnected_1005f4a4;
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x2d0) = 0;
    (*DAT_1006c1d8)((param_1 - DAT_1006c2c4) / 0x3d0 + 0x51f,&DAT_10060c60);
  }
  return;
}



/* FUN_1003f35b @ 1003f35b size 185 */

void FUN_1003f35b(void)

{
  char cVar1;
  size_t sVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  uint *puVar6;
  
  if (DAT_1006cdc8 == 0) {
    FUN_10042046();
  }
  iVar5 = 0;
  for (puVar6 = DAT_10061c4c; (char)*puVar6 != '\0'; puVar6 = (uint *)((int)puVar6 + sVar2 + 1)) {
    if ((char)*puVar6 != '=') {
      iVar5 = iVar5 + 1;
    }
    sVar2 = _strlen((char *)puVar6);
  }
  puVar3 = _malloc(iVar5 * 4 + 4);
  DAT_10061dfc = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = (char)*DAT_10061c4c;
  puVar6 = DAT_10061c4c;
  while (cVar1 != '\0') {
    sVar2 = _strlen((char *)puVar6);
    if ((char)*puVar6 != '=') {
      pvVar4 = _malloc(sVar2 + 1);
      *puVar3 = pvVar4;
      if (pvVar4 == (void *)0x0) {
        __amsg_exit(9);
      }
      FUN_10040000((uint *)*puVar3,puVar6);
      puVar3 = puVar3 + 1;
    }
    puVar6 = (uint *)((int)puVar6 + sVar2 + 1);
    cVar1 = (char)*puVar6;
  }
  FUN_100396e7(DAT_10061c4c);
  DAT_10061c4c = (uint *)0x0;
  *puVar3 = 0;
  DAT_1006cdc4 = 1;
  return;
}



/* FUN_10006c40 @ 10006c40 size 184 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10006c40(int param_1)

{
  int iVar1;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(int *)(param_1 + 0x330) == 2) {
    local_c = *(float *)(param_1 + 0x304) - *(float *)(param_1 + 0x10);
    local_8 = *(float *)(param_1 + 0x308) - *(float *)(param_1 + 0x14);
    local_4 = *(float *)(param_1 + 0x30c);
  }
  else {
    local_c = *(float *)(param_1 + 0x2ec) - *(float *)(param_1 + 0x10);
    local_8 = *(float *)(param_1 + 0x2f0) - *(float *)(param_1 + 0x14);
    local_4 = *(float *)(param_1 + 0x2f4);
  }
  local_4 = local_4 - *(float *)(param_1 + 0x18);
  iVar1 = FUN_100388c0(&local_c,(float *)&DAT_10061c18);
  if (iVar1 != 0) {
    FUN_10006c10(param_1);
    return;
  }
  FUN_10038a20(&local_c,10.0,(float *)(param_1 + 0x184));
  *(code **)(param_1 + 500) = FUN_10006c10;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  return;
}



/* FUN_10011d90 @ 10011d90 size 183 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10011d90(int param_1)

{
  uint uVar1;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  local_c = *(undefined4 *)(param_1 + 4);
  local_8 = *(undefined4 *)(param_1 + 8);
  local_4 = *(float *)(param_1 + 0xc4) + *(float *)(param_1 + 0xc) + _DAT_10044104;
  uVar1 = (*DAT_1006c1f4)(&local_c);
  if ((uVar1 & 0x38) == 0) {
    *(undefined4 *)(param_1 + 0x2a8) = 0;
    *(undefined4 *)(param_1 + 0x2a4) = 0;
    return;
  }
  local_4 = local_4 + _DAT_1004423c;
  *(uint *)(param_1 + 0x2a4) = uVar1;
  *(undefined4 *)(param_1 + 0x2a8) = 1;
  uVar1 = (*DAT_1006c1f4)(&local_c);
  if ((uVar1 & 0x38) != 0) {
    local_4 = local_4 + _DAT_10044238;
    *(undefined4 *)(param_1 + 0x2a8) = 2;
    uVar1 = (*DAT_1006c1f4)(&local_c);
    if ((uVar1 & 0x38) != 0) {
      *(undefined4 *)(param_1 + 0x2a8) = 3;
    }
  }
  return;
}



/* FUN_1000a8b0 @ 1000a8b0 size 182 */

void __cdecl FUN_1000a8b0(int param_1)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  char *pcVar5;
  bool bVar6;
  
  if (*(byte **)(param_1 + 0x128) == (byte *)0x0) {
    (*DAT_1006c1c4)(s_trigger_elevator_has_no_target_10046898);
    return;
  }
  uVar2 = FUN_1001ad80(*(byte **)(param_1 + 0x128));
  *(uint *)(param_1 + 0x1e0) = uVar2;
  if (uVar2 == 0) {
    (*DAT_1006c1c4)(s_trigger_elevator_unable_to_find_t_1004686c,*(undefined4 *)(param_1 + 0x128));
    return;
  }
  pbVar3 = *(byte **)(uVar2 + 0x118);
  pcVar5 = s_func_train_10046860;
  do {
    bVar1 = *pbVar3;
    bVar6 = bVar1 < (byte)*pcVar5;
    if (bVar1 != *pcVar5) {
LAB_1000a92e:
      iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      goto LAB_1000a933;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar3[1];
    bVar6 = bVar1 < (byte)pcVar5[1];
    if (bVar1 != pcVar5[1]) goto LAB_1000a92e;
    pbVar3 = pbVar3 + 2;
    pcVar5 = pcVar5 + 2;
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_1000a933:
  if (iVar4 != 0) {
    (*DAT_1006c1c4)(s_trigger_elevator_target__s_is_no_10046834,*(undefined4 *)(param_1 + 0x128));
    return;
  }
  *(undefined1 **)(param_1 + 0x200) = &LAB_1000a820;
  *(undefined4 *)(param_1 + 0xb8) = 1;
  return;
}



/* FUN_1003ff4a @ 1003ff4a size 182 */

void __cdecl FUN_1003ff4a(uint *param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint local_8;
  
  uVar1 = *(ushort *)((int)param_2 + 6);
  uVar3 = (uVar1 & 0x7ff0) >> 4;
  uVar2 = *param_2;
  local_8 = 0x80000000;
  if (uVar3 == 0) {
    if (((param_2[1] & 0xfffff) == 0) && (uVar2 == 0)) {
      param_1[1] = 0;
      *param_1 = 0;
      *(undefined2 *)(param_1 + 2) = 0;
      return;
    }
    iVar4 = 0x3c01;
    local_8 = 0;
  }
  else if (uVar3 == 0x7ff) {
    iVar4 = 0x7fff;
  }
  else {
    iVar4 = uVar3 + 0x3c00;
  }
  local_8 = uVar2 >> 0x15 | (param_2[1] & 0xfffff) << 0xb | local_8;
  param_1[1] = local_8;
  *param_1 = uVar2 << 0xb;
  while ((local_8 & 0x80000000) == 0) {
    local_8 = *param_1 >> 0x1f | local_8 * 2;
    *param_1 = *param_1 * 2;
    param_1[1] = local_8;
    iVar4 = iVar4 + 0xffff;
  }
  *(ushort *)(param_1 + 2) = uVar1 & 0x8000 | (ushort)iVar4;
  return;
}



/* FUN_1000db40 @ 1000db40 size 181 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000db40(int param_1)

{
  if (_DAT_100441ec <= *(float *)(param_1 + 0x178)) {
    if (_DAT_100441c4 < *(float *)(param_1 + 0x178)) {
      *(undefined4 *)(param_1 + 0x178) = 0x43960000;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x178) = 0xc3960000;
  }
  if (_DAT_100441ec <= *(float *)(param_1 + 0x17c)) {
    if (_DAT_100441c4 < *(float *)(param_1 + 0x17c)) {
      *(undefined4 *)(param_1 + 0x17c) = 0x43960000;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x17c) = 0xc3960000;
  }
  if (*(float *)(param_1 + 0x180) < _DAT_100441e8) {
    *(undefined4 *)(param_1 + 0x180) = 0x43480000;
    return;
  }
  if (_DAT_10044114 < *(float *)(param_1 + 0x180)) {
    *(undefined4 *)(param_1 + 0x180) = 0x43fa0000;
  }
  return;
}



/* FUN_10012170 @ 10012170 size 179 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10012170(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  int local_38 [2];
  float fStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  local_3c = *(float *)(param_1 + 0xc) + _DAT_10044104;
  local_44 = *(undefined4 *)(param_1 + 4);
  local_40 = *(undefined4 *)(param_1 + 8);
  *(float *)(param_1 + 0xc) = local_3c;
  local_3c = local_3c - _DAT_10044248;
  piVar1 = (int *)(*DAT_1006c1f0)(local_38,(undefined4 *)(param_1 + 4),param_1 + 0xbc,param_1 + 200,
                                  &local_44,param_1,0x2020003);
  piVar3 = local_38;
  for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = *piVar1;
    piVar1 = piVar1 + 1;
    piVar3 = piVar3 + 1;
  }
  if ((fStack_30 != _DAT_10044104) && (local_38[0] == 0)) {
    *(undefined4 *)(param_1 + 4) = uStack_2c;
    *(undefined4 *)(param_1 + 8) = uStack_28;
    *(undefined4 *)(param_1 + 0xc) = uStack_24;
    (*DAT_1006c208)(param_1);
    FUN_10011c90(param_1);
    FUN_10011d90(param_1);
  }
  return;
}



/* FUN_100254e0 @ 100254e0 size 178 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100254e0(int param_1)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  if ((*(float *)(param_1 + 0x210) <= DAT_1006c2e4) &&
     (*(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4,
     *(int *)(DAT_1006c41c + 0x14) != 0x40400000)) {
    iVar1 = _rand();
    uVar2 = iVar1 + 1U & 0x80000001;
    bVar3 = uVar2 == 0;
    if ((int)uVar2 < 0) {
      bVar3 = (uVar2 - 1 | 0xfffffffe) == 0xffffffff;
    }
    if (bVar3) {
      (*DAT_1006c1d0)(param_1,2,DAT_10061160);
      *(undefined **)(param_1 + 0x358) = &DAT_10052758;
      return;
    }
    (*DAT_1006c1d0)(param_1,2,DAT_10061158,0x3f800000,0x3f800000,0);
    *(undefined **)(param_1 + 0x358) = &DAT_10052708;
  }
  return;
}



/* FUN_100010b0 @ 100010b0 size 177 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_100010b0(int param_1)

{
  uint uVar1;
  
  if ((((*(byte *)(param_1 + 0x11c) & 1) == 0) && (*(code **)(param_1 + 0x36c) != (code *)0x0)) &&
     (*(float *)(param_1 + 0x3c0) < DAT_1006c2e4)) {
    if (*(float *)(param_1 + 0x3c0) != _DAT_1004410c) {
      (**(code **)(param_1 + 0x36c))(param_1);
      uVar1 = _rand();
      *(float *)(param_1 + 0x3c0) =
           ((float)(uVar1 & 0x7fff) * _DAT_10044108 + _DAT_10044104) * _DAT_10044100 + DAT_1006c2e4;
      return 1;
    }
    uVar1 = _rand();
    *(float *)(param_1 + 0x3c0) =
         (float)(uVar1 & 0x7fff) * _DAT_10044108 * _DAT_10044100 + DAT_1006c2e4;
  }
  return 0;
}



/* FUN_1003cfb4 @ 1003cfb4 size 177 */

undefined4 * FUN_1003cfb4(void)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  
  if (DAT_1006ddf4 == DAT_1006dde4) {
    pvVar2 = HeapReAlloc(DAT_1006ddfc,0,DAT_1006ddf8,(DAT_1006dde4 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_1006dde4 = DAT_1006dde4 + 0x10;
    DAT_1006ddf8 = pvVar2;
  }
  puVar1 = (undefined4 *)((int)DAT_1006ddf8 + DAT_1006ddf4 * 0x14);
  pvVar2 = HeapAlloc(DAT_1006ddfc,8,0x41c4);
  puVar1[4] = pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar1[3] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      puVar1[2] = 0xffffffff;
      *puVar1 = 0;
      puVar1[1] = 0;
      DAT_1006ddf4 = DAT_1006ddf4 + 1;
      *(undefined4 *)puVar1[4] = 0xffffffff;
      return puVar1;
    }
    HeapFree(DAT_1006ddfc,0,(LPVOID)puVar1[4]);
  }
  return (undefined4 *)0x0;
}



/* FUN_100305a0 @ 100305a0 size 176 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100305a0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < DAT_1006ca48) {
    iVar2 = 0;
    iVar3 = 0x3d0;
    do {
      iVar1 = iVar3 + DAT_1006c2c4;
      if (*(int *)(iVar3 + 0x58 + DAT_1006c2c4) != 0) {
        *(undefined4 *)(iVar2 + 0x2d4 + DAT_1006c844) = *(undefined4 *)(iVar1 + 0x220);
        *(undefined4 *)(iVar2 + 0x2d8 + DAT_1006c844) = *(undefined4 *)(iVar1 + 0x224);
        *(uint *)(iVar2 + 0x2dc + DAT_1006c844) = *(uint *)(iVar1 + 0x108) & 0x1030;
        if (*(float *)(DAT_1006c42c + 0x14) != _DAT_1004410c) {
          *(undefined4 *)(iVar2 + 0x720 + DAT_1006c844) =
               *(undefined4 *)(*(int *)(iVar1 + 0x54) + 0xda8);
        }
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x3d0;
      iVar2 = iVar2 + 0xf34;
    } while (iVar4 < DAT_1006ca48);
  }
  return;
}



/* FUN_10001170 @ 10001170 size 175 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10001170(int param_1)

{
  int iVar1;
  float10 fVar2;
  float local_c;
  float local_8;
  float local_4;
  
  iVar1 = *(int *)(param_1 + 0x25c);
  if (iVar1 != 0) {
    local_c = *(float *)(iVar1 + 4) - *(float *)(param_1 + 4);
    local_8 = *(float *)(iVar1 + 8) - *(float *)(param_1 + 8);
    local_4 = *(float *)(iVar1 + 0xc) - *(float *)(param_1 + 0xc);
    fVar2 = FUN_1001b160(&local_c);
    *(float *)(param_1 + 0x1e8) = (float)fVar2;
    FUN_1002a850(param_1);
    FUN_100022a0(param_1);
    return;
  }
  iVar1 = FUN_10001bc0(param_1);
  if ((iVar1 == 0) && ((*(byte *)(param_1 + 0x35c) & 3) == 0)) {
    if ((*(float *)(param_1 + 0x390) != _DAT_1004410c) &&
       (*(float *)(param_1 + 0x390) < DAT_1006c2e4)) {
      (**(code **)(param_1 + 0x374))(param_1);
      return;
    }
    FUN_100010b0(param_1);
  }
  return;
}



/* FUN_10025be0 @ 10025be0 size 175 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10025be0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  if ((*(float *)(param_1 + 0x210) <= DAT_1006c2e4) &&
     (*(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4,
     *(int *)(DAT_1006c41c + 0x14) != 0x40400000)) {
    iVar1 = _rand();
    if ((iVar1 + 1) % 3 == 0) {
      (*DAT_1006c1d0)(param_1,2,DAT_10061184);
      *(undefined **)(param_1 + 0x358) = &DAT_10053720;
      return;
    }
    (*DAT_1006c1d0)(param_1,2,DAT_10061180,0x3f800000,0x3f800000,0);
    *(undefined **)(param_1 + 0x358) = &DAT_10053790;
  }
  return;
}



/* FUN_100173e0 @ 100173e0 size 174 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong __cdecl FUN_100173e0(char *param_1)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  uint *puVar4;
  char *pcVar5;
  int iVar6;
  longlong lVar7;
  
  iVar6 = 0;
  pcVar5 = param_1;
  if (*param_1 != '\0') {
    while (iVar6 < 4) {
      cVar2 = *pcVar5;
      *(undefined1 *)((int)&param_1 + iVar6) = 0;
      while (('/' < cVar2 && (cVar2 < ':'))) {
        cVar3 = *(char *)((int)&param_1 + iVar6) * '\n' + cVar2;
        cVar2 = pcVar5[1];
        pcVar5 = pcVar5 + 1;
        *(char *)((int)&param_1 + iVar6) = cVar3 + -0x30;
      }
      if ((*pcVar5 == '\0') || (*pcVar5 == ':')) break;
      pcVar1 = pcVar5 + 1;
      iVar6 = iVar6 + 1;
      pcVar5 = pcVar5 + 1;
      if (*pcVar1 == '\0') break;
    }
  }
  iVar6 = 0;
  if (0 < (int)DAT_100620d0) {
    puVar4 = &DAT_100620e4;
    do {
      if ((puVar4[-1] & (uint)param_1) == *puVar4) {
        lVar7 = __ftol();
        return lVar7;
      }
      iVar6 = iVar6 + 1;
      puVar4 = puVar4 + 2;
    } while (iVar6 < (int)DAT_100620d0);
  }
  if (*(float *)(DAT_1006c178 + 0x14) != _DAT_1004410c) {
    return (ulonglong)DAT_100620d0 << 0x20;
  }
  return CONCAT44(DAT_100620d0,1);
}



/* FUN_1001b350 @ 1001b350 size 174 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_1001b350(void)

{
  int iVar1;
  int *piVar2;
  longlong lVar3;
  
  lVar3 = __ftol();
  piVar2 = (int *)(((int)lVar3 + 1) * 0x3d0 + DAT_1006c2c4);
  lVar3 = __ftol();
  for (iVar1 = (int)lVar3; iVar1 < DAT_1006c168; iVar1 = iVar1 + 1) {
    if ((piVar2[0x16] == 0) &&
       (((float)piVar2[0x44] < _DAT_1004413c ||
        ((float)_DAT_10044140 < DAT_1006c2e4 - (float)piVar2[0x44])))) goto LAB_1001b3f0;
    piVar2 = piVar2 + 0xf4;
  }
  if (iVar1 == DAT_1006ca4c) {
    (*DAT_1006c1dc)(s_ED_Alloc__no_free_edicts_1004be44);
  }
  DAT_1006c168 = DAT_1006c168 + 1;
LAB_1001b3f0:
  FUN_1001b310(piVar2);
  return piVar2;
}



/* FUN_1002bbc0 @ 1002bbc0 size 173 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1002bbc0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  if ((*(float *)(param_1 + 0x210) <= DAT_1006c2e4) &&
     (*(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4,
     *(int *)(DAT_1006c41c + 0x14) != 0x40400000)) {
    uVar1 = _rand();
    uVar2 = DAT_100612e8;
    if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044140) {
      uVar2 = DAT_100612ec;
    }
    (*DAT_1006c1d0)(param_1,2,uVar2,0x3f800000,0x3f800000,0);
    *(undefined **)(param_1 + 0x358) = &DAT_1005abc0;
  }
  return;
}



/* FUN_10003880 @ 10003880 size 172 */

void __cdecl FUN_10003880(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0x104) = 8;
  *(undefined4 *)(param_1 + 0xb8) = 1;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 200) = 0;
  if (*(int *)(param_1 + 300) == 0) {
    (*DAT_1006c1c0)(2,s__s_with_no_targetname_100460c4,*(undefined4 *)(param_1 + 0x118));
    *(undefined **)(param_1 + 300) = &DAT_10060c60;
  }
  *(undefined4 *)(param_1 + 0x254) = 0;
  *(undefined4 *)(param_1 + 0x1e0) = 0;
  *(code **)(param_1 + 0x200) = FUN_10003760;
  *(code **)(param_1 + 500) = FUN_100036b0;
  uVar1 = (*DAT_1006c1e0)(s_sprites_s_deatom1_sp2_100460ac);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10021300 @ 10021300 size 172 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10021300(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  if (*(float *)(param_1 + 0x210) <= DAT_1006c2e4) {
    *(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4;
    uVar1 = DAT_10061028;
    if ((param_4 < 10) || (uVar1 = DAT_10061030, param_4 < 0x1e)) {
      (*DAT_1006c1d0)(param_1,2,uVar1,0x3f800000,0,0);
      *(undefined **)(param_1 + 0x358) = &DAT_1004dec8;
      return;
    }
    (*DAT_1006c1d0)(param_1,2,DAT_10061024,0x3f800000,0,0);
    *(undefined **)(param_1 + 0x358) = &DAT_1004de88;
  }
  return;
}



/* FUN_10038a70 @ 10038a70 size 172 */

undefined * __cdecl FUN_10038a70(undefined4 *param_1)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  
  iVar4 = 0;
  pcVar2 = (char *)*param_1;
  DAT_10062000 = 0;
  if (pcVar2 == (char *)0x0) {
LAB_10038a83:
    *param_1 = 0;
    return &DAT_10060c60;
  }
  do {
    do {
      cVar3 = *pcVar2;
      while (cVar3 < '!') {
        if (cVar3 == '\0') goto LAB_10038a83;
        pcVar1 = pcVar2 + 1;
        pcVar2 = pcVar2 + 1;
        cVar3 = *pcVar1;
      }
      if (cVar3 != '/') {
        if (cVar3 != '\"') goto LAB_10038ae9;
        pcVar2 = pcVar2 + 1;
        while( true ) {
          cVar3 = *pcVar2;
          pcVar2 = pcVar2 + 1;
          if ((cVar3 == '\"') || (cVar3 == '\0')) break;
          if (iVar4 < 0x80) {
            (&DAT_10062000)[iVar4] = cVar3;
            iVar4 = iVar4 + 1;
          }
        }
LAB_10038b0c:
        (&DAT_10062000)[iVar4] = 0;
        *param_1 = pcVar2;
        return &DAT_10062000;
      }
      if (pcVar2[1] != '/') {
        do {
          (&DAT_10062000)[iVar4] = cVar3;
          iVar4 = iVar4 + 1;
          do {
            cVar3 = pcVar2[1];
            pcVar2 = pcVar2 + 1;
            if (cVar3 < '!') {
              if (iVar4 == 0x80) {
                iVar4 = 0;
              }
              goto LAB_10038b0c;
            }
LAB_10038ae9:
          } while (0x7f < iVar4);
        } while( true );
      }
      cVar3 = *pcVar2;
    } while (cVar3 == '\0');
    do {
      if (cVar3 == '\n') break;
      cVar3 = pcVar2[1];
      pcVar2 = pcVar2 + 1;
    } while (cVar3 != '\0');
  } while( true );
}



/* FUN_1000c4b0 @ 1000c4b0 size 171 */

void __cdecl FUN_1000c4b0(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if ((*(uint *)(param_1 + 0x108) & 0x1000) == 0) {
    puVar1 = FUN_1000b150((byte *)s_cells_10049004);
    if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar1 + -0x4011a4a) / 0x48) * 4) == 0) {
      (*DAT_1006c1c8)(param_1,2,s_No_cells_for_power_armor__10048fe8);
      return;
    }
    *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) | 0x1000;
    pcVar3 = s_misc_power1_wav_10048fd8;
  }
  else {
    *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) & 0xffffefff;
    pcVar3 = s_misc_power2_wav_1004900c;
  }
  uVar2 = (*DAT_1006c1e4)(pcVar3,0x3f800000,0x3f800000,0);
  (*DAT_1006c1d0)(param_1,0,uVar2);
  return;
}



/* FUN_10007050 @ 10007050 size 170 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10007050(int param_1)

{
  float fVar1;
  
  *(float *)(param_1 + 0x34c) = *(float *)(param_1 + 0x34c) - *(float *)(param_1 + 0x340);
  if (*(float *)(param_1 + 0x340) == _DAT_1004410c) {
    FUN_10006e60(param_1 + 0x2e0);
  }
  FUN_10006f10(param_1 + 0x2e0);
  if (*(float *)(param_1 + 0x34c) <= *(float *)(param_1 + 0x340)) {
    FUN_10006a00(param_1);
    return;
  }
  FUN_10038a20((float *)(param_1 + 0x334),*(float *)(param_1 + 0x340) * _DAT_100441b0,
               (float *)(param_1 + 0x178));
  fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
  *(code **)(param_1 + 500) = FUN_10007050;
  *(float *)(param_1 + 0x1ec) = fVar1;
  return;
}



/* FUN_1000da90 @ 1000da90 size 170 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000da90(int param_1,float *param_2)

{
  float fVar1;
  uint uVar2;
  
  uVar2 = _rand();
  fVar1 = (float)(uVar2 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  *param_2 = (fVar1 + fVar1) * (float)_DAT_100441e0;
  uVar2 = _rand();
  fVar1 = (float)(uVar2 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  param_2[1] = (fVar1 + fVar1) * (float)_DAT_100441e0;
  uVar2 = _rand();
  param_2[2] = (float)(uVar2 & 0x7fff) * _DAT_10044108 * (float)_DAT_100441e0 + (float)_DAT_100441d8
  ;
  if (param_1 < 0x32) {
    FUN_10038a20(param_2,0.7,param_2);
    return;
  }
  FUN_10038a20(param_2,1.2,param_2);
  return;
}



/* FUN_10006e60 @ 10006e60 size 169 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10006e60(int param_1)

{
  float fVar1;
  
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x40);
  if (*(float *)(param_1 + 0x6c) < *(float *)(param_1 + 0x3c)) {
    *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0x6c);
    return;
  }
  fVar1 = (*(float *)(param_1 + 0x40) / *(float *)(param_1 + 0x44) + _DAT_10044104) *
          *(float *)(param_1 + 0x40) * _DAT_10044158;
  if ((*(float *)(param_1 + 0x6c) -
      (*(float *)(param_1 + 0x40) / *(float *)(param_1 + 0x3c) + _DAT_10044104) *
      *(float *)(param_1 + 0x40) * _DAT_10044158) - fVar1 < _DAT_1004410c) {
    fVar1 = (*(float *)(param_1 + 0x44) + *(float *)(param_1 + 0x3c)) /
            (*(float *)(param_1 + 0x44) * *(float *)(param_1 + 0x3c));
    fVar1 = (SQRT(_DAT_100441a8 - *(float *)(param_1 + 0x6c) * _DAT_100441ac * fVar1 * _DAT_100441a8
                 ) - (float)_DAT_100441a0) / (fVar1 + fVar1);
    *(float *)(param_1 + 100) = fVar1;
    fVar1 = (fVar1 / *(float *)(param_1 + 0x44) + _DAT_10044104) * fVar1 * _DAT_10044158;
  }
  *(float *)(param_1 + 0x70) = fVar1;
  return;
}



/* FUN_10012a80 @ 10012a80 size 169 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10012a80(int param_1)

{
  int iVar1;
  undefined *puVar2;
  
  if (((*(byte *)(param_1 + 0x11c) & 2) == 0) && (DAT_1006c2e4 < _DAT_10044104)) {
    FUN_10012170(param_1);
    if (*(int *)(param_1 + 0x268) != 0) {
      iVar1 = FUN_1002ae40(param_1,0.0,0.0);
      if (iVar1 == 0) {
        iVar1 = param_1 + 4;
        puVar2 = FUN_1001b070();
        (*DAT_1006c1c4)(s__s_in_solid_at__s_100497dc,*(undefined4 *)(param_1 + 0x118),puVar2,iVar1);
      }
    }
  }
  if (*(float *)(param_1 + 0x1e4) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x1e4) = 0x41a00000;
  }
  *(undefined4 *)(param_1 + 0x23c) = 0x19;
  FUN_10012750(param_1);
  if ((*(byte *)(param_1 + 0x11c) & 2) != 0) {
    FUN_10012530(param_1);
  }
  return;
}



/* FUN_1003a678 @ 1003a678 size 167 */

char * __cdecl FUN_1003a678(char *param_1,size_t param_2,int *param_3,char param_4)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar1 = param_3[1];
  if ((param_4 != '\0') && (iVar1 - 1U == param_2)) {
    iVar2 = *param_3;
    param_1[(uint)(iVar2 == 0x2d) + (iVar1 - 1U)] = '0';
    (param_1 + (uint)(iVar2 == 0x2d) + (iVar1 - 1U))[1] = '\0';
  }
  pcVar3 = param_1;
  if (*param_3 == 0x2d) {
    *param_1 = '-';
    pcVar3 = param_1 + 1;
  }
  if (param_3[1] < 1) {
    FUN_1003a803(pcVar3,1);
    *pcVar3 = '0';
    pcVar3 = pcVar3 + 1;
  }
  else {
    pcVar3 = pcVar3 + param_3[1];
  }
  if (0 < (int)param_2) {
    FUN_1003a803(pcVar3,1);
    *pcVar3 = DAT_1005fed8;
    iVar1 = param_3[1];
    if (iVar1 < 0) {
      if ((param_4 != '\0') || (-iVar1 <= (int)param_2)) {
        param_2 = -iVar1;
      }
      FUN_1003a803(pcVar3 + 1,param_2);
      _memset(pcVar3 + 1,0x30,param_2);
    }
  }
  return param_1;
}



/* FUN_10006a70 @ 10006a70 size 165 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10006a70(int param_1)

{
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  
  if (*(float *)(param_1 + 0x34c) <= *(float *)(param_1 + 800) * (float)_DAT_10044168) {
    FUN_10006a00(param_1);
    return;
  }
  FUN_10038a20((float *)(param_1 + 0x334),*(float *)(param_1 + 800),(float *)(param_1 + 0x178));
  fVar3 = FUN_1003900b((double)((*(float *)(param_1 + 0x34c) / *(float *)(param_1 + 800)) *
                               (float)_DAT_10044170));
  *(float *)(param_1 + 0x34c) =
       (float)((float10)*(float *)(param_1 + 0x34c) -
              fVar3 * (float10)*(float *)(param_1 + 800) * (float10)_DAT_10044168);
  fVar2 = (float10)_DAT_10044168;
  fVar1 = (float10)DAT_1006c2e4;
  *(code **)(param_1 + 500) = FUN_10006a00;
  *(float *)(param_1 + 0x1ec) = (float)(fVar3 * fVar2 + fVar1);
  return;
}



/* FUN_10020380 @ 10020380 size 164 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10020380(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  float fVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 1;
  }
  if ((0x14 < param_4) && (*(float *)(param_1 + 0x210) <= DAT_1006c2e4)) {
    if ((param_4 < 0x33) &&
       (uVar2 = _rand(), (float)_DAT_10044198 < (float)(uVar2 & 0x7fff) * _DAT_10044108)) {
      return;
    }
    fVar1 = DAT_1006c2e4 + _DAT_100441b4;
    *(undefined **)(param_1 + 0x358) = &DAT_1004cba0;
    *(float *)(param_1 + 0x210) = fVar1;
    (*DAT_1006c1d0)(param_1,2,DAT_10060fe8,0x3f800000,0x3f800000,0);
  }
  return;
}



/* FUN_1003972f @ 1003972f size 164 */

uint __cdecl FUN_1003972f(byte *param_1,byte *param_2)

{
  byte bVar1;
  DWORD *pDVar2;
  int iVar3;
  byte *pbVar4;
  byte local_24 [32];
  
  pDVar2 = FUN_1003a8ad();
  pbVar4 = local_24;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    pbVar4[0] = 0;
    pbVar4[1] = 0;
    pbVar4[2] = 0;
    pbVar4[3] = 0;
    pbVar4 = pbVar4 + 4;
  }
  do {
    bVar1 = *param_2;
    local_24[bVar1 >> 3] = local_24[bVar1 >> 3] | '\x01' << (bVar1 & 7);
    param_2 = param_2 + 1;
  } while (bVar1 != 0);
  if (param_1 == (byte *)0x0) {
    param_1 = (byte *)pDVar2[6];
  }
  for (; (bVar1 = *param_1, pbVar4 = param_1, (local_24[bVar1 >> 3] & (byte)(1 << (bVar1 & 7))) != 0
         && (bVar1 != 0)); param_1 = param_1 + 1) {
  }
  do {
    bVar1 = *pbVar4;
    if (bVar1 == 0) {
LAB_100397be:
      pDVar2[6] = (DWORD)pbVar4;
      return -(uint)(param_1 != pbVar4) & (uint)param_1;
    }
    if ((local_24[bVar1 >> 3] & (byte)(1 << (bVar1 & 7))) != 0) {
      *pbVar4 = 0;
      pbVar4 = pbVar4 + 1;
      goto LAB_100397be;
    }
    pbVar4 = pbVar4 + 1;
  } while( true );
}



/* FUN_1003dfc7 @ 1003dfc7 size 164 */

int __cdecl FUN_1003dfc7(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar5 = 0;
  FUN_1003c8a1(2);
  iVar4 = 0;
  if (0 < DAT_1006dde0) {
    do {
      iVar2 = *(int *)(DAT_1006cddc + iVar4 * 4);
      if ((iVar2 != 0) && ((*(byte *)(iVar2 + 0xc) & 0x83) != 0)) {
        FUN_1003dccf(iVar4,iVar2);
        piVar1 = *(int **)(DAT_1006cddc + iVar4 * 4);
        if ((piVar1[3] & 0x83U) != 0) {
          if (param_1 == 1) {
            iVar2 = FUN_1003df34(piVar1);
            if (iVar2 != -1) {
              iVar3 = iVar3 + 1;
            }
          }
          else if ((param_1 == 0) && ((piVar1[3] & 2U) != 0)) {
            iVar2 = FUN_1003df34(piVar1);
            if (iVar2 == -1) {
              iVar5 = -1;
            }
          }
        }
        FUN_1003dd21(iVar4,*(int *)(DAT_1006cddc + iVar4 * 4));
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_1006dde0);
  }
  FUN_1003c902(2);
  if (param_1 != 1) {
    iVar3 = iVar5;
  }
  return iVar3;
}



/* FUN_10017520 @ 10017520 size 163 */

undefined4 __cdecl FUN_10017520(byte *param_1,undefined4 *param_2)

{
  byte bVar1;
  char cVar2;
  void *this;
  int iVar3;
  undefined4 local_88;
  undefined4 local_84;
  byte local_80 [128];
  
  local_84 = 0;
  local_88 = 0;
  iVar3 = 0;
  do {
    bVar1 = *param_1;
    if (((char)bVar1 < '0') || ('9' < (char)bVar1)) {
      (*DAT_1006c1c8)(0,2,s_Bad_filter_address___s_1004b7c8,param_1);
      return 0;
    }
    this = (void *)0x0;
    do {
      if ('9' < (char)bVar1) break;
      local_80[(int)this] = bVar1;
      bVar1 = param_1[1];
      this = (void *)((int)this + 1);
      param_1 = param_1 + 1;
    } while ('/' < (char)bVar1);
    local_80[(int)this] = 0;
    cVar2 = FUN_10039237(this,local_80);
    *(char *)((int)&local_88 + iVar3) = cVar2;
    if (cVar2 != '\0') {
      local_80[iVar3 + -4] = 0xff;
    }
    if (*param_1 == 0) break;
    param_1 = param_1 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  *param_2 = local_84;
  param_2[1] = local_88;
  return 1;
}



/* FUN_10019e90 @ 10019e90 size 163 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10019e90(float *param_1)

{
  float fVar1;
  
  if (_DAT_100442b0 < *param_1) {
    do {
      fVar1 = *param_1 - _DAT_100442b0;
      *param_1 = fVar1;
    } while (_DAT_100442b0 < fVar1);
  }
  if (*param_1 < _DAT_1004410c) {
    do {
      fVar1 = *param_1 + _DAT_100442b0;
      *param_1 = fVar1;
    } while (fVar1 < _DAT_1004410c);
  }
  if (_DAT_100442b0 < param_1[1]) {
    do {
      fVar1 = param_1[1] - _DAT_100442b0;
      param_1[1] = fVar1;
    } while (_DAT_100442b0 < fVar1);
  }
  if (param_1[1] < _DAT_1004410c) {
    do {
      fVar1 = param_1[1] + _DAT_100442b0;
      param_1[1] = fVar1;
    } while (fVar1 < _DAT_1004410c);
  }
  return;
}



/* FUN_1003f07a @ 1003f07a size 163 */

void __cdecl FUN_1003f07a(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  FUN_1003f11f();
  if (DAT_10061e1c == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  DAT_10061e18 = 1;
  DAT_10061e14 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_1006cdd0 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_1006cdcc - 4), DAT_1006cdd0 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_1006cdd0 <= puVar1);
    }
    FUN_1003f131((undefined4 *)&DAT_10046018,(undefined4 *)&DAT_10046020);
  }
  FUN_1003f131((undefined4 *)&DAT_10046024,(undefined4 *)&DAT_10046028);
  if (param_3 == 0) {
    DAT_10061e1c = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(param_1);
  }
  FUN_1003f128();
  return;
}



/* FUN_100049b0 @ 100049b0 size 162 */

void __cdecl FUN_100049b0(int param_1)

{
  byte *pbVar1;
  undefined4 *puVar2;
  
  pbVar1 = (byte *)(*DAT_1006c264)();
  puVar2 = FUN_1000b150(pbVar1);
  if (puVar2 == (undefined4 *)0x0) {
    (*DAT_1006c1c8)(param_1,2,s_unknown_item___s_100462dc,pbVar1);
    return;
  }
  if ((code *)puVar2[3] == (code *)0x0) {
    (*DAT_1006c1c8)(param_1,2,s_Item_is_not_dropable__10046394);
    return;
  }
  if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) == 0) {
    (*DAT_1006c1c8)(param_1,2,s_Out_of_item___s_100462b0,pbVar1);
    return;
  }
  (*(code *)puVar2[3])(param_1,puVar2);
  return;
}



/* FUN_10012e50 @ 10012e50 size 162 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte __cdecl FUN_10012e50(float *param_1,float *param_2,float *param_3,float param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  byte bVar10;
  int iVar11;
  
  bVar10 = _DAT_1004410c < param_2[2];
  if (param_2[2] == _DAT_1004410c) {
    bVar10 = bVar10 | 2;
  }
  iVar11 = 3;
  fVar2 = param_1[1];
  fVar3 = param_2[1];
  fVar4 = param_1[2];
  fVar5 = param_2[2];
  fVar6 = *param_1;
  fVar7 = *param_2;
  iVar9 = (int)param_2 - (int)param_3;
  do {
    pfVar1 = (float *)(iVar9 + (int)param_3);
    fVar8 = *(float *)((int)pfVar1 + ((int)param_1 - (int)param_2)) -
            (fVar6 * fVar7 + fVar4 * fVar5 + fVar2 * fVar3) * param_4 * *pfVar1;
    *param_3 = fVar8;
    if (((float)_DAT_10044258 < fVar8) && (fVar8 < (float)_DAT_10044168)) {
      *param_3 = 0.0;
    }
    param_3 = param_3 + 1;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  return bVar10;
}



/* FUN_100036b0 @ 100036b0 size 161 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100036b0(int param_1)

{
  if (*(int *)(param_1 + 0x1e0) != 0) {
    if (*(int *)(param_1 + 0x294) == -0x40800000) {
      *(undefined4 *)(param_1 + 0x294) = 0;
      *(undefined4 *)(param_1 + 0x180) = 0;
      *(undefined4 *)(param_1 + 0x17c) = 0;
      *(undefined4 *)(param_1 + 0x178) = 0;
      *(undefined4 *)(param_1 + 0x18c) = 0;
      *(undefined4 *)(param_1 + 0x188) = 0;
      *(undefined4 *)(param_1 + 0x184) = 0;
      *(undefined4 *)(param_1 + 0x1ec) = 0;
      return;
    }
    if (*(float *)(param_1 + 0x32c) != _DAT_1004410c) {
      do {
        if (DAT_1006c2e4 < *(float *)(param_1 + 0x32c)) break;
        FUN_10002f70(param_1);
      } while (*(float *)(param_1 + 0x32c) != _DAT_1004410c);
    }
  }
  *(undefined4 *)(param_1 + 0x1ec) = *(undefined4 *)(param_1 + 0x32c);
  return;
}



/* FUN_10008170 @ 10008170 size 161 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10008170(int param_1)

{
  int iVar1;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = *(float *)(param_1 + 0x304) - *(float *)(param_1 + 0x10);
  local_8 = *(float *)(param_1 + 0x308) - *(float *)(param_1 + 0x14);
  local_4 = *(float *)(param_1 + 0x30c) - *(float *)(param_1 + 0x18);
  iVar1 = FUN_100388c0(&local_c,(float *)&DAT_10061c18);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x18c) = 0;
    *(undefined4 *)(param_1 + 0x188) = 0;
    *(undefined4 *)(param_1 + 0x184) = 0;
    FUN_10007f60(param_1);
    return;
  }
  FUN_10038a20(&local_c,10.0,(float *)(param_1 + 0x184));
  *(code **)(param_1 + 500) = FUN_10007f60;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  return;
}



/* FUN_10015090 @ 10015090 size 161 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10015090(int param_1,undefined4 *param_2)

{
  if (((*(byte *)(param_2 + 0x2e) & 4) == 0) && (param_2[0x15] == 0)) {
    FUN_100060d0((uint)param_2,param_1,param_1,(float *)&DAT_10061c18,(float *)(param_2 + 1),
                 &DAT_10061c18,100000,1,0,0x14);
    if (param_2 != (undefined4 *)0x0) {
      FUN_1000e3e0(param_2);
      return;
    }
  }
  else if ((*(float *)(param_1 + 0x20c) <= DAT_1006c2e4) && (*(int *)(param_1 + 0x244) != 0)) {
    *(float *)(param_1 + 0x20c) = DAT_1006c2e4 + (float)_DAT_10044140;
    FUN_100060d0((uint)param_2,param_1,param_1,(float *)&DAT_10061c18,(float *)(param_2 + 1),
                 &DAT_10061c18,*(int *)(param_1 + 0x244),1,0,0x14);
  }
  return;
}



/* FUN_100294e0 @ 100294e0 size 161 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl FUN_100294e0(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  for (uVar1 = FUN_1001aca0(0,param_1 + 4,1024.0); uVar1 != 0;
      uVar1 = FUN_1001aca0(uVar1,param_1 + 4,1024.0)) {
    if ((((((uVar1 != param_1) && ((*(byte *)(uVar1 + 0xb8) & 4) != 0)) &&
          ((*(uint *)(uVar1 + 0x35c) & 0x100) == 0)) &&
         ((*(int *)(uVar1 + 0x100) == 0 && (*(int *)(uVar1 + 0x220) < 1)))) &&
        ((*(float *)(uVar1 + 0x1ec) == _DAT_1004410c &&
         (iVar2 = FUN_10001560(param_1,uVar1), iVar2 != 0)))) &&
       ((uVar3 == 0 || (*(int *)(uVar3 + 0x224) < *(int *)(uVar1 + 0x224))))) {
      uVar3 = uVar1;
    }
  }
  return uVar3;
}



/* FUN_10007280 @ 10007280 size 160 */

void __cdecl FUN_10007280(int param_1,undefined4 *param_2)

{
  if (((*(byte *)(param_2 + 0x2e) & 4) == 0) && (param_2[0x15] == 0)) {
    FUN_100060d0((uint)param_2,param_1,param_1,(float *)&DAT_10061c18,(float *)(param_2 + 1),
                 &DAT_10061c18,100000,1,0,0x14);
    if (param_2 != (undefined4 *)0x0) {
      FUN_1000e3e0(param_2);
      return;
    }
  }
  else {
    FUN_100060d0((uint)param_2,param_1,param_1,(float *)&DAT_10061c18,(float *)(param_2 + 1),
                 &DAT_10061c18,*(int *)(param_1 + 0x244),1,0,0x14);
    if (*(int *)(param_1 + 0x330) == 2) {
      FUN_100071c0(param_1);
      return;
    }
    if (*(int *)(param_1 + 0x330) == 3) {
      FUN_10007220(param_1);
    }
  }
  return;
}



/* FUN_1003a914 @ 1003a914 size 160 */

void __cdecl FUN_1003a914(LPVOID param_1)

{
  if (DAT_1005fbac != 0xffffffff) {
    if ((param_1 != (LPVOID)0x0) || (param_1 = TlsGetValue(DAT_1005fbac), param_1 != (LPVOID)0x0)) {
      if (*(LPVOID *)((int)param_1 + 0x24) != (LPVOID)0x0) {
        FUN_100396e7(*(LPVOID *)((int)param_1 + 0x24));
      }
      if (*(LPVOID *)((int)param_1 + 0x28) != (LPVOID)0x0) {
        FUN_100396e7(*(LPVOID *)((int)param_1 + 0x28));
      }
      if (*(LPVOID *)((int)param_1 + 0x30) != (LPVOID)0x0) {
        FUN_100396e7(*(LPVOID *)((int)param_1 + 0x30));
      }
      if (*(LPVOID *)((int)param_1 + 0x38) != (LPVOID)0x0) {
        FUN_100396e7(*(LPVOID *)((int)param_1 + 0x38));
      }
      if (*(LPVOID *)((int)param_1 + 0x40) != (LPVOID)0x0) {
        FUN_100396e7(*(LPVOID *)((int)param_1 + 0x40));
      }
      if (*(LPVOID *)((int)param_1 + 0x44) != (LPVOID)0x0) {
        FUN_100396e7(*(LPVOID *)((int)param_1 + 0x44));
      }
      if (*(undefined **)((int)param_1 + 0x50) != &DAT_10060530) {
        FUN_100396e7(*(undefined **)((int)param_1 + 0x50));
      }
      FUN_100396e7(param_1);
    }
    TlsSetValue(DAT_1005fbac,(LPVOID)0x0);
    return;
  }
  return;
}



/* FUN_1003a07d @ 1003a07d size 158 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl FUN_1003a07d(int param_1,undefined4 param_2)

{
  uint in_EAX;
  uint uVar1;
  uint extraout_EAX;
  bool in_ZF;
  ushort in_FPUControlWord;
  ushort in_FPUStatusWord;
  unkbyte10 in_ST0;
  float10 fVar2;
  undefined4 unaff_retaddr;
  
  if (in_ZF) {
    if (((in_EAX & 0xfffff) == 0) && (param_1 == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = FUN_1003ed3c();
    }
    if (DAT_10061c24 == 0) {
      __startOneArgErrorHandling(&DAT_1005fb80,0x12,in_FPUControlWord,unaff_retaddr,param_1,param_2)
      ;
      return extraout_EAX;
    }
  }
  else {
    fVar2 = (float10)fcos(in_ST0);
    uVar1 = CONCAT22((short)(in_EAX >> 0x10),in_FPUStatusWord);
    if ((in_FPUStatusWord & 0x400) != 0) {
      do {
        fVar2 = fVar2 - (fVar2 / _DAT_1004465a) * _DAT_1004465a;
        uVar1 = CONCAT22((short)(uVar1 >> 0x10),in_FPUStatusWord);
      } while ((in_FPUStatusWord & 0x400) != 0);
      fcos(fVar2);
    }
    if (DAT_10061c24 == 0) {
      uVar1 = __math_exit(&DAT_1005fb80,0x12,unaff_retaddr,param_1,param_2);
      return uVar1;
    }
  }
  return uVar1;
}



/* FUN_10002d40 @ 10002d40 size 157 */

void __cdecl FUN_10002d40(int param_1)

{
  int *piVar1;
  
  piVar1 = FUN_1001b350();
  *(int **)(*(int *)(param_1 + 0x54) + 0xf14) = piVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xf0c) = 1;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  (*DAT_1006c208)(param_1);
  piVar1[0x97] = param_1;
  piVar1[0x46] = (int)s_dummy_body_1004604c;
  piVar1[0x2f] = *(int *)(param_1 + 0xbc);
  piVar1[0x30] = *(int *)(param_1 + 0xc0);
  piVar1[0x31] = *(int *)(param_1 + 0xc4);
  piVar1[0x32] = *(int *)(param_1 + 200);
  piVar1[0x33] = *(int *)(param_1 + 0xcc);
  piVar1[0x34] = *(int *)(param_1 + 0xd0);
  FUN_10002ca0(param_1);
  return;
}



/* FUN_1000ad70 @ 1000ad70 size 157 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000ad70(int param_1,undefined4 *param_2)

{
  if (((*(byte *)(param_2 + 0x2e) & 4) == 0) && (param_2[0x15] == 0)) {
    FUN_100060d0((uint)param_2,param_1,param_1,(float *)&DAT_10061c18,(float *)(param_2 + 1),
                 &DAT_10061c18,100000,1,0,0x14);
    if (param_2 != (undefined4 *)0x0) {
      FUN_1000e3e0(param_2);
      return;
    }
  }
  else if (*(float *)(param_1 + 0x20c) <= DAT_1006c2e4) {
    *(float *)(param_1 + 0x20c) = DAT_1006c2e4 + (float)_DAT_10044140;
    FUN_100060d0((uint)param_2,param_1,param_1,(float *)&DAT_10061c18,(float *)(param_2 + 1),
                 &DAT_10061c18,*(int *)(param_1 + 0x244),1,0,0x14);
  }
  return;
}



/* FUN_10031570 @ 10031570 size 157 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10031570(int *param_1)

{
  FUN_1001b310(param_1);
  FUN_10030560(param_1[0x15]);
  FUN_10031070((int)param_1);
  if (_DAT_1006c3a8 == _DAT_1004410c) {
    (*DAT_1006c224)(1);
    (*DAT_1006c228)(((int)param_1 - DAT_1006c2c4) / 0x3d0);
    (*DAT_1006c224)(9);
    (*DAT_1006c218)(param_1 + 1,2);
  }
  else {
    FUN_100323b0((int)param_1);
  }
  (*DAT_1006c1c0)(2,s__s_entered_the_game_1005f3e4,param_1[0x15] + 700);
  FUN_10034d80((float)param_1);
  return;
}



/* entry @ 1003a2b9 size 157 */

int entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2;
  iVar2 = DAT_10061c48;
  if (param_2 != 0) {
    if ((param_2 != 1) && (param_2 != 2)) goto LAB_1003a301;
    if ((DAT_1006de04 != (code *)0x0) &&
       (iVar2 = (*DAT_1006de04)(param_1,param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    iVar2 = FUN_1003a1e0(param_1,param_2);
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_1003a301:
  iVar2 = FUN_1003f793();
  if (param_2 == 1) {
    if (iVar2 != 0) {
      return iVar2;
    }
    FUN_1003a1e0(param_1,0);
  }
  if ((param_2 != 0) && (param_2 != 3)) {
    return iVar2;
  }
  iVar3 = FUN_1003a1e0(param_1,param_2);
  param_2 = iVar2;
  if (iVar3 == 0) {
    param_2 = 0;
  }
  if (param_2 != 0) {
    if (DAT_1006de04 != (code *)0x0) {
      iVar2 = (*DAT_1006de04)(param_1,iVar1,param_3);
      return iVar2;
    }
    return param_2;
  }
  return 0;
}



/* FUN_10002ca0 @ 10002ca0 size 156 */

void __cdecl FUN_10002ca0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0xf14);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x38) = *(undefined4 *)(param_1 + 0x38);
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(iVar1 + 0x178) = *(undefined4 *)(param_1 + 0x178);
    *(undefined4 *)(iVar1 + 0x17c) = *(undefined4 *)(param_1 + 0x17c);
    *(undefined4 *)(iVar1 + 0x180) = *(undefined4 *)(param_1 + 0x180);
    *(undefined4 *)(iVar1 + 0x184) = *(undefined4 *)(param_1 + 0x184);
    *(undefined4 *)(iVar1 + 0x188) = *(undefined4 *)(param_1 + 0x188);
    *(undefined4 *)(iVar1 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);
    (*DAT_1006c208)(iVar1);
  }
  return;
}



/* FUN_10001690 @ 10001690 size 155 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10001690(int param_1)

{
  int iVar1;
  uint uVar2;
  float10 fVar3;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  *(undefined4 *)(param_1 + 0x1dc) = *(undefined4 *)(param_1 + 0x25c);
  if ((*(byte *)(param_1 + 0x35c) & 1) == 0) {
    (**(code **)(param_1 + 0x378))(param_1);
  }
  else {
    (**(code **)(param_1 + 0x368))();
  }
  iVar1 = *(int *)(param_1 + 0x25c);
  fStack_c = *(float *)(iVar1 + 4) - *(float *)(param_1 + 4);
  fStack_8 = *(float *)(iVar1 + 8) - *(float *)(param_1 + 8);
  fStack_4 = *(float *)(iVar1 + 0xc) - *(float *)(param_1 + 0xc);
  fVar3 = FUN_1001b160(&fStack_c);
  *(float *)(param_1 + 0x1e8) = (float)fVar3;
  if ((*(byte *)(param_1 + 0x35c) & 1) == 0) {
    uVar2 = _rand();
    FUN_10011c70(param_1,(float)(uVar2 & 0x7fff) * _DAT_10044108);
  }
  return;
}



/* FUN_1000a4c0 @ 1000a4c0 size 154 */

void __cdecl FUN_1000a4c0(int param_1)

{
  int iVar1;
  float local_c;
  float local_8;
  float local_4;
  
  iVar1 = *(int *)(param_1 + 0x144);
  local_c = *(float *)(iVar1 + 4) - *(float *)(param_1 + 0xbc);
  local_8 = *(float *)(iVar1 + 8) - *(float *)(param_1 + 0xc0);
  local_4 = *(float *)(iVar1 + 0xc) - *(float *)(param_1 + 0xc4);
  *(undefined4 *)(param_1 + 0x2e8) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0x2e0) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x2e4) = *(undefined4 *)(param_1 + 8);
  *(float *)(param_1 + 0x2f8) = local_c;
  *(undefined4 *)(param_1 + 0x330) = 0;
  *(float *)(param_1 + 0x2fc) = local_8;
  *(float *)(param_1 + 0x300) = local_4;
  FUN_10006b20(param_1,&local_c,&LAB_1000a1f0);
  *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) | 1;
  return;
}



/* FUN_100031e0 @ 100031e0 size 153 */

void __cdecl FUN_100031e0(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = DAT_1006c168;
  uVar2 = DAT_1006c2c4;
  uVar3 = DAT_1006c2c4;
  if (DAT_1006c2c4 < DAT_1006c168 * 0x3d0 + DAT_1006c2c4) {
    do {
      if ((*(int *)(uVar3 + 0x58) != 0) && (*(int *)(uVar3 + 0x54) != 0)) {
        FUN_10002f20(uVar3,param_1);
        iVar1 = DAT_1006c168;
        uVar2 = DAT_1006c2c4;
      }
      uVar3 = uVar3 + 0x3d0;
    } while (uVar3 < iVar1 * 0x3d0 + uVar2);
  }
  *(undefined4 *)(param_1 + 0x180) = 0;
  *(undefined4 *)(param_1 + 0x17c) = 0;
  *(undefined4 *)(param_1 + 0x178) = 0;
  *(undefined4 *)(param_1 + 0x18c) = 0;
  *(undefined4 *)(param_1 + 0x188) = 0;
  *(undefined4 *)(param_1 + 0x184) = 0;
  *(undefined4 *)(param_1 + 0x294) = 0;
  *(undefined4 *)(param_1 + 0x254) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  return;
}



/* FUN_1003f414 @ 1003f414 size 153 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1003f414(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_c;
  int local_8;
  
  if (DAT_1006cdc8 == 0) {
    FUN_10042046();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_10061e20,0x104);
  _DAT_10061e0c = &DAT_10061e20;
  pbVar2 = &DAT_10061e20;
  if (*DAT_1006de00 != 0) {
    pbVar2 = DAT_1006de00;
  }
  FUN_1003f4ad(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_c);
  puVar1 = _malloc(local_c + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_1003f4ad(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_c);
  _DAT_10061df4 = puVar1;
  _DAT_10061df0 = local_8 + -1;
  return;
}



/* FUN_1003aa08 @ 1003aa08 size 152 */

float10 __cdecl
FUN_1003aa08(uint param_1,uint param_2,undefined8 param_3,double param_4,uint param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  float10 fVar3;
  uint local_5c [14];
  uint local_24;
  
  bVar1 = FUN_1003ad53(param_1,&param_4,param_5);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    local_24 = local_24 & 0xfffffffe;
    FUN_1003aaa0(local_5c,&param_5,param_1,param_2,&param_3,&param_4);
  }
  iVar2 = FUN_1003b03f((byte)param_1);
  if ((DAT_10060720 == 0) && (iVar2 != 0)) {
    fVar3 = FUN_1003af6a(iVar2,param_2);
    return fVar3;
  }
  FUN_1003aff2(iVar2);
  FUN_1003b1df();
  return (float10)param_4;
}



/* FUN_10001560 @ 10001560 size 151 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10001560(int param_1,int param_2)

{
  float *pfVar1;
  int iVar2;
  float *pfVar3;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  float local_38 [14];
  
  local_44 = *(undefined4 *)(param_1 + 4);
  local_40 = *(undefined4 *)(param_1 + 8);
  local_3c = (float)*(int *)(param_1 + 0x23c) + *(float *)(param_1 + 0xc);
  local_50 = *(undefined4 *)(param_2 + 4);
  local_4c = *(undefined4 *)(param_2 + 8);
  local_48 = (float)*(int *)(param_2 + 0x23c) + *(float *)(param_2 + 0xc);
  pfVar1 = (float *)(*DAT_1006c1f0)(local_38,&local_44,&DAT_10061c18,&DAT_10061c18,&local_50,param_1
                                    ,0x19);
  pfVar3 = local_38;
  for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar3 = *pfVar1;
    pfVar1 = pfVar1 + 1;
    pfVar3 = pfVar3 + 1;
  }
  if (local_38[2] == (float)_DAT_10044120) {
    return 1;
  }
  return 0;
}



/* FUN_10018ea0 @ 10018ea0 size 151 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10018ea0(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 300) == 0) {
    iVar3 = param_1 + 4;
    puVar1 = FUN_1001b070();
    (*DAT_1006c1c4)(s_untargeted__s_at__s_1004bacc,*(undefined4 *)(param_1 + 0x118),puVar1,iVar3);
  }
  if (*(int *)(param_1 + 0x254) == 0) {
    *(undefined4 *)(param_1 + 0x254) = 5;
  }
  if (*(float *)(param_1 + 0x148) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x148) = 0x43480000;
  }
  *(code **)(param_1 + 500) = FUN_10018d10;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  *(undefined1 **)(param_1 + 0x200) = &LAB_10018e60;
  uVar2 = (*DAT_1006c1e4)(s_world_quake_wav_1004babc);
  *(undefined4 *)(param_1 + 0x280) = uVar2;
  return;
}



/* FUN_1001dc60 @ 1001dc60 size 151 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1001dc60(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x104) = 6;
  *(undefined4 *)(param_1 + 0x184) = 0;
  *(undefined4 *)(param_1 + 0x188) = 0;
  *(undefined4 *)(param_1 + 0x18c) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(float *)(param_1 + 0x334) = 0.0;
  *(undefined4 *)(param_1 + 0x338) = 0;
  *(undefined4 *)(param_1 + 0x33c) = 0x3f800000;
  *(undefined4 *)(param_1 + 800) = 0x41f00000;
  FUN_10038a20((float *)(param_1 + 0x334),30.0,(float *)(param_1 + 0x178));
  fVar1 = DAT_1006c2e4 + _DAT_10044104;
  *(undefined4 *)(param_1 + 0x254) = 0;
  *(code **)(param_1 + 500) = FUN_1001dd00;
  *(float *)(param_1 + 0x1ec) = fVar1;
  uVar2 = (*DAT_1006c1e4)(s_weapons_hgrenc1b_wav_1004bf2c);
  *(undefined4 *)(param_1 + 0x4c) = uVar2;
  return;
}



/* FUN_10043308 @ 10043308 size 151 */

byte * __cdecl FUN_10043308(byte *param_1,uint param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  
  if (DAT_1006ca8c == 0) {
    pbVar2 = (byte *)_strchr((char *)param_1,param_2);
  }
  else {
    FUN_1003c8a1(0x19);
    while( true ) {
      bVar1 = *param_1;
      uVar3 = (uint)bVar1;
      if (bVar1 == 0) break;
      if ((*(byte *)((int)&DAT_1006cba0 + uVar3 + 1) & 4) == 0) {
        pbVar2 = param_1;
        if (param_2 == uVar3) break;
      }
      else {
        pbVar2 = param_1 + 1;
        if (param_1[1] == 0) {
          FUN_1003c902(0x19);
          return (byte *)0x0;
        }
        if (param_2 == CONCAT11(bVar1,param_1[1])) {
          FUN_1003c902(0x19);
          return param_1;
        }
      }
      param_1 = pbVar2 + 1;
    }
    FUN_1003c902(0x19);
    pbVar2 = (byte *)(~-(uint)(param_2 != uVar3) & (uint)param_1);
  }
  return pbVar2;
}



/* FUN_10011640 @ 10011640 size 150 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10011640(uint param_1)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = DAT_1006c168;
  uVar3 = DAT_1006c2c4;
  uVar4 = DAT_1006c2c4;
  if (DAT_1006c2c4 < DAT_1006c168 * 0x3d0 + DAT_1006c2c4) {
    do {
      if ((*(int *)(uVar4 + 0x58) != 0) && (*(int *)(uVar4 + 0x54) != 0)) {
        FUN_1002f4c0(uVar4,s_gl_polyblend_1_10049688);
        iVar2 = DAT_1006c168;
        uVar3 = DAT_1006c2c4;
      }
      uVar4 = uVar4 + 0x3d0;
    } while (uVar4 < iVar2 * 0x3d0 + uVar3);
  }
  fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
  *(code **)(param_1 + 500) = FUN_10011570;
  *(float *)(param_1 + 0x1ec) = fVar1;
  *(float *)(param_1 + 0x120) = DAT_1006c2e4;
  FUN_10011570(param_1);
  return;
}



/* FUN_1001ac00 @ 1001ac00 size 150 */

uint __cdecl FUN_1001ac00(int param_1,int param_2,byte *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  uVar4 = DAT_1006c2c4;
  if (param_1 != 0) {
    uVar4 = param_1 + 0x3d0;
  }
  if (uVar4 < DAT_1006c168 * 0x3d0 + DAT_1006c2c4) {
    puVar5 = (undefined4 *)(uVar4 + param_2);
    iVar2 = DAT_1006c168;
    uVar3 = DAT_1006c2c4;
    do {
      if (((*(int *)((0x58 - param_2) + (int)puVar5) != 0) && ((void *)*puVar5 != (void *)0x0)) &&
         (iVar1 = FUN_10038b20((void *)*puVar5,param_3), iVar2 = DAT_1006c168, uVar3 = DAT_1006c2c4,
         iVar1 == 0)) {
        return uVar4;
      }
      uVar4 = uVar4 + 0x3d0;
      puVar5 = puVar5 + 0xf4;
    } while (uVar4 < iVar2 * 0x3d0 + uVar3);
  }
  return 0;
}



/* FUN_1000e460 @ 1000e460 size 147 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000e460(undefined4 *param_1)

{
  float fVar1;
  int *piVar2;
  
  (*DAT_1006c224)(1);
  (*DAT_1006c228)(((int)param_1 - DAT_1006c2c4) / 0x3d0);
  (*DAT_1006c224)(0x8a);
  (*DAT_1006c218)(param_1 + 1,2);
  piVar2 = FUN_1001b350();
  piVar2[0x14] = 6;
  fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
  piVar2[0x7d] = (int)FUN_1001b400;
  piVar2[0x7b] = (int)fVar1;
  piVar2[1] = param_1[1];
  piVar2[2] = param_1[2];
  piVar2[3] = param_1[3];
  (*DAT_1006c208)(piVar2);
  FUN_1001b400(param_1);
  return;
}



/* FUN_1003a71f @ 1003a71f size 147 */

void __cdecl FUN_1003a71f(undefined8 *param_1,char *param_2,size_t param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  uint local_2c [6];
  int local_14;
  int local_10;
  
  FUN_1003feee((int)*param_1,(int)((ulonglong)*param_1 >> 0x20),&local_14,local_2c);
  iVar1 = local_10 + -1;
  FUN_1003fe77(param_2 + (local_14 == 0x2d),param_3,(int)&local_14);
  local_10 = local_10 + -1;
  if ((local_10 < -4) || ((int)param_3 <= local_10)) {
    FUN_1003a561(param_2,param_3,param_4,&local_14,'\x01');
  }
  else {
    pcVar2 = param_2 + (local_14 == 0x2d);
    if (iVar1 < local_10) {
      do {
        pcVar3 = pcVar2;
        pcVar2 = pcVar3 + 1;
      } while (*pcVar3 != '\0');
      pcVar3[-1] = '\0';
    }
    FUN_1003a678(param_2,param_3,&local_14,'\x01');
  }
  return;
}



/* FUN_100410c3 @ 100410c3 size 147 */

undefined4 __cdecl FUN_100410c3(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (DAT_1006cdc0 <= param_1) {
LAB_10041144:
    pDVar3 = FUN_1004058e();
    *pDVar3 = 9;
    return 0xffffffff;
  }
  iVar4 = (param_1 & 0x1f) * 0x24;
  if ((*(byte *)((&DAT_1006ccc0)[(int)param_1 >> 5] + 4 + iVar4) & 1) == 0) goto LAB_10041144;
  FUN_10041042(param_1);
  if ((*(byte *)((&DAT_1006ccc0)[(int)param_1 >> 5] + 4 + iVar4) & 1) != 0) {
    hFile = (HANDLE)FUN_10041000(param_1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
    }
    uVar5 = 0;
    if (DVar2 == 0) goto LAB_10041139;
    pDVar3 = FUN_10040597();
    *pDVar3 = DVar2;
  }
  pDVar3 = FUN_1004058e();
  *pDVar3 = 9;
  uVar5 = 0xffffffff;
LAB_10041139:
  FUN_100410a1(param_1);
  return uVar5;
}



/* FUN_10004bc0 @ 10004bc0 size 146 */

void __cdecl FUN_10004bc0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0x54);
  if (*(int *)(iVar1 + 0x714) != 0) {
    iVar3 = 1;
    uVar4 = (*(int *)(iVar1 + 0x714) + -0x10046928) / 0x48 + 0xff;
    do {
      uVar2 = uVar4 & 0x800000ff;
      if ((int)uVar2 < 0) {
        uVar2 = (uVar2 - 1 | 0xffffff00) + 1;
      }
      if (*(int *)(iVar1 + 0x2e4 + uVar2 * 4) != 0) {
        if (((*(code **)(&DAT_10046930 + uVar2 * 0x48) != (code *)0x0) &&
            (((&DAT_10046960)[uVar2 * 0x48] & 1) != 0)) &&
           ((**(code **)(&DAT_10046930 + uVar2 * 0x48))(param_1,&DAT_10046928 + uVar2 * 0x12),
           *(undefined4 **)(iVar1 + 0x714) == &DAT_10046928 + uVar2 * 0x12)) {
          return;
        }
      }
      iVar3 = iVar3 + 1;
      uVar4 = uVar4 - 1;
    } while (iVar3 < 0x101);
  }
  return;
}



/* FUN_1003f970 @ 1003f970 size 146 */

uint __cdecl FUN_1003f970(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if ((param_1 & 1) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 0x10) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 0x20) != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x80000;
  }
  uVar2 = param_1 & 0xc00;
  if (uVar2 != 0) {
    if (uVar2 == 0x400) {
      uVar1 = uVar1 | 0x100;
    }
    else if (uVar2 == 0x800) {
      uVar1 = uVar1 | 0x200;
    }
    else if (uVar2 == 0xc00) {
      uVar1 = uVar1 | 0x300;
    }
  }
  if ((param_1 & 0x300) == 0) {
    uVar1 = uVar1 | 0x20000;
  }
  else if ((param_1 & 0x300) == 0x200) {
    uVar1 = uVar1 | 0x10000;
  }
  if ((param_1 & 0x1000) != 0) {
    uVar1 = uVar1 | 0x40000;
  }
  return uVar1;
}



/* FUN_10010710 @ 10010710 size 145 */

void __cdecl FUN_10010710(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0xbc) = 0xc1000000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc1000000;
  *(undefined4 *)(param_1 + 0xc4) = 0xc1000000;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 200) = 0x41000000;
  *(undefined4 *)(param_1 + 0xcc) = 0x41000000;
  *(undefined4 *)(param_1 + 0xd0) = 0x41000000;
  uVar1 = (*DAT_1006c1e0)(s_models_objects_bomb_tris_md2_10049494);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  if (*(int *)(param_1 + 0x244) == 0) {
    *(undefined4 *)(param_1 + 0x244) = 1000;
  }
  *(undefined1 **)(param_1 + 0x200) = &LAB_10010650;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_100154c0 @ 100154c0 size 145 */

void __cdecl FUN_100154c0(float param_1)

{
  int iVar1;
  float local_c;
  float local_8;
  float local_4;
  
  iVar1 = *(int *)((int)param_1 + 0x144);
  local_c = *(float *)(iVar1 + 4) - *(float *)((int)param_1 + 4);
  local_8 = *(float *)(iVar1 + 8) - *(float *)((int)param_1 + 8);
  local_4 = *(float *)(iVar1 + 0xc) - *(float *)((int)param_1 + 0xc);
  *(undefined4 *)((int)param_1 + 0x2e8) = *(undefined4 *)((int)param_1 + 0xc);
  *(undefined4 *)((int)param_1 + 0x2e0) = *(undefined4 *)((int)param_1 + 4);
  *(undefined4 *)((int)param_1 + 0x2e4) = *(undefined4 *)((int)param_1 + 8);
  *(float *)((int)param_1 + 0x2f8) = local_c;
  *(undefined4 *)((int)param_1 + 0x330) = 0;
  *(float *)((int)param_1 + 0x2fc) = local_8;
  *(float *)((int)param_1 + 0x300) = local_4;
  FUN_10014c50(param_1,&local_c,&LAB_10015140);
  *(uint *)((int)param_1 + 0x11c) = *(uint *)((int)param_1 + 0x11c) | 1;
  return;
}



/* FUN_10017d40 @ 10017d40 size 145 */

void __cdecl FUN_10017d40(float param_1)

{
  undefined4 uVar1;
  
  (*DAT_1006c224)(3);
  (*DAT_1006c224)(5);
  (*DAT_1006c238)((int)param_1 + 4);
  (*DAT_1006c218)((int)param_1 + 4,1);
  FUN_10006860(param_1,*(uint *)((int)param_1 + 0x264),(float)*(int *)((int)param_1 + 0x244),0,
               (float)(*(int *)((int)param_1 + 0x244) + 0x28),0x19);
  uVar1 = *(undefined4 *)((int)param_1 + 0x294);
  *(undefined4 *)((int)param_1 + 0x294) = 0;
  FUN_1001ae20((uint)param_1,*(int *)((int)param_1 + 0x264));
  *(undefined4 *)((int)param_1 + 0x294) = uVar1;
  return;
}



/* FUN_1001b0c0 @ 1001b0c0 size 145 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1001b0c0(float *param_1,float *param_2)

{
  int iVar1;
  
  iVar1 = FUN_100388c0(param_1,(float *)&DAT_1004bd10);
  if (iVar1 == 0) {
    iVar1 = FUN_100388c0(param_1,(float *)&DAT_1004bd28);
    if (iVar1 == 0) {
      FUN_10038700(param_1,param_2,(float *)0x0,(float *)0x0);
    }
    else {
      *param_2 = _DAT_1004bd34;
      param_2[1] = DAT_1004bd38;
      param_2[2] = DAT_1004bd3c;
    }
  }
  else {
    *param_2 = _DAT_1004bd1c;
    param_2[1] = DAT_1004bd20;
    param_2[2] = DAT_1004bd24;
  }
  param_1[2] = 0.0;
  param_1[1] = 0.0;
  *param_1 = 0.0;
  return;
}



/* FUN_10029030 @ 10029030 size 145 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10029030(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (0 < *(int *)(*(int *)(param_1 + 0x25c) + 0x220)) {
    iVar1 = FUN_100014e0(param_1,*(int *)(param_1 + 0x25c));
    if (iVar1 == 0) {
      uVar2 = _rand();
      if ((float)_DAT_10044168 <= (float)(uVar2 & 0x7fff) * _DAT_10044108) {
        uVar2 = _rand();
        if ((float)(uVar2 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044228) {
          *(undefined **)(param_1 + 0x358) = &DAT_10059020;
          return;
        }
        *(undefined **)(param_1 + 0x358) = &DAT_100590b8;
        return;
      }
    }
  }
  *(undefined **)(param_1 + 0x358) = &DAT_10058dc8;
  return;
}



/* FUN_1000c560 @ 1000c560 size 144 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1000c560(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (*(int *)(param_1 + 0x2cc) + -0x10046928) / 0x48;
  iVar1 = *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar2 * 4);
  *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar2 * 4) = iVar1 + 1;
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    if ((*(uint *)(param_1 + 0x11c) & 0x10000) == 0) {
      FUN_1000b210(param_1,(float)*(int *)(*(int *)(param_1 + 0x2cc) + 0x30));
    }
    if (iVar1 == 0) {
      (**(code **)(*(int *)(param_1 + 0x2cc) + 8))(param_2,*(int *)(param_1 + 0x2cc));
    }
  }
  return 1;
}



/* FUN_1001a4b0 @ 1001a4b0 size 144 */

void __cdecl FUN_1001a4b0(int param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (*(byte **)(param_1 + 0x128) == (byte *)0x0) {
    iVar3 = param_1 + 4;
    puVar1 = FUN_1001b070();
    (*DAT_1006c1c4)(s__s_at__s_needs_a_target_1004bcd0,*(undefined4 *)(param_1 + 0x118),puVar1,iVar3
                   );
  }
  else {
    puVar2 = (undefined4 *)FUN_1001ad80(*(byte **)(param_1 + 0x128));
    *(undefined4 **)(param_1 + 0x144) = puVar2;
    *(float *)(param_1 + 0x2ac) = (float)puVar2[1] - *(float *)(param_1 + 4);
    *(float *)(param_1 + 0x2b0) = (float)puVar2[2] - *(float *)(param_1 + 8);
    *(float *)(param_1 + 0x2b4) = (float)puVar2[3] - *(float *)(param_1 + 0xc);
    FUN_1001b400(puVar2);
  }
  *(undefined4 *)(*(int *)(param_1 + 0x274) + 0x244) = *(undefined4 *)(param_1 + 0x244);
  *(code **)(param_1 + 500) = FUN_1001a100;
  FUN_1001a100(param_1);
  return;
}



/* FUN_10017490 @ 10017490 size 143 */

void FUN_10017490(void)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  iVar1 = (*DAT_1006c25c)();
  if (iVar1 < 3) {
    (*DAT_1006c1c8)(0,2,s_Usage__addip_<ip_mask>_1004b7ac);
    return;
  }
  iVar1 = 0;
  if (0 < DAT_100620d0) {
    piVar4 = &DAT_100620e4;
    do {
      if (*piVar4 == -1) break;
      iVar1 = iVar1 + 1;
      piVar4 = piVar4 + 2;
    } while (iVar1 < DAT_100620d0);
  }
  if (iVar1 == DAT_100620d0) {
    if (DAT_100620d0 == 0x400) {
      (*DAT_1006c1c8)(0,2,s_IP_filter_list_is_full_1004b794);
      return;
    }
    DAT_100620d0 = DAT_100620d0 + 1;
  }
  puVar5 = &DAT_100620e0 + iVar1 * 2;
  pbVar2 = (byte *)(*DAT_1006c260)(2);
  iVar3 = FUN_10017520(pbVar2,puVar5);
  if (iVar3 == 0) {
    (&DAT_100620e4)[iVar1 * 2] = 0xffffffff;
  }
  return;
}



/* FUN_10030cd0 @ 10030cd0 size 143 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10030cd0(int *param_1)

{
  if ((*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) &&
     (*(float *)(DAT_1006c42c + 0x14) == _DAT_1004410c)) {
    (*DAT_1006c268)(s_menu_loadgame_1005f2f8);
    return;
  }
  if (param_1[0x41] != 1) {
    FUN_10030b40(param_1);
  }
  param_1[0x2e] = param_1[0x2e] & 0xfffffffe;
  FUN_10031070((int)param_1);
  param_1[0x14] = 6;
  *(undefined1 *)(param_1[0x15] + 0x10) = 0x20;
  *(undefined1 *)(param_1[0x15] + 0x11) = 0xe;
  *(undefined4 *)(param_1[0x15] + 0xf00) = DAT_1006c2e4;
  return;
}



/* FUN_10004b30 @ 10004b30 size 142 */

void __cdecl FUN_10004b30(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x54);
  iVar2 = *(int *)(iVar1 + 0x714);
  if (iVar2 != 0) {
    iVar4 = 1;
    do {
      uVar3 = (iVar2 + -0x10046928) / 0x48 + iVar4 & 0x800000ff;
      if ((int)uVar3 < 0) {
        uVar3 = (uVar3 - 1 | 0xffffff00) + 1;
      }
      if (*(int *)(iVar1 + 0x2e4 + uVar3 * 4) != 0) {
        if (((*(code **)(&DAT_10046930 + uVar3 * 0x48) != (code *)0x0) &&
            (((&DAT_10046960)[uVar3 * 0x48] & 1) != 0)) &&
           ((**(code **)(&DAT_10046930 + uVar3 * 0x48))(param_1,&DAT_10046928 + uVar3 * 0x12),
           *(undefined4 **)(iVar1 + 0x714) == &DAT_10046928 + uVar3 * 0x12)) {
          return;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x101);
  }
  return;
}



/* FUN_10012460 @ 10012460 size 142 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10012460(int param_1)

{
  *(float *)(param_1 + 0xc) = *(float *)(param_1 + 0xc) + _DAT_10044104;
  FUN_1001b510(param_1);
  *(undefined4 *)(param_1 + 0xf8) = 2;
  *(undefined4 *)(param_1 + 0x104) = 5;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffe;
  *(float *)(param_1 + 0x194) = DAT_1006c2e4 + _DAT_10044244;
  (*DAT_1006c208)(param_1);
  FUN_10012750(param_1);
  if (((*(int *)(param_1 + 0x25c) != 0) && ((*(byte *)(param_1 + 0x11c) & 1) == 0)) &&
     ((*(byte *)(*(int *)(param_1 + 0x25c) + 0x108) & 0x20) == 0)) {
    FUN_10001ac0(param_1);
    return;
  }
  *(undefined4 *)(param_1 + 0x25c) = 0;
  return;
}



/* FUN_10015f40 @ 10015f40 size 141 */

void __cdecl FUN_10015f40(int *param_1,undefined4 *param_2)

{
  undefined **ppuVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined **ppuVar5;
  char *pcVar6;
  char local_f34 [3892];
  
  puVar4 = param_2;
  pcVar6 = local_f34;
  for (iVar3 = 0x3cd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined4 *)pcVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    pcVar6 = pcVar6 + 4;
  }
  ppuVar5 = &PTR_s_pers_weapon_10049ee0;
  puVar2 = PTR_s_pers_weapon_10049ee0;
  while (puVar2 != (undefined *)0x0) {
    FUN_10015c90(param_1,(uint)ppuVar5,(int)local_f34);
    ppuVar1 = ppuVar5 + 4;
    ppuVar5 = ppuVar5 + 4;
    puVar2 = *ppuVar1;
  }
  FUN_10039a54(local_f34,0xf34,1,param_1);
  ppuVar5 = &PTR_s_pers_weapon_10049ee0;
  puVar2 = PTR_s_pers_weapon_10049ee0;
  while (puVar2 != (undefined *)0x0) {
    FUN_10015dc0(param_1,(int)ppuVar5,(int)param_2);
    ppuVar1 = ppuVar5 + 4;
    ppuVar5 = ppuVar5 + 4;
    puVar2 = *ppuVar1;
  }
  return;
}



/* FUN_10016240 @ 10016240 size 141 */

void __cdecl FUN_10016240(int *param_1,undefined4 *param_2)

{
  undefined **ppuVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined **ppuVar5;
  char *pcVar6;
  char local_3d0 [976];
  
  puVar4 = param_2;
  pcVar6 = local_3d0;
  for (iVar3 = 0xf4; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined4 *)pcVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    pcVar6 = pcVar6 + 4;
  }
  ppuVar5 = &PTR_s_classname_100498e0;
  puVar2 = PTR_s_classname_100498e0;
  while (puVar2 != (undefined *)0x0) {
    FUN_10015c90(param_1,(uint)ppuVar5,(int)local_3d0);
    ppuVar1 = ppuVar5 + 4;
    ppuVar5 = ppuVar5 + 4;
    puVar2 = *ppuVar1;
  }
  FUN_10039a54(local_3d0,0x3d0,1,param_1);
  ppuVar5 = &PTR_s_classname_100498e0;
  puVar2 = PTR_s_classname_100498e0;
  while (puVar2 != (undefined *)0x0) {
    FUN_10015dc0(param_1,(int)ppuVar5,(int)param_2);
    ppuVar1 = ppuVar5 + 4;
    ppuVar5 = ppuVar5 + 4;
    puVar2 = *ppuVar1;
  }
  return;
}



/* FUN_1003ea81 @ 1003ea81 size 141 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1003ea81(undefined4 *param_1)

{
  undefined4 uVar1;
  byte bVar2;
  undefined3 extraout_var;
  int iVar3;
  void *pvVar4;
  
  bVar2 = FUN_10040808(param_1[4]);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    return 0;
  }
  if (param_1 == (undefined4 *)&DAT_100600a0) {
    iVar3 = 0;
  }
  else {
    if (param_1 != (undefined4 *)&DAT_100600c0) {
      return 0;
    }
    iVar3 = 1;
  }
  _DAT_10061da4 = _DAT_10061da4 + 1;
  if ((*(ushort *)(param_1 + 3) & 0x10c) != 0) {
    return 0;
  }
  if ((&DAT_10061da8)[iVar3] == 0) {
    pvVar4 = _malloc(0x1000);
    (&DAT_10061da8)[iVar3] = pvVar4;
    if (pvVar4 == (void *)0x0) {
      param_1[2] = param_1 + 5;
      *param_1 = param_1 + 5;
      param_1[6] = 2;
      param_1[1] = 2;
      goto LAB_1003eafd;
    }
  }
  uVar1 = (&DAT_10061da8)[iVar3];
  param_1[6] = 0x1000;
  param_1[2] = uVar1;
  *param_1 = uVar1;
  param_1[1] = 0x1000;
LAB_1003eafd:
  *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) | 0x1102;
  return 1;
}



/* FUN_1003fbf8 @ 1003fbf8 size 141 */

void __cdecl FUN_1003fbf8(uint *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int local_8;
  
  local_8 = 3;
  iVar2 = (int)param_2 / 0x20;
  iVar5 = (int)param_2 % 0x20;
  param_2 = 0;
  bVar3 = (byte)iVar5;
  puVar6 = param_1;
  do {
    uVar1 = *puVar6;
    *puVar6 = uVar1 >> (bVar3 & 0x1f) | param_2;
    puVar6 = puVar6 + 1;
    param_2 = (uVar1 & ~(-1 << (bVar3 & 0x1f))) << (0x20 - bVar3 & 0x1f);
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  iVar5 = 2;
  iVar4 = 8;
  do {
    if (iVar5 < iVar2) {
      *(undefined4 *)(iVar4 + (int)param_1) = 0;
    }
    else {
      *(undefined4 *)(iVar4 + (int)param_1) = *(undefined4 *)(iVar4 + iVar2 * -4 + (int)param_1);
    }
    iVar5 = iVar5 + -1;
    iVar4 = iVar4 + -4;
  } while (-1 < iVar4);
  return;
}



/* FUN_1004048e @ 1004048e size 141 */

int * __cdecl FUN_1004048e(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint *_Size;
  uint *puVar3;
  
  _Size = (uint *)(param_1 * param_2);
  puVar3 = _Size;
  if (_Size < (uint *)0xffffffe1) {
    if (_Size == (uint *)0x0) {
      puVar3 = (uint *)0x1;
    }
    puVar3 = (uint *)((int)puVar3 + 0xfU & 0xfffffff0);
  }
  do {
    if (puVar3 < (uint *)0xffffffe1) {
      if (_Size < DAT_1005ffc4 || (int)_Size - (int)DAT_1005ffc4 == 0) {
        FUN_1003c8a1(9);
        piVar1 = FUN_1003ccab(_Size);
        FUN_1003c902(9);
        if (piVar1 != (int *)0x0) {
          _memset(piVar1,0,(size_t)_Size);
          return piVar1;
        }
      }
      piVar1 = HeapAlloc(DAT_1006ddfc,8,(SIZE_T)puVar3);
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
    }
    if (DAT_10061fc4 == 0) {
      return (int *)0x0;
    }
    iVar2 = FUN_1004251f(puVar3);
  } while (iVar2 != 0);
  return (int *)0x0;
}



/* FUN_1000fd60 @ 1000fd60 size 140 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000fd60(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0xc2800000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc2800000;
  *(undefined4 *)(param_1 + 200) = 0x42800000;
  *(undefined4 *)(param_1 + 0xcc) = 0x42800000;
  *(undefined4 *)(param_1 + 0xd0) = 0x41000000;
  uVar1 = (*DAT_1006c1e0)(s_models_objects_black_tris_md2_1004932c);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  *(undefined4 *)(param_1 + 0x44) = 0x20;
  *(undefined1 **)(param_1 + 0x200) = &LAB_1000fd20;
  *(undefined1 **)(param_1 + 500) = &LAB_1000fd30;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044198;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10022a50 @ 10022a50 size 140 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10022a50(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0xc1000000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc1000000;
  *(undefined4 *)(param_1 + 200) = 0x41000000;
  *(undefined4 *)(param_1 + 0xcc) = 0x41000000;
  *(undefined4 *)(param_1 + 0xd0) = 0x41000000;
  *(undefined4 *)(param_1 + 0x38) = 0x15a;
  uVar1 = (*DAT_1006c1e0)(s_models_monsters_boss3_rider_tris_1004e1fc);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  *(undefined1 **)(param_1 + 500) = &LAB_10022a20;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044198;
  uVar1 = (*DAT_1006c1e4)(s_makron_spine_wav_1004fc50);
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_1003fb2a @ 1003fb2a size 140 */

undefined4 __cdecl FUN_1003fb2a(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_8;
  
  local_8 = 0;
  puVar1 = (uint *)(param_1 + (param_2 / 0x20) * 4);
  bVar3 = 0x1f - (char)(param_2 % 0x20);
  if (((*puVar1 & 1 << (bVar3 & 0x1f)) != 0) &&
     (iVar2 = FUN_1003fa8b(param_1,param_2 + 1), iVar2 == 0)) {
    local_8 = FUN_1003fad4(param_1,param_2 + -1);
  }
  *puVar1 = *puVar1 & -1 << (bVar3 & 0x1f);
  iVar2 = param_2 / 0x20 + 1;
  if (iVar2 < 3) {
    puVar5 = (undefined4 *)(param_1 + iVar2 * 4);
    for (iVar4 = 3 - iVar2; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
  }
  return local_8;
}



/* FUN_100162d0 @ 100162d0 size 139 */

void __cdecl FUN_100162d0(int *param_1)

{
  undefined **ppuVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined **ppuVar5;
  char *pcVar6;
  char local_130 [304];
  
  puVar4 = &DAT_1006c2e0;
  pcVar6 = local_130;
  for (iVar3 = 0x4c; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined4 *)pcVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    pcVar6 = pcVar6 + 4;
  }
  ppuVar5 = &PTR_s_changemap_10049e80;
  puVar2 = PTR_s_changemap_10049e80;
  while (puVar2 != (undefined *)0x0) {
    FUN_10015c90(param_1,(uint)ppuVar5,(int)local_130);
    ppuVar1 = ppuVar5 + 4;
    ppuVar5 = ppuVar5 + 4;
    puVar2 = *ppuVar1;
  }
  FUN_10039a54(local_130,0x130,1,param_1);
  ppuVar5 = &PTR_s_changemap_10049e80;
  puVar2 = PTR_s_changemap_10049e80;
  while (puVar2 != (undefined *)0x0) {
    FUN_10015dc0(param_1,(int)ppuVar5,0x1006c2e0);
    ppuVar1 = ppuVar5 + 4;
    ppuVar5 = ppuVar5 + 4;
    puVar2 = *ppuVar1;
  }
  return;
}



/* FUN_100391ac @ 100391ac size 139 */

int __thiscall FUN_100391ac(void *this,byte *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  undefined *puVar6;
  
  while( true ) {
    if (DAT_1005fed4 < 2) {
      uVar1 = (byte)PTR_DAT_1005fcc8[(uint)*param_1 * 2] & 8;
      this = PTR_DAT_1005fcc8;
    }
    else {
      puVar6 = (undefined *)0x8;
      uVar1 = FUN_1003b258(this,(uint)*param_1,8);
      this = puVar6;
    }
    if (uVar1 == 0) break;
    param_1 = param_1 + 1;
  }
  uVar1 = (uint)*param_1;
  pbVar5 = param_1 + 1;
  if ((uVar1 == 0x2d) || (uVar4 = uVar1, uVar1 == 0x2b)) {
    uVar4 = (uint)*pbVar5;
    pbVar5 = param_1 + 2;
  }
  iVar3 = 0;
  while( true ) {
    if (DAT_1005fed4 < 2) {
      uVar2 = (byte)PTR_DAT_1005fcc8[uVar4 * 2] & 4;
    }
    else {
      puVar6 = (undefined *)0x4;
      uVar2 = FUN_1003b258(this,uVar4,4);
      this = puVar6;
    }
    if (uVar2 == 0) break;
    iVar3 = (uVar4 - 0x30) + iVar3 * 10;
    uVar4 = (uint)*pbVar5;
    pbVar5 = pbVar5 + 1;
  }
  if (uVar1 == 0x2d) {
    iVar3 = -iVar3;
  }
  return iVar3;
}



/* FUN_10003c70 @ 10003c70 size 138 */

char * __cdecl FUN_10003c70(int param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  ulonglong uVar6;
  
  DAT_10060c64._0_1_ = 0;
  if (*(int *)(param_1 + 0x54) == 0) {
    return (char *)&DAT_10060c64;
  }
  pcVar2 = FUN_10038bb0((byte *)(*(int *)(param_1 + 0x54) + 0xbc),&DAT_10046178);
  uVar3 = 0xffffffff;
  do {
    pcVar5 = pcVar2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar2 = pcVar5 + -uVar3;
  pcVar5 = (char *)&DAT_10060c64;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar5 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar5 = pcVar5 + 1;
  }
  pcVar2 = _strchr((char *)&DAT_10060c64,0x2f);
  if (pcVar2 == (char *)0x0) {
    return (char *)&DAT_10060c64;
  }
  uVar6 = __ftol();
  if ((uVar6 & 0x80) != 0) {
    *pcVar2 = '\0';
    return (char *)&DAT_10060c64;
  }
  return pcVar2 + 1;
}



/* FUN_1001b510 @ 1001b510 size 138 */

undefined4 __cdecl FUN_1001b510(int param_1)

{
  float *pfVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 auStack_70 [13];
  uint uStack_3c;
  undefined1 local_38 [56];
  
  pfVar1 = (float *)(param_1 + 4);
  while( true ) {
    puVar3 = (undefined4 *)
             (*DAT_1006c1f0)(local_38,pfVar1,param_1 + 0xbc,param_1 + 200,pfVar1,0,0x2010003);
    puVar5 = auStack_70;
    for (iVar4 = 0xe; uVar2 = uStack_3c, iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    }
    if (uStack_3c == 0) break;
    FUN_100060d0(uStack_3c,param_1,param_1,(float *)&DAT_10061c18,pfVar1,&DAT_10061c18,100000,0,0x20
                 ,0x15);
    if (*(int *)(uVar2 + 0xf8) != 0) {
      return 0;
    }
  }
  return 1;
}



/* FUN_10033240 @ 10033240 size 138 */

undefined4 __cdecl FUN_10033240(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (DAT_1006138c == 0) {
    return 0;
  }
  iVar1 = 8;
  uVar3 = DAT_100620c0;
  do {
    if (*(float *)(param_1 + 0x3a8) < *(float *)((&DAT_100620a0)[uVar3] + 0x120)) break;
    uVar3 = uVar3 + 1 & 7;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = FUN_10001560(param_1,(&DAT_100620a0)[uVar3]);
  if (iVar1 == 0) {
    uVar2 = uVar3 - 1 & 7;
    iVar1 = FUN_10001560(param_1,(&DAT_100620a0)[uVar2]);
    if (iVar1 != 0) {
      return (&DAT_100620a0)[uVar2];
    }
  }
  return (&DAT_100620a0)[uVar3];
}



/* FUN_10035830 @ 10035830 size 138 */

void __cdecl FUN_10035830(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x220) < 1) {
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xdfc) = 0;
    FUN_10035420(param_1);
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0x714);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x10) != 0)) {
    DAT_100613c0 = (uint)((float)DAT_1006c2e0 < *(float *)(*(int *)(param_1 + 0x54) + 0xeac));
    DAT_100613c4._0_1_ = -(*(int *)(*(int *)(param_1 + 0x54) + 0xec4) != 0) & 0x80;
    (**(code **)(*(int *)(*(int *)(param_1 + 0x54) + 0x714) + 0x10))(param_1);
  }
  return;
}



/* FUN_10001880 @ 10001880 size 137 */

undefined4 __cdecl FUN_10001880(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x58) != 0)) {
    iVar1 = FUN_10038b20(*(void **)(param_1 + 0x118),(byte *)s_player_10046030);
    if (iVar1 == 0) {
      return 1;
    }
    if ((*(uint *)(param_1 + 0x35c) & 0x8000000) != 0) {
      iVar1 = *(int *)(param_1 + 0x1dc);
      iVar3 = 0;
      while ((iVar1 != 0 && (*(void **)(iVar1 + 0x118) != (void *)0x0))) {
        iVar2 = FUN_10038b20(*(void **)(iVar1 + 0x118),(byte *)s_player_10046030);
        if (iVar2 == 0) {
          return 1;
        }
        if ((*(uint *)(iVar1 + 0x35c) & 0x8000000) == 0) {
          return 0;
        }
        if (iVar1 == param_1) {
          return 0;
        }
        iVar1 = *(int *)(iVar1 + 0x1dc);
        iVar3 = iVar3 + 1;
        if (9 < iVar3) {
          return 0;
        }
      }
    }
  }
  return 0;
}



/* FUN_1001b480 @ 1001b480 size 137 */

void FUN_1001b480(void)

{
  int iVar1;
  int iVar2;
  int in_stack_00001004;
  
  FUN_10039f80();
  if ((((*(int *)(in_stack_00001004 + 0x54) == 0) &&
       ((*(byte *)(in_stack_00001004 + 0xb8) & 4) == 0)) ||
      (0 < *(int *)(in_stack_00001004 + 0x220))) &&
     (iVar2 = (*DAT_1006c210)(in_stack_00001004 + 0xd4,in_stack_00001004 + 0xe0,&stack0x00000000,
                              0x400,2), 0 < iVar2)) {
    do {
      iVar1 = *(int *)register0x00000010;
      if ((*(int *)(iVar1 + 0x58) != 0) && (*(code **)(iVar1 + 0x1fc) != (code *)0x0)) {
        (**(code **)(iVar1 + 0x1fc))(iVar1,in_stack_00001004,0,0);
      }
      register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}



/* FUN_1003fa02 @ 1003fa02 size 137 */

uint __cdecl FUN_1003fa02(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)((param_1 & 0x10) != 0);
  if ((param_1 & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  if ((param_1 & 1) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  if ((param_1 & 0x80000) != 0) {
    uVar1 = uVar1 | 2;
  }
  uVar2 = param_1 & 0x300;
  if (uVar2 != 0) {
    if (uVar2 == 0x100) {
      uVar1 = uVar1 | 0x400;
    }
    else if (uVar2 == 0x200) {
      uVar1 = uVar1 | 0x800;
    }
    else if (uVar2 == 0x300) {
      uVar1 = uVar1 | 0xc00;
    }
  }
  if ((param_1 & 0x30000) == 0) {
    uVar1 = uVar1 | 0x300;
  }
  else if ((param_1 & 0x30000) == 0x10000) {
    uVar1 = uVar1 | 0x200;
  }
  if ((param_1 & 0x40000) != 0) {
    uVar1 = uVar1 | 0x1000;
  }
  return uVar1;
}



/* FUN_10042062 @ 10042062 size 137 */

int __cdecl FUN_10042062(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_10061fa0 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_10061fa0 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_10061fa0 != (FARPROC)0x0) {
        DAT_10061fa4 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_10061fa8 = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_100420b1;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_100420b1:
    if (DAT_10061fa4 != (FARPROC)0x0) {
      iVar1 = (*DAT_10061fa4)();
      if ((iVar1 != 0) && (DAT_10061fa8 != (FARPROC)0x0)) {
        iVar1 = (*DAT_10061fa8)(iVar1);
      }
    }
    iVar1 = (*DAT_10061fa0)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}



/* FUN_10004450 @ 10004450 size 136 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10004450(int param_1)

{
  if ((*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) &&
     (*(float *)(DAT_1006c1a4 + 0x14) == _DAT_1004410c)) {
    (*DAT_1006c1c8)(param_1,2,s_You_must_run_the_server_with___s_10046214);
    return;
  }
  if (*(int *)(param_1 + 0x104) == 1) {
    *(undefined4 *)(param_1 + 0x104) = 4;
    (*DAT_1006c1c8)(param_1,2,s_noclip_OFF_100462a4);
    return;
  }
  *(undefined4 *)(param_1 + 0x104) = 1;
  (*DAT_1006c1c8)(param_1,2,s_noclip_ON_10046298);
  return;
}



/* FUN_1000fe20 @ 1000fe20 size 136 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000fe20(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0xbc) = 0xc2000000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc2000000;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 2;
  *(undefined4 *)(param_1 + 0xc4) = 0xc1800000;
  *(undefined4 *)(param_1 + 200) = 0x42000000;
  *(undefined4 *)(param_1 + 0xcc) = 0x42000000;
  *(undefined4 *)(param_1 + 0xd0) = 0x42000000;
  uVar1 = (*DAT_1006c1e0)(s_models_monsters_tank_tris_md2_1004934c);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  *(undefined4 *)(param_1 + 0x38) = 0xfe;
  *(undefined1 **)(param_1 + 500) = &LAB_1000fdf0;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044198;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10014940 @ 10014940 size 136 */

void __cdecl FUN_10014940(int param_1)

{
  ulonglong uVar1;
  
  *(undefined4 *)(param_1 + 0x180) = 0;
  *(undefined4 *)(param_1 + 0x17c) = 0;
  *(undefined4 *)(param_1 + 0x178) = 0;
  *(undefined4 *)(param_1 + 0x18c) = 0;
  *(undefined4 *)(param_1 + 0x188) = 0;
  *(undefined4 *)(param_1 + 0x184) = 0;
  uVar1 = __ftol();
  *(float *)(param_1 + 0x10) =
       (float)(int)((longlong)((ulonglong)(uint)((int)uVar1 >> 0x1f) << 0x20 | uVar1 & 0xffffffff) %
                   0x168);
  uVar1 = __ftol();
  *(float *)(param_1 + 0x14) =
       (float)(int)((longlong)((ulonglong)(uint)((int)uVar1 >> 0x1f) << 0x20 | uVar1 & 0xffffffff) %
                   0x168);
  uVar1 = __ftol();
  *(float *)(param_1 + 0x18) =
       (float)(int)((longlong)((ulonglong)(uint)((int)uVar1 >> 0x1f) << 0x20 | uVar1 & 0xffffffff) %
                   0x168);
  (**(code **)(param_1 + 0x354))(param_1);
  return;
}



/* FUN_1003af6a @ 1003af6a size 136 */

float10 __cdecl FUN_1003af6a(int param_1,int param_2)

{
  int iVar1;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000020;
  
  iVar1 = FUN_1003b01a(param_2);
  if (iVar1 != 0) {
    FUN_1003b1df();
    iVar1 = FUN_100405a0();
    if (iVar1 == 0) {
      FUN_1003aff2(param_1);
    }
    return (float10)(double)CONCAT44(in_stack_00000020,in_stack_0000001c);
  }
  FUN_1003b1df();
  FUN_1003aff2(param_1);
  return (float10)(double)CONCAT44(in_stack_00000020,in_stack_0000001c);
}



/* FUN_10002e20 @ 10002e20 size 134 */

void __cdecl FUN_10002e20(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0xf18);
  iVar2 = 4;
  do {
    lVar4 = __ftol();
    iVar3 = iVar2 + 2;
    *(short *)(iVar2 + *(int *)(param_1 + 0x54)) = (short)lVar4;
    iVar2 = iVar3;
  } while (iVar3 < 10);
  **(undefined4 **)(param_1 + 0x54) = 4;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x1c) = *(undefined4 *)(iVar1 + 0x10);
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x20) = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x24) = *(undefined4 *)(iVar1 + 0x18);
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x28) =
       *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xf1c);
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x2c) =
       *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xf20);
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x30) =
       *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xf24);
  return;
}



/* FUN_10014530 @ 10014530 size 134 */

void __cdecl FUN_10014530(int param_1)

{
  int iVar1;
  
  FUN_10002d40(*(int *)(param_1 + 0x100));
  iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x54);
  *(undefined4 *)(iVar1 + 0xf28) = *(undefined4 *)(iVar1 + 0x58);
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x100) + 0x54) + 0x58) = 0;
  *(undefined1 **)(*(int *)(*(int *)(param_1 + 0x100) + 0x54) + 0xf10) = &LAB_10014750;
  *(undefined4 *)(param_1 + 0x120) = DAT_1006c2e4;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x100) + 0x54) + 0xf1c) = 0;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x100) + 0x54) + 0xf20) = 0;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x100) + 0x54) + 0xf24) = 0x41700000;
  return;
}



/* FUN_10001000 @ 10001000 size 133 */

void FUN_10001000(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_1006c3cc == 0) {
    iVar1 = 1;
    iVar2 = iVar1;
  }
  else {
    iVar1 = (DAT_1006c3cc - DAT_1006c2c4) / 0x3d0;
    iVar2 = iVar1;
  }
  while( true ) {
    iVar1 = iVar1 + 1;
    if (DAT_1006ca48 < iVar1) {
      iVar1 = 1;
    }
    DAT_1006c3cc = iVar1 * 0x3d0 + DAT_1006c2c4;
    if (((*(int *)(DAT_1006c3cc + 0x58) != 0) && (0 < *(int *)(DAT_1006c3cc + 0x220))) &&
       ((*(byte *)(DAT_1006c3cc + 0x108) & 0x20) == 0)) break;
    if (iVar1 == iVar2) {
      DAT_1006c3cc = 0;
      return;
    }
  }
  return;
}



/* FUN_10001600 @ 10001600 size 132 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10001600(int param_1,int param_2)

{
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  FUN_10038700((float *)(param_1 + 0x10),&local_c,(float *)0x0,(float *)0x0);
  local_18 = *(float *)(param_2 + 4) - *(float *)(param_1 + 4);
  local_14 = *(float *)(param_2 + 8) - *(float *)(param_1 + 8);
  local_10 = *(float *)(param_2 + 0xc) - *(float *)(param_1 + 0xc);
  FUN_10038900(&local_18);
  if ((float)_DAT_10044128 < local_c * local_18 + local_8 * local_14 + local_4 * local_10) {
    return 1;
  }
  return 0;
}



/* FUN_1003e71c @ 1003e71c size 131 */

undefined4 __cdecl FUN_1003e71c(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_10041000(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_10041000(2);
      iVar2 = FUN_10041000(1);
      if (iVar2 == iVar1) goto LAB_1003e76a;
    }
    hObject = (HANDLE)FUN_10041000(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_1003e76c;
    }
  }
LAB_1003e76a:
  DVar4 = 0;
LAB_1003e76c:
  FUN_10040f81(param_1);
  *(undefined1 *)((&DAT_1006ccc0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = 0;
  if (DVar4 == 0) {
    uVar5 = 0;
  }
  else {
    FUN_1004051b(DVar4);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}



/* FUN_10002210 @ 10002210 size 130 */

void __cdecl FUN_10002210(float param_1,float param_2)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  
  fVar2 = param_1;
  *(undefined4 *)((int)param_1 + 0x1e8) = DAT_1006ca68;
  FUN_1002a850((int)param_1);
  piVar1 = (int *)((int)param_1 + 0x3bc);
  param_1 = 90.0;
  if (*piVar1 == 0) {
    param_1 = -90.0;
  }
  iVar3 = FUN_1002ae40((int)fVar2,param_1 + *(float *)((int)fVar2 + 0x1e8),param_2);
  if (iVar3 == 0) {
    *(int *)((int)fVar2 + 0x3bc) = 1 - *(int *)((int)fVar2 + 0x3bc);
    FUN_1002ae40((int)fVar2,*(float *)((int)fVar2 + 0x1e8) - param_1,param_2);
  }
  return;
}



/* FUN_1000fee0 @ 1000fee0 size 130 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000fee0(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0xbc) = 0xc2000000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc2000000;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 2;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 200) = 0x42000000;
  *(undefined4 *)(param_1 + 0xcc) = 0x42000000;
  *(undefined4 *)(param_1 + 0xd0) = 0x42000000;
  uVar1 = (*DAT_1006c1e0)(s_models_monsters_bitch_tris_md2_1004936c);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  *(undefined4 *)(param_1 + 0x38) = 0xd0;
  *(undefined1 **)(param_1 + 500) = &LAB_1000feb0;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044198;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_1000ffa0 @ 1000ffa0 size 130 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000ffa0(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0xbc) = 0xc2000000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc2000000;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 2;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 200) = 0x42000000;
  *(undefined4 *)(param_1 + 0xcc) = 0x42000000;
  *(undefined4 *)(param_1 + 0xd0) = 0x42000000;
  uVar1 = (*DAT_1006c1e0)(s_models_monsters_bitch_tris_md2_1004936c);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  *(undefined4 *)(param_1 + 0x38) = 0xf8;
  *(undefined1 **)(param_1 + 500) = &LAB_1000ff70;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044198;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10012230 @ 10012230 size 129 */

void __cdecl FUN_10012230(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x40) & 0xfffffcff;
  uVar1 = *(uint *)(param_1 + 0x44) & 0xffffe3ff;
  *(uint *)(param_1 + 0x40) = uVar2;
  *(uint *)(param_1 + 0x44) = uVar1;
  if ((*(uint *)(param_1 + 0x35c) & 0x4000) != 0) {
    *(uint *)(param_1 + 0x40) = uVar2 | 0x100;
    *(uint *)(param_1 + 0x44) = uVar1 | 0x400;
  }
  if ((0 < *(int *)(param_1 + 0x220)) && (DAT_1006c2e4 < *(float *)(param_1 + 0x234))) {
    if (*(int *)(param_1 + 0x3c8) == 1) {
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x200;
      return;
    }
    if (*(int *)(param_1 + 0x3c8) == 2) {
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x100;
      *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 0x800;
    }
  }
  return;
}



/* FUN_10018fb0 @ 10018fb0 size 129 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10018fb0(uint param_1)

{
  float fVar1;
  
  if (*(float *)(param_1 + 0x1ec) == _DAT_1004410c) {
    FUN_1001ae20(param_1,*(int *)(param_1 + 0x264));
    if (_DAT_1004410c < *(float *)(param_1 + 0x290)) {
      *(undefined1 **)(param_1 + 500) = &LAB_10018fa0;
      *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + *(float *)(param_1 + 0x290);
      return;
    }
    *(undefined4 *)(param_1 + 0x1fc) = 0;
    fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
    *(code **)(param_1 + 500) = FUN_1001b400;
    *(float *)(param_1 + 0x1ec) = fVar1;
  }
  return;
}



/* _strcmp @ 10040c60 size 129 */

/* Library Function - Single Match
    _strcmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strcmp(char *_Str1,char *_Str2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  
  if (((uint)_Str1 & 3) != 0) {
    if (((uint)_Str1 & 1) != 0) {
      bVar4 = *_Str1;
      _Str1 = _Str1 + 1;
      bVar5 = bVar4 < (byte)*_Str2;
      if (bVar4 != *_Str2) goto LAB_10040ca4;
      _Str2 = _Str2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_10040c70;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) goto LAB_10040ca4;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) goto LAB_10040ca4;
    if (bVar4 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_10040c70:
  while( true ) {
    uVar2 = *(undefined4 *)_Str1;
    bVar4 = (byte)uVar2;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 0x10);
    bVar5 = bVar4 < (byte)_Str2[2];
    if (bVar4 != _Str2[2]) break;
    bVar3 = (byte)((uint)uVar2 >> 0x18);
    if (bVar4 == 0) {
      return 0;
    }
    bVar5 = bVar3 < (byte)_Str2[3];
    if (bVar3 != _Str2[3]) break;
    _Str2 = _Str2 + 4;
    _Str1 = _Str1 + 4;
    if (bVar3 == 0) {
      return 0;
    }
  }
LAB_10040ca4:
  return (uint)bVar5 * -2 + 1;
}



/* FUN_10032c20 @ 10032c20 size 128 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10032c20(int param_1)

{
  int iVar1;
  
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    FUN_10032ae0(param_1);
    return;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xddc) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xdd8) = 0;
  iVar1 = *(int *)(param_1 + 0x54);
  if ((*(int *)(iVar1 + 0xde0) != 0) && (*(int *)(iVar1 + 0x724) == DAT_1006c840)) {
    *(undefined4 *)(iVar1 + 0xde0) = 0;
    return;
  }
  *(undefined4 *)(iVar1 + 0xde0) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x728) = 0;
  FUN_10032b50(param_1);
  return;
}



/* _strstr @ 10039f00 size 128 */

/* Library Function - Single Match
    _strstr
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strstr(char *_Str,char *_SubStr)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  uint *puVar9;
  char *pcVar10;
  
  cVar3 = *_SubStr;
  if (cVar3 == '\0') {
    return _Str;
  }
  if (_SubStr[1] == '\0') {
    while (((uint)_Str & 3) != 0) {
      uVar4 = *(uint *)_Str;
      if ((char)uVar4 == cVar3) {
        return (char *)(uint *)_Str;
      }
      _Str = (char *)((int)_Str + 1);
      if ((char)uVar4 == '\0') {
        return (char *)0x0;
      }
    }
    while( true ) {
      while( true ) {
        uVar4 = *(uint *)_Str;
        uVar7 = uVar4 ^ CONCAT22(CONCAT11(cVar3,cVar3),CONCAT11(cVar3,cVar3));
        uVar6 = uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff;
        puVar9 = (uint *)((int)_Str + 4);
        if (((uVar7 ^ 0xffffffff ^ uVar7 + 0x7efefeff) & 0x81010100) != 0) break;
        _Str = (char *)puVar9;
        if ((uVar6 & 0x81010100) != 0) {
          if ((uVar6 & 0x1010100) != 0) {
            return (char *)0x0;
          }
          if ((uVar4 + 0x7efefeff & 0x80000000) == 0) {
            return (char *)0x0;
          }
        }
      }
      uVar4 = *(uint *)_Str;
      if ((char)uVar4 == cVar3) {
        return (char *)(uint *)_Str;
      }
      if ((char)uVar4 == '\0') {
        return (char *)0x0;
      }
      cVar5 = (char)(uVar4 >> 8);
      if (cVar5 == cVar3) {
        return (char *)((int)_Str + 1);
      }
      if (cVar5 == '\0') {
        return (char *)0x0;
      }
      cVar5 = (char)(uVar4 >> 0x10);
      if (cVar5 == cVar3) {
        return (char *)((int)_Str + 2);
      }
      if (cVar5 == '\0') break;
      cVar5 = (char)(uVar4 >> 0x18);
      if (cVar5 == cVar3) {
        return (char *)((int)_Str + 3);
      }
      _Str = (char *)puVar9;
      if (cVar5 == '\0') {
        return (char *)0x0;
      }
    }
    return (char *)0x0;
  }
  do {
    cVar5 = *_Str;
    do {
      while (_Str = _Str + 1, cVar5 != cVar3) {
        if (cVar5 == '\0') {
          return (char *)0x0;
        }
        cVar5 = *_Str;
      }
      cVar5 = *_Str;
      pcVar10 = _Str + 1;
      pcVar8 = _SubStr;
    } while (cVar5 != _SubStr[1]);
    do {
      if (pcVar8[2] == '\0') {
LAB_10039f73:
        return _Str + -1;
      }
      if (*pcVar10 != pcVar8[2]) break;
      pcVar1 = pcVar8 + 3;
      if (*pcVar1 == '\0') goto LAB_10039f73;
      pcVar2 = pcVar10 + 1;
      pcVar8 = pcVar8 + 2;
      pcVar10 = pcVar10 + 2;
    } while (*pcVar1 == *pcVar2);
  } while( true );
}



/* FUN_10009010 @ 10009010 size 127 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10009010(int param_1)

{
  if ((*(uint *)(param_1 + 0x108) & 0x400) == 0) {
    if (*(int *)(param_1 + 0x318) != 0) {
      (*DAT_1006c1d0)(param_1,10,*(int *)(param_1 + 0x318),0x3f800000,0x40400000,0);
    }
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  *(undefined4 *)(param_1 + 0x330) = 0;
  if (((*(byte *)(param_1 + 0x11c) & 0x20) == 0) && (_DAT_1004410c <= *(float *)(param_1 + 0x32c)))
  {
    *(code **)(param_1 + 500) = FUN_100090f0;
    *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + *(float *)(param_1 + 0x32c);
  }
  return;
}



/* FUN_10009340 @ 10009340 size 127 */

void __cdecl FUN_10009340(uint param_1,undefined4 param_2,int param_3)

{
  if ((*(uint *)(param_1 + 0x108) & 0x400) == 0) {
    if (((*(byte *)(param_1 + 0x11c) & 0x20) == 0) ||
       ((*(int *)(param_1 + 0x330) != 2 && (*(int *)(param_1 + 0x330) != 0)))) {
      for (; param_1 != 0; param_1 = *(uint *)(param_1 + 0x270)) {
        *(undefined4 *)(param_1 + 0x114) = 0;
        *(undefined4 *)(param_1 + 0x1fc) = 0;
        FUN_10009200(param_1,param_3);
      }
    }
    else if (param_1 != 0) {
      do {
        *(undefined4 *)(param_1 + 0x114) = 0;
        *(undefined4 *)(param_1 + 0x1fc) = 0;
        FUN_100090f0(param_1);
        param_1 = *(uint *)(param_1 + 0x270);
      } while (param_1 != 0);
      return;
    }
  }
  return;
}



/* FUN_10033340 @ 10033340 size 127 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_10033340(undefined4 param_1,float *param_2)

{
  float fVar1;
  float10 fVar2;
  int local_4;
  
  local_4 = -1;
  fVar1 = DAT_100613a4 * *param_2 + DAT_100613a8 * param_2[1] + _DAT_100613ac * param_2[2];
  if (_DAT_1004410c <= fVar1) {
    local_4 = 1;
  }
  fVar1 = ABS(fVar1);
  fVar2 = (float10)*(float *)(DAT_1006c430 + 0x14);
  if (fVar1 < *(float *)(DAT_1006c174 + 0x14)) {
    fVar2 = (fVar2 * (float10)fVar1) / (float10)*(float *)(DAT_1006c174 + 0x14);
  }
  return (float10)local_4 * fVar2;
}



/* FUN_1003ea02 @ 1003ea02 size 127 */

void __thiscall FUN_1003ea02(void *this,uint *param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  ushort local_1c [6];
  uint local_10;
  undefined4 uStack_c;
  int local_8;
  
  uVar3 = 0;
  uVar1 = FUN_10041425(this,local_1c,&local_8,param_2,0,0,0,0);
  if ((uVar1 & 4) == 0) {
    iVar2 = FUN_1003fdf1(local_1c,&local_10);
    if (((uVar1 & 2) != 0) || (iVar2 == 1)) {
      uVar3 = 0x80;
    }
    if (((uVar1 & 1) != 0) || (iVar2 == 2)) {
      uVar3 = uVar3 | 0x100;
    }
  }
  else {
    uVar3 = 0x200;
    local_10 = 0;
    uStack_c = 0;
  }
  *param_1 = uVar3;
  *(ulonglong *)(param_1 + 4) = CONCAT44(uStack_c,local_10);
  param_1[1] = local_8 - (int)param_2;
  return;
}



/* FUN_10040f81 @ 10040f81 size 127 */

undefined4 __cdecl FUN_10040f81(uint param_1)

{
  int *piVar1;
  DWORD *pDVar2;
  int iVar3;
  DWORD nStdHandle;
  
  if (param_1 < DAT_1006cdc0) {
    iVar3 = (param_1 & 0x1f) * 0x24;
    piVar1 = (int *)((&DAT_1006ccc0)[(int)param_1 >> 5] + iVar3);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_10061c58 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_10040fdd;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_10040fdd:
      *(undefined4 *)((&DAT_1006ccc0)[(int)param_1 >> 5] + iVar3) = 0xffffffff;
      return 0;
    }
  }
  pDVar2 = FUN_1004058e();
  *pDVar2 = 9;
  pDVar2 = FUN_10040597();
  *pDVar2 = 0;
  return 0xffffffff;
}



/* FUN_100014e0 @ 100014e0 size 126 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_100014e0(int param_1,int param_2)

{
  undefined4 uVar1;
  float10 fVar2;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = *(float *)(param_1 + 4) - *(float *)(param_2 + 4);
  local_8 = *(float *)(param_1 + 8) - *(float *)(param_2 + 8);
  local_4 = *(float *)(param_1 + 0xc) - *(float *)(param_2 + 0xc);
  fVar2 = FUN_100389f0(&local_c);
  if (fVar2 < (float10)_DAT_10044118) {
    return 0;
  }
  if (fVar2 < (float10)_DAT_10044114) {
    return 1;
  }
  uVar1 = 2;
  if ((float10)_DAT_10044110 <= fVar2) {
    uVar1 = 3;
  }
  return uVar1;
}



/* FUN_10017f80 @ 10017f80 size 125 */

void __cdecl FUN_10017f80(undefined4 *param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1[0x8e] == 0) {
    puVar3 = param_1 + 1;
    puVar1 = FUN_1001b070();
    (*DAT_1006c1c4)(s_target_changelevel_with_no_map_a_1004b9b0,puVar1,puVar3);
    FUN_1001b400(param_1);
    return;
  }
  iVar2 = FUN_10038b20(&DAT_1006c328,(byte *)s_fact1_1004b9a8);
  if (iVar2 == 0) {
    iVar2 = FUN_10038b20((void *)param_1[0x8e],(byte *)s_fact3_1004b9a0);
    if (iVar2 == 0) {
      param_1[0x8e] = s_fact3_secret1_1004b990;
    }
  }
  param_1[0x80] = &LAB_10017e50;
  param_1[0x2e] = 1;
  return;
}



/* FUN_10040ce4 @ 10040ce4 size 125 */

int __cdecl FUN_10040ce4(uchar *param_1)

{
  int iVar1;
  size_t _MaxCount;
  size_t sVar2;
  int *piVar3;
  
  if (((DAT_1006cdc4 != 0) &&
      ((DAT_10061dfc != (int *)0x0 ||
       (((DAT_10061e04 != 0 && (iVar1 = FUN_1004274b(), iVar1 == 0)) && (DAT_10061dfc != (int *)0x0)
        ))))) && (piVar3 = DAT_10061dfc, param_1 != (uchar *)0x0)) {
    _MaxCount = _strlen((char *)param_1);
    for (; (char *)*piVar3 != (char *)0x0; piVar3 = piVar3 + 1) {
      sVar2 = _strlen((char *)*piVar3);
      if (((_MaxCount < sVar2) && (((uchar *)*piVar3)[_MaxCount] == '=')) &&
         (iVar1 = __mbsnbicoll((uchar *)*piVar3,param_1,_MaxCount), iVar1 == 0)) {
        return *piVar3 + 1 + _MaxCount;
      }
    }
  }
  return 0;
}



/* FUN_10010d60 @ 10010d60 size 124 */

void __cdecl FUN_10010d60(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  
  uVar4 = 0xffffffff;
  pcVar5 = *(char **)(param_1 + 0x114);
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  iVar2 = *(int *)(param_1 + 0x274);
  do {
    if (iVar2 == 0) {
      return;
    }
    if (*(int *)(iVar2 + 0x254) != 0) {
      iVar3 = *(int *)(iVar2 + 0x254) + -1;
      if ((int)(~uVar4 - 1) < iVar3) {
LAB_10010dcb:
        *(undefined4 *)(iVar2 + 0x38) = 0xc;
      }
      else {
        cVar1 = *(char *)(iVar3 + *(int *)(param_1 + 0x114));
        if ((cVar1 < '0') || ('9' < cVar1)) {
          if (cVar1 == '-') {
            *(undefined4 *)(iVar2 + 0x38) = 10;
          }
          else {
            if (cVar1 != ':') goto LAB_10010dcb;
            *(undefined4 *)(iVar2 + 0x38) = 0xb;
          }
        }
        else {
          *(int *)(iVar2 + 0x38) = cVar1 + -0x30;
        }
      }
    }
    iVar2 = *(int *)(iVar2 + 0x270);
  } while( true );
}



/* FUN_10040f05 @ 10040f05 size 124 */

undefined4 __cdecl FUN_10040f05(uint param_1,HANDLE param_2)

{
  DWORD *pDVar1;
  int iVar2;
  DWORD nStdHandle;
  
  if (param_1 < DAT_1006cdc0) {
    iVar2 = (param_1 & 0x1f) * 0x24;
    if (*(int *)((&DAT_1006ccc0)[(int)param_1 >> 5] + iVar2) == -1) {
      if (DAT_10061c58 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_10040f5e;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,param_2);
      }
LAB_10040f5e:
      *(HANDLE *)((&DAT_1006ccc0)[(int)param_1 >> 5] + iVar2) = param_2;
      return 0;
    }
  }
  pDVar1 = FUN_1004058e();
  *pDVar1 = 9;
  pDVar1 = FUN_10040597();
  *pDVar1 = 0;
  return 0xffffffff;
}



/* FUN_10042afe @ 10042afe size 124 */

void __cdecl FUN_10042afe(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  undefined2 local_10;
  undefined4 local_e;
  undefined2 uStack_a;
  undefined *puStack_8;
  
  ppuVar3 = &PTR_s_November_10060940;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      ppuVar3 = (undefined **)0x10060aa0;
    }
    if (param_3 == 0) {
      *(undefined2 *)param_1 = 0;
    }
    while (param_2 != 0) {
      ppuVar3 = ppuVar3 + 0x15;
      uVar1 = (int)param_2 >> 3;
      uVar2 = param_2 & 7;
      param_2 = uVar1;
      if (uVar2 != 0) {
        ppuVar4 = ppuVar3 + uVar2 * 3;
        if (0x7fff < *(ushort *)(ppuVar3 + uVar2 * 3)) {
          local_10 = SUB42(*ppuVar4,0);
          local_e._0_2_ = (undefined2)((uint)*ppuVar4 >> 0x10);
          local_e._2_2_ = SUB42(ppuVar4[1],0);
          uStack_a = (undefined2)((uint)ppuVar4[1] >> 0x10);
          puStack_8 = ppuVar4[2];
          local_e = CONCAT22(local_e._2_2_,(undefined2)local_e) + -1;
          ppuVar4 = (undefined **)&local_10;
        }
        FUN_100428de(param_1,(int *)ppuVar4);
      }
    }
  }
  return;
}



/* FUN_10030860 @ 10030860 size 123 */

uint FUN_10030860(void)

{
  uint uVar1;
  uint uVar2;
  float10 fVar3;
  float local_4;
  
  uVar2 = 0;
  local_4 = 0.0;
  uVar1 = FUN_1001ac00(0,0x118,(byte *)s_info_player_deathmatch_1004b26c);
  if (uVar1 != 0) {
    do {
      fVar3 = FUN_100306b0(uVar1);
      if ((float10)local_4 < fVar3) {
        local_4 = (float)fVar3;
        uVar2 = uVar1;
      }
      uVar1 = FUN_1001ac00(uVar1,0x118,(byte *)s_info_player_deathmatch_1004b26c);
    } while (uVar1 != 0);
    if (uVar2 != 0) {
      return uVar2;
    }
  }
  uVar2 = FUN_1001ac00(0,0x118,(byte *)s_info_player_deathmatch_1004b26c);
  return uVar2;
}



/* _strlen @ 1003c6e0 size 123 */

/* Library Function - Single Match
    _strlen
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

size_t __cdecl _strlen(char *_Str)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar2 = (uint *)_Str;
  do {
    if (((uint)puVar2 & 3) == 0) goto LAB_1003c700;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_1003c733:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_1003c700:
  do {
    do {
      puVar3 = puVar2;
      puVar2 = puVar3 + 1;
    } while (((*puVar3 ^ 0xffffffff ^ *puVar3 + 0x7efefeff) & 0x81010100) == 0);
    uVar1 = *puVar3;
    if ((char)uVar1 == '\0') {
      return (int)puVar3 - (int)_Str;
    }
    if ((char)(uVar1 >> 8) == '\0') {
      return (size_t)((int)puVar3 + (1 - (int)_Str));
    }
    if ((uVar1 & 0xff0000) == 0) {
      return (size_t)((int)puVar3 + (2 - (int)_Str));
    }
  } while ((uVar1 & 0xff000000) != 0);
  goto LAB_1003c733;
}



/* FUN_10028940 @ 10028940 size 122 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10028940(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x11c);
  if ((uVar1 & 0x10) != 0) {
    *(undefined **)(param_1 + 0x358) = &DAT_100584c0;
    *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) | 1;
    return;
  }
  if (((uVar1 & 4) != 0) && ((uVar1 & 0x20) != 0)) {
    *(undefined **)(param_1 + 0x358) = &DAT_10057ef0;
    return;
  }
  uVar1 = _rand();
  if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044140) {
    *(undefined **)(param_1 + 0x358) = &DAT_10057750;
    return;
  }
  *(undefined **)(param_1 + 0x358) = &DAT_100578c8;
  return;
}



/* FUN_10003e70 @ 10003e70 size 121 */

void __cdecl FUN_10003e70(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x54);
  iVar4 = 1;
  uVar3 = *(int *)(iVar1 + 0x2e0) + 0xff;
  while( true ) {
    uVar2 = uVar3 & 0x800000ff;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xffffff00) + 1;
    }
    if (((*(int *)(iVar1 + 0x2e4 + uVar2 * 4) != 0) && (*(int *)(&DAT_10046930 + uVar2 * 0x48) != 0)
        ) && ((*(uint *)(&DAT_10046960 + uVar2 * 0x48) & param_2) != 0)) break;
    iVar4 = iVar4 + 1;
    uVar3 = uVar3 - 1;
    if (0x100 < iVar4) {
      *(undefined4 *)(iVar1 + 0x2e0) = 0xffffffff;
      return;
    }
  }
  *(uint *)(iVar1 + 0x2e0) = uVar2;
  return;
}



/* FUN_100176b0 @ 100176b0 size 121 */

void FUN_100176b0(void)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  (*DAT_1006c1c8)(0,2,s_Filter_list__1004b834);
  iVar2 = 0;
  if (0 < DAT_100620d0) {
    puVar3 = &DAT_100620e4;
    do {
      uVar1 = *puVar3;
      (*DAT_1006c1c8)(0,2,s__3i__3i__3i__3i_1004b820,uVar1 & 0xff,uVar1 >> 8 & 0xff,
                      uVar1 >> 0x10 & 0xff,uVar1 >> 0x18);
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 2;
    } while (iVar2 < DAT_100620d0);
  }
  return;
}



/* FUN_1001b160 @ 1001b160 size 121 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_1001b160(float *param_1)

{
  float10 fVar1;
  longlong lVar2;
  
  if (*param_1 == _DAT_1004410c) {
    fVar1 = (float10)_DAT_1004410c;
    if (_DAT_1004410c < param_1[1]) {
      return (float10)_DAT_100442d4;
    }
    if (param_1[1] < _DAT_1004410c) {
      return (float10)_DAT_100442d0;
    }
  }
  else {
    fpatan((float10)param_1[1],(float10)*param_1);
    lVar2 = __ftol();
    fVar1 = (float10)(int)lVar2;
    if (fVar1 < (float10)_DAT_1004410c) {
      fVar1 = fVar1 + (float10)_DAT_100442b0;
    }
  }
  return fVar1;
}



/* FUN_100044e0 @ 100044e0 size 120 */

undefined4 __cdecl FUN_100044e0(int param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_3 != 0) {
    iVar1 = FUN_10038b20(*(void **)(*(int *)(*(int *)(param_1 + 0x54) + 0x714) + 0x28),
                         (byte *)*param_2);
    if (iVar1 == 0) {
      *param_2 = param_3;
      return 0;
    }
    puVar2 = FUN_1000b150((byte *)*param_2);
    if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) == 0) {
      *param_2 = param_3;
      return 0;
    }
  }
  return 1;
}



/* FUN_1001ad80 @ 1001ad80 size 120 */

uint __cdecl FUN_1001ad80(byte *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint local_20 [8];
  
  uVar1 = 0;
  iVar3 = 0;
  if (param_1 == (byte *)0x0) {
    (*DAT_1006c1c4)(s_G_PickTarget_called_with_NULL_ta_1004bd64);
    return 0;
  }
  puVar4 = local_20;
  do {
    uVar1 = FUN_1001ac00(uVar1,300,param_1);
    if (uVar1 == 0) break;
    *puVar4 = uVar1;
    iVar3 = iVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar3 != 8);
  if (iVar3 == 0) {
    (*DAT_1006c1c4)(s_G_PickTarget__target__s_not_foun_1004bd40,param_1);
    return 0;
  }
  iVar2 = _rand();
  return local_20[iVar2 % iVar3];
}



/* FUN_100289c0 @ 100289c0 size 120 */

void __cdecl FUN_100289c0(int param_1)

{
  if ((*(byte *)(param_1 + 0x11c) & 0x10) == 0) {
    *(undefined4 *)(param_1 + 0xc4) = 0xc1c00000;
    *(undefined4 *)(param_1 + 0xbc) = 0xc1800000;
    *(undefined4 *)(param_1 + 0xc0) = 0xc1800000;
    *(undefined4 *)(param_1 + 0xd0) = 0xc1000000;
    *(undefined4 *)(param_1 + 200) = 0x41800000;
    *(undefined4 *)(param_1 + 0xcc) = 0x41800000;
    *(undefined4 *)(param_1 + 0x104) = 7;
  }
  else {
    *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) | 1;
  }
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 2;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10030ac0 @ 10030ac0 size 120 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10030ac0(float param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)((int)param_1 + 0x220) < -0x28) {
    uVar1 = (*DAT_1006c1e4)(s_misc_udeath_wav_100493f8,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_1,4,uVar1);
    iVar2 = 4;
    do {
      FUN_1000dd30(param_1,s_models_objects_gibs_sm_meat_tris_100493d0,param_4,0);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *(float *)((int)param_1 + 0xc) = *(float *)((int)param_1 + 0xc) - _DAT_100443d4;
    FUN_1000e0e0((int)param_1,param_4);
    *(undefined4 *)((int)param_1 + 0x240) = 0;
  }
  return;
}



/* FUN_100199c0 @ 100199c0 size 119 */

void __cdecl FUN_100199c0(int param_1)

{
  undefined4 uVar1;
  
  FUN_10018f40(param_1);
  uVar1 = (*DAT_1006c1e4)(s_world_electro_wav_1004bbe4);
  *(undefined4 *)(param_1 + 0x280) = uVar1;
  *(undefined1 **)(param_1 + 0x1fc) = &LAB_10019900;
  if (*(int *)(param_1 + 0x244) == 0) {
    *(undefined4 *)(param_1 + 0x244) = 5;
  }
  if ((*(uint *)(param_1 + 0x11c) & 1) == 0) {
    *(undefined4 *)(param_1 + 0xf8) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0xf8) = 0;
  }
  if ((*(uint *)(param_1 + 0x11c) & 2) != 0) {
    *(code **)(param_1 + 0x200) = FUN_100198c0;
  }
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10024620 @ 10024620 size 119 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10024620(int param_1)

{
  uint uVar1;
  
  if (*(undefined **)(param_1 + 0x358) == &DAT_10051730) {
    *(undefined **)(param_1 + 0x358) = &DAT_10051750;
    return;
  }
  if (*(undefined **)(param_1 + 0x358) == &DAT_10051750) {
    uVar1 = _rand();
    if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044168) {
      *(undefined **)(param_1 + 0x358) = &DAT_100517f0;
      return;
    }
  }
  else {
    if ((*(byte *)(param_1 + 0x35c) & 1) != 0) {
      *(undefined **)(param_1 + 0x358) = &DAT_10051540;
      return;
    }
    *(undefined **)(param_1 + 0x358) = &DAT_100516a0;
  }
  return;
}



/* FUN_1003fe77 @ 1003fe77 size 119 */

void __cdecl FUN_1003fe77(char *param_1,int param_2,int param_3)

{
  char *_Str;
  char *pcVar1;
  char *pcVar2;
  size_t sVar3;
  char *pcVar4;
  char cVar5;
  
  pcVar1 = param_1;
  pcVar4 = *(char **)(param_3 + 0xc);
  _Str = param_1 + 1;
  *param_1 = '0';
  pcVar2 = _Str;
  if (0 < param_2) {
    param_1 = (char *)param_2;
    param_2 = 0;
    do {
      cVar5 = *pcVar4;
      if (cVar5 == '\0') {
        cVar5 = '0';
      }
      else {
        pcVar4 = pcVar4 + 1;
      }
      *pcVar2 = cVar5;
      pcVar2 = pcVar2 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != (char *)0x0);
  }
  *pcVar2 = '\0';
  if ((-1 < param_2) && ('4' < *pcVar4)) {
    while (pcVar2 = pcVar2 + -1, *pcVar2 == '9') {
      *pcVar2 = '0';
    }
    *pcVar2 = *pcVar2 + '\x01';
  }
  if (*pcVar1 == '1') {
    *(int *)(param_3 + 4) = *(int *)(param_3 + 4) + 1;
  }
  else {
    sVar3 = _strlen(_Str);
    FUN_10040150((undefined4 *)pcVar1,(undefined4 *)_Str,sVar3 + 1);
  }
  return;
}



/* FUN_1003b258 @ 1003b258 size 117 */

uint __thiscall FUN_1003b258(void *this,int param_1,uint param_2)

{
  BOOL BVar1;
  int iVar2;
  undefined4 local_8;
  
  if (param_1 + 1U < 0x101) {
    param_1._2_2_ = *(ushort *)(PTR_DAT_1005fcc8 + param_1 * 2);
  }
  else {
    if ((PTR_DAT_1005fcc8[(param_1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      local_8 = CONCAT31((int3)((uint)this >> 8),(char)param_1) & 0xffff00ff;
      iVar2 = 1;
    }
    else {
      local_8._0_2_ = CONCAT11((char)param_1,(char)((uint)param_1 >> 8));
      local_8 = CONCAT22((short)((uint)this >> 0x10),(undefined2)local_8) & 0xff00ffff;
      iVar2 = 2;
    }
    BVar1 = FUN_100405a3(1,(LPCSTR)&local_8,iVar2,(LPWORD)((int)&param_1 + 2),0,0,1);
    if (BVar1 == 0) {
      return 0;
    }
  }
  return param_1._2_2_ & param_2;
}



/* FUN_1003c797 @ 1003c797 size 117 */

void FUN_1003c797(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (0 < DAT_1006ddf4) {
    puVar2 = (undefined4 *)((int)DAT_1006ddf8 + 0xc);
    do {
      VirtualFree((LPVOID)*puVar2,0x100000,0x4000);
      VirtualFree((LPVOID)*puVar2,0,0x8000);
      HeapFree(DAT_1006ddfc,0,(LPVOID)puVar2[1]);
      puVar2 = puVar2 + 5;
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_1006ddf4);
  }
  HeapFree(DAT_1006ddfc,0,DAT_1006ddf8);
  HeapDestroy(DAT_1006ddfc);
  return;
}



/* __aullrem @ 10040970 size 117 */

/* Library Function - Single Match
    __aullrem
   
   Library: Visual Studio */

undefined8 __aullrem(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  
  uVar3 = param_1;
  uVar4 = param_4;
  uVar9 = param_2;
  uVar10 = param_3;
  if (param_4 == 0) {
    iVar6 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) %
                 (ulonglong)param_3);
    iVar7 = 0;
  }
  else {
    do {
      uVar5 = uVar4 >> 1;
      uVar10 = uVar10 >> 1 | (uint)((uVar4 & 1) != 0) << 0x1f;
      uVar8 = uVar9 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f;
      uVar4 = uVar5;
      uVar9 = uVar8;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar8,uVar3) / (ulonglong)uVar10;
    uVar3 = (int)uVar1 * param_4;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;
    uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar4 = (uint)lVar2;
    uVar10 = uVar9 + uVar3;
    if (((CARRY4(uVar9,uVar3)) || (param_2 < uVar10)) || ((param_2 <= uVar10 && (param_1 < uVar4))))
    {
      bVar11 = uVar4 < param_3;
      uVar4 = uVar4 - param_3;
      uVar10 = (uVar10 - param_4) - (uint)bVar11;
    }
    iVar6 = -(uVar4 - param_1);
    iVar7 = -(uint)(uVar4 - param_1 != 0) - ((uVar10 - param_2) - (uint)(uVar4 < param_1));
  }
  return CONCAT44(iVar7,iVar6);
}



/* FUN_10003df0 @ 10003df0 size 116 */

void __cdecl FUN_10003df0(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x54);
  iVar4 = 1;
  uVar3 = *(uint *)(iVar1 + 0x2e0);
  while( true ) {
    uVar3 = uVar3 + 1;
    uVar2 = uVar3 & 0x800000ff;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xffffff00) + 1;
    }
    if (((*(int *)(iVar1 + 0x2e4 + uVar2 * 4) != 0) && (*(int *)(&DAT_10046930 + uVar2 * 0x48) != 0)
        ) && ((*(uint *)(&DAT_10046960 + uVar2 * 0x48) & param_2) != 0)) break;
    iVar4 = iVar4 + 1;
    if (0x100 < iVar4) {
      *(undefined4 *)(iVar1 + 0x2e0) = 0xffffffff;
      return;
    }
  }
  *(uint *)(iVar1 + 0x2e0) = uVar2;
  return;
}



/* FUN_100097b0 @ 100097b0 size 116 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100097b0(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_2 + 0x54) != 0) && (*(float *)(param_1 + 0x20c) <= DAT_1006c2e4)) {
    *(float *)(param_1 + 0x20c) = DAT_1006c2e4 + (float)_DAT_10044150;
    (*DAT_1006c1cc)(param_2,&DAT_10046140,*(undefined4 *)(param_1 + 0x114));
    uVar1 = (*DAT_1006c1e4)(s_misc_talk1_wav_10046130,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_2,0,uVar1);
  }
  return;
}



/* FUN_1000ab80 @ 1000ab80 size 116 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000ab80(int param_1)

{
  longlong lVar1;
  
  if (*(float *)(param_1 + 0x148) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x148) = 0x42c80000;
  }
  if ((*(byte *)(param_1 + 0x11c) & 1) == 0) {
    lVar1 = __ftol();
    *(int *)(param_1 + 0x254) = (int)lVar1;
    *(undefined4 *)(param_1 + 0x148) = 0;
  }
  *(undefined1 **)(param_1 + 0x200) = &LAB_1000ab40;
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  *(undefined4 *)(param_1 + 0xf8) = 3;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_1002adc0 @ 1002adc0 size 116 */

void __cdecl FUN_1002adc0(int param_1,float param_2)

{
  float fVar1;
  int iVar2;
  
  fVar1 = *(float *)(param_1 + 0x1dc);
  if ((*(int *)(param_1 + 0x268) != 0) || ((*(byte *)(param_1 + 0x108) & 3) != 0)) {
    if ((*(int *)(param_1 + 0x25c) != 0) &&
       (iVar2 = FUN_1002ad60(param_1,*(int *)(param_1 + 0x25c),param_2), iVar2 != 0)) {
      return;
    }
    iVar2 = _rand();
    if ((((byte)iVar2 & 3) != 1) &&
       (iVar2 = FUN_1002a920(param_1,*(float *)(param_1 + 0x1e8),param_2), iVar2 != 0)) {
      return;
    }
    if (*(int *)(param_1 + 0x58) != 0) {
      FUN_1002aa20(param_1,fVar1,param_2);
    }
  }
  return;
}



/* FUN_10004350 @ 10004350 size 115 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10004350(int param_1)

{
  char *pcVar1;
  uint uVar2;
  
  if ((*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) &&
     (*(float *)(DAT_1006c1a4 + 0x14) == _DAT_1004410c)) {
    (*DAT_1006c1c8)(param_1,2,s_You_must_run_the_server_with___s_10046214);
    return;
  }
  uVar2 = *(uint *)(param_1 + 0x108) ^ 0x10;
  *(uint *)(param_1 + 0x108) = uVar2;
  pcVar1 = s_godmode_OFF_10046268;
  if ((uVar2 & 0x10) != 0) {
    pcVar1 = s_godmode_ON_1004625c;
  }
  (*DAT_1006c1c8)(param_1,2,pcVar1);
  return;
}



/* FUN_100043d0 @ 100043d0 size 115 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100043d0(int param_1)

{
  char *pcVar1;
  uint uVar2;
  
  if ((*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) &&
     (*(float *)(DAT_1006c1a4 + 0x14) == _DAT_1004410c)) {
    (*DAT_1006c1c8)(param_1,2,s_You_must_run_the_server_with___s_10046214);
    return;
  }
  uVar2 = *(uint *)(param_1 + 0x108) ^ 0x20;
  *(uint *)(param_1 + 0x108) = uVar2;
  pcVar1 = s_notarget_OFF_10046288;
  if ((uVar2 & 0x20) != 0) {
    pcVar1 = s_notarget_ON_10046278;
  }
  (*DAT_1006c1c8)(param_1,2,pcVar1);
  return;
}



/* FUN_10008f90 @ 10008f90 size 115 */

void __cdecl FUN_10008f90(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  
  if (*(byte **)(param_1 + 0x128) != (byte *)0x0) {
    for (uVar1 = FUN_1001ac00(0,300,*(byte **)(param_1 + 0x128)); uVar1 != 0;
        uVar1 = FUN_1001ac00(uVar1,300,*(byte **)(param_1 + 0x128))) {
      iVar2 = FUN_10038b20(*(void **)(uVar1 + 0x118),(byte *)s_func_areaportal_100466a8);
      if (iVar2 == 0) {
        (*DAT_1006c200)(*(undefined4 *)(uVar1 + 0x2c8),param_2);
      }
    }
  }
  return;
}



/* FUN_1004051b @ 1004051b size 115 */

void __cdecl FUN_1004051b(uint param_1)

{
  DWORD *pDVar1;
  uint *puVar2;
  int iVar3;
  
  pDVar1 = FUN_10040597();
  iVar3 = 0;
  *pDVar1 = param_1;
  puVar2 = &DAT_100605b8;
  do {
    if (param_1 == *puVar2) {
      pDVar1 = FUN_1004058e();
      *pDVar1 = *(DWORD *)(iVar3 * 8 + 0x100605bc);
      return;
    }
    puVar2 = puVar2 + 2;
    iVar3 = iVar3 + 1;
  } while ((int)puVar2 < 0x10060720);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    pDVar1 = FUN_1004058e();
    *pDVar1 = 0xd;
    return;
  }
  if ((0xbb < param_1) && (param_1 < 0xcb)) {
    pDVar1 = FUN_1004058e();
    *pDVar1 = 8;
    return;
  }
  pDVar1 = FUN_1004058e();
  *pDVar1 = 0x16;
  return;
}



/* FUN_10040751 @ 10040751 size 115 */

DWORD __cdecl FUN_10040751(uint param_1,LONG param_2,DWORD param_3)

{
  byte *pbVar1;
  HANDLE hFile;
  DWORD *pDVar2;
  DWORD DVar3;
  uint uVar4;
  
  hFile = (HANDLE)FUN_10041000(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    pDVar2 = FUN_1004058e();
    *pDVar2 = 9;
  }
  else {
    DVar3 = SetFilePointer(hFile,param_2,(PLONG)0x0,param_3);
    if (DVar3 == 0xffffffff) {
      uVar4 = GetLastError();
    }
    else {
      uVar4 = 0;
    }
    if (uVar4 == 0) {
      pbVar1 = (byte *)((&DAT_1006ccc0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
      *pbVar1 = *pbVar1 & 0xfd;
      return DVar3;
    }
    FUN_1004051b(uVar4);
  }
  return 0xffffffff;
}



/* FUN_1001b400 @ 1001b400 size 114 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1001b400(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  (*DAT_1006c20c)(param_1);
  if (*(float *)(DAT_1006ca60 + 0x14) + _DAT_10044164 <
      (float)(((int)param_1 - DAT_1006c2c4) / 0x3d0)) {
    puVar2 = param_1;
    for (iVar1 = 0xf4; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    param_1[0x46] = s_freed_1004be60;
    param_1[0x44] = DAT_1006c2e4;
    param_1[0x16] = 0;
  }
  return;
}



/* FUN_10028680 @ 10028680 size 113 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10028680(int param_1)

{
  uint uVar1;
  
  if (((*(uint *)(param_1 + 0x11c) & 0x20) != 0) && (*(int *)(param_1 + 0x38) == 0xf4)) {
    *(undefined **)(param_1 + 0x358) = &DAT_10057ef0;
    return;
  }
  if ((*(uint *)(param_1 + 0x11c) & 4) != 0) {
    *(undefined **)(param_1 + 0x358) = &DAT_10058300;
    return;
  }
  uVar1 = _rand();
  if ((float)(uVar1 & 0x7fff) * _DAT_10044108 <= (float)_DAT_10044140) {
    *(undefined **)(param_1 + 0x358) = &DAT_10057fa0;
    return;
  }
  *(undefined **)(param_1 + 0x358) = &DAT_100580f8;
  return;
}



/* FUN_10028700 @ 10028700 size 113 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10028700(int param_1)

{
  uint uVar1;
  
  if (((*(uint *)(param_1 + 0x11c) & 0x20) != 0) && (*(int *)(param_1 + 0x38) == 0xf4)) {
    *(undefined **)(param_1 + 0x358) = &DAT_10057ef0;
    return;
  }
  if ((*(uint *)(param_1 + 0x11c) & 4) != 0) {
    *(undefined **)(param_1 + 0x358) = &DAT_10058310;
    return;
  }
  uVar1 = _rand();
  if ((float)(uVar1 & 0x7fff) * _DAT_10044108 <= (float)_DAT_10044140) {
    *(undefined **)(param_1 + 0x358) = &DAT_10057fb0;
    return;
  }
  *(undefined **)(param_1 + 0x358) = &DAT_10058108;
  return;
}



/* FUN_10011b90 @ 10011b90 size 112 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10011b90(int param_1)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x2a8) == 0) {
    uVar1 = _rand();
    if ((float)(uVar1 & 0x7fff) * _DAT_10044108 <= (float)_DAT_10044140) {
      *(code **)(param_1 + 500) = FUN_10011c00;
      uVar1 = _rand();
      *(float *)(param_1 + 0x1ec) =
           (float)(uVar1 & 0x7fff) * _DAT_10044108 * _DAT_100441b0 + DAT_1006c2e4 + _DAT_1004414c;
    }
  }
  return;
}



/* FUN_10013df0 @ 10013df0 size 112 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10013df0(int param_1)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  
  pfVar2 = (float *)(param_1 + 0x184);
  FUN_10038950((float *)(param_1 + 0x10),0.1,pfVar2,(float *)(param_1 + 0x10));
  iVar3 = 3;
  do {
    if (*pfVar2 <= _DAT_1004410c) {
      fVar1 = *pfVar2 + _DAT_100441c0;
      *pfVar2 = fVar1;
      if (_DAT_1004410c < fVar1) goto LAB_10013e53;
    }
    else {
      fVar1 = *pfVar2 - _DAT_100441c0;
      *pfVar2 = fVar1;
      if (fVar1 < _DAT_1004410c) {
LAB_10013e53:
        *pfVar2 = 0.0;
      }
    }
    pfVar2 = pfVar2 + 1;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return;
    }
  } while( true );
}



/* FUN_100144c0 @ 100144c0 size 112 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100144c0(int param_1)

{
  float fVar1;
  
  *(undefined4 *)
   (*(int *)(*(int *)(param_1 + 0x100) + 0x54) + 0x2e4 +
   ((*(int *)(param_1 + 0x2cc) + -0x10046928) / 0x48) * 4) = 0;
  FUN_100145c0(param_1);
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x100) + 0x54) + 0xf18) = 0;
  fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
  *(undefined1 **)(param_1 + 500) = &LAB_100143f0;
  *(float *)(param_1 + 0x1ec) = fVar1;
  return;
}



/* FUN_10018230 @ 10018230 size 112 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10018230(int param_1)

{
  undefined4 uVar1;
  
  *(code **)(param_1 + 0x200) = FUN_100181e0;
  FUN_1001b0c0((float *)(param_1 + 0x10),(float *)(param_1 + 0x154));
  uVar1 = (*DAT_1006c1e4)(s_weapons_laser2_wav_1004b9d8);
  *(undefined4 *)(param_1 + 0x280) = uVar1;
  if (*(int *)(param_1 + 0x244) == 0) {
    *(undefined4 *)(param_1 + 0x244) = 0xf;
  }
  if (*(float *)(param_1 + 0x148) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x148) = 0x447a0000;
  }
  *(undefined4 *)(param_1 + 0xb8) = 1;
  return;
}



/* FUN_100296b0 @ 100296b0 size 112 */

void __cdecl FUN_100296b0(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if ((*(uint *)(param_1 + 0x35c) & 0x2000) == 0) {
    uVar2 = FUN_100294e0(param_1);
    if (uVar2 != 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x25c);
      *(uint *)(param_1 + 0x25c) = uVar2;
      *(undefined4 *)(param_1 + 0x260) = uVar1;
      *(uint *)(uVar2 + 0x100) = param_1;
      *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) | 0x2000;
      FUN_10001ac0(param_1);
      return;
    }
  }
  if ((*(byte *)(param_1 + 0x35c) & 1) != 0) {
    *(undefined **)(param_1 + 0x358) = &DAT_100595f8;
    return;
  }
  *(undefined **)(param_1 + 0x358) = &DAT_100596f0;
  return;
}



/* FUN_1000d160 @ 1000d160 size 111 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000d160(undefined4 *param_1)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    uVar2 = __ftol();
    if ((uVar2 & 1) != 0) {
      FUN_1001b400(param_1);
      return;
    }
  }
  param_1[0x43] = s_models_items_healing_medium_tris_100490a4;
  param_1[0x95] = 10;
  puVar1 = FUN_1000b150((byte *)s_Health_100478ec);
  FUN_1000cf20(param_1,puVar1);
  (*DAT_1006c1e4)(s_items_n_health_wav_10048fb0);
  return;
}



/* FUN_100104f0 @ 100104f0 size 111 */

void __cdecl FUN_100104f0(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 2;
  *(undefined4 *)(param_1 + 0xbc) = 0xc3300000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc2f00000;
  *(undefined4 *)(param_1 + 0xc4) = 0xc1c00000;
  *(undefined4 *)(param_1 + 200) = 0x43300000;
  *(undefined4 *)(param_1 + 0xcc) = 0x42f00000;
  *(undefined4 *)(param_1 + 0xd0) = 0x42900000;
  uVar1 = (*DAT_1006c1e0)(s_models_ships_bigviper_tris_md2_10049468);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10012570 @ 10012570 size 111 */

void __cdecl FUN_10012570(uint param_1)

{
  *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) & 0xfffffffc;
  *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) & 0x100;
  if (*(int **)(param_1 + 0x2cc) != (int *)0x0) {
    FUN_1000c850(param_1,*(int **)(param_1 + 0x2cc));
    *(undefined4 *)(param_1 + 0x2cc) = 0;
  }
  if (*(int *)(param_1 + 0x13c) != 0) {
    *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x13c);
  }
  if (*(int *)(param_1 + 0x128) != 0) {
    FUN_1001ae20(param_1,*(int *)(param_1 + 0x25c));
  }
  return;
}



/* FUN_10014180 @ 10014180 size 111 */

void __cdecl FUN_10014180(float *param_1)

{
  if ((code *)param_1[0x7c] != (code *)0x0) {
    (*(code *)param_1[0x7c])(param_1);
  }
  switch(param_1[0x41]) {
  case 0.0:
    FUN_10013af0((int)param_1);
    return;
  case 1.4013e-45:
    FUN_10013b00((int)param_1);
    return;
  case 2.8026e-45:
  case 4.2039e-45:
    FUN_10013970((int)param_1);
    return;
  default:
    (*DAT_1006c1dc)(s_SV_Physics__bad_movetype__i_10049868,param_1[0x41]);
    return;
  case 7.00649e-45:
    FUN_10013e60(param_1);
    return;
  case 8.40779e-45:
  case 9.80909e-45:
  case 1.12104e-44:
  case 1.26117e-44:
    FUN_10013b50((int)param_1);
    return;
  }
}



/* FUN_1003eef3 @ 1003eef3 size 111 */

uint __cdecl FUN_1003eef3(uint param_1)

{
  void *extraout_ECX;
  bool bVar1;
  void *this;
  
  if (DAT_10061db8 == 0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      return param_1 + 0x20;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_1006cdd8);
    bVar1 = DAT_1006cdd4 != 0;
    this = extraout_ECX;
    if (bVar1) {
      InterlockedDecrement((LONG *)&DAT_1006cdd8);
      this = (void *)0x13;
      FUN_1003c8a1(0x13);
    }
    param_1 = FUN_1003ef62(this,param_1);
    if (bVar1) {
      FUN_1003c902(0x13);
    }
    else {
      InterlockedDecrement((LONG *)&DAT_1006cdd8);
    }
  }
  return param_1;
}



/* FUN_10030900 @ 10030900 size 110 */

uint __cdecl FUN_10030900(int param_1)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = (*(int *)(param_1 + 0x54) - DAT_1006c844) / 0xf34;
  if (iVar4 != 0) {
    uVar3 = 0;
    while( true ) {
      uVar3 = FUN_1001ac00(uVar3,0x118,(byte *)s_info_player_coop_1004b258);
      if (uVar3 == 0) break;
      pbVar1 = *(byte **)(uVar3 + 300);
      if (pbVar1 == (byte *)0x0) {
        pbVar1 = &DAT_10060c60;
      }
      iVar2 = FUN_10038b20(&DAT_1006c848,pbVar1);
      if ((iVar2 == 0) && (iVar4 = iVar4 + -1, iVar4 == 0)) {
        return uVar3;
      }
    }
  }
  return 0;
}



/* FUN_10040b5f @ 10040b5f size 110 */

uint __cdecl FUN_10040b5f(uint param_1,int *param_2)

{
  uint uVar1;
  
  if ((param_1 != 0xffffffff) &&
     ((uVar1 = param_2[3], (uVar1 & 1) != 0 || (((uVar1 & 0x80) != 0 && ((uVar1 & 2) == 0)))))) {
    if (param_2[2] == 0) {
      FUN_100407c4(param_2);
    }
    if (*param_2 == param_2[2]) {
      if (param_2[1] != 0) {
        return 0xffffffff;
      }
      *param_2 = *param_2 + 1;
    }
    if ((*(byte *)(param_2 + 3) & 0x40) == 0) {
      *param_2 = *param_2 + -1;
      *(char *)*param_2 = (char)param_1;
    }
    else {
      *param_2 = *param_2 + -1;
      if (*(char *)*param_2 != (char)param_1) {
        *param_2 = (int)((char *)*param_2 + 1);
        return 0xffffffff;
      }
    }
    param_2[1] = param_2[1] + 1;
    param_2[3] = param_2[3] & 0xffffffefU | 1;
    return param_1 & 0xff;
  }
  return 0xffffffff;
}



/* FUN_1004274b @ 1004274b size 110 */

undefined4 FUN_1004274b(void)

{
  LPCWSTR lpWideCharStr;
  size_t _Size;
  uint *lpMultiByteStr;
  int iVar1;
  undefined4 *puVar2;
  
  lpWideCharStr = (LPCWSTR)*DAT_10061e04;
  puVar2 = DAT_10061e04;
  while( true ) {
    if (lpWideCharStr == (LPCWSTR)0x0) {
      return 0;
    }
    _Size = WideCharToMultiByte(1,0,lpWideCharStr,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (((_Size == 0) || (lpMultiByteStr = _malloc(_Size), lpMultiByteStr == (uint *)0x0)) ||
       (iVar1 = WideCharToMultiByte(1,0,(LPCWSTR)*puVar2,-1,(LPSTR)lpMultiByteStr,_Size,(LPCSTR)0x0,
                                    (LPBOOL)0x0), iVar1 == 0)) break;
    FUN_10042f29(lpMultiByteStr,0);
    lpWideCharStr = (LPCWSTR)puVar2[1];
    puVar2 = puVar2 + 1;
  }
  return 0xffffffff;
}



/* FUN_10004a60 @ 10004a60 size 109 */

void __cdecl FUN_10004a60(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x54);
  *(undefined4 *)(iVar2 + 0xdd8) = 0;
  *(undefined4 *)(iVar2 + 0xde0) = 0;
  if (*(int *)(iVar2 + 0xddc) != 0) {
    *(undefined4 *)(iVar2 + 0xddc) = 0;
    return;
  }
  *(undefined4 *)(iVar2 + 0xddc) = 1;
  (*DAT_1006c224)(5);
  puVar1 = (undefined4 *)(iVar2 + 0x2e4);
  iVar2 = 0x100;
  do {
    (*DAT_1006c228)(*puVar1);
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  (*DAT_1006c21c)(param_1,1);
  return;
}



/* FUN_10010960 @ 10010960 size 109 */

void __cdecl FUN_10010960(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0xbc) = 0xc2800000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc2800000;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 2;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 200) = 0x42800000;
  *(undefined4 *)(param_1 + 0xcc) = 0x42800000;
  *(undefined4 *)(param_1 + 0xd0) = 0x43000000;
  uVar1 = (*DAT_1006c1e0)(s_models_objects_satellite_tris_md_100494f0);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  *(undefined1 **)(param_1 + 0x200) = &LAB_10010930;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10012d80 @ 10012d80 size 109 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_10012d80(int param_1)

{
  if (*(float *)(param_1 + 0x1ec) <= _DAT_1004410c) {
    return 1;
  }
  if (DAT_1006c2e4 + (float)_DAT_10044250 < *(float *)(param_1 + 0x1ec)) {
    return 1;
  }
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  if (*(int *)(param_1 + 500) == 0) {
    (*DAT_1006c1dc)(s_NULL_ent_>think_10049800);
  }
  (**(code **)(param_1 + 500))(param_1);
  return 0;
}



/* FUN_10019b30 @ 10019b30 size 109 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10019b30(int param_1)

{
  if (*(float *)(param_1 + 0x148) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x148) = 0x43480000;
  }
  if (DAT_1006c2a0 == 0) {
    DAT_1006c2a0 = 200;
  }
  if (*(float *)(param_1 + 0x14) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x14) = 0x43b40000;
  }
  FUN_10018f40(param_1);
  *(undefined1 **)(param_1 + 0x1fc) = &LAB_10019ac0;
  *(float *)(param_1 + 0x15c) = (float)DAT_1006c2a0;
  return;
}



/* FUN_1001fd40 @ 1001fd40 size 109 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1001fd40(float param_1)

{
  float fVar1;
  
  (*DAT_1006c224)(3);
  (*DAT_1006c224)(5);
  (*DAT_1006c238)((int)param_1 + 4);
  (*DAT_1006c218)((int)param_1 + 4,2);
  FUN_10006860(param_1,(uint)param_1,100.0,0,100.0,0x19);
  if (*(code **)((int)param_1 + 500) == FUN_1001fd40) {
    fVar1 = DAT_1006c2e4 + (float)_DAT_10044140;
    *(undefined **)((int)param_1 + 500) = &DAT_1001fde0;
    *(float *)((int)param_1 + 0x1ec) = fVar1;
  }
  return;
}



/* FUN_10019850 @ 10019850 size 108 */

/* WARNING: Removing unreachable block (ram,0x1001987f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10019850(int param_1)

{
  bool bVar1;
  
  FUN_10018f40(param_1);
  DAT_10060e7c = (*DAT_1006c1e4)(s_misc_windfly_wav_1004bbd0);
  bVar1 = *(float *)(param_1 + 0x148) == _DAT_1004410c;
  *(undefined1 **)(param_1 + 0x200) = &LAB_10019830;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x148) = 0x447a0000;
  }
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_1003c835 @ 1003c835 size 108 */

void FUN_1003c835(void)

{
  undefined **ppuVar1;
  
  ppuVar1 = (undefined **)&DAT_1005ff04;
  do {
    if (((((LPCRITICAL_SECTION)*ppuVar1 != (LPCRITICAL_SECTION)0x0) &&
         (ppuVar1 != &PTR_DAT_1005ff48)) && (ppuVar1 != &PTR_DAT_1005ff38)) &&
       ((ppuVar1 != &PTR_DAT_1005ff28 && (ppuVar1 != &PTR_DAT_1005ff08)))) {
      DeleteCriticalSection((LPCRITICAL_SECTION)*ppuVar1);
      FUN_100396e7(*ppuVar1);
    }
    ppuVar1 = ppuVar1 + 1;
  } while ((int)ppuVar1 < 0x1005ffc4);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1005ff28);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1005ff38);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1005ff48);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1005ff08);
  return;
}



/* FUN_1000ebd0 @ 1000ebd0 size 107 */

void __cdecl FUN_1000ebd0(int param_1)

{
  if (*(int *)(param_1 + 0xf8) == 0) {
    *(undefined4 *)(param_1 + 0xf8) = 3;
    *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffe;
    FUN_1001b510(param_1);
  }
  else {
    *(undefined4 *)(param_1 + 0xf8) = 0;
    *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  }
  (*DAT_1006c208)(param_1);
  if ((*(byte *)(param_1 + 0x11c) & 2) == 0) {
    *(undefined4 *)(param_1 + 0x200) = 0;
  }
  return;
}



/* FUN_1002e950 @ 1002e950 size 107 */

void __cdecl FUN_1002e950(int param_1)

{
  uint uVar1;
  
  if ((*(int *)(param_1 + 0x25c) == 0) || (*(int *)(*(int *)(param_1 + 0x25c) + 0x54) == 0)) {
    uVar1 = *(uint *)(param_1 + 0x35c) & 0xfffffdff;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x35c) | 0x200;
  }
  *(uint *)(param_1 + 0x35c) = uVar1;
  if ((uVar1 & 1) != 0) {
    *(undefined **)(param_1 + 0x358) = &DAT_1005dff0;
    return;
  }
  if ((*(undefined **)(param_1 + 0x358) != &DAT_1005e100) &&
     (*(undefined **)(param_1 + 0x358) != &DAT_1005e190)) {
    *(undefined **)(param_1 + 0x358) = &DAT_1005e190;
    return;
  }
  *(undefined **)(param_1 + 0x358) = &DAT_1005e260;
  return;
}



/* FUN_10032ae0 @ 10032ae0 size 106 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10032ae0(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xddc) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xde0) = 0;
  if ((*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) ||
     (*(float *)(DAT_1006c42c + 0x14) != _DAT_1004410c)) {
    iVar1 = *(int *)(param_1 + 0x54);
    if (*(int *)(iVar1 + 0xdd8) != 0) {
      *(undefined4 *)(iVar1 + 0xdd8) = 0;
      return;
    }
    *(undefined4 *)(iVar1 + 0xdd8) = 1;
    FUN_10032ac0(param_1);
  }
  return;
}



/* FUN_10010260 @ 10010260 size 105 */

void __cdecl FUN_10010260(float param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)((int)param_1 + 0x220) < -0x4f) {
    uVar1 = (*DAT_1006c1e4)(s_misc_udeath_wav_100493f8,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_1,4,uVar1);
    iVar2 = 4;
    do {
      FUN_1000dd30(param_1,s_models_objects_gibs_sm_meat_tris_100493d0,param_4,0);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    FUN_1000df70(param_1,s_models_objects_gibs_head2_tris_m_100491d4,param_4,0);
  }
  return;
}



/* FUN_10035db0 @ 10035db0 size 105 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_10035db0(int param_1,float *param_2,float *param_3,float *param_4,float *param_5,float *param_6)

{
  float local_c;
  float local_8;
  float local_4;
  
  local_c = *param_3;
  local_8 = param_3[1];
  local_4 = param_3[2];
  if (*(int *)(param_1 + 0x2cc) == 1) {
    local_8 = local_8 * _DAT_100441bc;
  }
  else if (*(int *)(param_1 + 0x2cc) == 2) {
    local_8 = 0.0;
  }
  FUN_1001aba0(param_2,&local_c,param_4,param_5,param_6);
  return;
}



/* FUN_1004088a @ 1004088a size 105 */

int __cdecl FUN_1004088a(LPSTR param_1,WCHAR param_2)

{
  LPSTR lpMultiByteStr;
  int iVar1;
  DWORD *pDVar2;
  
  lpMultiByteStr = param_1;
  if (param_1 == (LPSTR)0x0) {
    return 0;
  }
  if (DAT_10061db8 == 0) {
    if ((ushort)param_2 < 0x100) {
      *param_1 = (CHAR)param_2;
      return 1;
    }
  }
  else {
    param_1 = (LPSTR)0x0;
    iVar1 = WideCharToMultiByte(DAT_10061dc8,0x220,&param_2,1,lpMultiByteStr,DAT_1005fed4,
                                (LPCSTR)0x0,(LPBOOL)&param_1);
    if ((iVar1 != 0) && (param_1 == (LPSTR)0x0)) {
      return iVar1;
    }
  }
  pDVar2 = FUN_1004058e();
  *pDVar2 = 0x2a;
  return -1;
}



/* FUN_1000b1a0 @ 1000b1a0 size 104 */

void __cdecl FUN_1000b1a0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x134) != 0) {
    iVar2 = 0;
    param_1 = *(int *)(param_1 + 0x274);
    for (iVar1 = param_1; iVar1 != 0; iVar1 = *(int *)(iVar1 + 600)) {
      iVar2 = iVar2 + 1;
    }
    iVar1 = _rand();
    iVar1 = iVar1 % iVar2;
    if (0 < iVar1) {
      do {
        param_1 = *(int *)(param_1 + 600);
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffe;
  *(undefined4 *)(param_1 + 0xf8) = 1;
  (*DAT_1006c208)(param_1);
  *(undefined4 *)(param_1 + 0x50) = 1;
  return;
}



/* __aulldiv @ 10040900 size 104 */

/* Library Function - Single Match
    __aulldiv
   
   Library: Visual Studio */

undefined8 __aulldiv(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar3 = param_1;
  uVar8 = param_4;
  uVar6 = param_2;
  uVar9 = param_3;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar5 = uVar8 >> 1;
      uVar9 = uVar9 >> 1 | (uint)((uVar8 & 1) != 0) << 0x1f;
      uVar7 = uVar6 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;
      uVar8 = uVar5;
      uVar6 = uVar7;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar9;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar8 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar8)) ||
       ((param_2 <= uVar8 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  return CONCAT44(uVar3,iVar4);
}



/* __local_unwind2 @ 1004257e size 104 */

/* Library Function - Single Match
    __local_unwind2
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
   Studio 2003 Release */

void __cdecl __local_unwind2(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  int iStack_10;
  
  iStack_10 = param_1;
  puStack_18 = &LAB_1004255c;
  pvStack_1c = ExceptionList;
  ExceptionList = &pvStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_10042612();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  ExceptionList = pvStack_1c;
  return;
}



/* FUN_10006a00 @ 10006a00 size 103 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10006a00(int param_1)

{
  if (*(float *)(param_1 + 0x34c) == _DAT_1004410c) {
    FUN_100069d0(param_1);
    return;
  }
  FUN_10038a20((float *)(param_1 + 0x334),*(float *)(param_1 + 0x34c) * (float)_DAT_10044170,
               (float *)(param_1 + 0x178));
  *(code **)(param_1 + 500) = FUN_100069d0;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  return;
}



/* FUN_1003a8ad @ 1003a8ad size 103 */

DWORD * FUN_1003a8ad(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(DAT_1005fbac);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = (DWORD *)FUN_1004048e(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_1005fbac,lpTlsValue);
      if (BVar1 != 0) {
        FUN_1003a89a((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        goto LAB_1003a908;
      }
    }
    __amsg_exit(0x10);
  }
LAB_1003a908:
  SetLastError(dwErrCode);
  return lpTlsValue;
}



/* FUN_10043108 @ 10043108 size 103 */

undefined4 * __cdecl FUN_10043108(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar5 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    piVar2 = param_1;
    while (iVar1 != 0) {
      piVar2 = piVar2 + 1;
      iVar5 = iVar5 + 1;
      iVar1 = *piVar2;
    }
    puVar3 = _malloc(iVar5 * 4 + 4);
    if (puVar3 == (undefined4 *)0x0) {
      __amsg_exit(9);
    }
    puVar4 = (uint *)*param_1;
    puVar6 = puVar3;
    while (puVar4 != (uint *)0x0) {
      param_1 = param_1 + 1;
      puVar4 = FUN_1004339f(puVar4);
      *puVar6 = puVar4;
      puVar6 = puVar6 + 1;
      puVar4 = (uint *)*param_1;
    }
    *puVar6 = 0;
    return puVar3;
  }
  return (undefined4 *)0x0;
}



/* FUN_10006df0 @ 10006df0 size 102 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10006df0(int param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x18c) = 0;
  *(undefined4 *)(param_1 + 0x188) = 0;
  *(undefined4 *)(param_1 + 0x184) = 0;
  *(undefined4 *)(param_1 + 0x354) = param_2;
  iVar2 = param_1;
  if ((*(uint *)(param_1 + 0x108) & 0x400) != 0) {
    iVar2 = *(int *)(param_1 + 0x274);
  }
  if (DAT_1006c404 != iVar2) {
    fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
    *(code **)(param_1 + 500) = FUN_10006d00;
    *(float *)(param_1 + 0x1ec) = fVar1;
    return;
  }
  FUN_10006d00(param_1);
  return;
}



/* FUN_10027ec0 @ 10027ec0 size 102 */

void __cdecl FUN_10027ec0(int param_1)

{
  *(undefined4 *)(param_1 + 0xbc) = 0xc1800000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc1800000;
  *(undefined4 *)(param_1 + 0xc4) = 0xc1c00000;
  *(undefined4 *)(param_1 + 200) = 0x41800000;
  *(undefined4 *)(param_1 + 0xcc) = 0x41800000;
  *(undefined4 *)(param_1 + 0xd0) = 0xc1000000;
  *(undefined4 *)(param_1 + 0x104) = 7;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 2;
  (*DAT_1006c208)(param_1);
  FUN_10011b90(param_1);
  return;
}



/* FUN_10002eb0 @ 10002eb0 size 101 */

void __cdecl FUN_10002eb0(int param_1,undefined4 param_2)

{
  if (*(int *)(*(int *)(param_1 + 0x54) + 0xf18) == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xf18) = param_2;
    FUN_10002d40(param_1);
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xf28) =
         *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x58);
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x58) = 0;
    *(undefined **)(*(int *)(param_1 + 0x54) + 0xf10) = PTR_LAB_10046048;
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xf24) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xf20) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xf1c) = 0;
  }
  return;
}



/* FUN_1003dd44 @ 1003dd44 size 101 */

int __cdecl FUN_1003dd44(uint param_1,char *param_2,uint param_3)

{
  int iVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_1006cdc0) &&
     ((*(byte *)((&DAT_1006ccc0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_10041042(param_1);
    iVar1 = FUN_1003dda9(param_1,param_2,param_3);
    FUN_100410a1(param_1);
    return iVar1;
  }
  pDVar2 = FUN_1004058e();
  *pDVar2 = 9;
  pDVar2 = FUN_10040597();
  *pDVar2 = 0;
  return -1;
}



/* FUN_1003e481 @ 1003e481 size 101 */

int __cdecl FUN_1003e481(uint param_1,char *param_2,char *param_3)

{
  int iVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_1006cdc0) &&
     ((*(byte *)((&DAT_1006ccc0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_10041042(param_1);
    iVar1 = FUN_1003e4e6(param_1,param_2,param_3);
    FUN_100410a1(param_1);
    return iVar1;
  }
  pDVar2 = FUN_1004058e();
  *pDVar2 = 9;
  pDVar2 = FUN_10040597();
  *pDVar2 = 0;
  return -1;
}



/* FUN_100406ec @ 100406ec size 101 */

DWORD __cdecl FUN_100406ec(uint param_1,LONG param_2,DWORD param_3)

{
  DWORD DVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_1006cdc0) &&
     ((*(byte *)((&DAT_1006ccc0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_10041042(param_1);
    DVar1 = FUN_10040751(param_1,param_2,param_3);
    FUN_100410a1(param_1);
    return DVar1;
  }
  pDVar2 = FUN_1004058e();
  *pDVar2 = 9;
  pDVar2 = FUN_10040597();
  *pDVar2 = 0;
  return 0xffffffff;
}



/* FUN_100114a0 @ 100114a0 size 100 */

void __cdecl FUN_100114a0(int param_1)

{
  (*DAT_1006c1ec)(param_1,s_models_objects_dmspot_tris_md2_10049648);
  *(undefined4 *)(param_1 + 0xbc) = 0xc2000000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc2000000;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 2;
  *(undefined4 *)(param_1 + 0xc4) = 0xc1c00000;
  *(undefined4 *)(param_1 + 200) = 0x42000000;
  *(undefined4 *)(param_1 + 0xcc) = 0x42000000;
  *(undefined4 *)(param_1 + 0xd0) = 0xc1800000;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10014270 @ 10014270 size 100 */

void __cdecl FUN_10014270(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0xf18);
  if (iVar1 != 0) {
    iVar1 = FUN_10038b20(*(void **)(iVar1 + 0x118),&DAT_10048094);
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x54);
      if (*(int *)(iVar1 + 0xf0c) != 0) {
        FUN_100145c0(*(int *)(iVar1 + 0xf18));
        return;
      }
      FUN_10014530(*(int *)(iVar1 + 0xf18));
      return;
    }
  }
  FUN_100142e0(param_1);
  return;
}



/* FUN_10033c90 @ 10033c90 size 100 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10033c90(float param_1,float param_2,float param_3,float param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  if (_DAT_1004410c < param_4) {
    fVar1 = (_DAT_10044104 - param_5[3]) * param_4 + param_5[3];
    fVar2 = param_5[3] / fVar1;
    fVar3 = _DAT_10044104 - fVar2;
    *param_5 = fVar2 * *param_5 + fVar3 * param_1;
    param_5[1] = fVar3 * param_2 + fVar2 * param_5[1];
    param_5[2] = fVar3 * param_3 + fVar2 * param_5[2];
    param_5[3] = fVar1;
  }
  return;
}



/* FUN_10004c60 @ 10004c60 size 99 */

void __cdecl FUN_10004c60(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x54);
  if ((*(int *)(iVar1 + 0x714) != 0) && (*(int *)(iVar1 + 0x718) != 0)) {
    iVar2 = (*(int *)(iVar1 + 0x718) + -0x10046928) / 0x48;
    if (*(int *)(iVar1 + 0x2e4 + iVar2 * 4) != 0) {
      if ((*(code **)(&DAT_10046930 + iVar2 * 0x48) != (code *)0x0) &&
         (((&DAT_10046960)[iVar2 * 0x48] & 1) != 0)) {
        (**(code **)(&DAT_10046930 + iVar2 * 0x48))(param_1,&DAT_10046928 + iVar2 * 0x12);
      }
    }
  }
  return;
}



/* FUN_10008bd0 @ 10008bd0 size 99 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10008bd0(uint param_1)

{
  bool bVar1;
  float fVar2;
  
  *(undefined4 *)(param_1 + 0x330) = 0;
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffbff | 0x800;
  FUN_1001ae20(param_1,*(int *)(param_1 + 0x264));
  bVar1 = _DAT_1004410c <= *(float *)(param_1 + 0x32c);
  *(undefined4 *)(param_1 + 0x38) = 1;
  if (bVar1) {
    fVar2 = DAT_1006c2e4 + *(float *)(param_1 + 0x32c);
    *(code **)(param_1 + 500) = FUN_10008b80;
    *(float *)(param_1 + 0x1ec) = fVar2;
  }
  return;
}



/* FUN_10008c40 @ 10008c40 size 99 */

void __cdecl FUN_10008c40(int param_1)

{
  if ((*(int *)(param_1 + 0x330) != 2) && (*(int *)(param_1 + 0x330) != 0)) {
    *(undefined4 *)(param_1 + 0x330) = 2;
    if ((*(int *)(param_1 + 0x310) != 0) && ((*(uint *)(param_1 + 0x108) & 0x400) == 0)) {
      (*DAT_1006c1d0)(param_1,10,*(int *)(param_1 + 0x310),0x3f800000,0x40400000,0);
    }
    FUN_10006b20(param_1,(float *)(param_1 + 0x2f8),FUN_10008bd0);
  }
  return;
}



/* FUN_1000d5a0 @ 1000d5a0 size 99 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000d5a0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (_DAT_1004410c < *(float *)(DAT_1006ca60 + 0x14)) {
    iVar1 = 0x3d0;
    do {
      if ((*(int *)(iVar1 + 0x58 + DAT_1006c2c4) != 0) &&
         (*(int *)(iVar1 + DAT_1006c2c4 + 0x54) != 0)) {
        FUN_10034d80((float)(iVar1 + DAT_1006c2c4));
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x3d0;
    } while ((float)iVar2 < *(float *)(DAT_1006ca60 + 0x14));
  }
  return;
}



/* FUN_1000eb60 @ 1000eb60 size 99 */

void __cdecl FUN_1000eb60(int param_1)

{
  if ((*(byte *)(param_1 + 0x11c) & 1) != 0) {
    (*DAT_1006c1d8)(*(int *)(param_1 + 0x2c8) + 800,&DAT_10049280);
    *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) & 0xfffffffe;
    return;
  }
  (*DAT_1006c1d8)(*(int *)(param_1 + 0x2c8) + 800,&DAT_10049284);
  *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) | 1;
  return;
}



/* FUN_10007100 @ 10007100 size 98 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10007100(int param_1)

{
  if ((*(uint *)(param_1 + 0x108) & 0x400) == 0) {
    if (*(int *)(param_1 + 0x318) != 0) {
      (*DAT_1006c1d0)(param_1,10,*(int *)(param_1 + 0x318),0x3f800000,0x40400000,0);
    }
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  *(undefined4 *)(param_1 + 0x330) = 0;
  *(code **)(param_1 + 500) = FUN_100071c0;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + _DAT_100441b4;
  return;
}



/* FUN_1000dc00 @ 1000dc00 size 97 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000dc00(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x38) + 1;
  *(int *)(param_1 + 0x38) = iVar2;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  if (iVar2 == 10) {
    *(code **)(param_1 + 500) = FUN_1001b400;
    uVar1 = _rand();
    *(float *)(param_1 + 0x1ec) =
         (float)(uVar1 & 0x7fff) * _DAT_10044108 * _DAT_100441b0 + DAT_1006c2e4 + _DAT_10044164;
  }
  return;
}



/* FUN_10038b40 @ 10038b40 size 97 */

void FUN_10038b40(void)

{
  int iVar1;
  char *in_stack_00010004;
  int in_stack_00010008;
  byte *in_stack_0001000c;
  
  FUN_10039f80();
  iVar1 = FUN_10039696(&stack0x00000000,in_stack_0001000c,(undefined4 *)&stack0x00010010);
  if (in_stack_00010008 <= iVar1) {
    FUN_1000d560((byte *)s_Com_sprintf__overflow_of__i_in___1005fa4c);
  }
  _strncpy(in_stack_00010004,&stack0x00000000,in_stack_00010008 - 1);
  return;
}



/* FUN_1003a500 @ 1003a500 size 97 */

undefined1 * __cdecl FUN_1003a500(undefined8 *param_1,undefined1 *param_2,int param_3,int param_4)

{
  uint local_2c [6];
  int local_14 [4];
  
  FUN_1003feee((int)*param_1,(int)((ulonglong)*param_1 >> 0x20),local_14,local_2c);
  FUN_1003fe77(param_2 + (uint)(0 < param_3) + (uint)(local_14[0] == 0x2d),param_3 + 1,(int)local_14
              );
  FUN_1003a561(param_2,param_3,param_4,local_14,'\0');
  return param_2;
}



/* FUN_1003c8a1 @ 1003c8a1 size 97 */

void __cdecl FUN_1003c8a1(int param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  piVar1 = &DAT_1005ff04 + param_1;
  if ((&DAT_1005ff04)[param_1] == 0) {
    lpCriticalSection = _malloc(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    FUN_1003c8a1(0x11);
    if (*piVar1 == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *piVar1 = (int)lpCriticalSection;
    }
    else {
      FUN_100396e7(lpCriticalSection);
    }
    FUN_1003c902(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)*piVar1);
  return;
}



/* FUN_1004316f @ 1004316f size 97 */

int __cdecl FUN_1004316f(uint param_1,int param_2)

{
  byte bVar1;
  DWORD *pDVar2;
  byte bVar3;
  
  bVar1 = *(byte *)((&DAT_1006ccc0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24);
  if (param_2 == 0x8000) {
    bVar3 = bVar1 & 0x7f;
  }
  else {
    if (param_2 != 0x4000) {
      pDVar2 = FUN_1004058e();
      *pDVar2 = 0x16;
      return -1;
    }
    bVar3 = bVar1 | 0x80;
  }
  *(byte *)((&DAT_1006ccc0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = bVar3;
  return (-(uint)((bVar1 & 0x80) != 0) & 0xffffc000) + 0x8000;
}



/* FUN_10004ad0 @ 10004ad0 size 96 */

void __cdecl FUN_10004ad0(int param_1)

{
  int iVar1;
  
  FUN_10003ef0(param_1);
  iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0x2e0);
  if (iVar1 == -1) {
    (*DAT_1006c1c8)(param_1,2,s_No_item_to_use__100463ac);
    return;
  }
  if (*(code **)(&DAT_10046930 + iVar1 * 0x48) == (code *)0x0) {
    (*DAT_1006c1c8)(param_1,2,s_Item_is_not_usable__100462c4);
    return;
  }
  (**(code **)(&DAT_10046930 + iVar1 * 0x48))(param_1,&DAT_10046928 + iVar1 * 0x12);
  return;
}



/* FUN_10004cd0 @ 10004cd0 size 96 */

void __cdecl FUN_10004cd0(int param_1)

{
  int iVar1;
  
  FUN_10003ef0(param_1);
  iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0x2e0);
  if (iVar1 == -1) {
    (*DAT_1006c1c8)(param_1,2,s_No_item_to_drop__100463c0);
    return;
  }
  if (*(code **)(&DAT_10046934 + iVar1 * 0x48) == (code *)0x0) {
    (*DAT_1006c1c8)(param_1,2,s_Item_is_not_dropable__10046394);
    return;
  }
  (**(code **)(&DAT_10046934 + iVar1 * 0x48))(param_1,&DAT_10046928 + iVar1 * 0x12);
  return;
}



/* FUN_10027290 @ 10027290 size 96 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10027290(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (0 < *(int *)(*(int *)(param_1 + 0x25c) + 0x220)) {
    iVar1 = FUN_10001560(param_1,*(int *)(param_1 + 0x25c));
    if (iVar1 != 0) {
      uVar2 = _rand();
      if ((float)(uVar2 & 0x7fff) * _DAT_10044108 <= (float)_DAT_10044140) {
        *(undefined **)(param_1 + 0x358) = &DAT_10055a50;
        return;
      }
    }
  }
  *(undefined **)(param_1 + 0x358) = &DAT_10055ab8;
  return;
}



/* FUN_10010030 @ 10010030 size 95 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10010030(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x38) + 1;
  *(int *)(param_1 + 0x38) = iVar2;
  if (iVar2 < 0x18) {
    *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  }
  else {
    *(undefined4 *)(param_1 + 0x1ec) = 0;
  }
  if (iVar2 == 0x16) {
    uVar1 = (*DAT_1006c1e4)(s_tank_thud_wav_1004938c,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_1,4,uVar1);
  }
  return;
}



/* FUN_10017c70 @ 10017c70 size 95 */

void __cdecl FUN_10017c70(undefined4 *param_1,undefined4 param_2,int param_3)

{
  (*DAT_1006c1d0)(param_1,2,param_1[0xa0],0x3f800000,0x3f800000,0);
  DAT_1006c3f8 = DAT_1006c3f8 + 1;
  if (DAT_1006c3f8 == DAT_1006c3f4) {
    (*DAT_1006c1d8)(1,&DAT_1004a49c);
  }
  FUN_1001ae20((uint)param_1,param_3);
  FUN_1001b400(param_1);
  return;
}



/* FUN_10041042 @ 10041042 size 95 */

void __cdecl FUN_10041042(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (param_1 & 0x1f) * 0x24;
  iVar1 = (&DAT_1006ccc0)[(int)param_1 >> 5] + iVar2;
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_1003c8a1(0x11);
    if (*(int *)(iVar1 + 8) == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xc));
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    }
    FUN_1003c902(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((&DAT_1006ccc0)[(int)param_1 >> 5] + 0xc + iVar2));
  return;
}



/* FUN_10016850 @ 10016850 size 94 */

void __cdecl FUN_10016850(char *param_1)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0xffffffff;
  pcVar3 = param_1;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  uVar4 = ~uVar4;
  pcVar3 = (char *)(*DAT_1006c244)(uVar4,0x2fe);
  iVar5 = 0;
  if (0 < (int)uVar4) {
    do {
      if ((param_1[iVar5] == '\\') && (iVar5 < (int)(uVar4 - 1))) {
        iVar1 = iVar5 + 1;
        iVar5 = iVar5 + 1;
        if (param_1[iVar1] == 'n') {
          *pcVar3 = '\n';
        }
        else {
          *pcVar3 = '\\';
        }
      }
      else {
        *pcVar3 = param_1[iVar5];
      }
      pcVar3 = pcVar3 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)uVar4);
  }
  return;
}



/* ___add_12 @ 1004210c size 94 */

/* Library Function - Single Match
    ___add_12
   
   Library: Visual Studio 2003 Release */

void __cdecl ___add_12(uint *param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = FUN_100420eb(*param_1,*param_2,param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_100420eb(param_1[1],1,param_1 + 1);
    if (iVar1 != 0) {
      param_1[2] = param_1[2] + 1;
    }
  }
  iVar1 = FUN_100420eb(param_1[1],param_2[1],param_1 + 1);
  if (iVar1 != 0) {
    param_1[2] = param_1[2] + 1;
  }
  FUN_100420eb(param_1[2],param_2[2],param_1 + 2);
  return;
}



/* FUN_100071c0 @ 100071c0 size 93 */

void __cdecl FUN_100071c0(int param_1)

{
  if ((*(uint *)(param_1 + 0x108) & 0x400) == 0) {
    if (*(int *)(param_1 + 0x310) != 0) {
      (*DAT_1006c1d0)(param_1,10,*(int *)(param_1 + 0x310),0x3f800000,0x40400000,0);
    }
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x314);
  }
  *(undefined4 *)(param_1 + 0x330) = 3;
  FUN_10006b20(param_1,(float *)(param_1 + 0x2f8),FUN_10007170);
  return;
}



/* FUN_10007220 @ 10007220 size 93 */

void __cdecl FUN_10007220(int param_1)

{
  if ((*(uint *)(param_1 + 0x108) & 0x400) == 0) {
    if (*(int *)(param_1 + 0x310) != 0) {
      (*DAT_1006c1d0)(param_1,10,*(int *)(param_1 + 0x310),0x3f800000,0x40400000,0);
    }
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x314);
  }
  *(undefined4 *)(param_1 + 0x330) = 2;
  FUN_10006b20(param_1,(float *)(param_1 + 0x2e0),FUN_10007100);
  return;
}



/* FUN_1000a620 @ 1000a620 size 93 */

void __cdecl FUN_1000a620(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  *(undefined4 *)(param_1 + 0x264) = param_3;
  uVar1 = *(uint *)(param_1 + 0x11c);
  if ((uVar1 & 1) == 0) {
    if (*(int *)(param_1 + 0x144) != 0) {
      FUN_1000a4c0(param_1);
      return;
    }
    FUN_1000a300(param_1);
  }
  else if ((uVar1 & 2) != 0) {
    *(uint *)(param_1 + 0x11c) = uVar1 & 0xfffffffe;
    *(undefined4 *)(param_1 + 0x180) = 0;
    *(undefined4 *)(param_1 + 0x17c) = 0;
    *(undefined4 *)(param_1 + 0x178) = 0;
    *(undefined4 *)(param_1 + 0x1ec) = 0;
    return;
  }
  return;
}



/* FUN_10010200 @ 10010200 size 93 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10010200(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  uVar1 = (*DAT_1006c1e0)(s_models_objects_banner_tris_md2_1004924c);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar2 = _rand();
  uVar2 = uVar2 & 0x8000000f;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffff0) + 1;
  }
  *(uint *)(param_1 + 0x38) = uVar2;
  (*DAT_1006c208)(param_1);
  *(undefined1 **)(param_1 + 500) = &LAB_100101d0;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  return;
}



/* FUN_10012cc0 @ 10012cc0 size 93 */

uint __cdecl FUN_10012cc0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int local_38 [14];
  
  iVar2 = *(int *)(param_1 + 0xfc);
  if (iVar2 == 0) {
    iVar2 = 3;
  }
  piVar1 = (int *)(*DAT_1006c1f0)(local_38,param_1 + 4,param_1 + 0xbc,param_1 + 200,param_1 + 4,
                                  param_1,iVar2);
  piVar3 = local_38;
  for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = *piVar1;
    piVar1 = piVar1 + 1;
    piVar3 = piVar3 + 1;
  }
  return -(uint)(local_38[1] != 0) & DAT_1006c2c4;
}



/* FUN_10021af0 @ 10021af0 size 93 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10021af0(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_10001560(param_1,*(int *)(param_1 + 0x25c));
  if (iVar1 != 0) {
    uVar2 = _rand();
    if ((float)(uVar2 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044340) {
      *(undefined **)(param_1 + 0x358) = &DAT_1004ec38;
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined **)(param_1 + 0x358) = &DAT_1004ec78;
  return;
}



/* FUN_1003e6bf @ 1003e6bf size 93 */

undefined4 __cdecl FUN_1003e6bf(uint param_1)

{
  undefined4 uVar1;
  DWORD *pDVar2;
  
  if ((param_1 < DAT_1006cdc0) &&
     ((*(byte *)((&DAT_1006ccc0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_10041042(param_1);
    uVar1 = FUN_1003e71c(param_1);
    FUN_100410a1(param_1);
    return uVar1;
  }
  pDVar2 = FUN_1004058e();
  *pDVar2 = 9;
  pDVar2 = FUN_10040597();
  *pDVar2 = 0;
  return 0xffffffff;
}



/* FUN_100409e5 @ 100409e5 size 93 */

uint __cdecl FUN_100409e5(LPWSTR param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;
  
  InterlockedIncrement((LONG *)&DAT_1006cdd8);
  bVar2 = DAT_1006cdd4 != 0;
  if (bVar2) {
    InterlockedDecrement((LONG *)&DAT_1006cdd8);
    FUN_1003c8a1(0x13);
  }
  uVar1 = FUN_10040a42(param_1,param_2,param_3);
  if (bVar2) {
    FUN_1003c902(0x13);
  }
  else {
    InterlockedDecrement((LONG *)&DAT_1006cdd8);
  }
  return uVar1;
}



/* FUN_1002ae40 @ 1002ae40 size 92 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1002ae40(int param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  float10 fVar2;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  if ((*(int *)(param_1 + 0x268) == 0) && ((*(byte *)(param_1 + 0x108) & 3) == 0)) {
    return 0;
  }
  fVar2 = (float10)fcos((float10)param_2 * (float10)_DAT_100442b8);
  local_4 = 0;
  local_c = (float)(fVar2 * (float10)param_3);
  fVar2 = (float10)fsin((float10)param_2 * (float10)_DAT_100442b8);
  local_8 = (float)(fVar2 * (float10)param_3);
  uVar1 = FUN_1002a330(param_1,&local_c,1);
  return uVar1;
}



/* FUN_1003df62 @ 1003df62 size 92 */

undefined4 __cdecl FUN_1003df62(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if ((((byte)param_1[3] & 3) == 2) && ((param_1[3] & 0x108U) != 0)) {
    uVar3 = *param_1 - param_1[2];
    if (0 < (int)uVar3) {
      uVar1 = FUN_1003dd44(param_1[4],(char *)param_1[2],uVar3);
      if (uVar1 == uVar3) {
        if ((param_1[3] & 0x80U) != 0) {
          param_1[3] = param_1[3] & 0xfffffffd;
        }
      }
      else {
        param_1[3] = param_1[3] | 0x20;
        uVar2 = 0xffffffff;
      }
    }
  }
  param_1[1] = 0;
  *param_1 = param_1[2];
  return uVar2;
}



/* FUN_1003feee @ 1003feee size 92 */

int * __cdecl FUN_1003feee(undefined4 param_1,undefined4 param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  undefined4 in_stack_ffffffbc;
  undefined2 uVar4;
  short local_2c;
  char local_2a;
  uint local_28 [6];
  uint local_10;
  uint uStack_c;
  undefined2 uStack_8;
  
  uVar4 = (undefined2)((uint)in_stack_ffffffbc >> 0x10);
  FUN_1003ff4a(&local_10,&param_1);
  iVar3 = FUN_1004228c(local_10,uStack_c,CONCAT22(uVar4,uStack_8),0x11,0,&local_2c);
  puVar2 = param_4;
  piVar1 = param_3;
  param_3[2] = iVar3;
  *param_3 = (int)local_2a;
  param_3[1] = (int)local_2c;
  FUN_10040000(param_4,local_28);
  piVar1[3] = (int)puVar2;
  return piVar1;
}



/* FUN_10018f40 @ 10018f40 size 90 */

void __cdecl FUN_10018f40(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_100388c0((float *)(param_1 + 0x10),(float *)&DAT_10061c18);
  if (iVar1 == 0) {
    FUN_1001b0c0((float *)(param_1 + 0x10),(float *)(param_1 + 0x154));
  }
  *(undefined4 *)(param_1 + 0xf8) = 1;
  *(undefined4 *)(param_1 + 0x104) = 0;
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  *(undefined4 *)(param_1 + 0xb8) = 1;
  return;
}



/* FUN_1003a402 @ 1003a402 size 90 */

void __cdecl FUN_1003a402(char *param_1)

{
  char cVar1;
  char cVar2;
  undefined *this;
  uint uVar3;
  undefined *puVar4;
  
  this = (undefined *)(int)*param_1;
  uVar3 = FUN_1003eef3((uint)this);
  if (uVar3 != 0x65) {
    do {
      param_1 = param_1 + 1;
      if (DAT_1005fed4 < 2) {
        uVar3 = (byte)PTR_DAT_1005fcc8[*param_1 * 2] & 4;
        this = PTR_DAT_1005fcc8;
      }
      else {
        puVar4 = (undefined *)0x4;
        uVar3 = FUN_1003b258(this,(int)*param_1,4);
        this = puVar4;
      }
    } while (uVar3 != 0);
  }
  cVar2 = *param_1;
  *param_1 = DAT_1005fed8;
  do {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
    *param_1 = cVar2;
    cVar2 = cVar1;
  } while (*param_1 != '\0');
  return;
}



/* FUN_1003b0a7 @ 1003b0a7 size 90 */

undefined4 __cdecl FUN_1003b0a7(int param_1,uint param_2)

{
  undefined4 uStack_8;
  
  if (param_2 == 0x7ff00000) {
    if (param_1 == 0) {
      return 1;
    }
  }
  else if ((param_2 == 0xfff00000) && (param_1 == 0)) {
    return 2;
  }
  if ((param_2._2_2_ & 0x7ff8) == 0x7ff8) {
    uStack_8 = 3;
  }
  else {
    if (((param_2._2_2_ & 0x7ff8) != 0x7ff0) || (((param_2 & 0x7ffff) == 0 && (param_1 == 0)))) {
      return 0;
    }
    uStack_8 = 4;
  }
  return uStack_8;
}



/* FUN_10024ff0 @ 10024ff0 size 89 */

undefined4 __cdecl FUN_10024ff0(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x25c) != 0) && (0 < *(int *)(*(int *)(param_1 + 0x25c) + 0x220))) {
    bVar1 = FUN_10024ef0(param_1);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      *(undefined4 *)(param_1 + 0x3b8) = 3;
      return 1;
    }
    iVar2 = FUN_10024f10(param_1);
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 0x3b8) = 4;
      return 1;
    }
  }
  return 0;
}



/* FUN_1002b520 @ 1002b520 size 89 */

undefined4 __cdecl FUN_1002b520(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x25c) != 0) && (0 < *(int *)(*(int *)(param_1 + 0x25c) + 0x220))) {
    bVar1 = FUN_10024ef0(param_1);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      *(undefined4 *)(param_1 + 0x3b8) = 3;
      return 1;
    }
    iVar2 = FUN_1002b440(param_1);
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 0x3b8) = 4;
      return 1;
    }
  }
  return 0;
}



/* FUN_10040831 @ 10040831 size 89 */

int __cdecl FUN_10040831(LPSTR param_1,WCHAR param_2)

{
  int iVar1;
  bool bVar2;
  
  InterlockedIncrement((LONG *)&DAT_1006cdd8);
  bVar2 = DAT_1006cdd4 != 0;
  if (bVar2) {
    InterlockedDecrement((LONG *)&DAT_1006cdd8);
    FUN_1003c8a1(0x13);
  }
  iVar1 = FUN_1004088a(param_1,param_2);
  if (bVar2) {
    FUN_1003c902(0x13);
  }
  else {
    InterlockedDecrement((LONG *)&DAT_1006cdd8);
  }
  return iVar1;
}



/* FUN_10004d30 @ 10004d30 size 88 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10004d30(float param_1)

{
  if (_DAT_1004414c <= DAT_1006c2e4 - *(float *)(*(int *)((int)param_1 + 0x54) + 0xf00)) {
    *(uint *)((int)param_1 + 0x108) = *(uint *)((int)param_1 + 0x108) & 0xffffffef;
    *(undefined4 *)((int)param_1 + 0x220) = 0;
    DAT_1006c104 = 0x17;
    FUN_10030160(param_1,(int)param_1,(int)param_1,100000);
  }
  return;
}



/* FUN_10018340 @ 10018340 size 88 */

void __cdecl FUN_10018340(int param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x254);
  iVar2 = *(int *)(param_1 + 0x294);
  lVar1 = __ftol();
  FUN_1001cad0(param_1,(float *)(param_1 + 4),(float *)(param_1 + 0x154),*(int *)(param_1 + 0x244),
               (int)lVar1,iVar2,iVar3);
  (*DAT_1006c1d0)(param_1,2,*(undefined4 *)(param_1 + 0x280),0x3f800000,0x3f800000,0);
  return;
}



/* FUN_1002ad60 @ 1002ad60 size 88 */

undefined4 __cdecl FUN_1002ad60(int param_1,int param_2,float param_3)

{
  float *pfVar1;
  int iVar2;
  float *pfVar3;
  
  iVar2 = 0;
  pfVar3 = (float *)(param_1 + 0xd4);
  pfVar1 = (float *)(param_2 + 0xe0);
  while( true ) {
    if (param_3 + *(float *)((param_1 - param_2) + (int)pfVar1) < pfVar1[-3]) {
      return 0;
    }
    if (*pfVar1 < *pfVar3 - param_3) break;
    iVar2 = iVar2 + 1;
    pfVar1 = pfVar1 + 1;
    pfVar3 = pfVar3 + 1;
    if (2 < iVar2) {
      return 1;
    }
  }
  return 0;
}



/* _memset @ 100400f0 size 88 */

/* Library Function - Single Match
    _memset
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  size_t sVar3;
  uint *puVar4;
  
  if (_Size == 0) {
    return _Dst;
  }
  uVar1 = _Val & 0xff;
  puVar4 = _Dst;
  if (3 < _Size) {
    uVar2 = -(int)_Dst & 3;
    sVar3 = _Size;
    if (uVar2 != 0) {
      sVar3 = _Size - uVar2;
      do {
        *(undefined1 *)puVar4 = (undefined1)_Val;
        puVar4 = (uint *)((int)puVar4 + 1);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar1 = uVar1 * 0x1010101;
    _Size = sVar3 & 3;
    uVar2 = sVar3 >> 2;
    if (uVar2 != 0) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      }
      if (_Size == 0) {
        return _Dst;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    _Size = _Size - 1;
  } while (_Size != 0);
  return _Dst;
}



/* FUN_100430b0 @ 100430b0 size 88 */

int __cdecl FUN_100430b0(uchar *param_1,size_t param_2)

{
  uchar *_Str2;
  int iVar1;
  int *piVar2;
  
  _Str2 = (uchar *)*DAT_10061dfc;
  piVar2 = DAT_10061dfc;
  while( true ) {
    if (_Str2 == (uchar *)0x0) {
      return -((int)piVar2 - (int)DAT_10061dfc >> 2);
    }
    iVar1 = __mbsnbicoll(param_1,_Str2,param_2);
    if ((iVar1 == 0) &&
       ((*(char *)(*piVar2 + param_2) == '=' || (*(char *)(*piVar2 + param_2) == '\0')))) break;
    _Str2 = (uchar *)piVar2[1];
    piVar2 = piVar2 + 1;
  }
  return (int)piVar2 - (int)DAT_10061dfc >> 2;
}



/* FUN_1002d660 @ 1002d660 size 87 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1002d660(int param_1)

{
  uint uVar1;
  
  if ((*(byte *)(param_1 + 0x35c) & 1) != 0) {
    *(undefined **)(param_1 + 0x358) = &DAT_1005ca00;
    return;
  }
  uVar1 = _rand();
  if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044198) {
    *(undefined **)(param_1 + 0x358) = &DAT_1005cb10;
    return;
  }
  *(undefined **)(param_1 + 0x358) = &DAT_1005cb68;
  return;
}



/* FUN_10030650 @ 10030650 size 87 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10030650(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x220) = *(undefined4 *)(iVar1 + 0x2d4);
  *(undefined4 *)(param_1 + 0x224) = *(undefined4 *)(iVar1 + 0x2d8);
  *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) | *(uint *)(iVar1 + 0x2dc);
  if (*(float *)(DAT_1006c42c + 0x14) != _DAT_1004410c) {
    *(undefined4 *)(iVar1 + 0xda8) = *(undefined4 *)(iVar1 + 0x720);
  }
  return;
}



/* FUN_10039d65 @ 10039d65 size 87 */

float10 __thiscall FUN_10039d65(undefined *param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  byte *this;
  undefined *puVar3;
  uint local_1c [6];
  
  while( true ) {
    if (DAT_1005fed4 < 2) {
      uVar1 = (byte)PTR_DAT_1005fcc8[(uint)*param_2 * 2] & 8;
      param_1 = PTR_DAT_1005fcc8;
    }
    else {
      puVar3 = (undefined *)0x8;
      uVar1 = FUN_1003b258(param_1,(uint)*param_2,8);
      param_1 = puVar3;
    }
    if (uVar1 == 0) break;
    param_2 = param_2 + 1;
  }
  this = param_2;
  _strlen((char *)param_2);
  iVar2 = FUN_1003ea02(this,local_1c,param_2);
  return (float10)*(double *)(iVar2 + 0x10);
}



/* FUN_10027220 @ 10027220 size 86 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10027220(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_100014e0(param_1,*(int *)(param_1 + 0x25c));
  if (iVar1 != 0) {
    uVar2 = _rand();
    if ((float)(uVar2 & 0x7fff) * _DAT_10044108 <= (float)_DAT_10044140) {
      *(undefined **)(param_1 + 0x358) = &DAT_10055bc8;
      return;
    }
  }
  *(undefined **)(param_1 + 0x358) = &DAT_100559e0;
  return;
}



/* FUN_1002e030 @ 1002e030 size 86 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1002e030(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_10001560(param_1,*(int *)(param_1 + 0x25c));
  if (iVar1 != 0) {
    uVar2 = _rand();
    if ((float)(uVar2 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044340) {
      *(undefined **)(param_1 + 0x358) = &DAT_1005dcf8;
      return;
    }
  }
  *(undefined **)(param_1 + 0x358) = &DAT_1005ddb0;
  return;
}



/* FUN_1003b202 @ 1003b202 size 86 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1003b202(void)

{
  return;
}



/* FUN_1003fad4 @ 1003fad4 size 86 */

void __cdecl FUN_1003fad4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  puVar3 = (uint *)(param_1 + (param_2 / 0x20) * 4);
  iVar1 = FUN_100420eb(*puVar3,1 << (0x1fU - (char)(param_2 % 0x20) & 0x1f),puVar3);
  iVar2 = param_2 / 0x20 + -1;
  if (-1 < iVar2) {
    puVar3 = (uint *)(param_1 + iVar2 * 4);
    do {
      if (iVar1 == 0) {
        return;
      }
      iVar1 = FUN_100420eb(*puVar3,1,puVar3);
      iVar2 = iVar2 + -1;
      puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
  }
  return;
}



/* FUN_1003a623 @ 1003a623 size 85 */

char * __cdecl FUN_1003a623(undefined8 *param_1,char *param_2,size_t param_3)

{
  uint local_2c [6];
  int local_14;
  int local_10;
  
  FUN_1003feee((int)*param_1,(int)((ulonglong)*param_1 >> 0x20),&local_14,local_2c);
  FUN_1003fe77(param_2 + (local_14 == 0x2d),local_10 + param_3,(int)&local_14);
  FUN_1003a678(param_2,param_3,&local_14,'\0');
  return param_2;
}



/* FUN_1002cb80 @ 1002cb80 size 84 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1002cb80(int param_1)

{
  uint uVar1;
  
  if (3 < *(int *)(param_1 + 0x3c)) {
    *(undefined **)(param_1 + 0x358) = &DAT_1005bb18;
    return;
  }
  uVar1 = _rand();
  if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044140) {
    *(undefined **)(param_1 + 0x358) = &DAT_1005b958;
    return;
  }
  *(undefined **)(param_1 + 0x358) = &DAT_1005ba40;
  return;
}



/* FUN_1003a828 @ 1003a828 size 84 */

undefined4 FUN_1003a828(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  FUN_1003c80c();
  DAT_1005fbac = TlsAlloc();
  if (DAT_1005fbac != 0xffffffff) {
    lpTlsValue = (DWORD *)FUN_1004048e(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(DAT_1005fbac,lpTlsValue);
      if (BVar1 != 0) {
        FUN_1003a89a((int)lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        return 1;
      }
    }
  }
  return 0;
}



/* FUN_1003a9b4 @ 1003a9b4 size 84 */

float10 __cdecl FUN_1003a9b4(int param_1,double param_2)

{
  DWORD *pDVar1;
  float10 fVar2;
  
  if (DAT_10060720 == 0) {
    fVar2 = FUN_1003af6a(1,param_1);
    return fVar2;
  }
  pDVar1 = FUN_1004058e();
  *pDVar1 = 0x21;
  FUN_1003b1df();
  return (float10)param_2;
}



/* FUN_1003f307 @ 1003f307 size 84 */

void FUN_1003f307(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar1;
  uint uVar2;
  
  puVar1 = &DAT_1006ccc0;
  do {
    uVar2 = *puVar1;
    if (uVar2 != 0) {
      if (uVar2 < uVar2 + 0x480) {
        lpCriticalSection = (LPCRITICAL_SECTION)(uVar2 + 0xc);
        do {
          if (lpCriticalSection[-1].SpinCount != 0) {
            DeleteCriticalSection(lpCriticalSection);
          }
          uVar2 = uVar2 + 0x24;
          lpCriticalSection = (LPCRITICAL_SECTION)&lpCriticalSection[1].OwningThread;
        } while (uVar2 < *puVar1 + 0x480);
      }
      FUN_100396e7((LPVOID)*puVar1);
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x1006cdc0);
  return;
}



/* FUN_100182e0 @ 100182e0 size 83 */

void __cdecl FUN_100182e0(int param_1)

{
  undefined4 uVar1;
  
  *(code **)(param_1 + 0x200) = FUN_100182a0;
  FUN_1001b0c0((float *)(param_1 + 0x10),(float *)(param_1 + 0x154));
  uVar1 = (*DAT_1006c1e4)(s_weapons_railgf1a_wav_1004b9ec);
  *(undefined4 *)(param_1 + 0x280) = uVar1;
  if (*(int *)(param_1 + 0x244) == 0) {
    *(undefined4 *)(param_1 + 0x244) = 0x96;
  }
  *(undefined4 *)(param_1 + 0xb8) = 1;
  return;
}



/* FUN_1001ef10 @ 1001ef10 size 83 */

void __cdecl FUN_1001ef10(int param_1)

{
  if ((*(float *)(param_1 + 0x210) <= DAT_1006c2e4) || (*(int *)(param_1 + 0x25c) != 0)) {
    if ((*(byte *)(param_1 + 0x35c) & 1) == 0) {
      *(undefined **)(param_1 + 0x358) = &DAT_1004c408;
      return;
    }
  }
  else if (*(int *)(param_1 + 0x1e0) != 0) {
    FUN_1001ef00(param_1);
    return;
  }
  FUN_1001eeb0(param_1);
  return;
}



/* FUN_1000b210 @ 1000b210 size 82 */

void __cdecl FUN_1000b210(int param_1,float param_2)

{
  float fVar1;
  
  *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) | 0x80000000;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  fVar1 = DAT_1006c2e4 + param_2;
  *(code **)(param_1 + 500) = FUN_1000b1a0;
  *(float *)(param_1 + 0x1ec) = fVar1;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_1000c5f0 @ 1000c5f0 size 82 */

void __cdecl FUN_1000c5f0(int param_1,int *param_2)

{
  if (((*(uint *)(param_1 + 0x108) & 0x1000) != 0) &&
     (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(param_2 + -0x4011a4a) / 0x48) * 4) == 1)) {
    FUN_1000c4b0(param_1);
  }
  FUN_1000b3c0(param_1,param_2);
  return;
}



/* FUN_10012df0 @ 10012df0 size 82 */

void __cdecl FUN_10012df0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x34);
  if ((*(code **)(param_1 + 0x1fc) != (code *)0x0) && (*(int *)(param_1 + 0xf8) != 0)) {
    (**(code **)(param_1 + 0x1fc))(param_1,iVar1,param_2 + 0x18,*(undefined4 *)(param_2 + 0x2c));
  }
  if ((*(code **)(iVar1 + 0x1fc) != (code *)0x0) && (*(int *)(iVar1 + 0xf8) != 0)) {
    (**(code **)(iVar1 + 0x1fc))(iVar1,param_1,0,0);
  }
  return;
}



/* FUN_1001beb0 @ 1001beb0 size 82 */

void __cdecl
FUN_1001beb0(int param_1,float *param_2,float *param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,uint param_9)

{
  if (0 < param_8) {
    do {
      FUN_1001b8c0(param_1,param_2,param_3,param_4,param_5,4,param_6,param_7,param_9);
      param_8 = param_8 + -1;
    } while (param_8 != 0);
  }
  return;
}



/* FUN_10039541 @ 10039541 size 82 */

int __cdecl FUN_10039541(undefined1 *param_1,byte *param_2)

{
  int iVar1;
  undefined1 *local_24;
  int local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  
  local_1c = param_1;
  local_24 = param_1;
  local_18 = 0x42;
  local_20 = 0x7fffffff;
  iVar1 = FUN_1003b41c((int *)&local_24,param_2,(undefined4 *)&stack0x0000000c);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_1003b304(0,(int *)&local_24);
  }
  else {
    *local_24 = 0;
  }
  return iVar1;
}



/* FUN_10009090 @ 10009090 size 81 */

void __cdecl FUN_10009090(int param_1)

{
  if ((*(uint *)(param_1 + 0x108) & 0x400) == 0) {
    if (*(int *)(param_1 + 0x318) != 0) {
      (*DAT_1006c1d0)(param_1,10,*(int *)(param_1 + 0x318),0x3f800000,0x40400000,0);
    }
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  *(undefined4 *)(param_1 + 0x330) = 1;
  FUN_10008f90(param_1,0);
  return;
}



/* FUN_1000a9a0 @ 1000a9a0 size 81 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1000a9a0(uint param_1)

{
  float fVar1;
  uint uVar2;
  
  FUN_1001ae20(param_1,*(int *)(param_1 + 0x264));
  uVar2 = _rand();
  fVar1 = (float)(uVar2 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  *(float *)(param_1 + 0x1ec) =
       DAT_1006c2e4 + *(float *)(param_1 + 0x290) + (fVar1 + fVar1) * *(float *)(param_1 + 0x29c);
  return;
}



/* FUN_10012d20 @ 10012d20 size 81 */

void __cdecl FUN_10012d20(int param_1)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 3;
  pfVar1 = (float *)(param_1 + 0x178);
  iVar2 = DAT_1006c184;
  do {
    if (*pfVar1 <= *(float *)(iVar2 + 0x14)) {
      if (*pfVar1 < -*(float *)(iVar2 + 0x14)) {
        *pfVar1 = -*(float *)(iVar2 + 0x14);
        iVar2 = DAT_1006c184;
      }
    }
    else {
      *pfVar1 = *(float *)(iVar2 + 0x14);
      iVar2 = DAT_1006c184;
    }
    pfVar1 = pfVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}



/* FUN_10018180 @ 10018180 size 81 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10018180(int param_1)

{
  float *pfVar1;
  bool bVar2;
  
  bVar2 = *(float *)(param_1 + 0x148) != _DAT_1004410c;
  *(undefined1 **)(param_1 + 0x200) = &LAB_100180e0;
  *(undefined4 *)(param_1 + 0xb8) = 1;
  if (bVar2) {
    pfVar1 = (float *)(param_1 + 0x154);
    FUN_1001b0c0((float *)(param_1 + 0x10),pfVar1);
    FUN_10038a20(pfVar1,*(float *)(param_1 + 0x148),pfVar1);
  }
  return;
}



/* FUN_1001aba0 @ 1001aba0 size 81 */

void __cdecl
FUN_1001aba0(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  *param_5 = *param_2 * *param_3 + *param_4 * param_2[1] + *param_1;
  param_5[1] = param_4[1] * param_2[1] + param_3[1] * *param_2 + param_1[1];
  param_5[2] = param_4[2] * param_2[1] + param_3[2] * *param_2 + param_1[2] + param_2[2];
  return;
}



/* FUN_10039696 @ 10039696 size 81 */

int __cdecl FUN_10039696(undefined1 *param_1,byte *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 *local_24;
  int local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  
  local_1c = param_1;
  local_24 = param_1;
  local_18 = 0x42;
  local_20 = 0x7fffffff;
  iVar1 = FUN_1003b41c((int *)&local_24,param_2,param_3);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_1003b304(0,(int *)&local_24);
  }
  else {
    *local_24 = 0;
  }
  return iVar1;
}



/* __cfltcvt @ 1003a7b2 size 81 */

/* Library Function - Single Match
    __cfltcvt
   
   Library: Visual Studio 2003 Release */

errno_t __cdecl
__cfltcvt(double *arg,char *buffer,size_t sizeInBytes,int format,int precision,int caps)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  if ((sizeInBytes == 0x65) || (sizeInBytes == 0x45)) {
    puVar2 = FUN_1003a500(arg,buffer,format,precision);
  }
  else {
    if (sizeInBytes == 0x66) {
      pcVar1 = FUN_1003a623(arg,buffer,format);
      return (errno_t)pcVar1;
    }
    puVar2 = (undefined1 *)FUN_1003a71f(arg,buffer,format,precision);
  }
  return (errno_t)puVar2;
}



/* FUN_10034a40 @ 10034a40 size 80 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10034a40(int param_1)

{
  longlong lVar1;
  
  if (((*(int *)(param_1 + 0x50) == 0) && (*(int *)(param_1 + 0x268) != 0)) &&
     (_DAT_10044434 < _DAT_10062080)) {
    lVar1 = __ftol();
    if ((int)lVar1 != DAT_10062088) {
      *(undefined4 *)(param_1 + 0x50) = 2;
    }
  }
  return;
}



/* FUN_100145c0 @ 100145c0 size 78 */

void __cdecl FUN_100145c0(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x100) + 0x54) + 0xf10) = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x54);
  *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(iVar1 + 0xf28);
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x100) + 0x54) + 0xf28) = 0;
  FUN_10002de0(*(int *)(param_1 + 0x100));
  return;
}



/* FUN_100181e0 @ 100181e0 size 78 */

void __cdecl FUN_100181e0(int param_1)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0x21;
  uVar2 = 8;
  lVar1 = __ftol();
  FUN_1001c000(param_1,(float *)(param_1 + 4),(float *)(param_1 + 0x154),*(int *)(param_1 + 0x244),
               (int)lVar1,uVar2,iVar3);
  (*DAT_1006c1d0)(param_1,2,*(undefined4 *)(param_1 + 0x280),0x3f800000,0x3f800000,0);
  return;
}



/* FUN_1001b070 @ 1001b070 size 78 */

undefined * FUN_1001b070(void)

{
  int iVar1;
  
  iVar1 = DAT_10060fe0 * 0x20;
  DAT_10060fe0 = DAT_10060fe0 + 1 & 7;
  __ftol();
  __ftol();
  __ftol();
  FUN_10038b40();
  return &DAT_10060ee0 + iVar1;
}



/* FUN_1002c2d0 @ 1002c2d0 size 78 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1002c2d0(int param_1)

{
  uint uVar1;
  
  if (*(undefined **)(param_1 + 0x358) != &DAT_1005b330) {
    uVar1 = _rand();
    if ((float)_DAT_10044368 <= (float)(uVar1 & 0x7fff) * _DAT_10044108) {
      *(undefined **)(param_1 + 0x358) = &DAT_1005b330;
      return;
    }
  }
  *(undefined **)(param_1 + 0x358) = &DAT_1005b148;
  return;
}



/* FUN_10038900 @ 10038900 size 78 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10038900(float *param_1)

{
  float fVar1;
  
  fVar1 = SQRT(param_1[2] * param_1[2] + param_1[1] * param_1[1] + *param_1 * *param_1);
  if (fVar1 != _DAT_1004410c) {
    fVar1 = _DAT_10044104 / fVar1;
    *param_1 = fVar1 * *param_1;
    param_1[1] = fVar1 * param_1[1];
    param_1[2] = fVar1 * param_1[2];
  }
  return;
}



/* FUN_100394c7 @ 100394c7 size 78 */

void __cdecl FUN_100394c7(undefined1 *param_1,undefined1 *param_2,int param_3,undefined *param_4)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  for (; puVar2 = param_1, puVar3 = param_1, param_1 < param_2; param_2 = param_2 + -param_3) {
    while (puVar3 = puVar3 + param_3, puVar3 <= param_2) {
      iVar1 = (*(code *)param_4)(puVar3,puVar2);
      if (0 < iVar1) {
        puVar2 = puVar3;
      }
    }
    FUN_10039515(puVar2,param_2,param_3);
  }
  return;
}



/* FUN_10040c0b @ 10040c0b size 78 */

int * __cdecl FUN_10040c0b(uint *param_1)

{
  int *piVar1;
  
  if (param_1 <= DAT_1005ffc4) {
    FUN_1003c8a1(9);
    piVar1 = FUN_1003ccab(param_1);
    FUN_1003c902(9);
    if (piVar1 != (int *)0x0) {
      return piVar1;
    }
  }
  if (param_1 == (uint *)0x0) {
    param_1 = (uint *)0x1;
  }
  piVar1 = HeapAlloc(DAT_1006ddfc,0,(int)param_1 + 0xfU & 0xfffffff0);
  return piVar1;
}



/* FUN_10033120 @ 10033120 size 77 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10033120(void)

{
  int *piVar1;
  undefined4 *puVar2;
  
  if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
    puVar2 = &DAT_100620a0;
    do {
      piVar1 = FUN_1001b350();
      *puVar2 = piVar1;
      puVar2 = puVar2 + 1;
      piVar1[0x46] = (int)s_player_trail_1005f630;
    } while ((int)puVar2 < 0x100620c0);
    DAT_100620c0 = 0;
    DAT_1006138c = 1;
  }
  return;
}



/* __fclose_lk @ 10039cd5 size 76 */

/* Library Function - Single Match
    __fclose_lk
   
   Library: Visual Studio 2003 Release */

undefined4 __cdecl __fclose_lk(FILE *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1->_flag & 0x83) != 0) {
    uVar2 = FUN_1003df62((int *)param_1);
    __freebuf(param_1);
    iVar1 = FUN_1003e6bf(param_1->_file);
    if (iVar1 < 0) {
      uVar2 = 0xffffffff;
    }
    else if (param_1->_tmpfname != (char *)0x0) {
      FUN_100396e7(param_1->_tmpfname);
      param_1->_tmpfname = (char *)0x0;
    }
  }
  param_1->_flag = 0;
  return uVar2;
}



/* FUN_10019f40 @ 10019f40 size 75 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_10019f40(float param_1)

{
  longlong lVar1;
  
  if ((float)_DAT_10044268 < param_1 * (float)_DAT_10044270) {
    lVar1 = __ftol();
    return (float10)(int)lVar1 * (float10)_DAT_10044260;
  }
  lVar1 = __ftol();
  return (float10)(int)lVar1 * (float10)_DAT_10044260;
}



/* FUN_10028e90 @ 10028e90 size 75 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10028e90(int param_1)

{
  uint uVar1;
  
  if ((*(byte *)(param_1 + 0x35c) & 1) == 0) {
    uVar1 = _rand();
    if ((float)(uVar1 & 0x7fff) * _DAT_10044108 <= (float)_DAT_10044128) {
      *(undefined **)(param_1 + 0x358) = &DAT_10058928;
      return;
    }
    *(undefined **)(param_1 + 0x358) = &DAT_10058818;
  }
  return;
}



/* FUN_10002f20 @ 10002f20 size 74 */

void __cdecl FUN_10002f20(int param_1,int param_2)

{
  if (*(int *)(*(int *)(param_1 + 0x54) + 0xf18) == param_2) {
    FUN_10002de0(param_1);
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xf18) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x58) =
         *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xf28);
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xf0c) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xf10) = 0;
  }
  return;
}



/* FUN_1000c460 @ 1000c460 size 74 */

bool __cdecl FUN_1000c460(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x54);
  if (iVar1 == 0) {
    return false;
  }
  if ((*(uint *)(param_1 + 0x108) & 0x1000) == 0) {
    return false;
  }
  if (0 < *(int *)(iVar1 + 0x2e4 + DAT_10060e64 * 4)) {
    return true;
  }
  return 0 < *(int *)(iVar1 + 0x2e4 + DAT_10060e6c * 4);
}



/* FUN_10010090 @ 10010090 size 74 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10010090(int param_1)

{
  undefined4 uVar1;
  
  *(code **)(param_1 + 500) = FUN_10010030;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  uVar1 = (*DAT_1006c1e4)(s_tank_pain_wav_1004939c,0x3f800000,0x3f800000,0);
  (*DAT_1006c1d0)(param_1,4,uVar1);
  return;
}



/* FUN_10012c40 @ 10012c40 size 74 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10012c40(int param_1)

{
  if (*(float *)(param_1 + 0x1e4) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x1e4) = 0x41200000;
  }
  *(undefined4 *)(param_1 + 0x23c) = 10;
  FUN_10012750(param_1);
  if ((*(byte *)(param_1 + 0x11c) & 2) != 0) {
    FUN_10012530(param_1);
  }
  return;
}



/* FUN_10013b00 @ 10013b00 size 74 */

void __cdecl FUN_10013b00(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_10012d80(param_1);
  if (iVar1 != 0) {
    FUN_10038950((float *)(param_1 + 0x10),0.1,(float *)(param_1 + 0x184),(float *)(param_1 + 0x10))
    ;
    FUN_10038950((float *)(param_1 + 4),0.1,(float *)(param_1 + 0x178),(float *)(param_1 + 4));
    (*DAT_1006c208)(param_1);
  }
  return;
}



/* FUN_10041e1b @ 10041e1b size 74 */

int __cdecl FUN_10041e1b(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_10061f9c = 1;
                    /* WARNING: Could not recover jumptable at 0x10041e35. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_10061f9c = 1;
                    /* WARNING: Could not recover jumptable at 0x10041e4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_10061dc8;
  }
  DAT_10061f9c = (uint)bVar2;
  return param_1;
}



/* FUN_1003fa8b @ 1003fa8b size 73 */

undefined4 __cdecl FUN_1003fa8b(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + (param_2 / 0x20) * 4) & ~(-1 << (0x1fU - (char)(param_2 % 0x20) & 0x1f)))
      != 0) {
    return 0;
  }
  iVar2 = param_2 / 0x20 + 1;
  if (iVar2 < 3) {
    piVar1 = (int *)(param_1 + iVar2 * 4);
    do {
      if (*piVar1 != 0) {
        return 0;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 3);
  }
  return 1;
}



/* FUN_1000b3c0 @ 1000b3c0 size 72 */

void __cdecl FUN_1000b3c0(int param_1,int *param_2)

{
  FUN_1000c850(param_1,param_2);
  *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(param_2 + -0x4011a4a) / 0x48) * 4) =
       *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(param_2 + -0x4011a4a) / 0x48) * 4) + -1;
  FUN_10003ef0(param_1);
  return;
}



/* FUN_100396e7 @ 100396e7 size 72 */

void __cdecl FUN_100396e7(LPVOID param_1)

{
  uint *puVar1;
  
  if (param_1 != (LPVOID)0x0) {
    FUN_1003c8a1(9);
    puVar1 = (uint *)FUN_1003c955((int)param_1);
    if (puVar1 != (uint *)0x0) {
      FUN_1003c980(puVar1,(uint)param_1);
      FUN_1003c902(9);
      return;
    }
    FUN_1003c902(9);
    HeapFree(DAT_1006ddfc,0,param_1);
  }
  return;
}



/* FUN_1000c290 @ 1000c290 size 71 */

uint __cdecl FUN_1000c290(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x54);
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = DAT_10060e74;
  if ((*(int *)(iVar1 + 0x2e4 + DAT_10060e74 * 4) < 1) &&
     (uVar2 = DAT_10060e70, *(int *)(iVar1 + 0x2e4 + DAT_10060e70 * 4) < 1)) {
    uVar2 = DAT_10060e78 & (*(int *)(iVar1 + 0x2e4 + DAT_10060e78 * 4) < 1) - 1;
  }
  return uVar2;
}



/* FUN_10011c00 @ 10011c00 size 71 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_10011c00(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x2a8) == 0) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x4000;
    uVar1 = (*DAT_1006c1e4)(s_infantry_inflies1_wav_100496a4);
    *(undefined4 *)(param_1 + 0x4c) = uVar1;
    *(undefined1 **)(param_1 + 500) = &LAB_10011c50;
    *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + _DAT_100441c0;
  }
  return;
}



/* FUN_10007170 @ 10007170 size 70 */

void __cdecl FUN_10007170(int param_1)

{
  if ((*(uint *)(param_1 + 0x108) & 0x400) == 0) {
    if (*(int *)(param_1 + 0x318) != 0) {
      (*DAT_1006c1d0)(param_1,10,*(int *)(param_1 + 0x318),0x3f800000,0x40400000,0);
    }
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  *(undefined4 *)(param_1 + 0x330) = 1;
  return;
}



/* FUN_1001fa00 @ 1001fa00 size 70 */

void __cdecl FUN_1001fa00(int param_1)

{
  if (*(undefined **)(param_1 + 0x358) == &DAT_1004cb18) {
    *(undefined **)(param_1 + 0x358) = &DAT_1004c8f0;
  }
  else {
    FUN_10020370(param_1);
  }
  (*DAT_1006c1d0)(param_1,2,DAT_10060ff4,0x3f800000,0x3f800000,0);
  return;
}



/* FUN_100332d0 @ 100332d0 size 70 */

undefined4 __cdecl FUN_100332d0(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (DAT_1006138c == 0) {
    return 0;
  }
  iVar2 = 8;
  uVar1 = DAT_100620c0;
  do {
    if (*(float *)(param_1 + 0x3a8) < *(float *)((&DAT_100620a0)[uVar1] + 0x120)) break;
    uVar1 = uVar1 + 1 & 7;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return (&DAT_100620a0)[uVar1];
}



/* FUN_1000b150 @ 1000b150 size 69 */

undefined4 * __cdecl FUN_1000b150(byte *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar2 = &DAT_10046928;
  if (0 < DAT_1006ca54) {
    do {
      if (((void *)puVar2[10] != (void *)0x0) &&
         (iVar1 = FUN_10038b20((void *)puVar2[10],param_1), iVar1 == 0)) {
        return puVar2;
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 0x12;
    } while (iVar3 < DAT_1006ca54);
  }
  return (undefined4 *)0x0;
}



/* FUN_100163b0 @ 100163b0 size 69 */

void __cdecl FUN_100163b0(int *param_1)

{
  undefined **ppuVar1;
  undefined *puVar2;
  undefined **ppuVar3;
  
  FUN_10039b8d((char *)&DAT_1006c2e0,0x130,1,param_1);
  ppuVar3 = &PTR_s_changemap_10049e80;
  puVar2 = PTR_s_changemap_10049e80;
  while (puVar2 != (undefined *)0x0) {
    FUN_10015e00(param_1,(int)ppuVar3,0x1006c2e0);
    ppuVar1 = ppuVar3 + 4;
    ppuVar3 = ppuVar3 + 4;
    puVar2 = *ppuVar1;
  }
  return;
}



/* FUN_1000b100 @ 1000b100 size 68 */

undefined4 * __cdecl FUN_1000b100(byte *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar2 = &DAT_10046928;
  if (0 < DAT_1006ca54) {
    do {
      if (((void *)*puVar2 != (void *)0x0) &&
         (iVar1 = FUN_10038b20((void *)*puVar2,param_1), iVar1 == 0)) {
        return puVar2;
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 0x12;
    } while (iVar3 < DAT_1006ca54);
  }
  return (undefined4 *)0x0;
}



/* FUN_100407c4 @ 100407c4 size 68 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_100407c4(undefined4 *param_1)

{
  void *pvVar1;
  
  _DAT_10061da4 = _DAT_10061da4 + 1;
  pvVar1 = _malloc(0x1000);
  param_1[2] = pvVar1;
  if (pvVar1 == (void *)0x0) {
    param_1[3] = param_1[3] | 4;
    param_1[2] = param_1 + 5;
    param_1[6] = 2;
  }
  else {
    param_1[3] = param_1[3] | 8;
    param_1[6] = 0x1000;
  }
  param_1[1] = 0;
  *param_1 = param_1[2];
  return;
}



/* FUN_10015fd0 @ 10015fd0 size 67 */

void __cdecl FUN_10015fd0(int *param_1,char *param_2)

{
  undefined **ppuVar1;
  undefined *puVar2;
  undefined **ppuVar3;
  
  FUN_10039b8d(param_2,0xf34,1,param_1);
  ppuVar3 = &PTR_s_pers_weapon_10049ee0;
  puVar2 = PTR_s_pers_weapon_10049ee0;
  while (puVar2 != (undefined *)0x0) {
    FUN_10015e00(param_1,(int)ppuVar3,(int)param_2);
    ppuVar1 = ppuVar3 + 4;
    ppuVar3 = ppuVar3 + 4;
    puVar2 = *ppuVar1;
  }
  return;
}



/* FUN_10016360 @ 10016360 size 67 */

void __cdecl FUN_10016360(int *param_1,char *param_2)

{
  undefined **ppuVar1;
  undefined *puVar2;
  undefined **ppuVar3;
  
  FUN_10039b8d(param_2,0x3d0,1,param_1);
  ppuVar3 = &PTR_s_classname_100498e0;
  puVar2 = PTR_s_classname_100498e0;
  while (puVar2 != (undefined *)0x0) {
    FUN_10015e00(param_1,(int)ppuVar3,(int)param_2);
    ppuVar1 = ppuVar3 + 4;
    ppuVar3 = ppuVar3 + 4;
    puVar2 = *ppuVar1;
  }
  return;
}



/* FUN_1001eeb0 @ 1001eeb0 size 67 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl FUN_1001eeb0(int param_1)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  undefined4 in_EAX;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  *(undefined4 **)(param_1 + 0x358) = &DAT_1004c358;
  fVar3 = (float)_DAT_10044120;
  uVar5 = CONCAT22((short)((uint)in_EAX >> 0x10),
                   (ushort)(DAT_1006c2e4 < fVar3) << 8 |
                   (ushort)(NAN(DAT_1006c2e4) || NAN(fVar3)) << 10 |
                   (ushort)(DAT_1006c2e4 == fVar3) << 0xe);
  if (DAT_1006c2e4 < fVar3) {
    piVar1 = *(int **)(param_1 + 0x358);
    iVar2 = *piVar1;
    iVar4 = _rand();
    iVar6 = (piVar1[1] - iVar2) + 1;
    uVar5 = iVar4 / iVar6;
    *(int *)(param_1 + 0x38) = iVar4 % iVar6 + iVar2;
  }
  return uVar5;
}



/* FUN_10010fb0 @ 10010fb0 size 66 */

void __cdecl FUN_10010fb0(int param_1)

{
  *(undefined4 *)(param_1 + 0x264) = 0;
  if ((*(uint *)(param_1 + 0x11c) & 1) != 0) {
    *(undefined4 *)(param_1 + 0x220) = 0;
    *(float *)(param_1 + 0x290) = (float)*(int *)(param_1 + 0x254);
    return;
  }
  if ((*(uint *)(param_1 + 0x11c) & 2) != 0) {
    *(undefined4 *)(param_1 + 0x290) = 0;
    *(undefined4 *)(param_1 + 0x220) = *(undefined4 *)(param_1 + 0x254);
  }
  return;
}



/* FUN_10017b70 @ 10017b70 size 66 */

void __cdecl FUN_10017b70(undefined4 *param_1,undefined4 param_2,int param_3)

{
  (*DAT_1006c1d0)(param_1,2,param_1[0xa0],0x3f800000,0x3f800000,0);
  DAT_1006c3f0 = DAT_1006c3f0 + 1;
  FUN_1001ae20((uint)param_1,param_3);
  FUN_1001b400(param_1);
  return;
}



/* FUN_10018090 @ 10018090 size 66 */

void __cdecl FUN_10018090(int param_1)

{
  *(undefined1 **)(param_1 + 0x200) = &LAB_10018000;
  FUN_1001b0c0((float *)(param_1 + 0x10),(float *)(param_1 + 0x154));
  if (*(int *)(param_1 + 0x254) == 0) {
    *(undefined4 *)(param_1 + 0x254) = 0x20;
  }
  *(undefined4 *)(param_1 + 0xb8) = 1;
  return;
}



/* FUN_10041000 @ 10041000 size 66 */

undefined4 __cdecl FUN_10041000(uint param_1)

{
  DWORD *pDVar1;
  
  if ((param_1 < DAT_1006cdc0) &&
     ((*(byte *)((&DAT_1006ccc0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    return *(undefined4 *)((&DAT_1006ccc0)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x24);
  }
  pDVar1 = FUN_1004058e();
  *pDVar1 = 9;
  pDVar1 = FUN_10040597();
  *pDVar1 = 0;
  return 0xffffffff;
}



/* FUN_10008b80 @ 10008b80 size 65 */

void __cdecl FUN_10008b80(int param_1)

{
  *(undefined4 *)(param_1 + 0x330) = 3;
  FUN_10006b20(param_1,(float *)(param_1 + 0x2e0),&LAB_10008b60);
  *(undefined4 *)(param_1 + 0x38) = 0;
  if (*(int *)(param_1 + 0x220) != 0) {
    *(undefined4 *)(param_1 + 0x240) = 1;
  }
  return;
}



/* FUN_100123c0 @ 100123c0 size 65 */

void __cdecl FUN_100123c0(uint param_1)

{
  FUN_100122c0(param_1);
  if (*(int *)(param_1 + 0x5c) != *(int *)(param_1 + 0x3c4)) {
    *(int *)(param_1 + 0x3c4) = *(int *)(param_1 + 0x5c);
    FUN_10011c90(param_1);
  }
  FUN_10011d90(param_1);
  FUN_10011e50(param_1);
  FUN_10012230(param_1);
  return;
}



/* FUN_10002de0 @ 10002de0 size 64 */

void __cdecl FUN_10002de0(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x54) + 0xf14);
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xf14) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xf0c) = 0;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffe;
  (*DAT_1006c208)(param_1);
  FUN_1001b400(puVar1);
  return;
}



/* FUN_10015dc0 @ 10015dc0 size 64 */

void __cdecl FUN_10015dc0(int *param_1,int param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  
  if ((((*(byte *)(param_2 + 0xc) & 1) == 0) && (*(int *)(param_2 + 8) == 2)) &&
     (pcVar2 = *(char **)(*(int *)(param_2 + 4) + param_3), pcVar2 != (char *)0x0)) {
    uVar3 = 0xffffffff;
    pcVar4 = pcVar2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_10039a54(pcVar2,~uVar3,1,param_1);
  }
  return;
}



/* FUN_100182a0 @ 100182a0 size 64 */

void __cdecl FUN_100182a0(uint param_1)

{
  FUN_1001cf50(param_1,(float *)(param_1 + 4),(float *)(param_1 + 0x154),*(int *)(param_1 + 0x244),0
              );
  (*DAT_1006c1d0)(param_1,2,*(undefined4 *)(param_1 + 0x280),0x3f800000,0x3f800000,0);
  return;
}



/* FUN_10038880 @ 10038880 size 63 */

void __cdecl FUN_10038880(int param_1,float *param_2,int param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1 - (int)param_2;
  iVar2 = param_3 - (int)param_2;
  iVar4 = 3;
  do {
    fVar1 = *(float *)(iVar3 + (int)param_2);
    if (fVar1 < *param_2) {
      *param_2 = fVar1;
    }
    if (*(float *)(iVar2 + (int)param_2) < fVar1) {
      *(float *)(iVar2 + (int)param_2) = fVar1;
    }
    param_2 = param_2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}



/* __mbsnbicoll @ 1004270c size 63 */

/* Library Function - Single Match
    __mbsnbicoll
   
   Library: Visual Studio 2003 Release */

int __cdecl __mbsnbicoll(uchar *_Str1,uchar *_Str2,size_t _MaxCount)

{
  int iVar1;
  
  if (_MaxCount == 0) {
    return 0;
  }
  iVar1 = FUN_10042c81(DAT_1006cca4,1,_Str1,_MaxCount,_Str2,_MaxCount,DAT_1006ca74);
  if (iVar1 == 0) {
    return 0x7fffffff;
  }
  return iVar1 + -2;
}



/* FUN_10001f00 @ 10001f00 size 62 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10001f00(void)

{
  float10 fVar1;
  
  fVar1 = FUN_10038850();
  if (((float10)_DAT_10044138 < fVar1) && (fVar1 < (float10)_DAT_10044134)) {
    return 0;
  }
  return 1;
}



/* FUN_100142e0 @ 100142e0 size 62 */

void __cdecl FUN_100142e0(int param_1)

{
  int *piVar1;
  
  piVar1 = FUN_1001b350();
  FUN_100147d0((int)piVar1);
  piVar1[0x40] = param_1;
  piVar1[1] = *(int *)(param_1 + 4);
  piVar1[2] = *(int *)(param_1 + 8);
  piVar1[3] = *(int *)(param_1 + 0xc);
  piVar1[5] = *(int *)(param_1 + 0x14);
  *(int **)(*(int *)(param_1 + 0x54) + 0xf18) = piVar1;
  return;
}



/* FUN_1003a39b @ 1003a39b size 62 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1003a39b(void)

{
  if (_DAT_10044120 < _DAT_10044498 - (_DAT_10044498 / _DAT_100444a0) * _DAT_100444a0) {
    return 1;
  }
  return 0;
}



/* __fassign @ 1003a4c2 size 62 */

/* Library Function - Single Match
    __fassign
   
   Library: Visual Studio 2003 Release */

void __cdecl __fassign(int flag,char *argument,char *number)

{
  void *in_ECX;
  void *local_c;
  void *local_8;
  
  if (flag != 0) {
    local_c = in_ECX;
    local_8 = in_ECX;
    FUN_1003fe1d(in_ECX,(uint *)&local_c,(byte *)number);
    *(void **)argument = local_c;
    *(void **)(argument + 4) = local_8;
    return;
  }
  FUN_1003fe4a(in_ECX,(uint *)&number,(byte *)number);
  *(char **)argument = number;
  return;
}



/* FUN_1003c917 @ 1003c917 size 62 */

undefined4 FUN_1003c917(void)

{
  DAT_1006ddf8 = HeapAlloc(DAT_1006ddfc,0,0x140);
  if (DAT_1006ddf8 == (LPVOID)0x0) {
    return 0;
  }
  DAT_1006ddf0 = 0;
  DAT_1006ddf4 = 0;
  DAT_1006ddec = DAT_1006ddf8;
  DAT_1006dde4 = 0x10;
  return 1;
}



/* FUN_100419d0 @ 100419d0 size 62 */

int __cdecl FUN_100419d0(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    param_2 = param_2 + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  iVar2 = -1;
  do {
    iVar2 = iVar2 + 1;
    bVar1 = *param_1;
    if (bVar1 == 0) {
      return iVar2;
    }
    param_1 = param_1 + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return iVar2;
}



/* FUN_10018790 @ 10018790 size 61 */

void __cdecl FUN_10018790(uint param_1)

{
  if (*(int *)(param_1 + 0x264) == 0) {
    *(uint *)(param_1 + 0x264) = param_1;
  }
  *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) | 0x80000001;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffe;
  FUN_10018540(param_1);
  return;
}



/* FUN_1001a670 @ 1001a670 size 61 */

void __cdecl FUN_1001a670(int param_1)

{
  *(undefined4 *)(param_1 + 0xf8) = 3;
  *(undefined4 *)(param_1 + 0x104) = 2;
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  *(undefined1 **)(param_1 + 0x1f8) = &LAB_10019f90;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_1001b310 @ 1001b310 size 60 */

void __cdecl FUN_1001b310(int *param_1)

{
  param_1[0x16] = 1;
  param_1[0x46] = (int)s_noclass_1004be3c;
  param_1[0x66] = 0x3f800000;
  *param_1 = ((int)param_1 - DAT_1006c2c4) / 0x3d0;
  return;
}



/* FUN_10039ebe @ 10039ebe size 60 */

int __cdecl FUN_10039ebe(int *param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_1003dca0((uint)param_1);
  iVar1 = FUN_1003ea81(param_1);
  iVar2 = FUN_1003b41c(param_1,param_2,(undefined4 *)&stack0x0000000c);
  FUN_1003eb0e(iVar1,param_1);
  FUN_1003dcf2((uint)param_1);
  return iVar2;
}



/* FUN_1003c75b @ 1003c75b size 60 */

undefined4 __cdecl FUN_1003c75b(int param_1)

{
  int iVar1;
  
  DAT_1006ddfc = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_1006ddfc != (HANDLE)0x0) {
    iVar1 = FUN_1003c917();
    if (iVar1 != 0) {
      return 1;
    }
    HeapDestroy(DAT_1006ddfc);
  }
  return 0;
}



/* __startOneArgErrorHandling @ 1003eeb7 size 60 */

/* Library Function - Single Match
    __startOneArgErrorHandling
   
   Library: Visual Studio */

float10 __fastcall
__startOneArgErrorHandling
          (undefined4 param_1,uint param_2,ushort param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  float10 in_ST0;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  double local_c;
  
  local_c = (double)in_ST0;
  local_1c = param_5;
  local_18 = param_6;
  local_20 = param_1;
  FUN_100418f6(param_2,&local_24,&param_3);
  return (float10)local_c;
}



/* FUN_100389b0 @ 100389b0 size 59 */

void __cdecl FUN_100389b0(float *param_1,float *param_2,float *param_3)

{
  *param_3 = param_2[2] * param_1[1] - param_1[2] * param_2[1];
  param_3[1] = param_1[2] * *param_2 - *param_1 * param_2[2];
  param_3[2] = *param_1 * param_2[1] - *param_2 * param_1[1];
  return;
}



/* FUN_10002190 @ 10002190 size 58 */

void __cdecl FUN_10002190(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x1e8) = DAT_1006ca68;
  FUN_1002a850(param_1);
  iVar1 = FUN_10001f00();
  if (iVar1 != 0) {
    (**(code **)(param_1 + 900))(param_1);
    *(undefined4 *)(param_1 + 0x3b8) = 1;
  }
  return;
}



/* FUN_100021d0 @ 100021d0 size 58 */

void __cdecl FUN_100021d0(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x1e8) = DAT_1006ca68;
  FUN_1002a850(param_1);
  iVar1 = FUN_10001f00();
  if (iVar1 != 0) {
    (**(code **)(param_1 + 0x380))(param_1);
    *(undefined4 *)(param_1 + 0x3b8) = 1;
  }
  return;
}



/* FUN_1000f210 @ 1000f210 size 58 */

void __cdecl FUN_1000f210(int param_1)

{
  *(undefined4 *)(param_1 + 0xf8) = 3;
  *(undefined4 *)(param_1 + 0x200) = 0;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffe;
  FUN_1001b510(param_1);
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10010d20 @ 10010d20 size 58 */

void __cdecl FUN_10010d20(int param_1)

{
  *(undefined4 *)(param_1 + 0x104) = 2;
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  *(undefined4 *)(param_1 + 0xf8) = 3;
  *(undefined4 *)(param_1 + 0x38) = 0xc;
  (*DAT_1006c208)(param_1);
  return;
}



/* FUN_10041a10 @ 10041a10 size 58 */

byte * __cdecl FUN_10041a10(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte abStack_28 [32];
  
  abStack_28[0x1c] = 0;
  abStack_28[0x1d] = 0;
  abStack_28[0x1e] = 0;
  abStack_28[0x1f] = 0;
  abStack_28[0x18] = 0;
  abStack_28[0x19] = 0;
  abStack_28[0x1a] = 0;
  abStack_28[0x1b] = 0;
  abStack_28[0x14] = 0;
  abStack_28[0x15] = 0;
  abStack_28[0x16] = 0;
  abStack_28[0x17] = 0;
  abStack_28[0x10] = 0;
  abStack_28[0x11] = 0;
  abStack_28[0x12] = 0;
  abStack_28[0x13] = 0;
  abStack_28[0xc] = 0;
  abStack_28[0xd] = 0;
  abStack_28[0xe] = 0;
  abStack_28[0xf] = 0;
  abStack_28[8] = 0;
  abStack_28[9] = 0;
  abStack_28[10] = 0;
  abStack_28[0xb] = 0;
  abStack_28[4] = 0;
  abStack_28[5] = 0;
  abStack_28[6] = 0;
  abStack_28[7] = 0;
  abStack_28[0] = 0;
  abStack_28[1] = 0;
  abStack_28[2] = 0;
  abStack_28[3] = 0;
  while( true ) {
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    param_2 = param_2 + 1;
    abStack_28[(int)(uint)bVar1 >> 3] = abStack_28[(int)(uint)bVar1 >> 3] | '\x01' << (bVar1 & 7);
  }
  do {
    pbVar2 = param_1;
    bVar1 = *pbVar2;
    if (bVar1 == 0) {
      return (byte *)0x0;
    }
    param_1 = pbVar2 + 1;
  } while ((abStack_28[(int)(uint)bVar1 >> 3] >> (bVar1 & 7) & 1) == 0);
  return pbVar2;
}



/* FUN_1000ac00 @ 1000ac00 size 57 */

void __cdecl FUN_1000ac00(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_100388c0((float *)(param_1 + 4),(float *)&DAT_10061c18);
  if (iVar1 != 0) {
    FUN_10006b20(param_1,(float *)(param_1 + 0x160),&LAB_1000ac40);
    FUN_10008f90(param_1,1);
  }
  return;
}



/* FUN_1000d610 @ 1000d610 size 57 */

int * FUN_1000d610(void)

{
  int *piVar1;
  
  piVar1 = FUN_1001b350();
  piVar1[0x46] = (int)s_target_changelevel_1004915c;
  FUN_10038b40();
  piVar1[0x8e] = (int)&DAT_1006c368;
  return piVar1;
}



/* FUN_1000eda0 @ 1000eda0 size 57 */

void __cdecl FUN_1000eda0(int param_1)

{
  *(undefined4 *)(param_1 + 0xf8) = 3;
  *(undefined4 *)(param_1 + 0x200) = 0;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffe;
  FUN_1001b510(param_1);
  FUN_1000ed80(param_1);
  return;
}



/* FUN_1002f8b0 @ 1002f8b0 size 57 */

undefined4 __cdecl FUN_1002f8b0(int param_1)

{
  char cVar1;
  char *pcVar2;
  
  if (*(int *)(param_1 + 0x54) != 0) {
    pcVar2 = FUN_10038bb0((byte *)(*(int *)(param_1 + 0x54) + 0xbc),(byte *)s_gender_1005ed98);
    cVar1 = *pcVar2;
    if ((((cVar1 != 'f') && (cVar1 != 'F')) && (cVar1 != 'm')) && (cVar1 != 'M')) {
      return 1;
    }
  }
  return 0;
}



/* FUN_1003f799 @ 1003f799 size 57 */

void FUN_1003f799(void)

{
  if ((DAT_10061c54 == 1) || ((DAT_10061c54 == 0 && (DAT_10061c58 == 1)))) {
    FUN_1003f7d2(0xfc);
    if (DAT_10061f28 != (code *)0x0) {
      (*DAT_10061f28)();
    }
    FUN_1003f7d2(0xff);
  }
  return;
}



/* FUN_10005df0 @ 10005df0 size 56 */

void __cdecl FUN_10005df0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  (*DAT_1006c224)(3);
  (*DAT_1006c224)(param_1);
  (*DAT_1006c238)(param_2);
  (*DAT_1006c23c)(param_3);
  (*DAT_1006c218)(param_2,2);
  return;
}



/* FUN_100198c0 @ 100198c0 size 56 */

void __cdecl FUN_100198c0(int param_1)

{
  *(uint *)(param_1 + 0xf8) = (uint)(*(int *)(param_1 + 0xf8) == 0);
  (*DAT_1006c208)(param_1);
  if ((*(byte *)(param_1 + 0x11c) & 2) == 0) {
    *(undefined4 *)(param_1 + 0x200) = 0;
  }
  return;
}



/* FUN_10038f88 @ 10038f88 size 56 */

void FUN_10038f88(void)

{
  PTR___fptrap_1005fb98 = &LAB_1003a45c;
  PTR___fptrap_1005fb94 = __cfltcvt;
  PTR___fptrap_1005fb9c = __fassign;
  PTR___fptrap_1005fba0 = FUN_1003a402;
  PTR___fptrap_1005fba4 = &LAB_1003a4aa;
  PTR___fptrap_1005fba8 = __cfltcvt;
  return;
}



/* _strncmp @ 100397e0 size 56 */

/* Library Function - Single Match
    _strncmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char cVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar5 = 0;
  sVar3 = _MaxCount;
  pcVar6 = _Str1;
  if (_MaxCount != 0) {
    do {
      if (sVar3 == 0) break;
      sVar3 = sVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    iVar4 = _MaxCount - sVar3;
    do {
      pcVar6 = _Str2;
      pcVar7 = _Str1;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = _Str1 + 1;
      pcVar6 = _Str2 + 1;
      cVar2 = *_Str1;
      cVar1 = *_Str2;
      _Str2 = pcVar6;
      _Str1 = pcVar7;
    } while (cVar1 == cVar2);
    uVar5 = 0;
    if ((byte)pcVar6[-1] <= (byte)pcVar7[-1]) {
      if (pcVar6[-1] == pcVar7[-1]) {
        return 0;
      }
      uVar5 = 0xfffffffe;
    }
    uVar5 = ~uVar5;
  }
  return uVar5;
}



/* FUN_1003bbc3 @ 1003bbc3 size 56 */

void __cdecl FUN_1003bbc3(char *param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;
  
  do {
    if (param_2 < 1) {
      return;
    }
    param_2 = param_2 + -1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    FUN_1003bb5d((int)cVar1,param_3,param_4);
  } while (*param_4 != -1);
  return;
}



/* FUN_1003c64b @ 1003c64b size 55 */

uint __thiscall FUN_1003c64b(void *this,uint param_1)

{
  uint uVar1;
  
  if (DAT_1005fed4 < 2) {
    uVar1 = (byte)PTR_DAT_1005fcc8[param_1 * 2] & 4;
  }
  else {
    uVar1 = FUN_1003b258(this,param_1,4);
  }
  if (uVar1 == 0) {
    param_1 = (param_1 & 0xffffffdf) - 7;
  }
  return param_1;
}



/* FUN_1001f340 @ 1001f340 size 54 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1001f340(int param_1)

{
  uint uVar1;
  
  *(undefined **)(param_1 + 0x358) = &DAT_1004c7e8;
  uVar1 = _rand();
  *(float *)(param_1 + 0x390) = (float)((uVar1 & 0xf) + 10) * (float)_DAT_10044168 + DAT_1006c2e4;
  return;
}



/* FUN_10030560 @ 10030560 size 54 */

void __cdecl FUN_10030560(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar3 = (undefined4 *)(param_1 + 0x730);
  for (iVar2 = 0x1a3; uVar1 = DAT_1006c2e0, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  puVar3 = (undefined4 *)(param_1 + 0xbc);
  puVar4 = (undefined4 *)(param_1 + 0x730);
  for (iVar2 = 0x19d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 *)(param_1 + 0xda4) = uVar1;
  return;
}



/* FUN_100388c0 @ 100388c0 size 54 */

undefined4 __cdecl FUN_100388c0(float *param_1,float *param_2)

{
  if (((*param_1 == *param_2) && (param_1[1] == param_2[1])) && (param_1[2] == param_2[2])) {
    return 1;
  }
  return 0;
}



