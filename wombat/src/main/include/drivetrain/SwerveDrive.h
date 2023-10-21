#pragma once

#include "behaviour/Behaviour.h"
#include "utils/PID.h"

namespace wom {
    enum ModuleName {
        FrontLeft,
        FrontRight,
        BackLeft,
        BackRight,
    };

    struct SwerveModuleConfig {
      // falcon * 2
      // pid stuff
    };

    enum SwerveModuleState {
        kIdle,
        kCalibration,
        kPID,
    };

    class SwerveModule : public behaviour::HasBehaviour {
      public:
          SwerveModule(wom::ModuleName name, wom::SwerveModuleConfig config, wom::SwerveModuleState state);

          SwerveModuleState GetState();
          SwerveModuleConfig GetConfig(); 
          
          void SetState(SwerveModuleState state);

          void OnStart();
          void OnUpdate(units::second_t dt);

      protected:

      private:
          ModuleName _name;
          SwerveModuleConfig _config;
          SwerveModuleState _state;

    };

};
