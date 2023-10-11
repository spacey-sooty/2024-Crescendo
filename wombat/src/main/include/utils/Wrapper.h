#pragma once

#include "behaviour/HasBehaviour.h"
#include "Subsystem.h"

namespace wom {
  template<typename ConfigType, typename StateType>
  class Wrapper : public behaviour::HasBehaviour, public wom::Subsystem<ConfigType, StateType> {
    public:

    protected:

    private:

  };
};

