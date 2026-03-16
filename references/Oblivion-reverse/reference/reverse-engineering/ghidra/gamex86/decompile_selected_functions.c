/*
Program: gamex86.dll
Decompiled selected functions
*/

/* ai_move @ 10001090 status created size 23 */

void ai_move(int param_1,float param_2)

{
  M_walkmove(param_1,*(float *)(param_1 + 0x14),param_2);
  return;
}



/* FUN_100010b0 @ 100010b0 status existing size 177 */

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



/* ai_stand_tail @ 10001170 status existing size 175 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl ai_stand_tail(int param_1)

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
    fVar2 = vectoyaw(&local_c);
    *(float *)(param_1 + 0x1e8) = (float)fVar2;
    M_ChangeYaw(param_1);
    ai_checkattack(param_1);
    return;
  }
  iVar1 = FindTarget(param_1);
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



/* ai_stand @ 10001220 status created size 289 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ai_stand(int param_1,float param_2)

{
  int iVar1;
  float10 fVar2;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (param_2 != _DAT_1004410c) {
    M_walkmove(param_1,*(float *)(param_1 + 0x14),param_2);
  }
  if ((*(uint *)(param_1 + 0x35c) & 0x100) != 0) {
    ai_stand_tail(param_1);
    return;
  }
  if ((*(uint *)(param_1 + 0x35c) & 1) != 0) {
    iVar1 = *(int *)(param_1 + 0x25c);
    if (iVar1 != 0) {
      fStack_c = *(float *)(iVar1 + 4) - *(float *)(param_1 + 4);
      fStack_8 = *(float *)(iVar1 + 8) - *(float *)(param_1 + 8);
      fStack_4 = *(float *)(iVar1 + 0xc) - *(float *)(param_1 + 0xc);
      fVar2 = vectoyaw(&fStack_c);
      *(float *)(param_1 + 0x1e8) = (float)fVar2;
      if ((fVar2 != (float10)*(float *)(param_1 + 0x14)) && ((*(uint *)(param_1 + 0x35c) & 2) != 0))
      {
        *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) & 0xfffffffc;
        (**(code **)(param_1 + 0x378))(param_1);
      }
      M_ChangeYaw(param_1);
      ai_checkattack(param_1);
      return;
    }
    FindTarget(param_1);
    return;
  }
  iVar1 = FindTarget(param_1);
  if (iVar1 == 0) {
    if ((*(float *)(param_1 + 0x390) != _DAT_1004410c) &&
       (*(float *)(param_1 + 0x390) < DAT_1006c2e4)) {
      (**(code **)(param_1 + 0x374))(param_1);
      return;
    }
    FUN_100010b0(param_1);
  }
  return;
}



/* ai_walk @ 10001350 status created size 221 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ai_walk(int param_1,float param_2)

{
  int iVar1;
  uint uVar2;
  
  M_MoveToGoal(param_1,param_2);
  if ((*(uint *)(param_1 + 0x35c) & 0x100) == 0) {
    iVar1 = FindTarget(param_1);
    if (((iVar1 == 0) && (*(code **)(param_1 + 0x370) != (code *)0x0)) &&
       (*(float *)(param_1 + 0x3c0) < DAT_1006c2e4)) {
      if (*(float *)(param_1 + 0x3c0) != _DAT_1004410c) {
        (**(code **)(param_1 + 0x370))(param_1);
        uVar2 = _rand();
        *(float *)(param_1 + 0x3c0) =
             ((float)(uVar2 & 0x7fff) * _DAT_10044108 + _DAT_10044104) * _DAT_10044100 +
             DAT_1006c2e4;
        return;
      }
      uVar2 = _rand();
      *(float *)(param_1 + 0x3c0) =
           (float)(uVar2 & 0x7fff) * _DAT_10044108 * _DAT_10044100 + DAT_1006c2e4;
    }
  }
  else if ((*(uint *)(param_1 + 0x35c) & 0x2000000) != 0) {
    FindTarget(param_1);
    return;
  }
  return;
}



/* ai_charge @ 10001430 status created size 109 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ai_charge(int param_1,float param_2)

{
  int iVar1;
  float10 fVar2;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar1 = *(int *)(param_1 + 0x25c);
  fStack_c = *(float *)(iVar1 + 4) - *(float *)(param_1 + 4);
  fStack_8 = *(float *)(iVar1 + 8) - *(float *)(param_1 + 8);
  fStack_4 = *(float *)(iVar1 + 0xc) - *(float *)(param_1 + 0xc);
  fVar2 = vectoyaw(&fStack_c);
  *(float *)(param_1 + 0x1e8) = (float)fVar2;
  M_ChangeYaw(param_1);
  if (param_2 != _DAT_1004410c) {
    M_walkmove(param_1,*(float *)(param_1 + 0x14),param_2);
  }
  return;
}



/* range @ 100014e0 status existing size 126 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl range(int param_1,int param_2)

{
  undefined4 uVar1;
  float10 fVar2;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = *(float *)(param_1 + 4) - *(float *)(param_2 + 4);
  local_8 = *(float *)(param_1 + 8) - *(float *)(param_2 + 8);
  local_4 = *(float *)(param_1 + 0xc) - *(float *)(param_2 + 0xc);
  fVar2 = VectorLength(&local_c);
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



/* ai_turn @ 100014a0 status created size 64 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ai_turn(int param_1,float param_2)

{
  int iVar1;
  
  if (param_2 != _DAT_1004410c) {
    M_walkmove(param_1,*(float *)(param_1 + 0x14),param_2);
  }
  iVar1 = FindTarget(param_1);
  if (iVar1 == 0) {
    M_ChangeYaw(param_1);
  }
  return;
}



/* FacingIdeal @ 10001f00 status existing size 62 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FacingIdeal(void)

{
  float10 fVar1;
  
  fVar1 = anglemod();
  if (((float10)_DAT_10044138 < fVar1) && (fVar1 < (float10)_DAT_10044134)) {
    return 0;
  }
  return 1;
}



/* FoundTarget @ 10001ac0 status existing size 245 */

void __cdecl FoundTarget(int param_1)

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
    Actor_EngageEnemy(param_1);
    return;
  }
  uVar2 = G_PickTarget(*(byte **)(param_1 + 0x140));
  *(uint *)(param_1 + 0x1e0) = uVar2;
  *(uint *)(param_1 + 0x1dc) = uVar2;
  if (uVar2 == 0) {
    *(undefined4 *)(param_1 + 0x1e0) = *(undefined4 *)(param_1 + 0x25c);
    *(undefined4 *)(param_1 + 0x1dc) = *(undefined4 *)(param_1 + 0x25c);
    Actor_EngageEnemy(param_1);
    return;
  }
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) | 0x1000;
  *(undefined4 *)(uVar2 + 300) = 0;
  *(undefined4 *)(param_1 + 0x390) = 0;
  (**(code **)(param_1 + 0x378))(param_1);
  return;
}



/* FindTarget @ 10001bc0 status existing size 817 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FindTarget(int param_1)

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
              iVar5 = visible(param_1,iVar3);
              if (iVar5 == 0) {
                return 0;
              }
            }
            local_c = *(float *)(iVar3 + 4) - *(float *)(param_1 + 4);
            local_8 = *(float *)(iVar3 + 8) - *(float *)(param_1 + 8);
            local_4 = *(float *)(iVar3 + 0xc) - *(float *)(param_1 + 0xc);
            fVar10 = VectorLength(&local_c);
            if (fVar10 <= (float10)_DAT_10044110) {
              if ((*(int *)(iVar3 + 0xb0) == *(int *)(param_1 + 0xb0)) ||
                 (iVar5 = (*DAT_1006c204)(*(int *)(param_1 + 0xb0),*(int *)(iVar3 + 0xb0)),
                 iVar5 != 0)) {
                fVar10 = vectoyaw(&local_c);
                *(float *)(param_1 + 0x1e8) = (float)fVar10;
                M_ChangeYaw(param_1);
                *(int *)(param_1 + 0x25c) = iVar3;
                *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) | 4;
                goto LAB_10001ebb;
              }
            }
          }
          else {
            iVar5 = range(param_1,iVar3);
            if (((iVar5 != 3) && (5 < *(int *)(iVar3 + 0x2c4))) &&
               (iVar6 = visible(param_1,iVar3), iVar6 != 0)) {
              if (iVar5 == 1) {
                if (((float)*(int *)(iVar3 + 0x230) < DAT_1006c2e4) &&
                   (iVar5 = infront(param_1,iVar3), iVar5 == 0)) {
                  return 0;
                }
              }
              else if ((iVar5 == 2) && (iVar5 = infront(param_1,iVar3), iVar5 == 0)) {
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
              FoundTarget(param_1);
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
    if (((uVar2 & 0x1000000) != 0) && (iVar3 = Actor_FindEnemyTarget(param_1), iVar3 != 0)) {
      return 1;
    }
    uVar4 = Actor_FindFollowTarget(param_1);
    return uVar4;
  }
  return 0;
}



/* ai_checkattack @ 100022a0 status existing size 642 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl ai_checkattack(int param_1)

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
  Actor_EngageEnemy(param_1);
LAB_100023bf:
  lVar5 = __ftol();
  *(int *)(param_1 + 0x230) = (int)lVar5;
  DAT_1006ca64 = visible(param_1,*(int *)(param_1 + 0x25c));
  if (DAT_1006ca64 != 0) {
    iVar2 = *(int *)(param_1 + 0x25c);
    *(float *)(param_1 + 0x3a4) = DAT_1006c2e4 + _DAT_1004414c;
    *(undefined4 *)(param_1 + 0x3ac) = *(undefined4 *)(iVar2 + 4);
    *(undefined4 *)(param_1 + 0x3b0) = *(undefined4 *)(iVar2 + 8);
    *(undefined4 *)(param_1 + 0x3b4) = *(undefined4 *)(iVar2 + 0xc);
  }
  _DAT_1006ca70 = infront(param_1,*(int *)(param_1 + 0x25c));
  DAT_1006ca6c = range(param_1,*(int *)(param_1 + 0x25c));
  iVar2 = *(int *)(param_1 + 0x25c);
  local_c = *(float *)(iVar2 + 4) - *(float *)(param_1 + 4);
  local_8 = *(float *)(iVar2 + 8) - *(float *)(param_1 + 8);
  local_4 = *(float *)(iVar2 + 0xc) - *(float *)(param_1 + 0xc);
  fVar4 = vectoyaw(&local_c);
  DAT_1006ca68 = (float)fVar4;
  if (*(int *)(param_1 + 0x3b8) == 4) {
    ai_run_missile(param_1);
    return 1;
  }
  if (*(int *)(param_1 + 0x3b8) == 3) {
    ai_run_melee(param_1);
    return 1;
  }
  if (DAT_1006ca64 != 0) {
    uVar3 = (**(code **)(param_1 + 0x38c))(param_1);
    return uVar3;
  }
  return 0;
}



/* M_CheckAttack @ 10001f40 status existing size 583 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl M_CheckAttack(float param_1)

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



/* ai_run_melee @ 10002190 status existing size 58 */

void __cdecl ai_run_melee(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x1e8) = DAT_1006ca68;
  M_ChangeYaw(param_1);
  iVar1 = FacingIdeal();
  if (iVar1 != 0) {
    (**(code **)(param_1 + 900))(param_1);
    *(undefined4 *)(param_1 + 0x3b8) = 1;
  }
  return;
}



/* ai_run_missile @ 100021d0 status existing size 58 */

void __cdecl ai_run_missile(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x1e8) = DAT_1006ca68;
  M_ChangeYaw(param_1);
  iVar1 = FacingIdeal();
  if (iVar1 != 0) {
    (**(code **)(param_1 + 0x380))(param_1);
    *(undefined4 *)(param_1 + 0x3b8) = 1;
  }
  return;
}



/* ai_run_slide @ 10002210 status existing size 130 */

void __cdecl ai_run_slide(float param_1,float param_2)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  
  fVar2 = param_1;
  *(undefined4 *)((int)param_1 + 0x1e8) = DAT_1006ca68;
  M_ChangeYaw((int)param_1);
  piVar1 = (int *)((int)param_1 + 0x3bc);
  param_1 = 90.0;
  if (*piVar1 == 0) {
    param_1 = -90.0;
  }
  iVar3 = M_walkmove((int)fVar2,param_1 + *(float *)((int)fVar2 + 0x1e8),param_2);
  if (iVar3 == 0) {
    *(int *)((int)fVar2 + 0x3bc) = 1 - *(int *)((int)fVar2 + 0x3bc);
    M_walkmove((int)fVar2,*(float *)((int)fVar2 + 0x1e8) - param_1,param_2);
  }
  return;
}



/* ai_run @ 10002530 status created size 1881 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ai_run(float param_1,float param_2)

{
  float *pfVar1;
  undefined4 uVar2;
  uint uVar3;
  float fVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  bool bVar8;
  float10 fVar9;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  float fStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  float fStack_98;
  int *piStack_94;
  float fStack_90;
  undefined4 uStack_8c;
  float afStack_88 [3];
  float afStack_7c [3];
  float afStack_70 [14];
  undefined1 auStack_38 [56];
  
  if ((*(uint *)((int)param_1 + 0x35c) & 0x1000) != 0) {
    M_MoveToGoal((int)param_1,param_2);
    return;
  }
  if ((*(uint *)((int)param_1 + 0x35c) & 4) != 0) {
    iVar5 = *(int *)((int)param_1 + 0x25c);
    fStack_c4 = *(float *)((int)param_1 + 4) - *(float *)(iVar5 + 4);
    fStack_c0 = *(float *)((int)param_1 + 8) - *(float *)(iVar5 + 8);
    fStack_bc = *(float *)((int)param_1 + 0xc) - *(float *)(iVar5 + 0xc);
    fVar9 = VectorLength(&fStack_c4);
    if (fVar9 < (float10)_DAT_10044160) {
      *(uint *)((int)param_1 + 0x35c) = *(uint *)((int)param_1 + 0x35c) | 3;
      (**(code **)((int)param_1 + 0x368))(param_1);
      return;
    }
    M_MoveToGoal((int)param_1,param_2);
    iVar5 = FindTarget((int)param_1);
    if (iVar5 == 0) {
      return;
    }
  }
  iVar5 = ai_checkattack((int)param_1);
  if (iVar5 != 0) {
    return;
  }
  if (*(int *)((int)param_1 + 0x3b8) == 2) {
    ai_run_slide(param_1,param_2);
    return;
  }
  if (DAT_1006ca64 != 0) {
    M_MoveToGoal((int)param_1,param_2);
    *(uint *)((int)param_1 + 0x35c) = *(uint *)((int)param_1 + 0x35c) & 0xfffffff7;
    iVar5 = *(int *)((int)param_1 + 0x25c);
    *(undefined4 *)((int)param_1 + 0x3ac) = *(undefined4 *)(iVar5 + 4);
    *(undefined4 *)((int)param_1 + 0x3b0) = *(undefined4 *)(iVar5 + 8);
    *(undefined4 *)((int)param_1 + 0x3b4) = *(undefined4 *)(iVar5 + 0xc);
    *(float *)((int)param_1 + 0x3a8) = DAT_1006c2e4;
    return;
  }
  if ((*(float *)(DAT_1006c42c + 0x14) != _DAT_1004410c) &&
     (iVar5 = FindTarget((int)param_1), iVar5 != 0)) {
    return;
  }
  if ((*(float *)((int)param_1 + 0x3a4) != _DAT_1004410c) &&
     (*(float *)((int)param_1 + 0x3a4) + _DAT_1004415c < DAT_1006c2e4)) {
    M_MoveToGoal((int)param_1,param_2);
    *(undefined4 *)((int)param_1 + 0x3a4) = 0;
    return;
  }
  uStack_8c = *(undefined4 *)((int)param_1 + 0x1dc);
  piStack_94 = G_Spawn();
  *(int **)((int)param_1 + 0x1dc) = piStack_94;
  bVar8 = (*(uint *)((int)param_1 + 0x35c) & 8) == 0;
  if (bVar8) {
    *(uint *)((int)param_1 + 0x35c) = *(uint *)((int)param_1 + 0x35c) & 0xffffff9f | 0x18;
  }
  uVar3 = *(uint *)((int)param_1 + 0x35c);
  if ((uVar3 & 0x20) != 0) {
    *(uint *)((int)param_1 + 0x35c) = uVar3 & 0xffffffdf;
    *(float *)((int)param_1 + 0x3a4) = DAT_1006c2e4 + _DAT_1004414c;
    if ((uVar3 & 0x40) == 0) {
      if ((uVar3 & 0x10) == 0) {
        iVar5 = FUN_100332d0((int)param_1);
      }
      else {
        *(uint *)((int)param_1 + 0x35c) = uVar3 & 0xffffffcf;
        iVar5 = FUN_10033240((int)param_1);
      }
      if (iVar5 == 0) goto LAB_100027d1;
      *(undefined4 *)((int)param_1 + 0x3ac) = *(undefined4 *)(iVar5 + 4);
      *(undefined4 *)((int)param_1 + 0x3b0) = *(undefined4 *)(iVar5 + 8);
      *(undefined4 *)((int)param_1 + 0x3b4) = *(undefined4 *)(iVar5 + 0xc);
      *(undefined4 *)((int)param_1 + 0x3a8) = *(undefined4 *)(iVar5 + 0x120);
      uVar2 = *(undefined4 *)(iVar5 + 0x14);
      *(undefined4 *)((int)param_1 + 0x1e8) = uVar2;
      *(undefined4 *)((int)param_1 + 0x14) = uVar2;
    }
    else {
      *(undefined4 *)((int)param_1 + 0x3b0) = *(undefined4 *)((int)param_1 + 0x39c);
      *(uint *)((int)param_1 + 0x35c) = uVar3 & 0xffffff9f;
      *(undefined4 *)((int)param_1 + 0x3ac) = *(undefined4 *)((int)param_1 + 0x398);
      *(undefined4 *)((int)param_1 + 0x3b4) = *(undefined4 *)((int)param_1 + 0x3a0);
    }
    bVar8 = true;
  }
LAB_100027d1:
  fStack_c4 = *(float *)((int)param_1 + 4) - *(float *)((int)param_1 + 0x3ac);
  pfVar1 = (float *)((int)param_1 + 4);
  fStack_c0 = *(float *)((int)param_1 + 8) - *(float *)((int)param_1 + 0x3b0);
  fStack_bc = *(float *)((int)param_1 + 0xc) - *(float *)((int)param_1 + 0x3b4);
  fVar9 = VectorLength(&fStack_c4);
  if (fVar9 <= (float10)param_2) {
    param_2 = (float)fVar9;
    *(uint *)((int)param_1 + 0x35c) = *(uint *)((int)param_1 + 0x35c) | 0x20;
  }
  *(undefined4 *)(*(int *)((int)param_1 + 0x1dc) + 4) = *(undefined4 *)((int)param_1 + 0x3ac);
  *(undefined4 *)(*(int *)((int)param_1 + 0x1dc) + 8) = *(undefined4 *)((int)param_1 + 0x3b0);
  *(undefined4 *)(*(int *)((int)param_1 + 0x1dc) + 0xc) = *(undefined4 *)((int)param_1 + 0x3b4);
  if (bVar8) {
    pfVar6 = (float *)(*DAT_1006c1f0)(afStack_70,pfVar1,(int)param_1 + 0xbc,(int)param_1 + 200,
                                      (undefined4 *)((int)param_1 + 0x3ac),param_1,0x2010003);
    pfVar7 = afStack_70;
    for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {
      *pfVar7 = *pfVar6;
      pfVar6 = pfVar6 + 1;
      pfVar7 = pfVar7 + 1;
    }
    if (afStack_70[2] < _DAT_10044104) {
      iVar5 = *(int *)((int)param_1 + 0x1dc);
      fStack_c4 = *(float *)(iVar5 + 4) - *pfVar1;
      fStack_c0 = *(float *)(iVar5 + 8) - *(float *)((int)param_1 + 8);
      fStack_bc = *(float *)(iVar5 + 0xc) - *(float *)((int)param_1 + 0xc);
      fVar9 = VectorLength(&fStack_c4);
      fStack_98 = (float)fVar9;
      fStack_90 = afStack_70[2];
      fStack_b4 = (afStack_70[2] + _DAT_10044104) * _DAT_10044158 * fStack_98;
      fVar9 = vectoyaw(&fStack_c4);
      *(float *)((int)param_1 + 0x1e8) = (float)fVar9;
      *(float *)((int)param_1 + 0x14) = (float)fVar9;
      AngleVectors((float *)((int)param_1 + 0x10),afStack_7c,afStack_88,(float *)0x0);
      fStack_c4 = fStack_b4;
      fStack_c0 = -16.0;
      fStack_bc = 0.0;
      FUN_1001aba0(pfVar1,&fStack_c4,afStack_7c,afStack_88,&fStack_b0);
      pfVar6 = (float *)(*DAT_1006c1f0)(auStack_38,pfVar1,(int)param_1 + 0xbc,(int)param_1 + 200,
                                        &fStack_b0,param_1,0x2010003);
      pfVar7 = afStack_70;
      for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {
        *pfVar7 = *pfVar6;
        pfVar6 = pfVar6 + 1;
        pfVar7 = pfVar7 + 1;
      }
      fStack_b8 = afStack_70[2];
      fStack_c4 = fStack_b4;
      fStack_c0 = 16.0;
      fStack_bc = 0.0;
      FUN_1001aba0(pfVar1,&fStack_c4,afStack_7c,afStack_88,&fStack_a4);
      pfVar6 = (float *)(*DAT_1006c1f0)(auStack_38,pfVar1,(int)param_1 + 0xbc,(int)param_1 + 200,
                                        &fStack_a4,param_1,0x2010003);
      fVar4 = (fStack_90 * fStack_98) / fStack_b4;
      pfVar7 = afStack_70;
      for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {
        *pfVar7 = *pfVar6;
        pfVar6 = pfVar6 + 1;
        pfVar7 = pfVar7 + 1;
      }
      if ((fStack_b8 < fVar4) || (fStack_b8 <= afStack_70[2])) {
        if ((afStack_70[2] < fVar4) || (afStack_70[2] <= fStack_b8)) goto LAB_10002c55;
        if (afStack_70[2] < _DAT_10044104) {
          fStack_c4 = fStack_b4 * afStack_70[2] * (float)_DAT_10044140;
          fStack_c0 = 16.0;
          fStack_bc = 0.0;
          FUN_1001aba0(pfVar1,&fStack_c4,afStack_7c,afStack_88,&fStack_a4);
        }
        *(undefined4 *)((int)param_1 + 0x398) = *(undefined4 *)((int)param_1 + 0x3ac);
        *(undefined4 *)((int)param_1 + 0x39c) = *(undefined4 *)((int)param_1 + 0x3b0);
        *(uint *)((int)param_1 + 0x35c) = *(uint *)((int)param_1 + 0x35c) | 0x40;
        *(undefined4 *)((int)param_1 + 0x3a0) = *(undefined4 *)((int)param_1 + 0x3b4);
        *(float *)(*(int *)((int)param_1 + 0x1dc) + 4) = fStack_a4;
        *(undefined4 *)(*(int *)((int)param_1 + 0x1dc) + 8) = uStack_a0;
        *(undefined4 *)(*(int *)((int)param_1 + 0x1dc) + 0xc) = uStack_9c;
        *(undefined4 *)((int)param_1 + 0x3b0) = uStack_a0;
        iVar5 = *(int *)((int)param_1 + 0x1dc);
        *(float *)((int)param_1 + 0x3ac) = fStack_a4;
        *(undefined4 *)((int)param_1 + 0x3b4) = uStack_9c;
        fStack_c4 = *(float *)(iVar5 + 4) - *pfVar1;
        fStack_c0 = *(float *)(iVar5 + 8) - *(float *)((int)param_1 + 8);
        fStack_bc = *(float *)(iVar5 + 0xc) - *(float *)((int)param_1 + 0xc);
      }
      else {
        if (fStack_b8 < _DAT_10044104) {
          fStack_c4 = fStack_b8 * fStack_b4 * (float)_DAT_10044140;
          fStack_c0 = -16.0;
          fStack_bc = 0.0;
          FUN_1001aba0(pfVar1,&fStack_c4,afStack_7c,afStack_88,&fStack_b0);
        }
        *(undefined4 *)((int)param_1 + 0x3a0) = *(undefined4 *)((int)param_1 + 0x3b4);
        *(undefined4 *)((int)param_1 + 0x398) = *(undefined4 *)((int)param_1 + 0x3ac);
        *(undefined4 *)((int)param_1 + 0x39c) = *(undefined4 *)((int)param_1 + 0x3b0);
        *(uint *)((int)param_1 + 0x35c) = *(uint *)((int)param_1 + 0x35c) | 0x40;
        *(float *)(*(int *)((int)param_1 + 0x1dc) + 4) = fStack_b0;
        *(undefined4 *)(*(int *)((int)param_1 + 0x1dc) + 8) = uStack_ac;
        *(undefined4 *)(*(int *)((int)param_1 + 0x1dc) + 0xc) = uStack_a8;
        *(float *)((int)param_1 + 0x3ac) = fStack_b0;
        iVar5 = *(int *)((int)param_1 + 0x1dc);
        *(undefined4 *)((int)param_1 + 0x3b0) = uStack_ac;
        *(undefined4 *)((int)param_1 + 0x3b4) = uStack_a8;
        fStack_c4 = *(float *)(iVar5 + 4) - *pfVar1;
        fStack_c0 = *(float *)(iVar5 + 8) - *(float *)((int)param_1 + 8);
        fStack_bc = *(float *)(iVar5 + 0xc) - *(float *)((int)param_1 + 0xc);
      }
      fVar9 = vectoyaw(&fStack_c4);
      *(float *)((int)param_1 + 0x1e8) = (float)fVar9;
      *(float *)((int)param_1 + 0x14) = (float)fVar9;
    }
  }
LAB_10002c55:
  M_MoveToGoal((int)param_1,param_2);
  G_FreeEdict(piStack_94);
  if (param_1 != 0.0) {
    *(undefined4 *)((int)param_1 + 0x1dc) = uStack_8c;
  }
  return;
}



/* SelectNextItem @ 10003df0 status existing size 116 */

void __cdecl SelectNextItem(int param_1,uint param_2)

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



/* SelectPrevItem @ 10003e70 status existing size 121 */

void __cdecl SelectPrevItem(int param_1,uint param_2)

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



/* ValidateSelectedItem @ 10003ef0 status existing size 38 */

void __cdecl ValidateSelectedItem(int param_1)

{
  if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + *(int *)(*(int *)(param_1 + 0x54) + 0x2e0) * 4) ==
      0) {
    SelectNextItem(param_1,0xffffffff);
  }
  return;
}



/* Cmd_Give_f @ 10003f20 status existing size 1061 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Cmd_Give_f(int param_1)

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
          Add_Ammo(param_1,(int)(pbVar2 + -0x38),1000);
        }
        iVar3 = iVar3 + 1;
        pbVar2 = pbVar2 + 0x48;
      } while (iVar3 < DAT_1006ca54);
    }
    if (!bVar1) {
      return;
    }
LAB_100040a2:
    puVar7 = FindItem((byte *)s_Jacket_Armor_100461e0);
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar7 + -0x4011a4a) / 0x48) * 4) = 0;
    puVar7 = FindItem((byte *)s_Combat_Armor_100461d0);
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar7 + -0x4011a4a) / 0x48) * 4) = 0;
    puVar7 = FindItem((byte *)s_Body_Armor_100461c4);
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
        piVar6 = FindItem(pbVar2);
        if (piVar6 == (int *)0x0) {
          pbVar2 = (byte *)(*DAT_1006c260)(1);
          piVar6 = FindItem(pbVar2);
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
        piVar8 = G_Spawn();
        piVar8[0x46] = *piVar6;
        SpawnItem(piVar8,piVar6);
        Touch_Item(piVar8,param_1);
        if (piVar8[0x16] == 0) {
          return;
        }
        G_FreeEdict(piVar8);
        return;
      }
      goto LAB_100041ad;
    }
  }
  piVar6 = FindItem((byte *)s_Power_Shield_100461b4);
  piVar8 = G_Spawn();
  piVar8[0x46] = *piVar6;
  SpawnItem(piVar8,piVar6);
  Touch_Item(piVar8,param_1);
  if (piVar8[0x16] != 0) {
    G_FreeEdict(piVar8);
  }
  if (!bVar1) {
    return;
  }
LAB_100041ad:
  piVar6 = FindItem((byte *)s_Rifle_Plasma_100461a4);
  piVar8 = G_Spawn();
  piVar8[0x46] = *piVar6;
  SpawnItem(piVar8,piVar6);
  Touch_Item(piVar8,param_1);
  if (piVar8[0x16] != 0) {
    G_FreeEdict(piVar8);
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



/* Cmd_God_f @ 10004350 status existing size 115 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Cmd_God_f(int param_1)

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



/* Cmd_Notarget_f @ 100043d0 status existing size 115 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Cmd_Notarget_f(int param_1)

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



/* Cmd_Noclip_f @ 10004450 status existing size 136 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Cmd_Noclip_f(int param_1)

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



/* Cmd_Use_f @ 10004560 status existing size 491 */

void __cdecl Cmd_Use_f(int param_1)

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
  puVar2 = FindItem(pbStack_4);
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



/* Cmd_UseToggle_f @ 10004870 status existing size 319 */

void __cdecl Cmd_UseToggle_f(int param_1)

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
      puVar3 = FindItem(abStack_40);
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
      puVar3 = FindItem(abStack_40);
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



/* Cmd_Drop_f @ 100049b0 status existing size 162 */

void __cdecl Cmd_Drop_f(int param_1)

{
  byte *pbVar1;
  undefined4 *puVar2;
  
  pbVar1 = (byte *)(*DAT_1006c264)();
  puVar2 = FindItem(pbVar1);
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



/* Cmd_Inven_f @ 10004a60 status existing size 109 */

void __cdecl Cmd_Inven_f(int param_1)

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



/* Cmd_InvUse_f @ 10004ad0 status existing size 96 */

void __cdecl Cmd_InvUse_f(int param_1)

{
  int iVar1;
  
  ValidateSelectedItem(param_1);
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



/* Cmd_WeapPrev_f @ 10004b30 status existing size 142 */

void __cdecl Cmd_WeapPrev_f(int param_1)

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



/* Cmd_WeapNext_f @ 10004bc0 status existing size 146 */

void __cdecl Cmd_WeapNext_f(int param_1)

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



/* Cmd_WeapLast_f @ 10004c60 status existing size 99 */

void __cdecl Cmd_WeapLast_f(int param_1)

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



/* Cmd_InvDrop_f @ 10004cd0 status existing size 96 */

void __cdecl Cmd_InvDrop_f(int param_1)

{
  int iVar1;
  
  ValidateSelectedItem(param_1);
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



/* Cmd_Kill_f @ 10004d30 status existing size 88 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Cmd_Kill_f(float param_1)

{
  if (_DAT_1004414c <= DAT_1006c2e4 - *(float *)(*(int *)((int)param_1 + 0x54) + 0xf00)) {
    *(uint *)((int)param_1 + 0x108) = *(uint *)((int)param_1 + 0x108) & 0xffffffef;
    *(undefined4 *)((int)param_1 + 0x220) = 0;
    DAT_1006c104 = 0x17;
    player_die(param_1,(int)param_1,(int)param_1,100000);
  }
  return;
}



/* Cmd_PutAway_f @ 10004d90 status existing size 34 */

void __cdecl Cmd_PutAway_f(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xdd8) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xde0) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xddc) = 0;
  return;
}



/* Cmd_Players_f @ 10004e10 status existing size 392 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Cmd_Players_f(undefined4 param_1)

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



/* Cmd_Wave_f @ 10004fa0 status existing size 269 */

void __cdecl Cmd_Wave_f(int param_1)

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



/* Cmd_Say_f @ 100050c0 status existing size 901 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Cmd_Say_f(int param_1,int param_2,int param_3)

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



/* Cmd_PlayerList_f @ 10005450 status existing size 413 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Cmd_PlayerList_f(undefined4 param_1)

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



/* plat_hit_top @ 10007100 status existing size 98 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl plat_hit_top(int param_1)

{
  if ((*(uint *)(param_1 + 0x108) & 0x400) == 0) {
    if (*(int *)(param_1 + 0x318) != 0) {
      (*DAT_1006c1d0)(param_1,10,*(int *)(param_1 + 0x318),0x3f800000,0x40400000,0);
    }
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  *(undefined4 *)(param_1 + 0x330) = 0;
  *(code **)(param_1 + 500) = plat_go_up;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + _DAT_100441b4;
  return;
}



/* plat_hit_bottom @ 10007170 status existing size 70 */

void __cdecl plat_hit_bottom(int param_1)

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



/* plat_go_up @ 100071c0 status existing size 93 */

void __cdecl plat_go_up(int param_1)

{
  if ((*(uint *)(param_1 + 0x108) & 0x400) == 0) {
    if (*(int *)(param_1 + 0x310) != 0) {
      (*DAT_1006c1d0)(param_1,10,*(int *)(param_1 + 0x310),0x3f800000,0x40400000,0);
    }
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x314);
  }
  *(undefined4 *)(param_1 + 0x330) = 3;
  FUN_10006b20(param_1,(float *)(param_1 + 0x2f8),plat_hit_bottom);
  return;
}



/* plat_go_down @ 10007220 status existing size 93 */

void __cdecl plat_go_down(int param_1)

{
  if ((*(uint *)(param_1 + 0x108) & 0x400) == 0) {
    if (*(int *)(param_1 + 0x310) != 0) {
      (*DAT_1006c1d0)(param_1,10,*(int *)(param_1 + 0x310),0x3f800000,0x40400000,0);
    }
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x314);
  }
  *(undefined4 *)(param_1 + 0x330) = 2;
  FUN_10006b20(param_1,(float *)(param_1 + 0x2e0),plat_hit_top);
  return;
}



/* plat_blocked @ 10007280 status existing size 160 */

void __cdecl plat_blocked(int param_1,undefined4 *param_2)

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
      plat_go_up(param_1);
      return;
    }
    if (*(int *)(param_1 + 0x330) == 3) {
      plat_go_down(param_1);
    }
  }
  return;
}



/* plat_spawn_inside_trigger @ 10007390 status existing size 346 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl plat_spawn_inside_trigger(int param_1)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  
  piVar3 = G_Spawn();
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



/* SP_func_plat @ 100074f0 status existing size 670 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_func_plat(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 3;
  *(undefined4 *)(param_1 + 0x104) = 2;
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  *(code **)(param_1 + 0x1f8) = plat_blocked;
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
  plat_spawn_inside_trigger(param_1);
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



/* rotating_use @ 100083c0 status existing size 726 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl rotating_use(int param_1)

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
          VectorScale(local_24,*(float *)(param_1 + 0x1ac),(float *)(param_1 + 0x184));
          local_30 = *(float *)(param_1 + 0x184);
          local_2c = *(float *)(param_1 + 0x188);
          local_28 = *(float *)(param_1 + 0x18c);
        }
        if (*(float *)(param_1 + 0x1b0) != _DAT_1004410c) {
          VectorScale(local_24 + 3,*(float *)(param_1 + 0x1b0),(float *)(param_1 + 0x184));
          local_30 = local_30 + *(float *)(param_1 + 0x184);
          local_2c = local_2c + *(float *)(param_1 + 0x188);
          local_28 = local_28 + *(float *)(param_1 + 0x18c);
        }
        if (*(float *)(param_1 + 0x1b4) != _DAT_1004410c) {
          VectorScale(local_24 + 6,*(float *)(param_1 + 0x1b4),(float *)(param_1 + 0x184));
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



/* button_return @ 10008b80 status existing size 65 */

void __cdecl button_return(int param_1)

{
  *(undefined4 *)(param_1 + 0x330) = 3;
  FUN_10006b20(param_1,(float *)(param_1 + 0x2e0),&LAB_10008b60);
  *(undefined4 *)(param_1 + 0x38) = 0;
  if (*(int *)(param_1 + 0x220) != 0) {
    *(undefined4 *)(param_1 + 0x240) = 1;
  }
  return;
}



/* button_wait @ 10008bd0 status existing size 99 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl button_wait(uint param_1)

{
  bool bVar1;
  float fVar2;
  
  *(undefined4 *)(param_1 + 0x330) = 0;
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffbff | 0x800;
  G_UseTargets(param_1,*(int *)(param_1 + 0x264));
  bVar1 = _DAT_1004410c <= *(float *)(param_1 + 0x32c);
  *(undefined4 *)(param_1 + 0x38) = 1;
  if (bVar1) {
    fVar2 = DAT_1006c2e4 + *(float *)(param_1 + 0x32c);
    *(code **)(param_1 + 500) = button_return;
    *(float *)(param_1 + 0x1ec) = fVar2;
  }
  return;
}



/* button_fire @ 10008c40 status existing size 99 */

void __cdecl button_fire(int param_1)

{
  if ((*(int *)(param_1 + 0x330) != 2) && (*(int *)(param_1 + 0x330) != 0)) {
    *(undefined4 *)(param_1 + 0x330) = 2;
    if ((*(int *)(param_1 + 0x310) != 0) && ((*(uint *)(param_1 + 0x108) & 0x400) == 0)) {
      (*DAT_1006c1d0)(param_1,10,*(int *)(param_1 + 0x310),0x3f800000,0x40400000,0);
    }
    FUN_10006b20(param_1,(float *)(param_1 + 0x2f8),button_wait);
  }
  return;
}



/* SP_func_button @ 10008d30 status existing size 599 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_func_button(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  undefined4 uVar3;
  
  pfVar1 = (float *)(param_1 + 0x154);
  G_SetMovedir((float *)(param_1 + 0x10),pfVar1);
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
  VectorMA(pfVar2,(ABS(*pfVar1) * *(float *)(param_1 + 0xec) +
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



/* door_use_areaportals @ 10008f90 status existing size 115 */

void __cdecl door_use_areaportals(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  
  if (*(byte **)(param_1 + 0x128) != (byte *)0x0) {
    for (uVar1 = G_Find(0,300,*(byte **)(param_1 + 0x128)); uVar1 != 0;
        uVar1 = G_Find(uVar1,300,*(byte **)(param_1 + 0x128))) {
      iVar2 = FUN_10038b20(*(void **)(uVar1 + 0x118),(byte *)s_func_areaportal_100466a8);
      if (iVar2 == 0) {
        (*DAT_1006c200)(*(undefined4 *)(uVar1 + 0x2c8),param_2);
      }
    }
  }
  return;
}



/* door_hit_top @ 10009010 status existing size 127 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl door_hit_top(int param_1)

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
    *(code **)(param_1 + 500) = door_go_down;
    *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + *(float *)(param_1 + 0x32c);
  }
  return;
}



/* door_hit_bottom @ 10009090 status existing size 81 */

void __cdecl door_hit_bottom(int param_1)

{
  if ((*(uint *)(param_1 + 0x108) & 0x400) == 0) {
    if (*(int *)(param_1 + 0x318) != 0) {
      (*DAT_1006c1d0)(param_1,10,*(int *)(param_1 + 0x318),0x3f800000,0x40400000,0);
    }
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  *(undefined4 *)(param_1 + 0x330) = 1;
  door_use_areaportals(param_1,0);
  return;
}



/* door_go_down @ 100090f0 status existing size 262 */

void __cdecl door_go_down(int param_1)

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
    FUN_10006b20(param_1,(float *)(param_1 + 0x2e0),door_hit_bottom);
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
    FUN_10006df0(param_1,door_hit_bottom);
  }
  return;
}



/* door_go_up @ 10009200 status existing size 317 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl door_go_up(uint param_1,int param_2)

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
        FUN_10006b20(param_1,(float *)(param_1 + 0x2f8),door_hit_top);
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
          FUN_10006df0(param_1,door_hit_top);
        }
      }
      G_UseTargets(param_1,param_2);
      door_use_areaportals(param_1,1);
    }
  }
  return;
}



/* door_use @ 10009340 status existing size 127 */

void __cdecl door_use(uint param_1,undefined4 param_2,int param_3)

{
  if ((*(uint *)(param_1 + 0x108) & 0x400) == 0) {
    if (((*(byte *)(param_1 + 0x11c) & 0x20) == 0) ||
       ((*(int *)(param_1 + 0x330) != 2 && (*(int *)(param_1 + 0x330) != 0)))) {
      for (; param_1 != 0; param_1 = *(uint *)(param_1 + 0x270)) {
        *(undefined4 *)(param_1 + 0x114) = 0;
        *(undefined4 *)(param_1 + 0x1fc) = 0;
        door_go_up(param_1,param_3);
      }
    }
    else if (param_1 != 0) {
      do {
        *(undefined4 *)(param_1 + 0x114) = 0;
        *(undefined4 *)(param_1 + 0x1fc) = 0;
        door_go_down(param_1);
        param_1 = *(uint *)(param_1 + 0x270);
      } while (param_1 != 0);
      return;
    }
  }
  return;
}



/* Think_CalcMoveSpeed @ 10009430 status existing size 203 */

void __cdecl Think_CalcMoveSpeed(int param_1)

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



/* door_touch @ 100097b0 status existing size 116 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl door_touch(int param_1,int param_2)

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



/* SP_func_door @ 10009830 status existing size 919 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_func_door(int param_1)

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
  *(code **)(param_1 + 0x200) = door_use;
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
  G_SetMovedir(pfVar1,(float *)(param_1 + 0x154));
  pfVar2 = (float *)(param_1 + 0x160);
  *pfVar2 = *(float *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(param_1 + 0xc);
  pfVar3 = (float *)(param_1 + 0x16c);
  fVar4 = (ABS(*(float *)(param_1 + 0x154)) * *(float *)(param_1 + 0xec) +
          ABS(*(float *)(param_1 + 0x158)) * *(float *)(param_1 + 0xf0) +
          ABS(*(float *)(param_1 + 0x15c)) * *(float *)(param_1 + 0xf4)) - (float)DAT_1006c298;
  *(float *)(param_1 + 0x328) = fVar4;
  VectorMA(pfVar2,fVar4,(float *)(param_1 + 0x154),pfVar3);
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
      *(code **)(param_1 + 0x1fc) = door_touch;
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
  *(code **)(param_1 + 500) = Think_CalcMoveSpeed;
  return;
}



/* SP_func_door_rotating @ 10009bd0 status existing size 968 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_func_door_rotating(int param_1)

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
  VectorMA(pfVar1,(float)DAT_1006c29c,pfVar2,pfVar3);
  *(float *)(param_1 + 0x328) = (float)DAT_1006c29c;
  *(undefined4 *)(param_1 + 0x104) = 2;
  *(undefined4 *)(param_1 + 0xf8) = 3;
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  *(undefined1 **)(param_1 + 0x1f8) = &LAB_10009670;
  *(code **)(param_1 + 0x200) = door_use;
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
    *(code **)(param_1 + 0x1fc) = door_touch;
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
  *(code **)(param_1 + 500) = Think_CalcMoveSpeed;
  return;
}



/* SP_func_water @ 10009fa0 status existing size 580 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_func_water(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  bool bVar4;
  float fVar5;
  undefined4 uVar6;
  
  pfVar1 = (float *)(param_1 + 0x154);
  G_SetMovedir((float *)(param_1 + 0x10),pfVar1);
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
  VectorMA(pfVar2,fVar5,pfVar1,pfVar3);
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
  *(code **)(param_1 + 0x200) = door_use;
  *(int *)(param_1 + 0x32c) = *(int *)(param_1 + 0x290);
  if (*(int *)(param_1 + 0x290) == -0x40800000) {
    *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) | 0x20;
  }
  *(char **)(param_1 + 0x118) = s_func_door_100466cc;
  (*DAT_1006c208)(param_1);
  return;
}



/* train_next @ 1000a300 status existing size 438 */

void __cdecl train_next(int param_1)

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
      uVar4 = G_PickTarget(pbVar3);
      if (uVar4 == 0) {
        (*DAT_1006c1c4)(s_train_next__bad_target__s_1004676c,*(undefined4 *)(param_1 + 0x128));
        return;
      }
      *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(uVar4 + 0x128);
      if ((*(byte *)(uVar4 + 0x11c) & 1) == 0) break;
      if (!bVar2) {
        iVar6 = uVar4 + 4;
        puVar5 = vtos();
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



/* train_resume @ 1000a4c0 status existing size 154 */

void __cdecl train_resume(int param_1)

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



/* func_train_find @ 1000a560 status existing size 190 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl func_train_find(int param_1)

{
  float fVar1;
  uint uVar2;
  
  if (*(byte **)(param_1 + 0x128) == (byte *)0x0) {
    (*DAT_1006c1c4)(s_train_find__no_target_100467ac);
    return;
  }
  uVar2 = G_PickTarget(*(byte **)(param_1 + 0x128));
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
    *(code **)(param_1 + 500) = train_next;
    *(int *)(param_1 + 0x264) = param_1;
    *(float *)(param_1 + 0x1ec) = fVar1;
  }
  return;
}



/* train_use @ 1000a620 status existing size 93 */

void __cdecl train_use(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  *(undefined4 *)(param_1 + 0x264) = param_3;
  uVar1 = *(uint *)(param_1 + 0x11c);
  if ((uVar1 & 1) == 0) {
    if (*(int *)(param_1 + 0x144) != 0) {
      train_resume(param_1);
      return;
    }
    train_next(param_1);
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



/* SP_func_train @ 1000a680 status existing size 403 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_func_train(int param_1)

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
  *(code **)(param_1 + 0x200) = train_use;
  *(undefined4 *)(param_1 + 800) = uVar2;
  *(undefined4 *)(param_1 + 0x324) = uVar2;
  *(undefined4 *)(param_1 + 0x31c) = uVar2;
  (*DAT_1006c208)(param_1);
  if (*(int *)(param_1 + 0x128) != 0) {
    fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
    *(code **)(param_1 + 500) = func_train_find;
    *(float *)(param_1 + 0x1ec) = fVar1;
    return;
  }
  iVar4 = param_1 + 0xd4;
  puVar3 = vtos();
  (*DAT_1006c1c4)(s_func_train_without_a_target_at___100467c4,puVar3,iVar4);
  return;
}



/* func_timer_think @ 1000a9a0 status existing size 81 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl func_timer_think(uint param_1)

{
  float fVar1;
  uint uVar2;
  
  G_UseTargets(param_1,*(int *)(param_1 + 0x264));
  uVar2 = _rand();
  fVar1 = (float)(uVar2 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  *(float *)(param_1 + 0x1ec) =
       DAT_1006c2e4 + *(float *)(param_1 + 0x290) + (fVar1 + fVar1) * *(float *)(param_1 + 0x29c);
  return;
}



/* SP_func_timer @ 1000aa60 status existing size 216 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_func_timer(int param_1)

{
  float fVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  
  if (*(float *)(param_1 + 0x290) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x290) = 0x3f800000;
  }
  *(undefined1 **)(param_1 + 0x200) = &LAB_1000aa00;
  *(code **)(param_1 + 500) = func_timer_think;
  if (*(float *)(param_1 + 0x290) <= *(float *)(param_1 + 0x29c)) {
    iVar4 = param_1 + 4;
    *(float *)(param_1 + 0x29c) = *(float *)(param_1 + 0x290) - (float)_DAT_10044168;
    puVar2 = vtos();
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



/* SP_func_conveyor @ 1000ab80 status existing size 116 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_func_conveyor(int param_1)

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



/* door_secret_use @ 1000ac00 status existing size 57 */

void __cdecl door_secret_use(int param_1)

{
  int iVar1;
  
  iVar1 = VectorCompare((float *)(param_1 + 4),(float *)&DAT_10061c18);
  if (iVar1 != 0) {
    FUN_10006b20(param_1,(float *)(param_1 + 0x160),&LAB_1000ac40);
    door_use_areaportals(param_1,1);
  }
  return;
}



/* door_secret_blocked @ 1000ad70 status existing size 157 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl door_secret_blocked(int param_1,undefined4 *param_2)

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



/* AI_SetSightClient @ 10001000 status existing size 133 */

void AI_SetSightClient(void)

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



/* SP_path_corner @ 1000e670 status existing size 359 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_path_corner(undefined4 *param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  if (param_1[0x4b] == 0) {
    puVar2 = param_1 + 1;
    puVar1 = vtos();
    (*DAT_1006c1c4)(s_path_corner_with_no_targetname_a_10049200,puVar1,puVar2);
    G_FreeEdict(param_1);
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



/* point_combat_touch @ 1000e7e0 status existing size 339 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl point_combat_touch(uint param_1,int param_2)

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
      uVar3 = G_PickTarget(pbVar1);
      *(uint *)(param_2 + 0x1e0) = uVar3;
      *(uint *)(param_2 + 0x1dc) = uVar3;
      if (uVar3 == 0) {
        uVar6 = *(undefined4 *)(param_1 + 0x128);
        puVar4 = vtos();
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
      G_UseTargets(param_1,iVar5);
      *(undefined4 *)(param_1 + 0x128) = uVar6;
    }
  }
  return;
}



/* SP_point_combat @ 1000e940 status created size 129 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_point_combat(undefined4 *param_1)

{
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    G_FreeEdict(param_1);
    return;
  }
  param_1[0x2f] = 0xc1000000;
  param_1[0x30] = 0xc1000000;
  param_1[0x3e] = 1;
  param_1[0x7f] = point_combat_touch;
  param_1[0x31] = 0xc1800000;
  param_1[0x32] = 0x41000000;
  param_1[0x33] = 0x41000000;
  param_1[0x34] = 0x41800000;
  param_1[0x2e] = 1;
  (*DAT_1006c208)(param_1);
  return;
}



/* TH_viewthing @ 1000e9d0 status created size 40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TH_viewthing(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x38) + 1;
  *(int *)(param_1 + 0x38) = iVar1 % 7;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  return iVar1 / 7;
}



/* SP_viewthing @ 1000ea00 status created size 151 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_viewthing(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  
  (*DAT_1006c1c4)(s_viewthing_spawned_1004926c);
  *(undefined4 *)(param_1 + 0xbc) = 0xc1800000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc1800000;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 2;
  *(undefined4 *)(param_1 + 0x44) = 0x40;
  *(undefined4 *)(param_1 + 0xc4) = 0xc1c00000;
  *(undefined4 *)(param_1 + 200) = 0x41800000;
  *(undefined4 *)(param_1 + 0xcc) = 0x41800000;
  *(undefined4 *)(param_1 + 0xd0) = 0x42000000;
  uVar2 = (*DAT_1006c1e0)(s_models_objects_banner_tris_md2_1004924c);
  *(undefined4 *)(param_1 + 0x28) = uVar2;
  (*DAT_1006c208)(param_1);
  fVar1 = DAT_1006c2e4 + (float)_DAT_10044140;
  *(code **)(param_1 + 500) = TH_viewthing;
  *(float *)(param_1 + 0x1ec) = fVar1;
  return;
}



/* SP_info_notnull @ 1000eaa0 status created size 59 */

void SP_info_notnull(int param_1)

{
  *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0xdc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(param_1 + 0xc);
  return;
}



/* SP_light @ 1000eae0 status created size 117 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_light(undefined4 *param_1)

{
  int iVar1;
  
  if ((param_1[0x4b] == 0) || (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c)) {
    G_FreeEdict(param_1);
  }
  else {
    iVar1 = param_1[0xb2];
    if (0x1f < iVar1) {
      param_1[0x80] = light_use;
      if ((*(byte *)(param_1 + 0x47) & 1) != 0) {
        (*DAT_1006c1d8)(iVar1 + 800,&DAT_10049284);
        return;
      }
      (*DAT_1006c1d8)(iVar1 + 800,&DAT_10049280);
      return;
    }
  }
  return;
}



/* light_use @ 1000eb60 status existing size 99 */

void __cdecl light_use(int param_1)

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



/* SP_misc_banner @ 10010200 status existing size 93 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_misc_banner(int param_1)

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



/* SP_misc_viper @ 100103f0 status existing size 256 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_misc_viper(undefined4 *param_1)

{
  float fVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  if (param_1[0x4a] == 0) {
    puVar4 = param_1 + 0x35;
    puVar2 = vtos();
    (*DAT_1006c1c4)(s_misc_viper_without_a_target_at___10049444,puVar2,puVar4);
    G_FreeEdict(param_1);
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
  param_1[0x7d] = func_train_find;
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



/* SP_misc_bigviper @ 100104f0 status existing size 111 */

void __cdecl SP_misc_bigviper(int param_1)

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



/* SP_misc_strogg_ship @ 100107f0 status existing size 263 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_misc_strogg_ship(undefined4 *param_1)

{
  float fVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  if (param_1[0x4a] == 0) {
    puVar4 = param_1 + 0x35;
    puVar2 = vtos();
    (*DAT_1006c1c4)(s__s_without_a_target_at__s_100494d4,param_1[0x46],puVar2,puVar4);
    G_FreeEdict(param_1);
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
  param_1[0x7d] = func_train_find;
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



/* SP_misc_satellite_dish @ 10010960 status existing size 109 */

void __cdecl SP_misc_satellite_dish(int param_1)

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



/* SP_light_mine1 @ 100109d0 status existing size 51 */

void __cdecl SP_light_mine1(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 2;
  uVar1 = (*DAT_1006c1e0)(s_models_objects_minelite_light1_t_10049514);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  (*DAT_1006c208)(param_1);
  return;
}



/* SP_light_mine2 @ 10010a10 status existing size 51 */

void __cdecl SP_light_mine2(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 2;
  uVar1 = (*DAT_1006c1e0)(s_models_objects_minelite_light2_t_1004953c);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  (*DAT_1006c208)(param_1);
  return;
}



/* SP_misc_gib_arm @ 10010a50 status existing size 239 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_misc_gib_arm(int param_1)

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
  *(code **)(param_1 + 500) = G_FreeEdict;
  *(float *)(param_1 + 0x18c) = (float)(uVar1 & 0x7fff) * _DAT_10044108 * _DAT_100441e8;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + _DAT_10044220;
  (*DAT_1006c208)(param_1);
  return;
}



/* SP_misc_gib_leg @ 10010b40 status existing size 239 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_misc_gib_leg(int param_1)

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
  *(code **)(param_1 + 500) = G_FreeEdict;
  *(float *)(param_1 + 0x18c) = (float)(uVar1 & 0x7fff) * _DAT_10044108 * _DAT_100441e8;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + _DAT_10044220;
  (*DAT_1006c208)(param_1);
  return;
}



/* SP_misc_gib_head @ 10010c30 status existing size 239 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_misc_gib_head(int param_1)

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
  *(code **)(param_1 + 500) = G_FreeEdict;
  *(float *)(param_1 + 0x18c) = (float)(uVar1 & 0x7fff) * _DAT_10044108 * _DAT_100441e8;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + _DAT_10044220;
  (*DAT_1006c208)(param_1);
  return;
}



/* SP_target_character @ 10010d20 status existing size 58 */

void __cdecl SP_target_character(int param_1)

{
  *(undefined4 *)(param_1 + 0x104) = 2;
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  *(undefined4 *)(param_1 + 0xf8) = 3;
  *(undefined4 *)(param_1 + 0x38) = 0xc;
  (*DAT_1006c208)(param_1);
  return;
}



/* target_string_use @ 10010d60 status existing size 124 */

void __cdecl target_string_use(int param_1)

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



/* func_clock_format_countdown @ 10011000 status existing size 278 */

void __cdecl func_clock_format_countdown(int param_1)

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



/* SP_func_clock @ 10011160 status existing size 217 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_func_clock(undefined4 *param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (param_1[0x4a] == 0) {
    puVar3 = param_1 + 1;
    puVar1 = vtos();
    (*DAT_1006c1c4)(s__s_with_no_target_at__s_10049600,param_1[0x46],puVar1,puVar3);
    G_FreeEdict(param_1);
    return;
  }
  if (((param_1[0x47] & 2) != 0) && (param_1[0x95] == 0)) {
    puVar3 = param_1 + 1;
    puVar1 = vtos();
    (*DAT_1006c1c4)(s__s_with_no_count_at__s_100495e8,param_1[0x46],puVar1,puVar3);
    G_FreeEdict(param_1);
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



/* teleporter_touch @ 10011240 status existing size 321 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl teleporter_touch(int param_1,int param_2)

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
    uVar6 = G_Find(0,300,*(byte **)(param_1 + 0x128));
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
    KillBox(iVar5);
    (*DAT_1006c208)(iVar5);
  }
  return;
}



/* SP_misc_teleporter @ 10011390 status existing size 271 */

void __cdecl SP_misc_teleporter(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1[0x4a] == 0) {
    (*DAT_1006c1c4)(s_teleporter_without_a_target__10049668);
    G_FreeEdict(param_1);
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
  piVar3 = G_Spawn();
  piVar3[0x7f] = (int)teleporter_touch;
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



/* SP_misc_teleporter_dest @ 100114a0 status existing size 100 */

void __cdecl SP_misc_teleporter_dest(int param_1)

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



/* monster_fire_deatom @ 10011af0 status created size 34 */

void monster_fire_deatom(float param_1,int *param_2,float *param_3,int param_4,float param_5)

{
  fire_deatom(param_1,param_2,param_3,param_4,param_5);
  return;
}



/* ShutdownGame @ 1000d460 status created size 37 */

void ShutdownGame(void)

{
  (*DAT_1006c1c4)(s______ShutdownGame______10049144);
  (*DAT_1006c24c)(0x2fe);
  (*DAT_1006c24c)(0x2fd);
  return;
}



/* G_RunFrame @ 1000d940 status created size 244 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void G_RunFrame(void)

{
  float *pfVar1;
  int iStack_4;
  
  DAT_1006c2e0 = DAT_1006c2e0 + 1;
  DAT_1006c2e4 = (float)DAT_1006c2e0 * (float)_DAT_10044168;
  AI_SetSightClient();
  if (DAT_1006c3b0 == 0) {
    iStack_4 = 0;
    pfVar1 = DAT_1006c2c4;
    if (0 < DAT_1006c168) {
      do {
        if (pfVar1[0x16] != 0.0) {
          DAT_1006c404 = pfVar1;
          pfVar1[7] = pfVar1[1];
          pfVar1[8] = pfVar1[2];
          pfVar1[9] = pfVar1[3];
          if ((((pfVar1[0x9a] != 0.0) && (*(float *)((int)pfVar1[0x9a] + 0x5c) != pfVar1[0x9b])) &&
              (pfVar1[0x9a] = 0.0, ((uint)pfVar1[0x42] & 3) == 0)) &&
             (((uint)pfVar1[0x2e] & 4) != 0)) {
            M_CheckGround((int)pfVar1);
          }
          if ((iStack_4 < 1) || (*(float *)(DAT_1006ca60 + 0x14) < (float)iStack_4)) {
            G_RunEntity(pfVar1);
          }
          else {
            ClientBeginServerFrame((int *)pfVar1);
          }
        }
        iStack_4 = iStack_4 + 1;
        pfVar1 = pfVar1 + 0xf4;
      } while (iStack_4 < DAT_1006c168);
    }
    CheckDMRules();
    ClientEndServerFrames();
    return;
  }
  ExitLevel();
  return;
}



/* ClientEndServerFrames @ 1000d5a0 status existing size 99 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ClientEndServerFrames(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (_DAT_1004410c < *(float *)(DAT_1006ca60 + 0x14)) {
    iVar1 = 0x3d0;
    do {
      if ((*(int *)(iVar1 + 0x58 + DAT_1006c2c4) != 0) &&
         (*(int *)(iVar1 + DAT_1006c2c4 + 0x54) != 0)) {
        ClientEndServerFrame((float)(iVar1 + DAT_1006c2c4));
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x3d0;
    } while ((float)iVar2 < *(float *)(DAT_1006ca60 + 0x14));
  }
  return;
}



/* CreateTargetChangeLevel @ 1000d610 status existing size 57 */

int * CreateTargetChangeLevel(void)

{
  int *piVar1;
  
  piVar1 = G_Spawn();
  piVar1[0x46] = (int)s_target_changelevel_1004915c;
  FUN_10038b40();
  piVar1[0x8e] = (int)&DAT_1006c368;
  return piVar1;
}



/* EndDMLevel @ 1000d650 status existing size 280 */

void EndDMLevel(void)

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
          piVar1 = CreateTargetChangeLevel();
          BeginIntermission((int)piVar1);
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
      piVar1 = CreateTargetChangeLevel();
      BeginIntermission((int)piVar1);
      return;
    }
    uVar5 = G_Find(0,0x118,(byte *)s_target_changelevel_1004915c);
    if (uVar5 != 0) {
      BeginIntermission(uVar5);
      return;
    }
  }
  piVar1 = CreateTargetChangeLevel();
  BeginIntermission((int)piVar1);
  return;
}



/* CheckDMRules @ 1000d770 status existing size 251 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CheckDMRules(void)

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
  EndDMLevel();
  return;
}



/* ExitLevel @ 1000d870 status existing size 202 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ExitLevel(void)

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
  ClientEndServerFrames();
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



/* FindItem @ 1000b150 status existing size 69 */

undefined4 * __cdecl FindItem(byte *param_1)

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



/* FindItemByClassname @ 1000b100 status existing size 68 */

undefined4 * __cdecl FindItemByClassname(byte *param_1)

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



/* GetItemByIndex @ 1000b0e0 status existing size 30 */

undefined4 * __cdecl GetItemByIndex(int param_1)

{
  if ((param_1 != 0) && (param_1 < DAT_1006ca54)) {
    return &DAT_10046928 + param_1 * 0x12;
  }
  return (undefined4 *)0x0;
}



/* DoRespawn @ 1000b1a0 status existing size 104 */

void __cdecl DoRespawn(int param_1)

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



/* SetRespawn @ 1000b210 status existing size 82 */

void __cdecl SetRespawn(int param_1,float param_2)

{
  float fVar1;
  
  *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) | 0x80000000;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  fVar1 = DAT_1006c2e4 + param_2;
  *(code **)(param_1 + 500) = DoRespawn;
  *(float *)(param_1 + 0x1ec) = fVar1;
  (*DAT_1006c208)(param_1);
  return;
}



/* Pickup_Powerup @ 1000b270 status existing size 322 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl Pickup_Powerup(int param_1,int param_2)

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
        SetRespawn(param_1,(float)*(int *)(*(int *)(param_1 + 0x2cc) + 0x30));
      }
      uVar3 = __ftol();
      if (((uVar3 & 0x10) != 0) ||
         ((*(code **)(*(int *)(param_1 + 0x2cc) + 8) == Use_Quad &&
          ((*(uint *)(param_1 + 0x11c) & 0x20000) != 0)))) {
        if ((*(code **)(*(int *)(param_1 + 0x2cc) + 8) == Use_Quad) &&
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



/* Drop_General @ 1000b3c0 status existing size 72 */

void __cdecl Drop_General(int param_1,int *param_2)

{
  Drop_Item(param_1,param_2);
  *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(param_2 + -0x4011a4a) / 0x48) * 4) =
       *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(param_2 + -0x4011a4a) / 0x48) * 4) + -1;
  ValidateSelectedItem(param_1);
  return;
}



/* Pickup_Adrenaline @ 1000b410 status created size 119 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pickup_Adrenaline(int param_1,int param_2)

{
  if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
    *(int *)(param_2 + 0x224) = *(int *)(param_2 + 0x224) + 1;
  }
  if (*(int *)(param_2 + 0x220) < *(int *)(param_2 + 0x224)) {
    *(int *)(param_2 + 0x220) = *(int *)(param_2 + 0x224);
  }
  if (((*(uint *)(param_1 + 0x11c) & 0x10000) == 0) &&
     (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c)) {
    SetRespawn(param_1,(float)*(int *)(*(int *)(param_1 + 0x2cc) + 0x30));
  }
  return 1;
}



/* Pickup_AncientHead @ 1000b490 status created size 84 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pickup_AncientHead(int param_1,int param_2)

{
  *(int *)(param_2 + 0x224) = *(int *)(param_2 + 0x224) + 2;
  if (((*(uint *)(param_1 + 0x11c) & 0x10000) == 0) &&
     (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c)) {
    SetRespawn(param_1,(float)*(int *)(*(int *)(param_1 + 0x2cc) + 0x30));
  }
  return 1;
}



/* Pickup_Bandolier @ 1000b4f0 status existing size 337 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl Pickup_Bandolier(int param_1,int param_2)

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
  puVar4 = FindItem((byte *)s_Bullets_10048a60);
  if (puVar4 != (undefined4 *)0x0) {
    iVar3 = (int)(puVar4 + -0x4011a4a) / 0x48;
    piVar1 = (int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4);
    *piVar1 = *piVar1 + puVar4[0xc];
    iVar2 = *(int *)(param_2 + 0x54);
    if (*(int *)(iVar2 + 0x6e4) < *(int *)(iVar2 + 0x2e4 + iVar3 * 4)) {
      *(int *)(iVar2 + 0x2e4 + iVar3 * 4) = *(int *)(iVar2 + 0x6e4);
    }
  }
  puVar4 = FindItem((byte *)s_Shells_10048b88);
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
    SetRespawn(param_1,(float)*(int *)(*(int *)(param_1 + 0x2cc) + 0x30));
  }
  return 1;
}



/* Pickup_Pack @ 1000b650 status existing size 824 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl Pickup_Pack(int param_1,int param_2)

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
  puVar4 = FindItem((byte *)s_Bullets_10048a60);
  if (puVar4 != (undefined4 *)0x0) {
    iVar3 = (int)(puVar4 + -0x4011a4a) / 0x48;
    *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) =
         *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) + puVar4[0xc];
    iVar2 = *(int *)(param_2 + 0x54);
    if (*(int *)(iVar2 + 0x6e4) < *(int *)(iVar2 + 0x2e4 + iVar3 * 4)) {
      *(int *)(iVar2 + 0x2e4 + iVar3 * 4) = *(int *)(iVar2 + 0x6e4);
    }
  }
  puVar4 = FindItem((byte *)s_Shells_10048b88);
  if (puVar4 != (undefined4 *)0x0) {
    iVar3 = (int)(puVar4 + -0x4011a4a) / 0x48;
    *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) =
         *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) + puVar4[0xc];
    iVar2 = *(int *)(param_2 + 0x54);
    if (*(int *)(iVar2 + 0x6e8) < *(int *)(iVar2 + 0x2e4 + iVar3 * 4)) {
      *(int *)(iVar2 + 0x2e4 + iVar3 * 4) = *(int *)(iVar2 + 0x6e8);
    }
  }
  puVar4 = FindItem((byte *)s_Cells_1004662c);
  if (puVar4 != (undefined4 *)0x0) {
    iVar3 = (int)(puVar4 + -0x4011a4a) / 0x48;
    *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) =
         *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) + puVar4[0xc];
    iVar2 = *(int *)(param_2 + 0x54);
    if (*(int *)(iVar2 + 0x6f8) < *(int *)(iVar2 + 0x2e4 + iVar3 * 4)) {
      *(int *)(iVar2 + 0x2e4 + iVar3 * 4) = *(int *)(iVar2 + 0x6f8);
    }
  }
  puVar4 = FindItem((byte *)s_Grenades_10046384);
  if (puVar4 != (undefined4 *)0x0) {
    iVar3 = (int)(puVar4 + -0x4011a4a) / 0x48;
    *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) =
         *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) + puVar4[0xc];
    iVar2 = *(int *)(param_2 + 0x54);
    if (*(int *)(iVar2 + 0x6f0) < *(int *)(iVar2 + 0x2e4 + iVar3 * 4)) {
      *(int *)(iVar2 + 0x2e4 + iVar3 * 4) = *(int *)(iVar2 + 0x6f0);
    }
  }
  puVar4 = FindItem((byte *)s_Rockets_100485a0);
  if (puVar4 != (undefined4 *)0x0) {
    iVar3 = (int)(puVar4 + -0x4011a4a) / 0x48;
    *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) =
         *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar3 * 4) + puVar4[0xc];
    iVar2 = *(int *)(param_2 + 0x54);
    if (*(int *)(iVar2 + 0x6ec) < *(int *)(iVar2 + 0x2e4 + iVar3 * 4)) {
      *(int *)(iVar2 + 0x2e4 + iVar3 * 4) = *(int *)(iVar2 + 0x6ec);
    }
  }
  puVar4 = FindItem((byte *)s_Slugs_10048370);
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
    SetRespawn(param_1,(float)*(int *)(*(int *)(param_1 + 0x2cc) + 0x30));
  }
  return 1;
}



/* Use_Quad @ 1000b990 status created size 193 */

void Use_Quad(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = param_1;
  iVar1 = (param_2 + -0x10046928) / 0x48;
  *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + iVar1 * 4) =
       *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + iVar1 * 4) + -1;
  ValidateSelectedItem(param_1);
  param_1 = DAT_10060e68;
  if (DAT_10060e68 == 0) {
    param_1 = 300;
  }
  else {
    DAT_10060e68 = 0;
  }
  iVar1 = *(int *)(iVar3 + 0x54);
  if (*(float *)(iVar1 + 0xeac) <= (float)DAT_1006c2e0) {
    fVar2 = (float)(DAT_1006c2e0 + param_1);
  }
  else {
    fVar2 = (float)param_1 + *(float *)(iVar1 + 0xeac);
  }
  *(float *)(iVar1 + 0xeac) = fVar2;
  uVar4 = (*DAT_1006c1e4)(s_items_damage_wav_10048f28,0x3f800000,0x3f800000,0);
  (*DAT_1006c1d0)(iVar3,3,uVar4);
  return;
}



/* Use_Breather @ 1000ba60 status created size 131 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Use_Breather(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (param_2 + -0x10046928) / 0x48;
  *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + iVar1 * 4) =
       *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + iVar1 * 4) + -1;
  ValidateSelectedItem(param_1);
  iVar1 = *(int *)(param_1 + 0x54);
  if ((float)DAT_1006c2e0 < *(float *)(iVar1 + 0xeb4)) {
    *(float *)(iVar1 + 0xeb4) = *(float *)(iVar1 + 0xeb4) + _DAT_100441c4;
    return;
  }
  *(float *)(iVar1 + 0xeb4) = (float)(DAT_1006c2e0 + 300);
  return;
}



/* Use_Envirosuit @ 1000baf0 status created size 131 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Use_Envirosuit(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (param_2 + -0x10046928) / 0x48;
  *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + iVar1 * 4) =
       *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + iVar1 * 4) + -1;
  ValidateSelectedItem(param_1);
  iVar1 = *(int *)(param_1 + 0x54);
  if ((float)DAT_1006c2e0 < *(float *)(iVar1 + 0xeb8)) {
    *(float *)(iVar1 + 0xeb8) = *(float *)(iVar1 + 0xeb8) + _DAT_100441c4;
    return;
  }
  *(float *)(iVar1 + 0xeb8) = (float)(DAT_1006c2e0 + 300);
  return;
}



/* Use_Invulnerability @ 1000bb80 status created size 164 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Use_Invulnerability(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  undefined4 uVar3;
  
  iVar1 = (param_2 + -0x10046928) / 0x48;
  *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + iVar1 * 4) =
       *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + iVar1 * 4) + -1;
  ValidateSelectedItem(param_1);
  iVar1 = *(int *)(param_1 + 0x54);
  if (*(float *)(iVar1 + 0xeb0) <= (float)DAT_1006c2e0) {
    fVar2 = (float)(DAT_1006c2e0 + 300);
  }
  else {
    fVar2 = *(float *)(iVar1 + 0xeb0) + _DAT_100441c4;
  }
  *(float *)(iVar1 + 0xeb0) = fVar2;
  uVar3 = (*DAT_1006c1e4)(s_items_protect_wav_10048f3c,0x3f800000,0x3f800000,0);
  (*DAT_1006c1d0)(param_1,3,uVar3);
  return;
}



/* Use_Silencer @ 1000bc30 status created size 81 */

void Use_Silencer(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (param_2 + -0x10046928) / 0x48;
  *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + iVar1 * 4) =
       *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + iVar1 * 4) + -1;
  ValidateSelectedItem(param_1);
  *(int *)(*(int *)(param_1 + 0x54) + 0xec4) = *(int *)(*(int *)(param_1 + 0x54) + 0xec4) + 0x1e;
  return;
}



/* Pickup_Key @ 1000bc90 status created size 345 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pickup_Key(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  char *pcVar5;
  bool bVar6;
  
  if (*(float *)(DAT_1006c42c + 0x14) == _DAT_1004410c) {
    iVar4 = (*(int *)(param_1 + 0x2cc) + -0x10046928) / 0x48;
    *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar4 * 4) =
         *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar4 * 4) + 1;
    return 1;
  }
  pcVar5 = s_key_power_cube_10047b64;
  pbVar3 = *(byte **)(param_1 + 0x118);
  do {
    bVar1 = *pbVar3;
    bVar6 = bVar1 < (byte)*pcVar5;
    if (bVar1 != *pcVar5) {
LAB_1000bce4:
      iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      goto LAB_1000bce9;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar3[1];
    bVar6 = bVar1 < (byte)pcVar5[1];
    if (bVar1 != pcVar5[1]) goto LAB_1000bce4;
    pbVar3 = pbVar3 + 2;
    pcVar5 = pcVar5 + 2;
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_1000bce9:
  if (iVar4 != 0) {
    iVar4 = (*(int *)(param_1 + 0x2cc) + -0x10046928) / 0x48;
    if (*(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar4 * 4) != 0) {
      return 0;
    }
    *(undefined4 *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar4 * 4) = 1;
    return 1;
  }
  iVar4 = *(int *)(param_2 + 0x54);
  if ((*(byte *)(iVar4 + 0x71c) & (byte)((uint)*(undefined4 *)(param_1 + 0x11c) >> 8)) != 0) {
    return 0;
  }
  iVar2 = (*(int *)(param_1 + 0x2cc) + -0x10046928) / 0x48;
  *(int *)(iVar4 + 0x2e4 + iVar2 * 4) = *(int *)(iVar4 + 0x2e4 + iVar2 * 4) + 1;
  *(uint *)(*(int *)(param_2 + 0x54) + 0x71c) =
       *(uint *)(*(int *)(param_2 + 0x54) + 0x71c) | (uint)*(byte *)(param_1 + 0x11d);
  return 1;
}



/* Add_Ammo @ 1000bdf0 status existing size 253 */

undefined4 __cdecl Add_Ammo(int param_1,int param_2,int param_3)

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



/* Pickup_Ammo @ 1000bef0 status existing size 278 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl Pickup_Ammo(int param_1,int param_2)

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
  iVar2 = Add_Ammo(param_2,iVar2,iVar4);
  if (iVar2 != 0) {
    if ((((uVar5 != 0) && (iVar1 == 0)) &&
        (iVar2 = *(int *)(param_2 + 0x54), *(int *)(iVar2 + 0x714) != *(int *)(param_1 + 0x2cc))) &&
       ((*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c ||
        (puVar3 = FindItem((byte *)s_blaster_10048f64), *(undefined4 **)(iVar2 + 0x714) == puVar3)))
       ) {
      *(undefined4 *)(iVar2 + 0xdfc) = *(undefined4 *)(param_1 + 0x2cc);
    }
    if (((*(uint *)(param_1 + 0x11c) & 0x30000) == 0) &&
       (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c)) {
      SetRespawn(param_1,30.0);
    }
    return 1;
  }
  return 0;
}



/* Drop_Ammo @ 1000c010 status existing size 193 */

void __cdecl Drop_Ammo(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = (int)(param_2 + -0x4011a4a) / 0x48;
  piVar4 = Drop_Item(param_1,param_2);
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
    G_FreeEdict(piVar4);
    return;
  }
  *(int *)(iVar1 + 0x2e4 + iVar3 * 4) = *(int *)(iVar1 + 0x2e4 + iVar3 * 4) - piVar4[0x95];
  ValidateSelectedItem(param_1);
  return;
}



/* MegaHealth_think @ 1000c0e0 status created size 109 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MegaHealth_think(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x40];
  if (*(int *)(iVar1 + 0x224) < *(int *)(iVar1 + 0x220)) {
    param_1[0x7b] = DAT_1006c2e4 + _DAT_10044104;
    *(int *)(iVar1 + 0x220) = *(int *)(iVar1 + 0x220) + -1;
    return;
  }
  if (((param_1[0x47] & 0x10000) == 0) && (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c)) {
    SetRespawn((int)param_1,20.0);
    return;
  }
  G_FreeEdict(param_1);
  return;
}



/* Pickup_Health @ 1000c150 status created size 308 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pickup_Health(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  
  if (((*(byte *)(param_1 + 0x2c8) & 1) == 0) &&
     (*(int *)(param_2 + 0x224) <= *(int *)(param_2 + 0x220))) {
    return 0;
  }
  *(int *)(param_2 + 0x220) = *(int *)(param_2 + 0x220) + *(int *)(param_1 + 0x254);
  iVar1 = *(int *)(param_1 + 0x254);
  if (iVar1 == 2) {
    *(char **)(*(int *)(param_1 + 0x2cc) + 0x14) = s_items_s_health_wav_10048fc4;
  }
  else if (iVar1 == 10) {
    *(char **)(*(int *)(param_1 + 0x2cc) + 0x14) = s_items_n_health_wav_10048fb0;
  }
  else if (iVar1 == 0x19) {
    *(char **)(*(int *)(param_1 + 0x2cc) + 0x14) = s_items_l_health_wav_10048f9c;
  }
  else {
    *(char **)(*(int *)(param_1 + 0x2cc) + 0x14) = s_items_m_health_wav_10048f88;
  }
  if (((*(byte *)(param_1 + 0x2c8) & 1) == 0) &&
     (*(int *)(param_2 + 0x224) < *(int *)(param_2 + 0x220))) {
    *(int *)(param_2 + 0x220) = *(int *)(param_2 + 0x224);
  }
  if ((*(byte *)(param_1 + 0x2c8) & 2) != 0) {
    *(code **)(param_1 + 500) = MegaHealth_think;
    fVar2 = DAT_1006c2e4 + _DAT_1004414c;
    *(int *)(param_1 + 0x100) = param_2;
    *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
    *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) | 0x80000000;
    *(float *)(param_1 + 0x1ec) = fVar2;
    *(undefined4 *)(param_1 + 0xf8) = 0;
    return 1;
  }
  if (((*(uint *)(param_1 + 0x11c) & 0x10000) == 0) &&
     (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c)) {
    SetRespawn(param_1,30.0);
  }
  return 1;
}



/* ArmorIndex @ 1000c290 status existing size 71 */

uint __cdecl ArmorIndex(int param_1)

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



/* Pickup_Armor @ 1000c2e0 status existing size 376 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl Pickup_Armor(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  longlong lVar7;
  
  piVar2 = *(int **)(*(int *)(param_1 + 0x2cc) + 0x3c);
  uVar3 = ArmorIndex(param_2);
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
    SetRespawn(param_1,20.0);
  }
  return 1;
}



/* PowerArmorType @ 1000c460 status existing size 74 */

bool __cdecl PowerArmorType(int param_1)

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



/* Use_PowerArmor @ 1000c4b0 status existing size 171 */

void __cdecl Use_PowerArmor(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if ((*(uint *)(param_1 + 0x108) & 0x1000) == 0) {
    puVar1 = FindItem((byte *)s_cells_10049004);
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



/* Pickup_PowerArmor @ 1000c560 status existing size 144 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl Pickup_PowerArmor(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (*(int *)(param_1 + 0x2cc) + -0x10046928) / 0x48;
  iVar1 = *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar2 * 4);
  *(int *)(*(int *)(param_2 + 0x54) + 0x2e4 + iVar2 * 4) = iVar1 + 1;
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    if ((*(uint *)(param_1 + 0x11c) & 0x10000) == 0) {
      SetRespawn(param_1,(float)*(int *)(*(int *)(param_1 + 0x2cc) + 0x30));
    }
    if (iVar1 == 0) {
      (**(code **)(*(int *)(param_1 + 0x2cc) + 8))(param_2,*(int *)(param_1 + 0x2cc));
    }
  }
  return 1;
}



/* Drop_PowerArmor @ 1000c5f0 status existing size 82 */

void __cdecl Drop_PowerArmor(int param_1,int *param_2)

{
  if (((*(uint *)(param_1 + 0x108) & 0x1000) != 0) &&
     (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(param_2 + -0x4011a4a) / 0x48) * 4) == 1)) {
    Use_PowerArmor(param_1);
  }
  Drop_General(param_1,param_2);
  return;
}



/* Touch_Item @ 1000c650 status existing size 510 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Touch_Item(undefined4 *param_1,int param_2)

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
    if (*(code **)(param_1[0xb3] + 4) == Pickup_Health) {
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
    G_UseTargets((uint)param_1,param_2);
    param_1[0x47] = param_1[0x47] | 0x40000;
  }
  if ((iVar2 != 0) &&
     (((*(float *)(DAT_1006c42c + 0x14) == _DAT_1004410c ||
       ((*(byte *)(param_1[0xb3] + 0x38) & 8) == 0)) || ((param_1[0x47] & 0x30000) != 0)))) {
    if ((param_1[0x42] & 0x80000000) != 0) {
      param_1[0x42] = param_1[0x42] & 0x7fffffff;
      return;
    }
    G_FreeEdict(param_1);
  }
  return;
}



/* Drop_Item @ 1000c850 status existing size 442 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __cdecl Drop_Item(int param_1,int *param_2)

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
  
  piVar2 = G_Spawn();
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
  piVar2[0x7f] = (int)drop_temp_touch;
  piVar2[0x40] = param_1;
  if (*(int *)(param_1 + 0x54) == 0) {
    AngleVectors((float *)(param_1 + 0x10),afStack_5c + 3,afStack_44,(float *)0x0);
    piVar2[1] = *(int *)(param_1 + 4);
    piVar2[2] = *(int *)(param_1 + 8);
    piVar2[3] = *(int *)(param_1 + 0xc);
  }
  else {
    AngleVectors((float *)(*(int *)(param_1 + 0x54) + 0xe64),afStack_5c + 3,afStack_44,(float *)0x0)
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
  VectorScale(afStack_5c + 3,100.0,(float *)(piVar2 + 0x5e));
  piVar2[0x60] = 0x43960000;
  piVar2[0x7d] = (int)drop_make_touchable;
  piVar2[0x7b] = (int)(DAT_1006c2e4 + _DAT_10044104);
  (*DAT_1006c208)(piVar2);
  return piVar2;
}



/* drop_temp_touch @ 1000ca10 status created size 37 */

void drop_temp_touch(undefined4 *param_1,int param_2)

{
  if (param_2 != param_1[0x40]) {
    Touch_Item(param_1,param_2);
  }
  return;
}



/* drop_make_touchable @ 1000ca40 status created size 64 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void drop_make_touchable(int param_1)

{
  float fVar1;
  
  *(code **)(param_1 + 0x1fc) = Touch_Item;
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    fVar1 = DAT_1006c2e4 + _DAT_100441d0;
    *(code **)(param_1 + 500) = G_FreeEdict;
    *(float *)(param_1 + 0x1ec) = fVar1;
  }
  return;
}



/* Use_Item @ 1000ca80 status created size 94 */

void Use_Item(int param_1)

{
  *(undefined4 *)(param_1 + 0x200) = 0;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffe;
  if ((*(byte *)(param_1 + 0x11c) & 2) != 0) {
    *(undefined4 *)(param_1 + 0xf8) = 2;
    *(undefined4 *)(param_1 + 0x1fc) = 0;
    (*DAT_1006c208)(param_1);
    return;
  }
  *(undefined4 *)(param_1 + 0xf8) = 1;
  *(code **)(param_1 + 0x1fc) = Touch_Item;
  (*DAT_1006c208)(param_1);
  return;
}



/* droptofloor @ 1000cae0 status created size 530 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void droptofloor(undefined4 *param_1)

{
  float fVar1;
  undefined4 *puVar2;
  float *pfVar3;
  int *piVar4;
  undefined *puVar5;
  int iVar6;
  int *piVar7;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  int aiStack_38 [4];
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  puVar2 = (undefined4 *)tv(0xc1700000,0xc1700000,0xc1700000);
  param_1[0x2f] = *puVar2;
  param_1[0x30] = puVar2[1];
  param_1[0x31] = puVar2[2];
  puVar2 = (undefined4 *)tv(0x41700000,0x41700000,0x41700000);
  param_1[0x32] = *puVar2;
  param_1[0x33] = puVar2[1];
  param_1[0x34] = puVar2[2];
  iVar6 = param_1[0x43];
  if (iVar6 == 0) {
    iVar6 = *(int *)(param_1[0xb3] + 0x18);
  }
  (*DAT_1006c1ec)(param_1,iVar6);
  param_1[0x3e] = 1;
  param_1[0x41] = 7;
  param_1[0x7f] = Touch_Item;
  pfVar3 = (float *)tv(0,0,0xc3000000);
  fStack_44 = *pfVar3 + (float)param_1[1];
  puVar2 = param_1 + 1;
  fStack_40 = pfVar3[1] + (float)param_1[2];
  fStack_3c = pfVar3[2] + (float)param_1[3];
  piVar4 = (int *)(*DAT_1006c1f0)(aiStack_38,puVar2,param_1 + 0x2f,param_1 + 0x32,&fStack_44,param_1
                                  ,3);
  piVar7 = aiStack_38;
  for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar7 = *piVar4;
    piVar4 = piVar4 + 1;
    piVar7 = piVar7 + 1;
  }
  if (aiStack_38[1] == 0) {
    *puVar2 = aiStack_38[3];
    param_1[3] = uStack_24;
    param_1[2] = uStack_28;
    if (param_1[0x4d] != 0) {
      param_1[0x96] = param_1[0x9c];
      param_1[0x42] = param_1[0x42] & 0xfffffbff;
      param_1[0x9c] = 0;
      param_1[0x2e] = param_1[0x2e] | 1;
      param_1[0x3e] = 0;
      if (param_1 == (undefined4 *)param_1[0x9d]) {
        fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
        param_1[0x7d] = DoRespawn;
        param_1[0x7b] = fVar1;
      }
    }
    if ((param_1[0x47] & 2) != 0) {
      param_1[0x3e] = 2;
      param_1[0x7f] = 0;
      param_1[0x10] = param_1[0x10] & 0xfffffffe;
      param_1[0x11] = param_1[0x11] & 0xfffffdff;
    }
    if ((param_1[0x47] & 1) != 0) {
      param_1[0x3e] = 0;
      param_1[0x80] = Use_Item;
      param_1[0x2e] = param_1[0x2e] | 1;
    }
    (*DAT_1006c208)(param_1);
    return;
  }
  puVar5 = vtos();
  (*DAT_1006c1c4)(s_droptofloor___s_startsolid_at__s_1004901c,param_1[0x46],puVar5,puVar2);
  G_FreeEdict(param_1);
  return;
}



/* PrecacheItem @ 1000cd00 status existing size 537 */

void __cdecl PrecacheItem(undefined4 *param_1)

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
       (puVar3 = FindItem(pbVar6), puVar3 != param_1)) {
      PrecacheItem(puVar3);
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



/* SpawnItem @ 1000cf20 status existing size 575 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SpawnItem(undefined4 *param_1,undefined4 *param_2)

{
  byte bVar1;
  code *pcVar2;
  undefined4 uVar3;
  float fVar4;
  byte *pbVar5;
  int iVar6;
  undefined *puVar7;
  char *pcVar8;
  bool bVar9;
  ulonglong uVar10;
  undefined4 *puVar11;
  
  PrecacheItem(param_2);
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
      puVar7 = vtos();
      (*DAT_1006c1c4)(s__s_at__s_has_invalid_spawnflags_s_1004907c,param_1[0x46],puVar7,puVar11);
    }
  }
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    uVar10 = __ftol();
    if (((uVar10 & 0x800) != 0) &&
       (((code *)param_2[1] == Pickup_Armor || ((code *)param_2[1] == Pickup_PowerArmor)))) {
      G_FreeEdict(param_1);
      return;
    }
    if (((uVar10 & 2) != 0) && ((code *)param_2[1] == Pickup_Powerup)) {
      G_FreeEdict(param_1);
      return;
    }
    if (((uVar10 & 1) != 0) &&
       (((pcVar2 = (code *)param_2[1], pcVar2 == Pickup_Health || (pcVar2 == Pickup_Adrenaline)) ||
        (pcVar2 == Pickup_AncientHead)))) {
      G_FreeEdict(param_1);
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
      G_FreeEdict(param_1);
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
  param_1[0x7d] = droptofloor;
  param_1[0x7b] = fVar4;
  uVar3 = param_2[7];
  param_1[0x11] = 0x200;
  param_1[0x10] = uVar3;
  if (param_1[0x43] != 0) {
    (*DAT_1006c1e0)(param_1[0x43]);
  }
  return;
}



/* SP_item_health @ 1000d160 status existing size 111 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_item_health(undefined4 *param_1)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    uVar2 = __ftol();
    if ((uVar2 & 1) != 0) {
      G_FreeEdict(param_1);
      return;
    }
  }
  param_1[0x43] = s_models_items_healing_medium_tris_100490a4;
  param_1[0x95] = 10;
  puVar1 = FindItem((byte *)s_Health_100478ec);
  SpawnItem(param_1,puVar1);
  (*DAT_1006c1e4)(s_items_n_health_wav_10048fb0);
  return;
}



/* SP_item_health_small @ 1000d1d0 status created size 121 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_item_health_small(undefined4 *param_1)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    uVar2 = __ftol();
    if ((uVar2 & 1) != 0) {
      G_FreeEdict(param_1);
      return;
    }
  }
  param_1[0x43] = s_models_items_healing_stimpack_tr_100490cc;
  param_1[0x95] = 2;
  puVar1 = FindItem((byte *)s_Health_100478ec);
  SpawnItem(param_1,puVar1);
  param_1[0xb2] = 1;
  (*DAT_1006c1e4)(s_items_s_health_wav_10048fc4);
  return;
}



/* SP_item_health_large @ 1000d250 status created size 111 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_item_health_large(undefined4 *param_1)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    uVar2 = __ftol();
    if ((uVar2 & 1) != 0) {
      G_FreeEdict(param_1);
      return;
    }
  }
  param_1[0x43] = s_models_items_healing_large_tris__100490f4;
  param_1[0x95] = 0x19;
  puVar1 = FindItem((byte *)s_Health_100478ec);
  SpawnItem(param_1,puVar1);
  (*DAT_1006c1e4)(s_items_l_health_wav_10048f9c);
  return;
}



/* SP_item_health_mega @ 1000d2c0 status created size 121 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_item_health_mega(undefined4 *param_1)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    uVar2 = __ftol();
    if ((uVar2 & 1) != 0) {
      G_FreeEdict(param_1);
      return;
    }
  }
  param_1[0x43] = s_models_items_mega_h_tris_md2_10049118;
  param_1[0x95] = 100;
  puVar1 = FindItem((byte *)s_Health_100478ec);
  SpawnItem(param_1,puVar1);
  (*DAT_1006c1e4)(s_items_m_health_wav_10048f88);
  param_1[0xb2] = 3;
  return;
}



/* InitItems @ 1000d340 status existing size 11 */

void InitItems(void)

{
  DAT_1006ca54 = 0x36;
  return;
}



/* SetItemNames @ 1000d350 status existing size 261 */

void SetItemNames(void)

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
  puVar2 = FindItem((byte *)s_Jacket_Armor_100461e0);
  DAT_10060e74 = (int)(puVar2 + -0x4011a4a) / 0x48;
  puVar2 = FindItem((byte *)s_Combat_Armor_100461d0);
  DAT_10060e70 = (int)(puVar2 + -0x4011a4a) / 0x48;
  puVar2 = FindItem((byte *)s_Body_Armor_100461c4);
  DAT_10060e78 = (int)(puVar2 + -0x4011a4a) / 0x48;
  puVar2 = FindItem((byte *)s_Power_Screen_10048d80);
  DAT_10060e6c = (int)(puVar2 + -0x4011a4a) / 0x48;
  puVar2 = FindItem((byte *)s_Power_Shield_100461b4);
  DAT_10060e64 = (int)(puVar2 + -0x4011a4a) / 0x48;
  return;
}



/* M_FlyCheck @ 10011b90 status existing size 112 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl M_FlyCheck(int param_1)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x2a8) == 0) {
    uVar1 = _rand();
    if ((float)(uVar1 & 0x7fff) * _DAT_10044108 <= (float)_DAT_10044140) {
      *(code **)(param_1 + 500) = M_FliesOn;
      uVar1 = _rand();
      *(float *)(param_1 + 0x1ec) =
           (float)(uVar1 & 0x7fff) * _DAT_10044108 * _DAT_100441b0 + DAT_1006c2e4 + _DAT_1004414c;
    }
  }
  return;
}



/* M_FliesOn @ 10011c00 status existing size 71 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl M_FliesOn(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x2a8) == 0) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x4000;
    uVar1 = (*DAT_1006c1e4)(s_infantry_inflies1_wav_100496a4);
    *(undefined4 *)(param_1 + 0x4c) = uVar1;
    *(code **)(param_1 + 500) = M_FliesOff;
    *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + _DAT_100441c0;
  }
  return;
}



/* M_FliesOff @ 10011c50 status created size 21 */

void M_FliesOff(int param_1)

{
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xffffbfff;
  return;
}



/* AttackFinished @ 10011c70 status existing size 21 */

void __cdecl AttackFinished(int param_1,float param_2)

{
  *(float *)(param_1 + 0x394) = DAT_1006c2e4 + param_2;
  return;
}



/* M_CheckGround @ 10011c90 status existing size 256 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl M_CheckGround(int param_1)

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



/* M_CatagorizePosition @ 10011d90 status existing size 183 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl M_CatagorizePosition(int param_1)

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



/* M_WorldEffects @ 10011e50 status existing size 794 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl M_WorldEffects(uint param_1)

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



/* M_droptofloor @ 10012170 status existing size 179 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl M_droptofloor(int param_1)

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
    M_CheckGround(param_1);
    M_CatagorizePosition(param_1);
  }
  return;
}



/* M_SetEffects @ 10012230 status existing size 129 */

void __cdecl M_SetEffects(int param_1)

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



/* M_MoveFrame @ 100122c0 status existing size 247 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl M_MoveFrame(int param_1)

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



/* monster_think @ 100123c0 status existing size 65 */

void __cdecl monster_think(uint param_1)

{
  M_MoveFrame(param_1);
  if (*(int *)(param_1 + 0x5c) != *(int *)(param_1 + 0x3c4)) {
    *(int *)(param_1 + 0x3c4) = *(int *)(param_1 + 0x5c);
    M_CheckGround(param_1);
  }
  M_CatagorizePosition(param_1);
  M_WorldEffects(param_1);
  M_SetEffects(param_1);
  return;
}



/* monster_use @ 10012410 status created size 69 */

void monster_use(int param_1,undefined4 param_2,int param_3)

{
  if ((((*(int *)(param_1 + 0x25c) == 0) && (0 < *(int *)(param_1 + 0x220))) &&
      ((*(byte *)(param_3 + 0x108) & 0x20) == 0)) &&
     ((*(int *)(param_3 + 0x54) != 0 || ((*(uint *)(param_3 + 0x35c) & 0x100) != 0)))) {
    *(int *)(param_1 + 0x25c) = param_3;
    FoundTarget(param_1);
  }
  return;
}



/* monster_triggered_spawn @ 10012460 status existing size 142 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl monster_triggered_spawn(int param_1)

{
  *(float *)(param_1 + 0xc) = *(float *)(param_1 + 0xc) + _DAT_10044104;
  KillBox(param_1);
  *(undefined4 *)(param_1 + 0xf8) = 2;
  *(undefined4 *)(param_1 + 0x104) = 5;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffe;
  *(float *)(param_1 + 0x194) = DAT_1006c2e4 + _DAT_10044244;
  (*DAT_1006c208)(param_1);
  monster_start_go(param_1);
  if (((*(int *)(param_1 + 0x25c) != 0) && ((*(byte *)(param_1 + 0x11c) & 1) == 0)) &&
     ((*(byte *)(*(int *)(param_1 + 0x25c) + 0x108) & 0x20) == 0)) {
    FoundTarget(param_1);
    return;
  }
  *(undefined4 *)(param_1 + 0x25c) = 0;
  return;
}



/* monster_triggered_spawn_use @ 100124f0 status created size 60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void monster_triggered_spawn_use(int param_1,undefined4 param_2,int param_3)

{
  *(code **)(param_1 + 500) = monster_triggered_spawn;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  if (*(int *)(param_3 + 0x54) != 0) {
    *(int *)(param_1 + 0x25c) = param_3;
  }
  *(code **)(param_1 + 0x200) = monster_use;
  return;
}



/* monster_triggered_start @ 10012530 status existing size 50 */

void __cdecl monster_triggered_start(int param_1)

{
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(code **)(param_1 + 0x200) = monster_triggered_spawn_use;
  return;
}



/* monster_death_use @ 10012570 status existing size 111 */

void __cdecl monster_death_use(uint param_1)

{
  *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) & 0xfffffffc;
  *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) & 0x100;
  if (*(int **)(param_1 + 0x2cc) != (int *)0x0) {
    Drop_Item(param_1,*(int **)(param_1 + 0x2cc));
    *(undefined4 *)(param_1 + 0x2cc) = 0;
  }
  if (*(int *)(param_1 + 0x13c) != 0) {
    *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x13c);
  }
  if (*(int *)(param_1 + 0x128) != 0) {
    G_UseTargets(param_1,*(int *)(param_1 + 0x25c));
  }
  return;
}



/* monster_start @ 100125e0 status existing size 362 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl monster_start(undefined4 *param_1)

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
    G_FreeEdict(param_1);
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
  param_1[0x80] = monster_use;
  param_1[0x89] = param_1[0x88];
  param_1[0x65] = fVar4;
  param_1[0x3f] = 0x2020003;
  param_1[0xf] = 0;
  param_1[0x8b] = 0;
  if (param_1[0xe3] == 0) {
    param_1[0xe3] = M_CheckAttack;
  }
  param_1[7] = param_1[1];
  param_1[8] = param_1[2];
  param_1[9] = param_1[3];
  if (DAT_1006c2ac != (byte *)0x0) {
    puVar5 = FindItemByClassname(DAT_1006c2ac);
    param_1[0xb3] = puVar5;
    if (puVar5 == (undefined4 *)0x0) {
      pbVar8 = DAT_1006c2ac;
      puVar6 = vtos();
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



/* monster_start_go @ 10012750 status existing size 809 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl monster_start_go(int param_1)

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
    uVar3 = G_Find(0,300,*(byte **)(param_1 + 0x128));
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
        uVar3 = G_Find(uVar3,300,*(byte **)(param_1 + 0x128));
      } while (uVar3 != 0);
      if ((bVar2) && (*(int *)(param_1 + 0x140) != 0)) {
        iVar11 = param_1 + 4;
        puVar4 = vtos();
        (*DAT_1006c1c4)(s__s_at__s_has_target_with_mixed_t_100497a4,*(undefined4 *)(param_1 + 0x118)
                        ,puVar4,iVar11);
      }
      if (bVar14) {
        *(undefined4 *)(param_1 + 0x128) = 0;
      }
    }
  }
  if (*(byte **)(param_1 + 0x140) != (byte *)0x0) {
    for (uVar3 = G_Find(0,300,*(byte **)(param_1 + 0x140)); uVar3 != 0;
        uVar3 = G_Find(uVar3,300,*(byte **)(param_1 + 0x140))) {
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
    uVar3 = G_PickTarget(*(byte **)(param_1 + 0x128));
    *(uint *)(param_1 + 0x1e0) = uVar3;
    *(uint *)(param_1 + 0x1dc) = uVar3;
    if (uVar3 == 0) {
      iVar11 = param_1 + 4;
      puVar4 = vtos();
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
    fVar15 = vectoyaw(&fStack_c);
    *(float *)(param_1 + 0x14) = (float)fVar15;
    *(float *)(param_1 + 0x1e8) = (float)fVar15;
    (**(code **)(param_1 + 0x374))(param_1);
    *(undefined4 *)(param_1 + 0x128) = 0;
  }
LAB_10012a12:
  *(code **)(param_1 + 500) = monster_think;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  return;
}



/* walkmonster_start_go @ 10012a80 status existing size 169 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl walkmonster_start_go(int param_1)

{
  int iVar1;
  undefined *puVar2;
  
  if (((*(byte *)(param_1 + 0x11c) & 2) == 0) && (DAT_1006c2e4 < _DAT_10044104)) {
    M_droptofloor(param_1);
    if (*(int *)(param_1 + 0x268) != 0) {
      iVar1 = M_walkmove(param_1,0.0,0.0);
      if (iVar1 == 0) {
        iVar1 = param_1 + 4;
        puVar2 = vtos();
        (*DAT_1006c1c4)(s__s_in_solid_at__s_100497dc,*(undefined4 *)(param_1 + 0x118),puVar2,iVar1);
      }
    }
  }
  if (*(float *)(param_1 + 0x1e4) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x1e4) = 0x41a00000;
  }
  *(undefined4 *)(param_1 + 0x23c) = 0x19;
  monster_start_go(param_1);
  if ((*(byte *)(param_1 + 0x11c) & 2) != 0) {
    monster_triggered_start(param_1);
  }
  return;
}



/* walkmonster_start @ 10012b30 status existing size 22 */

void __cdecl walkmonster_start(undefined4 *param_1)

{
  param_1[0x7d] = walkmonster_start_go;
  monster_start(param_1);
  return;
}



/* flymonster_start_go @ 10012b50 status existing size 186 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl flymonster_start_go(int param_1)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = M_walkmove(param_1,0.0,0.0);
  if (iVar1 == 0) {
    iVar1 = param_1 + 4;
    puVar2 = vtos();
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
  monster_start_go(param_1);
  if ((*(byte *)(param_1 + 0x11c) & 2) != 0) {
    monster_triggered_start(param_1);
  }
  return;
}



/* swimmonster_start_go @ 10012c40 status existing size 74 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl swimmonster_start_go(int param_1)

{
  if (*(float *)(param_1 + 0x1e4) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x1e4) = 0x41200000;
  }
  *(undefined4 *)(param_1 + 0x23c) = 10;
  monster_start_go(param_1);
  if ((*(byte *)(param_1 + 0x11c) & 2) != 0) {
    monster_triggered_start(param_1);
  }
  return;
}



/* flymonster_start @ 10012c10 status existing size 37 */

void __cdecl flymonster_start(undefined4 *param_1)

{
  param_1[0x7d] = flymonster_start_go;
  param_1[0x42] = param_1[0x42] | 1;
  monster_start(param_1);
  return;
}



/* swimmonster_start @ 10012c90 status existing size 37 */

void __cdecl swimmonster_start(undefined4 *param_1)

{
  param_1[0x7d] = swimmonster_start_go;
  param_1[0x42] = param_1[0x42] | 2;
  monster_start(param_1);
  return;
}



/* G_RunEntity @ 10014180 status existing size 111 */

void __cdecl G_RunEntity(float *param_1)

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



/* rtdu_use @ 10014270 status existing size 100 */

void __cdecl rtdu_use(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0xf18);
  if (iVar1 != 0) {
    iVar1 = FUN_10038b20(*(void **)(iVar1 + 0x118),&DAT_10048094);
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x54);
      if (*(int *)(iVar1 + 0xf0c) != 0) {
        RTDU_EndRemoteView(*(int *)(iVar1 + 0xf18));
        return;
      }
      RTDU_BeginRemoteView(*(int *)(iVar1 + 0xf18));
      return;
    }
  }
  RTDU_SpawnTurret(param_1);
  return;
}



/* RTDU_SpawnTurret @ 100142e0 status existing size 62 */

void __cdecl RTDU_SpawnTurret(int param_1)

{
  int *piVar1;
  
  piVar1 = G_Spawn();
  RTDU_InitTurret((int)piVar1);
  piVar1[0x40] = param_1;
  piVar1[1] = *(int *)(param_1 + 4);
  piVar1[2] = *(int *)(param_1 + 8);
  piVar1[3] = *(int *)(param_1 + 0xc);
  piVar1[5] = *(int *)(param_1 + 0x14);
  *(int **)(*(int *)(param_1 + 0x54) + 0xf18) = piVar1;
  return;
}



/* RTDU_TurretThink @ 10014320 status existing size 195 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl RTDU_TurretThink(int param_1)

{
  if ((*(int *)(*(int *)(param_1 + 0x100) + 0x58) == 0) ||
     (*(int *)(*(int *)(*(int *)(param_1 + 0x100) + 0x54) + 0xf18) != param_1)) {
    RTDU_RemoveTurret(param_1);
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



/* RTDU_RemoveTurret @ 100144c0 status existing size 112 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl RTDU_RemoveTurret(int param_1)

{
  float fVar1;
  
  *(undefined4 *)
   (*(int *)(*(int *)(param_1 + 0x100) + 0x54) + 0x2e4 +
   ((*(int *)(param_1 + 0x2cc) + -0x10046928) / 0x48) * 4) = 0;
  RTDU_EndRemoteView(param_1);
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x100) + 0x54) + 0xf18) = 0;
  fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
  *(undefined1 **)(param_1 + 500) = &LAB_100143f0;
  *(float *)(param_1 + 0x1ec) = fVar1;
  return;
}



/* RTDU_BeginRemoteView @ 10014530 status existing size 134 */

void __cdecl RTDU_BeginRemoteView(int param_1)

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



/* RTDU_EndRemoteView @ 100145c0 status existing size 78 */

void __cdecl RTDU_EndRemoteView(int param_1)

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



/* RTDU_TurretAttack @ 10014610 status existing size 311 */

void __cdecl RTDU_TurretAttack(int param_1)

{
  int *piVar1;
  int iVar2;
  float local_24 [3];
  float local_18 [3];
  float local_c [3];
  
  if (*(int *)(param_1 + 0x254) < 1) {
    RTDU_RemoveTurret(param_1);
    return;
  }
  *(int *)(param_1 + 0x254) = *(int *)(param_1 + 0x254) + -1;
  piVar1 = (int *)(*(int *)(*(int *)(param_1 + 0x100) + 0x54) + 0x2e4 +
                  ((*(int *)(param_1 + 0x2cc) + -0x10046928) / 0x48) * 4);
  *piVar1 = *piVar1 + -1;
  AngleVectors((float *)(param_1 + 0x10),local_24,local_c,(float *)0x0);
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
  PlayerNoise(*(int *)(param_1 + 0x100),local_18,1);
  return;
}



/* RTDU_InitTurret @ 100147d0 status existing size 357 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl RTDU_InitTurret(int param_1)

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
  puVar3 = FindItem(&DAT_100498d4);
  *(undefined4 **)(param_1 + 0x2cc) = puVar3;
  *(undefined4 *)(param_1 + 0x220) = 0x3c;
  *(undefined4 *)(param_1 + 0x254) = 200;
  *(undefined4 *)(param_1 + 0x120) = 0;
  fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
  *(code **)(param_1 + 500) = RTDU_TurretThink;
  *(code **)(param_1 + 0x208) = RTDU_RemoveTurret;
  *(float *)(param_1 + 0x1ec) = fVar1;
  (*DAT_1006c208)(param_1);
  piVar4 = G_Spawn();
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



/* WriteField1 @ 10015c90 status existing size 250 */

uint __cdecl WriteField1(undefined4 param_1,uint param_2,int param_3)

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



/* WriteField2 @ 10015dc0 status existing size 64 */

void __cdecl WriteField2(int *param_1,int param_2,int param_3)

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



/* ReadField @ 10015e00 status existing size 264 */

void __cdecl ReadField(int *param_1,int param_2,int param_3)

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
      *puVar3 = (uint)(InitGame + *puVar3);
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



/* Svcmd_Test_f @ 100173c0 status existing size 19 */

void Svcmd_Test_f(void)

{
  (*DAT_1006c1c8)(0,2,s_Svcmd_Test_f___1004b784);
  return;
}



/* WriteGame @ 10016020 status created size 221 */

void WriteGame(LPCSTR param_1,int param_2)

{
  FILE *pFVar1;
  int iVar2;
  int iVar3;
  char acStack_10 [4];
  char acStack_c [4];
  char acStack_8 [4];
  undefined4 uStack_4;
  
  if (param_2 == 0) {
    SaveClientData();
  }
  pFVar1 = (FILE *)FUN_10039d52(param_1,&DAT_1004a508);
  if (pFVar1 == (FILE *)0x0) {
    (*DAT_1006c1dc)(s_Couldn_t_open__s_1004a4f4,param_1);
  }
  acStack_10[0] = s_Oct_20_1999_1004a3fc[0];
  acStack_10[1] = s_Oct_20_1999_1004a3fc[1];
  acStack_10[2] = s_Oct_20_1999_1004a3fc[2];
  acStack_10[3] = s_Oct_20_1999_1004a3fc[3];
  uStack_4 = 0;
  acStack_c[0] = s_Oct_20_1999_1004a3fc[4];
  acStack_c[1] = s_Oct_20_1999_1004a3fc[5];
  acStack_c[2] = s_Oct_20_1999_1004a3fc[6];
  acStack_c[3] = s_Oct_20_1999_1004a3fc[7];
  acStack_8[0] = s_Oct_20_1999_1004a3fc[8];
  acStack_8[1] = s_Oct_20_1999_1004a3fc[9];
  acStack_8[2] = s_Oct_20_1999_1004a3fc[10];
  acStack_8[3] = s_Oct_20_1999_1004a3fc[0xb];
  FUN_10039a54(acStack_10,0x10,1,(int *)pFVar1);
  DAT_1006ca58 = param_2;
  FUN_10039a54(&DAT_1006c440,0x61c,1,(int *)pFVar1);
  iVar3 = 0;
  DAT_1006ca58 = 0;
  if (0 < DAT_1006ca48) {
    iVar2 = 0;
    do {
      WriteClient((int *)pFVar1,(undefined4 *)(iVar2 + DAT_1006c844));
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xf34;
    } while (iVar3 < DAT_1006ca48);
  }
  FUN_10039ca4(pFVar1);
  return;
}



/* ReadGame @ 10016100 status created size 314 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ReadGame(LPCSTR param_1)

{
  byte bVar1;
  FILE *pFVar2;
  byte *pbVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  bool bVar7;
  byte abStack_10 [16];
  
  (*DAT_1006c24c)(0x2fd);
  pFVar2 = (FILE *)FUN_10039d52(param_1,&DAT_1004a530);
  if (pFVar2 == (FILE *)0x0) {
    (*DAT_1006c1dc)(s_Couldn_t_open__s_1004a4f4,param_1);
  }
  FUN_10039b8d((char *)abStack_10,0x10,1,(int *)pFVar2);
  pcVar5 = s_Oct_20_1999_1004a3fc;
  pbVar3 = abStack_10;
  do {
    bVar1 = *pbVar3;
    bVar7 = bVar1 < (byte)*pcVar5;
    if (bVar1 != *pcVar5) {
LAB_1001617b:
      iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      goto LAB_10016180;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar3[1];
    bVar7 = bVar1 < (byte)pcVar5[1];
    if (bVar1 != pcVar5[1]) goto LAB_1001617b;
    pbVar3 = pbVar3 + 2;
    pcVar5 = pcVar5 + 2;
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_10016180:
  if (iVar4 != 0) {
    FUN_10039ca4(pFVar2);
    (*DAT_1006c1dc)(s_Savegame_from_an_older_version__1004a50c);
  }
  _DAT_1006c160 = (*DAT_1006c244)(DAT_1006ca4c * 0x3d0,0x2fd);
  DAT_1006c2c4 = _DAT_1006c160;
  FUN_10039b8d(&DAT_1006c440,0x61c,1,(int *)pFVar2);
  DAT_1006c844 = (*DAT_1006c244)(DAT_1006ca48 * 0xf34,0x2fd);
  iVar4 = 0;
  if (0 < DAT_1006ca48) {
    iVar6 = 0;
    do {
      ReadClient((int *)pFVar2,(char *)(iVar6 + DAT_1006c844));
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + 0xf34;
    } while (iVar4 < DAT_1006ca48);
  }
  FUN_10039ca4(pFVar2);
  return;
}



/* WriteClient @ 10015f40 status existing size 141 */

void __cdecl WriteClient(int *param_1,undefined4 *param_2)

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
    WriteField1(param_1,(uint)ppuVar5,(int)local_f34);
    ppuVar1 = ppuVar5 + 4;
    ppuVar5 = ppuVar5 + 4;
    puVar2 = *ppuVar1;
  }
  FUN_10039a54(local_f34,0xf34,1,param_1);
  ppuVar5 = &PTR_s_pers_weapon_10049ee0;
  puVar2 = PTR_s_pers_weapon_10049ee0;
  while (puVar2 != (undefined *)0x0) {
    WriteField2(param_1,(int)ppuVar5,(int)param_2);
    ppuVar1 = ppuVar5 + 4;
    ppuVar5 = ppuVar5 + 4;
    puVar2 = *ppuVar1;
  }
  return;
}



/* ReadClient @ 10015fd0 status existing size 67 */

void __cdecl ReadClient(int *param_1,char *param_2)

{
  undefined **ppuVar1;
  undefined *puVar2;
  undefined **ppuVar3;
  
  FUN_10039b8d(param_2,0xf34,1,param_1);
  ppuVar3 = &PTR_s_pers_weapon_10049ee0;
  puVar2 = PTR_s_pers_weapon_10049ee0;
  while (puVar2 != (undefined *)0x0) {
    ReadField(param_1,(int)ppuVar3,(int)param_2);
    ppuVar1 = ppuVar3 + 4;
    ppuVar3 = ppuVar3 + 4;
    puVar2 = *ppuVar1;
  }
  return;
}



/* WriteLevel @ 10016400 status created size 220 */

void WriteLevel(LPCSTR param_1)

{
  LPCSTR pCVar1;
  FILE *pFVar2;
  undefined4 *puVar3;
  code *pcStack_4;
  
  pCVar1 = param_1;
  pFVar2 = (FILE *)FUN_10039d52(param_1,&DAT_1004a508);
  if (pFVar2 == (FILE *)0x0) {
    (*DAT_1006c1dc)(s_Couldn_t_open__s_1004a4f4,pCVar1);
  }
  param_1 = (LPCSTR)0x3d0;
  FUN_10039a54((char *)&param_1,4,1,(int *)pFVar2);
  pcStack_4 = InitGame;
  FUN_10039a54((char *)&pcStack_4,4,1,(int *)pFVar2);
  WriteLevelLocals((int *)pFVar2);
  param_1 = (LPCSTR)0x0;
  if (0 < DAT_1006c168) {
    do {
      puVar3 = (undefined4 *)((int)param_1 * 0x3d0 + DAT_1006c2c4);
      if (puVar3[0x16] != 0) {
        FUN_10039a54((char *)&param_1,4,1,(int *)pFVar2);
        WriteEdict((int *)pFVar2,puVar3);
      }
      param_1 = (LPCSTR)((int)param_1 + 1);
    } while ((int)param_1 < DAT_1006c168);
  }
  param_1 = (LPCSTR)0xffffffff;
  FUN_10039a54((char *)&param_1,4,1,(int *)pFVar2);
  FUN_10039ca4(pFVar2);
  return;
}



/* WriteEdict @ 10016240 status existing size 141 */

void __cdecl WriteEdict(int *param_1,undefined4 *param_2)

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
    WriteField1(param_1,(uint)ppuVar5,(int)local_3d0);
    ppuVar1 = ppuVar5 + 4;
    ppuVar5 = ppuVar5 + 4;
    puVar2 = *ppuVar1;
  }
  FUN_10039a54(local_3d0,0x3d0,1,param_1);
  ppuVar5 = &PTR_s_classname_100498e0;
  puVar2 = PTR_s_classname_100498e0;
  while (puVar2 != (undefined *)0x0) {
    WriteField2(param_1,(int)ppuVar5,(int)param_2);
    ppuVar1 = ppuVar5 + 4;
    ppuVar5 = ppuVar5 + 4;
    puVar2 = *ppuVar1;
  }
  return;
}



/* WriteLevelLocals @ 100162d0 status existing size 139 */

void __cdecl WriteLevelLocals(int *param_1)

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
    WriteField1(param_1,(uint)ppuVar5,(int)local_130);
    ppuVar1 = ppuVar5 + 4;
    ppuVar5 = ppuVar5 + 4;
    puVar2 = *ppuVar1;
  }
  FUN_10039a54(local_130,0x130,1,param_1);
  ppuVar5 = &PTR_s_changemap_10049e80;
  puVar2 = PTR_s_changemap_10049e80;
  while (puVar2 != (undefined *)0x0) {
    WriteField2(param_1,(int)ppuVar5,0x1006c2e0);
    ppuVar1 = ppuVar5 + 4;
    ppuVar5 = ppuVar5 + 4;
    puVar2 = *ppuVar1;
  }
  return;
}



/* ReadLevel @ 100164e0 status created size 612 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ReadLevel(LPCSTR param_1)

{
  byte bVar1;
  LPCSTR pCVar2;
  FILE *pFVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *puVar8;
  bool bVar9;
  longlong lVar10;
  code *pcStack_8;
  int iStack_4;
  
  pCVar2 = param_1;
  pFVar3 = (FILE *)FUN_10039d52(param_1,&DAT_1004a530);
  if (pFVar3 == (FILE *)0x0) {
    (*DAT_1006c1dc)(s_Couldn_t_open__s_1004a4f4,pCVar2);
  }
  (*DAT_1006c24c)(0x2fe);
  puVar8 = DAT_1006c2c4;
  for (uVar5 = (uint)(DAT_1006ca4c * 0x3d0) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(undefined1 *)puVar8 = 0;
    puVar8 = (undefined4 *)((int)puVar8 + 1);
  }
  lVar10 = __ftol();
  DAT_1006c168 = (int)lVar10;
  FUN_10039b8d((char *)&param_1,4,1,(int *)pFVar3);
  if (param_1 != (LPCSTR)0x3d0) {
    FUN_10039ca4(pFVar3);
    (*DAT_1006c1dc)(s_ReadLevel__mismatched_edict_size_1004a59c);
  }
  FUN_10039b8d((char *)&pcStack_8,4,1,(int *)pFVar3);
  if (pcStack_8 != InitGame) {
    FUN_10039ca4(pFVar3);
    (*DAT_1006c1dc)(s_ReadLevel__function_pointers_hav_1004a574);
  }
  ReadLevelLocals((int *)pFVar3);
  while( true ) {
    uVar5 = FUN_10039b8d((char *)&iStack_4,4,1,(int *)pFVar3);
    if (uVar5 != 1) {
      FUN_10039ca4(pFVar3);
      (*DAT_1006c1dc)(s_ReadLevel__failed_to_read_entnum_1004a550);
    }
    if (iStack_4 == -1) break;
    if (DAT_1006c168 <= iStack_4) {
      DAT_1006c168 = iStack_4 + 1;
    }
    pcVar7 = (char *)(DAT_1006c2c4 + iStack_4 * 0xf4);
    ReadEdict((int *)pFVar3,pcVar7);
    pcVar7[0x60] = '\0';
    pcVar7[0x61] = '\0';
    pcVar7[0x62] = '\0';
    pcVar7[99] = '\0';
    pcVar7[100] = '\0';
    pcVar7[0x65] = '\0';
    pcVar7[0x66] = '\0';
    pcVar7[0x67] = '\0';
    (*DAT_1006c208)(pcVar7);
  }
  FUN_10039ca4(pFVar3);
  param_1 = (LPCSTR)0x0;
  if (_DAT_1004410c < *(float *)(DAT_1006ca60 + 0x14)) {
    do {
      iVar6 = DAT_1006c844 + (int)param_1 * 0xf34;
      DAT_1006c2c4[(int)param_1 * 0xf4 + 0x109] = iVar6;
      *(undefined4 *)(iVar6 + 0x2d0) = 0;
      param_1 = (LPCSTR)((int)param_1 + 1);
    } while ((float)(int)param_1 < *(float *)(DAT_1006ca60 + 0x14));
  }
  param_1 = (LPCSTR)0x0;
  if (0 < DAT_1006c168) {
    do {
      if ((DAT_1006c2c4[(int)param_1 * 0xf4 + 0x16] != 0) &&
         (pbVar4 = (byte *)DAT_1006c2c4[(int)param_1 * 0xf4 + 0x46], pbVar4 != (byte *)0x0)) {
        pcVar7 = s_target_crosslevel_target_1004a534;
        do {
          bVar1 = *pbVar4;
          bVar9 = bVar1 < (byte)*pcVar7;
          if (bVar1 != *pcVar7) {
LAB_10016710:
            iVar6 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
            goto LAB_10016715;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar9 = bVar1 < (byte)pcVar7[1];
          if (bVar1 != pcVar7[1]) goto LAB_10016710;
          pbVar4 = pbVar4 + 2;
          pcVar7 = pcVar7 + 2;
        } while (bVar1 != 0);
        iVar6 = 0;
LAB_10016715:
        if (iVar6 == 0) {
          DAT_1006c2c4[(int)param_1 * 0xf4 + 0x7b] =
               DAT_1006c2e4 + (float)DAT_1006c2c4[(int)param_1 * 0xf4 + 0xa5];
        }
      }
      param_1 = (LPCSTR)((int)param_1 + 1);
    } while ((int)param_1 < DAT_1006c168);
  }
  return;
}



/* ReadEdict @ 10016360 status existing size 67 */

void __cdecl ReadEdict(int *param_1,char *param_2)

{
  undefined **ppuVar1;
  undefined *puVar2;
  undefined **ppuVar3;
  
  FUN_10039b8d(param_2,0x3d0,1,param_1);
  ppuVar3 = &PTR_s_classname_100498e0;
  puVar2 = PTR_s_classname_100498e0;
  while (puVar2 != (undefined *)0x0) {
    ReadField(param_1,(int)ppuVar3,(int)param_2);
    ppuVar1 = ppuVar3 + 4;
    ppuVar3 = ppuVar3 + 4;
    puVar2 = *ppuVar1;
  }
  return;
}



/* ReadLevelLocals @ 100163b0 status existing size 69 */

void __cdecl ReadLevelLocals(int *param_1)

{
  undefined **ppuVar1;
  undefined *puVar2;
  undefined **ppuVar3;
  
  FUN_10039b8d((char *)&DAT_1006c2e0,0x130,1,param_1);
  ppuVar3 = &PTR_s_changemap_10049e80;
  puVar2 = PTR_s_changemap_10049e80;
  while (puVar2 != (undefined *)0x0) {
    ReadField(param_1,(int)ppuVar3,0x1006c2e0);
    ppuVar1 = ppuVar3 + 4;
    ppuVar3 = ppuVar3 + 4;
    puVar2 = *ppuVar1;
  }
  return;
}



/* InitGame @ 100158d0 status created size 953 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitGame(void)

{
  longlong lVar1;
  
  (*DAT_1006c1c4)(s______InitGame______1004a4a0);
  DAT_1006c18c = (*DAT_1006c250)(s_gun_x_1004a494,&DAT_1004a49c,0);
  DAT_1006c190 = (*DAT_1006c250)(s_gun_y_1004a48c,&DAT_1004a49c,0);
  DAT_1006c194 = (*DAT_1006c250)(s_gun_z_1004a484,&DAT_1004a49c,0);
  DAT_1006c174 = (*DAT_1006c250)(s_sv_rollspeed_1004a470,&DAT_1004a480,0);
  DAT_1006c430 = (*DAT_1006c250)(s_sv_rollangle_1004a45c,&DAT_1004a46c,0);
  DAT_1006c184 = (*DAT_1006c250)(s_sv_maxvelocity_1004a444,&DAT_1004a454,0);
  DAT_1006c420 = (*DAT_1006c250)(s_sv_gravity_1004a434,&DAT_1004a440,0);
  DAT_1006c10c = (*DAT_1006c250)(s_dedicated_1004a428,&DAT_1004a49c,8);
  DAT_1006c1a4 = (*DAT_1006c250)(s_cheats_1004a420,&DAT_1004a49c,0x14);
  (*DAT_1006c250)(s_gamename_1004a408,s_oblivion_1004a414,0x14);
  (*DAT_1006c250)(s_gamedate_1004a3f0,s_Oct_20_1999_1004a3fc,0x14);
  DAT_1006ca60 = (*DAT_1006c250)(s_maxclients_1004a3e0,&DAT_1004a3ec,0x14);
  DAT_1006c410 = (*DAT_1006c250)(s_maxspectators_1004a3d0,&DAT_1004a3ec,4);
  DAT_1006c118 = (*DAT_1006c250)(s_deathmatch_1004a3c4,&DAT_1004a49c,0x10);
  DAT_1006c42c = (*DAT_1006c250)(&DAT_1004a3bc,&DAT_1004a49c,0x10);
  DAT_1006c41c = (*DAT_1006c250)(s_skill_1004a3b0,&DAT_1004a3b8,0x10);
  DAT_1006c2d0 = (*DAT_1006c250)(s_maxentities_1004a39c,&DAT_1004a3a8,0x10);
  DAT_1006c414 = (*DAT_1006c250)(s_dmflags_1004a394,&DAT_1004a49c,4);
  DAT_1006c180 = (*DAT_1006c250)(s_fraglimit_1004a388,&DAT_1004a49c,4);
  DAT_1006c428 = (*DAT_1006c250)(s_timelimit_1004a37c,&DAT_1004a49c,4);
  DAT_1006c2c8 = (*DAT_1006c250)(s_password_1004a370,&DAT_10060c60,2);
  DAT_1006c108 = (*DAT_1006c250)(s_spectator_password_1004a35c,&DAT_10060c60,2);
  DAT_1006c178 = (*DAT_1006c250)(s_filterban_1004a350,&DAT_1004a3b8,0);
  DAT_1006c110 = (*DAT_1006c250)(s_g_select_empty_1004a340,&DAT_1004a49c,1);
  DAT_1006c17c = (*DAT_1006c250)(s_run_pitch_1004a32c,s_0_002_1004a338,0);
  DAT_1006c424 = (*DAT_1006c250)(s_run_roll_1004a318,s_0_005_1004a324,0);
  DAT_1006ca5c = (*DAT_1006c250)(s_bob_up_1004a310,s_0_005_1004a324,0);
  DAT_1006c198 = (*DAT_1006c250)(s_bob_pitch_1004a304,s_0_002_1004a338,0);
  DAT_1006c19c = (*DAT_1006c250)(s_bob_roll_1004a2f8,s_0_002_1004a338,0);
  DAT_1006c114 = (*DAT_1006c250)(s_flood_msgs_1004a2ec,&DAT_1004a3ec,0);
  DAT_1006c188 = (*DAT_1006c250)(s_flood_persecond_1004a2dc,&DAT_1004a3ec,0);
  DAT_1006c2cc = (*DAT_1006c250)(s_flood_waitdelay_1004a2c8,&DAT_1004a2d8,0);
  DAT_1006c170 = (*DAT_1006c250)(s_sv_maplist_1004a2bc,&DAT_10060c60,0);
  InitItems();
  FUN_10038b40();
  FUN_10038b40();
  lVar1 = __ftol();
  DAT_1006ca4c = (int)lVar1;
  _DAT_1006c160 = (*DAT_1006c244)(DAT_1006ca4c * 0x3d0,0x2fd);
  _DAT_1006c16c = DAT_1006ca4c;
  DAT_1006c2c4 = _DAT_1006c160;
  lVar1 = __ftol();
  DAT_1006ca48 = (int)lVar1;
  DAT_1006c844 = (*DAT_1006c244)(DAT_1006ca48 * 0xf34,0x2fd);
  DAT_1006c168 = DAT_1006ca48 + 1;
  return;
}



/* ED_CallSpawn @ 10016750 status existing size 254 */

void __cdecl ED_CallSpawn(undefined4 *param_1)

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
          SpawnItem(param_1,puVar7);
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



/* ED_NewString @ 10016850 status existing size 94 */

void __cdecl ED_NewString(char *param_1)

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



/* ED_ParseField @ 100168b0 status existing size 300 */

void __cdecl ED_ParseField(byte *param_1,byte *param_2,undefined4 *param_3)

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
    uVar3 = ED_NewString((char *)param_2);
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



/* ED_ParseEdict @ 10016a00 status existing size 229 */

int __cdecl ED_ParseEdict(int param_1,undefined4 *param_2)

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
      ED_ParseField(local_100,pbVar2,puVar5);
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



/* G_FindTeams @ 10016af0 status existing size 361 */

void G_FindTeams(void)

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



/* SpawnEntities @ 10016c60 status created size 653 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SpawnEntities(char *param_1,int param_2,char *param_3)

{
  undefined *puVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 unaff_ESI;
  int *piVar7;
  undefined4 unaff_EDI;
  undefined4 *puVar8;
  bool bVar9;
  float10 fVar10;
  undefined *puVar11;
  double dVar12;
  undefined8 uVar13;
  
  fVar10 = FUN_1003900b((double)*(float *)(DAT_1006c41c + 0x14));
  if ((float10)_DAT_1004410c <= fVar10) {
    if ((float10)_DAT_100441b4 < fVar10) {
      fVar10 = (float10)_DAT_100441b4;
    }
  }
  else {
    fVar10 = (float10)_DAT_1004410c;
  }
  if (fVar10 != (float10)*(float *)(DAT_1006c41c + 0x14)) {
    dVar12 = (double)fVar10;
    puVar11 = &DAT_1004b3fc;
    puVar1 = FUN_10038a50(&DAT_1004b3fc);
    (*DAT_1006c258)(s_skill_1004a3b0,puVar1,puVar11,dVar12);
  }
  uVar13 = CONCAT44(unaff_ESI,unaff_EDI);
  SaveClientData();
  (*DAT_1006c24c)(0x2fe,uVar13);
  puVar8 = &DAT_1006c2e0;
  for (iVar3 = 0x4c; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  piVar7 = DAT_1006c2c4;
  for (uVar4 = (uint)(DAT_1006ca4c * 0x3d0) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)piVar7 = 0;
    piVar7 = (int *)((int)piVar7 + 1);
  }
  _strncpy(&DAT_1006c328,param_1,0x3f);
  _strncpy(&DAT_1006c848,param_3,0x1ff);
  iVar3 = 0;
  if (0 < DAT_1006ca48) {
    iVar6 = 0;
    iVar5 = 0;
    do {
      iVar3 = iVar3 + 1;
      *(int *)(iVar6 + 0x424 + (int)DAT_1006c2c4) = DAT_1006c844 + iVar5;
      iVar5 = iVar5 + 0xf34;
      iVar6 = iVar6 + 0x3d0;
    } while (iVar3 < DAT_1006ca48);
  }
  piVar7 = (int *)0x0;
  iVar3 = 0;
  do {
    while( true ) {
      pcVar2 = FUN_10038a70(&param_2);
      if (param_2 == 0) {
        (*DAT_1006c1c4)(s__i_entities_inhibited_1004b3ac,iVar3);
        G_FindTeams();
        PlayerTrail_Init();
        return;
      }
      if (*pcVar2 != '{') {
        (*DAT_1006c1dc)(s_ED_LoadFromFile__found__s_when_e_1004b3d0,pcVar2);
      }
      bVar9 = piVar7 != (int *)0x0;
      piVar7 = DAT_1006c2c4;
      if (bVar9) {
        piVar7 = G_Spawn();
      }
      param_2 = ED_ParseEdict(param_2,piVar7);
      iVar5 = FUN_10038b20(&DAT_1006c328,(byte *)s_command_1004b3c8);
      if (((iVar5 == 0) &&
          (iVar5 = FUN_10038b20((void *)piVar7[0x46],(byte *)s_trigger_once_1004b160), iVar5 == 0))
         && (iVar5 = FUN_10038b20((void *)piVar7[0x43],&DAT_1004b3c4), iVar5 == 0)) {
        piVar7[0x47] = piVar7[0x47] & 0xfffffbff;
      }
      if (piVar7 != DAT_1006c2c4) break;
LAB_10016ec3:
      ED_CallSpawn(piVar7);
    }
    if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
      if (((*(float *)(DAT_1006c41c + 0x14) != _DAT_1004410c) || ((piVar7[0x47] & 0x100U) == 0)) &&
         ((*(int *)(DAT_1006c41c + 0x14) != 0x3f800000 || ((piVar7[0x47] & 0x200U) == 0)))) {
        if ((*(int *)(DAT_1006c41c + 0x14) == 0x40000000) ||
           (*(int *)(DAT_1006c41c + 0x14) == 0x40400000)) {
          uVar4 = piVar7[0x47] & 0x400;
          goto LAB_10016e52;
        }
        goto LAB_10016eb4;
      }
    }
    else {
      uVar4 = piVar7[0x47] & 0x800;
LAB_10016e52:
      if (uVar4 == 0) {
LAB_10016eb4:
        piVar7[0x47] = piVar7[0x47] & 0xffffe0ff;
        goto LAB_10016ec3;
      }
    }
    G_FreeEdict(piVar7);
    iVar3 = iVar3 + 1;
  } while( true );
}



/* SV_FilterPacket @ 100173e0 status existing size 174 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong __cdecl SV_FilterPacket(char *param_1)

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



/* SVCmd_AddIP_f @ 10017490 status existing size 143 */

void SVCmd_AddIP_f(void)

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
  iVar3 = StringToFilter(pbVar2,puVar5);
  if (iVar3 == 0) {
    (&DAT_100620e4)[iVar1 * 2] = 0xffffffff;
  }
  return;
}



/* StringToFilter @ 10017520 status existing size 163 */

undefined4 __cdecl StringToFilter(byte *param_1,undefined4 *param_2)

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



/* SVCmd_RemoveIP_f @ 100175d0 status existing size 210 */

void SVCmd_RemoveIP_f(void)

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
  iVar1 = StringToFilter(pbVar2,piVar5);
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



/* SVCmd_ListIP_f @ 100176b0 status existing size 121 */

void SVCmd_ListIP_f(void)

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



/* SVCmd_WriteIP_f @ 10017730 status existing size 284 */

void SVCmd_WriteIP_f(void)

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



/* ServerCommand @ 10017850 status created size 157 */

void ServerCommand(void)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = (void *)(*DAT_1006c260)(1);
  iVar2 = FUN_10038b20(pvVar1,&DAT_1004b8f0);
  if (iVar2 == 0) {
    Svcmd_Test_f();
    return;
  }
  iVar2 = FUN_10038b20(pvVar1,(byte *)s_addip_1004b8e8);
  if (iVar2 == 0) {
    SVCmd_AddIP_f();
    return;
  }
  iVar2 = FUN_10038b20(pvVar1,(byte *)s_removeip_1004b8dc);
  if (iVar2 == 0) {
    SVCmd_RemoveIP_f();
    return;
  }
  iVar2 = FUN_10038b20(pvVar1,(byte *)s_listip_1004b8d4);
  if (iVar2 == 0) {
    SVCmd_ListIP_f();
    return;
  }
  iVar2 = FUN_10038b20(pvVar1,(byte *)s_writeip_1004b8cc);
  if (iVar2 == 0) {
    SVCmd_WriteIP_f();
    return;
  }
  (*DAT_1006c1c8)(0,2,s_Unknown_server_command___s__1004b8ac,pvVar1);
  return;
}



/* Use_Target_Help @ 10017aa0 status created size 82 */

void Use_Target_Help(int param_1)

{
  if ((*(byte *)(param_1 + 0x11c) & 1) != 0) {
    _strncpy(&DAT_1006c440,*(char **)(param_1 + 0x114),0x1ff);
    DAT_1006c840 = DAT_1006c840 + 1;
    return;
  }
  _strncpy(&DAT_1006c640,*(char **)(param_1 + 0x114),0x1ff);
  DAT_1006c840 = DAT_1006c840 + 1;
  return;
}



/* SP_target_help @ 10017b00 status created size 102 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_target_help(undefined4 *param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    G_FreeEdict(param_1);
    return;
  }
  if (param_1[0x45] == 0) {
    puVar2 = param_1 + 1;
    puVar1 = vtos();
    (*DAT_1006c1c4)(s__s_with_no_message_at__s_1004b930,param_1[0x46],puVar1,puVar2);
    G_FreeEdict(param_1);
    return;
  }
  param_1[0x80] = Use_Target_Help;
  return;
}



/* use_target_secret @ 10017b70 status existing size 66 */

void __cdecl use_target_secret(undefined4 *param_1,undefined4 param_2,int param_3)

{
  (*DAT_1006c1d0)(param_1,2,param_1[0xa0],0x3f800000,0x3f800000,0);
  DAT_1006c3f0 = DAT_1006c3f0 + 1;
  G_UseTargets((uint)param_1,param_3);
  G_FreeEdict(param_1);
  return;
}



/* SP_target_secret @ 10017bc0 status created size 167 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_target_secret(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    G_FreeEdict(param_1);
    return;
  }
  param_1[0x80] = use_target_secret;
  if (DAT_1006c2a4 == (char *)0x0) {
    DAT_1006c2a4 = s_misc_secret_wav_10046168;
  }
  uVar1 = (*DAT_1006c1e4)(DAT_1006c2a4);
  param_1[0xa0] = uVar1;
  param_1[0x2e] = 1;
  DAT_1006c3ec = DAT_1006c3ec + 1;
  iVar2 = FUN_10038b20(&DAT_1006c328,(byte *)s_mine3_1004b96c);
  if ((((iVar2 == 0) && (param_1[1] == 0x438c0000)) && (param_1[2] == -0x3b000000)) &&
     (param_1[3] == -0x3be40000)) {
    param_1[0x45] = s_You_have_found_a_secret_area__1004b94c;
  }
  return;
}



/* use_target_goal @ 10017c70 status existing size 95 */

void __cdecl use_target_goal(undefined4 *param_1,undefined4 param_2,int param_3)

{
  (*DAT_1006c1d0)(param_1,2,param_1[0xa0],0x3f800000,0x3f800000,0);
  DAT_1006c3f8 = DAT_1006c3f8 + 1;
  if (DAT_1006c3f8 == DAT_1006c3f4) {
    (*DAT_1006c1d8)(1,&DAT_1004a49c);
  }
  G_UseTargets((uint)param_1,param_3);
  G_FreeEdict(param_1);
  return;
}



/* SP_target_goal @ 10017cd0 status created size 108 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_target_goal(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    G_FreeEdict(param_1);
    return;
  }
  param_1[0x80] = use_target_goal;
  if (DAT_1006c2a4 == (char *)0x0) {
    DAT_1006c2a4 = s_misc_secret_wav_10046168;
  }
  uVar1 = (*DAT_1006c1e4)(DAT_1006c2a4);
  param_1[0xa0] = uVar1;
  param_1[0x2e] = 1;
  DAT_1006c3f4 = DAT_1006c3f4 + 1;
  return;
}



/* target_explosion_explode @ 10017d40 status existing size 145 */

void __cdecl target_explosion_explode(float param_1)

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
  G_UseTargets((uint)param_1,*(int *)((int)param_1 + 0x264));
  *(undefined4 *)((int)param_1 + 0x294) = uVar1;
  return;
}



/* use_target_explosion @ 10017de0 status created size 72 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void use_target_explosion(float param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  
  bVar1 = *(float *)((int)param_1 + 0x294) == _DAT_1004410c;
  *(undefined4 *)((int)param_1 + 0x264) = param_3;
  if (bVar1) {
    target_explosion_explode(param_1);
    return;
  }
  *(code **)((int)param_1 + 500) = target_explosion_explode;
  *(float *)((int)param_1 + 0x1ec) = DAT_1006c2e4 + *(float *)((int)param_1 + 0x294);
  return;
}



/* SP_target_explosion @ 10017e30 status created size 25 */

void SP_target_explosion(int param_1)

{
  *(code **)(param_1 + 0x200) = use_target_explosion;
  *(undefined4 *)(param_1 + 0xb8) = 1;
  return;
}



/* use_target_changelevel @ 10017e50 status created size 289 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void use_target_changelevel(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  ulonglong uVar4;
  
  uVar2 = DAT_1006c2c4;
  iVar1 = DAT_1006c118;
  if (_DAT_1006c3a8 == _DAT_1004410c) {
    if (((*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) ||
        (*(float *)(DAT_1006c42c + 0x14) != _DAT_1004410c)) || (0 < *(int *)(DAT_1006c2c4 + 0x5f0)))
    {
      if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
        uVar4 = __ftol();
        if (((uVar4 & 0x1000) == 0) && (param_2 != uVar2)) {
          FUN_100060d0(param_2,param_1,param_1,(float *)&DAT_10061c18,(float *)(param_2 + 4),
                       &DAT_10061c18,*(int *)(param_2 + 0x224) * 10,1000,0,0x1c);
          return;
        }
      }
      if ((*(float *)(iVar1 + 0x14) != _DAT_1004410c) &&
         ((param_3 != 0 && (*(int *)(param_3 + 0x54) != 0)))) {
        (*DAT_1006c1c0)(2,s__s_exited_the_level__1004b978,*(int *)(param_3 + 0x54) + 700);
      }
      pcVar3 = _strstr(*(char **)(param_1 + 0x238),&DAT_1004b974);
      if (pcVar3 != (char *)0x0) {
        DAT_1006ca50 = DAT_1006ca50 & 0xffffff00;
      }
      BeginIntermission(param_1);
    }
  }
  return;
}



/* SP_target_changelevel @ 10017f80 status existing size 125 */

void __cdecl SP_target_changelevel(undefined4 *param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1[0x8e] == 0) {
    puVar3 = param_1 + 1;
    puVar1 = vtos();
    (*DAT_1006c1c4)(s_target_changelevel_with_no_map_a_1004b9b0,puVar1,puVar3);
    G_FreeEdict(param_1);
    return;
  }
  iVar2 = FUN_10038b20(&DAT_1006c328,(byte *)s_fact1_1004b9a8);
  if (iVar2 == 0) {
    iVar2 = FUN_10038b20((void *)param_1[0x8e],(byte *)s_fact3_1004b9a0);
    if (iVar2 == 0) {
      param_1[0x8e] = s_fact3_secret1_1004b990;
    }
  }
  param_1[0x80] = use_target_changelevel;
  param_1[0x2e] = 1;
  return;
}



/* use_target_splash @ 10018000 status created size 143 */

void use_target_splash(float param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  
  (*DAT_1006c224)(3);
  (*DAT_1006c224)(10);
  (*DAT_1006c224)(*(undefined4 *)((int)param_1 + 0x254));
  (*DAT_1006c238)((int)param_1 + 4);
  (*DAT_1006c23c)((int)param_1 + 0x154);
  (*DAT_1006c224)(*(undefined4 *)((int)param_1 + 0x250));
  (*DAT_1006c218)((int)param_1 + 4,2);
  iVar1 = *(int *)((int)param_1 + 0x244);
  if (iVar1 != 0) {
    FUN_10006860(param_1,param_3,(float)iVar1,0,(float)(iVar1 + 0x28),0x1d);
  }
  return;
}



/* SP_target_splash @ 10018090 status existing size 66 */

void __cdecl SP_target_splash(int param_1)

{
  *(code **)(param_1 + 0x200) = use_target_splash;
  G_SetMovedir((float *)(param_1 + 0x10),(float *)(param_1 + 0x154));
  if (*(int *)(param_1 + 0x254) == 0) {
    *(undefined4 *)(param_1 + 0x254) = 0x20;
  }
  *(undefined4 *)(param_1 + 0xb8) = 1;
  return;
}



/* use_target_spawner @ 100180e0 status created size 148 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void use_target_spawner(int param_1)

{
  int *piVar1;
  
  piVar1 = G_Spawn();
  piVar1[0x46] = *(int *)(param_1 + 0x128);
  piVar1[1] = *(int *)(param_1 + 4);
  piVar1[2] = *(int *)(param_1 + 8);
  piVar1[3] = *(int *)(param_1 + 0xc);
  piVar1[4] = *(int *)(param_1 + 0x10);
  piVar1[5] = *(int *)(param_1 + 0x14);
  piVar1[6] = *(int *)(param_1 + 0x18);
  ED_CallSpawn(piVar1);
  (*DAT_1006c20c)(piVar1);
  KillBox((int)piVar1);
  (*DAT_1006c208)(piVar1);
  if (*(float *)(param_1 + 0x148) != _DAT_1004410c) {
    piVar1[0x5e] = *(int *)(param_1 + 0x154);
    piVar1[0x5f] = *(int *)(param_1 + 0x158);
    piVar1[0x60] = *(int *)(param_1 + 0x15c);
  }
  return;
}



/* SP_target_spawner @ 10018180 status existing size 81 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_target_spawner(int param_1)

{
  float *pfVar1;
  bool bVar2;
  
  bVar2 = *(float *)(param_1 + 0x148) != _DAT_1004410c;
  *(code **)(param_1 + 0x200) = use_target_spawner;
  *(undefined4 *)(param_1 + 0xb8) = 1;
  if (bVar2) {
    pfVar1 = (float *)(param_1 + 0x154);
    G_SetMovedir((float *)(param_1 + 0x10),pfVar1);
    VectorScale(pfVar1,*(float *)(param_1 + 0x148),pfVar1);
  }
  return;
}



/* use_target_blaster @ 100181e0 status existing size 78 */

void __cdecl use_target_blaster(int param_1)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0x21;
  uVar2 = 8;
  lVar1 = __ftol();
  fire_blaster(param_1,(float *)(param_1 + 4),(float *)(param_1 + 0x154),*(int *)(param_1 + 0x244),
               (int)lVar1,uVar2,iVar3);
  (*DAT_1006c1d0)(param_1,2,*(undefined4 *)(param_1 + 0x280),0x3f800000,0x3f800000,0);
  return;
}



/* SP_target_blaster @ 10018230 status existing size 112 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_target_blaster(int param_1)

{
  undefined4 uVar1;
  
  *(code **)(param_1 + 0x200) = use_target_blaster;
  G_SetMovedir((float *)(param_1 + 0x10),(float *)(param_1 + 0x154));
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



/* use_target_railgun @ 100182a0 status existing size 64 */

void __cdecl use_target_railgun(uint param_1)

{
  fire_rail(param_1,(float *)(param_1 + 4),(float *)(param_1 + 0x154),*(int *)(param_1 + 0x244),0);
  (*DAT_1006c1d0)(param_1,2,*(undefined4 *)(param_1 + 0x280),0x3f800000,0x3f800000,0);
  return;
}



/* SP_target_railgun @ 100182e0 status existing size 83 */

void __cdecl SP_target_railgun(int param_1)

{
  undefined4 uVar1;
  
  *(code **)(param_1 + 0x200) = use_target_railgun;
  G_SetMovedir((float *)(param_1 + 0x10),(float *)(param_1 + 0x154));
  uVar1 = (*DAT_1006c1e4)(s_weapons_railgf1a_wav_1004b9ec);
  *(undefined4 *)(param_1 + 0x280) = uVar1;
  if (*(int *)(param_1 + 0x244) == 0) {
    *(undefined4 *)(param_1 + 0x244) = 0x96;
  }
  *(undefined4 *)(param_1 + 0xb8) = 1;
  return;
}



/* target_rocket_fire @ 10018340 status existing size 88 */

void __cdecl target_rocket_fire(int param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x254);
  iVar2 = *(int *)(param_1 + 0x294);
  lVar1 = __ftol();
  fire_rocket(param_1,(float *)(param_1 + 4),(float *)(param_1 + 0x154),*(int *)(param_1 + 0x244),
              (int)lVar1,iVar2,iVar3);
  (*DAT_1006c1d0)(param_1,2,*(undefined4 *)(param_1 + 0x280),0x3f800000,0x3f800000,0);
  return;
}



/* SP_target_rocket @ 100183a0 status existing size 199 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_target_rocket(int param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  
  *(code **)(param_1 + 0x200) = target_rocket_fire;
  G_SetMovedir((float *)(param_1 + 0x10),(float *)(param_1 + 0x154));
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



/* trigger_crosslevel_trigger_use @ 10018470 status created size 32 */

void trigger_crosslevel_trigger_use(undefined4 *param_1)

{
  DAT_1006ca50 = DAT_1006ca50 | param_1[0x47];
  G_FreeEdict(param_1);
  return;
}



/* SP_target_crosslevel_trigger @ 10018490 status created size 25 */

void SP_target_crosslevel_trigger(int param_1)

{
  *(undefined4 *)(param_1 + 0xb8) = 1;
  *(code **)(param_1 + 0x200) = trigger_crosslevel_trigger_use;
  return;
}



/* target_crosslevel_target_think @ 100184b0 status created size 49 */

void target_crosslevel_target_think(undefined4 *param_1)

{
  if (param_1[0x47] == (param_1[0x47] & DAT_1006ca50 & 0xff)) {
    G_UseTargets((uint)param_1,(int)param_1);
    G_FreeEdict(param_1);
  }
  return;
}



/* SP_target_crosslevel_target @ 100184f0 status created size 72 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_target_crosslevel_target(int param_1)

{
  if (*(float *)(param_1 + 0x294) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x294) = 0x3f800000;
  }
  *(undefined4 *)(param_1 + 0xb8) = 1;
  *(code **)(param_1 + 500) = target_crosslevel_target_think;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + *(float *)(param_1 + 0x294);
  return;
}



/* target_laser_think @ 10018540 status existing size 579 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl target_laser_think(uint param_1)

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
    VectorMA((float *)(iVar2 + 0xd4),0.5,(float *)(iVar2 + 0xec),&local_88);
    *pfVar3 = local_88 - *(float *)(param_1 + 4);
    *(float *)(param_1 + 0x158) = local_84 - *(float *)(param_1 + 8);
    *(float *)(param_1 + 0x15c) = local_80 - *(float *)(param_1 + 0xc);
    VectorNormalize(pfVar3);
    iVar2 = VectorCompare(pfVar3,&local_94);
    if (iVar2 == 0) {
      *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) | 0x80000000;
    }
  }
  local_a0 = *(float *)(param_1 + 4);
  local_9c = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x100) = DAT_1006c2c4;
  local_98 = *(undefined4 *)(param_1 + 0xc);
  VectorMA(&local_a0,2048.0,(float *)(param_1 + 0x154),local_44);
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



/* target_laser_on @ 10018790 status existing size 61 */

void __cdecl target_laser_on(uint param_1)

{
  if (*(int *)(param_1 + 0x264) == 0) {
    *(uint *)(param_1 + 0x264) = param_1;
  }
  *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) | 0x80000001;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffe;
  target_laser_think(param_1);
  return;
}



/* target_laser_off @ 100187d0 status existing size 45 */

void __cdecl target_laser_off(int param_1)

{
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) & 0xfffffffe;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  return;
}



/* target_laser_use @ 10018800 status created size 42 */

void target_laser_use(uint param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x264) = param_3;
  if ((*(byte *)(param_1 + 0x11c) & 1) != 0) {
    target_laser_off(param_1);
    return;
  }
  target_laser_on(param_1);
  return;
}



/* target_laser_start @ 10018830 status existing size 382 */

void __cdecl target_laser_start(uint param_1)

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
      G_SetMovedir((float *)(param_1 + 0x10),(float *)(param_1 + 0x154));
    }
    else {
      uVar1 = G_Find(0,300,*(byte **)(param_1 + 0x128));
      if (uVar1 == 0) {
        uVar3 = *(undefined4 *)(param_1 + 0x128);
        puVar2 = vtos();
        (*DAT_1006c1c4)(s__s_at__s___s_is_a_bad_target_1004ba1c,*(undefined4 *)(param_1 + 0x118),
                        puVar2,uVar3);
      }
      *(uint *)(param_1 + 0x25c) = uVar1;
    }
  }
  *(code **)(param_1 + 0x200) = target_laser_use;
  *(code **)(param_1 + 500) = target_laser_think;
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
    target_laser_on(param_1);
    return;
  }
  target_laser_off(param_1);
  return;
}



/* SP_target_laser @ 100189b0 status created size 33 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_target_laser(int param_1)

{
  *(code **)(param_1 + 500) = target_laser_start;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + _DAT_10044104;
  return;
}



/* target_lightramp_think @ 100189e0 status existing size 204 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl target_lightramp_think(int param_1)

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



/* target_lightramp_use @ 10018ab0 status existing size 279 */

void __cdecl target_lightramp_use(undefined4 *param_1)

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
      uVar6 = G_Find(uVar6,300,(byte *)param_1[0x4a]);
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
        puVar4 = vtos();
        (*DAT_1006c1c4)(s__s_at__s_1004ba84,param_1[0x46],puVar4,puVar8);
        iVar3 = uVar6 + 4;
        puVar4 = vtos();
        (*DAT_1006c1c4)(s_target__s___s_at__s__is_not_a_li_1004ba5c,param_1[0x4a],
                        *(undefined4 *)(uVar6 + 0x118),puVar4,iVar3);
      }
    }
    if (param_1[0x97] == 0) {
      puVar8 = param_1 + 1;
      puVar4 = vtos();
      (*DAT_1006c1c4)(s__s_target__s_not_found_at__s_1004ba3c,param_1[0x46],param_1[0x4a],puVar4,
                      puVar8);
      G_FreeEdict(param_1);
      return;
    }
  }
  param_1[0x48] = DAT_1006c2e4;
  target_lightramp_think((int)param_1);
  return;
}



/* SP_target_lightramp @ 10018bd0 status existing size 316 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_target_lightramp(undefined4 *param_1)

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
        G_FreeEdict(param_1);
        return;
      }
      if (param_1[0x4a] == 0) {
        puVar7 = param_1 + 1;
        puVar4 = vtos();
        (*DAT_1006c1c4)(s__s_with_no_target_at__s_10049600,param_1[0x46],puVar4,puVar7);
        G_FreeEdict(param_1);
        return;
      }
      param_1[0x80] = target_lightramp_use;
      param_1[0x7d] = target_lightramp_think;
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
  puVar4 = vtos();
  (*DAT_1006c1c4)(s_target_lightramp_has_bad_ramp____1004ba90,param_1[0x45],puVar4,puVar7);
  G_FreeEdict(param_1);
  return;
}



/* target_earthquake_think @ 10018d10 status existing size 334 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl target_earthquake_think(int param_1)

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



/* target_earthquake_use @ 10018e60 status created size 61 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void target_earthquake_use(int param_1,undefined4 param_2,undefined4 param_3)

{
  float fVar1;
  
  *(float *)(param_1 + 0x120) = (float)*(int *)(param_1 + 0x254) + DAT_1006c2e4;
  fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
  *(undefined4 *)(param_1 + 0x264) = param_3;
  *(undefined4 *)(param_1 + 0x21c) = 0;
  *(float *)(param_1 + 0x1ec) = fVar1;
  return;
}



/* SP_target_earthquake @ 10018ea0 status existing size 151 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_target_earthquake(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 300) == 0) {
    iVar3 = param_1 + 4;
    puVar1 = vtos();
    (*DAT_1006c1c4)(s_untargeted__s_at__s_1004bacc,*(undefined4 *)(param_1 + 0x118),puVar1,iVar3);
  }
  if (*(int *)(param_1 + 0x254) == 0) {
    *(undefined4 *)(param_1 + 0x254) = 5;
  }
  if (*(float *)(param_1 + 0x148) == _DAT_1004410c) {
    *(undefined4 *)(param_1 + 0x148) = 0x43480000;
  }
  *(code **)(param_1 + 500) = target_earthquake_think;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  *(code **)(param_1 + 0x200) = target_earthquake_use;
  uVar2 = (*DAT_1006c1e4)(s_world_quake_wav_1004babc);
  *(undefined4 *)(param_1 + 0x280) = uVar2;
  return;
}



/* InitTrigger @ 10018f40 status existing size 90 */

void __cdecl InitTrigger(int param_1)

{
  int iVar1;
  
  iVar1 = VectorCompare((float *)(param_1 + 0x10),(float *)&DAT_10061c18);
  if (iVar1 == 0) {
    G_SetMovedir((float *)(param_1 + 0x10),(float *)(param_1 + 0x154));
  }
  *(undefined4 *)(param_1 + 0xf8) = 1;
  *(undefined4 *)(param_1 + 0x104) = 0;
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  *(undefined4 *)(param_1 + 0xb8) = 1;
  return;
}



/* multi_wait @ 10018fa0 status created size 15 */

void multi_wait(int param_1)

{
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  return;
}



/* multi_trigger @ 10018fb0 status existing size 129 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl multi_trigger(uint param_1)

{
  float fVar1;
  
  if (*(float *)(param_1 + 0x1ec) == _DAT_1004410c) {
    G_UseTargets(param_1,*(int *)(param_1 + 0x264));
    if (_DAT_1004410c < *(float *)(param_1 + 0x290)) {
      *(code **)(param_1 + 500) = multi_wait;
      *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + *(float *)(param_1 + 0x290);
      return;
    }
    *(undefined4 *)(param_1 + 0x1fc) = 0;
    fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
    *(code **)(param_1 + 500) = G_FreeEdict;
    *(float *)(param_1 + 0x1ec) = fVar1;
  }
  return;
}



/* Use_Multi @ 10019040 status created size 22 */

void Use_Multi(uint param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x264) = param_3;
  multi_trigger(param_1);
  return;
}



/* Touch_Multi @ 10019060 status created size 143 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Touch_Multi(uint param_1,int param_2)

{
  int iVar1;
  float10 fVar2;
  float afStack_c [3];
  
  if (*(int *)(param_2 + 0x54) == 0) {
    if ((*(byte *)(param_2 + 0xb8) & 4) == 0) {
      return;
    }
    if ((*(byte *)(param_1 + 0x11c) & 1) == 0) {
      return;
    }
  }
  else if ((*(byte *)(param_1 + 0x11c) & 2) != 0) {
    return;
  }
  iVar1 = VectorCompare((float *)(param_1 + 0x154),(float *)&DAT_10061c18);
  if (iVar1 == 0) {
    AngleVectors((float *)(param_2 + 0x10),afStack_c,(float *)0x0,(float *)0x0);
    fVar2 = DotProduct(afStack_c,(float *)(param_1 + 0x154));
    if (fVar2 < (float10)_DAT_1004410c) {
      return;
    }
  }
  *(int *)(param_1 + 0x264) = param_2;
  multi_trigger(param_1);
  return;
}



/* trigger_enable @ 100190f0 status created size 33 */

void trigger_enable(int param_1)

{
  *(undefined4 *)(param_1 + 0xf8) = 1;
  *(code **)(param_1 + 0x200) = Use_Multi;
  (*DAT_1006c208)(param_1);
  return;
}



/* SP_trigger_multiple @ 10019120 status existing size 235 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_trigger_multiple(int param_1)

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
  *(code **)(param_1 + 0x1fc) = Touch_Multi;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  if ((*(byte *)(param_1 + 0x11c) & 4) == 0) {
    *(undefined4 *)(param_1 + 0xf8) = 1;
    *(code **)(param_1 + 0x200) = Use_Multi;
  }
  else {
    *(undefined4 *)(param_1 + 0xf8) = 0;
    *(code **)(param_1 + 0x200) = trigger_enable;
  }
  iVar2 = VectorCompare((float *)(param_1 + 0x10),(float *)&DAT_10061c18);
  if (iVar2 == 0) {
    G_SetMovedir((float *)(param_1 + 0x10),(float *)(param_1 + 0x154));
  }
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  (*DAT_1006c208)(param_1);
  return;
}



/* SP_trigger_once @ 10019210 status created size 118 */

void SP_trigger_once(int param_1)

{
  undefined *puVar1;
  float *pfVar2;
  float afStack_c [3];
  
  if ((*(byte *)(param_1 + 0x11c) & 1) != 0) {
    VectorMA((float *)(param_1 + 0xbc),0.5,(float *)(param_1 + 0xec),afStack_c);
    pfVar2 = afStack_c;
    *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) & 0xfffffffe | 4;
    puVar1 = vtos();
    (*DAT_1006c1c4)(s_fixed_TRIGGERED_flag_on__s_at__s_1004bae4,*(undefined4 *)(param_1 + 0x118),
                    puVar1,pfVar2);
  }
  *(undefined4 *)(param_1 + 0x290) = 0xbf800000;
  SP_trigger_multiple(param_1);
  return;
}



/* trigger_relay_use @ 10019290 status created size 19 */

void trigger_relay_use(uint param_1,undefined4 param_2,int param_3)

{
  G_UseTargets(param_1,param_3);
  return;
}



/* SP_trigger_relay @ 100192b0 status created size 15 */

void SP_trigger_relay(int param_1)

{
  *(code **)(param_1 + 0x200) = trigger_relay_use;
  return;
}



/* trigger_key_use @ 100192c0 status created size 623 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void trigger_key_use(uint param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  bool bVar11;
  int iStack_8;
  
  iVar6 = *(int *)(param_1 + 0x2cc);
  if ((iVar6 != 0) && (*(int *)(param_3 + 0x54) != 0)) {
    iVar3 = (iVar6 + -0x10046928) / 0x48;
    if (*(int *)(*(int *)(param_3 + 0x54) + 0x2e4 + iVar3 * 4) == 0) {
      if (*(float *)(param_1 + 0x20c) <= DAT_1006c2e4) {
        *(float *)(param_1 + 0x20c) = DAT_1006c2e4 + (float)_DAT_10044150;
        (*DAT_1006c1cc)(param_3,s_You_need_the__s_1004bb28,*(undefined4 *)(iVar6 + 0x28));
        uVar4 = (*DAT_1006c1e4)(s_misc_keytry_wav_1004bb18,0x3f800000,0x3f800000,0);
        (*DAT_1006c1d0)(param_3,0,uVar4);
        return;
      }
    }
    else {
      uVar4 = (*DAT_1006c1e4)(s_misc_keyuse_wav_1004bb08,0x3f800000,0x3f800000,0);
      (*DAT_1006c1d0)(param_3,0,uVar4);
      if (*(float *)(DAT_1006c42c + 0x14) == _DAT_1004410c) {
        *(int *)(*(int *)(param_3 + 0x54) + 0x2e4 + iVar3 * 4) =
             *(int *)(*(int *)(param_3 + 0x54) + 0x2e4 + iVar3 * 4) + -1;
      }
      else {
        pcVar9 = s_key_power_cube_10047b64;
        pbVar5 = (byte *)**(undefined4 **)(param_1 + 0x2cc);
        do {
          bVar1 = *pbVar5;
          bVar11 = bVar1 < (byte)*pcVar9;
          if (bVar1 != *pcVar9) {
LAB_100193f6:
            iVar6 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
            goto LAB_100193fb;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar5[1];
          bVar11 = bVar1 < (byte)pcVar9[1];
          if (bVar1 != pcVar9[1]) goto LAB_100193f6;
          pbVar5 = pbVar5 + 2;
          pcVar9 = pcVar9 + 2;
        } while (bVar1 != 0);
        iVar6 = 0;
LAB_100193fb:
        if (iVar6 == 0) {
          iVar6 = 0;
          do {
            if ((*(uint *)(*(int *)(param_3 + 0x54) + 0x71c) & 1 << ((byte)iVar6 & 0x1f)) != 0)
            break;
            iVar6 = iVar6 + 1;
          } while (iVar6 < 8);
          iStack_8 = 1;
          if (0 < DAT_1006ca48) {
            iVar10 = 0x3d0;
            iVar8 = DAT_1006c2c4;
            do {
              if (*(int *)(iVar10 + 0x58 + iVar8) != 0) {
                iVar2 = *(int *)(iVar10 + 0x54 + iVar8);
                if ((iVar2 != 0) &&
                   (uVar7 = 1 << ((byte)iVar6 & 0x1f), (uVar7 & *(uint *)(iVar2 + 0x71c)) != 0)) {
                  *(int *)(iVar2 + 0x2e4 + iVar3 * 4) = *(int *)(iVar2 + 0x2e4 + iVar3 * 4) + -1;
                  iVar8 = *(int *)(iVar10 + 0x54 + iVar8);
                  *(uint *)(iVar8 + 0x71c) = *(uint *)(iVar8 + 0x71c) & ~uVar7;
                  iVar8 = DAT_1006c2c4;
                }
              }
              iStack_8 = iStack_8 + 1;
              iVar10 = iVar10 + 0x3d0;
            } while (iStack_8 <= DAT_1006ca48);
          }
        }
        else {
          iVar6 = 1;
          if (0 < DAT_1006ca48) {
            iVar10 = 0x3d0;
            iVar8 = DAT_1006c2c4;
            do {
              if ((*(int *)(iVar10 + 0x58 + iVar8) != 0) &&
                 (iVar2 = *(int *)(iVar10 + 0x54 + iVar8), iVar2 != 0)) {
                *(undefined4 *)(iVar2 + 0x2e4 + iVar3 * 4) = 0;
                iVar8 = DAT_1006c2c4;
              }
              iVar6 = iVar6 + 1;
              iVar10 = iVar10 + 0x3d0;
            } while (iVar6 <= DAT_1006ca48);
          }
        }
      }
      G_UseTargets(param_1,param_3);
      *(undefined4 *)(param_1 + 0x200) = 0;
    }
  }
  return;
}



/* SP_trigger_key @ 10019530 status created size 176 */

void SP_trigger_key(int param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (DAT_1006c2ac == (byte *)0x0) {
    param_1 = param_1 + 4;
    puVar1 = vtos();
    (*DAT_1006c1c4)(s_no_key_item_for_trigger_key_at___1004bb7c,puVar1,param_1);
    return;
  }
  puVar2 = FindItemByClassname(DAT_1006c2ac);
  *(undefined4 **)(param_1 + 0x2cc) = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    param_1 = param_1 + 4;
    puVar1 = vtos();
    (*DAT_1006c1c4)(s_item__s_not_found_for_trigger_ke_1004bb50,DAT_1006c2ac,puVar1,param_1);
    return;
  }
  if (*(int *)(param_1 + 0x128) == 0) {
    iVar3 = param_1 + 4;
    puVar1 = vtos();
    (*DAT_1006c1c4)(s__s_at__s_has_no_target_1004bb38,*(undefined4 *)(param_1 + 0x118),puVar1,iVar3)
    ;
    return;
  }
  (*DAT_1006c1e4)(s_misc_keytry_wav_1004bb18);
  (*DAT_1006c1e4)(s_misc_keyuse_wav_1004bb08);
  *(code **)(param_1 + 0x200) = trigger_key_use;
  return;
}



/* trigger_counter_use @ 100195e0 status existing size 191 */

void __cdecl trigger_counter_use(uint param_1,undefined4 param_2,undefined4 param_3)

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
      multi_trigger(param_1);
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



/* SP_trigger_counter @ 100196a0 status created size 45 */

void SP_trigger_counter(int param_1)

{
  *(undefined4 *)(param_1 + 0x290) = 0xbf800000;
  if (*(int *)(param_1 + 0x254) == 0) {
    *(undefined4 *)(param_1 + 0x254) = 2;
  }
  *(code **)(param_1 + 0x200) = trigger_counter_use;
  return;
}



/* SP_trigger_always @ 100196d0 status created size 44 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_trigger_always(uint param_1)

{
  if (*(float *)(param_1 + 0x294) < (float)_DAT_10044198) {
    *(undefined4 *)(param_1 + 0x294) = 0x3e4ccccd;
  }
  G_UseTargets(param_1,param_1);
  return;
}



/* trigger_push_touch @ 10019700 status existing size 301 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl trigger_push_touch(undefined4 *param_1,int param_2)

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
    VectorScale((float *)(param_1 + 0x55),(float)param_1[0x52] * _DAT_100441b0,
                (float *)(param_2 + 0x178));
  }
  else if (0 < *(int *)(param_2 + 0x220)) {
    VectorScale((float *)(param_1 + 0x55),(float)param_1[0x52] * _DAT_100441b0,
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
    G_FreeEdict(param_1);
  }
  return;
}



/* SP_trigger_push @ 10019850 status existing size 108 */

/* WARNING: Removing unreachable block (ram,0x1001987f) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_trigger_push(int param_1)

{
  bool bVar1;
  
  InitTrigger(param_1);
  DAT_10060e7c = (*DAT_1006c1e4)(s_misc_windfly_wav_1004bbd0);
  bVar1 = *(float *)(param_1 + 0x148) == _DAT_1004410c;
  *(undefined1 **)(param_1 + 0x200) = &LAB_10019830;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x148) = 0x447a0000;
  }
  (*DAT_1006c208)(param_1);
  return;
}



/* hurt_use @ 100198c0 status existing size 56 */

void __cdecl hurt_use(int param_1)

{
  *(uint *)(param_1 + 0xf8) = (uint)(*(int *)(param_1 + 0xf8) == 0);
  (*DAT_1006c208)(param_1);
  if ((*(byte *)(param_1 + 0x11c) & 2) == 0) {
    *(undefined4 *)(param_1 + 0x200) = 0;
  }
  return;
}



/* hurt_touch @ 10019900 status created size 192 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void hurt_touch(int param_1,uint param_2)

{
  float fVar1;
  
  if ((*(int *)(param_2 + 0x240) != 0) && (*(float *)(param_1 + 0x120) <= DAT_1006c2e4)) {
    fVar1 = _DAT_10044104;
    if ((*(uint *)(param_1 + 0x11c) & 0x10) == 0) {
      fVar1 = (float)_DAT_10044168;
    }
    *(float *)(param_1 + 0x120) = DAT_1006c2e4 + fVar1;
    if (((*(uint *)(param_1 + 0x11c) & 4) == 0) && (DAT_1006c2e0 % 10 == 0)) {
      (*DAT_1006c1d0)(param_2,0,*(undefined4 *)(param_1 + 0x280),0x3f800000,0x3f800000,0);
    }
    FUN_100060d0(param_2,param_1,param_1,(float *)&DAT_10061c18,(float *)(param_2 + 4),&DAT_10061c18
                 ,*(int *)(param_1 + 0x244),*(int *)(param_1 + 0x244),
                 ((int)*(char *)(param_1 + 0x11c) & 8U) << 2,0x1f);
  }
  return;
}



/* SP_trigger_hurt @ 100199c0 status existing size 119 */

void __cdecl SP_trigger_hurt(int param_1)

{
  undefined4 uVar1;
  
  InitTrigger(param_1);
  uVar1 = (*DAT_1006c1e4)(s_world_electro_wav_1004bbe4);
  *(undefined4 *)(param_1 + 0x280) = uVar1;
  *(code **)(param_1 + 0x1fc) = hurt_touch;
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
    *(code **)(param_1 + 0x200) = hurt_use;
  }
  (*DAT_1006c208)(param_1);
  return;
}



/* trigger_gravity_touch @ 10019a40 status created size 21 */

void trigger_gravity_touch(int param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x198) = *(undefined4 *)(param_1 + 0x198);
  return;
}



/* SP_trigger_gravity @ 10019a60 status created size 93 */

void SP_trigger_gravity(undefined4 *param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (DAT_1006c2b0 == (void *)0x0) {
    puVar3 = param_1 + 1;
    puVar1 = vtos();
    (*DAT_1006c1c4)(s_trigger_gravity_without_gravity_s_1004bbf8,puVar1,puVar3);
    G_FreeEdict(param_1);
    return;
  }
  InitTrigger((int)param_1);
  iVar2 = FUN_10039237(DAT_1006c2b0,DAT_1006c2b0);
  param_1[0x7f] = trigger_gravity_touch;
  param_1[0x66] = (float)iVar2;
  return;
}



/* trigger_monsterjump_touch @ 10019ac0 status created size 102 */

void trigger_monsterjump_touch(int param_1,int param_2)

{
  if ((((*(byte *)(param_2 + 0x108) & 3) == 0) && ((*(uint *)(param_2 + 0xb8) & 2) == 0)) &&
     ((*(uint *)(param_2 + 0xb8) & 4) != 0)) {
    *(float *)(param_2 + 0x178) = *(float *)(param_1 + 0x154) * *(float *)(param_1 + 0x148);
    *(float *)(param_2 + 0x17c) = *(float *)(param_1 + 0x158) * *(float *)(param_1 + 0x148);
    if (*(int *)(param_2 + 0x268) != 0) {
      *(undefined4 *)(param_2 + 0x268) = 0;
      *(undefined4 *)(param_2 + 0x180) = *(undefined4 *)(param_1 + 0x15c);
    }
  }
  return;
}



/* SP_trigger_monsterjump @ 10019b30 status existing size 109 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_trigger_monsterjump(int param_1)

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
  InitTrigger(param_1);
  *(code **)(param_1 + 0x1fc) = trigger_monsterjump_touch;
  *(float *)(param_1 + 0x15c) = (float)DAT_1006c2a0;
  return;
}



/* trigger_teleport_touch @ 10019ba0 status existing size 370 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl trigger_teleport_touch(int param_1,int param_2)

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
    uVar5 = G_Find(0,300,*(byte **)(param_1 + 0x128));
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
    KillBox(param_2);
    (*DAT_1006c208)(param_2);
  }
  return;
}



/* trigger_teleport_enable @ 10019d20 status existing size 31 */

void __cdecl trigger_teleport_enable(int param_1)

{
  (*DAT_1006c1c0)(2,s_enabled_1004bc24);
  *(code **)(param_1 + 0x1fc) = trigger_teleport_touch;
  return;
}



/* trigger_teleport_disable @ 10019d40 status existing size 31 */

void __cdecl trigger_teleport_disable(int param_1)

{
  (*DAT_1006c1c0)(2,s_disabled_1004bc30);
  *(undefined4 *)(param_1 + 0x1fc) = 0;
  return;
}



/* trigger_teleport_activate @ 10019d60 status existing size 44 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl trigger_teleport_activate(int param_1)

{
  trigger_teleport_enable(param_1);
  *(code **)(param_1 + 500) = trigger_teleport_disable;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  return;
}



/* trigger_teleport_toggle @ 10019d90 status created size 31 */

void trigger_teleport_toggle(int param_1)

{
  if (*(int *)(param_1 + 0x1fc) == 0) {
    trigger_teleport_enable(param_1);
    return;
  }
  trigger_teleport_disable(param_1);
  return;
}



/* SP_trigger_teleport @ 10019db0 status existing size 223 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_trigger_teleport(int param_1)

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
    *(code **)(param_1 + 0x200) = trigger_teleport_toggle;
    if ((uVar1 & 4) == 0) {
      *(code **)(param_1 + 0x1fc) = trigger_teleport_touch;
    }
    else {
      *(undefined4 *)(param_1 + 0x1fc) = 0;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1fc) = 0;
    *(code **)(param_1 + 0x200) = trigger_teleport_activate;
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



/* AnglesNormalize @ 10019e90 status existing size 163 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl AnglesNormalize(float *param_1)

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



/* SnapToEights @ 10019f40 status existing size 75 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl SnapToEights(float param_1)

{
  longlong lVar1;
  
  if ((float)_DAT_10044268 < param_1 * (float)_DAT_10044270) {
    lVar1 = __ftol();
    return (float10)(int)lVar1 * (float10)_DAT_10044260;
  }
  lVar1 = __ftol();
  return (float10)(int)lVar1 * (float10)_DAT_10044260;
}



/* turret_breach_fire @ 10019fe0 status existing size 274 */

void __cdecl turret_breach_fire(int param_1)

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
  
  AngleVectors((float *)(param_1 + 0x10),local_24,local_18,local_c);
  VectorMA((float *)(param_1 + 4),*(float *)(param_1 + 0x2ac),local_24,local_30);
  VectorMA(local_30,*(float *)(param_1 + 0x2b0),local_18,local_30);
  VectorMA(local_30,*(float *)(param_1 + 0x2b4),local_c,local_30);
  _rand();
  lVar2 = __ftol();
  iVar4 = 0x43160000;
  iVar5 = (int)lVar2;
  lVar3 = __ftol();
  fire_rocket(*(int *)(*(int *)(param_1 + 0x274) + 0x100),local_30,local_24,(int)lVar2,(int)lVar3,
              iVar4,iVar5);
  uVar1 = (*DAT_1006c1e4)(s_weapons_rocklf1a_wav_1004ba04,0x3f800000,0x3f800000,0);
  (*DAT_1006c1d4)(local_30,param_1,1,uVar1);
  return;
}



/* turret_breach_think @ 1001a100 status existing size 938 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl turret_breach_think(int param_1)

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
  AnglesNormalize(&local_c);
  pfVar1 = (float *)(param_1 + 0x2b8);
  AnglesNormalize(pfVar1);
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
  VectorScale(&local_18,10.0,(float *)(param_1 + 0x184));
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
    fVar6 = SnapToEights((float)(fVar6 * (float10)*(float *)(*(int *)(param_1 + 0x100) + 0x2ac) +
                                (float10)*(float *)(param_1 + 4)));
    fVar5 = (float10)fsin((float10)(float)fVar5);
    fVar5 = SnapToEights((float)(fVar5 * (float10)*(float *)(*(int *)(param_1 + 0x100) + 0x2ac) +
                                (float10)*(float *)(param_1 + 8)));
    iVar2 = *(int *)(param_1 + 0x100);
    *(float *)(iVar2 + 0x178) = ((float)fVar6 - *(float *)(iVar2 + 4)) * (float)_DAT_10044170;
    *(float *)(*(int *)(param_1 + 0x100) + 0x17c) =
         (float)((fVar5 - (float10)*(float *)(iVar2 + 8)) * (float10)_DAT_10044170);
    fVar5 = (float10)fptan((float10)*(float *)(param_1 + 0x10) * (float10)_DAT_100442b8);
    fVar5 = SnapToEights((float)(fVar5 * (float10)*(float *)(*(int *)(param_1 + 0x100) + 0x2ac) +
                                 (float10)*(float *)(*(int *)(param_1 + 0x100) + 0x2b4) +
                                (float10)*(float *)(param_1 + 0xc)));
    *(float *)(*(int *)(param_1 + 0x100) + 0x180) =
         (float)((fVar5 - (float10)*(float *)(*(int *)(param_1 + 0x100) + 0xc)) *
                (float10)_DAT_10044170);
    if ((*(uint *)(param_1 + 0x11c) & 0x10000) != 0) {
      turret_breach_fire(param_1);
      *(uint *)(param_1 + 0x11c) = *(uint *)(param_1 + 0x11c) & 0xfffeffff;
    }
  }
  return;
}



/* turret_breach_finish_init @ 1001a4b0 status existing size 144 */

void __cdecl turret_breach_finish_init(int param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (*(byte **)(param_1 + 0x128) == (byte *)0x0) {
    iVar3 = param_1 + 4;
    puVar1 = vtos();
    (*DAT_1006c1c4)(s__s_at__s_needs_a_target_1004bcd0,*(undefined4 *)(param_1 + 0x118),puVar1,iVar3
                   );
  }
  else {
    puVar2 = (undefined4 *)G_PickTarget(*(byte **)(param_1 + 0x128));
    *(undefined4 **)(param_1 + 0x144) = puVar2;
    *(float *)(param_1 + 0x2ac) = (float)puVar2[1] - *(float *)(param_1 + 4);
    *(float *)(param_1 + 0x2b0) = (float)puVar2[2] - *(float *)(param_1 + 8);
    *(float *)(param_1 + 0x2b4) = (float)puVar2[3] - *(float *)(param_1 + 0xc);
    G_FreeEdict(puVar2);
  }
  *(undefined4 *)(*(int *)(param_1 + 0x274) + 0x244) = *(undefined4 *)(param_1 + 0x244);
  *(code **)(param_1 + 500) = turret_breach_think;
  turret_breach_think(param_1);
  return;
}



/* SP_turret_breach @ 1001a540 status existing size 303 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_turret_breach(int param_1)

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
  *(code **)(param_1 + 500) = turret_breach_finish_init;
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  (*DAT_1006c208)(param_1);
  return;
}



/* SP_turret_base @ 1001a670 status existing size 61 */

void __cdecl SP_turret_base(int param_1)

{
  *(undefined4 *)(param_1 + 0xf8) = 3;
  *(undefined4 *)(param_1 + 0x104) = 2;
  (*DAT_1006c1ec)(param_1,*(undefined4 *)(param_1 + 0x10c));
  *(undefined1 **)(param_1 + 0x1f8) = &LAB_10019f90;
  (*DAT_1006c208)(param_1);
  return;
}



/* G_Find @ 1001ac00 status existing size 150 */

uint __cdecl G_Find(int param_1,int param_2,byte *param_3)

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



/* findradius @ 1001aca0 status existing size 216 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl findradius(int param_1,int param_2,float param_3)

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
        fVar6 = VectorLength(local_c);
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



/* G_PickTarget @ 1001ad80 status existing size 120 */

uint __cdecl G_PickTarget(byte *param_1)

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
    uVar1 = G_Find(uVar1,300,param_1);
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



/* Think_Delay @ 1001ae00 status existing size 29 */

void __cdecl Think_Delay(undefined4 *param_1)

{
  G_UseTargets((uint)param_1,param_1[0x99]);
  G_FreeEdict(param_1);
  return;
}



/* G_UseTargets @ 1001ae20 status existing size 534 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl G_UseTargets(uint param_1,int param_2)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  if (*(float *)(param_1 + 0x294) != _DAT_1004410c) {
    piVar2 = G_Spawn();
    piVar2[0x46] = (int)s_DelayedUse_1004be24;
    fVar1 = DAT_1006c2e4 + *(float *)(param_1 + 0x294);
    piVar2[0x7d] = (int)Think_Delay;
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
    for (puVar4 = (undefined4 *)G_Find(0,300,*(byte **)(param_1 + 0x130));
        puVar4 != (undefined4 *)0x0;
        puVar4 = (undefined4 *)G_Find((int)puVar4,300,*(byte **)(param_1 + 0x130))) {
      G_FreeEdict(puVar4);
      if (*(int *)(param_1 + 0x58) == 0) {
        (*DAT_1006c1c4)(s_entity_was_removed_while_using_k_1004bdb8);
        return;
      }
    }
  }
  if ((*(byte **)(param_1 + 0x128) != (byte *)0x0) &&
     (uVar5 = G_Find(0,300,*(byte **)(param_1 + 0x128)), uVar5 != 0)) {
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
      uVar5 = G_Find(uVar5,300,*(byte **)(param_1 + 0x128));
      if (uVar5 == 0) {
        return;
      }
    } while( true );
  }
  return;
}



/* tv @ 1001b040 status existing size 47 */

void __cdecl tv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = DAT_10060fe4 * 0xc;
  DAT_10060fe4 = DAT_10060fe4 + 1 & 7;
  *(undefined4 *)(&DAT_10060e80 + iVar1) = param_1;
  *(undefined4 *)(&DAT_10060e84 + iVar1) = param_2;
  *(undefined4 *)(&DAT_10060e88 + iVar1) = param_3;
  return;
}



/* vtos @ 1001b070 status existing size 78 */

undefined * vtos(void)

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



/* G_SetMovedir @ 1001b0c0 status existing size 145 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl G_SetMovedir(float *param_1,float *param_2)

{
  int iVar1;
  
  iVar1 = VectorCompare(param_1,(float *)&DAT_1004bd10);
  if (iVar1 == 0) {
    iVar1 = VectorCompare(param_1,(float *)&DAT_1004bd28);
    if (iVar1 == 0) {
      AngleVectors(param_1,param_2,(float *)0x0,(float *)0x0);
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



/* vectoangles @ 1001b1e0 status existing size 294 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl vectoangles(float *param_1,float *param_2)

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



/* kigrax_search @ 10028df0 status created size 99 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void kigrax_search(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = _rand();
  if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044140) {
    (*DAT_1006c1d0)(param_1,2,DAT_10061264);
    return;
  }
  (*DAT_1006c1d0)(param_1,2,DAT_10061260,0x3f800000,0x3f800000,0);
  return;
}



/* kigrax_sight @ 10028e60 status created size 47 */

void kigrax_sight(int param_1)

{
  (*DAT_1006c1d0)(param_1,2,DAT_1006126c,0x3f800000,0x3f800000,0);
  *(undefined **)(param_1 + 0x358) = &DAT_10058ce8;
  return;
}



/* kigrax_stand @ 10028e90 status existing size 75 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl kigrax_stand(int param_1)

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



/* kigrax_run @ 10028ee0 status created size 51 */

void kigrax_run(int param_1)

{
  (*DAT_1006c1c0)(1,s_running____1005915c);
  if ((*(byte *)(param_1 + 0x35c) & 1) != 0) {
    *(undefined **)(param_1 + 0x358) = &DAT_10058818;
    return;
  }
  *(undefined **)(param_1 + 0x358) = &DAT_10058dc8;
  return;
}



/* kigrax_walk @ 10028f20 status created size 86 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall kigrax_walk(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  (*DAT_1006c1c0)(1,s_walking____10059168,param_1);
  uVar1 = _rand();
  if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044128) {
    *(undefined **)(param_2 + 0x358) = &DAT_10058c08;
    return;
  }
  *(undefined **)(param_2 + 0x358) = &DAT_10058ae0;
  return;
}



/* kigrax_fire_plasma @ 10028f80 status created size 152 */

void kigrax_fire_plasma(int param_1)

{
  int iVar1;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float afStack_18 [3];
  float afStack_c [3];
  
  AngleVectors((float *)(param_1 + 0x10),afStack_c,afStack_18,(float *)0x0);
  FUN_1001aba0((float *)(param_1 + 4),(float *)0x10059150,afStack_c,afStack_18,&fStack_3c);
  iVar1 = *(int *)(param_1 + 0x25c);
  fStack_2c = *(float *)(iVar1 + 8);
  fStack_28 = (float)*(int *)(iVar1 + 0x23c) + *(float *)(iVar1 + 0xc);
  fStack_24 = *(float *)(iVar1 + 4) - fStack_3c;
  fStack_20 = fStack_2c - fStack_38;
  fStack_1c = fStack_28 - fStack_34;
  func_0x10011b20(param_1,&fStack_3c,&fStack_24,10,1000,1);
  return;
}



/* kigrax_attack @ 10029020 status created size 15 */

void kigrax_attack(int param_1)

{
  *(undefined **)(param_1 + 0x358) = &DAT_10059140;
  return;
}



/* kigrax_melee @ 10029030 status existing size 145 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl kigrax_melee(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (0 < *(int *)(*(int *)(param_1 + 0x25c) + 0x220)) {
    iVar1 = range(param_1,*(int *)(param_1 + 0x25c));
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



/* kigrax_strike1 @ 100290d0 status created size 102 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void kigrax_strike1(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = *(undefined4 *)(param_1 + 0xbc);
  uStack_c = 0x42a00000;
  uStack_4 = 0x41200000;
  (*DAT_1006c1d0)(param_1,1,_DAT_10061270,0x3f800000,0x3f800000,0);
  uVar2 = 100;
  iVar1 = _rand();
  func_0x1001b5a0(param_1,&uStack_c,iVar1 % 6 + 10,uVar2);
  return;
}



/* kigrax_strike2 @ 10029140 status created size 101 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void kigrax_strike2(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = *(undefined4 *)(param_1 + 0xbc);
  uStack_c = 0x42a00000;
  uStack_4 = 0x41200000;
  (*DAT_1006c1d0)(param_1,1,_DAT_10061270,0x3f800000,0x3f800000,0);
  uVar2 = 100;
  iVar1 = _rand();
  func_0x1001b5a0(param_1,&uStack_c,iVar1 % 0x14 + 0x14,uVar2);
  return;
}



/* kigrax_pain @ 100291b0 status created size 99 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void kigrax_pain(int param_1)

{
  if ((*(float *)(param_1 + 0x210) <= DAT_1006c2e4) &&
     (*(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4,
     *(int *)(DAT_1006c41c + 0x14) != 0x40400000)) {
    (*DAT_1006c1d0)(param_1,2,DAT_10061268,0x3f800000,0x3f800000,0);
    *(undefined **)(param_1 + 0x358) = &DAT_10058e60;
  }
  return;
}



/* kigrax_die @ 10029220 status created size 261 */

/* WARNING: Removing unreachable block (ram,0x100292e7) */

void kigrax_die(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_1006c104 == 0x23) {
    FUN_1000e460(param_1);
    return;
  }
  if ((int)param_1[0x8a] < (int)param_1[0x88]) {
    if (param_1[0x8b] != 2) {
      param_1[0x8b] = 2;
      param_1[0x90] = 1;
      param_1[0xd6] = &DAT_10058f58;
    }
    return;
  }
  uVar1 = (*DAT_1006c1e4)(s_misc_udeath_wav_100493f8,0x3f800000,0x3f800000,0);
  (*DAT_1006c1d0)(param_1,2,uVar1);
  iVar2 = 2;
  do {
    FUN_1000dd30((float)param_1,s_models_objects_gibs_bone_tris_md_1004b5a4,param_4,0);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 2;
  do {
    FUN_1000dd30((float)param_1,s_models_objects_gibs_sm_meat_tris_100493d0,param_4,0);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_1000df70((float)param_1,s_models_objects_gibs_sm_meat_tris_100493d0,param_4,0);
  param_1[0x8b] = 2;
  return;
}



/* SP_monster_kigrax @ 10029354 status created size 394 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_monster_kigrax(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_1006c1e0)(s_models_monsters_kigrax_tris_md2_1005919c);
  param_2[10] = uVar1;
  DAT_10061268 = (*DAT_1006c1e4)(s_hover_hovpain1_wav_10056b78);
  DAT_10061274 = (*DAT_1006c1e4)(s_hover_hovdeth1_wav_10056b50);
  DAT_1006126c = (*DAT_1006c1e4)(s_hover_hovsght1_wav_10056b28);
  DAT_10061264 = (*DAT_1006c1e4)(s_hover_hovsrch1_wav_10056b14);
  DAT_10061260 = (*DAT_1006c1e4)(s_hover_hovsrch2_wav_10056b00);
  _DAT_10061270 = (*DAT_1006c1e4)(s_chick_chkatck3_wav_100514f0);
  (*DAT_1006c1e4)(s_kigrax_hovatck1_wav_10059188);
  uVar1 = (*DAT_1006c1e4)(s_kigrax_hovidle1_wav_10059174);
  param_2[0x13] = uVar1;
  param_2[0x2f] = 0xc1a00000;
  param_2[0x30] = 0xc1a00000;
  param_2[0x31] = 0xc2000000;
  param_2[0x32] = 0x41a00000;
  param_2[0x33] = 0x41a00000;
  param_2[0x34] = 0x41400000;
  param_2[0x41] = 5;
  param_2[0x3e] = 2;
  param_2[0x88] = 200;
  param_2[0x8a] = 0xffffff9c;
  param_2[100] = 0x96;
  param_2[0x81] = kigrax_pain;
  param_2[0x82] = kigrax_die;
  param_2[0xda] = kigrax_stand;
  param_2[0xdd] = kigrax_walk;
  param_2[0xde] = kigrax_run;
  param_2[0xe0] = kigrax_attack;
  param_2[0xe1] = kigrax_melee;
  param_2[0xe2] = kigrax_sight;
  param_2[0xdc] = kigrax_search;
  param_2[0xdb] = kigrax_stand;
  param_2[0x79] = 0x41a00000;
  param_2[0x8f] = 0x5a;
  (*DAT_1006c208)(param_2);
  param_2[0xd6] = &DAT_10058818;
  param_2[0xd9] = 0x3f800000;
  flymonster_start(param_2);
  return;
}



/* kigrax_dead @ 1002f030 status created size 92 */

void kigrax_dead(int param_1)

{
  *(undefined4 *)(param_1 + 0xbc) = 0xc1800000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc1800000;
  *(undefined4 *)(param_1 + 0xc4) = 0xc1800000;
  *(undefined4 *)(param_1 + 200) = 0x41800000;
  *(undefined4 *)(param_1 + 0xcc) = 0x41800000;
  *(undefined4 *)(param_1 + 0x104) = 7;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 2;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  (*DAT_1006c208)(param_1);
  return;
}



/* soldier_stand @ 1002c2d0 status existing size 78 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl soldier_stand(int param_1)

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



/* soldier_walk @ 1002c360 status created size 70 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void soldier_walk(int param_1)

{
  uint uVar1;
  
  uVar1 = _rand();
  if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044140) {
    *(undefined **)(param_1 + 0x358) = &DAT_1005b4d0;
    return;
  }
  *(undefined **)(param_1 + 0x358) = &DAT_1005b558;
  return;
}



/* soldier_run @ 1002c3b0 status created size 73 */

void soldier_run(int param_1)

{
  undefined *puVar1;
  
  if ((*(byte *)(param_1 + 0x35c) & 1) != 0) {
    *(undefined **)(param_1 + 0x358) = &DAT_1005b148;
    return;
  }
  puVar1 = *(undefined **)(param_1 + 0x358);
  if (((puVar1 != &DAT_1005b4d0) && (puVar1 != &DAT_1005b558)) && (puVar1 != &DAT_1005b580)) {
    *(undefined **)(param_1 + 0x358) = &DAT_1005b580;
    return;
  }
  *(undefined **)(param_1 + 0x358) = &DAT_1005b5d8;
  return;
}



/* soldier_pain @ 1002c400 status existing size 345 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl soldier_pain(int param_1)

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



/* soldier_fire @ 1002c560 status created size 791 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void soldier_fire(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  int iVar7;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float afStack_24 [3];
  float afStack_18 [3];
  float afStack_c [3];
  
  if (*(int *)(param_1 + 0x3c) < 2) {
    iVar7 = *(int *)(param_2 * 4 + 0x1005b868);
  }
  else if (*(int *)(param_1 + 0x3c) < 4) {
    iVar7 = *(int *)(param_2 * 4 + 0x1005b888);
  }
  else {
    iVar7 = *(int *)(param_2 * 4 + 0x1005b8a8);
  }
  AngleVectors((float *)(param_1 + 0x10),&fStack_30,afStack_24,(float *)0x0);
  FUN_1001aba0((float *)(param_1 + 4),(float *)(iVar7 * 0xc + 0x10051d04),&fStack_30,afStack_24,
               &fStack_3c);
  if ((param_2 == 5) || (param_2 == 6)) {
    fStack_48 = fStack_30;
    fStack_44 = fStack_2c;
    fStack_40 = fStack_28;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x25c);
    fStack_54 = *(float *)(iVar1 + 4);
    fStack_50 = *(float *)(iVar1 + 8);
    fStack_4c = (float)*(int *)(iVar1 + 0x23c) + *(float *)(iVar1 + 0xc);
    fStack_48 = fStack_54 - fStack_3c;
    fStack_44 = fStack_50 - fStack_38;
    fStack_40 = fStack_4c - fStack_34;
    vectoangles(&fStack_48,afStack_18);
    AngleVectors(afStack_18,&fStack_30,afStack_24,afStack_c);
    uVar6 = _rand();
    fVar2 = (float)(uVar6 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
    fVar3 = (float)_DAT_100443b8;
    uVar6 = _rand();
    fVar4 = (float)(uVar6 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
    fVar5 = (float)_DAT_10044180;
    VectorMA(&fStack_3c,8192.0,&fStack_30,&fStack_54);
    VectorMA(&fStack_54,(fVar2 + fVar2) * fVar3,afStack_24,&fStack_54);
    VectorMA(&fStack_54,(fVar4 + fVar4) * fVar5,afStack_c,&fStack_54);
    fStack_48 = fStack_54 - fStack_3c;
    fStack_44 = fStack_50 - fStack_38;
    fStack_40 = fStack_4c - fStack_34;
    VectorNormalize(&fStack_48);
  }
  iVar1 = *(int *)(param_1 + 0x3c);
  if (iVar1 < 2) {
    func_0x100118a0(param_1,&fStack_3c,&fStack_48,5,600,iVar7,8);
    return;
  }
  if (iVar1 < 4) {
    func_0x10011820(param_1,&fStack_3c,&fStack_48,2,1,1000,500,0xc,iVar7);
    return;
  }
  if (iVar1 < 6) {
    if ((*(byte *)(param_1 + 0x35c) & 0x80) == 0) {
      uVar6 = _rand();
      uVar6 = uVar6 & 0x80000007;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;
      }
      *(float *)(param_1 + 0x390) = (float)(int)(uVar6 + 3) * (float)_DAT_10044168 + DAT_1006c2e4;
    }
    func_0x100117b0(param_1,&fStack_3c,&fStack_48,2,4,300,500,iVar7);
    if (*(float *)(param_1 + 0x390) <= DAT_1006c2e4) {
      *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) & 0xffffff7f;
      return;
    }
    *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) | 0x80;
    return;
  }
  monster_fire_deatom(param_1,&fStack_3c,&fStack_48,0x32,600);
  return;
}



/* soldier_attack6_refire @ 1002caf0 status created size 42 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void soldier_attack6_refire(int param_1)

{
  if (DAT_1006c2e4 + (float)_DAT_10044308 < *(float *)(param_1 + 0x390)) {
    *(undefined4 *)(param_1 + 0x360) = 0x20;
  }
  return;
}



/* soldier_fire4 @ 1002cb20 status created size 16 */

void soldier_fire4(undefined4 param_1)

{
  soldier_fire(param_1,3);
  return;
}



/* soldier_fire8 @ 1002cb30 status created size 16 */

void soldier_fire8(undefined4 param_1)

{
  soldier_fire(param_1,7);
  return;
}



/* soldier_attack @ 1002cb80 status existing size 84 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl soldier_attack(int param_1)

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



/* soldier_sight @ 1002cbe0 status created size 175 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void soldier_sight(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = _rand();
  uVar3 = DAT_10061300;
  if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044140) {
    uVar3 = DAT_10061304;
  }
  (*DAT_1006c1d0)(param_1,2,uVar3,0x3f800000,0x3f800000,0);
  if (((_DAT_1004410c < *(float *)(DAT_1006c41c + 0x14)) &&
      (iVar2 = range(param_1,*(int *)(param_1 + 0x25c)), 1 < iVar2)) &&
     (uVar1 = _rand(), (float)_DAT_10044140 < (float)(uVar1 & 0x7fff) * _DAT_10044108)) {
    *(undefined **)(param_1 + 0x358) = &DAT_1005bbd0;
  }
  return;
}



/* soldier_dodge @ 1002cc90 status created size 214 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void soldier_dodge(int param_1,undefined4 param_2,float param_3)

{
  float fVar1;
  uint uVar2;
  ushort uVar3;
  
  uVar2 = _rand();
  if ((float)_DAT_10044230 < (float)(uVar2 & 0x7fff) * _DAT_10044108) {
    return;
  }
  if (*(int *)(param_1 + 0x25c) == 0) {
    *(undefined4 *)(param_1 + 0x25c) = param_2;
  }
  if (*(float *)(DAT_1006c41c + 0x14) != _DAT_1004410c) {
    *(float *)(param_1 + 0x390) = DAT_1006c2e4 + param_3 + (float)_DAT_10044128;
    uVar2 = _rand();
    fVar1 = (float)(uVar2 & 0x7fff) * _DAT_10044108;
    if (*(int *)(DAT_1006c41c + 0x14) == 0x3f800000) {
      uVar3 = (ushort)(fVar1 < (float)_DAT_10044378) << 8 |
              (ushort)(fVar1 == (float)_DAT_10044378) << 0xe;
    }
    else {
      if (*(float *)(DAT_1006c41c + 0x14) < _DAT_1004413c) goto LAB_1002cd59;
      uVar3 = (ushort)(fVar1 < (float)_DAT_10044370) << 8 |
              (ushort)(fVar1 == (float)_DAT_10044370) << 0xe;
    }
    if (uVar3 != 0) {
LAB_1002cd59:
      *(undefined **)(param_1 + 0x358) = &DAT_1005bac0;
      return;
    }
  }
  *(undefined **)(param_1 + 0x358) = &DAT_1005bc20;
  return;
}



/* soldier_die @ 1002cd90 status created size 344 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int soldier_die(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  if (DAT_1006c104 == 0x23) {
    iVar4 = FUN_1000e460(param_1);
    return iVar4;
  }
  iVar4 = param_1[0x8a];
  if ((int)param_1[0x88] <= iVar4) {
    uVar5 = (*DAT_1006c1e4)(s_misc_udeath_wav_100493f8,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_1,2,uVar5);
    iVar4 = 3;
    do {
      FUN_1000dd30((float)param_1,s_models_objects_gibs_sm_meat_tris_100493d0,param_4,0);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_1000dd30((float)param_1,s_models_objects_gibs_chest_tris_m_1004b55c,param_4,0);
    iVar4 = FUN_1000df70((float)param_1,s_models_objects_gibs_head2_tris_m_100491d4,param_4,0);
    param_1[0x8b] = 2;
    return iVar4;
  }
  if (param_1[0x8b] != 2) {
    uVar1 = param_1[0xf];
    param_1[0x8b] = 2;
    param_1[0x90] = 1;
    param_1[0xf] = uVar1 | 1;
    fVar2 = ABS(((float)(int)param_1[0x8f] + (float)param_1[3]) - *(float *)(param_5 + 8));
    fVar3 = (float)_DAT_100443c0;
    if (fVar2 < fVar3 || (fVar2 == fVar3) != 0) {
      param_1[0xd6] = &DAT_1005c1c8;
      return CONCAT22((short)(uVar1 >> 0x10),
                      (ushort)(fVar2 < fVar3) << 8 | (ushort)(NAN(fVar2) || NAN(fVar3)) << 10 |
                      (ushort)(fVar2 == fVar3) << 0xe);
    }
    iVar6 = _rand();
    iVar4 = iVar6 / 5;
    iVar6 = iVar6 % 5;
    if (iVar6 == 0) {
      param_1[0xd6] = &DAT_1005bde0;
      return iVar4;
    }
    if (iVar6 == 1) {
      param_1[0xd6] = &DAT_1005bf98;
      return iVar4;
    }
    if (iVar6 == 2) {
      param_1[0xd6] = &DAT_1005c458;
      return iVar4;
    }
    if (iVar6 == 3) {
      param_1[0xd6] = &DAT_1005c588;
      return iVar4;
    }
    param_1[0xd6] = &DAT_1005c610;
  }
  return iVar4;
}



/* SP_monster_soldier_x @ 1002cef0 status existing size 632 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_monster_soldier_x(undefined4 *param_1)

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
  param_1[0x81] = soldier_pain;
  param_1[0x82] = soldier_die;
  param_1[0xda] = soldier_stand;
  param_1[0xdd] = soldier_walk;
  param_1[0xde] = soldier_run;
  param_1[0xdf] = soldier_dodge;
  param_1[0xe0] = soldier_attack;
  param_1[0xe1] = 0;
  param_1[0xe2] = soldier_sight;
  (*DAT_1006c208)(param_1);
  (*(code *)param_1[0xda])(param_1);
  walkmonster_start(param_1);
  return;
}



/* SP_monster_soldier_light @ 1002d170 status created size 141 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_monster_soldier_light(undefined4 *param_1)

{
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    G_FreeEdict(param_1);
    return;
  }
  param_1[0xf] = 0;
  param_1[0x88] = 0x14;
  param_1[0x8a] = 0xffffffe2;
  SP_monster_soldier_x(param_1);
  DAT_10061308 = (*DAT_1006c1e4)(s_soldier_solpain2_wav_1005c6bc);
  _DAT_10061324 = (*DAT_1006c1e4)(s_soldier_soldeth2_wav_1005c6a4);
  (*DAT_1006c1e0)(s_models_objects_laser_tris_md2_1004be8c);
  (*DAT_1006c1e4)(s_misc_lasfly_wav_1004be7c);
  (*DAT_1006c1e4)(s_soldier_solatck2_wav_1005c68c);
  return;
}



/* SP_monster_soldier @ 1002d200 status created size 122 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_monster_soldier(undefined4 *param_1)

{
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    G_FreeEdict(param_1);
    return;
  }
  SP_monster_soldier_x(param_1);
  param_1[0x88] = 0x1e;
  param_1[0xf] = param_1[0xf] | 2;
  param_1[0x8a] = 0xffffffe2;
  DAT_1006130c = (*DAT_1006c1e4)(s_soldier_solpain1_wav_1005c704);
  _DAT_10061320 = (*DAT_1006c1e4)(s_soldier_soldeth1_wav_1005c6ec);
  (*DAT_1006c1e4)(s_soldier_solatck1_wav_1005c6d4);
  return;
}



/* SP_monster_soldier_ss @ 1002d280 status created size 122 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_monster_soldier_ss(undefined4 *param_1)

{
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    G_FreeEdict(param_1);
    return;
  }
  SP_monster_soldier_x(param_1);
  param_1[0x88] = 0x28;
  param_1[0xf] = param_1[0xf] | 4;
  param_1[0x8a] = 0xffffffe2;
  DAT_1006131c = (*DAT_1006c1e4)(s_soldier_solpain3_wav_1005c74c);
  _DAT_10061318 = (*DAT_1006c1e4)(s_soldier_soldeth3_wav_1005c734);
  (*DAT_1006c1e4)(s_soldier_solatck3_wav_1005c71c);
  return;
}



/* SP_monster_soldier_deatom @ 1002d300 status created size 122 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_monster_soldier_deatom(undefined4 *param_1)

{
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    G_FreeEdict(param_1);
    return;
  }
  SP_monster_soldier_x(param_1);
  param_1[0x88] = 0x28;
  param_1[0xf] = param_1[0xf] | 6;
  param_1[0x8a] = 0xffffffe2;
  DAT_1006131c = (*DAT_1006c1e4)(s_soldier_solpain3_wav_1005c74c);
  _DAT_10061318 = (*DAT_1006c1e4)(s_soldier_soldeth3_wav_1005c734);
  (*DAT_1006c1e4)(s_soldier_solatck3_wav_1005c71c);
  return;
}



/* spider_idle @ 1002d380 status created size 35 */

void spider_idle(undefined4 param_1)

{
  (*DAT_1006c1d0)(param_1,2,DAT_10061330,0x3f800000,0x40000000,0);
  return;
}



/* spider_sight @ 1002d3b0 status created size 35 */

void spider_sight(undefined4 param_1)

{
  (*DAT_1006c1d0)(param_1,2,DAT_10061338,0x3f800000,0x3f800000,0);
  return;
}



/* spider_search @ 1002d3e0 status created size 35 */

void spider_search(undefined4 param_1)

{
  (*DAT_1006c1d0)(param_1,2,DAT_10061348,0x3f800000,0x3f800000,0);
  return;
}



/* spider_melee_swing @ 1002d410 status created size 35 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void spider_melee_swing(undefined4 param_1)

{
  (*DAT_1006c1d0)(param_1,1,_DAT_10061328,0x3f800000,0x3f800000,0);
  return;
}



/* spider_stand @ 1002d440 status created size 15 */

void spider_stand(int param_1)

{
  *(undefined **)(param_1 + 0x358) = &DAT_1005ca00;
  return;
}



/* spider_walk @ 1002d450 status created size 15 */

void spider_walk(int param_1)

{
  *(undefined **)(param_1 + 0x358) = &DAT_1005ca88;
  return;
}



/* spider_charge_think @ 1002d460 status created size 257 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void spider_charge_think(int param_1,uint param_2)

{
  float *pfVar1;
  int iVar2;
  float10 fVar3;
  longlong lVar4;
  float fStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  float afStack_c [3];
  
  if (0 < *(int *)(param_1 + 0x220)) {
    if (*(int *)(param_2 + 0x240) != 0) {
      pfVar1 = (float *)(param_1 + 0x178);
      fVar3 = VectorLength(pfVar1);
      if ((float10)_DAT_10044380 < fVar3) {
        fStack_18 = *pfVar1;
        uStack_14 = *(undefined4 *)(param_1 + 0x17c);
        uStack_10 = *(undefined4 *)(param_1 + 0x180);
        VectorNormalize(&fStack_18);
        VectorMA((float *)(param_1 + 4),*(float *)(param_1 + 200),&fStack_18,afStack_c);
        _rand();
        lVar4 = __ftol();
        FUN_100060d0(param_2,param_1,param_1,pfVar1,afStack_c,&fStack_18,(int)lVar4,(int)lVar4,0,0);
      }
    }
    iVar2 = M_CheckBottom(param_1);
    if (iVar2 == 0) {
      if (*(int *)(param_1 + 0x268) == 0) {
        return;
      }
      *(undefined4 *)(param_1 + 0x360) = 0x44;
    }
  }
  *(undefined4 *)(param_1 + 0x1fc) = 0;
  return;
}



/* spider_charge_start @ 1002d570 status created size 158 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void spider_charge_start(int param_1)

{
  float fVar1;
  float afStack_c [3];
  
  (*DAT_1006c1d0)(param_1,2,DAT_10061338,0x3f800000,0x3f800000,0);
  AngleVectors((float *)(param_1 + 0x10),afStack_c,(float *)0x0,(float *)0x0);
  *(float *)(param_1 + 0xc) = *(float *)(param_1 + 0xc) + _DAT_10044104;
  VectorScale(afStack_c,500.0,(float *)(param_1 + 0x178));
  *(undefined4 *)(param_1 + 0x180) = 0x437a0000;
  *(undefined4 *)(param_1 + 0x268) = 0;
  *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) | 0x800;
  fVar1 = DAT_1006c2e4 + _DAT_100441b4;
  *(code **)(param_1 + 0x1fc) = spider_charge_think;
  *(float *)(param_1 + 0x394) = fVar1;
  return;
}



/* spider_charge_end @ 1002d610 status created size 72 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void spider_charge_end(int param_1)

{
  if (*(int *)(param_1 + 0x268) != 0) {
    (*DAT_1006c1d0)(param_1,1,_DAT_1006133c,0x3f800000,0x3f800000,0);
    *(undefined4 *)(param_1 + 0x394) = 0;
    *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) & 0xfffff7ff;
  }
  return;
}



/* spider_run @ 1002d660 status existing size 87 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl spider_run(int param_1)

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



/* spider_melee_hit @ 1002d6c0 status created size 133 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void spider_melee_hit(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar2 = 300;
  uStack_c = 0x42a00000;
  uStack_8 = *(undefined4 *)(param_1 + 0xbc);
  uStack_4 = 0xc0800000;
  iVar1 = _rand();
  iVar1 = func_0x1001b5a0(param_1,&uStack_c,iVar1 % 5 + 0x14,uVar2);
  if (iVar1 != 0) {
    (*DAT_1006c1d0)(param_1,0,_DAT_1006132c);
    return;
  }
  (*DAT_1006c1d0)(param_1,0,_DAT_10061334,0x3f800000,0x3f800000,0);
  return;
}



/* spider_melee @ 1002d750 status created size 86 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall spider_melee(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  (*DAT_1006c1c0)(2,s_spider_melee_1005d008,param_1);
  uVar1 = _rand();
  if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044140) {
    *(undefined **)(param_2 + 0x358) = &DAT_1005cbb8;
    return;
  }
  *(undefined **)(param_2 + 0x358) = &DAT_1005cc20;
  return;
}



/* spider_rocket_left @ 1002d7b0 status created size 148 */

void spider_rocket_left(int param_1)

{
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float afStack_18 [3];
  float afStack_c [3];
  
  AngleVectors((float *)(param_1 + 0x10),afStack_c,afStack_18,(float *)0x0);
  FUN_1001aba0((float *)(param_1 + 4),(float *)0x1005237c,afStack_c,afStack_18,&fStack_24);
  fStack_30 = *(float *)(param_1 + 0x160) - fStack_24;
  fStack_2c = *(float *)(param_1 + 0x164) - fStack_20;
  fStack_28 = *(float *)(param_1 + 0x168) - fStack_1c;
  VectorNormalize(&fStack_30);
  func_0x10011990(param_1,&fStack_24,&fStack_30,0x32,500,0x8a);
  return;
}



/* spider_rocket_right @ 1002d850 status created size 148 */

void spider_rocket_right(int param_1)

{
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float afStack_18 [3];
  float afStack_c [3];
  
  AngleVectors((float *)(param_1 + 0x10),afStack_c,afStack_18,(float *)0x0);
  FUN_1001aba0((float *)(param_1 + 4),(float *)0x10052388,afStack_c,afStack_18,&fStack_24);
  fStack_30 = *(float *)(param_1 + 0x160) - fStack_24;
  fStack_2c = *(float *)(param_1 + 0x164) - fStack_20;
  fStack_28 = *(float *)(param_1 + 0x168) - fStack_1c;
  VectorNormalize(&fStack_30);
  func_0x10011990(param_1,&fStack_24,&fStack_30,0x32,500,0x8b);
  return;
}



/* spider_attack @ 1002d8f0 status created size 226 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void spider_attack(int param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  uint uVar4;
  float10 fVar5;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  uVar4 = _rand();
  iVar2 = *(int *)(param_1 + 0x25c);
  fVar3 = (float)(uVar4 & 0x7fff) * _DAT_10044108;
  fStack_c = *(float *)(param_1 + 4) - *(float *)(iVar2 + 4);
  fStack_8 = *(float *)(param_1 + 8) - *(float *)(iVar2 + 8);
  fStack_4 = *(float *)(param_1 + 0xc) - *(float *)(iVar2 + 0xc);
  fVar5 = VectorLength(&fStack_c);
  if ((float10)_DAT_10044384 < fVar5) {
    iVar2 = *(int *)(param_1 + 0x25c);
    *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)(iVar2 + 4);
    *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(iVar2 + 8);
    fVar1 = *(float *)(iVar2 + 0xc);
    *(float *)(param_1 + 0x168) = fVar1;
    *(float *)(param_1 + 0x168) = (float)*(int *)(iVar2 + 0x23c) + fVar1;
    if (fVar3 < (float)_DAT_10044378) {
      *(undefined **)(param_1 + 0x358) = &DAT_1005cc70;
      return;
    }
    if (fVar3 < (float)_DAT_10044370) {
      *(undefined **)(param_1 + 0x358) = &DAT_1005ccc0;
      return;
    }
    *(undefined **)(param_1 + 0x358) = &DAT_1005cd30;
  }
  return;
}



/* spider_pain @ 1002d9e0 status created size 395 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void spider_pain(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x220) < *(int *)(param_1 + 0x224) / 2) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  *(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4;
  uVar1 = _rand();
  uVar2 = DAT_10061344;
  if ((float)_DAT_10044140 <= (float)(uVar1 & 0x7fff) * _DAT_10044108) {
    uVar2 = DAT_10061340;
  }
  if (*(int *)(DAT_1006c41c + 0x14) == 0x40400000) {
    uVar1 = _rand();
    if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044168) goto LAB_1002da79;
  }
  if (param_4 < 10) {
    uVar1 = _rand();
    if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044198) {
LAB_1002da79:
      (*DAT_1006c1d0)(param_1,2,uVar2,0x3f800000,0x3f800000,0);
      *(undefined **)(param_1 + 0x358) = &DAT_1005cd88;
      return;
    }
  }
  if (param_4 < 0x32) {
    uVar1 = _rand();
    if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044140) {
      (*DAT_1006c1d0)(param_1,2,uVar2,0x3f800000,0x3f800000,0);
      uVar1 = _rand();
      if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044140) {
        *(undefined **)(param_1 + 0x358) = &DAT_1005cd88;
        return;
      }
      goto LAB_1002db5d;
    }
  }
  (*DAT_1006c1d0)(param_1,2,uVar2,0x3f800000,0x3f800000,0);
LAB_1002db5d:
  *(undefined **)(param_1 + 0x358) = &DAT_1005cdf8;
  return;
}



/* spider_dead @ 1002db70 status created size 96 */

void spider_dead(int param_1)

{
  *(undefined4 *)(param_1 + 0xbc) = 0xc2000000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc2000000;
  *(undefined4 *)(param_1 + 200) = 0x42000000;
  *(undefined4 *)(param_1 + 0xcc) = 0x42000000;
  *(undefined4 *)(param_1 + 0xc4) = 0xc1f00000;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0x104) = 7;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 2;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  (*DAT_1006c208)(param_1);
  return;
}



/* spider_die @ 1002dbd0 status created size 280 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void spider_die(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (DAT_1006c104 == 0x23) {
    FUN_1000e460(param_1);
    return;
  }
  if ((int)param_1[0x88] <= (int)param_1[0x8a]) {
    uVar1 = (*DAT_1006c1e4)(s_misc_udeath_wav_100493f8,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_1,2,uVar1);
    iVar3 = 2;
    do {
      FUN_1000dd30((float)param_1,s_models_objects_gibs_sm_meat_tris_100493d0,param_4,0);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar3 = 4;
    do {
      FUN_1000dd30((float)param_1,s_models_objects_gibs_sm_metal_tri_1004fc88,param_4,1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    FUN_1000dd30((float)param_1,s_models_objects_gibs_chest_tris_m_1004b55c,param_4,0);
    FUN_1000df70((float)param_1,s_models_objects_gibs_head2_tris_m_100491d4,param_4,0);
    param_1[0x8b] = 2;
    return;
  }
  if (param_1[0x8b] != 2) {
    param_1[0x8b] = 2;
    param_1[0x90] = 1;
    uVar2 = _rand();
    if ((float)(uVar2 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044140) {
      param_1[0xd6] = &DAT_1005cef8;
      return;
    }
    param_1[0xd6] = &DAT_1005cff8;
  }
  return;
}



/* SP_monster_spider @ 1002dcf0 status created size 588 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_monster_spider(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    G_FreeEdict(param_1);
    return;
  }
  _DAT_10061328 = (*DAT_1006c1e4)(s_gladiator_melee1_wav_100550ec);
  _DAT_1006132c = (*DAT_1006c1e4)(s_gladiator_melee2_wav_100550d4);
  _DAT_10061334 = (*DAT_1006c1e4)(s_gladiator_melee3_wav_100550bc);
  _DAT_1006133c = (*DAT_1006c1e4)(s_mutant_thud1_wav_1005a678);
  DAT_10061338 = (*DAT_1006c1e4)(s_mutant_mutsght1_wav_1005a6dc);
  DAT_10061344 = (*DAT_1006c1e4)(s_gladiator_pain_wav_1005514c);
  DAT_10061340 = (*DAT_1006c1e4)(s_gladiator_gldpain2_wav_10055134);
  DAT_10061330 = (*DAT_1006c1e4)(s_gladiator_gldidle1_wav_100550a4);
  DAT_10061348 = (*DAT_1006c1e4)(s_gladiator_gldsrch1_wav_1005508c);
  DAT_10061338 = (*DAT_1006c1e4)(s_spider_sight_wav_1005d038);
  uVar1 = (*DAT_1006c1e0)(s_models_monsters_spider_tris_md2_1005d018);
  param_1[0x88] = 400;
  param_1[100] = 400;
  param_1[10] = uVar1;
  param_1[0x2f] = 0xc2000000;
  param_1[0x30] = 0xc2000000;
  param_1[0x31] = 0xc20c0000;
  param_1[0x32] = 0x42000000;
  param_1[0x33] = 0x42000000;
  param_1[0x34] = 0x42000000;
  param_1[0x41] = 5;
  param_1[0x3e] = 2;
  param_1[0x8a] = 0xffffff51;
  if ((*(byte *)(param_1 + 0x47) & 8) != 0) {
    param_1[0x32] = 0x42000000;
    param_1[0x33] = 0x42000000;
    param_1[0xf] = param_1[0xf] | 1;
    param_1[0x88] = 0xffffffff;
    param_1[0x2f] = 0xc2000000;
    param_1[0x30] = 0xc2000000;
    param_1[0x31] = 0xc1f00000;
    param_1[0x34] = 0;
    param_1[0x41] = 7;
    param_1[0x2e] = param_1[0x2e] | 2;
    param_1[0x7b] = 0;
    (*DAT_1006c208)(param_1);
    return;
  }
  param_1[0x81] = spider_pain;
  param_1[0x82] = spider_die;
  param_1[0xda] = spider_stand;
  param_1[0xdd] = spider_walk;
  param_1[0xde] = spider_run;
  param_1[0xdf] = 0;
  param_1[0xe0] = spider_attack;
  param_1[0xe1] = spider_melee;
  param_1[0xe2] = spider_sight;
  param_1[0xdb] = spider_idle;
  param_1[0xdc] = spider_search;
  (*DAT_1006c208)(param_1);
  param_1[0xd6] = &DAT_1005ca00;
  param_1[0xd9] = 0x3f800000;
  param_1[0xe3] = spider_checkattack;
  walkmonster_start(param_1);
  return;
}



/* spider_checkattack @ 10021460 status created size 557 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 spider_checkattack(float param_1)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  float10 fVar8;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  float fStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  undefined4 auStack_38 [13];
  int iStack_4;
  
  iVar2 = (int)param_1;
  iVar4 = *(int *)((int)param_1 + 0x25c);
  if (0 < *(int *)(iVar4 + 0x220)) {
    uStack_50 = *(undefined4 *)((int)param_1 + 4);
    uStack_4c = *(undefined4 *)((int)param_1 + 8);
    fStack_48 = (float)*(int *)((int)param_1 + 0x23c) + *(float *)((int)param_1 + 0xc);
    uStack_5c = *(undefined4 *)(iVar4 + 4);
    uStack_58 = *(undefined4 *)(iVar4 + 8);
    fStack_54 = (float)*(int *)(iVar4 + 0x23c) + *(float *)(iVar4 + 0xc);
    puVar3 = (undefined4 *)(*DAT_1006c1f0)(auStack_38,&uStack_50,0,0,&uStack_5c,param_1,0x2000019);
    iVar4 = *(int *)((int)param_1 + 0x25c);
    puVar7 = auStack_38;
    for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar7 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar7 = puVar7 + 1;
    }
    if (iStack_4 != iVar4) {
      return 0;
    }
  }
  infront((int)param_1,iVar4);
  iVar6 = range((int)param_1,*(int *)((int)param_1 + 0x25c));
  iVar4 = *(int *)((int)param_1 + 0x25c);
  fStack_44 = *(float *)(iVar4 + 4) - *(float *)((int)param_1 + 4);
  fStack_40 = *(float *)(iVar4 + 8) - *(float *)((int)param_1 + 8);
  fStack_3c = *(float *)(iVar4 + 0xc) - *(float *)((int)param_1 + 0xc);
  fVar8 = vectoyaw(&fStack_44);
  *(float *)((int)param_1 + 0x1e8) = (float)fVar8;
  if (iVar6 == 0) {
    if (*(int *)((int)param_1 + 900) == 0) {
      *(undefined4 *)((int)param_1 + 0x3b8) = 4;
      return 1;
    }
    *(undefined4 *)((int)param_1 + 0x3b8) = 3;
    return 1;
  }
  if (((*(int *)((int)param_1 + 0x380) != 0) && (*(float *)((int)param_1 + 0x394) <= DAT_1006c2e4))
     && (iVar6 != 3)) {
    if ((*(byte *)((int)param_1 + 0x35c) & 1) == 0) {
      if ((iVar6 != 1) && (iVar6 != 2)) {
        return 0;
      }
      param_1 = 0.8;
    }
    else {
      param_1 = 0.4;
    }
    uVar5 = _rand();
    if ((float)(uVar5 & 0x7fff) * _DAT_10044108 < param_1) {
      *(undefined4 *)(iVar2 + 0x3b8) = 4;
      uVar5 = _rand();
      fVar1 = (float)(uVar5 & 0x7fff) * _DAT_10044108;
      *(float *)(iVar2 + 0x394) = fVar1 + fVar1 + DAT_1006c2e4;
      return 1;
    }
    if ((*(byte *)(iVar2 + 0x108) & 1) != 0) {
      uVar5 = _rand();
      if ((float)(uVar5 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044128) {
        *(undefined4 *)(iVar2 + 0x3b8) = 2;
        return 0;
      }
      *(undefined4 *)(iVar2 + 0x3b8) = 1;
    }
  }
  return 0;
}



/* visible @ 10001560 status existing size 151 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl visible(int param_1,int param_2)

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



/* infront @ 10001600 status existing size 132 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl infront(int param_1,int param_2)

{
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  AngleVectors((float *)(param_1 + 0x10),&local_c,(float *)0x0,(float *)0x0);
  local_18 = *(float *)(param_2 + 4) - *(float *)(param_1 + 4);
  local_14 = *(float *)(param_2 + 8) - *(float *)(param_1 + 8);
  local_10 = *(float *)(param_2 + 0xc) - *(float *)(param_1 + 0xc);
  VectorNormalize(&local_18);
  if ((float)_DAT_10044128 < local_c * local_18 + local_8 * local_14 + local_4 * local_10) {
    return 1;
  }
  return 0;
}



/* Actor_EngageEnemy @ 10001690 status existing size 155 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Actor_EngageEnemy(int param_1)

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
  fVar3 = vectoyaw(&fStack_c);
  *(float *)(param_1 + 0x1e8) = (float)fVar3;
  if ((*(byte *)(param_1 + 0x35c) & 1) == 0) {
    uVar2 = _rand();
    AttackFinished(param_1,(float)(uVar2 & 0x7fff) * _DAT_10044108);
  }
  return;
}



/* Actor_FindEnemyTarget @ 10001730 status existing size 323 */

undefined4 __cdecl Actor_FindEnemyTarget(int param_1)

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
          (iVar1 = visible(param_1,uVar4), iVar2 = DAT_1006c168, iVar1 != 0)))) {
        local_c = *(float *)(uVar4 + 4) - *(float *)(param_1 + 4);
        local_8 = *(float *)(uVar4 + 8) - *(float *)(param_1 + 8);
        local_4 = *(float *)(uVar4 + 0xc) - *(float *)(param_1 + 0xc);
        fVar5 = VectorLength(&local_c);
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
      fVar5 = vectoyaw(&local_c);
      *(float *)(param_1 + 0x1e8) = (float)fVar5;
      M_ChangeYaw(param_1);
      *(uint *)(param_1 + 0x25c) = uVar3;
      Actor_EngageEnemy(param_1);
      return 1;
    }
  }
  return 0;
}



/* Actor_IsPlayerFollowTarget @ 10001880 status existing size 137 */

undefined4 __cdecl Actor_IsPlayerFollowTarget(int param_1)

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



/* Actor_FindFollowTarget @ 10001910 status existing size 418 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl Actor_FindFollowTarget(int param_1)

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
      (iVar1 = Actor_IsPlayerFollowTarget(*(int *)(param_1 + 0x1dc)), iVar1 != 0)) &&
     (uVar3 = *(uint *)(param_1 + 0x1dc), uVar3 != 0)) {
LAB_10001a12:
    local_c = *(float *)(uVar3 + 4) - *(float *)(param_1 + 4);
    local_8 = *(float *)(uVar3 + 8) - *(float *)(param_1 + 8);
    local_4 = *(float *)(uVar3 + 0xc) - *(float *)(param_1 + 0xc);
    fVar5 = vectoyaw(&local_c);
    *(float *)(param_1 + 0x1e8) = (float)fVar5;
    M_ChangeYaw(param_1);
    *(uint *)(param_1 + 0x1e0) = uVar3;
    *(uint *)(param_1 + 0x1dc) = uVar3;
    *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) | 0x8000000;
    fVar5 = VectorLength(&local_c);
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
         (iVar2 = visible(param_1,uVar4), iVar1 = DAT_1006c168, iVar2 != 0)) {
        local_c = *(float *)(uVar4 + 4) - *(float *)(param_1 + 4);
        local_8 = *(float *)(uVar4 + 8) - *(float *)(param_1 + 8);
        local_4 = *(float *)(uVar4 + 0xc) - *(float *)(param_1 + 0xc);
        fVar5 = VectorLength(&local_c);
        iVar1 = DAT_1006c168;
        if ((fVar5 < (float10)local_10) &&
           (iVar2 = Actor_IsPlayerFollowTarget(uVar4), iVar1 = DAT_1006c168, iVar2 != 0)) {
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



/* actor_stand @ 1001eeb0 status existing size 67 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl actor_stand(int param_1)

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



/* actor_walk @ 1001ef00 status existing size 15 */

void __cdecl actor_walk(int param_1)

{
  *(undefined **)(param_1 + 0x358) = &DAT_1004c3b0;
  return;
}



/* actor_run @ 1001ef10 status existing size 83 */

void __cdecl actor_run(int param_1)

{
  if ((*(float *)(param_1 + 0x210) <= DAT_1006c2e4) || (*(int *)(param_1 + 0x25c) != 0)) {
    if ((*(byte *)(param_1 + 0x35c) & 1) == 0) {
      *(undefined **)(param_1 + 0x358) = &DAT_1004c408;
      return;
    }
  }
  else if (*(int *)(param_1 + 0x1e0) != 0) {
    actor_walk(param_1);
    return;
  }
  actor_stand(param_1);
  return;
}



/* actor_pain @ 1001ef70 status created size 373 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint actor_pain(int param_1,int param_2)

{
  float fVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  float10 fVar5;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  fVar1 = *(float *)(param_1 + 0x210);
  uVar3 = (uint)(ushort)((ushort)(DAT_1006c2e4 < fVar1) << 8 |
                         (ushort)(NAN(DAT_1006c2e4) || NAN(fVar1)) << 10 |
                        (ushort)(DAT_1006c2e4 == fVar1) << 0xe);
  if (DAT_1006c2e4 >= fVar1) {
    *(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_100441b4;
    if (*(int *)(param_2 + 0x54) != 0) {
      uVar3 = _rand();
      if ((float)(uVar3 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044308) {
        fStack_c = *(float *)(param_2 + 4) - *(float *)(param_1 + 4);
        fStack_8 = *(float *)(param_2 + 8) - *(float *)(param_1 + 8);
        fStack_4 = *(float *)(param_2 + 0xc) - *(float *)(param_1 + 0xc);
        fVar5 = vectoyaw(&fStack_c);
        *(float *)(param_1 + 0x1e8) = (float)fVar5;
        uVar3 = _rand();
        if ((float)_DAT_10044140 <= (float)(uVar3 & 0x7fff) * _DAT_10044108) {
          *(undefined **)(param_1 + 0x358) = &DAT_1004c648;
        }
        else {
          *(undefined **)(param_1 + 0x358) = &DAT_1004c568;
        }
        uVar3 = (param_1 - DAT_1006c2c4) / 0x3d0 & 0x80000007;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
        }
        puVar2 = (&PTR_s_Hellrot_1004c158)[uVar3];
        iVar4 = _rand();
        uVar3 = (*DAT_1006c1c8)(param_2,3,s__s___s__1004c874,puVar2,
                                (&PTR_s_Watch_it_1004c658)[iVar4 % 3]);
        return uVar3;
      }
    }
    iVar4 = _rand();
    uVar3 = iVar4 / 3;
    if (iVar4 % 3 == 0) {
      *(undefined **)(param_1 + 0x358) = &DAT_1004c448;
      return uVar3;
    }
    if (iVar4 % 3 == 1) {
      *(undefined **)(param_1 + 0x358) = &DAT_1004c488;
      return uVar3;
    }
    *(undefined **)(param_1 + 0x358) = &DAT_1004c4c8;
  }
  return uVar3;
}



/* actorMachineGun @ 1001f0f0 status created size 291 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void actorMachineGun(int param_1)

{
  int iVar1;
  float fVar2;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float afStack_c [3];
  
  AngleVectors((float *)(param_1 + 0x10),&fStack_24,afStack_c,(float *)0x0);
  FUN_1001aba0((float *)(param_1 + 4),(float *)0x10051ff8,&fStack_24,afStack_c,&fStack_18);
  iVar1 = *(int *)(param_1 + 0x25c);
  if (iVar1 == 0) {
    AngleVectors((float *)(param_1 + 0x10),&fStack_24,(float *)0x0,(float *)0x0);
  }
  else {
    if (*(int *)(iVar1 + 0x220) < 1) {
      fStack_30 = *(float *)(iVar1 + 0xd4);
      fStack_2c = *(float *)(iVar1 + 0xd8);
      fStack_28 = *(float *)(iVar1 + 0xdc);
      fVar2 = *(float *)(iVar1 + 0xf4) * _DAT_10044158;
    }
    else {
      VectorMA((float *)(iVar1 + 4),-0.2,(float *)(iVar1 + 0x178),&fStack_30);
      fVar2 = (float)*(int *)(*(int *)(param_1 + 0x25c) + 0x23c);
    }
    fStack_28 = fVar2 + fStack_28;
    fStack_24 = fStack_30 - fStack_18;
    fStack_20 = fStack_2c - fStack_14;
    fStack_1c = fStack_28 - fStack_10;
    VectorNormalize(&fStack_24);
  }
  func_0x100117b0(param_1,&fStack_18,&fStack_24,3,4,300,500,0x3f);
  return;
}



/* actor_die @ 1001f220 status created size 220 */

int actor_die(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if (DAT_1006c104 == 0x23) {
    iVar1 = FUN_1000e460(param_1);
    return iVar1;
  }
  if ((int)param_1[0x88] < -0x4f) {
    iVar1 = 2;
    do {
      FUN_1000dd30((float)param_1,s_models_objects_gibs_bone_tris_md_1004b5a4,param_4,0);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    iVar1 = 4;
    do {
      FUN_1000dd30((float)param_1,s_models_objects_gibs_sm_meat_tris_100493d0,param_4,0);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    iVar1 = FUN_1000df70((float)param_1,s_models_objects_gibs_head2_tris_m_100491d4,param_4,0);
    param_1[0x8b] = 2;
    return iVar1;
  }
  iVar1 = DAT_1006c104;
  if (param_1[0x8b] != 2) {
    param_1[0x8b] = 2;
    param_1[0x90] = 1;
    param_1[0xb] = 0;
    iVar2 = _rand();
    iVar1 = iVar2 / 3;
    if (iVar2 % 3 == 0) {
      param_1[0xd6] = &DAT_1004c6b0;
      return iVar1;
    }
    if (iVar2 % 3 == 1) {
      param_1[0xd6] = &DAT_1004c708;
      return iVar1;
    }
    param_1[0xd6] = &DAT_1004c778;
  }
  return iVar1;
}



/* actor_fire @ 1001f300 status created size 59 */

void actor_fire(int param_1)

{
  actorMachineGun(param_1);
  if (*(float *)(param_1 + 0x390) <= DAT_1006c2e4) {
    *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) & 0xffffff7f;
    return;
  }
  *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) | 0x80;
  return;
}



/* actor_attack @ 1001f340 status existing size 54 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl actor_attack(int param_1)

{
  uint uVar1;
  
  *(undefined **)(param_1 + 0x358) = &DAT_1004c7e8;
  uVar1 = _rand();
  *(float *)(param_1 + 0x390) = (float)((uVar1 & 0xf) + 10) * (float)_DAT_10044168 + DAT_1006c2e4;
  return;
}



/* actor_use @ 1001f380 status existing size 215 */

void __cdecl actor_use(int param_1)

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
  
  uVar2 = G_PickTarget(*(byte **)(param_1 + 0x128));
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
      fVar7 = vectoyaw(&local_c);
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



/* SP_misc_actor @ 1001f460 status created size 558 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_misc_actor(undefined4 *param_1)

{
  int iVar1;
  
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    G_FreeEdict(param_1);
    return;
  }
  if (param_1[0x4b] == 0) {
    param_1[0x4b] = s_Yo_Mama_1004c880;
    param_1[0x47] = param_1[0x47] | 0x20;
  }
  param_1[10] = 0xff;
  param_1[0xb] = 0xff;
  param_1[0x41] = 5;
  param_1[0x3e] = 2;
  param_1[0x2f] = 0xc1800000;
  param_1[0x30] = 0xc1800000;
  param_1[0x31] = 0xc1c00000;
  param_1[0x32] = 0x41800000;
  param_1[0x33] = 0x41800000;
  param_1[0x34] = 0x42000000;
  if (param_1[0x88] == 0) {
    param_1[0x88] = 100;
  }
  param_1[100] = 200;
  if ((param_1[0x47] & 8) != 0) {
    iVar1 = _rand();
    iVar1 = iVar1 % 3;
    if (iVar1 == 0) {
      param_1[0xe] = 0xb7;
    }
    else if (iVar1 == 1) {
      param_1[0xe] = 0xbd;
    }
    else if (iVar1 == 2) {
      param_1[0xe] = 0xc5;
    }
    param_1[0x88] = 0xffffffff;
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
  param_1[0x81] = actor_pain;
  param_1[0x82] = actor_die;
  param_1[0x80] = actor_use;
  param_1[0xda] = actor_stand;
  param_1[0xdd] = actor_walk;
  param_1[0xde] = actor_run;
  param_1[0xe0] = actor_attack;
  param_1[0xe1] = 0;
  param_1[0xe2] = 0;
  if (param_1[0x4a] == 0) {
    param_1[0xd7] = param_1[0xd7] | 0x2000000;
  }
  if ((param_1[0x47] & 0x40) == 0) {
    param_1[0xd7] = param_1[0xd7] | 0x1000000;
  }
  param_1[0xd7] = param_1[0xd7] | 0x100;
  (*DAT_1006c208)(param_1);
  param_1[0xd6] = &DAT_1004c358;
  param_1[0xd9] = 0x3f800000;
  walkmonster_start(param_1);
  if ((*(byte *)(param_1 + 0x47) & 0x20) != 0) {
    (*(code *)param_1[0x80])(param_1,DAT_1006c2c4,DAT_1006c2c4);
  }
  return;
}



/* target_actor_touch @ 1001f690 status created size 667 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void target_actor_touch(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar1 = param_2;
  if ((*(uint *)(param_2 + 0x1e0) == param_1) && (*(int *)(param_2 + 0x25c) == 0)) {
    *(undefined4 *)(param_2 + 0x1e0) = 0;
    *(undefined4 *)(param_2 + 0x1dc) = 0;
    if ((*(int *)(param_1 + 0x114) != 0) && (param_2 = 1, 0 < DAT_1006ca48)) {
      iVar5 = 0x3d0;
      iVar2 = DAT_1006c2c4;
      do {
        if (*(int *)(iVar5 + 0x58 + iVar2) != 0) {
          uVar4 = (iVar1 - iVar2) / 0x3d0 & 0x80000007;
          if ((int)uVar4 < 0) {
            uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
          }
          (*DAT_1006c1c8)(iVar5 + iVar2,3,s__s___s_1004c8a0,(&PTR_s_Hellrot_1004c158)[uVar4],
                          *(undefined4 *)(param_1 + 0x114));
          iVar2 = DAT_1006c2c4;
        }
        param_2 = param_2 + 1;
        iVar5 = iVar5 + 0x3d0;
      } while (param_2 <= DAT_1006ca48);
    }
    if ((*(byte *)(param_1 + 0x11c) & 1) != 0) {
      *(float *)(iVar1 + 0x178) = *(float *)(param_1 + 0x154) * *(float *)(param_1 + 0x148);
      *(float *)(iVar1 + 0x17c) = *(float *)(param_1 + 0x158) * *(float *)(param_1 + 0x148);
      if (*(int *)(iVar1 + 0x268) != 0) {
        *(undefined4 *)(iVar1 + 0x268) = 0;
        *(undefined4 *)(iVar1 + 0x180) = *(undefined4 *)(param_1 + 0x15c);
        uVar3 = (*DAT_1006c1e4)(s_player_male_jump1_wav_1004c888,0x3f800000,0x3f800000,0);
        (*DAT_1006c1d0)(iVar1,2,uVar3);
      }
    }
    if ((*(byte *)(param_1 + 0x11c) & 6) != 0) {
      uVar4 = G_PickTarget(*(byte **)(param_1 + 0x138));
      *(uint *)(iVar1 + 0x25c) = uVar4;
      if (uVar4 != 0) {
        *(uint *)(iVar1 + 0x1dc) = uVar4;
        if ((*(byte *)(param_1 + 0x11c) & 2) != 0) {
          *(uint *)(iVar1 + 0x35c) = *(uint *)(iVar1 + 0x35c) | 0x4000000;
        }
        if ((*(byte *)(param_1 + 0x11c) & 0x20) != 0) {
          *(uint *)(iVar1 + 0x35c) = *(uint *)(iVar1 + 0x35c) | 0x200;
        }
        if ((*(byte *)(param_1 + 0x11c) & 0x12) == 0) {
          actor_run(iVar1);
        }
        else {
          *(uint *)(iVar1 + 0x35c) = *(uint *)(iVar1 + 0x35c) | 1;
          actor_stand(iVar1);
        }
      }
    }
    if (*(int *)(param_1 + 0x138) != 0) {
      uVar3 = *(undefined4 *)(param_1 + 0x128);
      *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x138);
      G_UseTargets(param_1,iVar1);
      *(undefined4 *)(param_1 + 0x128) = uVar3;
    }
    if (*(byte **)(param_1 + 0x128) != (byte *)0x0) {
      uVar4 = G_PickTarget(*(byte **)(param_1 + 0x128));
      *(uint *)(iVar1 + 0x1e0) = uVar4;
    }
    if (*(int *)(iVar1 + 0x1dc) == 0) {
      *(undefined4 *)(iVar1 + 0x1dc) = *(undefined4 *)(iVar1 + 0x1e0);
    }
    iVar2 = *(int *)(iVar1 + 0x1e0);
    if ((iVar2 == 0) && (*(int *)(iVar1 + 0x25c) == 0)) {
      *(float *)(iVar1 + 0x390) = DAT_1006c2e4 + _DAT_10044148;
      (**(code **)(iVar1 + 0x368))(iVar1);
      *(uint *)(iVar1 + 0x35c) = *(uint *)(iVar1 + 0x35c) | 0x2000000;
      return;
    }
    if (iVar2 == *(int *)(iVar1 + 0x1dc)) {
      fStack_c = *(float *)(iVar2 + 4) - *(float *)(iVar1 + 4);
      fStack_8 = *(float *)(iVar2 + 8) - *(float *)(iVar1 + 8);
      fStack_4 = *(float *)(iVar2 + 0xc) - *(float *)(iVar1 + 0xc);
      fVar6 = vectoyaw(&fStack_c);
      *(float *)(iVar1 + 0x1e8) = (float)fVar6;
    }
  }
  return;
}



/* SP_target_actor @ 1001f930 status existing size 202 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SP_target_actor(int param_1)

{
  *(undefined4 *)(param_1 + 0xbc) = 0xc1000000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc1000000;
  *(undefined4 *)(param_1 + 0xc4) = 0xc1000000;
  *(undefined4 *)(param_1 + 200) = 0x41000000;
  *(undefined4 *)(param_1 + 0xcc) = 0x41000000;
  *(undefined4 *)(param_1 + 0xd0) = 0x41000000;
  *(undefined4 *)(param_1 + 0xf8) = 1;
  *(code **)(param_1 + 0x1fc) = target_actor_touch;
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
    G_SetMovedir((float *)(param_1 + 0x10),(float *)(param_1 + 0x154));
    *(float *)(param_1 + 0x15c) = (float)DAT_1006c2a0;
  }
  (*DAT_1006c208)(param_1);
  return;
}



/* badass_sight @ 1001fa00 status existing size 70 */

void __cdecl badass_sight(int param_1)

{
  if (*(undefined **)(param_1 + 0x358) == &DAT_1004cb18) {
    *(undefined **)(param_1 + 0x358) = &DAT_1004c8f0;
  }
  else {
    badass_run(param_1);
  }
  (*DAT_1006c1d0)(param_1,2,DAT_10060ff4,0x3f800000,0x3f800000,0);
  return;
}



/* badass_stand @ 1001fa50 status created size 27 */

void badass_stand(int param_1)

{
  if (*(undefined **)(param_1 + 0x358) != &DAT_1004cb18) {
    *(undefined **)(param_1 + 0x358) = &DAT_1004cdc8;
  }
  return;
}



/* badass_idle @ 1001fa70 status created size 38 */

void badass_idle(int param_1)

{
  if (*(undefined **)(param_1 + 0x358) == &DAT_1004cdc8) {
    *(undefined **)(param_1 + 0x358) = &DAT_1004c9b8;
    return;
  }
  *(undefined **)(param_1 + 0x358) = &DAT_1004cb18;
  return;
}



/* badass_attack @ 1001faa0 status created size 122 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void badass_attack(int param_1)

{
  int iVar1;
  uint uVar2;
  float10 fVar3;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar1 = *(int *)(param_1 + 0x25c);
  fStack_c = *(float *)(param_1 + 4) - *(float *)(iVar1 + 4);
  fStack_8 = *(float *)(param_1 + 8) - *(float *)(iVar1 + 8);
  fStack_4 = *(float *)(param_1 + 0xc) - *(float *)(iVar1 + 0xc);
  fVar3 = VectorLength(&fStack_c);
  if (((float10)_DAT_100441e8 < fVar3) &&
     (uVar2 = _rand(), (float)(uVar2 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044140)) {
    return;
  }
  *(undefined **)(param_1 + 0x358) = &DAT_1004c9f8;
  return;
}



/* badass_attack_loop @ 1001fb20 status created size 152 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void badass_attack_loop(int param_1)

{
  int iVar1;
  uint uVar2;
  float10 fVar3;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar1 = visible(param_1,*(int *)(param_1 + 0x25c));
  if ((iVar1 != 0) && (iVar1 = *(int *)(param_1 + 0x25c), 0 < *(int *)(iVar1 + 0x220))) {
    fStack_c = *(float *)(param_1 + 4) - *(float *)(iVar1 + 4);
    fStack_8 = *(float *)(param_1 + 8) - *(float *)(iVar1 + 8);
    fStack_4 = *(float *)(param_1 + 0xc) - *(float *)(iVar1 + 0xc);
    fVar3 = VectorLength(&fStack_c);
    if (fVar3 < (float10)_DAT_100441e8) {
      return;
    }
    uVar2 = _rand();
    if ((float)(uVar2 & 0x7fff) * _DAT_10044108 <= (float)_DAT_10044310) {
      return;
    }
  }
  *(undefined **)(param_1 + 0x358) = &DAT_1004ccc8;
  return;
}



/* badass_rocket_right @ 1001fbc0 status created size 188 */

void badass_rocket_right(int param_1)

{
  int iVar1;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float afStack_30 [4];
  float fStack_20;
  float fStack_1c;
  float afStack_18 [3];
  float afStack_c [3];
  
  afStack_30[0] = 18.0;
  afStack_30[1] = 40.0;
  afStack_30[2] = 0.0;
  AngleVectors((float *)(param_1 + 0x10),afStack_c,afStack_18,(float *)0x0);
  FUN_1001aba0((float *)(param_1 + 4),afStack_30,afStack_c,afStack_18,&fStack_3c);
  iVar1 = *(int *)(param_1 + 0x25c);
  fStack_20 = *(float *)(iVar1 + 8);
  fStack_1c = (float)*(int *)(iVar1 + 0x23c) + *(float *)(iVar1 + 0xc);
  fStack_48 = *(float *)(iVar1 + 4) - fStack_3c;
  fStack_44 = fStack_20 - fStack_38;
  fStack_40 = fStack_1c - fStack_34;
  VectorNormalize(&fStack_48);
  func_0x10011990(param_1,&fStack_3c,&fStack_48,0x32,0x226,0x17);
  return;
}



/* badass_rocket_left @ 1001fc80 status created size 188 */

void badass_rocket_left(int param_1)

{
  int iVar1;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float afStack_30 [4];
  float fStack_20;
  float fStack_1c;
  float afStack_18 [3];
  float afStack_c [3];
  
  afStack_30[0] = 18.0;
  afStack_30[1] = -40.0;
  afStack_30[2] = 0.0;
  AngleVectors((float *)(param_1 + 0x10),afStack_c,afStack_18,(float *)0x0);
  FUN_1001aba0((float *)(param_1 + 4),afStack_30,afStack_c,afStack_18,&fStack_3c);
  iVar1 = *(int *)(param_1 + 0x25c);
  fStack_20 = *(float *)(iVar1 + 8);
  fStack_1c = (float)*(int *)(iVar1 + 0x23c) + *(float *)(iVar1 + 0xc);
  fStack_48 = *(float *)(iVar1 + 4) - fStack_3c;
  fStack_44 = fStack_20 - fStack_38;
  fStack_40 = fStack_1c - fStack_34;
  VectorNormalize(&fStack_48);
  func_0x10011990(param_1,&fStack_3c,&fStack_48,0x32,0x226,0x17);
  return;
}



/* badass_gib_explosion @ 1001fd40 status existing size 109 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl badass_gib_explosion(float param_1)

{
  float fVar1;
  
  (*DAT_1006c224)(3);
  (*DAT_1006c224)(5);
  (*DAT_1006c238)((int)param_1 + 4);
  (*DAT_1006c218)((int)param_1 + 4,2);
  FUN_10006860(param_1,(uint)param_1,100.0,0,100.0,0x19);
  if (*(code **)((int)param_1 + 500) == badass_gib_explosion) {
    fVar1 = DAT_1006c2e4 + (float)_DAT_10044140;
    *(code **)((int)param_1 + 500) = badass_die_gibs;
    *(float *)((int)param_1 + 0x1ec) = fVar1;
  }
  return;
}



/* badass_die_gibs @ 1001fde0 status created size 1090 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void badass_die_gibs(undefined4 *param_1)

{
  float *pfVar1;
  float *pfVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  float fVar7;
  float *pfVar8;
  float *pfVar9;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float afStack_18 [3];
  float afStack_c [3];
  
  puVar3 = param_1;
  AngleVectors((float *)(param_1 + 4),afStack_c,&fStack_24,afStack_18);
  param_1 = (undefined4 *)0x0;
  pfVar1 = (float *)(puVar3 + 1);
  do {
    piVar4 = G_Spawn();
    piVar4[1] = (int)*pfVar1;
    piVar4[2] = puVar3[2];
    piVar4[3] = puVar3[3];
    piVar4[7] = (int)*pfVar1;
    piVar4[8] = puVar3[2];
    piVar4[9] = puVar3[3];
    piVar4[4] = puVar3[4];
    pfVar2 = (float *)(piVar4 + 0x5e);
    piVar4[5] = puVar3[5];
    piVar4[6] = puVar3[6];
    VectorScale(pfVar2,200.0,pfVar2);
    piVar4[99] = 0;
    piVar4[0x62] = 0;
    piVar4[0x61] = 0;
    piVar4[0x40] = (int)puVar3;
    piVar4[0x41] = 7;
    piVar4[0x3e] = 2;
    piVar4[0x8b] = 2;
    piVar4[0x2e] = piVar4[0x2e] | 2;
    piVar4[0x7d] = (int)&LAB_1001fdb0;
    piVar4[0x7b] = (int)(DAT_1006c2e4 + (float)_DAT_10044168);
    uVar5 = _rand();
    fVar7 = (float)(uVar5 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
    piVar4[0x62] = (int)((fVar7 + fVar7) * (float)_DAT_100441d8);
    switch(param_1) {
    case (undefined4 *)0x0:
      iVar6 = (*DAT_1006c1e0)(s_models_monsters_badass_gib_torso_1004ce68);
      piVar4[10] = iVar6;
      piVar4[0x2f] = -0x3e780000;
      piVar4[0x30] = -0x3e900000;
      piVar4[0x31] = -0x3db80000;
      piVar4[0x32] = 0x42240000;
      piVar4[0x33] = 0x41b00000;
      piVar4[0x34] = -0x3e180000;
      pfVar8 = pfVar2;
      uVar5 = _rand();
      VectorScale(afStack_c,(float)(uVar5 & 0x7fff) * _DAT_10044108 * _DAT_1004431c,pfVar8);
      VectorMA(pfVar2,300.0,afStack_18,pfVar2);
      break;
    case (undefined4 *)0x1:
      iVar6 = (*DAT_1006c1e0)(s_models_monsters_badass_gib_lleg__1004ce44);
      piVar4[10] = iVar6;
      piVar4[0x2f] = -0x3df40000;
      piVar4[0x30] = 0x3f800000;
      piVar4[0x31] = -0x3dc80000;
      piVar4[0x32] = 0x423c0000;
      piVar4[0x33] = 0x42540000;
      piVar4[0x34] = -0x3e500000;
      VectorMA(pfVar2,200.0,afStack_18,pfVar2);
      VectorMA(pfVar2,-200.0,&fStack_24,pfVar2);
      break;
    case (undefined4 *)0x2:
      iVar6 = (*DAT_1006c1e0)(s_models_monsters_badass_gib_rleg__1004ce20);
      piVar4[10] = iVar6;
      piVar4[0x2f] = -0x3df80000;
      piVar4[0x30] = -0x3db40000;
      piVar4[0x31] = -0x3dd00000;
      piVar4[0x32] = 0x42400000;
      piVar4[0x33] = -0x40800000;
      piVar4[0x34] = -0x3e580000;
      VectorMA(pfVar2,200.0,afStack_18,pfVar2);
      VectorMA(pfVar2,200.0,&fStack_24,pfVar2);
      break;
    case (undefined4 *)0x3:
      iVar6 = (*DAT_1006c1e0)(s_models_monsters_badass_gib_larm__1004cdfc);
      piVar4[10] = iVar6;
      piVar4[0x2f] = -0x3e180000;
      piVar4[0x30] = -0x3ec00000;
      piVar4[0x31] = -0x3dfc0000;
      piVar4[0x32] = 0x41f80000;
      piVar4[0x33] = 0x42540000;
      piVar4[0x34] = -0x3ec00000;
      VectorScale(afStack_c,-200.0,pfVar2);
      pfVar8 = afStack_18;
      pfVar9 = pfVar2;
      uVar5 = _rand();
      VectorMA(pfVar2,(float)(uVar5 & 0x7fff) * _DAT_10044108 * _DAT_10044318 + _DAT_10044190,pfVar8
               ,pfVar9);
      fVar7 = -100.0;
      goto LAB_100201b1;
    case (undefined4 *)0x4:
      iVar6 = (*DAT_1006c1e0)(s_models_monsters_badass_gib_rarm__1004cdd8);
      piVar4[10] = iVar6;
      piVar4[0x2f] = -0x3df80000;
      piVar4[0x30] = -0x3db40000;
      piVar4[0x31] = -0x3dd80000;
      piVar4[0x32] = 0x41d00000;
      piVar4[0x33] = -0x3e100000;
      piVar4[0x34] = -0x3e580000;
      VectorScale(afStack_c,-200.0,pfVar2);
      pfVar8 = afStack_18;
      pfVar9 = pfVar2;
      uVar5 = _rand();
      VectorMA(pfVar2,(float)(uVar5 & 0x7fff) * _DAT_10044108 * _DAT_100441c4,pfVar8,pfVar9);
      fVar7 = 50.0;
LAB_100201b1:
      VectorMA(pfVar2,fVar7,&fStack_24,pfVar2);
    }
    (*DAT_1006c208)(piVar4);
    param_1 = (undefined4 *)((int)param_1 + 1);
    if (4 < (int)param_1) {
      *pfVar1 = fStack_24 + *pfVar1;
      puVar3[2] = fStack_20 + (float)puVar3[2];
      puVar3[3] = fStack_1c + (float)puVar3[3];
      badass_gib_explosion((float)puVar3);
      VectorMA(pfVar1,-2.0,&fStack_24,pfVar1);
      badass_gib_explosion((float)puVar3);
      G_FreeEdict(puVar3);
      return;
    }
  } while( true );
}



/* badass_dead @ 10020240 status created size 136 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void badass_dead(int param_1)

{
  float fVar1;
  
  *(undefined4 *)(param_1 + 0x22c) = 2;
  *(undefined4 *)(param_1 + 0xbc) = 0xc2300000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc2780000;
  *(undefined4 *)(param_1 + 0xc4) = 0xc2800000;
  *(undefined4 *)(param_1 + 200) = 0x42300000;
  *(undefined4 *)(param_1 + 0xcc) = 0x42780000;
  *(undefined4 *)(param_1 + 0xd0) = 0xc0a00000;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 2;
  fVar1 = DAT_1006c2e4 + (float)_DAT_10044140;
  *(code **)(param_1 + 500) = badass_gib_explosion;
  *(undefined4 *)(param_1 + 0x254) = 0x7a69;
  *(float *)(param_1 + 0x1ec) = fVar1;
  (*DAT_1006c208)(param_1);
  return;
}



/* badass_die @ 100202d0 status created size 44 */

void badass_die(int param_1)

{
  if (*(int *)(param_1 + 0x22c) != 2) {
    *(undefined4 *)(param_1 + 0x22c) = 2;
    *(undefined4 *)(param_1 + 0x240) = 1;
    *(undefined **)(param_1 + 0x358) = &DAT_1004caf8;
  }
  return;
}



/* badass_step @ 10020300 status created size 35 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void badass_step(undefined4 param_1)

{
  (*DAT_1006c1d0)(param_1,4,_DAT_10060ffc,0x3f800000,0x3f800000,0);
  return;
}



/* badass_thud @ 10020330 status created size 35 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void badass_thud(undefined4 param_1)

{
  (*DAT_1006c1d0)(param_1,4,_DAT_10060ff8,0x3f800000,0x3f800000,0);
  return;
}



/* badass_walk @ 10020360 status created size 15 */

void badass_walk(int param_1)

{
  *(undefined **)(param_1 + 0x358) = &DAT_1004cc58;
  return;
}



/* badass_run @ 10020370 status existing size 15 */

void __cdecl badass_run(int param_1)

{
  *(undefined **)(param_1 + 0x358) = &DAT_1004ccc8;
  return;
}



/* badass_pain @ 10020380 status existing size 164 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl badass_pain(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

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



/* SP_monster_badass @ 10020430 status created size 652 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_monster_badass(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    G_FreeEdict(param_1);
    return;
  }
  uVar1 = (*DAT_1006c1e0)(s_models_monsters_badass_tris_md2_1004cfb0);
  param_1[10] = uVar1;
  param_1[0x2f] = 0xc2500000;
  param_1[0x30] = 0xc2200000;
  param_1[0x31] = 0xc2800000;
  param_1[0x32] = 0x42180000;
  param_1[0x33] = 0x42200000;
  param_1[0x34] = 0x42000000;
  param_1[0x41] = 5;
  param_1[0x3e] = 2;
  param_1[0x79] = 0x41c80000;
  param_1[0x88] = 0x5dc;
  param_1[0x8a] = 0;
  param_1[100] = 1000;
  if ((*(byte *)(param_1 + 0x47) & 8) != 0) {
    param_1[0x31] = 0xc2800000;
    param_1[0xf] = param_1[0xf] | 1;
    param_1[0x88] = 0xffffffff;
    param_1[0x8b] = 2;
    param_1[0x2f] = 0xc1f80000;
    param_1[0x30] = 0xc2b00000;
    param_1[0x32] = 0x42180000;
    param_1[0x33] = 0x41a80000;
    param_1[0x34] = 0xc1500000;
    param_1[0x2e] = param_1[0x2e] | 2;
    param_1[0x7b] = 0;
    (*DAT_1006c208)(param_1);
    return;
  }
  DAT_10060fe8 = (*DAT_1006c1e4)(s_tank_tnkpain2_wav_1004cf9c);
  _DAT_10060ff8 = (*DAT_1006c1e4)(s_tank_tnkdeth2_wav_1004cf88);
  _DAT_10060fec = (*DAT_1006c1e4)(s_tank_tnkidle1_wav_1004cf74);
  _DAT_10060ff0 = (*DAT_1006c1e4)(s_tank_death_wav_1004cf64);
  _DAT_10060ffc = (*DAT_1006c1e4)(s_tank_step_wav_1004cf54);
  _DAT_10061004 = (*DAT_1006c1e4)(s_tank_tnkatck4_wav_1004cf40);
  _DAT_10061000 = (*DAT_1006c1e4)(s_tank_tnkatck5_wav_1004cf2c);
  DAT_10060ff4 = (*DAT_1006c1e4)(s_tank_sight1_wav_1004cf1c);
  (*DAT_1006c1e4)(s_tank_tnkatck1_wav_1004cf08);
  (*DAT_1006c1e4)(s_tank_tnkatk2a_wav_1004cef4);
  (*DAT_1006c1e4)(s_tank_tnkatk2b_wav_1004cee0);
  (*DAT_1006c1e4)(s_tank_tnkatk2c_wav_1004cecc);
  (*DAT_1006c1e4)(s_tank_tnkatk2d_wav_1004ceb8);
  (*DAT_1006c1e4)(s_tank_tnkatk2e_wav_1004cea4);
  (*DAT_1006c1e4)(s_tank_tnkatck3_wav_1004ce90);
  param_1[0x81] = badass_pain;
  param_1[0x82] = badass_die;
  param_1[0xda] = badass_stand;
  param_1[0xdd] = badass_walk;
  param_1[0xde] = badass_run;
  param_1[0xdf] = 0;
  param_1[0xe0] = badass_attack;
  param_1[0xe1] = badass_attack;
  param_1[0xe2] = badass_sight;
  param_1[0xdb] = badass_idle;
  (*DAT_1006c208)(param_1);
  param_1[0xd9] = 0x3f800000;
  walkmonster_start(param_1);
  param_1[0xd6] = &DAT_1004cb18;
  return;
}



/* cyborg_footstep @ 100244f0 status created size 117 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cyborg_footstep(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _rand();
  iVar1 = (iVar1 + 1) % 3;
  if (iVar1 == 0) {
    (*DAT_1006c1d0)(param_1,2,_DAT_10061130,0x3f800000,0x3f800000,0);
    return;
  }
  if (iVar1 == 1) {
    (*DAT_1006c1d0)(param_1,2,_DAT_10061134);
    return;
  }
  (*DAT_1006c1d0)(param_1,2,_DAT_1006112c,0x3f800000,0x3f800000,0);
  return;
}



/* cyborg_sight @ 10024570 status created size 35 */

void cyborg_sight(undefined4 param_1)

{
  (*DAT_1006c1d0)(param_1,2,DAT_10061124,0x3f800000,0x3f800000,0);
  return;
}



/* cyborg_search @ 100245a0 status created size 35 */

void cyborg_search(undefined4 param_1)

{
  (*DAT_1006c1d0)(param_1,2,DAT_10061144,0x3f800000,0x3f800000,0);
  return;
}



/* cyborg_stand @ 100245d0 status created size 15 */

void cyborg_stand(int param_1)

{
  *(undefined **)(param_1 + 0x358) = &DAT_10051540;
  return;
}



/* cyborg_idle @ 100245e0 status created size 46 */

void cyborg_idle(int param_1)

{
  *(undefined **)(param_1 + 0x358) = &DAT_10051560;
  (*DAT_1006c1d0)(param_1,2,DAT_1006111c,0x3f800000,0x40000000,0);
  return;
}



/* cyborg_walk @ 10024610 status created size 15 */

void cyborg_walk(int param_1)

{
  *(undefined **)(param_1 + 0x358) = &DAT_10051648;
  return;
}



/* cyborg_run @ 10024620 status existing size 119 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl cyborg_run(int param_1)

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



/* cyborg_pain @ 100246a0 status existing size 199 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl cyborg_pain(int param_1)

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



/* cyborg_hit_left @ 10024770 status created size 130 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cyborg_hit_left(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar2 = 100;
  uStack_c = 0x42a00000;
  uStack_8 = *(undefined4 *)(param_1 + 0xbc);
  uStack_4 = 0x41000000;
  iVar1 = _rand();
  iVar1 = func_0x1001b5a0(param_1,&uStack_c,iVar1 % 5 + 10,uVar2);
  if (iVar1 != 0) {
    (*DAT_1006c1d0)(param_1,1,_DAT_10061148);
    return;
  }
  (*DAT_1006c1d0)(param_1,1,_DAT_10061120,0x3f800000,0x3f800000,0);
  return;
}



/* cyborg_hit_right @ 10024800 status created size 130 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cyborg_hit_right(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar2 = 100;
  uStack_c = 0x42a00000;
  uStack_8 = *(undefined4 *)(param_1 + 0xbc);
  uStack_4 = 0x41000000;
  iVar1 = _rand();
  iVar1 = func_0x1001b5a0(param_1,&uStack_c,iVar1 % 5 + 10,uVar2);
  if (iVar1 != 0) {
    (*DAT_1006c1d0)(param_1,1,_DAT_10061148);
    return;
  }
  (*DAT_1006c1d0)(param_1,1,_DAT_10061120,0x3f800000,0x3f800000,0);
  return;
}



/* cyborg_hit_alt @ 10024890 status created size 130 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cyborg_hit_alt(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar2 = 100;
  uStack_c = 0x42a00000;
  uStack_8 = *(undefined4 *)(param_1 + 200);
  uStack_4 = 0x41000000;
  iVar1 = _rand();
  iVar1 = func_0x1001b5a0(param_1,&uStack_c,iVar1 % 5 + 10,uVar2);
  if (iVar1 != 0) {
    (*DAT_1006c1d0)(param_1,1,_DAT_10061118);
    return;
  }
  (*DAT_1006c1d0)(param_1,1,_DAT_10061120,0x3f800000,0x3f800000,0);
  return;
}



/* cyborg_touch @ 10024920 status created size 257 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cyborg_touch(int param_1,uint param_2)

{
  float *pfVar1;
  int iVar2;
  float10 fVar3;
  longlong lVar4;
  float fStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  float afStack_c [3];
  
  if (0 < *(int *)(param_1 + 0x220)) {
    if (*(int *)(param_2 + 0x240) != 0) {
      pfVar1 = (float *)(param_1 + 0x178);
      fVar3 = VectorLength(pfVar1);
      if ((float10)_DAT_10044380 < fVar3) {
        fStack_18 = *pfVar1;
        uStack_14 = *(undefined4 *)(param_1 + 0x17c);
        uStack_10 = *(undefined4 *)(param_1 + 0x180);
        VectorNormalize(&fStack_18);
        VectorMA((float *)(param_1 + 4),*(float *)(param_1 + 200),&fStack_18,afStack_c);
        _rand();
        lVar4 = __ftol();
        FUN_100060d0(param_2,param_1,param_1,pfVar1,afStack_c,&fStack_18,(int)lVar4,(int)lVar4,0,0);
      }
    }
    iVar2 = M_CheckBottom(param_1);
    if (iVar2 == 0) {
      if (*(int *)(param_1 + 0x268) == 0) {
        return;
      }
      *(undefined4 *)(param_1 + 0x360) = 0x29;
    }
  }
  *(undefined4 *)(param_1 + 0x1fc) = 0;
  return;
}



/* cyborg_attack_start @ 10024a30 status created size 158 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cyborg_attack_start(int param_1)

{
  float fVar1;
  float afStack_c [3];
  
  (*DAT_1006c1d0)(param_1,2,DAT_10061124,0x3f800000,0x3f800000,0);
  AngleVectors((float *)(param_1 + 0x10),afStack_c,(float *)0x0,(float *)0x0);
  *(float *)(param_1 + 0xc) = *(float *)(param_1 + 0xc) + _DAT_10044104;
  VectorScale(afStack_c,-100.0,(float *)(param_1 + 0x178));
  *(undefined4 *)(param_1 + 0x180) = 0x437a0000;
  *(undefined4 *)(param_1 + 0x268) = 0;
  *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) | 0x800;
  fVar1 = DAT_1006c2e4 + _DAT_100441b4;
  *(code **)(param_1 + 0x1fc) = cyborg_touch;
  *(float *)(param_1 + 0x394) = fVar1;
  return;
}



/* cyborg_attack_end @ 10024ad0 status created size 72 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cyborg_attack_end(int param_1)

{
  if (*(int *)(param_1 + 0x268) != 0) {
    (*DAT_1006c1d0)(param_1,1,_DAT_10061128,0x3f800000,0x3f800000,0);
    *(undefined4 *)(param_1 + 0x394) = 0;
    *(uint *)(param_1 + 0x35c) = *(uint *)(param_1 + 0x35c) & 0xfffff7ff;
  }
  return;
}



/* cyborg_fire_right @ 10024b20 status created size 186 */

void cyborg_fire_right(int param_1)

{
  int iVar1;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float afStack_30 [4];
  float fStack_20;
  float fStack_1c;
  float afStack_18 [3];
  float afStack_c [3];
  
  afStack_30[0] = 15.0;
  afStack_30[1] = 12.0;
  afStack_30[2] = 12.0;
  AngleVectors((float *)(param_1 + 0x10),afStack_c,afStack_18,(float *)0x0);
  FUN_1001aba0((float *)(param_1 + 4),afStack_30,afStack_c,afStack_18,&fStack_3c);
  iVar1 = *(int *)(param_1 + 0x25c);
  fStack_20 = *(float *)(iVar1 + 8);
  fStack_1c = (float)*(int *)(iVar1 + 0x23c) + *(float *)(iVar1 + 0xc);
  fStack_48 = *(float *)(iVar1 + 4) - fStack_3c;
  fStack_44 = fStack_20 - fStack_38;
  fStack_40 = fStack_1c - fStack_34;
  VectorNormalize(&fStack_48);
  monster_fire_deatom(param_1,&fStack_3c,&fStack_48,0x32,600);
  return;
}



/* cyborg_fire_left @ 10024be0 status created size 186 */

void cyborg_fire_left(int param_1)

{
  int iVar1;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float afStack_30 [4];
  float fStack_20;
  float fStack_1c;
  float afStack_18 [3];
  float afStack_c [3];
  
  afStack_30[0] = 15.0;
  afStack_30[1] = -12.0;
  afStack_30[2] = 12.0;
  AngleVectors((float *)(param_1 + 0x10),afStack_c,afStack_18,(float *)0x0);
  FUN_1001aba0((float *)(param_1 + 4),afStack_30,afStack_c,afStack_18,&fStack_3c);
  iVar1 = *(int *)(param_1 + 0x25c);
  fStack_20 = *(float *)(iVar1 + 8);
  fStack_1c = (float)*(int *)(iVar1 + 0x23c) + *(float *)(iVar1 + 0xc);
  fStack_48 = *(float *)(iVar1 + 4) - fStack_3c;
  fStack_44 = fStack_20 - fStack_38;
  fStack_40 = fStack_1c - fStack_34;
  VectorNormalize(&fStack_48);
  monster_fire_deatom(param_1,&fStack_3c,&fStack_48,0x32,600);
  return;
}



/* cyborg_fire_both @ 10024ca0 status created size 343 */

void cyborg_fire_both(int param_1)

{
  int iVar1;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_38;
  float fStack_34;
  float afStack_30 [9];
  float afStack_c [3];
  
  afStack_30[0] = 15.0;
  afStack_30[1] = -12.0;
  afStack_30[2] = 12.0;
  afStack_30[3] = 15.0;
  afStack_30[4] = 12.0;
  afStack_30[5] = 12.0;
  AngleVectors((float *)(param_1 + 0x10),afStack_c,afStack_30 + 6,(float *)0x0);
  FUN_1001aba0((float *)(param_1 + 4),afStack_30,afStack_c,afStack_30 + 6,&fStack_48);
  iVar1 = *(int *)(param_1 + 0x25c);
  fStack_38 = *(float *)(iVar1 + 8);
  fStack_34 = (float)*(int *)(iVar1 + 0x23c) + *(float *)(iVar1 + 0xc);
  fStack_54 = *(float *)(iVar1 + 4) - fStack_48;
  fStack_50 = fStack_38 - fStack_44;
  fStack_4c = fStack_34 - fStack_40;
  VectorNormalize(&fStack_54);
  monster_fire_deatom(param_1,&fStack_48,&fStack_54,0x32,600);
  FUN_1001aba0((float *)(param_1 + 4),afStack_30 + 3,afStack_c,afStack_30 + 6,&fStack_48);
  iVar1 = *(int *)(param_1 + 0x25c);
  fStack_38 = *(float *)(iVar1 + 8);
  fStack_34 = (float)*(int *)(iVar1 + 0x23c) + *(float *)(iVar1 + 0xc);
  fStack_54 = *(float *)(iVar1 + 4) - fStack_48;
  fStack_50 = fStack_38 - fStack_44;
  fStack_4c = fStack_34 - fStack_40;
  VectorNormalize(&fStack_54);
  monster_fire_deatom(param_1,&fStack_48,&fStack_54,0x32,600);
  return;
}



/* cyborg_attack @ 10024e00 status created size 101 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cyborg_attack(int param_1)

{
  float fVar1;
  uint uVar2;
  
  uVar2 = _rand();
  fVar1 = (float)(uVar2 & 0x7fff) * _DAT_10044108;
  if (fVar1 < (float)_DAT_10044140) {
    *(undefined **)(param_1 + 0x358) = &DAT_10051958;
    return;
  }
  if (fVar1 < (float)_DAT_10044228) {
    *(undefined **)(param_1 + 0x358) = &DAT_10051aa0;
    return;
  }
  *(undefined **)(param_1 + 0x358) = &DAT_10051a48;
  return;
}



/* cyborg_melee @ 10024e70 status created size 123 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cyborg_melee(int param_1)

{
  uint uVar1;
  
  uVar1 = _rand();
  if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044128) {
    *(undefined **)(param_1 + 0x358) = &DAT_10051860;
    return;
  }
  uVar1 = _rand();
  if ((float)(uVar1 & 0x7fff) * _DAT_10044108 < (float)_DAT_10044228) {
    *(undefined **)(param_1 + 0x358) = &DAT_100518b8;
    return;
  }
  *(undefined **)(param_1 + 0x358) = &DAT_100519f0;
  return;
}



/* cyborg_check_range @ 10024f10 status existing size 218 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl cyborg_check_range(int param_1)

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
  fVar3 = VectorLength(&local_c);
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



/* cyborg_checkattack @ 10024ff0 status existing size 89 */

undefined4 __cdecl cyborg_checkattack(int param_1)

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
    iVar2 = cyborg_check_range(param_1);
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 0x3b8) = 4;
      return 1;
    }
  }
  return 0;
}



/* cyborg_dead @ 10025050 status created size 92 */

void cyborg_dead(int param_1)

{
  *(undefined4 *)(param_1 + 0xbc) = 0xc2000000;
  *(undefined4 *)(param_1 + 0xc0) = 0xc2000000;
  *(undefined4 *)(param_1 + 0xc4) = 0xc2180000;
  *(undefined4 *)(param_1 + 200) = 0x42000000;
  *(undefined4 *)(param_1 + 0xcc) = 0x42000000;
  *(undefined4 *)(param_1 + 0xd0) = 0xc1a00000;
  *(undefined4 *)(param_1 + 0x104) = 7;
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 2;
  (*DAT_1006c208)(param_1);
  return;
}



/* cyborg_die @ 100250b0 status created size 328 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cyborg_die(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  float fVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  if (DAT_1006c104 == 0x23) {
    FUN_1000e460(param_1);
    return;
  }
  if ((int)param_1[0x88] <= (int)param_1[0x8a]) {
    uVar2 = (*DAT_1006c1e4)(s_misc_udeath_wav_100493f8,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_1,2,uVar2);
    iVar4 = 2;
    do {
      FUN_1000dd30((float)param_1,s_models_objects_gibs_bone_tris_md_1004b5a4,param_4,0);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar4 = 4;
    do {
      FUN_1000dd30((float)param_1,s_models_objects_gibs_sm_meat_tris_100493d0,param_4,0);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_1000df70((float)param_1,s_models_objects_gibs_head2_tris_m_100491d4,param_4,0);
    param_1[0x8b] = 2;
    return;
  }
  if (param_1[0x8b] != 2) {
    (*DAT_1006c1d0)(param_1,2,DAT_10061138,0x3f800000,0x3f800000,0);
    param_1[0x8b] = 2;
    param_1[0x90] = 1;
    param_1[0xf] = 1;
    uVar3 = _rand();
    fVar1 = (float)(uVar3 & 0x7fff) * _DAT_10044108;
    if (fVar1 < (float)_DAT_10044378) {
      param_1[0xd6] = &DAT_10051b20;
      return;
    }
    if (fVar1 < (float)_DAT_10044370) {
      param_1[0xd6] = &DAT_10051b78;
      return;
    }
    param_1[0xd6] = &DAT_10051bd0;
  }
  return;
}



/* SP_monster_cyborg @ 10025200 status created size 521 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SP_monster_cyborg(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    G_FreeEdict(param_1);
    return;
  }
  _DAT_10061120 = (*DAT_1006c1e4)(s_cyborg_mutatck1_wav_10051cf0);
  _DAT_10061148 = (*DAT_1006c1e4)(s_cyborg_mutatck2_wav_10051cdc);
  _DAT_10061118 = (*DAT_1006c1e4)(s_cyborg_mutatck3_wav_10051cc8);
  DAT_10061138 = (*DAT_1006c1e4)(s_cyborg_mutdeth1_wav_10051cb4);
  DAT_1006111c = (*DAT_1006c1e4)(s_cyborg_mutidle1_wav_10051ca0);
  DAT_10061140 = (*DAT_1006c1e4)(s_cyborg_mutpain1_wav_10051c8c);
  DAT_1006113c = (*DAT_1006c1e4)(s_cyborg_mutpain2_wav_10051c78);
  DAT_10061124 = (*DAT_1006c1e4)(s_cyborg_mutsght1_wav_10051c64);
  DAT_10061144 = (*DAT_1006c1e4)(s_cyborg_mutsrch1_wav_10051c50);
  _DAT_10061130 = (*DAT_1006c1e4)(s_cyborg_step1_wav_10051c3c);
  _DAT_10061134 = (*DAT_1006c1e4)(s_cyborg_step2_wav_10051c28);
  _DAT_1006112c = (*DAT_1006c1e4)(s_cyborg_step3_wav_10051c14);
  _DAT_10061128 = (*DAT_1006c1e4)(s_cyborg_thud1_wav_10051c00);
  param_1[0x41] = 5;
  param_1[0x3e] = 2;
  uVar1 = (*DAT_1006c1e0)(s_models_monsters_cyborg_tris_md2_10051be0);
  param_1[10] = uVar1;
  param_1[0x2f] = 0xc1800000;
  param_1[0x30] = 0xc1800000;
  param_1[0x32] = 0x41800000;
  param_1[0x33] = 0x41800000;
  param_1[0x31] = 0xc2180000;
  param_1[0x34] = 0x41d80000;
  param_1[0x88] = 300;
  param_1[0x8a] = 0xffffff88;
  param_1[100] = 300;
  param_1[0x81] = cyborg_pain;
  param_1[0x82] = cyborg_die;
  param_1[0xda] = cyborg_stand;
  param_1[0xdd] = cyborg_walk;
  param_1[0xde] = cyborg_run;
  param_1[0xdf] = 0;
  param_1[0xe0] = cyborg_attack;
  param_1[0xe1] = cyborg_melee;
  param_1[0xe2] = cyborg_sight;
  param_1[0xdc] = cyborg_search;
  param_1[0xdb] = cyborg_idle;
  param_1[0xe3] = cyborg_checkattack;
  (*DAT_1006c208)(param_1);
  param_1[0xd6] = &DAT_10051540;
  param_1[0xd9] = 0x3f800000;
  walkmonster_start(param_1);
  return;
}



/* vectoyaw @ 1001b160 status existing size 121 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl vectoyaw(float *param_1)

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



/* blaster_touch @ 1001bf10 status existing size 225 */

void __cdecl blaster_touch(undefined4 *param_1,uint param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = param_1[0x40];
  if (param_2 != uVar1) {
    if ((param_4 == 0) || ((*(byte *)(param_4 + 0x10) & 4) == 0)) {
      if (*(int *)(uVar1 + 0x54) != 0) {
        PlayerNoise(uVar1,(float *)(param_1 + 1),2);
      }
      if (*(int *)(param_2 + 0x240) != 0) {
        FUN_100060d0(param_2,param_1,param_1[0x40],(float *)(param_1 + 0x5e),(float *)(param_1 + 1),
                     param_3,param_1[0x91],1,4,(-(uint)((param_1[0x47] & 1) != 0) & 9) + 1);
        G_FreeEdict(param_1);
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
    G_FreeEdict(param_1);
  }
  return;
}



/* fire_blaster @ 1001c000 status existing size 445 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
fire_blaster(int param_1,float *param_2,float *param_3,int param_4,int param_5,uint param_6,
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
  
  VectorNormalize(param_3);
  piVar3 = G_Spawn();
  piVar3[0x2e] = 2;
  pfVar1 = (float *)(piVar3 + 1);
  *pfVar1 = *param_2;
  piVar3[2] = (int)param_2[1];
  piVar3[3] = (int)param_2[2];
  piVar3[7] = (int)*param_2;
  piVar3[8] = (int)param_2[1];
  piVar3[9] = (int)param_2[2];
  vectoangles(param_3,(float *)(piVar3 + 4));
  VectorScale(param_3,(float)param_5,(float *)(piVar3 + 0x5e));
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
  piVar3[0x7f] = (int)blaster_touch;
  fVar2 = DAT_1006c2e4 + _DAT_1004413c;
  piVar3[0x7d] = (int)G_FreeEdict;
  piVar3[0x91] = param_4;
  piVar3[0x46] = (int)&DAT_1004be74;
  piVar3[0x7b] = (int)fVar2;
  if (param_7 != 0) {
    piVar3[0x47] = 1;
  }
  (*DAT_1006c208)(piVar3);
  if (*(int *)(param_1 + 0x54) != 0) {
    check_dodge(param_1,pfVar1,param_3,param_5);
  }
  pfVar5 = (float *)(*DAT_1006c1f0)(afStack_38,param_1 + 4,0,0,pfVar1,piVar3,0x6000003);
  pfVar6 = afStack_38;
  for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar6 = *pfVar5;
    pfVar5 = pfVar5 + 1;
    pfVar6 = pfVar6 + 1;
  }
  if (afStack_38[2] < (float)_DAT_10044120) {
    VectorMA(pfVar1,-10.0,param_3,pfVar1);
    (*(code *)piVar3[0x7f])(piVar3,uStack_4,0,0);
  }
  return;
}



/* check_dodge @ 1001c1c0 status existing size 293 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl check_dodge(int param_1,float *param_2,float *param_3,int param_4)

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
  VectorMA(param_2,8192.0,param_3,local_7c);
  pfVar2 = (float *)(*DAT_1006c1f0)(local_38,param_2,0,0,local_7c,param_1,0x6000003);
  pfVar4 = afStack_70;
  for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar4 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar4 = pfVar4 + 1;
  }
  if ((((iStack_3c != 0) && ((*(byte *)(iStack_3c + 0xb8) & 4) != 0)) &&
      (0 < *(int *)(iStack_3c + 0x220))) &&
     ((*(int *)(iStack_3c + 0x37c) != 0 && (iVar3 = infront(iStack_3c,param_1), iVar3 != 0)))) {
    fStack_88 = afStack_70[3] - *param_2;
    fStack_84 = fStack_60 - param_2[1];
    fStack_80 = fStack_5c - param_2[2];
    fVar5 = VectorLength(&fStack_88);
    (**(code **)(iStack_3c + 0x37c))
              (iStack_3c,param_1,
               (float)((fVar5 - (float10)*(float *)(iStack_3c + 200)) / (float10)param_4));
  }
  return;
}



/* rocket_touch @ 1001c960 status created size 367 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rocket_touch(undefined4 *param_1,uint param_2,undefined4 param_3,int param_4)

{
  float *pfVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  float afStack_c [3];
  
  uVar2 = param_1[0x40];
  if (param_2 != uVar2) {
    if ((param_4 != 0) && ((*(byte *)(param_4 + 0x10) & 4) != 0)) {
      G_FreeEdict(param_1);
      return;
    }
    if (*(int *)(uVar2 + 0x54) != 0) {
      PlayerNoise(uVar2,(float *)(param_1 + 1),2);
    }
    pfVar1 = (float *)(param_1 + 1);
    VectorMA(pfVar1,-0.02,(float *)(param_1 + 0x5e),afStack_c);
    if (*(int *)(param_2 + 0x240) == 0) {
      if ((((*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) &&
           (*(float *)(DAT_1006c42c + 0x14) == _DAT_1004410c)) && (param_4 != 0)) &&
         ((*(byte *)(param_4 + 0x10) & 0x78) == 0)) {
        iVar3 = _rand();
        for (iVar3 = iVar3 % 5; iVar3 != 0; iVar3 = iVar3 + -1) {
          FUN_1000e210((int)param_1,s_models_objects_debris2_tris_md2_100492ac,2.0,(int *)pfVar1);
        }
      }
    }
    else {
      FUN_100060d0(param_2,param_1,param_1[0x40],(float *)(param_1 + 0x5e),pfVar1,param_3,
                   param_1[0x91],0,0,8);
    }
    FUN_10006860((float)param_1,param_1[0x40],(float)(int)param_1[0x92],param_2,(float)param_1[0x93]
                 ,9);
    (*DAT_1006c224)(3);
    if (param_1[0xaa] == 0) {
      uVar4 = 7;
    }
    else {
      uVar4 = 0x11;
    }
    (*DAT_1006c224)(uVar4);
    (*DAT_1006c238)(afStack_c);
    (*DAT_1006c218)(pfVar1,1);
    G_FreeEdict(param_1);
  }
  return;
}



/* fire_rocket @ 1001cad0 status existing size 347 */

void __cdecl
fire_rocket(int param_1,float *param_2,float *param_3,int param_4,int param_5,int param_6,
           int param_7)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = G_Spawn();
  piVar2[1] = (int)*param_2;
  piVar2[2] = (int)param_2[1];
  piVar2[3] = (int)param_2[2];
  piVar2[0x55] = (int)*param_3;
  piVar2[0x56] = (int)param_3[1];
  piVar2[0x57] = (int)param_3[2];
  vectoangles(param_3,(float *)(piVar2 + 4));
  VectorScale(param_3,(float)param_5,(float *)(piVar2 + 0x5e));
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
  piVar2[0x7f] = (int)rocket_touch;
  fVar1 = (float)(int)(8000 / (longlong)param_5) + DAT_1006c2e4;
  piVar2[0x7d] = (int)G_FreeEdict;
  piVar2[0x91] = param_4;
  piVar2[0x92] = param_7;
  piVar2[0x93] = param_6;
  piVar2[0x7b] = (int)fVar1;
  iVar3 = (*DAT_1006c1e4)(s_weapons_rockfly_wav_1004bf7c);
  piVar2[0x13] = iVar3;
  piVar2[0x46] = (int)s_rocket_1004bf74;
  if (*(int *)(param_1 + 0x54) != 0) {
    check_dodge(param_1,(float *)(piVar2 + 1),param_3,param_5);
  }
  (*DAT_1006c208)(piVar2);
  return;
}



/* obliterator_projectile_think @ 1001cc30 status existing size 238 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl obliterator_projectile_think(int param_1)

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
  VectorMA(pfVar1,fVar2 + fVar2,pfVar4,pfVar5);
  pfVar4 = (float *)(param_1 + 0x16c);
  pfVar5 = pfVar1;
  uVar3 = _rand();
  fVar2 = (float)(uVar3 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  VectorMA(pfVar1,fVar2 + fVar2,pfVar4,pfVar5);
  VectorScale(pfVar1,*(float *)(param_1 + 0x148),(float *)(param_1 + 0x178));
  vectoangles(pfVar1,(float *)(param_1 + 0x10));
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044198;
  if (*(float *)(param_1 + 0x120) + (float)_DAT_100442e0 < DAT_1006c2e4) {
    *(code **)(param_1 + 500) = G_FreeEdict;
  }
  return;
}



/* fire_obliterator_projectile @ 1001cd20 status existing size 555 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
fire_obliterator_projectile
          (int param_1,int *param_2,float *param_3,int param_4,int param_5,int param_6,int param_7)

{
  float *pfVar1;
  float fVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  
  piVar3 = G_Spawn();
  piVar3[1] = *param_2;
  piVar3[2] = param_2[1];
  piVar3[3] = param_2[2];
  piVar3[0x74] = (int)*param_3;
  piVar3[0x75] = (int)param_3[1];
  piVar3[0x76] = (int)param_3[2];
  vectoangles(param_3,(float *)(piVar3 + 4));
  pfVar1 = (float *)(piVar3 + 0x5b);
  pfVar6 = (float *)(piVar3 + 0x58);
  AngleVectors((float *)(piVar3 + 4),(float *)0x0,pfVar6,pfVar1);
  VectorScale(pfVar6,0.1,pfVar6);
  VectorScale(pfVar1,0.1,pfVar1);
  piVar3[0x55] = piVar3[0x74];
  pfVar1 = (float *)(param_1 + 0x154);
  pfVar6 = (float *)(param_1 + 0x160);
  piVar3[0x56] = piVar3[0x75];
  piVar3[0x57] = piVar3[0x76];
  pfVar7 = pfVar1;
  uVar4 = _rand();
  fVar2 = (float)(uVar4 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  VectorMA(pfVar1,fVar2 + fVar2,pfVar6,pfVar7);
  pfVar6 = (float *)(param_1 + 0x16c);
  pfVar7 = pfVar1;
  uVar4 = _rand();
  fVar2 = (float)(uVar4 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  VectorMA(pfVar1,fVar2 + fVar2,pfVar6,pfVar7);
  piVar3[0x52] = (int)(float)param_5;
  VectorScale((float *)(piVar3 + 0x55),(float)param_5,(float *)(piVar3 + 0x5e));
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
  piVar3[0x7f] = (int)rocket_touch;
  piVar3[0x91] = param_4;
  piVar3[0x92] = param_7;
  piVar3[0x93] = param_6;
  iVar5 = (*DAT_1006c1e4)(s_weapons_rockfly_wav_1004bf7c);
  piVar3[0x13] = iVar5;
  piVar3[0x46] = (int)s_rocket_1004bf74;
  fVar2 = DAT_1006c2e4;
  piVar3[0x7d] = (int)obliterator_projectile_think;
  piVar3[0x48] = (int)fVar2;
  piVar3[0x7b] = (int)(DAT_1006c2e4 + (float)_DAT_10044198);
  if (*(int *)(param_1 + 0x54) != 0) {
    check_dodge(param_1,(float *)(piVar3 + 1),param_3,param_5);
  }
  (*DAT_1006c208)(piVar3);
  return;
}



/* Grenade_Explode @ 1001c4a0 status existing size 472 */

void __cdecl Grenade_Explode(undefined4 *param_1)

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
    PlayerNoise(param_1[0x40],(float *)(param_1 + 1),2);
  }
  iVar1 = param_1[0x97];
  if (iVar1 != 0) {
    local_24 = *(float *)(iVar1 + 200) + *(float *)(iVar1 + 0xbc);
    local_20 = *(float *)(iVar1 + 0xcc) + *(float *)(iVar1 + 0xc0);
    local_1c = *(float *)(iVar1 + 0xd0) + *(float *)(iVar1 + 0xc4);
    VectorMA((float *)(iVar1 + 4),0.5,&local_24,&local_24);
    local_24 = (float)param_1[1] - local_24;
    local_20 = (float)param_1[2] - local_20;
    local_1c = (float)param_1[3] - local_1c;
    VectorLength(&local_24);
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
  VectorMA((float *)(param_1 + 1),-0.02,(float *)(param_1 + 0x5e),local_c);
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
  G_FreeEdict(param_1);
  return;
}



/* fire_grenade2 @ 1001c740 status existing size 543 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
fire_grenade2(int param_1,int *param_2,float *param_3,int param_4,int param_5,float param_6,
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
  
  vectoangles(param_3,local_30);
  AngleVectors(local_30,local_c,local_18,local_24);
  piVar3 = G_Spawn();
  pfVar1 = (float *)(piVar3 + 0x5e);
  piVar3[1] = *param_2;
  piVar3[2] = param_2[1];
  piVar3[3] = param_2[2];
  VectorScale(param_3,(float)param_5,pfVar1);
  pfVar7 = local_24;
  pfVar8 = pfVar1;
  uVar4 = _rand();
  fVar2 = (float)(uVar4 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  VectorMA(pfVar1,(fVar2 + fVar2) * (float)_DAT_10044170 + (float)_DAT_100441d8,pfVar7,pfVar8);
  pfVar7 = local_18;
  pfVar8 = pfVar1;
  uVar4 = _rand();
  fVar2 = (float)(uVar4 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  VectorMA(pfVar1,(fVar2 + fVar2) * (float)_DAT_10044170,pfVar7,pfVar8);
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
  piVar3[0x7d] = (int)Grenade_Explode;
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
    Grenade_Explode(piVar3);
    return;
  }
  uVar6 = (*DAT_1006c1e4)(s_weapons_hgrent1a_wav_1004bf14,0x3f800000,0x3f800000,0);
  (*DAT_1006c1d0)(param_1,1,uVar6);
  (*DAT_1006c208)(piVar3);
  return;
}



/* fire_rail @ 1001cf50 status existing size 449 */

void __cdecl fire_rail(uint param_1,float *param_2,float *param_3,int param_4,int param_5)

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
  
  VectorMA(param_2,8192.0,param_3,local_44);
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
    PlayerNoise(param_1,afStack_7c + 3,2);
  }
  return;
}



/* bfg_explode @ 1001d120 status created size 442 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bfg_explode(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  bool bVar4;
  uint uVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  longlong lVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (*(int *)(param_1 + 0x38) == 0) {
    pfVar1 = (float *)(param_1 + 4);
    for (uVar5 = findradius(0,(int)pfVar1,*(float *)(param_1 + 0x24c)); uVar5 != 0;
        uVar5 = findradius(uVar5,(int)pfVar1,*(float *)(param_1 + 0x24c))) {
      if ((((*(int *)(uVar5 + 0x240) != 0) && (uVar5 != *(uint *)(param_1 + 0x100))) &&
          (bVar4 = FUN_10005990(uVar5,param_1), CONCAT31(extraout_var,bVar4) != 0)) &&
         (bVar4 = FUN_10005990(uVar5,*(int *)(param_1 + 0x100)),
         CONCAT31(extraout_var_00,bVar4) != 0)) {
        fStack_c = *(float *)(uVar5 + 200) + *(float *)(uVar5 + 0xbc);
        pfVar2 = (float *)(uVar5 + 4);
        fStack_8 = *(float *)(uVar5 + 0xcc) + *(float *)(uVar5 + 0xc0);
        fStack_4 = *(float *)(uVar5 + 0xd0) + *(float *)(uVar5 + 0xc4);
        VectorMA(pfVar2,0.5,&fStack_c,&fStack_c);
        fStack_c = *pfVar1 - fStack_c;
        fStack_8 = *(float *)(param_1 + 8) - fStack_8;
        fStack_4 = *(float *)(param_1 + 0xc) - fStack_4;
        VectorLength(&fStack_c);
        (*DAT_1006c224)(3);
        (*DAT_1006c224)(0x14);
        (*DAT_1006c238)(pfVar2);
        (*DAT_1006c218)(pfVar2,1);
        uVar9 = 0xe;
        uVar8 = 4;
        iVar7 = 0;
        lVar6 = __ftol();
        FUN_100060d0(uVar5,param_1,*(uint *)(param_1 + 0x100),(float *)(param_1 + 0x178),pfVar2,
                     &DAT_10061c18,(int)lVar6,iVar7,uVar8,uVar9);
      }
    }
  }
  fVar3 = DAT_1006c2e4 + (float)_DAT_10044168;
  iVar7 = *(int *)(param_1 + 0x38) + 1;
  *(int *)(param_1 + 0x38) = iVar7;
  *(float *)(param_1 + 0x1ec) = fVar3;
  if (iVar7 == 5) {
    *(code **)(param_1 + 500) = G_FreeEdict;
  }
  return;
}



/* bfg_touch @ 1001d2e0 status created size 344 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bfg_touch(undefined4 *param_1,uint param_2,undefined4 param_3,int param_4)

{
  float *pfVar1;
  uint uVar2;
  float fVar3;
  undefined4 uVar4;
  
  uVar2 = param_1[0x40];
  if (param_2 != uVar2) {
    if ((param_4 != 0) && ((*(byte *)(param_4 + 0x10) & 4) != 0)) {
      G_FreeEdict(param_1);
      return;
    }
    if (*(int *)(uVar2 + 0x54) != 0) {
      PlayerNoise(uVar2,(float *)(param_1 + 1),2);
    }
    if (*(int *)(param_2 + 0x240) != 0) {
      FUN_100060d0(param_2,param_1,param_1[0x40],(float *)(param_1 + 0x5e),(float *)(param_1 + 1),
                   param_3,200,0,0,0xd);
    }
    FUN_10006860((float)param_1,param_1[0x40],200.0,param_2,100.0,0xd);
    uVar4 = (*DAT_1006c1e4)(s_weapons_bfg__x1b_wav_1004bfc4,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_1,2,uVar4);
    pfVar1 = (float *)(param_1 + 1);
    param_1[0x3e] = 0;
    param_1[0x7f] = 0;
    VectorMA(pfVar1,-0.1,(float *)(param_1 + 0x5e),pfVar1);
    param_1[0x60] = 0;
    param_1[0x5f] = 0;
    param_1[0x5e] = 0.0;
    uVar4 = (*DAT_1006c1e0)(s_sprites_s_bfg3_sp2_1004bfb0);
    param_1[10] = uVar4;
    param_1[0xe] = 0;
    param_1[0x13] = 0;
    param_1[0x10] = param_1[0x10] & 0xffffdfff;
    param_1[0x7d] = bfg_explode;
    fVar3 = DAT_1006c2e4 + (float)_DAT_10044168;
    param_1[0x97] = param_2;
    param_1[0x7b] = fVar3;
    (*DAT_1006c224)(3);
    (*DAT_1006c224)(0x15);
    (*DAT_1006c238)(pfVar1);
    (*DAT_1006c218)(pfVar1,2);
  }
  return;
}



/* bfg_think @ 1001d440 status created size 681 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bfg_think(uint param_1)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  float *pfVar5;
  char *pcVar6;
  uint uVar7;
  float *pfVar8;
  bool bVar9;
  int iStack_a4;
  float fStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float afStack_7c [4];
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined1 auStack_64 [28];
  uint uStack_48;
  float afStack_44 [3];
  undefined1 auStack_38 [56];
  
  iStack_a4 = 5;
  if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
    iStack_a4 = 10;
  }
  uVar2 = findradius(0,param_1 + 4,256.0);
  do {
    if (uVar2 == 0) {
      *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
      return;
    }
    if (((uVar2 != param_1) && (uVar2 != *(uint *)(param_1 + 0x100))) &&
       (*(int *)(uVar2 + 0x240) != 0)) {
      if (((*(byte *)(uVar2 + 0xb8) & 4) == 0) && (*(int *)(uVar2 + 0x54) == 0)) {
        pbVar3 = *(byte **)(uVar2 + 0x118);
        pcVar6 = s_misc_explobox_1004aefc;
        do {
          bVar1 = *pbVar3;
          bVar9 = bVar1 < (byte)*pcVar6;
          if (bVar1 != *pcVar6) {
LAB_1001d4f4:
            iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
            goto LAB_1001d4f9;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar3[1];
          bVar9 = bVar1 < (byte)pcVar6[1];
          if (bVar1 != pcVar6[1]) goto LAB_1001d4f4;
          pbVar3 = pbVar3 + 2;
          pcVar6 = pcVar6 + 2;
        } while (bVar1 != 0);
        iVar4 = 0;
LAB_1001d4f9:
        if (iVar4 != 0) goto LAB_1001d6b0;
      }
      VectorMA((float *)(uVar2 + 0xd4),0.5,(float *)(uVar2 + 0xec),&fStack_88);
      fStack_94 = fStack_88 - *(float *)(param_1 + 4);
      fStack_90 = fStack_84 - *(float *)(param_1 + 8);
      fStack_8c = fStack_80 - *(float *)(param_1 + 0xc);
      VectorNormalize(&fStack_94);
      fStack_a0 = *(float *)(param_1 + 4);
      uStack_9c = *(undefined4 *)(param_1 + 8);
      uStack_98 = *(undefined4 *)(param_1 + 0xc);
      VectorMA(&fStack_a0,2048.0,&fStack_94,afStack_44);
      uVar7 = param_1;
      while( true ) {
        pfVar5 = (float *)(*DAT_1006c1f0)(auStack_38,&fStack_a0,0,0,afStack_44,uVar7,0x6000001);
        pfVar8 = afStack_7c;
        for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
          *pfVar8 = *pfVar5;
          pfVar5 = pfVar5 + 1;
          pfVar8 = pfVar8 + 1;
        }
        if (uStack_48 == 0) goto LAB_1001d67f;
        if (((*(int *)(uStack_48 + 0x240) != 0) && ((*(byte *)(uStack_48 + 0x108) & 4) == 0)) &&
           (uStack_48 != *(uint *)(param_1 + 0x100))) {
          FUN_100060d0(uStack_48,param_1,*(uint *)(param_1 + 0x100),&fStack_94,afStack_7c + 3,
                       &DAT_10061c18,iStack_a4,1,4,0xc);
        }
        if (((*(byte *)(uStack_48 + 0xb8) & 4) == 0) && (*(int *)(uStack_48 + 0x54) == 0)) break;
        uStack_9c = uStack_6c;
        uStack_98 = uStack_68;
        fStack_a0 = afStack_7c[3];
        uVar7 = uStack_48;
      }
      (*DAT_1006c224)(3);
      (*DAT_1006c224)(0xf);
      (*DAT_1006c224)(4);
      (*DAT_1006c238)(afStack_7c + 3);
      (*DAT_1006c23c)(auStack_64);
      (*DAT_1006c224)(*(undefined4 *)(param_1 + 0x3c));
      (*DAT_1006c218)(afStack_7c + 3,2);
LAB_1001d67f:
      (*DAT_1006c224)(3);
      (*DAT_1006c224)(0x17);
      (*DAT_1006c238)(param_1 + 4);
      (*DAT_1006c238)(afStack_7c + 3);
      (*DAT_1006c218)(param_1 + 4,1);
    }
LAB_1001d6b0:
    uVar2 = findradius(uVar2,param_1 + 4,256.0);
  } while( true );
}



/* fire_bfg @ 1001d6f0 status existing size 380 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl fire_bfg(int param_1,float *param_2,float *param_3,int param_4,int param_5,int param_6)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = G_Spawn();
  piVar2[1] = (int)*param_2;
  piVar2[2] = (int)param_2[1];
  piVar2[3] = (int)param_2[2];
  piVar2[0x55] = (int)*param_3;
  piVar2[0x56] = (int)param_3[1];
  piVar2[0x57] = (int)param_3[2];
  vectoangles(param_3,(float *)(piVar2 + 4));
  VectorScale(param_3,(float)param_5,(float *)(piVar2 + 0x5e));
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
  piVar2[0x7f] = (int)bfg_touch;
  fVar1 = (float)(int)(8000 / (longlong)param_5) + DAT_1006c2e4;
  piVar2[0x7d] = (int)G_FreeEdict;
  piVar2[0x92] = param_4;
  piVar2[0x93] = param_6;
  piVar2[0x46] = (int)s_bfg_blast_1004bfdc;
  piVar2[0x7b] = (int)fVar1;
  iVar3 = (*DAT_1006c1e4)(s_weapons_bfg__l1a_wav_1004bfe8);
  piVar2[0x13] = iVar3;
  piVar2[0x7d] = (int)bfg_think;
  fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
  piVar2[0x9d] = (int)piVar2;
  piVar2[0x9c] = 0;
  piVar2[0x7b] = (int)fVar1;
  if (*(int *)(param_1 + 0x54) != 0) {
    check_dodge(param_1,(float *)(piVar2 + 1),param_3,param_5);
  }
  (*DAT_1006c208)(piVar2);
  return;
}



/* fire_proximity_mine @ 1001d870 status existing size 707 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl fire_proximity_mine(int param_1,int *param_2,float *param_3,int param_4)

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
  
  vectoangles(param_3,local_30);
  AngleVectors(local_30,local_c,local_18,local_24);
  piVar4 = G_Spawn();
  pfVar1 = (float *)(piVar4 + 0x5e);
  piVar4[1] = *param_2;
  piVar4[2] = param_2[1];
  piVar4[3] = param_2[2];
  VectorScale(param_3,(float)param_4,pfVar1);
  pfVar12 = local_24;
  pfVar13 = pfVar1;
  uVar5 = _rand();
  fVar3 = (float)(uVar5 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  VectorMA(pfVar1,(fVar3 + fVar3) * (float)_DAT_10044170 + (float)_DAT_100441d8,pfVar12,pfVar13);
  pfVar12 = local_18;
  pfVar13 = pfVar1;
  uVar5 = _rand();
  fVar3 = (float)(uVar5 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  VectorMA(pfVar1,(fVar3 + fVar3) * (float)_DAT_10044170,pfVar12,pfVar13);
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
  piVar4[0x7f] = (int)proximity_mine_touch;
  piVar4[0x7b] = 0;
  piVar4[0x7d] = (int)proximity_mine_think;
  piVar4[0x90] = 1;
  piVar4[0x82] = (int)proximity_mine_die;
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
      proximity_mine_explode(piVar4);
    }
  }
  return;
}



/* proximity_mine_explode @ 1001db40 status existing size 190 */

void __cdecl proximity_mine_explode(undefined4 *param_1)

{
  undefined4 uVar1;
  float local_c [3];
  
  param_1[0x60] = 0;
  param_1[0x5f] = 0;
  param_1[0x5e] = 0.0;
  FUN_10006860((float)param_1,param_1[0x40],(float)(int)param_1[0x91],0,(float)param_1[0x93],0x2a);
  VectorMA((float *)(param_1 + 1),-0.02,(float *)(param_1 + 0x5e),local_c);
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
  G_FreeEdict(param_1);
  return;
}



/* proximity_mine_think @ 1001dc00 status created size 93 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void proximity_mine_think(int param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar2 = findradius(uVar2,param_1 + 4,100.0);
    if (uVar2 == 0) {
      *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
      return;
    }
    iVar1 = *(int *)(uVar2 + 0x240);
    *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  } while (iVar1 != 2);
  *(code **)(param_1 + 500) = proximity_mine_laser_start;
  return;
}



/* proximity_mine_laser_start @ 1001dc60 status existing size 151 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl proximity_mine_laser_start(int param_1)

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
  VectorScale((float *)(param_1 + 0x334),30.0,(float *)(param_1 + 0x178));
  fVar1 = DAT_1006c2e4 + _DAT_10044104;
  *(undefined4 *)(param_1 + 0x254) = 0;
  *(code **)(param_1 + 500) = proximity_mine_laser_think;
  *(float *)(param_1 + 0x1ec) = fVar1;
  uVar2 = (*DAT_1006c1e4)(s_weapons_hgrenc1b_wav_1004bf2c);
  *(undefined4 *)(param_1 + 0x4c) = uVar2;
  return;
}



/* proximity_mine_laser_think @ 1001dd00 status existing size 458 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl proximity_mine_laser_think(int *param_1)

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
        piVar5 = G_Spawn();
        pfVar7 = (float *)(piVar5 + 0x55);
        piVar5[0x99] = piVar3[0x40];
        piVar5[0x40] = piVar3[0x40];
        piVar5[0x47] = 0x89;
        AngleVectors((float *)(piVar8 + 4),(float *)0x0,pfVar7,(float *)0x0);
        VectorNormalize(pfVar7);
        vectoangles(pfVar7,(float *)(piVar5 + 4));
        piVar5[1] = piVar3[1];
        piVar5[2] = piVar3[2];
        piVar5[3] = piVar3[3];
        piVar5[0x91] = 0x28;
        piVar5[0x46] = (int)s_mine_laser_1004c03c;
        piVar8[0x96] = (int)piVar5;
        target_laser_start((uint)piVar5);
        (*DAT_1006c208)(piVar5);
        param_1 = (int *)((int)param_1 + -1);
        piVar8 = piVar5;
      } while (param_1 != (int *)0x0);
    }
    pfVar7 = (float *)(piVar3 + 4);
    param_1 = (int *)0x4;
    piVar8 = piVar3;
    do {
      AngleVectors(pfVar7,(float *)0x0,(float *)(piVar8[0x96] + 0x154),(float *)0x0);
      piVar8 = (int *)piVar8[0x96];
      VectorNormalize((float *)(piVar8 + 0x55));
      pfVar7 = (float *)(piVar8 + 4);
      vectoangles((float *)(piVar8 + 0x55),pfVar7);
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
    G_FreeEdict(puVar4);
    iVar6 = iVar6 + -1;
    puVar4 = puVar1;
  } while (iVar6 != 0);
  fVar2 = DAT_1006c2e4 + (float)_DAT_10044168;
  param_1[0x7d] = (int)proximity_mine_explode;
  param_1[0x7b] = (int)fVar2;
  return;
}



/* proximity_mine_touch @ 1001ded0 status created size 126 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void proximity_mine_touch(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = (*DAT_1006c1e4)(s_weapons_hgrenb1a_wav_1004befc,0x3f800000,0x3f800000,0);
  (*DAT_1006c1d0)(param_1,2,uVar2);
  iVar1 = *(int *)(param_2 + 0x240);
  *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  if (iVar1 == 2) {
    *(code **)(param_1 + 500) = proximity_mine_explode;
    *(undefined4 *)(param_1 + 0x184) = 0;
    *(undefined4 *)(param_1 + 0x188) = 0;
    *(undefined4 *)(param_1 + 0x18c) = 0;
    *(undefined4 *)(param_1 + 0x178) = 0;
    *(undefined4 *)(param_1 + 0x17c) = 0;
    *(undefined4 *)(param_1 + 0x180) = 0;
  }
  return;
}



/* proximity_mine_die @ 1001df50 status created size 45 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void proximity_mine_die(int param_1)

{
  float fVar1;
  
  if (*(code **)(param_1 + 500) == proximity_mine_think) {
    fVar1 = DAT_1006c2e4 + (float)_DAT_10044198;
    *(code **)(param_1 + 500) = proximity_mine_explode;
    *(float *)(param_1 + 0x1ec) = fVar1;
  }
  return;
}



/* deatom_touch @ 1001df80 status existing size 234 */

void __cdecl deatom_touch(undefined4 *param_1,uint param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = param_1[0x40];
  if (param_2 != uVar1) {
    if ((param_4 != 0) && ((*(byte *)(param_4 + 0x10) & 4) != 0)) {
      G_FreeEdict(param_1);
      return;
    }
    if (*(int *)(uVar1 + 0x54) != 0) {
      PlayerNoise(uVar1,(float *)(param_1 + 1),2);
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
    G_FreeEdict(param_1);
  }
  return;
}



/* deatom_think @ 1001e070 status created size 463 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void deatom_think(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  float fVar3;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar1 = *(int *)(param_1 + 0x25c);
  *(int *)(param_1 + 0x38) = (*(int *)(param_1 + 0x38) + 2) % 0xf;
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x58) != 0)) {
    fStack_14 = *(float *)(iVar1 + 8);
    fStack_10 = (float)*(int *)(iVar1 + 0x23c) + *(float *)(iVar1 + 0xc);
    fStack_c = *(float *)(iVar1 + 4) - *(float *)(param_1 + 4);
    fStack_8 = fStack_14 - *(float *)(param_1 + 8);
    fStack_4 = fStack_10 - *(float *)(param_1 + 0xc);
    VectorNormalize(&fStack_c);
    fStack_10 = *(float *)(param_1 + 0x15c);
    fStack_14 = *(float *)(param_1 + 0x158);
    fStack_18 = *(float *)(param_1 + 0x154);
    fVar3 = fStack_18 * fStack_c + fStack_14 * fStack_8 + fStack_10 * fStack_4;
    if (fVar3 <= (float)_DAT_100442f0) {
      *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + _DAT_100441c0;
      return;
    }
    VectorMA(&fStack_c,-fVar3,(float *)(param_1 + 0x154),&fStack_c);
    if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
      fVar3 = 0.25;
    }
    else {
      fVar3 = 0.5;
    }
    VectorMA(&fStack_18,fVar3,&fStack_c,&fStack_18);
    VectorNormalize(&fStack_18);
    *(float *)(param_1 + 0x158) = fStack_14;
    *(float *)(param_1 + 0x15c) = fStack_10;
    *(float *)(param_1 + 0x154) = fStack_18;
    uVar2 = *(undefined4 *)(param_1 + 0x18);
    vectoangles(&fStack_18,(float *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x18) = uVar2;
    VectorScale(&fStack_18,*(float *)(param_1 + 0x148),(float *)(param_1 + 0x178));
    *(float *)(param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
    return;
  }
  *(undefined4 *)(param_1 + 0x25c) = 0;
  fVar3 = DAT_1006c2e4 + _DAT_100441c0;
  *(code **)(param_1 + 500) = G_FreeEdict;
  *(float *)(param_1 + 0x1ec) = fVar3;
  return;
}



/* fire_deatom @ 1001e240 status existing size 733 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl fire_deatom(float param_1,int *param_2,float *param_3,int param_4,float param_5)

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
  VectorNormalize(param_3);
  piVar5 = G_Spawn();
  piVar5[0x2e] = 2;
  piVar5[1] = *param_2;
  piVar5[2] = param_2[1];
  piVar5[3] = param_2[2];
  piVar5[7] = *param_2;
  piVar5[8] = param_2[1];
  piVar5[9] = param_2[2];
  vectoangles(param_3,(float *)(piVar5 + 4));
  piVar5[0x52] = (int)(float)(int)param_5;
  VectorScale(param_3,(float)(int)param_5,(float *)(piVar5 + 0x5e));
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
  piVar5[0x7f] = (int)deatom_touch;
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
    VectorMA((float *)(piVar5 + 1),-10.0,param_3,(float *)(piVar5 + 1));
    if (iStack_4 == piVar5[0x40]) {
      G_FreeEdict(piVar5);
    }
    else {
      (*(code *)piVar5[0x7f])(piVar5,iStack_4,0,0);
    }
  }
  fVar1 = DAT_1006c2e4 + (float)_DAT_10044168;
  pfVar8 = (float *)0x0;
  piVar5[0x7d] = (int)deatom_think;
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
    pfVar8 = (float *)findradius((int)pfVar8,(int)(piVar5 + 1),1024.0);
    if (pfVar8 == (float *)0x0) break;
    fVar1 = param_1;
    pfVar7 = param_3;
    fVar4 = param_5;
    if ((pfVar8[0x90] == 2.8026e-45) && (iVar6 = visible((int)piVar5,(int)pfVar8), iVar6 != 0)) {
      fStack_44 = pfVar8[1] - (float)piVar5[1];
      fStack_40 = pfVar8[2] - (float)piVar5[2];
      fStack_3c = pfVar8[3] - (float)piVar5[3];
      fVar9 = (float10)VectorNormalize(&fStack_44);
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



/* plasma_bolt_touch @ 1001e520 status existing size 277 */

void __cdecl plasma_bolt_touch(undefined4 *param_1,uint param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  uVar1 = param_1[0x40];
  if (param_2 != uVar1) {
    if ((param_4 == 0) || ((*(byte *)(param_4 + 0x10) & 4) == 0)) {
      if (*(int *)(uVar1 + 0x54) != 0) {
        PlayerNoise(uVar1,(float *)(param_1 + 1),2);
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
        G_FreeEdict(param_1);
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
    G_FreeEdict(param_1);
  }
  return;
}



/* fire_plasma_bolt @ 1001e640 status existing size 475 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
fire_plasma_bolt(int param_1,float *param_2,float *param_3,int param_4,int param_5,int param_6)

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
  
  VectorNormalize(param_3);
  piVar3 = G_Spawn();
  piVar3[0x2e] = 2;
  pfVar1 = (float *)(piVar3 + 1);
  *pfVar1 = *param_2;
  piVar3[2] = (int)param_2[1];
  piVar3[3] = (int)param_2[2];
  piVar3[7] = (int)*param_2;
  piVar3[8] = (int)param_2[1];
  piVar3[9] = (int)param_2[2];
  vectoangles(param_3,(float *)(piVar3 + 4));
  VectorScale(param_3,(float)param_5,(float *)(piVar3 + 0x5e));
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
  piVar3[0x7f] = (int)plasma_bolt_touch;
  fVar2 = DAT_1006c2e4 + _DAT_100441a8;
  piVar3[0x91] = param_4;
  piVar3[0x7d] = (int)G_FreeEdict;
  piVar3[0x46] = (int)&DAT_1004be74;
  piVar3[0x7b] = (int)fVar2;
  if (param_6 != 0) {
    piVar3[0x47] = 1;
  }
  (*DAT_1006c208)(piVar3);
  if (*(int *)(param_1 + 0x54) != 0) {
    check_dodge(param_1,pfVar1,param_3,param_5);
  }
  pfVar5 = (float *)(*DAT_1006c1f0)(afStack_38,param_1 + 4,0,0,pfVar1,piVar3,0x6000003);
  pfVar6 = afStack_38;
  for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar6 = *pfVar5;
    pfVar5 = pfVar5 + 1;
    pfVar6 = pfVar6 + 1;
  }
  if (afStack_38[2] < (float)_DAT_10044120) {
    VectorMA(pfVar1,-10.0,param_3,pfVar1);
    (*(code *)piVar3[0x7f])(piVar3,uStack_4,0,0);
  }
  return;
}



/* detpack_detonate @ 1001e820 status existing size 205 */

void __cdecl detpack_detonate(undefined4 *param_1)

{
  undefined4 uVar1;
  float local_c [3];
  
  param_1[0x90] = 0;
  if (*(int *)(param_1[0x40] + 0x54) != 0) {
    PlayerNoise(param_1[0x40],(float *)(param_1 + 1),2);
  }
  FUN_10006860((float)param_1,param_1[0x40],(float)(int)param_1[0x91],param_1[0x97],
               (float)param_1[0x93],0x26);
  VectorMA((float *)(param_1 + 1),-0.02,(float *)(param_1 + 0x5e),local_c);
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
  G_FreeEdict(param_1);
  return;
}



/* fire_detpack @ 1001e8f0 status existing size 701 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
fire_detpack(int param_1,int *param_2,float *param_3,int param_4,int param_5,float param_6,
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
  
  vectoangles(param_3,local_30);
  AngleVectors(local_30,local_c,local_18,local_24);
  piVar4 = G_Spawn();
  pfVar1 = (float *)(piVar4 + 0x5e);
  piVar4[1] = *param_2;
  piVar4[2] = param_2[1];
  piVar4[3] = param_2[2];
  VectorScale(param_3,param_6,pfVar1);
  pfVar11 = local_24;
  pfVar12 = pfVar1;
  uVar5 = _rand();
  fVar3 = (float)(uVar5 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  VectorMA(pfVar1,(fVar3 + fVar3) * (float)_DAT_10044170 + (float)_DAT_10044300,pfVar11,pfVar12);
  pfVar11 = local_18;
  pfVar12 = pfVar1;
  uVar5 = _rand();
  fVar3 = (float)(uVar5 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  VectorMA(pfVar1,(fVar3 + fVar3) * (float)_DAT_10044170,pfVar11,pfVar12);
  local_3c = -*param_3;
  local_38 = -param_3[1];
  local_34 = -param_3[2];
  vectoangles(&local_3c,(float *)(piVar4 + 4));
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
    piVar4[0x7d] = (int)detpack_detonate;
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
      detpack_detonate(piVar4);
    }
  }
  return;
}



/* dod_client_reset @ 1001eca0 status created size 19 */

void dod_client_reset(undefined4 param_1,int param_2)

{
  *(undefined2 *)(param_2 + 0xc) = 0;
  *(undefined2 *)(param_2 + 10) = 0;
  *(undefined2 *)(param_2 + 8) = 0;
  return;
}



/* dod_pulse_think @ 1001ecc0 status created size 172 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void dod_pulse_think(float param_1)

{
  float fVar1;
  int iVar2;
  
  if (*(int *)((int)param_1 + 0x38) < 10) {
    fVar1 = *(float *)((int)param_1 + 0x24c) + _DAT_10044200;
    iVar2 = *(int *)((int)param_1 + 0x244) + 0x19;
    *(int *)((int)param_1 + 0x38) = *(int *)((int)param_1 + 0x38) + 1;
    *(float *)((int)param_1 + 0x24c) = fVar1;
    *(int *)((int)param_1 + 0x244) = iVar2;
    FUN_10006860(param_1,*(uint *)((int)param_1 + 0x100),(float)iVar2,
                 *(uint *)((int)param_1 + 0x100),fVar1,0x28);
    *(float *)((int)param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
  }
  else {
    *(code **)((int)param_1 + 500) = G_FreeEdict;
    *(float *)((int)param_1 + 0x1ec) = DAT_1006c2e4 + (float)_DAT_10044168;
    if ((*(int *)((int)param_1 + 0x100) != 0) &&
       (iVar2 = *(int *)(*(int *)((int)param_1 + 0x100) + 0x54), iVar2 != 0)) {
      *(undefined4 *)(iVar2 + 0xf10) = 0;
      return;
    }
  }
  return;
}



/* fire_dod @ 1001ed70 status existing size 315 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl fire_dod(int param_1,int *param_2)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar2 = G_Spawn();
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
  piVar2[0x7d] = (int)dod_pulse_think;
  piVar2[0x91] = 0x32;
  piVar2[0x7b] = (int)fVar1;
  piVar2[0x93] = 0x42800000;
  piVar2[0x46] = (int)&DAT_1004c128;
  uVar4 = (*DAT_1006c1e4)(s_dod_dod_wav_1004c12c,0x3f800000,0x3f800000,0);
  (*DAT_1006c1d0)(param_1,2,uVar4);
  (*DAT_1006c208)(piVar2);
  if (*(int *)(param_1 + 0x54) != 0) {
    *(code **)(*(int *)(param_1 + 0x54) + 0xf10) = dod_client_reset;
  }
  return;
}



/* G_InitEdict @ 1001b310 status existing size 60 */

void __cdecl G_InitEdict(int *param_1)

{
  param_1[0x16] = 1;
  param_1[0x46] = (int)s_noclass_1004be3c;
  param_1[0x66] = 0x3f800000;
  *param_1 = ((int)param_1 - DAT_1006c2c4) / 0x3d0;
  return;
}



/* G_Spawn @ 1001b350 status existing size 174 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * G_Spawn(void)

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
  G_InitEdict(piVar2);
  return piVar2;
}



/* G_FreeEdict @ 1001b400 status existing size 114 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl G_FreeEdict(undefined4 *param_1)

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



/* KillBox @ 1001b510 status existing size 138 */

undefined4 __cdecl KillBox(int param_1)

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



/* player_die @ 10030160 status existing size 768 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl player_die(float param_1,int param_2,int param_3,int param_4)

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
      Cmd_Help_f((int)param_1);
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



/* InitClientPersistant @ 10030460 status existing size 254 */

void __cdecl InitClientPersistant(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(param_1 + 0xbc);
  for (iVar2 = 0x19d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  puVar1 = FindItem((byte *)s_Plasma_Pistol_10048cb0);
  *(int *)(param_1 + 0x2e0) = (int)(puVar1 + -0x4011a4a) / 0x48;
  *(undefined4 *)(param_1 + 0x2e4 + ((int)(puVar1 + -0x4011a4a) / 0x48) * 4) = 1;
  *(undefined4 **)(param_1 + 0x714) = puVar1;
  puVar1 = FindItem((byte *)s_PistolPlasma_10048ca0);
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



/* InitClientResp @ 10030560 status existing size 54 */

void __cdecl InitClientResp(int param_1)

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



/* SaveClientData @ 100305a0 status existing size 176 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SaveClientData(void)

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



/* PutClientInServer @ 10031070 status existing size 1278 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl PutClientInServer(int param_1)

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
      ClientUserinfoChanged(param_1,local_f00);
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
    InitClientPersistant((int)puVar1);
    ClientUserinfoChanged(param_1,local_f00);
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
    InitClientPersistant((int)puVar1);
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
  *(code **)(param_1 + 0x208) = player_die;
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
  KillBox(param_1);
  (*DAT_1006c208)(param_1);
  puVar1[0x37f] = puVar1[0x1c5];
  ChangeWeapon(param_1);
  return;
}



/* ClientBeginDeathmatch @ 10031570 status existing size 157 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl ClientBeginDeathmatch(int *param_1)

{
  G_InitEdict(param_1);
  InitClientResp(param_1[0x15]);
  PutClientInServer((int)param_1);
  if (_DAT_1006c3a8 == _DAT_1004410c) {
    (*DAT_1006c224)(1);
    (*DAT_1006c228)(((int)param_1 - DAT_1006c2c4) / 0x3d0);
    (*DAT_1006c224)(9);
    (*DAT_1006c218)(param_1 + 1,2);
  }
  else {
    MoveClientToIntermission((int)param_1);
  }
  (*DAT_1006c1c0)(2,s__s_entered_the_game_1005f3e4,param_1[0x15] + 700);
  ClientEndServerFrame((float)param_1);
  return;
}



/* ClientBegin @ 10031610 status created size 330 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ClientBegin(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  
  param_1[0x15] = DAT_1006c844 + -0xf34 + (((int)param_1 - DAT_1006c2c4) / 0x3d0) * 0xf34;
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    ClientBeginDeathmatch(param_1);
    return;
  }
  if (param_1[0x16] == 1) {
    iVar2 = 0x14;
    iVar3 = 0x1c;
    do {
      iVar1 = param_1[0x15];
      lVar4 = __ftol();
      *(short *)(iVar1 + iVar2) = (short)lVar4;
      iVar3 = iVar3 + 4;
      iVar2 = iVar2 + 2;
    } while (iVar3 < 0x28);
  }
  else {
    G_InitEdict(param_1);
    param_1[0x46] = (int)s_player_10046030;
    InitClientResp(param_1[0x15]);
    PutClientInServer((int)param_1);
  }
  if (_DAT_1006c3a8 == _DAT_1004410c) {
    if (1 < DAT_1006ca48) {
      (*DAT_1006c224)(1);
      (*DAT_1006c228)(((int)param_1 - DAT_1006c2c4) / 0x3d0);
      (*DAT_1006c224)(9);
      (*DAT_1006c218)(param_1 + 1,2);
      (*DAT_1006c1c0)(2,s__s_entered_the_game_1005f3e4,param_1[0x15] + 700);
    }
    ClientEndServerFrame((float)param_1);
    return;
  }
  MoveClientToIntermission((int)param_1);
  ClientEndServerFrame((float)param_1);
  return;
}



/* ClientUserinfoChanged @ 10031760 status existing size 485 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl ClientUserinfoChanged(int param_1,byte *param_2)

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



/* ClientConnect @ 10031950 status existing size 732 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl ClientConnect(int param_1,byte *param_2)

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
  lVar11 = SV_FilterPacket(pcVar3);
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
     ((InitClientResp(iVar6), DAT_1006ca58 == 0 || (*(int *)(*(int *)(param_1 + 0x54) + 0x714) == 0)
      ))) {
    InitClientPersistant(*(int *)(param_1 + 0x54));
  }
  ClientUserinfoChanged(param_1,pbVar2);
  if (1 < DAT_1006ca48) {
    (*DAT_1006c1c4)(s__s_connected_1005f434,*(int *)(param_1 + 0x54) + 700);
  }
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x2d0) = 1;
  return 1;
}



/* ClientDisconnect @ 10031c30 status existing size 185 */

void __cdecl ClientDisconnect(int param_1)

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



/* ClientThink @ 10031d70 status created size 1248 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ClientThink(int param_1,undefined4 *param_2)

{
  short *psVar1;
  byte bVar2;
  short sVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  undefined4 uVar8;
  int iVar9;
  short *psVar10;
  int *piVar11;
  byte *pbVar12;
  uint *puVar13;
  char *pcVar14;
  uint *puVar15;
  int *piVar16;
  bool bVar17;
  longlong lVar18;
  int iStack_f4;
  uint uStack_f0;
  short asStack_ec [12];
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  int iStack_c0;
  int aiStack_bc [32];
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int iStack_14;
  undefined4 uStack_10;
  int iStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  DAT_1006c404 = param_1;
  puVar4 = *(uint **)(param_1 + 0x54);
  pbVar12 = *(byte **)(param_1 + 0x118);
  pcVar14 = s_misc_actor_1004aed0;
  do {
    bVar2 = *pbVar12;
    bVar17 = bVar2 < (byte)*pcVar14;
    if (bVar2 != *pcVar14) {
LAB_10031dbd:
      iVar6 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
      goto LAB_10031dc2;
    }
    if (bVar2 == 0) break;
    bVar2 = pbVar12[1];
    bVar17 = bVar2 < (byte)pcVar14[1];
    if (bVar2 != pcVar14[1]) goto LAB_10031dbd;
    pbVar12 = pbVar12 + 2;
    pcVar14 = pcVar14 + 2;
  } while (bVar2 != 0);
  iVar6 = 0;
LAB_10031dc2:
  if (iVar6 == 0) {
    (*DAT_1006c1c4)(s_ClientThink___on_misc_actor_1005f4c8);
    return;
  }
  if (_DAT_1006c3a8 == _DAT_1004410c) {
    DAT_100620c4 = param_1;
    puVar13 = &uStack_f0;
    for (iVar6 = 0x3c; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar13 = 0;
      puVar13 = puVar13 + 1;
    }
    if (*(int *)(param_1 + 0x104) == 1) {
      *puVar4 = 1;
    }
    else if (*(int *)(param_1 + 0x28) == 0xff) {
      *puVar4 = -(uint)(*(int *)(param_1 + 0x22c) != 0) & 2;
    }
    else {
      *puVar4 = 3;
    }
    lVar18 = __ftol();
    *(short *)((int)puVar4 + 0x12) = (short)lVar18;
    puVar13 = puVar4;
    puVar15 = &uStack_f0;
    for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar15 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar15 = puVar15 + 1;
    }
    psVar10 = asStack_ec + 3;
    iStack_f4 = 3;
    do {
      lVar18 = __ftol();
      psVar10[-3] = (short)lVar18;
      lVar18 = __ftol();
      *psVar10 = (short)lVar18;
      psVar10 = psVar10 + 1;
      iStack_f4 = iStack_f4 + -1;
    } while (iStack_f4 != 0);
    iVar6 = 7;
    bVar17 = true;
    puVar13 = puVar4 + 0x36f;
    puVar15 = &uStack_f0;
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar17 = *puVar13 == *puVar15;
      puVar13 = puVar13 + 1;
      puVar15 = puVar15 + 1;
    } while (bVar17);
    if (!bVar17) {
      uStack_c4 = 1;
    }
    if ((code *)puVar4[0x3c4] != (code *)0x0) {
      (*(code *)puVar4[0x3c4])(param_1,param_2);
    }
    puStack_8 = &LAB_10031cf0;
    uStack_d4 = *param_2;
    uStack_d0 = param_2[1];
    uStack_cc = param_2[2];
    uStack_c8 = param_2[3];
    uStack_4 = DAT_1006c1f4;
    (*DAT_1006c214)(&uStack_f0);
    puVar13 = &uStack_f0;
    puVar15 = puVar4;
    for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar15 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar15 = puVar15 + 1;
    }
    puVar13 = &uStack_f0;
    puVar15 = puVar4 + 0x36f;
    for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar15 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar15 = puVar15 + 1;
    }
    psVar10 = asStack_ec + 3;
    iVar6 = 3;
    pfVar7 = (float *)(param_1 + 0x178);
    do {
      psVar1 = psVar10 + -3;
      sVar3 = *psVar10;
      psVar10 = psVar10 + 1;
      iVar6 = iVar6 + -1;
      pfVar7[-0x5d] = (float)(int)*psVar1 * (float)_DAT_10044260;
      *pfVar7 = (float)(int)sVar3 * (float)_DAT_10044260;
      pfVar7 = pfVar7 + 1;
    } while (iVar6 != 0);
    *(undefined4 *)(param_1 + 0xbc) = uStack_2c;
    *(undefined4 *)(param_1 + 0xc0) = uStack_28;
    *(undefined4 *)(param_1 + 0xc4) = uStack_24;
    *(undefined4 *)(param_1 + 200) = uStack_20;
    *(undefined4 *)(param_1 + 0xcc) = uStack_1c;
    *(undefined4 *)(param_1 + 0xd0) = uStack_18;
    puVar4[0x36b] = (uint)((float)(int)*(short *)((int)param_2 + 2) * (float)_DAT_10044280);
    puVar4[0x36c] = (uint)((float)(int)*(short *)(param_2 + 1) * (float)_DAT_10044280);
    puVar4[0x36d] = (uint)((float)(int)*(short *)((int)param_2 + 6) * (float)_DAT_10044280);
    if ((((*(int *)(param_1 + 0x268) != 0) && (iStack_14 == 0)) && (9 < (short)uStack_c8)) &&
       (iStack_c == 0)) {
      uVar8 = (*DAT_1006c1e4)(s__jump1_wav_1004b6c8,0x3f800000,0x3f800000,0);
      (*DAT_1006c1d0)(param_1,2,uVar8);
      PlayerNoise(param_1,(float *)(param_1 + 4),0);
    }
    lVar18 = __ftol();
    *(int *)(param_1 + 0x23c) = (int)lVar18;
    *(int *)(param_1 + 0x2a8) = iStack_c;
    *(undefined4 *)(param_1 + 0x2a4) = uStack_10;
    *(int *)(param_1 + 0x268) = iStack_14;
    if (iStack_14 != 0) {
      *(undefined4 *)(param_1 + 0x26c) = *(undefined4 *)(iStack_14 + 0x5c);
    }
    if (*(int *)(param_1 + 0x22c) == 0) {
      puVar4[0x399] = uStack_3c;
      puVar4[0x39a] = uStack_38;
      puVar4[0x39b] = uStack_34;
      puVar4[7] = uStack_3c;
      puVar4[8] = uStack_38;
      puVar4[9] = uStack_34;
    }
    else {
      puVar4[9] = 0x42200000;
      puVar4[7] = 0xc1700000;
      puVar4[8] = puVar4[0x387];
    }
    (*DAT_1006c208)(param_1);
    if (*(int *)(param_1 + 0x104) != 1) {
      G_TouchTriggers();
    }
    iVar6 = 0;
    if (0 < iStack_c0) {
      piVar16 = aiStack_bc;
      do {
        iVar5 = *piVar16;
        iVar9 = 0;
        if (0 < iVar6) {
          piVar11 = aiStack_bc;
          do {
            if (*piVar11 == iVar5) break;
            iVar9 = iVar9 + 1;
            piVar11 = piVar11 + 1;
          } while (iVar9 < iVar6);
        }
        if ((iVar9 == iVar6) && (*(code **)(iVar5 + 0x1fc) != (code *)0x0)) {
          (**(code **)(iVar5 + 0x1fc))(iVar5,param_1,0,0);
        }
        iVar6 = iVar6 + 1;
        piVar16 = piVar16 + 1;
      } while (iVar6 < iStack_c0);
    }
    puVar4[0x37c] = puVar4[0x37b];
    bVar2 = *(byte *)((int)param_2 + 1);
    puVar4[0x37b] = (uint)bVar2;
    puVar4[0x37d] = puVar4[0x37d] | ~puVar4[0x37c] & (uint)bVar2;
    *(uint *)(param_1 + 0x2c4) = (uint)*(byte *)((int)param_2 + 0xf);
    if (((puVar4[0x37d] & 1) != 0) && (puVar4[0x37e] == 0)) {
      puVar4[0x37e] = 1;
      Think_Weapon(param_1);
    }
    Oblivion_UpdateWeaponRegen(param_1);
  }
  else {
    *puVar4 = 4;
    if ((_DAT_1006c3a8 + (float)_DAT_10044150 < DAT_1006c2e4) &&
       ((*(byte *)((int)param_2 + 1) & 0x80) != 0)) {
      DAT_1006c3b0 = 1;
      return;
    }
  }
  return;
}



/* CopyToBodyQue @ 10030b40 status existing size 400 */

void __cdecl CopyToBodyQue(int *param_1)

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



/* respawn @ 10030cd0 status existing size 143 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl respawn(int *param_1)

{
  if ((*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) &&
     (*(float *)(DAT_1006c42c + 0x14) == _DAT_1004410c)) {
    (*DAT_1006c268)(s_menu_loadgame_1005f2f8);
    return;
  }
  if (param_1[0x41] != 1) {
    CopyToBodyQue(param_1);
  }
  param_1[0x2e] = param_1[0x2e] & 0xfffffffe;
  PutClientInServer((int)param_1);
  param_1[0x14] = 6;
  *(undefined1 *)(param_1[0x15] + 0x10) = 0x20;
  *(undefined1 *)(param_1[0x15] + 0x11) = 0xe;
  *(undefined4 *)(param_1[0x15] + 0xf00) = DAT_1006c2e4;
  return;
}



/* spectator_respawn @ 10030d60 status existing size 774 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl spectator_respawn(int param_1)

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
      PutClientInServer(iVar2);
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



/* DeathmatchScoreboardMessage @ 100327c0 status existing size 764 */

void __cdecl DeathmatchScoreboardMessage(int param_1,int param_2)

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



/* DeathmatchScoreboard @ 10032ac0 status existing size 32 */

void __cdecl DeathmatchScoreboard(int param_1)

{
  DeathmatchScoreboardMessage(param_1,*(int *)(param_1 + 0x25c));
  (*DAT_1006c21c)(param_1,1);
  return;
}



/* Cmd_Score_f @ 10032ae0 status existing size 106 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Cmd_Score_f(int param_1)

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
    DeathmatchScoreboard(param_1);
  }
  return;
}



/* HelpComputer @ 10032b50 status existing size 194 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl HelpComputer(undefined4 param_1)

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



/* G_SetStats @ 10032ca0 status existing size 1142 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl G_SetStats(int param_1)

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
  bVar2 = PowerArmorType(param_1);
  iVar8 = CONCAT31(extraout_var,bVar2);
  iVar7 = param_1;
  if (iVar8 != 0) {
    puVar4 = FindItem((byte *)s_cells_10049004);
    iVar7 = *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar4 + -0x4011a4a) / 0x48) * 4);
    if (iVar7 == 0) {
      *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) & 0xffffefff;
      uVar5 = (*DAT_1006c1e4)(s_misc_power2_wav_1004900c,0x3f800000,0x3f800000,0);
      (*DAT_1006c1d0)(param_1,3,uVar5);
      iVar8 = 0;
    }
  }
  uVar6 = ArmorIndex(param_1);
  if ((iVar8 == 0) || ((uVar6 != 0 && ((DAT_1006c2e0 & 8) == 0)))) {
    if (uVar6 == 0) {
      *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x80) = 0;
      *(undefined2 *)(*(int *)(param_1 + 0x54) + 0x82) = 0;
    }
    else {
      puVar4 = GetItemByIndex(uVar6);
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



/* Cmd_Help_f @ 10032c20 status existing size 128 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Cmd_Help_f(int param_1)

{
  int iVar1;
  
  if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
    Cmd_Score_f(param_1);
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
  HelpComputer(param_1);
  return;
}



/* ClientBeginServerFrame @ 10032250 status existing size 342 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl ClientBeginServerFrame(int *param_1)

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
      spectator_respawn((int)param_1);
      return;
    }
    if ((*(int *)(iVar1 + 0xdf8) == 0) && (*(int *)(iVar1 + 0xdb8) == 0)) {
      Think_Weapon((int)param_1);
    }
    else {
      *(undefined4 *)(iVar1 + 0xdf8) = 0;
    }
    if (param_1[0x8b] == 0) {
      if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
        iVar3 = PlayerTrail_LastSpot();
        iVar3 = visible((int)param_1,iVar3);
        if (iVar3 == 0) {
          PlayerTrail_Add((float *)(param_1 + 7));
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
        respawn(param_1);
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



/* MoveClientToIntermission @ 100323b0 status existing size 374 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl MoveClientToIntermission(int param_1)

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
    DeathmatchScoreboardMessage(param_1,0);
    (*DAT_1006c21c)(param_1,1);
  }
  return;
}



/* BeginIntermission @ 10032530 status existing size 641 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl BeginIntermission(int param_1)

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
          respawn((int *)(iVar7 + DAT_1006c2c4));
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
    uVar4 = G_Find(0,0x118,(byte *)s_info_player_intermission_1004b23c);
    if (uVar4 == 0) {
      uVar4 = G_Find(0,0x118,(byte *)s_info_player_start_1004b284);
      if (uVar4 == 0) {
        uVar4 = G_Find(0,0x118,(byte *)s_info_player_deathmatch_1004b26c);
      }
    }
    else {
      uVar5 = _rand();
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        uVar4 = G_Find(uVar4,0x118,(byte *)s_info_player_intermission_1004b23c);
        if (uVar4 == 0) {
          uVar4 = G_Find(0,0x118,(byte *)s_info_player_intermission_1004b23c);
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
          MoveClientToIntermission(DAT_1006c2c4 + iVar7);
        }
        iVar8 = iVar8 + 1;
        iVar7 = iVar7 + 0x3d0;
      } while ((float)iVar8 < *(float *)(DAT_1006ca60 + 0x14));
    }
  }
  return;
}



/* PlayerTrail_Init @ 10033120 status existing size 77 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PlayerTrail_Init(void)

{
  int *piVar1;
  undefined4 *puVar2;
  
  if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
    puVar2 = &DAT_100620a0;
    do {
      piVar1 = G_Spawn();
      *puVar2 = piVar1;
      puVar2 = puVar2 + 1;
      piVar1[0x46] = (int)s_player_trail_1005f630;
    } while ((int)puVar2 < 0x100620c0);
    DAT_100620c0 = 0;
    DAT_1006138c = 1;
  }
  return;
}



/* PlayerTrail_Add @ 10033170 status existing size 193 */

void __cdecl PlayerTrail_Add(float *param_1)

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
    fVar2 = vectoyaw(&local_c);
    *(float *)((&DAT_100620a0)[DAT_100620c0] + 0x14) = (float)fVar2;
    DAT_100620c0 = DAT_100620c0 + 1 & 7;
  }
  return;
}



/* PlayerTrail_LastSpot @ 10033320 status existing size 17 */

undefined4 PlayerTrail_LastSpot(void)

{
  return (&DAT_100620a0)[DAT_100620c0 - 1U & 7];
}



/* SV_CalcRoll @ 10033340 status existing size 127 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl SV_CalcRoll(undefined4 param_1,float *param_2)

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



/* P_DamageFeedback @ 100333c0 status existing size 1110 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl P_DamageFeedback(float param_1)

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
      VectorMA(&fStack_c,(float)*(int *)(iVar2 + 0xe04) / fVar1,(float *)&DAT_1005f640,&fStack_c);
    }
    if (*(int *)(iVar2 + 0xe00) != 0) {
      VectorMA(&fStack_c,(float)*(int *)(iVar2 + 0xe00) / fVar1,(float *)&DAT_1005f64c,&fStack_c);
    }
    if (*(int *)(iVar2 + 0xe08) != 0) {
      VectorMA(&fStack_c,(float)*(int *)(iVar2 + 0xe08) / fVar1,(float *)&DAT_1005f658,&fStack_c);
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
      VectorNormalize(&fStack_c);
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



/* SV_CalcViewOffset @ 10033820 status existing size 752 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SV_CalcViewOffset(int param_1)

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



/* SV_CalcGunOffset @ 10033b10 status existing size 374 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SV_CalcGunOffset(int param_1)

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



/* SV_CalcBlend @ 10033d00 status existing size 1027 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SV_CalcBlend(int param_1)

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



/* P_FallingDamage @ 10034110 status existing size 505 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl P_FallingDamage(uint param_1)

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



/* P_WorldEffects @ 10034310 status existing size 1554 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void P_WorldEffects(void)

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
    PlayerNoise(DAT_10061394,(float *)(DAT_10061394 + 4),0);
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
      PlayerNoise(DAT_10061394,(float *)(DAT_10061394 + 4),0);
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
        PlayerNoise(DAT_10061394,(float *)(DAT_10061394 + 4),0);
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
      PlayerNoise(DAT_10061394,(float *)(DAT_10061394 + 4),0);
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



/* G_SetClientEffects @ 10034930 status existing size 262 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl G_SetClientEffects(int param_1)

{
  int iVar1;
  bool bVar2;
  undefined3 extraout_var;
  ulonglong uVar3;
  
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  if ((0 < *(int *)(param_1 + 0x220)) && (_DAT_1006c3a8 == _DAT_1004410c)) {
    if (DAT_1006c2e4 < *(float *)(param_1 + 0x234)) {
      bVar2 = PowerArmorType(param_1);
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



/* G_SetClientEvent @ 10034a40 status existing size 80 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl G_SetClientEvent(int param_1)

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



/* G_SetClientSound @ 10034a90 status existing size 350 */

void __cdecl G_SetClientSound(int param_1)

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



/* G_SetClientFrame @ 10034bf0 status existing size 390 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl G_SetClientFrame(int param_1)

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



/* PlayerNoise @ 100350a0 status existing size 442 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl PlayerNoise(int param_1,float *param_2,int param_3)

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
      piVar1 = G_Spawn();
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
      piVar1 = G_Spawn();
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



/* ChangeWeapon @ 10035420 status existing size 271 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl ChangeWeapon(int param_1)

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
    puVar3 = FindItem(pbVar2);
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



/* Pickup_Weapon @ 10035260 status existing size 443 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong __cdecl Pickup_Weapon(int param_1,int param_2)

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
    puVar2 = FindItem(*(byte **)(*(int *)(param_1 + 0x2cc) + 0x34));
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
    Add_Ammo(param_2,(int)puVar2,iVar5);
    uVar3 = extraout_EDX;
    if ((*(uint *)(param_1 + 0x11c) & 0x20000) == 0) {
      if (*(float *)(DAT_1006c118 + 0x14) != _DAT_1004410c) {
        uVar4 = __ftol();
        uVar3 = (uint)(uVar4 >> 0x20);
        if ((uVar4 & 4) == 0) {
          SetRespawn(param_1,30.0);
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
      puVar2 = FindItem((byte *)s_Plasma_Pistol_10048cb0);
      uVar3 = extraout_EDX_01;
      if (*(undefined4 **)(iVar5 + 0x714) != puVar2) goto LAB_10035411;
    }
    *(undefined4 *)(iVar5 + 0xdfc) = *(undefined4 *)(param_1 + 0x2cc);
  }
LAB_10035411:
  return CONCAT44(uVar3,1);
}



/* NoAmmoWeaponChange @ 10035530 status existing size 756 */

void __cdecl NoAmmoWeaponChange(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  char *pcVar3;
  
  iVar1 = FUN_10038b20((void *)**(undefined4 **)(*(int *)(param_1 + 0x54) + 0x714),
                       (byte *)s_weapon_plasma_rifle_100481ac);
  if (iVar1 != 0) {
    puVar2 = FindItem((byte *)s_slugs_1005f93c);
    if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0) {
      puVar2 = FindItem((byte *)s_railgun_1005f934);
      if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0)
      {
        pcVar3 = s_railgun_1005f934;
        goto LAB_100357f9;
      }
    }
    puVar2 = FindItem((byte *)s_cells_10049004);
    if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0) {
      puVar2 = FindItem((byte *)s_hyperblaster_1005f924);
      if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0)
      {
        pcVar3 = s_hyperblaster_1005f924;
        goto LAB_100357f9;
      }
    }
    puVar2 = FindItem((byte *)s_bullets_1005f91c);
    if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0) {
      puVar2 = FindItem((byte *)s_chaingun_1005f910);
      if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0)
      {
        pcVar3 = s_chaingun_1005f910;
        goto LAB_100357f9;
      }
    }
    puVar2 = FindItem((byte *)s_bullets_1005f91c);
    if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0) {
      puVar2 = FindItem((byte *)s_machinegun_1005f904);
      if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0)
      {
        pcVar3 = s_machinegun_1005f904;
        goto LAB_100357f9;
      }
    }
    puVar2 = FindItem((byte *)s_shells_1005f8fc);
    if (1 < *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4)) {
      puVar2 = FindItem((byte *)s_super_shotgun_1005f8ec);
      if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0)
      {
        pcVar3 = s_super_shotgun_1005f8ec;
        goto LAB_100357f9;
      }
    }
    puVar2 = FindItem((byte *)s_shells_1005f8fc);
    if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0) {
      puVar2 = FindItem((byte *)s_shotgun_1005f8e4);
      if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4) != 0)
      {
        pcVar3 = s_shotgun_1005f8e4;
LAB_100357f9:
        puVar2 = FindItem((byte *)pcVar3);
        *(undefined4 **)(*(int *)(param_1 + 0x54) + 0xdfc) = puVar2;
        return;
      }
    }
    puVar2 = FindItem((byte *)s_Plasma_Pistol_10048cb0);
    *(undefined4 **)(*(int *)(param_1 + 0x54) + 0xdfc) = puVar2;
  }
  return;
}



/* Think_Weapon @ 10035830 status existing size 138 */

void __cdecl Think_Weapon(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x220) < 1) {
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xdfc) = 0;
    ChangeWeapon(param_1);
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0x714);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x10) != 0)) {
    DAT_100613c0 = (uint)((float)DAT_1006c2e0 < *(float *)(*(int *)(param_1 + 0x54) + 0xeac));
    DAT_100613c4._0_1_ = -(*(int *)(*(int *)(param_1 + 0x54) + 0xec4) != 0) & 0x80;
    (**(code **)(*(int *)(*(int *)(param_1 + 0x54) + 0x714) + 0x10))(param_1);
  }
  return;
}



/* Use_Weapon @ 100358c0 status created size 187 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Use_Weapon(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x54);
  if (param_2 != *(int *)(iVar3 + 0x714)) {
    if (((*(byte **)(param_2 + 0x34) != (byte *)0x0) &&
        (*(float *)(DAT_1006c110 + 0x14) == _DAT_1004410c)) &&
       ((*(byte *)(param_2 + 0x38) & 2) == 0)) {
      puVar2 = FindItem(*(byte **)(param_2 + 0x34));
      iVar3 = *(int *)(param_1 + 0x54);
      iVar1 = *(int *)(iVar3 + 0x2e4 + ((int)(puVar2 + -0x4011a4a) / 0x48) * 4);
      if (iVar1 == 0) {
        (*DAT_1006c1c8)(param_1,2,s_No__s_for__s__1005f95c,puVar2[10],
                        *(undefined4 *)(param_2 + 0x28));
        return;
      }
      if (iVar1 < *(int *)(param_2 + 0x30)) {
        (*DAT_1006c1c8)(param_1,2,s_Not_enough__s_for__s__1005f944,puVar2[10],
                        *(undefined4 *)(param_2 + 0x28));
        return;
      }
    }
    *(int *)(iVar3 + 0xdfc) = param_2;
  }
  return;
}



/* Drop_Weapon @ 10035980 status created size 141 */

void Drop_Weapon(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = __ftol();
  if ((uVar3 & 4) == 0) {
    iVar1 = *(int *)(param_1 + 0x54);
    iVar2 = (int)(param_2 + -0x4011a4a) / 0x48;
    if (((param_2 == *(int **)(iVar1 + 0x714)) || (param_2 == *(int **)(iVar1 + 0xdfc))) &&
       (*(int *)(iVar1 + 0x2e4 + iVar2 * 4) == 1)) {
      (*DAT_1006c1c8)(param_1,2,s_Can_t_drop_current_weapon_10048f6c);
      return;
    }
    Drop_Item(param_1,param_2);
    *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + iVar2 * 4) =
         *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + iVar2 * 4) + -1;
  }
  return;
}



/* Weapon_Generic @ 10035a10 status existing size 644 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
Weapon_Generic(int param_1,int param_2,int param_3,int param_4,int param_5,int *param_6,int *param_7
              ,undefined *param_8)

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
      ChangeWeapon(param_1);
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
          NoAmmoWeaponChange(param_1);
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



/* weapon_grenade_fire @ 10035ca0 status existing size 269 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl weapon_grenade_fire(int param_1,int param_2)

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
  AngleVectors((float *)(*(int *)(param_1 + 0x54) + 0xe64),local_24,local_18,(float *)0x0);
  P_ProjectSource(*(int *)(param_1 + 0x54),(float *)(param_1 + 4),local_30,local_24,local_18,local_c
                 );
  iVar6 = 0x43250000;
  fVar5 = *(float *)(*(int *)(param_1 + 0x54) + 0xec0) - DAT_1006c2e4;
  lVar3 = __ftol();
  fire_grenade2(param_1,(int *)local_c,local_24,iVar2,(int)lVar3,fVar5,iVar6,param_2);
  uVar4 = __ftol();
  if ((uVar4 & 0x2000) == 0) {
    piVar1 = (int *)(*(int *)(param_1 + 0x54) + 0x2e4 +
                    *(int *)(*(int *)(param_1 + 0x54) + 0xde8) * 4);
    *piVar1 = *piVar1 + -1;
  }
  *(float *)(*(int *)(param_1 + 0x54) + 0xec0) = DAT_1006c2e4 + (float)_DAT_10044120;
  return;
}



/* P_ProjectSource @ 10035db0 status existing size 105 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
P_ProjectSource(int param_1,float *param_2,float *param_3,float *param_4,float *param_5,
               float *param_6)

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



/* Weapon_Grenade @ 10035e20 status existing size 642 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Weapon_Grenade(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0x54);
  if ((*(int *)(iVar1 + 0xdfc) != 0) && (*(int *)(iVar1 + 0xe20) == 0)) {
    ChangeWeapon(param_1);
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
        NoAmmoWeaponChange(param_1);
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
        weapon_grenade_fire(param_1,1);
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
      weapon_grenade_fire(param_1,0);
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



/* weapon_grenadelauncher_fire @ 100360b0 status created size 347 */

void weapon_grenadelauncher_fire(int param_1)

{
  int iVar1;
  ulonglong uVar2;
  float afStack_30 [3];
  float afStack_24 [3];
  float afStack_18 [3];
  float afStack_c [3];
  
  iVar1 = 0x78;
  if (DAT_100613c0 != 0) {
    iVar1 = 0x1e0;
  }
  afStack_30[2] = (float)(*(int *)(param_1 + 0x23c) + -8);
  afStack_30[0] = 8.0;
  afStack_30[1] = 8.0;
  AngleVectors((float *)(*(int *)(param_1 + 0x54) + 0xe64),afStack_24,afStack_c,(float *)0x0);
  P_ProjectSource(*(int *)(param_1 + 0x54),(float *)(param_1 + 4),afStack_30,afStack_24,afStack_c,
                  afStack_18);
  VectorScale(afStack_24,-2.0,(float *)(*(int *)(param_1 + 0x54) + 0xe30));
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe24) = 0xbf800000;
  FUN_1001c2f0(param_1,(int *)afStack_18,afStack_24,iVar1,600,2.5,0x43200000);
  (*DAT_1006c224)(1);
  (*DAT_1006c228)((param_1 - DAT_1006c2c4) / 0x3d0);
  (*DAT_1006c224)(DAT_100613c4 & 0xff | 8);
  (*DAT_1006c218)((float *)(param_1 + 4),2);
  *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = *(int *)(*(int *)(param_1 + 0x54) + 0x5c) + 1;
  PlayerNoise(param_1,afStack_18,1);
  uVar2 = __ftol();
  if ((uVar2 & 0x2000) == 0) {
    iVar1 = *(int *)(param_1 + 0x54);
    *(int *)(iVar1 + 0x2e4 + *(int *)(iVar1 + 0xde8) * 4) =
         *(int *)(iVar1 + 0x2e4 + *(int *)(iVar1 + 0xde8) * 4) + -1;
  }
  return;
}



/* Weapon_GrenadeLauncher @ 10036210 status created size 37 */

void Weapon_GrenadeLauncher(int param_1)

{
  Weapon_Generic(param_1,5,0x10,0x3b,0x40,(int *)&DAT_1005f700,(int *)&DAT_1005f710,
                 weapon_grenadelauncher_fire);
  return;
}



/* Weapon_RocketLauncher_Fire @ 10036240 status created size 391 */

void Weapon_RocketLauncher_Fire(int param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  float afStack_30 [3];
  float afStack_24 [3];
  float afStack_18 [3];
  float afStack_c [3];
  
  _rand();
  lVar3 = __ftol();
  iVar2 = 0x78;
  iVar1 = 100 - (int)lVar3;
  if (DAT_100613c0 != 0) {
    iVar1 = iVar1 * 4;
    iVar2 = 0x1e0;
  }
  AngleVectors((float *)(*(int *)(param_1 + 0x54) + 0xe64),afStack_24,afStack_c,(float *)0x0);
  VectorScale(afStack_24,-2.0,(float *)(*(int *)(param_1 + 0x54) + 0xe30));
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe24) = 0xbf800000;
  afStack_30[2] = (float)(*(int *)(param_1 + 0x23c) + -8);
  afStack_30[0] = 8.0;
  afStack_30[1] = 8.0;
  P_ProjectSource(*(int *)(param_1 + 0x54),(float *)(param_1 + 4),afStack_30,afStack_24,afStack_c,
                  afStack_18);
  fire_rocket(param_1,afStack_18,afStack_24,iVar1,0x28a,0x42f00000,iVar2);
  (*DAT_1006c224)(1);
  (*DAT_1006c228)((param_1 - DAT_1006c2c4) / 0x3d0);
  (*DAT_1006c224)(DAT_100613c4 & 0xff | 7);
  (*DAT_1006c218)((float *)(param_1 + 4),2);
  *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = *(int *)(*(int *)(param_1 + 0x54) + 0x5c) + 1;
  PlayerNoise(param_1,afStack_18,1);
  uVar4 = __ftol();
  if ((uVar4 & 0x2000) == 0) {
    iVar1 = *(int *)(param_1 + 0x54);
    *(int *)(iVar1 + 0x2e4 + *(int *)(iVar1 + 0xde8) * 4) =
         *(int *)(iVar1 + 0x2e4 + *(int *)(iVar1 + 0xde8) * 4) + -1;
  }
  return;
}



/* Weapon_RocketLauncher @ 100363d0 status created size 37 */

void Weapon_RocketLauncher(int param_1)

{
  Weapon_Generic(param_1,4,0xc,0x32,0x36,(int *)&DAT_1005f718,(int *)&DAT_1005f72c,
                 Weapon_RocketLauncher_Fire);
  return;
}



/* Blaster_Fire @ 10036400 status existing size 348 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Blaster_Fire(int param_1,float *param_2,int param_3,int param_4,uint param_5)

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
  AngleVectors((float *)(*(int *)(param_1 + 0x54) + 0xe64),local_24,local_c,(float *)0x0);
  local_30 = *param_2 + _DAT_100443d8;
  local_2c = param_2[1] + _DAT_10044164;
  local_28 = (float)(*(int *)(param_1 + 0x23c) + -8) + param_2[2];
  P_ProjectSource(*(int *)(param_1 + 0x54),(float *)(param_1 + 4),&local_30,local_24,local_c,
                  local_18);
  VectorScale(local_24,-2.0,(float *)(*(int *)(param_1 + 0x54) + 0xe30));
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe24) = 0xbf800000;
  fire_blaster(param_1,local_18,local_24,param_3,1000,param_5,param_4);
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
  PlayerNoise(param_1,local_18,1);
  return;
}



/* Weapon_Blaster_Fire @ 10036560 status created size 67 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Weapon_Blaster_Fire(int param_1)

{
  int iVar1;
  
  iVar1 = 0xf;
  if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
    iVar1 = 10;
  }
  Blaster_Fire(param_1,(float *)&DAT_10061c18,iVar1,0,8);
  *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = *(int *)(*(int *)(param_1 + 0x54) + 0x5c) + 1;
  return;
}



/* Weapon_Blaster @ 100365b0 status created size 37 */

void Weapon_Blaster(int param_1)

{
  Weapon_Generic(param_1,4,8,0x34,0x37,(int *)0x1005f734,(int *)0x1005f740,Weapon_Blaster_Fire);
  return;
}



/* Weapon_HyperBlaster_Fire @ 100365e0 status created size 430 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Weapon_HyperBlaster_Fire(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  float10 fVar5;
  float10 fVar6;
  ulonglong uVar7;
  float afStack_c [3];
  
  uVar2 = (*DAT_1006c1e4)(s_weapons_hyprbl1a_wav_1005f9b0);
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xec8) = uVar2;
  iVar3 = *(int *)(param_1 + 0x54);
  if ((*(byte *)(iVar3 + 0xdec) & 1) == 0) {
    *(int *)(iVar3 + 0x5c) = *(int *)(iVar3 + 0x5c) + 1;
  }
  else {
    if (*(int *)(iVar3 + 0x2e4 + *(int *)(iVar3 + 0xde8) * 4) == 0) {
      if (*(float *)(param_1 + 0x210) <= DAT_1006c2e4) {
        uVar2 = (*DAT_1006c1e4)(s_weapons_noammo_wav_1004b5c8,0x3f800000,0x3f800000,0);
        (*DAT_1006c1d0)(param_1,2,uVar2);
        *(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_10044104;
      }
      NoAmmoWeaponChange(param_1);
    }
    else {
      afStack_c[1] = 0.0;
      fVar5 = (float10)(*(int *)(iVar3 + 0x5c) * 2 + -10) * (float10)_DAT_10044468;
      fVar6 = (float10)fsin(fVar5);
      afStack_c[0] = (float)(fVar6 * (float10)_DAT_10044460);
      fVar5 = (float10)fcos(fVar5);
      afStack_c[2] = (float)(fVar5 * (float10)_DAT_100443c0);
      if ((*(int *)(iVar3 + 0x5c) == 6) || (*(int *)(iVar3 + 0x5c) == 9)) {
        uVar4 = 0x40;
      }
      else {
        uVar4 = 0;
      }
      iVar3 = 0xf;
      if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
        iVar3 = 0x14;
      }
      Blaster_Fire(param_1,afStack_c,iVar3,1,uVar4);
      uVar7 = __ftol();
      if ((uVar7 & 0x2000) == 0) {
        piVar1 = (int *)(*(int *)(param_1 + 0x54) + 0x2e4 +
                        *(int *)(*(int *)(param_1 + 0x54) + 0xde8) * 4);
        *piVar1 = *piVar1 + -1;
      }
    }
    *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = *(int *)(*(int *)(param_1 + 0x54) + 0x5c) + 1;
    iVar3 = *(int *)(param_1 + 0x54);
    if ((*(int *)(iVar3 + 0x5c) == 0xc) &&
       (*(int *)(iVar3 + 0x2e4 + *(int *)(iVar3 + 0xde8) * 4) != 0)) {
      *(undefined4 *)(iVar3 + 0x5c) = 6;
    }
  }
  if (*(int *)(*(int *)(param_1 + 0x54) + 0x5c) == 0xc) {
    uVar2 = (*DAT_1006c1e4)(s_weapons_hyprbd1a_wav_1005f998,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_1,0,uVar2);
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xec8) = 0;
  }
  return;
}



/* Weapon_HyperBlaster @ 10036790 status created size 37 */

void Weapon_HyperBlaster(int param_1)

{
  Weapon_Generic(param_1,5,0x14,0x31,0x35,(int *)&DAT_100613c8,(int *)&DAT_1005f748,
                 Weapon_HyperBlaster_Fire);
  return;
}



/* Machinegun_Fire @ 100367c0 status created size 765 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Machinegun_Fire(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ulonglong uVar8;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float afStack_30 [3];
  float afStack_24 [3];
  float afStack_18 [3];
  float afStack_c [3];
  
  iVar5 = 8;
  iVar6 = *(int *)(param_1 + 0x54);
  iVar4 = 2;
  if ((*(byte *)(iVar6 + 0xdec) & 1) == 0) {
    *(undefined4 *)(iVar6 + 0xe98) = 0;
    *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = *(int *)(*(int *)(param_1 + 0x54) + 0x5c) + 1;
    return;
  }
  *(uint *)(iVar6 + 0x5c) = (*(int *)(iVar6 + 0x5c) != 5) + 4;
  iVar6 = *(int *)(param_1 + 0x54);
  if (*(int *)(iVar6 + 0x2e4 + *(int *)(iVar6 + 0xde8) * 4) < 1) {
    *(undefined4 *)(iVar6 + 0x5c) = 6;
    if (*(float *)(param_1 + 0x210) <= DAT_1006c2e4) {
      uVar2 = (*DAT_1006c1e4)(s_weapons_noammo_wav_1004b5c8,0x3f800000,0x3f800000,0);
      (*DAT_1006c1d0)(param_1,2,uVar2);
      *(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_10044104;
    }
    NoAmmoWeaponChange(param_1);
    return;
  }
  if (DAT_100613c0 != 0) {
    iVar5 = 0x20;
    iVar4 = 8;
  }
  iVar6 = 0xe28;
  do {
    uVar3 = _rand();
    fVar1 = (float)(uVar3 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
    *(float *)(iVar6 + 0xc + *(int *)(param_1 + 0x54)) = (fVar1 + fVar1) * (float)_DAT_10044358;
    uVar3 = _rand();
    iVar7 = iVar6 + 4;
    fVar1 = (float)(uVar3 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
    *(float *)(iVar6 + *(int *)(param_1 + 0x54)) = (fVar1 + fVar1) * (float)_DAT_10044228;
    iVar6 = iVar7;
  } while (iVar7 < 0xe30);
  uVar3 = _rand();
  fVar1 = (float)(uVar3 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  *(float *)(*(int *)(param_1 + 0x54) + 0xe30) = (fVar1 + fVar1) * (float)_DAT_10044358;
  *(float *)(*(int *)(param_1 + 0x54) + 0xe24) =
       (float)*(int *)(*(int *)(param_1 + 0x54) + 0xe98) * (float)_DAT_10044470;
  if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
    *(int *)(*(int *)(param_1 + 0x54) + 0xe98) = *(int *)(*(int *)(param_1 + 0x54) + 0xe98) + 1;
    if (9 < *(int *)(*(int *)(param_1 + 0x54) + 0xe98)) {
      *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe98) = 9;
    }
  }
  iVar6 = *(int *)(param_1 + 0x54);
  fStack_3c = *(float *)(iVar6 + 0xe64) + *(float *)(iVar6 + 0xe24);
  fStack_38 = *(float *)(iVar6 + 0xe68) + *(float *)(iVar6 + 0xe28);
  fStack_34 = *(float *)(iVar6 + 0xe6c) + *(float *)(iVar6 + 0xe2c);
  AngleVectors(&fStack_3c,afStack_24,afStack_c,(float *)0x0);
  afStack_30[2] = (float)(*(int *)(param_1 + 0x23c) + -8);
  afStack_30[0] = 0.0;
  afStack_30[1] = 8.0;
  P_ProjectSource(*(int *)(param_1 + 0x54),(float *)(param_1 + 4),afStack_30,afStack_24,afStack_c,
                  afStack_18);
  FUN_1001b880(param_1,afStack_18,afStack_24,iVar5,iVar4,300,500,4);
  (*DAT_1006c224)(1);
  (*DAT_1006c228)((param_1 - DAT_1006c2c4) / 0x3d0);
  (*DAT_1006c224)(DAT_100613c4 & 0xff | 1);
  (*DAT_1006c218)((float *)(param_1 + 4),2);
  PlayerNoise(param_1,afStack_18,1);
  uVar8 = __ftol();
  if ((uVar8 & 0x2000) == 0) {
    iVar6 = *(int *)(param_1 + 0x54);
    *(int *)(iVar6 + 0x2e4 + *(int *)(iVar6 + 0xde8) * 4) =
         *(int *)(iVar6 + 0x2e4 + *(int *)(iVar6 + 0xde8) * 4) + -1;
  }
  return;
}



/* Weapon_Machinegun @ 10036ac0 status created size 37 */

void Weapon_Machinegun(int param_1)

{
  Weapon_Generic(param_1,3,5,0x2d,0x31,(int *)&DAT_1005f764,(int *)&DAT_1005f770,Machinegun_Fire);
  return;
}



/* Chaingun_Fire @ 10036af0 status created size 953 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Chaingun_Fire(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ulonglong uVar10;
  int iStack_48;
  int iStack_44;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float afStack_30 [3];
  float afStack_24 [3];
  float afStack_18 [3];
  float afStack_c [3];
  
  iStack_44 = 2;
  iStack_48 = 6;
  if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
    iStack_48 = 8;
  }
  if (*(int *)(*(int *)(param_1 + 0x54) + 0x5c) == 5) {
    uVar5 = (*DAT_1006c1e4)(s_weapons_chngnu1a_wav_1005f9f8,0x3f800000,0x40000000,0);
    (*DAT_1006c1d0)(param_1,0,uVar5);
  }
  iVar9 = *(int *)(param_1 + 0x54);
  iVar7 = *(int *)(iVar9 + 0x5c);
  if ((iVar7 == 0xe) && ((*(byte *)(iVar9 + 0xdec) & 1) == 0)) {
    *(undefined4 *)(iVar9 + 0x5c) = 0x20;
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xec8) = 0;
    return;
  }
  if ((iVar7 == 0x15) &&
     (((*(byte *)(iVar9 + 0xdec) & 1) != 0 &&
      (*(int *)(iVar9 + 0x2e4 + *(int *)(iVar9 + 0xde8) * 4) != 0)))) {
    *(undefined4 *)(iVar9 + 0x5c) = 0xf;
  }
  else {
    *(int *)(iVar9 + 0x5c) = iVar7 + 1;
  }
  if (*(int *)(*(int *)(param_1 + 0x54) + 0x5c) == 0x16) {
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xec8) = 0;
    uVar5 = (*DAT_1006c1e4)(s_weapons_chngnd1a_wav_1005f9e0,0x3f800000,0x40000000,0);
    (*DAT_1006c1d0)(param_1,0,uVar5);
  }
  else {
    uVar5 = (*DAT_1006c1e4)(s_weapons_chngnl1a_wav_1005f9c8);
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xec8) = uVar5;
  }
  iVar9 = *(int *)(param_1 + 0x54);
  if (*(int *)(iVar9 + 0x5c) < 10) {
    iVar7 = 1;
  }
  else if (*(int *)(iVar9 + 0x5c) < 0xf) {
    iVar7 = ((*(uint *)(iVar9 + 0xdec) & 1) != 0) + 1;
  }
  else {
    iVar7 = 3;
  }
  iVar9 = *(int *)(iVar9 + 0x2e4 + *(int *)(iVar9 + 0xde8) * 4);
  if (iVar9 < iVar7) {
    iVar7 = iVar9;
  }
  if (iVar7 == 0) {
    if (*(float *)(param_1 + 0x210) <= DAT_1006c2e4) {
      uVar5 = (*DAT_1006c1e4)(s_weapons_noammo_wav_1004b5c8,0x3f800000,0x3f800000,0);
      (*DAT_1006c1d0)(param_1,2,uVar5);
      *(float *)(param_1 + 0x210) = DAT_1006c2e4 + _DAT_10044104;
    }
    NoAmmoWeaponChange(param_1);
    return;
  }
  if (DAT_100613c0 != 0) {
    iStack_44 = 8;
    iStack_48 = iStack_48 * 4;
  }
  iVar9 = 0xe24;
  do {
    uVar6 = _rand();
    fVar1 = (float)(uVar6 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
    *(float *)(iVar9 + 0xc + *(int *)(param_1 + 0x54)) = (fVar1 + fVar1) * (float)_DAT_10044358;
    uVar6 = _rand();
    iVar8 = iVar9 + 4;
    fVar1 = (float)(uVar6 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
    *(float *)(iVar9 + *(int *)(param_1 + 0x54)) = (fVar1 + fVar1) * (float)_DAT_10044228;
    iVar9 = iVar8;
  } while (iVar8 < 0xe30);
  if (0 < iVar7) {
    iVar9 = iVar7;
    do {
      AngleVectors((float *)(*(int *)(param_1 + 0x54) + 0xe64),afStack_30,afStack_18,afStack_c);
      uVar6 = _rand();
      fVar1 = (float)(uVar6 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
      fVar3 = (float)_DAT_100443c0;
      fVar2 = (float)_DAT_10044478;
      uVar6 = _rand();
      fVar4 = (float)(uVar6 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
      fStack_3c = 0.0;
      fStack_34 = ((float)*(int *)(param_1 + 0x23c) + (fVar4 + fVar4) * (float)_DAT_100443c0) -
                  _DAT_10044164;
      fStack_38 = (fVar1 + fVar1) * fVar3 + fVar2;
      P_ProjectSource(*(int *)(param_1 + 0x54),(float *)(param_1 + 4),&fStack_3c,afStack_30,
                      afStack_18,afStack_24);
      FUN_1001b880(param_1,afStack_24,afStack_30,iStack_48,iStack_44,300,500,5);
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  (*DAT_1006c224)(1);
  (*DAT_1006c228)((param_1 - DAT_1006c2c4) / 0x3d0);
  (*DAT_1006c224)(iVar7 + 2U | DAT_100613c4 & 0xff);
  (*DAT_1006c218)(param_1 + 4,2);
  PlayerNoise(param_1,afStack_24,1);
  uVar10 = __ftol();
  if ((uVar10 & 0x2000) == 0) {
    iVar9 = *(int *)(param_1 + 0x54);
    *(int *)(iVar9 + 0x2e4 + *(int *)(iVar9 + 0xde8) * 4) =
         *(int *)(iVar9 + 0x2e4 + *(int *)(iVar9 + 0xde8) * 4) - iVar7;
  }
  return;
}



/* Weapon_Chaingun @ 10036eb0 status created size 37 */

void Weapon_Chaingun(int param_1)

{
  Weapon_Generic(param_1,4,0x1f,0x3d,0x40,(int *)&DAT_1005f77c,(int *)&DAT_1005f790,Chaingun_Fire);
  return;
}



/* weapon_shotgun_fire @ 10036ee0 status created size 415 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void weapon_shotgun_fire(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  float afStack_30 [3];
  float afStack_24 [3];
  float afStack_18 [3];
  float afStack_c [3];
  
  iVar3 = 4;
  iVar2 = 8;
  iVar1 = *(int *)(param_1 + 0x54);
  if (*(int *)(iVar1 + 0x5c) == 9) {
    *(undefined4 *)(iVar1 + 0x5c) = 10;
    return;
  }
  AngleVectors((float *)(iVar1 + 0xe64),afStack_30,afStack_c,(float *)0x0);
  VectorScale(afStack_30,-2.0,(float *)(*(int *)(param_1 + 0x54) + 0xe30));
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe24) = 0xc0000000;
  afStack_24[2] = (float)(*(int *)(param_1 + 0x23c) + -8);
  afStack_24[0] = 0.0;
  afStack_24[1] = 8.0;
  P_ProjectSource(*(int *)(param_1 + 0x54),(float *)(param_1 + 4),afStack_24,afStack_30,afStack_c,
                  afStack_18);
  if (DAT_100613c0 != 0) {
    iVar3 = 0x10;
    iVar2 = 0x20;
  }
  FUN_1001beb0(param_1,afStack_18,afStack_30,iVar3,iVar2,500,500,0xc,2);
  (*DAT_1006c224)(1);
  (*DAT_1006c228)((param_1 - DAT_1006c2c4) / 0x3d0);
  (*DAT_1006c224)(DAT_100613c4 & 0xff | 2);
  (*DAT_1006c218)((float *)(param_1 + 4),2);
  *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = *(int *)(*(int *)(param_1 + 0x54) + 0x5c) + 1;
  PlayerNoise(param_1,afStack_18,1);
  uVar4 = __ftol();
  if ((uVar4 & 0x2000) == 0) {
    iVar1 = *(int *)(param_1 + 0x54);
    *(int *)(iVar1 + 0x2e4 + *(int *)(iVar1 + 0xde8) * 4) =
         *(int *)(iVar1 + 0x2e4 + *(int *)(iVar1 + 0xde8) * 4) + -1;
  }
  return;
}



/* Weapon_Shotgun @ 10037080 status created size 37 */

void Weapon_Shotgun(int param_1)

{
  Weapon_Generic(param_1,7,0x12,0x24,0x27,(int *)&DAT_1005f7d8,(int *)&DAT_1005f7e8,
                 weapon_shotgun_fire);
  return;
}



/* weapon_supershotgun_fire @ 100370b0 status created size 493 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void weapon_supershotgun_fire(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  float afStack_3c [3];
  float fStack_30;
  float fStack_2c;
  undefined4 uStack_28;
  float afStack_24 [3];
  float afStack_18 [3];
  float afStack_c [3];
  
  iVar3 = 6;
  iVar2 = 0xc;
  AngleVectors((float *)(*(int *)(param_1 + 0x54) + 0xe64),afStack_3c,afStack_c,(float *)0x0);
  VectorScale(afStack_3c,-2.0,(float *)(*(int *)(param_1 + 0x54) + 0xe30));
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe24) = 0xc0000000;
  afStack_24[2] = (float)(*(int *)(param_1 + 0x23c) + -8);
  afStack_24[0] = 0.0;
  afStack_24[1] = 8.0;
  P_ProjectSource(*(int *)(param_1 + 0x54),(float *)(param_1 + 4),afStack_24,afStack_3c,afStack_c,
                  afStack_18);
  if (DAT_100613c0 != 0) {
    iVar3 = 0x18;
    iVar2 = 0x30;
  }
  iVar1 = *(int *)(param_1 + 0x54);
  fStack_30 = *(float *)(iVar1 + 0xe64);
  fStack_2c = *(float *)(iVar1 + 0xe68) - _DAT_1004414c;
  uStack_28 = *(undefined4 *)(iVar1 + 0xe6c);
  AngleVectors(&fStack_30,afStack_3c,(float *)0x0,(float *)0x0);
  FUN_1001beb0(param_1,afStack_18,afStack_3c,iVar3,iVar2,1000,500,10,3);
  fStack_2c = *(float *)(*(int *)(param_1 + 0x54) + 0xe68) + _DAT_1004414c;
  AngleVectors(&fStack_30,afStack_3c,(float *)0x0,(float *)0x0);
  FUN_1001beb0(param_1,afStack_18,afStack_3c,iVar3,iVar2,1000,500,10,3);
  (*DAT_1006c224)(1);
  (*DAT_1006c228)((param_1 - DAT_1006c2c4) / 0x3d0);
  (*DAT_1006c224)(DAT_100613c4 & 0xff | 0xd);
  (*DAT_1006c218)((float *)(param_1 + 4),2);
  *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = *(int *)(*(int *)(param_1 + 0x54) + 0x5c) + 1;
  PlayerNoise(param_1,afStack_18,1);
  uVar4 = __ftol();
  if ((uVar4 & 0x2000) == 0) {
    iVar2 = *(int *)(param_1 + 0x54);
    *(int *)(iVar2 + 0x2e4 + *(int *)(iVar2 + 0xde8) * 4) =
         *(int *)(iVar2 + 0x2e4 + *(int *)(iVar2 + 0xde8) * 4) + -2;
  }
  return;
}



/* Weapon_SuperShotgun @ 100372a0 status created size 37 */

void Weapon_SuperShotgun(int param_1)

{
  Weapon_Generic(param_1,6,0x11,0x39,0x3d,(int *)&DAT_1005f7f4,(int *)&DAT_1005f804,
                 weapon_supershotgun_fire);
  return;
}



/* weapon_railgun_fire @ 100372d0 status created size 375 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void weapon_railgun_fire(uint param_1)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  float afStack_30 [3];
  float afStack_24 [3];
  float afStack_18 [3];
  float afStack_c [3];
  
  if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
    iVar1 = 0x96;
    iVar2 = 0xfa;
  }
  else {
    iVar1 = 100;
    iVar2 = 200;
  }
  if (DAT_100613c0 != 0) {
    iVar1 = iVar1 << 2;
    iVar2 = iVar2 << 2;
  }
  AngleVectors((float *)(*(int *)(param_1 + 0x54) + 0xe64),afStack_24,afStack_c,(float *)0x0);
  VectorScale(afStack_24,-3.0,(float *)(*(int *)(param_1 + 0x54) + 0xe30));
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe24) = 0xc0400000;
  afStack_30[2] = (float)(*(int *)(param_1 + 0x23c) + -8);
  afStack_30[0] = 0.0;
  afStack_30[1] = 7.0;
  P_ProjectSource(*(int *)(param_1 + 0x54),(float *)(param_1 + 4),afStack_30,afStack_24,afStack_c,
                  afStack_18);
  fire_rail(param_1,afStack_18,afStack_24,iVar1,iVar2);
  (*DAT_1006c224)(1);
  (*DAT_1006c228)((int)(param_1 - DAT_1006c2c4) / 0x3d0);
  (*DAT_1006c224)(DAT_100613c4 & 0xff | 6);
  (*DAT_1006c218)((float *)(param_1 + 4),2);
  *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = *(int *)(*(int *)(param_1 + 0x54) + 0x5c) + 1;
  PlayerNoise(param_1,afStack_18,1);
  uVar3 = __ftol();
  if ((uVar3 & 0x2000) == 0) {
    iVar1 = *(int *)(param_1 + 0x54);
    *(int *)(iVar1 + 0x2e4 + *(int *)(iVar1 + 0xde8) * 4) =
         *(int *)(iVar1 + 0x2e4 + *(int *)(iVar1 + 0xde8) * 4) + -1;
  }
  return;
}



/* Weapon_Railgun @ 10037450 status created size 37 */

void Weapon_Railgun(int param_1)

{
  Weapon_Generic(param_1,3,0x12,0x38,0x3d,(int *)&DAT_1005f80c,(int *)&DAT_1005f814,
                 weapon_railgun_fire);
  return;
}



/* weapon_bfg_fire @ 10037480 status created size 508 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void weapon_bfg_fire(int param_1)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  float afStack_30 [3];
  float afStack_24 [3];
  float afStack_18 [3];
  float afStack_c [3];
  
  iVar4 = 200;
  if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
    iVar4 = 500;
  }
  iVar1 = *(int *)(param_1 + 0x54);
  if (*(int *)(iVar1 + 0x5c) == 9) {
    (*DAT_1006c224)(1);
    (*DAT_1006c228)((param_1 - DAT_1006c2c4) / 0x3d0);
    (*DAT_1006c224)(DAT_100613c4 & 0xff | 0xc);
    (*DAT_1006c218)(param_1 + 4,2);
    *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = *(int *)(*(int *)(param_1 + 0x54) + 0x5c) + 1;
    PlayerNoise(param_1,afStack_18,1);
    return;
  }
  if (*(int *)(iVar1 + 0x2e4 + *(int *)(iVar1 + 0xde8) * 4) < 0x32) {
    *(int *)(iVar1 + 0x5c) = *(int *)(iVar1 + 0x5c) + 1;
    return;
  }
  if (DAT_100613c0 != 0) {
    iVar4 = iVar4 << 2;
  }
  AngleVectors((float *)(iVar1 + 0xe64),afStack_24,afStack_c,(float *)0x0);
  VectorScale(afStack_24,-2.0,(float *)(*(int *)(param_1 + 0x54) + 0xe30));
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe40) = 0xc2200000;
  uVar3 = _rand();
  fVar2 = (float)(uVar3 & 0x7fff) * _DAT_10044108 - (float)_DAT_10044140;
  *(float *)(*(int *)(param_1 + 0x54) + 0xe3c) = (fVar2 + fVar2) * (float)_DAT_10044270;
  *(float *)(*(int *)(param_1 + 0x54) + 0xe44) = DAT_1006c2e4 + (float)_DAT_10044140;
  afStack_30[2] = (float)(*(int *)(param_1 + 0x23c) + -8);
  afStack_30[0] = 8.0;
  afStack_30[1] = 8.0;
  P_ProjectSource(*(int *)(param_1 + 0x54),(float *)(param_1 + 4),afStack_30,afStack_24,afStack_c,
                  afStack_18);
  fire_bfg(param_1,afStack_18,afStack_24,iVar4,400,0x447a0000);
  *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = *(int *)(*(int *)(param_1 + 0x54) + 0x5c) + 1;
  PlayerNoise(param_1,afStack_18,1);
  uVar5 = __ftol();
  if ((uVar5 & 0x2000) == 0) {
    iVar4 = *(int *)(param_1 + 0x54);
    *(int *)(iVar4 + 0x2e4 + *(int *)(iVar4 + 0xde8) * 4) =
         *(int *)(iVar4 + 0x2e4 + *(int *)(iVar4 + 0xde8) * 4) + -0x32;
  }
  return;
}



/* Weapon_BFG @ 10037680 status created size 37 */

void Weapon_BFG(int param_1)

{
  Weapon_Generic(param_1,8,0x20,0x37,0x3a,(int *)&DAT_1005f81c,(int *)&DAT_1005f830,weapon_bfg_fire)
  ;
  return;
}



/* Weapon_ProximityMines_Fire @ 100376b0 status existing size 209 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Weapon_ProximityMines_Fire(int param_1)

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
  AngleVectors((float *)(*(int *)(param_1 + 0x54) + 0xe64),local_24,local_18,(float *)0x0);
  P_ProjectSource(*(int *)(param_1 + 0x54),(float *)(param_1 + 4),local_30,local_24,local_18,local_c
                 );
  lVar2 = __ftol();
  fire_proximity_mine(param_1,(int *)local_c,local_24,(int)lVar2);
  piVar1 = (int *)(*(int *)(param_1 + 0x54) + 0x2e4 + *(int *)(*(int *)(param_1 + 0x54) + 0xde8) * 4
                  );
  *piVar1 = *piVar1 + -1;
  *(float *)(*(int *)(param_1 + 0x54) + 0xec0) = DAT_1006c2e4 + (float)_DAT_10044120;
  return;
}



/* Weapon_ProximityMines @ 10037790 status existing size 639 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Weapon_ProximityMines(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0x54);
  if ((*(int *)(iVar1 + 0xdfc) != 0) && (*(int *)(iVar1 + 0xe20) == 0)) {
    ChangeWeapon(param_1);
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
        NoAmmoWeaponChange(param_1);
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
        Weapon_ProximityMines_Fire(param_1);
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
      Weapon_ProximityMines_Fire(param_1);
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



/* Weapon_Deatomizer_Fire @ 10037a10 status existing size 472 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Weapon_Deatomizer_Fire(float param_1,float *param_2,int param_3)

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
    AngleVectors((float *)(*(int *)((int)param_1 + 0x54) + 0xe64),local_24,local_c,(float *)0x0);
    local_30 = *param_2 + _DAT_10044480;
    local_2c = param_2[1] + _DAT_10044164;
    local_28 = (float)(*(int *)((int)param_1 + 0x23c) + -8) + param_2[2];
    P_ProjectSource(*(int *)((int)param_1 + 0x54),(float *)((int)param_1 + 4),&local_30,local_24,
                    local_c,local_18);
    VectorScale(local_24,-2.0,(float *)(*(int *)((int)param_1 + 0x54) + 0xe30));
    *(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xe24) = 0xbf800000;
    fire_deatom(param_1,(int *)local_18,local_24,param_3,1.4013e-42);
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
    PlayerNoise((int)param_1,local_18,1);
    return;
  }
  if (*(float *)((int)param_1 + 0x210) <= DAT_1006c2e4) {
    uVar3 = (*DAT_1006c1e4)(s_weapons_noammo_wav_1004b5c8,0x3f800000,0x3f800000,0);
    (*DAT_1006c1d0)(param_1,2,uVar3);
    *(float *)((int)param_1 + 0x210) = DAT_1006c2e4 + _DAT_10044104;
  }
  NoAmmoWeaponChange((int)param_1);
  return;
}



/* Weapon_Deatomizer @ 10037c50 status created size 37 */

void Weapon_Deatomizer(int param_1)

{
  Weapon_Generic(param_1,0xb,0x15,0x2b,0x31,(int *)&DAT_1005f83c,(int *)&DAT_1005f844,&LAB_10037bf0)
  ;
  return;
}



/* Weapon_Plasma_Fire @ 10037de0 status existing size 437 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Weapon_Plasma_Fire(int param_1,float *param_2,int param_3,int param_4)

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
  AngleVectors((float *)(*(int *)(param_1 + 0x54) + 0xe64),local_24,local_c,(float *)0x0);
  local_30 = *param_2 + _DAT_10044480;
  local_2c = param_2[1] + _DAT_10044164;
  local_28 = (float)(*(int *)(param_1 + 0x23c) + -8) + param_2[2];
  P_ProjectSource(*(int *)(param_1 + 0x54),(float *)(param_1 + 4),&local_30,local_24,local_c,
                  local_18);
  VectorScale(local_24,-2.0,(float *)(*(int *)(param_1 + 0x54) + 0xe30));
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe24) = 0xbf800000;
  fire_plasma_bolt(param_1,local_18,local_24,param_3,2000,param_4);
  if (param_4 == 0) {
    puVar1 = FindItem((byte *)s_PistolPlasma_10048ca0);
    piVar2 = (int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar1 + -0x4011a4a) / 0x48) * 4);
    iVar3 = *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar1 + -0x4011a4a) / 0x48) * 4) +
            -1;
  }
  else {
    puVar1 = FindItem((byte *)s_Rifle_Plasma_100461a4);
    piVar2 = (int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar1 + -0x4011a4a) / 0x48) * 4);
    iVar3 = *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar1 + -0x4011a4a) / 0x48) * 4) +
            -5;
  }
  *piVar2 = iVar3;
  (*DAT_1006c224)(1);
  (*DAT_1006c228)((param_1 - DAT_1006c2c4) / 0x3d0);
  (*DAT_1006c224)(DAT_100613c4 & 0xff | 0x22);
  (*DAT_1006c218)((float *)(param_1 + 4),2);
  PlayerNoise(param_1,local_18,1);
  return;
}



/* Oblivion_UpdateWeaponRegen @ 10037cd0 status existing size 259 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Oblivion_UpdateWeaponRegen(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_1 + 0x54) != 0) {
    if (*(float *)(*(int *)(param_1 + 0x54) + 0xf2c) + (float)_DAT_10044120 < DAT_1006c2e4) {
      puVar3 = FindItem((byte *)s_PistolPlasma_10048ca0);
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
      puVar3 = FindItem((byte *)s_Rifle_Plasma_100461a4);
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



/* Weapon_PlasmaPistol_Fire @ 10037fa0 status created size 120 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Weapon_PlasmaPistol_Fire(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = 0xf;
  if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
    iVar1 = 10;
  }
  Weapon_Plasma_Fire(param_1,(float *)&DAT_10061c18,iVar1,0);
  *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = *(int *)(*(int *)(param_1 + 0x54) + 0x5c) + 1;
  if ((char)DAT_100613c4 == '\0') {
    uVar2 = 0x3f800000;
  }
  else {
    uVar2 = 0x3f000000;
  }
  uVar2 = (*DAT_1006c1e4)(s_plasma1_fire_wav_1005fa24,uVar2,0x3f800000,0);
  (*DAT_1006c1d0)(param_1,2,uVar2);
  return;
}



/* Weapon_PlasmaPistol @ 10038020 status created size 37 */

void Weapon_PlasmaPistol(int param_1)

{
  Weapon_Generic(param_1,6,0xb,0x20,0x28,(int *)0x1005f84c,(int *)0x1005f858,
                 Weapon_PlasmaPistol_Fire);
  return;
}



/* Weapon_PlasmaRifle_Fire @ 10038050 status created size 120 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Weapon_PlasmaRifle_Fire(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = 0x32;
  if (*(float *)(DAT_1006c118 + 0x14) == _DAT_1004410c) {
    iVar1 = 0x23;
  }
  Weapon_Plasma_Fire(param_1,(float *)&DAT_10061c18,iVar1,1);
  *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = *(int *)(*(int *)(param_1 + 0x54) + 0x5c) + 1;
  if ((char)DAT_100613c4 == '\0') {
    uVar2 = 0x3f800000;
  }
  else {
    uVar2 = 0x3f000000;
  }
  uVar2 = (*DAT_1006c1e4)(s_plasma2_fire_wav_1005fa38,uVar2,0x3f800000,0);
  (*DAT_1006c1d0)(param_1,2,uVar2);
  return;
}



/* Weapon_PlasmaRifle @ 100380d0 status created size 37 */

void Weapon_PlasmaRifle(int param_1)

{
  Weapon_Generic(param_1,7,10,0x18,0x20,(int *)&DAT_1005f860,(int *)&DAT_1005f870,
                 Weapon_PlasmaRifle_Fire);
  return;
}



/* Weapon_DetonationPack_Fire @ 10038100 status created size 366 */

void Weapon_DetonationPack_Fire(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  longlong lVar4;
  float fVar5;
  float fVar6;
  float afStack_30 [3];
  float afStack_24 [3];
  float afStack_18 [3];
  float afStack_c [3];
  
  iVar2 = param_1;
  iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0x5c);
  if (iVar1 == 0xe) {
    puVar3 = FindItem((byte *)s_Remote_Detonator_1004630c);
    *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar3 + -0x4011a4a) / 0x48) * 4) = 1;
    *(undefined4 **)(*(int *)(param_1 + 0x54) + 0xdfc) = puVar3;
    ChangeWeapon(param_1);
    return;
  }
  *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = iVar1 + 1;
  param_1 = 0x43960000;
  if (DAT_100613c0 != 0) {
    param_1 = 0x44160000;
  }
  AngleVectors((float *)(*(int *)(iVar2 + 0x54) + 0xe64),afStack_24,afStack_18,(float *)0x0);
  afStack_30[2] = (float)*(int *)(iVar2 + 0x23c);
  afStack_30[0] = 8.0;
  afStack_30[1] = -5.0;
  P_ProjectSource(*(int *)(iVar2 + 0x54),(float *)(iVar2 + 4),afStack_30,afStack_24,afStack_18,
                  afStack_c);
  VectorScale(afStack_24,-2.0,(float *)(*(int *)(iVar2 + 0x54) + 0xe30));
  fVar6 = 0.0;
  fVar5 = 400.0;
  *(undefined4 *)(*(int *)(iVar2 + 0x54) + 0xe24) = 0xbf800000;
  lVar4 = __ftol();
  fire_detpack(iVar2,(int *)afStack_c,afStack_24,(int)lVar4,param_1,fVar5,fVar6);
  puVar3 = FindItem((byte *)s_Detonation_Pack_10046320);
  *(int *)(*(int *)(iVar2 + 0x54) + 0x2e4 + ((int)(puVar3 + -0x4011a4a) / 0x48) * 4) =
       *(int *)(*(int *)(iVar2 + 0x54) + 0x2e4 + ((int)(puVar3 + -0x4011a4a) / 0x48) * 4) + -1;
  return;
}



/* Weapon_DetonationPack @ 10038270 status created size 37 */

void Weapon_DetonationPack(int param_1)

{
  Weapon_Generic(param_1,4,0xe,0x22,0x27,(int *)&DAT_1005f878,(int *)&DAT_1005f888,
                 Weapon_DetonationPack_Fire);
  return;
}



/* Weapon_RemoteDetonator_Fire @ 100382a0 status created size 305 */

void Weapon_RemoteDetonator_Fire(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  undefined4 *puVar7;
  bool bVar8;
  
  *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = *(int *)(*(int *)(param_1 + 0x54) + 0x5c) + 1;
  puVar4 = DAT_1006c2c4;
  iVar5 = DAT_1006c168;
  puVar7 = DAT_1006c2c4;
  if (DAT_1006c2c4 < DAT_1006c2c4 + DAT_1006c168 * 0xf4) {
    do {
      if (((puVar7[0x16] != 0) && (puVar7[0x40] == param_1)) &&
         (pbVar2 = (byte *)puVar7[0x46], pbVar2 != (byte *)0x0)) {
        pcVar6 = s_detpack_1004c100;
        do {
          bVar1 = *pbVar2;
          bVar8 = bVar1 < (byte)*pcVar6;
          if (bVar1 != *pcVar6) {
LAB_10038316:
            iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
            goto LAB_1003831b;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar2[1];
          bVar8 = bVar1 < (byte)pcVar6[1];
          if (bVar1 != pcVar6[1]) goto LAB_10038316;
          pbVar2 = pbVar2 + 2;
          pcVar6 = pcVar6 + 2;
        } while (bVar1 != 0);
        iVar3 = 0;
LAB_1003831b:
        if (iVar3 == 0) {
          detpack_detonate(puVar7);
          puVar4 = DAT_1006c2c4;
          iVar5 = DAT_1006c168;
        }
      }
      puVar7 = puVar7 + 0xf4;
    } while (puVar7 < puVar4 + iVar5 * 0xf4);
  }
  puVar4 = FindItem((byte *)s_Detonation_Pack_10046320);
  if (*(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar4 + -0x4011a4a) / 0x48) * 4) == 0) {
    NoAmmoWeaponChange(param_1);
  }
  else {
    *(undefined4 **)(*(int *)(param_1 + 0x54) + 0xdfc) = puVar4;
  }
  puVar4 = FindItem((byte *)s_Remote_Detonator_1004630c);
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar4 + -0x4011a4a) / 0x48) * 4) = 0;
  return;
}



/* Weapon_RemoteDetonator @ 100383e0 status created size 37 */

void Weapon_RemoteDetonator(int param_1)

{
  Weapon_Generic(param_1,4,8,0x1c,0x21,(int *)0x1005f894,(int *)0x1005f8a4,
                 Weapon_RemoteDetonator_Fire);
  return;
}



/* Weapon_DOD_Fire @ 10038410 status created size 113 */

void Weapon_DOD_Fire(int param_1)

{
  undefined4 *puVar1;
  float afStack_c [3];
  
  *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = *(int *)(*(int *)(param_1 + 0x54) + 0x5c) + 1;
  AngleVectors((float *)(param_1 + 0x10),afStack_c,(float *)0x0,(float *)0x0);
  fire_dod(param_1,(int *)(param_1 + 4));
  puVar1 = FindItem(&DAT_10048728);
  *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar1 + -0x4011a4a) / 0x48) * 4) =
       *(int *)(*(int *)(param_1 + 0x54) + 0x2e4 + ((int)(puVar1 + -0x4011a4a) / 0x48) * 4) + -1;
  return;
}



/* Weapon_DOD @ 10038490 status created size 37 */

void Weapon_DOD(int param_1)

{
  Weapon_Generic(param_1,10,0xf,0x23,0x2e,(int *)&DAT_1005f8ac,(int *)&DAT_1005f8b4,Weapon_DOD_Fire)
  ;
  return;
}



/* Weapon_Obliterator_Fire @ 100384c0 status created size 522 */

void Weapon_Obliterator_Fire(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  float afStack_30 [3];
  float afStack_24 [3];
  float afStack_18 [3];
  float afStack_c [3];
  
  _rand();
  lVar4 = __ftol();
  iVar3 = 0x3c;
  iVar2 = 0x32 - (int)lVar4;
  if (DAT_100613c0 != 0) {
    iVar2 = iVar2 * 4;
    iVar3 = 0xf0;
  }
  AngleVectors((float *)(*(int *)(param_1 + 0x54) + 0xe64),afStack_24,afStack_c,(float *)0x0);
  VectorScale(afStack_24,-2.0,(float *)(*(int *)(param_1 + 0x54) + 0xe30));
  *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xe24) = 0xbf800000;
  iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0x5c);
  if (iVar1 == 0xf) {
    afStack_30[0] = 8.0;
    afStack_30[1] = 12.0;
    afStack_30[2] = (float)(*(int *)(param_1 + 0x23c) + -8);
  }
  else if (iVar1 == 0x10) {
    afStack_30[0] = 10.0;
    afStack_30[1] = 12.0;
    afStack_30[2] = (float)(*(int *)(param_1 + 0x23c) + -8);
  }
  else if (iVar1 == 0x11) {
    afStack_30[0] = 10.0;
    afStack_30[1] = 10.0;
    afStack_30[2] = (float)(*(int *)(param_1 + 0x23c) + -8);
  }
  else if (iVar1 == 0x12) {
    afStack_30[0] = 8.0;
    afStack_30[1] = 10.0;
    afStack_30[2] = (float)(*(int *)(param_1 + 0x23c) + -8);
  }
  P_ProjectSource(*(int *)(param_1 + 0x54),(float *)(param_1 + 4),afStack_30,afStack_24,afStack_c,
                  afStack_18);
  fire_obliterator_projectile(param_1,(int *)afStack_18,afStack_24,iVar2,900,0x42c80000,iVar3);
  (*DAT_1006c224)(1);
  (*DAT_1006c228)((param_1 - DAT_1006c2c4) / 0x3d0);
  (*DAT_1006c224)(DAT_100613c4 & 0xff | 7);
  (*DAT_1006c218)((float *)(param_1 + 4),2);
  *(int *)(*(int *)(param_1 + 0x54) + 0x5c) = *(int *)(*(int *)(param_1 + 0x54) + 0x5c) + 1;
  PlayerNoise(param_1,afStack_18,1);
  uVar5 = __ftol();
  if ((uVar5 & 0x2000) == 0) {
    iVar2 = *(int *)(param_1 + 0x54);
    *(int *)(iVar2 + 0x2e4 + *(int *)(iVar2 + 0xde8) * 4) =
         *(int *)(iVar2 + 0x2e4 + *(int *)(iVar2 + 0xde8) * 4) + -1;
  }
  return;
}



/* Weapon_Obliterator @ 100386d0 status created size 37 */

void Weapon_Obliterator(int param_1)

{
  Weapon_Generic(param_1,0xe,0x1b,0x28,0x30,(int *)&DAT_1005f8bc,(int *)&DAT_1005f8d0,
                 Weapon_Obliterator_Fire);
  return;
}



/* AngleVectors @ 10038700 status existing size 329 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl AngleVectors(float *param_1,float *param_2,float *param_3,float *param_4)

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



/* anglemod @ 10038850 status existing size 35 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 anglemod(void)

{
  longlong lVar1;
  
  lVar1 = __ftol();
  return (float10)((uint)lVar1 & 0xffff) * (float10)_DAT_10044280;
}



/* M_CheckBottom @ 1002a0c0 status existing size 609 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl M_CheckBottom(int param_1)

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



/* SV_movestep @ 1002a330 status existing size 1299 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl SV_movestep(int param_1,float *param_2,int param_3)

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
        G_TouchTriggers();
      }
      *(undefined4 *)(param_1 + 0x268) = 0;
      return 1;
    }
    *(undefined4 *)(param_1 + 4) = uStack_a8;
    *(undefined4 *)(param_1 + 8) = uStack_a4;
    *(float *)(param_1 + 0xc) = fStack_a0;
    iVar5 = M_CheckBottom(param_1);
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
    G_TouchTriggers();
  }
  return 1;
}



/* M_ChangeYaw @ 1002a850 status existing size 198 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl M_ChangeYaw(int param_1)

{
  float10 fVar1;
  
  fVar1 = anglemod();
  if (fVar1 != (float10)*(float *)(param_1 + 0x1e8)) {
    fVar1 = anglemod();
    *(float *)(param_1 + 0x14) = (float)fVar1;
    return;
  }
  return;
}



/* SV_StepDirection @ 1002a920 status existing size 214 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl SV_StepDirection(int param_1,float param_2,float param_3)

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
  M_ChangeYaw(param_1);
  uVar1 = *(undefined4 *)(param_1 + 4);
  uVar2 = *(undefined4 *)(param_1 + 8);
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  fVar6 = (float10)fcos((float10)param_2 * (float10)_DAT_100442b8);
  local_4 = 0;
  local_c = (float)(fVar6 * (float10)param_3);
  fVar6 = (float10)fsin((float10)param_2 * (float10)_DAT_100442b8);
  local_8 = (float)(fVar6 * (float10)param_3);
  iVar5 = SV_movestep(param_1,&local_c,0);
  if (iVar5 == 0) {
    (*DAT_1006c208)(param_1);
    G_TouchTriggers();
    return 0;
  }
  fVar4 = *(float *)(param_1 + 0x14) - *(float *)(param_1 + 0x1e8);
  if ((_DAT_10044138 < fVar4) && (fVar4 < _DAT_10044134)) {
    *(undefined4 *)(param_1 + 4) = uVar1;
    *(undefined4 *)(param_1 + 8) = uVar2;
    *(undefined4 *)(param_1 + 0xc) = uVar3;
  }
  (*DAT_1006c208)(param_1);
  G_TouchTriggers();
  return 1;
}



/* SV_FixCheckBottom @ 1002aa00 status existing size 20 */

void __cdecl SV_FixCheckBottom(int param_1)

{
  *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) | 0x100;
  return;
}



/* SV_NewChaseDir @ 1002aa20 status existing size 825 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SV_NewChaseDir(int param_1,float param_2,float param_3)

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
  fVar8 = anglemod();
  fVar1 = (float)fVar8;
  fVar8 = anglemod();
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
       (iVar5 = SV_StepDirection(param_1,(float)(int)param_2,param_3), iVar5 != 0)) {
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
       (iVar5 = SV_StepDirection(param_1,local_8,param_3), iVar5 == 0)) &&
      (((local_4 == _DAT_100441bc || (local_4 == fVar2)) ||
       (iVar5 = SV_StepDirection(param_1,local_4,param_3), iVar5 == 0)))) &&
     ((fVar1 == _DAT_100441bc || (iVar5 = SV_StepDirection(param_1,fVar1,param_3), iVar5 == 0)))) {
    uVar6 = _rand();
    if ((uVar6 & 1) == 0) {
      param_2 = 315.0;
      do {
        if ((param_2 != fVar2) && (iVar5 = SV_StepDirection(param_1,param_2,param_3), iVar5 != 0)) {
          return;
        }
        param_2 = param_2 - _DAT_10044138;
      } while (_DAT_1004410c <= param_2);
    }
    else {
      param_2 = 0.0;
      do {
        if ((param_2 != fVar2) && (iVar5 = SV_StepDirection(param_1,param_2,param_3), iVar5 != 0)) {
          return;
        }
        param_2 = param_2 + _DAT_10044138;
      } while (param_2 <= _DAT_10044134);
    }
    if ((fVar2 == _DAT_100441bc) || (iVar5 = SV_StepDirection(param_1,fVar2,param_3), iVar5 == 0)) {
      *(float *)(param_1 + 0x1e8) = fVar1;
      iVar5 = M_CheckBottom(param_1);
      if (iVar5 == 0) {
        SV_FixCheckBottom(param_1);
      }
    }
  }
  return;
}



/* SV_CloseEnough @ 1002ad60 status existing size 88 */

undefined4 __cdecl SV_CloseEnough(int param_1,int param_2,float param_3)

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



/* M_MoveToGoal @ 1002adc0 status existing size 116 */

void __cdecl M_MoveToGoal(int param_1,float param_2)

{
  float fVar1;
  int iVar2;
  
  fVar1 = *(float *)(param_1 + 0x1dc);
  if ((*(int *)(param_1 + 0x268) != 0) || ((*(byte *)(param_1 + 0x108) & 3) != 0)) {
    if ((*(int *)(param_1 + 0x25c) != 0) &&
       (iVar2 = SV_CloseEnough(param_1,*(int *)(param_1 + 0x25c),param_2), iVar2 != 0)) {
      return;
    }
    iVar2 = _rand();
    if ((((byte)iVar2 & 3) != 1) &&
       (iVar2 = SV_StepDirection(param_1,*(float *)(param_1 + 0x1e8),param_2), iVar2 != 0)) {
      return;
    }
    if (*(int *)(param_1 + 0x58) != 0) {
      SV_NewChaseDir(param_1,fVar1,param_2);
    }
  }
  return;
}



/* M_walkmove @ 1002ae40 status existing size 92 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl M_walkmove(int param_1,float param_2,float param_3)

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
  uVar1 = SV_movestep(param_1,&local_c,1);
  return uVar1;
}



/* AddPointToBounds @ 10038880 status existing size 63 */

void __cdecl AddPointToBounds(int param_1,float *param_2,int param_3)

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



/* VectorNormalize @ 10038900 status existing size 78 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl VectorNormalize(float *param_1)

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



/* VectorCompare @ 100388c0 status existing size 54 */

undefined4 __cdecl VectorCompare(float *param_1,float *param_2)

{
  if (((*param_1 == *param_2) && (param_1[1] == param_2[1])) && (param_1[2] == param_2[2])) {
    return 1;
  }
  return 0;
}



/* VectorMA @ 10038950 status existing size 49 */

void __cdecl VectorMA(float *param_1,float param_2,float *param_3,float *param_4)

{
  *param_4 = param_2 * *param_3 + *param_1;
  param_4[1] = param_2 * param_3[1] + param_1[1];
  param_4[2] = param_2 * param_3[2] + param_1[2];
  return;
}



/* DotProduct @ 10038990 status existing size 29 */

float10 __cdecl DotProduct(float *param_1,float *param_2)

{
  return (float10)*param_1 * (float10)*param_2 +
         (float10)param_1[1] * (float10)param_2[1] + (float10)param_1[2] * (float10)param_2[2];
}



/* CrossProduct @ 100389b0 status existing size 59 */

void __cdecl CrossProduct(float *param_1,float *param_2,float *param_3)

{
  *param_3 = param_2[2] * param_1[1] - param_1[2] * param_2[1];
  param_3[1] = param_1[2] * *param_2 - *param_1 * param_2[2];
  param_3[2] = *param_1 * param_2[1] - *param_2 * param_1[1];
  return;
}



/* VectorLength @ 100389f0 status existing size 34 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl VectorLength(float *param_1)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  
  fVar3 = (float10)_DAT_1004410c;
  iVar2 = 3;
  do {
    fVar1 = *param_1;
    param_1 = param_1 + 1;
    iVar2 = iVar2 + -1;
    fVar3 = (float10)fVar1 * (float10)fVar1 + fVar3;
  } while (iVar2 != 0);
  return SQRT(fVar3);
}



/* VectorScale @ 10038a20 status existing size 37 */

void __cdecl VectorScale(float *param_1,float param_2,float *param_3)

{
  *param_3 = param_2 * *param_1;
  param_3[1] = param_2 * param_1[1];
  param_3[2] = param_2 * param_1[2];
  return;
}



/* G_TouchTriggers @ 1001b480 status existing size 137 */

void G_TouchTriggers(void)

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



/* ClientEndServerFrame @ 10034d80 status existing size 790 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl ClientEndServerFrame(float param_1)

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
    G_SetStats((int)param_1);
    return;
  }
  AngleVectors((float *)(*(int *)((int)param_1 + 0x54) + 0xe64),(float *)&DAT_10061398,
               (float *)&DAT_100613a4,(float *)&DAT_100613b0);
  P_WorldEffects();
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
  fVar6 = SV_CalcRoll((float *)((int)param_1 + 0x10),pfVar1);
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
  P_FallingDamage((uint)param_1);
  P_DamageFeedback(param_1);
  if (*(int *)(*(int *)((int)param_1 + 0x54) + 0xf0c) == 0) {
    SV_CalcViewOffset((int)param_1);
    SV_CalcGunOffset((int)param_1);
  }
  SV_CalcBlend((int)param_1);
  G_SetStats((int)param_1);
  G_SetClientEvent((int)param_1);
  G_SetClientEffects((int)param_1);
  G_SetClientSound((int)param_1);
  G_SetClientFrame((int)param_1);
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
    DeathmatchScoreboardMessage((int)param_1,*(int *)((int)param_1 + 0x25c));
    (*DAT_1006c21c)(param_1,0);
  }
  return;
}



/* ClientCommand @ 100055f0 status created size 923 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ClientCommand(float param_1)

{
  void *pvVar1;
  int iVar2;
  
  if (*(int *)((int)param_1 + 0x54) != 0) {
    pvVar1 = (void *)(*DAT_1006c260)(0);
    iVar2 = FUN_10038b20(pvVar1,(byte *)s_players_100465bc);
    if (iVar2 == 0) {
      Cmd_Players_f(param_1);
      return;
    }
    iVar2 = FUN_10038b20(pvVar1,&DAT_100465b8);
    if (iVar2 == 0) {
      Cmd_Say_f((int)param_1,0,0);
      return;
    }
    iVar2 = FUN_10038b20(pvVar1,(byte *)s_say_team_100465ac);
    if (iVar2 == 0) {
      Cmd_Say_f((int)param_1,1,0);
      return;
    }
    iVar2 = FUN_10038b20(pvVar1,(byte *)s_score_100465a4);
    if (iVar2 == 0) {
      Cmd_Score_f((int)param_1);
      return;
    }
    iVar2 = FUN_10038b20(pvVar1,&DAT_1004659c);
    if (iVar2 == 0) {
      Cmd_Help_f((int)param_1);
      return;
    }
    if (_DAT_1006c3a8 == _DAT_1004410c) {
      iVar2 = FUN_10038b20(pvVar1,&DAT_10046598);
      if (iVar2 == 0) {
        Cmd_Use_f((int)param_1);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,(byte *)s_usetoggle_1004658c);
      if (iVar2 == 0) {
        Cmd_UseToggle_f((int)param_1);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,&DAT_10046584);
      if (iVar2 == 0) {
        Cmd_Drop_f((int)param_1);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,&DAT_1004657c);
      if (iVar2 == 0) {
        Cmd_Give_f((int)param_1);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,&DAT_10046578);
      if (iVar2 == 0) {
        Cmd_God_f((int)param_1);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,(byte *)s_notarget_1004656c);
      if (iVar2 == 0) {
        Cmd_Notarget_f((int)param_1);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,(byte *)s_noclip_10046564);
      if (iVar2 == 0) {
        Cmd_Noclip_f((int)param_1);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,(byte *)s_inven_1004655c);
      if (iVar2 == 0) {
        Cmd_Inven_f((int)param_1);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,(byte *)s_invnext_10046554);
      if (iVar2 == 0) {
        SelectNextItem((int)param_1,0xffffffff);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,(byte *)s_invprev_1004654c);
      if (iVar2 == 0) {
        SelectPrevItem((int)param_1,0xffffffff);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,(byte *)s_invnextw_10046540);
      if (iVar2 == 0) {
        SelectNextItem((int)param_1,1);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,(byte *)s_invprevw_10046534);
      if (iVar2 == 0) {
        SelectPrevItem((int)param_1,1);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,(byte *)s_invnextp_10046528);
      if (iVar2 == 0) {
        SelectNextItem((int)param_1,0x20);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,(byte *)s_invprevp_1004651c);
      if (iVar2 == 0) {
        SelectPrevItem((int)param_1,0x20);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,(byte *)s_invuse_10046514);
      if (iVar2 == 0) {
        Cmd_InvUse_f((int)param_1);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,(byte *)s_invdrop_1004650c);
      if (iVar2 == 0) {
        Cmd_InvDrop_f((int)param_1);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,(byte *)s_weapprev_10046500);
      if (iVar2 == 0) {
        Cmd_WeapPrev_f((int)param_1);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,(byte *)s_weapnext_100464f4);
      if (iVar2 == 0) {
        Cmd_WeapNext_f((int)param_1);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,(byte *)s_weaplast_100464e8);
      if (iVar2 == 0) {
        Cmd_WeapLast_f((int)param_1);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,&DAT_100464e0);
      if (iVar2 == 0) {
        Cmd_Kill_f(param_1);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,(byte *)s_putaway_100464d8);
      if (iVar2 == 0) {
        Cmd_PutAway_f((int)param_1);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,&DAT_100464d0);
      if (iVar2 == 0) {
        Cmd_Wave_f((int)param_1);
        return;
      }
      iVar2 = FUN_10038b20(pvVar1,(byte *)s_playerlist_100464c4);
      if (iVar2 == 0) {
        Cmd_PlayerList_f(param_1);
        return;
      }
      Cmd_Say_f((int)param_1,0,1);
    }
  }
  return;
}



