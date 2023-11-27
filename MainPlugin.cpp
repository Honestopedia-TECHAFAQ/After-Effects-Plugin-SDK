#include "MainPlugin.h"

static PF_Err GlobalSetup(PF_GlobalData *g_data, PF_AppUID app_uid, PF_ProgID app_id)
{

  GLatorSDK_Initialize();

  return PF_Err_NONE;
}

static PF_Err ParamsSetup(PF_InData *in_data, PF_OutData *out_data, PF_ParamDef *params[])
{
  PF_Err err = PF_Err_NONE;

  AEFX_CLR_STRUCT(*params);
  out_data->num_params = 2;
  out_data->num_params_UI = 2;

  params[0]->flags = PF_ParamFlag_SUPERVISE;
  params[0]->ui_flags = PF_PUI_EXPAND | PF_PUI_COLLAPSE_TWIRLY_OPEN;
  params[0]->id = 1;
  params[0]->param_type = PF_Param_ANGLE;
  params[0]->name = "Vertices";
  params[0]->flags2 = PF_ParamFlag2_AUTOMATIC;
r
  params[1]->flags = PF_ParamFlag_SUPERVISE;
  params[1]->ui_flags = PF_PUI_EXPAND | PF_PUI_COLLAPSE_TWIRLY_OPEN;
  params[1]->id = 2;
  params[1]->param_type = PF_Param_INTEGER;
  params[1]->name = "Faces";
  params[1]->flags2 = PF_ParamFlag2_AUTOMATIC;

  return err;
}
static PF_Err SequenceSetup(PF_InData *in_data, PF_OutData *out_data, PF_ParamDef *params[], PF_RenderRequest *req)
{
  return PF_Err_NONE;
}
static PF_Err RenderTriangle(const PF_InData *in_data, const PF_OutData *out_data, const PF_ParamDef *params[], PF_RenderRequest *req)
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
static PF_Err DrawWhiteTriangle(const PF_InData *in_data, double *vertex1, double *vertex2, double *vertex3)
{
  return PF_Err_NONE;
}
DllExport PF_Err PluginMain(
  PF_Cmd cmd,
  PF_InData *in_data,
  PF_OutData *out_data,
  PF_ParamDef *params[],
  PF_LayerDef *output,
  void *extra)
{
  PF_Err err = PF_Err_NONE;
  try
  {
    switch (cmd)
    {
    case PF_Cmd_GLOBAL_SETUP:
      err = GlobalSetup(&in_data->global_data, in_data->app_id, in_data->app_id);
      break;
    case PF_Cmd_PARAMS_SETUP:
      err = ParamsSetup(in_data, out_data, params);
      break;
    case PF_Cmd_RENDER:
      err = RenderTriangle(in_data, out_data, params, (PF_RenderRequest *)extra);
      break;
    }
  }
  catch (PF_Err &thrown_err)
  {
    err = thrown_err;
  }
  return err;
}
