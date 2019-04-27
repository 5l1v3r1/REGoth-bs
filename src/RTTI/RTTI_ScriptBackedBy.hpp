#pragma once

#include "RTTI_TypeIDs.hpp"
#include <BsCorePrerequisites.h>
#include <Private/RTTI/BsGameObjectRTTI.h>  // Says private, but bs:f uses this too in their RTTIs
#include <Reflection/BsRTTIType.h>
#include <components/ScriptBackedBy.hpp>

namespace REGoth
{
  class RTTI_ScriptBackedBy
      : public bs::RTTIType<ScriptBackedBy, NeedsGameWorld, RTTI_ScriptBackedBy>
  {
    BS_BEGIN_RTTI_MEMBERS
    BS_RTTI_MEMBER_PLAIN(mScriptClassName, 0)
    BS_RTTI_MEMBER_PLAIN(mScriptInstance, 1)
    BS_RTTI_MEMBER_PLAIN(mScriptObject, 2)
    BS_END_RTTI_MEMBERS

  public:
    RTTI_ScriptBackedBy()
    {
    }

    bs::SPtr<bs::IReflectable> newRTTIObject() override
    {
      return bs::GameObjectRTTI::createGameObject<ScriptBackedBy>();
    }

    const bs::String& getRTTIName() override
    {
      static bs::String name = "ScriptBackedBy";
      return name;
    }

    bs::UINT32 getRTTIId() override
    {
      return TID_REGOTH_ScriptBackedBy;
    }
  };

}  // namespace REGoth
