#pragma once

namespace wom {
    enum ModuleName {
        FrontLeft,
        FrontRight,
        BackLeft,
        BackRight,
    };

    struct SwerveModuleConfig {};

    enum SwerveModuleState {
        kIdle,
        kCalibration,
        kPID,
    };
};
