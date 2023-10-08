#include "drivetrain/SwerveDrive.h"

// do not touch sub_system unless you know what your doing
wom::SwerveModule::SwerveModule(wom::Subsystem<wom::SwerveModuleConfig, wom::SwerveModuleState> sub_system, wom::ModuleName name, wom::SwerveModuleConfig config, wom::SwerveModuleState state) : _name(name) {
  sub_system._config = config;
  sub_system._state = state;
}

void wom::SwerveModule::OnUpdate(units::second_t dt) {
    switch(_state) {
        case wom::SwerveModuleState::kIdle:
            break;
        case wom::SwerveModuleState::kPID:
            break;
        case wom::SwerveModuleState::kCalibration:
            break;
    }
}

void wom::SwerveModule::OnStart() {
    switch(_name) {
        case wom::ModuleName::FrontLeft:
            std::cout << "Starting Swerve Module Front Left" << std::endl;
            break;
        case wom::ModuleName::FrontRight:
            std::cout << "Starting Swerve Module Front Right" << std::endl;
            break;
        case wom::ModuleName::BackLeft:
            std::cout << "Starting Swerve Module Back Left" << std::endl;
            break;
        case wom::ModuleName::BackRight:
            std::cout << "Starting Swerve Module Back Right" << std::endl;
            break;
    }
}

