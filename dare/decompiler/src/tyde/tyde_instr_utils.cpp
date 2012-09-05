/*
 * Copyright (C) 2012 The Pennsylvania State University
 * Systems and Internet Infrastructure Security Laboratory
 *
 * Author: Damien Octeau <octeau@cse.psu.edu>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */

/*
 * tyde_instr_utils.cpp
 *
 * Utility things for Tyde instructions.
 */


#include "tyde/tyde_instr_utils.h"


/**
 * Table that maps each opcode to the Tyde instruction format associated
 * that opcode.
 */
/*static*/ u1 TydeInstrUtils::tyde_format_table_[kNumPackedOpcodes] = {
  // BEGIN(tyde-formats); GENERATED AUTOMATICALLY BY opcode-gen
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTao,  kFmtTao,  kFmtTuo,  kFmtTao,  kFmtTao,  kFmtTao,
  kFmtTao,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTao,  kFmtTfna, kFmtTfna, kFmtTfad, kFmtTuo,  kFmtTub,  kFmtTub,
  kFmtTub,  kFmtTps,  kFmtTss,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTab,  kFmtTab,  kFmtTub,  kFmtTub,  kFmtTub,  kFmtTub,
  kFmtTab,  kFmtTab,  kFmtTub,  kFmtTub,  kFmtTub,  kFmtTub,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTao,  kFmtTao,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTao,  kFmtTao,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTno,  kFmtTuo,
  kFmtTno,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTunk, kFmtTunk, kFmtTunk, kFmtTunk,
  kFmtTunk, kFmtTunk, kFmtTunk, kFmtTunk, kFmtTunk, kFmtTunk, kFmtTtve,
  kFmtTunk, kFmtTunk, kFmtTunk, kFmtTunk, kFmtTunk, kFmtTunk, kFmtTunk,
  kFmtTunk, kFmtTunk, kFmtTunk, kFmtTunk, kFmtTunk, kFmtTunk, kFmtTunk,
  kFmtTunk, kFmtTunk, kFmtTunk, kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTao,  kFmtTfna, kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,  kFmtTuo,
  kFmtTuo,  kFmtTunk, kFmtTunk, kFmtTunk, kFmtTunk, kFmtTunk, kFmtTunk,
  kFmtTunk, kFmtTunk, kFmtTunk, kFmtTunk, kFmtTunk, kFmtTunk, kFmtTunk,
  kFmtTunk,
  // END(tyde-formats)
};

/**
 * Tyde opcode mapping.
 * Convention: UNUSED_CA: Not enough info a priori
 *             UNUSED_FF: No opcode necessary
 *             UNUSED_BA: Unused
 */
