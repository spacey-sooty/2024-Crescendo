#include "drivetrain/SwerveDrive.h"

wom::SwerveModule::SwerveModule(wom::ModuleName name, wom::SwerveModuleConfig config, wom::SwerveModuleState state) : _name(name), _config(config), _state(state) {}

void wom::SwerveModule::SetState(wom::SwerveModuleState state) {
  _state = state;
}

wom::SwerveModuleState wom::SwerveModule::GetState() {
  return _state;
}

wom::SwerveModuleConfig wom::SwerveModule::GetConfig() {
  return _config;
}

void wom::SwerveModule::OnUpdate(units::second_t dt) {
    switch(_state) {
        case wom::SwerveModuleState::kIdle: {
            break;
        }
        case wom::SwerveModuleState::kPID: {
            break;
        }
        case wom::SwerveModuleState::kCalibration: {
            break;
        }
    }
}

void wom::SwerveModule::OnStart() {
    switch(_name) {
        case wom::ModuleName::FrontLeft: {
            std::cout << "Starting Swerve Module Front Left" << std::endl;
            break;
        }
        case wom::ModuleName::FrontRight: {
            std::cout << "Starting Swerve Module Front Right" << std::endl;
            break;
        }
        case wom::ModuleName::BackLeft: {
            std::cout << "Starting Swerve Module Back Left" << std::endl;
            break;
        }
        case wom::ModuleName::BackRight: {
            std::cout << "Starting Swerve Module Back Right" << std::endl;
            break;
        }
    }
}

