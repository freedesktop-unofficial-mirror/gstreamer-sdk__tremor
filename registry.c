/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE OggVorbis 'TREMOR' CODEC SOURCE CODE.   *
 *                                                                  *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS LIBRARY SOURCE IS     *
 * GOVERNED BY A BSD-STYLE SOURCE LICENSE INCLUDED WITH THIS SOURCE *
 * IN 'COPYING'. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.       *
 *                                                                  *
 * THE OggVorbis 'TREMOR' SOURCE CODE IS (C) COPYRIGHT 1994-2002    *
 * BY THE Xiph.Org FOUNDATION http://www.xiph.org/                  *
 *                                                                  *
 ********************************************************************

 function: registry for floor, res backends and channel mappings

 ********************************************************************/

#include "ivorbiscodec.h"
#include "codec_internal.h"
#include "registry.h"
#include "misc.h"


/* seems like major overkill now; the backend numbers will grow into
   the infrastructure soon enough */

extern vorbis_func_floor     ivorbis_floor0_exportbundle;
extern vorbis_func_floor     ivorbis_floor1_exportbundle;
extern vorbis_func_residue   ivorbis_residue0_exportbundle;
extern vorbis_func_residue   ivorbis_residue1_exportbundle;
extern vorbis_func_residue   ivorbis_residue2_exportbundle;
extern vorbis_func_mapping   ivorbis_mapping0_exportbundle;

vorbis_func_floor     *_ivorbis_floor_P[]={
  &ivorbis_floor0_exportbundle,
  &ivorbis_floor1_exportbundle,
};

vorbis_func_residue   *_ivorbis_residue_P[]={
  &ivorbis_residue0_exportbundle,
  &ivorbis_residue1_exportbundle,
  &ivorbis_residue2_exportbundle,
};

vorbis_func_mapping   *_ivorbis_mapping_P[]={
  &ivorbis_mapping0_exportbundle,
};



