#pragma once

#include <AE_Effect.h>
#include <AE_Macros.h>
#include <AE_EffectCB.h>
#include <AE_EffectUI.h>
#include "GLatorSDK.h"

static PF_Err GlobalSetup(PF_GlobalData *gData, PF_AppUID appUID, PF_ProgID appID);
static PF_Err ParamsSetup(PF_InData *in_data, PF_OutData *out_data, PF_ParamDef *params[]);
static PF_Err SequenceSetup(PF_InData *in_data, PF_OutData *out_data, PF_ParamDef *params[], PF_RenderRequest *req);
static PF_Err RenderTriangle(const PF_InData *in_data, const PF_OutData *out_data, const PF_ParamDef *params[], PF_RenderRequest *req);
static PF_Err DrawWhiteTriangle(const PF_InData *in_data, double *vertex1, double *vertex2, double *vertex3);

DllExport PF_Err PluginMain(
    PF_Cmd cmd,
    PF_InData *in_data,
    PF_OutData *out_data,
    PF_ParamDef *params[],
    PF_LayerDef *output,
    void *extra);
