#pragma once

#include <networktables/DoubleTopic.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <units/angular_velocity.h>
#include <units/charge.h>
#include <units/math.h>
#include <units/time.h>
#include <units/velocity.h>

#include <iostream>
#include <memory>
#include <string>

#include "behaviour/HasBehaviour.h"
#include "utils/Gearbox.h"
#include "utils/PID.h"
#include "utils/Util.h"
#include "vision/Limelight.h"

namespace wom {
namespace drivetrain {
  enum class SwerveModuleName {
    FrontLeft,
    FrontRight,
    BackLeft,
    BackRight,
  };

  struct SwerveModuleConfig {
    wom::utils::Gearbox rotationGearbox;
    wom::utils::Gearbox movementGearbox;

    wom::utils::PIDConfig<units::radians_per_second, units::volt>
        rotationalVelocityPID;
    wom::utils::PIDConfig<units::meters_per_second, units::volt>
        movementVelocityPID;

    wom::utils::PIDConfig<units::radian, units::radians_per_second> rotationPID;
    wom::utils::PIDConfig<units::meter, units::meters_per_second>   movementPID;

    units::meter_t wheelRadius;

    std::string      path;
    SwerveModuleName name;
  };

  enum class SwerveModuleState {
    kIdle,
    kCalibration,
    kPID,
  };

  class SwerveModule : public behaviour::HasBehaviour {
   public:
    explicit SwerveModule(SwerveModuleConfig config, SwerveModuleState state);

    SwerveModuleConfig GetConfig();
    SwerveModuleState  GetState();

    void SetState(SwerveModuleState state);

    void                       Log();
    units::meters_per_second_t GetSpeed();
    void PIDControl(units::second_t dt, units::radian_t rotation,
                    units::meter_t movement);

    void OnStart();
    void OnUpdate(units::second_t dt, units::radian_t rotation,
                  units::meter_t movement);

   protected:
   private:
    wom::utils::PIDController<units::radians_per_second, units::volt>
        _rotationalVelocityPID;
    wom::utils::PIDController<units::meters_per_second, units::volt>
        _movementVelocityPID;

    wom::utils::PIDController<units::radian, units::radians_per_second>
        _rotationalPID;
    wom::utils::PIDController<units::meters, units::meters_per_second>
        _movementPID;


    units::volt_t voltageRotation;
    units::volt_t voltageMovement;

    units::meters_per_second_t  velocity;
    units::radians_per_second_t angularVelocity;

    SwerveModuleConfig _config;
    SwerveModuleState  _state;

    std::string                       name;
    std::shared_ptr<nt::NetworkTable> table;
  };

  struct SwerveConfig {
    SwerveModule frontLeft;
    SwerveModule frontRight;
    SwerveModule backLeft;
    SwerveModule backRight;
  };

  enum class SwerveState {
    kIdle,
    kPose,
    kFieldRelative,
  };

  class Swerve : public behaviour::HasBehaviour {
   public:
    explicit Swerve(SwerveConfig config, SwerveState state,
                    wom::vision::Limelight vision);

    SwerveConfig GetConfig();
    SwerveState  GetState();

    void SetState(SwerveState state);
    void FieldRelativeControl(frc::Pose3d desiredPose, units::second_t dt);

    void OnStart();
    void OnUpdate(units::second_t dt, wom::vision::Limelight vision,
                  frc::Pose3d desiredPose);

   protected:
   private:
    SwerveConfig           _config;
    SwerveState            _state;
    wom::vision::Limelight _vision;
  };
};  // namespace drivetrain
};  // namespace wom
