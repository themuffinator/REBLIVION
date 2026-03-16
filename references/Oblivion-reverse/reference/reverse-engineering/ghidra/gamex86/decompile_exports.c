/*
Program: gamex86.dll
Decompiled exports
*/

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



