#pragma once

#include <PF_Win_SDK.h>

PF_Err GLatorSDK_Initialize();
void GLatorSDK_BeginRender();
void GLatorSDK_SetLayerAlpha(float alpha);
void GLatorSDK_EndRender();

// MainPlugin.cpp
#include "MainPlugin.h"

PF_Err GLatorSDK_Initialize()
{
    return PF_Err_NONE;
}

void GLatorSDK_BeginRender()
{
}

void GLatorSDK_SetLayerAlpha(float alpha)
{
}

void GLatorSDK_EndRender()
{
}

PF_Err RenderTriangle(const PF_InData *in_data, const PF_OutData *out_data, const PF_ParamDef *params[], PF_RenderRequest *req)
{
    PF_Err err = PF_Err_NONE;
    try
    {
        double **vertices = params[0]->u.ar.value;
        int **faces = params[1]->u.ar.value;
        err = SequenceSetup(in_data, out_data, params, req);
        if (err) throw err;
        GLatorSDK_BeginRender();
        GLatorSDK_SetLayerAlpha(1.0f);
        DrawWhiteTriangle(in_data, vertices[faces[0][0]], vertices[faces[0][1]], vertices[faces[0][2]]);
        GLatorSDK_EndRender();
    }
    catch (PF_Err &thrown_err)
    {
        err = thrown_err;
    }
    return err;
}

PF_Err DrawWhiteTriangle(const PF_InData *in_data, double *vertex1, double *vertex2, double *vertex3)
{
    return PF_Err_NONE;
}
