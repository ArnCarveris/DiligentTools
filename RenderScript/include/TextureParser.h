/*     Copyright 2015-2016 Egor Yusov
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
#include "EngineObjectParserCommon.h"
#include "ClassMethodBinding.h"

namespace std
{
    DEFINE_ENUM_HASH( Diligent::MISC_TEXTURE_FLAG )
}

namespace Diligent
{
    class TextureParser : public EngineObjectParserCommon<ITexture>
    {
    public:
        TextureParser( IRenderDevice *pRenderDevice, lua_State *L );
        static const Char* TextureLibName;

    protected:
        virtual void CreateObj( lua_State *L );
        
    private:
        // TextureDesc structure does not provide storage for the Name field.
        // We need to use ObjectDescWrapper<> to be able to store the field.
        typedef ObjectDescWrapper<TextureDesc> STexDescWrapper;

        ResourceDimEnumMapping     m_TexTypeEnumMapping;
        TextureFormatEnumMapping   m_TexFormatEnumMapping;
        
        // Note that different bind flags are allowed for different objects, 
        // so we need to populate this enum with values suitable for textures only
        EnumMapping<Diligent::BIND_FLAGS>    m_BindFlagEnumMapping;
        // Explicit namespace declaraion is necesseary to avoid 
        // name conflicts when building for windows store

        EnumMapping<Diligent::MISC_TEXTURE_FLAG> m_MiscFlagEnumMapping;

        UsageEnumMapping           m_UsageEnumMapping;
        CpuAccessFlagEnumMapping  m_CpuAccessFlagEnumMapping;
    };
}
