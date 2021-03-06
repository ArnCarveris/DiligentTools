/*     Copyright 2015-2017 Egor Yusov
 *  
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF ANY PROPRIETARY RIGHTS.
 *
 *  In no event and under no legal theory, whether in tort (including negligence), 
 *  contract, or otherwise, unless required by applicable law (such as deliberate 
 *  and grossly negligent acts) or agreed to in writing, shall any Contributor be
 *  liable for any damages, including any direct, indirect, special, incidental, 
 *  or consequential damages of any character arising as a result of this License or 
 *  out of the use or inability to use the software (including but not limited to damages 
 *  for loss of goodwill, work stoppage, computer failure or malfunction, or any and 
 *  all other commercial damages or losses), even if such Contributor has been advised 
 *  of the possibility of such damages.
 */

#pragma once

#include "LuaWrappers.h"
#include "LuaBindings.h"
#include "ClassMethodBinding.h"

namespace std
{
    DEFINE_ENUM_HASH( Diligent::COMMIT_SHADER_RESOURCES_FLAG )
}

namespace Diligent
{
    class DeviceContextFuncBindings
    {
    public:
        DeviceContextFuncBindings( IRenderDevice *pRenderDevice, lua_State *L, class TextureViewParser *pTexViewPasrser, class ShaderResourceBindingParser *pSRBParser, class PSODescParser *pPSOParser );

    private:
        int SetRenderTargets( lua_State * );
        ClassMethodCaller<DeviceContextFuncBindings> m_SetRenderTargetsBinding;

        int ClearRenderTarget( lua_State * );
        ClassMethodCaller<DeviceContextFuncBindings> m_ClearRenderTargetBinding;

        int ClearDepthStencil( lua_State * );
        ClassMethodCaller<DeviceContextFuncBindings> m_ClearDepthStencilBinding;

        int SetStencilRef( lua_State * );
        ClassMethodCaller<DeviceContextFuncBindings> m_SetStencilRefBinding;

        int SetBlendFactors( lua_State * );
        ClassMethodCaller<DeviceContextFuncBindings> m_SetBlendFactorsBinding;

        int CommitShaderResources( lua_State * );
        ClassMethodCaller<DeviceContextFuncBindings> m_CommitShaderResourcesBinding;

        int TransitionShaderResources( lua_State * );
        ClassMethodCaller<DeviceContextFuncBindings> m_TransitionShaderResourcesBinding;

        EnumMapping<COMMIT_SHADER_RESOURCES_FLAG> m_CommitShaderResFlagsEnumMapping;

        String m_TexViewMetatableName;
        String m_ShaderResBindingMetatableName;
        String m_PSOMetatableName;
    };
}
