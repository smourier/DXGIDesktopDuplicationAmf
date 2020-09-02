#ifndef _ENCODINGMANAGER_H_
#define _ENCODINGMANAGER_H_

#include "CommonTypes.h"
using namespace amf;

//
// Handles the task of encoding frames
//
class ENCODINGMANAGER
{
    public:
        ENCODINGMANAGER();
        ~ENCODINGMANAGER();

        AMF_RESULT InitEnc(DX_RESOURCES* Res, DXGI_OUTPUT_DESC* Desc);
        AMF_RESULT ProcessFrame(FRAME_DATA* Data, ID3D11Texture2D* SharedSurf, INT OffsetX, INT OffsetY, DXGI_OUTPUT_DESC* DeskDesc);

    private:
        AMFContextPtr m_context;
        AMFComponentPtr m_encoder;
        AMFComponentPtr m_converter;
        FILE* m_file;
        ID3D11DeviceContext* m_deviceContext;

        AMF_RESULT InitEncoder();
        AMF_RESULT InitConverter(DXGI_OUTPUT_DESC* Desc);
};

#endif