/*static*/ const char* TydeInstrUtils::tyde_opcode_mapping_[kNumPackedOpcodes]
                                                            = {
  // BEGIN(tyde-mapping); GENERATED AUTOMATICALLY BY opcode-gen
  "  nop",
  "  ",
  "  ",
  "  ",
  "  ",
  "  ",
  "  ",
  "  ",
  "  ",
  "  ",
  "  ",
  "  ",
  "  ",
  "  ",
  "  return",
  "  unused_ca",
  "  unused_ca",
  "  areturn",
  "  unused_ca",
  "  unused_ca",
  "  unused_ca",
  "  unused_ca",
  "  ldc2_w",
  "  ldc2_w",
  "  ldc2_w",
  "  ldc2_w",
  "  ldc",
  "  ldc",
  "  ldc",
  "  monitorenter",
  "  monitorexit",
  "  checkcast",
  "  instanceof",
  "  arraylength",
  "  new",
  "  unused_ca",
  "  newarray",
  "  newarray",
  "  unused_ca",
  "  athrow",
  "  goto",
  "  goto",
  "  goto",
  "  tableswitch",
  "  lookupswitch",
  "  fcmpl",
  "  fcmpg",
  "  dcmpl",
  "  dcmpg",
  "  lcmp",
  "  unused_ca",
  "  unused_ca",
  "  if_icmplt",
  "  if_icmpge",
  "  if_icmpgt",
  "  if_icmple",
  "  unused_ca",
  "  unused_ca",
  "  iflt",
  "  ifge",
  "  ifgt",
  "  ifle",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ca",
  "  unused_ca",
  "  aaload",
  "  baload",
  "  baload",
  "  caload",
  "  saload",
  "  unused_ca",
  "  unused_ca",
  "  aastore",
  "  bastore",
  "  bastore",
  "  castore",
  "  sastore",
  "  getfield",
  "  getfield",
  "  getfield",
  "  getfield",
  "  getfield",
  "  getfield",
  "  getfield",
  "  putfield",
  "  putfield",
  "  putfield",
  "  putfield",
  "  putfield",
  "  putfield",
  "  putfield",
  "  getstatic",
  "  getstatic",
  "  getstatic",
  "  getstatic",
  "  getstatic",
  "  getstatic",
  "  getstatic",
  "  putstatic",
  "  putstatic",
  "  putstatic",
  "  putstatic",
  "  putstatic",
  "  putstatic",
  "  putstatic",
  "  invokevirtual",
  "  invokespecial",
  "  invokespecial",
  "  invokestatic",
  "  invokeinterface",
  "  unused_ba",
  "  invokevirtual",
  "  invokespecial",
  "  invokespecial",
  "  invokestatic",
  "  invokeinterface",
  "  unused_ba",
  "  unused_ba",
  "  ineg",
  "  ldc",
  "  lneg",
  "  ldc2_w",
  "  fneg",
  "  dneg",
  "  i2l",
  "  i2f",
  "  i2d",
  "  l2i",
  "  l2f",
  "  l2d",
  "  f2i",
  "  f2l",
  "  f2d",
  "  d2i",
  "  d2l",
  "  d2f",
  "  i2b",
  "  i2c",
  "  i2s",
  "  iadd",
  "  isub",
  "  imul",
  "  idiv",
  "  irem",
  "  iand",
  "  ior",
  "  ixor",
  "  ishl",
  "  ishr",
  "  iushr",
  "  ladd",
  "  lsub",
  "  lmul",
  "  ldiv",
  "  lrem",
  "  land",
  "  lor",
  "  lxor",
  "  lshl",
  "  lshr",
  "  lushr",
  "  fadd",
  "  fsub",
  "  fmul",
  "  fdiv",
  "  frem",
  "  dadd",
  "  dsub",
  "  dmul",
  "  ddiv",
  "  drem",
  "  iadd",
  "  isub",
  "  imul",
  "  idiv",
  "  irem",
  "  iand",
  "  ior",
  "  ixor",
  "  ishl",
  "  ishr",
  "  iushr",
  "  ladd",
  "  lsub",
  "  lmul",
  "  ldiv",
  "  lrem",
  "  land",
  "  lor",
  "  lxor",
  "  lshl",
  "  lshr",
  "  lushr",
  "  fadd",
  "  fsub",
  "  fmul",
  "  fdiv",
  "  frem",
  "  dadd",
  "  dsub",
  "  dmul",
  "  ddiv",
  "  drem",
  "  iadd",
  "  isub",
  "  imul",
  "  idiv",
  "  irem",
  "  iadd",
  "  ior",
  "  ixor",
  "  iadd",
  "  isub",
  "  imul",
  "  idiv",
  "  irem",
  "  iand",
  "  ior",
  "  ixor",
  "  ishl",
  "  ishr",
  "  iushr",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ca",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  ldc",
  "  checkcast",
  "  instanceof",
  "  new",
  "  unused_ca",
  "  newarray",
  "  getfield",
  "  getfield",
  "  getfield",
  "  getfield",
  "  getfield",
  "  getfield",
  "  getfield",
  "  putfield",
  "  putfield",
  "  putfield",
  "  putfield",
  "  putfield",
  "  putfield",
  "  putfield",
  "  getstatic",
  "  getstatic",
  "  getstatic",
  "  getstatic",
  "  getstatic",
  "  getstatic",
  "  getstatic",
  "  putstatic",
  "  putstatic",
  "  putstatic",
  "  putstatic",
  "  putstatic",
  "  putstatic",
  "  putstatic",
  "  invokevirtual",
  "  invokespecial",
  "  invokespecial",
  "  invokestatic",
  "  invokeinterface",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  "  unused_ba",
  // END(tyde-mapping)
};