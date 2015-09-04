﻿#ifndef HairWorksIntegration_h
#define HairWorksIntegration_h

typedef GFSDK_HairSDK hwSDK;
//typedef GFSDK_HairAssetID hwAssetID;
//typedef GFSDK_HairInstanceID hwInstanceID;
typedef int hwAssetID;
typedef int hwInstanceID;
typedef int hwShaderID;
typedef GFSDK_HairInstanceDescriptor hwHairDescriptor;
typedef GFSDK_HAIR_TEXTURE_TYPE hwTextureType;

typedef ID3D11Device hwDevice;
typedef ID3D11Texture2D hwTexture;
typedef ID3D11ShaderResourceView hwSRV;
typedef ID3D11RenderTargetView hwRTV;
typedef XMMATRIX hwMatrix;

typedef void(__stdcall *hwLogCallback)(const char *);
#define hwNullID 0xFFFF
#define hwFlushEventID 0x14840001

class hwContext;


// Unity plugin callbacks
hwCLinkage hwExport void            UnitySetGraphicsDevice(void* device, int deviceType, int eventType);
hwCLinkage hwExport void            UnityRenderEvent(int eventID);


hwCLinkage hwExport bool            hwInitialize();
hwCLinkage hwExport void            hwFinalize();
hwCLinkage hwExport hwContext*      hwGetContext();
hwCLinkage hwExport int             hwGetFlushEventID();
hwCLinkage hwExport void            hwSetLogCallback(hwLogCallback cb);

hwCLinkage hwExport hwShaderID      hwShaderLoadFromFile(const char *path);
hwCLinkage hwExport void            hwShaderRelease(hwShaderID sid);
hwCLinkage hwExport void            hwShaderReload(hwShaderID sid);

hwCLinkage hwExport hwAssetID       hwAssetLoadFromFile(const char *path);
hwCLinkage hwExport void            hwAssetRelease(hwAssetID aid);
hwCLinkage hwExport void            hwAssetReload(hwAssetID aid);

hwCLinkage hwExport hwInstanceID    hwInstanceCreate(hwAssetID aid);
hwCLinkage hwExport void            hwInstanceRelease(hwInstanceID iid);
hwCLinkage hwExport void            hwInstanceGetAssetID(hwInstanceID iid);
hwCLinkage hwExport void            hwInstanceGetDescriptor(hwInstanceID iid, hwHairDescriptor *desc);
hwCLinkage hwExport void            hwInstanceSetDescriptor(hwInstanceID iid, const hwHairDescriptor *desc);
hwCLinkage hwExport void            hwInstanceSetTexture(hwInstanceID iid, hwTextureType type, hwTexture *tex);
hwCLinkage hwExport void            hwInstanceUpdateSkinningMatrices(hwInstanceID iid, int num_matrices, const hwMatrix *matrices);

hwCLinkage hwExport void            hwSetViewProjection(const hwMatrix *view, const hwMatrix *proj, float fov);
hwCLinkage hwExport void            hwSetRenderTarget(hwTexture *framebuffer, hwTexture *depthbuffer);
hwCLinkage hwExport void            hwSetShader(hwShaderID sid);
hwCLinkage hwExport void            hwRender(hwInstanceID iid);
hwCLinkage hwExport void            hwRenderShadow(hwInstanceID iid);
hwCLinkage hwExport void            hwStepSimulation(float dt);

#endif // HairWorksIntegration_h
